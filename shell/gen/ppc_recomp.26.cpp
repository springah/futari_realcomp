#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82167514"))) PPC_WEAK_FUNC(sub_82167514);
PPC_FUNC_IMPL(__imp__sub_82167514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167518"))) PPC_WEAK_FUNC(sub_82167518);
PPC_FUNC_IMPL(__imp__sub_82167518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f13,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f12,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f4,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f11,f11
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f12,f8,f8,f1
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f1.f64));
	// fmadds f9,f5,f5,f12
	ctx.f9.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f12.f64));
	// fsqrts f6,f9
	ctx.f6.f64 = double(float(sqrt(ctx.f9.f64)));
	// fdivs f1,f0,f6
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f6.f64));
	// fmuls f12,f1,f8
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// stfs f12,40(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fmuls f9,f1,f5
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f5.f64));
	// stfs f9,32(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fmuls f8,f1,f11
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// stfs f8,36(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fmuls f6,f4,f12
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fmuls f5,f3,f9
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// fmuls f1,f2,f8
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f8.f64));
	// fmuls f11,f13,f8
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fmsubs f6,f2,f9,f6
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f9.f64 - ctx.f6.f64));
	// fmsubs f5,f4,f8,f5
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f8.f64 - ctx.f5.f64));
	// fmsubs f4,f3,f12,f1
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 - ctx.f1.f64));
	// fmadds f3,f10,f12,f11
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fmuls f2,f6,f6
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fnmadds f1,f7,f9,f3
	ctx.f1.f64 = double(float(-(ctx.f7.f64 * ctx.f9.f64 + ctx.f3.f64)));
	// stfs f1,44(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fmadds f11,f5,f5,f2
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fmadds f3,f4,f4,f11
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f11.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fdivs f1,f0,f2
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f2.f64));
	// fmuls f0,f5,f1
	ctx.f0.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fmuls f11,f4,f1
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f1.f64));
	// stfs f11,0(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmuls f6,f6,f1
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// stfs f6,4(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmuls f5,f0,f9
	ctx.f5.f64 = double(float(ctx.f0.f64 * ctx.f9.f64));
	// fmuls f4,f11,f8
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmuls f3,f6,f12
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// fmuls f2,f13,f6
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// fmsubs f1,f11,f12,f5
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 - ctx.f5.f64));
	// stfs f1,20(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fmsubs f12,f6,f9,f4
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 - ctx.f4.f64));
	// stfs f12,24(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fmsubs f9,f0,f8,f3
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f8.f64 - ctx.f3.f64));
	// stfs f9,16(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fmadds f8,f10,f0,f2
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f2.f64));
	// fmuls f6,f13,f1
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// fnmadds f5,f7,f11,f8
	ctx.f5.f64 = double(float(-(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64)));
	// stfs f5,12(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fmadds f4,f10,f12,f6
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fnmadds f3,f7,f9,f4
	ctx.f3.f64 = double(float(-(ctx.f7.f64 * ctx.f9.f64 + ctx.f4.f64)));
	// stfs f3,28(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167618"))) PPC_WEAK_FUNC(sub_82167618);
PPC_FUNC_IMPL(__imp__sub_82167618) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8207ae60
	ctx.lr = 0x8216763C;
	sub_8207AE60(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207af40
	ctx.lr = 0x82167648;
	sub_8207AF40(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// fneg f11,f30
	ctx.f11.u64 = ctx.f30.u64 ^ 0x8000000000000000;
	// stfs f12,0(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f11,4(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f30,16(r31)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 40, temp.u32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-32(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821676AC"))) PPC_WEAK_FUNC(sub_821676AC);
PPC_FUNC_IMPL(__imp__sub_821676AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821676B0"))) PPC_WEAK_FUNC(sub_821676B0);
PPC_FUNC_IMPL(__imp__sub_821676B0) {
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
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821676d8
	if (ctx.cr6.eq) goto loc_821676D8;
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// bne cr6,0x821676dc
	if (!ctx.cr6.eq) goto loc_821676DC;
loc_821676D8:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_821676DC:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f13,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// lfs f9,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// stfs f6,0(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f5,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,36(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmadds f12,f5,f4,f13
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f13.f64));
	// fmadds f11,f3,f2,f12
	ctx.f11.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f12.f64));
	// stfs f11,4(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// fmadds f3,f10,f9,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f4.f64));
	// fmadds f2,f8,f7,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f3.f64));
	// stfs f2,8(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmadds f7,f1,f0,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f0.f64 + ctx.f8.f64));
	// fmadds f6,f13,f12,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fadds f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f11.f64));
	// stfs f5,12(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lfs f4,16(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,20(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmadds f11,f4,f3,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f3.f64 + ctx.f12.f64));
	// fmadds f10,f2,f1,f11
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f10,16(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,36(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// fmadds f2,f9,f8,f3
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fmadds f1,f7,f6,f2
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 + ctx.f2.f64));
	// stfs f1,20(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// lfs f0,16(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,24(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmadds f7,f0,f13,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f6,f12,f11,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f6,24(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lfs f5,16(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,20(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmadds f11,f5,f4,f12
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f12.f64));
	// fmadds f10,f3,f2,f11
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f11.f64));
	// fadds f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f1.f64));
	// stfs f9,28(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// lfs f8,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,32(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,36(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f3.f64));
	// fmadds f1,f8,f7,f2
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f2.f64));
	// fmadds f0,f6,f5,f1
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f5.f64 + ctx.f1.f64));
	// stfs f0,32(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 32, temp.u32);
	// lfs f13,36(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmadds f6,f7,f13,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f5,f12,f11,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f6.f64));
	// stfs f5,36(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// lfs f4,40(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,32(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,36(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmadds f11,f4,f3,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f3.f64 + ctx.f12.f64));
	// fmadds f10,f2,f1,f11
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f10,40(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// lfs f2,40(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f8,32(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,36(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// lfs f9,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f1,f2,f9,f3
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmadds f0,f8,f7,f1
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f1.f64));
	// fadds f13,f0,f6
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f6.f64));
	// stfs f13,44(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 44, temp.u32);
	// bne cr6,0x821678ec
	if (!ctx.cr6.eq) goto loc_821678EC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x821678EC;
	sub_8207DAC0(ctx, base);
loc_821678EC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821678FC"))) PPC_WEAK_FUNC(sub_821678FC);
PPC_FUNC_IMPL(__imp__sub_821678FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167900"))) PPC_WEAK_FUNC(sub_82167900);
PPC_FUNC_IMPL(__imp__sub_82167900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82167618
	sub_82167618(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216790C"))) PPC_WEAK_FUNC(sub_8216790C);
PPC_FUNC_IMPL(__imp__sub_8216790C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167910"))) PPC_WEAK_FUNC(sub_82167910);
PPC_FUNC_IMPL(__imp__sub_82167910) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,227
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 227, ctx.xer);
	// bge cr6,0x82167964
	if (!ctx.cr6.lt) goto loc_82167964;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,397
	ctx.r8.s64 = ctx.r11.s64 + 397;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r4,r7,6112
	ctx.r4.s64 = ctx.r7.s64 + 6112;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwimi r11,r5,0,0,0
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// lwzx r8,r6,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// rlwinm r7,r11,2,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x4;
	// rlwinm r6,r11,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r5,r7,r4
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// xor r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// xor r11,r4,r6
	ctx.r11.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u32);
	// b 0x821679e8
	goto loc_821679E8;
loc_82167964:
	// cmplwi cr6,r11,623
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 623, ctx.xer);
	// bge cr6,0x821679b4
	if (!ctx.cr6.lt) goto loc_821679B4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,-227
	ctx.r8.s64 = ctx.r11.s64 + -227;
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r4,r7,6112
	ctx.r4.s64 = ctx.r7.s64 + 6112;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwimi r11,r5,0,0,0
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// lwzx r8,r6,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// rlwinm r7,r11,2,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x4;
	// rlwinm r6,r11,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r5,r7,r4
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// xor r4,r8,r5
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r5.u64;
	// xor r11,r4,r6
	ctx.r11.u64 = ctx.r4.u64 ^ ctx.r6.u64;
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u32);
	// b 0x821679e8
	goto loc_821679E8;
loc_821679B4:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,6112
	ctx.r9.s64 = ctx.r10.s64 + 6112;
	// lwz r8,2492(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2492);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r6,1584(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1584);
	// rlwimi r7,r8,0,0,0
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0x80000000) | (ctx.r7.u64 & 0xFFFFFFFF7FFFFFFF);
	// rlwinm r5,r7,2,29,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x4;
	// rlwinm r4,r7,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lwzx r10,r5,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// xor r9,r10,r6
	ctx.r9.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// xor r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r4.u64;
	// stw r8,2492(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2492, ctx.r8.u32);
loc_821679E8:
	// lhz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r11,r9,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,624
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 624, ctx.xer);
	// sth r7,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r7.u16);
	// blt cr6,0x82167a14
	if (ctx.cr6.lt) goto loc_82167A14;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
loc_82167A14:
	// rlwinm r10,r11,21,11,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1FFFFF;
	// lis r12,-198
	ctx.r12.s64 = -12976128;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// ori r12,r12,22701
	ctx.r12.u64 = ctx.r12.u64 | 22701;
	// and r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 & ctx.r12.u64;
	// rlwinm r7,r8,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// xor r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// rlwinm r5,r6,15,0,14
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 15) & 0xFFFE0000;
	// rlwinm r5,r5,0,13,9
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFC7FFFF;
	// rlwinm r5,r5,0,4,2
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// xor r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// rlwinm r3,r4,14,18,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 14) & 0x3FFF;
	// xor r3,r3,r4
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167A4C"))) PPC_WEAK_FUNC(sub_82167A4C);
PPC_FUNC_IMPL(__imp__sub_82167A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167A50"))) PPC_WEAK_FUNC(sub_82167A50);
PPC_FUNC_IMPL(__imp__sub_82167A50) {
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
	// li r3,2496
	ctx.r3.s64 = 2496;
	// bl 0x8207a030
	ctx.lr = 0x82167A6C;
	sub_8207A030(ctx, base);
	// lis r11,299
	ctx.r11.s64 = 19595264;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// ori r9,r11,54954
	ctx.r9.u64 = ctx.r11.u64 | 54954;
	// lis r11,27655
	ctx.r11.s64 = 1812398080;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// sth r10,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r10.u16);
	// ori r8,r11,35173
	ctx.r8.u64 = ctx.r11.u64 | 35173;
loc_82167A8C:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// rlwinm r7,r9,2,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3;
	// xor r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// mullw r9,r6,r8
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lhz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r11,624
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 624, ctx.xer);
	// blt cr6,0x82167a8c
	if (ctx.cr6.lt) goto loc_82167A8C;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
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

__attribute__((alias("__imp__sub_82167AE8"))) PPC_WEAK_FUNC(sub_82167AE8);
PPC_FUNC_IMPL(__imp__sub_82167AE8) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82167910
	ctx.lr = 0x82167B00;
	sub_82167910(ctx, base);
	// clrlwi r11,r3,1
	ctx.r11.u64 = ctx.r3.u32 & 0x7FFFFFFF;
	// divwu r10,r11,r31
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r31.u32);
	// mullw r9,r10,r31
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r31.s32);
	// subf r3,r9,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r9.s64;
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

__attribute__((alias("__imp__sub_82167B24"))) PPC_WEAK_FUNC(sub_82167B24);
PPC_FUNC_IMPL(__imp__sub_82167B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167B28"))) PPC_WEAK_FUNC(sub_82167B28);
PPC_FUNC_IMPL(__imp__sub_82167B28) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31396(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31396);
	// lwz r30,12(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x82167a50
	ctx.lr = 0x82167B50;
	sub_82167A50(ctx, base);
	// li r5,624
	ctx.r5.s64 = 624;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lis r10,25
	ctx.r10.s64 = 1638400;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// ori r6,r10,26125
	ctx.r6.u64 = ctx.r10.u64 | 26125;
loc_82167B6C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,624
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 624, ctx.xer);
	// lwzx r8,r7,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r30.u32);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r7,r4,2,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x3;
	// xor r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r4.u64;
	// mullw r7,r4,r6
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// xor r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r3.u64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// blt cr6,0x82167bc4
	if (ctx.cr6.lt) goto loc_82167BC4;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,2492(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2492);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_82167BC4:
	// subfc r10,r5,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r5.u32;
	ctx.r10.s64 = ctx.r9.s64 - ctx.r5.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 & ctx.r9.u64;
	// bdnz 0x82167b6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82167B6C;
	// li r10,623
	ctx.r10.s64 = 623;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,23896
	ctx.r10.s64 = 1566048256;
	// ori r8,r10,35685
	ctx.r8.u64 = ctx.r10.u64 | 35685;
loc_82167BE4:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r6,r9,2,30,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x3;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// xor r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r11.s64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r11,624
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 624, ctx.xer);
	// blt cr6,0x82167c2c
	if (ctx.cr6.lt) goto loc_82167C2C;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,2492(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2492);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_82167C2C:
	// bdnz 0x82167be4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82167BE4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82167C58"))) PPC_WEAK_FUNC(sub_82167C58);
