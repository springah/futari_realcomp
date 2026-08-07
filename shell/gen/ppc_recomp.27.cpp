#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8216E93C"))) PPC_WEAK_FUNC(sub_8216E93C);
PPC_FUNC_IMPL(__imp__sub_8216E93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E940"))) PPC_WEAK_FUNC(sub_8216E940);
PPC_FUNC_IMPL(__imp__sub_8216E940) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31324(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216e964
	if (ctx.cr6.eq) goto loc_8216E964;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r11,-31136
	ctx.r10.s64 = ctx.r11.s64 + -31136;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_8216E964:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E96C"))) PPC_WEAK_FUNC(sub_8216E96C);
PPC_FUNC_IMPL(__imp__sub_8216E96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E970"))) PPC_WEAK_FUNC(sub_8216E970);
PPC_FUNC_IMPL(__imp__sub_8216E970) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,5816
	ctx.r10.s64 = ctx.r11.s64 + 5816;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8216e9bc
	if (ctx.cr6.eq) goto loc_8216E9BC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216E9B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_8216E9BC:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216e9e0
	if (ctx.cr6.eq) goto loc_8216E9E0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216E9DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_8216E9E0:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r31,r11,-31136
	ctx.r31.s64 = ctx.r11.s64 + -31136;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216ea10
	if (ctx.cr6.eq) goto loc_8216EA10;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216EA08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
loc_8216EA10:
	// bl 0x82158d00
	ctx.lr = 0x8216EA14;
	sub_82158D00(ctx, base);
	// bl 0x82157bd8
	ctx.lr = 0x8216EA18;
	sub_82157BD8(ctx, base);
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

__attribute__((alias("__imp__sub_8216EA30"))) PPC_WEAK_FUNC(sub_8216EA30);
PPC_FUNC_IMPL(__imp__sub_8216EA30) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,5816
	ctx.r9.s64 = ctx.r10.s64 + 5816;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216EA4C"))) PPC_WEAK_FUNC(sub_8216EA4C);
PPC_FUNC_IMPL(__imp__sub_8216EA4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216EA50"))) PPC_WEAK_FUNC(sub_8216EA50);
PPC_FUNC_IMPL(__imp__sub_8216EA50) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,5840
	ctx.r10.s64 = ctx.r11.s64 + 5840;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8216e808
	sub_8216E808(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216EA64"))) PPC_WEAK_FUNC(sub_8216EA64);
PPC_FUNC_IMPL(__imp__sub_8216EA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216EA68"))) PPC_WEAK_FUNC(sub_8216EA68);
PPC_FUNC_IMPL(__imp__sub_8216EA68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216EA70;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31312(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// lwz r30,-31324(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31324);
	// lwz r9,152(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// lbz r8,552(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 552);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8216eb3c
	if (!ctx.cr6.eq) goto loc_8216EB3C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a4b8
	ctx.lr = 0x8216EAA0;
	sub_8208A4B8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// lfd f0,-31320(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r31.u32 + -31320);
	// lfd f13,88(r10)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + 88);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfd f12,80(r10)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r10.u32 + 80);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// fmul f31,f13,f12
	ctx.f31.f64 = ctx.f13.f64 * ctx.f12.f64;
	// bne cr6,0x8216eae0
	if (!ctx.cr6.eq) goto loc_8216EAE0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a498
	ctx.lr = 0x8216EAD4;
	sub_8208A498(ctx, base);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfd f0,-31320(r31)
	PPC_STORE_U64(ctx.r31.u32 + -31320, ctx.f0.u64);
loc_8216EAE0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a498
	ctx.lr = 0x8216EAE8;
	sub_8208A498(ctx, base);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfd f13,-31320(r31)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r31.u32 + -31320);
	// fsub f0,f12,f13
	ctx.f0.f64 = ctx.f12.f64 - ctx.f13.f64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8216eb28
	if (!ctx.cr6.lt) goto loc_8216EB28;
loc_8216EB00:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82089e08
	ctx.lr = 0x8216EB08;
	sub_82089E08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a498
	ctx.lr = 0x8216EB10;
	sub_8208A498(ctx, base);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfd f13,-31320(r31)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r31.u32 + -31320);
	// fsub f0,f12,f13
	ctx.f0.f64 = ctx.f12.f64 - ctx.f13.f64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8216eb00
	if (ctx.cr6.lt) goto loc_8216EB00;
loc_8216EB28:
	// fsub f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 - ctx.f31.f64;
	// fadd f13,f13,f31
	ctx.f13.f64 = ctx.f13.f64 + ctx.f31.f64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8216eb28
	if (!ctx.cr6.lt) goto loc_8216EB28;
	// stfd f13,-31320(r31)
	PPC_STORE_U64(ctx.r31.u32 + -31320, ctx.f13.u64);
loc_8216EB3C:
	// lwz r31,16(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8216eb74
	if (ctx.cr6.eq) goto loc_8216EB74;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216EB5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8216EB74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216EB74:
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// bl 0x8216b148
	ctx.lr = 0x8216EB80;
	sub_8216B148(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216EB8C"))) PPC_WEAK_FUNC(sub_8216EB8C);
PPC_FUNC_IMPL(__imp__sub_8216EB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216EB90"))) PPC_WEAK_FUNC(sub_8216EB90);
PPC_FUNC_IMPL(__imp__sub_8216EB90) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31324(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r9,r11,44
	ctx.r9.s64 = ctx.r11.s64 + 44;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216EBCC"))) PPC_WEAK_FUNC(sub_8216EBCC);
PPC_FUNC_IMPL(__imp__sub_8216EBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216EBD0"))) PPC_WEAK_FUNC(sub_8216EBD0);
PPC_FUNC_IMPL(__imp__sub_8216EBD0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31324(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8216ea68
	sub_8216EA68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216EBE4"))) PPC_WEAK_FUNC(sub_8216EBE4);
PPC_FUNC_IMPL(__imp__sub_8216EBE4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216EBE8"))) PPC_WEAK_FUNC(sub_8216EBE8);
PPC_FUNC_IMPL(__imp__sub_8216EBE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8216EBF0;
	__savegprlr_25(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r31,r11,-12560
	ctx.r31.s64 = ctx.r11.s64 + -12560;
	// addi r30,r10,-12704
	ctx.r30.s64 = ctx.r10.s64 + -12704;
	// li r27,-1
	ctx.r27.s64 = -1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lwz r25,-31324(r9)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31324);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x820601f8
	ctx.lr = 0x8216EC28;
	sub_820601F8(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,28
	ctx.r4.s64 = ctx.r30.s64 + 28;
	// addi r3,r31,28
	ctx.r3.s64 = ctx.r31.s64 + 28;
	// bl 0x820601f8
	ctx.lr = 0x8216EC3C;
	sub_820601F8(ctx, base);
	// lwz r11,56(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// lwz r8,68(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lbz r7,72(r30)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + 72);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// addi r4,r30,88
	ctx.r4.s64 = ctx.r30.s64 + 88;
	// lwz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r8.u32);
	// stb r7,72(r31)
	PPC_STORE_U8(ctx.r31.u32 + 72, ctx.r7.u8);
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// lwz r8,76(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 76);
	// lwz r7,80(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// lwz r11,84(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// lbz r28,73(r30)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r30.u32 + 73);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// stw r7,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r7.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stb r28,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r28.u8);
	// bl 0x820601f8
	ctx.lr = 0x8216EC98;
	sub_820601F8(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,116
	ctx.r4.s64 = ctx.r30.s64 + 116;
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// bl 0x820601f8
	ctx.lr = 0x8216ECAC;
	sub_820601F8(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8216eccc
	if (ctx.cr6.eq) goto loc_8216ECCC;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
loc_8216ECCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82157bc8
	ctx.lr = 0x8216ECD4;
	sub_82157BC8(ctx, base);
	// bl 0x82158cf0
	ctx.lr = 0x8216ECD8;
	sub_82158CF0(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r1,136
	ctx.r11.s64 = ctx.r1.s64 + 136;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8216ECEC:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x8216ecec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216ECEC;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821d5184
	ctx.lr = 0x8216ECFC;
	__imp__XGetVideoMode(ctx, base);
	// lwz r9,156(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r8,144(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8216ed18
	if (!ctx.cr6.eq) goto loc_8216ED18;
	// li r11,1920
	ctx.r11.s64 = 1920;
	// li r10,960
	ctx.r10.s64 = 960;
	// b 0x8216ed34
	goto loc_8216ED34;
loc_8216ED18:
	// cmplwi cr6,r8,1280
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1280, ctx.xer);
	// ble cr6,0x8216ed2c
	if (!ctx.cr6.gt) goto loc_8216ED2C;
	// li r11,1920
	ctx.r11.s64 = 1920;
	// li r10,1080
	ctx.r10.s64 = 1080;
	// b 0x8216ed34
	goto loc_8216ED34;
loc_8216ED2C:
	// li r11,1280
	ctx.r11.s64 = 1280;
	// li r10,720
	ctx.r10.s64 = 720;
loc_8216ED34:
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r8,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r8.u32);
	// stb r30,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r30.u8);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// beq cr6,0x8216ed64
	if (ctx.cr6.eq) goto loc_8216ED64;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// stb r26,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r26.u8);
loc_8216ED64:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r29,r11,-21892
	ctx.r29.s64 = ctx.r11.s64 + -21892;
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// addi r4,r29,-28
	ctx.r4.s64 = ctx.r29.s64 + -28;
	// bl 0x82060368
	ctx.lr = 0x8216ED7C;
	sub_82060368(ctx, base);
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8216ed94
	if (ctx.cr6.lt) goto loc_8216ED94;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// b 0x8216ed98
	goto loc_8216ED98;
loc_8216ED94:
	// addi r11,r31,92
	ctx.r11.s64 = ctx.r31.s64 + 92;
loc_8216ED98:
	// stw r11,-31868(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31868, ctx.r11.u32);
	// li r3,808
	ctx.r3.s64 = 808;
	// bl 0x82079fd8
	ctx.lr = 0x8216EDA4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216edc8
	if (ctx.cr6.eq) goto loc_8216EDC8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,-31136
	ctx.r9.s64 = ctx.r11.s64 + -31136;
	// addi r8,r10,5840
	ctx.r8.s64 = ctx.r10.s64 + 5840;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r3,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r3.u32);
	// b 0x8216edd8
	goto loc_8216EDD8;
loc_8216EDC8:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r9,r10,-31136
	ctx.r9.s64 = ctx.r10.s64 + -31136;
	// stw r30,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r30.u32);
loc_8216EDD8:
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// addi r4,r29,-20
	ctx.r4.s64 = ctx.r29.s64 + -20;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x8216EDF8;
	sub_82060368(ctx, base);
	// addi r4,r29,-12
	ctx.r4.s64 = ctx.r29.s64 + -12;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82061760
	ctx.lr = 0x8216EE08;
	sub_82061760(ctx, base);
	// addi r4,r29,-4
	ctx.r4.s64 = ctx.r29.s64 + -4;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206a100
	ctx.lr = 0x8216EE1C;
	sub_8206A100(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8216ee5c
	if (ctx.cr6.eq) goto loc_8216EE5C;
loc_8216EE28:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82069ed8
	ctx.lr = 0x8216EE3C;
	sub_82069ED8(ctx, base);
	// addi r4,r29,-4
	ctx.r4.s64 = ctx.r29.s64 + -4;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206a100
	ctx.lr = 0x8216EE50;
	sub_8206A100(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8216ee28
	if (!ctx.cr6.eq) goto loc_8216EE28;
loc_8216EE5C:
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r28.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x8216EE7C;
	sub_820601F8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8216a110
	ctx.lr = 0x8216EE84;
	sub_8216A110(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8216ee98
	if (ctx.cr6.lt) goto loc_8216EE98;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8216EE98;
	sub_8207A630(ctx, base);
loc_8216EE98:
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// bl 0x82079fd8
	ctx.lr = 0x8216EEAC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216ef3c
	if (ctx.cr6.eq) goto loc_8216EF3C;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r4,r7,5820
	ctx.r4.s64 = ctx.r7.s64 + 5820;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// stb r30,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r30.u8);
	// stb r30,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r30.u8);
	// stb r30,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r30.u8);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r30,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r30.u32);
	// stb r30,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r30.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r26,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r26.u8);
	// stb r26,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r26.u8);
	// stw r3,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r3.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8216EF3C:
	// stw r30,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r30.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216EF48"))) PPC_WEAK_FUNC(sub_8216EF48);
PPC_FUNC_IMPL(__imp__sub_8216EF48) {
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
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-31324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216efb8
	if (!ctx.cr6.eq) goto loc_8216EFB8;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82079fd8
	ctx.lr = 0x8216EF78;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x8216efa0
	if (ctx.cr6.eq) goto loc_8216EFA0;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r8,r9,5816
	ctx.r8.s64 = ctx.r9.s64 + 5816;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x8216efa4
	goto loc_8216EFA4;
loc_8216EFA0:
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8216EFA4:
	// stw r11,-31324(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31324, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bl 0x8216ebe8
	ctx.lr = 0x8216EFB8;
	sub_8216EBE8(ctx, base);
loc_8216EFB8:
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

__attribute__((alias("__imp__sub_8216EFD0"))) PPC_WEAK_FUNC(sub_8216EFD0);
PPC_FUNC_IMPL(__imp__sub_8216EFD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,20(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216EFE4"))) PPC_WEAK_FUNC(sub_8216EFE4);
PPC_FUNC_IMPL(__imp__sub_8216EFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216EFE8"))) PPC_WEAK_FUNC(sub_8216EFE8);
PPC_FUNC_IMPL(__imp__sub_8216EFE8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216EFEC"))) PPC_WEAK_FUNC(sub_8216EFEC);
PPC_FUNC_IMPL(__imp__sub_8216EFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216EFF0"))) PPC_WEAK_FUNC(sub_8216EFF0);
PPC_FUNC_IMPL(__imp__sub_8216EFF0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216EFF8"))) PPC_WEAK_FUNC(sub_8216EFF8);
PPC_FUNC_IMPL(__imp__sub_8216EFF8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216F000"))) PPC_WEAK_FUNC(sub_8216F000);
PPC_FUNC_IMPL(__imp__sub_8216F000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216F008"))) PPC_WEAK_FUNC(sub_8216F008);
PPC_FUNC_IMPL(__imp__sub_8216F008) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216F010"))) PPC_WEAK_FUNC(sub_8216F010);
PPC_FUNC_IMPL(__imp__sub_8216F010) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,5752
	ctx.r10.s64 = ctx.r11.s64 + 5752;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216F020"))) PPC_WEAK_FUNC(sub_8216F020);
PPC_FUNC_IMPL(__imp__sub_8216F020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r8,r10,5752
	ctx.r8.s64 = ctx.r10.s64 + 5752;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216F044"))) PPC_WEAK_FUNC(sub_8216F044);
PPC_FUNC_IMPL(__imp__sub_8216F044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216F048"))) PPC_WEAK_FUNC(sub_8216F048);
PPC_FUNC_IMPL(__imp__sub_8216F048) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r11,r3,36
	ctx.r11.s64 = ctx.r3.s64 + 36;
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r10,0
	ctx.r10.s64 = 0;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi. r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
loc_8216F064:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8216f080
	if (ctx.cr6.lt) goto loc_8216F080;
	// twi 31,r0,22
loc_8216F080:
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8216f064
	if (ctx.cr6.lt) goto loc_8216F064;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216F0A0"))) PPC_WEAK_FUNC(sub_8216F0A0);
PPC_FUNC_IMPL(__imp__sub_8216F0A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8216F0A8;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8208035c
	ctx.lr = 0x8216F0B0;
	__savefpr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// std r4,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r4.u64);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// std r6,248(r1)
	PPC_STORE_U64(ctx.r1.u32 + 248, ctx.r6.u64);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216F0D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// std r31,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r31.u64);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f26,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f26.f64 = double(temp.f32);
	// stfs f26,80(r1)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f31,f26
	ctx.f31.f64 = ctx.f26.f64;
	// bl 0x82074758
	ctx.lr = 0x8216F0F8;
	sub_82074758(ctx, base);
	// lfs f28,252(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	ctx.f28.f64 = double(temp.f32);
	// lfs f25,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f25.f64 = double(temp.f32);
	// lfs f27,232(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f27.f64 = double(temp.f32);
	// lfs f29,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f30.f64 = double(temp.f32);
	// lwz r31,96(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r29,100(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_8216F114:
	// lwz r8,24(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// addi r30,r28,4
	ctx.r30.s64 = ctx.r28.s64 + 4;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f12c
	if (ctx.cr6.lt) goto loc_8216F12C;
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x8216f130
	goto loc_8216F130;
loc_8216F12C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F130:
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add. r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8216f17c
	if (ctx.cr0.eq) goto loc_8216F17C;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f150
	if (ctx.cr6.lt) goto loc_8216F150;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f154
	goto loc_8216F154;
loc_8216F150:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F154:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8216f17c
	if (ctx.cr6.gt) goto loc_8216F17C;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f16c
	if (ctx.cr6.lt) goto loc_8216F16C;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f170
	goto loc_8216F170;
loc_8216F16C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F170:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216f180
	if (!ctx.cr6.gt) goto loc_8216F180;
loc_8216F17C:
	// twi 31,r0,22
loc_8216F180:
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f19c
	if (ctx.cr6.eq) goto loc_8216F19C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8216f198
	if (ctx.cr6.eq) goto loc_8216F198;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8216f19c
	if (ctx.cr6.eq) goto loc_8216F19C;
loc_8216F198:
	// twi 31,r0,22
loc_8216F19C:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216f348
	if (ctx.cr6.eq) goto loc_8216F348;
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f1e8
	if (ctx.cr6.eq) goto loc_8216F1E8;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f1b8
	if (!ctx.cr6.eq) goto loc_8216F1B8;
	// twi 31,r0,22
loc_8216F1B8:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f1cc
	if (ctx.cr6.lt) goto loc_8216F1CC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f1d0
	goto loc_8216F1D0;
loc_8216F1CC:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F1D0:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f1e8
	if (ctx.cr6.lt) goto loc_8216F1E8;
	// twi 31,r0,22
loc_8216F1E8:
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8216f2e0
	if (ctx.cr6.eq) goto loc_8216F2E0;
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f238
	if (ctx.cr6.eq) goto loc_8216F238;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f208
	if (!ctx.cr6.eq) goto loc_8216F208;
	// twi 31,r0,22
loc_8216F208:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f21c
	if (ctx.cr6.lt) goto loc_8216F21C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f220
	goto loc_8216F220;
loc_8216F21C:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F220:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f238
	if (ctx.cr6.lt) goto loc_8216F238;
	// twi 31,r0,22
loc_8216F238:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lhz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216F254;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f298
	if (ctx.cr6.eq) goto loc_8216F298;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f268
	if (!ctx.cr6.eq) goto loc_8216F268;
	// twi 31,r0,22
loc_8216F268:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f27c
	if (ctx.cr6.lt) goto loc_8216F27C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f280
	goto loc_8216F280;
loc_8216F27C:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F280:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f298
	if (ctx.cr6.lt) goto loc_8216F298;
	// twi 31,r0,22
loc_8216F298:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216F2B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// fadds f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f31,f12
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// fadds f30,f13,f25
	ctx.f30.f64 = double(float(ctx.f13.f64 + ctx.f25.f64));
	// stfs f30,88(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// blt cr6,0x8216f2d8
	if (ctx.cr6.lt) goto loc_8216F2D8;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8216F2D8:
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// b 0x8216f2f8
	goto loc_8216F2F8;
loc_8216F2E0:
	// fadds f0,f29,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f29.f64 + ctx.f28.f64));
	// stfs f27,88(r1)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f30,f27
	ctx.f30.f64 = ctx.f27.f64;
	// fadds f29,f0,f31
	ctx.f29.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f29,92(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f31,f26
	ctx.f31.f64 = ctx.f26.f64;
loc_8216F2F8:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f340
	if (ctx.cr6.eq) goto loc_8216F340;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f310
	if (!ctx.cr6.eq) goto loc_8216F310;
	// twi 31,r0,22
loc_8216F310:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f324
	if (ctx.cr6.lt) goto loc_8216F324;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f328
	goto loc_8216F328;
loc_8216F324:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F328:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f340
	if (ctx.cr6.lt) goto loc_8216F340;
	// twi 31,r0,22
loc_8216F340:
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// b 0x8216f114
	goto loc_8216F114;
loc_8216F348:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216F35C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// blt cr6,0x8216f370
	if (ctx.cr6.lt) goto loc_8216F370;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8216F370;
	sub_8207A630(ctx, base);
loc_8216F370:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
	// stw r10,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r10.u32);
	// sth r11,0(r30)
	PPC_STORE_U16(ctx.r30.u32 + 0, ctx.r11.u16);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803a8
	ctx.lr = 0x8216F390;
	__restfpr_25(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216F394"))) PPC_WEAK_FUNC(sub_8216F394);
PPC_FUNC_IMPL(__imp__sub_8216F394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216F398"))) PPC_WEAK_FUNC(sub_8216F398);
PPC_FUNC_IMPL(__imp__sub_8216F398) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8216F3A0;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x82080358
	ctx.lr = 0x8216F3A8;
	__savefpr_24(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// std r6,296(r1)
	PPC_STORE_U64(ctx.r1.u32 + 296, ctx.r6.u64);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f29,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f29.f64 = double(temp.f32);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// stfs f29,80(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f28,f29
	ctx.f28.f64 = ctx.f29.f64;
	// fmr f26,f29
	ctx.f26.f64 = ctx.f29.f64;
	// fmr f27,f29
	ctx.f27.f64 = ctx.f29.f64;
	// bl 0x82074758
	ctx.lr = 0x8216F3E0;
	sub_82074758(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f24,296(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f24.f64 = double(temp.f32);
	// li r25,0
	ctx.r25.s64 = 0;
	// lfs f25,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f25.f64 = double(temp.f32);
	// lwz r31,96(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r29,100(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_8216F3F8:
	// lwz r8,24(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// addi r30,r27,4
	ctx.r30.s64 = ctx.r27.s64 + 4;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f410
	if (ctx.cr6.lt) goto loc_8216F410;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// b 0x8216f414
	goto loc_8216F414;
loc_8216F410:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F414:
	// lwz r10,20(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add. r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8216f460
	if (ctx.cr0.eq) goto loc_8216F460;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f434
	if (ctx.cr6.lt) goto loc_8216F434;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f438
	goto loc_8216F438;
loc_8216F434:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F438:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8216f460
	if (ctx.cr6.gt) goto loc_8216F460;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f450
	if (ctx.cr6.lt) goto loc_8216F450;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f454
	goto loc_8216F454;
loc_8216F450:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F454:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216f464
	if (!ctx.cr6.gt) goto loc_8216F464;
loc_8216F460:
	// twi 31,r0,22
loc_8216F464:
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f480
	if (ctx.cr6.eq) goto loc_8216F480;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8216f47c
	if (ctx.cr6.eq) goto loc_8216F47C;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8216f480
	if (ctx.cr6.eq) goto loc_8216F480;
loc_8216F47C:
	// twi 31,r0,22
loc_8216F480:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216f764
	if (ctx.cr6.eq) goto loc_8216F764;
	// stfs f29,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
	// stfs f29,92(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f30,f29
	ctx.f30.f64 = ctx.f29.f64;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
loc_8216F49C:
	// lwz r8,24(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f4b0
	if (ctx.cr6.lt) goto loc_8216F4B0;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f4b4
	goto loc_8216F4B4;
loc_8216F4B0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F4B4:
	// lwz r10,20(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add. r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8216f500
	if (ctx.cr0.eq) goto loc_8216F500;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f4d4
	if (ctx.cr6.lt) goto loc_8216F4D4;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f4d8
	goto loc_8216F4D8;
loc_8216F4D4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F4D8:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8216f500
	if (ctx.cr6.gt) goto loc_8216F500;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f4f0
	if (ctx.cr6.lt) goto loc_8216F4F0;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f4f4
	goto loc_8216F4F4;
loc_8216F4F0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F4F4:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216f504
	if (!ctx.cr6.gt) goto loc_8216F504;
loc_8216F500:
	// twi 31,r0,22
loc_8216F504:
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f520
	if (ctx.cr6.eq) goto loc_8216F520;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8216f51c
	if (ctx.cr6.eq) goto loc_8216F51C;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8216f520
	if (ctx.cr6.eq) goto loc_8216F520;
loc_8216F51C:
	// twi 31,r0,22
loc_8216F520:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216f650
	if (ctx.cr6.eq) goto loc_8216F650;
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f56c
	if (ctx.cr6.eq) goto loc_8216F56C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f53c
	if (!ctx.cr6.eq) goto loc_8216F53C;
	// twi 31,r0,22
loc_8216F53C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f550
	if (ctx.cr6.lt) goto loc_8216F550;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f554
	goto loc_8216F554;
loc_8216F550:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F554:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r7
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8216f56c
	if (ctx.cr6.lt) goto loc_8216F56C;
	// twi 31,r0,22
loc_8216F56C:
	// lhz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x8216f650
	if (ctx.cr6.eq) goto loc_8216F650;
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f5bc
	if (ctx.cr6.eq) goto loc_8216F5BC;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f58c
	if (!ctx.cr6.eq) goto loc_8216F58C;
	// twi 31,r0,22
loc_8216F58C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f5a0
	if (ctx.cr6.lt) goto loc_8216F5A0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f5a4
	goto loc_8216F5A4;
loc_8216F5A0:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F5A4:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f5bc
	if (ctx.cr6.lt) goto loc_8216F5BC;
	// twi 31,r0,22
loc_8216F5BC:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216F5D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,100
	ctx.r11.s64 = ctx.r1.s64 + 100;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fcmpu cr6,f30,f13
	ctx.cr6.compare(ctx.f30.f64, ctx.f13.f64);
	// blt cr6,0x8216f5f8
	if (ctx.cr6.lt) goto loc_8216F5F8;
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
loc_8216F5F8:
	// lfs f30,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// stfs f30,92(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// beq cr6,0x8216f644
	if (ctx.cr6.eq) goto loc_8216F644;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f614
	if (!ctx.cr6.eq) goto loc_8216F614;
	// twi 31,r0,22
loc_8216F614:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f628
	if (ctx.cr6.lt) goto loc_8216F628;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f62c
	goto loc_8216F62C;
loc_8216F628:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F62C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f644
	if (ctx.cr6.lt) goto loc_8216F644;
	// twi 31,r0,22
loc_8216F644:
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// b 0x8216f49c
	goto loc_8216F49C;
loc_8216F650:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x8216f678
	if (ctx.cr6.eq) goto loc_8216F678;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f31,f12,f24,f31
	ctx.f31.f64 = double(float(ctx.f12.f64 * ctx.f24.f64 + ctx.f31.f64));
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_8216F678:
	// fcmpu cr6,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f28.f64, ctx.f31.f64);
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// blt cr6,0x8216f688
	if (ctx.cr6.lt) goto loc_8216F688;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8216F688:
	// lfs f28,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// fadds f27,f30,f27
	ctx.f27.f64 = double(float(ctx.f30.f64 + ctx.f27.f64));
	// stfs f28,80(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f6a4
	if (ctx.cr6.lt) goto loc_8216F6A4;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f6a8
	goto loc_8216F6A8;
loc_8216F6A4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F6A8:
	// add. r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8216f6ec
	if (ctx.cr0.eq) goto loc_8216F6EC;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f6c0
	if (ctx.cr6.lt) goto loc_8216F6C0;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f6c4
	goto loc_8216F6C4;
loc_8216F6C0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F6C4:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8216f6ec
	if (ctx.cr6.gt) goto loc_8216F6EC;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// blt cr6,0x8216f6dc
	if (ctx.cr6.lt) goto loc_8216F6DC;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216f6e0
	goto loc_8216F6E0;
loc_8216F6DC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8216F6E0:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216f6f0
	if (!ctx.cr6.gt) goto loc_8216F6F0;
loc_8216F6EC:
	// twi 31,r0,22
loc_8216F6F0:
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f70c
	if (ctx.cr6.eq) goto loc_8216F70C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8216f708
	if (ctx.cr6.eq) goto loc_8216F708;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8216f70c
	if (ctx.cr6.eq) goto loc_8216F70C;
loc_8216F708:
	// twi 31,r0,22
loc_8216F70C:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216f764
	if (ctx.cr6.eq) goto loc_8216F764;
	// cmpwi cr6,r31,-4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -4, ctx.xer);
	// beq cr6,0x8216f758
	if (ctx.cr6.eq) goto loc_8216F758;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8216f728
	if (!ctx.cr6.eq) goto loc_8216F728;
	// twi 31,r0,22
loc_8216F728:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216f73c
	if (ctx.cr6.lt) goto loc_8216F73C;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8216f740
	goto loc_8216F740;
loc_8216F73C:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8216F740:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8216f758
	if (ctx.cr6.lt) goto loc_8216F758;
	// twi 31,r0,22
loc_8216F758:
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// fadds f26,f26,f25
	ctx.fpscr.disableFlushMode();
	ctx.f26.f64 = double(float(ctx.f26.f64 + ctx.f25.f64));
	// b 0x8216f3f8
	goto loc_8216F3F8;
loc_8216F764:
	// lfs f0,300(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// fmadds f13,f0,f26,f27
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f26.f64 + ctx.f27.f64));
	// stfs f28,0(r24)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r24.u32 + 0, temp.u32);
	// stfs f13,4(r24)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r24.u32 + 4, temp.u32);
	// blt cr6,0x8216f784
	if (ctx.cr6.lt) goto loc_8216F784;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8216F784;
	sub_8207A630(ctx, base);
loc_8216F784:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r25,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r25.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r11,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r11.u32);
	// sth r25,0(r30)
	PPC_STORE_U16(ctx.r30.u32 + 0, ctx.r25.u16);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x820803a4
	ctx.lr = 0x8216F7A4;
	__restfpr_24(ctx, base);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216F7A8"))) PPC_WEAK_FUNC(sub_8216F7A8);
PPC_FUNC_IMPL(__imp__sub_8216F7A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8216F7B0;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8216F7EC;
	sub_820601F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d3a20
	ctx.lr = 0x8216F7F8;
	sub_821D3A20(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// bl 0x8216f398
	ctx.lr = 0x8216F80C;
	sub_8216F398(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8216f820
	if (ctx.cr6.lt) goto loc_8216F820;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8216F820;
	sub_8207A630(ctx, base);
loc_8216F820:
	// stw r28,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216F838"))) PPC_WEAK_FUNC(sub_8216F838);
PPC_FUNC_IMPL(__imp__sub_8216F838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8216F840;
	__savegprlr_25(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r27,r3,60
	ctx.r27.s64 = ctx.r3.s64 + 60;
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r9,37(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 37);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8216f890
	if (!ctx.cr6.eq) goto loc_8216F890;
loc_8216F868:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r26
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x8216f87c
	if (!ctx.cr6.lt) goto loc_8216F87C;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8216f884
	goto loc_8216F884;
loc_8216F87C:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8216F884:
	// lbz r9,37(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 37);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216f868
	if (ctx.cr6.eq) goto loc_8216F868;
loc_8216F890:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r9,24(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x8216f8b0
	if (ctx.cr6.eq) goto loc_8216F8B0;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216f8b4
	if (ctx.cr6.eq) goto loc_8216F8B4;
loc_8216F8B0:
	// twi 31,r0,22
loc_8216F8B4:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8216f8d0
	if (ctx.cr6.eq) goto loc_8216F8D0;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8216f8d0
	if (ctx.cr6.lt) goto loc_8216F8D0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// b 0x8216f8dc
	goto loc_8216F8DC;
loc_8216F8D0:
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_8216F8DC:
	// ld r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// lwz r9,24(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216f900
	if (ctx.cr6.eq) goto loc_8216F900;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216f904
	if (ctx.cr6.eq) goto loc_8216F904;
loc_8216F900:
	// twi 31,r0,22
loc_8216F904:
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8216f95c
	if (ctx.cr6.eq) goto loc_8216F95C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216f954
	if (!ctx.cr6.eq) goto loc_8216F954;
	// twi 31,r0,22
loc_8216F91C:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8216f92c
	if (!ctx.cr6.eq) goto loc_8216F92C;
	// twi 31,r0,22
loc_8216F92C:
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r11,r10,12
	ctx.r11.s64 = ctx.r10.s64 + 12;
	// addi r10,r28,-4
	ctx.r10.s64 = ctx.r28.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8216F93C:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8216f93c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216F93C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8216F954:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8216f91c
	goto loc_8216F91C;
loc_8216F95C:
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,7
	ctx.r30.s64 = 7;
	// stw r29,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r30.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// sth r29,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, ctx.r29.u16);
	// clrlwi r31,r26,16
	ctx.r31.u64 = ctx.r26.u32 & 0xFFFF;
	// bl 0x82064328
	ctx.lr = 0x8216F980;
	sub_82064328(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216f9cc
	if (ctx.cr6.eq) goto loc_8216F9CC;
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bge cr6,0x8216f9a0
	if (!ctx.cr6.lt) goto loc_8216F9A0;
	// addi r11,r1,148
	ctx.r11.s64 = ctx.r1.s64 + 148;
loc_8216F9A0:
	// lwz r10,164(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r31,r8,r11
	PPC_STORE_U16(ctx.r8.u32 + ctx.r11.u32, ctx.r31.u16);
	// lwz r7,168(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// cmplwi cr6,r7,8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 8, ctx.xer);
	// lwz r11,148(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// stw r9,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// bge cr6,0x8216f9c8
	if (!ctx.cr6.lt) goto loc_8216F9C8;
	// addi r11,r1,148
	ctx.r11.s64 = ctx.r1.s64 + 148;
loc_8216F9C8:
	// sth r29,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r29.u16);
loc_8216F9CC:
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r30.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r29,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r29.u16);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x8216F9EC;
	sub_82063CC8(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821d3b40
	ctx.lr = 0x8216F9F8;
	sub_821D3B40(ctx, base);
	// lwz r11,200(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// bge cr6,0x8216fa14
	if (!ctx.cr6.lt) goto loc_8216FA14;
	// addi r4,r1,180
	ctx.r4.s64 = ctx.r1.s64 + 180;
loc_8216FA14:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,28
	ctx.r3.s64 = ctx.r25.s64 + 28;
	// bl 0x821753c8
	ctx.lr = 0x8216FA20;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216fae0
	if (ctx.cr6.eq) goto loc_8216FAE0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,-21468
	ctx.r31.s64 = ctx.r11.s64 + -21468;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r5,r31,-20
	ctx.r5.s64 = ctx.r31.s64 + -20;
	// bl 0x82175ae8
	ctx.lr = 0x8216FA48;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8216FA4C;
	sub_82175D08(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// addi r5,r31,-16
	ctx.r5.s64 = ctx.r31.s64 + -16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8216FA60;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8216FA64;
	sub_82175BB0(ctx, base);
	// stfs f1,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// addi r5,r31,-12
	ctx.r5.s64 = ctx.r31.s64 + -12;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8216FA78;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8216FA7C;
	sub_82175BB0(ctx, base);
	// stfs f1,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// addi r5,r31,-8
	ctx.r5.s64 = ctx.r31.s64 + -8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8216FA90;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8216FA94;
	sub_82175BB0(ctx, base);
	// stfs f1,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8216FAA8;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8216FAAC;
	sub_82175BB0(ctx, base);
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f1,16(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16, temp.u32);
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r26.u32);
	// addi r11,r28,-4
	ctx.r11.s64 = ctx.r28.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8216FAC4:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8216fac4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216FAC4;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x820747d0
	ctx.lr = 0x8216FAE0;
	sub_820747D0(ctx, base);
loc_8216FAE0:
	// lwz r11,200(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8216faf4
	if (ctx.cr6.lt) goto loc_8216FAF4;
	// lwz r3,180(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x8207a630
	ctx.lr = 0x8216FAF4;
	sub_8207A630(ctx, base);
loc_8216FAF4:
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r29,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r29.u32);
	// stw r10,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r10.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// stb r29,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r29.u8);
	// blt cr6,0x8216fb18
	if (ctx.cr6.lt) goto loc_8216FB18;
	// lwz r3,148(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x8207a630
	ctx.lr = 0x8216FB18;
	sub_8207A630(ctx, base);
loc_8216FB18:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216FB24"))) PPC_WEAK_FUNC(sub_8216FB24);
PPC_FUNC_IMPL(__imp__sub_8216FB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216FB28"))) PPC_WEAK_FUNC(sub_8216FB28);
PPC_FUNC_IMPL(__imp__sub_8216FB28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8216f838
	ctx.lr = 0x8216FB3C;
	sub_8216F838(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216FB4C"))) PPC_WEAK_FUNC(sub_8216FB4C);
PPC_FUNC_IMPL(__imp__sub_8216FB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216FB50"))) PPC_WEAK_FUNC(sub_8216FB50);
PPC_FUNC_IMPL(__imp__sub_8216FB50) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8216f838
	ctx.lr = 0x8216FB7C;
	sub_8216F838(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216fbac
	if (ctx.cr6.eq) goto loc_8216FBAC;
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f11,0(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f10,4(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x8216fbbc
	goto loc_8216FBBC;
loc_8216FBAC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_8216FBBC:
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

__attribute__((alias("__imp__sub_8216FBD4"))) PPC_WEAK_FUNC(sub_8216FBD4);
PPC_FUNC_IMPL(__imp__sub_8216FBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216FBD8"))) PPC_WEAK_FUNC(sub_8216FBD8);
PPC_FUNC_IMPL(__imp__sub_8216FBD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8216FBE0;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r10,r11,5784
	ctx.r10.s64 = ctx.r11.s64 + 5784;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r31,r3,36
	ctx.r31.s64 = ctx.r3.s64 + 36;
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi. r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x8216fc70
	if (ctx.cr0.eq) goto loc_8216FC70;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
loc_8216FC18:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8216fc34
	if (ctx.cr6.lt) goto loc_8216FC34;
	// twi 31,r0,22
loc_8216FC34:
	// lwzx r28,r27,r11
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8216fc50
	if (ctx.cr6.eq) goto loc_8216FC50;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82167ee8
	ctx.lr = 0x8216FC48;
	sub_82167EE8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207a630
	ctx.lr = 0x8216FC50;
	sub_8207A630(ctx, base);
loc_8216FC50:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8216fc18
	if (ctx.cr6.lt) goto loc_8216FC18;
loc_8216FC70:
	// lwz r11,84(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// addi r4,r30,60
	ctx.r4.s64 = ctx.r30.s64 + 60;
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82074c78
	ctx.lr = 0x8216FCA0;
	sub_82074C78(ctx, base);
	// lwz r3,84(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8216FCA8;
	sub_8207A630(ctx, base);
	// stw r26,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r26.u32);
	// stw r26,88(r30)
	PPC_STORE_U32(ctx.r30.u32 + 88, ctx.r26.u32);
	// lwz r3,60(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// bl 0x8207a630
	ctx.lr = 0x8216FCB8;
	sub_8207A630(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216fcc8
	if (ctx.cr6.eq) goto loc_8216FCC8;
	// bl 0x8207a630
	ctx.lr = 0x8216FCC8;
	sub_8207A630(ctx, base);
loc_8216FCC8:
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// stw r26,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8216FCDC;
	sub_8207A630(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,5752
	ctx.r10.s64 = ctx.r11.s64 + 5752;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216FCF0"))) PPC_WEAK_FUNC(sub_8216FCF0);
PPC_FUNC_IMPL(__imp__sub_8216FCF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8216FCF8;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-2240(r1)
	ea = -2240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stfs f1,16(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r8,r10,5784
	ctx.r8.s64 = ctx.r10.s64 + 5784;
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r26,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r26.u32);
	// stw r26,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r26.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r27,r29,36
	ctx.r27.s64 = ctx.r29.s64 + 36;
	// bl 0x82079fd8
	ctx.lr = 0x8216FD44;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216fd54
	if (ctx.cr6.eq) goto loc_8216FD54;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
	// b 0x8216fd58
	goto loc_8216FD58;
loc_8216FD54:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_8216FD58:
	// stw r3,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r26,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r26.u32);
	// addi r30,r29,60
	ctx.r30.s64 = ctx.r29.s64 + 60;
	// stw r26,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r26.u32);
	// stw r26,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r26.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8216FD74;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216fd84
	if (ctx.cr6.eq) goto loc_8216FD84;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x8216fd88
	goto loc_8216FD88;
loc_8216FD84:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_8216FD88:
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82079fd8
	ctx.lr = 0x8216FD94;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216fda0
	if (ctx.cr6.eq) goto loc_8216FDA0;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
loc_8216FDA0:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8216fdac
	if (ctx.cr0.eq) goto loc_8216FDAC;
	// stw r26,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
loc_8216FDAC:
	// addic. r11,r3,8
	ctx.xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r11.s64 = ctx.r3.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8216fdb8
	if (ctx.cr0.eq) goto loc_8216FDB8;
	// stw r26,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
loc_8216FDB8:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r26,37(r3)
	PPC_STORE_U8(ctx.r3.u32 + 37, ctx.r26.u8);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// stb r10,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r10.u8);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r3,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// addi r31,r11,-21832
	ctx.r31.s64 = ctx.r11.s64 + -21832;
	// stb r10,37(r3)
	PPC_STORE_U8(ctx.r3.u32 + 37, ctx.r10.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r4,r31,8
	ctx.r4.s64 = ctx.r31.s64 + 8;
	// stw r11,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r10,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// stw r9,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r9.u32);
	// stw r26,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r26.u32);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// bl 0x821753c8
	ctx.lr = 0x8216FE18;
	sub_821753C8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8216fff4
	if (ctx.cr6.eq) goto loc_8216FFF4;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// bl 0x821749c8
	ctx.lr = 0x8216FE30;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82175150
	ctx.lr = 0x8216FE3C;
	sub_82175150(ctx, base);
loc_8216FE3C:
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// beq cr6,0x8216fe60
	if (ctx.cr6.eq) goto loc_8216FE60;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8216fe3c
	if (ctx.cr6.eq) goto loc_8216FE3C;
loc_8216FE60:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8216fff4
	if (!ctx.cr6.eq) goto loc_8216FFF4;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r5,r31,48
	ctx.r5.s64 = ctx.r31.s64 + 48;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8216FE88;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8216FE94;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8216FEA0;
	sub_82175150(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,-31868(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31868);
loc_8216FEA8:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// beq cr6,0x8216fecc
	if (ctx.cr6.eq) goto loc_8216FECC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8216fea8
	if (ctx.cr6.eq) goto loc_8216FEA8;
loc_8216FECC:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// beq cr6,0x8216ff24
	if (ctx.cr6.eq) goto loc_8216FF24;
	// addi r5,r31,56
	ctx.r5.s64 = ctx.r31.s64 + 56;
	// bl 0x82175ae8
	ctx.lr = 0x8216FEF4;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8216FF00;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8216FF0C;
	sub_82175150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,64
	ctx.r4.s64 = ctx.r31.s64 + 64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8207a8a8
	ctx.lr = 0x8216FF1C;
	sub_8207A8A8(ctx, base);
	// bl 0x8210e878
	ctx.lr = 0x8216FF20;
	sub_8210E878(ctx, base);
	// b 0x8216fffc
	goto loc_8216FFFC;
loc_8216FF24:
	// addi r5,r31,136
	ctx.r5.s64 = ctx.r31.s64 + 136;
	// bl 0x82175ae8
	ctx.lr = 0x8216FF2C;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8216FF30;
	sub_82175BB0(ctx, base);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lfs f0,-4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bge cr6,0x8216ff8c
	if (!ctx.cr6.lt) goto loc_8216FF8C;
	// addi r5,r31,144
	ctx.r5.s64 = ctx.r31.s64 + 144;
	// bl 0x82175ae8
	ctx.lr = 0x8216FF5C;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8216FF68;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8216FF74;
	sub_82175150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,152
	ctx.r4.s64 = ctx.r31.s64 + 152;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8207a8a8
	ctx.lr = 0x8216FF84;
	sub_8207A8A8(ctx, base);
	// bl 0x8210e878
	ctx.lr = 0x8216FF88;
	sub_8210E878(ctx, base);
	// b 0x8216fffc
	goto loc_8216FFFC;
loc_8216FF8C:
	// addi r5,r31,236
	ctx.r5.s64 = ctx.r31.s64 + 236;
	// bl 0x82175ae8
	ctx.lr = 0x8216FF94;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8216FF98;
	sub_82175BB0(ctx, base);
	// lfs f0,-4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8216fffc
	if (!ctx.cr6.gt) goto loc_8216FFFC;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r5,r31,244
	ctx.r5.s64 = ctx.r31.s64 + 244;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8216FFC4;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8216FFD0;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8216FFDC;
	sub_82175150(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,252
	ctx.r4.s64 = ctx.r31.s64 + 252;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8207a8a8
	ctx.lr = 0x8216FFEC;
	sub_8207A8A8(ctx, base);
	// bl 0x8210e878
	ctx.lr = 0x8216FFF0;
	sub_8210E878(ctx, base);
	// b 0x8216fffc
	goto loc_8216FFFC;
loc_8216FFF4:
	// bl 0x8210e878
	ctx.lr = 0x8216FFF8;
	sub_8210E878(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8216FFFC;
	sub_8207B288(ctx, base);
loc_8216FFFC:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r5,r31,304
	ctx.r5.s64 = ctx.r31.s64 + 304;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// bl 0x82175ae8
	ctx.lr = 0x82170028;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217002C;
	sub_82175BB0(ctx, base);
	// lfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r31,316
	ctx.r5.s64 = ctx.r31.s64 + 316;
	// fmuls f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x82170044;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x82170048;
	sub_82175BB0(ctx, base);
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f12,20(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r29.u32 + 20, temp.u32);
	// stfs f31,24(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 24, temp.u32);
	// addi r5,r31,328
	ctx.r5.s64 = ctx.r31.s64 + 328;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82175ae8
	ctx.lr = 0x82170078;
	sub_82175AE8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r5,r31,336
	ctx.r5.s64 = ctx.r31.s64 + 336;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r10.u32);
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r9,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r9.u32);
	// lwz r8,44(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82175ae8
	ctx.lr = 0x821700AC;
	sub_82175AE8(ctx, base);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// addi r28,r7,1
	ctx.r28.s64 = ctx.r7.s64 + 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82174af8
	ctx.lr = 0x821700C0;
	sub_82174AF8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217018c
	if (ctx.cr6.eq) goto loc_8217018C;
loc_821700C8:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82079fd8
	ctx.lr = 0x821700D0;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82170100
	if (ctx.cr6.eq) goto loc_82170100;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175648
	ctx.lr = 0x821700EC;
	sub_82175648(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// bl 0x821680d0
	ctx.lr = 0x821700FC;
	sub_821680D0(ctx, base);
	// b 0x82170104
	goto loc_82170104;
loc_82170100:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_82170104:
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217011c
	if (!ctx.cr6.eq) goto loc_8217011C;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// b 0x82170128
	goto loc_82170128;
loc_8217011C:
	// lwz r11,20(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_82170128:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8217014c
	if (!ctx.cr6.lt) goto loc_8217014C;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// stw r10,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r10.u32);
	// b 0x82170178
	goto loc_82170178;
loc_8217014C:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82170158
	if (!ctx.cr6.gt) goto loc_82170158;
	// twi 31,r0,22
loc_82170158:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x820697e0
	ctx.lr = 0x82170178;
	sub_820697E0(ctx, base);
loc_82170178:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x82170184;
	sub_82174AF8(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x821700c8
	if (ctx.cr6.lt) goto loc_821700C8;
loc_8217018C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,2240
	ctx.r1.s64 = ctx.r1.s64 + 2240;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217019C"))) PPC_WEAK_FUNC(sub_8217019C);
PPC_FUNC_IMPL(__imp__sub_8217019C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821701A0"))) PPC_WEAK_FUNC(sub_821701A0);
PPC_FUNC_IMPL(__imp__sub_821701A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31328(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31328);
	// lbz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821701bc
	if (ctx.cr6.eq) goto loc_821701BC;
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_821701BC:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821701D4"))) PPC_WEAK_FUNC(sub_821701D4);
PPC_FUNC_IMPL(__imp__sub_821701D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821701D8"))) PPC_WEAK_FUNC(sub_821701D8);
PPC_FUNC_IMPL(__imp__sub_821701D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821701EC"))) PPC_WEAK_FUNC(sub_821701EC);
PPC_FUNC_IMPL(__imp__sub_821701EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821701F0"))) PPC_WEAK_FUNC(sub_821701F0);
PPC_FUNC_IMPL(__imp__sub_821701F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82170214"))) PPC_WEAK_FUNC(sub_82170214);
PPC_FUNC_IMPL(__imp__sub_82170214) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170218"))) PPC_WEAK_FUNC(sub_82170218);
PPC_FUNC_IMPL(__imp__sub_82170218) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8217023C"))) PPC_WEAK_FUNC(sub_8217023C);
PPC_FUNC_IMPL(__imp__sub_8217023C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170240"))) PPC_WEAK_FUNC(sub_82170240);
PPC_FUNC_IMPL(__imp__sub_82170240) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82170264"))) PPC_WEAK_FUNC(sub_82170264);
PPC_FUNC_IMPL(__imp__sub_82170264) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170268"))) PPC_WEAK_FUNC(sub_82170268);
PPC_FUNC_IMPL(__imp__sub_82170268) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,116
	ctx.r3.s64 = ctx.r3.s64 + 116;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82170288"))) PPC_WEAK_FUNC(sub_82170288);
PPC_FUNC_IMPL(__imp__sub_82170288) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217028C"))) PPC_WEAK_FUNC(sub_8217028C);
PPC_FUNC_IMPL(__imp__sub_8217028C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170290"))) PPC_WEAK_FUNC(sub_82170290);
PPC_FUNC_IMPL(__imp__sub_82170290) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,5740
	ctx.r9.s64 = ctx.r10.s64 + 5740;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821702B0"))) PPC_WEAK_FUNC(sub_821702B0);
PPC_FUNC_IMPL(__imp__sub_821702B0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,5728
	ctx.r9.s64 = ctx.r10.s64 + 5728;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821702D0"))) PPC_WEAK_FUNC(sub_821702D0);
PPC_FUNC_IMPL(__imp__sub_821702D0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,5708
	ctx.r9.s64 = ctx.r10.s64 + 5708;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821702F0"))) PPC_WEAK_FUNC(sub_821702F0);
PPC_FUNC_IMPL(__imp__sub_821702F0) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821702FC"))) PPC_WEAK_FUNC(sub_821702FC);
PPC_FUNC_IMPL(__imp__sub_821702FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170300"))) PPC_WEAK_FUNC(sub_82170300);
PPC_FUNC_IMPL(__imp__sub_82170300) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217030C"))) PPC_WEAK_FUNC(sub_8217030C);
PPC_FUNC_IMPL(__imp__sub_8217030C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170310"))) PPC_WEAK_FUNC(sub_82170310);
PPC_FUNC_IMPL(__imp__sub_82170310) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,5688
	ctx.r9.s64 = ctx.r10.s64 + 5688;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170330"))) PPC_WEAK_FUNC(sub_82170330);
PPC_FUNC_IMPL(__imp__sub_82170330) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-31328(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31328);
	// addi r9,r11,116
	ctx.r9.s64 = ctx.r11.s64 + 116;
	// lwz r7,136(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// stw r10,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r10.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170358"))) PPC_WEAK_FUNC(sub_82170358);
PPC_FUNC_IMPL(__imp__sub_82170358) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82170360;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,5676
	ctx.r10.s64 = ctx.r11.s64 + 5676;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82170394
	if (ctx.cr6.eq) goto loc_82170394;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170394;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170394:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821703A8;
	sub_82173A18(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// addi r29,r10,-1456
	ctx.r29.s64 = ctx.r10.s64 + -1456;
	// stw r29,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r29.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821703C0;
	sub_82173A18(ctx, base);
	// stw r29,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r29.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// bl 0x82173a18
	ctx.lr = 0x821703D0;
	sub_82173A18(ctx, base);
	// stw r29,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r29.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// addi r3,r31,32
	ctx.r3.s64 = ctx.r31.s64 + 32;
	// bl 0x82173a18
	ctx.lr = 0x821703E0;
	sub_82173A18(ctx, base);
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821703EC"))) PPC_WEAK_FUNC(sub_821703EC);
PPC_FUNC_IMPL(__imp__sub_821703EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821703F0"))) PPC_WEAK_FUNC(sub_821703F0);
PPC_FUNC_IMPL(__imp__sub_821703F0) {
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
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// addi r3,r6,5720
	ctx.r3.s64 = ctx.r6.s64 + 5720;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// lwz r11,-31328(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31328);
	// addi r3,r11,88
	ctx.r3.s64 = ctx.r11.s64 + 88;
	// bl 0x82173a70
	ctx.lr = 0x82170420;
	sub_82173A70(ctx, base);
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82170440
	if (ctx.cr6.eq) goto loc_82170440;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170440;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170440:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170450"))) PPC_WEAK_FUNC(sub_82170450);
PPC_FUNC_IMPL(__imp__sub_82170450) {
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
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,5720
	ctx.r9.s64 = ctx.r11.s64 + 5720;
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82170480;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x821704ac
	if (ctx.cr6.eq) goto loc_821704AC;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r8,r10,5728
	ctx.r8.s64 = ctx.r10.s64 + 5728;
	// stb r9,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x821704b0
	goto loc_821704B0;
loc_821704AC:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_821704B0:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,-31328(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31328);
	// addi r7,r10,88
	ctx.r7.s64 = ctx.r10.s64 + 88;
	// lwz r7,108(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r8,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_821704EC"))) PPC_WEAK_FUNC(sub_821704EC);
PPC_FUNC_IMPL(__imp__sub_821704EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821704F0"))) PPC_WEAK_FUNC(sub_821704F0);
PPC_FUNC_IMPL(__imp__sub_821704F0) {
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
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// addi r3,r6,5700
	ctx.r3.s64 = ctx.r6.s64 + 5700;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// lwz r11,-31328(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31328);
	// addi r3,r11,60
	ctx.r3.s64 = ctx.r11.s64 + 60;
	// bl 0x82173a70
	ctx.lr = 0x82170520;
	sub_82173A70(ctx, base);
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82170540
	if (ctx.cr6.eq) goto loc_82170540;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170540;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170540:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170550"))) PPC_WEAK_FUNC(sub_82170550);
PPC_FUNC_IMPL(__imp__sub_82170550) {
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
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,5700
	ctx.r9.s64 = ctx.r11.s64 + 5700;
	// stb r10,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r10.u8);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82170580;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x821705ac
	if (ctx.cr6.eq) goto loc_821705AC;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r8,r10,5708
	ctx.r8.s64 = ctx.r10.s64 + 5708;
	// stb r9,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x821705b0
	goto loc_821705B0;
loc_821705AC:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_821705B0:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,-31328(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31328);
	// addi r7,r10,60
	ctx.r7.s64 = ctx.r10.s64 + 60;
	// lwz r7,80(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r8,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_821705EC"))) PPC_WEAK_FUNC(sub_821705EC);
PPC_FUNC_IMPL(__imp__sub_821705EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821705F0"))) PPC_WEAK_FUNC(sub_821705F0);
PPC_FUNC_IMPL(__imp__sub_821705F0) {
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
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// addi r3,r6,5680
	ctx.r3.s64 = ctx.r6.s64 + 5680;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// lwz r11,-31328(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31328);
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82173a70
	ctx.lr = 0x82170620;
	sub_82173A70(ctx, base);
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82170640
	if (ctx.cr6.eq) goto loc_82170640;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170640;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170640:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170650"))) PPC_WEAK_FUNC(sub_82170650);
PPC_FUNC_IMPL(__imp__sub_82170650) {
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
	// stb r4,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r4.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r3,20
	ctx.r3.s64 = 20;
	// addi r10,r11,5680
	ctx.r10.s64 = ctx.r11.s64 + 5680;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217067C;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x821706a8
	if (ctx.cr6.eq) goto loc_821706A8;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r8,r10,5688
	ctx.r8.s64 = ctx.r10.s64 + 5688;
	// stb r9,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r9.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// b 0x821706ac
	goto loc_821706AC;
loc_821706A8:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_821706AC:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,-31328(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31328);
	// addi r7,r10,32
	ctx.r7.s64 = ctx.r10.s64 + 32;
	// lwz r7,52(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r8,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_821706E8"))) PPC_WEAK_FUNC(sub_821706E8);
PPC_FUNC_IMPL(__imp__sub_821706E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821706F0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r26,-32224
	ctx.r26.s64 = -2111832064;
	// li r25,1
	ctx.r25.s64 = 1;
	// lwz r31,-31328(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31328);
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// addi r28,r31,32
	ctx.r28.s64 = ctx.r31.s64 + 32;
	// addi r24,r31,116
	ctx.r24.s64 = ctx.r31.s64 + 116;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r3,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r3.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
loc_82170724:
	// lbz r11,29(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 29);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821707b8
	if (!ctx.cr6.eq) goto loc_821707B8;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r3,r31,60
	ctx.r3.s64 = ctx.r31.s64 + 60;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82170750
	if (!ctx.cr6.eq) goto loc_82170750;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170750;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170750:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82170770
	if (!ctx.cr6.eq) goto loc_82170770;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170770;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170770:
	// lbz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82170794
	if (!ctx.cr6.eq) goto loc_82170794;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170794;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170794:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821707bc
	if (!ctx.cr6.eq) goto loc_821707BC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821707B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x821707bc
	goto loc_821707BC;
loc_821707B8:
	// stb r29,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r29.u8);
loc_821707BC:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x821707e4
	if (!ctx.cr6.eq) goto loc_821707E4;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821707E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_821707E4:
	// lwz r11,-31324(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31324);
	// stb r25,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r25.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821707f8
	if (ctx.cr6.eq) goto loc_821707F8;
	// bl 0x8216ea68
	ctx.lr = 0x821707F8;
	sub_8216EA68(ctx, base);
loc_821707F8:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// stb r29,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r29.u8);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// lwz r8,8(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r11,-31296(r27)
	PPC_STORE_U32(ctx.r27.u32 + -31296, ctx.r11.u32);
	// bne cr6,0x82170844
	if (!ctx.cr6.eq) goto loc_82170844;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170844;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170844:
	// lwz r11,8(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82170864
	if (!ctx.cr6.eq) goto loc_82170864;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170864;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82170864:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82170878
	if (ctx.cr6.eq) goto loc_82170878;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82170724
	if (ctx.cr6.eq) goto loc_82170724;
loc_82170878:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82170880"))) PPC_WEAK_FUNC(sub_82170880);
PPC_FUNC_IMPL(__imp__sub_82170880) {
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
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r8,5676
	ctx.r7.s64 = ctx.r8.s64 + 5676;
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// addi r9,r3,60
	ctx.r9.s64 = ctx.r3.s64 + 60;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// addi r5,r6,840
	ctx.r5.s64 = ctx.r6.s64 + 840;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r8,r3,88
	ctx.r8.s64 = ctx.r3.s64 + 88;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// stb r30,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r30.u8);
	// li r3,20
	ctx.r3.s64 = 20;
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// addi r9,r31,116
	ctx.r9.s64 = ctx.r31.s64 + 116;
	// stb r30,44(r31)
	PPC_STORE_U8(ctx.r31.u32 + 44, ctx.r30.u8);
	// stb r30,45(r31)
	PPC_STORE_U8(ctx.r31.u32 + 45, ctx.r30.u8);
	// stb r30,47(r31)
	PPC_STORE_U8(ctx.r31.u32 + 47, ctx.r30.u8);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r5,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r5.u32);
	// stb r30,46(r31)
	PPC_STORE_U8(ctx.r31.u32 + 46, ctx.r30.u8);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// addi r10,r8,16
	ctx.r10.s64 = ctx.r8.s64 + 16;
	// stw r30,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// stb r30,72(r31)
	PPC_STORE_U8(ctx.r31.u32 + 72, ctx.r30.u8);
	// stb r30,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r30.u8);
	// stb r30,75(r31)
	PPC_STORE_U8(ctx.r31.u32 + 75, ctx.r30.u8);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// stw r5,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r5.u32);
	// stb r30,74(r31)
	PPC_STORE_U8(ctx.r31.u32 + 74, ctx.r30.u8);
	// stw r10,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r10.u32);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stb r30,100(r31)
	PPC_STORE_U8(ctx.r31.u32 + 100, ctx.r30.u8);
	// stb r30,101(r31)
	PPC_STORE_U8(ctx.r31.u32 + 101, ctx.r30.u8);
	// stb r30,103(r31)
	PPC_STORE_U8(ctx.r31.u32 + 103, ctx.r30.u8);
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r5,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// stb r30,102(r31)
	PPC_STORE_U8(ctx.r31.u32 + 102, ctx.r30.u8);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// stb r30,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r30.u8);
	// stb r30,129(r31)
	PPC_STORE_U8(ctx.r31.u32 + 129, ctx.r30.u8);
	// stb r30,131(r31)
	PPC_STORE_U8(ctx.r31.u32 + 131, ctx.r30.u8);
	// stw r30,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// stw r5,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r5.u32);
	// stb r30,130(r31)
	PPC_STORE_U8(ctx.r31.u32 + 130, ctx.r30.u8);
	// stb r11,45(r31)
	PPC_STORE_U8(ctx.r31.u32 + 45, ctx.r11.u8);
	// stb r11,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r11.u8);
	// stb r11,101(r31)
	PPC_STORE_U8(ctx.r31.u32 + 101, ctx.r11.u8);
	// stb r11,47(r31)
	PPC_STORE_U8(ctx.r31.u32 + 47, ctx.r11.u8);
	// stb r11,75(r31)
	PPC_STORE_U8(ctx.r31.u32 + 75, ctx.r11.u8);
	// stb r11,103(r31)
	PPC_STORE_U8(ctx.r31.u32 + 103, ctx.r11.u8);
	// stw r31,-31328(r4)
	PPC_STORE_U32(ctx.r4.u32 + -31328, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821709A4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821709cc
	if (ctx.cr6.eq) goto loc_821709CC;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,5740
	ctx.r9.s64 = ctx.r10.s64 + 5740;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x821709d0
	goto loc_821709D0;
loc_821709CC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821709D0:
	// stw r11,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_821709F4"))) PPC_WEAK_FUNC(sub_821709F4);
PPC_FUNC_IMPL(__imp__sub_821709F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821709F8"))) PPC_WEAK_FUNC(sub_821709F8);
PPC_FUNC_IMPL(__imp__sub_821709F8) {
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
	// li r3,156
	ctx.r3.s64 = 156;
	// bl 0x82079fd8
	ctx.lr = 0x82170A0C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82170a30
	if (ctx.cr6.eq) goto loc_82170A30;
	// bl 0x82170880
	ctx.lr = 0x82170A18;
	sub_82170880(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,-31328(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31328, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82170A30:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31328(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31328, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170A4C"))) PPC_WEAK_FUNC(sub_82170A4C);
PPC_FUNC_IMPL(__imp__sub_82170A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170A50"))) PPC_WEAK_FUNC(sub_82170A50);
PPC_FUNC_IMPL(__imp__sub_82170A50) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170A58"))) PPC_WEAK_FUNC(sub_82170A58);
PPC_FUNC_IMPL(__imp__sub_82170A58) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170A60"))) PPC_WEAK_FUNC(sub_82170A60);
PPC_FUNC_IMPL(__imp__sub_82170A60) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170A64"))) PPC_WEAK_FUNC(sub_82170A64);
PPC_FUNC_IMPL(__imp__sub_82170A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170A68"))) PPC_WEAK_FUNC(sub_82170A68);
PPC_FUNC_IMPL(__imp__sub_82170A68) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82170A74"))) PPC_WEAK_FUNC(sub_82170A74);
PPC_FUNC_IMPL(__imp__sub_82170A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170A78"))) PPC_WEAK_FUNC(sub_82170A78);
PPC_FUNC_IMPL(__imp__sub_82170A78) {
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
	// lwz r4,84(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170AA0;
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

__attribute__((alias("__imp__sub_82170AB8"))) PPC_WEAK_FUNC(sub_82170AB8);
PPC_FUNC_IMPL(__imp__sub_82170AB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,84(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170AC0"))) PPC_WEAK_FUNC(sub_82170AC0);
PPC_FUNC_IMPL(__imp__sub_82170AC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82170AD4"))) PPC_WEAK_FUNC(sub_82170AD4);
PPC_FUNC_IMPL(__imp__sub_82170AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170AD8"))) PPC_WEAK_FUNC(sub_82170AD8);
PPC_FUNC_IMPL(__imp__sub_82170AD8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170B08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82170B20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170B38"))) PPC_WEAK_FUNC(sub_82170B38);
PPC_FUNC_IMPL(__imp__sub_82170B38) {
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
	// lwz r4,80(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170B60;
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

__attribute__((alias("__imp__sub_82170B78"))) PPC_WEAK_FUNC(sub_82170B78);
PPC_FUNC_IMPL(__imp__sub_82170B78) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170B80"))) PPC_WEAK_FUNC(sub_82170B80);
PPC_FUNC_IMPL(__imp__sub_82170B80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170B88"))) PPC_WEAK_FUNC(sub_82170B88);
PPC_FUNC_IMPL(__imp__sub_82170B88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170B90"))) PPC_WEAK_FUNC(sub_82170B90);
PPC_FUNC_IMPL(__imp__sub_82170B90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// lfs f11,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,76(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f0,f12
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fadds f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// stfs f10,84(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f9,88(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170BB8"))) PPC_WEAK_FUNC(sub_82170BB8);
PPC_FUNC_IMPL(__imp__sub_82170BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// lfs f13,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,76(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r3,76
	ctx.r11.s64 = ctx.r3.s64 + 76;
	// lfs f10,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fsubs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// lfs f8,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// fadds f6,f11,f8
	ctx.f6.f64 = double(float(ctx.f11.f64 + ctx.f8.f64));
	// stfs f0,76(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f13,80(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f6,84(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// fadds f5,f9,f7
	ctx.f5.f64 = double(float(ctx.f9.f64 + ctx.f7.f64));
	// stfs f5,88(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170BFC"))) PPC_WEAK_FUNC(sub_82170BFC);
PPC_FUNC_IMPL(__imp__sub_82170BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170C00"))) PPC_WEAK_FUNC(sub_82170C00);
PPC_FUNC_IMPL(__imp__sub_82170C00) {
	PPC_FUNC_PROLOGUE();
	// stb r4,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170C08"))) PPC_WEAK_FUNC(sub_82170C08);
PPC_FUNC_IMPL(__imp__sub_82170C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170C10"))) PPC_WEAK_FUNC(sub_82170C10);
PPC_FUNC_IMPL(__imp__sub_82170C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170C18"))) PPC_WEAK_FUNC(sub_82170C18);
PPC_FUNC_IMPL(__imp__sub_82170C18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,80(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// lwz r10,84(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170C2C"))) PPC_WEAK_FUNC(sub_82170C2C);
PPC_FUNC_IMPL(__imp__sub_82170C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170C30"))) PPC_WEAK_FUNC(sub_82170C30);
PPC_FUNC_IMPL(__imp__sub_82170C30) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,208(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r11,212(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82170c44
	if (!ctx.cr6.gt) goto loc_82170C44;
	// twi 31,r0,22
loc_82170C44:
	// lwz r10,212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// lwz r11,208(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r9,196(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82170c5c
	if (!ctx.cr6.gt) goto loc_82170C5C;
	// twi 31,r0,22
loc_82170C5C:
	// lwz r11,208(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r7,212(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x82170c70
	if (!ctx.cr6.gt) goto loc_82170C70;
	// twi 31,r0,22
loc_82170C70:
	// lwz r7,196(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// stw r7,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r7.u32);
	// ld r6,-16(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// beq cr6,0x82170ca4
	if (ctx.cr6.eq) goto loc_82170CA4;
loc_82170C8C:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82170ca4
	if (ctx.cr6.eq) goto loc_82170CA4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82170c8c
	if (!ctx.cr6.eq) goto loc_82170C8C;
loc_82170CA4:
	// lwz r10,-16(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82170cb8
	if (ctx.cr6.eq) goto loc_82170CB8;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82170cbc
	if (ctx.cr6.eq) goto loc_82170CBC;
loc_82170CB8:
	// twi 31,r0,22
loc_82170CBC:
	// lwz r10,220(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// subf r9,r8,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r8.s64;
	// li r8,2
	ctx.r8.s64 = 2;
	// srawi r7,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170CD8"))) PPC_WEAK_FUNC(sub_82170CD8);
PPC_FUNC_IMPL(__imp__sub_82170CD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82170CE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82170dc8
	if (ctx.cr6.eq) goto loc_82170DC8;
	// lwz r10,224(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r5,r6,-2064
	ctx.r5.s64 = ctx.r6.s64 + -2064;
	// stb r9,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r9.u8);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r4,76(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r3,224(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// lfs f0,28(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// lwz r6,84(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r5,88(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// ld r10,228(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 228);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// stw r6,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// stw r5,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r5.u32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// stw r6,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r6.u32);
	// stw r5,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r5.u32);
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lwz r28,0(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f6,f13,f12
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fmuls f4,f6,f11
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f5,f7,f10
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// fmuls f2,f4,f0
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// stfs f2,80(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x82170DC0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82170DC8:
	// lwz r11,224(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r10.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82170DDC"))) PPC_WEAK_FUNC(sub_82170DDC);
PPC_FUNC_IMPL(__imp__sub_82170DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170DE0"))) PPC_WEAK_FUNC(sub_82170DE0);
PPC_FUNC_IMPL(__imp__sub_82170DE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,228(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 228);
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82170e00
	if (!ctx.cr6.eq) goto loc_82170E00;
	// lwz r10,236(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 236);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
loc_82170E00:
	// lwz r10,232(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r10,236(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 236);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170E20"))) PPC_WEAK_FUNC(sub_82170E20);
PPC_FUNC_IMPL(__imp__sub_82170E20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82170E28;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r9,r10,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82170f10
	if (ctx.cr6.eq) goto loc_82170F10;
	// lwz r10,240(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 240);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r5,r6,-2064
	ctx.r5.s64 = ctx.r6.s64 + -2064;
	// stb r9,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r9.u8);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r4,76(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r3,240(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 240);
	// lfs f0,28(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// lwz r6,84(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r5,88(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
	// ld r10,228(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 228);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// stw r6,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// stw r5,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r5.u32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// stw r6,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r6.u32);
	// stw r5,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r5.u32);
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lwz r28,0(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f6,f13,f12
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fmuls f4,f6,f11
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fmuls f5,f7,f10
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// fmuls f2,f4,f0
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// stfs f2,80(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x82170F08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82170F10:
	// lwz r11,240(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 240);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r10.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82170F24"))) PPC_WEAK_FUNC(sub_82170F24);
PPC_FUNC_IMPL(__imp__sub_82170F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170F28"))) PPC_WEAK_FUNC(sub_82170F28);
PPC_FUNC_IMPL(__imp__sub_82170F28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r11.u32);
	// beq 0x82170f58
	if (ctx.cr0.eq) goto loc_82170F58;
	// lwz r11,112(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
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
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_82170F58:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170F64"))) PPC_WEAK_FUNC(sub_82170F64);
PPC_FUNC_IMPL(__imp__sub_82170F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170F68"))) PPC_WEAK_FUNC(sub_82170F68);
PPC_FUNC_IMPL(__imp__sub_82170F68) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// stb r4,92(r10)
	PPC_STORE_U8(ctx.r10.u32 + 92, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170F78"))) PPC_WEAK_FUNC(sub_82170F78);
PPC_FUNC_IMPL(__imp__sub_82170F78) {
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
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82170FA0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170FB0"))) PPC_WEAK_FUNC(sub_82170FB0);
PPC_FUNC_IMPL(__imp__sub_82170FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,84(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,76(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f10,80(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f9,4(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170FD4"))) PPC_WEAK_FUNC(sub_82170FD4);
PPC_FUNC_IMPL(__imp__sub_82170FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170FD8"))) PPC_WEAK_FUNC(sub_82170FD8);
PPC_FUNC_IMPL(__imp__sub_82170FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,76(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82170FEC"))) PPC_WEAK_FUNC(sub_82170FEC);
PPC_FUNC_IMPL(__imp__sub_82170FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82170FF0"))) PPC_WEAK_FUNC(sub_82170FF0);
PPC_FUNC_IMPL(__imp__sub_82170FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// lfs f13,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f13,84(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82171008"))) PPC_WEAK_FUNC(sub_82171008);
PPC_FUNC_IMPL(__imp__sub_82171008) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// std r4,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r4.u64);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82171034;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r9,-2064
	ctx.r8.s64 = ctx.r9.s64 + -2064;
	// lfs f12,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f12.f64 = double(temp.f32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,76(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82171070;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_82171084"))) PPC_WEAK_FUNC(sub_82171084);
PPC_FUNC_IMPL(__imp__sub_82171084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171088"))) PPC_WEAK_FUNC(sub_82171088);
PPC_FUNC_IMPL(__imp__sub_82171088) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82171090;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r22,r9
	ctx.r22.u64 = ctx.r9.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r23,r8
	ctx.r23.u64 = ctx.r8.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// addi r10,r7,5408
	ctx.r10.s64 = ctx.r7.s64 + 5408;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// li r28,15
	ctx.r28.s64 = 15;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// li r26,-1
	ctx.r26.s64 = -1;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// stb r9,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r9.u8);
	// stw r28,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// stb r30,76(r31)
	PPC_STORE_U8(ctx.r31.u32 + 76, ctx.r30.u8);
	// bl 0x820601f8
	ctx.lr = 0x82171158;
	sub_820601F8(ctx, base);
	// stw r28,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r28.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// addi r3,r31,100
	ctx.r3.s64 = ctx.r31.s64 + 100;
	// stb r30,104(r31)
	PPC_STORE_U8(ctx.r31.u32 + 104, ctx.r30.u8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x820601f8
	ctx.lr = 0x82171178;
	sub_820601F8(ctx, base);
	// stw r28,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r28.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// addi r3,r31,128
	ctx.r3.s64 = ctx.r31.s64 + 128;
	// stb r30,132(r31)
	PPC_STORE_U8(ctx.r31.u32 + 132, ctx.r30.u8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x820601f8
	ctx.lr = 0x82171198;
	sub_820601F8(ctx, base);
	// stw r24,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r24.u32);
	// stw r23,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r23.u32);
	// stw r22,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r22.u32);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x821711b8
	if (ctx.cr6.lt) goto loc_821711B8;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821711B8;
	sub_8207A630(ctx, base);
loc_821711B8:
	// stw r28,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r28.u32);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stb r30,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r30.u8);
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821711d8
	if (ctx.cr6.lt) goto loc_821711D8;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821711D8;
	sub_8207A630(ctx, base);
loc_821711D8:
	// stw r28,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r28.u32);
	// stw r30,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r30.u32);
	// stb r30,4(r27)
	PPC_STORE_U8(ctx.r27.u32 + 4, ctx.r30.u8);
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821711f8
	if (ctx.cr6.lt) goto loc_821711F8;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821711F8;
	sub_8207A630(ctx, base);
loc_821711F8:
	// stw r28,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r30.u32);
	// stb r30,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r30.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82171210"))) PPC_WEAK_FUNC(sub_82171210);
PPC_FUNC_IMPL(__imp__sub_82171210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addi r9,r3,16
	ctx.r9.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r3,44
	ctx.r8.s64 = ctx.r3.s64 + 44;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r5,r10,-1396
	ctx.r5.s64 = ctx.r10.s64 + -1396;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r4,r9,840
	ctx.r4.s64 = ctx.r9.s64 + 840;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// addi r9,r8,16
	ctx.r9.s64 = ctx.r8.s64 + 16;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r8,r6,5484
	ctx.r8.s64 = ctx.r6.s64 + 5484;
	// stw r4,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lfs f0,21768(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stb r10,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r10.u8);
	// stb r10,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r10.u8);
	// stb r10,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r10.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,76(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stb r11,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821712B8"))) PPC_WEAK_FUNC(sub_821712B8);
PPC_FUNC_IMPL(__imp__sub_821712B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x821712C0;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,168
	ctx.r3.s64 = 168;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// bl 0x82079fd8
	ctx.lr = 0x821712E0;
	sub_82079FD8(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// li r29,15
	ctx.r29.s64 = 15;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq cr6,0x821713ac
	if (ctx.cr6.eq) goto loc_821713AC;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// li r27,-1
	ctx.r27.s64 = -1;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82171318;
	sub_820601F8(ctx, base);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x82171338;
	sub_820601F8(ctx, base);
	// stw r29,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r29.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x82171358;
	sub_820601F8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217136C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82171384;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r7,r23
	ctx.r7.u64 = ctx.r23.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// bl 0x82171088
	ctx.lr = 0x821713A4;
	sub_82171088(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x821713b0
	goto loc_821713B0;
loc_821713AC:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_821713B0:
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821713c4
	if (ctx.cr6.lt) goto loc_821713C4;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821713C4;
	sub_8207A630(ctx, base);
loc_821713C4:
	// stw r29,24(r26)
	PPC_STORE_U32(ctx.r26.u32 + 24, ctx.r29.u32);
	// stw r31,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r31.u32);
	// stb r31,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r31.u8);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821713e4
	if (ctx.cr6.lt) goto loc_821713E4;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821713E4;
	sub_8207A630(ctx, base);
loc_821713E4:
	// stw r29,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r29.u32);
	// stw r31,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r31.u32);
	// stb r31,4(r28)
	PPC_STORE_U8(ctx.r28.u32 + 4, ctx.r31.u8);
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82171404
	if (ctx.cr6.lt) goto loc_82171404;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82171404;
	sub_8207A630(ctx, base);
loc_82171404:
	// stw r29,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r31.u32);
	// stb r31,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r31.u8);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217141C"))) PPC_WEAK_FUNC(sub_8217141C);
PPC_FUNC_IMPL(__imp__sub_8217141C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171420"))) PPC_WEAK_FUNC(sub_82171420);
PPC_FUNC_IMPL(__imp__sub_82171420) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r3,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r3.u64);
	// lfs f13,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// lfs f12,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// std r5,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r5.u64);
	// lfs f11,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f10.f64 = double(temp.f32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// lfs f9,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f0,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d9b8
	ctx.lr = 0x82171494;
	sub_8216D9B8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821714A4"))) PPC_WEAK_FUNC(sub_821714A4);
PPC_FUNC_IMPL(__imp__sub_821714A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821714A8"))) PPC_WEAK_FUNC(sub_821714A8);
PPC_FUNC_IMPL(__imp__sub_821714A8) {
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
	// bl 0x8216a4d8
	ctx.lr = 0x821714C0;
	sub_8216A4D8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,5440
	ctx.r9.s64 = ctx.r11.s64 + 5440;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
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

__attribute__((alias("__imp__sub_821714F4"))) PPC_WEAK_FUNC(sub_821714F4);
PPC_FUNC_IMPL(__imp__sub_821714F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821714F8"))) PPC_WEAK_FUNC(sub_821714F8);
PPC_FUNC_IMPL(__imp__sub_821714F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82171500;
	__savegprlr_25(ctx, base);
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x8216a4d8
	ctx.lr = 0x82171520;
	sub_8216A4D8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r3,96
	ctx.r3.s64 = 96;
	// addi r10,r11,5528
	ctx.r10.s64 = ctx.r11.s64 + 5528;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82171534;
	sub_82079FD8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217154c
	if (ctx.cr6.eq) goto loc_8217154C;
	// bl 0x821650f0
	ctx.lr = 0x82171544;
	sub_821650F0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x82171550
	goto loc_82171550;
loc_8217154C:
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_82171550:
	// li r25,15
	ctx.r25.s64 = 15;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r25,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r25.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r28,r11,-2064
	ctx.r28.s64 = ctx.r11.s64 + -2064;
	// li r26,-1
	ctx.r26.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lfs f30,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f30.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f29,60(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 60);
	ctx.f29.f64 = double(temp.f32);
	// stfs f30,80(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f29,84(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x820601f8
	ctx.lr = 0x82171594;
	sub_820601F8(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8216f7a8
	ctx.lr = 0x821715A8;
	sub_8216F7A8(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,228(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// lfs f0,-21836(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r11,92
	ctx.r6.s64 = ctx.r11.s64 + 92;
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// lwz r5,92(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// lwz r4,96(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// lwz r3,100(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// stw r5,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r5.u32);
	// stw r4,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r4.u32);
	// stw r3,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r3.u32);
	// lwz r11,104(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r11.u32);
	// lfs f0,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// fsubs f0,f11,f13
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// bne cr6,0x8217160c
	if (!ctx.cr6.eq) goto loc_8217160C;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8217160c
	if (!ctx.cr6.gt) goto loc_8217160C;
	// fdivs f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
loc_8217160C:
	// stfs f31,12(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r27.u32 + 12, temp.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// fmuls f0,f31,f30
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f30.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f13,f31,f29
	ctx.f13.f64 = double(float(ctx.f31.f64 * ctx.f29.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82171628;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82171640
	if (ctx.cr6.eq) goto loc_82171640;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216e790
	ctx.lr = 0x8217163C;
	sub_8216E790(ctx, base);
	// b 0x82171644
	goto loc_82171644;
loc_82171640:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82171644:
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stw r25,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820601f8
	ctx.lr = 0x82171668;
	sub_820601F8(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x8216e718
	ctx.lr = 0x82171674;
	sub_8216E718(ctx, base);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r3,96
	ctx.r3.s64 = 96;
	// stb r30,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r30.u8);
	// bl 0x82079fd8
	ctx.lr = 0x82171684;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82171694
	if (ctx.cr6.eq) goto loc_82171694;
	// bl 0x82171210
	ctx.lr = 0x82171690;
	sub_82171210(ctx, base);
	// b 0x82171698
	goto loc_82171698;
loc_82171694:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82171698:
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821716B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,76(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f13,232(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r4,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r4.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// stw r5,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r5.u32);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f8,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f8.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// fsubs f6,f11,f13
	ctx.f6.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fsubs f4,f6,f9
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fsubs f3,f5,f7
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f7.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8217172C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r30,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r30.u8);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8217174C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// ld r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stfs f2,72(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stfs f1,76(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r3,16
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 16, ctx.xer);
	// blt cr6,0x821717ac
	if (ctx.cr6.lt) goto loc_821717AC;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821717AC;
	sub_8207A630(ctx, base);
loc_821717AC:
	// stw r25,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r25.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stb r30,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r30.u8);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821717D0"))) PPC_WEAK_FUNC(sub_821717D0);
PPC_FUNC_IMPL(__imp__sub_821717D0) {
	PPC_FUNC_PROLOGUE();
	// rlwimi r6,r5,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r11,r6,16
	ctx.r11.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwimi r7,r11,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r8,r7,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// b 0x821ce900
	sub_821CE900(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821717E8"))) PPC_WEAK_FUNC(sub_821717E8);
PPC_FUNC_IMPL(__imp__sub_821717E8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// ld r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 80);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f11,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r7,-2064
	ctx.r30.s64 = ctx.r7.s64 + -2064;
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lfs f0,236(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f13,240(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// stw r4,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// stw r3,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r3.u32);
	// lfs f8,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f5,f9,f13
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsubs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f0.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f4,f8,f13
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f5,104(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f4,108(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x821ce9a8
	ctx.lr = 0x821718A4;
	sub_821CE9A8(ctx, base);
	// ld r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f3,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f3,108(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ori r5,r5,65535
	ctx.r5.u64 = ctx.r5.u64 | 65535;
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lfs f0,220(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 220);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f13,244(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// stw r4,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r4.u32);
	// stw r3,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r3.u32);
	// lfs f10,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f7,f11,f13
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f6,f10,f13
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x821ce9a8
	ctx.lr = 0x82171944;
	sub_821CE9A8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_8217195C"))) PPC_WEAK_FUNC(sub_8217195C);
PPC_FUNC_IMPL(__imp__sub_8217195C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171960"))) PPC_WEAK_FUNC(sub_82171960);
PPC_FUNC_IMPL(__imp__sub_82171960) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82171968;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// addi r10,r7,5424
	ctx.r10.s64 = ctx.r7.s64 + 5424;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// li r28,15
	ctx.r28.s64 = 15;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// stb r9,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r9.u8);
	// stw r28,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// stb r30,76(r31)
	PPC_STORE_U8(ctx.r31.u32 + 76, ctx.r30.u8);
	// bl 0x820601f8
	ctx.lr = 0x82171A28;
	sub_820601F8(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r31,100
	ctx.r3.s64 = ctx.r31.s64 + 100;
	// bl 0x82073c80
	ctx.lr = 0x82171A34;
	sub_82073C80(ctx, base);
	// stw r26,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r26.u32);
	// stw r25,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r25.u32);
	// stw r24,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r24.u32);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x82171a54
	if (ctx.cr6.lt) goto loc_82171A54;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82171A54;
	sub_8207A630(ctx, base);
loc_82171A54:
	// stw r28,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stb r30,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82171A6C"))) PPC_WEAK_FUNC(sub_82171A6C);
PPC_FUNC_IMPL(__imp__sub_82171A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171A70"))) PPC_WEAK_FUNC(sub_82171A70);
PPC_FUNC_IMPL(__imp__sub_82171A70) {
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
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216c190
	ctx.lr = 0x82171AA4;
	sub_8216C190(ctx, base);
	// lwz r3,108(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 108);
	// lbz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82171ac8
	if (!ctx.cr6.eq) goto loc_82171AC8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82171AC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82171AC8:
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

__attribute__((alias("__imp__sub_82171AE0"))) PPC_WEAK_FUNC(sub_82171AE0);
PPC_FUNC_IMPL(__imp__sub_82171AE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82171AE8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82166cb8
	ctx.lr = 0x82171B00;
	sub_82166CB8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r3,88
	ctx.r3.s64 = 88;
	// addi r10,r11,5572
	ctx.r10.s64 = ctx.r11.s64 + 5572;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82171B14;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r27,15
	ctx.r27.s64 = 15;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x82171b5c
	if (ctx.cr6.eq) goto loc_82171B5C;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82171B48;
	sub_820601F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x821714f8
	ctx.lr = 0x82171B58;
	sub_821714F8(ctx, base);
	// b 0x82171b60
	goto loc_82171B60;
loc_82171B5C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82171B60:
	// stw r3,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r3.u32);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
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
	// lwz r8,24(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x82171b98
	if (ctx.cr6.lt) goto loc_82171B98;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82171B98;
	sub_8207A630(ctx, base);
loc_82171B98:
	// stw r27,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stb r30,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r30.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82171BB4"))) PPC_WEAK_FUNC(sub_82171BB4);
PPC_FUNC_IMPL(__imp__sub_82171BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171BB8"))) PPC_WEAK_FUNC(sub_82171BB8);
PPC_FUNC_IMPL(__imp__sub_82171BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82171BC0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lwz r11,-30992(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -30992);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82171bf8
	if (!ctx.cr6.eq) goto loc_82171BF8;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// addi r8,r9,-2064
	ctx.r8.s64 = ctx.r9.s64 + -2064;
	// stw r11,-30992(r10)
	PPC_STORE_U32(ctx.r10.u32 + -30992, ctx.r11.u32);
	// lfs f0,208(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-30996(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + -30996, temp.u32);
loc_82171BF8:
	// lbz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r11,r11,-21384
	ctx.r11.s64 = ctx.r11.s64 + -21384;
	// beq cr6,0x82171c10
	if (ctx.cr6.eq) goto loc_82171C10;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_82171C10:
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r10,r31,76
	ctx.r10.s64 = ctx.r31.s64 + 76;
	// lwz r6,84(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lis r28,-32251
	ctx.r28.s64 = -2113601536;
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// rotlwi r3,r4,8
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// stw r6,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// lfs f0,5388(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 5388);
	ctx.f0.f64 = double(temp.f32);
	// stw r5,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r5.u32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// or r8,r3,r10
	ctx.r8.u64 = ctx.r3.u64 | ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// rlwinm r6,r8,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// fsubs f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// fsubs f6,f11,f0
	ctx.f6.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// rlwinm r11,r5,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// or r5,r11,r7
	ctx.r5.u64 = ctx.r11.u64 | ctx.r7.u64;
	// bl 0x821ce900
	ctx.lr = 0x82171CA4;
	sub_821CE900(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// fneg f5,f0
	ctx.f5.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f4,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// lfs f3,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// fadds f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// lfs f12,5388(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 5388);
	ctx.f12.f64 = double(temp.f32);
	// fmr f13,f4
	ctx.f13.f64 = ctx.f4.f64;
	// fadds f0,f4,f12
	ctx.f0.f64 = double(float(ctx.f4.f64 + ctx.f12.f64));
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stfs f4,96(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fadds f13,f3,f5
	ctx.f13.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x821ce900
	ctx.lr = 0x82171CF0;
	sub_821CE900(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fneg f11,f0
	ctx.f11.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f9,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,5388(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 5388);
	ctx.f12.f64 = double(temp.f32);
	// fmr f13,f9
	ctx.f13.f64 = ctx.f9.f64;
	// lfs f10,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f7,f9,f12
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// lfs f8,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// fadds f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fadds f5,f10,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfs f5,108(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x821ce900
	ctx.lr = 0x82171D38;
	sub_821CE900(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f2,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// fneg f3,f0
	ctx.f3.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f4,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// fmr f13,f2
	ctx.f13.f64 = ctx.f2.f64;
	// lfs f1,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// lfs f12,5388(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 5388);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f2,f12
	ctx.f12.f64 = double(float(ctx.f2.f64 + ctx.f12.f64));
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fadds f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fadds f10,f4,f3
	ctx.f10.f64 = double(float(ctx.f4.f64 + ctx.f3.f64));
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x821ce900
	ctx.lr = 0x82171D80;
	sub_821CE900(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f7,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f7.f64 = double(temp.f32);
	// fneg f9,f0
	ctx.f9.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fadds f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f0.f64));
	// lfs f13,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,5388(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 5388);
	ctx.f0.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fsubs f4,f13,f0
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f5,f13
	ctx.f5.f64 = ctx.f13.f64;
	// lfs f8,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fadds f3,f8,f9
	ctx.f3.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// stfs f3,104(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x821ce900
	ctx.lr = 0x82171DC8;
	sub_821CE900(ctx, base);
	// lfs f2,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// fmr f12,f2
	ctx.f12.f64 = ctx.f2.f64;
	// lfs f0,-30996(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// fmr f10,f2
	ctx.f10.f64 = ctx.f2.f64;
	// fadds f13,f2,f0
	ctx.f13.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// stfs f2,80(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f6,f1,f0
	ctx.f6.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f6,84(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fadds f9,f2,f0
	ctx.f9.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f8,f1
	ctx.f8.f64 = ctx.f1.f64;
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fmr f7,f1
	ctx.f7.f64 = ctx.f1.f64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82171420
	ctx.lr = 0x82171E1C;
	sub_82171420(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// fneg f5,f0
	ctx.f5.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f4,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,96(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// lfs f2,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// fmr f12,f4
	ctx.f12.f64 = ctx.f4.f64;
	// fadds f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fadds f13,f2,f0
	ctx.f13.f64 = double(float(ctx.f2.f64 + ctx.f0.f64));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f10,f2
	ctx.f10.f64 = ctx.f2.f64;
	// fadds f8,f4,f5
	ctx.f8.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// stfs f8,88(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f9,f4,f5
	ctx.f9.f64 = double(float(ctx.f4.f64 + ctx.f5.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82171420
	ctx.lr = 0x82171E74;
	sub_82171420(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// fneg f6,f0
	ctx.f6.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f5,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f5
	ctx.f3.f64 = ctx.f5.f64;
	// fmr f4,f7
	ctx.f4.f64 = ctx.f7.f64;
	// fmr f2,f7
	ctx.f2.f64 = ctx.f7.f64;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// fadds f13,f5,f6
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// fadds f12,f7,f0
	ctx.f12.f64 = double(float(ctx.f7.f64 + ctx.f0.f64));
	// stfs f5,92(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fadds f11,f7,f0
	ctx.f11.f64 = double(float(ctx.f7.f64 + ctx.f0.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f10,f5,f6
	ctx.f10.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82171420
	ctx.lr = 0x82171ECC;
	sub_82171420(ctx, base);
	// lfs f0,-30996(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -30996);
	ctx.f0.f64 = double(temp.f32);
	// fneg f9,f0
	ctx.f9.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f8,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// fmr f6,f8
	ctx.f6.f64 = ctx.f8.f64;
	// stfs f8,88(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f4,f8
	ctx.f4.f64 = ctx.f8.f64;
	// fmr f3,f7
	ctx.f3.f64 = ctx.f7.f64;
	// fadds f2,f8,f9
	ctx.f2.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fadds f1,f7,f9
	ctx.f1.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// stfs f1,92(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fadds f0,f8,f9
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f13,f7,f9
	ctx.f13.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// ld r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82171420
	ctx.lr = 0x82171F24;
	sub_82171420(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82171F2C"))) PPC_WEAK_FUNC(sub_82171F2C);
PPC_FUNC_IMPL(__imp__sub_82171F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82171F30"))) PPC_WEAK_FUNC(sub_82171F30);
PPC_FUNC_IMPL(__imp__sub_82171F30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82171F38;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,136
	ctx.r3.s64 = 136;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82171F54;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r25,15
	ctx.r25.s64 = 15;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// beq cr6,0x82171fd8
	if (ctx.cr6.eq) goto loc_82171FD8;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82171F88;
	sub_820601F8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82171F9C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82171FB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// bl 0x82171960
	ctx.lr = 0x82171FD0;
	sub_82171960(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82171fdc
	goto loc_82171FDC;
loc_82171FD8:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82171FDC:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82171ff0
	if (ctx.cr6.lt) goto loc_82171FF0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82171FF0;
	sub_8207A630(ctx, base);
loc_82171FF0:
	// stw r25,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r25.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
	// stb r29,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r29.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172008"))) PPC_WEAK_FUNC(sub_82172008);
PPC_FUNC_IMPL(__imp__sub_82172008) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82172010;
	__savegprlr_21(ctx, base);
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,224(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r31,r3,44
	ctx.r31.s64 = ctx.r3.s64 + 44;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82172058
	if (ctx.cr6.eq) goto loc_82172058;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,33(r11)
	PPC_STORE_U8(ctx.r11.u32 + 33, ctx.r10.u8);
loc_82172058:
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82079fd8
	ctx.lr = 0x82172060;
	sub_82079FD8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r21,15
	ctx.r21.s64 = 15;
	// li r22,-1
	ctx.r22.s64 = -1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f30,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f30.f64 = double(temp.f32);
	// beq cr6,0x821720b0
	if (ctx.cr6.eq) goto loc_821720B0;
	// stw r21,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r21.u32);
	// addi r4,r28,140
	ctx.r4.s64 = ctx.r28.s64 + 140;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x8217209C;
	sub_820601F8(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x821714f8
	ctx.lr = 0x821720AC;
	sub_821714F8(ctx, base);
	// b 0x821720b4
	goto loc_821720B4;
loc_821720B0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821720B4:
	// stw r3,192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 192, ctx.r3.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,192(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 192);
	// bne cr6,0x821720d4
	if (!ctx.cr6.eq) goto loc_821720D4;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
loc_821720D4:
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r4,192(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 192);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821720F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r9,184(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r8,180(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 180);
	// li r24,28
	ctx.r24.s64 = 28;
	// addi r23,r11,-2064
	ctx.r23.s64 = ctx.r11.s64 + -2064;
	// lfs f31,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r31,r28,168
	ctx.r31.s64 = ctx.r28.s64 + 168;
	// divw. r6,r7,r24
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r24.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lfs f29,296(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 296);
	ctx.f29.f64 = double(temp.f32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// beq 0x82172270
	if (ctx.cr0.eq) goto loc_82172270;
	// addi r25,r28,196
	ctx.r25.s64 = ctx.r28.s64 + 196;
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
loc_8217212C:
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82079fd8
	ctx.lr = 0x82172134;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82172194
	if (ctx.cr6.eq) goto loc_82172194;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r24
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r24.s32);
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217215c
	if (ctx.cr6.lt) goto loc_8217215C;
	// twi 31,r0,22
loc_8217215C:
	// stw r21,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r21.u32);
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x8217217C;
	sub_820601F8(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82171ae0
	ctx.lr = 0x8217218C;
	sub_82171AE0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82172198
	goto loc_82172198;
loc_82172194:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82172198:
	// lwz r9,12(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821721b0
	if (!ctx.cr6.eq) goto loc_821721B0;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// b 0x821721bc
	goto loc_821721BC;
loc_821721B0:
	// lwz r10,20(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 20);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
loc_821721BC:
	// lwz r10,16(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r6,r8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x821721e0
	if (!ctx.cr6.lt) goto loc_821721E0;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r9,16(r25)
	PPC_STORE_U32(ctx.r25.u32 + 16, ctx.r9.u32);
	// b 0x82172210
	goto loc_82172210;
loc_821721E0:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821721ec
	if (!ctx.cr6.gt) goto loc_821721EC;
	// twi 31,r0,22
loc_821721EC:
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x820697e0
	ctx.lr = 0x8217220C;
	sub_820697E0(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82172210:
	// stw r28,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r28.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r9,84(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 84);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82172244;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// subf r3,r4,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r4.s64;
	// addi r26,r26,28
	ctx.r26.s64 = ctx.r26.s64 + 28;
	// divw r11,r3,r24
	ctx.r11.s32 = ppc_divw(ctx.r3.s32, ctx.r24.s32);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// fadds f31,f13,f29
	ctx.f31.f64 = double(float(ctx.f13.f64 + ctx.f29.f64));
	// blt cr6,0x8217212c
	if (ctx.cr6.lt) goto loc_8217212C;
loc_82172270:
	// lwz r4,192(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 192);
	// lfs f30,32(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 32);
	ctx.f30.f64 = double(temp.f32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// fmuls f31,f31,f30
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f30.f64));
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82172290;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f31,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f0,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,192(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 192);
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bctrl 
	ctx.lr = 0x821722B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,192(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 192);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821722D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f12,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lwz r5,212(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 212);
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// lwz r4,208(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 208);
	// addi r31,r28,196
	ctx.r31.s64 = ctx.r28.s64 + 196;
	// subf r3,r4,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r4.s64;
	// srawi. r11,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// fadds f31,f11,f29
	ctx.f31.f64 = double(float(ctx.f11.f64 + ctx.f29.f64));
	// beq 0x821723dc
	if (ctx.cr0.eq) goto loc_821723DC;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_821722F8:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82172314
	if (ctx.cr6.lt) goto loc_82172314;
	// twi 31,r0,22
loc_82172314:
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82172330;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r30,r6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82172350
	if (ctx.cr6.lt) goto loc_82172350;
	// twi 31,r0,22
loc_82172350:
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// fmuls f0,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82172378;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r30,r6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82172394
	if (ctx.cr6.lt) goto loc_82172394;
	// twi 31,r0,22
loc_82172394:
	// lwzx r11,r11,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,84(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821723B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// srawi r5,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 2;
	// cmplw cr6,r30,r5
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r5.u32, ctx.xer);
	// fadds f31,f13,f29
	ctx.f31.f64 = double(float(ctx.f13.f64 + ctx.f29.f64));
	// blt cr6,0x821722f8
	if (ctx.cr6.lt) goto loc_821722F8;
loc_821723DC:
	// lwz r11,220(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 220);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8217242c
	if (!ctx.cr6.lt) goto loc_8217242C;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82172418
	if (ctx.cr6.lt) goto loc_82172418;
	// twi 31,r0,22
loc_82172418:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// lwz r3,72(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// bl 0x82166700
	ctx.lr = 0x8217242C;
	sub_82166700(ctx, base);
loc_8217242C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172440"))) PPC_WEAK_FUNC(sub_82172440);
PPC_FUNC_IMPL(__imp__sub_82172440) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82172448;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82172490
	if (ctx.cr6.eq) goto loc_82172490;
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82172488;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82172494
	goto loc_82172494;
loc_82172490:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_82172494:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82166fe8
	ctx.lr = 0x8217249C;
	sub_82166FE8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r24,15
	ctx.r24.s64 = 15;
	// addi r10,r11,5640
	ctx.r10.s64 = ctx.r11.s64 + 5640;
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r24,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r24.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r30.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stb r30,144(r31)
	PPC_STORE_U8(ctx.r31.u32 + 144, ctx.r30.u8);
	// bl 0x820601f8
	ctx.lr = 0x821724CC;
	sub_820601F8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,168
	ctx.r3.s64 = ctx.r31.s64 + 168;
	// bl 0x82073c80
	ctx.lr = 0x821724D8;
	sub_82073C80(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r29,r31,196
	ctx.r29.s64 = ctx.r31.s64 + 196;
	// bl 0x82079fd8
	ctx.lr = 0x821724E4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821724f4
	if (ctx.cr6.eq) goto loc_821724F4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x821724f8
	goto loc_821724F8;
loc_821724F4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821724F8:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stw r26,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r26.u32);
	// stw r25,224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 224, ctx.r25.u32);
	// beq cr6,0x82172530
	if (ctx.cr6.eq) goto loc_82172530;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stw r28,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r28.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r30,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
loc_82172530:
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82172544
	if (ctx.cr6.lt) goto loc_82172544;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82172544;
	sub_8207A630(ctx, base);
loc_82172544:
	// stw r24,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r24.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r30.u32);
	// stb r30,4(r27)
	PPC_STORE_U8(ctx.r27.u32 + 4, ctx.r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217255C"))) PPC_WEAK_FUNC(sub_8217255C);
PPC_FUNC_IMPL(__imp__sub_8217255C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82172560"))) PPC_WEAK_FUNC(sub_82172560);
PPC_FUNC_IMPL(__imp__sub_82172560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82172568;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x82080368
	ctx.lr = 0x82172570;
	__savefpr_28(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,240(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 240);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r9,64(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r29,r3,44
	ctx.r29.s64 = ctx.r3.s64 + 44;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821725ac
	if (ctx.cr6.eq) goto loc_821725AC;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,33(r11)
	PPC_STORE_U8(ctx.r11.u32 + 33, ctx.r10.u8);
loc_821725AC:
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82079fd8
	ctx.lr = 0x821725B4;
	sub_82079FD8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r25,15
	ctx.r25.s64 = 15;
	// li r26,-1
	ctx.r26.s64 = -1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f29,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f29.f64 = double(temp.f32);
	// beq cr6,0x82172604
	if (ctx.cr6.eq) goto loc_82172604;
	// stw r25,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r25.u32);
	// addi r4,r31,140
	ctx.r4.s64 = ctx.r31.s64 + 140;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stb r30,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820601f8
	ctx.lr = 0x821725F0;
	sub_820601F8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x821714f8
	ctx.lr = 0x82172600;
	sub_821714F8(ctx, base);
	// b 0x82172608
	goto loc_82172608;
loc_82172604:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82172608:
	// stw r3,224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// bne cr6,0x82172628
	if (!ctx.cr6.eq) goto loc_82172628;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stw r9,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
loc_82172628:
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r3,96
	ctx.r3.s64 = 96;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82172638;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217264c
	if (ctx.cr6.eq) goto loc_8217264C;
	// bl 0x821650f0
	ctx.lr = 0x82172644;
	sub_821650F0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82172650
	goto loc_82172650;
loc_8217264C:
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82172650:
	// stw r25,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r25.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r30,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r30.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stb r30,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r30.u8);
	// addi r24,r11,-2064
	ctx.r24.s64 = ctx.r11.s64 + -2064;
	// addi r28,r31,168
	ctx.r28.s64 = ctx.r31.s64 + 168;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lfs f31,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lfs f30,60(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 60);
	ctx.f30.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x820601f8
	ctx.lr = 0x82172690;
	sub_820601F8(ctx, base);
	// stw r25,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r25.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r30.u32);
	// addi r27,r31,196
	ctx.r27.s64 = ctx.r31.s64 + 196;
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r30.u8);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f30,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x821726BC;
	sub_820601F8(ctx, base);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// ld r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8216f7a8
	ctx.lr = 0x821726D0;
	sub_8216F7A8(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x8216f7a8
	ctx.lr = 0x821726E8;
	sub_8216F7A8(ctx, base);
	// lfs f0,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// fadds f30,f0,f13
	ctx.f30.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// beq cr6,0x82172714
	if (ctx.cr6.eq) goto loc_82172714;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82172714;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82172714:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,216(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f31,296(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 296);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r9,r11,92
	ctx.r9.s64 = ctx.r11.s64 + 92;
	// lwz r8,92(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// lwz r7,104(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// lwz r6,96(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// lwz r5,100(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// fsubs f0,f10,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 - ctx.f31.f64));
	// fcmpu cr6,f30,f0
	ctx.cr6.compare(ctx.f30.f64, ctx.f0.f64);
	// ble cr6,0x82172770
	if (!ctx.cr6.gt) goto loc_82172770;
	// fdivs f30,f0,f30
	ctx.f30.f64 = double(float(ctx.f0.f64 / ctx.f30.f64));
	// b 0x82172774
	goto loc_82172774;
loc_82172770:
	// fmr f30,f29
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f29.f64;
loc_82172774:
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82079fd8
	ctx.lr = 0x8217277C;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821727c0
	if (ctx.cr6.eq) goto loc_821727C0;
	// stw r25,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r25.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stw r30,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r30.u8);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x820601f8
	ctx.lr = 0x821727A8;
	sub_820601F8(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82171ae0
	ctx.lr = 0x821727B8;
	sub_82171AE0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821727c4
	goto loc_821727C4;
loc_821727C0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821727C4:
	// stw r11,228(r31)
	PPC_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r31,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r31.u32);
	// li r3,88
	ctx.r3.s64 = 88;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821727EC;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82172830
	if (ctx.cr6.eq) goto loc_82172830;
	// stw r25,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r25.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stw r30,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r30.u8);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x820601f8
	ctx.lr = 0x82172818;
	sub_820601F8(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82171ae0
	ctx.lr = 0x82172828;
	sub_82171AE0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82172834
	goto loc_82172834;
loc_82172830:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82172834:
	// stw r11,232(r31)
	PPC_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r31,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r31.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r6,232(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// stw r9,80(r6)
	PPC_STORE_U32(ctx.r6.u32 + 80, ctx.r9.u32);
	// lwz r5,232(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// lwz r4,84(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217287C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// lfs f30,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// stfs f30,80(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,84(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821728A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// lfs f29,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f29.f64 = double(temp.f32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// stfs f29,96(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r5,28(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821728C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f30
	ctx.cr6.compare(ctx.f29.f64, ctx.f30.f64);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x821728d4
	if (ctx.cr6.lt) goto loc_821728D4;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
loc_821728D4:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f30,32(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 32);
	ctx.f30.f64 = double(temp.f32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f31.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f29,f11,f30
	ctx.f29.f64 = double(float(ctx.f11.f64 * ctx.f30.f64));
	// bctrl 
	ctx.lr = 0x82172900;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f10,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lwz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// fmuls f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f30.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f29,100(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x8217292C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,228(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwz r4,84(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,28(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82172948;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,84(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lfs f28,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8217296C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r4,224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f8,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fadds f7,f28,f8
	ctx.f7.f64 = double(float(ctx.f28.f64 + ctx.f8.f64));
	// lwz r11,28(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f6,f7,f31
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f31.f64));
	// fmuls f30,f6,f30
	ctx.f30.f64 = double(float(ctx.f6.f64 * ctx.f30.f64));
	// bctrl 
	ctx.lr = 0x82172998;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,228(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// lfs f5,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fadds f4,f5,f29
	ctx.f4.f64 = double(float(ctx.f5.f64 + ctx.f29.f64));
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r3,84(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f3,f4,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f31.f64));
	// stfs f3,100(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821729C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821729E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,228(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// lfs f28,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,84(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82172A00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// lfs f2,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fadds f1,f28,f29
	ctx.f1.f64 = double(float(ctx.f28.f64 + ctx.f29.f64));
	// fadds f0,f2,f30
	ctx.f0.f64 = double(float(ctx.f2.f64 + ctx.f30.f64));
	// lwz r3,84(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fadds f13,f1,f31
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f31.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bctrl 
	ctx.lr = 0x82172A38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,236(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 236);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bne cr6,0x82172a58
	if (!ctx.cr6.eq) goto loc_82172A58;
	// lwz r11,228(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 228);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// bl 0x82166700
	ctx.lr = 0x82172A58;
	sub_82166700(ctx, base);
loc_82172A58:
	// lwz r11,236(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 236);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82172a78
	if (!ctx.cr6.eq) goto loc_82172A78;
	// lwz r11,232(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 232);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// bl 0x82166700
	ctx.lr = 0x82172A78;
	sub_82166700(ctx, base);
loc_82172A78:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x820803b4
	ctx.lr = 0x82172A84;
	__restfpr_28(ctx, base);
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172A88"))) PPC_WEAK_FUNC(sub_82172A88);
PPC_FUNC_IMPL(__imp__sub_82172A88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82172A90;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r23,r7
	ctx.r23.u64 = ctx.r7.u64;
	// mr r22,r8
	ctx.r22.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82172adc
	if (ctx.cr6.eq) goto loc_82172ADC;
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82172AD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82172ae0
	goto loc_82172AE0;
loc_82172ADC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
loc_82172AE0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82166fe8
	ctx.lr = 0x82172AE8;
	sub_82166FE8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r10,r11,5604
	ctx.r10.s64 = ctx.r11.s64 + 5604;
	// li r27,-1
	ctx.r27.s64 = -1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r3,r31,140
	ctx.r3.s64 = ctx.r31.s64 + 140;
	// stw r28,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r30.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stb r30,144(r31)
	PPC_STORE_U8(ctx.r31.u32 + 144, ctx.r30.u8);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x820601f8
	ctx.lr = 0x82172B1C;
	sub_820601F8(ctx, base);
	// stw r28,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r28.u32);
	// stw r30,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r30.u32);
	// addi r3,r31,168
	ctx.r3.s64 = ctx.r31.s64 + 168;
	// stb r30,172(r31)
	PPC_STORE_U8(ctx.r31.u32 + 172, ctx.r30.u8);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x820601f8
	ctx.lr = 0x82172B3C;
	sub_820601F8(ctx, base);
	// stw r28,220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 220, ctx.r28.u32);
	// stw r30,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r30.u32);
	// addi r3,r31,196
	ctx.r3.s64 = ctx.r31.s64 + 196;
	// stb r30,200(r31)
	PPC_STORE_U8(ctx.r31.u32 + 200, ctx.r30.u8);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// bl 0x820601f8
	ctx.lr = 0x82172B5C;
	sub_820601F8(ctx, base);
	// stw r23,236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 236, ctx.r23.u32);
	// stw r22,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r22.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82172b84
	if (ctx.cr6.eq) goto loc_82172B84;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stw r29,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r30,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
loc_82172B84:
	// lwz r11,24(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82172b98
	if (ctx.cr6.lt) goto loc_82172B98;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82172B98;
	sub_8207A630(ctx, base);
loc_82172B98:
	// stw r28,24(r25)
	PPC_STORE_U32(ctx.r25.u32 + 24, ctx.r28.u32);
	// stw r30,20(r25)
	PPC_STORE_U32(ctx.r25.u32 + 20, ctx.r30.u32);
	// stb r30,4(r25)
	PPC_STORE_U8(ctx.r25.u32 + 4, ctx.r30.u8);
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82172bb8
	if (ctx.cr6.lt) goto loc_82172BB8;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82172BB8;
	sub_8207A630(ctx, base);
loc_82172BB8:
	// stw r28,24(r26)
	PPC_STORE_U32(ctx.r26.u32 + 24, ctx.r28.u32);
	// stw r30,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r30.u32);
	// stb r30,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r30.u8);
	// lwz r11,24(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82172bd8
	if (ctx.cr6.lt) goto loc_82172BD8;
	// lwz r3,4(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82172BD8;
	sub_8207A630(ctx, base);
loc_82172BD8:
	// stw r28,24(r24)
	PPC_STORE_U32(ctx.r24.u32 + 24, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r24)
	PPC_STORE_U32(ctx.r24.u32 + 20, ctx.r30.u32);
	// stb r30,4(r24)
	PPC_STORE_U8(ctx.r24.u32 + 4, ctx.r30.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172BF0"))) PPC_WEAK_FUNC(sub_82172BF0);
PPC_FUNC_IMPL(__imp__sub_82172BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82172BF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82079fd8
	ctx.lr = 0x82172C08;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// beq cr6,0x82172c58
	if (ctx.cr6.eq) goto loc_82172C58;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// addi r4,r31,76
	ctx.r4.s64 = ctx.r31.s64 + 76;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820601f8
	ctx.lr = 0x82172C3C;
	sub_820601F8(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821714f8
	ctx.lr = 0x82172C50;
	sub_821714F8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x82172c5c
	goto loc_82172C5C;
loc_82172C58:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
loc_82172C5C:
	// stw r4,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r4.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82172C74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// addi r7,r8,-2064
	ctx.r7.s64 = ctx.r8.s64 + -2064;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,28(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82172CBC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r30,r31,44
	ctx.r30.s64 = ctx.r31.s64 + 44;
	// stb r29,12(r4)
	PPC_STORE_U8(ctx.r4.u32 + 12, ctx.r29.u8);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// lbz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82172d00
	if (!ctx.cr6.eq) goto loc_82172D00;
	// lis r11,-32233
	ctx.r11.s64 = -2112421888;
	// addi r10,r11,2656
	ctx.r10.s64 = ctx.r11.s64 + 2656;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82172D00:
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82079fd8
	ctx.lr = 0x82172D08;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82172d18
	if (ctx.cr6.eq) goto loc_82172D18;
	// bl 0x82165ce0
	ctx.lr = 0x82172D14;
	sub_82165CE0(ctx, base);
	// b 0x82172d1c
	goto loc_82172D1C;
loc_82172D18:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82172D1C:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82172D44;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r7,-32233
	ctx.r7.s64 = -2112421888;
	// stw r3,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r3.u32);
	// li r6,300
	ctx.r6.s64 = 300;
	// addi r5,r7,3880
	ctx.r5.s64 = ctx.r7.s64 + 3880;
	// stw r6,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r6.u32);
	// stw r5,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r5.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172D64"))) PPC_WEAK_FUNC(sub_82172D64);
PPC_FUNC_IMPL(__imp__sub_82172D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82172D68"))) PPC_WEAK_FUNC(sub_82172D68);
PPC_FUNC_IMPL(__imp__sub_82172D68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82172D70;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
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
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// addi r10,r7,5392
	ctx.r10.s64 = ctx.r7.s64 + 5392;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// addi r3,r3,76
	ctx.r3.s64 = ctx.r3.s64 + 76;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// stb r9,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r9.u8);
	// stw r28,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r28.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stb r30,80(r31)
	PPC_STORE_U8(ctx.r31.u32 + 80, ctx.r30.u8);
	// bl 0x820601f8
	ctx.lr = 0x82172E24;
	sub_820601F8(ctx, base);
	// lis r9,-32233
	ctx.r9.s64 = -2112421888;
	// stb r27,104(r31)
	PPC_STORE_U8(ctx.r31.u32 + 104, ctx.r27.u8);
	// addi r8,r9,11248
	ctx.r8.s64 = ctx.r9.s64 + 11248;
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// lwz r7,24(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x82172e48
	if (ctx.cr6.lt) goto loc_82172E48;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82172E48;
	sub_8207A630(ctx, base);
loc_82172E48:
	// stw r28,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stb r30,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172E60"))) PPC_WEAK_FUNC(sub_82172E60);
PPC_FUNC_IMPL(__imp__sub_82172E60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82172E68;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,120
	ctx.r3.s64 = 120;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82172E7C;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r27,15
	ctx.r27.s64 = 15;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x82172ec8
	if (ctx.cr6.eq) goto loc_82172EC8;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82172EB0;
	sub_820601F8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82172d68
	ctx.lr = 0x82172EC0;
	sub_82172D68(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82172ecc
	goto loc_82172ECC;
loc_82172EC8:
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82172ECC:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82172ee0
	if (ctx.cr6.lt) goto loc_82172EE0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82172EE0;
	sub_8207A630(ctx, base);
loc_82172EE0:
	// stw r27,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82172EF8"))) PPC_WEAK_FUNC(sub_82172EF8);
PPC_FUNC_IMPL(__imp__sub_82172EF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82172F00;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82172F10;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x82172f50
	if (ctx.cr6.eq) goto loc_82172F50;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r10,r11,5300
	ctx.r10.s64 = ctx.r11.s64 + 5300;
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// b 0x82172f54
	goto loc_82172F54;
loc_82172F50:
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82172F54:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,228
	ctx.r3.s64 = 228;
	// stb r11,14(r29)
	PPC_STORE_U8(ctx.r29.u32 + 14, ctx.r11.u8);
	// bl 0x82079fd8
	ctx.lr = 0x82172F64;
	sub_82079FD8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82172fe4
	if (ctx.cr6.eq) goto loc_82172FE4;
	// lwz r28,128(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82172f9c
	if (!ctx.cr6.eq) goto loc_82172F9C;
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x82172F84;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82172f98
	if (ctx.cr6.eq) goto loc_82172F98;
	// bl 0x821714a8
	ctx.lr = 0x82172F90;
	sub_821714A8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x82172f9c
	goto loc_82172F9C;
loc_82172F98:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
loc_82172F9C:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// addi r4,r31,72
	ctx.r4.s64 = ctx.r31.s64 + 72;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x82172FC0;
	sub_820601F8(ctx, base);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// addi r5,r31,100
	ctx.r5.s64 = ctx.r31.s64 + 100;
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,124(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82172440
	ctx.lr = 0x82172FDC;
	sub_82172440(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x82172fe8
	goto loc_82172FE8;
loc_82172FE4:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
loc_82172FE8:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82172FF8;
	sub_820735C8(ctx, base);
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
	// addi r10,r29,4
	ctx.r10.s64 = ctx.r29.s64 + 4;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r28,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r28.u32);
	// stw r11,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r30,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r30.u32);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173040"))) PPC_WEAK_FUNC(sub_82173040);
PPC_FUNC_IMPL(__imp__sub_82173040) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82173048;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82173058;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq cr6,0x82173098
	if (ctx.cr6.eq) goto loc_82173098;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stb r31,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r31.u8);
	// addi r10,r11,5300
	ctx.r10.s64 = ctx.r11.s64 + 5300;
	// stb r31,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r31.u8);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r31,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r31.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stb r31,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r31.u8);
	// b 0x8217309c
	goto loc_8217309C;
loc_82173098:
	// mr r28,r31
	ctx.r28.u64 = ctx.r31.u64;
loc_8217309C:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,244
	ctx.r3.s64 = 244;
	// stb r11,14(r28)
	PPC_STORE_U8(ctx.r28.u32 + 14, ctx.r11.u8);
	// bl 0x82079fd8
	ctx.lr = 0x821730AC;
	sub_82079FD8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82173174
	if (ctx.cr6.eq) goto loc_82173174;
	// lwz r26,160(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 160);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x821730e4
	if (!ctx.cr6.eq) goto loc_821730E4;
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x821730CC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821730e0
	if (ctx.cr6.eq) goto loc_821730E0;
	// bl 0x821714a8
	ctx.lr = 0x821730D8;
	sub_821714A8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// b 0x821730e4
	goto loc_821730E4;
loc_821730E0:
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
loc_821730E4:
	// li r27,15
	ctx.r27.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// addi r4,r30,128
	ctx.r4.s64 = ctx.r30.s64 + 128;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8217310C;
	sub_820601F8(ctx, base);
	// stw r27,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r27.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// addi r4,r30,100
	ctx.r4.s64 = ctx.r30.s64 + 100;
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820601f8
	ctx.lr = 0x8217312C;
	sub_820601F8(ctx, base);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r27.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// addi r4,r30,72
	ctx.r4.s64 = ctx.r30.s64 + 72;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x8217314C;
	sub_820601F8(ctx, base);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r9,164(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 164);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r7,156(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 156);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82172a88
	ctx.lr = 0x8217316C;
	sub_82172A88(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82173178
	goto loc_82173178;
loc_82173174:
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
loc_82173178:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82173188;
	sub_820735C8(ctx, base);
	// lwz r8,20(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
	// addi r10,r28,4
	ctx.r10.s64 = ctx.r28.s64 + 4;
	// addi r9,r30,16
	ctx.r9.s64 = ctx.r30.s64 + 16;
	// stw r29,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r29.u32);
	// stw r11,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r31,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r28,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r28.u32);
	// stw r10,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// stw r31,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r31.u32);
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821731D0"))) PPC_WEAK_FUNC(sub_821731D0);
PPC_FUNC_IMPL(__imp__sub_821731D0) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821731FC"))) PPC_WEAK_FUNC(sub_821731FC);
PPC_FUNC_IMPL(__imp__sub_821731FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173200"))) PPC_WEAK_FUNC(sub_82173200);
PPC_FUNC_IMPL(__imp__sub_82173200) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r4,104(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lbz r6,-14757(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -14757);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// b 0x8216d2f8
	sub_8216D2F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173220"))) PPC_WEAK_FUNC(sub_82173220);
PPC_FUNC_IMPL(__imp__sub_82173220) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173238"))) PPC_WEAK_FUNC(sub_82173238);
PPC_FUNC_IMPL(__imp__sub_82173238) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82173240;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r11,r11,-21360
	ctx.r11.s64 = ctx.r11.s64 + -21360;
loc_82173260:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82173284
	if (ctx.cr6.eq) goto loc_82173284;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82173260
	if (ctx.cr6.eq) goto loc_82173260;
loc_82173284:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x821732e0
	if (!ctx.cr6.eq) goto loc_821732E0;
	// lbz r11,7(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 7);
	// lbz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 6);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,5(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 5);
	// lbz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// bl 0x8207a030
	ctx.lr = 0x821732BC;
	sub_8207A030(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r31,8
	ctx.r5.s64 = ctx.r31.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821d1c90
	ctx.lr = 0x821732D0;
	sub_821D1C90(ctx, base);
	// cntlzw r11,r3
	ctx.r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821732E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821732EC"))) PPC_WEAK_FUNC(sub_821732EC);
PPC_FUNC_IMPL(__imp__sub_821732EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821732F0"))) PPC_WEAK_FUNC(sub_821732F0);
PPC_FUNC_IMPL(__imp__sub_821732F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821732F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,100(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,5368
	ctx.r10.s64 = ctx.r11.s64 + 5368;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8217331c
	if (ctx.cr6.eq) goto loc_8217331C;
	// bl 0x8207a630
	ctx.lr = 0x8217331C;
	sub_8207A630(ctx, base);
loc_8217331C:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r30,r31,72
	ctx.r30.s64 = ctx.r31.s64 + 72;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82173334
	if (ctx.cr6.lt) goto loc_82173334;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82173334;
	sub_8207A630(ctx, base);
loc_82173334:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,15
	ctx.r9.s64 = 15;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// addi r7,r10,6128
	ctx.r7.s64 = ctx.r10.s64 + 6128;
	// stw r9,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r9.u32);
	// addi r29,r8,-1408
	ctx.r29.s64 = ctx.r8.s64 + -1408;
	// stb r11,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r11.u8);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82173368;
	sub_82173A18(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r30,r6,-1456
	ctx.r30.s64 = ctx.r6.s64 + -1456;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82173380;
	sub_82173A18(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173390"))) PPC_WEAK_FUNC(sub_82173390);
PPC_FUNC_IMPL(__imp__sub_82173390) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r11,5324
	ctx.r10.s64 = ctx.r11.s64 + 5324;
	// addi r31,r3,124
	ctx.r31.s64 = ctx.r3.s64 + 124;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x821733cc
	if (ctx.cr6.lt) goto loc_821733CC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821733CC;
	sub_8207A630(ctx, base);
loc_821733CC:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// bl 0x8216a010
	ctx.lr = 0x821733E8;
	sub_8216A010(ctx, base);
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

__attribute__((alias("__imp__sub_82173400"))) PPC_WEAK_FUNC(sub_82173400);
PPC_FUNC_IMPL(__imp__sub_82173400) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82173408;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// addi r8,r7,5368
	ctx.r8.s64 = ctx.r7.s64 + 5368;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// li r27,15
	ctx.r27.s64 = 15;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// addi r3,r3,72
	ctx.r3.s64 = ctx.r3.s64 + 72;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// stb r9,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r9.u8);
	// stw r27,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r27.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
	// stb r30,76(r31)
	PPC_STORE_U8(ctx.r31.u32 + 76, ctx.r30.u8);
	// stw r31,-31384(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31384, ctx.r31.u32);
	// bl 0x820601f8
	ctx.lr = 0x821734C8;
	sub_820601F8(ctx, base);
	// stw r26,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r26.u32);
	// stw r29,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r29.u32);
	// addi r11,r29,4
	ctx.r11.s64 = ctx.r29.s64 + 4;
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r30,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// lwz r6,24(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r6,16
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 16, ctx.xer);
	// blt cr6,0x821734f8
	if (ctx.cr6.lt) goto loc_821734F8;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821734F8;
	sub_8207A630(ctx, base);
loc_821734F8:
	// stw r27,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r30.u32);
	// stb r30,4(r28)
	PPC_STORE_U8(ctx.r28.u32 + 4, ctx.r30.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173510"))) PPC_WEAK_FUNC(sub_82173510);
PPC_FUNC_IMPL(__imp__sub_82173510) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82173518;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,15
	ctx.r26.s64 = 15;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// li r27,-1
	ctx.r27.s64 = -1;
	// stw r26,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r26.u32);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// bl 0x820601f8
	ctx.lr = 0x82173554;
	sub_820601F8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r11,-21304
	ctx.r30.s64 = ctx.r11.s64 + -21304;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8206a100
	ctx.lr = 0x82173570;
	sub_8206A100(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821735b0
	if (ctx.cr6.eq) goto loc_821735B0;
loc_8217357C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82069ed8
	ctx.lr = 0x82173590;
	sub_82069ED8(ctx, base);
	// addi r4,r30,-4
	ctx.r4.s64 = ctx.r30.s64 + -4;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8206a100
	ctx.lr = 0x821735A4;
	sub_8206A100(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8217357c
	if (!ctx.cr6.eq) goto loc_8217357C;
loc_821735B0:
	// stw r26,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r26.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r29,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r29.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820601f8
	ctx.lr = 0x821735D0;
	sub_820601F8(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82167208
	ctx.lr = 0x821735DC;
	sub_82167208(ctx, base);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// lwz r30,84(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8217362c
	if (!ctx.cr6.eq) goto loc_8217362C;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821735fc
	if (ctx.cr6.lt) goto loc_821735FC;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x82173600
	goto loc_82173600;
loc_821735FC:
	// addi r3,r28,4
	ctx.r3.s64 = ctx.r28.s64 + 4;
loc_82173600:
	// bl 0x8210e878
	ctx.lr = 0x82173604;
	sub_8210E878(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8207a8a0
	ctx.lr = 0x8217360C;
	sub_8207A8A0(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82173620
	if (ctx.cr6.lt) goto loc_82173620;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82173620;
	sub_8207A630(ctx, base);
loc_82173620:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_8217362C:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217363c
	if (ctx.cr6.lt) goto loc_8217363C;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x82173640
	goto loc_82173640;
loc_8217363C:
	// addi r3,r28,4
	ctx.r3.s64 = ctx.r28.s64 + 4;
loc_82173640:
	// bl 0x8210e878
	ctx.lr = 0x82173644;
	sub_8210E878(ctx, base);
	// lwz r31,88(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a030
	ctx.lr = 0x82173650;
	sub_8207A030(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82173660;
	sub_8207DAC0(ctx, base);
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173678
	if (!ctx.cr6.eq) goto loc_82173678;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82173678
	if (ctx.cr6.eq) goto loc_82173678;
	// stw r31,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r31.u32);
loc_82173678:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x82173680;
	sub_8207A8A0(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82173694
	if (ctx.cr6.lt) goto loc_82173694;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82173694;
	sub_8207A630(ctx, base);
loc_82173694:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821736A0"))) PPC_WEAK_FUNC(sub_821736A0);
PPC_FUNC_IMPL(__imp__sub_821736A0) {
	PPC_FUNC_PROLOGUE();
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// addi r3,r3,124
	ctx.r3.s64 = ctx.r3.s64 + 124;
	// b 0x820601f8
	sub_820601F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821736B4"))) PPC_WEAK_FUNC(sub_821736B4);
PPC_FUNC_IMPL(__imp__sub_821736B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821736B8"))) PPC_WEAK_FUNC(sub_821736B8);
PPC_FUNC_IMPL(__imp__sub_821736B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821736C0;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,108
	ctx.r3.s64 = 108;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// bl 0x82079fd8
	ctx.lr = 0x821736D8;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r26,15
	ctx.r26.s64 = 15;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x82173728
	if (ctx.cr6.eq) goto loc_82173728;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8217370C;
	sub_820601F8(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82173400
	ctx.lr = 0x82173720;
	sub_82173400(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x8217372c
	goto loc_8217372C;
loc_82173728:
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_8217372C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82173740
	if (ctx.cr6.lt) goto loc_82173740;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82173740;
	sub_8207A630(ctx, base);
loc_82173740:
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173758"))) PPC_WEAK_FUNC(sub_82173758);
PPC_FUNC_IMPL(__imp__sub_82173758) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82173760;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r27,15
	ctx.r27.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r4,r11,-12408
	ctx.r4.s64 = ctx.r11.s64 + -12408;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8217379C;
	sub_820601F8(ctx, base);
	// addi r5,r31,124
	ctx.r5.s64 = ctx.r31.s64 + 124;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206a968
	ctx.lr = 0x821737AC;
	sub_8206A968(ctx, base);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x821737c0
	if (ctx.cr6.lt) goto loc_821737C0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821737C0;
	sub_8207A630(ctx, base);
loc_821737C0:
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821737F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x82173808
	if (ctx.cr6.lt) goto loc_82173808;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x82173808;
	sub_8207A630(ctx, base);
loc_82173808:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173814"))) PPC_WEAK_FUNC(sub_82173814);
PPC_FUNC_IMPL(__imp__sub_82173814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173818"))) PPC_WEAK_FUNC(sub_82173818);
PPC_FUNC_IMPL(__imp__sub_82173818) {
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
	// bl 0x8216a178
	ctx.lr = 0x82173830;
	sub_8216A178(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,5324
	ctx.r9.s64 = ctx.r11.s64 + 5324;
	// li r8,15
	ctx.r8.s64 = 15;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r11,r31,124
	ctx.r11.s64 = ctx.r31.s64 + 124;
	// stw r8,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r10.u32);
	// stb r10,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8217386C"))) PPC_WEAK_FUNC(sub_8217386C);
PPC_FUNC_IMPL(__imp__sub_8217386C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173870"))) PPC_WEAK_FUNC(sub_82173870);
PPC_FUNC_IMPL(__imp__sub_82173870) {
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
	// li r3,152
	ctx.r3.s64 = 152;
	// bl 0x82079fd8
	ctx.lr = 0x82173888;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821738d4
	if (ctx.cr6.eq) goto loc_821738D4;
	// bl 0x8216a178
	ctx.lr = 0x82173898;
	sub_8216A178(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,5324
	ctx.r9.s64 = ctx.r11.s64 + 5324;
	// li r8,15
	ctx.r8.s64 = 15;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r11,r31,124
	ctx.r11.s64 = ctx.r31.s64 + 124;
	// stw r8,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r10.u32);
	// stb r10,128(r31)
	PPC_STORE_U8(ctx.r31.u32 + 128, ctx.r10.u8);
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
loc_821738D4:
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
}

__attribute__((alias("__imp__sub_821738EC"))) PPC_WEAK_FUNC(sub_821738EC);
PPC_FUNC_IMPL(__imp__sub_821738EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821738F0"))) PPC_WEAK_FUNC(sub_821738F0);
PPC_FUNC_IMPL(__imp__sub_821738F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821738F4"))) PPC_WEAK_FUNC(sub_821738F4);
PPC_FUNC_IMPL(__imp__sub_821738F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821738F8"))) PPC_WEAK_FUNC(sub_821738F8);
PPC_FUNC_IMPL(__imp__sub_821738F8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821738FC"))) PPC_WEAK_FUNC(sub_821738FC);
PPC_FUNC_IMPL(__imp__sub_821738FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173900"))) PPC_WEAK_FUNC(sub_82173900);
PPC_FUNC_IMPL(__imp__sub_82173900) {
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
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// lbz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217393c
	if (!ctx.cr6.eq) goto loc_8217393C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217393C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8217393C:
	// lbz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 28);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173960
	if (!ctx.cr6.eq) goto loc_82173960;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173960;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173960:
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

__attribute__((alias("__imp__sub_82173978"))) PPC_WEAK_FUNC(sub_82173978);
PPC_FUNC_IMPL(__imp__sub_82173978) {
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
	// lwz r31,16(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821739cc
	if (ctx.cr6.eq) goto loc_821739CC;
loc_8217399C:
	// lbz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821739c0
	if (!ctx.cr6.eq) goto loc_821739C0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821739C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821739C0:
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8217399c
	if (!ctx.cr6.eq) goto loc_8217399C;
loc_821739CC:
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

__attribute__((alias("__imp__sub_821739E4"))) PPC_WEAK_FUNC(sub_821739E4);
PPC_FUNC_IMPL(__imp__sub_821739E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821739E8"))) PPC_WEAK_FUNC(sub_821739E8);
PPC_FUNC_IMPL(__imp__sub_821739E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lbz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82173A10"))) PPC_WEAK_FUNC(sub_82173A10);
PPC_FUNC_IMPL(__imp__sub_82173A10) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173A14"))) PPC_WEAK_FUNC(sub_82173A14);
PPC_FUNC_IMPL(__imp__sub_82173A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173A18"))) PPC_WEAK_FUNC(sub_82173A18);
PPC_FUNC_IMPL(__imp__sub_82173A18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82173A20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r3,16
	ctx.r30.s64 = ctx.r3.s64 + 16;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82173a5c
	if (ctx.cr6.eq) goto loc_82173A5C;
loc_82173A38:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r31,4(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173A50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82173a38
	if (!ctx.cr6.eq) goto loc_82173A38;
loc_82173A5C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173A70"))) PPC_WEAK_FUNC(sub_82173A70);
PPC_FUNC_IMPL(__imp__sub_82173A70) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_82173A80:
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82173a9c
	if (ctx.cr6.eq) goto loc_82173A9C;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173a80
	if (!ctx.cr6.eq) goto loc_82173A80;
	// blr 
	return;
loc_82173A9C:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173ABC"))) PPC_WEAK_FUNC(sub_82173ABC);
PPC_FUNC_IMPL(__imp__sub_82173ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173AC0"))) PPC_WEAK_FUNC(sub_82173AC0);
PPC_FUNC_IMPL(__imp__sub_82173AC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173ADC"))) PPC_WEAK_FUNC(sub_82173ADC);
PPC_FUNC_IMPL(__imp__sub_82173ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173AE0"))) PPC_WEAK_FUNC(sub_82173AE0);
PPC_FUNC_IMPL(__imp__sub_82173AE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173af4
	if (!ctx.cr6.eq) goto loc_82173AF4;
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
loc_82173AF4:
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173B00"))) PPC_WEAK_FUNC(sub_82173B00);
PPC_FUNC_IMPL(__imp__sub_82173B00) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-1408
	ctx.r10.s64 = ctx.r11.s64 + -1408;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x82173a18
	ctx.lr = 0x82173B24;
	sub_82173A18(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,-1456
	ctx.r8.s64 = ctx.r9.s64 + -1456;
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

__attribute__((alias("__imp__sub_82173B44"))) PPC_WEAK_FUNC(sub_82173B44);
PPC_FUNC_IMPL(__imp__sub_82173B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173B48"))) PPC_WEAK_FUNC(sub_82173B48);
PPC_FUNC_IMPL(__imp__sub_82173B48) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,2952
	ctx.r4.s64 = ctx.r11.s64 + 2952;
	// b 0x820735c8
	sub_820735C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173B54"))) PPC_WEAK_FUNC(sub_82173B54);
PPC_FUNC_IMPL(__imp__sub_82173B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173B58"))) PPC_WEAK_FUNC(sub_82173B58);
PPC_FUNC_IMPL(__imp__sub_82173B58) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,192
	ctx.r4.s64 = ctx.r11.s64 + 192;
	// b 0x820735c8
	sub_820735C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173B64"))) PPC_WEAK_FUNC(sub_82173B64);
PPC_FUNC_IMPL(__imp__sub_82173B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173B68"))) PPC_WEAK_FUNC(sub_82173B68);
PPC_FUNC_IMPL(__imp__sub_82173B68) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// b 0x820735c8
	sub_820735C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173B74"))) PPC_WEAK_FUNC(sub_82173B74);
PPC_FUNC_IMPL(__imp__sub_82173B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173B78"))) PPC_WEAK_FUNC(sub_82173B78);
PPC_FUNC_IMPL(__imp__sub_82173B78) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r4,r11,13752
	ctx.r4.s64 = ctx.r11.s64 + 13752;
	// b 0x820735c8
	sub_820735C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173B84"))) PPC_WEAK_FUNC(sub_82173B84);
PPC_FUNC_IMPL(__imp__sub_82173B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173B88"))) PPC_WEAK_FUNC(sub_82173B88);
PPC_FUNC_IMPL(__imp__sub_82173B88) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r4,r11,13736
	ctx.r4.s64 = ctx.r11.s64 + 13736;
	// b 0x820735c8
	sub_820735C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173B94"))) PPC_WEAK_FUNC(sub_82173B94);
PPC_FUNC_IMPL(__imp__sub_82173B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173B98"))) PPC_WEAK_FUNC(sub_82173B98);
PPC_FUNC_IMPL(__imp__sub_82173B98) {
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
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173bc8
	if (!ctx.cr6.eq) goto loc_82173BC8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173BC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173BC8:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82173be8
	if (!ctx.cr6.eq) goto loc_82173BE8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173BE8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173BE8:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82173c08
	if (!ctx.cr6.eq) goto loc_82173C08;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173C08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173C08:
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

__attribute__((alias("__imp__sub_82173C1C"))) PPC_WEAK_FUNC(sub_82173C1C);
PPC_FUNC_IMPL(__imp__sub_82173C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173C20"))) PPC_WEAK_FUNC(sub_82173C20);
PPC_FUNC_IMPL(__imp__sub_82173C20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82173C28;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,16(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r28,r3,16
	ctx.r28.s64 = ctx.r3.s64 + 16;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82173ca8
	if (ctx.cr6.eq) goto loc_82173CA8;
loc_82173C44:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82173c64
	if (!ctx.cr6.eq) goto loc_82173C64;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173C64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173C64:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82173c98
	if (!ctx.cr6.eq) goto loc_82173C98;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82173C90;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82173ca0
	goto loc_82173CA0;
loc_82173C98:
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
loc_82173CA0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82173c44
	if (!ctx.cr6.eq) goto loc_82173C44;
loc_82173CA8:
	// lbz r11,14(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 14);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82173ccc
	if (ctx.cr6.eq) goto loc_82173CCC;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173ccc
	if (!ctx.cr6.eq) goto loc_82173CCC;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
loc_82173CCC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173CD4"))) PPC_WEAK_FUNC(sub_82173CD4);
PPC_FUNC_IMPL(__imp__sub_82173CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173CD8"))) PPC_WEAK_FUNC(sub_82173CD8);
PPC_FUNC_IMPL(__imp__sub_82173CD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82173CE0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,16(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r3,16
	ctx.r30.s64 = ctx.r3.s64 + 16;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82173d5c
	if (ctx.cr6.eq) goto loc_82173D5C;
loc_82173CF8:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82173d18
	if (!ctx.cr6.eq) goto loc_82173D18;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173D18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173D18:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82173d60
	if (ctx.cr6.eq) goto loc_82173D60;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x82173d50
	if (!ctx.cr6.eq) goto loc_82173D50;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82173D50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82173D50:
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82173cf8
	if (!ctx.cr6.eq) goto loc_82173CF8;
loc_82173D5C:
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
loc_82173D60:
	// lbz r11,14(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 14);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82173d80
	if (ctx.cr6.eq) goto loc_82173D80;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82173d80
	if (!ctx.cr6.eq) goto loc_82173D80;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
loc_82173D80:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82173D88"))) PPC_WEAK_FUNC(sub_82173D88);
PPC_FUNC_IMPL(__imp__sub_82173D88) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82173DA4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82173de8
	if (ctx.cr6.eq) goto loc_82173DE8;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r31.u32);
	// lis r8,-32233
	ctx.r8.s64 = -2112421888;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,5288
	ctx.r9.s64 = ctx.r10.s64 + 5288;
	// addi r7,r8,14872
	ctx.r7.s64 = ctx.r8.s64 + 14872;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
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
loc_82173DE8:
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
}

__attribute__((alias("__imp__sub_82173E00"))) PPC_WEAK_FUNC(sub_82173E00);
PPC_FUNC_IMPL(__imp__sub_82173E00) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r9,5820
	ctx.r8.s64 = ctx.r9.s64 + 5820;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// addi r5,r7,-1396
	ctx.r5.s64 = ctx.r7.s64 + -1396;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// addi r4,r6,840
	ctx.r4.s64 = ctx.r6.s64 + 840;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
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
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stb r11,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r11.u8);
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173E88"))) PPC_WEAK_FUNC(sub_82173E88);
PPC_FUNC_IMPL(__imp__sub_82173E88) {
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
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82173eb4
	if (ctx.cr6.eq) goto loc_82173EB4;
	// bl 0x8207a8a0
	ctx.lr = 0x82173EAC;
	sub_8207A8A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_82173EB4:
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

__attribute__((alias("__imp__sub_82173EC8"))) PPC_WEAK_FUNC(sub_82173EC8);
PPC_FUNC_IMPL(__imp__sub_82173EC8) {
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
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82173ef0
	if (ctx.cr6.eq) goto loc_82173EF0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82173ef8
	if (!ctx.cr6.eq) goto loc_82173EF8;
loc_82173EF0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a8a0
	ctx.lr = 0x82173EF8;
	sub_8207A8A0(ctx, base);
loc_82173EF8:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82173f14
	if (!ctx.cr6.eq) goto loc_82173F14;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a8a0
	ctx.lr = 0x82173F0C;
	sub_8207A8A0(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x8207a8a0
	ctx.lr = 0x82173F14;
	sub_8207A8A0(ctx, base);
loc_82173F14:
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

__attribute__((alias("__imp__sub_82173F28"))) PPC_WEAK_FUNC(sub_82173F28);
PPC_FUNC_IMPL(__imp__sub_82173F28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82173f4c
	if (!ctx.cr6.eq) goto loc_82173F4C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82173f50
	if (ctx.cr6.eq) goto loc_82173F50;
loc_82173F4C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82173F50:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173F58"))) PPC_WEAK_FUNC(sub_82173F58);
PPC_FUNC_IMPL(__imp__sub_82173F58) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173F64"))) PPC_WEAK_FUNC(sub_82173F64);
PPC_FUNC_IMPL(__imp__sub_82173F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82173F68"))) PPC_WEAK_FUNC(sub_82173F68);
PPC_FUNC_IMPL(__imp__sub_82173F68) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82173F78"))) PPC_WEAK_FUNC(sub_82173F78);
PPC_FUNC_IMPL(__imp__sub_82173F78) {
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
	// lbz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bgt cr6,0x821740dc
	if (ctx.cr6.gt) goto loc_821740DC;
	// lis r12,-32233
	ctx.r12.s64 = -2112421888;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,16300
	ctx.r12.s64 = ctx.r12.s64 + 16300;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_82174028;
	case 1:
		goto loc_82174028;
	case 2:
		goto loc_82174028;
	case 3:
		goto loc_82174028;
	case 4:
		goto loc_8217403C;
	case 5:
		goto loc_82174050;
	case 6:
		goto loc_82174064;
	case 7:
		goto loc_82174078;
	case 8:
		goto loc_8217408C;
	case 9:
		goto loc_821740A0;
	case 10:
		goto loc_821740B4;
	case 11:
		goto loc_821740C8;
	case 12:
		goto loc_8217403C;
	case 13:
		goto loc_82174050;
	case 14:
		goto loc_82174064;
	case 15:
		goto loc_82174078;
	case 16:
		goto loc_8217403C;
	case 17:
		goto loc_82174050;
	case 18:
		goto loc_82174064;
	case 19:
		goto loc_82174078;
	case 20:
		goto loc_8217403C;
	case 21:
		goto loc_82174050;
	case 22:
		goto loc_82174064;
	case 23:
		goto loc_82174078;
	case 24:
		goto loc_8217403C;
	case 25:
		goto loc_82174050;
	case 26:
		goto loc_82174064;
	case 27:
		goto loc_82174078;
	case 28:
		goto loc_82174028;
	case 29:
		goto loc_82174078;
	case 30:
		goto loc_821740C8;
	default:
		__builtin_unreachable();
	}
	// lwz r16,16424(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16424);
	// lwz r16,16424(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16424);
	// lwz r16,16424(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16424);
	// lwz r16,16424(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16424);
	// lwz r16,16444(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16444);
	// lwz r16,16464(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16464);
	// lwz r16,16484(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16484);
	// lwz r16,16504(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16504);
	// lwz r16,16524(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16524);
	// lwz r16,16544(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16544);
	// lwz r16,16564(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16564);
	// lwz r16,16584(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16584);
	// lwz r16,16444(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16444);
	// lwz r16,16464(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16464);
	// lwz r16,16484(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16484);
	// lwz r16,16504(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16504);
	// lwz r16,16444(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16444);
	// lwz r16,16464(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16464);
	// lwz r16,16484(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16484);
	// lwz r16,16504(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16504);
	// lwz r16,16444(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16444);
	// lwz r16,16464(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16464);
	// lwz r16,16484(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16484);
	// lwz r16,16504(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16504);
	// lwz r16,16444(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16444);
	// lwz r16,16464(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16464);
	// lwz r16,16484(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16484);
	// lwz r16,16504(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16504);
	// lwz r16,16424(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16424);
	// lwz r16,16504(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16504);
	// lwz r16,16584(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16584);
loc_82174028:
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
loc_8217403C:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174050:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174064:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174078:
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217408C:
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821740A0:
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821740B4:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821740C8:
	// li r3,9
	ctx.r3.s64 = 9;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821740DC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-21064
	ctx.r3.s64 = ctx.r11.s64 + -21064;
	// bl 0x8207bc98
	ctx.lr = 0x821740E8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821740EC;
	sub_8207B288(ctx, base);
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

__attribute__((alias("__imp__sub_82174100"))) PPC_WEAK_FUNC(sub_82174100);
PPC_FUNC_IMPL(__imp__sub_82174100) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174118"))) PPC_WEAK_FUNC(sub_82174118);
PPC_FUNC_IMPL(__imp__sub_82174118) {
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
	// lbz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bgt cr6,0x821742c0
	if (ctx.cr6.gt) goto loc_821742C0;
	// lis r12,-32233
	ctx.r12.s64 = -2112421888;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,16716
	ctx.r12.s64 = ctx.r12.s64 + 16716;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_821741D0;
	case 1:
		goto loc_821741E4;
	case 2:
		goto loc_821741E4;
	case 3:
		goto loc_821741F8;
	case 4:
		goto loc_821741F8;
	case 5:
		goto loc_821741F8;
	case 6:
		goto loc_821741F8;
	case 7:
		goto loc_821741F8;
	case 8:
		goto loc_8217420C;
	case 9:
		goto loc_8217420C;
	case 10:
		goto loc_8217420C;
	case 11:
		goto loc_8217420C;
	case 12:
		goto loc_82174220;
	case 13:
		goto loc_82174220;
	case 14:
		goto loc_82174220;
	case 15:
		goto loc_82174220;
	case 16:
		goto loc_82174234;
	case 17:
		goto loc_82174234;
	case 18:
		goto loc_82174234;
	case 19:
		goto loc_82174234;
	case 20:
		goto loc_82174248;
	case 21:
		goto loc_82174248;
	case 22:
		goto loc_82174248;
	case 23:
		goto loc_82174248;
	case 24:
		goto loc_8217425C;
	case 25:
		goto loc_8217425C;
	case 26:
		goto loc_8217425C;
	case 27:
		goto loc_8217425C;
	case 28:
		goto loc_82174270;
	case 29:
		goto loc_82174270;
	case 30:
		goto loc_82174284;
	case 31:
		goto loc_82174298;
	case 32:
		goto loc_821742AC;
	default:
		__builtin_unreachable();
	}
	// lwz r16,16848(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16848);
	// lwz r16,16868(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16868);
	// lwz r16,16868(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16868);
	// lwz r16,16888(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16888);
	// lwz r16,16888(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16888);
	// lwz r16,16888(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16888);
	// lwz r16,16888(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16888);
	// lwz r16,16888(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16888);
	// lwz r16,16908(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16908);
	// lwz r16,16908(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16908);
	// lwz r16,16908(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16908);
	// lwz r16,16908(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16908);
	// lwz r16,16928(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16928);
	// lwz r16,16928(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16928);
	// lwz r16,16928(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16928);
	// lwz r16,16928(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16928);
	// lwz r16,16948(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16948);
	// lwz r16,16948(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16948);
	// lwz r16,16948(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16948);
	// lwz r16,16948(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16948);
	// lwz r16,16968(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16968);
	// lwz r16,16968(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16968);
	// lwz r16,16968(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16968);
	// lwz r16,16968(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16968);
	// lwz r16,16988(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16988);
	// lwz r16,16988(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16988);
	// lwz r16,16988(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16988);
	// lwz r16,16988(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16988);
	// lwz r16,17008(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 17008);
	// lwz r16,17008(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 17008);
	// lwz r16,17028(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 17028);
	// lwz r16,17048(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 17048);
	// lwz r16,17068(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 17068);
loc_821741D0:
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
loc_821741E4:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821741F8:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217420C:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174220:
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174234:
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174248:
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217425C:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174270:
	// li r3,9
	ctx.r3.s64 = 9;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174284:
	// li r3,10
	ctx.r3.s64 = 10;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174298:
	// li r3,11
	ctx.r3.s64 = 11;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821742AC:
	// li r3,12
	ctx.r3.s64 = 12;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821742C0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-21168
	ctx.r3.s64 = ctx.r11.s64 + -21168;
	// bl 0x8207bc98
	ctx.lr = 0x821742CC;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821742D0;
	sub_8207B288(ctx, base);
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

__attribute__((alias("__imp__sub_821742E4"))) PPC_WEAK_FUNC(sub_821742E4);
PPC_FUNC_IMPL(__imp__sub_821742E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821742E8"))) PPC_WEAK_FUNC(sub_821742E8);
PPC_FUNC_IMPL(__imp__sub_821742E8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 | ctx.r8.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 | ctx.r7.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174318"))) PPC_WEAK_FUNC(sub_82174318);
PPC_FUNC_IMPL(__imp__sub_82174318) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r5,r8
	ctx.r3.u64 = ctx.r5.u64 | ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217433C"))) PPC_WEAK_FUNC(sub_8217433C);
PPC_FUNC_IMPL(__imp__sub_8217433C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174340"))) PPC_WEAK_FUNC(sub_82174340);
PPC_FUNC_IMPL(__imp__sub_82174340) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 | ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174358"))) PPC_WEAK_FUNC(sub_82174358);
PPC_FUNC_IMPL(__imp__sub_82174358) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174364"))) PPC_WEAK_FUNC(sub_82174364);
PPC_FUNC_IMPL(__imp__sub_82174364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174368"))) PPC_WEAK_FUNC(sub_82174368);
PPC_FUNC_IMPL(__imp__sub_82174368) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174394"))) PPC_WEAK_FUNC(sub_82174394);
PPC_FUNC_IMPL(__imp__sub_82174394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174398"))) PPC_WEAK_FUNC(sub_82174398);
PPC_FUNC_IMPL(__imp__sub_82174398) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 | ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821743B8"))) PPC_WEAK_FUNC(sub_821743B8);
PPC_FUNC_IMPL(__imp__sub_821743B8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 | ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821743CC"))) PPC_WEAK_FUNC(sub_821743CC);
PPC_FUNC_IMPL(__imp__sub_821743CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821743D0"))) PPC_WEAK_FUNC(sub_821743D0);
PPC_FUNC_IMPL(__imp__sub_821743D0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821743D8"))) PPC_WEAK_FUNC(sub_821743D8);
PPC_FUNC_IMPL(__imp__sub_821743D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r10,7(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 7);
	// lbz r9,6(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r7,5(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r4,r7
	ctx.r10.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lbz r7,10(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10);
	// lbz r6,9(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9);
	// lbz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// lbz r4,11(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// rotlwi r10,r4,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// or r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 | ctx.r7.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 | ctx.r6.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 | ctx.r5.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// lbz r4,14(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 14);
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 13);
	// lbz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// lbz r8,15(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 15);
	// rotlwi r7,r8,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// or r6,r7,r4
	ctx.r6.u64 = ctx.r7.u64 | ctx.r4.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r10
	ctx.r4.u64 = ctx.r5.u64 | ctx.r10.u64;
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// lbz r8,18(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 18);
	// lbz r7,17(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 17);
	// lbz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 16);
	// lbz r5,19(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 19);
	// rotlwi r4,r5,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// or r10,r4,r8
	ctx.r10.u64 = ctx.r4.u64 | ctx.r8.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r7
	ctx.r8.u64 = ctx.r9.u64 | ctx.r7.u64;
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// lbz r5,22(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 22);
	// lbz r4,21(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 21);
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 20);
	// lbz r9,23(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 23);
	// rotlwi r8,r9,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// or r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 | ctx.r5.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r4
	ctx.r5.u64 = ctx.r6.u64 | ctx.r4.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r10,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// lbz r9,26(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 26);
	// lbz r8,25(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 25);
	// lbz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 24);
	// lbz r6,27(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 27);
	// rotlwi r5,r6,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 | ctx.r8.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 | ctx.r7.u64;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// lbz r6,30(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 30);
	// lbz r5,29(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 29);
	// lbz r4,31(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 31);
	// rotlwi r10,r4,8
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// or r9,r10,r6
	ctx.r9.u64 = ctx.r10.u64 | ctx.r6.u64;
	// lbz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 28);
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r5
	ctx.r6.u64 = ctx.r7.u64 | ctx.r5.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r5,r8
	ctx.r10.u64 = ctx.r5.u64 | ctx.r8.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r4.u32);
	// lbz r10,34(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 34);
	// lbz r9,33(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 33);
	// lbz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 32);
	// lbz r7,35(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 35);
	// rotlwi r6,r7,8
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r4,r9
	ctx.r10.u64 = ctx.r4.u64 | ctx.r9.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 | ctx.r8.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// lbz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 38);
	// lbz r7,37(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 37);
	// lbz r4,36(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 36);
	// lbz r6,39(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 39);
	// rotlwi r5,r6,8
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// or r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 | ctx.r10.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r6,r4
	ctx.r10.u64 = ctx.r6.u64 | ctx.r4.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217458C"))) PPC_WEAK_FUNC(sub_8217458C);
PPC_FUNC_IMPL(__imp__sub_8217458C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174590"))) PPC_WEAK_FUNC(sub_82174590);
PPC_FUNC_IMPL(__imp__sub_82174590) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82174598;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82174648
	if (ctx.cr6.eq) goto loc_82174648;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// subf r30,r11,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r11.s64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a030
	ctx.lr = 0x821745C0;
	sub_8207A030(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// add. r6,r11,r30
	ctx.r6.u64 = ctx.r11.u64 + ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble 0x821745dc
	if (!ctx.cr0.gt) goto loc_821745DC;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x821745DC;
	sub_8207A520(ctx, base);
loc_821745DC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a030
	ctx.lr = 0x821745F8;
	sub_8207A030(ctx, base);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// add. r6,r11,r30
	ctx.r6.u64 = ctx.r11.u64 + ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble 0x82174614
	if (!ctx.cr0.gt) goto loc_82174614;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x82174614;
	sub_8207A520(ctx, base);
loc_82174614:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82174628
	if (ctx.cr6.eq) goto loc_82174628;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82174630
	if (!ctx.cr6.eq) goto loc_82174630;
loc_82174628:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a8a0
	ctx.lr = 0x82174630;
	sub_8207A8A0(ctx, base);
loc_82174630:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bl 0x821743d8
	ctx.lr = 0x82174644;
	sub_821743D8(ctx, base);
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
loc_82174648:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82174650"))) PPC_WEAK_FUNC(sub_82174650);
PPC_FUNC_IMPL(__imp__sub_82174650) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,44(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174660"))) PPC_WEAK_FUNC(sub_82174660);
PPC_FUNC_IMPL(__imp__sub_82174660) {
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
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bl 0x821743d8
	ctx.lr = 0x82174688;
	sub_821743D8(ctx, base);
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

__attribute__((alias("__imp__sub_8217469C"))) PPC_WEAK_FUNC(sub_8217469C);
PPC_FUNC_IMPL(__imp__sub_8217469C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821746A0"))) PPC_WEAK_FUNC(sub_821746A0);
PPC_FUNC_IMPL(__imp__sub_821746A0) {
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
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821747b0
	if (ctx.cr6.eq) goto loc_821747B0;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174118
	ctx.lr = 0x821746C0;
	sub_82174118(ctx, base);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x821747a0
	if (ctx.cr6.gt) goto loc_821747A0;
	// lis r12,-32233
	ctx.r12.s64 = -2112421888;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,18148
	ctx.r12.s64 = ctx.r12.s64 + 18148;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_821747B0;
	case 1:
		goto loc_82174714;
	case 2:
		goto loc_82174728;
	case 3:
		goto loc_82174728;
	case 4:
		goto loc_821747A0;
	case 5:
		goto loc_821747A0;
	case 6:
		goto loc_82174750;
	case 7:
		goto loc_82174764;
	case 8:
		goto loc_8217473C;
	case 9:
		goto loc_8217473C;
	case 10:
		goto loc_82174778;
	case 11:
		goto loc_8217478C;
	default:
		__builtin_unreachable();
	}
	// lwz r16,18352(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18352);
	// lwz r16,18196(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18196);
	// lwz r16,18216(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18216);
	// lwz r16,18216(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18216);
	// lwz r16,18336(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18336);
	// lwz r16,18336(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18336);
	// lwz r16,18256(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18256);
	// lwz r16,18276(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18276);
	// lwz r16,18236(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18236);
	// lwz r16,18236(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18236);
	// lwz r16,18296(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18296);
	// lwz r16,18316(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 18316);
loc_82174714:
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
loc_82174728:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217473C:
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174750:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174764:
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174778:
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217478C:
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821747A0:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-21024
	ctx.r3.s64 = ctx.r11.s64 + -21024;
	// bl 0x8207bc98
	ctx.lr = 0x821747AC;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821747B0;
	sub_8207B288(ctx, base);
loc_821747B0:
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

__attribute__((alias("__imp__sub_821747C4"))) PPC_WEAK_FUNC(sub_821747C4);
PPC_FUNC_IMPL(__imp__sub_821747C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821747C8"))) PPC_WEAK_FUNC(sub_821747C8);
PPC_FUNC_IMPL(__imp__sub_821747C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821747DC"))) PPC_WEAK_FUNC(sub_821747DC);
PPC_FUNC_IMPL(__imp__sub_821747DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821747E0"))) PPC_WEAK_FUNC(sub_821747E0);
PPC_FUNC_IMPL(__imp__sub_821747E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82174804
	if (!ctx.cr6.eq) goto loc_82174804;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82174808
	if (ctx.cr6.eq) goto loc_82174808;
loc_82174804:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82174808:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174818"))) PPC_WEAK_FUNC(sub_82174818);
PPC_FUNC_IMPL(__imp__sub_82174818) {
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
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bgt cr6,0x8217490c
	if (ctx.cr6.gt) goto loc_8217490C;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82174864
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174864;
	// bdzf 4*cr6+eq,0x82174890
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174890;
	// bne cr6,0x821748c8
	if (!ctx.cr6.eq) goto loc_821748C8;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r9,r11,r4
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174864:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r11,r11,r4
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// or r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82174890:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r11,r11,r4
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r5,r7
	ctx.r3.u64 = ctx.r5.u64 | ctx.r7.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_821748C8:
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r11,r11,r4
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r8,r10,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r11,r6
	ctx.r3.u64 = ctx.r11.u64 | ctx.r6.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217490C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-21128
	ctx.r3.s64 = ctx.r11.s64 + -21128;
	// bl 0x8207bc98
	ctx.lr = 0x82174918;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217491C;
	sub_8207B288(ctx, base);
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

__attribute__((alias("__imp__sub_82174930"))) PPC_WEAK_FUNC(sub_82174930);
PPC_FUNC_IMPL(__imp__sub_82174930) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,-25
	ctx.r11.s64 = ctx.r11.s64 + -25;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x821749bc
	if (ctx.cr6.gt) goto loc_821749BC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217495c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217495C;
	// bdzf 4*cr6+eq,0x82174970
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174970;
	// bne cr6,0x82174990
	if (!ctx.cr6.eq) goto loc_82174990;
	// lbz r3,1(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// blr 
	return;
loc_8217495C:
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 | ctx.r10.u64;
	// blr 
	return;
loc_82174970:
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 | ctx.r8.u64;
	// blr 
	return;
loc_82174990:
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,1(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// blr 
	return;
loc_821749BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821749C4"))) PPC_WEAK_FUNC(sub_821749C4);
PPC_FUNC_IMPL(__imp__sub_821749C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821749C8"))) PPC_WEAK_FUNC(sub_821749C8);
PPC_FUNC_IMPL(__imp__sub_821749C8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,-21
	ctx.r11.s64 = ctx.r11.s64 + -21;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82174a54
	if (ctx.cr6.gt) goto loc_82174A54;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x821749f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821749F4;
	// bdzf 4*cr6+eq,0x82174a08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174A08;
	// bne cr6,0x82174a28
	if (!ctx.cr6.eq) goto loc_82174A28;
	// lbz r3,1(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// blr 
	return;
loc_821749F4:
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 | ctx.r10.u64;
	// blr 
	return;
loc_82174A08:
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 | ctx.r8.u64;
	// blr 
	return;
loc_82174A28:
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,1(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// blr 
	return;
loc_82174A54:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174A5C"))) PPC_WEAK_FUNC(sub_82174A5C);
PPC_FUNC_IMPL(__imp__sub_82174A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174A60"))) PPC_WEAK_FUNC(sub_82174A60);
PPC_FUNC_IMPL(__imp__sub_82174A60) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,-17
	ctx.r11.s64 = ctx.r11.s64 + -17;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82174aec
	if (ctx.cr6.gt) goto loc_82174AEC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82174a8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174A8C;
	// bdzf 4*cr6+eq,0x82174aa0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174AA0;
	// bne cr6,0x82174ac0
	if (!ctx.cr6.eq) goto loc_82174AC0;
	// lbz r3,1(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// blr 
	return;
loc_82174A8C:
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 | ctx.r10.u64;
	// blr 
	return;
loc_82174AA0:
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 | ctx.r8.u64;
	// blr 
	return;
loc_82174AC0:
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,1(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// blr 
	return;
loc_82174AEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174AF4"))) PPC_WEAK_FUNC(sub_82174AF4);
PPC_FUNC_IMPL(__imp__sub_82174AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174AF8"))) PPC_WEAK_FUNC(sub_82174AF8);
PPC_FUNC_IMPL(__imp__sub_82174AF8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,-13
	ctx.r11.s64 = ctx.r11.s64 + -13;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82174b84
	if (ctx.cr6.gt) goto loc_82174B84;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82174b24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174B24;
	// bdzf 4*cr6+eq,0x82174b38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174B38;
	// bne cr6,0x82174b58
	if (!ctx.cr6.eq) goto loc_82174B58;
	// lbz r3,1(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// blr 
	return;
loc_82174B24:
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 | ctx.r10.u64;
	// blr 
	return;
loc_82174B38:
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 | ctx.r8.u64;
	// blr 
	return;
loc_82174B58:
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,1(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// blr 
	return;
loc_82174B84:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174B8C"))) PPC_WEAK_FUNC(sub_82174B8C);
PPC_FUNC_IMPL(__imp__sub_82174B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174B90"))) PPC_WEAK_FUNC(sub_82174B90);
PPC_FUNC_IMPL(__imp__sub_82174B90) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x82174c34
	if (ctx.cr6.gt) goto loc_82174C34;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82174c34
	if (ctx.cr6.eq) goto loc_82174C34;
	// bdz 0x82174bbc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82174BBC;
	// bdz 0x82174bc8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82174BC8;
	// bdz 0x82174be0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82174BE0;
	// b 0x82174c04
	goto loc_82174C04;
loc_82174BBC:
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// blr 
	return;
loc_82174BC8:
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r8,r10
	ctx.r3.u64 = ctx.r8.u64 | ctx.r10.u64;
	// blr 
	return;
loc_82174BE0:
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r5,r8
	ctx.r3.u64 = ctx.r5.u64 | ctx.r8.u64;
	// blr 
	return;
loc_82174C04:
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,1(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 | ctx.r8.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r11,r7
	ctx.r3.u64 = ctx.r11.u64 | ctx.r7.u64;
	// blr 
	return;
loc_82174C34:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174C3C"))) PPC_WEAK_FUNC(sub_82174C3C);
PPC_FUNC_IMPL(__imp__sub_82174C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174C40"))) PPC_WEAK_FUNC(sub_82174C40);
PPC_FUNC_IMPL(__imp__sub_82174C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 | ctx.r8.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r7
	ctx.r10.u64 = ctx.r11.u64 | ctx.r7.u64;
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// lfs f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174C78"))) PPC_WEAK_FUNC(sub_82174C78);
PPC_FUNC_IMPL(__imp__sub_82174C78) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,7(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// lbz r7,3(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r10,6(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r5,2(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r4,r7,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// or r7,r4,r5
	ctx.r7.u64 = ctx.r4.u64 | ctx.r5.u64;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r4,r7,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r5,r10,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r4,r9
	ctx.r10.u64 = ctx.r4.u64 | ctx.r9.u64;
	// or r3,r5,r8
	ctx.r3.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r8,r10,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r3,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// or r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 | ctx.r11.u64;
	// rldicr r4,r5,32,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF00000000;
	// or r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 | ctx.r8.u64;
	// or r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 | ctx.r6.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174CDC"))) PPC_WEAK_FUNC(sub_82174CDC);
PPC_FUNC_IMPL(__imp__sub_82174CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174CE0"))) PPC_WEAK_FUNC(sub_82174CE0);
PPC_FUNC_IMPL(__imp__sub_82174CE0) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,6(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r8,3(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// lbz r7,2(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r4,r8,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 | ctx.r7.u64;
	// lbz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r6,r8,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r7,r10,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r11
	ctx.r3.u64 = ctx.r6.u64 | ctx.r11.u64;
	// extsw r4,r7
	ctx.r4.s64 = ctx.r7.s32;
	// rlwinm r10,r3,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rldicr r8,r11,32,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// or r3,r7,r9
	ctx.r3.u64 = ctx.r7.u64 | ctx.r9.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174D38"))) PPC_WEAK_FUNC(sub_82174D38);
PPC_FUNC_IMPL(__imp__sub_82174D38) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// lbz r9,2(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// extsb r7,r10
	ctx.r7.s64 = ctx.r10.s8;
	// lbz r6,1(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lbz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// rlwinm r11,r7,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r9,r5,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// or r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 | ctx.r6.u64;
	// or r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 | ctx.r4.u64;
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rldicr r4,r6,32,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF00000000;
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 | ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174D84"))) PPC_WEAK_FUNC(sub_82174D84);
PPC_FUNC_IMPL(__imp__sub_82174D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174D88"))) PPC_WEAK_FUNC(sub_82174D88);
PPC_FUNC_IMPL(__imp__sub_82174D88) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lbz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// lbz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb r4,r7
	ctx.r4.s64 = ctx.r7.s8;
	// rlwinm r3,r6,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// rldicr r11,r4,32,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000;
	// or r10,r3,r8
	ctx.r10.u64 = ctx.r3.u64 | ctx.r8.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// or r3,r8,r5
	ctx.r3.u64 = ctx.r8.u64 | ctx.r5.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174DC4"))) PPC_WEAK_FUNC(sub_82174DC4);
PPC_FUNC_IMPL(__imp__sub_82174DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174DC8"))) PPC_WEAK_FUNC(sub_82174DC8);
PPC_FUNC_IMPL(__imp__sub_82174DC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82174DD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82174DEC;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// rotlwi r8,r3,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r3.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r9.u32);
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// add r11,r10,r30
	ctx.r11.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

