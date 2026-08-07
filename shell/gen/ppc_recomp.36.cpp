#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821CE650"))) PPC_WEAK_FUNC(sub_821CE650);
PPC_FUNC_IMPL(__imp__sub_821CE650) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r5,-32227
	ctx.r5.s64 = -2112028672;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r4,r8,-1396
	ctx.r4.s64 = ctx.r8.s64 + -1396;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r7,r7,840
	ctx.r7.s64 = ctx.r7.s64 + 840;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// addi r6,r6,-1384
	ctx.r6.s64 = ctx.r6.s64 + -1384;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r5,r5,-6592
	ctx.r5.s64 = ctx.r5.s64 + -6592;
	// stw r7,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r7.u32);
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
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r5,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE6EC"))) PPC_WEAK_FUNC(sub_821CE6EC);
PPC_FUNC_IMPL(__imp__sub_821CE6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE6F0"))) PPC_WEAK_FUNC(sub_821CE6F0);
PPC_FUNC_IMPL(__imp__sub_821CE6F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lfs f0,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE71C"))) PPC_WEAK_FUNC(sub_821CE71C);
PPC_FUNC_IMPL(__imp__sub_821CE71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE720"))) PPC_WEAK_FUNC(sub_821CE720);
PPC_FUNC_IMPL(__imp__sub_821CE720) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CE728;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82079fd8
	ctx.lr = 0x821CE734;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce74c
	if (ctx.cr6.eq) goto loc_821CE74C;
	// bl 0x821ce650
	ctx.lr = 0x821CE744;
	sub_821CE650(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x821ce750
	goto loc_821CE750;
loc_821CE74C:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_821CE750:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821CE758;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce774
	if (ctx.cr6.eq) goto loc_821CE774;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-1428
	ctx.r10.s64 = ctx.r11.s64 + -1428;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821ce778
	goto loc_821CE778;
loc_821CE774:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_821CE778:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r10,-2232
	ctx.r4.s64 = ctx.r10.s64 + -2232;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821CE79C;
	sub_82060368(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821736b8
	ctx.lr = 0x821CE7AC;
	sub_821736B8(ctx, base);
	// bl 0x821706e8
	ctx.lr = 0x821CE7B0;
	sub_821706E8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CE7BC"))) PPC_WEAK_FUNC(sub_821CE7BC);
PPC_FUNC_IMPL(__imp__sub_821CE7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE7C0"))) PPC_WEAK_FUNC(sub_821CE7C0);
PPC_FUNC_IMPL(__imp__sub_821CE7C0) {
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
	ctx.lr = 0x821CE7E4;
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

__attribute__((alias("__imp__sub_821CE800"))) PPC_WEAK_FUNC(sub_821CE800);
PPC_FUNC_IMPL(__imp__sub_821CE800) {
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
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE818"))) PPC_WEAK_FUNC(sub_821CE818);
PPC_FUNC_IMPL(__imp__sub_821CE818) {
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
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f13,32(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE830"))) PPC_WEAK_FUNC(sub_821CE830);
PPC_FUNC_IMPL(__imp__sub_821CE830) {
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
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE848"))) PPC_WEAK_FUNC(sub_821CE848);
PPC_FUNC_IMPL(__imp__sub_821CE848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// addi r5,r9,5312
	ctx.r5.s64 = ctx.r9.s64 + 5312;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r4,r7,-2064
	ctx.r4.s64 = ctx.r7.s64 + -2064;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// lfs f0,21768(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lfs f13,-21836(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r11.u8);
	// stb r11,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r11.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// lfs f12,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r11.u8);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f12,64(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f12,68(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE8C4"))) PPC_WEAK_FUNC(sub_821CE8C4);
PPC_FUNC_IMPL(__imp__sub_821CE8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE8C8"))) PPC_WEAK_FUNC(sub_821CE8C8);
PPC_FUNC_IMPL(__imp__sub_821CE8C8) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// addi r8,r9,5300
	ctx.r8.s64 = ctx.r9.s64 + 5300;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r11.u8);
	// stb r11,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r11.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE8FC"))) PPC_WEAK_FUNC(sub_821CE8FC);
PPC_FUNC_IMPL(__imp__sub_821CE8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE900"))) PPC_WEAK_FUNC(sub_821CE900);
PPC_FUNC_IMPL(__imp__sub_821CE900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r5,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r8,181(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 181);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lbz r7,182(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 182);
	// std r3,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r3.u64);
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// std r4,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r4.u64);
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// lbz r9,183(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 183);
	// lfs f11,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f11.f64 = double(temp.f32);
	// lbz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 180);
	// rlwimi r11,r9,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// clrlwi r6,r11,16
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFF;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r11,-31312(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31312);
	// rlwimi r8,r6,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwimi r7,r8,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// stw r7,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d8c8
	ctx.lr = 0x821CE994;
	sub_8216D8C8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CE9A4"))) PPC_WEAK_FUNC(sub_821CE9A4);
PPC_FUNC_IMPL(__imp__sub_821CE9A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE9A8"))) PPC_WEAK_FUNC(sub_821CE9A8);
PPC_FUNC_IMPL(__imp__sub_821CE9A8) {
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
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lbz r7,165(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 165);
	// li r8,32
	ctx.r8.s64 = 32;
	// lbz r6,166(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// std r3,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r3.u64);
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// lbz r9,167(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 167);
	// lfs f11,156(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// lbz r11,164(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 164);
	// rlwimi r11,r9,8,16,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r11.u64 & 0xFFFFFFFFFFFF00FF);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// rlwimi r7,r5,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r3,-32224
	ctx.r3.s64 = -2111832064;
	// rlwimi r6,r7,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// lwz r11,-31312(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d708
	ctx.lr = 0x821CEA28;
	sub_8216D708(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CEA38"))) PPC_WEAK_FUNC(sub_821CEA38);
PPC_FUNC_IMPL(__imp__sub_821CEA38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821CEA40;
	__savegprlr_28(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// addi r30,r11,48
	ctx.r30.s64 = ctx.r11.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82075840
	ctx.lr = 0x821CEA60;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820758e8
	ctx.lr = 0x821CEA6C;
	sub_820758E8(ctx, base);
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// bl 0x82075840
	ctx.lr = 0x821CEA78;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x821CEA88;
	sub_8207DAC0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r30,-32225
	ctx.r30.s64 = -2111897600;
	// lfs f10,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f11,48(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,32(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f8,28(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f13,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-14024(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -14024);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f6,f0,f13
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f12,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f5,f0,f11
	ctx.f5.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmuls f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f5,116(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f13,f6,f11
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f12,f6,f11
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f2,f6,f10
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f1,f6,f10
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f0,f6,f10
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmuls f11,f6,f11
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fneg f2,f4
	ctx.f2.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fneg f1,f3
	ctx.f1.u64 = ctx.f3.u64 ^ 0x8000000000000000;
	// bl 0x821673f0
	ctx.lr = 0x821CEB20;
	sub_821673F0(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lfs f1,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82167618
	ctx.lr = 0x821CEB2C;
	sub_82167618(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821676b0
	ctx.lr = 0x821CEB3C;
	sub_821676B0(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lfs f1,-31332(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31332);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82167618
	ctx.lr = 0x821CEB4C;
	sub_82167618(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821676b0
	ctx.lr = 0x821CEB5C;
	sub_821676B0(ctx, base);
	// lfs f5,-14024(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -14024);
	ctx.f5.f64 = double(temp.f32);
	// lfs f10,32(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f9,28(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f2,f10,f5
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmuls f1,f9,f5
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// bl 0x821673f0
	ctx.lr = 0x821CEB7C;
	sub_821673F0(ctx, base);
	// lfs f8,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f7,36(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f5
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f5,f7,f5
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// fneg f2,f6
	ctx.f2.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// fneg f1,f5
	ctx.f1.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// bl 0x821673f0
	ctx.lr = 0x821CEBA0;
	sub_821673F0(ctx, base);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821676b0
	ctx.lr = 0x821CEBB0;
	sub_821676B0(ctx, base);
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// bl 0x82075840
	ctx.lr = 0x821CEBBC;
	sub_82075840(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x821CEBC8;
	sub_8207DAC0(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8216bed0
	ctx.lr = 0x821CEBD0;
	sub_8216BED0(ctx, base);
	// lfs f4,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f3.f64 = double(temp.f32);
	// fcmpu cr6,f4,f3
	ctx.cr6.compare(ctx.f4.f64, ctx.f3.f64);
	// bgt cr6,0x821cebf4
	if (ctx.cr6.gt) goto loc_821CEBF4;
	// lfs f0,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,68(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x821cebf8
	if (!ctx.cr6.gt) goto loc_821CEBF8;
loc_821CEBF4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821CEBF8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cecdc
	if (ctx.cr6.eq) goto loc_821CECDC;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r30,-31312(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// ld r5,136(r30)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r30.u32 + 136);
	// ld r6,144(r30)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r30.u32 + 144);
	// bl 0x8206e7f8
	ctx.lr = 0x821CEC40;
	sub_8206E7F8(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// bgt cr6,0x821cec64
	if (ctx.cr6.gt) goto loc_821CEC64;
	// fcmpu cr6,f11,f12
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// ble cr6,0x821cec68
	if (!ctx.cr6.gt) goto loc_821CEC68;
loc_821CEC64:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821CEC68:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x821cece4
	if (ctx.cr6.eq) goto loc_821CECE4;
	// lwz r11,136(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,140(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// lwz r8,144(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// lwz r7,148(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// stfs f0,136(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 136, temp.u32);
	// stfs f11,140(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 140, temp.u32);
	// stfs f13,144(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 144, temp.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stfs f12,148(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 148, temp.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// bl 0x82173978
	ctx.lr = 0x821CECB4;
	sub_82173978(ctx, base);
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,136(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 136, temp.u32);
	// stfs f13,140(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// stfs f12,144(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// stfs f11,148(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// b 0x821cecec
	goto loc_821CECEC;
loc_821CECDC:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821CECE4:
	// bl 0x82173978
	ctx.lr = 0x821CECE8;
	sub_82173978(ctx, base);
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
loc_821CECEC:
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
	// lwz r11,64(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// li r9,48
	ctx.r9.s64 = 48;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x821ced10
	if (ctx.cr0.eq) goto loc_821CED10;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_821CED10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82075840
	ctx.lr = 0x821CED18;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x821CED28;
	sub_8207DAC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82075840
	ctx.lr = 0x821CED30;
	sub_82075840(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x821CED3C;
	sub_8207DAC0(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x8216bed0
	ctx.lr = 0x821CED44;
	sub_8216BED0(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CED4C"))) PPC_WEAK_FUNC(sub_821CED4C);
PPC_FUNC_IMPL(__imp__sub_821CED4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CED50"))) PPC_WEAK_FUNC(sub_821CED50);
PPC_FUNC_IMPL(__imp__sub_821CED50) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
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
	ctx.lr = 0x821CED84;
	sub_8216C190(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82173978
	ctx.lr = 0x821CED90;
	sub_82173978(ctx, base);
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

__attribute__((alias("__imp__sub_821CEDA8"))) PPC_WEAK_FUNC(sub_821CEDA8);
PPC_FUNC_IMPL(__imp__sub_821CEDA8) {
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
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x821cedf4
	if (ctx.cr6.eq) goto loc_821CEDF4;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// beq cr6,0x821ceddc
	if (ctx.cr6.eq) goto loc_821CEDDC;
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// beq cr6,0x821cedf4
	if (ctx.cr6.eq) goto loc_821CEDF4;
loc_821CEDDC:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,14920
	ctx.r9.s64 = ctx.r11.s64 + 14920;
	// stw r10,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r10.u32);
	// stw r9,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r9.u32);
	// b 0x821cee24
	goto loc_821CEE24;
loc_821CEDF4:
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// bne cr6,0x821ceddc
	if (!ctx.cr6.eq) goto loc_821CEDDC;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
	// bl 0x82188d08
	ctx.lr = 0x821CEE0C;
	sub_82188D08(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x821ceddc
	if (ctx.cr6.lt) goto loc_821CEDDC;
	// lwz r11,164(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cee24
	if (ctx.cr6.eq) goto loc_821CEE24;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_821CEE24:
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

__attribute__((alias("__imp__sub_821CEE3C"))) PPC_WEAK_FUNC(sub_821CEE3C);
PPC_FUNC_IMPL(__imp__sub_821CEE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CEE40"))) PPC_WEAK_FUNC(sub_821CEE40);
PPC_FUNC_IMPL(__imp__sub_821CEE40) {
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
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x821CEE60;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// bl 0x82188d98
	ctx.lr = 0x821CEE88;
	sub_82188D98(ctx, base);
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

__attribute__((alias("__imp__sub_821CEE9C"))) PPC_WEAK_FUNC(sub_821CEE9C);
PPC_FUNC_IMPL(__imp__sub_821CEE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CEEA0"))) PPC_WEAK_FUNC(sub_821CEEA0);
PPC_FUNC_IMPL(__imp__sub_821CEEA0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,1160
	ctx.r10.s64 = ctx.r11.s64 + 1160;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821ba410
	sub_821BA410(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CEEB0"))) PPC_WEAK_FUNC(sub_821CEEB0);
PPC_FUNC_IMPL(__imp__sub_821CEEB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821CEEB8;
	__savegprlr_24(ctx, base);
	// stwu r1,-2336(r1)
	ea = -2336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x821ba6f0
	ctx.lr = 0x821CEEC8;
	sub_821BA6F0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,184(r28)
	PPC_STORE_U32(ctx.r28.u32 + 184, ctx.r31.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,1160
	ctx.r9.s64 = ctx.r11.s64 + 1160;
	// stw r10,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r10.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// addi r24,r28,88
	ctx.r24.s64 = ctx.r28.s64 + 88;
	// addi r29,r11,-10968
	ctx.r29.s64 = ctx.r11.s64 + -10968;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r4,r29,-708
	ctx.r4.s64 = ctx.r29.s64 + -708;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82060368
	ctx.lr = 0x821CEEFC;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r31.u32);
	// addi r4,r29,-692
	ctx.r4.s64 = ctx.r29.s64 + -692;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stb r31,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, ctx.r31.u8);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82060368
	ctx.lr = 0x821CEF20;
	sub_82060368(ctx, base);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stw r31,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r31.u32);
	// addi r4,r29,-684
	ctx.r4.s64 = ctx.r29.s64 + -684;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r1,260
	ctx.r3.s64 = ctx.r1.s64 + 260;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
	// stw r30,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r30.u32);
	// stw r31,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r31.u32);
	// stb r31,264(r1)
	PPC_STORE_U8(ctx.r1.u32 + 264, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CEF48;
	sub_82060368(ctx, base);
	// addi r7,r1,292
	ctx.r7.s64 = ctx.r1.s64 + 292;
	// li r25,1
	ctx.r25.s64 = 1;
	// addi r4,r29,-676
	ctx.r4.s64 = ctx.r29.s64 + -676;
	// stw r25,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r25.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r1,296
	ctx.r3.s64 = ctx.r1.s64 + 296;
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r31.u32);
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r30.u32);
	// stw r31,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r31.u32);
	// stb r31,300(r1)
	PPC_STORE_U8(ctx.r1.u32 + 300, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CEF74;
	sub_82060368(ctx, base);
	// addi r6,r1,328
	ctx.r6.s64 = ctx.r1.s64 + 328;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r4,r29,-668
	ctx.r4.s64 = ctx.r29.s64 + -668;
	// stw r26,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r26.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r1,332
	ctx.r3.s64 = ctx.r1.s64 + 332;
	// stw r31,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r31.u32);
	// stw r30,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r30.u32);
	// stw r31,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r31.u32);
	// stb r31,336(r1)
	PPC_STORE_U8(ctx.r1.u32 + 336, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CEFA0;
	sub_82060368(ctx, base);
	// addi r11,r1,364
	ctx.r11.s64 = ctx.r1.s64 + 364;
	// li r27,3
	ctx.r27.s64 = 3;
	// stw r31,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r31.u32);
	// stw r30,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r30.u32);
	// addi r4,r29,-660
	ctx.r4.s64 = ctx.r29.s64 + -660;
	// stw r27,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r27.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r31,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r31.u32);
	// addi r3,r1,372
	ctx.r3.s64 = ctx.r1.s64 + 372;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stb r31,376(r1)
	PPC_STORE_U8(ctx.r1.u32 + 376, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CEFD0;
	sub_82060368(ctx, base);
	// stw r30,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r30.u32);
	// stw r31,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r31.u32);
	// addi r4,r29,-636
	ctx.r4.s64 = ctx.r29.s64 + -636;
	// stb r31,404(r1)
	PPC_STORE_U8(ctx.r1.u32 + 404, ctx.r31.u8);
	// stw r30,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r30.u32);
	// stw r31,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r31.u32);
	// stb r31,432(r1)
	PPC_STORE_U8(ctx.r1.u32 + 432, ctx.r31.u8);
	// stw r25,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r25.u32);
	// stw r30,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r30.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// stw r31,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r31.u32);
	// addi r3,r1,460
	ctx.r3.s64 = ctx.r1.s64 + 460;
	// stb r31,464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 464, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF008;
	sub_82060368(ctx, base);
	// stw r30,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r30.u32);
	// stw r31,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r31.u32);
	// addi r4,r29,-612
	ctx.r4.s64 = ctx.r29.s64 + -612;
	// stb r31,492(r1)
	PPC_STORE_U8(ctx.r1.u32 + 492, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,488
	ctx.r3.s64 = ctx.r1.s64 + 488;
	// bl 0x82060368
	ctx.lr = 0x821CF024;
	sub_82060368(ctx, base);
	// stw r30,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, ctx.r30.u32);
	// stw r31,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r31.u32);
	// addi r4,r29,-588
	ctx.r4.s64 = ctx.r29.s64 + -588;
	// stb r31,520(r1)
	PPC_STORE_U8(ctx.r1.u32 + 520, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r26,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r26.u32);
	// addi r3,r1,548
	ctx.r3.s64 = ctx.r1.s64 + 548;
	// stw r30,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r30.u32);
	// stw r31,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r31.u32);
	// stb r31,552(r1)
	PPC_STORE_U8(ctx.r1.u32 + 552, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF050;
	sub_82060368(ctx, base);
	// stw r30,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r30.u32);
	// stw r31,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r31.u32);
	// addi r4,r29,-564
	ctx.r4.s64 = ctx.r29.s64 + -564;
	// stb r31,580(r1)
	PPC_STORE_U8(ctx.r1.u32 + 580, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r30,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r30.u32);
	// addi r3,r1,636
	ctx.r3.s64 = ctx.r1.s64 + 636;
	// stw r31,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r31.u32);
	// stb r31,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, ctx.r31.u8);
	// stw r27,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r27.u32);
	// stw r30,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, ctx.r30.u32);
	// stw r31,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r31.u32);
	// stb r31,640(r1)
	PPC_STORE_U8(ctx.r1.u32 + 640, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF088;
	sub_82060368(ctx, base);
	// stw r30,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r30.u32);
	// stw r31,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r31.u32);
	// addi r4,r29,-540
	ctx.r4.s64 = ctx.r29.s64 + -540;
	// stb r31,668(r1)
	PPC_STORE_U8(ctx.r1.u32 + 668, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,664
	ctx.r3.s64 = ctx.r1.s64 + 664;
	// bl 0x82060368
	ctx.lr = 0x821CF0A4;
	sub_82060368(ctx, base);
	// stw r30,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r30.u32);
	// stw r31,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r31.u32);
	// addi r4,r29,-516
	ctx.r4.s64 = ctx.r29.s64 + -516;
	// stb r31,696(r1)
	PPC_STORE_U8(ctx.r1.u32 + 696, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r31.u32);
	// addi r3,r1,728
	ctx.r3.s64 = ctx.r1.s64 + 728;
	// stw r31,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r31.u32);
	// stw r30,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r30.u32);
	// stw r31,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r31.u32);
	// stb r31,732(r1)
	PPC_STORE_U8(ctx.r1.u32 + 732, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF0D4;
	sub_82060368(ctx, base);
	// stw r30,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r30.u32);
	// stw r31,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r31.u32);
	// addi r4,r29,-500
	ctx.r4.s64 = ctx.r29.s64 + -500;
	// stb r31,760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 760, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,756
	ctx.r3.s64 = ctx.r1.s64 + 756;
	// bl 0x82060368
	ctx.lr = 0x821CF0F0;
	sub_82060368(ctx, base);
	// stw r30,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r30.u32);
	// stw r31,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r31.u32);
	// addi r4,r29,-476
	ctx.r4.s64 = ctx.r29.s64 + -476;
	// stb r31,788(r1)
	PPC_STORE_U8(ctx.r1.u32 + 788, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r30.u32);
	// addi r3,r1,876
	ctx.r3.s64 = ctx.r1.s64 + 876;
	// stw r31,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r31.u32);
	// stb r31,816(r1)
	PPC_STORE_U8(ctx.r1.u32 + 816, ctx.r31.u8);
	// stw r30,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r30.u32);
	// stw r31,860(r1)
	PPC_STORE_U32(ctx.r1.u32 + 860, ctx.r31.u32);
	// stb r31,844(r1)
	PPC_STORE_U8(ctx.r1.u32 + 844, ctx.r31.u8);
	// stw r25,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r25.u32);
	// stw r31,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r31.u32);
	// stw r30,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, ctx.r30.u32);
	// stw r31,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r31.u32);
	// stb r31,880(r1)
	PPC_STORE_U8(ctx.r1.u32 + 880, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF138;
	sub_82060368(ctx, base);
	// stw r30,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r30.u32);
	// stw r31,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, ctx.r31.u32);
	// addi r4,r29,-460
	ctx.r4.s64 = ctx.r29.s64 + -460;
	// stb r31,908(r1)
	PPC_STORE_U8(ctx.r1.u32 + 908, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,904
	ctx.r3.s64 = ctx.r1.s64 + 904;
	// bl 0x82060368
	ctx.lr = 0x821CF154;
	sub_82060368(ctx, base);
	// stw r30,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, ctx.r30.u32);
	// stw r31,952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 952, ctx.r31.u32);
	// addi r4,r29,-436
	ctx.r4.s64 = ctx.r29.s64 + -436;
	// stb r31,936(r1)
	PPC_STORE_U8(ctx.r1.u32 + 936, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r30.u32);
	// addi r3,r1,1024
	ctx.r3.s64 = ctx.r1.s64 + 1024;
	// stw r31,980(r1)
	PPC_STORE_U32(ctx.r1.u32 + 980, ctx.r31.u32);
	// stb r31,964(r1)
	PPC_STORE_U8(ctx.r1.u32 + 964, ctx.r31.u8);
	// stw r30,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, ctx.r30.u32);
	// stw r31,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, ctx.r31.u32);
	// stb r31,992(r1)
	PPC_STORE_U8(ctx.r1.u32 + 992, ctx.r31.u8);
	// stw r26,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r26.u32);
	// stw r31,1020(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1020, ctx.r31.u32);
	// stw r30,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, ctx.r30.u32);
	// stw r31,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r31.u32);
	// stb r31,1028(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1028, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF19C;
	sub_82060368(ctx, base);
	// stw r30,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r30.u32);
	// stw r31,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r31.u32);
	// addi r4,r29,-420
	ctx.r4.s64 = ctx.r29.s64 + -420;
	// stb r31,1056(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1056, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1052
	ctx.r3.s64 = ctx.r1.s64 + 1052;
	// bl 0x82060368
	ctx.lr = 0x821CF1B8;
	sub_82060368(ctx, base);
	// stw r30,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r30.u32);
	// stw r31,1100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1100, ctx.r31.u32);
	// addi r4,r29,-396
	ctx.r4.s64 = ctx.r29.s64 + -396;
	// stb r31,1084(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1084, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r30.u32);
	// addi r3,r1,1172
	ctx.r3.s64 = ctx.r1.s64 + 1172;
	// stw r31,1128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1128, ctx.r31.u32);
	// stb r31,1112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1112, ctx.r31.u8);
	// stw r30,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r30.u32);
	// stw r31,1156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1156, ctx.r31.u32);
	// stb r31,1140(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1140, ctx.r31.u8);
	// stw r27,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r27.u32);
	// stw r31,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r31.u32);
	// stw r30,1196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1196, ctx.r30.u32);
	// stw r31,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r31.u32);
	// stb r31,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF200;
	sub_82060368(ctx, base);
	// stw r30,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, ctx.r30.u32);
	// stw r31,1220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1220, ctx.r31.u32);
	// addi r4,r29,-380
	ctx.r4.s64 = ctx.r29.s64 + -380;
	// stb r31,1204(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1204, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1200
	ctx.r3.s64 = ctx.r1.s64 + 1200;
	// bl 0x82060368
	ctx.lr = 0x821CF21C;
	sub_82060368(ctx, base);
	// stw r30,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, ctx.r30.u32);
	// stw r31,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, ctx.r31.u32);
	// addi r4,r29,-356
	ctx.r4.s64 = ctx.r29.s64 + -356;
	// stb r31,1232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1232, ctx.r31.u8);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r30,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,1276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1276, ctx.r31.u32);
	// stb r31,1260(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1260, ctx.r31.u8);
	// stw r30,1308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1308, ctx.r30.u32);
	// stw r31,1304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1304, ctx.r31.u32);
	// stb r31,1288(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1288, ctx.r31.u8);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF25C;
	sub_82060368(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// addi r4,r29,-348
	ctx.r4.s64 = ctx.r29.s64 + -348;
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// stb r31,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF284;
	sub_82060368(ctx, base);
	// addi r9,r1,148
	ctx.r9.s64 = ctx.r1.s64 + 148;
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// addi r4,r29,-340
	ctx.r4.s64 = ctx.r29.s64 + -340;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r31.u32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF2AC;
	sub_82060368(ctx, base);
	// addi r8,r1,184
	ctx.r8.s64 = ctx.r1.s64 + 184;
	// stw r26,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r26.u32);
	// addi r4,r29,-332
	ctx.r4.s64 = ctx.r29.s64 + -332;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r1,188
	ctx.r3.s64 = ctx.r1.s64 + 188;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
	// stw r30,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r30.u32);
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF2D4;
	sub_82060368(ctx, base);
	// addi r7,r1,220
	ctx.r7.s64 = ctx.r1.s64 + 220;
	// stw r27,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r27.u32);
	// addi r4,r29,-324
	ctx.r4.s64 = ctx.r29.s64 + -324;
	// stw r31,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r30,1340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1340, ctx.r30.u32);
	// addi r3,r1,1316
	ctx.r3.s64 = ctx.r1.s64 + 1316;
	// stw r31,1336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1336, ctx.r31.u32);
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r31.u32);
	// stb r31,1320(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1320, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF300;
	sub_82060368(ctx, base);
	// stw r30,1368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1368, ctx.r30.u32);
	// stw r31,1364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1364, ctx.r31.u32);
	// addi r4,r29,-300
	ctx.r4.s64 = ctx.r29.s64 + -300;
	// stb r31,1348(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1348, ctx.r31.u8);
	// li r5,22
	ctx.r5.s64 = 22;
	// stw r30,1396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1396, ctx.r30.u32);
	// addi r3,r1,1404
	ctx.r3.s64 = ctx.r1.s64 + 1404;
	// stw r31,1392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1392, ctx.r31.u32);
	// stb r31,1376(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1376, ctx.r31.u8);
	// stw r25,1400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1400, ctx.r25.u32);
	// stw r30,1428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1428, ctx.r30.u32);
	// stw r31,1424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1424, ctx.r31.u32);
	// stb r31,1408(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1408, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CF338;
	sub_82060368(ctx, base);
	// stw r30,1456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1456, ctx.r30.u32);
	// stw r31,1452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1452, ctx.r31.u32);
	// addi r4,r29,-276
	ctx.r4.s64 = ctx.r29.s64 + -276;
	// stb r31,1436(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1436, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1432
	ctx.r3.s64 = ctx.r1.s64 + 1432;
	// bl 0x82060368
	ctx.lr = 0x821CF354;
	sub_82060368(ctx, base);
	// stw r30,1484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1484, ctx.r30.u32);
	// stw r31,1480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1480, ctx.r31.u32);
	// addi r4,r29,-252
	ctx.r4.s64 = ctx.r29.s64 + -252;
	// stb r31,1464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1464, ctx.r31.u8);
	// addi r3,r1,1492
	ctx.r3.s64 = ctx.r1.s64 + 1492;
	// stw r26,1488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1488, ctx.r26.u32);
	// bl 0x82060190
	ctx.lr = 0x821CF370;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1520
	ctx.r3.s64 = ctx.r1.s64 + 1520;
	// bl 0x820602f0
	ctx.lr = 0x821CF380;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1548
	ctx.r3.s64 = ctx.r1.s64 + 1548;
	// bl 0x820602f0
	ctx.lr = 0x821CF390;
	sub_820602F0(ctx, base);
	// stw r27,1576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1576, ctx.r27.u32);
	// addi r4,r29,-228
	ctx.r4.s64 = ctx.r29.s64 + -228;
	// addi r3,r1,1580
	ctx.r3.s64 = ctx.r1.s64 + 1580;
	// bl 0x82060190
	ctx.lr = 0x821CF3A0;
	sub_82060190(ctx, base);
	// addi r4,r29,-204
	ctx.r4.s64 = ctx.r29.s64 + -204;
	// addi r3,r1,1608
	ctx.r3.s64 = ctx.r1.s64 + 1608;
	// bl 0x82060190
	ctx.lr = 0x821CF3AC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1636
	ctx.r3.s64 = ctx.r1.s64 + 1636;
	// bl 0x820602f0
	ctx.lr = 0x821CF3BC;
	sub_820602F0(ctx, base);
	// stw r31,1664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1664, ctx.r31.u32);
	// stw r31,1668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1668, ctx.r31.u32);
	// addi r4,r29,-180
	ctx.r4.s64 = ctx.r29.s64 + -180;
	// addi r3,r1,1672
	ctx.r3.s64 = ctx.r1.s64 + 1672;
	// bl 0x82060190
	ctx.lr = 0x821CF3D0;
	sub_82060190(ctx, base);
	// addi r4,r29,-164
	ctx.r4.s64 = ctx.r29.s64 + -164;
	// addi r3,r1,1700
	ctx.r3.s64 = ctx.r1.s64 + 1700;
	// bl 0x82060190
	ctx.lr = 0x821CF3DC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1728
	ctx.r3.s64 = ctx.r1.s64 + 1728;
	// bl 0x820602f0
	ctx.lr = 0x821CF3EC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1756
	ctx.r3.s64 = ctx.r1.s64 + 1756;
	// bl 0x820602f0
	ctx.lr = 0x821CF3FC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1784
	ctx.r3.s64 = ctx.r1.s64 + 1784;
	// bl 0x820602f0
	ctx.lr = 0x821CF40C;
	sub_820602F0(ctx, base);
	// stw r25,1812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1812, ctx.r25.u32);
	// stw r31,1816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1816, ctx.r31.u32);
	// addi r4,r29,-140
	ctx.r4.s64 = ctx.r29.s64 + -140;
	// addi r3,r1,1820
	ctx.r3.s64 = ctx.r1.s64 + 1820;
	// bl 0x82060190
	ctx.lr = 0x821CF420;
	sub_82060190(ctx, base);
	// addi r4,r29,-124
	ctx.r4.s64 = ctx.r29.s64 + -124;
	// addi r3,r1,1848
	ctx.r3.s64 = ctx.r1.s64 + 1848;
	// bl 0x82060190
	ctx.lr = 0x821CF42C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1876
	ctx.r3.s64 = ctx.r1.s64 + 1876;
	// bl 0x820602f0
	ctx.lr = 0x821CF43C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1904
	ctx.r3.s64 = ctx.r1.s64 + 1904;
	// bl 0x820602f0
	ctx.lr = 0x821CF44C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1932
	ctx.r3.s64 = ctx.r1.s64 + 1932;
	// bl 0x820602f0
	ctx.lr = 0x821CF45C;
	sub_820602F0(ctx, base);
	// stw r26,1960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1960, ctx.r26.u32);
	// stw r31,1964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1964, ctx.r31.u32);
	// addi r4,r29,-100
	ctx.r4.s64 = ctx.r29.s64 + -100;
	// addi r3,r1,1968
	ctx.r3.s64 = ctx.r1.s64 + 1968;
	// bl 0x82060190
	ctx.lr = 0x821CF470;
	sub_82060190(ctx, base);
	// addi r4,r29,-84
	ctx.r4.s64 = ctx.r29.s64 + -84;
	// addi r3,r1,1996
	ctx.r3.s64 = ctx.r1.s64 + 1996;
	// bl 0x82060190
	ctx.lr = 0x821CF47C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,2024
	ctx.r3.s64 = ctx.r1.s64 + 2024;
	// bl 0x820602f0
	ctx.lr = 0x821CF48C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,2052
	ctx.r3.s64 = ctx.r1.s64 + 2052;
	// bl 0x820602f0
	ctx.lr = 0x821CF49C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x820602f0
	ctx.lr = 0x821CF4AC;
	sub_820602F0(ctx, base);
	// stw r27,2108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2108, ctx.r27.u32);
	// stw r31,2112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2112, ctx.r31.u32);
	// addi r4,r29,-60
	ctx.r4.s64 = ctx.r29.s64 + -60;
	// addi r3,r1,2116
	ctx.r3.s64 = ctx.r1.s64 + 2116;
	// bl 0x82060190
	ctx.lr = 0x821CF4C0;
	sub_82060190(ctx, base);
	// addi r4,r29,-44
	ctx.r4.s64 = ctx.r29.s64 + -44;
	// addi r3,r1,2144
	ctx.r3.s64 = ctx.r1.s64 + 2144;
	// bl 0x82060190
	ctx.lr = 0x821CF4CC;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,2172
	ctx.r3.s64 = ctx.r1.s64 + 2172;
	// bl 0x820602f0
	ctx.lr = 0x821CF4DC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,2200
	ctx.r3.s64 = ctx.r1.s64 + 2200;
	// bl 0x820602f0
	ctx.lr = 0x821CF4EC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,2228
	ctx.r3.s64 = ctx.r1.s64 + 2228;
	// bl 0x820602f0
	ctx.lr = 0x821CF4FC;
	sub_820602F0(ctx, base);
	// lwz r6,184(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r11,124(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 124);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x821cf534
	if (ctx.cr6.lt) goto loc_821CF534;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x821cf534
	if (ctx.cr6.gt) goto loc_821CF534;
	// addi r4,r29,-20
	ctx.r4.s64 = ctx.r29.s64 + -20;
	// li r5,17
	ctx.r5.s64 = 17;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82060368
	ctx.lr = 0x821CF524;
	sub_82060368(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r31,r1,1312
	ctx.r31.s64 = ctx.r1.s64 + 1312;
	// addi r30,r1,1664
	ctx.r30.s64 = ctx.r1.s64 + 1664;
	// b 0x821cf550
	goto loc_821CF550;
loc_821CF534:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82060368
	ctx.lr = 0x821CF544;
	sub_82060368(ctx, base);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r31,r1,368
	ctx.r31.s64 = ctx.r1.s64 + 368;
	// addi r30,r1,720
	ctx.r30.s64 = ctx.r1.s64 + 720;
loc_821CF550:
	// addic. r3,r28,132
	ctx.xer.ca = ctx.r28.u32 > 4294967163;
	ctx.r3.s64 = ctx.r28.s64 + 132;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821cf560
	if (ctx.cr0.eq) goto loc_821CF560;
	// li r5,4
	ctx.r5.s64 = 4;
	// bl 0x821ba6a0
	ctx.lr = 0x821CF560;
	sub_821BA6A0(ctx, base);
loc_821CF560:
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x821bcd20
	ctx.lr = 0x821CF570;
	sub_821BCD20(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x821CF580;
	sub_821BCC50(ctx, base);
	// lwz r11,184(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x821cf5a0
	if (!ctx.cr6.eq) goto loc_821CF5A0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821CF5A0;
	sub_821BA280(ctx, base);
loc_821CF5A0:
	// lwz r11,184(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// bne cr6,0x821cf5c0
	if (!ctx.cr6.eq) goto loc_821CF5C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821CF5C0;
	sub_821BA280(ctx, base);
loc_821CF5C0:
	// lwz r3,184(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CF5D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,184(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,68(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821CF5F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x821cf608
	if (ctx.cr6.eq) goto loc_821CF608;
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x821cf618
	if (ctx.cr6.eq) goto loc_821CF618;
loc_821CF608:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821CF618;
	sub_821BA280(ctx, base);
loc_821CF618:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x821cf634
	if (ctx.cr6.eq) goto loc_821CF634;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821CF634;
	sub_821BA280(ctx, base);
loc_821CF634:
	// lwz r10,184(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r11,140(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x821cf690
	if (ctx.cr6.lt) goto loc_821CF690;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x821cf690
	if (ctx.cr6.gt) goto loc_821CF690;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r11,176(r28)
	PPC_STORE_U32(ctx.r28.u32 + 176, ctx.r11.u32);
	// slw r8,r25,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r25.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r7,144(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x821cf690
	if (ctx.cr6.eq) goto loc_821CF690;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r10,-31352(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// lwz r10,36(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x821cf690
	if (ctx.cr6.eq) goto loc_821CF690;
	// stw r10,180(r28)
	PPC_STORE_U32(ctx.r28.u32 + 180, ctx.r10.u32);
loc_821CF690:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,19656
	ctx.r6.s64 = ctx.r11.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,1664
	ctx.r3.s64 = ctx.r1.s64 + 1664;
	// bl 0x82060818
	ctx.lr = 0x821CF6A8;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r10,19288
	ctx.r6.s64 = ctx.r10.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,1312
	ctx.r3.s64 = ctx.r1.s64 + 1312;
	// bl 0x82060818
	ctx.lr = 0x821CF6C0;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r9,24552
	ctx.r6.s64 = ctx.r9.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x821CF6D8;
	sub_82060818(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r8,19656
	ctx.r6.s64 = ctx.r8.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,720
	ctx.r3.s64 = ctx.r1.s64 + 720;
	// bl 0x82060818
	ctx.lr = 0x821CF6F0;
	sub_82060818(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r7,19288
	ctx.r6.s64 = ctx.r7.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x82060818
	ctx.lr = 0x821CF708;
	sub_82060818(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r6,24552
	ctx.r6.s64 = ctx.r6.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82060818
	ctx.lr = 0x821CF720;
	sub_82060818(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,2336
	ctx.r1.s64 = ctx.r1.s64 + 2336;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CF72C"))) PPC_WEAK_FUNC(sub_821CF72C);
PPC_FUNC_IMPL(__imp__sub_821CF72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CF730"))) PPC_WEAK_FUNC(sub_821CF730);
PPC_FUNC_IMPL(__imp__sub_821CF730) {
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
	// bl 0x821ba9a0
	ctx.lr = 0x821CF740;
	sub_821BA9A0(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CF76C"))) PPC_WEAK_FUNC(sub_821CF76C);
PPC_FUNC_IMPL(__imp__sub_821CF76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CF770"))) PPC_WEAK_FUNC(sub_821CF770);
PPC_FUNC_IMPL(__imp__sub_821CF770) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821CF778;
	__savegprlr_24(ctx, base);
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r26,-1
	ctx.r26.s64 = -1;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x821cf9c0
	if (ctx.cr6.eq) goto loc_821CF9C0;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// beq cr6,0x821cf8fc
	if (ctx.cr6.eq) goto loc_821CF8FC;
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// beq cr6,0x821cf7ac
	if (ctx.cr6.eq) goto loc_821CF7AC;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// b 0x821cfba4
	goto loc_821CFBA4;
loc_821CF7AC:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cf7c4
	if (ctx.cr6.eq) goto loc_821CF7C4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821CF7C4;
	sub_821BC718(ctx, base);
loc_821CF7C4:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821CF7CC;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r28,r11,-10812
	ctx.r28.s64 = ctx.r11.s64 + -10812;
	// beq cr6,0x821cf804
	if (ctx.cr6.eq) goto loc_821CF804;
	// addi r4,r28,-40
	ctx.r4.s64 = ctx.r28.s64 + -40;
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// bl 0x82060190
	ctx.lr = 0x821CF7F0;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821CF800;
	sub_821BAE98(ctx, base);
	// b 0x821cf808
	goto loc_821CF808;
loc_821CF804:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821CF808:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// lwz r9,184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r11,124(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x821cf89c
	if (ctx.cr6.lt) goto loc_821CF89C;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x821cf89c
	if (ctx.cr6.gt) goto loc_821CF89C;
	// li r3,116
	ctx.r3.s64 = 116;
	// bl 0x82079fd8
	ctx.lr = 0x821CF840;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cfb84
	if (ctx.cr6.eq) goto loc_821CFB84;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r25,176(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-21302
	ctx.r11.s64 = ctx.r11.s64 + -21302;
	// addi r4,r11,-3
	ctx.r4.s64 = ctx.r11.s64 + -3;
	// bl 0x82060190
	ctx.lr = 0x821CF864;
	sub_82060190(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r4,r28,-32
	ctx.r4.s64 = ctx.r28.s64 + -32;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82060190
	ctx.lr = 0x821CF874;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CF884;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// bl 0x821bd8b8
	ctx.lr = 0x821CF898;
	sub_821BD8B8(ctx, base);
	// b 0x821cfb88
	goto loc_821CFB88;
loc_821CF89C:
	// li r3,116
	ctx.r3.s64 = 116;
	// bl 0x82079fd8
	ctx.lr = 0x821CF8A4;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cfb84
	if (ctx.cr6.eq) goto loc_821CFB84;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r25,176(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// addi r4,r11,-21302
	ctx.r4.s64 = ctx.r11.s64 + -21302;
	// bl 0x82060190
	ctx.lr = 0x821CF8C4;
	sub_82060190(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82060190
	ctx.lr = 0x821CF8D4;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CF8E4;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// bl 0x821bd8b8
	ctx.lr = 0x821CF8F8;
	sub_821BD8B8(ctx, base);
	// b 0x821cfb88
	goto loc_821CFB88;
loc_821CF8FC:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cf914
	if (ctx.cr6.eq) goto loc_821CF914;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821CF914;
	sub_821BC718(ctx, base);
loc_821CF914:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821CF91C;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cf958
	if (ctx.cr6.eq) goto loc_821CF958;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// addi r11,r11,-10812
	ctx.r11.s64 = ctx.r11.s64 + -10812;
	// addi r4,r11,-140
	ctx.r4.s64 = ctx.r11.s64 + -140;
	// bl 0x82060190
	ctx.lr = 0x821CF940;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821CF950;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cf95c
	goto loc_821CF95C;
loc_821CF958:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_821CF95C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,188
	ctx.r3.s64 = 188;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CF97C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cf998
	if (ctx.cr6.eq) goto loc_821CF998;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r6,176(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x821d2d40
	ctx.lr = 0x821CF994;
	sub_821D2D40(ctx, base);
	// b 0x821cf99c
	goto loc_821CF99C;
loc_821CF998:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821CF99C:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// b 0x821cfba8
	goto loc_821CFBA8;
loc_821CF9C0:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cf9d8
	if (ctx.cr6.eq) goto loc_821CF9D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821CF9D8;
	sub_821BC718(ctx, base);
loc_821CF9D8:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821CF9E0;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r29,r11,-10812
	ctx.r29.s64 = ctx.r11.s64 + -10812;
	// beq cr6,0x821cfa18
	if (ctx.cr6.eq) goto loc_821CFA18;
	// addi r4,r29,-132
	ctx.r4.s64 = ctx.r29.s64 + -132;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821CFA04;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821CFA14;
	sub_821BAE98(ctx, base);
	// b 0x821cfa1c
	goto loc_821CFA1C;
loc_821CFA18:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821CFA1C:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// li r3,116
	ctx.r3.s64 = 116;
	// lwz r11,184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821cfb24
	if (ctx.cr6.eq) goto loc_821CFB24;
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// addi r9,r10,32
	ctx.r9.s64 = ctx.r10.s64 + 32;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt cr6,0x821cfac4
	if (ctx.cr6.lt) goto loc_821CFAC4;
	// bl 0x82079fd8
	ctx.lr = 0x821CFA68;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cfb84
	if (ctx.cr6.eq) goto loc_821CFB84;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r25,176(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-21302
	ctx.r11.s64 = ctx.r11.s64 + -21302;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x82060190
	ctx.lr = 0x821CFA8C;
	sub_82060190(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r4,r29,-124
	ctx.r4.s64 = ctx.r29.s64 + -124;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82060190
	ctx.lr = 0x821CFA9C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CFAAC;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// bl 0x821bd8b8
	ctx.lr = 0x821CFAC0;
	sub_821BD8B8(ctx, base);
	// b 0x821cfb88
	goto loc_821CFB88;
loc_821CFAC4:
	// bl 0x82079fd8
	ctx.lr = 0x821CFAC8;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cfb84
	if (ctx.cr6.eq) goto loc_821CFB84;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r25,176(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// addi r11,r11,-21302
	ctx.r11.s64 = ctx.r11.s64 + -21302;
	// addi r4,r11,-7
	ctx.r4.s64 = ctx.r11.s64 + -7;
	// bl 0x82060190
	ctx.lr = 0x821CFAEC;
	sub_82060190(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r4,r29,-92
	ctx.r4.s64 = ctx.r29.s64 + -92;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x82060190
	ctx.lr = 0x821CFAFC;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CFB0C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// bl 0x821bd8b8
	ctx.lr = 0x821CFB20;
	sub_821BD8B8(ctx, base);
	// b 0x821cfb88
	goto loc_821CFB88;
loc_821CFB24:
	// bl 0x82079fd8
	ctx.lr = 0x821CFB28;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cfb84
	if (ctx.cr6.eq) goto loc_821CFB84;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r25,176(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// addi r3,r1,496
	ctx.r3.s64 = ctx.r1.s64 + 496;
	// addi r11,r11,-21302
	ctx.r11.s64 = ctx.r11.s64 + -21302;
	// addi r4,r11,-4
	ctx.r4.s64 = ctx.r11.s64 + -4;
	// bl 0x82060190
	ctx.lr = 0x821CFB4C;
	sub_82060190(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r4,r29,-60
	ctx.r4.s64 = ctx.r29.s64 + -60;
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// bl 0x82060190
	ctx.lr = 0x821CFB5C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CFB6C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// bl 0x821bd8b8
	ctx.lr = 0x821CFB80;
	sub_821BD8B8(ctx, base);
	// b 0x821cfb88
	goto loc_821CFB88;
loc_821CFB84:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821CFB88:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// addi r10,r11,14936
	ctx.r10.s64 = ctx.r11.s64 + 14936;
loc_821CFBA4:
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821CFBA8:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cfbb8
	if (ctx.cr6.eq) goto loc_821CFBB8;
	// stw r26,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
loc_821CFBB8:
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CFBC0"))) PPC_WEAK_FUNC(sub_821CFBC0);
PPC_FUNC_IMPL(__imp__sub_821CFBC0) {
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
	// bl 0x821bb3a8
	ctx.lr = 0x821CFBD0;
	sub_821BB3A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82188d98
	ctx.lr = 0x821CFBD8;
	sub_82188D98(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CFBE8"))) PPC_WEAK_FUNC(sub_821CFBE8);
PPC_FUNC_IMPL(__imp__sub_821CFBE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// ld r12,-4096(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-5904(r1)
	ea = -5904 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r31.u64);
	// li r5,5760
	ctx.r5.s64 = 5760;
	// std r31,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r31.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r9,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r9.u8);
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, ctx.r11.u8);
	// stb r11,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r11.u8);
	// stb r8,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r8.u8);
	// stb r31,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r31.u8);
	// stb r31,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r31.u8);
	// stb r31,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r31.u8);
	// stb r31,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, ctx.r31.u8);
	// bl 0x8207da20
	ctx.lr = 0x821CFC48;
	sub_8207DA20(ctx, base);
	// addi r7,r1,5856
	ctx.r7.s64 = ctx.r1.s64 + 5856;
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// std r31,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r31.u64);
	// std r31,8(r7)
	PPC_STORE_U64(ctx.r7.u32 + 8, ctx.r31.u64);
	// std r31,16(r7)
	PPC_STORE_U64(ctx.r7.u32 + 16, ctx.r31.u64);
	// std r31,24(r7)
	PPC_STORE_U64(ctx.r7.u32 + 24, ctx.r31.u64);
	// lwz r10,-31348(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31348);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_821CFC70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x821cfc90
	if (!ctx.cr0.eq) goto loc_821CFC90;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x821cfc70
	if (!ctx.cr6.eq) goto loc_821CFC70;
loc_821CFC90:
	// cntlzw r11,r9
	ctx.r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,5904
	ctx.r1.s64 = ctx.r1.s64 + 5904;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CFCAC"))) PPC_WEAK_FUNC(sub_821CFCAC);
PPC_FUNC_IMPL(__imp__sub_821CFCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CFCB0"))) PPC_WEAK_FUNC(sub_821CFCB0);
PPC_FUNC_IMPL(__imp__sub_821CFCB0) {
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
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r10,204(r11)
	PPC_STORE_U8(ctx.r11.u32 + 204, ctx.r10.u8);
	// bl 0x821cfbe8
	ctx.lr = 0x821CFCD4;
	sub_821CFBE8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821cfcec
	if (!ctx.cr6.eq) goto loc_821CFCEC;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,204(r11)
	PPC_STORE_U8(ctx.r11.u32 + 204, ctx.r10.u8);
loc_821CFCEC:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r10,r11,14920
	ctx.r10.s64 = ctx.r11.s64 + 14920;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821CFD0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821CFD20"))) PPC_WEAK_FUNC(sub_821CFD20);
PPC_FUNC_IMPL(__imp__sub_821CFD20) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,1016
	ctx.r10.s64 = ctx.r11.s64 + 1016;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821ba410
	sub_821BA410(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CFD30"))) PPC_WEAK_FUNC(sub_821CFD30);
PPC_FUNC_IMPL(__imp__sub_821CFD30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821CFD38;
	__savegprlr_24(ctx, base);
	// stwu r1,-1600(r1)
	ea = -1600 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x821ba6f0
	ctx.lr = 0x821CFD4C;
	sub_821BA6F0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r30,188(r28)
	PPC_STORE_U32(ctx.r28.u32 + 188, ctx.r30.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r31,184(r28)
	PPC_STORE_U32(ctx.r28.u32 + 184, ctx.r31.u32);
	// addi r9,r11,1016
	ctx.r9.s64 = ctx.r11.s64 + 1016;
	// stw r10,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r10.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r29,r8,-9328
	ctx.r29.s64 = ctx.r8.s64 + -9328;
	// addi r3,r28,88
	ctx.r3.s64 = ctx.r28.s64 + 88;
	// addi r4,r29,-516
	ctx.r4.s64 = ctx.r29.s64 + -516;
	// bl 0x82060368
	ctx.lr = 0x821CFD80;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r4,r29,-500
	ctx.r4.s64 = ctx.r29.s64 + -500;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821CFDA4;
	sub_82060368(ctx, base);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// addi r4,r29,-484
	ctx.r4.s64 = ctx.r29.s64 + -484;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// stb r31,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CFDC8;
	sub_82060368(ctx, base);
	// li r25,1
	ctx.r25.s64 = 1;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r4,r29,-596
	ctx.r4.s64 = ctx.r29.s64 + -596;
	// stw r25,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r25.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CFDF0;
	sub_82060368(ctx, base);
	// li r26,2
	ctx.r26.s64 = 2;
	// stw r31,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r31.u32);
	// addi r4,r29,-468
	ctx.r4.s64 = ctx.r29.s64 + -468;
	// stw r26,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r26.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r30,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r30.u32);
	// addi r3,r1,188
	ctx.r3.s64 = ctx.r1.s64 + 188;
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CFE18;
	sub_82060368(ctx, base);
	// li r27,3
	ctx.r27.s64 = 3;
	// stw r31,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r31.u32);
	// addi r4,r29,-456
	ctx.r4.s64 = ctx.r29.s64 + -456;
	// stw r27,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r27.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r31,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r31.u32);
	// addi r3,r1,580
	ctx.r3.s64 = ctx.r1.s64 + 580;
	// stw r30,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, ctx.r30.u32);
	// stw r31,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r31.u32);
	// stb r31,584(r1)
	PPC_STORE_U8(ctx.r1.u32 + 584, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CFE44;
	sub_82060368(ctx, base);
	// stw r30,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r30.u32);
	// stw r31,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r31.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stb r31,612(r1)
	PPC_STORE_U8(ctx.r1.u32 + 612, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r24,r7,-21263
	ctx.r24.s64 = ctx.r7.s64 + -21263;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// addi r4,r24,-38
	ctx.r4.s64 = ctx.r24.s64 + -38;
	// bl 0x82060368
	ctx.lr = 0x821CFE68;
	sub_82060368(ctx, base);
	// stw r30,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, ctx.r30.u32);
	// stw r31,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r31.u32);
	// addi r4,r29,-432
	ctx.r4.s64 = ctx.r29.s64 + -432;
	// stb r31,640(r1)
	PPC_STORE_U8(ctx.r1.u32 + 640, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,636
	ctx.r3.s64 = ctx.r1.s64 + 636;
	// bl 0x82060368
	ctx.lr = 0x821CFE84;
	sub_82060368(ctx, base);
	// stw r25,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r25.u32);
	// stw r30,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, ctx.r30.u32);
	// addi r4,r29,-400
	ctx.r4.s64 = ctx.r29.s64 + -400;
	// stw r31,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stb r31,672(r1)
	PPC_STORE_U8(ctx.r1.u32 + 672, ctx.r31.u8);
	// addi r3,r1,668
	ctx.r3.s64 = ctx.r1.s64 + 668;
	// bl 0x82060368
	ctx.lr = 0x821CFEA4;
	sub_82060368(ctx, base);
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r30.u32);
	// stw r31,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r31.u32);
	// addi r4,r29,-376
	ctx.r4.s64 = ctx.r29.s64 + -376;
	// stb r31,700(r1)
	PPC_STORE_U8(ctx.r1.u32 + 700, ctx.r31.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r1,696
	ctx.r3.s64 = ctx.r1.s64 + 696;
	// bl 0x82060368
	ctx.lr = 0x821CFEC0;
	sub_82060368(ctx, base);
	// stw r30,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r30.u32);
	// stw r31,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r31.u32);
	// addi r4,r29,-340
	ctx.r4.s64 = ctx.r29.s64 + -340;
	// stb r31,728(r1)
	PPC_STORE_U8(ctx.r1.u32 + 728, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,724
	ctx.r3.s64 = ctx.r1.s64 + 724;
	// bl 0x82060368
	ctx.lr = 0x821CFEDC;
	sub_82060368(ctx, base);
	// stw r26,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r26.u32);
	// stw r30,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r30.u32);
	// addi r4,r29,-308
	ctx.r4.s64 = ctx.r29.s64 + -308;
	// stw r31,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r31.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// stb r31,760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 760, ctx.r31.u8);
	// addi r3,r1,756
	ctx.r3.s64 = ctx.r1.s64 + 756;
	// bl 0x82060368
	ctx.lr = 0x821CFEFC;
	sub_82060368(ctx, base);
	// stw r30,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r30.u32);
	// stw r31,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r31.u32);
	// addi r4,r29,-284
	ctx.r4.s64 = ctx.r29.s64 + -284;
	// stb r31,788(r1)
	PPC_STORE_U8(ctx.r1.u32 + 788, ctx.r31.u8);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r30,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r30.u32);
	// addi r3,r1,844
	ctx.r3.s64 = ctx.r1.s64 + 844;
	// stw r31,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r31.u32);
	// stb r31,816(r1)
	PPC_STORE_U8(ctx.r1.u32 + 816, ctx.r31.u8);
	// stw r27,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r27.u32);
	// stw r30,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r30.u32);
	// stw r31,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r31.u32);
	// stb r31,848(r1)
	PPC_STORE_U8(ctx.r1.u32 + 848, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CFF34;
	sub_82060368(ctx, base);
	// stw r30,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r30.u32);
	// stw r31,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r31.u32);
	// addi r4,r29,-272
	ctx.r4.s64 = ctx.r29.s64 + -272;
	// stb r31,876(r1)
	PPC_STORE_U8(ctx.r1.u32 + 876, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, ctx.r30.u32);
	// addi r3,r1,228
	ctx.r3.s64 = ctx.r1.s64 + 228;
	// stw r31,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r31.u32);
	// stb r31,904(r1)
	PPC_STORE_U8(ctx.r1.u32 + 904, ctx.r31.u8);
	// stw r31,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r31.u32);
	// stw r30,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r30.u32);
	// stw r31,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r31.u32);
	// stb r31,232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 232, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821CFF6C;
	sub_82060368(ctx, base);
	// stw r30,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r30.u32);
	// stw r31,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r31.u32);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// stb r31,260(r1)
	PPC_STORE_U8(ctx.r1.u32 + 260, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82060368
	ctx.lr = 0x821CFF88;
	sub_82060368(ctx, base);
	// stw r30,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r30.u32);
	// stw r31,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r31.u32);
	// addi r4,r29,-240
	ctx.r4.s64 = ctx.r29.s64 + -240;
	// stb r31,288(r1)
	PPC_STORE_U8(ctx.r1.u32 + 288, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,284
	ctx.r3.s64 = ctx.r1.s64 + 284;
	// bl 0x82060368
	ctx.lr = 0x821CFFA4;
	sub_82060368(ctx, base);
	// stw r25,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r25.u32);
	// stw r30,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r30.u32);
	// addi r4,r29,-208
	ctx.r4.s64 = ctx.r29.s64 + -208;
	// stw r31,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r31.u32);
	// li r5,29
	ctx.r5.s64 = 29;
	// stb r31,320(r1)
	PPC_STORE_U8(ctx.r1.u32 + 320, ctx.r31.u8);
	// addi r3,r1,316
	ctx.r3.s64 = ctx.r1.s64 + 316;
	// bl 0x82060368
	ctx.lr = 0x821CFFC4;
	sub_82060368(ctx, base);
	// stw r30,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r30.u32);
	// addi r4,r29,-176
	ctx.r4.s64 = ctx.r29.s64 + -176;
	// stw r31,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r31.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stb r31,348(r1)
	PPC_STORE_U8(ctx.r1.u32 + 348, ctx.r31.u8);
	// addi r3,r1,344
	ctx.r3.s64 = ctx.r1.s64 + 344;
	// bl 0x82060368
	ctx.lr = 0x821CFFE0;
	sub_82060368(ctx, base);
	// stw r30,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r30.u32);
	// stw r31,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r31.u32);
	// addi r4,r29,-140
	ctx.r4.s64 = ctx.r29.s64 + -140;
	// stb r31,376(r1)
	PPC_STORE_U8(ctx.r1.u32 + 376, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,372
	ctx.r3.s64 = ctx.r1.s64 + 372;
	// bl 0x82060368
	ctx.lr = 0x821CFFFC;
	sub_82060368(ctx, base);
	// stw r26,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r26.u32);
	// stw r30,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r30.u32);
	// addi r4,r29,-108
	ctx.r4.s64 = ctx.r29.s64 + -108;
	// stw r31,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r31.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// stb r31,408(r1)
	PPC_STORE_U8(ctx.r1.u32 + 408, ctx.r31.u8);
	// addi r3,r1,404
	ctx.r3.s64 = ctx.r1.s64 + 404;
	// bl 0x82060368
	ctx.lr = 0x821D001C;
	sub_82060368(ctx, base);
	// stw r30,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r30.u32);
	// stw r31,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r31.u32);
	// addi r4,r29,-84
	ctx.r4.s64 = ctx.r29.s64 + -84;
	// stb r31,436(r1)
	PPC_STORE_U8(ctx.r1.u32 + 436, ctx.r31.u8);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r30,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r30.u32);
	// addi r3,r1,492
	ctx.r3.s64 = ctx.r1.s64 + 492;
	// stw r31,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r31.u32);
	// stb r31,464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 464, ctx.r31.u8);
	// stw r27,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r27.u32);
	// stw r30,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r30.u32);
	// stw r31,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r31.u32);
	// stb r31,496(r1)
	PPC_STORE_U8(ctx.r1.u32 + 496, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0054;
	sub_82060368(ctx, base);
	// stw r30,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r30.u32);
	// stw r31,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, ctx.r31.u32);
	// addi r4,r29,-72
	ctx.r4.s64 = ctx.r29.s64 + -72;
	// stb r31,524(r1)
	PPC_STORE_U8(ctx.r1.u32 + 524, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r30.u32);
	// addi r3,r1,936
	ctx.r3.s64 = ctx.r1.s64 + 936;
	// stw r31,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r31.u32);
	// stb r31,552(r1)
	PPC_STORE_U8(ctx.r1.u32 + 552, ctx.r31.u8);
	// stw r31,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r31.u32);
	// stw r31,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r31.u32);
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r30.u32);
	// stw r31,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, ctx.r31.u32);
	// stb r31,940(r1)
	PPC_STORE_U8(ctx.r1.u32 + 940, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0090;
	sub_82060368(ctx, base);
	// stw r30,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r30.u32);
	// stw r31,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r31.u32);
	// addi r4,r29,-56
	ctx.r4.s64 = ctx.r29.s64 + -56;
	// stb r31,968(r1)
	PPC_STORE_U8(ctx.r1.u32 + 968, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r30.u32);
	// addi r3,r1,1084
	ctx.r3.s64 = ctx.r1.s64 + 1084;
	// stw r31,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, ctx.r31.u32);
	// stb r31,996(r1)
	PPC_STORE_U8(ctx.r1.u32 + 996, ctx.r31.u8);
	// stw r30,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r30.u32);
	// stw r31,1040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1040, ctx.r31.u32);
	// stb r31,1024(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1024, ctx.r31.u8);
	// stw r30,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r30.u32);
	// stw r31,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r31.u32);
	// stb r31,1052(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1052, ctx.r31.u8);
	// stw r25,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r25.u32);
	// stw r31,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, ctx.r31.u32);
	// stw r30,1108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1108, ctx.r30.u32);
	// stw r31,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r31.u32);
	// stb r31,1088(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1088, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D00E4;
	sub_82060368(ctx, base);
	// stw r30,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r30.u32);
	// stw r31,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r31.u32);
	// addi r4,r29,-40
	ctx.r4.s64 = ctx.r29.s64 + -40;
	// stb r31,1116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1116, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1112
	ctx.r3.s64 = ctx.r1.s64 + 1112;
	// bl 0x82060368
	ctx.lr = 0x821D0100;
	sub_82060368(ctx, base);
	// stw r30,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r30.u32);
	// stw r31,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r31.u32);
	// stb r31,1144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1144, ctx.r31.u8);
	// addi r4,r29,-16
	ctx.r4.s64 = ctx.r29.s64 + -16;
	// stw r30,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r30.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,1188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1188, ctx.r31.u32);
	// addi r3,r1,1232
	ctx.r3.s64 = ctx.r1.s64 + 1232;
	// stb r31,1172(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1172, ctx.r31.u8);
	// stw r30,1220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1220, ctx.r30.u32);
	// stw r31,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, ctx.r31.u32);
	// stb r31,1200(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1200, ctx.r31.u8);
	// stw r26,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, ctx.r26.u32);
	// stw r31,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r31.u32);
	// stw r30,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, ctx.r30.u32);
	// stw r31,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, ctx.r31.u32);
	// stb r31,1236(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1236, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0148;
	sub_82060368(ctx, base);
	// stw r30,1284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1284, ctx.r30.u32);
	// stw r31,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stb r31,1264(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1264, ctx.r31.u8);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r30,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, ctx.r30.u32);
	// addi r3,r1,1380
	ctx.r3.s64 = ctx.r1.s64 + 1380;
	// stw r31,1308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1308, ctx.r31.u32);
	// stb r31,1292(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1292, ctx.r31.u8);
	// stw r30,1340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1340, ctx.r30.u32);
	// stw r31,1336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1336, ctx.r31.u32);
	// stb r31,1320(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1320, ctx.r31.u8);
	// stw r30,1368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1368, ctx.r30.u32);
	// stw r31,1364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1364, ctx.r31.u32);
	// stb r31,1348(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1348, ctx.r31.u8);
	// stw r27,1372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1372, ctx.r27.u32);
	// stw r31,1376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1376, ctx.r31.u32);
	// stw r30,1404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1404, ctx.r30.u32);
	// stw r31,1400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1400, ctx.r31.u32);
	// stb r31,1384(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1384, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D019C;
	sub_82060368(ctx, base);
	// stw r30,1432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1432, ctx.r30.u32);
	// stw r31,1428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1428, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,1412(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1412, ctx.r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,1460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1460, ctx.r30.u32);
	// addi r3,r1,1492
	ctx.r3.s64 = ctx.r1.s64 + 1492;
	// stw r31,1456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1456, ctx.r31.u32);
	// stb r31,1440(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1440, ctx.r31.u8);
	// stw r30,1488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1488, ctx.r30.u32);
	// stw r31,1484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1484, ctx.r31.u32);
	// stb r31,1468(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1468, ctx.r31.u8);
	// bl 0x820602f0
	ctx.lr = 0x821D01D0;
	sub_820602F0(ctx, base);
	// addic. r3,r28,132
	ctx.xer.ca = ctx.r28.u32 > 4294967163;
	ctx.r3.s64 = ctx.r28.s64 + 132;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821d01e4
	if (ctx.cr0.eq) goto loc_821D01E4;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ba6a0
	ctx.lr = 0x821D01E4;
	sub_821BA6A0(ctx, base);
loc_821D01E4:
	// lwz r3,184(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D01F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,576
	ctx.r4.s64 = ctx.r1.s64 + 576;
	// bne cr6,0x821d0210
	if (!ctx.cr6.eq) goto loc_821D0210;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
loc_821D0210:
	// bl 0x821bcd20
	ctx.lr = 0x821D0214;
	sub_821BCD20(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,928
	ctx.r4.s64 = ctx.r1.s64 + 928;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x821D0224;
	sub_821BCC50(ctx, base);
	// lwz r11,128(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// stb r31,204(r11)
	PPC_STORE_U8(ctx.r11.u32 + 204, ctx.r31.u8);
	// bl 0x821cfbe8
	ctx.lr = 0x821D0230;
	sub_821CFBE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821d0244
	if (!ctx.cr6.eq) goto loc_821D0244;
	// lwz r11,128(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// stb r25,204(r11)
	PPC_STORE_U8(ctx.r11.u32 + 204, ctx.r25.u8);
loc_821D0244:
	// lwz r3,184(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 184);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D0258;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x821d0270
	if (!ctx.cr6.eq) goto loc_821D0270;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D0270;
	sub_821BA280(ctx, base);
loc_821D0270:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r9,19656
	ctx.r6.s64 = ctx.r9.s64 + 19656;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,928
	ctx.r3.s64 = ctx.r1.s64 + 928;
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// stw r10,40(r7)
	PPC_STORE_U32(ctx.r7.u32 + 40, ctx.r10.u32);
	// bl 0x82060818
	ctx.lr = 0x821D02A0;
	sub_82060818(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r6,19288
	ctx.r6.s64 = ctx.r6.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82060818
	ctx.lr = 0x821D02B8;
	sub_82060818(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r4,19288
	ctx.r6.s64 = ctx.r4.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x82060818
	ctx.lr = 0x821D02D0;
	sub_82060818(ctx, base);
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r3,24552
	ctx.r6.s64 = ctx.r3.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x821D02E8;
	sub_82060818(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,1600
	ctx.r1.s64 = ctx.r1.s64 + 1600;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D02F4"))) PPC_WEAK_FUNC(sub_821D02F4);
PPC_FUNC_IMPL(__imp__sub_821D02F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D02F8"))) PPC_WEAK_FUNC(sub_821D02F8);
PPC_FUNC_IMPL(__imp__sub_821D02F8) {
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821d038c
	if (ctx.cr6.lt) goto loc_821D038C;
	// lwz r10,148(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// li r9,36
	ctx.r9.s64 = 36;
	// lwz r8,144(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// addi r11,r3,132
	ctx.r11.s64 = ctx.r3.s64 + 132;
	// subf r5,r8,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r8.s64;
	// divw r4,r5,r9
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r9.s32);
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x821d038c
	if (!ctx.cr6.lt) goto loc_821D038C;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r5,r8,r9
	ctx.r5.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	// cmplw cr6,r7,r5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x821d0350
	if (ctx.cr6.lt) goto loc_821D0350;
	// twi 31,r0,22
loc_821D0350:
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821d0374
	if (ctx.cr6.eq) goto loc_821D0374;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821d038c
	if (!ctx.cr6.eq) goto loc_821D038C;
loc_821D0374:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,80(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// bl 0x82190ae0
	ctx.lr = 0x821D038C;
	sub_82190AE0(ctx, base);
loc_821D038C:
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x821ba9a0
	ctx.lr = 0x821D0398;
	sub_821BA9A0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D03A8"))) PPC_WEAK_FUNC(sub_821D03A8);
PPC_FUNC_IMPL(__imp__sub_821D03A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D03B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r3,132
	ctx.r3.s64 = ctx.r3.s64 + 132;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r4,156(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 156);
	// bl 0x820652a8
	ctx.lr = 0x821D03C8;
	sub_820652A8(ctx, base);
	// lwz r28,28(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x821d03d8
	if (!ctx.cr6.eq) goto loc_821D03D8;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_821D03D8:
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// blt cr6,0x821d04a0
	if (ctx.cr6.lt) goto loc_821D04A0;
	// bne cr6,0x821d04a0
	if (!ctx.cr6.eq) goto loc_821D04A0;
	// lwz r3,128(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d03fc
	if (ctx.cr6.eq) goto loc_821D03FC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D03FC;
	sub_821BC718(ctx, base);
loc_821D03FC:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D0404;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d043c
	if (ctx.cr6.eq) goto loc_821D043C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-9316
	ctx.r4.s64 = ctx.r11.s64 + -9316;
	// bl 0x82060190
	ctx.lr = 0x821D0424;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,124(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D0434;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d0440
	goto loc_821D0440;
loc_821D043C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D0440:
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,6200
	ctx.r3.s64 = 6200;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D0460;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0478
	if (ctx.cr6.eq) goto loc_821D0478;
	// lwz r5,188(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 188);
	// lwz r4,184(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// bl 0x821b2610
	ctx.lr = 0x821D0474;
	sub_821B2610(ctx, base);
	// b 0x821d047c
	goto loc_821D047C;
loc_821D0478:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D047C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r8,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r8.u32);
	// b 0x821d04ac
	goto loc_821D04AC;
loc_821D04A0:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
loc_821D04AC:
	// lwz r11,164(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d04bc
	if (ctx.cr6.eq) goto loc_821D04BC;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_821D04BC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D04C4"))) PPC_WEAK_FUNC(sub_821D04C4);
PPC_FUNC_IMPL(__imp__sub_821D04C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D04C8"))) PPC_WEAK_FUNC(sub_821D04C8);
PPC_FUNC_IMPL(__imp__sub_821D04C8) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 1;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x821d0528
	if (ctx.cr6.gt) goto loc_821D0528;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821d0588
	if (ctx.cr6.eq) goto loc_821D0588;
	// bdz 0x821d04fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D04FC;
	// bdz 0x821d04fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D04FC;
	// bdz 0x821d0548
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0548;
	// bdz 0x821d0560
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0560;
	// bdz 0x821d0528
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0528;
	// bdz 0x821d0528
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0528;
	// b 0x821d0588
	goto loc_821D0588;
loc_821D04FC:
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// blt cr6,0x821d0540
	if (ctx.cr6.lt) goto loc_821D0540;
	// bne cr6,0x821d0528
	if (!ctx.cr6.eq) goto loc_821D0528;
	// li r10,1
	ctx.r10.s64 = 1;
loc_821D050C:
	// lwz r11,188(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
loc_821D0514:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
loc_821D0520:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bge cr6,0x821d05c4
	if (!ctx.cr6.lt) goto loc_821D05C4;
loc_821D0528:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,14920
	ctx.r9.s64 = ctx.r11.s64 + 14920;
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
loc_821D0540:
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x821d050c
	goto loc_821D050C;
loc_821D0548:
	// cmpwi cr6,r5,16
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16, ctx.xer);
	// bne cr6,0x821d0528
	if (!ctx.cr6.eq) goto loc_821D0528;
	// lwz r11,188(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d0528
	if (ctx.cr6.eq) goto loc_821D0528;
	// b 0x821d0514
	goto loc_821D0514;
loc_821D0560:
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// beq cr6,0x821d0528
	if (ctx.cr6.eq) goto loc_821D0528;
	// lwz r11,188(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d0528
	if (ctx.cr6.eq) goto loc_821D0528;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r5,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r5.u32);
	// addi r9,r10,23160
	ctx.r9.s64 = ctx.r10.s64 + 23160;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// b 0x821d0520
	goto loc_821D0520;
loc_821D0588:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// addi r10,r11,7504
	ctx.r10.s64 = ctx.r11.s64 + 7504;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// bne cr6,0x821d05b8
	if (!ctx.cr6.eq) goto loc_821D05B8;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// addi r9,r10,23160
	ctx.r9.s64 = ctx.r10.s64 + 23160;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// beq cr6,0x821d05b8
	if (ctx.cr6.eq) goto loc_821D05B8;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
loc_821D05B8:
	// lwz r11,160(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r11.u32);
	// blr 
	return;
loc_821D05C4:
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D05D8"))) PPC_WEAK_FUNC(sub_821D05D8);
PPC_FUNC_IMPL(__imp__sub_821D05D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,944
	ctx.r10.s64 = ctx.r11.s64 + 944;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821ba410
	sub_821BA410(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D05E8"))) PPC_WEAK_FUNC(sub_821D05E8);
PPC_FUNC_IMPL(__imp__sub_821D05E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x821D05F0;
	__savegprlr_22(ctx, base);
	// stwu r1,-2096(r1)
	ea = -2096 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x821ba6f0
	ctx.lr = 0x821D0604;
	sub_821BA6F0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,184(r28)
	PPC_STORE_U32(ctx.r28.u32 + 184, ctx.r31.u32);
	// li r27,5
	ctx.r27.s64 = 5;
	// stw r30,188(r28)
	PPC_STORE_U32(ctx.r28.u32 + 188, ctx.r30.u32);
	// addi r10,r11,944
	ctx.r10.s64 = ctx.r11.s64 + 944;
	// stw r27,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r27.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r29,r9,-8704
	ctx.r29.s64 = ctx.r9.s64 + -8704;
	// addi r3,r28,88
	ctx.r3.s64 = ctx.r28.s64 + 88;
	// addi r4,r29,-492
	ctx.r4.s64 = ctx.r29.s64 + -492;
	// bl 0x82060368
	ctx.lr = 0x821D0638;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r4,r29,-476
	ctx.r4.s64 = ctx.r29.s64 + -476;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821D065C;
	sub_82060368(ctx, base);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// addi r4,r29,-456
	ctx.r4.s64 = ctx.r29.s64 + -456;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// li r5,15
	ctx.r5.s64 = 15;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// stb r31,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0680;
	sub_82060368(ctx, base);
	// li r24,1
	ctx.r24.s64 = 1;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r4,r29,-440
	ctx.r4.s64 = ctx.r29.s64 + -440;
	// stw r24,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r24.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D06A8;
	sub_82060368(ctx, base);
	// li r23,2
	ctx.r23.s64 = 2;
	// stw r31,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r31.u32);
	// addi r4,r29,-424
	ctx.r4.s64 = ctx.r29.s64 + -424;
	// stw r23,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r23.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r30,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r30.u32);
	// addi r3,r1,188
	ctx.r3.s64 = ctx.r1.s64 + 188;
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D06D0;
	sub_82060368(ctx, base);
	// li r22,3
	ctx.r22.s64 = 3;
	// stw r31,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r31.u32);
	// addi r4,r29,-412
	ctx.r4.s64 = ctx.r29.s64 + -412;
	// stw r22,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r22.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r31.u32);
	// stb r31,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D06F8;
	sub_82060368(ctx, base);
	// li r25,4
	ctx.r25.s64 = 4;
	// stw r31,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r31.u32);
	// addi r4,r29,-400
	ctx.r4.s64 = ctx.r29.s64 + -400;
	// stw r25,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r25.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stw r30,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r30.u32);
	// addi r3,r1,260
	ctx.r3.s64 = ctx.r1.s64 + 260;
	// stw r31,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r31.u32);
	// stb r31,264(r1)
	PPC_STORE_U8(ctx.r1.u32 + 264, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0720;
	sub_82060368(ctx, base);
	// stw r27,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r27.u32);
	// stw r31,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r31.u32);
	// li r5,23
	ctx.r5.s64 = 23;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r30.u32);
	// addi r4,r29,-388
	ctx.r4.s64 = ctx.r29.s64 + -388;
	// stw r31,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r31.u32);
	// stb r31,300(r1)
	PPC_STORE_U8(ctx.r1.u32 + 300, ctx.r31.u8);
	// addi r3,r1,296
	ctx.r3.s64 = ctx.r1.s64 + 296;
	// bl 0x82060368
	ctx.lr = 0x821D0744;
	sub_82060368(ctx, base);
	// li r26,6
	ctx.r26.s64 = 6;
	// stw r31,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r31.u32);
	// addi r4,r29,-364
	ctx.r4.s64 = ctx.r29.s64 + -364;
	// stw r31,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r31.u32);
	// li r5,26
	ctx.r5.s64 = 26;
	// stw r26,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r26.u32);
	// addi r3,r1,340
	ctx.r3.s64 = ctx.r1.s64 + 340;
	// stw r30,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r30.u32);
	// stw r31,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r31.u32);
	// stb r31,344(r1)
	PPC_STORE_U8(ctx.r1.u32 + 344, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0770;
	sub_82060368(ctx, base);
	// stw r30,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r30.u32);
	// stw r31,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r31.u32);
	// addi r4,r29,-336
	ctx.r4.s64 = ctx.r29.s64 + -336;
	// stb r31,372(r1)
	PPC_STORE_U8(ctx.r1.u32 + 372, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x82060368
	ctx.lr = 0x821D078C;
	sub_82060368(ctx, base);
	// stw r30,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r30.u32);
	// stw r31,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r31.u32);
	// addi r4,r29,-312
	ctx.r4.s64 = ctx.r29.s64 + -312;
	// stb r31,400(r1)
	PPC_STORE_U8(ctx.r1.u32 + 400, ctx.r31.u8);
	// li r5,25
	ctx.r5.s64 = 25;
	// stw r24,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r24.u32);
	// addi r3,r1,428
	ctx.r3.s64 = ctx.r1.s64 + 428;
	// stw r30,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r30.u32);
	// stw r31,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r31.u32);
	// stb r31,432(r1)
	PPC_STORE_U8(ctx.r1.u32 + 432, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D07B8;
	sub_82060368(ctx, base);
	// stw r30,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r30.u32);
	// stw r31,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r31.u32);
	// addi r4,r29,-284
	ctx.r4.s64 = ctx.r29.s64 + -284;
	// stb r31,460(r1)
	PPC_STORE_U8(ctx.r1.u32 + 460, ctx.r31.u8);
	// li r5,23
	ctx.r5.s64 = 23;
	// stw r30,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r30.u32);
	// addi r3,r1,516
	ctx.r3.s64 = ctx.r1.s64 + 516;
	// stw r31,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r31.u32);
	// stb r31,488(r1)
	PPC_STORE_U8(ctx.r1.u32 + 488, ctx.r31.u8);
	// stw r23,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r23.u32);
	// stw r30,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, ctx.r30.u32);
	// stw r31,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r31.u32);
	// stb r31,520(r1)
	PPC_STORE_U8(ctx.r1.u32 + 520, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D07F0;
	sub_82060368(ctx, base);
	// stw r30,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r30.u32);
	// stw r31,564(r1)
	PPC_STORE_U32(ctx.r1.u32 + 564, ctx.r31.u32);
	// addi r4,r29,-260
	ctx.r4.s64 = ctx.r29.s64 + -260;
	// stb r31,548(r1)
	PPC_STORE_U8(ctx.r1.u32 + 548, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r30,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r30.u32);
	// addi r3,r1,604
	ctx.r3.s64 = ctx.r1.s64 + 604;
	// stw r31,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r31.u32);
	// stb r31,576(r1)
	PPC_STORE_U8(ctx.r1.u32 + 576, ctx.r31.u8);
	// stw r22,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r22.u32);
	// stw r30,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r30.u32);
	// stw r31,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r31.u32);
	// stb r31,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0828;
	sub_82060368(ctx, base);
	// stw r30,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r30.u32);
	// stw r31,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, ctx.r31.u32);
	// addi r4,r29,-236
	ctx.r4.s64 = ctx.r29.s64 + -236;
	// stb r31,636(r1)
	PPC_STORE_U8(ctx.r1.u32 + 636, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// addi r3,r1,632
	ctx.r3.s64 = ctx.r1.s64 + 632;
	// bl 0x82060368
	ctx.lr = 0x821D0844;
	sub_82060368(ctx, base);
	// stw r30,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r30.u32);
	// stw r31,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, ctx.r31.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stb r31,664(r1)
	PPC_STORE_U8(ctx.r1.u32 + 664, ctx.r31.u8);
	// addi r4,r29,-212
	ctx.r4.s64 = ctx.r29.s64 + -212;
	// stw r25,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r25.u32);
	// addi r3,r1,692
	ctx.r3.s64 = ctx.r1.s64 + 692;
	// stw r30,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r30.u32);
	// stw r31,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r31.u32);
	// stb r31,696(r1)
	PPC_STORE_U8(ctx.r1.u32 + 696, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0870;
	sub_82060368(ctx, base);
	// stw r30,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r30.u32);
	// stw r31,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r31.u32);
	// stb r31,724(r1)
	PPC_STORE_U8(ctx.r1.u32 + 724, ctx.r31.u8);
	// stw r30,772(r1)
	PPC_STORE_U32(ctx.r1.u32 + 772, ctx.r30.u32);
	// addi r4,r29,-188
	ctx.r4.s64 = ctx.r29.s64 + -188;
	// stw r31,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, ctx.r31.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stb r31,752(r1)
	PPC_STORE_U8(ctx.r1.u32 + 752, ctx.r31.u8);
	// addi r3,r1,780
	ctx.r3.s64 = ctx.r1.s64 + 780;
	// stw r27,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r27.u32);
	// stw r30,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r30.u32);
	// stw r31,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, ctx.r31.u32);
	// stb r31,784(r1)
	PPC_STORE_U8(ctx.r1.u32 + 784, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D08A8;
	sub_82060368(ctx, base);
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r30.u32);
	// stw r31,828(r1)
	PPC_STORE_U32(ctx.r1.u32 + 828, ctx.r31.u32);
	// addi r4,r29,-168
	ctx.r4.s64 = ctx.r29.s64 + -168;
	// stb r31,812(r1)
	PPC_STORE_U8(ctx.r1.u32 + 812, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r30,860(r1)
	PPC_STORE_U32(ctx.r1.u32 + 860, ctx.r30.u32);
	// addi r3,r1,868
	ctx.r3.s64 = ctx.r1.s64 + 868;
	// stw r31,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, ctx.r31.u32);
	// stb r31,840(r1)
	PPC_STORE_U8(ctx.r1.u32 + 840, ctx.r31.u8);
	// stw r26,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r26.u32);
	// stw r30,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r30.u32);
	// stw r31,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, ctx.r31.u32);
	// stb r31,872(r1)
	PPC_STORE_U8(ctx.r1.u32 + 872, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D08E0;
	sub_82060368(ctx, base);
	// stw r30,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r30.u32);
	// stw r31,916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 916, ctx.r31.u32);
	// addi r4,r29,-144
	ctx.r4.s64 = ctx.r29.s64 + -144;
	// stb r31,900(r1)
	PPC_STORE_U8(ctx.r1.u32 + 900, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, ctx.r30.u32);
	// addi r3,r1,968
	ctx.r3.s64 = ctx.r1.s64 + 968;
	// stw r31,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, ctx.r31.u32);
	// stb r31,928(r1)
	PPC_STORE_U8(ctx.r1.u32 + 928, ctx.r31.u8);
	// stw r31,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r31.u32);
	// stw r31,964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 964, ctx.r31.u32);
	// stw r30,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r30.u32);
	// stw r31,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r31.u32);
	// stb r31,972(r1)
	PPC_STORE_U8(ctx.r1.u32 + 972, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D091C;
	sub_82060368(ctx, base);
	// stw r30,1020(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1020, ctx.r30.u32);
	// stw r31,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r31.u32);
	// addi r4,r29,-128
	ctx.r4.s64 = ctx.r29.s64 + -128;
	// stb r31,1000(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1000, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,996
	ctx.r3.s64 = ctx.r1.s64 + 996;
	// bl 0x82060368
	ctx.lr = 0x821D0938;
	sub_82060368(ctx, base);
	// stw r30,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, ctx.r30.u32);
	// stw r31,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r31.u32);
	// addi r4,r29,-104
	ctx.r4.s64 = ctx.r29.s64 + -104;
	// stb r31,1028(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1028, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r30.u32);
	// addi r3,r1,1116
	ctx.r3.s64 = ctx.r1.s64 + 1116;
	// stw r31,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r31.u32);
	// stb r31,1056(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1056, ctx.r31.u8);
	// stw r30,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r30.u32);
	// stw r31,1100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1100, ctx.r31.u32);
	// stb r31,1084(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1084, ctx.r31.u8);
	// stw r24,1108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1108, ctx.r24.u32);
	// stw r31,1112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1112, ctx.r31.u32);
	// stw r30,1140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1140, ctx.r30.u32);
	// stw r31,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r31.u32);
	// stb r31,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0980;
	sub_82060368(ctx, base);
	// stw r30,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r30.u32);
	// stw r31,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r31.u32);
	// addi r4,r29,-88
	ctx.r4.s64 = ctx.r29.s64 + -88;
	// stb r31,1148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1148, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1196, ctx.r30.u32);
	// stw r31,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r31.u32);
	// stb r31,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, ctx.r31.u8);
	// stw r30,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, ctx.r30.u32);
	// stw r31,1220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1220, ctx.r31.u32);
	// stb r31,1204(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1204, ctx.r31.u8);
	// stw r30,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, ctx.r30.u32);
	// stw r31,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, ctx.r31.u32);
	// stb r31,1232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1232, ctx.r31.u8);
	// stw r23,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, ctx.r23.u32);
	// stw r31,1260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1260, ctx.r31.u32);
	// stw r30,1288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1288, ctx.r30.u32);
	// addi r3,r1,1264
	ctx.r3.s64 = ctx.r1.s64 + 1264;
	// stw r31,1284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1284, ctx.r31.u32);
	// stb r31,1268(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1268, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D09D4;
	sub_82060368(ctx, base);
	// stw r30,1316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1316, ctx.r30.u32);
	// stw r31,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, ctx.r31.u32);
	// addi r4,r29,-72
	ctx.r4.s64 = ctx.r29.s64 + -72;
	// stb r31,1296(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1296, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1344, ctx.r30.u32);
	// addi r3,r1,1412
	ctx.r3.s64 = ctx.r1.s64 + 1412;
	// stw r31,1340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1340, ctx.r31.u32);
	// stb r31,1324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1324, ctx.r31.u8);
	// stw r30,1372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1372, ctx.r30.u32);
	// stw r31,1368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1368, ctx.r31.u32);
	// stb r31,1352(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1352, ctx.r31.u8);
	// stw r30,1400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1400, ctx.r30.u32);
	// stw r31,1396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1396, ctx.r31.u32);
	// stb r31,1380(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1380, ctx.r31.u8);
	// stw r22,1404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1404, ctx.r22.u32);
	// stw r31,1408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1408, ctx.r31.u32);
	// stw r30,1436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1436, ctx.r30.u32);
	// stw r31,1432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1432, ctx.r31.u32);
	// stb r31,1416(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1416, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D0A28;
	sub_82060368(ctx, base);
	// stw r30,1464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1464, ctx.r30.u32);
	// stw r31,1460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1460, ctx.r31.u32);
	// addi r4,r29,-56
	ctx.r4.s64 = ctx.r29.s64 + -56;
	// stb r31,1444(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1444, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1440
	ctx.r3.s64 = ctx.r1.s64 + 1440;
	// bl 0x82060368
	ctx.lr = 0x821D0A44;
	sub_82060368(ctx, base);
	// stw r30,1492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1492, ctx.r30.u32);
	// stw r31,1488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1488, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r31,1472(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1472, ctx.r31.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,1520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1520, ctx.r30.u32);
	// addi r3,r1,1524
	ctx.r3.s64 = ctx.r1.s64 + 1524;
	// stw r31,1516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1516, ctx.r31.u32);
	// stb r31,1500(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1500, ctx.r31.u8);
	// bl 0x820602f0
	ctx.lr = 0x821D0A6C;
	sub_820602F0(ctx, base);
	// stw r25,1552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1552, ctx.r25.u32);
	// stw r31,1556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1556, ctx.r31.u32);
	// addi r4,r29,-32
	ctx.r4.s64 = ctx.r29.s64 + -32;
	// addi r3,r1,1560
	ctx.r3.s64 = ctx.r1.s64 + 1560;
	// bl 0x82060190
	ctx.lr = 0x821D0A80;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1588
	ctx.r3.s64 = ctx.r1.s64 + 1588;
	// bl 0x820602f0
	ctx.lr = 0x821D0A90;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1616
	ctx.r3.s64 = ctx.r1.s64 + 1616;
	// bl 0x820602f0
	ctx.lr = 0x821D0AA0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1644
	ctx.r3.s64 = ctx.r1.s64 + 1644;
	// bl 0x820602f0
	ctx.lr = 0x821D0AB0;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1672
	ctx.r3.s64 = ctx.r1.s64 + 1672;
	// bl 0x820602f0
	ctx.lr = 0x821D0AC0;
	sub_820602F0(ctx, base);
	// stw r27,1700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1700, ctx.r27.u32);
	// stw r31,1704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1704, ctx.r31.u32);
	// addi r4,r29,-16
	ctx.r4.s64 = ctx.r29.s64 + -16;
	// addi r3,r1,1708
	ctx.r3.s64 = ctx.r1.s64 + 1708;
	// bl 0x82060190
	ctx.lr = 0x821D0AD4;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1736
	ctx.r3.s64 = ctx.r1.s64 + 1736;
	// bl 0x820602f0
	ctx.lr = 0x821D0AE4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1764
	ctx.r3.s64 = ctx.r1.s64 + 1764;
	// bl 0x820602f0
	ctx.lr = 0x821D0AF4;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// bl 0x820602f0
	ctx.lr = 0x821D0B04;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1820
	ctx.r3.s64 = ctx.r1.s64 + 1820;
	// bl 0x820602f0
	ctx.lr = 0x821D0B14;
	sub_820602F0(ctx, base);
	// stw r26,1848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1848, ctx.r26.u32);
	// stw r31,1852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1852, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,1856
	ctx.r3.s64 = ctx.r1.s64 + 1856;
	// bl 0x82060190
	ctx.lr = 0x821D0B28;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1884
	ctx.r3.s64 = ctx.r1.s64 + 1884;
	// bl 0x820602f0
	ctx.lr = 0x821D0B38;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1912
	ctx.r3.s64 = ctx.r1.s64 + 1912;
	// bl 0x820602f0
	ctx.lr = 0x821D0B48;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1940
	ctx.r3.s64 = ctx.r1.s64 + 1940;
	// bl 0x820602f0
	ctx.lr = 0x821D0B58;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1968
	ctx.r3.s64 = ctx.r1.s64 + 1968;
	// bl 0x820602f0
	ctx.lr = 0x821D0B68;
	sub_820602F0(ctx, base);
	// addic. r3,r28,132
	ctx.xer.ca = ctx.r28.u32 > 4294967163;
	ctx.r3.s64 = ctx.r28.s64 + 132;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821d0b7c
	if (ctx.cr0.eq) goto loc_821D0B7C;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ba6a0
	ctx.lr = 0x821D0B7C;
	sub_821BA6A0(ctx, base);
loc_821D0B7C:
	// li r5,7
	ctx.r5.s64 = 7;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// bl 0x821bcd20
	ctx.lr = 0x821D0B8C;
	sub_821BCD20(ctx, base);
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r1,960
	ctx.r4.s64 = ctx.r1.s64 + 960;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x821D0B9C;
	sub_821BCC50(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r6,-31352(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// blt cr6,0x821d0bd8
	if (ctx.cr6.lt) goto loc_821D0BD8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D0BC8;
	sub_821BA280(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D0BD4;
	sub_821BA280(ctx, base);
	// stw r24,156(r28)
	PPC_STORE_U32(ctx.r28.u32 + 156, ctx.r24.u32);
loc_821D0BD8:
	// lwz r10,188(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 188);
	// lwz r11,68(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821d0c14
	if (ctx.cr6.eq) goto loc_821D0C14;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x821d0c1c
	if (!ctx.cr6.eq) goto loc_821D0C1C;
	// lwz r11,76(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// bge cr6,0x821d0c0c
	if (!ctx.cr6.lt) goto loc_821D0C0C;
	// stw r22,156(r28)
	PPC_STORE_U32(ctx.r28.u32 + 156, ctx.r22.u32);
	// b 0x821d0c18
	goto loc_821D0C18;
loc_821D0C0C:
	// stw r23,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r23.u32);
	// b 0x821d0c1c
	goto loc_821D0C1C;
loc_821D0C14:
	// stw r23,156(r28)
	PPC_STORE_U32(ctx.r28.u32 + 156, ctx.r23.u32);
loc_821D0C18:
	// stb r24,172(r28)
	PPC_STORE_U8(ctx.r28.u32 + 172, ctx.r24.u8);
loc_821D0C1C:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r6,r11,19656
	ctx.r6.s64 = ctx.r11.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// bl 0x82060818
	ctx.lr = 0x821D0C34;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r6,r10,19288
	ctx.r6.s64 = ctx.r10.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82060818
	ctx.lr = 0x821D0C4C;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r6,r9,24552
	ctx.r6.s64 = ctx.r9.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x821D0C64;
	sub_82060818(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,2096
	ctx.r1.s64 = ctx.r1.s64 + 2096;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D0C70"))) PPC_WEAK_FUNC(sub_821D0C70);
PPC_FUNC_IMPL(__imp__sub_821D0C70) {
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
	// bl 0x821ba9a0
	ctx.lr = 0x821D0C80;
	sub_821BA9A0(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D0CAC"))) PPC_WEAK_FUNC(sub_821D0CAC);
PPC_FUNC_IMPL(__imp__sub_821D0CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D0CB0"))) PPC_WEAK_FUNC(sub_821D0CB0);
PPC_FUNC_IMPL(__imp__sub_821D0CB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821D0CB8;
	__savegprlr_26(ctx, base);
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,-1
	ctx.r27.s64 = -1;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x821d1198
	if (ctx.cr6.gt) goto loc_821D1198;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821d10f8
	if (ctx.cr6.eq) goto loc_821D10F8;
	// bdz 0x821d0cf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0CF8;
	// bdz 0x821d0e6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0E6C;
	// bdz 0x821d0f08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0F08;
	// bdz 0x821d0fa4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D0FA4;
	// bdz 0x821d105c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D105C;
	// bdz 0x821d1198
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821D1198;
	// b 0x821d10f8
	goto loc_821D10F8;
loc_821D0CF8:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0d10
	if (ctx.cr6.eq) goto loc_821D0D10;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D0D10;
	sub_821BC718(ctx, base);
loc_821D0D10:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,-8608
	ctx.r28.s64 = ctx.r11.s64 + -8608;
	// lwz r11,-31352(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x821d0d4c
	if (!ctx.cr6.lt) goto loc_821D0D4C;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x821d0dd0
	if (ctx.cr6.eq) goto loc_821D0DD0;
loc_821D0D4C:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x821D0D54;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0db4
	if (ctx.cr6.eq) goto loc_821D0DB4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-21261
	ctx.r11.s64 = ctx.r11.s64 + -21261;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x82060190
	ctx.lr = 0x821D0D74;
	sub_82060190(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r28,-68
	ctx.r4.s64 = ctx.r28.s64 + -68;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x82060190
	ctx.lr = 0x821D0D84;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821D0D94;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x821D0DB0;
	sub_821BD670(ctx, base);
	// b 0x821d0db8
	goto loc_821D0DB8;
loc_821D0DB4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D0DB8:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
loc_821D0DD0:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D0DD8;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e08
	if (ctx.cr6.eq) goto loc_821D0E08;
	// addi r4,r28,-40
	ctx.r4.s64 = ctx.r28.s64 + -40;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82060190
	ctx.lr = 0x821D0DF0;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D0E00;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d0e0c
	goto loc_821D0E0C;
loc_821D0E08:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D0E0C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,188
	ctx.r3.s64 = 188;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D0E2C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e44
	if (ctx.cr6.eq) goto loc_821D0E44;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x821d1e98
	ctx.lr = 0x821D0E40;
	sub_821D1E98(ctx, base);
	// b 0x821d0e48
	goto loc_821D0E48;
loc_821D0E44:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D0E48:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// b 0x821d11a8
	goto loc_821D11A8;
loc_821D0E6C:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e84
	if (ctx.cr6.eq) goto loc_821D0E84;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D0E84;
	sub_821BC718(ctx, base);
loc_821D0E84:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D0E8C;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0ec8
	if (ctx.cr6.eq) goto loc_821D0EC8;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// addi r11,r11,-8608
	ctx.r11.s64 = ctx.r11.s64 + -8608;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// bl 0x82060190
	ctx.lr = 0x821D0EB0;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D0EC0;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d0ecc
	goto loc_821D0ECC;
loc_821D0EC8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D0ECC:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,192
	ctx.r3.s64 = 192;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D0EEC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e44
	if (ctx.cr6.eq) goto loc_821D0E44;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r6,188(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x821cfd30
	ctx.lr = 0x821D0F04;
	sub_821CFD30(ctx, base);
	// b 0x821d0e48
	goto loc_821D0E48;
loc_821D0F08:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0f20
	if (ctx.cr6.eq) goto loc_821D0F20;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D0F20;
	sub_821BC718(ctx, base);
loc_821D0F20:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D0F28;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0f64
	if (ctx.cr6.eq) goto loc_821D0F64;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-8608
	ctx.r11.s64 = ctx.r11.s64 + -8608;
	// addi r4,r11,-24
	ctx.r4.s64 = ctx.r11.s64 + -24;
	// bl 0x82060190
	ctx.lr = 0x821D0F4C;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D0F5C;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d0f68
	goto loc_821D0F68;
loc_821D0F64:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D0F68:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,412
	ctx.r3.s64 = 412;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D0F88;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e44
	if (ctx.cr6.eq) goto loc_821D0E44;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r6,188(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x821966d0
	ctx.lr = 0x821D0FA0;
	sub_821966D0(ctx, base);
	// b 0x821d0e48
	goto loc_821D0E48;
loc_821D0FA4:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0fbc
	if (ctx.cr6.eq) goto loc_821D0FBC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D0FBC;
	sub_821BC718(ctx, base);
loc_821D0FBC:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D0FC4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d1000
	if (ctx.cr6.eq) goto loc_821D1000;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-8608
	ctx.r11.s64 = ctx.r11.s64 + -8608;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// bl 0x82060190
	ctx.lr = 0x821D0FE8;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D0FF8;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d1004
	goto loc_821D1004;
loc_821D1000:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D1004:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,11440
	ctx.r3.s64 = 11440;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D1024;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e44
	if (ctx.cr6.eq) goto loc_821D0E44;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D1044;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821abf58
	ctx.lr = 0x821D1058;
	sub_821ABF58(ctx, base);
	// b 0x821d0e48
	goto loc_821D0E48;
loc_821D105C:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d1074
	if (ctx.cr6.eq) goto loc_821D1074;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D1074;
	sub_821BC718(ctx, base);
loc_821D1074:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D107C;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d10b8
	if (ctx.cr6.eq) goto loc_821D10B8;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r11,r11,-8608
	ctx.r11.s64 = ctx.r11.s64 + -8608;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x82060190
	ctx.lr = 0x821D10A0;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D10B0;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d10bc
	goto loc_821D10BC;
loc_821D10B8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D10BC:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,188
	ctx.r3.s64 = 188;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D10DC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d0e44
	if (ctx.cr6.eq) goto loc_821D0E44;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// bl 0x821d2d40
	ctx.lr = 0x821D10F4;
	sub_821D2D40(ctx, base);
	// b 0x821d0e48
	goto loc_821D0E48;
loc_821D10F8:
	// li r3,116
	ctx.r3.s64 = 116;
	// bl 0x82079fd8
	ctx.lr = 0x821D1100;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d115c
	if (ctx.cr6.eq) goto loc_821D115C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// addi r4,r11,-21261
	ctx.r4.s64 = ctx.r11.s64 + -21261;
	// bl 0x82060190
	ctx.lr = 0x821D1120;
	sub_82060190(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,-8608
	ctx.r4.s64 = ctx.r10.s64 + -8608;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82060190
	ctx.lr = 0x821D1134;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821D1144;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x821bd8b8
	ctx.lr = 0x821D1158;
	sub_821BD8B8(ctx, base);
	// b 0x821d1160
	goto loc_821D1160;
loc_821D115C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D1160:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r6,r8,14936
	ctx.r6.s64 = ctx.r8.s64 + 14936;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// stw r5,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r5.u32);
	// stw r7,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r7.u32);
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// b 0x821d11a8
	goto loc_821D11A8;
loc_821D1198:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821D11A8:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d11b8
	if (ctx.cr6.eq) goto loc_821D11B8;
	// stw r27,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r27.u32);
loc_821D11B8:
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D11C0"))) PPC_WEAK_FUNC(sub_821D11C0);
PPC_FUNC_IMPL(__imp__sub_821D11C0) {
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
	// bl 0x821bb3a8
	ctx.lr = 0x821D11DC;
	sub_821BB3A8(ctx, base);
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r11,68(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821d1264
	if (ctx.cr6.eq) goto loc_821D1264;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x821d12e8
	if (!ctx.cr6.eq) goto loc_821D12E8;
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-8684
	ctx.r4.s64 = ctx.r10.s64 + -8684;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821D120C;
	sub_8217C468(ctx, base);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d1224
	if (ctx.cr6.eq) goto loc_821D1224;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D1224;
	sub_821BC718(ctx, base);
loc_821D1224:
	// li r3,11440
	ctx.r3.s64 = 11440;
	// bl 0x82079fd8
	ctx.lr = 0x821D122C;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d12bc
	if (ctx.cr6.eq) goto loc_821D12BC;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D124C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821abf58
	ctx.lr = 0x821D1260;
	sub_821ABF58(ctx, base);
	// b 0x821d12c0
	goto loc_821D12C0;
loc_821D1264:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,-8684
	ctx.r11.s64 = ctx.r11.s64 + -8684;
	// addi r3,r10,16
	ctx.r3.s64 = ctx.r10.s64 + 16;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x8217c468
	ctx.lr = 0x821D1280;
	sub_8217C468(ctx, base);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d1298
	if (ctx.cr6.eq) goto loc_821D1298;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D1298;
	sub_821BC718(ctx, base);
loc_821D1298:
	// li r3,412
	ctx.r3.s64 = 412;
	// bl 0x82079fd8
	ctx.lr = 0x821D12A0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d12bc
	if (ctx.cr6.eq) goto loc_821D12BC;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r6,188(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// bl 0x821966d0
	ctx.lr = 0x821D12B8;
	sub_821966D0(ctx, base);
	// b 0x821d12c0
	goto loc_821D12C0;
loc_821D12BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821D12C0:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,14936
	ctx.r6.s64 = ctx.r8.s64 + 14936;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
loc_821D12E8:
	// lwz r11,188(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 188);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821D130C"))) PPC_WEAK_FUNC(sub_821D130C);
PPC_FUNC_IMPL(__imp__sub_821D130C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D1310"))) PPC_WEAK_FUNC(sub_821D1310);
PPC_FUNC_IMPL(__imp__sub_821D1310) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// lwz r8,596(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 596);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r7,r7,0,31,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x821d133c
	if (ctx.cr6.eq) goto loc_821D133C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, ctx.r11.u8);
loc_821D133C:
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821D1348"))) PPC_WEAK_FUNC(sub_821D1348);
PPC_FUNC_IMPL(__imp__sub_821D1348) {
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
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x821D1368;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_821D1398"))) PPC_WEAK_FUNC(sub_821D1398);
PPC_FUNC_IMPL(__imp__sub_821D1398) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821D13A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,-1444
	ctx.r10.s64 = ctx.r11.s64 + -1444;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x821d13cc
	if (ctx.cr6.eq) goto loc_821D13CC;
	// bl 0x82060120
	ctx.lr = 0x821D13C4;
	sub_82060120(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_821D13CC:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821D13E0;
	sub_82173A18(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r29,r10,-1456
	ctx.r29.s64 = ctx.r10.s64 + -1456;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821D13F8;
	sub_82173A18(ctx, base);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D1408"))) PPC_WEAK_FUNC(sub_821D1408);
PPC_FUNC_IMPL(__imp__sub_821D1408) {
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
	// lbz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d1430
	if (ctx.cr6.eq) goto loc_821D1430;
	// li r11,60
	ctx.r11.s64 = 60;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_821D1430:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r4,128
	ctx.r4.s64 = 128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,136(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,292(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// subfic r11,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r6.s64;
	// clrlwi r5,r11,24
	ctx.r5.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,8,16,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// or r10,r11,r5
	ctx.r10.u64 = ctx.r11.u64 | ctx.r5.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r5
	ctx.r8.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r4,r8,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// bl 0x821796b0
	ctx.lr = 0x821D1498;
	sub_821796B0(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// blt cr6,0x821d14ec
	if (ctx.cr6.lt) goto loc_821D14EC;
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,524
	ctx.r8.s64 = 524;
	// stb r9,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r9.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r7,272(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r8
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821d14d4
	if (!ctx.cr0.eq) goto loc_821D14D4;
	// twi 31,r0,22
loc_821D14D4:
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r9,4936
	ctx.r8.s64 = ctx.r9.s64 + 4936;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
loc_821D14EC:
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

__attribute__((alias("__imp__sub_821D1500"))) PPC_WEAK_FUNC(sub_821D1500);
PPC_FUNC_IMPL(__imp__sub_821D1500) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d1514
	if (ctx.cr6.eq) goto loc_821D1514;
	// li r11,120
	ctx.r11.s64 = 120;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_821D1514:
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,5128
	ctx.r9.s64 = ctx.r11.s64 + 5128;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D1540"))) PPC_WEAK_FUNC(sub_821D1540);
PPC_FUNC_IMPL(__imp__sub_821D1540) {
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
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821d15b8
	if (!ctx.cr6.eq) goto loc_821D15B8;
	// lwz r8,92(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r10,524
	ctx.r10.s64 = 524;
	// stb r9,12(r8)
	PPC_STORE_U8(ctx.r8.u32 + 12, ctx.r9.u8);
	// lwz r11,268(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 268);
	// lwz r7,272(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821d1590
	if (!ctx.cr0.eq) goto loc_821D1590;
	// twi 31,r0,22
loc_821D1590:
	// stb r30,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r30.u8);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// stb r30,12(r8)
	PPC_STORE_U8(ctx.r8.u32 + 12, ctx.r30.u8);
	// lwz r7,272(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 272);
	// lwz r11,268(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 268);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821d15b4
	if (!ctx.cr0.eq) goto loc_821D15B4;
	// twi 31,r0,22
loc_821D15B4:
	// stb r9,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r9.u8);
loc_821D15B8:
	// lbz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d15d0
	if (ctx.cr6.eq) goto loc_821D15D0;
	// li r11,60
	ctx.r11.s64 = 60;
	// stb r30,104(r31)
	PPC_STORE_U8(ctx.r31.u32 + 104, ctx.r30.u8);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_821D15D0:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r4,128
	ctx.r4.s64 = 128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,136(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,292(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// rotlwi r11,r6,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// or r10,r11,r6
	ctx.r10.u64 = ctx.r11.u64 | ctx.r6.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwimi r4,r8,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// bl 0x821796b0
	ctx.lr = 0x821D1634;
	sub_821796B0(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// blt cr6,0x821d1658
	if (ctx.cr6.lt) goto loc_821D1658;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// addi r10,r11,5376
	ctx.r10.s64 = ctx.r11.s64 + 5376;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821D1658:
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

__attribute__((alias("__imp__sub_821D1670"))) PPC_WEAK_FUNC(sub_821D1670);
PPC_FUNC_IMPL(__imp__sub_821D1670) {
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
	// lbz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d1698
	if (ctx.cr6.eq) goto loc_821D1698;
	// li r11,60
	ctx.r11.s64 = 60;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_821D1698:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r4,128
	ctx.r4.s64 = 128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,136(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,292(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// subfic r11,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r11.s64 = 128 - ctx.r6.s64;
	// clrlwi r5,r11,24
	ctx.r5.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r11,r11,8,16,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF00;
	// or r10,r11,r5
	ctx.r10.u64 = ctx.r11.u64 | ctx.r5.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r5
	ctx.r8.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r4,r8,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// bl 0x821796b0
	ctx.lr = 0x821D1700;
	sub_821796B0(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// blt cr6,0x821d1728
	if (ctx.cr6.lt) goto loc_821D1728;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,5440
	ctx.r9.s64 = ctx.r11.s64 + 5440;
	// stw r10,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
loc_821D1728:
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

__attribute__((alias("__imp__sub_821D173C"))) PPC_WEAK_FUNC(sub_821D173C);
PPC_FUNC_IMPL(__imp__sub_821D173C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D1740"))) PPC_WEAK_FUNC(sub_821D1740);
PPC_FUNC_IMPL(__imp__sub_821D1740) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d1754
	if (ctx.cr6.eq) goto loc_821D1754;
	// li r11,120
	ctx.r11.s64 = 120;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
loc_821D1754:
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,120
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 120, ctx.xer);
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,5744
	ctx.r9.s64 = ctx.r11.s64 + 5744;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D1780"))) PPC_WEAK_FUNC(sub_821D1780);
PPC_FUNC_IMPL(__imp__sub_821D1780) {
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
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821d17d4
	if (!ctx.cr6.eq) goto loc_821D17D4;
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// li r9,524
	ctx.r9.s64 = 524;
	// stb r30,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r30.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r8,272(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821d17cc
	if (!ctx.cr0.eq) goto loc_821D17CC;
	// twi 31,r0,22
loc_821D17CC:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
loc_821D17D4:
	// lbz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d17ec
	if (ctx.cr6.eq) goto loc_821D17EC;
	// li r11,60
	ctx.r11.s64 = 60;
	// stb r30,104(r31)
	PPC_STORE_U8(ctx.r31.u32 + 104, ctx.r30.u8);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
loc_821D17EC:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r4,128
	ctx.r4.s64 = 128;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,136(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,292(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// rotlwi r11,r6,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// or r10,r11,r6
	ctx.r10.u64 = ctx.r11.u64 | ctx.r6.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwimi r4,r8,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// bl 0x821796b0
	ctx.lr = 0x821D1850;
	sub_821796B0(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r11,60
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 60, ctx.xer);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// blt cr6,0x821d1874
	if (ctx.cr6.lt) goto loc_821D1874;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// addi r10,r11,5952
	ctx.r10.s64 = ctx.r11.s64 + 5952;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821D1874:
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

__attribute__((alias("__imp__sub_821D188C"))) PPC_WEAK_FUNC(sub_821D188C);
PPC_FUNC_IMPL(__imp__sub_821D188C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D1890"))) PPC_WEAK_FUNC(sub_821D1890);
PPC_FUNC_IMPL(__imp__sub_821D1890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821D1898;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x821D18A8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x821d18e8
	if (ctx.cr6.eq) goto loc_821D18E8;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r9,r10,5300
	ctx.r9.s64 = ctx.r10.s64 + 5300;
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// b 0x821d18ec
	goto loc_821D18EC;
loc_821D18E8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821D18EC:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82079fd8
	ctx.lr = 0x821D18F8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d197c
	if (ctx.cr6.eq) goto loc_821D197C;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// addi r6,r10,5312
	ctx.r6.s64 = ctx.r10.s64 + 5312;
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// addi r5,r8,-2064
	ctx.r5.s64 = ctx.r8.s64 + -2064;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lfs f0,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f13,-21836(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lfs f12,56(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f12,64(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f12,68(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// b 0x821d1980
	goto loc_821D1980;
loc_821D197C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821D1980:
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82079fd8
	ctx.lr = 0x821D198C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d199c
	if (ctx.cr6.eq) goto loc_821D199C;
	// bl 0x8217a960
	ctx.lr = 0x821D1998;
	sub_8217A960(ctx, base);
	// b 0x821d19a0
	goto loc_821D19A0;
loc_821D199C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821D19A0:
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x8217b6a8
	ctx.lr = 0x821D19AC;
	sub_8217B6A8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r3,556
	ctx.r3.s64 = 556;
	// stb r30,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r30.u8);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D19D8;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r28,r11,-2076
	ctx.r28.s64 = ctx.r11.s64 + -2076;
	// beq cr6,0x821d1a10
	if (ctx.cr6.eq) goto loc_821D1A10;
	// addi r4,r28,-16
	ctx.r4.s64 = ctx.r28.s64 + -16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821D19F8;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821D1A08;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d1a14
	goto loc_821D1A14;
loc_821D1A10:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821D1A14:
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// addi r4,r28,-8
	ctx.r4.s64 = ctx.r28.s64 + -8;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821D1A28;
	sub_8217C468(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r26,1
	ctx.r26.s64 = 1;
	// li r27,524
	ctx.r27.s64 = 524;
	// stb r26,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r26.u8);
	// lwz r10,272(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// lwz r11,268(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 268);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x821d1a50
	if (!ctx.cr0.eq) goto loc_821D1A50;
	// twi 31,r0,22
loc_821D1A50:
	// stb r30,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r30.u8);
	// li r3,556
	ctx.r3.s64 = 556;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D1A78;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d1aa8
	if (ctx.cr6.eq) goto loc_821D1AA8;
	// addi r4,r28,-104
	ctx.r4.s64 = ctx.r28.s64 + -104;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821D1A90;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821D1AA0;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d1aac
	goto loc_821D1AAC;
loc_821D1AA8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821D1AAC:
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821D1AC0;
	sub_8217C468(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// stb r26,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r26.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r9,272(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r27
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821d1ae0
	if (!ctx.cr0.eq) goto loc_821D1AE0;
	// twi 31,r0,22
loc_821D1AE0:
	// stb r30,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r30.u8);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r6,r8,6016
	ctx.r6.s64 = ctx.r8.s64 + 6016;
	// lwz r7,20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D1B4C"))) PPC_WEAK_FUNC(sub_821D1B4C);
PPC_FUNC_IMPL(__imp__sub_821D1B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D1B50"))) PPC_WEAK_FUNC(sub_821D1B50);
PPC_FUNC_IMPL(__imp__sub_821D1B50) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r4,r10,-2108
	ctx.r4.s64 = ctx.r10.s64 + -2108;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821D1B90;
	sub_82060368(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31352(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31352);
	// addi r5,r31,76
	ctx.r5.s64 = ctx.r31.s64 + 76;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x82194df8
	ctx.lr = 0x821D1BB8;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821D1BBC;
	sub_82193870(ctx, base);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,6288
	ctx.r9.s64 = ctx.r10.s64 + 6288;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_821D1BF8"))) PPC_WEAK_FUNC(sub_821D1BF8);
PPC_FUNC_IMPL(__imp__sub_821D1BF8) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r5,-32227
	ctx.r5.s64 = -2112028672;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r4,r8,-1396
	ctx.r4.s64 = ctx.r8.s64 + -1396;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r7,r7,840
	ctx.r7.s64 = ctx.r7.s64 + 840;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// addi r6,r6,-1444
	ctx.r6.s64 = ctx.r6.s64 + -1444;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r5,r5,6992
	ctx.r5.s64 = ctx.r5.s64 + 6992;
	// stw r7,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r7.u32);
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
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
	// stb r11,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, ctx.r11.u8);
	// stw r5,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D1C90"))) PPC_WEAK_FUNC(sub_821D1C90);
PPC_FUNC_IMPL(__imp__sub_821D1C90) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// bl 0x82164c10
	ctx.lr = 0x821D1CD0;
	sub_82164C10(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821d1d2c
	if (!ctx.cr6.eq) goto loc_821D1D2C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82163468
	ctx.lr = 0x821D1CE0;
	sub_82163468(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x821d1d20
	if (ctx.cr6.eq) goto loc_821D1D20;
	// bl 0x821631d8
	ctx.lr = 0x821D1CF4;
	sub_821631D8(ctx, base);
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// beq cr6,0x821d1d18
	if (ctx.cr6.eq) goto loc_821D1D18;
	// cmpwi cr6,r30,-5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -5, ctx.xer);
	// bne cr6,0x821d1d10
	if (!ctx.cr6.eq) goto loc_821D1D10;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d1d18
	if (ctx.cr6.eq) goto loc_821D1D18;
loc_821D1D10:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x821d1d2c
	goto loc_821D1D2C;
loc_821D1D18:
	// li r3,-3
	ctx.r3.s64 = -3;
	// b 0x821d1d2c
	goto loc_821D1D2C;
loc_821D1D20:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x821631d8
	ctx.lr = 0x821D1D2C;
	sub_821631D8(ctx, base);
loc_821D1D2C:
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

__attribute__((alias("__imp__sub_821D1D44"))) PPC_WEAK_FUNC(sub_821D1D44);
PPC_FUNC_IMPL(__imp__sub_821D1D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D1D48"))) PPC_WEAK_FUNC(sub_821D1D48);
PPC_FUNC_IMPL(__imp__sub_821D1D48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821D1D50;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,6128
	ctx.r9.s64 = ctx.r11.s64 + 6128;
	// addi r30,r10,-1408
	ctx.r30.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821D1D78;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r29,r8,-1456
	ctx.r29.s64 = ctx.r8.s64 + -1456;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821D1D90;
	sub_82173A18(ctx, base);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D1DA0"))) PPC_WEAK_FUNC(sub_821D1DA0);
PPC_FUNC_IMPL(__imp__sub_821D1DA0) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// addi r4,r7,840
	ctx.r4.s64 = ctx.r7.s64 + 840;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r5,r8,-1396
	ctx.r5.s64 = ctx.r8.s64 + -1396;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// addi r9,r6,6128
	ctx.r9.s64 = ctx.r6.s64 + 6128;
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
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
	// stw r3,-31384(r7)
	PPC_STORE_U32(ctx.r7.u32 + -31384, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D1E30"))) PPC_WEAK_FUNC(sub_821D1E30);
PPC_FUNC_IMPL(__imp__sub_821D1E30) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r8,r10,14920
	ctx.r8.s64 = ctx.r10.s64 + 14920;
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// stw r8,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r8.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,76(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x821d1e74
	if (!ctx.cr6.lt) goto loc_821D1E74;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821D1E74:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x821ba280
	sub_821BA280(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D1E80"))) PPC_WEAK_FUNC(sub_821D1E80);
PPC_FUNC_IMPL(__imp__sub_821D1E80) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D1E84"))) PPC_WEAK_FUNC(sub_821D1E84);
PPC_FUNC_IMPL(__imp__sub_821D1E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D1E88"))) PPC_WEAK_FUNC(sub_821D1E88);
PPC_FUNC_IMPL(__imp__sub_821D1E88) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,1232
	ctx.r10.s64 = ctx.r11.s64 + 1232;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821ba410
	sub_821BA410(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D1E98"))) PPC_WEAK_FUNC(sub_821D1E98);
PPC_FUNC_IMPL(__imp__sub_821D1E98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821D1EA0;
	__savegprlr_25(ctx, base);
	// stwu r1,-1264(r1)
	ea = -1264 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x821ba6f0
	ctx.lr = 0x821D1EB0;
	sub_821BA6F0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,184(r26)
	PPC_STORE_U32(ctx.r26.u32 + 184, ctx.r31.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,1232
	ctx.r9.s64 = ctx.r11.s64 + 1232;
	// stw r10,84(r26)
	PPC_STORE_U32(ctx.r26.u32 + 84, ctx.r10.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r9,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r9.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r29,r8,-11808
	ctx.r29.s64 = ctx.r8.s64 + -11808;
	// addi r3,r26,88
	ctx.r3.s64 = ctx.r26.s64 + 88;
	// addi r4,r29,-324
	ctx.r4.s64 = ctx.r29.s64 + -324;
	// bl 0x82060368
	ctx.lr = 0x821D1EE0;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r4,r29,-304
	ctx.r4.s64 = ctx.r29.s64 + -304;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821D1F04;
	sub_82060368(ctx, base);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// addi r4,r29,-288
	ctx.r4.s64 = ctx.r29.s64 + -288;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// stb r31,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D1F28;
	sub_82060368(ctx, base);
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// addi r4,r29,-272
	ctx.r4.s64 = ctx.r29.s64 + -272;
	// stw r27,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r27.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D1F50;
	sub_82060368(ctx, base);
	// li r28,2
	ctx.r28.s64 = 2;
	// stw r31,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r31.u32);
	// addi r4,r29,-252
	ctx.r4.s64 = ctx.r29.s64 + -252;
	// stw r28,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r28.u32);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r30,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r30.u32);
	// addi r3,r1,188
	ctx.r3.s64 = ctx.r1.s64 + 188;
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D1F78;
	sub_82060368(ctx, base);
	// li r25,3
	ctx.r25.s64 = 3;
	// stw r31,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r31.u32);
	// addi r4,r29,-240
	ctx.r4.s64 = ctx.r29.s64 + -240;
	// stw r25,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r25.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// stw r31,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r31.u32);
	// addi r3,r1,244
	ctx.r3.s64 = ctx.r1.s64 + 244;
	// stw r30,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r30.u32);
	// stw r31,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r31.u32);
	// stb r31,248(r1)
	PPC_STORE_U8(ctx.r1.u32 + 248, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D1FA4;
	sub_82060368(ctx, base);
	// stw r30,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r30.u32);
	// stw r31,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r31.u32);
	// addi r4,r29,-216
	ctx.r4.s64 = ctx.r29.s64 + -216;
	// stb r31,276(r1)
	PPC_STORE_U8(ctx.r1.u32 + 276, ctx.r31.u8);
	// li r5,22
	ctx.r5.s64 = 22;
	// stw r30,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r30.u32);
	// addi r3,r1,332
	ctx.r3.s64 = ctx.r1.s64 + 332;
	// stw r31,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r31.u32);
	// stb r31,304(r1)
	PPC_STORE_U8(ctx.r1.u32 + 304, ctx.r31.u8);
	// stw r27,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r27.u32);
	// stw r30,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r30.u32);
	// stw r31,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r31.u32);
	// stb r31,336(r1)
	PPC_STORE_U8(ctx.r1.u32 + 336, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D1FDC;
	sub_82060368(ctx, base);
	// stw r30,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r30.u32);
	// stw r31,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r31.u32);
	// addi r4,r29,-192
	ctx.r4.s64 = ctx.r29.s64 + -192;
	// stb r31,364(r1)
	PPC_STORE_U8(ctx.r1.u32 + 364, ctx.r31.u8);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r1,360
	ctx.r3.s64 = ctx.r1.s64 + 360;
	// bl 0x82060368
	ctx.lr = 0x821D1FF8;
	sub_82060368(ctx, base);
	// stw r30,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r30.u32);
	// stw r31,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r31.u32);
	// addi r4,r29,-156
	ctx.r4.s64 = ctx.r29.s64 + -156;
	// stb r31,392(r1)
	PPC_STORE_U8(ctx.r1.u32 + 392, ctx.r31.u8);
	// li r5,24
	ctx.r5.s64 = 24;
	// stw r28,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r28.u32);
	// addi r3,r1,420
	ctx.r3.s64 = ctx.r1.s64 + 420;
	// stw r30,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r30.u32);
	// stw r31,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, ctx.r31.u32);
	// stb r31,424(r1)
	PPC_STORE_U8(ctx.r1.u32 + 424, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2024;
	sub_82060368(ctx, base);
	// stw r30,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r30.u32);
	// stw r31,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r31.u32);
	// addi r4,r29,-128
	ctx.r4.s64 = ctx.r29.s64 + -128;
	// stb r31,452(r1)
	PPC_STORE_U8(ctx.r1.u32 + 452, ctx.r31.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x82060368
	ctx.lr = 0x821D2040;
	sub_82060368(ctx, base);
	// stw r30,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r30.u32);
	// stw r31,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r31.u32);
	// addi r4,r29,-108
	ctx.r4.s64 = ctx.r29.s64 + -108;
	// stb r31,480(r1)
	PPC_STORE_U8(ctx.r1.u32 + 480, ctx.r31.u8);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r25,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r25.u32);
	// addi r3,r1,508
	ctx.r3.s64 = ctx.r1.s64 + 508;
	// stw r30,532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 532, ctx.r30.u32);
	// stw r31,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r31.u32);
	// stb r31,512(r1)
	PPC_STORE_U8(ctx.r1.u32 + 512, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D206C;
	sub_82060368(ctx, base);
	// stw r30,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r30.u32);
	// stw r31,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r31.u32);
	// addi r4,r29,-96
	ctx.r4.s64 = ctx.r29.s64 + -96;
	// stb r31,540(r1)
	PPC_STORE_U8(ctx.r1.u32 + 540, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r30.u32);
	// addi r3,r1,616
	ctx.r3.s64 = ctx.r1.s64 + 616;
	// stw r31,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r31.u32);
	// stb r31,568(r1)
	PPC_STORE_U8(ctx.r1.u32 + 568, ctx.r31.u8);
	// stw r31,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r31.u32);
	// stw r31,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r31.u32);
	// stw r30,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, ctx.r30.u32);
	// stw r31,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r31.u32);
	// stb r31,620(r1)
	PPC_STORE_U8(ctx.r1.u32 + 620, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D20A8;
	sub_82060368(ctx, base);
	// stw r30,668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 668, ctx.r30.u32);
	// stw r31,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r31.u32);
	// addi r4,r29,-80
	ctx.r4.s64 = ctx.r29.s64 + -80;
	// stb r31,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r30.u32);
	// addi r3,r1,764
	ctx.r3.s64 = ctx.r1.s64 + 764;
	// stw r31,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, ctx.r31.u32);
	// stb r31,676(r1)
	PPC_STORE_U8(ctx.r1.u32 + 676, ctx.r31.u8);
	// stw r30,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r30.u32);
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r31.u32);
	// stb r31,704(r1)
	PPC_STORE_U8(ctx.r1.u32 + 704, ctx.r31.u8);
	// stw r30,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r30.u32);
	// stw r31,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r31.u32);
	// stb r31,732(r1)
	PPC_STORE_U8(ctx.r1.u32 + 732, ctx.r31.u8);
	// stw r27,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r27.u32);
	// stw r31,760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 760, ctx.r31.u32);
	// stw r30,788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 788, ctx.r30.u32);
	// stw r31,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, ctx.r31.u32);
	// stb r31,768(r1)
	PPC_STORE_U8(ctx.r1.u32 + 768, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D20FC;
	sub_82060368(ctx, base);
	// stw r30,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, ctx.r30.u32);
	// stw r31,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r31.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// stb r31,796(r1)
	PPC_STORE_U8(ctx.r1.u32 + 796, ctx.r31.u8);
	// addi r4,r29,-64
	ctx.r4.s64 = ctx.r29.s64 + -64;
	// addi r3,r1,792
	ctx.r3.s64 = ctx.r1.s64 + 792;
	// bl 0x82060368
	ctx.lr = 0x821D2118;
	sub_82060368(ctx, base);
	// stw r30,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r30.u32);
	// stw r31,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r31.u32);
	// stb r31,824(r1)
	PPC_STORE_U8(ctx.r1.u32 + 824, ctx.r31.u8);
	// stw r30,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r30.u32);
	// stw r31,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r31.u32);
	// stb r31,852(r1)
	PPC_STORE_U8(ctx.r1.u32 + 852, ctx.r31.u8);
	// addi r4,r29,-40
	ctx.r4.s64 = ctx.r29.s64 + -40;
	// stw r30,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, ctx.r30.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r31.u32);
	// addi r3,r1,912
	ctx.r3.s64 = ctx.r1.s64 + 912;
	// stb r31,880(r1)
	PPC_STORE_U8(ctx.r1.u32 + 880, ctx.r31.u8);
	// stw r28,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, ctx.r28.u32);
	// stw r31,908(r1)
	PPC_STORE_U32(ctx.r1.u32 + 908, ctx.r31.u32);
	// stw r30,936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 936, ctx.r30.u32);
	// stw r31,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r31.u32);
	// stb r31,916(r1)
	PPC_STORE_U8(ctx.r1.u32 + 916, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2160;
	sub_82060368(ctx, base);
	// stw r30,964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 964, ctx.r30.u32);
	// stw r31,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r31.u32);
	// addi r4,r29,-24
	ctx.r4.s64 = ctx.r29.s64 + -24;
	// stb r31,944(r1)
	PPC_STORE_U8(ctx.r1.u32 + 944, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,940
	ctx.r3.s64 = ctx.r1.s64 + 940;
	// bl 0x82060368
	ctx.lr = 0x821D217C;
	sub_82060368(ctx, base);
	// stw r30,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r30.u32);
	// stw r31,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stb r31,972(r1)
	PPC_STORE_U8(ctx.r1.u32 + 972, ctx.r31.u8);
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r30,1020(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1020, ctx.r30.u32);
	// addi r3,r1,1060
	ctx.r3.s64 = ctx.r1.s64 + 1060;
	// stw r31,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r31.u32);
	// stb r31,1000(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1000, ctx.r31.u8);
	// stw r30,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, ctx.r30.u32);
	// stw r31,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r31.u32);
	// stb r31,1028(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1028, ctx.r31.u8);
	// stw r25,1052(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1052, ctx.r25.u32);
	// stw r31,1056(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1056, ctx.r31.u32);
	// stw r30,1084(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1084, ctx.r30.u32);
	// stw r31,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, ctx.r31.u32);
	// stb r31,1064(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1064, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D21C4;
	sub_82060368(ctx, base);
	// addic. r29,r26,132
	ctx.xer.ca = ctx.r26.u32 > 4294967163;
	ctx.r29.s64 = ctx.r26.s64 + 132;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,1112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1112, ctx.r30.u32);
	// stw r31,1108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1108, ctx.r31.u32);
	// stb r31,1092(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1092, ctx.r31.u8);
	// stw r30,1140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1140, ctx.r30.u32);
	// stw r31,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r31.u32);
	// stb r31,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, ctx.r31.u8);
	// stw r30,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r30.u32);
	// stw r31,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r31.u32);
	// stb r31,1148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1148, ctx.r31.u8);
	// stw r30,1196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1196, ctx.r30.u32);
	// stw r31,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r31.u32);
	// stb r31,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, ctx.r31.u8);
	// beq 0x821d2224
	if (ctx.cr0.eq) goto loc_821D2224;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82065d80
	ctx.lr = 0x821D2204;
	sub_82065D80(ctx, base);
	// addi r27,r1,80
	ctx.r27.s64 = ctx.r1.s64 + 80;
	// li r28,4
	ctx.r28.s64 = 4;
loc_821D220C:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820653e8
	ctx.lr = 0x821D2218;
	sub_820653E8(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r27,r27,36
	ctx.r27.s64 = ctx.r27.s64 + 36;
	// bne 0x821d220c
	if (!ctx.cr0.eq) goto loc_821D220C;
loc_821D2224:
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,128(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 128);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// bl 0x821bcd20
	ctx.lr = 0x821D2234;
	sub_821BCD20(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,608
	ctx.r4.s64 = ctx.r1.s64 + 608;
	// lwz r3,128(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x821D2244;
	sub_821BCC50(ctx, base);
	// lwz r3,184(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 184);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821D2258;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x821d2270
	if (!ctx.cr6.eq) goto loc_821D2270;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D2270;
	sub_821BA280(ctx, base);
loc_821D2270:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r6,-31352(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r11,76(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x821d22a0
	if (!ctx.cr6.lt) goto loc_821D22A0;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x821d22b0
	if (ctx.cr6.eq) goto loc_821D22B0;
loc_821D22A0:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D22B0;
	sub_821BA280(ctx, base);
loc_821D22B0:
	// lwz r11,76(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r29,r1,1200
	ctx.r29.s64 = ctx.r1.s64 + 1200;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// stw r10,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r10.u32);
loc_821D22C8:
	// addi r29,r29,-148
	ctx.r29.s64 = ctx.r29.s64 + -148;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82064cc8
	ctx.lr = 0x821D22D4;
	sub_82064CC8(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x821d22c8
	if (!ctx.cr0.lt) goto loc_821D22C8;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// addi r29,r1,656
	ctx.r29.s64 = ctx.r1.s64 + 656;
loc_821D22E4:
	// addi r29,r29,-88
	ctx.r29.s64 = ctx.r29.s64 + -88;
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d22fc
	if (ctx.cr6.lt) goto loc_821D22FC;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D22FC;
	sub_8207A630(ctx, base);
loc_821D22FC:
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stb r31,0(r29)
	PPC_STORE_U8(ctx.r29.u32 + 0, ctx.r31.u8);
	// lwz r11,-8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -8);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d231c
	if (ctx.cr6.lt) goto loc_821D231C;
	// lwz r3,-28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + -28);
	// bl 0x8207a630
	ctx.lr = 0x821D231C;
	sub_8207A630(ctx, base);
loc_821D231C:
	// stw r30,-8(r29)
	PPC_STORE_U32(ctx.r29.u32 + -8, ctx.r30.u32);
	// stw r31,-12(r29)
	PPC_STORE_U32(ctx.r29.u32 + -12, ctx.r31.u32);
	// stb r31,-28(r29)
	PPC_STORE_U8(ctx.r29.u32 + -28, ctx.r31.u8);
	// lwz r11,-36(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -36);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d233c
	if (ctx.cr6.lt) goto loc_821D233C;
	// lwz r3,-56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + -56);
	// bl 0x8207a630
	ctx.lr = 0x821D233C;
	sub_8207A630(ctx, base);
loc_821D233C:
	// stw r30,-36(r29)
	PPC_STORE_U32(ctx.r29.u32 + -36, ctx.r30.u32);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stw r31,-40(r29)
	PPC_STORE_U32(ctx.r29.u32 + -40, ctx.r31.u32);
	// stb r31,-56(r29)
	PPC_STORE_U8(ctx.r29.u32 + -56, ctx.r31.u8);
	// bge 0x821d22e4
	if (!ctx.cr0.lt) goto loc_821D22E4;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// addi r29,r1,228
	ctx.r29.s64 = ctx.r1.s64 + 228;
loc_821D2358:
	// addi r29,r29,-36
	ctx.r29.s64 = ctx.r29.s64 + -36;
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d2370
	if (ctx.cr6.lt) goto loc_821D2370;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D2370;
	sub_8207A630(ctx, base);
loc_821D2370:
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stb r31,0(r29)
	PPC_STORE_U8(ctx.r29.u32 + 0, ctx.r31.u8);
	// bge 0x821d2358
	if (!ctx.cr0.lt) goto loc_821D2358;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D2390"))) PPC_WEAK_FUNC(sub_821D2390);
PPC_FUNC_IMPL(__imp__sub_821D2390) {
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821d2424
	if (ctx.cr6.lt) goto loc_821D2424;
	// lwz r10,148(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// li r9,36
	ctx.r9.s64 = 36;
	// lwz r8,144(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// addi r11,r3,132
	ctx.r11.s64 = ctx.r3.s64 + 132;
	// subf r5,r8,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r8.s64;
	// divw r4,r5,r9
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r9.s32);
	// cmpw cr6,r7,r4
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r4.s32, ctx.xer);
	// bge cr6,0x821d2424
	if (!ctx.cr6.lt) goto loc_821D2424;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r5,r8,r9
	ctx.r5.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	// cmplw cr6,r7,r5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x821d23e8
	if (ctx.cr6.lt) goto loc_821D23E8;
	// twi 31,r0,22
loc_821D23E8:
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,28(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821d240c
	if (ctx.cr6.eq) goto loc_821D240C;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821d2424
	if (!ctx.cr6.eq) goto loc_821D2424;
loc_821D240C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,80(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// bl 0x82190ae0
	ctx.lr = 0x821D2424;
	sub_82190AE0(ctx, base);
loc_821D2424:
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x821ba9a0
	ctx.lr = 0x821D2430;
	sub_821BA9A0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D2440"))) PPC_WEAK_FUNC(sub_821D2440);
PPC_FUNC_IMPL(__imp__sub_821D2440) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,76(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x821d2498
	if (!ctx.cr6.lt) goto loc_821D2498;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x821d2498
	if (!ctx.cr6.eq) goto loc_821D2498;
	// bl 0x821ba190
	ctx.lr = 0x821D2484;
	sub_821BA190(ctx, base);
	// clrlwi r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821d24c4
	if (ctx.cr6.eq) goto loc_821D24C4;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x821d24b0
	goto loc_821D24B0;
loc_821D2498:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x821ba190
	ctx.lr = 0x821D24A0;
	sub_821BA190(ctx, base);
	// clrlwi r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821d24c4
	if (!ctx.cr6.eq) goto loc_821D24C4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_821D24B0:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D24BC;
	sub_821BA280(ctx, base);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x821babb8
	ctx.lr = 0x821D24C4;
	sub_821BABB8(ctx, base);
loc_821D24C4:
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

__attribute__((alias("__imp__sub_821D24D8"))) PPC_WEAK_FUNC(sub_821D24D8);
PPC_FUNC_IMPL(__imp__sub_821D24D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D24E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r28,-1
	ctx.r28.s64 = -1;
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// blt cr6,0x821d25b0
	if (ctx.cr6.lt) goto loc_821D25B0;
	// bne cr6,0x821d25b0
	if (!ctx.cr6.eq) goto loc_821D25B0;
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d2510
	if (ctx.cr6.eq) goto loc_821D2510;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D2510;
	sub_821BC718(ctx, base);
loc_821D2510:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D2518;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d2550
	if (ctx.cr6.eq) goto loc_821D2550;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11796
	ctx.r4.s64 = ctx.r11.s64 + -11796;
	// bl 0x82060190
	ctx.lr = 0x821D2538;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,124(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D2548;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d2554
	goto loc_821D2554;
loc_821D2550:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D2554:
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,388
	ctx.r3.s64 = 388;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D2574;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d2588
	if (ctx.cr6.eq) goto loc_821D2588;
	// lwz r4,184(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 184);
	// bl 0x821ae8d0
	ctx.lr = 0x821D2584;
	sub_821AE8D0(ctx, base);
	// b 0x821d258c
	goto loc_821D258C;
loc_821D2588:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D258C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r8,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r8.u32);
	// b 0x821d25c0
	goto loc_821D25C0;
loc_821D25B0:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r10,r11,23160
	ctx.r10.s64 = ctx.r11.s64 + 23160;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
loc_821D25C0:
	// lwz r11,164(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d25d0
	if (ctx.cr6.eq) goto loc_821D25D0;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_821D25D0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D25D8"))) PPC_WEAK_FUNC(sub_821D25D8);
PPC_FUNC_IMPL(__imp__sub_821D25D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,1396
	ctx.r10.s64 = ctx.r11.s64 + 1396;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821b89a0
	sub_821B89A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D25E8"))) PPC_WEAK_FUNC(sub_821D25E8);
PPC_FUNC_IMPL(__imp__sub_821D25E8) {
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
	// bl 0x821b8ff8
	ctx.lr = 0x821D25F8;
	sub_821B8FF8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r10,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D2624"))) PPC_WEAK_FUNC(sub_821D2624);
PPC_FUNC_IMPL(__imp__sub_821D2624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D2628"))) PPC_WEAK_FUNC(sub_821D2628);
PPC_FUNC_IMPL(__imp__sub_821D2628) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821D2630;
	__savegprlr_26(ctx, base);
	// stwu r1,-1760(r1)
	ea = -1760 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// bl 0x821b9138
	ctx.lr = 0x821D2640;
	sub_821B9138(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r26,176(r27)
	PPC_STORE_U32(ctx.r27.u32 + 176, ctx.r26.u32);
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r9,r11,1396
	ctx.r9.s64 = ctx.r11.s64 + 1396;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r31.u32);
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r9,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r9.u32);
	// stw r10,84(r27)
	PPC_STORE_U32(ctx.r27.u32 + 84, ctx.r10.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r30,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r30.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stb r31,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r31.u8);
	// addi r29,r11,-12872
	ctx.r29.s64 = ctx.r11.s64 + -12872;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// addi r4,r29,-468
	ctx.r4.s64 = ctx.r29.s64 + -468;
	// bl 0x82060368
	ctx.lr = 0x821D2684;
	sub_82060368(ctx, base);
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// stw r31,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r31.u32);
	// addi r4,r29,-452
	ctx.r4.s64 = ctx.r29.s64 + -452;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r3,r1,356
	ctx.r3.s64 = ctx.r1.s64 + 356;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
	// stw r30,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r30.u32);
	// stw r31,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r31.u32);
	// stb r31,360(r1)
	PPC_STORE_U8(ctx.r1.u32 + 360, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D26AC;
	sub_82060368(ctx, base);
	// addi r7,r1,388
	ctx.r7.s64 = ctx.r1.s64 + 388;
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r30.u32);
	// stw r31,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r31.u32);
	// addi r4,r29,-440
	ctx.r4.s64 = ctx.r29.s64 + -440;
	// stw r28,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r28.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r31.u8);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r31.u32);
	// bl 0x82060368
	ctx.lr = 0x821D26D8;
	sub_82060368(ctx, base);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stw r31,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r31.u32);
	// addi r4,r29,-424
	ctx.r4.s64 = ctx.r29.s64 + -424;
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r1,196
	ctx.r3.s64 = ctx.r1.s64 + 196;
	// stw r31,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r31.u32);
	// stw r30,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r30.u32);
	// stw r31,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r31.u32);
	// stb r31,200(r1)
	PPC_STORE_U8(ctx.r1.u32 + 200, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2700;
	sub_82060368(ctx, base);
	// addi r11,r1,228
	ctx.r11.s64 = ctx.r1.s64 + 228;
	// stw r28,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r28.u32);
	// addi r4,r29,-408
	ctx.r4.s64 = ctx.r29.s64 + -408;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// bl 0x82060368
	ctx.lr = 0x821D2728;
	sub_82060368(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// addi r4,r29,-392
	ctx.r4.s64 = ctx.r29.s64 + -392;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// stb r31,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2750;
	sub_82060368(ctx, base);
	// addi r9,r1,148
	ctx.r9.s64 = ctx.r1.s64 + 148;
	// stw r28,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r28.u32);
	// addi r4,r29,-380
	ctx.r4.s64 = ctx.r29.s64 + -380;
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r30.u32);
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r31.u32);
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r31.u32);
	// stb r31,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, ctx.r31.u8);
	// li r5,13
	ctx.r5.s64 = 13;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82060368
	ctx.lr = 0x821D2778;
	sub_82060368(ctx, base);
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// stw r31,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r31.u32);
	// addi r4,r29,-364
	ctx.r4.s64 = ctx.r29.s64 + -364;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r3,r1,276
	ctx.r3.s64 = ctx.r1.s64 + 276;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
	// stw r30,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r30.u32);
	// stw r31,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r31.u32);
	// stb r31,280(r1)
	PPC_STORE_U8(ctx.r1.u32 + 280, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D27A0;
	sub_82060368(ctx, base);
	// addi r7,r1,308
	ctx.r7.s64 = ctx.r1.s64 + 308;
	// stw r28,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r28.u32);
	// addi r4,r29,-352
	ctx.r4.s64 = ctx.r29.s64 + -352;
	// stw r31,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r31.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r30,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, ctx.r30.u32);
	// addi r3,r1,580
	ctx.r3.s64 = ctx.r1.s64 + 580;
	// stw r31,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r31.u32);
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r31.u32);
	// stb r31,584(r1)
	PPC_STORE_U8(ctx.r1.u32 + 584, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D27CC;
	sub_82060368(ctx, base);
	// stw r30,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r30.u32);
	// stw r31,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r31.u32);
	// addi r4,r29,-320
	ctx.r4.s64 = ctx.r29.s64 + -320;
	// stb r31,612(r1)
	PPC_STORE_U8(ctx.r1.u32 + 612, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, ctx.r30.u32);
	// addi r3,r1,668
	ctx.r3.s64 = ctx.r1.s64 + 668;
	// stw r31,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r31.u32);
	// stb r31,640(r1)
	PPC_STORE_U8(ctx.r1.u32 + 640, ctx.r31.u8);
	// stw r28,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r28.u32);
	// stw r30,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, ctx.r30.u32);
	// stw r31,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r31.u32);
	// stb r31,672(r1)
	PPC_STORE_U8(ctx.r1.u32 + 672, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2804;
	sub_82060368(ctx, base);
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r30.u32);
	// stw r31,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r31.u32);
	// addi r4,r29,-288
	ctx.r4.s64 = ctx.r29.s64 + -288;
	// stb r31,700(r1)
	PPC_STORE_U8(ctx.r1.u32 + 700, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r30.u32);
	// addi r3,r1,932
	ctx.r3.s64 = ctx.r1.s64 + 932;
	// stw r31,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r31.u32);
	// stb r31,728(r1)
	PPC_STORE_U8(ctx.r1.u32 + 728, ctx.r31.u8);
	// stw r31,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r31.u32);
	// stw r30,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, ctx.r30.u32);
	// stw r31,952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 952, ctx.r31.u32);
	// stb r31,936(r1)
	PPC_STORE_U8(ctx.r1.u32 + 936, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D283C;
	sub_82060368(ctx, base);
	// stw r30,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r30.u32);
	// stw r31,980(r1)
	PPC_STORE_U32(ctx.r1.u32 + 980, ctx.r31.u32);
	// addi r4,r29,-256
	ctx.r4.s64 = ctx.r29.s64 + -256;
	// stb r31,964(r1)
	PPC_STORE_U8(ctx.r1.u32 + 964, ctx.r31.u8);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r30,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, ctx.r30.u32);
	// addi r3,r1,1020
	ctx.r3.s64 = ctx.r1.s64 + 1020;
	// stw r31,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, ctx.r31.u32);
	// stb r31,992(r1)
	PPC_STORE_U8(ctx.r1.u32 + 992, ctx.r31.u8);
	// stw r28,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r28.u32);
	// stw r30,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r30.u32);
	// stw r31,1040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1040, ctx.r31.u32);
	// stb r31,1024(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1024, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2874;
	sub_82060368(ctx, base);
	// stw r30,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r30.u32);
	// stw r31,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r31.u32);
	// addi r4,r29,-224
	ctx.r4.s64 = ctx.r29.s64 + -224;
	// stb r31,1052(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1052, ctx.r31.u8);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r30,1100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1100, ctx.r30.u32);
	// stw r31,1096(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1096, ctx.r31.u32);
	// stb r31,1080(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1080, ctx.r31.u8);
	// stw r31,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r31.u32);
	// stw r30,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r30.u32);
	// stw r31,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r31.u32);
	// addi r3,r1,756
	ctx.r3.s64 = ctx.r1.s64 + 756;
	// stb r31,760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 760, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D28AC;
	sub_82060368(ctx, base);
	// stw r30,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r30.u32);
	// stw r31,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r31.u32);
	// addi r4,r29,-192
	ctx.r4.s64 = ctx.r29.s64 + -192;
	// stb r31,788(r1)
	PPC_STORE_U8(ctx.r1.u32 + 788, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r30.u32);
	// addi r3,r1,844
	ctx.r3.s64 = ctx.r1.s64 + 844;
	// stw r31,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r31.u32);
	// stb r31,816(r1)
	PPC_STORE_U8(ctx.r1.u32 + 816, ctx.r31.u8);
	// stw r28,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r28.u32);
	// stw r30,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r30.u32);
	// stw r31,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r31.u32);
	// stb r31,848(r1)
	PPC_STORE_U8(ctx.r1.u32 + 848, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D28E4;
	sub_82060368(ctx, base);
	// stw r30,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r30.u32);
	// stw r31,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r31.u32);
	// addi r4,r29,-160
	ctx.r4.s64 = ctx.r29.s64 + -160;
	// stb r31,876(r1)
	PPC_STORE_U8(ctx.r1.u32 + 876, ctx.r31.u8);
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r30,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, ctx.r30.u32);
	// addi r3,r1,404
	ctx.r3.s64 = ctx.r1.s64 + 404;
	// stw r31,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r31.u32);
	// stb r31,904(r1)
	PPC_STORE_U8(ctx.r1.u32 + 904, ctx.r31.u8);
	// stw r31,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r31.u32);
	// stw r30,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r30.u32);
	// stw r31,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r31.u32);
	// stb r31,408(r1)
	PPC_STORE_U8(ctx.r1.u32 + 408, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D291C;
	sub_82060368(ctx, base);
	// stw r30,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r30.u32);
	// stw r31,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r31.u32);
	// addi r4,r29,-128
	ctx.r4.s64 = ctx.r29.s64 + -128;
	// stb r31,436(r1)
	PPC_STORE_U8(ctx.r1.u32 + 436, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r30.u32);
	// addi r3,r1,492
	ctx.r3.s64 = ctx.r1.s64 + 492;
	// stw r31,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r31.u32);
	// stb r31,464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 464, ctx.r31.u8);
	// stw r28,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r28.u32);
	// stw r30,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r30.u32);
	// stw r31,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r31.u32);
	// stb r31,496(r1)
	PPC_STORE_U8(ctx.r1.u32 + 496, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2954;
	sub_82060368(ctx, base);
	// stw r30,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r30.u32);
	// stw r31,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, ctx.r31.u32);
	// addi r4,r29,-96
	ctx.r4.s64 = ctx.r29.s64 + -96;
	// stb r31,524(r1)
	PPC_STORE_U8(ctx.r1.u32 + 524, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r30.u32);
	// addi r3,r1,1112
	ctx.r3.s64 = ctx.r1.s64 + 1112;
	// stw r31,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r31.u32);
	// stb r31,552(r1)
	PPC_STORE_U8(ctx.r1.u32 + 552, ctx.r31.u8);
	// stw r31,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r31.u32);
	// stw r31,1108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1108, ctx.r31.u32);
	// stw r30,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r30.u32);
	// stw r31,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r31.u32);
	// stb r31,1116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1116, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2990;
	sub_82060368(ctx, base);
	// stw r30,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r30.u32);
	// stw r31,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r31.u32);
	// addi r4,r29,-64
	ctx.r4.s64 = ctx.r29.s64 + -64;
	// stb r31,1144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1144, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r30.u32);
	// addi r3,r1,1260
	ctx.r3.s64 = ctx.r1.s64 + 1260;
	// stw r31,1188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1188, ctx.r31.u32);
	// stb r31,1172(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1172, ctx.r31.u8);
	// stw r30,1220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1220, ctx.r30.u32);
	// stw r31,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, ctx.r31.u32);
	// stb r31,1200(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1200, ctx.r31.u8);
	// stw r30,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, ctx.r30.u32);
	// stw r31,1244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1244, ctx.r31.u32);
	// stb r31,1228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1228, ctx.r31.u8);
	// stw r28,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, ctx.r28.u32);
	// stw r31,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, ctx.r31.u32);
	// stw r30,1284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1284, ctx.r30.u32);
	// stw r31,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, ctx.r31.u32);
	// stb r31,1264(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1264, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D29E4;
	sub_82060368(ctx, base);
	// stw r30,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, ctx.r30.u32);
	// stw r31,1308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1308, ctx.r31.u32);
	// addi r4,r29,-32
	ctx.r4.s64 = ctx.r29.s64 + -32;
	// stb r31,1292(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1292, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,1340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1340, ctx.r30.u32);
	// addi r3,r1,1416
	ctx.r3.s64 = ctx.r1.s64 + 1416;
	// stw r31,1336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1336, ctx.r31.u32);
	// stb r31,1320(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1320, ctx.r31.u8);
	// stw r30,1368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1368, ctx.r30.u32);
	// stw r31,1364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1364, ctx.r31.u32);
	// stb r31,1348(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1348, ctx.r31.u8);
	// stw r30,1396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1396, ctx.r30.u32);
	// stw r31,1392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1392, ctx.r31.u32);
	// stb r31,1376(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1376, ctx.r31.u8);
	// stw r31,1408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1408, ctx.r31.u32);
	// stw r31,1412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1412, ctx.r31.u32);
	// stw r30,1440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1440, ctx.r30.u32);
	// stw r31,1436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1436, ctx.r31.u32);
	// stb r31,1420(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1420, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2A38;
	sub_82060368(ctx, base);
	// stw r30,1468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1468, ctx.r30.u32);
	// stw r31,1464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1464, ctx.r31.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stb r31,1448(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1448, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// stw r30,1496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1496, ctx.r30.u32);
	// addi r3,r1,1564
	ctx.r3.s64 = ctx.r1.s64 + 1564;
	// stw r31,1492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1492, ctx.r31.u32);
	// stb r31,1476(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1476, ctx.r31.u8);
	// stw r30,1524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1524, ctx.r30.u32);
	// stw r31,1520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1520, ctx.r31.u32);
	// stb r31,1504(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1504, ctx.r31.u8);
	// stw r30,1552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1552, ctx.r30.u32);
	// stw r31,1548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1548, ctx.r31.u32);
	// stb r31,1532(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1532, ctx.r31.u8);
	// stw r28,1556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1556, ctx.r28.u32);
	// stw r31,1560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1560, ctx.r31.u32);
	// stw r30,1588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1588, ctx.r30.u32);
	// stw r31,1584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1584, ctx.r31.u32);
	// stb r31,1568(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1568, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2A8C;
	sub_82060368(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1592
	ctx.r3.s64 = ctx.r1.s64 + 1592;
	// bl 0x820602f0
	ctx.lr = 0x821D2A9C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1620
	ctx.r3.s64 = ctx.r1.s64 + 1620;
	// bl 0x820602f0
	ctx.lr = 0x821D2AAC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1648
	ctx.r3.s64 = ctx.r1.s64 + 1648;
	// bl 0x820602f0
	ctx.lr = 0x821D2ABC;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1676
	ctx.r3.s64 = ctx.r1.s64 + 1676;
	// bl 0x820602f0
	ctx.lr = 0x821D2ACC;
	sub_820602F0(ctx, base);
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// beq cr6,0x821d2ba4
	if (ctx.cr6.eq) goto loc_821D2BA4;
	// cmpwi cr6,r26,2
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 2, ctx.xer);
	// beq cr6,0x821d2b64
	if (ctx.cr6.eq) goto loc_821D2B64;
	// cmpwi cr6,r26,3
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 3, ctx.xer);
	// beq cr6,0x821d2b24
	if (ctx.cr6.eq) goto loc_821D2B24;
	// addi r11,r29,-580
	ctx.r11.s64 = ctx.r29.s64 + -580;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_821D2AEC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821d2aec
	if (!ctx.cr6.eq) goto loc_821D2AEC;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r4,r29,-580
	ctx.r4.s64 = ctx.r29.s64 + -580;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r27,88
	ctx.r3.s64 = ctx.r27.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821D2B14;
	sub_82060368(ctx, base);
	// addi r31,r1,320
	ctx.r31.s64 = ctx.r1.s64 + 320;
	// addi r29,r1,576
	ctx.r29.s64 = ctx.r1.s64 + 576;
	// addi r28,r1,1104
	ctx.r28.s64 = ctx.r1.s64 + 1104;
	// b 0x821d2be0
	goto loc_821D2BE0;
loc_821D2B24:
	// addi r11,r29,-496
	ctx.r11.s64 = ctx.r29.s64 + -496;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_821D2B2C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821d2b2c
	if (!ctx.cr6.eq) goto loc_821D2B2C;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r4,r29,-496
	ctx.r4.s64 = ctx.r29.s64 + -496;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r27,88
	ctx.r3.s64 = ctx.r27.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821D2B54;
	sub_82060368(ctx, base);
	// addi r31,r1,240
	ctx.r31.s64 = ctx.r1.s64 + 240;
	// addi r29,r1,400
	ctx.r29.s64 = ctx.r1.s64 + 400;
	// addi r28,r1,1104
	ctx.r28.s64 = ctx.r1.s64 + 1104;
	// b 0x821d2be0
	goto loc_821D2BE0;
loc_821D2B64:
	// addi r11,r29,-524
	ctx.r11.s64 = ctx.r29.s64 + -524;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_821D2B6C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821d2b6c
	if (!ctx.cr6.eq) goto loc_821D2B6C;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r4,r29,-524
	ctx.r4.s64 = ctx.r29.s64 + -524;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r27,88
	ctx.r3.s64 = ctx.r27.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821D2B94;
	sub_82060368(ctx, base);
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,752
	ctx.r29.s64 = ctx.r1.s64 + 752;
	// addi r28,r1,1104
	ctx.r28.s64 = ctx.r1.s64 + 1104;
	// b 0x821d2be0
	goto loc_821D2BE0;
loc_821D2BA4:
	// addi r11,r29,-556
	ctx.r11.s64 = ctx.r29.s64 + -556;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_821D2BAC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821d2bac
	if (!ctx.cr6.eq) goto loc_821D2BAC;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r4,r29,-556
	ctx.r4.s64 = ctx.r29.s64 + -556;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r27,88
	ctx.r3.s64 = ctx.r27.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821D2BD4;
	sub_82060368(ctx, base);
	// addi r31,r1,160
	ctx.r31.s64 = ctx.r1.s64 + 160;
	// addi r29,r1,928
	ctx.r29.s64 = ctx.r1.s64 + 928;
	// addi r28,r1,1408
	ctx.r28.s64 = ctx.r1.s64 + 1408;
loc_821D2BE0:
	// addic. r26,r27,136
	ctx.xer.ca = ctx.r27.u32 > 4294967159;
	ctx.r26.s64 = ctx.r27.s64 + 136;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq 0x821d2c14
	if (ctx.cr0.eq) goto loc_821D2C14;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821d2c14
	if (ctx.cr6.eq) goto loc_821D2C14;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82065d80
	ctx.lr = 0x821D2BF8;
	sub_82065D80(ctx, base);
	// li r30,2
	ctx.r30.s64 = 2;
loc_821D2BFC:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820653e8
	ctx.lr = 0x821D2C08;
	sub_820653E8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,36
	ctx.r31.s64 = ctx.r31.s64 + 36;
	// bne 0x821d2bfc
	if (!ctx.cr0.eq) goto loc_821D2BFC;
loc_821D2C14:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,132(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 132);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x821bcd20
	ctx.lr = 0x821D2C24;
	sub_821BCD20(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,132(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 132);
	// bl 0x821bcc50
	ctx.lr = 0x821D2C34;
	sub_821BCC50(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r11,19656
	ctx.r6.s64 = ctx.r11.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,1408
	ctx.r3.s64 = ctx.r1.s64 + 1408;
	// bl 0x82060818
	ctx.lr = 0x821D2C4C;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r10,19656
	ctx.r6.s64 = ctx.r10.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x82060818
	ctx.lr = 0x821D2C64;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r9,19288
	ctx.r6.s64 = ctx.r9.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82060818
	ctx.lr = 0x821D2C7C;
	sub_82060818(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r8,19288
	ctx.r6.s64 = ctx.r8.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82060818
	ctx.lr = 0x821D2C94;
	sub_82060818(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r7,19288
	ctx.r6.s64 = ctx.r7.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,928
	ctx.r3.s64 = ctx.r1.s64 + 928;
	// bl 0x82060818
	ctx.lr = 0x821D2CAC;
	sub_82060818(ctx, base);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r6,19288
	ctx.r6.s64 = ctx.r6.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x82060818
	ctx.lr = 0x821D2CC4;
	sub_82060818(ctx, base);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r4,24552
	ctx.r6.s64 = ctx.r4.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82060818
	ctx.lr = 0x821D2CDC;
	sub_82060818(ctx, base);
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r3,24552
	ctx.r6.s64 = ctx.r3.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x821D2CF4;
	sub_82060818(ctx, base);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r11,24552
	ctx.r6.s64 = ctx.r11.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82060818
	ctx.lr = 0x821D2D0C;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r10,24552
	ctx.r6.s64 = ctx.r10.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82060818
	ctx.lr = 0x821D2D24;
	sub_82060818(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,1760
	ctx.r1.s64 = ctx.r1.s64 + 1760;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D2D30"))) PPC_WEAK_FUNC(sub_821D2D30);
PPC_FUNC_IMPL(__imp__sub_821D2D30) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,1088
	ctx.r10.s64 = ctx.r11.s64 + 1088;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821ba410
	sub_821BA410(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D2D40"))) PPC_WEAK_FUNC(sub_821D2D40);
PPC_FUNC_IMPL(__imp__sub_821D2D40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x821D2D48;
	__savegprlr_22(ctx, base);
	// stwu r1,-1808(r1)
	ea = -1808 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// bl 0x821ba6f0
	ctx.lr = 0x821D2D5C;
	sub_821BA6F0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,184(r28)
	PPC_STORE_U32(ctx.r28.u32 + 184, ctx.r31.u32);
	// li r27,5
	ctx.r27.s64 = 5;
	// addi r10,r11,1088
	ctx.r10.s64 = ctx.r11.s64 + 1088;
	// stw r27,84(r28)
	PPC_STORE_U32(ctx.r28.u32 + 84, ctx.r27.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r29,r9,-10052
	ctx.r29.s64 = ctx.r9.s64 + -10052;
	// addi r3,r28,88
	ctx.r3.s64 = ctx.r28.s64 + 88;
	// addi r4,r29,-624
	ctx.r4.s64 = ctx.r29.s64 + -624;
	// bl 0x82060368
	ctx.lr = 0x821D2D8C;
	sub_82060368(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r30,15
	ctx.r30.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// addi r4,r29,-612
	ctx.r4.s64 = ctx.r29.s64 + -612;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r30.u32);
	// li r5,15
	ctx.r5.s64 = 15;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821D2DB0;
	sub_82060368(ctx, base);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// addi r4,r29,-596
	ctx.r4.s64 = ctx.r29.s64 + -596;
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r31.u32);
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r30.u32);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// stb r31,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2DD8;
	sub_82060368(ctx, base);
	// addi r7,r1,148
	ctx.r7.s64 = ctx.r1.s64 + 148;
	// li r23,1
	ctx.r23.s64 = 1;
	// addi r4,r29,-584
	ctx.r4.s64 = ctx.r29.s64 + -584;
	// stw r23,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r23.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// stw r31,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r31.u32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r30.u32);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r31.u32);
	// stb r31,156(r1)
	PPC_STORE_U8(ctx.r1.u32 + 156, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2E04;
	sub_82060368(ctx, base);
	// addi r6,r1,184
	ctx.r6.s64 = ctx.r1.s64 + 184;
	// li r24,2
	ctx.r24.s64 = 2;
	// addi r4,r29,-572
	ctx.r4.s64 = ctx.r29.s64 + -572;
	// stw r24,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r24.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// addi r3,r1,188
	ctx.r3.s64 = ctx.r1.s64 + 188;
	// stw r31,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r31.u32);
	// stw r30,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r30.u32);
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// stb r31,192(r1)
	PPC_STORE_U8(ctx.r1.u32 + 192, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2E30;
	sub_82060368(ctx, base);
	// addi r11,r1,220
	ctx.r11.s64 = ctx.r1.s64 + 220;
	// li r25,3
	ctx.r25.s64 = 3;
	// addi r4,r29,-556
	ctx.r4.s64 = ctx.r29.s64 + -556;
	// stw r25,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r25.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// stw r31,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r31.u32);
	// stb r31,228(r1)
	PPC_STORE_U8(ctx.r1.u32 + 228, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2E5C;
	sub_82060368(ctx, base);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// li r26,4
	ctx.r26.s64 = 4;
	// addi r4,r29,-544
	ctx.r4.s64 = ctx.r29.s64 + -544;
	// stw r26,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r26.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r1,260
	ctx.r3.s64 = ctx.r1.s64 + 260;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
	// stw r30,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r30.u32);
	// stw r31,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r31.u32);
	// stb r31,264(r1)
	PPC_STORE_U8(ctx.r1.u32 + 264, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2E88;
	sub_82060368(ctx, base);
	// addi r9,r1,292
	ctx.r9.s64 = ctx.r1.s64 + 292;
	// stw r27,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r27.u32);
	// addi r4,r29,-536
	ctx.r4.s64 = ctx.r29.s64 + -536;
	// stw r31,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r31.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// stw r30,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r30.u32);
	// addi r3,r1,308
	ctx.r3.s64 = ctx.r1.s64 + 308;
	// stw r31,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r31.u32);
	// stw r31,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r31.u32);
	// stb r31,312(r1)
	PPC_STORE_U8(ctx.r1.u32 + 312, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2EB4;
	sub_82060368(ctx, base);
	// stw r30,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r30.u32);
	// stw r31,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r31.u32);
	// addi r4,r29,-512
	ctx.r4.s64 = ctx.r29.s64 + -512;
	// stb r31,340(r1)
	PPC_STORE_U8(ctx.r1.u32 + 340, ctx.r31.u8);
	// li r5,18
	ctx.r5.s64 = 18;
	// stw r30,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r30.u32);
	// addi r3,r1,396
	ctx.r3.s64 = ctx.r1.s64 + 396;
	// stw r31,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r31.u32);
	// stb r31,368(r1)
	PPC_STORE_U8(ctx.r1.u32 + 368, ctx.r31.u8);
	// stw r23,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r23.u32);
	// stw r30,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r30.u32);
	// stw r31,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r31.u32);
	// stb r31,400(r1)
	PPC_STORE_U8(ctx.r1.u32 + 400, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2EEC;
	sub_82060368(ctx, base);
	// stw r30,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r30.u32);
	// stw r31,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r31.u32);
	// addi r4,r29,-492
	ctx.r4.s64 = ctx.r29.s64 + -492;
	// stb r31,428(r1)
	PPC_STORE_U8(ctx.r1.u32 + 428, ctx.r31.u8);
	// li r5,17
	ctx.r5.s64 = 17;
	// stw r30,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r30.u32);
	// addi r3,r1,484
	ctx.r3.s64 = ctx.r1.s64 + 484;
	// stw r31,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r31.u32);
	// stb r31,456(r1)
	PPC_STORE_U8(ctx.r1.u32 + 456, ctx.r31.u8);
	// stw r24,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r24.u32);
	// stw r30,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r30.u32);
	// stw r31,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r31.u32);
	// stb r31,488(r1)
	PPC_STORE_U8(ctx.r1.u32 + 488, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2F24;
	sub_82060368(ctx, base);
	// stw r30,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r30.u32);
	// stw r31,532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 532, ctx.r31.u32);
	// addi r4,r29,-472
	ctx.r4.s64 = ctx.r29.s64 + -472;
	// stb r31,516(r1)
	PPC_STORE_U8(ctx.r1.u32 + 516, ctx.r31.u8);
	// li r5,19
	ctx.r5.s64 = 19;
	// stw r30,564(r1)
	PPC_STORE_U32(ctx.r1.u32 + 564, ctx.r30.u32);
	// addi r3,r1,572
	ctx.r3.s64 = ctx.r1.s64 + 572;
	// stw r31,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r31.u32);
	// stb r31,544(r1)
	PPC_STORE_U8(ctx.r1.u32 + 544, ctx.r31.u8);
	// stw r25,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r25.u32);
	// stw r30,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r30.u32);
	// stw r31,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r31.u32);
	// stb r31,576(r1)
	PPC_STORE_U8(ctx.r1.u32 + 576, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2F5C;
	sub_82060368(ctx, base);
	// stw r30,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r30.u32);
	// stw r31,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r31.u32);
	// addi r4,r29,-452
	ctx.r4.s64 = ctx.r29.s64 + -452;
	// stb r31,604(r1)
	PPC_STORE_U8(ctx.r1.u32 + 604, ctx.r31.u8);
	// li r5,21
	ctx.r5.s64 = 21;
	// addi r3,r1,600
	ctx.r3.s64 = ctx.r1.s64 + 600;
	// bl 0x82060368
	ctx.lr = 0x821D2F78;
	sub_82060368(ctx, base);
	// stw r30,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, ctx.r30.u32);
	// stw r31,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, ctx.r31.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stb r31,632(r1)
	PPC_STORE_U8(ctx.r1.u32 + 632, ctx.r31.u8);
	// addi r4,r29,-428
	ctx.r4.s64 = ctx.r29.s64 + -428;
	// stw r26,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r26.u32);
	// addi r3,r1,660
	ctx.r3.s64 = ctx.r1.s64 + 660;
	// stw r30,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r30.u32);
	// stw r31,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, ctx.r31.u32);
	// stb r31,664(r1)
	PPC_STORE_U8(ctx.r1.u32 + 664, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2FA4;
	sub_82060368(ctx, base);
	// stw r30,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r30.u32);
	// stw r31,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, ctx.r31.u32);
	// stb r31,692(r1)
	PPC_STORE_U8(ctx.r1.u32 + 692, ctx.r31.u8);
	// stw r30,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r30.u32);
	// stw r31,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, ctx.r31.u32);
	// stb r31,720(r1)
	PPC_STORE_U8(ctx.r1.u32 + 720, ctx.r31.u8);
	// stw r27,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r27.u32);
	// addi r4,r29,-408
	ctx.r4.s64 = ctx.r29.s64 + -408;
	// stw r30,772(r1)
	PPC_STORE_U32(ctx.r1.u32 + 772, ctx.r30.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r31,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, ctx.r31.u32);
	// addi r3,r1,748
	ctx.r3.s64 = ctx.r1.s64 + 748;
	// stb r31,752(r1)
	PPC_STORE_U8(ctx.r1.u32 + 752, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D2FDC;
	sub_82060368(ctx, base);
	// stw r30,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, ctx.r30.u32);
	// stw r31,796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 796, ctx.r31.u32);
	// addi r4,r29,-396
	ctx.r4.s64 = ctx.r29.s64 + -396;
	// stb r31,780(r1)
	PPC_STORE_U8(ctx.r1.u32 + 780, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,828(r1)
	PPC_STORE_U32(ctx.r1.u32 + 828, ctx.r30.u32);
	// addi r3,r1,840
	ctx.r3.s64 = ctx.r1.s64 + 840;
	// stw r31,824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 824, ctx.r31.u32);
	// stb r31,808(r1)
	PPC_STORE_U8(ctx.r1.u32 + 808, ctx.r31.u8);
	// stw r31,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r31.u32);
	// stw r31,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r31.u32);
	// stw r30,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r30.u32);
	// stw r31,860(r1)
	PPC_STORE_U32(ctx.r1.u32 + 860, ctx.r31.u32);
	// stb r31,844(r1)
	PPC_STORE_U8(ctx.r1.u32 + 844, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D3018;
	sub_82060368(ctx, base);
	// stw r30,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r30.u32);
	// stw r31,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, ctx.r31.u32);
	// addi r4,r29,-380
	ctx.r4.s64 = ctx.r29.s64 + -380;
	// stb r31,872(r1)
	PPC_STORE_U8(ctx.r1.u32 + 872, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,868
	ctx.r3.s64 = ctx.r1.s64 + 868;
	// bl 0x82060368
	ctx.lr = 0x821D3034;
	sub_82060368(ctx, base);
	// stw r30,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r30.u32);
	// stw r31,916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 916, ctx.r31.u32);
	// addi r4,r29,-356
	ctx.r4.s64 = ctx.r29.s64 + -356;
	// stb r31,900(r1)
	PPC_STORE_U8(ctx.r1.u32 + 900, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x82060368
	ctx.lr = 0x821D3050;
	sub_82060368(ctx, base);
	// stw r30,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, ctx.r30.u32);
	// stw r31,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, ctx.r31.u32);
	// addi r4,r29,-324
	ctx.r4.s64 = ctx.r29.s64 + -324;
	// stb r31,928(r1)
	PPC_STORE_U8(ctx.r1.u32 + 928, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, ctx.r30.u32);
	// addi r3,r1,988
	ctx.r3.s64 = ctx.r1.s64 + 988;
	// stw r31,972(r1)
	PPC_STORE_U32(ctx.r1.u32 + 972, ctx.r31.u32);
	// stb r31,956(r1)
	PPC_STORE_U8(ctx.r1.u32 + 956, ctx.r31.u8);
	// stw r23,980(r1)
	PPC_STORE_U32(ctx.r1.u32 + 980, ctx.r23.u32);
	// stw r31,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r31.u32);
	// stw r30,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, ctx.r30.u32);
	// stw r31,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, ctx.r31.u32);
	// stb r31,992(r1)
	PPC_STORE_U8(ctx.r1.u32 + 992, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D308C;
	sub_82060368(ctx, base);
	// stw r30,1040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1040, ctx.r30.u32);
	// stw r31,1036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1036, ctx.r31.u32);
	// addi r4,r29,-308
	ctx.r4.s64 = ctx.r29.s64 + -308;
	// stb r31,1020(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1020, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1016
	ctx.r3.s64 = ctx.r1.s64 + 1016;
	// bl 0x82060368
	ctx.lr = 0x821D30A8;
	sub_82060368(ctx, base);
	// stw r30,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r30.u32);
	// stw r31,1064(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1064, ctx.r31.u32);
	// addi r4,r29,-284
	ctx.r4.s64 = ctx.r29.s64 + -284;
	// stb r31,1048(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1048, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,1044
	ctx.r3.s64 = ctx.r1.s64 + 1044;
	// bl 0x82060368
	ctx.lr = 0x821D30C4;
	sub_82060368(ctx, base);
	// stw r30,1096(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1096, ctx.r30.u32);
	// stw r31,1092(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1092, ctx.r31.u32);
	// addi r4,r29,-252
	ctx.r4.s64 = ctx.r29.s64 + -252;
	// stb r31,1076(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1076, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1124, ctx.r30.u32);
	// addi r3,r1,1136
	ctx.r3.s64 = ctx.r1.s64 + 1136;
	// stw r31,1120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1120, ctx.r31.u32);
	// stb r31,1104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1104, ctx.r31.u8);
	// stw r24,1128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1128, ctx.r24.u32);
	// stw r31,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r31.u32);
	// stw r30,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r30.u32);
	// stw r31,1156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1156, ctx.r31.u32);
	// stb r31,1140(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1140, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D3100;
	sub_82060368(ctx, base);
	// stw r30,1188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1188, ctx.r30.u32);
	// addi r4,r29,-236
	ctx.r4.s64 = ctx.r29.s64 + -236;
	// stw r31,1184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1184, ctx.r31.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// stb r31,1168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1168, ctx.r31.u8);
	// addi r3,r1,1164
	ctx.r3.s64 = ctx.r1.s64 + 1164;
	// bl 0x82060368
	ctx.lr = 0x821D311C;
	sub_82060368(ctx, base);
	// stw r30,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, ctx.r30.u32);
	// stw r31,1212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1212, ctx.r31.u32);
	// addi r4,r29,-212
	ctx.r4.s64 = ctx.r29.s64 + -212;
	// stb r31,1196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1196, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,1192
	ctx.r3.s64 = ctx.r1.s64 + 1192;
	// bl 0x82060368
	ctx.lr = 0x821D3138;
	sub_82060368(ctx, base);
	// stw r30,1244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1244, ctx.r30.u32);
	// stw r31,1240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1240, ctx.r31.u32);
	// addi r4,r29,-180
	ctx.r4.s64 = ctx.r29.s64 + -180;
	// stb r31,1224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1224, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1272, ctx.r30.u32);
	// addi r3,r1,1284
	ctx.r3.s64 = ctx.r1.s64 + 1284;
	// stw r31,1268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1268, ctx.r31.u32);
	// stb r31,1252(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1252, ctx.r31.u8);
	// stw r25,1276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1276, ctx.r25.u32);
	// stw r31,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, ctx.r31.u32);
	// stw r30,1308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1308, ctx.r30.u32);
	// stw r31,1304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1304, ctx.r31.u32);
	// stb r31,1288(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1288, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D3174;
	sub_82060368(ctx, base);
	// stw r30,1336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1336, ctx.r30.u32);
	// stw r31,1332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1332, ctx.r31.u32);
	// addi r4,r29,-164
	ctx.r4.s64 = ctx.r29.s64 + -164;
	// stb r31,1316(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1316, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1312
	ctx.r3.s64 = ctx.r1.s64 + 1312;
	// bl 0x82060368
	ctx.lr = 0x821D3190;
	sub_82060368(ctx, base);
	// stw r30,1364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1364, ctx.r30.u32);
	// stw r31,1360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1360, ctx.r31.u32);
	// addi r4,r29,-140
	ctx.r4.s64 = ctx.r29.s64 + -140;
	// stb r31,1344(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1344, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,1340
	ctx.r3.s64 = ctx.r1.s64 + 1340;
	// bl 0x82060368
	ctx.lr = 0x821D31AC;
	sub_82060368(ctx, base);
	// stw r30,1392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1392, ctx.r30.u32);
	// stw r31,1388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1388, ctx.r31.u32);
	// addi r4,r29,-108
	ctx.r4.s64 = ctx.r29.s64 + -108;
	// stb r31,1372(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1372, ctx.r31.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r30,1420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1420, ctx.r30.u32);
	// addi r3,r1,1432
	ctx.r3.s64 = ctx.r1.s64 + 1432;
	// stw r31,1416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1416, ctx.r31.u32);
	// stb r31,1400(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1400, ctx.r31.u8);
	// stw r26,1424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1424, ctx.r26.u32);
	// stw r31,1428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1428, ctx.r31.u32);
	// stw r30,1456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1456, ctx.r30.u32);
	// stw r31,1452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1452, ctx.r31.u32);
	// stb r31,1436(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1436, ctx.r31.u8);
	// bl 0x82060368
	ctx.lr = 0x821D31E8;
	sub_82060368(ctx, base);
	// stw r30,1484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1484, ctx.r30.u32);
	// stw r31,1480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1480, ctx.r31.u32);
	// addi r4,r29,-92
	ctx.r4.s64 = ctx.r29.s64 + -92;
	// stb r31,1464(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1464, ctx.r31.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r1,1460
	ctx.r3.s64 = ctx.r1.s64 + 1460;
	// bl 0x82060368
	ctx.lr = 0x821D3204;
	sub_82060368(ctx, base);
	// stw r30,1512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1512, ctx.r30.u32);
	// stw r31,1508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1508, ctx.r31.u32);
	// addi r4,r29,-68
	ctx.r4.s64 = ctx.r29.s64 + -68;
	// stb r31,1492(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1492, ctx.r31.u8);
	// li r5,29
	ctx.r5.s64 = 29;
	// addi r3,r1,1488
	ctx.r3.s64 = ctx.r1.s64 + 1488;
	// bl 0x82060368
	ctx.lr = 0x821D3220;
	sub_82060368(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1516
	ctx.r3.s64 = ctx.r1.s64 + 1516;
	// bl 0x820602f0
	ctx.lr = 0x821D3230;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1544
	ctx.r3.s64 = ctx.r1.s64 + 1544;
	// bl 0x820602f0
	ctx.lr = 0x821D3240;
	sub_820602F0(ctx, base);
	// stw r27,1572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1572, ctx.r27.u32);
	// stw r31,1576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1576, ctx.r31.u32);
	// addi r4,r29,-36
	ctx.r4.s64 = ctx.r29.s64 + -36;
	// addi r3,r1,1580
	ctx.r3.s64 = ctx.r1.s64 + 1580;
	// bl 0x82060190
	ctx.lr = 0x821D3254;
	sub_82060190(ctx, base);
	// addi r4,r29,-24
	ctx.r4.s64 = ctx.r29.s64 + -24;
	// addi r3,r1,1608
	ctx.r3.s64 = ctx.r1.s64 + 1608;
	// bl 0x82060190
	ctx.lr = 0x821D3260;
	sub_82060190(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,1636
	ctx.r3.s64 = ctx.r1.s64 + 1636;
	// bl 0x82060190
	ctx.lr = 0x821D326C;
	sub_82060190(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1664
	ctx.r3.s64 = ctx.r1.s64 + 1664;
	// bl 0x820602f0
	ctx.lr = 0x821D327C;
	sub_820602F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,1692
	ctx.r3.s64 = ctx.r1.s64 + 1692;
	// bl 0x820602f0
	ctx.lr = 0x821D328C;
	sub_820602F0(ctx, base);
	// addic. r3,r28,132
	ctx.xer.ca = ctx.r28.u32 > 4294967163;
	ctx.r3.s64 = ctx.r28.s64 + 132;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821d32a0
	if (ctx.cr0.eq) goto loc_821D32A0;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ba6a0
	ctx.lr = 0x821D32A0;
	sub_821BA6A0(ctx, base);
loc_821D32A0:
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// bl 0x821bcd20
	ctx.lr = 0x821D32B0;
	sub_821BCD20(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,832
	ctx.r4.s64 = ctx.r1.s64 + 832;
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// bl 0x821bcc50
	ctx.lr = 0x821D32C0;
	sub_821BCC50(ctx, base);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// blt cr6,0x821d32cc
	if (ctx.cr6.lt) goto loc_821D32CC;
	// stw r22,176(r28)
	PPC_STORE_U32(ctx.r28.u32 + 176, ctx.r22.u32);
loc_821D32CC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 4, ctx.xer);
	// blt cr6,0x821d32fc
	if (ctx.cr6.lt) goto loc_821D32FC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821ba280
	ctx.lr = 0x821D32F8;
	sub_821BA280(ctx, base);
	// stw r23,156(r28)
	PPC_STORE_U32(ctx.r28.u32 + 156, ctx.r23.u32);
loc_821D32FC:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r6,r11,19656
	ctx.r6.s64 = ctx.r11.s64 + 19656;
	// li r4,148
	ctx.r4.s64 = 148;
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// bl 0x82060818
	ctx.lr = 0x821D3314;
	sub_82060818(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r6,r10,19288
	ctx.r6.s64 = ctx.r10.s64 + 19288;
	// li r4,88
	ctx.r4.s64 = 88;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82060818
	ctx.lr = 0x821D332C;
	sub_82060818(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r6,r9,24552
	ctx.r6.s64 = ctx.r9.s64 + 24552;
	// li r4,36
	ctx.r4.s64 = 36;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060818
	ctx.lr = 0x821D3344;
	sub_82060818(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,1808
	ctx.r1.s64 = ctx.r1.s64 + 1808;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D3350"))) PPC_WEAK_FUNC(sub_821D3350);
PPC_FUNC_IMPL(__imp__sub_821D3350) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821D3358;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lbz r10,-31360(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + -31360);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821d3468
	if (ctx.cr6.eq) goto loc_821D3468;
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// stb r27,-31360(r11)
	PPC_STORE_U8(ctx.r11.u32 + -31360, ctx.r27.u8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3394
	if (ctx.cr6.eq) goto loc_821D3394;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D3394;
	sub_821BC718(ctx, base);
loc_821D3394:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D339C;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d33cc
	if (ctx.cr6.eq) goto loc_821D33CC;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-9976
	ctx.r4.s64 = ctx.r11.s64 + -9976;
	// bl 0x82060190
	ctx.lr = 0x821D33B8;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,124(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D33C8;
	sub_821BAE98(ctx, base);
	// b 0x821d33d0
	goto loc_821D33D0;
loc_821D33CC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821D33D0:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r9,36(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r31,r28,16
	ctx.r31.s64 = ctx.r28.s64 + 16;
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r28)
	PPC_STORE_U32(ctx.r28.u32 + 36, ctx.r11.u32);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// li r3,1768
	ctx.r3.s64 = 1768;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x821d3420
	if (ctx.cr6.eq) goto loc_821D3420;
	// bl 0x82079fd8
	ctx.lr = 0x821D3408;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d343c
	if (ctx.cr6.eq) goto loc_821D343C;
	// addi r4,r28,168
	ctx.r4.s64 = ctx.r28.s64 + 168;
	// lwz r5,176(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 176);
	// bl 0x821a7e30
	ctx.lr = 0x821D341C;
	sub_821A7E30(ctx, base);
	// b 0x821d3440
	goto loc_821D3440;
loc_821D3420:
	// bl 0x82079fd8
	ctx.lr = 0x821D3424;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d343c
	if (ctx.cr6.eq) goto loc_821D343C;
	// addi r4,r28,168
	ctx.r4.s64 = ctx.r28.s64 + 168;
	// lwz r5,176(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 176);
	// bl 0x821a89d0
	ctx.lr = 0x821D3438;
	sub_821A89D0(ctx, base);
	// b 0x821d3440
	goto loc_821D3440;
loc_821D343C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821D3440:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// addi r10,r11,14936
	ctx.r10.s64 = ctx.r11.s64 + 14936;
	// stw r10,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821D3468:
	// lwz r11,144(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 144);
	// addi r29,r28,132
	ctx.r29.s64 = ctx.r28.s64 + 132;
	// lwz r10,148(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 148);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821d3480
	if (!ctx.cr6.gt) goto loc_821D3480;
	// twi 31,r0,22
loc_821D3480:
	// lwz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// li r27,0
	ctx.r27.s64 = 0;
loc_821D348C:
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821d34a0
	if (!ctx.cr6.gt) goto loc_821D34A0;
	// twi 31,r0,22
loc_821D34A0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821d34b4
	if (ctx.cr6.eq) goto loc_821D34B4;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821d34b8
	if (ctx.cr6.eq) goto loc_821D34B8;
loc_821D34B4:
	// twi 31,r0,22
loc_821D34B8:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x821d3568
	if (!ctx.cr6.lt) goto loc_821D3568;
	// bl 0x82185ab8
	ctx.lr = 0x821D34C4;
	sub_82185AB8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d3500
	if (ctx.cr6.eq) goto loc_821D3500;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821d34f8
	if (!ctx.cr6.eq) goto loc_821D34F8;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_821D34E0:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821d34f0
	if (ctx.cr6.lt) goto loc_821D34F0;
	// twi 31,r0,22
loc_821D34F0:
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x821d3524
	goto loc_821D3524;
loc_821D34F8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821d34e0
	goto loc_821D34E0;
loc_821D3500:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821d3558
	if (!ctx.cr6.eq) goto loc_821D3558;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_821D3510:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821d3520
	if (ctx.cr6.lt) goto loc_821D3520;
	// twi 31,r0,22
loc_821D3520:
	// li r5,0
	ctx.r5.s64 = 0;
loc_821D3524:
	// lwz r4,28(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r3,128(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 128);
	// bl 0x821bb9b0
	ctx.lr = 0x821D3530;
	sub_821BB9B0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821d3560
	if (!ctx.cr6.eq) goto loc_821D3560;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_821D3540:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821d3550
	if (ctx.cr6.lt) goto loc_821D3550;
	// twi 31,r0,22
loc_821D3550:
	// addi r30,r30,36
	ctx.r30.s64 = ctx.r30.s64 + 36;
	// b 0x821d348c
	goto loc_821D348C;
loc_821D3558:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821d3510
	goto loc_821D3510;
loc_821D3560:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821d3540
	goto loc_821D3540;
loc_821D3568:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r10,r11,14920
	ctx.r10.s64 = ctx.r11.s64 + 14920;
	// stw r10,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D357C"))) PPC_WEAK_FUNC(sub_821D357C);
PPC_FUNC_IMPL(__imp__sub_821D357C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D3580"))) PPC_WEAK_FUNC(sub_821D3580);
PPC_FUNC_IMPL(__imp__sub_821D3580) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D3588;
	__savegprlr_28(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,-1
	ctx.r28.s64 = -1;
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// bgt cr6,0x821d3948
	if (ctx.cr6.gt) goto loc_821D3948;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x821d3678
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821D3678;
	// bdzf 4*cr6+eq,0x821d3768
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821D3768;
	// bdzf 4*cr6+eq,0x821d3808
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821D3808;
	// bne cr6,0x821d38a8
	if (!ctx.cr6.eq) goto loc_821D38A8;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d35cc
	if (ctx.cr6.eq) goto loc_821D35CC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D35CC;
	sub_821BC718(ctx, base);
loc_821D35CC:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D35D4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3610
	if (ctx.cr6.eq) goto loc_821D3610;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r11,r11,-9984
	ctx.r11.s64 = ctx.r11.s64 + -9984;
	// addi r4,r11,-40
	ctx.r4.s64 = ctx.r11.s64 + -40;
	// bl 0x82060190
	ctx.lr = 0x821D35F8;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D3608;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d3614
	goto loc_821D3614;
loc_821D3610:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D3614:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,104
	ctx.r3.s64 = 104;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D3634;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3668
	if (ctx.cr6.eq) goto loc_821D3668;
	// lwz r5,184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r11,116(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 116);
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r10,r11,32
	ctx.r10.s64 = ctx.r11.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// bl 0x821b1918
	ctx.lr = 0x821D365C;
	sub_821B1918(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// b 0x821d39ec
	goto loc_821D39EC;
loc_821D3668:
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// b 0x821d39ec
	goto loc_821D39EC;
loc_821D3678:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3690
	if (ctx.cr6.eq) goto loc_821D3690;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D3690;
	sub_821BC718(ctx, base);
loc_821D3690:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D3698;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d36d0
	if (ctx.cr6.eq) goto loc_821D36D0;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-9984
	ctx.r11.s64 = ctx.r11.s64 + -9984;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// bl 0x82060190
	ctx.lr = 0x821D36BC;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D36CC;
	sub_821BAE98(ctx, base);
	// b 0x821d36d4
	goto loc_821D36D4;
loc_821D36D0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D36D4:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// li r3,1768
	ctx.r3.s64 = 1768;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x821d3724
	if (ctx.cr6.eq) goto loc_821D3724;
	// bl 0x82079fd8
	ctx.lr = 0x821D370C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3740
	if (ctx.cr6.eq) goto loc_821D3740;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// bl 0x821a7e30
	ctx.lr = 0x821D3720;
	sub_821A7E30(ctx, base);
	// b 0x821d3744
	goto loc_821D3744;
loc_821D3724:
	// bl 0x82079fd8
	ctx.lr = 0x821D3728;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3740
	if (ctx.cr6.eq) goto loc_821D3740;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// bl 0x821a89d0
	ctx.lr = 0x821D373C;
	sub_821A89D0(ctx, base);
	// b 0x821d3744
	goto loc_821D3744;
loc_821D3740:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D3744:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// addi r10,r11,14936
	ctx.r10.s64 = ctx.r11.s64 + 14936;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// b 0x821d3a04
	goto loc_821D3A04;
loc_821D3768:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3780
	if (ctx.cr6.eq) goto loc_821D3780;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D3780;
	sub_821BC718(ctx, base);
loc_821D3780:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D3788;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d37c4
	if (ctx.cr6.eq) goto loc_821D37C4;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-9984
	ctx.r11.s64 = ctx.r11.s64 + -9984;
	// addi r4,r11,-24
	ctx.r4.s64 = ctx.r11.s64 + -24;
	// bl 0x82060190
	ctx.lr = 0x821D37AC;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D37BC;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d37c8
	goto loc_821D37C8;
loc_821D37C4:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D37C8:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,372
	ctx.r3.s64 = 372;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D37E8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3668
	if (ctx.cr6.eq) goto loc_821D3668;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// bl 0x8219c950
	ctx.lr = 0x821D37FC;
	sub_8219C950(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// b 0x821d39ec
	goto loc_821D39EC;
loc_821D3808:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3820
	if (ctx.cr6.eq) goto loc_821D3820;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D3820;
	sub_821BC718(ctx, base);
loc_821D3820:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D3828;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3864
	if (ctx.cr6.eq) goto loc_821D3864;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-9984
	ctx.r11.s64 = ctx.r11.s64 + -9984;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// bl 0x82060190
	ctx.lr = 0x821D384C;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D385C;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d3868
	goto loc_821D3868;
loc_821D3864:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D3868:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,372
	ctx.r3.s64 = 372;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D3888;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3668
	if (ctx.cr6.eq) goto loc_821D3668;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// bl 0x82199eb8
	ctx.lr = 0x821D389C;
	sub_82199EB8(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// b 0x821d39ec
	goto loc_821D39EC;
loc_821D38A8:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d38c0
	if (ctx.cr6.eq) goto loc_821D38C0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D38C0;
	sub_821BC718(ctx, base);
loc_821D38C0:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D38C8;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3904
	if (ctx.cr6.eq) goto loc_821D3904;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r11,r11,-9984
	ctx.r11.s64 = ctx.r11.s64 + -9984;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x82060190
	ctx.lr = 0x821D38EC;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D38FC;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d3908
	goto loc_821D3908;
loc_821D3904:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D3908:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,308
	ctx.r3.s64 = 308;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D3928;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3668
	if (ctx.cr6.eq) goto loc_821D3668;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// bl 0x8219be60
	ctx.lr = 0x821D393C;
	sub_8219BE60(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,14936
	ctx.r8.s64 = ctx.r9.s64 + 14936;
	// b 0x821d39ec
	goto loc_821D39EC;
loc_821D3948:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3964
	if (ctx.cr6.eq) goto loc_821D3964;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x821bc718
	ctx.lr = 0x821D3964;
	sub_821BC718(ctx, base);
loc_821D3964:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821D396C;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d39a4
	if (ctx.cr6.eq) goto loc_821D39A4;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// addi r4,r11,-9984
	ctx.r4.s64 = ctx.r11.s64 + -9984;
	// bl 0x82060190
	ctx.lr = 0x821D398C;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x821bae98
	ctx.lr = 0x821D399C;
	sub_821BAE98(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821d39a8
	goto loc_821D39A8;
loc_821D39A4:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821D39A8:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,8304
	ctx.r3.s64 = 8304;
	// addi r30,r31,16
	ctx.r30.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821D39C8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d39e0
	if (ctx.cr6.eq) goto loc_821D39E0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187af0
	ctx.lr = 0x821D39DC;
	sub_82187AF0(ctx, base);
	// b 0x821d39e4
	goto loc_821D39E4;
loc_821D39E0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821D39E4:
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,23160
	ctx.r8.s64 = ctx.r9.s64 + 23160;
loc_821D39EC:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
loc_821D3A04:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821d3a14
	if (ctx.cr6.eq) goto loc_821D3A14;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_821D3A14:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D3A1C"))) PPC_WEAK_FUNC(sub_821D3A1C);
PPC_FUNC_IMPL(__imp__sub_821D3A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D3A20"))) PPC_WEAK_FUNC(sub_821D3A20);
PPC_FUNC_IMPL(__imp__sub_821D3A20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821D3A28;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r26,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r26.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// sth r26,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r26.u16);
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821d3b0c
	if (ctx.cr6.eq) goto loc_821D3B0C;
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// addi r28,r4,4
	ctx.r28.s64 = ctx.r4.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d3a6c
	if (ctx.cr6.lt) goto loc_821D3A6C;
	// lwz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x821d3a70
	goto loc_821D3A70;
loc_821D3A6C:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
loc_821D3A70:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x8208a5b0
	ctx.lr = 0x821D3A8C;
	sub_8208A5B0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3b0c
	if (ctx.cr6.eq) goto loc_821D3B0C;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// ori r10,r11,65535
	ctx.r10.u64 = ctx.r11.u64 | 65535;
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x821d3ab0
	if (!ctx.cr6.gt) goto loc_821D3AB0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_821D3AB0:
	// bl 0x8207a030
	ctx.lr = 0x821D3AB4;
	sub_8207A030(ctx, base);
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d3acc
	if (ctx.cr6.lt) goto loc_821D3ACC;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// b 0x821d3ad0
	goto loc_821D3AD0;
loc_821D3ACC:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
loc_821D3AD0:
	// lis r3,0
	ctx.r3.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x8208a5b0
	ctx.lr = 0x821D3AEC;
	sub_8208A5B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207adf0
	ctx.lr = 0x821D3AF4;
	sub_8207ADF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8206a848
	ctx.lr = 0x821D3B04;
	sub_8206A848(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x821D3B0C;
	sub_8207A8A0(ctx, base);
loc_821D3B0C:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d3b20
	if (ctx.cr6.lt) goto loc_821D3B20;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821D3B20;
	sub_8207A630(ctx, base);
loc_821D3B20:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r26,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// stb r26,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D3B3C"))) PPC_WEAK_FUNC(sub_821D3B3C);
PPC_FUNC_IMPL(__imp__sub_821D3B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D3B40"))) PPC_WEAK_FUNC(sub_821D3B40);
PPC_FUNC_IMPL(__imp__sub_821D3B40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821D3B48;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r26,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r26.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stb r26,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r26.u8);
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821d3c38
	if (ctx.cr6.eq) goto loc_821D3C38;
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// addi r28,r4,4
	ctx.r28.s64 = ctx.r4.s64 + 4;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x821d3b8c
	if (ctx.cr6.lt) goto loc_821D3B8C;
	// lwz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x821d3b90
	goto loc_821D3B90;
loc_821D3B8C:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
loc_821D3B90:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x8208a4f0
	ctx.lr = 0x821D3BB4;
	sub_8208A4F0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3c38
	if (ctx.cr6.eq) goto loc_821D3C38;
	// bl 0x8207a030
	ctx.lr = 0x821D3BC4;
	sub_8207A030(ctx, base);
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x821d3bdc
	if (ctx.cr6.lt) goto loc_821D3BDC;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// b 0x821d3be0
	goto loc_821D3BE0;
loc_821D3BDC:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
loc_821D3BE0:
	// lis r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,65001
	ctx.r3.u64 = ctx.r3.u64 | 65001;
	// bl 0x8208a4f0
	ctx.lr = 0x821D3C04;
	sub_8208A4F0(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_821D3C08:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821d3c08
	if (!ctx.cr6.eq) goto loc_821D3C08;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821D3C30;
	sub_82060368(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x821D3C38;
	sub_8207A8A0(ctx, base);
loc_821D3C38:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x821d3c4c
	if (ctx.cr6.lt) goto loc_821D3C4C;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821D3C4C;
	sub_8207A630(ctx, base);
loc_821D3C4C:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r26,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// sth r26,4(r30)
	PPC_STORE_U16(ctx.r30.u32 + 4, ctx.r26.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D3C68"))) PPC_WEAK_FUNC(sub_821D3C68);
PPC_FUNC_IMPL(__imp__sub_821D3C68) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// std r31,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r31.u64);
	// lfs f0,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stw r31,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r31.u32);
	// lfs f13,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8216ef48
	ctx.lr = 0x821D3CB0;
	sub_8216EF48(ctx, base);
	// li r3,156
	ctx.r3.s64 = 156;
	// bl 0x82079fd8
	ctx.lr = 0x821D3CB8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d3cd0
	if (ctx.cr6.eq) goto loc_821D3CD0;
	// bl 0x82170880
	ctx.lr = 0x821D3CC4;
	sub_82170880(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,-31328(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31328, ctx.r3.u32);
	// b 0x821d3cdc
	goto loc_821D3CDC;
loc_821D3CD0:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stw r31,-31328(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31328, ctx.r31.u32);
loc_821D3CDC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,-31308(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31308);
	// bl 0x8216c550
	ctx.lr = 0x821D3CE8;
	sub_8216C550(ctx, base);
	// bl 0x82165a68
	ctx.lr = 0x821D3CEC;
	sub_82165A68(ctx, base);
	// bl 0x82167e58
	ctx.lr = 0x821D3CF0;
	sub_82167E58(ctx, base);
	// bl 0x821ce720
	ctx.lr = 0x821D3CF4;
	sub_821CE720(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_821D3D0C"))) PPC_WEAK_FUNC(sub_821D3D0C);
PPC_FUNC_IMPL(__imp__sub_821D3D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D3D10"))) PPC_WEAK_FUNC(sub_821D3D10);
PPC_FUNC_IMPL(__imp__sub_821D3D10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821D3D18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r29,r11,-2580
	ctx.r29.s64 = ctx.r11.s64 + -2580;
	// addi r31,r10,-13448
	ctx.r31.s64 = ctx.r10.s64 + -13448;
	// addi r4,r29,152
	ctx.r4.s64 = ctx.r29.s64 + 152;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x82060368
	ctx.lr = 0x821D3D3C;
	sub_82060368(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// addi r4,r29,132
	ctx.r4.s64 = ctx.r29.s64 + 132;
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// addi r11,r31,36
	ctx.r11.s64 = ctx.r31.s64 + 36;
	// bl 0x82060368
	ctx.lr = 0x821D3D8C;
	sub_82060368(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// addi r4,r29,112
	ctx.r4.s64 = ctx.r29.s64 + 112;
	// std r30,88(r31)
	PPC_STORE_U64(ctx.r31.u32 + 88, ctx.r30.u64);
	// li r5,17
	ctx.r5.s64 = 17;
	// std r30,96(r31)
	PPC_STORE_U64(ctx.r31.u32 + 96, ctx.r30.u64);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// addi r3,r31,104
	ctx.r3.s64 = ctx.r31.s64 + 104;
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stb r30,108(r31)
	PPC_STORE_U8(ctx.r31.u32 + 108, ctx.r30.u8);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r11,r31,88
	ctx.r11.s64 = ctx.r31.s64 + 88;
	// bl 0x82060368
	ctx.lr = 0x821D3DD0;
	sub_82060368(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// addi r4,r29,92
	ctx.r4.s64 = ctx.r29.s64 + 92;
	// stw r30,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
	// li r5,17
	ctx.r5.s64 = 17;
	// stw r30,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// addi r3,r31,156
	ctx.r3.s64 = ctx.r31.s64 + 156;
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r30,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r30.u32);
	// addi r11,r31,140
	ctx.r11.s64 = ctx.r31.s64 + 140;
	// stb r30,160(r31)
	PPC_STORE_U8(ctx.r31.u32 + 160, ctx.r30.u8);
	// bl 0x82060368
	ctx.lr = 0x821D3E1C;
	sub_82060368(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r10,188(r31)
	PPC_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// std r30,192(r31)
	PPC_STORE_U64(ctx.r31.u32 + 192, ctx.r30.u64);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// std r30,200(r31)
	PPC_STORE_U64(ctx.r31.u32 + 200, ctx.r30.u64);
	// stw r11,232(r31)
	PPC_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// addi r4,r29,72
	ctx.r4.s64 = ctx.r29.s64 + 72;
	// stw r30,228(r31)
	PPC_STORE_U32(ctx.r31.u32 + 228, ctx.r30.u32);
	// stb r30,212(r31)
	PPC_STORE_U8(ctx.r31.u32 + 212, ctx.r30.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r3,r31,208
	ctx.r3.s64 = ctx.r31.s64 + 208;
	// addi r11,r31,192
	ctx.r11.s64 = ctx.r31.s64 + 192;
	// bl 0x82060368
	ctx.lr = 0x821D3E60;
	sub_82060368(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,236(r31)
	PPC_STORE_U32(ctx.r31.u32 + 236, ctx.r11.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r10,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r10.u32);
	// addi r4,r29,48
	ctx.r4.s64 = ctx.r29.s64 + 48;
	// stw r30,244(r31)
	PPC_STORE_U32(ctx.r31.u32 + 244, ctx.r30.u32);
	// li r5,21
	ctx.r5.s64 = 21;
	// stw r30,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// addi r3,r31,260
	ctx.r3.s64 = ctx.r31.s64 + 260;
	// stw r30,252(r31)
	PPC_STORE_U32(ctx.r31.u32 + 252, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r30,256(r31)
	PPC_STORE_U32(ctx.r31.u32 + 256, ctx.r30.u32);
	// stw r11,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r11.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r30,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r30.u32);
	// addi r11,r31,244
	ctx.r11.s64 = ctx.r31.s64 + 244;
	// stb r30,264(r31)
	PPC_STORE_U8(ctx.r31.u32 + 264, ctx.r30.u8);
	// bl 0x82060368
	ctx.lr = 0x821D3EAC;
	sub_82060368(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r10,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r10.u32);
	// addi r4,r29,24
	ctx.r4.s64 = ctx.r29.s64 + 24;
	// std r30,296(r31)
	PPC_STORE_U64(ctx.r31.u32 + 296, ctx.r30.u64);
	// li r5,21
	ctx.r5.s64 = 21;
	// std r30,304(r31)
	PPC_STORE_U64(ctx.r31.u32 + 304, ctx.r30.u64);
	// stw r11,336(r31)
	PPC_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// addi r3,r31,312
	ctx.r3.s64 = ctx.r31.s64 + 312;
	// stw r30,332(r31)
	PPC_STORE_U32(ctx.r31.u32 + 332, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stb r30,316(r31)
	PPC_STORE_U8(ctx.r31.u32 + 316, ctx.r30.u8);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r11,r31,296
	ctx.r11.s64 = ctx.r31.s64 + 296;
	// bl 0x82060368
	ctx.lr = 0x821D3EF0;
	sub_82060368(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,340(r31)
	PPC_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r10,344(r31)
	PPC_STORE_U32(ctx.r31.u32 + 344, ctx.r10.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r30,348(r31)
	PPC_STORE_U32(ctx.r31.u32 + 348, ctx.r30.u32);
	// li r5,22
	ctx.r5.s64 = 22;
	// stw r30,352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 352, ctx.r30.u32);
	// addi r3,r31,364
	ctx.r3.s64 = ctx.r31.s64 + 364;
	// stw r30,356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 356, ctx.r30.u32);
	// addi r11,r31,348
	ctx.r11.s64 = ctx.r31.s64 + 348;
	// stw r30,360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 360, ctx.r30.u32);
	// stw r10,388(r31)
	PPC_STORE_U32(ctx.r31.u32 + 388, ctx.r10.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stb r30,368(r31)
	PPC_STORE_U8(ctx.r31.u32 + 368, ctx.r30.u8);
	// bl 0x82060368
	ctx.lr = 0x821D3F3C;
	sub_82060368(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stw r10,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r10.u32);
	// addi r11,r31,400
	ctx.r11.s64 = ctx.r31.s64 + 400;
	// std r30,400(r31)
	PPC_STORE_U64(ctx.r31.u32 + 400, ctx.r30.u64);
	// addi r3,r9,18240
	ctx.r3.s64 = ctx.r9.s64 + 18240;
	// std r30,408(r31)
	PPC_STORE_U64(ctx.r31.u32 + 408, ctx.r30.u64);
	// bl 0x8207a878
	ctx.lr = 0x821D3F64;
	sub_8207A878(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D3F6C"))) PPC_WEAK_FUNC(sub_821D3F6C);
PPC_FUNC_IMPL(__imp__sub_821D3F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D3F70"))) PPC_WEAK_FUNC(sub_821D3F70);
PPC_FUNC_IMPL(__imp__sub_821D3F70) {
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
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821D3F84;
	sub_82079FD8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,-31232
	ctx.r11.s64 = ctx.r11.s64 + -31232;
	// beq cr6,0x821d3fa0
	if (ctx.cr6.eq) goto loc_821D3FA0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// b 0x821d3fa8
	goto loc_821D3FA8;
loc_821D3FA0:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821D3FA8:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// addi r3,r10,20504
	ctx.r3.s64 = ctx.r10.s64 + 20504;
	// bl 0x8207a878
	ctx.lr = 0x821D3FCC;
	sub_8207A878(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D3FDC"))) PPC_WEAK_FUNC(sub_821D3FDC);
PPC_FUNC_IMPL(__imp__sub_821D3FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D3FE0"))) PPC_WEAK_FUNC(sub_821D3FE0);
PPC_FUNC_IMPL(__imp__sub_821D3FE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D3FE8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r30,r11,29807
	ctx.r30.s64 = ctx.r11.s64 + 29807;
	// addi r31,r10,-12704
	ctx.r31.s64 = ctx.r10.s64 + -12704;
	// addi r4,r30,13801
	ctx.r4.s64 = ctx.r30.s64 + 13801;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// bl 0x82060368
	ctx.lr = 0x821D400C;
	sub_82060368(ctx, base);
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// addi r4,r30,13793
	ctx.r4.s64 = ctx.r30.s64 + 13793;
	// stb r9,32(r31)
	PPC_STORE_U8(ctx.r31.u32 + 32, ctx.r9.u8);
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r3,r31,28
	ctx.r3.s64 = ctx.r31.s64 + 28;
	// bl 0x82060368
	ctx.lr = 0x821D4034;
	sub_82060368(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r11,640
	ctx.r11.s64 = 640;
	// li r10,480
	ctx.r10.s64 = 480;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r10,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// li r11,-1
	ctx.r11.s64 = -1;
	// lfs f0,21768(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f0,80(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stfs f0,84(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// li r6,15
	ctx.r6.s64 = 15;
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// stb r10,72(r31)
	PPC_STORE_U8(ctx.r31.u32 + 72, ctx.r10.u8);
	// stb r8,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r8.u8);
	// addi r4,r30,13789
	ctx.r4.s64 = ctx.r30.s64 + 13789;
	// stw r7,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r7.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r6,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r6.u32);
	// addi r3,r31,88
	ctx.r3.s64 = ctx.r31.s64 + 88;
	// stw r29,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
	// stb r28,92(r31)
	PPC_STORE_U8(ctx.r31.u32 + 92, ctx.r28.u8);
	// bl 0x82060368
	ctx.lr = 0x821D40A4;
	sub_82060368(ctx, base);
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stb r9,120(r31)
	PPC_STORE_U8(ctx.r31.u32 + 120, ctx.r9.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,116
	ctx.r3.s64 = ctx.r31.s64 + 116;
	// bl 0x82060368
	ctx.lr = 0x821D40CC;
	sub_82060368(ctx, base);
	// lis r5,-32227
	ctx.r5.s64 = -2112028672;
	// addi r3,r5,20600
	ctx.r3.s64 = ctx.r5.s64 + 20600;
	// bl 0x8207a878
	ctx.lr = 0x821D40D8;
	sub_8207A878(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D40E0"))) PPC_WEAK_FUNC(sub_821D40E0);
PPC_FUNC_IMPL(__imp__sub_821D40E0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,20616
	ctx.r3.s64 = ctx.r11.s64 + 20616;
	// b 0x8207a878
	sub_8207A878(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D40EC"))) PPC_WEAK_FUNC(sub_821D40EC);
PPC_FUNC_IMPL(__imp__sub_821D40EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D40F0"))) PPC_WEAK_FUNC(sub_821D40F0);
PPC_FUNC_IMPL(__imp__sub_821D40F0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r10,-31136
	ctx.r8.s64 = ctx.r10.s64 + -31136;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r11.u32);
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r11.u32);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4120"))) PPC_WEAK_FUNC(sub_821D4120);
PPC_FUNC_IMPL(__imp__sub_821D4120) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r3,r11,-31080
	ctx.r3.s64 = ctx.r11.s64 + -31080;
	// bl 0x820760a0
	ctx.lr = 0x821D4138;
	sub_820760A0(ctx, base);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r3,r10,20632
	ctx.r3.s64 = ctx.r10.s64 + 20632;
	// bl 0x8207a878
	ctx.lr = 0x821D4144;
	sub_8207A878(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4154"))) PPC_WEAK_FUNC(sub_821D4154);
PPC_FUNC_IMPL(__imp__sub_821D4154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4158"))) PPC_WEAK_FUNC(sub_821D4158);
PPC_FUNC_IMPL(__imp__sub_821D4158) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r3,r11,-31112
	ctx.r3.s64 = ctx.r11.s64 + -31112;
	// bl 0x820760a0
	ctx.lr = 0x821D4170;
	sub_820760A0(ctx, base);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r3,r10,20648
	ctx.r3.s64 = ctx.r10.s64 + 20648;
	// bl 0x8207a878
	ctx.lr = 0x821D417C;
	sub_8207A878(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D418C"))) PPC_WEAK_FUNC(sub_821D418C);
PPC_FUNC_IMPL(__imp__sub_821D418C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4190"))) PPC_WEAK_FUNC(sub_821D4190);
PPC_FUNC_IMPL(__imp__sub_821D4190) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,20664
	ctx.r3.s64 = ctx.r11.s64 + 20664;
	// b 0x8207a878
	sub_8207A878(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D419C"))) PPC_WEAK_FUNC(sub_821D419C);
PPC_FUNC_IMPL(__imp__sub_821D419C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D41A0"))) PPC_WEAK_FUNC(sub_821D41A0);
PPC_FUNC_IMPL(__imp__sub_821D41A0) {
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
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821D41B4;
	sub_82079FD8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,-31048
	ctx.r11.s64 = ctx.r11.s64 + -31048;
	// beq cr6,0x821d41d0
	if (ctx.cr6.eq) goto loc_821D41D0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// b 0x821d41d8
	goto loc_821D41D8;
loc_821D41D0:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821D41D8:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// addi r3,r10,20752
	ctx.r3.s64 = ctx.r10.s64 + 20752;
	// bl 0x8207a878
	ctx.lr = 0x821D41FC;
	sub_8207A878(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D420C"))) PPC_WEAK_FUNC(sub_821D420C);
PPC_FUNC_IMPL(__imp__sub_821D420C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4210"))) PPC_WEAK_FUNC(sub_821D4210);
PPC_FUNC_IMPL(__imp__sub_821D4210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f0,14160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5856(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -5856, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4224"))) PPC_WEAK_FUNC(sub_821D4224);
PPC_FUNC_IMPL(__imp__sub_821D4224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4228"))) PPC_WEAK_FUNC(sub_821D4228);
PPC_FUNC_IMPL(__imp__sub_821D4228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-5848
	ctx.r9.s64 = ctx.r11.s64 + -5848;
	// lfs f0,14160(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4240"))) PPC_WEAK_FUNC(sub_821D4240);
PPC_FUNC_IMPL(__imp__sub_821D4240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f0,14160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,14164(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 14164, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4254"))) PPC_WEAK_FUNC(sub_821D4254);
PPC_FUNC_IMPL(__imp__sub_821D4254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4258"))) PPC_WEAK_FUNC(sub_821D4258);
PPC_FUNC_IMPL(__imp__sub_821D4258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r8,r9,-5840
	ctx.r8.s64 = ctx.r9.s64 + -5840;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14160);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D427C"))) PPC_WEAK_FUNC(sub_821D427C);
PPC_FUNC_IMPL(__imp__sub_821D427C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4280"))) PPC_WEAK_FUNC(sub_821D4280);
PPC_FUNC_IMPL(__imp__sub_821D4280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14160);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,14172(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 14172, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D42A0"))) PPC_WEAK_FUNC(sub_821D42A0);
PPC_FUNC_IMPL(__imp__sub_821D42A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r8,r9,14180
	ctx.r8.s64 = ctx.r9.s64 + 14180;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14160);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,4(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D42C4"))) PPC_WEAK_FUNC(sub_821D42C4);
PPC_FUNC_IMPL(__imp__sub_821D42C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D42C8"))) PPC_WEAK_FUNC(sub_821D42C8);
PPC_FUNC_IMPL(__imp__sub_821D42C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14160);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,-5832(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -5832, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D42E8"))) PPC_WEAK_FUNC(sub_821D42E8);
PPC_FUNC_IMPL(__imp__sub_821D42E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,14188
	ctx.r9.s64 = ctx.r11.s64 + 14188;
	// lfs f0,14160(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4300"))) PPC_WEAK_FUNC(sub_821D4300);
PPC_FUNC_IMPL(__imp__sub_821D4300) {
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
	// li r5,504
	ctx.r5.s64 = 504;
	// addi r31,r11,14512
	ctx.r31.s64 = ctx.r11.s64 + 14512;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x8207da20
	ctx.lr = 0x821D4328;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D433C;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D434C;
	sub_8207DA20(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D4390"))) PPC_WEAK_FUNC(sub_821D4390);
PPC_FUNC_IMPL(__imp__sub_821D4390) {
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
	// li r5,502
	ctx.r5.s64 = 502;
	// addi r31,r11,15584
	ctx.r31.s64 = ctx.r11.s64 + 15584;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,26
	ctx.r3.s64 = ctx.r31.s64 + 26;
	// bl 0x8207da20
	ctx.lr = 0x821D43B8;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D43CC;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D43DC;
	sub_8207DA20(ctx, base);
	// li r11,11
	ctx.r11.s64 = 11;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D4420"))) PPC_WEAK_FUNC(sub_821D4420);
PPC_FUNC_IMPL(__imp__sub_821D4420) {
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
	// li r5,498
	ctx.r5.s64 = 498;
	// addi r31,r11,16656
	ctx.r31.s64 = ctx.r11.s64 + 16656;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,30
	ctx.r3.s64 = ctx.r31.s64 + 30;
	// bl 0x8207da20
	ctx.lr = 0x821D4448;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D445C;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D446C;
	sub_8207DA20(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,63
	ctx.r9.s64 = 63;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D44B0"))) PPC_WEAK_FUNC(sub_821D44B0);
PPC_FUNC_IMPL(__imp__sub_821D44B0) {
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
	// li r5,480
	ctx.r5.s64 = 480;
	// addi r31,r11,17728
	ctx.r31.s64 = ctx.r11.s64 + 17728;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x8207da20
	ctx.lr = 0x821D44D8;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D44EC;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D44FC;
	sub_8207DA20(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D4540"))) PPC_WEAK_FUNC(sub_821D4540);
PPC_FUNC_IMPL(__imp__sub_821D4540) {
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
	// li r5,484
	ctx.r5.s64 = 484;
	// addi r31,r11,18800
	ctx.r31.s64 = ctx.r11.s64 + 18800;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// bl 0x8207da20
	ctx.lr = 0x821D4568;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D457C;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D458C;
	sub_8207DA20(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,11
	ctx.r9.s64 = 11;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D45D0"))) PPC_WEAK_FUNC(sub_821D45D0);
PPC_FUNC_IMPL(__imp__sub_821D45D0) {
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
	// li r5,488
	ctx.r5.s64 = 488;
	// addi r31,r11,19872
	ctx.r31.s64 = ctx.r11.s64 + 19872;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x8207da20
	ctx.lr = 0x821D45F8;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D460C;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D461C;
	sub_8207DA20(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,63
	ctx.r9.s64 = 63;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D4660"))) PPC_WEAK_FUNC(sub_821D4660);
PPC_FUNC_IMPL(__imp__sub_821D4660) {
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
	// li r5,498
	ctx.r5.s64 = 498;
	// addi r31,r11,20944
	ctx.r31.s64 = ctx.r11.s64 + 20944;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,30
	ctx.r3.s64 = ctx.r31.s64 + 30;
	// bl 0x8207da20
	ctx.lr = 0x821D4688;
	sub_8207DA20(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r31,528
	ctx.r3.s64 = ctx.r31.s64 + 528;
	// addi r4,r11,26376
	ctx.r4.s64 = ctx.r11.s64 + 26376;
	// li r5,72
	ctx.r5.s64 = 72;
	// bl 0x8207dac0
	ctx.lr = 0x821D469C;
	sub_8207DAC0(ctx, base);
	// li r5,440
	ctx.r5.s64 = 440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,600
	ctx.r3.s64 = ctx.r31.s64 + 600;
	// bl 0x8207da20
	ctx.lr = 0x821D46AC;
	sub_8207DA20(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,30
	ctx.r9.s64 = 30;
	// stw r10,1044(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1044, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,1048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1048, ctx.r9.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,1040(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1040, ctx.r11.u32);
	// stw r11,1052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1052, ctx.r11.u32);
	// stw r10,1056(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1056, ctx.r10.u32);
	// stw r9,1060(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1060, ctx.r9.u32);
	// stw r11,1064(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1064, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821D46F0"))) PPC_WEAK_FUNC(sub_821D46F0);
PPC_FUNC_IMPL(__imp__sub_821D46F0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r3,r11,-32400
	ctx.r3.s64 = ctx.r11.s64 + -32400;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8207da20
	sub_8207DA20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4704"))) PPC_WEAK_FUNC(sub_821D4704);
PPC_FUNC_IMPL(__imp__sub_821D4704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4708"))) PPC_WEAK_FUNC(sub_821D4708);
PPC_FUNC_IMPL(__imp__sub_821D4708) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,-15652
	ctx.r11.s64 = ctx.r11.s64 + -15652;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// bl 0x821d53a4
	ctx.lr = 0x821D4724;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r3,r11,20848
	ctx.r3.s64 = ctx.r11.s64 + 20848;
	// bl 0x8207a878
	ctx.lr = 0x821D4730;
	sub_8207A878(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821D4740"))) PPC_WEAK_FUNC(sub_821D4740);
PPC_FUNC_IMPL(__imp__sub_821D4740) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4748;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r11,r11,-13448
	ctx.r11.s64 = ctx.r11.s64 + -13448;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,420
	ctx.r31.s64 = ctx.r11.s64 + 420;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4764:
	// addi r31,r31,-52
	ctx.r31.s64 = ctx.r31.s64 + -52;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d477c
	if (ctx.cr6.lt) goto loc_821D477C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D477C;
	sub_8207A630(ctx, base);
loc_821D477C:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4764
	if (!ctx.cr0.lt) goto loc_821D4764;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4798"))) PPC_WEAK_FUNC(sub_821D4798);
PPC_FUNC_IMPL(__imp__sub_821D4798) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D47A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-30984
	ctx.r11.s64 = ctx.r11.s64 + -30984;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,168
	ctx.r31.s64 = ctx.r11.s64 + 168;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D47BC:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d47d4
	if (ctx.cr6.lt) goto loc_821D47D4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D47D4;
	sub_8207A630(ctx, base);
loc_821D47D4:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d47bc
	if (!ctx.cr0.lt) goto loc_821D47BC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D47F0"))) PPC_WEAK_FUNC(sub_821D47F0);
PPC_FUNC_IMPL(__imp__sub_821D47F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D47F8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-30824
	ctx.r11.s64 = ctx.r11.s64 + -30824;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,168
	ctx.r31.s64 = ctx.r11.s64 + 168;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4814:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d482c
	if (ctx.cr6.lt) goto loc_821D482C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D482C;
	sub_8207A630(ctx, base);
loc_821D482C:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4814
	if (!ctx.cr0.lt) goto loc_821D4814;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4848"))) PPC_WEAK_FUNC(sub_821D4848);
PPC_FUNC_IMPL(__imp__sub_821D4848) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4850;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,-30664
	ctx.r11.s64 = ctx.r11.s64 + -30664;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,328
	ctx.r31.s64 = ctx.r11.s64 + 328;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D486C:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4884
	if (ctx.cr6.lt) goto loc_821D4884;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4884;
	sub_8207A630(ctx, base);
loc_821D4884:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d486c
	if (!ctx.cr0.lt) goto loc_821D486C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D48A0"))) PPC_WEAK_FUNC(sub_821D48A0);
PPC_FUNC_IMPL(__imp__sub_821D48A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D48A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,12
	ctx.r30.s64 = 12;
	// addi r11,r11,-30344
	ctx.r11.s64 = ctx.r11.s64 + -30344;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,424
	ctx.r31.s64 = ctx.r11.s64 + 424;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D48C4:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d48dc
	if (ctx.cr6.lt) goto loc_821D48DC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D48DC;
	sub_8207A630(ctx, base);
loc_821D48DC:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d48c4
	if (!ctx.cr0.lt) goto loc_821D48C4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D48F8"))) PPC_WEAK_FUNC(sub_821D48F8);
PPC_FUNC_IMPL(__imp__sub_821D48F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4900;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,3
	ctx.r29.s64 = 3;
	// addi r11,r11,-26984
	ctx.r11.s64 = ctx.r11.s64 + -26984;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,388
	ctx.r31.s64 = ctx.r11.s64 + 388;
	// li r28,15
	ctx.r28.s64 = 15;
loc_821D491C:
	// lwzu r3,-80(r31)
	ea = -80 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d4938
	if (ctx.cr6.eq) goto loc_821D4938;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82066ab0
	ctx.lr = 0x821D4930;
	sub_82066AB0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4938;
	sub_8207A630(ctx, base);
loc_821D4938:
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// bl 0x8207a630
	ctx.lr = 0x821D494C;
	sub_8207A630(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4960
	if (ctx.cr6.lt) goto loc_821D4960;
	// lwz r3,-64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// bl 0x8207a630
	ctx.lr = 0x821D4960;
	sub_8207A630(ctx, base);
loc_821D4960:
	// stw r28,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,-48(r31)
	PPC_STORE_U32(ctx.r31.u32 + -48, ctx.r30.u32);
	// stb r30,-64(r31)
	PPC_STORE_U8(ctx.r31.u32 + -64, ctx.r30.u8);
	// bge 0x821d491c
	if (!ctx.cr0.lt) goto loc_821D491C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D497C"))) PPC_WEAK_FUNC(sub_821D497C);
PPC_FUNC_IMPL(__imp__sub_821D497C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4980"))) PPC_WEAK_FUNC(sub_821D4980);
PPC_FUNC_IMPL(__imp__sub_821D4980) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4988;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-25464
	ctx.r11.s64 = ctx.r11.s64 + -25464;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,168
	ctx.r31.s64 = ctx.r11.s64 + 168;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D49A4:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d49bc
	if (ctx.cr6.lt) goto loc_821D49BC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D49BC;
	sub_8207A630(ctx, base);
loc_821D49BC:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d49a4
	if (!ctx.cr0.lt) goto loc_821D49A4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D49D8"))) PPC_WEAK_FUNC(sub_821D49D8);
PPC_FUNC_IMPL(__imp__sub_821D49D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D49E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,4
	ctx.r30.s64 = 4;
	// addi r11,r11,-25304
	ctx.r11.s64 = ctx.r11.s64 + -25304;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,168
	ctx.r31.s64 = ctx.r11.s64 + 168;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D49FC:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4a14
	if (ctx.cr6.lt) goto loc_821D4A14;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4A14;
	sub_8207A630(ctx, base);
loc_821D4A14:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d49fc
	if (!ctx.cr0.lt) goto loc_821D49FC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4A30"))) PPC_WEAK_FUNC(sub_821D4A30);
PPC_FUNC_IMPL(__imp__sub_821D4A30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4A38;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,13
	ctx.r30.s64 = 13;
	// addi r11,r11,-25144
	ctx.r11.s64 = ctx.r11.s64 + -25144;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,456
	ctx.r31.s64 = ctx.r11.s64 + 456;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4A54:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4a6c
	if (ctx.cr6.lt) goto loc_821D4A6C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4A6C;
	sub_8207A630(ctx, base);
loc_821D4A6C:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4a54
	if (!ctx.cr0.lt) goto loc_821D4A54;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4A88"))) PPC_WEAK_FUNC(sub_821D4A88);
PPC_FUNC_IMPL(__imp__sub_821D4A88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4A90;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,17
	ctx.r30.s64 = 17;
	// addi r11,r11,-24696
	ctx.r11.s64 = ctx.r11.s64 + -24696;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,584
	ctx.r31.s64 = ctx.r11.s64 + 584;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4AAC:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4ac4
	if (ctx.cr6.lt) goto loc_821D4AC4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4AC4;
	sub_8207A630(ctx, base);
loc_821D4AC4:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4aac
	if (!ctx.cr0.lt) goto loc_821D4AAC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4AE0"))) PPC_WEAK_FUNC(sub_821D4AE0);
PPC_FUNC_IMPL(__imp__sub_821D4AE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4AE8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,-24120
	ctx.r11.s64 = ctx.r11.s64 + -24120;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,328
	ctx.r31.s64 = ctx.r11.s64 + 328;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4B04:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4b1c
	if (ctx.cr6.lt) goto loc_821D4B1C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4B1C;
	sub_8207A630(ctx, base);
loc_821D4B1C:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4b04
	if (!ctx.cr0.lt) goto loc_821D4B04;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4B38"))) PPC_WEAK_FUNC(sub_821D4B38);
PPC_FUNC_IMPL(__imp__sub_821D4B38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4B40;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,12
	ctx.r30.s64 = 12;
	// addi r11,r11,-23800
	ctx.r11.s64 = ctx.r11.s64 + -23800;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,424
	ctx.r31.s64 = ctx.r11.s64 + 424;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4B5C:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4b74
	if (ctx.cr6.lt) goto loc_821D4B74;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4B74;
	sub_8207A630(ctx, base);
loc_821D4B74:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4b5c
	if (!ctx.cr0.lt) goto loc_821D4B5C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4B90"))) PPC_WEAK_FUNC(sub_821D4B90);
PPC_FUNC_IMPL(__imp__sub_821D4B90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4B98;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,8
	ctx.r30.s64 = 8;
	// addi r11,r11,-28824
	ctx.r11.s64 = ctx.r11.s64 + -28824;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,296
	ctx.r31.s64 = ctx.r11.s64 + 296;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4BB4:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4bcc
	if (ctx.cr6.lt) goto loc_821D4BCC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4BCC;
	sub_8207A630(ctx, base);
loc_821D4BCC:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4bb4
	if (!ctx.cr0.lt) goto loc_821D4BB4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4BE8"))) PPC_WEAK_FUNC(sub_821D4BE8);
PPC_FUNC_IMPL(__imp__sub_821D4BE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4BF0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,17
	ctx.r30.s64 = 17;
	// addi r11,r11,-28536
	ctx.r11.s64 = ctx.r11.s64 + -28536;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,584
	ctx.r31.s64 = ctx.r11.s64 + 584;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4C0C:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4c24
	if (ctx.cr6.lt) goto loc_821D4C24;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4C24;
	sub_8207A630(ctx, base);
loc_821D4C24:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4c0c
	if (!ctx.cr0.lt) goto loc_821D4C0C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4C40"))) PPC_WEAK_FUNC(sub_821D4C40);
PPC_FUNC_IMPL(__imp__sub_821D4C40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4C48;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,5
	ctx.r30.s64 = 5;
	// addi r11,r11,-26656
	ctx.r11.s64 = ctx.r11.s64 + -26656;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,200
	ctx.r31.s64 = ctx.r11.s64 + 200;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4C64:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4c7c
	if (ctx.cr6.lt) goto loc_821D4C7C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4C7C;
	sub_8207A630(ctx, base);
loc_821D4C7C:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4c64
	if (!ctx.cr0.lt) goto loc_821D4C64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4C98"))) PPC_WEAK_FUNC(sub_821D4C98);
PPC_FUNC_IMPL(__imp__sub_821D4C98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4CA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,20
	ctx.r30.s64 = 20;
	// addi r11,r11,-26464
	ctx.r11.s64 = ctx.r11.s64 + -26464;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,680
	ctx.r31.s64 = ctx.r11.s64 + 680;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4CBC:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4cd4
	if (ctx.cr6.lt) goto loc_821D4CD4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4CD4;
	sub_8207A630(ctx, base);
loc_821D4CD4:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4cbc
	if (!ctx.cr0.lt) goto loc_821D4CBC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4CF0"))) PPC_WEAK_FUNC(sub_821D4CF0);
PPC_FUNC_IMPL(__imp__sub_821D4CF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4CF8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,-25792
	ctx.r11.s64 = ctx.r11.s64 + -25792;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,328
	ctx.r31.s64 = ctx.r11.s64 + 328;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4D14:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4d2c
	if (ctx.cr6.lt) goto loc_821D4D2C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4D2C;
	sub_8207A630(ctx, base);
loc_821D4D2C:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4d14
	if (!ctx.cr0.lt) goto loc_821D4D14;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4D48"))) PPC_WEAK_FUNC(sub_821D4D48);
PPC_FUNC_IMPL(__imp__sub_821D4D48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4D50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,11
	ctx.r30.s64 = 11;
	// addi r11,r11,-29920
	ctx.r11.s64 = ctx.r11.s64 + -29920;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,392
	ctx.r31.s64 = ctx.r11.s64 + 392;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4D6C:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4d84
	if (ctx.cr6.lt) goto loc_821D4D84;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4D84;
	sub_8207A630(ctx, base);
loc_821D4D84:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4d6c
	if (!ctx.cr0.lt) goto loc_821D4D6C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4DA0"))) PPC_WEAK_FUNC(sub_821D4DA0);
PPC_FUNC_IMPL(__imp__sub_821D4DA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4DA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,21
	ctx.r30.s64 = 21;
	// addi r11,r11,-29536
	ctx.r11.s64 = ctx.r11.s64 + -29536;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,712
	ctx.r31.s64 = ctx.r11.s64 + 712;
	// li r29,0
	ctx.r29.s64 = 0;
loc_821D4DC4:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4ddc
	if (ctx.cr6.lt) goto loc_821D4DDC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4DDC;
	sub_8207A630(ctx, base);
loc_821D4DDC:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821d4dc4
	if (!ctx.cr0.lt) goto loc_821D4DC4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4DF8"))) PPC_WEAK_FUNC(sub_821D4DF8);
PPC_FUNC_IMPL(__imp__sub_821D4DF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4E00;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r11,r11,-27952
	ctx.r11.s64 = ctx.r11.s64 + -27952;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,308
	ctx.r31.s64 = ctx.r11.s64 + 308;
	// li r28,15
	ctx.r28.s64 = 15;
loc_821D4E1C:
	// lwzu r3,-80(r31)
	ea = -80 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d4e38
	if (ctx.cr6.eq) goto loc_821D4E38;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82066ab0
	ctx.lr = 0x821D4E30;
	sub_82066AB0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4E38;
	sub_8207A630(ctx, base);
loc_821D4E38:
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// bl 0x8207a630
	ctx.lr = 0x821D4E4C;
	sub_8207A630(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4e60
	if (ctx.cr6.lt) goto loc_821D4E60;
	// lwz r3,-64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// bl 0x8207a630
	ctx.lr = 0x821D4E60;
	sub_8207A630(ctx, base);
loc_821D4E60:
	// stw r28,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,-48(r31)
	PPC_STORE_U32(ctx.r31.u32 + -48, ctx.r30.u32);
	// stb r30,-64(r31)
	PPC_STORE_U8(ctx.r31.u32 + -64, ctx.r30.u8);
	// bge 0x821d4e1c
	if (!ctx.cr0.lt) goto loc_821D4E1C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4E7C"))) PPC_WEAK_FUNC(sub_821D4E7C);
PPC_FUNC_IMPL(__imp__sub_821D4E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4E80"))) PPC_WEAK_FUNC(sub_821D4E80);
PPC_FUNC_IMPL(__imp__sub_821D4E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4E88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r11,r11,-27712
	ctx.r11.s64 = ctx.r11.s64 + -27712;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,308
	ctx.r31.s64 = ctx.r11.s64 + 308;
	// li r28,15
	ctx.r28.s64 = 15;
loc_821D4EA4:
	// lwzu r3,-80(r31)
	ea = -80 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d4ec0
	if (ctx.cr6.eq) goto loc_821D4EC0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82066ab0
	ctx.lr = 0x821D4EB8;
	sub_82066AB0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4EC0;
	sub_8207A630(ctx, base);
loc_821D4EC0:
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// bl 0x8207a630
	ctx.lr = 0x821D4ED4;
	sub_8207A630(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4ee8
	if (ctx.cr6.lt) goto loc_821D4EE8;
	// lwz r3,-64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// bl 0x8207a630
	ctx.lr = 0x821D4EE8;
	sub_8207A630(ctx, base);
loc_821D4EE8:
	// stw r28,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,-48(r31)
	PPC_STORE_U32(ctx.r31.u32 + -48, ctx.r30.u32);
	// stb r30,-64(r31)
	PPC_STORE_U8(ctx.r31.u32 + -64, ctx.r30.u8);
	// bge 0x821d4ea4
	if (!ctx.cr0.lt) goto loc_821D4EA4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4F04"))) PPC_WEAK_FUNC(sub_821D4F04);
PPC_FUNC_IMPL(__imp__sub_821D4F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4F08"))) PPC_WEAK_FUNC(sub_821D4F08);
PPC_FUNC_IMPL(__imp__sub_821D4F08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4F10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r11,r11,-27472
	ctx.r11.s64 = ctx.r11.s64 + -27472;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,308
	ctx.r31.s64 = ctx.r11.s64 + 308;
	// li r28,15
	ctx.r28.s64 = 15;
loc_821D4F2C:
	// lwzu r3,-80(r31)
	ea = -80 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d4f48
	if (ctx.cr6.eq) goto loc_821D4F48;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82066ab0
	ctx.lr = 0x821D4F40;
	sub_82066AB0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4F48;
	sub_8207A630(ctx, base);
loc_821D4F48:
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// bl 0x8207a630
	ctx.lr = 0x821D4F5C;
	sub_8207A630(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4f70
	if (ctx.cr6.lt) goto loc_821D4F70;
	// lwz r3,-64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// bl 0x8207a630
	ctx.lr = 0x821D4F70;
	sub_8207A630(ctx, base);
loc_821D4F70:
	// stw r28,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,-48(r31)
	PPC_STORE_U32(ctx.r31.u32 + -48, ctx.r30.u32);
	// stb r30,-64(r31)
	PPC_STORE_U8(ctx.r31.u32 + -64, ctx.r30.u8);
	// bge 0x821d4f2c
	if (!ctx.cr0.lt) goto loc_821D4F2C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D4F8C"))) PPC_WEAK_FUNC(sub_821D4F8C);
PPC_FUNC_IMPL(__imp__sub_821D4F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D4F90"))) PPC_WEAK_FUNC(sub_821D4F90);
PPC_FUNC_IMPL(__imp__sub_821D4F90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821D4F98;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,2
	ctx.r29.s64 = 2;
	// addi r11,r11,-27232
	ctx.r11.s64 = ctx.r11.s64 + -27232;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r31,r11,308
	ctx.r31.s64 = ctx.r11.s64 + 308;
	// li r28,15
	ctx.r28.s64 = 15;
loc_821D4FB4:
	// lwzu r3,-80(r31)
	ea = -80 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d4fd0
	if (ctx.cr6.eq) goto loc_821D4FD0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82066ab0
	ctx.lr = 0x821D4FC8;
	sub_82066AB0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821D4FD0;
	sub_8207A630(ctx, base);
loc_821D4FD0:
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// bl 0x8207a630
	ctx.lr = 0x821D4FE4;
	sub_8207A630(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d4ff8
	if (ctx.cr6.lt) goto loc_821D4FF8;
	// lwz r3,-64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// bl 0x8207a630
	ctx.lr = 0x821D4FF8;
	sub_8207A630(ctx, base);
loc_821D4FF8:
	// stw r28,-44(r31)
	PPC_STORE_U32(ctx.r31.u32 + -44, ctx.r28.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r30,-48(r31)
	PPC_STORE_U32(ctx.r31.u32 + -48, ctx.r30.u32);
	// stb r30,-64(r31)
	PPC_STORE_U8(ctx.r31.u32 + -64, ctx.r30.u8);
	// bge 0x821d4fb4
	if (!ctx.cr0.lt) goto loc_821D4FB4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D5014"))) PPC_WEAK_FUNC(sub_821D5014);
PPC_FUNC_IMPL(__imp__sub_821D5014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D5018"))) PPC_WEAK_FUNC(sub_821D5018);
PPC_FUNC_IMPL(__imp__sub_821D5018) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r31,r11,-31232
	ctx.r31.s64 = ctx.r11.s64 + -31232;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d5040
	if (ctx.cr6.eq) goto loc_821D5040;
	// bl 0x8207a630
	ctx.lr = 0x821D5040;
	sub_8207A630(ctx, base);
loc_821D5040:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// bl 0x8207a630
	ctx.lr = 0x821D5060;
	sub_8207A630(ctx, base);
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

__attribute__((alias("__imp__sub_821D5074"))) PPC_WEAK_FUNC(sub_821D5074);
PPC_FUNC_IMPL(__imp__sub_821D5074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D5078"))) PPC_WEAK_FUNC(sub_821D5078);
PPC_FUNC_IMPL(__imp__sub_821D5078) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-12704
	ctx.r3.s64 = ctx.r11.s64 + -12704;
	// b 0x82075490
	sub_82075490(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D5084"))) PPC_WEAK_FUNC(sub_821D5084);
PPC_FUNC_IMPL(__imp__sub_821D5084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D5088"))) PPC_WEAK_FUNC(sub_821D5088);
PPC_FUNC_IMPL(__imp__sub_821D5088) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-12560
	ctx.r3.s64 = ctx.r11.s64 + -12560;
	// b 0x82075490
	sub_82075490(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D5094"))) PPC_WEAK_FUNC(sub_821D5094);
PPC_FUNC_IMPL(__imp__sub_821D5094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D5098"))) PPC_WEAK_FUNC(sub_821D5098);
PPC_FUNC_IMPL(__imp__sub_821D5098) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r3,r11,-31080
	ctx.r3.s64 = ctx.r11.s64 + -31080;
	// b 0x82076158
	sub_82076158(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D50A4"))) PPC_WEAK_FUNC(sub_821D50A4);
PPC_FUNC_IMPL(__imp__sub_821D50A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D50A8"))) PPC_WEAK_FUNC(sub_821D50A8);
PPC_FUNC_IMPL(__imp__sub_821D50A8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r3,r11,-31112
	ctx.r3.s64 = ctx.r11.s64 + -31112;
	// b 0x82076158
	sub_82076158(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821D50B4"))) PPC_WEAK_FUNC(sub_821D50B4);
PPC_FUNC_IMPL(__imp__sub_821D50B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D50B8"))) PPC_WEAK_FUNC(sub_821D50B8);
PPC_FUNC_IMPL(__imp__sub_821D50B8) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r31,r11,-12408
	ctx.r31.s64 = ctx.r11.s64 + -12408;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821d50e4
	if (ctx.cr6.lt) goto loc_821D50E4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821D50E4;
	sub_8207A630(ctx, base);
loc_821D50E4:
	// li r11,15
	ctx.r11.s64 = 15;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stb r9,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_821D5110"))) PPC_WEAK_FUNC(sub_821D5110);
PPC_FUNC_IMPL(__imp__sub_821D5110) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r31,r11,-31048
	ctx.r31.s64 = ctx.r11.s64 + -31048;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821d5138
	if (ctx.cr6.eq) goto loc_821D5138;
	// bl 0x8207a630
	ctx.lr = 0x821D5138;
	sub_8207A630(ctx, base);
loc_821D5138:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// bl 0x8207a630
	ctx.lr = 0x821D5158;
	sub_8207A630(ctx, base);
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

__attribute__((alias("__imp__sub_821D516C"))) PPC_WEAK_FUNC(sub_821D516C);
PPC_FUNC_IMPL(__imp__sub_821D516C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821D5170"))) PPC_WEAK_FUNC(sub_821D5170);
PPC_FUNC_IMPL(__imp__sub_821D5170) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,29372
	ctx.r11.s64 = ctx.r11.s64 + 29372;
	// stw r11,-15652(r10)
	PPC_STORE_U32(ctx.r10.u32 + -15652, ctx.r11.u32);
	// blr 
	return;
}