PPC_FUNC_IMPL(__imp__sub_82167C58) {
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
	// bl 0x82167910
	ctx.lr = 0x82167C68;
	sub_82167910(ctx, base);
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,72(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// lfd f2,48(r9)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r9.u32 + 48);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x8207b020
	ctx.lr = 0x82167C94;
	sub_8207B020(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167CA8"))) PPC_WEAK_FUNC(sub_82167CA8);
PPC_FUNC_IMPL(__imp__sub_82167CA8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82167cd8
	if (ctx.cr6.eq) goto loc_82167CD8;
	// subfic r9,r10,16
	ctx.xer.ca = ctx.r10.u32 <= 16;
	ctx.r9.s64 = 16 - ctx.r10.s64;
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// slw r7,r11,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r9.u8 & 0x3F));
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// srw r4,r8,r6
	ctx.r4.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r6.u8 & 0x3F));
	// or r11,r5,r4
	ctx.r11.u64 = ctx.r5.u64 | ctx.r4.u64;
loc_82167CD8:
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// clrlwi r8,r11,16
	ctx.r8.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r11,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// xor r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// sthx r6,r11,r10
	PPC_STORE_U16(ctx.r11.u32 + ctx.r10.u32, ctx.r6.u16);
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// cmpwi cr6,r11,1248
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1248, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167D24"))) PPC_WEAK_FUNC(sub_82167D24);
PPC_FUNC_IMPL(__imp__sub_82167D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167D28"))) PPC_WEAK_FUNC(sub_82167D28);
PPC_FUNC_IMPL(__imp__sub_82167D28) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,6120
	ctx.r10.s64 = ctx.r11.s64 + 6120;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8207a8a0
	ctx.lr = 0x82167D50;
	sub_8207A8A0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r7,r9,5680
	ctx.r7.s64 = ctx.r9.s64 + 5680;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lwz r11,-31328(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31328);
	// addi r3,r11,32
	ctx.r3.s64 = ctx.r11.s64 + 32;
	// bl 0x82173a70
	ctx.lr = 0x82167D70;
	sub_82173A70(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82167d90
	if (ctx.cr6.eq) goto loc_82167D90;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82167D90;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82167D90:
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

__attribute__((alias("__imp__sub_82167DA4"))) PPC_WEAK_FUNC(sub_82167DA4);
PPC_FUNC_IMPL(__imp__sub_82167DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167DA8"))) PPC_WEAK_FUNC(sub_82167DA8);
PPC_FUNC_IMPL(__imp__sub_82167DA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82167DB0;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82170650
	ctx.lr = 0x82167DC4;
	sub_82170650(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r3,2496
	ctx.r3.s64 = 2496;
	// addi r10,r11,6120
	ctx.r10.s64 = ctx.r11.s64 + 6120;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x8207a030
	ctx.lr = 0x82167DD8;
	sub_8207A030(ctx, base);
	// li r10,1248
	ctx.r10.s64 = 1248;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82167DEC:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// sthx r30,r10,r11
	PPC_STORE_U16(ctx.r10.u32 + ctx.r11.u32, ctx.r30.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x82167dec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82167DEC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8208a4b8
	ctx.lr = 0x82167E08;
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
	ctx.lr = 0x82167E24;
	sub_8208A498(ctx, base);
	// lfd f11,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// sth r10,0(r29)
	PPC_STORE_U16(ctx.r29.u32 + 0, ctx.r10.u16);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82167E58"))) PPC_WEAK_FUNC(sub_82167E58);
PPC_FUNC_IMPL(__imp__sub_82167E58) {
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
	// lbz r10,-31020(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + -31020);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82167eb4
	if (!ctx.cr6.eq) goto loc_82167EB4;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,24
	ctx.r3.s64 = 24;
	// stb r10,-31020(r11)
	PPC_STORE_U8(ctx.r11.u32 + -31020, ctx.r10.u8);
	// bl 0x82079fd8
	ctx.lr = 0x82167E84;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82167ea8
	if (ctx.cr6.eq) goto loc_82167EA8;
	// bl 0x82167da8
	ctx.lr = 0x82167E90;
	sub_82167DA8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,-31396(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31396, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82167EA8:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31396(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31396, ctx.r11.u32);
loc_82167EB4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167EC4"))) PPC_WEAK_FUNC(sub_82167EC4);
PPC_FUNC_IMPL(__imp__sub_82167EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167EC8"))) PPC_WEAK_FUNC(sub_82167EC8);
PPC_FUNC_IMPL(__imp__sub_82167EC8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167ECC"))) PPC_WEAK_FUNC(sub_82167ECC);
PPC_FUNC_IMPL(__imp__sub_82167ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167ED0"))) PPC_WEAK_FUNC(sub_82167ED0);
PPC_FUNC_IMPL(__imp__sub_82167ED0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167ED8"))) PPC_WEAK_FUNC(sub_82167ED8);
PPC_FUNC_IMPL(__imp__sub_82167ED8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167EE0"))) PPC_WEAK_FUNC(sub_82167EE0);
PPC_FUNC_IMPL(__imp__sub_82167EE0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82167EE4"))) PPC_WEAK_FUNC(sub_82167EE4);
PPC_FUNC_IMPL(__imp__sub_82167EE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82167EE8"))) PPC_WEAK_FUNC(sub_82167EE8);
PPC_FUNC_IMPL(__imp__sub_82167EE8) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r30,r11,-31048
	ctx.r30.s64 = ctx.r11.s64 + -31048;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82167f18
	if (!ctx.cr6.gt) goto loc_82167F18;
	// twi 31,r0,22
loc_82167F18:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r31,r9
	ctx.r31.u64 = ctx.r9.u64;
loc_82167F20:
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82167f2c
	if (!ctx.cr6.gt) goto loc_82167F2C;
	// twi 31,r0,22
loc_82167F2C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82167f38
	if (!ctx.cr6.eq) goto loc_82167F38;
	// twi 31,r0,22
loc_82167F38:
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x821680a4
	if (!ctx.cr6.lt) goto loc_821680A4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82167f98
	if (!ctx.cr6.eq) goto loc_82167F98;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82167F50:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82167f60
	if (ctx.cr6.lt) goto loc_82167F60;
	// twi 31,r0,22
loc_82167F60:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x82167fa8
	if (ctx.cr6.eq) goto loc_82167FA8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82167fa0
	if (!ctx.cr6.eq) goto loc_82167FA0;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82167F80:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82167f90
	if (ctx.cr6.lt) goto loc_82167F90;
	// twi 31,r0,22
loc_82167F90:
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// b 0x82167f20
	goto loc_82167F20;
loc_82167F98:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82167f50
	goto loc_82167F50;
loc_82167FA0:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82167f80
	goto loc_82167F80;
loc_82167FA8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821680bc
	if (!ctx.cr6.eq) goto loc_821680BC;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82167FB8:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82167fc8
	if (ctx.cr6.lt) goto loc_82167FC8;
	// twi 31,r0,22
loc_82167FC8:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// bne cr6,0x821680c4
	if (!ctx.cr6.eq) goto loc_821680C4;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82167FE4:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82167ff4
	if (ctx.cr6.lt) goto loc_82167FF4;
	// twi 31,r0,22
loc_82167FF4:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821680a4
	if (!ctx.cr6.eq) goto loc_821680A4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82168020
	if (ctx.cr6.eq) goto loc_82168020;
	// lwz r11,156(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x82168024
	if (!ctx.cr6.eq) goto loc_82168024;
loc_82168020:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82168024:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216803c
	if (ctx.cr6.eq) goto loc_8216803C;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r3,156(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 156);
	// bl 0x8216d120
	ctx.lr = 0x8216803C;
	sub_8216D120(ctx, base);
loc_8216803C:
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82168084
	if (ctx.cr6.eq) goto loc_82168084;
	// addi r10,r11,-16
	ctx.r10.s64 = ctx.r11.s64 + -16;
loc_82168050:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r5,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82168050
	if (!ctx.cr6.eq) goto loc_82168050;
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
loc_82168084:
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r9,-16
	ctx.r11.s64 = ctx.r9.s64 + -16;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x821680a0
	if (ctx.cr6.gt) goto loc_821680A0;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x821680a4
	if (!ctx.cr6.gt) goto loc_821680A4;
loc_821680A0:
	// twi 31,r0,22
loc_821680A4:
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
loc_821680BC:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82167fb8
	goto loc_82167FB8;
loc_821680C4:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82167fe4
	goto loc_82167FE4;
}

__attribute__((alias("__imp__sub_821680CC"))) PPC_WEAK_FUNC(sub_821680CC);
PPC_FUNC_IMPL(__imp__sub_821680CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821680D0"))) PPC_WEAK_FUNC(sub_821680D0);
PPC_FUNC_IMPL(__imp__sub_821680D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x821680D8;
	__savegprlr_14(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r17,0
	ctx.r17.s64 = 0;
	// std r4,408(r1)
	PPC_STORE_U64(ctx.r1.u32 + 408, ctx.r4.u64);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r28,408(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	// stw r17,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r17.u32);
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// stw r17,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r17.u32);
	// addi r31,r11,-24320
	ctx.r31.s64 = ctx.r11.s64 + -24320;
	// lwz r11,44(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 44);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r5,r31,-324
	ctx.r5.s64 = ctx.r31.s64 + -324;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82175ae8
	ctx.lr = 0x82168118;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x82168124;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x82168130;
	sub_82175150(ctx, base);
	// li r27,15
	ctx.r27.s64 = 15;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r17,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r17.u32);
	// stw r27,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r27.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r17,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, ctx.r17.u8);
loc_82168148:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82168148
	if (!ctx.cr6.eq) goto loc_82168148;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8216816C;
	sub_82060368(ctx, base);
	// addi r5,r31,-316
	ctx.r5.s64 = ctx.r31.s64 + -316;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8216817C;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x82168188;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x82168194;
	sub_82175150(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r27,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r27.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r17,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r17.u32);
	// stb r17,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r17.u8);
loc_821681A8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821681a8
	if (!ctx.cr6.eq) goto loc_821681A8;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821681CC;
	sub_82060368(ctx, base);
	// addi r5,r31,-308
	ctx.r5.s64 = ctx.r31.s64 + -308;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x821681DC;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x821681E0;
	sub_82175D08(ctx, base);
	// stw r3,8(r15)
	PPC_STORE_U32(ctx.r15.u32 + 8, ctx.r3.u32);
	// addi r5,r31,-300
	ctx.r5.s64 = ctx.r31.s64 + -300;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x821681F4;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x821681F8;
	sub_82175D08(ctx, base);
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,12(r15)
	PPC_STORE_U32(ctx.r15.u32 + 12, ctx.r3.u32);
	// addi r30,r11,-31048
	ctx.r30.s64 = ctx.r11.s64 + -31048;
	// lbz r10,-31357(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + -31357);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82168260
	if (!ctx.cr6.eq) goto loc_82168260;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82168228
	if (!ctx.cr6.gt) goto loc_82168228;
	// twi 31,r0,22
loc_82168228:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x82168240
	if (!ctx.cr6.gt) goto loc_82168240;
	// twi 31,r0,22
loc_82168240:
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82077d48
	ctx.lr = 0x82168258;
	sub_82077D48(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,-31357(r29)
	PPC_STORE_U8(ctx.r29.u32 + -31357, ctx.r11.u8);
loc_82168260:
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x82168274
	if (!ctx.cr6.gt) goto loc_82168274;
	// twi 31,r0,22
loc_82168274:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r6,412(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
loc_82168280:
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// ble cr6,0x8216828c
	if (!ctx.cr6.gt) goto loc_8216828C;
	// twi 31,r0,22
loc_8216828C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82168298
	if (!ctx.cr6.eq) goto loc_82168298;
	// twi 31,r0,22
loc_82168298:
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x821683c8
	if (!ctx.cr6.lt) goto loc_821683C8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82168314
	if (!ctx.cr6.eq) goto loc_82168314;
	// twi 31,r0,22
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_821682B0:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821682c0
	if (ctx.cr6.lt) goto loc_821682C0;
	// twi 31,r0,22
loc_821682C0:
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x821682dc
	if (!ctx.cr6.eq) goto loc_821682DC;
	// lwz r11,8(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821682e0
	if (ctx.cr6.eq) goto loc_821682E0;
loc_821682DC:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_821682E0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82168324
	if (!ctx.cr6.eq) goto loc_82168324;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8216831c
	if (!ctx.cr6.eq) goto loc_8216831C;
	// twi 31,r0,22
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_821682FC:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8216830c
	if (ctx.cr6.lt) goto loc_8216830C;
	// twi 31,r0,22
loc_8216830C:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// b 0x82168280
	goto loc_82168280;
loc_82168314:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x821682b0
	goto loc_821682B0;
loc_8216831C:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x821682fc
	goto loc_821682FC;
loc_82168324:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821683b8
	if (!ctx.cr6.eq) goto loc_821683B8;
	// twi 31,r0,22
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_82168334:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82168344
	if (ctx.cr6.lt) goto loc_82168344;
	// twi 31,r0,22
loc_82168344:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r11,16(r15)
	PPC_STORE_U32(ctx.r15.u32 + 16, ctx.r11.u32);
	// bne cr6,0x821683c0
	if (!ctx.cr6.eq) goto loc_821683C0;
	// twi 31,r0,22
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_8216835C:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8216836c
	if (ctx.cr6.lt) goto loc_8216836C;
	// twi 31,r0,22
loc_8216836C:
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// lwz r10,184(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8216838c
	if (ctx.cr6.lt) goto loc_8216838C;
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// bl 0x8207a630
	ctx.lr = 0x8216838C;
	sub_8207A630(ctx, base);
loc_8216838C:
	// lwz r11,216(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// stw r27,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r27.u32);
	// stw r17,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r17.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r17,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r17.u8);
	// blt cr6,0x82168e40
	if (ctx.cr6.lt) goto loc_82168E40;
	// lwz r3,196(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// bl 0x8207a630
	ctx.lr = 0x821683AC;
	sub_8207A630(ctx, base);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
loc_821683B8:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x82168334
	goto loc_82168334;
loc_821683C0:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8216835c
	goto loc_8216835C;
loc_821683C8:
	// lwz r11,8(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// li r10,24
	ctx.r10.s64 = 24;
	// lwz r9,12(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 12);
	// li r3,84
	ctx.r3.s64 = 84;
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// mullw r6,r9,r11
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stb r3,129(r1)
	PPC_STORE_U8(ctx.r1.u32 + 129, ctx.r3.u8);
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// sth r11,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, ctx.r11.u16);
	// sth r17,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, ctx.r17.u16);
	// sth r17,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, ctx.r17.u16);
	// sth r9,146(r1)
	PPC_STORE_U16(ctx.r1.u32 + 146, ctx.r9.u16);
	// li r4,77
	ctx.r4.s64 = 77;
	// li r11,80
	ctx.r11.s64 = 80;
	// li r10,71
	ctx.r10.s64 = 71;
	// stb r4,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, ctx.r4.u8);
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r11,130(r1)
	PPC_STORE_U8(ctx.r1.u32 + 130, ctx.r11.u8);
	// stb r10,131(r1)
	PPC_STORE_U8(ctx.r1.u32 + 131, ctx.r10.u8);
	// li r14,1
	ctx.r14.s64 = 1;
	// bl 0x8207a030
	ctx.lr = 0x82168420;
	sub_8207A030(ctx, base);
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// addi r5,r31,-292
	ctx.r5.s64 = ctx.r31.s64 + -292;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r4,212(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820654f8
	ctx.lr = 0x8216843C;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821687e4
	if (!ctx.cr6.eq) goto loc_821687E4;
	// addi r5,r31,-284
	ctx.r5.s64 = ctx.r31.s64 + -284;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,5
	ctx.r6.s64 = 5;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x82168458;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821684c8
	if (!ctx.cr6.eq) goto loc_821684C8;
	// addi r5,r31,-268
	ctx.r5.s64 = ctx.r31.s64 + -268;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175ae8
	ctx.lr = 0x82168470;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x8216847C;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168488;
	sub_821750D8(ctx, base);
	// lwz r30,8(r15)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r5,r31,-276
	ctx.r5.s64 = ctx.r31.s64 + -276;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rlwinm r31,r30,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82175ae8
	ctx.lr = 0x821684A4;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x821684A8;
	sub_821756F0(ctx, base);
	// divwu r8,r3,r31
	ctx.r8.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820782a0
	ctx.lr = 0x821684C4;
	sub_820782A0(ctx, base);
	// b 0x82168db4
	goto loc_82168DB4;
loc_821684C8:
	// addi r5,r31,-260
	ctx.r5.s64 = ctx.r31.s64 + -260;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,6
	ctx.r6.s64 = 6;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x821684DC;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821685e0
	if (!ctx.cr6.eq) goto loc_821685E0;
	// addi r5,r31,-244
	ctx.r5.s64 = ctx.r31.s64 + -244;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x821684F4;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168500;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x8216850C;
	sub_821750D8(ctx, base);
	// lwz r23,8(r15)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// addi r5,r31,-252
	ctx.r5.s64 = ctx.r31.s64 + -252;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rlwinm r31,r23,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x82175ae8
	ctx.lr = 0x82168528;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x8216852C;
	sub_821756F0(ctx, base);
	// divwu. r11,r3,r31
	ctx.r11.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r24,r23,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// beq 0x82168db4
	if (ctx.cr0.eq) goto loc_82168DB4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r19,r31,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r18,r24,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r22,r16,2
	ctx.r22.s64 = ctx.r16.s64 + 2;
	// addi r21,r11,1
	ctx.r21.s64 = ctx.r11.s64 + 1;
loc_82168550:
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
	// add r20,r19,r20
	ctx.r20.u64 = ctx.r19.u64 + ctx.r20.u64;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x821685d0
	if (ctx.cr6.eq) goto loc_821685D0;
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
loc_82168570:
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// li r27,4
	ctx.r27.s64 = 4;
loc_82168578:
	// addi r31,r28,-6
	ctx.r31.s64 = ctx.r28.s64 + -6;
	// li r30,4
	ctx.r30.s64 = 4;
loc_82168580:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82077ab0
	ctx.lr = 0x8216858C;
	sub_82077AB0(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// lbz r8,83(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// stb r11,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// stb r10,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r10.u8);
	// stb r9,7(r31)
	PPC_STORE_U8(ctx.r31.u32 + 7, ctx.r9.u8);
	// stbu r8,4(r31)
	ea = 4 + ctx.r31.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r31.u32 = ea;
	// bne 0x82168580
	if (!ctx.cr0.eq) goto loc_82168580;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// add r28,r24,r28
	ctx.r28.u64 = ctx.r24.u64 + ctx.r28.u64;
	// bne 0x82168578
	if (!ctx.cr0.eq) goto loc_82168578;
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r26,r26,16
	ctx.r26.s64 = ctx.r26.s64 + 16;
	// bne 0x82168570
	if (!ctx.cr0.eq) goto loc_82168570;
loc_821685D0:
	// addic. r21,r21,-1
	ctx.xer.ca = ctx.r21.u32 > 0;
	ctx.r21.s64 = ctx.r21.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// add r22,r18,r22
	ctx.r22.u64 = ctx.r18.u64 + ctx.r22.u64;
	// bne 0x82168550
	if (!ctx.cr0.eq) goto loc_82168550;
	// b 0x82168db4
	goto loc_82168DB4;
loc_821685E0:
	// addi r5,r31,-236
	ctx.r5.s64 = ctx.r31.s64 + -236;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x821685F4;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8216872c
	if (!ctx.cr6.eq) goto loc_8216872C;
	// addi r5,r31,-224
	ctx.r5.s64 = ctx.r31.s64 + -224;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8216860C;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168618;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168624;
	sub_821750D8(ctx, base);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// addi r5,r31,-216
	ctx.r5.s64 = ctx.r31.s64 + -216;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x82168638;
	sub_82175AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168644;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168650;
	sub_821750D8(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r5,r31,-232
	ctx.r5.s64 = ctx.r31.s64 + -232;
	// lwz r24,8(r15)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168668;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x8216866C;
	sub_821756F0(ctx, base);
	// divwu. r11,r3,r24
	ctx.r11.u32 = ppc_divwu(ctx.r3.u32, ctx.r24.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r22,r24,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// beq 0x82168db4
	if (ctx.cr0.eq) goto loc_82168DB4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r18,r24,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r17,r22,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r21,r16,2
	ctx.r21.s64 = ctx.r16.s64 + 2;
	// addi r20,r11,1
	ctx.r20.s64 = ctx.r11.s64 + 1;
loc_82168690:
	// mr r10,r19
	ctx.r10.u64 = ctx.r19.u64;
	// add r19,r19,r18
	ctx.r19.u64 = ctx.r19.u64 + ctx.r18.u64;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82168718
	if (ctx.cr6.eq) goto loc_82168718;
	// addi r11,r24,-1
	ctx.r11.s64 = ctx.r24.s64 + -1;
	// mr r25,r21
	ctx.r25.u64 = ctx.r21.u64;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r29,r10,-1
	ctx.r29.s64 = ctx.r10.s64 + -1;
	// addi r23,r11,1
	ctx.r23.s64 = ctx.r11.s64 + 1;
loc_821686B4:
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// li r26,4
	ctx.r26.s64 = 4;
loc_821686BC:
	// addi r31,r28,-6
	ctx.r31.s64 = ctx.r28.s64 + -6;
	// li r30,8
	ctx.r30.s64 = 8;
loc_821686C4:
	// lbzu r11,1(r29)
	ea = 1 + ctx.r29.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r29.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x82077ab0
	ctx.lr = 0x821686D8;
	sub_82077AB0(ctx, base);
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lbz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r8,83(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// stb r11,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// stb r10,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r10.u8);
	// stb r9,7(r31)
	PPC_STORE_U8(ctx.r31.u32 + 7, ctx.r9.u8);
	// stbu r8,4(r31)
	ea = 4 + ctx.r31.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r31.u32 = ea;
	// bne 0x821686c4
	if (!ctx.cr0.eq) goto loc_821686C4;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// add r28,r22,r28
	ctx.r28.u64 = ctx.r22.u64 + ctx.r28.u64;
	// bne 0x821686bc
	if (!ctx.cr0.eq) goto loc_821686BC;
	// addic. r23,r23,-1
	ctx.xer.ca = ctx.r23.u32 > 0;
	ctx.r23.s64 = ctx.r23.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r25,r25,32
	ctx.r25.s64 = ctx.r25.s64 + 32;
	// bne 0x821686b4
	if (!ctx.cr0.eq) goto loc_821686B4;
loc_82168718:
	// addic. r20,r20,-1
	ctx.xer.ca = ctx.r20.u32 > 0;
	ctx.r20.s64 = ctx.r20.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// add r21,r17,r21
	ctx.r21.u64 = ctx.r17.u64 + ctx.r21.u64;
	// bne 0x82168690
	if (!ctx.cr0.eq) goto loc_82168690;
	// li r17,0
	ctx.r17.s64 = 0;
	// b 0x82168db4
	goto loc_82168DB4;
loc_8216872C:
	// addi r5,r31,-212
	ctx.r5.s64 = ctx.r31.s64 + -212;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x82168740;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168db4
	if (!ctx.cr6.eq) goto loc_82168DB4;
	// addi r5,r31,-200
	ctx.r5.s64 = ctx.r31.s64 + -200;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168758;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168764;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168770;
	sub_821750D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-192
	ctx.r5.s64 = ctx.r31.s64 + -192;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x82168784;
	sub_82175AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168790;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x8216879C;
	sub_821750D8(ctx, base);
	// lwz r29,8(r15)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// addi r5,r31,-208
	ctx.r5.s64 = ctx.r31.s64 + -208;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addze r31,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r31.s64 = temp.s64;
	// bl 0x82175ae8
	ctx.lr = 0x821687BC;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x821687C0;
	sub_821756F0(ctx, base);
	// divwu r9,r3,r31
	ctx.r9.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820783a8
	ctx.lr = 0x821687E0;
	sub_820783A8(ctx, base);
	// b 0x82168db4
	goto loc_82168DB4;
loc_821687E4:
	// addi r5,r31,-188
	ctx.r5.s64 = ctx.r31.s64 + -188;
	// lwz r4,212(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820654f8
	ctx.lr = 0x821687F8;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821689ec
	if (!ctx.cr6.eq) goto loc_821689EC;
	// addi r5,r31,-184
	ctx.r5.s64 = ctx.r31.s64 + -184;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,5
	ctx.r6.s64 = 5;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x82168814;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168884
	if (!ctx.cr6.eq) goto loc_82168884;
	// addi r5,r31,-168
	ctx.r5.s64 = ctx.r31.s64 + -168;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x8216882C;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168838;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168844;
	sub_821750D8(ctx, base);
	// lwz r30,8(r15)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r5,r31,-176
	ctx.r5.s64 = ctx.r31.s64 + -176;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rlwinm r31,r30,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82175ae8
	ctx.lr = 0x82168860;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x82168864;
	sub_821756F0(ctx, base);
	// divwu r8,r3,r31
	ctx.r8.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r5,r16
	ctx.r5.u64 = ctx.r16.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820784b8
	ctx.lr = 0x82168880;
	sub_820784B8(ctx, base);
	// b 0x82168db4
	goto loc_82168DB4;
loc_82168884:
	// addi r5,r31,-160
	ctx.r5.s64 = ctx.r31.s64 + -160;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x82168898;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168934
	if (!ctx.cr6.eq) goto loc_82168934;
	// addi r5,r31,-148
	ctx.r5.s64 = ctx.r31.s64 + -148;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x821688B0;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x821688BC;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x821688C8;
	sub_821750D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-140
	ctx.r5.s64 = ctx.r31.s64 + -140;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x821688DC;
	sub_82175AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x821688E8;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x821688F4;
	sub_821750D8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r5,r31,-156
	ctx.r5.s64 = ctx.r31.s64 + -156;
	// lwz r31,8(r15)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x8216890C;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x82168910;
	sub_821756F0(ctx, base);
	// divwu r9,r3,r31
	ctx.r9.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820785b8
	ctx.lr = 0x82168930;
	sub_820785B8(ctx, base);
	// b 0x82168db4
	goto loc_82168DB4;
loc_82168934:
	// addi r5,r31,-136
	ctx.r5.s64 = ctx.r31.s64 + -136;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x82168948;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168db4
	if (!ctx.cr6.eq) goto loc_82168DB4;
	// addi r5,r31,-124
	ctx.r5.s64 = ctx.r31.s64 + -124;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168960;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x8216896C;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168978;
	sub_821750D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-116
	ctx.r5.s64 = ctx.r31.s64 + -116;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8216898C;
	sub_82175AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168998;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x821689A4;
	sub_821750D8(ctx, base);
	// lwz r29,8(r15)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// addi r5,r31,-132
	ctx.r5.s64 = ctx.r31.s64 + -132;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addze r31,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r31.s64 = temp.s64;
	// bl 0x82175ae8
	ctx.lr = 0x821689C4;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x821689C8;
	sub_821756F0(ctx, base);
	// divwu r9,r3,r31
	ctx.r9.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820786f8
	ctx.lr = 0x821689E8;
	sub_820786F8(ctx, base);
	// b 0x82168db4
	goto loc_82168DB4;
loc_821689EC:
	// addi r5,r31,-112
	ctx.r5.s64 = ctx.r31.s64 + -112;
	// lwz r4,212(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820654f8
	ctx.lr = 0x82168A00;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168ab8
	if (!ctx.cr6.eq) goto loc_82168AB8;
	// addi r5,r31,-100
	ctx.r5.s64 = ctx.r31.s64 + -100;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168A18;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168A24;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168A30;
	sub_821750D8(ctx, base);
	// lwz r29,8(r15)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-108
	ctx.r5.s64 = ctx.r31.s64 + -108;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rlwinm r31,r29,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82175ae8
	ctx.lr = 0x82168A4C;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x82168A50;
	sub_821756F0(ctx, base);
	// divwu. r11,r3,r31
	ctx.r11.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// beq 0x82168db4
	if (ctx.cr0.eq) goto loc_82168DB4;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
loc_82168A64:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82168aa4
	if (ctx.cr6.eq) goto loc_82168AA4;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// addi r11,r9,2
	ctx.r11.s64 = ctx.r9.s64 + 2;
	// subf r7,r9,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_82168A7C:
	// lbz r5,-1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r3,1(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r30,-2(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + -2);
	// stb r5,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, ctx.r5.u8);
	// stbx r4,r7,r11
	PPC_STORE_U8(ctx.r7.u32 + ctx.r11.u32, ctx.r4.u8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stb r3,7(r10)
	PPC_STORE_U8(ctx.r10.u32 + 7, ctx.r3.u8);
	// stbu r30,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r30.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82168a7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82168A7C;
loc_82168AA4:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// bne 0x82168a64
	if (!ctx.cr0.eq) goto loc_82168A64;
	// b 0x82168db4
	goto loc_82168DB4;
loc_82168AB8:
	// addi r5,r31,-92
	ctx.r5.s64 = ctx.r31.s64 + -92;
	// lwz r4,212(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// li r6,3
	ctx.r6.s64 = 3;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820654f8
	ctx.lr = 0x82168ACC;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168d48
	if (!ctx.cr6.eq) goto loc_82168D48;
	// addi r5,r31,-88
	ctx.r5.s64 = ctx.r31.s64 + -88;
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// li r6,5
	ctx.r6.s64 = 5;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820654f8
	ctx.lr = 0x82168AE8;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82168ba0
	if (!ctx.cr6.eq) goto loc_82168BA0;
	// addi r5,r31,-72
	ctx.r5.s64 = ctx.r31.s64 + -72;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168B00;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168B0C;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168B18;
	sub_821750D8(ctx, base);
	// lwz r29,8(r15)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-80
	ctx.r5.s64 = ctx.r31.s64 + -80;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rlwinm r31,r29,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82175ae8
	ctx.lr = 0x82168B34;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x82168B38;
	sub_821756F0(ctx, base);
	// divwu. r11,r3,r31
	ctx.r11.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// beq 0x82168db4
	if (ctx.cr0.eq) goto loc_82168DB4;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
loc_82168B4C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82168b8c
	if (ctx.cr6.eq) goto loc_82168B8C;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// subf r7,r9,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_82168B64:
	// lbz r5,1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r3,-1(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// lbz r30,2(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// stbx r5,r7,r11
	PPC_STORE_U8(ctx.r7.u32 + ctx.r11.u32, ctx.r5.u8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stb r4,6(r10)
	PPC_STORE_U8(ctx.r10.u32 + 6, ctx.r4.u8);
	// stb r3,7(r10)
	PPC_STORE_U8(ctx.r10.u32 + 7, ctx.r3.u8);
	// stbu r30,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r30.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82168b64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82168B64;
loc_82168B8C:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// add r8,r8,r31
	ctx.r8.u64 = ctx.r8.u64 + ctx.r31.u64;
	// bne 0x82168b4c
	if (!ctx.cr0.eq) goto loc_82168B4C;
	// b 0x82168db4
	goto loc_82168DB4;
loc_82168BA0:
	// addi r4,r31,-64
	ctx.r4.s64 = ctx.r31.s64 + -64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820659a0
	ctx.lr = 0x82168BAC;
	sub_820659A0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82168c94
	if (ctx.cr6.eq) goto loc_82168C94;
	// addi r5,r31,-52
	ctx.r5.s64 = ctx.r31.s64 + -52;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168BC8;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168BD4;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168BE0;
	sub_821750D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-44
	ctx.r5.s64 = ctx.r31.s64 + -44;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x82168BF4;
	sub_82175AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168C00;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168C0C;
	sub_821750D8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r5,r31,-60
	ctx.r5.s64 = ctx.r31.s64 + -60;
	// lwz r31,8(r15)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x82168C24;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x82168C28;
	sub_821756F0(ctx, base);
	// divwu. r11,r3,r31
	ctx.r11.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r31,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r16
	ctx.r8.u64 = ctx.r16.u64;
	// beq 0x82168db4
	if (ctx.cr0.eq) goto loc_82168DB4;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
loc_82168C3C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82168c80
	if (ctx.cr6.eq) goto loc_82168C80;
	// addi r11,r8,-4
	ctx.r11.s64 = ctx.r8.s64 + -4;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// addi r9,r30,-1
	ctx.r9.s64 = ctx.r30.s64 + -1;
loc_82168C50:
	// lbzu r10,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lbz r5,2(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lbz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r10,3(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// stb r5,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r5.u8);
	// stb r4,6(r11)
	PPC_STORE_U8(ctx.r11.u32 + 6, ctx.r4.u8);
	// stb r3,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r3.u8);
	// stbu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x82168c50
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82168C50;
loc_82168C80:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// bne 0x82168c3c
	if (!ctx.cr0.eq) goto loc_82168C3C;
	// b 0x82168db4
	goto loc_82168DB4;
loc_82168C94:
	// addi r4,r31,-40
	ctx.r4.s64 = ctx.r31.s64 + -40;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820659a0
	ctx.lr = 0x82168CA0;
	sub_820659A0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82168db4
	if (ctx.cr6.eq) goto loc_82168DB4;
	// addi r5,r31,-28
	ctx.r5.s64 = ctx.r31.s64 + -28;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168CBC;
	sub_82175AE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168CC8;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168CD4;
	sub_821750D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r5,r31,-20
	ctx.r5.s64 = ctx.r31.s64 + -20;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x82168CE8;
	sub_82175AE8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168CF4;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168D00;
	sub_821750D8(ctx, base);
	// lwz r29,8(r15)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// srawi r11,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r29.s32 >> 1;
	// addi r5,r31,-36
	ctx.r5.s64 = ctx.r31.s64 + -36;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addze r31,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r31.s64 = temp.s64;
	// bl 0x82175ae8
	ctx.lr = 0x82168D20;
	sub_82175AE8(ctx, base);
	// bl 0x821756f0
	ctx.lr = 0x82168D24;
	sub_821756F0(ctx, base);
	// divwu r9,r3,r31
	ctx.r9.u32 = ppc_divwu(ctx.r3.u32, ctx.r31.u32);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// rlwinm r7,r29,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r16
	ctx.r6.u64 = ctx.r16.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820787e0
	ctx.lr = 0x82168D44;
	sub_820787E0(ctx, base);
	// b 0x82168db4
	goto loc_82168DB4;
loc_82168D48:
	// addi r4,r31,-16
	ctx.r4.s64 = ctx.r31.s64 + -16;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x820659a0
	ctx.lr = 0x82168D54;
	sub_820659A0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82168db4
	if (ctx.cr6.eq) goto loc_82168DB4;
	// addi r4,r31,-8
	ctx.r4.s64 = ctx.r31.s64 + -8;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x820659a0
	ctx.lr = 0x82168D6C;
	sub_820659A0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82168db4
	if (ctx.cr6.eq) goto loc_82168DB4;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x82168D80;
	sub_8207A8A0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,408
	ctx.r4.s64 = ctx.r1.s64 + 408;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x82168D90;
	sub_82175AE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82168D9C;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82168DA8;
	sub_821750D8(ctx, base);
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// mr r14,r17
	ctx.r14.u64 = ctx.r17.u64;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
loc_82168DB4:
	// lwz r9,8(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 8);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r11,12(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwz r11,-31312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x8216e1b8
	ctx.lr = 0x82168DE0;
	sub_8216E1B8(ctx, base);
	// stw r3,16(r15)
	PPC_STORE_U32(ctx.r15.u32 + 16, ctx.r3.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r17,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r17.u32);
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r17.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8216c730
	ctx.lr = 0x82168DFC;
	sub_8216C730(ctx, base);
	// clrlwi r8,r14,24
	ctx.r8.u64 = ctx.r14.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82168e10
	if (ctx.cr6.eq) goto loc_82168E10;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x82168E10;
	sub_8207A8A0(ctx, base);
loc_82168E10:
	// lwz r11,16(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// ld r9,408(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 408);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// std r9,116(r1)
	PPC_STORE_U64(ctx.r1.u32 + 116, ctx.r9.u64);
	// bl 0x82077b78
	ctx.lr = 0x82168E30;
	sub_82077B78(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82065fe8
	ctx.lr = 0x82168E38;
	sub_82065FE8(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82065fe8
	ctx.lr = 0x82168E40;
	sub_82065FE8(ctx, base);
loc_82168E40:
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82168E4C"))) PPC_WEAK_FUNC(sub_82168E4C);
PPC_FUNC_IMPL(__imp__sub_82168E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82168E50"))) PPC_WEAK_FUNC(sub_82168E50);
PPC_FUNC_IMPL(__imp__sub_82168E50) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82168E54"))) PPC_WEAK_FUNC(sub_82168E54);
PPC_FUNC_IMPL(__imp__sub_82168E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82168E58"))) PPC_WEAK_FUNC(sub_82168E58);
PPC_FUNC_IMPL(__imp__sub_82168E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x82168E60;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82080364
	ctx.lr = 0x82168E68;
	__savefpr_27(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,80(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// addi r27,r3,64
	ctx.r27.s64 = ctx.r3.s64 + 64;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// ble cr6,0x82168e88
	if (!ctx.cr6.gt) goto loc_82168E88;
	// twi 31,r0,22
loc_82168E88:
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82168ea0
	if (!ctx.cr6.gt) goto loc_82168EA0;
	// twi 31,r0,22
loc_82168EA0:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82168eb4
	if (ctx.cr6.eq) goto loc_82168EB4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82168eb8
	if (ctx.cr6.eq) goto loc_82168EB8;
loc_82168EB4:
	// twi 31,r0,22
loc_82168EB8:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82168f10
	if (ctx.cr6.eq) goto loc_82168F10;
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// srawi r5,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 2;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// lis r9,-32233
	ctx.r9.s64 = -2112421888;
	// addi r8,r5,1
	ctx.r8.s64 = ctx.r5.s64 + 1;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// srawi r11,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 1;
	// addi r7,r9,25160
	ctx.r7.s64 = ctx.r9.s64 + 25160;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
	// bl 0x82076ca8
	ctx.lr = 0x82168F00;
	sub_82076CA8(ctx, base);
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82168f10
	if (ctx.cr6.eq) goto loc_82168F10;
	// bl 0x8207a630
	ctx.lr = 0x82168F10;
	sub_8207A630(ctx, base);
loc_82168F10:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lis r26,-32224
	ctx.r26.s64 = -2111832064;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82169398
	if (ctx.cr0.eq) goto loc_82169398;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// li r20,-1
	ctx.r20.s64 = -1;
	// li r21,10
	ctx.r21.s64 = 10;
	// li r30,255
	ctx.r30.s64 = 255;
	// lfs f31,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// li r22,9
	ctx.r22.s64 = 9;
	// li r23,8
	ctx.r23.s64 = 8;
loc_82168F50:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82168f6c
	if (ctx.cr6.lt) goto loc_82168F6C;
	// twi 31,r0,22
loc_82168F6C:
	// lwzx r31,r25,r11
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82168f80
	if (ctx.cr6.eq) goto loc_82168F80;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_82168F80:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82168fa0
	if (ctx.cr6.eq) goto loc_82168FA0;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82168fa4
	if (!ctx.cr6.eq) goto loc_82168FA4;
	// li r9,2
	ctx.r9.s64 = 2;
	// b 0x82168fa4
	goto loc_82168FA4;
loc_82168FA0:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82168FA4:
	// lfs f7,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f7.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// fmr f2,f7
	ctx.f2.f64 = ctx.f7.f64;
	// lfs f9,52(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f4,f7,f9
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// lfs f5,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f8
	ctx.f3.f64 = ctx.f8.f64;
	// fmr f7,f5
	ctx.f7.f64 = ctx.f5.f64;
	// lfs f11,48(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f8,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// lfs f27,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f27.f64 = double(temp.f32);
	// fadds f1,f5,f8
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f8.f64));
	// lfs f8,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,56
	ctx.r11.s64 = ctx.r31.s64 + 56;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// lfs f28,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f28.f64 = double(temp.f32);
	// lfs f30,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f30.f64 = double(temp.f32);
	// addi r11,r1,180
	ctx.r11.s64 = ctx.r1.s64 + 180;
	// lfs f29,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f30,f30,f31
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f31.f64));
	// fmr f3,f2
	ctx.f3.f64 = ctx.f2.f64;
	// lfs f0,44(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fadds f5,f2,f8
	ctx.f5.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// lfs f8,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f4,f27,f11,f4
	ctx.f4.f64 = double(float(ctx.f27.f64 * ctx.f11.f64 + ctx.f4.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f2,f7,f31
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f31.f64));
	// fmr f11,f27
	ctx.f11.f64 = ctx.f27.f64;
	// lfs f27,68(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f9,f28,f9,f6
	ctx.f9.f64 = double(float(ctx.f28.f64 * ctx.f9.f64 + ctx.f6.f64));
	// lfs f6,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f8,f8,f13
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f29,f29,f31
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f31.f64));
	// fmuls f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fmuls f7,f3,f31
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f31.f64));
	// lfs f3,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f3,f3,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fmuls f5,f5,f31
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f31.f64));
	// fmadds f2,f6,f13,f2
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f2.f64));
	// fmr f6,f28
	ctx.f6.f64 = ctx.f28.f64;
	// fmadds f8,f28,f0,f8
	ctx.f8.f64 = double(float(ctx.f28.f64 * ctx.f0.f64 + ctx.f8.f64));
	// fsubs f10,f1,f9
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f9.f64));
	// fmadds f12,f11,f12,f7
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fmr f11,f27
	ctx.f11.f64 = ctx.f27.f64;
	// fmadds f7,f27,f0,f3
	ctx.f7.f64 = double(float(ctx.f27.f64 * ctx.f0.f64 + ctx.f3.f64));
	// lfs f3,16(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f5,f5,f4
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fmadds f6,f6,f0,f30
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f0.f64 + ctx.f30.f64));
	// lfs f30,20(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f30.f64 = double(temp.f32);
	// fsubs f2,f2,f9
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f9.f64));
	// fsubs f8,f8,f9
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fsubs f1,f12,f4
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f4.f64));
	// fmadds f11,f11,f0,f29
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f29.f64));
	// fsubs f7,f7,f4
	ctx.f7.f64 = double(float(ctx.f7.f64 - ctx.f4.f64));
	// fadds f12,f10,f3
	ctx.f12.f64 = double(float(ctx.f10.f64 + ctx.f3.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fsubs f6,f6,f9
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// fadds f10,f2,f3
	ctx.f10.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fadds f8,f8,f3
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f3.f64));
	// stfs f8,104(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fadds f9,f1,f30
	ctx.f9.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fsubs f4,f11,f4
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f4.f64));
	// fadds f11,f5,f30
	ctx.f11.f64 = double(float(ctx.f5.f64 + ctx.f30.f64));
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fadds f7,f7,f30
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f30.f64));
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fadds f6,f6,f3
	ctx.f6.f64 = double(float(ctx.f6.f64 + ctx.f3.f64));
	// stfs f6,112(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f5,f4,f30
	ctx.f5.f64 = double(float(ctx.f4.f64 + ctx.f30.f64));
	// stfs f5,116(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
loc_821690D0:
	// stwu r20,12(r11)
	ea = 12 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r20.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821690d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821690D0;
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lfs f4,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f4.f64 = double(temp.f32);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfs f3,36(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,72(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stfs f4,176(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stw r9,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// stfs f3,180(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f10,196(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f9,200(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f8,208(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f7,212(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f6,220(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f5,224(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// bl 0x82076c10
	ctx.lr = 0x8216912C;
	sub_82076C10(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r9,82(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r7,83(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r6,r8,16
	ctx.r6.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// rlwimi r10,r6,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r10,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// bl 0x82076c10
	ctx.lr = 0x82169164;
	sub_82076C10(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lbz r11,81(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r8,83(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// rlwimi r11,r7,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r10,r11,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// stw r10,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r10.u32);
	// bl 0x82076c10
	ctx.lr = 0x8216919C;
	sub_82076C10(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// lbz r6,81(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r11,82(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r9,83(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// ld r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// rlwimi r6,r8,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r6,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// stw r11,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r11.u32);
	// bl 0x82076c10
	ctx.lr = 0x821691D4;
	sub_82076C10(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lbz r7,81(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r6,82(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r3,83(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r5,r3,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// lwz r11,-31312(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31312);
	// rlwimi r7,r10,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r6,r7,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// stw r6,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r6.u32);
	// bl 0x8216daa0
	ctx.lr = 0x8216920C;
	sub_8216DAA0(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82169378
	if (ctx.cr6.eq) goto loc_82169378;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82169328
	if (ctx.cr6.eq) goto loc_82169328;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821692ac
	if (ctx.cr6.eq) goto loc_821692AC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82169368
	if (!ctx.cr6.eq) goto loc_82169368;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r21,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r21.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r5,83(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// rlwimi r8,r5,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwimi r9,r4,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r7,r9,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
loc_82169264:
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82169280:
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// lbzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// divw r3,r4,r30
	ctx.r3.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// stbx r3,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r3.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x82169280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82169280;
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x82169264
	if (!ctx.cr0.eq) goto loc_82169264;
	// b 0x82169368
	goto loc_82169368;
loc_821692AC:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r22,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r22.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbz r7,82(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r5,83(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,81(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// rlwimi r8,r5,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwimi r9,r4,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r7,r9,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
loc_821692E0:
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r8,4
	ctx.r8.s64 = 4;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_821692FC:
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// lbzx r5,r11,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// divw r3,r4,r30
	ctx.r3.s32 = ppc_divw(ctx.r4.s32, ctx.r30.s32);
	// stbx r3,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r3.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x821692fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821692FC;
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// bne 0x821692e0
	if (!ctx.cr0.eq) goto loc_821692E0;
	// b 0x82169368
	goto loc_82169368;
loc_82169328:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r1,180
	ctx.r10.s64 = ctx.r1.s64 + 180;
	// stw r23,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r23.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lbz r6,81(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r8,83(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r11,82(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwimi r6,r5,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r6,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
loc_82169360:
	// stwu r11,12(r10)
	ea = 12 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82169360
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82169360;
loc_82169368:
	// lwz r11,-31312(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31312);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216daa0
	ctx.lr = 0x82169378;
	sub_8216DAA0(ctx, base);
loc_82169378:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82168f50
	if (ctx.cr6.lt) goto loc_82168F50;
loc_82169398:
	// lwz r11,-31312(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,156(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820975e8
	ctx.lr = 0x821693AC;
	sub_820975E8(ctx, base);
	// lwz r5,16(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x821693c8
	if (!ctx.cr6.gt) goto loc_821693C8;
	// twi 31,r0,22
	// twi 31,r0,22
	// twi 31,r0,22
loc_821693C8:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x821693dc
	if (ctx.cr6.gt) goto loc_821693DC;
	// cmplw cr6,r5,r5
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x821693e0
	if (!ctx.cr6.gt) goto loc_821693E0;
loc_821693DC:
	// twi 31,r0,22
loc_821693E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821693f0
	if (ctx.cr6.eq) goto loc_821693F0;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821693f4
	if (ctx.cr6.eq) goto loc_821693F4;
loc_821693F0:
	// twi 31,r0,22
loc_821693F4:
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8216941c
	if (ctx.cr6.eq) goto loc_8216941C;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r3
	ctx.r31.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x82169418
	if (!ctx.cr0.gt) goto loc_82169418;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x82169418;
	sub_8207A520(ctx, base);
loc_82169418:
	// stw r31,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r31.u32);
loc_8216941C:
	// lwz r3,100(r19)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r19.u32 + 100);
	// addi r30,r19,88
	ctx.r30.s64 = ctx.r19.s64 + 88;
	// lwz r5,104(r19)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r19.u32 + 104);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x8216943c
	if (!ctx.cr6.gt) goto loc_8216943C;
	// twi 31,r0,22
	// twi 31,r0,22
	// twi 31,r0,22
loc_8216943C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x82169450
	if (ctx.cr6.gt) goto loc_82169450;
	// cmplw cr6,r5,r5
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x82169454
	if (!ctx.cr6.gt) goto loc_82169454;
loc_82169450:
	// twi 31,r0,22
loc_82169454:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169464
	if (ctx.cr6.eq) goto loc_82169464;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82169468
	if (ctx.cr6.eq) goto loc_82169468;
loc_82169464:
	// twi 31,r0,22
loc_82169468:
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82169490
	if (ctx.cr6.eq) goto loc_82169490;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r3
	ctx.r31.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x8216948c
	if (!ctx.cr0.gt) goto loc_8216948C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x8216948C;
	sub_8207A520(ctx, base);
loc_8216948C:
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
loc_82169490:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x820803b0
	ctx.lr = 0x8216949C;
	__restfpr_27(ctx, base);
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821694A0"))) PPC_WEAK_FUNC(sub_821694A0);
PPC_FUNC_IMPL(__imp__sub_821694A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821694C4"))) PPC_WEAK_FUNC(sub_821694C4);
PPC_FUNC_IMPL(__imp__sub_821694C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821694C8"))) PPC_WEAK_FUNC(sub_821694C8);
PPC_FUNC_IMPL(__imp__sub_821694C8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_821694D8:
	// mullw r10,r3,r11
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// divw r3,r10,r4
	ctx.r3.s32 = ppc_divw(ctx.r10.s32, ctx.r4.s32);
	// bdnz 0x821694d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821694D8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821694E8"))) PPC_WEAK_FUNC(sub_821694E8);
PPC_FUNC_IMPL(__imp__sub_821694E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82169584
	if (ctx.cr6.eq) goto loc_82169584;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f13,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// clrldi r10,r4,32
	ctx.r10.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lfs f12,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f0,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f8
	ctx.f11.f64 = double(float(ctx.f8.f64));
	// lfs f7,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// lfs f5,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,76(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fdivs f10,f6,f11
	ctx.f10.f64 = double(float(ctx.f6.f64 / ctx.f11.f64));
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(ctx.f0.f64 - ctx.f10.f64));
	// fmuls f8,f13,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmuls f6,f12,f10
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fmuls f0,f7,f10
	ctx.f0.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmuls f13,f5,f10
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f10.f64));
	// fmadds f12,f4,f9,f8
	ctx.f12.f64 = double(float(ctx.f4.f64 * ctx.f9.f64 + ctx.f8.f64));
	// stfs f12,52(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fmadds f11,f3,f9,f6
	ctx.f11.f64 = double(float(ctx.f3.f64 * ctx.f9.f64 + ctx.f6.f64));
	// stfs f11,60(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// fmadds f10,f2,f9,f0
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f9.f64 + ctx.f0.f64));
	// stfs f10,56(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fmadds f9,f1,f9,f13
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f9.f64 + ctx.f13.f64));
	// stfs f9,64(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// blr 
	return;
loc_82169584:
	// lfs f0,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f13,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lfs f12,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,60(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// lfs f11,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,64(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821695A8"))) PPC_WEAK_FUNC(sub_821695A8);
PPC_FUNC_IMPL(__imp__sub_821695A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216963c
	if (ctx.cr6.eq) goto loc_8216963C;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f6,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// clrldi r10,r4,32
	ctx.r10.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lfs f5,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f5.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f0,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// frsp f2,f8
	ctx.f2.f64 = double(float(ctx.f8.f64));
	// lfs f13,76(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f4,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f1,f7,f2
	ctx.f1.f64 = double(float(ctx.f7.f64 / ctx.f2.f64));
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// fmuls f11,f6,f1
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// fmuls f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// fmuls f12,f12,f1
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f1.f64));
	// fmuls f10,f5,f0
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmuls f9,f4,f0
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f8,f3,f0
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fadds f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// stfs f7,52(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fadds f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// stfs f6,56(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fadds f5,f8,f11
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f11.f64));
	// stfs f5,60(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// blr 
	return;
loc_8216963C:
	// lfs f0,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f13,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lfs f12,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,60(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82169658"))) PPC_WEAK_FUNC(sub_82169658);
PPC_FUNC_IMPL(__imp__sub_82169658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821696b8
	if (ctx.cr6.eq) goto loc_821696B8;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f13,60(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// clrldi r10,r4,32
	ctx.r10.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lfs f12,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f0,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fsubs f4,f0,f5
	ctx.f4.f64 = double(float(ctx.f0.f64 - ctx.f5.f64));
	// fmuls f3,f13,f5
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// fmadds f2,f4,f12,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 + ctx.f3.f64));
	// stfs f2,52(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// blr 
	return;
loc_821696B8:
	// lfs f0,60(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821696C4"))) PPC_WEAK_FUNC(sub_821696C4);
PPC_FUNC_IMPL(__imp__sub_821696C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821696C8"))) PPC_WEAK_FUNC(sub_821696C8);
PPC_FUNC_IMPL(__imp__sub_821696C8) {
	PPC_FUNC_PROLOGUE();
	// subf r10,r3,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r3.s64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// beq cr6,0x821696e8
	if (ctx.cr6.eq) goto loc_821696E8;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_821696DC:
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// divw r11,r11,r4
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r4.s32);
	// bdnz 0x821696dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821696DC;
loc_821696E8:
	// subf r3,r11,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r11.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821696F0"))) PPC_WEAK_FUNC(sub_821696F0);
PPC_FUNC_IMPL(__imp__sub_821696F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216976c
	if (ctx.cr6.eq) goto loc_8216976C;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f13,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// clrldi r10,r4,32
	ctx.r10.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lfs f12,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f0,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// lfs f6,60(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f5.f64 = double(temp.f32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 / ctx.f4.f64));
	// fsubs f2,f0,f3
	ctx.f2.f64 = double(float(ctx.f0.f64 - ctx.f3.f64));
	// fmuls f1,f13,f3
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
	// fmuls f0,f12,f3
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f3.f64));
	// fmuls f13,f6,f2
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f2.f64));
	// fmuls f12,f5,f2
	ctx.f12.f64 = double(float(ctx.f5.f64 * ctx.f2.f64));
	// fadds f11,f13,f1
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// stfs f11,52(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f10,56(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// blr 
	return;
loc_8216976C:
	// lfs f0,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f13,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82169780"))) PPC_WEAK_FUNC(sub_82169780);
PPC_FUNC_IMPL(__imp__sub_82169780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82169788;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82169914
	if (ctx.cr6.eq) goto loc_82169914;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lwz r30,60(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// clrldi r10,r4,32
	ctx.r10.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r29,56(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	// fcfid f9,f0
	ctx.f9.f64 = double(ctx.f0.s64);
	// clrlwi r8,r29,24
	ctx.r8.u64 = ctx.r29.u32 & 0xFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f12
	ctx.f8.f64 = double(ctx.f12.s64);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// lfs f0,-21836(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// fdivs f31,f7,f5
	ctx.f31.f64 = double(float(ctx.f7.f64 / ctx.f5.f64));
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// fsubs f30,f0,f31
	ctx.f30.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmuls f2,f4,f31
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f31.f64));
	// fmadds f1,f3,f30,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f30.f64 + ctx.f2.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8216981C;
	sub_8206C5F8(ctx, base);
	// rlwinm r6,r29,8,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFF;
	// fctidz f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// rlwinm r5,r30,8,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// stfd f1,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f1.u64);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lwz r28,92(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f8,f10,f31
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fmadds f1,f9,f30,f8
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f30.f64 + ctx.f8.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8216985C;
	sub_8206C5F8(ctx, base);
	// rlwinm r4,r29,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 16) & 0xFF;
	// fctidz f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// rlwinm r3,r30,16,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFF;
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f6,88(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f5,88(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f3,f6
	ctx.f3.f64 = double(ctx.f6.s64);
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmuls f0,f2,f31
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f31.f64));
	// fmadds f1,f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f30.f64 + ctx.f0.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8216989C;
	sub_8206C5F8(ctx, base);
	// rlwinm r11,r29,24,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 24) & 0xFF;
	// fctidz f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// rlwinm r10,r30,24,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// lwz r30,84(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fmadds f1,f7,f30,f6
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f30.f64 + ctx.f6.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x821698DC;
	sub_8206C5F8(ctx, base);
	// rlwinm r9,r27,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 8) & 0xFFFFFF00;
	// fctidz f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f5.u64);
	// or r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 | ctx.r30.u64;
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r6,r8,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r28
	ctx.r3.u64 = ctx.r4.u64 | ctx.r28.u64;
	// stw r3,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r3.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82169914:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216992C"))) PPC_WEAK_FUNC(sub_8216992C);
PPC_FUNC_IMPL(__imp__sub_8216992C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82169930"))) PPC_WEAK_FUNC(sub_82169930);
PPC_FUNC_IMPL(__imp__sub_82169930) {
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
	// lbz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82169974
	if (!ctx.cr6.eq) goto loc_82169974;
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r30,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r30.u8);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
loc_82169974:
	// lbz r10,17(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 17);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82169990
	if (ctx.cr6.eq) goto loc_82169990;
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r11,17(r31)
	PPC_STORE_U8(ctx.r31.u32 + 17, ctx.r11.u8);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// b 0x82169a98
	goto loc_82169A98;
loc_82169990:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821699d8
	if (!ctx.cr6.eq) goto loc_821699D8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821699B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821699cc
	if (ctx.cr6.eq) goto loc_821699CC;
	// stb r30,17(r31)
	PPC_STORE_U8(ctx.r31.u32 + 17, ctx.r30.u8);
	// b 0x82169a98
	goto loc_82169A98;
loc_821699CC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x82169a98
	goto loc_82169A98;
loc_821699D8:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31328(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31328);
	// lbz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821699f4
	if (ctx.cr6.eq) goto loc_821699F4;
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82169a08
	goto loc_82169A08;
loc_821699F4:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
loc_82169A08:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82169a54
	if (ctx.cr6.lt) goto loc_82169A54;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82169abc
	if (ctx.cr6.eq) goto loc_82169ABC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bne 0x82169abc
	if (!ctx.cr0.eq) goto loc_82169ABC;
	// lbz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169ab0
	if (ctx.cr6.eq) goto loc_82169AB0;
	// stb r30,17(r31)
	PPC_STORE_U8(ctx.r31.u32 + 17, ctx.r30.u8);
loc_82169A54:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// lwz r30,20(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// divw r4,r7,r10
	ctx.r4.s32 = ppc_divw(ctx.r7.s32, ctx.r10.s32);
	// bl 0x82076aa8
	ctx.lr = 0x82169A74;
	sub_82076AA8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82169a98
	if (ctx.cr6.eq) goto loc_82169A98;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82169A90:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x82169A98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82169A98:
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
loc_82169AB0:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x82169a54
	goto loc_82169A54;
loc_82169ABC:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82169abc
	if (!ctx.cr6.lt) goto loc_82169ABC;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// divw r4,r8,r10
	ctx.r4.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	// bl 0x82076aa8
	ctx.lr = 0x82169AF0;
	sub_82076AA8(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// b 0x82169a90
	goto loc_82169A90;
}

__attribute__((alias("__imp__sub_82169B08"))) PPC_WEAK_FUNC(sub_82169B08);
PPC_FUNC_IMPL(__imp__sub_82169B08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82169B0C"))) PPC_WEAK_FUNC(sub_82169B0C);
PPC_FUNC_IMPL(__imp__sub_82169B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82169B10"))) PPC_WEAK_FUNC(sub_82169B10);
PPC_FUNC_IMPL(__imp__sub_82169B10) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82169B18"))) PPC_WEAK_FUNC(sub_82169B18);
PPC_FUNC_IMPL(__imp__sub_82169B18) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82169B20"))) PPC_WEAK_FUNC(sub_82169B20);
PPC_FUNC_IMPL(__imp__sub_82169B20) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82169B24"))) PPC_WEAK_FUNC(sub_82169B24);
PPC_FUNC_IMPL(__imp__sub_82169B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82169B28"))) PPC_WEAK_FUNC(sub_82169B28);
PPC_FUNC_IMPL(__imp__sub_82169B28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82169B34"))) PPC_WEAK_FUNC(sub_82169B34);
PPC_FUNC_IMPL(__imp__sub_82169B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82169B38"))) PPC_WEAK_FUNC(sub_82169B38);
PPC_FUNC_IMPL(__imp__sub_82169B38) {
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
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addi r11,r3,76
	ctx.r11.s64 = ctx.r3.s64 + 76;
	// lwz r9,88(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rlwinm r7,r8,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x82169b7c
	if (!ctx.cr6.eq) goto loc_82169B7C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82169B7C:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// srawi. r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82169b94
	if (!ctx.cr0.eq) goto loc_82169B94;
	// twi 31,r0,22
loc_82169B94:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// ble cr6,0x82169bb0
	if (!ctx.cr6.gt) goto loc_82169BB0;
	// twi 31,r0,22
loc_82169BB0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82076a10
	ctx.lr = 0x82169BCC;
	sub_82076A10(ctx, base);
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

__attribute__((alias("__imp__sub_82169BE0"))) PPC_WEAK_FUNC(sub_82169BE0);
PPC_FUNC_IMPL(__imp__sub_82169BE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,120(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r4,r3,76
	ctx.r4.s64 = ctx.r3.s64 + 76;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169c08
	if (ctx.cr6.eq) goto loc_82169C08;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_82169C08:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82169C18"))) PPC_WEAK_FUNC(sub_82169C18);
PPC_FUNC_IMPL(__imp__sub_82169C18) {
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
	// lbz r11,102(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 102);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82169c88
	if (!ctx.cr6.eq) goto loc_82169C88;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82169C48;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82169c88
	if (ctx.cr6.eq) goto loc_82169C88;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169c68
	if (ctx.cr6.eq) goto loc_82169C68;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_82169C68:
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r10,101(r31)
	PPC_STORE_U8(ctx.r31.u32 + 101, ctx.r10.u8);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
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
loc_82169C88:
	// lis r11,-32233
	ctx.r11.s64 = -2112421888;
	// addi r10,r11,-25824
	ctx.r10.s64 = ctx.r11.s64 + -25824;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82169CA8"))) PPC_WEAK_FUNC(sub_82169CA8);
PPC_FUNC_IMPL(__imp__sub_82169CA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82169CB0;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,113(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 113);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82169cf4
	if (!ctx.cr6.eq) goto loc_82169CF4;
	// lwz r3,120(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r4,r29,76
	ctx.r4.s64 = ctx.r29.s64 + 76;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82169ce0
	if (ctx.cr6.eq) goto loc_82169CE0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82169cec
	goto loc_82169CEC;
loc_82169CE0:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
loc_82169CEC:
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82169CF4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82169CF4:
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r23,r28
	ctx.r23.u64 = ctx.r28.u64;
	// bl 0x82169b38
	ctx.lr = 0x82169D0C;
	sub_82169B38(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169f1c
	if (ctx.cr6.eq) goto loc_82169F1C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82169D34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r22,1
	ctx.r22.s64 = 1;
	// li r25,2
	ctx.r25.s64 = 2;
	// mr r24,r22
	ctx.r24.u64 = ctx.r22.u64;
	// li r26,15
	ctx.r26.s64 = 15;
loc_82169D44:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r23.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mr r23,r30
	ctx.r23.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82169D70;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82169d90
	if (!ctx.cr6.eq) goto loc_82169D90;
	// lwz r11,40(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169eec
	if (ctx.cr6.eq) goto loc_82169EEC;
	// stw r25,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// b 0x82169eac
	goto loc_82169EAC;
loc_82169D90:
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169db0
	if (ctx.cr6.eq) goto loc_82169DB0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82169b38
	ctx.lr = 0x82169DA8;
	sub_82169B38(ctx, base);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
loc_82169DB0:
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169dd4
	if (ctx.cr6.eq) goto loc_82169DD4;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82169DD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82169DD4:
	// lbz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169e28
	if (ctx.cr6.eq) goto loc_82169E28;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r7,r1,92
	ctx.r7.s64 = ctx.r1.s64 + 92;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82169E04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82169f00
	if (ctx.cr6.eq) goto loc_82169F00;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a8a0
	ctx.lr = 0x82169E18;
	sub_8207A8A0(ctx, base);
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
loc_82169E28:
	// lwz r11,48(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82169e7c
	if (ctx.cr6.lt) goto loc_82169E7C;
	// bne cr6,0x82169e9c
	if (!ctx.cr6.eq) goto loc_82169E9C;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82079fd8
	ctx.lr = 0x82169E40;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82169e6c
	if (ctx.cr6.eq) goto loc_82169E6C;
	// lwz r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r25,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r25.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821743d8
	ctx.lr = 0x82169E60;
	sub_821743D8(ctx, base);
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// b 0x82169e9c
	goto loc_82169E9C;
loc_82169E6C:
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// b 0x82169e9c
	goto loc_82169E9C;
loc_82169E7C:
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,36(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169e9c
	if (ctx.cr6.eq) goto loc_82169E9C;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82169E9C:
	// lwz r11,40(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169eac
	if (ctx.cr6.eq) goto loc_82169EAC;
	// stw r22,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r22.u32);
loc_82169EAC:
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82169ec4
	if (ctx.cr6.lt) goto loc_82169EC4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82169EC4;
	sub_8207A630(ctx, base);
loc_82169EC4:
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// stb r28,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r28.u8);
	// bl 0x8207a630
	ctx.lr = 0x82169ED8;
	sub_8207A630(ctx, base);
	// clrlwi r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82169d44
	if (!ctx.cr6.eq) goto loc_82169D44;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_82169EEC:
	// stb r22,102(r29)
	PPC_STORE_U8(ctx.r29.u32 + 102, ctx.r22.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820769a8
	ctx.lr = 0x82169EF8;
	sub_820769A8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_82169F00:
	// stb r22,102(r29)
	PPC_STORE_U8(ctx.r29.u32 + 102, ctx.r22.u8);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820769a8
	ctx.lr = 0x82169F0C;
	sub_820769A8(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82169f1c
	if (ctx.cr6.eq) goto loc_82169F1C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820769a8
	ctx.lr = 0x82169F1C;
	sub_820769A8(ctx, base);
loc_82169F1C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82169F24"))) PPC_WEAK_FUNC(sub_82169F24);
PPC_FUNC_IMPL(__imp__sub_82169F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82169F28"))) PPC_WEAK_FUNC(sub_82169F28);
PPC_FUNC_IMPL(__imp__sub_82169F28) {
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
	// lbz r11,102(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 102);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82169f58
	if (ctx.cr6.eq) goto loc_82169F58;
	// lis r11,-32233
	ctx.r11.s64 = -2112421888;
	// addi r10,r11,-25824
	ctx.r10.s64 = ctx.r11.s64 + -25824;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
loc_82169F58:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82169fdc
	if (ctx.cr6.eq) goto loc_82169FDC;
	// li r3,36
	ctx.r3.s64 = 36;
	// lwz r30,104(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// bl 0x82079fd8
	ctx.lr = 0x82169F7C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x82169fc0
	if (ctx.cr6.eq) goto loc_82169FC0;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// lis r9,-32233
	ctx.r9.s64 = -2112421888;
	// stw r31,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r31.u32);
	// addi r8,r10,6224
	ctx.r8.s64 = ctx.r10.s64 + 6224;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r7,r9,-25432
	ctx.r7.s64 = ctx.r9.s64 + -25432;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
	// stb r11,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r11.u8);
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// b 0x82169fc4
	goto loc_82169FC4;
loc_82169FC0:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_82169FC4:
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_82169FDC:
	// lbz r11,113(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 113);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82169ff4
	if (!ctx.cr6.eq) goto loc_82169FF4;
	// lis r11,-32233
	ctx.r11.s64 = -2112421888;
	// addi r10,r11,-25576
	ctx.r10.s64 = ctx.r11.s64 + -25576;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82169FF4:
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

__attribute__((alias("__imp__sub_8216A00C"))) PPC_WEAK_FUNC(sub_8216A00C);
PPC_FUNC_IMPL(__imp__sub_8216A00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A010"))) PPC_WEAK_FUNC(sub_8216A010);
PPC_FUNC_IMPL(__imp__sub_8216A010) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216A018;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,120(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,6072
	ctx.r10.s64 = ctx.r11.s64 + 6072;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8216a04c
	if (ctx.cr6.eq) goto loc_8216A04C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A04C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216A04C:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r30,r31,76
	ctx.r30.s64 = ctx.r31.s64 + 76;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216a060
	if (ctx.cr6.eq) goto loc_8216A060;
	// bl 0x8207a630
	ctx.lr = 0x8216A060;
	sub_8207A630(ctx, base);
loc_8216A060:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// bl 0x8207a630
	ctx.lr = 0x8216A078;
	sub_8207A630(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x8216A08C;
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
	ctx.lr = 0x8216A0A4;
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

__attribute__((alias("__imp__sub_8216A0B4"))) PPC_WEAK_FUNC(sub_8216A0B4);
PPC_FUNC_IMPL(__imp__sub_8216A0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A0B8"))) PPC_WEAK_FUNC(sub_8216A0B8);
PPC_FUNC_IMPL(__imp__sub_8216A0B8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r11.u8);
	// addi r4,r9,-12408
	ctx.r4.s64 = ctx.r9.s64 + -12408;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820601f8
	ctx.lr = 0x8216A0F4;
	sub_820601F8(ctx, base);
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

__attribute__((alias("__imp__sub_8216A10C"))) PPC_WEAK_FUNC(sub_8216A10C);
PPC_FUNC_IMPL(__imp__sub_8216A10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A110"))) PPC_WEAK_FUNC(sub_8216A110);
PPC_FUNC_IMPL(__imp__sub_8216A110) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,-12408
	ctx.r3.s64 = ctx.r11.s64 + -12408;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x8216A13C;
	sub_820601F8(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8216a150
	if (ctx.cr6.lt) goto loc_8216A150;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8216A150;
	sub_8207A630(ctx, base);
loc_8216A150:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
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

__attribute__((alias("__imp__sub_8216A178"))) PPC_WEAK_FUNC(sub_8216A178);
PPC_FUNC_IMPL(__imp__sub_8216A178) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8216A180;
	__savegprlr_28(ctx, base);
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
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r4,r7,6072
	ctx.r4.s64 = ctx.r7.s64 + 6072;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r29,r31,76
	ctx.r29.s64 = ctx.r31.s64 + 76;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// stb r28,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r28.u8);
	// stb r28,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r28.u8);
	// bl 0x82079fd8
	ctx.lr = 0x8216A218;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216a228
	if (ctx.cr6.eq) goto loc_8216A228;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8216a22c
	goto loc_8216A22C;
loc_8216A228:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8216A22C:
	// lis r11,-32233
	ctx.r11.s64 = -2112421888;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-24792
	ctx.r10.s64 = ctx.r11.s64 + -24792;
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stb r30,100(r31)
	PPC_STORE_U8(ctx.r31.u32 + 100, ctx.r30.u8);
	// stb r30,101(r31)
	PPC_STORE_U8(ctx.r31.u32 + 101, ctx.r30.u8);
	// stb r30,102(r31)
	PPC_STORE_U8(ctx.r31.u32 + 102, ctx.r30.u8);
	// stw r28,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r28.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stb r30,113(r31)
	PPC_STORE_U8(ctx.r31.u32 + 113, ctx.r30.u8);
	// stw r30,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216A274"))) PPC_WEAK_FUNC(sub_8216A274);
PPC_FUNC_IMPL(__imp__sub_8216A274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A278"))) PPC_WEAK_FUNC(sub_8216A278);
PPC_FUNC_IMPL(__imp__sub_8216A278) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	// lwz r10,76(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A28C"))) PPC_WEAK_FUNC(sub_8216A28C);
PPC_FUNC_IMPL(__imp__sub_8216A28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A290"))) PPC_WEAK_FUNC(sub_8216A290);
PPC_FUNC_IMPL(__imp__sub_8216A290) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A294"))) PPC_WEAK_FUNC(sub_8216A294);
PPC_FUNC_IMPL(__imp__sub_8216A294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A298"))) PPC_WEAK_FUNC(sub_8216A298);
PPC_FUNC_IMPL(__imp__sub_8216A298) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A2BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A2D0"))) PPC_WEAK_FUNC(sub_8216A2D0);
PPC_FUNC_IMPL(__imp__sub_8216A2D0) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A2F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f1,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A308"))) PPC_WEAK_FUNC(sub_8216A308);
PPC_FUNC_IMPL(__imp__sub_8216A308) {
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
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f13,76(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A320"))) PPC_WEAK_FUNC(sub_8216A320);
PPC_FUNC_IMPL(__imp__sub_8216A320) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A324"))) PPC_WEAK_FUNC(sub_8216A324);
PPC_FUNC_IMPL(__imp__sub_8216A324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A328"))) PPC_WEAK_FUNC(sub_8216A328);
PPC_FUNC_IMPL(__imp__sub_8216A328) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A358;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8216A370;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fadds f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f11.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f10,8(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f9,12(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
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

__attribute__((alias("__imp__sub_8216A3B4"))) PPC_WEAK_FUNC(sub_8216A3B4);
PPC_FUNC_IMPL(__imp__sub_8216A3B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A3B8"))) PPC_WEAK_FUNC(sub_8216A3B8);
PPC_FUNC_IMPL(__imp__sub_8216A3B8) {
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
	// std r4,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r4.u64);
	// lfs f30,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f31.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stfs f30,84(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r5.u64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A400;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fsubs f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8216A430;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
}

__attribute__((alias("__imp__sub_8216A44C"))) PPC_WEAK_FUNC(sub_8216A44C);
PPC_FUNC_IMPL(__imp__sub_8216A44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A450"))) PPC_WEAK_FUNC(sub_8216A450);
PPC_FUNC_IMPL(__imp__sub_8216A450) {
	PPC_FUNC_PROLOGUE();
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
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r6,r10,-1396
	ctx.r6.s64 = ctx.r10.s64 + -1396;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r5,r9,840
	ctx.r5.s64 = ctx.r9.s64 + 840;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r9,r8,16
	ctx.r9.s64 = ctx.r8.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// addi r4,r7,6000
	ctx.r4.s64 = ctx.r7.s64 + 6000;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
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
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r10,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r10.u8);
	// stb r10,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r10.u8);
	// stb r10,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A4D8"))) PPC_WEAK_FUNC(sub_8216A4D8);
PPC_FUNC_IMPL(__imp__sub_8216A4D8) {
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
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
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
	// addi r8,r7,6036
	ctx.r8.s64 = ctx.r7.s64 + 6036;
	// stw r4,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lfs f0,21768(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21768);
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
	// stb r10,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r10.u8);
	// stb r10,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r10.u8);
	// stb r10,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r10.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,72(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f0,76(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A570"))) PPC_WEAK_FUNC(sub_8216A570);
PPC_FUNC_IMPL(__imp__sub_8216A570) {
	PPC_FUNC_PROLOGUE();
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
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r6,r10,-1396
	ctx.r6.s64 = ctx.r10.s64 + -1396;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r5,r9,840
	ctx.r5.s64 = ctx.r9.s64 + 840;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r9,r8,16
	ctx.r9.s64 = ctx.r8.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// addi r8,r7,6036
	ctx.r8.s64 = ctx.r7.s64 + 6036;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
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
	// stb r10,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r10.u8);
	// std r4,72(r3)
	PPC_STORE_U64(ctx.r3.u32 + 72, ctx.r4.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A5FC"))) PPC_WEAK_FUNC(sub_8216A5FC);
PPC_FUNC_IMPL(__imp__sub_8216A5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A600"))) PPC_WEAK_FUNC(sub_8216A600);
PPC_FUNC_IMPL(__imp__sub_8216A600) {
	PPC_FUNC_PROLOGUE();
	// stw r4,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A608"))) PPC_WEAK_FUNC(sub_8216A608);
PPC_FUNC_IMPL(__imp__sub_8216A608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A610"))) PPC_WEAK_FUNC(sub_8216A610);
PPC_FUNC_IMPL(__imp__sub_8216A610) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A618"))) PPC_WEAK_FUNC(sub_8216A618);
PPC_FUNC_IMPL(__imp__sub_8216A618) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,84(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// lwz r10,88(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A62C"))) PPC_WEAK_FUNC(sub_8216A62C);
PPC_FUNC_IMPL(__imp__sub_8216A62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A630"))) PPC_WEAK_FUNC(sub_8216A630);
PPC_FUNC_IMPL(__imp__sub_8216A630) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A634"))) PPC_WEAK_FUNC(sub_8216A634);
PPC_FUNC_IMPL(__imp__sub_8216A634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A638"))) PPC_WEAK_FUNC(sub_8216A638);
PPC_FUNC_IMPL(__imp__sub_8216A638) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A63C"))) PPC_WEAK_FUNC(sub_8216A63C);
PPC_FUNC_IMPL(__imp__sub_8216A63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A640"))) PPC_WEAK_FUNC(sub_8216A640);
PPC_FUNC_IMPL(__imp__sub_8216A640) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A648"))) PPC_WEAK_FUNC(sub_8216A648);
PPC_FUNC_IMPL(__imp__sub_8216A648) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A650"))) PPC_WEAK_FUNC(sub_8216A650);
PPC_FUNC_IMPL(__imp__sub_8216A650) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A658"))) PPC_WEAK_FUNC(sub_8216A658);
PPC_FUNC_IMPL(__imp__sub_8216A658) {
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
	// stfs f0,84(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f13,88(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A670"))) PPC_WEAK_FUNC(sub_8216A670);
PPC_FUNC_IMPL(__imp__sub_8216A670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r7,0
	ctx.r7.s64 = 0;
	// srawi r6,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 1;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// extsw r4,r4
	ctx.r4.s64 = ctx.r4.s32;
	// addze r9,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r6,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 1;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// srawi r9,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 1;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// addze r6,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r6.s64 = temp.s64;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// neg r4,r6
	ctx.r4.s64 = -ctx.r6.s64;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// stfs f9,84(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// stfs f10,88(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// fcfid f5,f7
	ctx.f5.f64 = double(ctx.f7.s64);
	// lfs f0,21768(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// stfs f4,80(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// stfs f3,76(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// stfs f3,92(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 92, temp.u32);
	// lfs f1,80(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,96(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f13,84(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// stfs f13,100(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 100, temp.u32);
	// lfs f12,88(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// stb r7,124(r11)
	PPC_STORE_U8(ctx.r11.u32 + 124, ctx.r7.u8);
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,128(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 128, temp.u32);
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,132(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r11.u32 + 132, temp.u32);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f4,-16(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f2,f5
	ctx.f2.f64 = double(ctx.f5.s64);
	// stfs f0,136(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 136, temp.u32);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// stfs f0,140(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// frsp f0,f2
	ctx.f0.f64 = double(float(ctx.f2.f64));
	// stfs f0,148(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// stfs f1,144(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A7B8"))) PPC_WEAK_FUNC(sub_8216A7B8);
PPC_FUNC_IMPL(__imp__sub_8216A7B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f13,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r8,48
	ctx.r8.s64 = 48;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lfs f0,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r11,48
	ctx.r10.s64 = ctx.r11.s64 + 48;
	// stfs f13,76(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// lfs f12,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// lfs f11,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,84(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// lfs f10,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,88(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// lfs f9,60(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,92(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 92, temp.u32);
	// lfs f8,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,96(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f7,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,100(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r11.u32 + 100, temp.u32);
	// lfs f6,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,104(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// lbz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// stb r7,124(r11)
	PPC_STORE_U8(ctx.r11.u32 + 124, ctx.r7.u8);
	// lfs f5,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,128(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r11.u32 + 128, temp.u32);
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// lfs f3,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,132(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 132, temp.u32);
	// stfs f0,136(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 136, temp.u32);
	// stfs f0,140(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// stfs f5,144(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// stfs f3,148(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r6,60(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// divw. r4,r5,r8
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// addi r11,r9,-48
	ctx.r11.s64 = ctx.r9.s64 + -48;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216A85C"))) PPC_WEAK_FUNC(sub_8216A85C);
PPC_FUNC_IMPL(__imp__sub_8216A85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A860"))) PPC_WEAK_FUNC(sub_8216A860);
PPC_FUNC_IMPL(__imp__sub_8216A860) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8216a894
	if (!ctx.cr6.eq) goto loc_8216A894;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A894;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216A894:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8216a8bc
	if (ctx.cr6.eq) goto loc_8216A8BC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d2f8
	ctx.lr = 0x8216A8BC;
	sub_8216D2F8(ctx, base);
loc_8216A8BC:
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

__attribute__((alias("__imp__sub_8216A8D0"))) PPC_WEAK_FUNC(sub_8216A8D0);
PPC_FUNC_IMPL(__imp__sub_8216A8D0) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,5988
	ctx.r9.s64 = ctx.r10.s64 + 5988;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216a910
	if (ctx.cr6.eq) goto loc_8216A910;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x8216a914
	if (!ctx.cr6.eq) goto loc_8216A914;
loc_8216A910:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8216A914:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216a92c
	if (ctx.cr6.eq) goto loc_8216A92C;
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d120
	ctx.lr = 0x8216A92C;
	sub_8216D120(ctx, base);
loc_8216A92C:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8207a630
	ctx.lr = 0x8216A934;
	sub_8207A630(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x8207a8a0
	ctx.lr = 0x8216A93C;
	sub_8207A8A0(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216a95c
	if (ctx.cr6.eq) goto loc_8216A95C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A95C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216A95C:
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

__attribute__((alias("__imp__sub_8216A97C"))) PPC_WEAK_FUNC(sub_8216A97C);
PPC_FUNC_IMPL(__imp__sub_8216A97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216A980"))) PPC_WEAK_FUNC(sub_8216A980);
PPC_FUNC_IMPL(__imp__sub_8216A980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8216A988;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216A9B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,80(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r5,120(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 120);
	// addi r31,r29,96
	ctx.r31.s64 = ctx.r29.s64 + 96;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// lwz r7,112(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 112);
	// lwz r6,108(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 108);
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// lwz r4,24(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// subf r3,r6,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r6.s64;
	// lwz r11,20(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// stw r5,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r5.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// srawi. r7,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 5;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lwz r9,92(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// stw r5,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r5.u32);
	// frsp f30,f11
	ctx.f30.f64 = double(float(ctx.f11.f64));
	// stw r5,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r5.u32);
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// frsp f31,f12
	ctx.f31.f64 = double(float(ctx.f12.f64));
	// beq 0x8216ab70
	if (ctx.cr0.eq) goto loc_8216AB70;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
loc_8216AA2C:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 5;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8216aa48
	if (ctx.cr6.lt) goto loc_8216AA48;
	// twi 31,r0,22
loc_8216AA48:
	// add r9,r29,r10
	ctx.r9.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwzx r6,r29,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r11.s64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// srawi r3,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 5;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r4,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r4.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r9.u32);
	// blt cr6,0x8216aa8c
	if (ctx.cr6.lt) goto loc_8216AA8C;
	// twi 31,r0,22
loc_8216AA8C:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f7,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f12,f31,f9
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f9.f64));
	// fmuls f11,f30,f7
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f7.f64));
	// lfs f6,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f5.f64 = double(temp.f32);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r5,12(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// fmsubs f2,f31,f6,f12
	ctx.f2.f64 = double(float(ctx.f31.f64 * ctx.f6.f64 - ctx.f12.f64));
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r5,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// fmsubs f12,f30,f5,f11
	ctx.f12.f64 = double(float(ctx.f30.f64 * ctx.f5.f64 - ctx.f11.f64));
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// lfs f11,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// lfs f3,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f5,f8,f3,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f3.f64 + ctx.f13.f64));
	// lfs f4,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f9,f8,f11,f13
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fmadds f7,f10,f1,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f0.f64));
	// stfs f7,152(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmadds f6,f10,f4,f0
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f4.f64 + ctx.f0.f64));
	// stfs f9,156(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f6,164(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f2,136(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f9,168(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f6,176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f5,180(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f7,188(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f5,192(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// bl 0x8216daa0
	ctx.lr = 0x8216AB50;
	sub_8216DAA0(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,32
	ctx.r29.s64 = ctx.r29.s64 + 32;
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8216aa2c
	if (ctx.cr6.lt) goto loc_8216AA2C;
loc_8216AB70:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216AB80"))) PPC_WEAK_FUNC(sub_8216AB80);
PPC_FUNC_IMPL(__imp__sub_8216AB80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216AB88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82075840
	ctx.lr = 0x8216ABA4;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820758e8
	ctx.lr = 0x8216ABB0;
	sub_820758E8(ctx, base);
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// lfs f0,76(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// lfs f13,80(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,48(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// lfs f12,84(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,52(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// lfs f11,88(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,56(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// lfs f10,92(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,60(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r30.u32 + 60, temp.u32);
	// lfs f9,96(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,64(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r30.u32 + 64, temp.u32);
	// lfs f8,100(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,68(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 68, temp.u32);
	// lfs f7,104(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,72(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 72, temp.u32);
	// lbz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 124);
	// stb r10,76(r30)
	PPC_STORE_U8(ctx.r30.u32 + 76, ctx.r10.u8);
	// lfs f6,128(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,80(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 80, temp.u32);
	// lfs f5,132(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,84(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r30.u32 + 84, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216AC14"))) PPC_WEAK_FUNC(sub_8216AC14);
PPC_FUNC_IMPL(__imp__sub_8216AC14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216AC18"))) PPC_WEAK_FUNC(sub_8216AC18);
PPC_FUNC_IMPL(__imp__sub_8216AC18) {
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
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,18
	ctx.r9.s64 = 1179648;
	// li r11,640
	ctx.r11.s64 = 640;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r3,r9,51712
	ctx.r3.u64 = ctx.r9.u64 | 51712;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// addi r8,r10,5988
	ctx.r8.s64 = ctx.r10.s64 + 5988;
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// li r7,480
	ctx.r7.s64 = 480;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// li r6,512
	ctx.r6.s64 = 512;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r30,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r30.u8);
	// stw r7,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r7.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r6,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// bl 0x8207a030
	ctx.lr = 0x8216AC78;
	sub_8207A030(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// bl 0x8207da20
	ctx.lr = 0x8216AC88;
	sub_8207DA20(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,-31312(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -31312);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216e1b8
	ctx.lr = 0x8216ACB4;
	sub_8216E1B8(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82079fd8
	ctx.lr = 0x8216ACC0;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8216acdc
	if (ctx.cr6.eq) goto loc_8216ACDC;
	// stb r30,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// b 0x8216ace0
	goto loc_8216ACE0;
loc_8216ACDC:
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
loc_8216ACE0:
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

__attribute__((alias("__imp__sub_8216ACF8"))) PPC_WEAK_FUNC(sub_8216ACF8);
PPC_FUNC_IMPL(__imp__sub_8216ACF8) {
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
	// bl 0x8216ab80
	ctx.lr = 0x8216AD10;
	sub_8216AB80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8216a670
	ctx.lr = 0x8216AD18;
	sub_8216A670(ctx, base);
	// bl 0x8216a860
	ctx.lr = 0x8216AD1C;
	sub_8216A860(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8216a7b8
	ctx.lr = 0x8216AD24;
	sub_8216A7B8(ctx, base);
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

__attribute__((alias("__imp__sub_8216AD38"))) PPC_WEAK_FUNC(sub_8216AD38);
PPC_FUNC_IMPL(__imp__sub_8216AD38) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// ld r11,-31392(r10)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + -31392);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// std r9,-31392(r10)
	PPC_STORE_U64(ctx.r10.u32 + -31392, ctx.r9.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216AD4C"))) PPC_WEAK_FUNC(sub_8216AD4C);
PPC_FUNC_IMPL(__imp__sub_8216AD4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216AD50"))) PPC_WEAK_FUNC(sub_8216AD50);
PPC_FUNC_IMPL(__imp__sub_8216AD50) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216AD54"))) PPC_WEAK_FUNC(sub_8216AD54);
PPC_FUNC_IMPL(__imp__sub_8216AD54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216AD58"))) PPC_WEAK_FUNC(sub_8216AD58);
PPC_FUNC_IMPL(__imp__sub_8216AD58) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216AD60"))) PPC_WEAK_FUNC(sub_8216AD60);
PPC_FUNC_IMPL(__imp__sub_8216AD60) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216AD68"))) PPC_WEAK_FUNC(sub_8216AD68);
PPC_FUNC_IMPL(__imp__sub_8216AD68) {
	PPC_FUNC_PROLOGUE();
	// lwz r4,504(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 504);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x8209ab80
	sub_8209AB80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216AD74"))) PPC_WEAK_FUNC(sub_8216AD74);
PPC_FUNC_IMPL(__imp__sub_8216AD74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216AD78"))) PPC_WEAK_FUNC(sub_8216AD78);
PPC_FUNC_IMPL(__imp__sub_8216AD78) {
	PPC_FUNC_PROLOGUE();
	// lwz r4,500(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 500);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x8209ad40
	sub_8209AD40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216AD84"))) PPC_WEAK_FUNC(sub_8216AD84);
PPC_FUNC_IMPL(__imp__sub_8216AD84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216AD88"))) PPC_WEAK_FUNC(sub_8216AD88);
PPC_FUNC_IMPL(__imp__sub_8216AD88) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8209af10
	sub_8209AF10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216AD94"))) PPC_WEAK_FUNC(sub_8216AD94);
PPC_FUNC_IMPL(__imp__sub_8216AD94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216AD98"))) PPC_WEAK_FUNC(sub_8216AD98);
PPC_FUNC_IMPL(__imp__sub_8216AD98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8216ADA0;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,32
	ctx.r11.s64 = 32;
	// li r26,1
	ctx.r26.s64 = 1;
	// stw r11,544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 544, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r26.u32);
	// addi r5,r3,152
	ctx.r5.s64 = ctx.r3.s64 + 152;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820a5b80
	ctx.lr = 0x8216ADCC;
	sub_820A5B80(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8216ade4
	if (ctx.cr6.eq) goto loc_8216ADE4;
loc_8216ADD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8216ADE4:
	// addi r27,r31,12
	ctx.r27.s64 = ctx.r31.s64 + 12;
	// li r5,124
	ctx.r5.s64 = 124;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207da20
	ctx.lr = 0x8216ADF8;
	sub_8207DA20(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r11,r11,-12560
	ctx.r11.s64 = ctx.r11.s64 + -12560;
	// lfs f31,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r8,84(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// lfs f0,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// lwz r29,76(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// beq cr6,0x8216ae48
	if (ctx.cr6.eq) goto loc_8216AE48;
	// lwz r11,536(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 / ctx.f0.f64));
	// stfs f10,556(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 556, temp.u32);
loc_8216AE48:
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// bne cr6,0x8216ae60
	if (!ctx.cr6.eq) goto loc_8216AE60;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x8216ae60
	if (ctx.cr6.eq) goto loc_8216AE60;
	// stfs f0,560(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 560, temp.u32);
loc_8216AE60:
	// li r10,6
	ctx.r10.s64 = 6;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r1,104
	ctx.r11.s64 = ctx.r1.s64 + 104;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8216AE74:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x8216ae74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216AE74;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d5184
	ctx.lr = 0x8216AE84;
	__imp__XGetVideoMode(ctx, base);
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// bne cr6,0x8216af6c
	if (!ctx.cr6.eq) goto loc_8216AF6C;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r9,124(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f13,f10,f9
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// beq cr6,0x8216aed8
	if (ctx.cr6.eq) goto loc_8216AED8;
	// lfs f13,20(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
loc_8216AED8:
	// lwz r9,536(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// lfs f0,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// extsw r6,r11
	ctx.r6.s64 = ctx.r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// fmuls f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// fmuls f0,f6,f0
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x8216af6c
	if (ctx.cr6.lt) goto loc_8216AF6C;
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// addi r11,r31,456
	ctx.r11.s64 = ctx.r31.s64 + 456;
	// li r6,464
	ctx.r6.s64 = 464;
	// fctiwz f12,f0
	ctx.f12.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r9,468(r31)
	PPC_STORE_U32(ctx.r31.u32 + 468, ctx.r9.u32);
	// stw r7,472(r31)
	PPC_STORE_U32(ctx.r31.u32 + 472, ctx.r7.u32);
	// addi r9,r31,104
	ctx.r9.s64 = ctx.r31.s64 + 104;
	// stw r8,476(r31)
	PPC_STORE_U32(ctx.r31.u32 + 476, ctx.r8.u32);
	// stfiwx f12,0,r11
	PPC_STORE_U32(ctx.r11.u32, ctx.f12.u32);
	// stw r30,460(r31)
	PPC_STORE_U32(ctx.r31.u32 + 460, ctx.r30.u32);
	// stw r30,480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 480, ctx.r30.u32);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fctiwz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f11,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.f11.u32);
loc_8216AF60:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8216af60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216AF60;
loc_8216AF6C:
	// lwz r11,532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// lis r10,6184
	ctx.r10.s64 = 405274624;
	// lwz r9,536(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// lis r8,10280
	ctx.r8.s64 = 673710080;
	// ori r7,r10,390
	ctx.r7.u64 = ctx.r10.u64 | 390;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// ori r6,r8,262
	ctx.r6.u64 = ctx.r8.u64 | 262;
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// addi r28,r31,8
	ctx.r28.s64 = ctx.r31.s64 + 8;
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r26,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r26,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r26.u32);
	// bl 0x820a4ac0
	ctx.lr = 0x8216AFCC;
	sub_820A4AC0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8216add4
	if (!ctx.cr6.eq) goto loc_8216ADD4;
	// stb r26,552(r31)
	PPC_STORE_U8(ctx.r31.u32 + 552, ctx.r26.u8);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r30,r11,-22608
	ctx.r30.s64 = ctx.r11.s64 + -22608;
	// addi r3,r30,-1520
	ctx.r3.s64 = ctx.r30.s64 + -1520;
	// bl 0x8209b498
	ctx.lr = 0x8216AFE8;
	sub_8209B498(ctx, base);
	// stw r3,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r3.u32);
	// addi r3,r30,-1152
	ctx.r3.s64 = ctx.r30.s64 + -1152;
	// bl 0x8209b498
	ctx.lr = 0x8216AFF4;
	sub_8209B498(ctx, base);
	// stw r3,500(r31)
	PPC_STORE_U32(ctx.r31.u32 + 500, ctx.r3.u32);
	// addi r3,r30,-680
	ctx.r3.s64 = ctx.r30.s64 + -680;
	// bl 0x8209b2b0
	ctx.lr = 0x8216B000;
	sub_8209B2B0(ctx, base);
	// stw r3,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r3.u32);
	// addi r3,r30,-360
	ctx.r3.s64 = ctx.r30.s64 + -360;
	// bl 0x8209b2b0
	ctx.lr = 0x8216B00C;
	sub_8209B2B0(ctx, base);
	// stw r3,508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 508, ctx.r3.u32);
	// addi r3,r30,-48
	ctx.r3.s64 = ctx.r30.s64 + -48;
	// bl 0x8209b018
	ctx.lr = 0x8216B018;
	sub_8209B018(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8209b018
	ctx.lr = 0x8216B024;
	sub_8209B018(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r10,5972
	ctx.r6.s64 = ctx.r10.s64 + 5972;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,496(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 496);
	// bl 0x820a05a0
	ctx.lr = 0x8216B044;
	sub_820A05A0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,500(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 500);
	// addi r6,r9,5976
	ctx.r6.s64 = ctx.r9.s64 + 5976;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820a05a0
	ctx.lr = 0x8216B060;
	sub_820A05A0(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8216b070
	if (ctx.cr6.eq) goto loc_8216B070;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820a4400
	ctx.lr = 0x8216B070;
	sub_820A4400(ctx, base);
loc_8216B070:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8216b080
	if (ctx.cr6.eq) goto loc_8216B080;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820a4400
	ctx.lr = 0x8216B080;
	sub_820A4400(ctx, base);
loc_8216B080:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x82099388
	ctx.lr = 0x8216B08C;
	sub_82099388(ctx, base);
	// stw r3,484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 484, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216B0A0"))) PPC_WEAK_FUNC(sub_8216B0A0);
PPC_FUNC_IMPL(__imp__sub_8216B0A0) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// std r5,532(r3)
	PPC_STORE_U64(ctx.r3.u32 + 532, ctx.r5.u64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r4,540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 540, ctx.r4.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stb r6,553(r3)
	PPC_STORE_U8(ctx.r3.u32 + 553, ctx.r6.u8);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r8,5980
	ctx.r7.s64 = ctx.r8.s64 + 5980;
	// lfs f0,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lfs f13,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f0,556(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 556, temp.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stfs f13,560(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 560, temp.u32);
	// stw r11,484(r3)
	PPC_STORE_U32(ctx.r3.u32 + 484, ctx.r11.u32);
	// stw r11,488(r3)
	PPC_STORE_U32(ctx.r3.u32 + 488, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, ctx.r11.u32);
	// bl 0x8216ad98
	ctx.lr = 0x8216B100;
	sub_8216AD98(ctx, base);
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

__attribute__((alias("__imp__sub_8216B118"))) PPC_WEAK_FUNC(sub_8216B118);
PPC_FUNC_IMPL(__imp__sub_8216B118) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r9,5984
	ctx.r8.s64 = ctx.r9.s64 + 5984;
	// lwz r11,-31304(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31304);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,-31304(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31304, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B138"))) PPC_WEAK_FUNC(sub_8216B138);
PPC_FUNC_IMPL(__imp__sub_8216B138) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-31304(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31304, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B148"))) PPC_WEAK_FUNC(sub_8216B148);
PPC_FUNC_IMPL(__imp__sub_8216B148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8216B150;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8209b098
	ctx.lr = 0x8216B16C;
	sub_8209B098(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a9718
	ctx.lr = 0x8216B174;
	sub_820A9718(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r11,-31492
	ctx.r30.s64 = ctx.r11.s64 + -31492;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lbz r11,134(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 134);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216b228
	if (!ctx.cr6.eq) goto loc_8216B228;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// ori r9,r10,32768
	ctx.r9.u64 = ctx.r10.u64 | 32768;
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// lis r8,32
	ctx.r8.s64 = 2097152;
	// stb r11,134(r30)
	PPC_STORE_U8(ctx.r30.u32 + 134, ctx.r11.u8);
	// li r7,128
	ctx.r7.s64 = 128;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a92e0
	ctx.lr = 0x8216B1CC;
	sub_820A92E0(ctx, base);
	// lis r6,-32233
	ctx.r6.s64 = -2112421888;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r4,r6,-21192
	ctx.r4.s64 = ctx.r6.s64 + -21192;
	// bl 0x820a4f78
	ctx.lr = 0x8216B1DC;
	sub_820A4F78(ctx, base);
	// li r4,100
	ctx.r4.s64 = 100;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82098698
	ctx.lr = 0x8216B1E8;
	sub_82098698(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097510
	ctx.lr = 0x8216B1F4;
	sub_82097510(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// std r29,100(r30)
	PPC_STORE_U64(ctx.r30.u32 + 100, ctx.r29.u64);
	// std r29,84(r30)
	PPC_STORE_U64(ctx.r30.u32 + 84, ctx.r29.u64);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r9,-31400(r28)
	PPC_STORE_U32(ctx.r28.u32 + -31400, ctx.r9.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a4f80
	ctx.lr = 0x8216B21C;
	sub_820A4F80(ctx, base);
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82098688
	ctx.lr = 0x8216B228;
	sub_82098688(ctx, base);
loc_8216B228:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8216b258
	if (!ctx.cr6.eq) goto loc_8216B258;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a9268
	ctx.lr = 0x8216B23C;
	sub_820A9268(ctx, base);
	// ld r10,84(r30)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r30.u32 + 84);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
loc_8216B244:
	// ld r9,-31392(r11)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r11.u32 + -31392);
	// cmpld cr6,r9,r10
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r10.u64, ctx.xer);
	// beq cr6,0x8216b244
	if (ctx.cr6.eq) goto loc_8216B244;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// std r10,100(r30)
	PPC_STORE_U64(ctx.r30.u32 + 100, ctx.r10.u64);
loc_8216B258:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8216b2c8
	if (ctx.cr6.eq) goto loc_8216B2C8;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8216b2c8
	if (ctx.cr6.eq) goto loc_8216B2C8;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82099410
	ctx.lr = 0x8216B270;
	sub_82099410(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f1.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820a2280
	ctx.lr = 0x8216B2A8;
	sub_820A2280(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a5408
	ctx.lr = 0x8216B2B8;
	sub_820A5408(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820a4400
	ctx.lr = 0x8216B2C0;
	sub_820A4400(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x8216b2d0
	goto loc_8216B2D0;
loc_8216B2C8:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a5a68
	ctx.lr = 0x8216B2D0;
	sub_820A5A68(ctx, base);
loc_8216B2D0:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8216b2f4
	if (!ctx.cr6.eq) goto loc_8216B2F4;
	// ld r11,84(r30)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r30.u32 + 84);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
loc_8216B2E4:
	// ld r8,-31392(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + -31392);
	// cmpld cr6,r8,r11
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r11.u64, ctx.xer);
	// beq cr6,0x8216b2e4
	if (ctx.cr6.eq) goto loc_8216B2E4;
	// std r11,100(r30)
	PPC_STORE_U64(ctx.r30.u32 + 100, ctx.r11.u64);
loc_8216B2F4:
	// lwz r11,-31400(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31400);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216b388
	if (ctx.cr6.eq) goto loc_8216B388;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x8216b388
	if (ctx.cr6.gt) goto loc_8216B388;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8216b324
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8216B324;
	// bdzf 4*cr6+eq,0x8216b344
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8216B344;
	// bdzf 4*cr6+eq,0x8216b364
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8216B364;
	// bne cr6,0x8216b324
	if (!ctx.cr6.eq) goto loc_8216B324;
loc_8216B324:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a4f80
	ctx.lr = 0x8216B330;
	sub_820A4F80(ctx, base);
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82098688
	ctx.lr = 0x8216B33C;
	sub_82098688(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8216b380
	goto loc_8216B380;
loc_8216B344:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a4f80
	ctx.lr = 0x8216B350;
	sub_820A4F80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82098688
	ctx.lr = 0x8216B35C;
	sub_82098688(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8216b380
	goto loc_8216B380;
loc_8216B364:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a4f80
	ctx.lr = 0x8216B370;
	sub_820A4F80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82098688
	ctx.lr = 0x8216B37C;
	sub_82098688(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
loc_8216B380:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097510
	ctx.lr = 0x8216B388;
	sub_82097510(ctx, base);
loc_8216B388:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x8216b39c
	if (!ctx.cr6.lt) goto loc_8216B39C;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820a4710
	ctx.lr = 0x8216B39C;
	sub_820A4710(ctx, base);
loc_8216B39C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216B3A4"))) PPC_WEAK_FUNC(sub_8216B3A4);
PPC_FUNC_IMPL(__imp__sub_8216B3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B3A8"))) PPC_WEAK_FUNC(sub_8216B3A8);
PPC_FUNC_IMPL(__imp__sub_8216B3A8) {
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
	// lwz r3,496(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216b3d8
	if (ctx.cr6.eq) goto loc_8216B3D8;
	// bl 0x820a4400
	ctx.lr = 0x8216B3D4;
	sub_820A4400(ctx, base);
	// stw r30,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r30.u32);
loc_8216B3D8:
	// lwz r3,500(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 500);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216b3ec
	if (ctx.cr6.eq) goto loc_8216B3EC;
	// bl 0x820a4400
	ctx.lr = 0x8216B3E8;
	sub_820A4400(ctx, base);
	// stw r30,500(r31)
	PPC_STORE_U32(ctx.r31.u32 + 500, ctx.r30.u32);
loc_8216B3EC:
	// lwz r3,504(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 504);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216b400
	if (ctx.cr6.eq) goto loc_8216B400;
	// bl 0x820a4400
	ctx.lr = 0x8216B3FC;
	sub_820A4400(ctx, base);
	// stw r30,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r30.u32);
loc_8216B400:
	// lwz r3,508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 508);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216b414
	if (ctx.cr6.eq) goto loc_8216B414;
	// bl 0x820a4400
	ctx.lr = 0x8216B410;
	sub_820A4400(ctx, base);
	// stw r30,508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 508, ctx.r30.u32);
loc_8216B414:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216b428
	if (ctx.cr6.eq) goto loc_8216B428;
	// bl 0x820a46b8
	ctx.lr = 0x8216B424;
	sub_820A46B8(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_8216B428:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216b438
	if (ctx.cr6.eq) goto loc_8216B438;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_8216B438:
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

__attribute__((alias("__imp__sub_8216B450"))) PPC_WEAK_FUNC(sub_8216B450);
PPC_FUNC_IMPL(__imp__sub_8216B450) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,5980
	ctx.r10.s64 = ctx.r11.s64 + 5980;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8216b3a8
	sub_8216B3A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216B460"))) PPC_WEAK_FUNC(sub_8216B460);
PPC_FUNC_IMPL(__imp__sub_8216B460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B468"))) PPC_WEAK_FUNC(sub_8216B468);
PPC_FUNC_IMPL(__imp__sub_8216B468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B470"))) PPC_WEAK_FUNC(sub_8216B470);
PPC_FUNC_IMPL(__imp__sub_8216B470) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,84(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// lwz r10,88(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B484"))) PPC_WEAK_FUNC(sub_8216B484);
PPC_FUNC_IMPL(__imp__sub_8216B484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B488"))) PPC_WEAK_FUNC(sub_8216B488);
PPC_FUNC_IMPL(__imp__sub_8216B488) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B48C"))) PPC_WEAK_FUNC(sub_8216B48C);
PPC_FUNC_IMPL(__imp__sub_8216B48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B490"))) PPC_WEAK_FUNC(sub_8216B490);
PPC_FUNC_IMPL(__imp__sub_8216B490) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B494"))) PPC_WEAK_FUNC(sub_8216B494);
PPC_FUNC_IMPL(__imp__sub_8216B494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B498"))) PPC_WEAK_FUNC(sub_8216B498);
PPC_FUNC_IMPL(__imp__sub_8216B498) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B4A0"))) PPC_WEAK_FUNC(sub_8216B4A0);
PPC_FUNC_IMPL(__imp__sub_8216B4A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B4A8"))) PPC_WEAK_FUNC(sub_8216B4A8);
PPC_FUNC_IMPL(__imp__sub_8216B4A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B4B0"))) PPC_WEAK_FUNC(sub_8216B4B0);
PPC_FUNC_IMPL(__imp__sub_8216B4B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216b4d0
	if (ctx.cr6.eq) goto loc_8216B4D0;
	// lwz r11,156(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_8216B4D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B4D8"))) PPC_WEAK_FUNC(sub_8216B4D8);
PPC_FUNC_IMPL(__imp__sub_8216B4D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B4E8"))) PPC_WEAK_FUNC(sub_8216B4E8);
PPC_FUNC_IMPL(__imp__sub_8216B4E8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B4F8"))) PPC_WEAK_FUNC(sub_8216B4F8);
PPC_FUNC_IMPL(__imp__sub_8216B4F8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r10,r11,136
	ctx.r10.s64 = ctx.r11.s64 + 136;
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// lwz r8,140(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// lwz r7,144(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// lwz r6,148(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 148);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B528"))) PPC_WEAK_FUNC(sub_8216B528);
PPC_FUNC_IMPL(__imp__sub_8216B528) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r1,32
	ctx.r11.s64 = ctx.r1.s64 + 32;
	// std r4,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r4.u64);
	// std r5,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r5.u64);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B558"))) PPC_WEAK_FUNC(sub_8216B558);
PPC_FUNC_IMPL(__imp__sub_8216B558) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B55C"))) PPC_WEAK_FUNC(sub_8216B55C);
PPC_FUNC_IMPL(__imp__sub_8216B55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B560"))) PPC_WEAK_FUNC(sub_8216B560);
PPC_FUNC_IMPL(__imp__sub_8216B560) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B564"))) PPC_WEAK_FUNC(sub_8216B564);
PPC_FUNC_IMPL(__imp__sub_8216B564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B568"))) PPC_WEAK_FUNC(sub_8216B568);
PPC_FUNC_IMPL(__imp__sub_8216B568) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r10,r11,92
	ctx.r10.s64 = ctx.r11.s64 + 92;
	// lwz r9,92(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// lwz r8,96(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// lwz r6,104(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B598"))) PPC_WEAK_FUNC(sub_8216B598);
PPC_FUNC_IMPL(__imp__sub_8216B598) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,80(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r7,84(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B5C8"))) PPC_WEAK_FUNC(sub_8216B5C8);
PPC_FUNC_IMPL(__imp__sub_8216B5C8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,-31308(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31308);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B5D4"))) PPC_WEAK_FUNC(sub_8216B5D4);
PPC_FUNC_IMPL(__imp__sub_8216B5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B5D8"))) PPC_WEAK_FUNC(sub_8216B5D8);
PPC_FUNC_IMPL(__imp__sub_8216B5D8) {
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
	// stfs f0,84(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f13,88(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B5F0"))) PPC_WEAK_FUNC(sub_8216B5F0);
PPC_FUNC_IMPL(__imp__sub_8216B5F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 136, temp.u32);
	// stfs f0,140(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// stfs f1,144(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// stfs f2,148(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B614"))) PPC_WEAK_FUNC(sub_8216B614);
PPC_FUNC_IMPL(__imp__sub_8216B614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B618"))) PPC_WEAK_FUNC(sub_8216B618);
PPC_FUNC_IMPL(__imp__sub_8216B618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r3,16(r1)
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.r3.u64);
	// lfs f13,20(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// lfs f12,24(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B64C"))) PPC_WEAK_FUNC(sub_8216B64C);
PPC_FUNC_IMPL(__imp__sub_8216B64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B650"))) PPC_WEAK_FUNC(sub_8216B650);
PPC_FUNC_IMPL(__imp__sub_8216B650) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r10,r11,48
	ctx.r10.s64 = ctx.r11.s64 + 48;
	// lwz r8,60(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r11,64(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// addi r11,r11,-48
	ctx.r11.s64 = ctx.r11.s64 + -48;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B680"))) PPC_WEAK_FUNC(sub_8216B680);
PPC_FUNC_IMPL(__imp__sub_8216B680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// lfs f13,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f12,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f11,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,104(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B6A4"))) PPC_WEAK_FUNC(sub_8216B6A4);
PPC_FUNC_IMPL(__imp__sub_8216B6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B6A8"))) PPC_WEAK_FUNC(sub_8216B6A8);
PPC_FUNC_IMPL(__imp__sub_8216B6A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// addi r9,r11,-12560
	ctx.r9.s64 = ctx.r11.s64 + -12560;
	// lwz r10,64(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r11,68(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// addi r11,r3,76
	ctx.r11.s64 = ctx.r3.s64 + 76;
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// frsp f0,f11
	ctx.f0.f64 = double(float(ctx.f11.f64));
	// bne cr6,0x8216b710
	if (!ctx.cr6.eq) goto loc_8216B710;
	// lfs f12,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fmuls f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f8,f0,f11
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// b 0x8216b72c
	goto loc_8216B72C;
loc_8216B710:
	// lfs f12,36(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// lfs f12,40(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f11,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f8,f0,f12
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
loc_8216B72C:
	// fmuls f7,f13,f11
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// stfs f7,88(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f8,84(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f9,80(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f10,76(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f11,12(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,104(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B764"))) PPC_WEAK_FUNC(sub_8216B764);
PPC_FUNC_IMPL(__imp__sub_8216B764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B768"))) PPC_WEAK_FUNC(sub_8216B768);
PPC_FUNC_IMPL(__imp__sub_8216B768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r7,0
	ctx.r7.s64 = 0;
	// srawi r6,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 1;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// srawi r6,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 1;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// extsw r4,r4
	ctx.r4.s64 = ctx.r4.s32;
	// addze r9,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r6,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 1;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// srawi r9,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 1;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// neg r8,r10
	ctx.r8.s64 = -ctx.r10.s64;
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// addze r6,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r6.s64 = temp.s64;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// neg r4,r6
	ctx.r4.s64 = -ctx.r6.s64;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// stfs f9,84(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// stfs f10,88(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// fcfid f5,f7
	ctx.f5.f64 = double(ctx.f7.s64);
	// lfs f0,21768(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// stfs f4,80(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// addi r10,r11,76
	ctx.r10.s64 = ctx.r11.s64 + 76;
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// stfs f3,76(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// stfs f3,92(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 92, temp.u32);
	// lfs f1,80(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,96(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f13,84(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// stfs f13,100(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 100, temp.u32);
	// lfs f12,88(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// stb r7,124(r11)
	PPC_STORE_U8(ctx.r11.u32 + 124, ctx.r7.u8);
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,128(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 128, temp.u32);
	// lwz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stfs f6,132(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r11.u32 + 132, temp.u32);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f4,-16(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f2,f5
	ctx.f2.f64 = double(ctx.f5.s64);
	// stfs f0,136(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 136, temp.u32);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// stfs f0,140(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// frsp f0,f2
	ctx.f0.f64 = double(float(ctx.f2.f64));
	// stfs f0,148(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// stfs f1,144(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B8B0"))) PPC_WEAK_FUNC(sub_8216B8B0);
PPC_FUNC_IMPL(__imp__sub_8216B8B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f13,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r8,48
	ctx.r8.s64 = 48;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lfs f0,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r11,48
	ctx.r10.s64 = ctx.r11.s64 + 48;
	// stfs f13,76(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// lfs f12,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// lfs f11,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,84(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// lfs f10,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,88(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// lfs f9,60(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,92(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 92, temp.u32);
	// lfs f8,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,96(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 96, temp.u32);
	// lfs f7,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,100(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r11.u32 + 100, temp.u32);
	// lfs f6,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,104(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r11.u32 + 104, temp.u32);
	// lbz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// stb r7,124(r11)
	PPC_STORE_U8(ctx.r11.u32 + 124, ctx.r7.u8);
	// lfs f5,80(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,128(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r11.u32 + 128, temp.u32);
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// lfs f3,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,132(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 132, temp.u32);
	// stfs f0,136(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 136, temp.u32);
	// stfs f0,140(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 140, temp.u32);
	// stfs f5,144(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r11.u32 + 144, temp.u32);
	// stfs f3,148(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + 148, temp.u32);
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r6,60(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// divw. r4,r5,r8
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// addi r11,r9,-48
	ctx.r11.s64 = ctx.r9.s64 + -48;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216B954"))) PPC_WEAK_FUNC(sub_8216B954);
PPC_FUNC_IMPL(__imp__sub_8216B954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216B958"))) PPC_WEAK_FUNC(sub_8216B958);
PPC_FUNC_IMPL(__imp__sub_8216B958) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r3,r11,48
	ctx.r3.s64 = ctx.r11.s64 + 48;
	// bl 0x82075840
	ctx.lr = 0x8216B97C;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8216B98C;
	sub_8207DAC0(ctx, base);
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

__attribute__((alias("__imp__sub_8216B9A0"))) PPC_WEAK_FUNC(sub_8216B9A0);
PPC_FUNC_IMPL(__imp__sub_8216B9A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216B9A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8216b9d0
	if (!ctx.cr6.eq) goto loc_8216B9D0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216B9D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216B9D0:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x8216ba5c
	if (ctx.cr6.eq) goto loc_8216BA5C;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r29,r11,-31136
	ctx.r29.s64 = ctx.r11.s64 + -31136;
	// lwz r11,-31324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216ba04
	if (ctx.cr6.eq) goto loc_8216BA04;
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8216ba08
	if (!ctx.cr6.eq) goto loc_8216BA08;
loc_8216BA04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8216BA08:
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// ori r4,r4,65280
	ctx.r4.u64 = ctx.r4.u64 | 65280;
	// bl 0x8216e808
	ctx.lr = 0x8216BA14;
	sub_8216E808(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r5,92(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 92);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d2f8
	ctx.lr = 0x8216BA30;
	sub_8216D2F8(ctx, base);
	// lwz r11,-31324(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216ba48
	if (ctx.cr6.eq) goto loc_8216BA48;
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216ba4c
	if (!ctx.cr6.eq) goto loc_8216BA4C;
loc_8216BA48:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8216BA4C:
	// lis r4,-1
	ctx.r4.s64 = -65536;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// ori r4,r4,255
	ctx.r4.u64 = ctx.r4.u64 | 255;
	// bl 0x8216e808
	ctx.lr = 0x8216BA5C;
	sub_8216E808(ctx, base);
loc_8216BA5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216BA64"))) PPC_WEAK_FUNC(sub_8216BA64);
PPC_FUNC_IMPL(__imp__sub_8216BA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216BA68"))) PPC_WEAK_FUNC(sub_8216BA68);
PPC_FUNC_IMPL(__imp__sub_8216BA68) {
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
	// lwz r4,92(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r11,5960
	ctx.r9.s64 = ctx.r11.s64 + 5960;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r11,-31312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d120
	ctx.lr = 0x8216BA9C;
	sub_8216D120(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8207a630
	ctx.lr = 0x8216BAA4;
	sub_8207A630(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x8207a8a0
	ctx.lr = 0x8216BAAC;
	sub_8207A8A0(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216bacc
	if (ctx.cr6.eq) goto loc_8216BACC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216BACC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216BACC:
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

__attribute__((alias("__imp__sub_8216BAEC"))) PPC_WEAK_FUNC(sub_8216BAEC);
PPC_FUNC_IMPL(__imp__sub_8216BAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216BAF0"))) PPC_WEAK_FUNC(sub_8216BAF0);
PPC_FUNC_IMPL(__imp__sub_8216BAF0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216BAF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,152(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,5944
	ctx.r9.s64 = ctx.r11.s64 + 5944;
	// addi r8,r10,5952
	ctx.r8.s64 = ctx.r10.s64 + 5952;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216bb40
	if (ctx.cr6.eq) goto loc_8216BB40;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216BB3C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r29.u32);
loc_8216BB40:
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216bb64
	if (ctx.cr6.eq) goto loc_8216BB64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216BB60;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
loc_8216BB64:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216bb78
	if (ctx.cr6.eq) goto loc_8216BB78;
	// bl 0x8207a630
	ctx.lr = 0x8216BB78;
	sub_8207A630(ctx, base);
loc_8216BB78:
	// stw r29,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r29.u32);
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
	// stw r29,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8216BB8C;
	sub_8207A630(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r10,r11,5720
	ctx.r10.s64 = ctx.r11.s64 + 5720;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r7,-31328(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31328);
	// addi r3,r7,88
	ctx.r3.s64 = ctx.r7.s64 + 88;
	// bl 0x82173a70
	ctx.lr = 0x8216BBAC;
	sub_82173A70(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216bbd0
	if (ctx.cr6.eq) goto loc_8216BBD0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216BBCC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,-31328(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31328);
loc_8216BBD0:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r7,60
	ctx.r3.s64 = ctx.r7.s64 + 60;
	// addi r10,r11,5700
	ctx.r10.s64 = ctx.r11.s64 + 5700;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82173a70
	ctx.lr = 0x8216BBE8;
	sub_82173A70(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216bc08
	if (ctx.cr6.eq) goto loc_8216BC08;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216BC08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216BC08:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216BC10"))) PPC_WEAK_FUNC(sub_8216BC10);
PPC_FUNC_IMPL(__imp__sub_8216BC10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8216BC18;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8208035c
	ctx.lr = 0x8216BC20;
	__savefpr_25(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216BC40;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,80(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// stw r11,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r11.u32);
	// lwz r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r6,20(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// addi r10,r1,164
	ctx.r10.s64 = ctx.r1.s64 + 164;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// lwz r4,92(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// stw r11,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r11.u32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r28,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r28.u32);
	// stw r4,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r4.u32);
	// frsp f29,f11
	ctx.f29.f64 = double(float(ctx.f11.f64));
	// frsp f30,f12
	ctx.f30.f64 = double(float(ctx.f12.f64));
loc_8216BCA8:
	// stwu r11,12(r10)
	ea = 12 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8216bca8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216BCA8;
	// lwz r11,112(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 112);
	// addi r31,r30,96
	ctx.r31.s64 = ctx.r30.s64 + 96;
	// lwz r10,108(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 108);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 5;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8216be74
	if (ctx.cr0.eq) goto loc_8216BE74;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// lfs f28,104(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,100(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	ctx.f27.f64 = double(temp.f32);
	// lfs f31,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
loc_8216BCE4:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 5;
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8216bd00
	if (ctx.cr6.lt) goto loc_8216BD00;
	// twi 31,r0,22
loc_8216BD00:
	// add r9,r28,r10
	ctx.r9.u64 = ctx.r28.u64 + ctx.r10.u64;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwzx r6,r28,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// subf r5,r11,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r11.s64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// srawi r3,r5,5
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 5;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r4,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r4.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r9.u32);
	// blt cr6,0x8216bd44
	if (ctx.cr6.lt) goto loc_8216BD44;
	// twi 31,r0,22
loc_8216BD44:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// fmuls f26,f30,f0
	ctx.f26.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// addi r6,r11,16
	ctx.r6.s64 = ctx.r11.s64 + 16;
	// fmuls f25,f29,f13
	ctx.f25.f64 = double(float(ctx.f29.f64 * ctx.f13.f64));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,24(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r7,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
	// fmsubs f10,f30,f12,f26
	ctx.f10.f64 = double(float(ctx.f30.f64 * ctx.f12.f64 - ctx.f26.f64));
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmsubs f9,f29,f11,f25
	ctx.f9.f64 = double(float(ctx.f29.f64 * ctx.f11.f64 - ctx.f25.f64));
	// stfs f9,156(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r5,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r5.u32);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x8216BDB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// lfs f8,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// fnmsubs f7,f8,f31,f27
	ctx.f7.f64 = double(float(-(ctx.f8.f64 * ctx.f31.f64 - ctx.f27.f64)));
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// fadds f6,f7,f26
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f26.f64));
	// stfs f6,160(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bctrl 
	ctx.lr = 0x8216BDDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f5,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f3,f5,f31,f28
	ctx.f3.f64 = double(float(-(ctx.f5.f64 * ctx.f31.f64 - ctx.f28.f64)));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-31312(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31312);
	// lfs f4,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lfs f2,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 - ctx.f0.f64));
	// fsubs f12,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 - ctx.f13.f64));
	// lfs f11,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f9.f64 = double(temp.f32);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// lfs f8,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f3,f25
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f25.f64));
	// stfs f7,164(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmadds f6,f1,f11,f0
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f11.f64 + ctx.f0.f64));
	// stfs f6,168(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmadds f5,f12,f10,f13
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f13.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fmadds f4,f1,f9,f0
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f9.f64 + ctx.f0.f64));
	// stfs f4,180(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmadds f3,f12,f8,f13
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f13.f64));
	// stfs f5,184(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f4,192(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f3,196(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f6,204(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f3,208(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// bl 0x8216daa0
	ctx.lr = 0x8216BE54;
	sub_8216DAA0(ctx, base);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,32
	ctx.r28.s64 = ctx.r28.s64 + 32;
	// subf r4,r5,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r5.s64;
	// srawi r3,r4,5
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 5;
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8216bce4
	if (ctx.cr6.lt) goto loc_8216BCE4;
loc_8216BE74:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803a8
	ctx.lr = 0x8216BE80;
	__restfpr_25(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216BE84"))) PPC_WEAK_FUNC(sub_8216BE84);
PPC_FUNC_IMPL(__imp__sub_8216BE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216BE88"))) PPC_WEAK_FUNC(sub_8216BE88);
PPC_FUNC_IMPL(__imp__sub_8216BE88) {
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
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82075840
	ctx.lr = 0x8216BEAC;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820758e8
	ctx.lr = 0x8216BEB8;
	sub_820758E8(ctx, base);
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

__attribute__((alias("__imp__sub_8216BECC"))) PPC_WEAK_FUNC(sub_8216BECC);
PPC_FUNC_IMPL(__imp__sub_8216BECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216BED0"))) PPC_WEAK_FUNC(sub_8216BED0);
PPC_FUNC_IMPL(__imp__sub_8216BED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8216BED8;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r8,8
	ctx.r8.s64 = 8;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// rotlwi r9,r3,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r31,104(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// vupkd3d128 v60,v63,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v60 = vTemp;
	// li r11,4
	ctx.r11.s64 = 4;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// vpermwi128 v63,v60,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x15));
	// lvsr v0,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// vpermwi128 v62,v60,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x45));
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// vpermwi128 v61,v60,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x51));
	// vperm128 v59,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vperm128 v58,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r29,104(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r30,16
	ctx.r30.s64 = 16;
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// vperm128 v57,v61,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r27,20
	ctx.r27.s64 = 20;
	// vpermwi128 v60,v60,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x54));
	// stvewx128 v59,r0,r29
	ea = (ctx.r29.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v59.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r26,r1,112
	ctx.r26.s64 = ctx.r1.s64 + 112;
	// stvewx128 v59,r7,r6
	ea = (ctx.r7.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v59.u32[3 - ((ea & 0xF) >> 2)]);
	// li r25,24
	ctx.r25.s64 = 24;
	// stvewx128 v59,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v59.u32[3 - ((ea & 0xF) >> 2)]);
	// li r7,28
	ctx.r7.s64 = 28;
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stvewx128 v59,r31,r3
	ea = (ctx.r31.u32 + ctx.r3.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v59.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stvewx128 v58,r8,r30
	ea = (ctx.r8.u32 + ctx.r30.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v58.u32[3 - ((ea & 0xF) >> 2)]);
	// li r4,32
	ctx.r4.s64 = 32;
	// stvewx128 v58,r28,r27
	ea = (ctx.r28.u32 + ctx.r27.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v58.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v58,r26,r25
	ea = (ctx.r26.u32 + ctx.r25.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v58.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r10,36
	ctx.r10.s64 = 36;
	// vperm128 v56,v60,v60,v0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvewx128 v58,r29,r7
	ea = (ctx.r29.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v58.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r31,40
	ctx.r31.s64 = 40;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stvewx128 v57,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v57.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r30,44
	ctx.r30.s64 = 44;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stvewx128 v57,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v57.u32[3 - ((ea & 0xF) >> 2)]);
	// li r4,48
	ctx.r4.s64 = 48;
	// stvewx128 v57,r8,r31
	ea = (ctx.r8.u32 + ctx.r31.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v57.u32[3 - ((ea & 0xF) >> 2)]);
	// rotlwi r5,r5,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// li r10,52
	ctx.r10.s64 = 52;
	// stvewx128 v57,r7,r30
	ea = (ctx.r7.u32 + ctx.r30.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v57.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r8,r5,-12
	ctx.r8.s64 = ctx.r5.s64 + -12;
	// stvewx128 v56,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v56.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,56
	ctx.r6.s64 = 56;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,60
	ctx.r4.s64 = 60;
	// stvewx128 v56,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v56.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r9,r9,28
	ctx.r9.s64 = ctx.r9.s64 + 28;
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stvewx128 v56,r7,r6
	ea = (ctx.r7.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v56.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stvewx128 v56,r5,r4
	ea = (ctx.r5.u32 + ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v56.u32[3 - ((ea & 0xF) >> 2)]);
loc_8216C020:
	// lfs f13,-28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	ctx.f12.f64 = double(temp.f32);
	// lfsu f0,4(r11)
	ea = 4 + ctx.r11.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// stfs f13,8(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stfs f12,12(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// stfsu f0,16(r10)
	temp.f32 = float(ctx.f0.f64);
	ea = 16 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8216c020
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216C020;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// ld r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// ld r5,120(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r11,-12560
	ctx.r3.s64 = ctx.r11.s64 + -12560;
	// ld r6,128(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// ld r7,136(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// addi r31,r10,-2064
	ctx.r31.s64 = ctx.r10.s64 + -2064;
	// ld r8,144(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// ld r9,152(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// ld r10,160(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// extsw r3,r11
	ctx.r3.s64 = ctx.r11.s32;
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lfs f0,28(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// std r3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r3.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,168(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// ld r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x8216dd68
	ctx.lr = 0x8216C0A4;
	sub_8216DD68(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216C0AC"))) PPC_WEAK_FUNC(sub_8216C0AC);
PPC_FUNC_IMPL(__imp__sub_8216C0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C0B0"))) PPC_WEAK_FUNC(sub_8216C0B0);
PPC_FUNC_IMPL(__imp__sub_8216C0B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216C0B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82075840
	ctx.lr = 0x8216C0D4;
	sub_82075840(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820758e8
	ctx.lr = 0x8216C0E0;
	sub_820758E8(ctx, base);
	// lwz r11,-31312(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31312);
	// lfs f0,76(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// lfs f13,80(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,48(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// lfs f12,84(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,52(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// lfs f11,88(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,56(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// lfs f10,92(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,60(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r30.u32 + 60, temp.u32);
	// lfs f9,96(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,64(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r30.u32 + 64, temp.u32);
	// lfs f8,100(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,68(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 68, temp.u32);
	// lfs f7,104(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,72(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 72, temp.u32);
	// lbz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 124);
	// stb r10,76(r30)
	PPC_STORE_U8(ctx.r30.u32 + 76, ctx.r10.u8);
	// lfs f6,128(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,80(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 80, temp.u32);
	// lfs f5,132(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,84(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r30.u32 + 84, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216C144"))) PPC_WEAK_FUNC(sub_8216C144);
PPC_FUNC_IMPL(__imp__sub_8216C144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C148"))) PPC_WEAK_FUNC(sub_8216C148);
PPC_FUNC_IMPL(__imp__sub_8216C148) {
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
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82075840
	ctx.lr = 0x8216C164;
	sub_82075840(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x8216C170;
	sub_8207DAC0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8216bed0
	ctx.lr = 0x8216C178;
	sub_8216BED0(ctx, base);
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

__attribute__((alias("__imp__sub_8216C18C"))) PPC_WEAK_FUNC(sub_8216C18C);
PPC_FUNC_IMPL(__imp__sub_8216C18C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C190"))) PPC_WEAK_FUNC(sub_8216C190);
PPC_FUNC_IMPL(__imp__sub_8216C190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r3,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, ctx.r3.u64);
	// lfs f13,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f0,272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f31,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f13,260(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lwz r31,-31312(r8)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31312);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x82167518
	ctx.lr = 0x8216C208;
	sub_82167518(ctx, base);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f7.f64 = double(temp.f32);
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
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f8,104(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f7,108(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x82167618
	ctx.lr = 0x8216C254;
	sub_82167618(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821676b0
	ctx.lr = 0x8216C264;
	sub_821676B0(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = ctx.r31.s64 + 48;
	// bl 0x82075840
	ctx.lr = 0x8216C26C;
	sub_82075840(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x8207dac0
	ctx.lr = 0x8216C278;
	sub_8207DAC0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8216bed0
	ctx.lr = 0x8216C280;
	sub_8216BED0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_8216C298"))) PPC_WEAK_FUNC(sub_8216C298);
PPC_FUNC_IMPL(__imp__sub_8216C298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a4b8
	ctx.lr = 0x8216C2B8;
	sub_8208A4B8(ctx, base);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fcfid f31,f0
	ctx.f31.f64 = double(ctx.f0.s64);
	// bl 0x8208a498
	ctx.lr = 0x8216C2C8;
	sub_8208A498(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r11,-31000(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31000);
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8216c2fc
	if (!ctx.cr6.eq) goto loc_8216C2FC;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stfd f13,-31008(r9)
	PPC_STORE_U64(ctx.r9.u32 + -31008, ctx.f13.u64);
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// stw r11,-31000(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31000, ctx.r11.u32);
	// b 0x8216c300
	goto loc_8216C300;
loc_8216C2FC:
	// lfd f0,-31008(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + -31008);
loc_8216C300:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// fsub f12,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64 - ctx.f0.f64;
	// lwz r10,-31024(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31024);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-31024(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31024, ctx.r10.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// blt cr6,0x8216c344
	if (ctx.cr6.lt) goto loc_8216C344;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// addi r7,r8,-31136
	ctx.r7.s64 = ctx.r8.s64 + -31136;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
loc_8216C328:
	// fadd f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 + ctx.f31.f64;
	// fsub f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 - ctx.f0.f64;
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// bge cr6,0x8216c328
	if (!ctx.cr6.lt) goto loc_8216C328;
	// li r10,0
	ctx.r10.s64 = 0;
	// stfd f0,-31008(r9)
	PPC_STORE_U64(ctx.r9.u32 + -31008, ctx.f0.u64);
	// stw r10,-31024(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31024, ctx.r10.u32);
loc_8216C344:
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lfs f13,-21836(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,21768(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ble cr6,0x8216c39c
	if (!ctx.cr6.gt) goto loc_8216C39C;
	// twi 31,r0,22
loc_8216C39C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x8216c3b4
	if (!ctx.cr6.gt) goto loc_8216C3B4;
	// twi 31,r0,22
loc_8216C3B4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82075ab8
	ctx.lr = 0x8216C3D0;
	sub_82075AB8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8216bed0
	ctx.lr = 0x8216C3D8;
	sub_8216BED0(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820758e8
	ctx.lr = 0x8216C3E4;
	sub_820758E8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_8216C3FC"))) PPC_WEAK_FUNC(sub_8216C3FC);
PPC_FUNC_IMPL(__imp__sub_8216C3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C400"))) PPC_WEAK_FUNC(sub_8216C400);
PPC_FUNC_IMPL(__imp__sub_8216C400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8216C408;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x82170550
	ctx.lr = 0x8216C418;
	sub_82170550(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x82170450
	ctx.lr = 0x8216C420;
	sub_82170450(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,5944
	ctx.r9.s64 = ctx.r11.s64 + 5944;
	// addi r8,r10,5952
	ctx.r8.s64 = ctx.r10.s64 + 5952;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r8,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
	// bl 0x82079fd8
	ctx.lr = 0x8216C444;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216c458
	if (ctx.cr6.eq) goto loc_8216C458;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x8216c45c
	goto loc_8216C45C;
loc_8216C458:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8216C45C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// stw r29,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r29.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
	// stb r11,44(r31)
	PPC_STORE_U8(ctx.r31.u32 + 44, ctx.r11.u8);
	// bl 0x8216b6a8
	ctx.lr = 0x8216C480;
	sub_8216B6A8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stb r29,124(r31)
	PPC_STORE_U8(ctx.r31.u32 + 124, ctx.r29.u8);
	// li r3,564
	ctx.r3.s64 = 564;
	// addi r30,r11,-12560
	ctx.r30.s64 = ctx.r11.s64 + -12560;
	// lwz r11,64(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,128(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// lwz r11,68(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// stw r29,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r29.u32);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,132(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// stw r29,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8216C4D4;
	sub_82079FD8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r28,r11,-31136
	ctx.r28.s64 = ctx.r11.s64 + -31136;
	// beq cr6,0x8216c4f8
	if (ctx.cr6.eq) goto loc_8216C4F8;
	// lbz r6,72(r30)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r30.u32 + 72);
	// ld r5,64(r30)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r30.u32 + 64);
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// bl 0x8216b0a0
	ctx.lr = 0x8216C4F4;
	sub_8216B0A0(ctx, base);
	// b 0x8216c4fc
	goto loc_8216C4FC;
loc_8216C4F8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8216C4FC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r3.u32);
	// li r3,544
	ctx.r3.s64 = 544;
	// stw r31,-31312(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31312, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8216C510;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216c53c
	if (ctx.cr6.eq) goto loc_8216C53C;
	// lbz r6,72(r30)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r30.u32 + 72);
	// ld r5,64(r30)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r30.u32 + 64);
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// bl 0x8216e428
	ctx.lr = 0x8216C528;
	sub_8216E428(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8216C53C:
	// stw r29,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216C54C"))) PPC_WEAK_FUNC(sub_8216C54C);
PPC_FUNC_IMPL(__imp__sub_8216C54C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C550"))) PPC_WEAK_FUNC(sub_8216C550);
PPC_FUNC_IMPL(__imp__sub_8216C550) {
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
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8216c5a0
	if (!ctx.cr6.eq) goto loc_8216C5A0;
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82079fd8
	ctx.lr = 0x8216C580;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216c598
	if (ctx.cr6.eq) goto loc_8216C598;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8216c400
	ctx.lr = 0x8216C590;
	sub_8216C400(ctx, base);
	// stw r3,-31312(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31312, ctx.r3.u32);
	// b 0x8216c5a0
	goto loc_8216C5A0;
loc_8216C598:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31312(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31312, ctx.r11.u32);
loc_8216C5A0:
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

__attribute__((alias("__imp__sub_8216C5B8"))) PPC_WEAK_FUNC(sub_8216C5B8);
PPC_FUNC_IMPL(__imp__sub_8216C5B8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,-31308(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31308);
	// b 0x8216c550
	sub_8216C550(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216C5C4"))) PPC_WEAK_FUNC(sub_8216C5C4);
PPC_FUNC_IMPL(__imp__sub_8216C5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C5C8"))) PPC_WEAK_FUNC(sub_8216C5C8);
PPC_FUNC_IMPL(__imp__sub_8216C5C8) {
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
	// bl 0x8216c0b0
	ctx.lr = 0x8216C5E0;
	sub_8216C0B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8216b768
	ctx.lr = 0x8216C5E8;
	sub_8216B768(ctx, base);
	// bl 0x8216b9a0
	ctx.lr = 0x8216C5EC;
	sub_8216B9A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8216b8b0
	ctx.lr = 0x8216C5F4;
	sub_8216B8B0(ctx, base);
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

__attribute__((alias("__imp__sub_8216C608"))) PPC_WEAK_FUNC(sub_8216C608);
PPC_FUNC_IMPL(__imp__sub_8216C608) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216C60C"))) PPC_WEAK_FUNC(sub_8216C60C);
PPC_FUNC_IMPL(__imp__sub_8216C60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C610"))) PPC_WEAK_FUNC(sub_8216C610);
PPC_FUNC_IMPL(__imp__sub_8216C610) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216C618"))) PPC_WEAK_FUNC(sub_8216C618);
PPC_FUNC_IMPL(__imp__sub_8216C618) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216C628"))) PPC_WEAK_FUNC(sub_8216C628);
PPC_FUNC_IMPL(__imp__sub_8216C628) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216C644"))) PPC_WEAK_FUNC(sub_8216C644);
PPC_FUNC_IMPL(__imp__sub_8216C644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C648"))) PPC_WEAK_FUNC(sub_8216C648);
PPC_FUNC_IMPL(__imp__sub_8216C648) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r9,r10,5940
	ctx.r9.s64 = ctx.r10.s64 + 5940;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8209b710
	sub_8209B710(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216C66C"))) PPC_WEAK_FUNC(sub_8216C66C);
PPC_FUNC_IMPL(__imp__sub_8216C66C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216C670"))) PPC_WEAK_FUNC(sub_8216C670);
PPC_FUNC_IMPL(__imp__sub_8216C670) {
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
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addi r9,r10,5940
	ctx.r9.s64 = ctx.r10.s64 + 5940;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x8209d148
	ctx.lr = 0x8216C6AC;
	sub_8209D148(ctx, base);
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

__attribute__((alias("__imp__sub_8216C6C4"))) PPC_WEAK_FUNC(sub_8216C6C4);
PPC_FUNC_IMPL(__imp__sub_8216C6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216C6C8"))) PPC_WEAK_FUNC(sub_8216C6C8);
PPC_FUNC_IMPL(__imp__sub_8216C6C8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8216c6fc
	if (!ctx.cr6.eq) goto loc_8216C6FC;
	// lwz r9,488(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 488);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216c6fc
	if (ctx.cr6.eq) goto loc_8216C6FC;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r4,488(r11)
	PPC_STORE_U32(ctx.r11.u32 + 488, ctx.r4.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// b 0x8209d660
	sub_8209D660(ctx, base);
	return;
loc_8216C6FC:
	// lwz r9,488(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 488);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,488(r11)
	PPC_STORE_U32(ctx.r11.u32 + 488, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// b 0x8209d660
	sub_8209D660(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216C72C"))) PPC_WEAK_FUNC(sub_8216C72C);
PPC_FUNC_IMPL(__imp__sub_8216C72C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216C730"))) PPC_WEAK_FUNC(sub_8216C730);
PPC_FUNC_IMPL(__imp__sub_8216C730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c968
	ctx.lr = 0x8216C738;
	__savegprlr_20(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// std r5,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, ctx.r5.u64);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// bl 0x8209d220
	ctx.lr = 0x8216C754;
	sub_8209D220(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r1,136
	ctx.r11.s64 = ctx.r1.s64 + 136;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8216C770:
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x8216c770
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216C770;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820e4338
	ctx.lr = 0x8216C78C;
	sub_820E4338(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r7,18(r29)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r29.u32 + 18);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lhz r6,16(r29)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r29.u32 + 16);
	// bl 0x82089f78
	ctx.lr = 0x8216C7A4;
	sub_82089F78(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209d148
	ctx.lr = 0x8216C7BC;
	sub_8209D148(ctx, base);
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8216cd74
	if (ctx.cr6.eq) goto loc_8216CD74;
	// lhz r8,16(r29)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r29.u32 + 16);
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// lwz r11,136(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r7,20(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// lhz r27,18(r29)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r29.u32 + 18);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216c7ec
	if (!ctx.cr6.gt) goto loc_8216C7EC;
	// subf r25,r11,r8
	ctx.r25.s64 = ctx.r8.s64 - ctx.r11.s64;
	// mr r24,r11
	ctx.r24.u64 = ctx.r11.u64;
loc_8216C7EC:
	// lwz r11,140(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216c7fc
	if (!ctx.cr6.gt) goto loc_8216C7FC;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_8216C7FC:
	// lwz r10,356(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x8216cc84
	if (ctx.cr6.eq) goto loc_8216CC84;
	// cmplwi cr6,r11,24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 24, ctx.xer);
	// beq cr6,0x8216cac4
	if (ctx.cr6.eq) goto loc_8216CAC4;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bne cr6,0x8216cd68
	if (!ctx.cr6.eq) goto loc_8216CD68;
	// lis r9,10280
	ctx.r9.s64 = 673710080;
	// lwz r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// ori r9,r9,323
	ctx.r9.u64 = ctx.r9.u64 | 323;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x8216ca04
	if (ctx.cr6.gt) goto loc_8216CA04;
	// beq cr6,0x8216c984
	if (ctx.cr6.eq) goto loc_8216C984;
	// addis r11,r11,-6184
	ctx.r11.s64 = ctx.r11.s64 + -405274624;
	// addic. r11,r11,-323
	ctx.xer.ca = ctx.r11.u32 > 322;
	ctx.r11.s64 = ctx.r11.s64 + -323;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8216c8e4
	if (ctx.cr0.eq) goto loc_8216C8E4;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bne cr6,0x8216ca14
	if (!ctx.cr6.eq) goto loc_8216CA14;
	// lwz r11,352(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x8216cd68
	if (ctx.cr6.eq) goto loc_8216CD68;
	// rlwinm r8,r25,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8216C874:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216c8c0
	if (ctx.cr6.eq) goto loc_8216C8C0;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216C884:
	// lbz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// lbz r5,1(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// rlwinm r4,r6,4,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFF00;
	// lbz r3,3(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 3);
	// lbz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// or r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r4,r3,8,16,19
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xF000;
	// rlwinm r3,r5,0,16,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFF0;
	// rlwinm r6,r6,28,4,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// or r5,r3,r4
	ctx.r5.u64 = ctx.r3.u64 | ctx.r4.u64;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// sthu r4,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U16(ea, ctx.r4.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x8216c884
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216C884;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8216C8C0:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 + ctx.r9.u64;
	// bne 0x8216c874
	if (!ctx.cr0.eq) goto loc_8216C874;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216C8DC;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216C8E4:
	// lwz r11,352(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x8216cd68
	if (ctx.cr6.eq) goto loc_8216CD68;
	// lis r11,0
	ctx.r11.s64 = 0;
	// rlwinm r6,r25,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// ori r8,r11,32768
	ctx.r8.u64 = ctx.r11.u64 | 32768;
loc_8216C908:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216c960
	if (ctx.cr6.eq) goto loc_8216C960;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216C918:
	// lbz r5,3(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 3);
	// lbz r4,2(r7)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// subfic r5,r5,0
	ctx.xer.ca = ctx.r5.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r5.s64;
	// lbz r3,1(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// rlwinm r4,r4,5,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFF00;
	// lbz r31,0(r7)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// subfe r5,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r3,r5,r8
	ctx.r3.u64 = ctx.r5.u64 & ctx.r8.u64;
	// rlwinm r5,r4,2,16,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFE0;
	// rlwinm r4,r31,29,3,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 29) & 0x1FFFFFFF;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// or r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 | ctx.r4.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// or r4,r5,r3
	ctx.r4.u64 = ctx.r5.u64 | ctx.r3.u64;
	// sthu r4,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U16(ea, ctx.r4.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x8216c918
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216C918;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8216C960:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 + ctx.r9.u64;
	// bne 0x8216c908
	if (!ctx.cr0.eq) goto loc_8216C908;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216C97C;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216C984:
	// lwz r11,352(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x8216cd68
	if (ctx.cr6.eq) goto loc_8216CD68;
	// rlwinm r8,r25,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8216C9A0:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216c9e0
	if (ctx.cr6.eq) goto loc_8216C9E0;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216C9B0:
	// lbz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// lbz r5,1(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// rlwinm r4,r6,5,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFF00;
	// lbz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// or r6,r4,r5
	ctx.r6.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r5,r3,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r4,r6,2,16,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFE0;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// sthu r3,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U16(ea, ctx.r3.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x8216c9b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216C9B0;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8216C9E0:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 + ctx.r9.u64;
	// bne 0x8216c9a0
	if (!ctx.cr0.eq) goto loc_8216C9A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216C9FC;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CA04:
	// lis r9,10280
	ctx.r9.s64 = 673710080;
	// ori r6,r9,324
	ctx.r6.u64 = ctx.r9.u64 | 324;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// beq cr6,0x8216ca44
	if (ctx.cr6.eq) goto loc_8216CA44;
loc_8216CA14:
	// lwz r10,188(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,180(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// divwu r4,r4,r10
	ctx.r4.u32 = ppc_divwu(ctx.r4.u32, ctx.r10.u32);
	// bl 0x820e3c78
	ctx.lr = 0x8216CA30;
	sub_820E3C78(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CA3C;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CA44:
	// lwz r11,352(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x8216cd68
	if (ctx.cr6.eq) goto loc_8216CD68;
	// rlwinm r8,r25,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_8216CA60:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216caa0
	if (ctx.cr6.eq) goto loc_8216CAA0;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216CA70:
	// lbz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// lbz r5,1(r7)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// rlwinm r4,r6,5,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFF00;
	// lbz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// or r6,r4,r5
	ctx.r6.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r5,r3,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r4,r6,3,16,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFE0;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// sthu r3,2(r11)
	ea = 2 + ctx.r11.u32;
	PPC_STORE_U16(ea, ctx.r3.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x8216ca70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216CA70;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8216CAA0:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 + ctx.r9.u64;
	// bne 0x8216ca60
	if (!ctx.cr0.eq) goto loc_8216CA60;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CABC;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CAC4:
	// lis r11,6184
	ctx.r11.s64 = 405274624;
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// ori r11,r11,335
	ctx.r11.u64 = ctx.r11.u64 | 335;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8216cb70
	if (ctx.cr6.gt) goto loc_8216CB70;
	// beq cr6,0x8216cb90
	if (ctx.cr6.eq) goto loc_8216CB90;
	// lis r11,6184
	ctx.r11.s64 = 405274624;
	// ori r9,r11,323
	ctx.r9.u64 = ctx.r11.u64 | 323;
	// cmpw cr6,r6,r9
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x8216cb90
	if (ctx.cr6.eq) goto loc_8216CB90;
loc_8216CAEC:
	// lwz r11,352(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// beq cr6,0x8216cd68
	if (ctx.cr6.eq) goto loc_8216CD68;
	// rlwinm r11,r25,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// add r8,r25,r11
	ctx.r8.u64 = ctx.r25.u64 + ctx.r11.u64;
loc_8216CB0C:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216cb4c
	if (ctx.cr6.eq) goto loc_8216CB4C;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216CB1C:
	// lbz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// lis r5,-1
	ctx.r5.s64 = -65536;
	// lbz r4,1(r7)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// rlwimi r5,r6,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// addi r7,r7,3
	ctx.r7.s64 = ctx.r7.s64 + 3;
	// or r6,r5,r4
	ctx.r6.u64 = ctx.r5.u64 | ctx.r4.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r3
	ctx.r4.u64 = ctx.r5.u64 | ctx.r3.u64;
	// stwu r4,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8216cb1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216CB1C;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8216CB4C:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 + ctx.r9.u64;
	// bne 0x8216cb0c
	if (!ctx.cr0.eq) goto loc_8216CB0C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CB68;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CB70:
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r9,r11,323
	ctx.r9.u64 = ctx.r11.u64 | 323;
	// cmpw cr6,r6,r9
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8216caec
	if (ctx.cr6.lt) goto loc_8216CAEC;
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r9,r11,324
	ctx.r9.u64 = ctx.r11.u64 | 324;
	// cmpw cr6,r6,r9
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x8216caec
	if (ctx.cr6.gt) goto loc_8216CAEC;
loc_8216CB90:
	// lwz r8,352(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-22296
	ctx.r11.s64 = ctx.r11.s64 + -22296;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_8216CBA8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8216cbd8
	if (ctx.cr6.eq) goto loc_8216CBD8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// blt cr6,0x8216cba8
	if (ctx.cr6.lt) goto loc_8216CBA8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CBD0;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CBD8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8216cd68
	if (ctx.cr6.eq) goto loc_8216CD68;
	// rlwinm r10,r25,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// add r6,r25,r10
	ctx.r6.u64 = ctx.r25.u64 + ctx.r10.u64;
loc_8216CBEC:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216cc60
	if (ctx.cr6.eq) goto loc_8216CC60;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
	// addi r10,r8,-2
	ctx.r10.s64 = ctx.r8.s64 + -2;
loc_8216CBFC:
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lbz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + 2);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// lbz r31,1(r7)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r7.u32 + 1);
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// srw r3,r3,r5
	ctx.r3.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (ctx.r5.u8 & 0x3F));
	// lwz r30,24(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// srw r4,r31,r4
	ctx.r4.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r4.u8 & 0x3F));
	// lwz r31,4(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// slw r5,r4,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r5.u8 & 0x3F));
	// slw r3,r3,r30
	ctx.r3.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r30.u8 & 0x3F));
	// lbz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// clrlwi r4,r31,24
	ctx.r4.u64 = ctx.r31.u32 & 0xFF;
	// lwz r31,28(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// or r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 | ctx.r5.u64;
	// srw r5,r30,r4
	ctx.r5.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r4.u8 & 0x3F));
	// or r4,r3,r5
	ctx.r4.u64 = ctx.r3.u64 | ctx.r5.u64;
	// clrlwi r3,r31,16
	ctx.r3.u64 = ctx.r31.u32 & 0xFFFF;
	// addi r7,r7,3
	ctx.r7.s64 = ctx.r7.s64 + 3;
	// or r5,r4,r3
	ctx.r5.u64 = ctx.r4.u64 | ctx.r3.u64;
	// sthu r5,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r5.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x8216cbfc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216CBFC;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8216CC60:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 + ctx.r8.u64;
	// bne 0x8216cbec
	if (!ctx.cr0.eq) goto loc_8216CBEC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CC7C;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CC84:
	// lis r11,6184
	ctx.r11.s64 = 405274624;
	// lwz r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// ori r11,r11,335
	ctx.r11.u64 = ctx.r11.u64 | 335;
	// cmpw cr6,r8,r11
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r11.s32, ctx.xer);
	// bgt cr6,0x8216cd7c
	if (ctx.cr6.gt) goto loc_8216CD7C;
	// beq cr6,0x8216cd9c
	if (ctx.cr6.eq) goto loc_8216CD9C;
	// lis r11,6184
	ctx.r11.s64 = 405274624;
	// ori r9,r11,323
	ctx.r9.u64 = ctx.r11.u64 | 323;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// beq cr6,0x8216cd9c
	if (ctx.cr6.eq) goto loc_8216CD9C;
loc_8216CCAC:
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// mullw r11,r27,r24
	ctx.r11.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r24.s32);
	// addi r31,r29,24
	ctx.r31.s64 = ctx.r29.s64 + 24;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// addi r30,r31,2048
	ctx.r30.s64 = ctx.r31.s64 + 2048;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8216ccd0
	if (!ctx.cr6.gt) goto loc_8216CCD0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8216CCD0:
	// bl 0x8207a030
	ctx.lr = 0x8216CCD4;
	sub_8207A030(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// beq cr6,0x8216cd34
	if (ctx.cr6.eq) goto loc_8216CD34;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r9,r3,-4
	ctx.r9.s64 = ctx.r3.s64 + -4;
	// addi r10,r30,-1
	ctx.r10.s64 = ctx.r30.s64 + -1;
loc_8216CCEC:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216cd2c
	if (ctx.cr6.eq) goto loc_8216CD2C;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216CCF8:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// rotlwi r11,r11,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// rlwinm r8,r5,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r5,0,16,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFF00;
	// rlwinm r7,r5,24,16,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 24) & 0xFF00;
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r8,r5,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r4,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8216ccf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216CCF8;
loc_8216CD2C:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x8216ccec
	if (!ctx.cr0.eq) goto loc_8216CCEC;
loc_8216CD34:
	// lwz r10,188(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lhz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 16);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwz r5,180(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// divwu r4,r4,r10
	ctx.r4.u32 = ppc_divwu(ctx.r4.u32, ctx.r10.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x820e3c78
	ctx.lr = 0x8216CD60;
	sub_820E3C78(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8216CD64:
	// bl 0x8207a8a0
	ctx.lr = 0x8216CD68;
	sub_8207A8A0(ctx, base);
loc_8216CD68:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CD74;
	sub_8209B710(ctx, base);
loc_8216CD74:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CD7C:
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r9,r11,323
	ctx.r9.u64 = ctx.r11.u64 | 323;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8216ccac
	if (ctx.cr6.lt) goto loc_8216CCAC;
	// lis r11,10280
	ctx.r11.s64 = 673710080;
	// ori r9,r11,324
	ctx.r9.u64 = ctx.r11.u64 | 324;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x8216ccac
	if (ctx.cr6.gt) goto loc_8216CCAC;
loc_8216CD9C:
	// lwz r9,352(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r30,r29,24
	ctx.r30.s64 = ctx.r29.s64 + 24;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r31,r11,-22296
	ctx.r31.s64 = ctx.r11.s64 + -22296;
	// addi r29,r30,2048
	ctx.r29.s64 = ctx.r30.s64 + 2048;
	// add r28,r9,r10
	ctx.r28.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8216CDBC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8216cdec
	if (ctx.cr6.eq) goto loc_8216CDEC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x8216cdbc
	if (ctx.cr6.lt) goto loc_8216CDBC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8209b710
	ctx.lr = 0x8216CDE4;
	sub_8209B710(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9b8
	__restgprlr_20(ctx, base);
	return;
loc_8216CDEC:
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x8207a030
	ctx.lr = 0x8216CDF4;
	sub_8207A030(ctx, base);
	// li r11,64
	ctx.r11.s64 = 64;
	// addi r8,r3,-2
	ctx.r8.s64 = ctx.r3.s64 + -2;
	// li r7,255
	ctx.r7.s64 = 255;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r30,-2
	ctx.r11.s64 = ctx.r30.s64 + -2;
loc_8216CE08:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216ce5c
	if (ctx.cr6.eq) goto loc_8216CE5C;
	// lbz r10,5(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216ce58
	if (ctx.cr6.eq) goto loc_8216CE58;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// divwu r5,r6,r7
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r7.u32);
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216ce40
	if (!ctx.cr6.eq) goto loc_8216CE40;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8216CE40:
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// slw r4,r6,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r5.u8 & 0x3F));
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// b 0x8216ce5c
	goto loc_8216CE5C;
loc_8216CE58:
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
loc_8216CE5C:
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lbz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// lwz r22,24(r31)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// srw r5,r4,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r5.u8 & 0x3F));
	// lwz r21,16(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// srw r9,r6,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r9.u8 & 0x3F));
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// slw r6,r5,r22
	ctx.r6.u64 = ctx.r22.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r22.u8 & 0x3F));
	// slw r5,r9,r21
	ctx.r5.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r21.u8 & 0x3F));
	// lbz r30,2(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// srw r5,r30,r4
	ctx.r5.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r4.u8 & 0x3F));
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// sth r10,2(r8)
	PPC_STORE_U16(ctx.r8.u32 + 2, ctx.r10.u16);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216cf00
	if (ctx.cr6.eq) goto loc_8216CF00;
	// lbz r10,9(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216cefc
	if (ctx.cr6.eq) goto loc_8216CEFC;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// divwu r5,r6,r7
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r7.u32);
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216cee4
	if (!ctx.cr6.eq) goto loc_8216CEE4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8216CEE4:
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// slw r4,r6,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r5.u8 & 0x3F));
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// b 0x8216cf00
	goto loc_8216CF00;
loc_8216CEFC:
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
loc_8216CF00:
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lbz r4,7(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 7);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// lbz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// lwz r22,16(r31)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// srw r5,r4,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r5.u8 & 0x3F));
	// lwz r21,24(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// srw r9,r6,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r9.u8 & 0x3F));
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// slw r6,r5,r22
	ctx.r6.u64 = ctx.r22.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r22.u8 & 0x3F));
	// slw r5,r9,r21
	ctx.r5.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r21.u8 & 0x3F));
	// lbz r30,6(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// srw r5,r30,r4
	ctx.r5.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r4.u8 & 0x3F));
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// sth r10,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r10.u16);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216cfa4
	if (ctx.cr6.eq) goto loc_8216CFA4;
	// lbz r10,13(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 13);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216cfa0
	if (ctx.cr6.eq) goto loc_8216CFA0;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// divwu r5,r6,r7
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r7.u32);
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216cf88
	if (!ctx.cr6.eq) goto loc_8216CF88;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8216CF88:
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// slw r4,r6,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r5.u8 & 0x3F));
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// b 0x8216cfa4
	goto loc_8216CFA4;
loc_8216CFA0:
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
loc_8216CFA4:
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lbz r4,11(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// lbz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// lwz r22,16(r31)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// srw r5,r4,r5
	ctx.r5.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r5.u8 & 0x3F));
	// lwz r21,24(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// srw r9,r6,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r9.u8 & 0x3F));
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// slw r6,r5,r22
	ctx.r6.u64 = ctx.r22.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r22.u8 & 0x3F));
	// slw r5,r9,r21
	ctx.r5.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r21.u8 & 0x3F));
	// lbz r30,10(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10);
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// srw r5,r30,r4
	ctx.r5.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r4.u8 & 0x3F));
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// sth r10,6(r8)
	PPC_STORE_U16(ctx.r8.u32 + 6, ctx.r10.u16);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216d048
	if (ctx.cr6.eq) goto loc_8216D048;
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 17);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216d044
	if (ctx.cr6.eq) goto loc_8216D044;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mullw r6,r9,r10
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// divwu r5,r6,r7
	ctx.r5.u32 = ppc_divwu(ctx.r6.u32, ctx.r7.u32);
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216d02c
	if (!ctx.cr6.eq) goto loc_8216D02C;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8216D02C:
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
	// slw r4,r6,r5
	ctx.r4.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r5.u8 & 0x3F));
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// b 0x8216d048
	goto loc_8216D048;
loc_8216D044:
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
loc_8216D048:
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r30,20(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lbz r4,14(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 14);
	// clrlwi r6,r6,24
	ctx.r6.u64 = ctx.r6.u32 & 0xFF;
	// lbz r5,15(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 15);
	// clrlwi r30,r30,24
	ctx.r30.u64 = ctx.r30.u32 & 0xFF;
	// lbzu r9,16(r11)
	ea = 16 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// lwz r22,16(r31)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// srw r5,r5,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x20 ? 0 : (ctx.r5.u32 >> (ctx.r6.u8 & 0x3F));
	// lwz r21,24(r31)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// srw r9,r9,r30
	ctx.r9.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r30.u8 & 0x3F));
	// lwz r20,4(r31)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// slw r6,r5,r22
	ctx.r6.u64 = ctx.r22.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r22.u8 & 0x3F));
	// slw r5,r9,r21
	ctx.r5.u64 = ctx.r21.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r21.u8 & 0x3F));
	// clrlwi r9,r20,24
	ctx.r9.u64 = ctx.r20.u32 & 0xFF;
	// or r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 | ctx.r5.u64;
	// srw r5,r4,r9
	ctx.r5.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r9.u8 & 0x3F));
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// sthu r10,8(r8)
	ea = 8 + ctx.r8.u32;
	PPC_STORE_U16(ea, ctx.r10.u16);
	ctx.r8.u32 = ea;
	// bdnz 0x8216ce08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216CE08;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8216cd64
	if (ctx.cr6.eq) goto loc_8216CD64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
loc_8216D0AC:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8216d0d0
	if (ctx.cr6.eq) goto loc_8216D0D0;
	// addi r10,r28,-2
	ctx.r10.s64 = ctx.r28.s64 + -2;
	// mtctr r24
	ctx.ctr.u64 = ctx.r24.u64;
loc_8216D0BC:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// lhzx r7,r9,r3
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r3.u32);
	// sthu r7,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r7.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x8216d0bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216D0BC;
loc_8216D0D0:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r28,r10,r28
	ctx.r28.u64 = ctx.r10.u64 + ctx.r28.u64;
	// bne 0x8216d0ac
	if (!ctx.cr0.eq) goto loc_8216D0AC;
	// b 0x8216cd64
	goto loc_8216CD64;
}

__attribute__((alias("__imp__sub_8216D0E8"))) PPC_WEAK_FUNC(sub_8216D0E8);
PPC_FUNC_IMPL(__imp__sub_8216D0E8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216c730
	ctx.lr = 0x8216D10C;
	sub_8216C730(ctx, base);
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

__attribute__((alias("__imp__sub_8216D120"))) PPC_WEAK_FUNC(sub_8216D120);
PPC_FUNC_IMPL(__imp__sub_8216D120) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8216D128;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,468(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 468);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,472(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 472);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r30,r3,456
	ctx.r30.s64 = ctx.r3.s64 + 456;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8216d14c
	if (!ctx.cr6.gt) goto loc_8216D14C;
	// twi 31,r0,22
loc_8216D14C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
loc_8216D160:
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8216d16c
	if (!ctx.cr6.gt) goto loc_8216D16C;
	// twi 31,r0,22
loc_8216D16C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8216d180
	if (ctx.cr6.eq) goto loc_8216D180;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216d184
	if (ctx.cr6.eq) goto loc_8216D184;
loc_8216D180:
	// twi 31,r0,22
loc_8216D184:
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8216d2ec
	if (ctx.cr6.eq) goto loc_8216D2EC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216d1e0
	if (!ctx.cr6.eq) goto loc_8216D1E0;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8216D19C:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8216d1ac
	if (ctx.cr6.lt) goto loc_8216D1AC;
	// twi 31,r0,22
loc_8216D1AC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8216d1f0
	if (ctx.cr6.eq) goto loc_8216D1F0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216d1e8
	if (!ctx.cr6.eq) goto loc_8216D1E8;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8216D1C8:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8216d1d8
	if (ctx.cr6.lt) goto loc_8216D1D8;
	// twi 31,r0,22
loc_8216D1D8:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// b 0x8216d160
	goto loc_8216D160;
loc_8216D1E0:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8216d19c
	goto loc_8216D19C;
loc_8216D1E8:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8216d1c8
	goto loc_8216D1C8;
loc_8216D1F0:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addi r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 4;
	// subf r10,r5,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r5.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8216d214
	if (!ctx.cr0.gt) goto loc_8216D214;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x8207a520
	ctx.lr = 0x8216D214;
	sub_8207A520(ctx, base);
loc_8216D214:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// bgt cr6,0x8216d234
	if (ctx.cr6.gt) goto loc_8216D234;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216d238
	if (!ctx.cr6.gt) goto loc_8216D238;
loc_8216D234:
	// twi 31,r0,22
loc_8216D238:
	// lwz r11,488(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 488);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x8216d258
	if (ctx.cr6.eq) goto loc_8216D258;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// bl 0x820a3560
	ctx.lr = 0x8216D250;
	sub_820A3560(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8216d274
	if (ctx.cr6.eq) goto loc_8216D274;
loc_8216D258:
	// stw r27,488(r28)
	PPC_STORE_U32(ctx.r28.u32 + 488, ctx.r27.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216D274;
	sub_8209D660(ctx, base);
loc_8216D274:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// bl 0x82099388
	ctx.lr = 0x8216D280;
	sub_82099388(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216d2b0
	if (ctx.cr6.eq) goto loc_8216D2B0;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8216d2a8
	if (!ctx.cr6.eq) goto loc_8216D2A8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,480(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 480);
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x8216D2A8;
	sub_8209A100(ctx, base);
loc_8216D2A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820a4400
	ctx.lr = 0x8216D2B0;
	sub_820A4400(ctx, base);
loc_8216D2B0:
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216d2c4
	if (ctx.cr6.eq) goto loc_8216D2C4;
	// bl 0x820a4400
	ctx.lr = 0x8216D2C0;
	sub_820A4400(ctx, base);
	// stw r27,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r27.u32);
loc_8216D2C4:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216d2d8
	if (ctx.cr6.eq) goto loc_8216D2D8;
	// bl 0x820a4400
	ctx.lr = 0x8216D2D4;
	sub_820A4400(ctx, base);
	// stw r27,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r27.u32);
loc_8216D2D8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207a630
	ctx.lr = 0x8216D2E0;
	sub_8207A630(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8216D2EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216D2F8"))) PPC_WEAK_FUNC(sub_8216D2F8);
PPC_FUNC_IMPL(__imp__sub_8216D2F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216D300;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8216d330
	if (ctx.cr6.eq) goto loc_8216D330;
	// lwz r5,12(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8216d334
	if (!ctx.cr6.eq) goto loc_8216D334;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8216D330:
	// lwz r5,480(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 480);
loc_8216D334:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x8216D340;
	sub_8209A100(ctx, base);
	// clrlwi r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216d374
	if (ctx.cr6.eq) goto loc_8216D374;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r7,536(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r6,63
	ctx.r6.s64 = 63;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820a19f0
	ctx.lr = 0x8216D374;
	sub_820A19F0(ctx, base);
loc_8216D374:
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lbz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,-31304(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31304);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-31304(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31304, ctx.r11.u32);
	// bne cr6,0x8216d3ac
	if (!ctx.cr6.eq) goto loc_8216D3AC;
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
	ctx.lr = 0x8216D3A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-31304(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31304);
loc_8216D3AC:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,-31304(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31304, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216D3C0"))) PPC_WEAK_FUNC(sub_8216D3C0);
PPC_FUNC_IMPL(__imp__sub_8216D3C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8216D3C8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,468(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 468);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r10,472(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 472);
	// addi r28,r3,456
	ctx.r28.s64 = ctx.r3.s64 + 456;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8216d3e8
	if (!ctx.cr6.gt) goto loc_8216D3E8;
	// twi 31,r0,22
loc_8216D3E8:
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// li r27,0
	ctx.r27.s64 = 0;
loc_8216D3F4:
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8216d408
	if (!ctx.cr6.gt) goto loc_8216D408;
	// twi 31,r0,22
loc_8216D408:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8216d41c
	if (ctx.cr6.eq) goto loc_8216D41C;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216d420
	if (ctx.cr6.eq) goto loc_8216D420;
loc_8216D41C:
	// twi 31,r0,22
loc_8216D420:
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216d4a0
	if (ctx.cr6.eq) goto loc_8216D4A0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8216d490
	if (!ctx.cr6.eq) goto loc_8216D490;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8216D438:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8216d448
	if (ctx.cr6.lt) goto loc_8216D448;
	// twi 31,r0,22
loc_8216D448:
	// lwz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216d460
	if (ctx.cr6.eq) goto loc_8216D460;
	// bl 0x820a4400
	ctx.lr = 0x8216D45C;
	sub_820A4400(ctx, base);
	// stw r27,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
loc_8216D460:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a630
	ctx.lr = 0x8216D468;
	sub_8207A630(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8216d498
	if (!ctx.cr6.eq) goto loc_8216D498;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8216D478:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8216d488
	if (ctx.cr6.lt) goto loc_8216D488;
	// twi 31,r0,22
loc_8216D488:
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// b 0x8216d3f4
	goto loc_8216D3F4;
loc_8216D490:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216d438
	goto loc_8216D438;
loc_8216D498:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8216d478
	goto loc_8216D478;
loc_8216D4A0:
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x8216d4bc
	if (!ctx.cr6.gt) goto loc_8216D4BC;
	// twi 31,r0,22
	// twi 31,r0,22
	// twi 31,r0,22
loc_8216D4BC:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x8216d4d0
	if (ctx.cr6.gt) goto loc_8216D4D0;
	// cmplw cr6,r5,r5
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x8216d4d4
	if (!ctx.cr6.gt) goto loc_8216D4D4;
loc_8216D4D0:
	// twi 31,r0,22
loc_8216D4D4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216d4e4
	if (ctx.cr6.eq) goto loc_8216D4E4;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8216d4e8
	if (ctx.cr6.eq) goto loc_8216D4E8;
loc_8216D4E4:
	// twi 31,r0,22
loc_8216D4E8:
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8216d510
	if (ctx.cr6.eq) goto loc_8216D510;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r3
	ctx.r31.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x8216d50c
	if (!ctx.cr0.gt) goto loc_8216D50C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x8216D50C;
	sub_8207A520(ctx, base);
loc_8216D50C:
	// stw r31,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r31.u32);
loc_8216D510:
	// lwz r3,480(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 480);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216d524
	if (ctx.cr6.eq) goto loc_8216D524;
	// bl 0x820a4400
	ctx.lr = 0x8216D520;
	sub_820A4400(ctx, base);
	// stw r27,480(r26)
	PPC_STORE_U32(ctx.r26.u32 + 480, ctx.r27.u32);
loc_8216D524:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216D52C"))) PPC_WEAK_FUNC(sub_8216D52C);
PPC_FUNC_IMPL(__imp__sub_8216D52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216D530"))) PPC_WEAK_FUNC(sub_8216D530);
PPC_FUNC_IMPL(__imp__sub_8216D530) {
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
	// addi r10,r11,5936
	ctx.r10.s64 = ctx.r11.s64 + 5936;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x8216d3c0
	ctx.lr = 0x8216D554;
	sub_8216D3C0(ctx, base);
	// addi r31,r31,456
	ctx.r31.s64 = ctx.r31.s64 + 456;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216d568
	if (ctx.cr6.eq) goto loc_8216D568;
	// bl 0x8207a630
	ctx.lr = 0x8216D568;
	sub_8207A630(ctx, base);
loc_8216D568:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x8207a630
	ctx.lr = 0x8216D580;
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

__attribute__((alias("__imp__sub_8216D594"))) PPC_WEAK_FUNC(sub_8216D594);
PPC_FUNC_IMPL(__imp__sub_8216D594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216D598"))) PPC_WEAK_FUNC(sub_8216D598);
PPC_FUNC_IMPL(__imp__sub_8216D598) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216D5A0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,504(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 504);
	// clrlwi r11,r4,29
	ctx.r11.u64 = ctx.r4.u32 & 0x7;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8216d5ec
	if (ctx.cr6.eq) goto loc_8216D5EC;
	// rlwinm r10,r10,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r8,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r8.u32);
	// addi r30,r9,5888
	ctx.r30.s64 = ctx.r9.s64 + 5888;
	// lwzx r4,r29,r30
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// bl 0x82096fd0
	ctx.lr = 0x8216D5DC;
	sub_82096FD0(ctx, base);
	// addi r7,r30,4
	ctx.r7.s64 = ctx.r30.s64 + 4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwzx r4,r29,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r7.u32);
	// bl 0x82097060
	ctx.lr = 0x8216D5EC;
	sub_82097060(ctx, base);
loc_8216D5EC:
	// lwz r11,512(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 512);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// beq cr6,0x8216d620
	if (ctx.cr6.eq) goto loc_8216D620;
	// li r11,32
	ctx.r11.s64 = 32;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,512(r31)
	PPC_STORE_U32(ctx.r31.u32 + 512, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82098860
	ctx.lr = 0x8216D610;
	sub_82098860(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x8216D620;
	sub_820986B8(ctx, base);
loc_8216D620:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216D628"))) PPC_WEAK_FUNC(sub_8216D628);
PPC_FUNC_IMPL(__imp__sub_8216D628) {
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
	// li r10,39
	ctx.r10.s64 = 39;
	// stw r30,504(r3)
	PPC_STORE_U32(ctx.r3.u32 + 504, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,508(r3)
	PPC_STORE_U32(ctx.r3.u32 + 508, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,512(r3)
	PPC_STORE_U32(ctx.r3.u32 + 512, ctx.r30.u32);
	// addi r11,r3,504
	ctx.r11.s64 = ctx.r3.s64 + 504;
	// stw r30,516(r3)
	PPC_STORE_U32(ctx.r3.u32 + 516, ctx.r30.u32);
	// stw r10,504(r3)
	PPC_STORE_U32(ctx.r3.u32 + 504, ctx.r10.u32);
	// bl 0x8216d598
	ctx.lr = 0x8216D668;
	sub_8216D598(ctx, base);
	// stw r30,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82098860
	ctx.lr = 0x8216D67C;
	sub_82098860(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x8216D68C;
	sub_820986B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216D6A4;
	sub_8209D660(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820972d8
	ctx.lr = 0x8216D6B0;
	sub_820972D8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096e78
	ctx.lr = 0x8216D6BC;
	sub_82096E78(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097338
	ctx.lr = 0x8216D6C8;
	sub_82097338(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8216D6D4;
	sub_82096FD0(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x8216D6E0;
	sub_82097060(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096eb0
	ctx.lr = 0x8216D6EC;
	sub_82096EB0(ctx, base);
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

__attribute__((alias("__imp__sub_8216D704"))) PPC_WEAK_FUNC(sub_8216D704);
PPC_FUNC_IMPL(__imp__sub_8216D704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216D708"))) PPC_WEAK_FUNC(sub_8216D708);
PPC_FUNC_IMPL(__imp__sub_8216D708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8216D710;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x82080358
	ctx.lr = 0x8216D718;
	__savefpr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,488(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 488);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216d750
	if (ctx.cr6.eq) goto loc_8216D750;
	// stw r28,488(r3)
	PPC_STORE_U32(ctx.r3.u32 + 488, ctx.r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216D750;
	sub_8209D660(ctx, base);
loc_8216D750:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8216d598
	ctx.lr = 0x8216D75C;
	sub_8216D598(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f10,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// fadds f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f10.f64));
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lis r8,2730
	ctx.r8.s64 = 178913280;
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// fmr f7,f13
	ctx.f7.f64 = ctx.f13.f64;
	// ori r7,r8,43690
	ctx.r7.u64 = ctx.r8.u64 | 43690;
	// fmr f6,f12
	ctx.f6.f64 = ctx.f12.f64;
	// lfs f31,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
	// fsubs f26,f0,f13
	ctx.f26.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fmr f5,f10
	ctx.f5.f64 = ctx.f10.f64;
	// fsubs f25,f12,f10
	ctx.f25.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmuls f30,f11,f31
	ctx.f30.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fmuls f29,f9,f31
	ctx.f29.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r27,r11,2
	ctx.r27.s64 = ctx.r11.s64 + 2;
	// cmplw cr6,r27,r7
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r7.u32, ctx.xer);
	// bgt cr6,0x8216d7cc
	if (ctx.cr6.gt) goto loc_8216D7CC;
	// rlwinm r11,r27,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// b 0x8216d7d0
	goto loc_8216D7D0;
loc_8216D7CC:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8216D7D0:
	// bl 0x8207a030
	ctx.lr = 0x8216D7D4;
	sub_8207A030(ctx, base);
	// rlwinm r11,r27,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8207da20
	ctx.lr = 0x8216D7EC;
	sub_8207DA20(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// addi r29,r30,8
	ctx.r29.s64 = ctx.r30.s64 + 8;
	// stfs f29,4(r30)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lfs f28,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f28.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f28,8(r30)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r9,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r9.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lfs f27,-17884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17884);
	ctx.f27.f64 = double(temp.f32);
loc_8216D818:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r10,r28,32
	ctx.r10.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// fmuls f9,f11,f27
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f27.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f24,f9,f8
	ctx.f24.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
	// fmr f1,f24
	ctx.f1.f64 = ctx.f24.f64;
	// bl 0x8207af40
	ctx.lr = 0x8216D854;
	sub_8207AF40(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// fmr f1,f24
	ctx.f1.f64 = ctx.f24.f64;
	// fmuls f6,f7,f26
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f26.f64));
	// fmadds f5,f6,f31,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f31.f64 + ctx.f30.f64));
	// stfs f5,-8(r29)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r29.u32 + -8, temp.u32);
	// bl 0x8207ae60
	ctx.lr = 0x8216D86C;
	sub_8207AE60(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// stfs f28,0(r29)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// fmuls f3,f4,f25
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f25.f64));
	// fmadds f2,f3,f31,f29
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f31.f64 + ctx.f29.f64));
	// stfs f2,-4(r29)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r29.u32 + -4, temp.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r9,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216d818
	if (!ctx.cr6.gt) goto loc_8216D818;
	// li r7,24
	ctx.r7.s64 = 24;
	// lwz r3,8(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216D8B0;
	sub_8209DC98(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x8216D8B8;
	sub_8207A8A0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x820803a4
	ctx.lr = 0x8216D8C4;
	__restfpr_24(ctx, base);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216D8C8"))) PPC_WEAK_FUNC(sub_8216D8C8);
PPC_FUNC_IMPL(__imp__sub_8216D8C8) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,4
	ctx.r9.s64 = 4;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r11,r1,68
	ctx.r11.s64 = ctx.r1.s64 + 68;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f0,21768(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r8,r9,-2064
	ctx.r8.s64 = ctx.r9.s64 + -2064;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f13,28(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
loc_8216D928:
	// lfs f12,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwzu r9,12(r10)
	ea = 12 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f10,12(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f9,16(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stwu r9,24(r11)
	ea = 24 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8216d928
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216D928;
	// lwz r11,488(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216d97c
	if (ctx.cr6.eq) goto loc_8216D97C;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216D97C;
	sub_8209D660(ctx, base);
loc_8216D97C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8216d598
	ctx.lr = 0x8216D988;
	sub_8216D598(ctx, base);
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216D9A0;
	sub_8209DC98(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_8216D9B8"))) PPC_WEAK_FUNC(sub_8216D9B8);
PPC_FUNC_IMPL(__imp__sub_8216D9B8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,3
	ctx.r9.s64 = 3;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r11,r1,68
	ctx.r11.s64 = ctx.r1.s64 + 68;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f0,21768(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// addi r8,r9,-2064
	ctx.r8.s64 = ctx.r9.s64 + -2064;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f13,28(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
loc_8216DA10:
	// lfs f12,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwzu r9,12(r10)
	ea = 12 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfs f10,12(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f9,16(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f0,20(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stwu r9,24(r11)
	ea = 24 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8216da10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216DA10;
	// lwz r11,488(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216da64
	if (ctx.cr6.eq) goto loc_8216DA64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216DA64;
	sub_8209D660(ctx, base);
loc_8216DA64:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8216d598
	ctx.lr = 0x8216DA70;
	sub_8216D598(ctx, base);
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216DA88;
	sub_8209DC98(ctx, base);
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

__attribute__((alias("__imp__sub_8216DAA0"))) PPC_WEAK_FUNC(sub_8216DAA0);
PPC_FUNC_IMPL(__imp__sub_8216DAA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8216DAA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f0,16(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lfs f12,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r4,20
	ctx.r10.s64 = ctx.r4.s64 + 20;
	// lfs f11,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fdivs f2,f12,f5
	ctx.f2.f64 = double(float(ctx.f12.f64 / ctx.f5.f64));
	// stfs f2,140(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fdivs f1,f11,f5
	ctx.f1.f64 = double(float(ctx.f11.f64 / ctx.f5.f64));
	// stfs f2,116(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fdivs f4,f0,f6
	ctx.f4.f64 = double(float(ctx.f0.f64 / ctx.f6.f64));
	// stfs f4,184(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// fdivs f3,f13,f6
	ctx.f3.f64 = double(float(ctx.f13.f64 / ctx.f6.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f13,21768(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f3,f4
	ctx.f0.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfs f0,28(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
loc_8216DB54:
	// lfs f12,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwzu r9,12(r10)
	ea = 12 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f10,12(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fsubs f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f9,16(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stwu r9,24(r11)
	ea = 24 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8216db54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216DB54;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82098860
	ctx.lr = 0x8216DB8C;
	sub_82098860(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x8216DB9C;
	sub_820986B8(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r10,r11,29
	ctx.r10.u64 = ctx.r11.u32 & 0x7;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x8216dd18
	if (!ctx.cr6.eq) goto loc_8216DD18;
	// lwz r11,488(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r28,0
	ctx.r28.s64 = 0;
	// oris r29,r10,32768
	ctx.r29.u64 = ctx.r10.u64 | 2147483648;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8216dbdc
	if (ctx.cr6.eq) goto loc_8216DBDC;
	// stw r28,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r28.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216DBDC;
	sub_8209D660(ctx, base);
loc_8216DBDC:
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x8207dac0
	ctx.lr = 0x8216DBEC;
	sub_8207DAC0(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r11,r1,180
	ctx.r11.s64 = ctx.r1.s64 + 180;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8216DBFC:
	// stwu r10,24(r11)
	ea = 24 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8216dbfc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8216DBFC;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8216DC10;
	sub_82096FD0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x8216DC1C;
	sub_82097060(ctx, base);
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216DC34;
	sub_8209DC98(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8216DC40;
	sub_82096FD0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x8216DC4C;
	sub_82097060(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x8216DC64;
	sub_8209D660(ctx, base);
	// li r7,24
	ctx.r7.s64 = 24;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216DC7C;
	sub_8209DC98(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8216DC88;
	sub_82096FD0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x8216DC94;
	sub_82097060(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d660
	ctx.lr = 0x8216DCA8;
	sub_8209D660(ctx, base);
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216DCC0;
	sub_8209DC98(ctx, base);
	// stw r28,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r28.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8216DCD0;
	sub_82096FD0(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x8216DCDC;
	sub_82097060(ctx, base);
	// lwz r10,512(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 512);
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// beq cr6,0x8216dd5c
	if (ctx.cr6.eq) goto loc_8216DD5C;
	// li r11,32
	ctx.r11.s64 = 32;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,512(r31)
	PPC_STORE_U32(ctx.r31.u32 + 512, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82098860
	ctx.lr = 0x8216DD00;
	sub_82098860(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x8216DD10;
	sub_820986B8(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8216DD18:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r5,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r5.u32);
	// bl 0x8209d660
	ctx.lr = 0x8216DD38;
	sub_8209D660(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8216d598
	ctx.lr = 0x8216DD44;
	sub_8216D598(ctx, base);
	// li r7,24
	ctx.r7.s64 = 24;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8209dc98
	ctx.lr = 0x8216DD5C;
	sub_8209DC98(ctx, base);
loc_8216DD5C:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216DD64"))) PPC_WEAK_FUNC(sub_8216DD64);
PPC_FUNC_IMPL(__imp__sub_8216DD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216DD68"))) PPC_WEAK_FUNC(sub_8216DD68);
PPC_FUNC_IMPL(__imp__sub_8216DD68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x8216DD70;
	__savegprlr_14(ctx, base);
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, ctx.f31.u64);
	// stwu r1,-592(r1)
	ea = -592 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,624(r1)
	PPC_STORE_U64(ctx.r1.u32 + 624, ctx.r4.u64);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// std r5,632(r1)
	PPC_STORE_U64(ctx.r1.u32 + 632, ctx.r5.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r6,640(r1)
	PPC_STORE_U64(ctx.r1.u32 + 640, ctx.r6.u64);
	// std r7,648(r1)
	PPC_STORE_U64(ctx.r1.u32 + 648, ctx.r7.u64);
	// std r8,656(r1)
	PPC_STORE_U64(ctx.r1.u32 + 656, ctx.r8.u64);
	// std r9,664(r1)
	PPC_STORE_U64(ctx.r1.u32 + 664, ctx.r9.u64);
	// std r10,672(r1)
	PPC_STORE_U64(ctx.r1.u32 + 672, ctx.r10.u64);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r11.u32);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// stw r3,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r3.u32);
	// lfs f0,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lfs f13,128(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,132(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// fdivs f31,f11,f10
	ctx.f31.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// bl 0x8209af10
	ctx.lr = 0x8216DDD4;
	sub_8209AF10(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// vupkd3d128 v56,v63,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v56 = vTemp;
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lvsr v0,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// rotlwi r6,r9,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// vpermwi128 v63,v56,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x15));
	// li r10,4
	ctx.r10.s64 = 4;
	// rotlwi r4,r7,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// vpermwi128 v62,v56,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x45));
	// li r8,8
	ctx.r8.s64 = 8;
	// vpermwi128 v61,v56,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x51));
	// li r7,12
	ctx.r7.s64 = 12;
	// vpermwi128 v60,v56,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x54));
	// vperm128 v55,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// vpermwi128 v59,v56,234
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x15));
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// vpermwi128 v58,v56,186
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x45));
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// vpermwi128 v57,v56,174
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x51));
	// vperm128 v54,v62,v62,v0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r5,16
	ctx.r5.s64 = 16;
	// vperm128 v53,v61,v61,v0
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r9,20
	ctx.r9.s64 = 20;
	// vperm128 v52,v60,v60,v0
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r31,r1,160
	ctx.r31.s64 = ctx.r1.s64 + 160;
	// stvewx128 v55,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v55.u32[3 - ((ea & 0xF) >> 2)]);
	// li r30,24
	ctx.r30.s64 = 24;
	// stvewx128 v55,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v55.u32[3 - ((ea & 0xF) >> 2)]);
	// vpermwi128 v56,v56,171
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v56.u32), 0x54));
	// stvewx128 v55,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v55.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stvewx128 v55,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v55.u32[3 - ((ea & 0xF) >> 2)]);
	// li r10,28
	ctx.r10.s64 = 28;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// li r29,36
	ctx.r29.s64 = 36;
	// addi r28,r1,160
	ctx.r28.s64 = ctx.r1.s64 + 160;
	// li r11,40
	ctx.r11.s64 = 40;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// li r27,44
	ctx.r27.s64 = 44;
	// addi r26,r1,160
	ctx.r26.s64 = ctx.r1.s64 + 160;
	// li r25,48
	ctx.r25.s64 = 48;
	// addi r24,r1,160
	ctx.r24.s64 = ctx.r1.s64 + 160;
	// li r23,52
	ctx.r23.s64 = 52;
	// addi r22,r1,160
	ctx.r22.s64 = ctx.r1.s64 + 160;
	// li r21,56
	ctx.r21.s64 = 56;
	// addi r20,r1,160
	ctx.r20.s64 = ctx.r1.s64 + 160;
	// addi r18,r1,96
	ctx.r18.s64 = ctx.r1.s64 + 96;
	// lwz r15,80(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r16,r1,96
	ctx.r16.s64 = ctx.r1.s64 + 96;
	// li r14,4
	ctx.r14.s64 = 4;
	// li r19,60
	ctx.r19.s64 = 60;
	// addi r17,r1,96
	ctx.r17.s64 = ctx.r1.s64 + 96;
	// lvsr v0,r0,r18
	temp.u32 = ctx.r18.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// lwz r18,84(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stvewx128 v54,r15,r5
	ea = (ctx.r15.u32 + ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v54.u32[3 - ((ea & 0xF) >> 2)]);
	// stw r16,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r16.u32);
	// addi r16,r1,96
	ctx.r16.s64 = ctx.r1.s64 + 96;
	// vperm128 v51,v59,v59,v0
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vperm128 v50,v58,v58,v0
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r16,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r16.u32);
	// li r16,8
	ctx.r16.s64 = 8;
	// stvewx128 v54,r18,r9
	ea = (ctx.r18.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v54.u32[3 - ((ea & 0xF) >> 2)]);
	// li r9,12
	ctx.r9.s64 = 12;
	// stvewx128 v54,r31,r30
	ea = (ctx.r31.u32 + ctx.r30.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v54.u32[3 - ((ea & 0xF) >> 2)]);
	// vperm128 v49,v57,v57,v0
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvewx128 v54,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v54.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvewx128 v53,r8,r6
	ea = (ctx.r8.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v53.u32[3 - ((ea & 0xF) >> 2)]);
	// li r10,16
	ctx.r10.s64 = 16;
	// stvewx128 v53,r4,r29
	ea = (ctx.r4.u32 + ctx.r29.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v53.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r29,84(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stvewx128 v53,r28,r11
	ea = (ctx.r28.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v53.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stvewx128 v53,r7,r27
	ea = (ctx.r7.u32 + ctx.r27.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v53.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stvewx128 v52,r26,r25
	ea = (ctx.r26.u32 + ctx.r25.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v52.u32[3 - ((ea & 0xF) >> 2)]);
	// li r7,20
	ctx.r7.s64 = 20;
	// stvewx128 v52,r24,r23
	ea = (ctx.r24.u32 + ctx.r23.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v52.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvewx128 v52,r22,r21
	ea = (ctx.r22.u32 + ctx.r21.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v52.u32[3 - ((ea & 0xF) >> 2)]);
	// li r4,24
	ctx.r4.s64 = 24;
	// stvewx128 v52,r20,r19
	ea = (ctx.r20.u32 + ctx.r19.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v52.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvewx128 v51,r0,r17
	ea = (ctx.r17.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v51.u32[3 - ((ea & 0xF) >> 2)]);
	// li r31,28
	ctx.r31.s64 = 28;
	// stvewx128 v51,r29,r14
	ea = (ctx.r29.u32 + ctx.r14.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v51.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// stvewx128 v51,r28,r16
	ea = (ctx.r28.u32 + ctx.r16.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v51.u32[3 - ((ea & 0xF) >> 2)]);
	// li r29,32
	ctx.r29.s64 = 32;
	// stvewx128 v51,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v51.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stvewx128 v50,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v50.u32[3 - ((ea & 0xF) >> 2)]);
	// li r5,36
	ctx.r5.s64 = 36;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvewx128 v50,r8,r7
	ea = (ctx.r8.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v50.u32[3 - ((ea & 0xF) >> 2)]);
	// li r10,40
	ctx.r10.s64 = 40;
	// stvewx128 v50,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v50.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stvewx128 v50,r11,r31
	ea = (ctx.r11.u32 + ctx.r31.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v50.u32[3 - ((ea & 0xF) >> 2)]);
	// li r7,44
	ctx.r7.s64 = 44;
	// stvewx128 v49,r30,r29
	ea = (ctx.r30.u32 + ctx.r29.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v49.u32[3 - ((ea & 0xF) >> 2)]);
	// vperm128 v48,v56,v56,v0
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stvewx128 v49,r9,r5
	ea = (ctx.r9.u32 + ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v49.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,224(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// stvewx128 v49,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v49.u32[3 - ((ea & 0xF) >> 2)]);
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// li r10,52
	ctx.r10.s64 = 52;
	// stvewx128 v49,r8,r7
	ea = (ctx.r8.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v49.u32[3 - ((ea & 0xF) >> 2)]);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r3,56
	ctx.r3.s64 = 56;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stvewx128 v48,r6,r4
	ea = (ctx.r6.u32 + ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v48.u32[3 - ((ea & 0xF) >> 2)]);
	// li r7,60
	ctx.r7.s64 = 60;
	// stvewx128 v48,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v48.u32[3 - ((ea & 0xF) >> 2)]);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stvewx128 v48,r5,r3
	ea = (ctx.r5.u32 + ctx.r3.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v48.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx128 v48,r8,r7
	ea = (ctx.r8.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v48.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// lfs f3,21768(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21768);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lfs f0,560(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 560);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f3
	ctx.cr6.compare(ctx.f0.f64, ctx.f3.f64);
	// lfs f2,556(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 556);
	ctx.f2.f64 = double(temp.f32);
	// beq cr6,0x8216e004
	if (ctx.cr6.eq) goto loc_8216E004;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
loc_8216E004:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stfs f3,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f3,144(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f31.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// bl 0x820b6ae8
	ctx.lr = 0x8216E030;
	sub_820B6AE8(ctx, base);
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820b6890
	ctx.lr = 0x8216E040;
	sub_820B6890(ctx, base);
	// addi r5,r1,624
	ctx.r5.s64 = ctx.r1.s64 + 624;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x820b6890
	ctx.lr = 0x8216E050;
	sub_820B6890(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x820b6890
	ctx.lr = 0x8216E060;
	sub_820B6890(ctx, base);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x820b6a00
	ctx.lr = 0x8216E06C;
	sub_820B6A00(ctx, base);
	// lwz r10,612(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 612);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// rldicr r7,r7,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209a998
	ctx.lr = 0x8216E08C;
	sub_8209A998(ctx, base);
	// addi r1,r1,592
	ctx.r1.s64 = ctx.r1.s64 + 592;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216E098"))) PPC_WEAK_FUNC(sub_8216E098);
PPC_FUNC_IMPL(__imp__sub_8216E098) {
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
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209af10
	ctx.lr = 0x8216E0C8;
	sub_8209AF10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820972d8
	ctx.lr = 0x8216E0D4;
	sub_820972D8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096e78
	ctx.lr = 0x8216E0E0;
	sub_82096E78(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097338
	ctx.lr = 0x8216E0EC;
	sub_82097338(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,500(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 500);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x8216E100;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,504(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 504);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x8216E114;
	sub_8209AB80(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8216E120;
	sub_82096FD0(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x8216E12C;
	sub_82097060(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096eb0
	ctx.lr = 0x8216E138;
	sub_82096EB0(ctx, base);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,1164(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1164);
	// rlwimi r6,r8,24,7,8
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 24) & 0x1800000) | (ctx.r6.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r6,1164(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1164, ctx.r6.u32);
	// ld r5,24(r7)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r7.u32 + 24);
	// oris r3,r5,32768
	ctx.r3.u64 = ctx.r5.u64 | 2147483648;
	// std r3,24(r7)
	PPC_STORE_U64(ctx.r7.u32 + 24, ctx.r3.u64);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,1152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1152);
	// rlwinm r9,r10,0,22,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFE3FF;
	// stw r9,1152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1152, ctx.r9.u32);
	// ld r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 24);
	// oris r7,r8,32768
	ctx.r7.u64 = ctx.r8.u64 | 2147483648;
	// std r7,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r7.u64);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r5,1152(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1152);
	// rlwinm r3,r5,0,19,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFF1FFF;
	// stw r3,1152(r6)
	PPC_STORE_U32(ctx.r6.u32 + 1152, ctx.r3.u32);
	// ld r11,24(r6)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r6.u32 + 24);
	// oris r10,r11,32768
	ctx.r10.u64 = ctx.r11.u64 | 2147483648;
	// std r10,24(r6)
	PPC_STORE_U64(ctx.r6.u32 + 24, ctx.r10.u64);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82096e18
	ctx.lr = 0x8216E19C;
	sub_82096E18(ctx, base);
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

__attribute__((alias("__imp__sub_8216E1B4"))) PPC_WEAK_FUNC(sub_8216E1B4);
PPC_FUNC_IMPL(__imp__sub_8216E1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E1B8"))) PPC_WEAK_FUNC(sub_8216E1B8);
PPC_FUNC_IMPL(__imp__sub_8216E1B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8216E1C0;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// std r4,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r4.u64);
	// li r3,20
	ctx.r3.s64 = 20;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x82079fd8
	ctx.lr = 0x8216E1DC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r25,0
	ctx.r25.s64 = 0;
	// beq cr6,0x8216e204
	if (ctx.cr6.eq) goto loc_8216E204;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r25.u32);
	// stw r25,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r25.u32);
	// stw r25,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r25.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r25.u32);
	// stw r25,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r25.u32);
	// b 0x8216e208
	goto loc_8216E208;
loc_8216E204:
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_8216E208:
	// clrlwi r30,r30,24
	ctx.r30.u64 = ctx.r30.u32 & 0xFF;
	// lwz r27,200(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lwz r26,204(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// li r11,1
	ctx.r11.s64 = 1;
	// addic r10,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r10.s64 = ctx.r30.s64 + -1;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// clrlwi r28,r29,24
	ctx.r28.u64 = ctx.r29.u32 & 0xFF;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// and r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 & ctx.r11.u64;
	// stw r26,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r26.u32);
	// lis r8,6184
	ctx.r8.s64 = 405274624;
	// bne cr6,0x8216e244
	if (!ctx.cr6.eq) goto loc_8216E244;
	// lis r8,10280
	ctx.r8.s64 = 673710080;
loc_8216E244:
	// ori r8,r8,390
	ctx.r8.u64 = ctx.r8.u64 | 390;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8209d2e0
	ctx.lr = 0x8216E264;
	sub_8209D2E0(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216e340
	if (ctx.cr6.eq) goto loc_8216E340;
	// addi r29,r31,12
	ctx.r29.s64 = ctx.r31.s64 + 12;
	// stw r25,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r25.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8216e2b8
	if (ctx.cr6.eq) goto loc_8216E2B8;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lis r5,6184
	ctx.r5.s64 = 405274624;
	// bne cr6,0x8216e290
	if (!ctx.cr6.eq) goto loc_8216E290;
	// lis r5,10280
	ctx.r5.s64 = 673710080;
loc_8216E290:
	// ori r5,r5,390
	ctx.r5.u64 = ctx.r5.u64 | 390;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8209d400
	ctx.lr = 0x8216E2A8;
	sub_8209D400(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8216e2b8
	if (!ctx.cr6.eq) goto loc_8216E2B8;
	// bl 0x8210e878
	ctx.lr = 0x8216E2B8;
	sub_8210E878(ctx, base);
loc_8216E2B8:
	// lwz r10,468(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 468);
	// addi r4,r24,456
	ctx.r4.s64 = ctx.r24.s64 + 456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8216e2d0
	if (!ctx.cr6.eq) goto loc_8216E2D0;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// b 0x8216e2dc
	goto loc_8216E2DC;
loc_8216E2D0:
	// lwz r11,20(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_8216E2DC:
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8216e308
	if (!ctx.cr6.lt) goto loc_8216E308;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8216E308:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8216e314
	if (!ctx.cr6.gt) goto loc_8216E314;
	// twi 31,r0,22
loc_8216E314:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x820697e0
	ctx.lr = 0x8216E330;
	sub_820697E0(ctx, base);
	// lwz r31,80(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8216E340:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216E34C"))) PPC_WEAK_FUNC(sub_8216E34C);
PPC_FUNC_IMPL(__imp__sub_8216E34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E350"))) PPC_WEAK_FUNC(sub_8216E350);
PPC_FUNC_IMPL(__imp__sub_8216E350) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r5,484(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 484);
	// stw r5,480(r3)
	PPC_STORE_U32(ctx.r3.u32 + 480, ctx.r5.u32);
	// lwz r4,152(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r11,488(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 488);
	// stw r11,484(r3)
	PPC_STORE_U32(ctx.r3.u32 + 484, ctx.r11.u32);
	// bl 0x8216e098
	ctx.lr = 0x8216E3A4;
	sub_8216E098(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,39
	ctx.r10.s64 = 39;
	// stw r30,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,508(r31)
	PPC_STORE_U32(ctx.r31.u32 + 508, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,512(r31)
	PPC_STORE_U32(ctx.r31.u32 + 512, ctx.r30.u32);
	// addi r11,r31,504
	ctx.r11.s64 = ctx.r31.s64 + 504;
	// stw r30,516(r31)
	PPC_STORE_U32(ctx.r31.u32 + 516, ctx.r30.u32);
	// stw r10,504(r31)
	PPC_STORE_U32(ctx.r31.u32 + 504, ctx.r10.u32);
	// bl 0x8216d598
	ctx.lr = 0x8216E3D0;
	sub_8216D598(ctx, base);
	// lbz r9,541(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 541);
	// stw r30,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r30.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8216e404
	if (ctx.cr6.eq) goto loc_8216E404;
	// li r11,1024
	ctx.r11.s64 = 1024;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216e1b8
	ctx.lr = 0x8216E400;
	sub_8216E1B8(ctx, base);
	// stw r3,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r3.u32);
loc_8216E404:
	// lis r11,-256
	ctx.r11.s64 = -16777216;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 536, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8216E428"))) PPC_WEAK_FUNC(sub_8216E428);
PPC_FUNC_IMPL(__imp__sub_8216E428) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8216E430;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r10,r11,5936
	ctx.r10.s64 = ctx.r11.s64 + 5936;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// addi r30,r31,456
	ctx.r30.s64 = ctx.r31.s64 + 456;
	// bl 0x82079fd8
	ctx.lr = 0x8216E45C;
	sub_82079FD8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8216e470
	if (ctx.cr6.eq) goto loc_8216E470;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x8216e474
	goto loc_8216E474;
loc_8216E470:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_8216E474:
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r11,500(r31)
	PPC_STORE_U32(ctx.r31.u32 + 500, ctx.r11.u32);
	// std r28,520(r31)
	PPC_STORE_U64(ctx.r31.u32 + 520, ctx.r28.u64);
	// stw r29,528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 528, ctx.r29.u32);
	// stb r27,541(r31)
	PPC_STORE_U8(ctx.r31.u32 + 541, ctx.r27.u8);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,480(r31)
	PPC_STORE_U32(ctx.r31.u32 + 480, ctx.r11.u32);
	// stw r11,484(r31)
	PPC_STORE_U32(ctx.r31.u32 + 484, ctx.r11.u32);
	// stw r11,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r11.u32);
	// bl 0x8216e350
	ctx.lr = 0x8216E4B0;
	sub_8216E350(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216E4BC"))) PPC_WEAK_FUNC(sub_8216E4BC);
PPC_FUNC_IMPL(__imp__sub_8216E4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E4C0"))) PPC_WEAK_FUNC(sub_8216E4C0);
PPC_FUNC_IMPL(__imp__sub_8216E4C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,120(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	// lwz r10,124(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E4D4"))) PPC_WEAK_FUNC(sub_8216E4D4);
PPC_FUNC_IMPL(__imp__sub_8216E4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E4D8"))) PPC_WEAK_FUNC(sub_8216E4D8);
PPC_FUNC_IMPL(__imp__sub_8216E4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E4E4"))) PPC_WEAK_FUNC(sub_8216E4E4);
PPC_FUNC_IMPL(__imp__sub_8216E4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E4E8"))) PPC_WEAK_FUNC(sub_8216E4E8);
PPC_FUNC_IMPL(__imp__sub_8216E4E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E4F4"))) PPC_WEAK_FUNC(sub_8216E4F4);
PPC_FUNC_IMPL(__imp__sub_8216E4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E4F8"))) PPC_WEAK_FUNC(sub_8216E4F8);
PPC_FUNC_IMPL(__imp__sub_8216E4F8) {
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
	// stfs f0,120(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stfs f13,124(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E510"))) PPC_WEAK_FUNC(sub_8216E510);
PPC_FUNC_IMPL(__imp__sub_8216E510) {
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
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// addi r4,r3,84
	ctx.r4.s64 = ctx.r3.s64 + 84;
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82063cc8
	ctx.lr = 0x8216E54C;
	sub_82063CC8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ld r6,112(r31)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r31.u32 + 112);
	// ld r4,120(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 120);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x8216f0a0
	ctx.lr = 0x8216E560;
	sub_8216F0A0(ctx, base);
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

__attribute__((alias("__imp__sub_8216E574"))) PPC_WEAK_FUNC(sub_8216E574);
PPC_FUNC_IMPL(__imp__sub_8216E574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E578"))) PPC_WEAK_FUNC(sub_8216E578);
PPC_FUNC_IMPL(__imp__sub_8216E578) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// addi r4,r3,84
	ctx.r4.s64 = ctx.r3.s64 + 84;
	// sth r11,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, ctx.r11.u16);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82063cc8
	ctx.lr = 0x8216E5B4;
	sub_82063CC8(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r6,112(r31)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r31.u32 + 112);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x8216f398
	ctx.lr = 0x8216E5C8;
	sub_8216F398(ctx, base);
	// ld r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 76, temp.u32);
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

__attribute__((alias("__imp__sub_8216E5F4"))) PPC_WEAK_FUNC(sub_8216E5F4);
PPC_FUNC_IMPL(__imp__sub_8216E5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E5F8"))) PPC_WEAK_FUNC(sub_8216E5F8);
PPC_FUNC_IMPL(__imp__sub_8216E5F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8216E600;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,5844
	ctx.r10.s64 = ctx.r11.s64 + 5844;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8216e634
	if (ctx.cr6.eq) goto loc_8216E634;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216E634;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8216E634:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r30,r31,84
	ctx.r30.s64 = ctx.r31.s64 + 84;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216e64c
	if (ctx.cr6.lt) goto loc_8216E64C;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8216E64C;
	sub_8207A630(ctx, base);
loc_8216E64C:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r9,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r9.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// sth r11,4(r30)
	PPC_STORE_U16(ctx.r30.u32 + 4, ctx.r11.u16);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8216E674;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r30,r8,-1456
	ctx.r30.s64 = ctx.r8.s64 + -1456;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8216E68C;
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

__attribute__((alias("__imp__sub_8216E69C"))) PPC_WEAK_FUNC(sub_8216E69C);
PPC_FUNC_IMPL(__imp__sub_8216E69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E6A0"))) PPC_WEAK_FUNC(sub_8216E6A0);
PPC_FUNC_IMPL(__imp__sub_8216E6A0) {
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
	// addi r3,r3,84
	ctx.r3.s64 = ctx.r3.s64 + 84;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82063cc8
	ctx.lr = 0x8216E6CC;
	sub_82063CC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8216e578
	ctx.lr = 0x8216E6D4;
	sub_8216E578(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8216e6e8
	if (ctx.cr6.lt) goto loc_8216E6E8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8216E6E8;
	sub_8207A630(ctx, base);
loc_8216E6E8:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
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

__attribute__((alias("__imp__sub_8216E714"))) PPC_WEAK_FUNC(sub_8216E714);
PPC_FUNC_IMPL(__imp__sub_8216E714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E718"))) PPC_WEAK_FUNC(sub_8216E718);
PPC_FUNC_IMPL(__imp__sub_8216E718) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8216E720;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,15
	ctx.r29.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x820601f8
	ctx.lr = 0x8216E750;
	sub_820601F8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d3a20
	ctx.lr = 0x8216E75C;
	sub_821D3A20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8216e6a0
	ctx.lr = 0x8216E768;
	sub_8216E6A0(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8216e77c
	if (ctx.cr6.lt) goto loc_8216E77C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8216E77C;
	sub_8207A630(ctx, base);
loc_8216E77C:
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8216E790"))) PPC_WEAK_FUNC(sub_8216E790);
PPC_FUNC_IMPL(__imp__sub_8216E790) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x8216a4d8
	ctx.lr = 0x8216E7B0;
	sub_8216A4D8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r31.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,5844
	ctx.r9.s64 = ctx.r11.s64 + 5844;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r8,7
	ctx.r8.s64 = 7;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r11.u32);
	// stw r8,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r8.u32);
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// sth r11,88(r3)
	PPC_STORE_U16(ctx.r3.u32 + 88, ctx.r11.u16);
	// addi r11,r3,84
	ctx.r11.s64 = ctx.r3.s64 + 84;
	// std r30,112(r3)
	PPC_STORE_U64(ctx.r3.u32 + 112, ctx.r30.u64);
	// stfs f0,120(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stfs f0,124(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
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

__attribute__((alias("__imp__sub_8216E804"))) PPC_WEAK_FUNC(sub_8216E804);
PPC_FUNC_IMPL(__imp__sub_8216E804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E808"))) PPC_WEAK_FUNC(sub_8216E808);
PPC_FUNC_IMPL(__imp__sub_8216E808) {
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
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bge cr6,0x8216e888
	if (!ctx.cr6.lt) goto loc_8216E888;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a498
	ctx.lr = 0x8216E838;
	sub_8208A498(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,134
	ctx.r11.s64 = ctx.r11.s64 + 134;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r30.u32);
	// lfd f0,792(r31)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r31.u32 + 792);
	// ld r9,800(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 800);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// subf r7,r9,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r9.s64;
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// addi r6,r11,3
	ctx.r6.s64 = ctx.r11.s64 + 3;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// fdiv f10,f11,f13
	ctx.f10.f64 = ctx.f11.f64 / ctx.f13.f64;
	// stfdx f10,r5,r31
	PPC_STORE_U64(ctx.r5.u32 + ctx.r31.u32, ctx.f10.u64);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// stw r4,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r4.u32);
loc_8216E888:
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

__attribute__((alias("__imp__sub_8216E8A0"))) PPC_WEAK_FUNC(sub_8216E8A0);
PPC_FUNC_IMPL(__imp__sub_8216E8A0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E8A4"))) PPC_WEAK_FUNC(sub_8216E8A4);
PPC_FUNC_IMPL(__imp__sub_8216E8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E8A8"))) PPC_WEAK_FUNC(sub_8216E8A8);
PPC_FUNC_IMPL(__imp__sub_8216E8A8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,5840
	ctx.r10.s64 = ctx.r11.s64 + 5840;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E8B8"))) PPC_WEAK_FUNC(sub_8216E8B8);
PPC_FUNC_IMPL(__imp__sub_8216E8B8) {
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
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,5836
	ctx.r10.s64 = ctx.r11.s64 + 5836;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8216e900
	if (ctx.cr6.eq) goto loc_8216E900;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8216E8F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_8216E900:
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

__attribute__((alias("__imp__sub_8216E914"))) PPC_WEAK_FUNC(sub_8216E914);
PPC_FUNC_IMPL(__imp__sub_8216E914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E918"))) PPC_WEAK_FUNC(sub_8216E918);
PPC_FUNC_IMPL(__imp__sub_8216E918) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E920"))) PPC_WEAK_FUNC(sub_8216E920);
PPC_FUNC_IMPL(__imp__sub_8216E920) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r3,r11,-31136
	ctx.r3.s64 = ctx.r11.s64 + -31136;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8216E92C"))) PPC_WEAK_FUNC(sub_8216E92C);
PPC_FUNC_IMPL(__imp__sub_8216E92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8216E930"))) PPC_WEAK_FUNC(sub_8216E930);
PPC_FUNC_IMPL(__imp__sub_8216E930) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r11,-12560
	ctx.r3.s64 = ctx.r11.s64 + -12560;
	// blr 
	return;
}

