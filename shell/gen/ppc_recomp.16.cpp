#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_820FAEF0"))) PPC_WEAK_FUNC(sub_820FAEF0);
PPC_FUNC_IMPL(__imp__sub_820FAEF0) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820faf24
	if (ctx.cr6.lt) goto loc_820FAF24;
	// stfs f1,40(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// b 0x820faf28
	goto loc_820FAF28;
loc_820FAF24:
	// stfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 40, temp.u32);
loc_820FAF28:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820faf54
	if (ctx.cr6.eq) goto loc_820FAF54;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lfs f31,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f79e8
	ctx.lr = 0x820FAF44;
	sub_820F79E8(ctx, base);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x820f5fe0
	ctx.lr = 0x820FAF54;
	sub_820F5FE0(ctx, base);
loc_820FAF54:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_820FAF70"))) PPC_WEAK_FUNC(sub_820FAF70);
PPC_FUNC_IMPL(__imp__sub_820FAF70) {
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
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// stfs f1,44(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fafbc
	if (ctx.cr6.eq) goto loc_820FAFBC;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f30,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f6ef8
	ctx.lr = 0x820FAFAC;
	sub_820F6EF8(ctx, base);
	// fadds f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bl 0x820f6040
	ctx.lr = 0x820FAFBC;
	sub_820F6040(ctx, base);
loc_820FAFBC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_820FAFD8"))) PPC_WEAK_FUNC(sub_820FAFD8);
PPC_FUNC_IMPL(__imp__sub_820FAFD8) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r7,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r7.u8);
	// addi r6,r8,22040
	ctx.r6.s64 = ctx.r8.s64 + 22040;
	// lfs f0,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f1,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f1.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stfs f1,56(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stfs f0,60(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stb r11,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, ctx.r11.u8);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// beq cr6,0x820fb0e0
	if (ctx.cr6.eq) goto loc_820FB0E0;
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r10,21008
	ctx.r9.s64 = ctx.r10.s64 + 21008;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lfsx f1,r8,r9
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820faef0
	ctx.lr = 0x820FB06C;
	sub_820FAEF0(ctx, base);
	// lhz r5,7(r30)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + 7);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lhz r6,5(r30)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r30.u32 + 5);
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rlwinm r10,r6,29,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0xFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfs f0,22044(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 22044);
	ctx.f0.f64 = double(temp.f32);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,64(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f2,f8,f0
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// stfs f2,68(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// beq cr6,0x820fb128
	if (ctx.cr6.eq) goto loc_820FB128;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fb128
	if (ctx.cr6.eq) goto loc_820FB128;
	// lhz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fb128
	if (ctx.cr6.eq) goto loc_820FB128;
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// b 0x820fb124
	goto loc_820FB124;
loc_820FB0E0:
	// bl 0x820faef0
	ctx.lr = 0x820FB0E4;
	sub_820FAEF0(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r10,r11,21008
	ctx.r10.s64 = ctx.r11.s64 + 21008;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lfs f1,1024(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,1028(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1028);
	ctx.f2.f64 = double(temp.f32);
	// stfs f1,64(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stfs f2,68(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// beq cr6,0x820fb128
	if (ctx.cr6.eq) goto loc_820FB128;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fb128
	if (ctx.cr6.eq) goto loc_820FB128;
	// lhz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fb128
	if (ctx.cr6.eq) goto loc_820FB128;
loc_820FB124:
	// bl 0x820f6000
	ctx.lr = 0x820FB128;
	sub_820F6000(ctx, base);
loc_820FB128:
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

__attribute__((alias("__imp__sub_820FB144"))) PPC_WEAK_FUNC(sub_820FB144);
PPC_FUNC_IMPL(__imp__sub_820FB144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB148"))) PPC_WEAK_FUNC(sub_820FB148);
PPC_FUNC_IMPL(__imp__sub_820FB148) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FB150;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// bne cr6,0x820fb1b0
	if (!ctx.cr6.eq) goto loc_820FB1B0;
	// lbz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + 48);
	// bl 0x820f7720
	ctx.lr = 0x820FB178;
	sub_820F7720(ctx, base);
	// clrlwi r29,r3,24
	ctx.r29.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820fb1b0
	if (ctx.cr6.eq) goto loc_820FB1B0;
	// li r31,0
	ctx.r31.s64 = 0;
loc_820FB188:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820f5590
	ctx.lr = 0x820FB1A0;
	sub_820F5590(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// clrlwi r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x820fb188
	if (ctx.cr6.lt) goto loc_820FB188;
loc_820FB1B0:
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x820f6990
	ctx.lr = 0x820FB1B8;
	sub_820F6990(ctx, base);
	// lbz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 32);
	// rlwinm r11,r10,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// bne cr6,0x820fb1f0
	if (!ctx.cr6.eq) goto loc_820FB1F0;
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fb1f0
	if (ctx.cr6.eq) goto loc_820FB1F0;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820fb1f0
	if (!ctx.cr6.eq) goto loc_820FB1F0;
	// clrlwi r11,r10,25
	ctx.r11.u64 = ctx.r10.u32 & 0x7F;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r11,32(r30)
	PPC_STORE_U8(ctx.r30.u32 + 32, ctx.r11.u8);
	// bl 0x820fae68
	ctx.lr = 0x820FB1F0;
	sub_820FAE68(ctx, base);
loc_820FB1F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FB1F8"))) PPC_WEAK_FUNC(sub_820FB1F8);
PPC_FUNC_IMPL(__imp__sub_820FB1F8) {
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
	// lwz r4,36(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820fb224
	if (ctx.cr6.eq) goto loc_820FB224;
	// bl 0x820fae00
	ctx.lr = 0x820FB21C;
	sub_820FAE00(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_820FB224:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x8210e878
	ctx.lr = 0x820FB22C;
	sub_8210E878(ctx, base);
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

__attribute__((alias("__imp__sub_820FB240"))) PPC_WEAK_FUNC(sub_820FB240);
PPC_FUNC_IMPL(__imp__sub_820FB240) {
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
	// bl 0x820f7db8
	ctx.lr = 0x820FB258;
	sub_820F7DB8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,22064
	ctx.r9.s64 = ctx.r11.s64 + 22064;
	// addi r8,r10,22048
	ctx.r8.s64 = ctx.r10.s64 + 22048;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_820FB288"))) PPC_WEAK_FUNC(sub_820FB288);
PPC_FUNC_IMPL(__imp__sub_820FB288) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820fb3a0
	sub_820FB3A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FB290"))) PPC_WEAK_FUNC(sub_820FB290);
PPC_FUNC_IMPL(__imp__sub_820FB290) {
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
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820fb2d4
	if (ctx.cr6.eq) goto loc_820FB2D4;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// beq cr6,0x820fb2d4
	if (ctx.cr6.eq) goto loc_820FB2D4;
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820fb2f0
	if (!ctx.cr6.eq) goto loc_820FB2F0;
loc_820FB2D4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FB2E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r30,0(r3)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// b 0x820fb2f4
	goto loc_820FB2F4;
loc_820FB2F0:
	// li r30,0
	ctx.r30.s64 = 0;
loc_820FB2F4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FB308;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhzx r3,r3,r30
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r30.u32);
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

__attribute__((alias("__imp__sub_820FB324"))) PPC_WEAK_FUNC(sub_820FB324);
PPC_FUNC_IMPL(__imp__sub_820FB324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB328"))) PPC_WEAK_FUNC(sub_820FB328);
PPC_FUNC_IMPL(__imp__sub_820FB328) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lhz r3,10(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 10);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FB334"))) PPC_WEAK_FUNC(sub_820FB334);
PPC_FUNC_IMPL(__imp__sub_820FB334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB338"))) PPC_WEAK_FUNC(sub_820FB338);
PPC_FUNC_IMPL(__imp__sub_820FB338) {
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
	// lwz r31,32(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FB35C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lhz r3,10(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 10);
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

__attribute__((alias("__imp__sub_820FB37C"))) PPC_WEAK_FUNC(sub_820FB37C);
PPC_FUNC_IMPL(__imp__sub_820FB37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB380"))) PPC_WEAK_FUNC(sub_820FB380);
PPC_FUNC_IMPL(__imp__sub_820FB380) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r3,r11,10
	ctx.r3.s64 = ctx.r11.s64 + 10;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FB38C"))) PPC_WEAK_FUNC(sub_820FB38C);
PPC_FUNC_IMPL(__imp__sub_820FB38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB390"))) PPC_WEAK_FUNC(sub_820FB390);
PPC_FUNC_IMPL(__imp__sub_820FB390) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lbz r3,9(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FB39C"))) PPC_WEAK_FUNC(sub_820FB39C);
PPC_FUNC_IMPL(__imp__sub_820FB39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB3A0"))) PPC_WEAK_FUNC(sub_820FB3A0);
PPC_FUNC_IMPL(__imp__sub_820FB3A0) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,22064
	ctx.r9.s64 = ctx.r11.s64 + 22064;
	// addi r8,r10,22048
	ctx.r8.s64 = ctx.r10.s64 + 22048;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x820f7268
	ctx.lr = 0x820FB3D8;
	sub_820F7268(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820fb3f8
	if (ctx.cr6.eq) goto loc_820FB3F8;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32793
	ctx.r4.u64 = ctx.r4.u64 | 32793;
	// bl 0x820e9410
	ctx.lr = 0x820FB3F4;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FB3F8:
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

__attribute__((alias("__imp__sub_820FB410"))) PPC_WEAK_FUNC(sub_820FB410);
PPC_FUNC_IMPL(__imp__sub_820FB410) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FB418;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820fb450
	if (ctx.cr6.eq) goto loc_820FB450;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// beq cr6,0x820fb450
	if (ctx.cr6.eq) goto loc_820FB450;
	// rlwinm r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x820fb46c
	if (!ctx.cr6.eq) goto loc_820FB46C;
loc_820FB450:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FB464;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// b 0x820fb470
	goto loc_820FB470;
loc_820FB46C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FB470:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// clrlwi r29,r11,16
	ctx.r29.u64 = ctx.r11.u32 & 0xFFFF;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// bne cr6,0x820fb498
	if (!ctx.cr6.eq) goto loc_820FB498;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fb290
	ctx.lr = 0x820FB490;
	sub_820FB290(ctx, base);
	// clrlwi r8,r3,16
	ctx.r8.u64 = ctx.r3.u32 & 0xFFFF;
	// b 0x820fb49c
	goto loc_820FB49C;
loc_820FB498:
	// li r8,0
	ctx.r8.s64 = 0;
loc_820FB49C:
	// clrlwi r9,r30,16
	ctx.r9.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// rlwinm r11,r30,3,13,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0x7FFF8;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// clrlwi r9,r29,16
	ctx.r9.u64 = ctx.r29.u32 & 0xFFFF;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r3,r11,10
	ctx.r3.s64 = ctx.r11.s64 + 10;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FB4CC"))) PPC_WEAK_FUNC(sub_820FB4CC);
PPC_FUNC_IMPL(__imp__sub_820FB4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB4D0"))) PPC_WEAK_FUNC(sub_820FB4D0);
PPC_FUNC_IMPL(__imp__sub_820FB4D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x820FB4D8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r26,0
	ctx.r26.s64 = 0;
	// bl 0x820f7598
	ctx.lr = 0x820FB4FC;
	sub_820F7598(ctx, base);
	// lis r11,-30009
	ctx.r11.s64 = -1966669824;
	// li r31,0
	ctx.r31.s64 = 0;
	// ori r23,r11,25
	ctx.r23.u64 = ctx.r11.u64 | 25;
loc_820FB508:
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// clrlwi r25,r31,24
	ctx.r25.u64 = ctx.r31.u32 & 0xFF;
	// lbz r10,9(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9);
	// cmplw cr6,r25,r10
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820fb638
	if (!ctx.cr6.lt) goto loc_820FB638;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32776
	ctx.r4.u64 = ctx.r4.u64 | 32776;
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x820e9408
	ctx.lr = 0x820FB534;
	sub_820E9408(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fb5c4
	if (ctx.cr6.eq) goto loc_820FB5C4;
	// clrlwi r4,r31,24
	ctx.r4.u64 = ctx.r31.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820fb410
	ctx.lr = 0x820FB54C;
	sub_820FB410(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// bl 0x820fafd8
	ctx.lr = 0x820FB564;
	sub_820FAFD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fb5cc
	if (!ctx.cr6.eq) goto loc_820FB5CC;
loc_820FB570:
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
loc_820FB578:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820fb598
	if (ctx.cr6.eq) goto loc_820FB598;
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
	ctx.lr = 0x820FB598;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FB598:
	// cmpw cr6,r28,r23
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r23.s32, ctx.xer);
	// bne cr6,0x820fb5a8
	if (!ctx.cr6.eq) goto loc_820FB5A8;
	// li r24,1
	ctx.r24.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
loc_820FB5A8:
	// addi r11,r25,1
	ctx.r11.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// bge cr6,0x820fb508
	if (!ctx.cr6.lt) goto loc_820FB508;
loc_820FB5B8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_820FB5C4:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x820fb570
	goto loc_820FB570;
loc_820FB5CC:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x820fb578
	if (ctx.cr6.lt) goto loc_820FB578;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1);
	// bl 0x820fad58
	ctx.lr = 0x820FB5E8;
	sub_820FAD58(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fb578
	if (ctx.cr6.lt) goto loc_820FB578;
	// stw r27,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r27.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fb614
	if (ctx.cr6.eq) goto loc_820FB614;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x820fb618
	if (ctx.cr6.eq) goto loc_820FB618;
loc_820FB614:
	// li r22,0
	ctx.r22.s64 = 0;
loc_820FB618:
	// addi r11,r30,44
	ctx.r11.s64 = ctx.r30.s64 + 44;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r11,52(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r31.u32);
	// stw r31,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r31.u32);
	// b 0x820fb5a8
	goto loc_820FB5A8;
loc_820FB638:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x820fb5b8
	if (ctx.cr6.lt) goto loc_820FB5B8;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x820fb65c
	if (!ctx.cr6.eq) goto loc_820FB65C;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x820fb65c
	if (ctx.cr6.eq) goto loc_820FB65C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_820FB65C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f7848
	ctx.lr = 0x820FB664;
	sub_820F7848(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fb684
	if (ctx.cr6.lt) goto loc_820FB684;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x820fb684
	if (ctx.cr6.eq) goto loc_820FB684;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f7598
	ctx.lr = 0x820FB684;
	sub_820F7598(ctx, base);
loc_820FB684:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FB690"))) PPC_WEAK_FUNC(sub_820FB690);
PPC_FUNC_IMPL(__imp__sub_820FB690) {
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
	// bl 0x820f7db8
	ctx.lr = 0x820FB6A8;
	sub_820F7DB8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,22108
	ctx.r9.s64 = ctx.r11.s64 + 22108;
	// addi r8,r10,22092
	ctx.r8.s64 = ctx.r10.s64 + 22092;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_820FB6D8"))) PPC_WEAK_FUNC(sub_820FB6D8);
PPC_FUNC_IMPL(__imp__sub_820FB6D8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820fb748
	sub_820FB748(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FB6E0"))) PPC_WEAK_FUNC(sub_820FB6E0);
PPC_FUNC_IMPL(__imp__sub_820FB6E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lhz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FB6EC"))) PPC_WEAK_FUNC(sub_820FB6EC);
PPC_FUNC_IMPL(__imp__sub_820FB6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB6F0"))) PPC_WEAK_FUNC(sub_820FB6F0);
PPC_FUNC_IMPL(__imp__sub_820FB6F0) {
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
	// lwz r31,32(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FB714;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lhz r3,12(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 12);
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

__attribute__((alias("__imp__sub_820FB734"))) PPC_WEAK_FUNC(sub_820FB734);
PPC_FUNC_IMPL(__imp__sub_820FB734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB738"))) PPC_WEAK_FUNC(sub_820FB738);
PPC_FUNC_IMPL(__imp__sub_820FB738) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FB744"))) PPC_WEAK_FUNC(sub_820FB744);
PPC_FUNC_IMPL(__imp__sub_820FB744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FB748"))) PPC_WEAK_FUNC(sub_820FB748);
PPC_FUNC_IMPL(__imp__sub_820FB748) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,22108
	ctx.r9.s64 = ctx.r11.s64 + 22108;
	// addi r8,r10,22092
	ctx.r8.s64 = ctx.r10.s64 + 22092;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x820f7268
	ctx.lr = 0x820FB780;
	sub_820F7268(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820fb7a0
	if (ctx.cr6.eq) goto loc_820FB7A0;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32794
	ctx.r4.u64 = ctx.r4.u64 | 32794;
	// bl 0x820e9410
	ctx.lr = 0x820FB79C;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FB7A0:
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

__attribute__((alias("__imp__sub_820FB7B8"))) PPC_WEAK_FUNC(sub_820FB7B8);
PPC_FUNC_IMPL(__imp__sub_820FB7B8) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,108(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// lwz r9,112(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// subf r31,r9,r10
	ctx.r31.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820FB7F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
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

__attribute__((alias("__imp__sub_820FB808"))) PPC_WEAK_FUNC(sub_820FB808);
PPC_FUNC_IMPL(__imp__sub_820FB808) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FB810;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820f7598
	ctx.lr = 0x820FB824;
	sub_820F7598(ctx, base);
	// lwz r9,136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwimi r9,r11,0,27,31
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0x1F) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFE0);
	// li r10,255
	ctx.r10.s64 = 255;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// rlwinm r7,r8,0,27,2
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFE000001F;
	// li r6,0
	ctx.r6.s64 = 0;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r9,r11,8192
	ctx.r9.u64 = ctx.r11.u64 | 536870912;
	// ori r4,r4,32776
	ctx.r4.u64 = ctx.r4.u64 | 32776;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// rlwinm r7,r8,0,2,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// addi r30,r31,136
	ctx.r30.s64 = ctx.r31.s64 + 136;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r7,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r7.u32);
	// clrlwi r9,r11,1
	ctx.r9.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// stw r9,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r9.u32);
	// stb r10,142(r31)
	PPC_STORE_U8(ctx.r31.u32 + 142, ctx.r10.u8);
	// sth r29,140(r31)
	PPC_STORE_U16(ctx.r31.u32 + 140, ctx.r29.u16);
	// lbz r8,143(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 143);
	// rlwinm r7,r8,0,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// stb r7,143(r31)
	PPC_STORE_U8(ctx.r31.u32 + 143, ctx.r7.u8);
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,143(r31)
	PPC_STORE_U8(ctx.r31.u32 + 143, ctx.r10.u8);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r8,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// stb r8,143(r31)
	PPC_STORE_U8(ctx.r31.u32 + 143, ctx.r8.u8);
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// rlwinm r11,r11,0,29,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stb r11,143(r31)
	PPC_STORE_U8(ctx.r31.u32 + 143, ctx.r11.u8);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lhz r9,9(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 9);
	// sth r9,144(r31)
	PPC_STORE_U16(ctx.r31.u32 + 144, ctx.r9.u16);
	// lbz r8,11(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11);
	// stb r8,146(r31)
	PPC_STORE_U8(ctx.r31.u32 + 146, ctx.r8.u8);
	// stb r29,147(r31)
	PPC_STORE_U8(ctx.r31.u32 + 147, ctx.r29.u8);
	// sth r29,148(r31)
	PPC_STORE_U16(ctx.r31.u32 + 148, ctx.r29.u16);
	// sth r29,150(r31)
	PPC_STORE_U16(ctx.r31.u32 + 150, ctx.r29.u16);
	// bl 0x820e9408
	ctx.lr = 0x820FB8EC;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fb914
	if (ctx.cr6.eq) goto loc_820FB914;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820fafd8
	ctx.lr = 0x820FB908;
	sub_820FAFD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fb988
	if (!ctx.cr6.eq) goto loc_820FB988;
loc_820FB914:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
loc_820FB91C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820fb93c
	if (ctx.cr6.eq) goto loc_820FB93C;
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
	ctx.lr = 0x820FB93C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FB93C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fb97c
	if (ctx.cr6.lt) goto loc_820FB97C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f7848
	ctx.lr = 0x820FB94C;
	sub_820F7848(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fb97c
	if (ctx.cr6.lt) goto loc_820FB97C;
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fb97c
	if (ctx.cr6.eq) goto loc_820FB97C;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820fb97c
	if (!ctx.cr6.eq) goto loc_820FB97C;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f7598
	ctx.lr = 0x820FB97C;
	sub_820F7598(ctx, base);
loc_820FB97C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FB988:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fac80
	ctx.lr = 0x820FB998;
	sub_820FAC80(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fb91c
	if (ctx.cr6.lt) goto loc_820FB91C;
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r28,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r28.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r29,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r29.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// b 0x820fb93c
	goto loc_820FB93C;
}

__attribute__((alias("__imp__sub_820FB9C8"))) PPC_WEAK_FUNC(sub_820FB9C8);
PPC_FUNC_IMPL(__imp__sub_820FB9C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FB9D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FB9EC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FBA08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fba44
	if (ctx.cr6.lt) goto loc_820FBA44;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1);
	// bl 0x820edac8
	ctx.lr = 0x820FBA30;
	sub_820EDAC8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fba44
	if (ctx.cr6.lt) goto loc_820FBA44;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_820FBA44:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FBA4C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FBA58"))) PPC_WEAK_FUNC(sub_820FBA58);
PPC_FUNC_IMPL(__imp__sub_820FBA58) {
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
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FBA8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fbabc
	if (ctx.cr6.lt) goto loc_820FBABC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820edac8
	ctx.lr = 0x820FBAAC;
	sub_820EDAC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fbabc
	if (ctx.cr6.lt) goto loc_820FBABC;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_820FBABC:
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

__attribute__((alias("__imp__sub_820FBAD4"))) PPC_WEAK_FUNC(sub_820FBAD4);
PPC_FUNC_IMPL(__imp__sub_820FBAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FBAD8"))) PPC_WEAK_FUNC(sub_820FBAD8);
PPC_FUNC_IMPL(__imp__sub_820FBAD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FBAE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FBAFC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FBB10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// blt cr6,0x820fbbc0
	if (ctx.cr6.lt) goto loc_820FBBC0;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fbb44
	if (ctx.cr6.eq) goto loc_820FBB44;
	// lwz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x820fbbc0
	goto loc_820FBBC0;
loc_820FBB44:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32795
	ctx.r4.u64 = ctx.r4.u64 | 32795;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x820e9408
	ctx.lr = 0x820FBB5C;
	sub_820E9408(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fbb98
	if (ctx.cr6.eq) goto loc_820FBB98;
	// lwz r3,308(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FBB84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821035c0
	ctx.lr = 0x820FBB94;
	sub_821035C0(ctx, base);
	// b 0x820fbb9c
	goto loc_820FBB9C;
loc_820FBB98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820FBB9C:
	// stw r3,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fbbb8
	if (ctx.cr6.eq) goto loc_820FBBB8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82103868
	ctx.lr = 0x820FBBB0;
	sub_82103868(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x820fbbc0
	goto loc_820FBBC0;
loc_820FBBB8:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
loc_820FBBC0:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// blt cr6,0x820fbbfc
	if (ctx.cr6.lt) goto loc_820FBBFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820edac8
	ctx.lr = 0x820FBBE8;
	sub_820EDAC8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fbbfc
	if (ctx.cr6.lt) goto loc_820FBBFC;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_820FBBFC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FBC04;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FBC10"))) PPC_WEAK_FUNC(sub_820FBC10);
PPC_FUNC_IMPL(__imp__sub_820FBC10) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r7,14(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 14);
	// lhz r5,10(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 10);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820FBC3C"))) PPC_WEAK_FUNC(sub_820FBC3C);
PPC_FUNC_IMPL(__imp__sub_820FBC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FBC40"))) PPC_WEAK_FUNC(sub_820FBC40);
PPC_FUNC_IMPL(__imp__sub_820FBC40) {
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
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stb r30,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// sth r10,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// beq cr6,0x820fbcbc
	if (ctx.cr6.eq) goto loc_820FBCBC;
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x820fbcb4
	if (!ctx.cr6.eq) goto loc_820FBCB4;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,40(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// addi r6,r1,81
	ctx.r6.s64 = ctx.r1.s64 + 81;
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// addi r5,r1,82
	ctx.r5.s64 = ctx.r1.s64 + 82;
	// bl 0x821031c0
	ctx.lr = 0x820FBCA8;
	sub_821031C0(ctx, base);
	// lhz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// b 0x820fbcbc
	goto loc_820FBCBC;
loc_820FBCB4:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// li r9,255
	ctx.r9.s64 = 255;
loc_820FBCBC:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// sth r10,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r10.u16);
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
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

__attribute__((alias("__imp__sub_820FBCF0"))) PPC_WEAK_FUNC(sub_820FBCF0);
PPC_FUNC_IMPL(__imp__sub_820FBCF0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// lwz r3,372(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// ori r3,r3,64
	ctx.r3.u64 = ctx.r3.u64 | 64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FBD08"))) PPC_WEAK_FUNC(sub_820FBD08);
PPC_FUNC_IMPL(__imp__sub_820FBD08) {
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
	// lwz r11,396(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fbd68
	if (ctx.cr6.eq) goto loc_820FBD68;
	// bl 0x820e6990
	ctx.lr = 0x820FBD2C;
	sub_820E6990(ctx, base);
	// lwz r11,404(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 404);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// bgt cr6,0x820fbd40
	if (ctx.cr6.gt) goto loc_820FBD40;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FBD40:
	// lwz r10,400(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// lwz r9,396(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// subf r8,r10,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r10.s64;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// subf r3,r9,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r9.s64;
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
loc_820FBD68:
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

__attribute__((alias("__imp__sub_820FBD80"))) PPC_WEAK_FUNC(sub_820FBD80);
PPC_FUNC_IMPL(__imp__sub_820FBD80) {
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
	// lwz r11,396(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fbdc0
	if (ctx.cr6.eq) goto loc_820FBDC0;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lwz r31,100(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// bl 0x820fbd08
	ctx.lr = 0x820FBDA8;
	sub_820FBD08(ctx, base);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
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
loc_820FBDC0:
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

__attribute__((alias("__imp__sub_820FBDD8"))) PPC_WEAK_FUNC(sub_820FBDD8);
PPC_FUNC_IMPL(__imp__sub_820FBDD8) {
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
	// bl 0x820edd40
	ctx.lr = 0x820FBDF4;
	sub_820EDD40(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f0,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// ori r10,r9,65535
	ctx.r10.u64 = ctx.r9.u64 | 65535;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// addi r9,r8,22160
	ctx.r9.s64 = ctx.r8.s64 + 22160;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// addi r8,r7,18224
	ctx.r8.s64 = ctx.r7.s64 + 18224;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// addi r7,r6,18048
	ctx.r7.s64 = ctx.r6.s64 + 18048;
	// addi r6,r5,22156
	ctx.r6.s64 = ctx.r5.s64 + 22156;
	// addi r5,r4,22140
	ctx.r5.s64 = ctx.r4.s64 + 22140;
	// addi r4,r3,22136
	ctx.r4.s64 = ctx.r3.s64 + 22136;
	// addi r30,r11,19572
	ctx.r30.s64 = ctx.r11.s64 + 19572;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 368, ctx.r30.u32);
	// stw r3,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r3.u32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// stw r11,376(r31)
	PPC_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// stw r5,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r5.u32);
	// stw r4,368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 368, ctx.r4.u32);
	// stw r11,380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// stw r11,384(r31)
	PPC_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// stw r11,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// stw r11,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// stw r11,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// stw r11,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// stw r11,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// stw r11,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r11.u32);
	// stw r11,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
	// stw r11,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r11.u32);
	// stw r11,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r11.u32);
	// stw r11,428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
	// stw r11,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r11.u32);
	// stw r11,436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 436, ctx.r11.u32);
	// sth r10,440(r31)
	PPC_STORE_U16(ctx.r31.u32 + 440, ctx.r10.u16);
	// sth r10,442(r31)
	PPC_STORE_U16(ctx.r31.u32 + 442, ctx.r10.u16);
	// stw r11,444(r31)
	PPC_STORE_U32(ctx.r31.u32 + 444, ctx.r11.u32);
	// stw r11,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_820FBED0"))) PPC_WEAK_FUNC(sub_820FBED0);
PPC_FUNC_IMPL(__imp__sub_820FBED0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-24
	ctx.r3.s64 = ctx.r3.s64 + -24;
	// b 0x820fd4d8
	sub_820FD4D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FBED8"))) PPC_WEAK_FUNC(sub_820FBED8);
PPC_FUNC_IMPL(__imp__sub_820FBED8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-12
	ctx.r3.s64 = ctx.r3.s64 + -12;
	// b 0x820fd4d8
	sub_820FD4D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FBEE0"))) PPC_WEAK_FUNC(sub_820FBEE0);
PPC_FUNC_IMPL(__imp__sub_820FBEE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f1,20(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FBEFC"))) PPC_WEAK_FUNC(sub_820FBEFC);
PPC_FUNC_IMPL(__imp__sub_820FBEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FBF00"))) PPC_WEAK_FUNC(sub_820FBF00);
PPC_FUNC_IMPL(__imp__sub_820FBF00) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x820fbf18
	if (!ctx.cr6.eq) goto loc_820FBF18;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_820FBF18:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FBF24"))) PPC_WEAK_FUNC(sub_820FBF24);
PPC_FUNC_IMPL(__imp__sub_820FBF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FBF28"))) PPC_WEAK_FUNC(sub_820FBF28);
PPC_FUNC_IMPL(__imp__sub_820FBF28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,424(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 424);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FBF40"))) PPC_WEAK_FUNC(sub_820FBF40);
PPC_FUNC_IMPL(__imp__sub_820FBF40) {
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
	// lwz r11,376(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fc09c
	if (!ctx.cr6.eq) goto loc_820FC09C;
	// lwz r11,436(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 436);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fc09c
	if (!ctx.cr6.eq) goto loc_820FC09C;
	// lwz r11,372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x820fbf94
	if (ctx.cr6.eq) goto loc_820FBF94;
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fc09c
	if (!ctx.cr6.eq) goto loc_820FC09C;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820fc09c
	if (!ctx.cr6.eq) goto loc_820FC09C;
loc_820FBF94:
	// lwz r11,448(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 448);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820fc09c
	if (!ctx.cr6.eq) goto loc_820FC09C;
	// lwz r11,416(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 416);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fbfcc
	if (ctx.cr6.eq) goto loc_820FBFCC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fbd80
	ctx.lr = 0x820FBFB4;
	sub_820FBD80(ctx, base);
	// lwz r11,412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfc r8,r11,r3
	ctx.xer.ca = ctx.r3.u32 >= ctx.r11.u32;
	ctx.r8.s64 = ctx.r3.s64 - ctx.r11.s64;
	// adde r30,r9,r10
	temp.u8 = (ctx.r9.u32 + ctx.r10.u32 < ctx.r9.u32) | (ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x820fc064
	goto loc_820FC064;
loc_820FBFCC:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc010
	if (ctx.cr6.eq) goto loc_820FC010;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r9,r10,0,24,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r9,128
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 128, ctx.xer);
	// bne cr6,0x820fc010
	if (!ctx.cr6.eq) goto loc_820FC010;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x820fc010
	if (ctx.cr6.eq) goto loc_820FC010;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x820fc010
	if (ctx.cr6.eq) goto loc_820FC010;
	// bl 0x820f6f08
	ctx.lr = 0x820FC004;
	sub_820F6F08(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r3.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 & ctx.r30.u64;
loc_820FC010:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fc038
	if (ctx.cr6.eq) goto loc_820FC038;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r11,r10,0,24,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xE0;
	// addi r11,r11,-96
	ctx.r11.s64 = ctx.r11.s64 + -96;
	// subfic r9,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r11.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r7,r30
	ctx.r30.u64 = ctx.r7.u64 & ctx.r30.u64;
loc_820FC038:
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r11,r10,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820fc054
	if (ctx.cr6.eq) goto loc_820FC054;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820fc064
	if (!ctx.cr6.eq) goto loc_820FC064;
loc_820FC054:
	// lwz r11,424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 424);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r8,r30
	ctx.r30.u64 = ctx.r8.u64 & ctx.r30.u64;
loc_820FC064:
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fc084
	if (ctx.cr6.eq) goto loc_820FC084;
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r8,r30
	ctx.r30.u64 = ctx.r8.u64 & ctx.r30.u64;
loc_820FC084:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fc0a4
	if (ctx.cr6.eq) goto loc_820FC0A4;
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x820fc0a4
	if (ctx.cr6.eq) goto loc_820FC0A4;
loc_820FC09C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x820fc0a8
	goto loc_820FC0A8;
loc_820FC0A4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820FC0A8:
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

__attribute__((alias("__imp__sub_820FC0C0"))) PPC_WEAK_FUNC(sub_820FC0C0);
PPC_FUNC_IMPL(__imp__sub_820FC0C0) {
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
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820fc150
	if (!ctx.cr6.eq) goto loc_820FC150;
	// lwz r10,448(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// sth r9,440(r3)
	PPC_STORE_U16(ctx.r3.u32 + 440, ctx.r9.u16);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// bne cr6,0x820fc1bc
	if (!ctx.cr6.eq) goto loc_820FC1BC;
	// lwz r11,416(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fc1bc
	if (!ctx.cr6.eq) goto loc_820FC1BC;
	// lwz r11,444(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 444);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r11,r10,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x820fc128
	if (ctx.cr6.eq) goto loc_820FC128;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x820fc1bc
	if (!ctx.cr6.eq) goto loc_820FC1BC;
loc_820FC128:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fbd08
	ctx.lr = 0x820FC130;
	sub_820FBD08(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// stw r11,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
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
loc_820FC150:
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820fc180
	if (!ctx.cr6.eq) goto loc_820FC180;
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r11,442(r31)
	PPC_STORE_U16(ctx.r31.u32 + 442, ctx.r11.u16);
	// stw r10,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r10.u32);
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
loc_820FC180:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820fc1a8
	if (!ctx.cr6.eq) goto loc_820FC1A8;
	// li r11,0
	ctx.r11.s64 = 0;
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
loc_820FC1A8:
	// lwz r11,436(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x820fc1bc
	if (!ctx.cr6.eq) goto loc_820FC1BC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 436, ctx.r11.u32);
loc_820FC1BC:
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

__attribute__((alias("__imp__sub_820FC1D0"))) PPC_WEAK_FUNC(sub_820FC1D0);
PPC_FUNC_IMPL(__imp__sub_820FC1D0) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820f7098
	ctx.lr = 0x820FC1F0;
	sub_820F7098(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fbd08
	ctx.lr = 0x820FC1F8;
	sub_820FBD08(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// stw r11,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_820FC218"))) PPC_WEAK_FUNC(sub_820FC218);
PPC_FUNC_IMPL(__imp__sub_820FC218) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 424, ctx.r11.u32);
	// bl 0x820fbd08
	ctx.lr = 0x820FC238;
	sub_820FBD08(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// stw r10,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_820FC258"))) PPC_WEAK_FUNC(sub_820FC258);
PPC_FUNC_IMPL(__imp__sub_820FC258) {
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
	// lwz r11,444(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 444);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r11,r10,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x7;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x820fc40c
	if (ctx.cr6.gt) goto loc_820FC40C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820fc36c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FC36C;
	// bdzf 4*cr6+eq,0x820fc36c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FC36C;
	// bdzf 4*cr6+eq,0x820fc2f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FC2F0;
	// bne cr6,0x820fc2b4
	if (!ctx.cr6.eq) goto loc_820FC2B4;
loc_820FC29C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fbd80
	ctx.lr = 0x820FC2A4;
	sub_820FBD80(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// stw r11,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
	// b 0x820fc3f0
	goto loc_820FC3F0;
loc_820FC2B4:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FC2C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// ori r8,r9,65535
	ctx.r8.u64 = ctx.r9.u64 | 65535;
	// cmpw cr6,r3,r8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x820fc29c
	if (ctx.cr6.eq) goto loc_820FC29C;
	// lwz r11,396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// li r10,0
	ctx.r10.s64 = 0;
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r11.s64;
	// stw r10,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r10.u32);
	// stw r9,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r9.u32);
	// b 0x820fc3f0
	goto loc_820FC3F0;
loc_820FC2F0:
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// stw r30,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// bl 0x820f6f68
	ctx.lr = 0x820FC300;
	sub_820F6F68(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820fc350
	if (!ctx.cr6.eq) goto loc_820FC350;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x820f6fc8
	ctx.lr = 0x820FC310;
	sub_820F6FC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820fc350
	if (!ctx.cr6.eq) goto loc_820FC350;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FC32C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// ori r8,r9,65535
	ctx.r8.u64 = ctx.r9.u64 | 65535;
	// cmpw cr6,r3,r8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x820fc29c
	if (ctx.cr6.eq) goto loc_820FC29C;
	// lwz r11,396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// stw r30,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r11.s64;
	// stw r10,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r10.u32);
	// b 0x820fc3f0
	goto loc_820FC3F0;
loc_820FC350:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x820f6fe8
	ctx.lr = 0x820FC358;
	sub_820F6FE8(ctx, base);
	// stw r3,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x820f7098
	ctx.lr = 0x820FC368;
	sub_820F7098(ctx, base);
	// b 0x820fc3f0
	goto loc_820FC3F0;
loc_820FC36C:
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r30.u32);
	// bl 0x820fbd80
	ctx.lr = 0x820FC37C;
	sub_820FBD80(ctx, base);
	// stw r3,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r3.u32);
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r11,r10,0,24,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xE0;
	// addi r9,r11,-32
	ctx.r9.s64 = ctx.r11.s64 + -32;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x820f7ab0
	ctx.lr = 0x820FC3A8;
	sub_820F7AB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r3.u32);
	// beq cr6,0x820fc3f0
	if (ctx.cr6.eq) goto loc_820FC3F0;
	// stw r30,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r30.u32);
	// lwz r11,424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 424);
	// lhz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 56);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// beq cr6,0x820fc3d0
	if (ctx.cr6.eq) goto loc_820FC3D0;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
loc_820FC3D0:
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,396(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// stw r9,416(r31)
	PPC_STORE_U32(ctx.r31.u32 + 416, ctx.r9.u32);
	// subf r11,r8,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r6.u32);
loc_820FC3F0:
	// lwz r11,412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// divw r11,r9,r10
	ctx.r11.s32 = ppc_divw(ctx.r9.s32, ctx.r10.s32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r8,412(r31)
	PPC_STORE_U32(ctx.r31.u32 + 412, ctx.r8.u32);
loc_820FC40C:
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

__attribute__((alias("__imp__sub_820FC424"))) PPC_WEAK_FUNC(sub_820FC424);
PPC_FUNC_IMPL(__imp__sub_820FC424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FC428"))) PPC_WEAK_FUNC(sub_820FC428);
PPC_FUNC_IMPL(__imp__sub_820FC428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FC430;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FC44C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bne cr6,0x820fc474
	if (!ctx.cr6.eq) goto loc_820FC474;
	// lis r29,-30009
	ctx.r29.s64 = -1966669824;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// ori r29,r29,6
	ctx.r29.u64 = ctx.r29.u64 | 6;
	// bl 0x821d5394
	ctx.lr = 0x820FC468;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FC474:
	// lwz r11,376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x820fc540
	if (ctx.cr6.eq) goto loc_820FC540;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820eca30
	ctx.lr = 0x820FC490;
	sub_820ECA30(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fc540
	if (ctx.cr6.lt) goto loc_820FC540;
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc4b8
	if (ctx.cr6.eq) goto loc_820FC4B8;
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// subfe r4,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x820f6a28
	ctx.lr = 0x820FC4B4;
	sub_820F6A28(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_820FC4B8:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820fc540
	if (ctx.cr6.lt) goto loc_820FC540;
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc4dc
	if (ctx.cr6.eq) goto loc_820FC4DC;
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// subfe r4,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x820f6a28
	ctx.lr = 0x820FC4D8;
	sub_820F6A28(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_820FC4DC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820fc540
	if (ctx.cr6.lt) goto loc_820FC540;
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// subfe r11,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// stw r11,376(r31)
	PPC_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// bne cr6,0x820fc540
	if (!ctx.cr6.eq) goto loc_820FC540;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fc520
	if (ctx.cr6.eq) goto loc_820FC520;
	// bl 0x820e6990
	ctx.lr = 0x820FC508;
	sub_820E6990(ctx, base);
	// stw r3,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FC514;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FC520:
	// bl 0x820e6990
	ctx.lr = 0x820FC524;
	sub_820E6990(ctx, base);
	// lwz r11,400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 400);
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 404);
	// li r9,0
	ctx.r9.s64 = 0;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r9.u32);
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// stw r7,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r7.u32);
loc_820FC540:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FC548;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FC554"))) PPC_WEAK_FUNC(sub_820FC554);
PPC_FUNC_IMPL(__imp__sub_820FC554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FC558"))) PPC_WEAK_FUNC(sub_820FC558);
PPC_FUNC_IMPL(__imp__sub_820FC558) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FC560;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FC57C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820fc5a0
	if (!ctx.cr6.eq) goto loc_820FC5A0;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ori r30,r30,87
	ctx.r30.u64 = ctx.r30.u64 | 87;
	// bl 0x821d5394
	ctx.lr = 0x820FC594;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FC5A0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ea458
	ctx.lr = 0x820FC5AC;
	sub_820EA458(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fc5f4
	if (ctx.cr6.lt) goto loc_820FC5F4;
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc5cc
	if (ctx.cr6.eq) goto loc_820FC5CC;
	// addi r4,r31,320
	ctx.r4.s64 = ctx.r31.s64 + 320;
	// bl 0x820f6c78
	ctx.lr = 0x820FC5CC;
	sub_820F6C78(ctx, base);
loc_820FC5CC:
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc5e0
	if (ctx.cr6.eq) goto loc_820FC5E0;
	// addi r4,r31,320
	ctx.r4.s64 = ctx.r31.s64 + 320;
	// bl 0x820f6c78
	ctx.lr = 0x820FC5E0;
	sub_820F6C78(ctx, base);
loc_820FC5E0:
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc5f4
	if (ctx.cr6.eq) goto loc_820FC5F4;
	// addi r4,r31,320
	ctx.r4.s64 = ctx.r31.s64 + 320;
	// bl 0x820f6c78
	ctx.lr = 0x820FC5F4;
	sub_820F6C78(ctx, base);
loc_820FC5F4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FC5FC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FC608"))) PPC_WEAK_FUNC(sub_820FC608);
PPC_FUNC_IMPL(__imp__sub_820FC608) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FC610;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FC634;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ece08
	ctx.lr = 0x820FC648;
	sub_820ECE08(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fc6c4
	if (ctx.cr6.lt) goto loc_820FC6C4;
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc674
	if (ctx.cr6.eq) goto loc_820FC674;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// bl 0x820f6cb8
	ctx.lr = 0x820FC670;
	sub_820F6CB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FC674:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fc6c4
	if (ctx.cr6.lt) goto loc_820FC6C4;
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc69c
	if (ctx.cr6.eq) goto loc_820FC69C;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// bl 0x820f6cb8
	ctx.lr = 0x820FC698;
	sub_820F6CB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FC69C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fc6c4
	if (ctx.cr6.lt) goto loc_820FC6C4;
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc6c4
	if (ctx.cr6.eq) goto loc_820FC6C4;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// bl 0x820f6cb8
	ctx.lr = 0x820FC6C0;
	sub_820F6CB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FC6C4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FC6CC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FC6D8"))) PPC_WEAK_FUNC(sub_820FC6D8);
PPC_FUNC_IMPL(__imp__sub_820FC6D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FC6E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FC6F8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lhz r29,6(r9)
	ctx.r29.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// bne cr6,0x820fc72c
	if (!ctx.cr6.eq) goto loc_820FC72C;
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// ori r30,r30,10
	ctx.r30.u64 = ctx.r30.u64 | 10;
	// bl 0x821d5394
	ctx.lr = 0x820FC720;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FC72C:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FC750;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fc794
	if (ctx.cr6.lt) goto loc_820FC794;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r5,r31,384
	ctx.r5.s64 = ctx.r31.s64 + 384;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,30,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820fc788
	if (ctx.cr6.eq) goto loc_820FC788;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ed750
	ctx.lr = 0x820FC784;
	sub_820ED750(ctx, base);
	// b 0x820fc790
	goto loc_820FC790;
loc_820FC788:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// bl 0x820e6918
	ctx.lr = 0x820FC790;
	sub_820E6918(ctx, base);
loc_820FC790:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FC794:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FC79C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FC7A8"))) PPC_WEAK_FUNC(sub_820FC7A8);
PPC_FUNC_IMPL(__imp__sub_820FC7A8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r4,308(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 308);
	// b 0x82103598
	sub_82103598(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FC7BC"))) PPC_WEAK_FUNC(sub_820FC7BC);
PPC_FUNC_IMPL(__imp__sub_820FC7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FC7C0"))) PPC_WEAK_FUNC(sub_820FC7C0);
PPC_FUNC_IMPL(__imp__sub_820FC7C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FC7C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lhz r4,440(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 440);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// cmplwi cr6,r4,65535
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 65535, ctx.xer);
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x820fc80c
	if (ctx.cr6.eq) goto loc_820FC80C;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lwz r3,312(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82103258
	ctx.lr = 0x820FC80C;
	sub_82103258(ctx, base);
loc_820FC80C:
	// lhz r11,440(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 440);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stb r29,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r29.u8);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// sth r11,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r11.u16);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FC838"))) PPC_WEAK_FUNC(sub_820FC838);
PPC_FUNC_IMPL(__imp__sub_820FC838) {
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
	// bl 0x820ecf80
	ctx.lr = 0x820FC854;
	sub_820ECF80(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r11,204
	ctx.r30.s64 = ctx.r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FC864;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc874
	if (ctx.cr6.eq) goto loc_820FC874;
	// bl 0x820f6b88
	ctx.lr = 0x820FC874;
	sub_820F6B88(ctx, base);
loc_820FC874:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc884
	if (ctx.cr6.eq) goto loc_820FC884;
	// bl 0x820f6b88
	ctx.lr = 0x820FC884;
	sub_820F6B88(ctx, base);
loc_820FC884:
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc894
	if (ctx.cr6.eq) goto loc_820FC894;
	// bl 0x820f6b88
	ctx.lr = 0x820FC894;
	sub_820F6B88(ctx, base);
loc_820FC894:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FC89C;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_820FC8B4"))) PPC_WEAK_FUNC(sub_820FC8B4);
PPC_FUNC_IMPL(__imp__sub_820FC8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FC8B8"))) PPC_WEAK_FUNC(sub_820FC8B8);
PPC_FUNC_IMPL(__imp__sub_820FC8B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FC8C0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,448(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820fca34
	if (ctx.cr6.eq) goto loc_820FCA34;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820fc950
	if (ctx.cr6.eq) goto loc_820FC950;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820fcc80
	if (!ctx.cr6.eq) goto loc_820FCC80;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fc904
	if (ctx.cr6.eq) goto loc_820FC904;
	// lwz r11,88(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
loc_820FC904:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fc924
	if (ctx.cr6.eq) goto loc_820FC924;
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
loc_820FC924:
	// lhz r11,442(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 442);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r9,432(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r10,436(r31)
	PPC_STORE_U32(ctx.r31.u32 + 436, ctx.r10.u32);
	// stw r28,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r28.u32);
	// sth r8,442(r31)
	PPC_STORE_U16(ctx.r31.u32 + 442, ctx.r8.u16);
	// sth r11,440(r31)
	PPC_STORE_U16(ctx.r31.u32 + 440, ctx.r11.u16);
	// stw r28,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r28.u32);
	// stw r9,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r9.u32);
	// b 0x820fcc80
	goto loc_820FCC80;
loc_820FC950:
	// lwz r11,456(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 456);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fc9f4
	if (ctx.cr6.eq) goto loc_820FC9F4;
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fc990
	if (ctx.cr6.eq) goto loc_820FC990;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FC978;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,444(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lhz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 20);
	// subf r30,r8,r3
	ctx.r30.s64 = ctx.r3.s64 - ctx.r8.s64;
	// bl 0x820e6990
	ctx.lr = 0x820FC988;
	sub_820E6990(ctx, base);
	// cmpw cr6,r3,r30
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r30.s32, ctx.xer);
	// blt cr6,0x820fc9f4
	if (ctx.cr6.lt) goto loc_820FC9F4;
loc_820FC990:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fc9c4
	if (ctx.cr6.eq) goto loc_820FC9C4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r9,444(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lhz r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 24);
	// lhz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 20);
	// clrlwi r6,r7,30
	ctx.r6.u64 = ctx.r7.u32 & 0x3;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FC9C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FC9C4:
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r10,444(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lhz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 24);
	// lhz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 20);
	// clrlwi r6,r8,30
	ctx.r6.u64 = ctx.r8.u32 & 0x3;
	// lwz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820FC9F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820fca14
	goto loc_820FCA14;
loc_820FC9F4:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fca14
	if (ctx.cr6.eq) goto loc_820FCA14;
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
loc_820FCA14:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// bl 0x820ed268
	ctx.lr = 0x820FCA20;
	sub_820ED268(ctx, base);
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// bl 0x820f7f88
	ctx.lr = 0x820FCA28;
	sub_820F7F88(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
	// b 0x820fcc80
	goto loc_820FCC80;
loc_820FCA34:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fbf40
	ctx.lr = 0x820FCA3C;
	sub_820FBF40(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fcc80
	if (ctx.cr6.eq) goto loc_820FCC80;
	// lwz r9,444(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r27,3
	ctx.r27.s64 = 3;
	// lhz r11,24(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 24);
	// rlwinm r11,r11,30,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x7;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x820fcaf0
	if (ctx.cr6.gt) goto loc_820FCAF0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820fcae0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCAE0;
	// bdzf 4*cr6+eq,0x820fca94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCA94;
	// bdzf 4*cr6+eq,0x820fcaa4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCAA4;
	// bdzf 4*cr6+eq,0x820fcab8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCAB8;
	// bdzf 4*cr6+eq,0x820fcacc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCACC;
	// bdzf 4*cr6+eq,0x820fca88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCA88;
	// bne cr6,0x820fcae0
	if (!ctx.cr6.eq) goto loc_820FCAE0;
loc_820FCA88:
	// stw r28,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r28.u32);
	// stw r28,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r28.u32);
	// b 0x820fcaec
	goto loc_820FCAEC;
loc_820FCA94:
	// stw r10,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r10.u32);
	// stw r28,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r28.u32);
	// stw r28,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r28.u32);
	// b 0x820fcaf0
	goto loc_820FCAF0;
loc_820FCAA4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r10.u32);
	// stw r28,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r28.u32);
	// stw r11,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// b 0x820fcaf0
	goto loc_820FCAF0;
loc_820FCAB8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r10.u32);
	// stw r28,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r28.u32);
	// stw r11,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
	// b 0x820fcaf0
	goto loc_820FCAF0;
loc_820FCACC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r10.u32);
	// stw r11,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// stw r11,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
	// b 0x820fcaf0
	goto loc_820FCAF0;
loc_820FCAE0:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
	// stw r11,452(r31)
	PPC_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
loc_820FCAEC:
	// stw r27,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r27.u32);
loc_820FCAF0:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r30,60
	ctx.r30.s64 = 60;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fcb74
	if (ctx.cr6.eq) goto loc_820FCB74;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x820fcb18
	if (ctx.cr6.eq) goto loc_820FCB18;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bne cr6,0x820fcb74
	if (!ctx.cr6.eq) goto loc_820FCB74;
loc_820FCB18:
	// lwz r10,428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820fcb34
	if (!ctx.cr6.eq) goto loc_820FCB34;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// beq cr6,0x820fcb38
	if (ctx.cr6.eq) goto loc_820FCB38;
loc_820FCB34:
	// li r10,60
	ctx.r10.s64 = 60;
loc_820FCB38:
	// lwz r8,452(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 452);
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x820fcb54
	if (ctx.cr6.eq) goto loc_820FCB54;
	// lhz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 24);
	// lhz r30,22(r9)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r9.u32 + 22);
	// clrlwi r29,r10,30
	ctx.r29.u64 = ctx.r10.u32 & 0x3;
loc_820FCB54:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FCB74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FCB74:
	// lwz r10,428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fcbe8
	if (ctx.cr6.eq) goto loc_820FCBE8;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// bne cr6,0x820fcb94
	if (!ctx.cr6.eq) goto loc_820FCB94;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_820FCB94:
	// lwz r9,452(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 452);
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820fcbb4
	if (ctx.cr6.eq) goto loc_820FCBB4;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lhz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// lhz r30,22(r11)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r11.u32 + 22);
	// clrlwi r29,r9,30
	ctx.r29.u64 = ctx.r9.u32 & 0x3;
loc_820FCBB4:
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FCBD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,428(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// bl 0x820ed268
	ctx.lr = 0x820FCBE0;
	sub_820ED268(ctx, base);
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// bl 0x820f7f88
	ctx.lr = 0x820FCBE8;
	sub_820F7F88(ctx, base);
loc_820FCBE8:
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fcc70
	if (ctx.cr6.eq) goto loc_820FCC70;
	// lwz r11,448(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 448);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820fcc70
	if (!ctx.cr6.eq) goto loc_820FCC70;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fcc1c
	if (!ctx.cr6.eq) goto loc_820FCC1C;
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// beq cr6,0x820fcc20
	if (ctx.cr6.eq) goto loc_820FCC20;
loc_820FCC1C:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
loc_820FCC20:
	// lwz r9,456(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 456);
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820fcc40
	if (ctx.cr6.eq) goto loc_820FCC40;
	// lwz r11,444(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// lhz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// lhz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 20);
	// clrlwi r29,r9,30
	ctx.r29.u64 = ctx.r9.u32 & 0x3;
loc_820FCC40:
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FCC5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// bl 0x820ed268
	ctx.lr = 0x820FCC68;
	sub_820ED268(ctx, base);
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// bl 0x820f7f88
	ctx.lr = 0x820FCC70;
	sub_820F7F88(ctx, base);
loc_820FCC70:
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fcc80
	if (!ctx.cr6.eq) goto loc_820FCC80;
	// stw r27,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r27.u32);
loc_820FCC80:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ecba0
	ctx.lr = 0x820FCC88;
	sub_820ECBA0(ctx, base);
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fcc98
	if (ctx.cr6.eq) goto loc_820FCC98;
	// bl 0x820f8168
	ctx.lr = 0x820FCC98;
	sub_820F8168(ctx, base);
loc_820FCC98:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fcca8
	if (ctx.cr6.eq) goto loc_820FCCA8;
	// bl 0x820f8168
	ctx.lr = 0x820FCCA8;
	sub_820F8168(ctx, base);
loc_820FCCA8:
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fccb8
	if (ctx.cr6.eq) goto loc_820FCCB8;
	// bl 0x820f8168
	ctx.lr = 0x820FCCB8;
	sub_820F8168(ctx, base);
loc_820FCCB8:
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820fcd10
	if (!ctx.cr6.eq) goto loc_820FCD10;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fcd10
	if (!ctx.cr6.eq) goto loc_820FCD10;
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fcd10
	if (!ctx.cr6.eq) goto loc_820FCD10;
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fcd10
	if (!ctx.cr6.eq) goto loc_820FCD10;
	// lwz r11,436(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fcd10
	if (!ctx.cr6.eq) goto loc_820FCD10;
	// li r11,32
	ctx.r11.s64 = 32;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// lwz r9,128(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FCD10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FCD10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FCD18"))) PPC_WEAK_FUNC(sub_820FCD18);
PPC_FUNC_IMPL(__imp__sub_820FCD18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FCD20;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r27,r11,204
	ctx.r27.s64 = ctx.r11.s64 + 204;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FCD3C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
	// stw r11,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1);
	// lwz r30,308(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 308);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FCD68;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r6,52(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r5,44(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// lwz r4,5(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 5);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820FCD88;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FCDA0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fce64
	if (ctx.cr6.lt) goto loc_820FCE64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32795
	ctx.r4.u64 = ctx.r4.u64 | 32795;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x820e9408
	ctx.lr = 0x820FCDC4;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fcde0
	if (ctx.cr6.eq) goto loc_820FCDE0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,60(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x821035c0
	ctx.lr = 0x820FCDD8;
	sub_821035C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fcdfc
	if (!ctx.cr6.eq) goto loc_820FCDFC;
loc_820FCDE0:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// bl 0x821d5394
	ctx.lr = 0x820FCDF0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820FCDFC:
	// stw r3,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r3.u32);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32819
	ctx.r4.u64 = ctx.r4.u64 | 32819;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x820e9408
	ctx.lr = 0x820FCE18;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fcde0
	if (ctx.cr6.eq) goto loc_820FCDE0;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x821038d8
	ctx.lr = 0x820FCE30;
	sub_821038D8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fcde0
	if (ctx.cr6.eq) goto loc_820FCDE0;
	// stw r3,420(r31)
	PPC_STORE_U32(ctx.r31.u32 + 420, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fc6d8
	ctx.lr = 0x820FCE44;
	sub_820FC6D8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fce64
	if (ctx.cr6.lt) goto loc_820FCE64;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ec880
	ctx.lr = 0x820FCE64;
	sub_820EC880(ctx, base);
loc_820FCE64:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FCE6C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FCE78"))) PPC_WEAK_FUNC(sub_820FCE78);
PPC_FUNC_IMPL(__imp__sub_820FCE78) {
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
	// lwz r11,444(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 444);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 24);
	// rlwinm r8,r10,24,29,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x7;
	// cmplwi cr6,r8,5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 5, ctx.xer);
	// bgt cr6,0x820fcfcc
	if (ctx.cr6.gt) goto loc_820FCFCC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820fcee4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCEE4;
	// bdzf 4*cr6+eq,0x820fcf48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCF48;
	// bdzf 4*cr6+eq,0x820fcf48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCF48;
	// bdzf 4*cr6+eq,0x820fcfa4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FCFA4;
	// bne cr6,0x820fcfa4
	if (!ctx.cr6.eq) goto loc_820FCFA4;
	// lwz r6,408(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 408);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cntlzw r11,r6
	ctx.r11.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r7,r11,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// bl 0x820edac8
	ctx.lr = 0x820FCEDC;
	sub_820EDAC8(ctx, base);
	// stw r30,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
	// b 0x820fcfcc
	goto loc_820FCFCC;
loc_820FCEE4:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fcf30
	if (ctx.cr6.eq) goto loc_820FCF30;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x820fcf08
	if (ctx.cr6.eq) goto loc_820FCF08;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bne cr6,0x820fcf30
	if (!ctx.cr6.eq) goto loc_820FCF30;
loc_820FCF08:
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// lwz r7,412(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 412);
	// lwz r6,108(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r8,112(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// lwz r10,396(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r3,100(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// subf r11,r3,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r3.s64;
	// subf r11,r6,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r6.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r6,r11,r8
	ctx.r6.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_820FCF30:
	// lwz r11,408(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 408);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x820edac8
	ctx.lr = 0x820FCF44;
	sub_820EDAC8(ctx, base);
	// b 0x820fcfcc
	goto loc_820FCFCC;
loc_820FCF48:
	// lwz r9,424(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 424);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fcf90
	if (ctx.cr6.eq) goto loc_820FCF90;
	// rlwinm r11,r10,0,21,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x700;
	// addi r11,r11,-768
	ctx.r11.s64 = ctx.r11.s64 + -768;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fcf74
	if (!ctx.cr6.eq) goto loc_820FCF74;
	// lhz r11,48(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 48);
loc_820FCF74:
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// clrlwi r6,r11,16
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// lwz r7,7(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 7);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// b 0x820fcfc4
	goto loc_820FCFC4;
loc_820FCF90:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820edac8
	ctx.lr = 0x820FCFA0;
	sub_820EDAC8(ctx, base);
	// b 0x820fcfcc
	goto loc_820FCFCC;
loc_820FCFA4:
	// rlwinm r10,r10,0,21,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x700;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// addi r11,r10,-1024
	ctx.r11.s64 = ctx.r10.s64 + -1024;
	// li r6,0
	ctx.r6.s64 = 0;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_820FCFC4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820edbe8
	ctx.lr = 0x820FCFCC;
	sub_820EDBE8(ctx, base);
loc_820FCFCC:
	// stw r30,408(r31)
	PPC_STORE_U32(ctx.r31.u32 + 408, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_820FCFE8"))) PPC_WEAK_FUNC(sub_820FCFE8);
PPC_FUNC_IMPL(__imp__sub_820FCFE8) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r10,384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// addi r4,r11,22160
	ctx.r4.s64 = ctx.r11.s64 + 22160;
	// addi r3,r9,18224
	ctx.r3.s64 = ctx.r9.s64 + 18224;
	// addi r11,r8,18048
	ctx.r11.s64 = ctx.r8.s64 + 18048;
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r9,r7,22156
	ctx.r9.s64 = ctx.r7.s64 + 22156;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// addi r8,r6,22140
	ctx.r8.s64 = ctx.r6.s64 + 22140;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r7,r5,22136
	ctx.r7.s64 = ctx.r5.s64 + 22136;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// addi r11,r31,368
	ctx.r11.s64 = ctx.r31.s64 + 368;
	// stw r7,368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 368, ctx.r7.u32);
	// lwz r4,228(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 228);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820fd07c
	if (ctx.cr6.eq) goto loc_820FD07C;
loc_820FD058:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820fd074
	if (ctx.cr6.eq) goto loc_820FD074;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820fd058
	if (!ctx.cr6.eq) goto loc_820FD058;
	// b 0x820fd07c
	goto loc_820FD07C;
loc_820FD074:
	// addi r3,r10,24
	ctx.r3.s64 = ctx.r10.s64 + 24;
	// bl 0x820e9d30
	ctx.lr = 0x820FD07C;
	sub_820E9D30(ctx, base);
loc_820FD07C:
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd09c
	if (ctx.cr6.eq) goto loc_820FD09C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FD09C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD09C:
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd0c0
	if (ctx.cr6.eq) goto loc_820FD0C0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FD0C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD0C0:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd0e4
	if (ctx.cr6.eq) goto loc_820FD0E4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FD0E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD0E4:
	// lwz r11,436(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd108
	if (ctx.cr6.eq) goto loc_820FD108;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FD108;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD108:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r6,r11,18240
	ctx.r6.s64 = ctx.r11.s64 + 18240;
	// addi r3,r8,18232
	ctx.r3.s64 = ctx.r8.s64 + 18232;
	// addi r5,r10,18224
	ctx.r5.s64 = ctx.r10.s64 + 18224;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// addi r4,r9,18048
	ctx.r4.s64 = ctx.r9.s64 + 18048;
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// addi r11,r7,18208
	ctx.r11.s64 = ctx.r7.s64 + 18208;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// stw r4,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bl 0x820edfe0
	ctx.lr = 0x820FD14C;
	sub_820EDFE0(ctx, base);
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

__attribute__((alias("__imp__sub_820FD160"))) PPC_WEAK_FUNC(sub_820FD160);
PPC_FUNC_IMPL(__imp__sub_820FD160) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820FD168;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r27,r11,204
	ctx.r27.s64 = ctx.r11.s64 + 204;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FD18C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r26,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r26.u32);
	// lhz r4,440(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 440);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// cmplwi cr6,r4,65535
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 65535, ctx.xer);
	// lwz r29,312(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 312);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// beq cr6,0x820fd1c4
	if (ctx.cr6.eq) goto loc_820FD1C4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82102fb8
	ctx.lr = 0x820FD1C4;
	sub_82102FB8(ctx, base);
loc_820FD1C4:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820fd20c
	if (!ctx.cr6.eq) goto loc_820FD20C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fd1e8
	if (!ctx.cr6.eq) goto loc_820FD1E8;
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x820fd220
	if (ctx.cr6.eq) goto loc_820FD220;
loc_820FD1E8:
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82102e80
	ctx.lr = 0x820FD1FC;
	sub_82102E80(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fd2e4
	if (ctx.cr6.lt) goto loc_820FD2E4;
	// b 0x820fd220
	goto loc_820FD220;
loc_820FD20C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fd2e4
	if (!ctx.cr6.eq) goto loc_820FD2E4;
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820fd2e4
	if (!ctx.cr6.eq) goto loc_820FD2E4;
loc_820FD220:
	// lhz r4,440(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 440);
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// cmplw cr6,r4,r5
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x820fd2e4
	if (ctx.cr6.eq) goto loc_820FD2E4;
	// addi r29,r31,444
	ctx.r29.s64 = ctx.r31.s64 + 444;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 420);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// bl 0x821039c0
	ctx.lr = 0x820FD248;
	sub_821039C0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fd25c
	if (ctx.cr6.lt) goto loc_820FD25C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fc258
	ctx.lr = 0x820FD25C;
	sub_820FC258(ctx, base);
loc_820FD25C:
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r26.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fd2e4
	if (ctx.cr6.lt) goto loc_820FD2E4;
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,65535
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65535, ctx.xer);
	// beq cr6,0x820fd288
	if (ctx.cr6.eq) goto loc_820FD288;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fce78
	ctx.lr = 0x820FD284;
	sub_820FCE78(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FD288:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fd2e4
	if (ctx.cr6.lt) goto loc_820FD2E4;
	// lhz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// sth r11,442(r31)
	PPC_STORE_U16(ctx.r31.u32 + 442, ctx.r11.u16);
	// stw r10,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r10.u32);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x820fd2cc
	if (ctx.cr6.eq) goto loc_820FD2CC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820edac8
	ctx.lr = 0x820FD2C8;
	sub_820EDAC8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FD2CC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fd2e4
	if (ctx.cr6.lt) goto loc_820FD2E4;
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
loc_820FD2E4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FD2EC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FD2FC"))) PPC_WEAK_FUNC(sub_820FD2FC);
PPC_FUNC_IMPL(__imp__sub_820FD2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FD300"))) PPC_WEAK_FUNC(sub_820FD300);
PPC_FUNC_IMPL(__imp__sub_820FD300) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FD308;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r27,r11,204
	ctx.r27.s64 = ctx.r11.s64 + 204;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FD324;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// beq cr6,0x820fd468
	if (ctx.cr6.eq) goto loc_820FD468;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820fd358
	if (!ctx.cr6.eq) goto loc_820FD358;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820fd468
	if (ctx.cr6.eq) goto loc_820FD468;
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd468
	if (ctx.cr6.eq) goto loc_820FD468;
loc_820FD358:
	// lwz r11,376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fd368
	if (ctx.cr6.eq) goto loc_820FD368;
	// li r30,1
	ctx.r30.s64 = 1;
loc_820FD368:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ec778
	ctx.lr = 0x820FD374;
	sub_820EC778(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r30,r10,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820fd3f0
	if (ctx.cr6.eq) goto loc_820FD3F0;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd3ac
	if (ctx.cr6.eq) goto loc_820FD3AC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820f80b0
	ctx.lr = 0x820FD3A0;
	sub_820F80B0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fd468
	if (ctx.cr6.lt) goto loc_820FD468;
loc_820FD3AC:
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd3c4
	if (ctx.cr6.eq) goto loc_820FD3C4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820f80b0
	ctx.lr = 0x820FD3C0;
	sub_820F80B0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_820FD3C4:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x820fd468
	if (ctx.cr6.lt) goto loc_820FD468;
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd3e4
	if (ctx.cr6.eq) goto loc_820FD3E4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820f80b0
	ctx.lr = 0x820FD3E0;
	sub_820F80B0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_820FD3E4:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x820fd468
	if (ctx.cr6.lt) goto loc_820FD468;
	// stw r29,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r29.u32);
loc_820FD3F0:
	// lwz r11,424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 424);
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r10,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd40c
	if (ctx.cr6.eq) goto loc_820FD40C;
	// stw r29,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r29.u32);
	// stw r29,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r29.u32);
loc_820FD40C:
	// lwz r10,384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 384);
	// addi r11,r31,368
	ctx.r11.s64 = ctx.r31.s64 + 368;
	// stw r29,376(r31)
	PPC_STORE_U32(ctx.r31.u32 + 376, ctx.r29.u32);
	// stw r29,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r29.u32);
	// stw r29,400(r31)
	PPC_STORE_U32(ctx.r31.u32 + 400, ctx.r29.u32);
	// stw r29,404(r31)
	PPC_STORE_U32(ctx.r31.u32 + 404, ctx.r29.u32);
	// stw r29,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r29.u32);
	// lwz r4,228(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 228);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820fd468
	if (ctx.cr6.eq) goto loc_820FD468;
loc_820FD434:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820fd460
	if (ctx.cr6.eq) goto loc_820FD460;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820fd434
	if (!ctx.cr6.eq) goto loc_820FD434;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FD454;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820FD460:
	// addi r3,r10,24
	ctx.r3.s64 = ctx.r10.s64 + 24;
	// bl 0x820e9d30
	ctx.lr = 0x820FD468;
	sub_820E9D30(ctx, base);
loc_820FD468:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FD470;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FD47C"))) PPC_WEAK_FUNC(sub_820FD47C);
PPC_FUNC_IMPL(__imp__sub_820FD47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FD480"))) PPC_WEAK_FUNC(sub_820FD480);
PPC_FUNC_IMPL(__imp__sub_820FD480) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r4,r3,368
	ctx.r4.s64 = ctx.r3.s64 + 368;
	// bne cr6,0x820fd4a4
	if (!ctx.cr6.eq) goto loc_820FD4A4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_820FD4A4:
	// lwz r11,384(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 384);
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x820f58b8
	ctx.lr = 0x820FD4B0;
	sub_820F58B8(ctx, base);
	// lwz r10,384(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 384);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 388, temp.u32);
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

__attribute__((alias("__imp__sub_820FD4D8"))) PPC_WEAK_FUNC(sub_820FD4D8);
PPC_FUNC_IMPL(__imp__sub_820FD4D8) {
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
	// bl 0x820fcfe8
	ctx.lr = 0x820FD4F8;
	sub_820FCFE8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd518
	if (ctx.cr6.eq) goto loc_820FD518;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x820e9410
	ctx.lr = 0x820FD514;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FD518:
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

__attribute__((alias("__imp__sub_820FD530"))) PPC_WEAK_FUNC(sub_820FD530);
PPC_FUNC_IMPL(__imp__sub_820FD530) {
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
	// lwz r11,372(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x820fd580
	if (ctx.cr6.eq) goto loc_820FD580;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// beq cr6,0x820fd580
	if (ctx.cr6.eq) goto loc_820FD580;
	// lwz r10,376(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fd580
	if (!ctx.cr6.eq) goto loc_820FD580;
	// lwz r10,392(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fd580
	if (ctx.cr6.eq) goto loc_820FD580;
	// lwz r10,448(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fd5a0
	if (ctx.cr6.eq) goto loc_820FD5A0;
loc_820FD580:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fd6b0
	if (!ctx.cr6.eq) goto loc_820FD6B0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x820fd6b0
	if (!ctx.cr6.eq) goto loc_820FD6B0;
	// lwz r11,380(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 380);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820fd6b0
	if (!ctx.cr6.eq) goto loc_820FD6B0;
loc_820FD5A0:
	// lwz r11,424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 424);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd5b8
	if (ctx.cr6.eq) goto loc_820FD5B8;
	// stw r30,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r30.u32);
	// stw r30,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r30.u32);
loc_820FD5B8:
	// lwz r11,428(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd608
	if (ctx.cr6.eq) goto loc_820FD608;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x820fd5d8
	if (ctx.cr6.eq) goto loc_820FD5D8;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bne cr6,0x820fd5f0
	if (!ctx.cr6.eq) goto loc_820FD5F0;
loc_820FD5D8:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fd608
	if (!ctx.cr6.eq) goto loc_820FD608;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x820fd608
	if (!ctx.cr6.eq) goto loc_820FD608;
loc_820FD5F0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FD608;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD608:
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd658
	if (ctx.cr6.eq) goto loc_820FD658;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x820fd628
	if (ctx.cr6.eq) goto loc_820FD628;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bne cr6,0x820fd640
	if (!ctx.cr6.eq) goto loc_820FD640;
loc_820FD628:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fd658
	if (!ctx.cr6.eq) goto loc_820FD658;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x820fd658
	if (!ctx.cr6.eq) goto loc_820FD658;
loc_820FD640:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FD658;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD658:
	// stw r30,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f1.f64 = double(temp.f32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// bl 0x820fd160
	ctx.lr = 0x820FD670;
	sub_820FD160(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fd68c
	if (ctx.cr6.lt) goto loc_820FD68C;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fd68c
	if (ctx.cr6.eq) goto loc_820FD68C;
	// stw r11,448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
loc_820FD68C:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x820fd6a4
	if (!ctx.cr6.eq) goto loc_820FD6A4;
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// beq cr6,0x820fd6a8
	if (ctx.cr6.eq) goto loc_820FD6A8;
loc_820FD6A4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820FD6A8:
	// stw r11,380(r31)
	PPC_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// stw r30,392(r31)
	PPC_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
loc_820FD6B0:
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd6c0
	if (ctx.cr6.eq) goto loc_820FD6C0;
	// bl 0x820f7430
	ctx.lr = 0x820FD6C0;
	sub_820F7430(ctx, base);
loc_820FD6C0:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd6d0
	if (ctx.cr6.eq) goto loc_820FD6D0;
	// bl 0x820f7430
	ctx.lr = 0x820FD6D0;
	sub_820F7430(ctx, base);
loc_820FD6D0:
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd6e0
	if (ctx.cr6.eq) goto loc_820FD6E0;
	// bl 0x820f7430
	ctx.lr = 0x820FD6E0;
	sub_820F7430(ctx, base);
loc_820FD6E0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ecc18
	ctx.lr = 0x820FD6E8;
	sub_820ECC18(ctx, base);
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

__attribute__((alias("__imp__sub_820FD700"))) PPC_WEAK_FUNC(sub_820FD700);
PPC_FUNC_IMPL(__imp__sub_820FD700) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FD708;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x820FD720;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x820fd73c
	if (!ctx.cr6.eq) goto loc_820FD73C;
	// lwz r11,376(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fd744
	if (ctx.cr6.eq) goto loc_820FD744;
loc_820FD73C:
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// ori r30,r30,6
	ctx.r30.u64 = ctx.r30.u64 | 6;
loc_820FD744:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fd79c
	if (ctx.cr6.lt) goto loc_820FD79C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FD760;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820fd7b0
	if (ctx.cr6.eq) goto loc_820FD7B0;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820fd79c
	if (ctx.cr6.eq) goto loc_820FD79C;
	// bl 0x820e6990
	ctx.lr = 0x820FD774;
	sub_820E6990(ctx, base);
	// stw r3,396(r31)
	PPC_STORE_U32(ctx.r31.u32 + 396, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fd480
	ctx.lr = 0x820FD780;
	sub_820FD480(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// lwz r9,132(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FD79C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FD79C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5394
	ctx.lr = 0x820FD7A4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FD7B0:
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ori r30,r30,8
	ctx.r30.u64 = ctx.r30.u64 | 8;
	// bl 0x821d5394
	ctx.lr = 0x820FD7C0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FD7CC"))) PPC_WEAK_FUNC(sub_820FD7CC);
PPC_FUNC_IMPL(__imp__sub_820FD7CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FD7D0"))) PPC_WEAK_FUNC(sub_820FD7D0);
PPC_FUNC_IMPL(__imp__sub_820FD7D0) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,22312
	ctx.r9.s64 = ctx.r11.s64 + 22312;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x820fd80c
	if (ctx.cr6.eq) goto loc_820FD80C;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32815
	ctx.r4.u64 = ctx.r4.u64 | 32815;
	// bl 0x820e9410
	ctx.lr = 0x820FD808;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FD80C:
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

__attribute__((alias("__imp__sub_820FD820"))) PPC_WEAK_FUNC(sub_820FD820);
PPC_FUNC_IMPL(__imp__sub_820FD820) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FD828;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r31,r3,16
	ctx.r31.s64 = ctx.r3.s64 + 16;
	// li r30,-1
	ctx.r30.s64 = -1;
loc_820FD838:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82089cf8
	ctx.lr = 0x820FD84C;
	sub_82089CF8(ctx, base);
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// beq cr6,0x820fd85c
	if (ctx.cr6.eq) goto loc_820FD85C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fd868
	if (!ctx.cr6.eq) goto loc_820FD868;
loc_820FD85C:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x820e7708
	ctx.lr = 0x820FD864;
	sub_820E7708(ctx, base);
	// b 0x820fd838
	goto loc_820FD838;
loc_820FD868:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FD870"))) PPC_WEAK_FUNC(sub_820FD870);
PPC_FUNC_IMPL(__imp__sub_820FD870) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FD878;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r3,12
	ctx.r31.s64 = ctx.r3.s64 + 12;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fd918
	if (ctx.cr6.eq) goto loc_820FD918;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x820fd918
	if (ctx.cr6.eq) goto loc_820FD918;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x82088440
	ctx.lr = 0x820FD8A0;
	sub_82088440(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82088438
	ctx.lr = 0x820FD8AC;
	sub_82088438(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
loc_820FD8B4:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r31
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r31.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r29,0,r31
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r31.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r29.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820fd8b4
	if (!ctx.cr0.eq) goto loc_820FD8B4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd8e0
	if (ctx.cr6.eq) goto loc_820FD8E0;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fd8e0
	if (ctx.cr6.eq) goto loc_820FD8E0;
	// bl 0x82088d00
	ctx.lr = 0x820FD8E0;
	sub_82088D00(ctx, base);
loc_820FD8E0:
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd8fc
	if (ctx.cr6.eq) goto loc_820FD8FC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fd8fc
	if (ctx.cr6.eq) goto loc_820FD8FC;
	// bl 0x82088d00
	ctx.lr = 0x820FD8F8;
	sub_82088D00(ctx, base);
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
loc_820FD8FC:
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd918
	if (ctx.cr6.eq) goto loc_820FD918;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fd918
	if (ctx.cr6.eq) goto loc_820FD918;
	// bl 0x82088d00
	ctx.lr = 0x820FD914;
	sub_82088D00(ctx, base);
	// stw r29,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
loc_820FD918:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FD920"))) PPC_WEAK_FUNC(sub_820FD920);
PPC_FUNC_IMPL(__imp__sub_820FD920) {
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
	// bl 0x820fd820
	ctx.lr = 0x820FD930;
	sub_820FD820(ctx, base);
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

__attribute__((alias("__imp__sub_820FD944"))) PPC_WEAK_FUNC(sub_820FD944);
PPC_FUNC_IMPL(__imp__sub_820FD944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FD948"))) PPC_WEAK_FUNC(sub_820FD948);
PPC_FUNC_IMPL(__imp__sub_820FD948) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FD950;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x820FD96C;
	sub_82088928(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// beq cr6,0x820fd9e8
	if (ctx.cr6.eq) goto loc_820FD9E8;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fd9e8
	if (ctx.cr6.eq) goto loc_820FD9E8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x820FD994;
	sub_82088928(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd9e8
	if (ctx.cr6.eq) goto loc_820FD9E8;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fd9e8
	if (ctx.cr6.eq) goto loc_820FD9E8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r11,-9952
	ctx.r5.s64 = ctx.r11.s64 + -9952;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088d88
	ctx.lr = 0x820FD9C8;
	sub_82088D88(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fd9e8
	if (ctx.cr6.eq) goto loc_820FD9E8;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fd9e8
	if (ctx.cr6.eq) goto loc_820FD9E8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FD9E8:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// li r30,0
	ctx.r30.s64 = 0;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fda10
	if (ctx.cr6.eq) goto loc_820FDA10;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fda10
	if (ctx.cr6.eq) goto loc_820FDA10;
	// bl 0x82088d00
	ctx.lr = 0x820FDA0C;
	sub_82088D00(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_820FDA10:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fda2c
	if (ctx.cr6.eq) goto loc_820FDA2C;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fda2c
	if (ctx.cr6.eq) goto loc_820FDA2C;
	// bl 0x82088d00
	ctx.lr = 0x820FDA28;
	sub_82088D00(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_820FDA2C:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fda48
	if (ctx.cr6.eq) goto loc_820FDA48;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x820fda48
	if (ctx.cr6.eq) goto loc_820FDA48;
	// bl 0x82088d00
	ctx.lr = 0x820FDA44;
	sub_82088D00(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
loc_820FDA48:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FDA54"))) PPC_WEAK_FUNC(sub_820FDA54);
PPC_FUNC_IMPL(__imp__sub_820FDA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FDA58"))) PPC_WEAK_FUNC(sub_820FDA58);
PPC_FUNC_IMPL(__imp__sub_820FDA58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FDA60;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32815
	ctx.r4.u64 = ctx.r4.u64 | 32815;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x820e9408
	ctx.lr = 0x820FDA84;
	sub_820E9408(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fdac4
	if (ctx.cr6.eq) goto loc_820FDAC4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,22312
	ctx.r9.s64 = ctx.r11.s64 + 22312;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bl 0x820fd948
	ctx.lr = 0x820FDAAC;
	sub_820FD948(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fdad4
	if (ctx.cr6.lt) goto loc_820FDAD4;
	// stw r31,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FDAC4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FDAD4:
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
	ctx.lr = 0x820FDAEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FDAF8"))) PPC_WEAK_FUNC(sub_820FDAF8);
PPC_FUNC_IMPL(__imp__sub_820FDAF8) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
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
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r9,14420
	ctx.r11.s64 = ctx.r9.s64 + 14420;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,-4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FDB28"))) PPC_WEAK_FUNC(sub_820FDB28);
PPC_FUNC_IMPL(__imp__sub_820FDB28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x820FDB30;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820fdb74
	if (!ctx.cr6.eq) goto loc_820FDB74;
	// clrlwi r11,r5,16
	ctx.r11.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820fdb60
	if (!ctx.cr6.eq) goto loc_820FDB60;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x820fdb74
	goto loc_820FDB74;
loc_820FDB60:
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// li r10,32
	ctx.r10.s64 = 32;
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r3,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r3,r10
	ctx.r11.u64 = ctx.r3.u64 & ctx.r10.u64;
loc_820FDB74:
	// addis r10,r4,1
	ctx.r10.s64 = ctx.r4.s64 + 65536;
	// sth r6,2(r31)
	PPC_STORE_U16(ctx.r31.u32 + 2, ctx.r6.u16);
	// clrlwi r28,r11,16
	ctx.r28.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// addi r10,r10,-18
	ctx.r10.s64 = ctx.r10.s64 + -18;
	// clrlwi r27,r5,16
	ctx.r27.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r28,14(r31)
	PPC_STORE_U16(ctx.r31.u32 + 14, ctx.r28.u16);
	// li r29,0
	ctx.r29.s64 = 0;
	// sth r10,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r10.u16);
	// cmplwi cr6,r27,2
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 2, ctx.xer);
	// clrlwi r30,r6,16
	ctx.r30.u64 = ctx.r6.u32 & 0xFFFF;
	// beq cr6,0x820fdbc8
	if (ctx.cr6.eq) goto loc_820FDBC8;
	// clrlwi r11,r28,16
	ctx.r11.u64 = ctx.r28.u32 & 0xFFFF;
	// mullw r10,r11,r30
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// srawi r9,r10,3
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 3;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// clrlwi r6,r8,16
	ctx.r6.u64 = ctx.r8.u32 & 0xFFFF;
	// mullw r3,r6,r7
	ctx.r3.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// sth r6,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r6.u16);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// b 0x820fdc70
	goto loc_820FDC70;
loc_820FDBC8:
	// lhz r11,262(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 262);
	// li r9,7
	ctx.r9.s64 = 7;
	// rlwinm r10,r6,3,13,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0x7FFF8;
	// addi r3,r11,-2
	ctx.r3.s64 = ctx.r11.s64 + -2;
	// sth r9,20(r31)
	PPC_STORE_U16(ctx.r31.u32 + 20, ctx.r9.u16);
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r30.s64;
	// mullw r9,r3,r30
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// sth r11,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r11.u16);
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// twllei r11,0
	// srawi r9,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 3;
	// li r8,256
	ctx.r8.s64 = 256;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// li r6,512
	ctx.r6.s64 = 512;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// li r24,-256
	ctx.r24.s64 = -256;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// li r23,192
	ctx.r23.s64 = 192;
	// mullw r7,r10,r7
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// sth r10,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r10.u16);
	// divwu r11,r7,r11
	ctx.r11.u32 = ppc_divwu(ctx.r7.u32, ctx.r11.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// li r22,240
	ctx.r22.s64 = 240;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// li r9,460
	ctx.r9.s64 = 460;
	// sth r8,22(r31)
	PPC_STORE_U16(ctx.r31.u32 + 22, ctx.r8.u16);
	// li r21,-208
	ctx.r21.s64 = -208;
	// sth r29,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r29.u16);
	// li r10,392
	ctx.r10.s64 = 392;
	// sth r6,26(r31)
	PPC_STORE_U16(ctx.r31.u32 + 26, ctx.r6.u16);
	// li r7,-232
	ctx.r7.s64 = -232;
	// sth r24,28(r31)
	PPC_STORE_U16(ctx.r31.u32 + 28, ctx.r24.u16);
	// sth r29,30(r31)
	PPC_STORE_U16(ctx.r31.u32 + 30, ctx.r29.u16);
	// sth r29,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r29.u16);
	// sth r23,34(r31)
	PPC_STORE_U16(ctx.r31.u32 + 34, ctx.r23.u16);
	// sth r3,36(r31)
	PPC_STORE_U16(ctx.r31.u32 + 36, ctx.r3.u16);
	// sth r22,38(r31)
	PPC_STORE_U16(ctx.r31.u32 + 38, ctx.r22.u16);
	// sth r29,40(r31)
	PPC_STORE_U16(ctx.r31.u32 + 40, ctx.r29.u16);
	// sth r9,42(r31)
	PPC_STORE_U16(ctx.r31.u32 + 42, ctx.r9.u16);
	// sth r21,44(r31)
	PPC_STORE_U16(ctx.r31.u32 + 44, ctx.r21.u16);
	// sth r10,46(r31)
	PPC_STORE_U16(ctx.r31.u32 + 46, ctx.r10.u16);
	// sth r7,48(r31)
	PPC_STORE_U16(ctx.r31.u32 + 48, ctx.r7.u16);
loc_820FDC70:
	// cmplwi cr6,r4,40
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 40, ctx.xer);
	// beq cr6,0x820fdc84
	if (ctx.cr6.eq) goto loc_820FDC84;
	// sth r5,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r5.u16);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_820FDC84:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,-2
	ctx.r10.s64 = -2;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// addi r4,r11,22348
	ctx.r4.s64 = ctx.r11.s64 + 22348;
	// sth r10,0(r31)
	PPC_STORE_U16(ctx.r31.u32 + 0, ctx.r10.u16);
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x820FDCA0;
	sub_8207DAC0(ctx, base);
	// clrlwi r9,r26,16
	ctx.r9.u64 = ctx.r26.u32 & 0xFFFF;
	// stw r27,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fdcb4
	if (ctx.cr6.eq) goto loc_820FDCB4;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
loc_820FDCB4:
	// sth r28,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r28.u16);
	// cmpwi cr6,r25,-1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, -1, ctx.xer);
	// bne cr6,0x820fdcf0
	if (!ctx.cr6.eq) goto loc_820FDCF0;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// blt cr6,0x820fdce4
	if (ctx.cr6.lt) goto loc_820FDCE4;
	// cmplwi cr6,r30,8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 8, ctx.xer);
	// bgt cr6,0x820fdce4
	if (ctx.cr6.gt) goto loc_820FDCE4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,14420
	ctx.r11.s64 = ctx.r11.s64 + 14420;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r29,-4(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
loc_820FDCE4:
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_820FDCF0:
	// stw r25,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r25.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FDCFC"))) PPC_WEAK_FUNC(sub_820FDCFC);
PPC_FUNC_IMPL(__imp__sub_820FDCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FDD00"))) PPC_WEAK_FUNC(sub_820FDD00);
PPC_FUNC_IMPL(__imp__sub_820FDD00) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// addic r10,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// subfe r5,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FDD38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fdd48
	if (ctx.cr6.lt) goto loc_820FDD48;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_820FDD48:
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

__attribute__((alias("__imp__sub_820FDD5C"))) PPC_WEAK_FUNC(sub_820FDD5C);
PPC_FUNC_IMPL(__imp__sub_820FDD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FDD60"))) PPC_WEAK_FUNC(sub_820FDD60);
PPC_FUNC_IMPL(__imp__sub_820FDD60) {
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
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820fddbc
	if (ctx.cr6.eq) goto loc_820FDDBC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addic r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// li r9,32
	ctx.r9.s64 = 32;
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r5,0
	ctx.r5.s64 = 0;
	// and r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 & ctx.r9.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820FDDAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fddbc
	if (ctx.cr6.lt) goto loc_820FDDBC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_820FDDBC:
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

__attribute__((alias("__imp__sub_820FDDD0"))) PPC_WEAK_FUNC(sub_820FDDD0);
PPC_FUNC_IMPL(__imp__sub_820FDDD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FDDE0"))) PPC_WEAK_FUNC(sub_820FDDE0);
PPC_FUNC_IMPL(__imp__sub_820FDDE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820FDDE8;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820fde10
	if (ctx.cr6.eq) goto loc_820FDE10;
	// cmplwi cr6,r4,8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 8, ctx.xer);
	// ble cr6,0x820fde20
	if (!ctx.cr6.gt) goto loc_820FDE20;
loc_820FDE10:
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820FDE20:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820fde3c
	if (ctx.cr6.eq) goto loc_820FDE3C;
loc_820FDE2C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820FDE3C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820fde2c
	if (ctx.cr6.eq) goto loc_820FDE2C;
	// lhz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r29.u32 + 8);
	// bl 0x820fdaf8
	ctx.lr = 0x820FDE4C;
	sub_820FDAF8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// clrlwi r3,r28,16
	ctx.r3.u64 = ctx.r28.u32 & 0xFFFF;
	// bl 0x820fdaf8
	ctx.lr = 0x820FDE58;
	sub_820FDAF8(ctx, base);
	// lhz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 8);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820fe008
	if (ctx.cr6.eq) goto loc_820FE008;
	// li r7,0
	ctx.r7.s64 = 0;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_820FDE6C:
	// neg r10,r31
	ctx.r10.s64 = -ctx.r31.s64;
	// li r11,0
	ctx.r11.s64 = 0;
	// and r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 & ctx.r31.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// andc r31,r31,r10
	ctx.r31.u64 = ctx.r31.u64 & ~ctx.r10.u64;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bgt cr6,0x820fdf2c
	if (ctx.cr6.gt) goto loc_820FDF2C;
	// beq cr6,0x820fdf00
	if (ctx.cr6.eq) goto loc_820FDF00;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x820fdfe0
	if (ctx.cr6.eq) goto loc_820FDFE0;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// beq cr6,0x820fded0
	if (ctx.cr6.eq) goto loc_820FDED0;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x820fdff0
	if (!ctx.cr6.eq) goto loc_820FDFF0;
	// rlwinm r10,r3,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdec8
	if (ctx.cr6.eq) goto loc_820FDEC8;
	// rlwinm r10,r3,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x1;
	// rlwinm r11,r3,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// clrlwi r9,r3,31
	ctx.r9.u64 = ctx.r3.u32 & 0x1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDEC8:
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDED0:
	// rlwinm r10,r3,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdeec
	if (ctx.cr6.eq) goto loc_820FDEEC;
	// rlwinm r11,r3,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDEEC:
	// rlwinm r10,r3,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdff0
	if (ctx.cr6.eq) goto loc_820FDFF0;
	// li r8,2
	ctx.r8.s64 = 2;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDF00:
	// rlwinm r10,r3,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdff0
	if (ctx.cr6.eq) goto loc_820FDFF0;
	// rlwinm r10,r3,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x1;
	// rlwinm r11,r3,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1;
	// rlwinm r9,r3,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDF2C:
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// beq cr6,0x820fdfb0
	if (ctx.cr6.eq) goto loc_820FDFB0;
	// cmplwi cr6,r10,512
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 512, ctx.xer);
	// beq cr6,0x820fdf6c
	if (ctx.cr6.eq) goto loc_820FDF6C;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bne cr6,0x820fdff0
	if (!ctx.cr6.eq) goto loc_820FDFF0;
	// rlwinm r10,r3,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdf58
	if (ctx.cr6.eq) goto loc_820FDF58;
	// li r11,7
	ctx.r11.s64 = 7;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDF58:
	// rlwinm r10,r3,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdfe0
	if (ctx.cr6.eq) goto loc_820FDFE0;
	// li r8,4
	ctx.r8.s64 = 4;
	// b 0x820fdfbc
	goto loc_820FDFBC;
loc_820FDF6C:
	// rlwinm r10,r3,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdf80
	if (ctx.cr6.eq) goto loc_820FDF80;
	// li r11,6
	ctx.r11.s64 = 6;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDF80:
	// rlwinm r10,r3,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdff0
	if (ctx.cr6.eq) goto loc_820FDFF0;
	// rlwinm r10,r3,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x1;
	// rlwinm r11,r3,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1;
	// rlwinm r9,r3,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDFB0:
	// rlwinm r10,r3,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdfe0
	if (ctx.cr6.eq) goto loc_820FDFE0;
loc_820FDFBC:
	// rlwinm r10,r3,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x1;
	// rlwinm r11,r3,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1;
	// rlwinm r9,r3,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x820fdff0
	goto loc_820FDFF0;
loc_820FDFE0:
	// rlwinm r10,r3,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fdff0
	if (ctx.cr6.eq) goto loc_820FDFF0;
	// li r11,1
	ctx.r11.s64 = 1;
loc_820FDFF0:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stwx r11,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r11.u32);
	// stwx r8,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r8.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bdnz 0x820fde6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820FDE6C;
loc_820FE008:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820fe0fc
	if (ctx.cr6.eq) goto loc_820FE0FC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r4,r28,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lfs f13,12868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12868);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f12.f64 = double(temp.f32);
loc_820FE030:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x820fe0e8
	if (ctx.cr6.eq) goto loc_820FE0E8;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
loc_820FE044:
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bgt cr6,0x820fe0bc
	if (ctx.cr6.gt) goto loc_820FE0BC;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820fe0bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FE0BC;
	// bdzf 4*cr6+eq,0x820fe084
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FE084;
	// bdzf 4*cr6+eq,0x820fe094
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820FE094;
	// bne cr6,0x820fe09c
	if (!ctx.cr6.eq) goto loc_820FE09C;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820fe0bc
	goto loc_820FE0BC;
loc_820FE084:
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// b 0x820fe0b8
	goto loc_820FE0B8;
loc_820FE094:
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820fe0a0
	goto loc_820FE0A0;
loc_820FE09C:
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
loc_820FE0A0:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// add r3,r10,r8
	ctx.r3.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r10,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
loc_820FE0B8:
	// fmuls f0,f10,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
loc_820FE0BC:
	// mullw r10,r5,r6
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// lwz r5,36(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfsx f0,r3,r5
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r5.u32, temp.u32);
	// lhz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 8);
	// cmplw cr6,r9,r5
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x820fe044
	if (ctx.cr6.lt) goto loc_820FE044;
loc_820FE0E8:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// add r8,r8,r28
	ctx.r8.u64 = ctx.r8.u64 + ctx.r28.u64;
	// add r7,r4,r7
	ctx.r7.u64 = ctx.r4.u64 + ctx.r7.u64;
	// cmplw cr6,r6,r27
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x820fe030
	if (ctx.cr6.lt) goto loc_820FE030;
loc_820FE0FC:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r7,36(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lwz r6,24(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE120;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FE12C"))) PPC_WEAK_FUNC(sub_820FE12C);
PPC_FUNC_IMPL(__imp__sub_820FE12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE130"))) PPC_WEAK_FUNC(sub_820FE130);
PPC_FUNC_IMPL(__imp__sub_820FE130) {
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
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fe1d0
	if (ctx.cr6.eq) goto loc_820FE1D0;
	// lhz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmplwi cr6,r5,1
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 1, ctx.xer);
	// bne cr6,0x820fe168
	if (!ctx.cr6.eq) goto loc_820FE168;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// b 0x820fe1b4
	goto loc_820FE1B4;
loc_820FE168:
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r7,r9,-5568
	ctx.r7.s64 = ctx.r9.s64 + -5568;
	// ble cr6,0x820fe1b0
	if (!ctx.cr6.gt) goto loc_820FE1B0;
	// addi r9,r7,-4
	ctx.r9.s64 = ctx.r7.s64 + -4;
loc_820FE180:
	// extsw r8,r5
	ctx.r8.s64 = ctx.r5.s32;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 / ctx.f11.f64));
	// stfsu f10,4(r9)
	temp.f32 = float(ctx.f10.f64);
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// lhz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x820fe180
	if (ctx.cr6.lt) goto loc_820FE180;
loc_820FE1B0:
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
loc_820FE1B4:
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE1D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FE1D0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FE1E0"))) PPC_WEAK_FUNC(sub_820FE1E0);
PPC_FUNC_IMPL(__imp__sub_820FE1E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FE1E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE21C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820fe27c
	if (ctx.cr6.eq) goto loc_820FE27C;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// mullw r6,r30,r29
	ctx.r6.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r29.s32);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fe27c
	if (ctx.cr6.eq) goto loc_820FE27C;
	// addi r7,r30,1
	ctx.r7.s64 = ctx.r30.s64 + 1;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FE240:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// mullw r10,r9,r7
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x820fe268
	if (!ctx.cr6.lt) goto loc_820FE268;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// lfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r10,r28
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r28.u32, temp.u32);
loc_820FE268:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x820fe240
	if (ctx.cr6.lt) goto loc_820FE240;
loc_820FE27C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FE288"))) PPC_WEAK_FUNC(sub_820FE288);
PPC_FUNC_IMPL(__imp__sub_820FE288) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820FE2A0"))) PPC_WEAK_FUNC(sub_820FE2A0);
PPC_FUNC_IMPL(__imp__sub_820FE2A0) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fe414
	if (ctx.cr6.eq) goto loc_820FE414;
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// lfs f31,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// lfs f30,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	ctx.cr6.compare(ctx.f2.f64, ctx.f31.f64);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x820fe30c
	if (ctx.cr6.eq) goto loc_820FE30C;
	// fdivs f0,f30,f2
	ctx.f0.f64 = double(float(ctx.f30.f64 / ctx.f2.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x820fe324
	if (ctx.cr6.gt) goto loc_820FE324;
loc_820FE30C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,22044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 22044);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// b 0x820fe344
	goto loc_820FE344;
loc_820FE324:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,23040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x820fe344
	if (!ctx.cr6.gt) goto loc_820FE344;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
loc_820FE344:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,22364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 22364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x820fe358
	if (!ctx.cr6.lt) goto loc_820FE358;
	// fmr f1,f13
	ctx.f1.f64 = ctx.f13.f64;
loc_820FE358:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// fadds f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,-18440(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18440);
	ctx.f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fdivs f0,f9,f13
	ctx.f0.f64 = double(float(ctx.f9.f64 / ctx.f13.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x820fe390
	if (!ctx.cr6.gt) goto loc_820FE390;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
loc_820FE390:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,22440(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 22440);
	// fmul f0,f1,f0
	ctx.f0.f64 = ctx.f1.f64 * ctx.f0.f64;
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fdiv f1,f0,f12
	ctx.f1.f64 = ctx.f0.f64 / ctx.f12.f64;
	// bl 0x8207ae60
	ctx.lr = 0x820FE3B4;
	sub_8207AE60(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,2440(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 2440);
	// fmul f11,f1,f0
	ctx.f11.f64 = ctx.f1.f64 * ctx.f0.f64;
	// frsp f0,f11
	ctx.f0.f64 = double(float(ctx.f11.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x820fe3e4
	if (!ctx.cr6.lt) goto loc_820FE3E4;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x820fe3f4
	goto loc_820FE3F4;
loc_820FE3E4:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x820fe3f8
	if (!ctx.cr6.gt) goto loc_820FE3F8;
	// stfs f30,80(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_820FE3F4:
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
loc_820FE3F8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE414;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FE414:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_820FE430"))) PPC_WEAK_FUNC(sub_820FE430);
PPC_FUNC_IMPL(__imp__sub_820FE430) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
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

__attribute__((alias("__imp__sub_820FE458"))) PPC_WEAK_FUNC(sub_820FE458);
PPC_FUNC_IMPL(__imp__sub_820FE458) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FE45C"))) PPC_WEAK_FUNC(sub_820FE45C);
PPC_FUNC_IMPL(__imp__sub_820FE45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE460"))) PPC_WEAK_FUNC(sub_820FE460);
PPC_FUNC_IMPL(__imp__sub_820FE460) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820FE48C"))) PPC_WEAK_FUNC(sub_820FE48C);
PPC_FUNC_IMPL(__imp__sub_820FE48C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FE490"))) PPC_WEAK_FUNC(sub_820FE490);
PPC_FUNC_IMPL(__imp__sub_820FE490) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// lwz r9,28(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r9,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r9.u32);
	// lwz r11,32(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// lwz r8,28(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820fe4c4
	if (ctx.cr6.lt) goto loc_820FE4C4;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// b 0x820fe4c8
	goto loc_820FE4C8;
loc_820FE4C4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FE4C8:
	// stw r11,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r11.u32);
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x820fe4d8
	if (!ctx.cr6.eq) {
		sub_820FE4D8(ctx, base);
		return;
	}
}

__attribute__((alias("__imp__sub_820FE4D8"))) PPC_WEAK_FUNC(sub_820FE4D8);
PPC_FUNC_IMPL(__imp__sub_820FE4D8) {
	PPC_FUNC_PROLOGUE();
	// stw r11,28(r5)
	PPC_STORE_U32(ctx.r5.u32 + 28, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x820fe4ec
	if (ctx.cr6.eq) goto loc_820FE4EC;
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
loc_820FE4EC:
	// stw r10,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fe504
	if (ctx.cr6.eq) goto loc_820FE504;
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_820FE504:
	// stw r11,24(r5)
	PPC_STORE_U32(ctx.r5.u32 + 24, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,36(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// stw r10,32(r5)
	PPC_STORE_U32(ctx.r5.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FE51C"))) PPC_WEAK_FUNC(sub_820FE51C);
PPC_FUNC_IMPL(__imp__sub_820FE51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE520"))) PPC_WEAK_FUNC(sub_820FE520);
PPC_FUNC_IMPL(__imp__sub_820FE520) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820FE534"))) PPC_WEAK_FUNC(sub_820FE534);
PPC_FUNC_IMPL(__imp__sub_820FE534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE538"))) PPC_WEAK_FUNC(sub_820FE538);
PPC_FUNC_IMPL(__imp__sub_820FE538) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820FE550"))) PPC_WEAK_FUNC(sub_820FE550);
PPC_FUNC_IMPL(__imp__sub_820FE550) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r11,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, ctx.r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FE560"))) PPC_WEAK_FUNC(sub_820FE560);
PPC_FUNC_IMPL(__imp__sub_820FE560) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,22368
	ctx.r10.s64 = ctx.r11.s64 + 22368;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820fe5a4
	if (ctx.cr6.eq) goto loc_820FE5A4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE5A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FE5A4:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fe5bc
	if (ctx.cr6.eq) goto loc_820FE5BC;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x820e9410
	ctx.lr = 0x820FE5BC;
	sub_820E9410(ctx, base);
loc_820FE5BC:
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fe5dc
	if (ctx.cr6.eq) goto loc_820FE5DC;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32816
	ctx.r4.u64 = ctx.r4.u64 | 32816;
	// bl 0x820e9410
	ctx.lr = 0x820FE5D8;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FE5DC:
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

__attribute__((alias("__imp__sub_820FE5F4"))) PPC_WEAK_FUNC(sub_820FE5F4);
PPC_FUNC_IMPL(__imp__sub_820FE5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE5F8"))) PPC_WEAK_FUNC(sub_820FE5F8);
PPC_FUNC_IMPL(__imp__sub_820FE5F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820FE600;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r24,0
	ctx.r24.s64 = 0;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// beq cr6,0x820fe630
	if (ctx.cr6.eq) goto loc_820FE630;
	// li r28,16
	ctx.r28.s64 = 16;
loc_820FE630:
	// stw r8,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x820fe640
	if (ctx.cr6.eq) goto loc_820FE640;
	// ori r28,r28,8
	ctx.r28.u64 = ctx.r28.u64 | 8;
loc_820FE640:
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f1,2440(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2440);
	// bl 0x8207b7a8
	ctx.lr = 0x820FE650;
	sub_8207B7A8(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r26,r31,4
	ctx.r26.s64 = ctx.r31.s64 + 4;
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// lwz r11,32(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FE684;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fe7c8
	if (ctx.cr6.lt) goto loc_820FE7C8;
	// lwz r11,260(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// lis r10,8324
	ctx.r10.s64 = 545521664;
	// lwz r9,268(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r8,252(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// ori r28,r10,1
	ctx.r28.u64 = ctx.r10.u64 | 1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lhz r7,2(r29)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r29.u32 + 2);
	// sth r7,8(r31)
	PPC_STORE_U16(ctx.r31.u32 + 8, ctx.r7.u16);
	// lwz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// beq cr6,0x820fe780
	if (ctx.cr6.eq) goto loc_820FE780;
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE6D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x820e9408
	ctx.lr = 0x820FE70C;
	sub_820E9408(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fe728
	if (!ctx.cr6.eq) goto loc_820FE728;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_820FE728:
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r24.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820fe758
	if (ctx.cr6.eq) goto loc_820FE758;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r24,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r24.u32);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
loc_820FE758:
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE770;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x820e9410
	ctx.lr = 0x820FE780;
	sub_820E9410(ctx, base);
loc_820FE780:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fe7c8
	if (ctx.cr6.lt) goto loc_820FE7C8;
	// lhz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x820e9408
	ctx.lr = 0x820FE7A8;
	sub_820E9408(ctx, base);
	// addic r7,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r7.s64 = ctx.r3.s64 + -1;
	// lis r8,-32761
	ctx.r8.s64 = -2147024896;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// subfe r4,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r5,r8,14
	ctx.r5.u64 = ctx.r8.u64 | 14;
	// and r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 & ctx.r5.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_820FE7C8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FE7D4"))) PPC_WEAK_FUNC(sub_820FE7D4);
PPC_FUNC_IMPL(__imp__sub_820FE7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE7D8"))) PPC_WEAK_FUNC(sub_820FE7D8);
PPC_FUNC_IMPL(__imp__sub_820FE7D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FE7E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// bl 0x820fe490
	ctx.lr = 0x820FE810;
	sub_820FE490(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820fe888
	if (ctx.cr6.eq) goto loc_820FE888;
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// twllei r29,0
	// divwu r10,r11,r29
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r29.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// beq cr6,0x820fe880
	if (ctx.cr6.eq) goto loc_820FE880;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// blt cr6,0x820fe848
	if (ctx.cr6.lt) goto loc_820FE848;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820FE848:
	// addi r7,r28,48
	ctx.r7.s64 = ctx.r28.s64 + 48;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fe884
	if (ctx.cr6.eq) goto loc_820FE884;
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_820FE868:
	// lwzu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// stwu r5,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820fe868
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820FE868;
	// b 0x820fe884
	goto loc_820FE884;
loc_820FE880:
	// addi r7,r30,4
	ctx.r7.s64 = ctx.r30.s64 + 4;
loc_820FE884:
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
loc_820FE888:
	// subfic r11,r27,0
	ctx.xer.ca = ctx.r27.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r27.s64;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// li r9,64
	ctx.r9.s64 = 64;
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r7,r30,0
	ctx.xer.ca = ctx.r30.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r30.s64;
	// and r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 & ctx.r9.u64;
	// subfe r11,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// and r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 & ctx.r10.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FE8C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FE8CC"))) PPC_WEAK_FUNC(sub_820FE8CC);
PPC_FUNC_IMPL(__imp__sub_820FE8CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FE8D0"))) PPC_WEAK_FUNC(sub_820FE8D0);
PPC_FUNC_IMPL(__imp__sub_820FE8D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FE8D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x820e9408
	ctx.lr = 0x820FE908;
	sub_820E9408(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fe924
	if (!ctx.cr6.eq) goto loc_820FE924;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FE924:
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x820fe1e0
	ctx.lr = 0x820FE940;
	sub_820FE1E0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// lhz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FE968;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820e9410
	ctx.lr = 0x820FE97C;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FE988"))) PPC_WEAK_FUNC(sub_820FE988);
PPC_FUNC_IMPL(__imp__sub_820FE988) {
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
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,23040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820fe9b4
	if (ctx.cr6.lt) goto loc_820FE9B4;
	// li r11,2400
	ctx.r11.s64 = 2400;
	// b 0x820fe9e4
	goto loc_820FE9E4;
loc_820FE9B4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-20792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -20792);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x820fe9cc
	if (ctx.cr6.gt) goto loc_820FE9CC;
	// li r11,-2400
	ctx.r11.s64 = -2400;
	// b 0x820fe9e4
	goto loc_820FE9E4;
loc_820FE9CC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,17852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 17852);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lhz r11,86(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
loc_820FE9E4:
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f0,19576(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 19576);
	ctx.f0.f64 = double(temp.f32);
	// lfd f1,2440(r10)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2440);
	// fmuls f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x820FEA10;
	sub_8207B7A8(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820FEA2C;
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

__attribute__((alias("__imp__sub_820FEA40"))) PPC_WEAK_FUNC(sub_820FEA40);
PPC_FUNC_IMPL(__imp__sub_820FEA40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820FEA48;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32816
	ctx.r4.u64 = ctx.r4.u64 | 32816;
	// li r3,8240
	ctx.r3.s64 = 8240;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// bl 0x820e9408
	ctx.lr = 0x820FEA88;
	sub_820E9408(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r23,0
	ctx.r23.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820feb30
	if (ctx.cr6.eq) goto loc_820FEB30;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r23,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r23.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// lwz r26,292(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// addi r9,r11,22368
	ctx.r9.s64 = ctx.r11.s64 + 22368;
	// lwz r11,308(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r23,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r23.u16);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r9,300(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stw r10,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r23,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r23.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r23,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r23.u32);
	// stw r23,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r23.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// stw r23,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r23.u32);
	// stw r23,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r23.u32);
	// stw r23,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r23.u32);
	// stw r23,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r23.u32);
	// stw r23,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r23.u32);
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// bl 0x820fe5f8
	ctx.lr = 0x820FEB10;
	sub_820FE5F8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820feb3c
	if (ctx.cr6.lt) goto loc_820FEB3C;
	// lwz r11,316(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// stw r31,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_820FEB30:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x820feb54
	goto loc_820FEB54;
loc_820FEB3C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FEB54;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FEB54:
	// lwz r11,316(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r23,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r23.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FEB6C"))) PPC_WEAK_FUNC(sub_820FEB6C);
PPC_FUNC_IMPL(__imp__sub_820FEB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FEB70"))) PPC_WEAK_FUNC(sub_820FEB70);
PPC_FUNC_IMPL(__imp__sub_820FEB70) {
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
	// lfs f0,84(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r5,r3,8
	ctx.r5.s64 = ctx.r3.s64 + 8;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r6,52
	ctx.r6.s64 = 52;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stb r9,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r9.u8);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// stb r9,17(r3)
	PPC_STORE_U8(ctx.r3.u32 + 17, ctx.r9.u8);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stb r9,18(r3)
	PPC_STORE_U8(ctx.r3.u32 + 18, ctx.r9.u8);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stb r9,19(r3)
	PPC_STORE_U8(ctx.r3.u32 + 19, ctx.r9.u8);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stb r9,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r9.u8);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stb r9,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, ctx.r9.u8);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stb r9,22(r3)
	PPC_STORE_U8(ctx.r3.u32 + 22, ctx.r9.u8);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// stb r9,23(r3)
	PPC_STORE_U8(ctx.r3.u32 + 23, ctx.r9.u8);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// stb r9,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r9.u8);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stb r9,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, ctx.r9.u8);
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// stb r9,26(r3)
	PPC_STORE_U8(ctx.r3.u32 + 26, ctx.r9.u8);
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stb r9,27(r3)
	PPC_STORE_U8(ctx.r3.u32 + 27, ctx.r9.u8);
	// lfs f13,52(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// lfs f12,56(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lfs f11,60(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// lfs f10,64(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// lfs f9,68(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// lfs f8,72(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// lfs f7,76(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r9,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// lfs f6,80(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FECA0;
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

__attribute__((alias("__imp__sub_820FECB0"))) PPC_WEAK_FUNC(sub_820FECB0);
PPC_FUNC_IMPL(__imp__sub_820FECB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FECB8"))) PPC_WEAK_FUNC(sub_820FECB8);
PPC_FUNC_IMPL(__imp__sub_820FECB8) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,22448
	ctx.r10.s64 = ctx.r11.s64 + 22448;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820fed18
	if (ctx.cr6.eq) goto loc_820FED18;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FED04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FED18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FED18:
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fed38
	if (ctx.cr6.eq) goto loc_820FED38;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32817
	ctx.r4.u64 = ctx.r4.u64 | 32817;
	// bl 0x820e9410
	ctx.lr = 0x820FED34;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FED38:
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

__attribute__((alias("__imp__sub_820FED50"))) PPC_WEAK_FUNC(sub_820FED50);
PPC_FUNC_IMPL(__imp__sub_820FED50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820FED58;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32817
	ctx.r4.u64 = ctx.r4.u64 | 32817;
	// li r3,60
	ctx.r3.s64 = 60;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// bl 0x820e9408
	ctx.lr = 0x820FED88;
	sub_820E9408(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fedf0
	if (ctx.cr6.eq) goto loc_820FEDF0;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r25,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r25.u32);
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// addi r10,r11,22448
	ctx.r10.s64 = ctx.r11.s64 + 22448;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FEDD8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fee08
	if (ctx.cr6.lt) goto loc_820FEE08;
	// stw r31,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_820FEDF0:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// stw r25,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_820FEE08:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FEE20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r25,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FEE30"))) PPC_WEAK_FUNC(sub_820FEE30);
PPC_FUNC_IMPL(__imp__sub_820FEE30) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820fee78
	if (!ctx.cr6.eq) goto loc_820FEE78;
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r5,r3,52
	ctx.r5.s64 = ctx.r3.s64 + 52;
	// lhz r4,120(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 120);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FEE6C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x820fee7c
	if (ctx.cr6.eq) goto loc_820FEE7C;
loc_820FEE78:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820FEE7C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FEE8C"))) PPC_WEAK_FUNC(sub_820FEE8C);
PPC_FUNC_IMPL(__imp__sub_820FEE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FEE90"))) PPC_WEAK_FUNC(sub_820FEE90);
PPC_FUNC_IMPL(__imp__sub_820FEE90) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// b 0x820f3c20
	sub_820F3C20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FEE9C"))) PPC_WEAK_FUNC(sub_820FEE9C);
PPC_FUNC_IMPL(__imp__sub_820FEE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FEEA0"))) PPC_WEAK_FUNC(sub_820FEEA0);
PPC_FUNC_IMPL(__imp__sub_820FEEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FEEA8;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x820be318
	ctx.lr = 0x820FEEC4;
	sub_820BE318(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,116(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lhz r4,120(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 120);
	// bl 0x820f3e28
	ctx.lr = 0x820FEED4;
	sub_820F3E28(ctx, base);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FEEE8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fef60
	if (ctx.cr6.eq) goto loc_820FEF60;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820fef60
	if (ctx.cr6.eq) goto loc_820FEF60;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lhz r4,120(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 120);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FEF10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f42c8
	ctx.lr = 0x820FEF1C;
	sub_820F42C8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// divwu r8,r29,r9
	ctx.r8.u32 = ppc_divwu(ctx.r29.u32, ctx.r9.u32);
	// twllei r9,0
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subf r6,r7,r29
	ctx.r6.s64 = ctx.r29.s64 - ctx.r7.s64;
	// subfic r5,r6,0
	ctx.xer.ca = ctx.r6.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r6.s64;
	// subfe r11,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r4.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 & ctx.r29.u64;
	// bl 0x820f42c8
	ctx.lr = 0x820FEF44;
	sub_820F42C8(ctx, base);
	// add r11,r3,r29
	ctx.r11.u64 = ctx.r3.u64 + ctx.r29.u64;
	// stw r29,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r29.u32);
	// twllei r3,0
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// divwu r9,r10,r3
	ctx.r9.u32 = ppc_divwu(ctx.r10.u32, ctx.r3.u32);
	// mullw r11,r9,r3
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_820FEF60:
	// lis r4,-21628
	ctx.r4.s64 = -1417412608;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820e9408
	ctx.lr = 0x820FEF78;
	sub_820E9408(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff018
	if (ctx.cr6.eq) goto loc_820FF018;
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_820FEFA0:
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820fefa0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820FEFA0;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// addi r10,r31,100
	ctx.r10.s64 = ctx.r31.s64 + 100;
	// clrlwi r30,r28,24
	ctx.r30.u64 = ctx.r28.u32 & 0xFF;
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820ff090
	if (ctx.cr6.eq) goto loc_820FF090;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ec0
	ctx.lr = 0x820FEFD0;
	sub_820F3EC0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// beq cr6,0x820ff028
	if (ctx.cr6.eq) goto loc_820FF028;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820f4838
	ctx.lr = 0x820FEFE4;
	sub_820F4838(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3eb8
	ctx.lr = 0x820FEFF0;
	sub_820F3EB8(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f48e8
	ctx.lr = 0x820FEFFC;
	sub_820F48E8(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ec0
	ctx.lr = 0x820FF008;
	sub_820F3EC0(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// b 0x820ff048
	goto loc_820FF048;
loc_820FF018:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FF028:
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// bl 0x820f3ea0
	ctx.lr = 0x820FF038;
	sub_820F3EA0(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ea8
	ctx.lr = 0x820FF044;
	sub_820F3EA8(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
loc_820FF048:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ed8
	ctx.lr = 0x820FF050;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x820ff090
	if (!ctx.cr6.eq) goto loc_820FF090;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// ble cr6,0x820ff070
	if (!ctx.cr6.gt) goto loc_820FF070;
	// clrlwi r10,r11,25
	ctx.r10.u64 = ctx.r11.u32 & 0x7F;
	// subf r10,r10,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_820FF070:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// ble cr6,0x820ff08c
	if (!ctx.cr6.gt) goto loc_820FF08C;
	// clrlwi r10,r11,25
	ctx.r10.u64 = ctx.r11.u32 & 0x7F;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_820FF08C:
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
loc_820FF090:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FF09C"))) PPC_WEAK_FUNC(sub_820FF09C);
PPC_FUNC_IMPL(__imp__sub_820FF09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF0A0"))) PPC_WEAK_FUNC(sub_820FF0A0);
PPC_FUNC_IMPL(__imp__sub_820FF0A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FF0A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,96(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820ff2c8
	if (!ctx.cr6.gt) goto loc_820FF2C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820be318
	ctx.lr = 0x820FF0C8;
	sub_820BE318(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,116(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lhz r4,120(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 120);
	// bl 0x820f3e28
	ctx.lr = 0x820FF0D8;
	sub_820F3E28(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// subf r30,r11,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r11.s64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// beq cr6,0x820ff1bc
	if (ctx.cr6.eq) goto loc_820FF1BC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f4258
	ctx.lr = 0x820FF0F8;
	sub_820F4258(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x820ff138
	if (!ctx.cr6.gt) goto loc_820FF138;
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820ff138
	if (!ctx.cr6.eq) goto loc_820FF138;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f4258
	ctx.lr = 0x820FF114;
	sub_820F4258(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x820ff134
	if (!ctx.cr6.gt) goto loc_820FF134;
	// divwu r11,r30,r3
	ctx.r11.u32 = ppc_divwu(ctx.r30.u32, ctx.r3.u32);
	// twllei r3,0
	// mullw r10,r11,r3
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// subf r9,r10,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r10.s64;
	// subf r11,r9,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r9.s64;
loc_820FF134:
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_820FF138:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ed8
	ctx.lr = 0x820FF140;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x820ff1a8
	if (!ctx.cr6.eq) goto loc_820FF1A8;
	// lis r4,-21628
	ctx.r4.s64 = -1417412608;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// bl 0x820e9408
	ctx.lr = 0x820FF160;
	sub_820E9408(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ff1bc
	if (ctx.cr6.eq) goto loc_820FF1BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x8207da20
	ctx.lr = 0x820FF178;
	sub_8207DA20(ctx, base);
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x8207dac0
	ctx.lr = 0x820FF190;
	sub_8207DAC0(ctx, base);
	// lis r4,-21628
	ctx.r4.s64 = -1417412608;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// bl 0x820e9410
	ctx.lr = 0x820FF1A0;
	sub_820E9410(ctx, base);
	// stw r29,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r29.u32);
	// b 0x820ff1bc
	goto loc_820FF1BC;
loc_820FF1A8:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r10,0
	ctx.r10.s64 = 0;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// subf r30,r11,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r11.s64;
loc_820FF1BC:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820ff1cc
	if (!ctx.cr6.lt) goto loc_820FF1CC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_820FF1CC:
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ed8
	ctx.lr = 0x820FF1D8;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820ff258
	if (ctx.cr6.eq) goto loc_820FF258;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f4258
	ctx.lr = 0x820FF1E8;
	sub_820F4258(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// twllei r3,0
	// divwu r10,r11,r3
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r3.u32);
	// mullw r9,r10,r3
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf. r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x820ff258
	if (ctx.cr0.eq) goto loc_820FF258;
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820ff258
	if (!ctx.cr6.eq) goto loc_820FF258;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,16(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x820f4258
	ctx.lr = 0x820FF218;
	sub_820F4258(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x820ff250
	if (!ctx.cr6.gt) goto loc_820FF250;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f4258
	ctx.lr = 0x820FF228;
	sub_820F4258(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x820ff254
	if (!ctx.cr6.gt) goto loc_820FF254;
	// divwu r10,r11,r3
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r3.u32);
	// twllei r3,0
	// mullw r9,r10,r3
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	// subf r10,r8,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r8.s64;
	// b 0x820ff254
	goto loc_820FF254;
loc_820FF250:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_820FF254:
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
loc_820FF258:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FF278;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff2bc
	if (ctx.cr6.eq) goto loc_820FF2BC;
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lhz r4,120(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 120);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF298;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff2bc
	if (ctx.cr6.eq) goto loc_820FF2BC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,88(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r29,76(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x820f3f10
	ctx.lr = 0x820FF2B0;
	sub_820F3F10(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x820e7ce0
	ctx.lr = 0x820FF2BC;
	sub_820E7CE0(ctx, base);
loc_820FF2BC:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FF2C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FF2D4"))) PPC_WEAK_FUNC(sub_820FF2D4);
PPC_FUNC_IMPL(__imp__sub_820FF2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF2D8"))) PPC_WEAK_FUNC(sub_820FF2D8);
PPC_FUNC_IMPL(__imp__sub_820FF2D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FF2E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r4.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// stw r30,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r30.u32);
	// addi r9,r10,22460
	ctx.r9.s64 = ctx.r10.s64 + 22460;
	// stw r30,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// addi r29,r31,72
	ctx.r29.s64 = ctx.r31.s64 + 72;
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// sth r11,120(r31)
	PPC_STORE_U16(ctx.r31.u32 + 120, ctx.r11.u16);
	// stw r6,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r6.u32);
	// bl 0x8207da20
	ctx.lr = 0x820FF33C;
	sub_8207DA20(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r9,r31,12
	ctx.r9.s64 = ctx.r31.s64 + 12;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820FF350:
	// stwu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x820ff350
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820FF350;
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r29,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r29.u32);
	// stw r9,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FF37C"))) PPC_WEAK_FUNC(sub_820FF37C);
PPC_FUNC_IMPL(__imp__sub_820FF37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF380"))) PPC_WEAK_FUNC(sub_820FF380);
PPC_FUNC_IMPL(__imp__sub_820FF380) {
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
	// lwz r3,88(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,22460
	ctx.r10.s64 = ctx.r11.s64 + 22460;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820ff3c0
	if (ctx.cr6.eq) goto loc_820FF3C0;
	// lis r4,-21628
	ctx.r4.s64 = -1417412608;
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// bl 0x820e9410
	ctx.lr = 0x820FF3C0;
	sub_820E9410(ctx, base);
loc_820FF3C0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,16136
	ctx.r9.s64 = ctx.r11.s64 + 16136;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x820ff3ec
	if (ctx.cr6.eq) goto loc_820FF3EC;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32810
	ctx.r4.u64 = ctx.r4.u64 | 32810;
	// bl 0x820e9410
	ctx.lr = 0x820FF3E8;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FF3EC:
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

__attribute__((alias("__imp__sub_820FF404"))) PPC_WEAK_FUNC(sub_820FF404);
PPC_FUNC_IMPL(__imp__sub_820FF404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF408"))) PPC_WEAK_FUNC(sub_820FF408);
PPC_FUNC_IMPL(__imp__sub_820FF408) {
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
	// bl 0x820f98d8
	ctx.lr = 0x820FF420;
	sub_820F98D8(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// lbz r3,216(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r6,r10,22500
	ctx.r6.s64 = ctx.r10.s64 + 22500;
	// addi r5,r8,22464
	ctx.r5.s64 = ctx.r8.s64 + 22464;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// addi r4,r7,22556
	ctx.r4.s64 = ctx.r7.s64 + 22556;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// clrlwi r9,r3,29
	ctx.r9.u64 = ctx.r3.u32 & 0x7;
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// addi r10,r31,156
	ctx.r10.s64 = ctx.r31.s64 + 156;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r11,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// stw r4,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r4.u32);
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// stb r9,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r9.u8);
loc_820FF490:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x820ff490
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820FF490;
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

__attribute__((alias("__imp__sub_820FF4B0"))) PPC_WEAK_FUNC(sub_820FF4B0);
PPC_FUNC_IMPL(__imp__sub_820FF4B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r9,r3,-16
	ctx.r9.s64 = ctx.r3.s64 + -16;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// subfic r8,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// and r4,r6,r11
	ctx.r4.u64 = ctx.r6.u64 & ctx.r11.u64;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820FF4D8"))) PPC_WEAK_FUNC(sub_820FF4D8);
PPC_FUNC_IMPL(__imp__sub_820FF4D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FF4E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,216(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 216);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r7,r10,22500
	ctx.r7.s64 = ctx.r10.s64 + 22500;
	// addi r6,r9,22464
	ctx.r6.s64 = ctx.r9.s64 + 22464;
	// addi r5,r8,22556
	ctx.r5.s64 = ctx.r8.s64 + 22556;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// ori r4,r11,128
	ctx.r4.u64 = ctx.r11.u64 | 128;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r4,216(r3)
	PPC_STORE_U8(ctx.r3.u32 + 216, ctx.r4.u8);
	// bl 0x820f9db0
	ctx.lr = 0x820FF51C;
	sub_820F9DB0(ctx, base);
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// beq cr6,0x820ff56c
	if (ctx.cr6.eq) goto loc_820FF56C;
	// bl 0x820fee30
	ctx.lr = 0x820FF534;
	sub_820FEE30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// beq cr6,0x820ff54c
	if (ctx.cr6.eq) goto loc_820FF54C;
	// li r30,1
	ctx.r30.s64 = 1;
	// bl 0x820fee90
	ctx.lr = 0x820FF548;
	sub_820FEE90(ctx, base);
	// b 0x820ff568
	goto loc_820FF568;
loc_820FF54C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ff568
	if (ctx.cr6.eq) goto loc_820FF568;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF568;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF568:
	// stw r29,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
loc_820FF56C:
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff5b4
	if (ctx.cr6.eq) goto loc_820FF5B4;
	// bl 0x820fee30
	ctx.lr = 0x820FF57C;
	sub_820FEE30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// beq cr6,0x820ff594
	if (ctx.cr6.eq) goto loc_820FF594;
	// li r30,1
	ctx.r30.s64 = 1;
	// bl 0x820fee90
	ctx.lr = 0x820FF590;
	sub_820FEE90(ctx, base);
	// b 0x820ff5b0
	goto loc_820FF5B0;
loc_820FF594:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ff5b0
	if (ctx.cr6.eq) goto loc_820FF5B0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF5B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF5B0:
	// stw r29,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r29.u32);
loc_820FF5B4:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ff5d4
	if (ctx.cr6.eq) goto loc_820FF5D4;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x820f3f48
	ctx.lr = 0x820FF5C8;
	sub_820F3F48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f37a8
	ctx.lr = 0x820FF5D4;
	sub_820F37A8(ctx, base);
loc_820FF5D4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x820ff61c
	if (!ctx.cr6.eq) goto loc_820FF61C;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF5F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff61c
	if (ctx.cr6.eq) goto loc_820FF61C;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// lwz r30,80(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x820FF604;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF61C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF61C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9ed0
	ctx.lr = 0x820FF624;
	sub_820F9ED0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FF62C"))) PPC_WEAK_FUNC(sub_820FF62C);
PPC_FUNC_IMPL(__imp__sub_820FF62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF630"))) PPC_WEAK_FUNC(sub_820FF630);
PPC_FUNC_IMPL(__imp__sub_820FF630) {
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
	// lwz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,200(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x820ff704
	if (ctx.cr6.lt) goto loc_820FF704;
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x820ff6ac
	if (!ctx.cr6.eq) goto loc_820FF6AC;
	// lbz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ff6ac
	if (!ctx.cr6.eq) goto loc_820FF6AC;
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// rlwinm r9,r11,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r9,2048
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2048, ctx.xer);
	// beq cr6,0x820ff6ac
	if (ctx.cr6.eq) goto loc_820FF6AC;
	// lbz r11,216(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 216);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820ff69c
	if (!ctx.cr6.eq) goto loc_820FF69C;
	// lwz r11,168(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ff704
	if (ctx.cr6.eq) goto loc_820FF704;
loc_820FF69C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r11.u32);
	// stw r11,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// b 0x820ff6d8
	goto loc_820FF6D8;
loc_820FF6AC:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r9,r11,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r9,2048
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2048, ctx.xer);
	// beq cr6,0x820ff6c8
	if (ctx.cr6.eq) goto loc_820FF6C8;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820ff704
	if (!ctx.cr6.eq) goto loc_820FF704;
loc_820FF6C8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820ff704
	if (ctx.cr6.eq) goto loc_820FF704;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r11.u32);
loc_820FF6D8:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// ori r10,r11,4096
	ctx.r10.u64 = ctx.r11.u64 | 4096;
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FF6F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r7,216(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stb r6,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r6.u8);
loc_820FF704:
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

__attribute__((alias("__imp__sub_820FF718"))) PPC_WEAK_FUNC(sub_820FF718);
PPC_FUNC_IMPL(__imp__sub_820FF718) {
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
	// bl 0x820f9f18
	ctx.lr = 0x820FF738;
	sub_820F9F18(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820ff760
	if (ctx.cr6.lt) goto loc_820FF760;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x820ff760
	if (!ctx.cr6.eq) goto loc_820FF760;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x820ff760
	if (!ctx.cr6.eq) goto loc_820FF760;
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
	// stb r10,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r10.u8);
loc_820FF760:
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

__attribute__((alias("__imp__sub_820FF778"))) PPC_WEAK_FUNC(sub_820FF778);
PPC_FUNC_IMPL(__imp__sub_820FF778) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FF780;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// addi r28,r3,144
	ctx.r28.s64 = ctx.r3.s64 + 144;
	// addi r30,r3,24
	ctx.r30.s64 = ctx.r3.s64 + 24;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r3,160
	ctx.r29.s64 = ctx.r3.s64 + 160;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// stw r9,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r9.u32);
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// stw r8,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r8.u32);
	// stw r28,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r28.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f3ec8
	ctx.lr = 0x820FF7BC;
	sub_820F3EC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff820
	if (ctx.cr6.eq) goto loc_820FF820;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r27,80(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x820f48e8
	ctx.lr = 0x820FF7D4;
	sub_820F48E8(ctx, base);
	// cmplw cr6,r3,r27
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r27.u32, ctx.xer);
	// bgt cr6,0x820ff820
	if (ctx.cr6.gt) goto loc_820FF820;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// stw r9,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r9.u32);
	// lwz r8,40(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// stw r8,180(r31)
	PPC_STORE_U32(ctx.r31.u32 + 180, ctx.r8.u32);
	// bl 0x820f3ec0
	ctx.lr = 0x820FF7FC;
	sub_820F3EC0(ctx, base);
	// lwz r7,180(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// add r6,r3,r7
	ctx.r6.u64 = ctx.r3.u64 + ctx.r7.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r6.u32);
	// bl 0x820f48e8
	ctx.lr = 0x820FF810;
	sub_820F48E8(ctx, base);
	// lbz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// stw r3,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r3.u32);
	// ori r4,r5,32
	ctx.r4.u64 = ctx.r5.u64 | 32;
	// stb r4,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r4.u8);
loc_820FF820:
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r31,136
	ctx.r9.s64 = ctx.r31.s64 + 136;
	// stw r31,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r31.u32);
	// ori r8,r11,64
	ctx.r8.u64 = ctx.r11.u64 | 64;
	// stw r29,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r29.u32);
	// stw r10,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r10.u32);
	// stw r9,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r9.u32);
	// stb r8,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r8.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FF84C"))) PPC_WEAK_FUNC(sub_820FF84C);
PPC_FUNC_IMPL(__imp__sub_820FF84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF850"))) PPC_WEAK_FUNC(sub_820FF850);
PPC_FUNC_IMPL(__imp__sub_820FF850) {
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
	// lwz r3,108(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff888
	if (ctx.cr6.eq) goto loc_820FF888;
	// bl 0x820fee30
	ctx.lr = 0x820FF87C;
	sub_820FEE30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff888
	if (ctx.cr6.eq) goto loc_820FF888;
	// li r30,1
	ctx.r30.s64 = 1;
loc_820FF888:
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff8a4
	if (ctx.cr6.eq) goto loc_820FF8A4;
	// bl 0x820fee30
	ctx.lr = 0x820FF898;
	sub_820FEE30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff8a4
	if (ctx.cr6.eq) goto loc_820FF8A4;
	// li r30,1
	ctx.r30.s64 = 1;
loc_820FF8A4:
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff8d0
	if (ctx.cr6.eq) goto loc_820FF8D0;
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// beq cr6,0x820ff8d0
	if (ctx.cr6.eq) goto loc_820FF8D0;
	// bl 0x820fee30
	ctx.lr = 0x820FF8C4;
	sub_820FEE30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x820ff8d4
	if (!ctx.cr6.eq) goto loc_820FF8D4;
loc_820FF8D0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820FF8D4:
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

__attribute__((alias("__imp__sub_820FF8EC"))) PPC_WEAK_FUNC(sub_820FF8EC);
PPC_FUNC_IMPL(__imp__sub_820FF8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF8F0"))) PPC_WEAK_FUNC(sub_820FF8F0);
PPC_FUNC_IMPL(__imp__sub_820FF8F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FF8F8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ff970
	if (ctx.cr6.eq) goto loc_820FF970;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// bne cr6,0x820ff944
	if (!ctx.cr6.eq) goto loc_820FF944;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ff944
	if (ctx.cr6.eq) goto loc_820FF944;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF944;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF944:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF958;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,132(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820FF970;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FF970:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,8192
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8192, ctx.xer);
	// beq cr6,0x820ff9d8
	if (ctx.cr6.eq) goto loc_820FF9D8;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FF998;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820ff9cc
	if (ctx.cr6.lt) goto loc_820FF9CC;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820ff9b4
	if (ctx.cr6.eq) goto loc_820FF9B4;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x820f8a70
	ctx.lr = 0x820FF9B4;
	sub_820F8A70(ctx, base);
loc_820FF9B4:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FF9CC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FF9D8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FF9E4"))) PPC_WEAK_FUNC(sub_820FF9E4);
PPC_FUNC_IMPL(__imp__sub_820FF9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FF9E8"))) PPC_WEAK_FUNC(sub_820FF9E8);
PPC_FUNC_IMPL(__imp__sub_820FF9E8) {
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
	// bl 0x820ff4d8
	ctx.lr = 0x820FFA08;
	sub_820FF4D8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ffa28
	if (ctx.cr6.eq) goto loc_820FFA28;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32799
	ctx.r4.u64 = ctx.r4.u64 | 32799;
	// bl 0x820e9410
	ctx.lr = 0x820FFA24;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FFA28:
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

__attribute__((alias("__imp__sub_820FFA40"))) PPC_WEAK_FUNC(sub_820FFA40);
PPC_FUNC_IMPL(__imp__sub_820FFA40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820FFA48;
	__savegprlr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820f9210
	ctx.lr = 0x820FFA54;
	sub_820F9210(ctx, base);
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r23,0
	ctx.r23.s64 = 0;
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bne cr6,0x820ffa8c
	if (!ctx.cr6.eq) goto loc_820FFA8C;
loc_820FFA6C:
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
	ctx.lr = 0x820FFA84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_820FFA8C:
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x820ffacc
	if (!ctx.cr6.eq) goto loc_820FFACC;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x820ffacc
	if (!ctx.cr6.eq) goto loc_820FFACC;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r11,r11,0,28,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ff8f0
	ctx.lr = 0x820FFAC4;
	sub_820FF8F0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820ffa6c
	if (ctx.cr6.lt) goto loc_820FFA6C;
loc_820FFACC:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x820ffb10
	if (!ctx.cr6.eq) goto loc_820FFB10;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x82100098
	if (ctx.cr6.eq) goto loc_82100098;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FFAFC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f8f80
	ctx.lr = 0x820FFB08;
	sub_820F8F80(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_820FFB10:
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// beq cr6,0x82100098
	if (ctx.cr6.eq) goto loc_82100098;
	// addi r24,r31,24
	ctx.r24.s64 = ctx.r31.s64 + 24;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f4258
	ctx.lr = 0x820FFB2C;
	sub_820F4258(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r27,r23
	ctx.r27.u64 = ctx.r23.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x820FFB3C;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x820ffb60
	if (!ctx.cr6.eq) goto loc_820FFB60;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f3f28
	ctx.lr = 0x820FFB4C;
	sub_820F3F28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ffb60
	if (ctx.cr6.eq) goto loc_820FFB60;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f3f28
	ctx.lr = 0x820FFB5C;
	sub_820F3F28(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_820FFB60:
	// lwz r30,116(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820ffbd8
	if (ctx.cr6.eq) goto loc_820FFBD8;
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// beq cr6,0x820ffbd8
	if (ctx.cr6.eq) goto loc_820FFBD8;
	// lwz r11,72(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820ffbd0
	if (!ctx.cr6.eq) goto loc_820FFBD0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r28,80(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x820FFB94;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r30,52
	ctx.r5.s64 = ctx.r30.s64 + 52;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FFBB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82100098
	if (ctx.cr6.eq) goto loc_82100098;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,116(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// bl 0x820ff0a0
	ctx.lr = 0x820FFBC8;
	sub_820FF0A0(ctx, base);
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// stw r23,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r23.u32);
loc_820FFBD0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ff778
	ctx.lr = 0x820FFBD8;
	sub_820FF778(ctx, base);
loc_820FFBD8:
	// lwz r30,132(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// li r25,2
	ctx.r25.s64 = 2;
	// lwz r11,72(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820ffdec
	if (!ctx.cr6.eq) goto loc_820FFDEC;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r28,80(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x820FFBF8;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r30,52
	ctx.r5.s64 = ctx.r30.s64 + 52;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FFC18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820ffdec
	if (ctx.cr6.eq) goto loc_820FFDEC;
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x820ff0a0
	ctx.lr = 0x820FFC2C;
	sub_820FF0A0(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820ffd98
	if (ctx.cr6.eq) goto loc_820FFD98;
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// add r28,r11,r3
	ctx.r28.u64 = ctx.r11.u64 + ctx.r3.u64;
	// beq cr6,0x820ffc70
	if (ctx.cr6.eq) goto loc_820FFC70;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x820ffc70
	if (ctx.cr6.eq) goto loc_820FFC70;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// twllei r26,0
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// lwz r11,92(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// divwu r29,r10,r26
	ctx.r29.u32 = ppc_divwu(ctx.r10.u32, ctx.r26.u32);
loc_820FFC70:
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ffcec
	if (ctx.cr6.eq) goto loc_820FFCEC;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// beq cr6,0x820ffcec
	if (ctx.cr6.eq) goto loc_820FFCEC;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x820FFC94;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x820ffcec
	if (!ctx.cr6.eq) goto loc_820FFCEC;
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820ffcec
	if (!ctx.cr6.lt) goto loc_820FFCEC;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820ffcec
	if (ctx.cr6.lt) goto loc_820FFCEC;
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// lwz r30,212(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820ffcec
	if (!ctx.cr6.eq) goto loc_820FFCEC;
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820ffcec
	if (!ctx.cr6.eq) goto loc_820FFCEC;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r30,r9,r30
	ctx.r30.u64 = ctx.r9.u64 & ctx.r30.u64;
loc_820FFCEC:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// stw r28,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r28.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r30,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r30.u32);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r10,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r10.u32);
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r23,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r23.u32);
	// stw r25,72(r8)
	PPC_STORE_U32(ctx.r8.u32 + 72, ctx.r25.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cntlzw r8,r4
	ctx.r8.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FFD44;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820ffd6c
	if (ctx.cr6.lt) goto loc_820FFD6C;
	// stw r23,44(r11)
	PPC_STORE_U32(ctx.r11.u32 + 44, ctx.r23.u32);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r23,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r23.u32);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r9,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// b 0x820ffd70
	goto loc_820FFD70;
loc_820FFD6C:
	// stw r23,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r23.u32);
loc_820FFD70:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820ffda0
	if (!ctx.cr6.eq) goto loc_820FFDA0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9a50
	ctx.lr = 0x820FFD88;
	sub_820F9A50(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820FFD94;
	sub_820F9380(ctx, base);
	// b 0x820ffda0
	goto loc_820FFDA0;
loc_820FFD98:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// stw r23,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r23.u32);
loc_820FFDA0:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820ffdc4
	if (!ctx.cr6.eq) goto loc_820FFDC4;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ffdc8
	if (ctx.cr6.eq) goto loc_820FFDC8;
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// b 0x820ffdc8
	goto loc_820FFDC8;
loc_820FFDC4:
	// stw r10,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
loc_820FFDC8:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820ffde8
	if (!ctx.cr6.eq) goto loc_820FFDE8;
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820ffdec
	if (ctx.cr6.eq) goto loc_820FFDEC;
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// b 0x820ffdec
	goto loc_820FFDEC;
loc_820FFDE8:
	// stw r10,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
loc_820FFDEC:
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ffee8
	if (ctx.cr6.eq) goto loc_820FFEE8;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// beq cr6,0x820ffee8
	if (ctx.cr6.eq) goto loc_820FFEE8;
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820ffee8
	if (ctx.cr6.lt) goto loc_820FFEE8;
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82100098
	if (!ctx.cr6.eq) goto loc_82100098;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820ffe7c
	if (ctx.cr6.eq) goto loc_820FFE7C;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r31,160
	ctx.r4.s64 = ctx.r31.s64 + 160;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FFE58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820ffe78
	if (ctx.cr6.lt) goto loc_820FFE78;
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// stw r25,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r25.u32);
	// ori r10,r11,8
	ctx.r10.u64 = ctx.r11.u64 | 8;
	// stb r10,216(r31)
	PPC_STORE_U8(ctx.r31.u32 + 216, ctx.r10.u8);
	// b 0x820ffe7c
	goto loc_820FFE7C;
loc_820FFE78:
	// stw r23,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r23.u32);
loc_820FFE7C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820ffeb0
	if (ctx.cr6.lt) goto loc_820FFEB0;
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820ffe9c
	if (!ctx.cr6.eq) goto loc_820FFE9C;
	// addi r11,r31,160
	ctx.r11.s64 = ctx.r31.s64 + 160;
	// b 0x820ffea0
	goto loc_820FFEA0;
loc_820FFE9C:
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
loc_820FFEA0:
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
	// bl 0x820ff630
	ctx.lr = 0x820FFEB0;
	sub_820FF630(ctx, base);
loc_820FFEB0:
	// lbz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820ffed0
	if (ctx.cr6.eq) goto loc_820FFED0;
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_820FFED0:
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_820FFEE8:
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820fff08
	if (ctx.cr6.lt) goto loc_820FFF08;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820ff630
	ctx.lr = 0x820FFF00;
	sub_820FF630(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_820FFF08:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82100098
	if (!ctx.cr6.eq) goto loc_82100098;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x820f2fa8
	ctx.lr = 0x820FFF30;
	sub_820F2FA8(ctx, base);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r3,60(r9)
	PPC_STORE_U32(ctx.r9.u32 + 60, ctx.r3.u32);
	// stw r23,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, ctx.r23.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r7,124(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// subf r6,r3,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r3.s64;
	// stw r6,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, ctx.r6.u32);
	// lhz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r4,r5,0,20,20
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r4,2048
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2048, ctx.xer);
	// beq cr6,0x820fff70
	if (ctx.cr6.eq) goto loc_820FFF70;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fff70
	if (ctx.cr6.eq) goto loc_820FFF70;
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// b 0x820fff74
	goto loc_820FFF74;
loc_820FFF70:
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
loc_820FFF74:
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,96(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820fffa0
	if (!ctx.cr6.gt) goto loc_820FFFA0;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_820FFFA0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82100054
	if (ctx.cr6.lt) goto loc_82100054;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x820FFFB0;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82100010
	if (!ctx.cr6.eq) goto loc_82100010;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820ffffc
	if (!ctx.cr6.gt) goto loc_820FFFFC;
	// lwz r10,124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820ffffc
	if (!ctx.cr6.eq) goto loc_820FFFFC;
	// lbz r10,216(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 216);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,64
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 64, ctx.xer);
	// bne cr6,0x820ffffc
	if (!ctx.cr6.eq) goto loc_820FFFFC;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// clrlwi r10,r11,21
	ctx.r10.u64 = ctx.r11.u32 & 0x7FF;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// b 0x82100050
	goto loc_82100050;
loc_820FFFFC:
	// cmplwi cr6,r11,2048
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2048, ctx.xer);
	// ble cr6,0x82100054
	if (!ctx.cr6.gt) goto loc_82100054;
	// clrlwi r10,r11,21
	ctx.r10.u64 = ctx.r11.u32 & 0x7FF;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// b 0x82100050
	goto loc_82100050;
loc_82100010:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f42c8
	ctx.lr = 0x82100018;
	sub_820F42C8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x82100054
	if (!ctx.cr6.gt) goto loc_82100054;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x820f42c8
	ctx.lr = 0x8210002C;
	sub_820F42C8(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x82100050
	if (!ctx.cr6.gt) goto loc_82100050;
	// divwu r11,r10,r3
	ctx.r11.u32 = ppc_divwu(ctx.r10.u32, ctx.r3.u32);
	// twllei r3,0
	// mullw r9,r11,r3
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// subf r11,r8,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r8.s64;
loc_82100050:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_82100054:
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r11,80(r10)
	PPC_STORE_U32(ctx.r10.u32 + 80, ctx.r11.u32);
	// lwz r29,80(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r30,128(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// bl 0x820f3f48
	ctx.lr = 0x8210006C;
	sub_820F3F48(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82100088;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x82100098
	if (!ctx.cr6.lt) goto loc_82100098;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r23,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r23.u32);
loc_82100098:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821000A0"))) PPC_WEAK_FUNC(sub_821000A0);
PPC_FUNC_IMPL(__imp__sub_821000A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x821000A8;
	__savegprlr_22(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stb r5,247(r1)
	PPC_STORE_U8(ctx.r1.u32 + 247, ctx.r5.u8);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// bl 0x820f9a50
	ctx.lr = 0x821000CC;
	sub_820F9A50(ctx, base);
	// addic r10,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r10.s64 = ctx.r29.s64 + -1;
	// lbz r11,247(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 247);
	// lis r12,0
	ctx.r12.s64 = 0;
	// subfe r8,r10,r29
	temp.u8 = (~ctx.r10.u32 + ctx.r29.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic r7,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// subfe r5,r7,r11
	temp.u8 = (~ctx.r7.u32 + ctx.r11.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r11.u8);
	// ori r12,r12,63423
	ctx.r12.u64 = ctx.r12.u64 | 63423;
	// rlwimi r5,r8,5,26,26
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r8.u32, 5) & 0x20) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFDF);
	// li r22,0
	ctx.r22.s64 = 0;
	// rlwinm r11,r5,6,20,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFC0;
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// addi r7,r1,247
	ctx.r7.s64 = ctx.r1.s64 + 247;
	// rlwinm r11,r11,0,25,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF87F;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// and r9,r10,r12
	ctx.r9.u64 = ctx.r10.u64 & ctx.r12.u64;
	// or r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 | ctx.r9.u64;
	// sth r8,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// bl 0x820f94a8
	ctx.lr = 0x8210012C;
	sub_820F94A8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r22.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821005a4
	if (ctx.cr6.lt) goto loc_821005A4;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8210014c
	if (!ctx.cr6.eq) goto loc_8210014C;
	// lbz r11,247(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 247);
	// stb r11,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r11.u8);
loc_8210014C:
	// addi r25,r31,24
	ctx.r25.s64 = ctx.r31.s64 + 24;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f4640
	ctx.lr = 0x82100160;
	sub_820F4640(ctx, base);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f3ea0
	ctx.lr = 0x8210016C;
	sub_820F3EA0(ctx, base);
	// stw r3,200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 200, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820f4838
	ctx.lr = 0x8210017C;
	sub_820F4838(ctx, base);
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// addi r4,r31,212
	ctx.r4.s64 = ctx.r31.s64 + 212;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f4848
	ctx.lr = 0x8210018C;
	sub_820F4848(ctx, base);
	// lbz r10,247(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 247);
	// stw r3,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821001b4
	if (ctx.cr6.eq) goto loc_821001B4;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f3ec8
	ctx.lr = 0x821001A4;
	sub_820F3EC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821001b4
	if (!ctx.cr6.eq) goto loc_821001B4;
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
loc_821001B4:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// beq cr6,0x821001cc
	if (ctx.cr6.eq) goto loc_821001CC;
	// lbz r30,60(r31)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
loc_821001CC:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r26,80(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x821001D8;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r29,r31,112
	ctx.r29.s64 = ctx.r31.s64 + 112;
	// addi r27,r31,108
	ctx.r27.s64 = ctx.r31.s64 + 108;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r8,r23
	ctx.r8.u64 = ctx.r23.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// clrlwi r7,r30,24
	ctx.r7.u64 = ctx.r30.u32 & 0xFF;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100208;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821005a4
	if (ctx.cr6.lt) goto loc_821005A4;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// li r26,1
	ctx.r26.s64 = 1;
	// stw r31,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r31.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82100234
	if (ctx.cr6.eq) goto loc_82100234;
	// stw r31,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r31.u32);
	// li r26,2
	ctx.r26.s64 = 2;
loc_82100234:
	// clrlwi r29,r26,24
	ctx.r29.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// bne cr6,0x82100280
	if (!ctx.cr6.eq) goto loc_82100280;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x82100248;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x82100268
	if (!ctx.cr6.eq) goto loc_82100268;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82100268
	if (ctx.cr6.eq) goto loc_82100268;
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r23,r22
	ctx.r23.u64 = ctx.r22.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_82100268:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// beq cr6,0x821002d8
	if (ctx.cr6.eq) goto loc_821002D8;
	// stb r22,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r22.u8);
	// b 0x821002d8
	goto loc_821002D8;
loc_82100280:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// beq cr6,0x821002d8
	if (ctx.cr6.eq) goto loc_821002D8;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821002d8
	if (ctx.cr6.eq) goto loc_821002D8;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r30,80(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x821002A8;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r31,116
	ctx.r5.s64 = ctx.r31.s64 + 116;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821002C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821005a4
	if (ctx.cr6.lt) goto loc_821005A4;
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// clrlwi r26,r11,24
	ctx.r26.u64 = ctx.r11.u32 & 0xFF;
loc_821002D8:
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r9,r28,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// rlwimi r10,r9,2,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 2) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// beq cr6,0x8210034c
	if (ctx.cr6.eq) goto loc_8210034C;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r7,32(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// lwz r30,64(r8)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// lhz r4,1(r7)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + 1);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82100334
	if (ctx.cr6.eq) goto loc_82100334;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100330;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82100338
	goto loc_82100338;
loc_82100334:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_82100338:
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// subfe r9,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r9,2,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 2) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
loc_8210034C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r22,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r22.u32);
	// mr r10,r22
	ctx.r10.u64 = ctx.r22.u64;
	// stw r22,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r22.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f0,14004(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// beq cr6,0x821003a4
	if (ctx.cr6.eq) goto loc_821003A4;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,20(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r6,16
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 16, ctx.xer);
	// bne cr6,0x821003a4
	if (!ctx.cr6.eq) goto loc_821003A4;
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// lfs f0,124(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_821003A4:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lhz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// rlwinm r6,r7,30,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821003E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821005a4
	if (ctx.cr6.lt) goto loc_821005A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x820f8f80
	ctx.lr = 0x821003F8;
	sub_820F8F80(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82100450
	if (ctx.cr6.eq) goto loc_82100450;
	// lwz r28,88(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r29,0(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x820fa2a8
	ctx.lr = 0x82100418;
	sub_820FA2A8(ctx, base);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100428;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r28,88(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r29,0(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x820fa2f0
	ctx.lr = 0x82100440;
	sub_820FA2F0(ctx, base);
	// lwz r7,8(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82100450;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82100450:
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82100618
	if (!ctx.cr6.lt) goto loc_82100618;
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// bl 0x820f2fa8
	ctx.lr = 0x82100474;
	sub_820F2FA8(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// subf r9,r3,r23
	ctx.r9.s64 = ctx.r23.s64 - ctx.r3.s64;
	// stw r3,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r3.u32);
	// stw r22,64(r10)
	PPC_STORE_U32(ctx.r10.u32 + 64, ctx.r22.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r9,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, ctx.r9.u32);
	// lhz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r6,r7,0,20,20
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r6,2048
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 2048, ctx.xer);
	// beq cr6,0x821004a8
	if (ctx.cr6.eq) goto loc_821004A8;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821004b0
	if (!ctx.cr6.eq) goto loc_821004B0;
loc_821004A8:
	// lwz r11,200(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 200);
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
loc_821004B0:
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// lwz r11,76(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x821004c8
	if (ctx.cr6.lt) goto loc_821004C8;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_821004C8:
	// lwz r9,96(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// subf r10,r23,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r23.s64;
	// subf r30,r9,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r9.s64;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x821004e0
	if (ctx.cr6.lt) goto loc_821004E0;
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
loc_821004E0:
	// clrlwi r11,r26,24
	ctx.r11.u64 = ctx.r26.u32 & 0xFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x82100530
	if (!ctx.cr6.gt) goto loc_82100530;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x821004F4;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8210050c
	if (!ctx.cr6.eq) goto loc_8210050C;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8210050c
	if (ctx.cr6.lt) goto loc_8210050C;
	// lis r30,1
	ctx.r30.s64 = 65536;
loc_8210050C:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x820f42c8
	ctx.lr = 0x82100514;
	sub_820F42C8(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x82100530
	if (!ctx.cr6.gt) goto loc_82100530;
	// divwu r11,r30,r3
	ctx.r11.u32 = ppc_divwu(ctx.r30.u32, ctx.r3.u32);
	// twllei r3,0
	// mullw r10,r11,r3
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// subf r9,r10,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r10.s64;
	// subf r30,r9,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r9.s64;
loc_82100530:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r30,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r30.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r10,72(r9)
	PPC_STORE_U32(ctx.r9.u32 + 72, ctx.r10.u32);
	// lwz r30,80(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r29,0(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x820f3f48
	ctx.lr = 0x82100554;
	sub_820F3F48(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r7,108(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82100570;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821005a4
	if (ctx.cr6.lt) goto loc_821005A4;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// ori r8,r9,16384
	ctx.r8.u64 = ctx.r9.u64 | 16384;
	// add r7,r11,r23
	ctx.r7.u64 = ctx.r11.u64 + ctx.r23.u64;
	// stw r10,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// stw r10,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// sth r8,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// stw r7,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r7.u32);
	// b 0x82100618
	goto loc_82100618;
loc_821005A4:
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821005c8
	if (ctx.cr6.eq) goto loc_821005C8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821005C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r22,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r22.u32);
loc_821005C8:
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821005ec
	if (ctx.cr6.eq) goto loc_821005EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821005E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r22,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r22.u32);
loc_821005EC:
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82100610
	if (ctx.cr6.eq) goto loc_82100610;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x820f3f48
	ctx.lr = 0x82100600;
	sub_820F3F48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f37a8
	ctx.lr = 0x8210060C;
	sub_820F37A8(ctx, base);
	// stw r22,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r22.u32);
loc_82100610:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82100658
	if (ctx.cr6.lt) goto loc_82100658;
loc_82100618:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210062C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82100658
	if (ctx.cr6.eq) goto loc_82100658;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// lwz r31,80(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x82100640;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100658;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82100658:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82100664"))) PPC_WEAK_FUNC(sub_82100664);
PPC_FUNC_IMPL(__imp__sub_82100664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82100668"))) PPC_WEAK_FUNC(sub_82100668);
PPC_FUNC_IMPL(__imp__sub_82100668) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x82100684
	if (!ctx.cr6.eq) goto loc_82100684;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820ff8f0
	sub_820FF8F0(ctx, base);
	return;
loc_82100684:
	// lbz r10,216(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 216);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,216(r11)
	PPC_STORE_U8(ctx.r11.u32 + 216, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82100694"))) PPC_WEAK_FUNC(sub_82100694);
PPC_FUNC_IMPL(__imp__sub_82100694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82100698"))) PPC_WEAK_FUNC(sub_82100698);
PPC_FUNC_IMPL(__imp__sub_82100698) {
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
	// bl 0x820f98d8
	ctx.lr = 0x821006B0;
	sub_820F98D8(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r11,22560
	ctx.r8.s64 = ctx.r11.s64 + 22560;
	// addi r7,r10,22464
	ctx.r7.s64 = ctx.r10.s64 + 22464;
	// addi r6,r9,22556
	ctx.r6.s64 = ctx.r9.s64 + 22556;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r10,r31,108
	ctx.r10.s64 = ctx.r31.s64 + 108;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// addi r11,r31,124
	ctx.r11.s64 = ctx.r31.s64 + 124;
	// stw r31,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r31.u32);
	// stw r31,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r31.u32);
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

__attribute__((alias("__imp__sub_82100720"))) PPC_WEAK_FUNC(sub_82100720);
PPC_FUNC_IMPL(__imp__sub_82100720) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r11,22560
	ctx.r8.s64 = ctx.r11.s64 + 22560;
	// addi r7,r10,22464
	ctx.r7.s64 = ctx.r10.s64 + 22464;
	// addi r6,r9,22556
	ctx.r6.s64 = ctx.r9.s64 + 22556;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// bl 0x820f9db0
	ctx.lr = 0x82100760;
	sub_820F9DB0(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82100774;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821007a0
	if (ctx.cr6.eq) goto loc_821007A0;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// lwz r30,80(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x82100788;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821007A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821007A0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9ed0
	ctx.lr = 0x821007A8;
	sub_820F9ED0(ctx, base);
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

__attribute__((alias("__imp__sub_821007C0"))) PPC_WEAK_FUNC(sub_821007C0);
PPC_FUNC_IMPL(__imp__sub_821007C0) {
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
	// bl 0x820f9210
	ctx.lr = 0x821007D8;
	sub_820F9210(ctx, base);
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bne cr6,0x82100814
	if (!ctx.cr6.eq) goto loc_82100814;
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
	ctx.lr = 0x82100800;
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
loc_82100814:
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x82100850
	if (ctx.cr6.eq) goto loc_82100850;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x82100850
	if (!ctx.cr6.eq) goto loc_82100850;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82100844;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f8f80
	ctx.lr = 0x82100850;
	sub_820F8F80(ctx, base);
loc_82100850:
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

__attribute__((alias("__imp__sub_82100864"))) PPC_WEAK_FUNC(sub_82100864);
PPC_FUNC_IMPL(__imp__sub_82100864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82100868"))) PPC_WEAK_FUNC(sub_82100868);
PPC_FUNC_IMPL(__imp__sub_82100868) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82100870;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821008e4
	if (ctx.cr6.eq) goto loc_821008E4;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// bne cr6,0x821008b8
	if (!ctx.cr6.eq) goto loc_821008B8;
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821008b8
	if (ctx.cr6.eq) goto loc_821008B8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821008B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821008B8:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821008CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,132(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821008E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821008E4:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,8192
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8192, ctx.xer);
	// beq cr6,0x82100930
	if (ctx.cr6.eq) goto loc_82100930;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210090C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82100950
	if (ctx.cr6.lt) goto loc_82100950;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82100924
	if (ctx.cr6.eq) goto loc_82100924;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x820f8a70
	ctx.lr = 0x82100924;
	sub_820F8A70(ctx, base);
loc_82100924:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
loc_82100930:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// ori r10,r11,4096
	ctx.r10.u64 = ctx.r11.u64 | 4096;
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82100950;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82100950:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82100958"))) PPC_WEAK_FUNC(sub_82100958);
PPC_FUNC_IMPL(__imp__sub_82100958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,92(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addic r10,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// subfe r4,r10,r4
	temp.u8 = (~ctx.r10.u32 + ctx.r4.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r10.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// lwz r3,56(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82100984"))) PPC_WEAK_FUNC(sub_82100984);
PPC_FUNC_IMPL(__imp__sub_82100984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82100988"))) PPC_WEAK_FUNC(sub_82100988);
PPC_FUNC_IMPL(__imp__sub_82100988) {
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
	// bl 0x82100720
	ctx.lr = 0x821009A8;
	sub_82100720(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821009c8
	if (ctx.cr6.eq) goto loc_821009C8;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32798
	ctx.r4.u64 = ctx.r4.u64 | 32798;
	// bl 0x820e9410
	ctx.lr = 0x821009C4;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821009C8:
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

__attribute__((alias("__imp__sub_821009E0"))) PPC_WEAK_FUNC(sub_821009E0);
PPC_FUNC_IMPL(__imp__sub_821009E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c960
	ctx.lr = 0x821009E8;
	__savegprlr_18(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// rlwinm r11,r4,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// stb r5,311(r1)
	PPC_STORE_U8(ctx.r1.u32 + 311, ctx.r5.u8);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// rlwimi r10,r11,2,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 2) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// li r4,1
	ctx.r4.s64 = 1;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r9,r9,0,18,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFBFFF;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// sth r9,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, ctx.r9.u16);
	// mr r20,r7
	ctx.r20.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// bl 0x820f9a50
	ctx.lr = 0x82100A24;
	sub_820F9A50(ctx, base);
	// addic r8,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r8.s64 = ctx.r29.s64 + -1;
	// lbz r10,311(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// lis r12,0
	ctx.r12.s64 = 0;
	// subfe r6,r8,r29
	temp.u8 = (~ctx.r8.u32 + ctx.r29.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addic r5,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// subfe r4,r5,r10
	temp.u8 = (~ctx.r5.u32 + ctx.r10.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r10,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r10.u8);
	// ori r12,r12,63423
	ctx.r12.u64 = ctx.r12.u64 | 63423;
	// rlwimi r4,r6,5,26,26
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r6.u32, 5) & 0x20) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFDF);
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwinm r3,r4,6,20,25
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFC0;
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
	// rlwinm r3,r3,0,25,20
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFF87F;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// and r9,r10,r12
	ctx.r9.u64 = ctx.r10.u64 & ctx.r12.u64;
	// or r8,r3,r9
	ctx.r8.u64 = ctx.r3.u64 | ctx.r9.u64;
	// sth r8,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// beq cr6,0x82100acc
	if (ctx.cr6.eq) goto loc_82100ACC;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r7,32(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// lwz r24,64(r8)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// lhz r4,1(r7)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + 1);
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82100ab4
	if (ctx.cr6.eq) goto loc_82100AB4;
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100AB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82100ab8
	goto loc_82100AB8;
loc_82100AB4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82100AB8:
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// subfe r9,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r9,2,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 2) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
loc_82100ACC:
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r7,r1,311
	ctx.r7.s64 = ctx.r1.s64 + 311;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f94a8
	ctx.lr = 0x82100AE8;
	sub_820F94A8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82100fb8
	if (ctx.cr6.lt) goto loc_82100FB8;
	// addi r23,r31,24
	ctx.r23.s64 = ctx.r31.s64 + 24;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820f4640
	ctx.lr = 0x82100B04;
	sub_820F4640(ctx, base);
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82100B1C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82100b1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82100B1C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r28,80(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x82100B30;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100B4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r22,r11
	ctx.r22.u64 = ctx.r11.u64;
	// mr r19,r10
	ctx.r19.u64 = ctx.r10.u64;
	// add r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r21,112(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r26,116(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x820f3ed8
	ctx.lr = 0x82100B70;
	sub_820F3ED8(ctx, base);
	// li r18,1
	ctx.r18.s64 = 1;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x82100b9c
	if (ctx.cr6.eq) goto loc_82100B9C;
	// lbz r10,311(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82100b9c
	if (ctx.cr6.eq) goto loc_82100B9C;
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// ble cr6,0x82100b9c
	if (!ctx.cr6.gt) goto loc_82100B9C;
	// cmplw cr6,r30,r25
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r25.u32, ctx.xer);
	// mr r27,r18
	ctx.r27.u64 = ctx.r18.u64;
	// blt cr6,0x82100ba0
	if (ctx.cr6.lt) goto loc_82100BA0;
loc_82100B9C:
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
loc_82100BA0:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f0,14004(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// beq cr6,0x82100bf8
	if (ctx.cr6.eq) goto loc_82100BF8;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,20(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r6,16
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 16, ctx.xer);
	// bne cr6,0x82100bf8
	if (!ctx.cr6.eq) goto loc_82100BF8;
	// lwz r9,16(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// mr r10,r18
	ctx.r10.u64 = ctx.r18.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lfs f0,124(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_82100BF8:
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cntlzw r8,r27
	ctx.r8.u64 = ctx.r27.u32 == 0 ? 32 : __builtin_clz(ctx.r27.u32);
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// lhz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// rlwinm r6,r7,30,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x1;
	// xori r11,r4,1
	ctx.r11.u64 = ctx.r4.u64 ^ 1;
	// lwz r3,36(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82100C40;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82100fb8
	if (ctx.cr6.lt) goto loc_82100FB8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x820f8f80
	ctx.lr = 0x82100C54;
	sub_820F8F80(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x82100C5C;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82100ca8
	if (!ctx.cr6.eq) goto loc_82100CA8;
	// lbz r11,311(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// bne cr6,0x82100c84
	if (!ctx.cr6.eq) goto loc_82100C84;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
loc_82100C84:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// ble cr6,0x82100c98
	if (!ctx.cr6.gt) goto loc_82100C98;
	// clrlwi r10,r11,25
	ctx.r10.u64 = ctx.r11.u32 & 0x7F;
	// subf r29,r10,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r10.s64;
loc_82100C98:
	// stw r29,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82100eb8
	goto loc_82100EB8;
loc_82100CA8:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// bl 0x820f4258
	ctx.lr = 0x82100CB4;
	sub_820F4258(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x82100CC0;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x82100ce4
	if (!ctx.cr6.eq) goto loc_82100CE4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820f3f28
	ctx.lr = 0x82100CD0;
	sub_820F3F28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82100ce4
	if (ctx.cr6.eq) goto loc_82100CE4;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820f3f28
	ctx.lr = 0x82100CE0;
	sub_820F3F28(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_82100CE4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82100dd8
	if (ctx.cr6.eq) goto loc_82100DD8;
	// subf r11,r26,r25
	ctx.r11.s64 = ctx.r25.s64 - ctx.r26.s64;
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// lwz r6,120(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// addi r30,r31,108
	ctx.r30.s64 = ctx.r31.s64 + 108;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// stw r4,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r4.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// stw r29,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r29.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100D58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82100fb8
	if (ctx.cr6.lt) goto loc_82100FB8;
	// lbz r11,311(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// add r10,r22,r21
	ctx.r10.u64 = ctx.r22.u64 + ctx.r21.u64;
	// subf r9,r22,r26
	ctx.r9.s64 = ctx.r26.s64 - ctx.r22.s64;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// beq cr6,0x82100d80
	if (ctx.cr6.eq) goto loc_82100D80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_82100D80:
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// stw r19,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// bl 0x820f3ec0
	ctx.lr = 0x82100D98;
	sub_820F3EC0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r3,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r3.u32);
	// addi r11,r31,124
	ctx.r11.s64 = ctx.r31.s64 + 124;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r9,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r9.u32);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r3,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// stw r18,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r18.u32);
	// b 0x82100ec8
	goto loc_82100EC8;
loc_82100DD8:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x820f3ed8
	ctx.lr = 0x82100DE0;
	sub_820F3ED8(ctx, base);
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x82100e04
	if (!ctx.cr6.eq) goto loc_82100E04;
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lbz r9,311(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// stw r22,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r22.u32);
	// stw r19,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r11.u32);
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// b 0x82100eb0
	goto loc_82100EB0;
loc_82100E04:
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// subf r11,r30,r22
	ctx.r11.s64 = ctx.r22.s64 - ctx.r30.s64;
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// add r8,r10,r30
	ctx.r8.u64 = ctx.r10.u64 + ctx.r30.u64;
	// subf r7,r30,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r30.s64;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// bgt cr6,0x82100e7c
	if (ctx.cr6.gt) goto loc_82100E7C;
	// lbz r10,311(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 311);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// bne cr6,0x82100e48
	if (!ctx.cr6.eq) goto loc_82100E48;
loc_82100E3C:
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82100e54
	if (ctx.cr6.eq) goto loc_82100E54;
loc_82100E48:
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// stw r19,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r19.u32);
	// ble cr6,0x82100e58
	if (!ctx.cr6.gt) goto loc_82100E58;
loc_82100E54:
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
loc_82100E58:
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82100e88
	if (ctx.cr6.eq) goto loc_82100E88;
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// bgt cr6,0x82100e88
	if (ctx.cr6.gt) goto loc_82100E88;
	// lwz r9,132(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// b 0x82100e8c
	goto loc_82100E8C;
loc_82100E7C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// b 0x82100e3c
	goto loc_82100E3C;
loc_82100E88:
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
loc_82100E8C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82100eac
	if (ctx.cr6.eq) goto loc_82100EAC;
	// cmplw cr6,r30,r22
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r22.u32, ctx.xer);
	// bgt cr6,0x82100eac
	if (ctx.cr6.gt) goto loc_82100EAC;
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// stw r9,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// b 0x82100eb0
	goto loc_82100EB0;
loc_82100EAC:
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
loc_82100EB0:
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
loc_82100EB8:
	// addi r11,r31,108
	ctx.r11.s64 = ctx.r31.s64 + 108;
	// stw r18,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r18.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
loc_82100EC8:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82100EE4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82100fb4
	if (ctx.cr6.lt) goto loc_82100FB4;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// ori r10,r11,16384
	ctx.r10.u64 = ctx.r11.u64 | 16384;
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82100F10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82100f3c
	if (ctx.cr6.eq) goto loc_82100F3C;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lwz r29,80(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x820f3f48
	ctx.lr = 0x82100F24;
	sub_820F3F48(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100F3C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82100F3C:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9a50
	ctx.lr = 0x82100F48;
	sub_820F9A50(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x82100F54;
	sub_820F9380(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82100fb4
	if (ctx.cr6.eq) goto loc_82100FB4;
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82100fb4
	if (ctx.cr6.eq) goto loc_82100FB4;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r28,0(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x820fa2a8
	ctx.lr = 0x82100F7C;
	sub_820FA2A8(ctx, base);
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100F8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x820fa2f0
	ctx.lr = 0x82100FA4;
	sub_820FA2F0(ctx, base);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82100FB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82100FB4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82100FB8:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9b0
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82100FC0"))) PPC_WEAK_FUNC(sub_82100FC0);
PPC_FUNC_IMPL(__imp__sub_82100FC0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82100FEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101010
	if (ctx.cr6.eq) goto loc_82101010;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101008;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820f8e00
	ctx.lr = 0x82101010;
	sub_820F8E00(ctx, base);
loc_82101010:
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

__attribute__((alias("__imp__sub_82101028"))) PPC_WEAK_FUNC(sub_82101028);
PPC_FUNC_IMPL(__imp__sub_82101028) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101054;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101078
	if (ctx.cr6.eq) goto loc_82101078;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101070;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820f8e48
	ctx.lr = 0x82101078;
	sub_820F8E48(ctx, base);
loc_82101078:
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

__attribute__((alias("__imp__sub_82101090"))) PPC_WEAK_FUNC(sub_82101090);
PPC_FUNC_IMPL(__imp__sub_82101090) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821010BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821010e0
	if (ctx.cr6.eq) goto loc_821010E0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821010D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820f8ed0
	ctx.lr = 0x821010E0;
	sub_820F8ED0(ctx, base);
loc_821010E0:
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

__attribute__((alias("__imp__sub_821010F8"))) PPC_WEAK_FUNC(sub_821010F8);
PPC_FUNC_IMPL(__imp__sub_821010F8) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101124;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101148
	if (ctx.cr6.eq) goto loc_82101148;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101140;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820f8ef0
	ctx.lr = 0x82101148;
	sub_820F8EF0(ctx, base);
loc_82101148:
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

__attribute__((alias("__imp__sub_82101160"))) PPC_WEAK_FUNC(sub_82101160);
PPC_FUNC_IMPL(__imp__sub_82101160) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82101168;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101190;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821011d4
	if (ctx.cr6.eq) goto loc_821011D4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821011AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821011CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821011D4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821011E0"))) PPC_WEAK_FUNC(sub_821011E0);
PPC_FUNC_IMPL(__imp__sub_821011E0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210120C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101244
	if (ctx.cr6.eq) goto loc_82101244;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101228;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82101240;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82101248
	goto loc_82101248;
loc_82101244:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82101248:
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

__attribute__((alias("__imp__sub_82101260"))) PPC_WEAK_FUNC(sub_82101260);
PPC_FUNC_IMPL(__imp__sub_82101260) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82101268;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210128C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8210134c
	if (ctx.cr6.eq) goto loc_8210134C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821012A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8210134c
	if (ctx.cr6.eq) goto loc_8210134C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821012C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,164(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821012E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r6,160(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821012F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lwz r4,152(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 152);
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82101310;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101328;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8210134C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8210134C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8210135C"))) PPC_WEAK_FUNC(sub_8210135C);
PPC_FUNC_IMPL(__imp__sub_8210135C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101360"))) PPC_WEAK_FUNC(sub_82101360);
PPC_FUNC_IMPL(__imp__sub_82101360) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82101368;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// li r26,0
	ctx.r26.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101394;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821013cc
	if (ctx.cr6.eq) goto loc_821013CC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821013B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// bl 0x820f98b0
	ctx.lr = 0x821013C4;
	sub_820F98B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_821013CC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821013D8"))) PPC_WEAK_FUNC(sub_821013D8);
PPC_FUNC_IMPL(__imp__sub_821013D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// lbz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// subfe r9,r11,r4
	temp.u8 = (~ctx.r11.u32 + ctx.r4.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r10,r9,5,26,26
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821013F0"))) PPC_WEAK_FUNC(sub_821013F0);
PPC_FUNC_IMPL(__imp__sub_821013F0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821013FC"))) PPC_WEAK_FUNC(sub_821013FC);
PPC_FUNC_IMPL(__imp__sub_821013FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101400"))) PPC_WEAK_FUNC(sub_82101400);
PPC_FUNC_IMPL(__imp__sub_82101400) {
	PPC_FUNC_PROLOGUE();
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,6
	ctx.r3.u64 = ctx.r3.u64 | 6;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210140C"))) PPC_WEAK_FUNC(sub_8210140C);
PPC_FUNC_IMPL(__imp__sub_8210140C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101410"))) PPC_WEAK_FUNC(sub_82101410);
PPC_FUNC_IMPL(__imp__sub_82101410) {
	PPC_FUNC_PROLOGUE();
	// stw r4,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101418"))) PPC_WEAK_FUNC(sub_82101418);
PPC_FUNC_IMPL(__imp__sub_82101418) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,60(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101420"))) PPC_WEAK_FUNC(sub_82101420);
PPC_FUNC_IMPL(__imp__sub_82101420) {
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
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82102340
	ctx.lr = 0x82101444;
	sub_82102340(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,22768
	ctx.r9.s64 = ctx.r10.s64 + 22768;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lbz r7,11(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 11);
	// stb r7,52(r31)
	PPC_STORE_U8(ctx.r31.u32 + 52, ctx.r7.u8);
	// stw r30,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82101490"))) PPC_WEAK_FUNC(sub_82101490);
PPC_FUNC_IMPL(__imp__sub_82101490) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 52);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101498"))) PPC_WEAK_FUNC(sub_82101498);
PPC_FUNC_IMPL(__imp__sub_82101498) {
	PPC_FUNC_PROLOGUE();
	// stw r4,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821014A0"))) PPC_WEAK_FUNC(sub_821014A0);
PPC_FUNC_IMPL(__imp__sub_821014A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,64(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821014A8"))) PPC_WEAK_FUNC(sub_821014A8);
PPC_FUNC_IMPL(__imp__sub_821014A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821014B0"))) PPC_WEAK_FUNC(sub_821014B0);
PPC_FUNC_IMPL(__imp__sub_821014B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// lfd f0,22936(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 22936);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821014D8"))) PPC_WEAK_FUNC(sub_821014D8);
PPC_FUNC_IMPL(__imp__sub_821014D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r8,14(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 14);
	// lfd f0,22936(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 22936);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fmul f11,f12,f0
	ctx.f11.f64 = ctx.f12.f64 * ctx.f0.f64;
	// frsp f1,f11
	ctx.f1.f64 = double(float(ctx.f11.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101500"))) PPC_WEAK_FUNC(sub_82101500);
PPC_FUNC_IMPL(__imp__sub_82101500) {
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
	// bl 0x821021b0
	ctx.lr = 0x82101518;
	sub_821021B0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210152C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101568
	if (ctx.cr6.eq) goto loc_82101568;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101548;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82101568;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82101568:
	// bl 0x820e6990
	ctx.lr = 0x8210156C;
	sub_820E6990(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82101584"))) PPC_WEAK_FUNC(sub_82101584);
PPC_FUNC_IMPL(__imp__sub_82101584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101588"))) PPC_WEAK_FUNC(sub_82101588);
PPC_FUNC_IMPL(__imp__sub_82101588) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82101590;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x821015ac
	if (!ctx.cr6.eq) goto loc_821015AC;
	// bl 0x820e6990
	ctx.lr = 0x821015A8;
	sub_820E6990(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
loc_821015AC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821015C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101664
	if (ctx.cr6.eq) goto loc_82101664;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// li r30,1
	ctx.r30.s64 = 1;
	// lbz r10,7(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 7);
	// clrlwi r29,r10,31
	ctx.r29.u64 = ctx.r10.u32 & 0x1;
	// bne cr6,0x82101624
	if (!ctx.cr6.eq) goto loc_82101624;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82101610
	if (ctx.cr6.eq) goto loc_82101610;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101600;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82101628
	if (!ctx.cr6.eq) goto loc_82101628;
loc_82101610:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x820fa600
	ctx.lr = 0x8210161C;
	sub_820FA600(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82101628
	if (!ctx.cr6.eq) goto loc_82101628;
loc_82101624:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82101628:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210163C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8210165C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82101664:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82101670"))) PPC_WEAK_FUNC(sub_82101670);
PPC_FUNC_IMPL(__imp__sub_82101670) {
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
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101694;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821016c0
	if (ctx.cr6.eq) goto loc_821016C0;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821016B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bge cr6,0x821016c4
	if (!ctx.cr6.lt) goto loc_821016C4;
loc_821016C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821016C4:
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

__attribute__((alias("__imp__sub_821016D8"))) PPC_WEAK_FUNC(sub_821016D8);
PPC_FUNC_IMPL(__imp__sub_821016D8) {
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
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821016FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101748
	if (ctx.cr6.eq) goto loc_82101748;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101718;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// blt cr6,0x82101748
	if (ctx.cr6.lt) goto loc_82101748;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101738;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,84(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r9,5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 5, ctx.xer);
	// ble cr6,0x8210174c
	if (!ctx.cr6.gt) goto loc_8210174C;
loc_82101748:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8210174C:
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

__attribute__((alias("__imp__sub_82101760"))) PPC_WEAK_FUNC(sub_82101760);
PPC_FUNC_IMPL(__imp__sub_82101760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// lbz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// lwz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// subfe r8,r11,r4
	temp.u8 = (~ctx.r11.u32 + ctx.r4.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r11.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwimi r9,r8,5,26,26
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 5) & 0x20) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFDF);
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// beq cr6,0x82101798
	if (ctx.cr6.eq) goto loc_82101798;
	// lhz r10,76(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 76);
	// rlwinm r9,r10,0,17,17
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8210179c
	if (!ctx.cr6.eq) goto loc_8210179C;
loc_82101798:
	// li r10,1
	ctx.r10.s64 = 1;
loc_8210179C:
	// addic r9,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// subfe r8,r9,r10
	temp.u8 = (~ctx.r9.u32 + ctx.r10.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r11,r8,6,25,25
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0x40) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821017B0"))) PPC_WEAK_FUNC(sub_821017B0);
PPC_FUNC_IMPL(__imp__sub_821017B0) {
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
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821017D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,132(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821017EC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82101808
	if (ctx.cr6.eq) goto loc_82101808;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x820f70c8
	ctx.lr = 0x82101808;
	sub_820F70C8(ctx, base);
loc_82101808:
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

__attribute__((alias("__imp__sub_8210181C"))) PPC_WEAK_FUNC(sub_8210181C);
PPC_FUNC_IMPL(__imp__sub_8210181C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101820"))) PPC_WEAK_FUNC(sub_82101820);
PPC_FUNC_IMPL(__imp__sub_82101820) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82101828;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820e6990
	ctx.lr = 0x82101834;
	sub_820E6990(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8210184C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r27,20(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r29,0(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8210186C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,28(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82101880;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r11,r3,r27
	ctx.r11.u64 = ctx.r3.u64 + ctx.r27.u64;
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x821018c8
	if (!ctx.cr6.lt) goto loc_821018C8;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821018A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,20(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821018B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// subf r7,r30,r31
	ctx.r7.s64 = ctx.r31.s64 - ctx.r30.s64;
	// add r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 + ctx.r7.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821018C8:
	// subf r3,r30,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r30.s64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821018D4"))) PPC_WEAK_FUNC(sub_821018D4);
PPC_FUNC_IMPL(__imp__sub_821018D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821018D8"))) PPC_WEAK_FUNC(sub_821018D8);
PPC_FUNC_IMPL(__imp__sub_821018D8) {
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
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821018FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101924
	if (ctx.cr6.eq) goto loc_82101924;
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// bl 0x820f3f18
	ctx.lr = 0x8210190C;
	sub_820F3F18(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
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
loc_82101924:
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

__attribute__((alias("__imp__sub_8210193C"))) PPC_WEAK_FUNC(sub_8210193C);
PPC_FUNC_IMPL(__imp__sub_8210193C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101940"))) PPC_WEAK_FUNC(sub_82101940);
PPC_FUNC_IMPL(__imp__sub_82101940) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,22616
	ctx.r10.s64 = ctx.r11.s64 + 22616;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x82101cc0
	ctx.lr = 0x8210196C;
	sub_82101CC0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8210198c
	if (ctx.cr6.eq) goto loc_8210198C;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32878
	ctx.r4.u64 = ctx.r4.u64 | 32878;
	// bl 0x820e9410
	ctx.lr = 0x82101988;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8210198C:
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

__attribute__((alias("__imp__sub_821019A4"))) PPC_WEAK_FUNC(sub_821019A4);
PPC_FUNC_IMPL(__imp__sub_821019A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821019A8"))) PPC_WEAK_FUNC(sub_821019A8);
PPC_FUNC_IMPL(__imp__sub_821019A8) {
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
	// lwz r3,60(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,22768
	ctx.r10.s64 = ctx.r11.s64 + 22768;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x821019f0
	if (ctx.cr6.eq) goto loc_821019F0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821019F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821019F0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,22616
	ctx.r10.s64 = ctx.r11.s64 + 22616;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82101cc0
	ctx.lr = 0x82101A04;
	sub_82101CC0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82101a24
	if (ctx.cr6.eq) goto loc_82101A24;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// bl 0x820e9410
	ctx.lr = 0x82101A20;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82101A24:
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

__attribute__((alias("__imp__sub_82101A3C"))) PPC_WEAK_FUNC(sub_82101A3C);
PPC_FUNC_IMPL(__imp__sub_82101A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101A40"))) PPC_WEAK_FUNC(sub_82101A40);
PPC_FUNC_IMPL(__imp__sub_82101A40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82101A48;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,27,8,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0xFFFFFF;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bgt cr6,0x82101a78
	if (ctx.cr6.gt) goto loc_82101A78;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// subf r27,r11,r4
	ctx.r27.s64 = ctx.r4.s64 - ctx.r11.s64;
	// b 0x82101a80
	goto loc_82101A80;
loc_82101A78:
	// stw r4,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
loc_82101A80:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r4,10(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r3,308(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 308);
	// bl 0x820ef3b0
	ctx.lr = 0x82101A9C;
	sub_820EF3B0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82101ab4
	if (!ctx.cr6.eq) goto loc_82101AB4;
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// ori r30,r30,19
	ctx.r30.u64 = ctx.r30.u64 | 19;
	// b 0x82101ac8
	goto loc_82101AC8;
loc_82101AB4:
	// lwz r11,256(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 256);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82101ac8
	if (!ctx.cr6.eq) goto loc_82101AC8;
	// lis r30,-30009
	ctx.r30.s64 = -1966669824;
	// ori r30,r30,22
	ctx.r30.u64 = ctx.r30.u64 | 22;
loc_82101AC8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// blt cr6,0x82101bbc
	if (ctx.cr6.lt) goto loc_82101BBC;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82101af0
	if (ctx.cr6.eq) goto loc_82101AF0;
	// lhz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r29,r11,31
	ctx.r29.u64 = ctx.r11.u32 & 0x1;
loc_82101AF0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// lhz r26,8(r10)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82101B10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,80(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// bctrl 
	ctx.lr = 0x82101B4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82101bbc
	if (ctx.cr6.lt) goto loc_82101BBC;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82101B70;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82101bbc
	if (ctx.cr6.eq) goto loc_82101BBC;
	// lhz r10,5(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 5);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82101bbc
	if (ctx.cr6.eq) goto loc_82101BBC;
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lfs f2,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f1,64(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r8,5(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 5);
	// rlwinm r4,r8,31,30,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x3;
	// lwz r7,40(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82101BBC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82101BBC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82101BC8"))) PPC_WEAK_FUNC(sub_82101BC8);
PPC_FUNC_IMPL(__imp__sub_82101BC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82101BD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lbz r4,10(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r3,308(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 308);
	// bl 0x820ef3b0
	ctx.lr = 0x82101BFC;
	sub_820EF3B0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101c5c
	if (ctx.cr6.eq) goto loc_82101C5C;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lbz r10,11(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 11);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// bne cr6,0x82101c28
	if (!ctx.cr6.eq) goto loc_82101C28;
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82101C28:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820be318
	ctx.lr = 0x82101C30;
	sub_820BE318(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// bl 0x820f3e28
	ctx.lr = 0x82101C44;
	sub_820F3E28(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r4,11(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 11);
	// bl 0x820f41e8
	ctx.lr = 0x82101C54;
	sub_820F41E8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82101C5C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82101C68"))) PPC_WEAK_FUNC(sub_82101C68);
PPC_FUNC_IMPL(__imp__sub_82101C68) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// bne cr6,0x82101c84
	if (!ctx.cr6.eq) goto loc_82101C84;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// blr 
	return;
loc_82101C84:
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101C98"))) PPC_WEAK_FUNC(sub_82101C98);
PPC_FUNC_IMPL(__imp__sub_82101C98) {
	PPC_FUNC_PROLOGUE();
	// lbz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stb r9,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101CBC"))) PPC_WEAK_FUNC(sub_82101CBC);
PPC_FUNC_IMPL(__imp__sub_82101CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82101CC0"))) PPC_WEAK_FUNC(sub_82101CC0);
PPC_FUNC_IMPL(__imp__sub_82101CC0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,16136
	ctx.r10.s64 = ctx.r11.s64 + 16136;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82101CD0"))) PPC_WEAK_FUNC(sub_82101CD0);
PPC_FUNC_IMPL(__imp__sub_82101CD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82101CD8;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 20, ctx.xer);
	// bgt cr6,0x8210219c
	if (ctx.cr6.gt) goto loc_8210219C;
	// lis r12,-32240
	ctx.r12.s64 = -2112880640;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,7448
	ctx.r12.s64 = ctx.r12.s64 + 7448;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u64) {
	case 0:
		goto loc_82101D6C;
	case 1:
		goto loc_82101DCC;
	case 2:
		goto loc_82101E08;
	case 3:
		goto loc_82101E44;
	case 4:
		goto loc_82101DCC;
	case 5:
		goto loc_82101E08;
	case 6:
		goto loc_82101E44;
	case 7:
		goto loc_82101FA0;
	case 8:
		goto loc_82101FDC;
	case 9:
		goto loc_82102018;
	case 10:
		goto loc_82101EB4;
	case 11:
		goto loc_82101EF0;
	case 12:
		goto loc_82101F2C;
	case 13:
		goto loc_82101F64;
	case 14:
		goto loc_82102064;
	case 15:
		goto loc_8210209C;
	case 16:
		goto loc_821020D8;
	case 17:
		goto loc_82102114;
	case 18:
		goto loc_82102150;
	case 19:
		goto loc_82101E7C;
	case 20:
		goto loc_82101DAC;
	default:
		__builtin_unreachable();
	}
	// lwz r16,7532(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7532);
	// lwz r16,7628(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7628);
	// lwz r16,7688(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7688);
	// lwz r16,7748(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7748);
	// lwz r16,7628(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7628);
	// lwz r16,7688(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7688);
	// lwz r16,7748(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7748);
	// lwz r16,8096(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8096);
	// lwz r16,8156(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8156);
	// lwz r16,8216(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8216);
	// lwz r16,7860(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7860);
	// lwz r16,7920(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7920);
	// lwz r16,7980(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7980);
	// lwz r16,8036(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8036);
	// lwz r16,8292(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8292);
	// lwz r16,8348(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8348);
	// lwz r16,8408(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8408);
	// lwz r16,8468(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8468);
	// lwz r16,8528(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 8528);
	// lwz r16,7804(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7804);
	// lwz r16,7596(r16)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r16.u32 + 7596);
loc_82101D6C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32791
	ctx.r4.u64 = ctx.r4.u64 | 32791;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x820e9408
	ctx.lr = 0x82101D84;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82105dc8
	ctx.lr = 0x82101DA0;
	sub_82105DC8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101DA4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82101DA8:
	// stw r3,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
loc_82101DAC:
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// ori r7,r10,14
	ctx.r7.u64 = ctx.r10.u64 | 14;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 & ctx.r7.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82101DCC:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x820e9408
	ctx.lr = 0x82101DE4;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82101420
	ctx.lr = 0x82101E04;
	sub_82101420(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101E08:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32785
	ctx.r4.u64 = ctx.r4.u64 | 32785;
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x820e9408
	ctx.lr = 0x82101E20;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82101420
	ctx.lr = 0x82101E40;
	sub_82101420(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101E44:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32786
	ctx.r4.u64 = ctx.r4.u64 | 32786;
	// li r3,188
	ctx.r3.s64 = 188;
	// bl 0x820e9408
	ctx.lr = 0x82101E5C;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821057a8
	ctx.lr = 0x82101E78;
	sub_821057A8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101E7C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32784
	ctx.r4.u64 = ctx.r4.u64 | 32784;
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x820e9408
	ctx.lr = 0x82101E94;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82104c80
	ctx.lr = 0x82101EB0;
	sub_82104C80(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101EB4:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32782
	ctx.r4.u64 = ctx.r4.u64 | 32782;
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x820e9408
	ctx.lr = 0x82101ECC;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82102a60
	ctx.lr = 0x82101EEC;
	sub_82102A60(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101EF0:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32782
	ctx.r4.u64 = ctx.r4.u64 | 32782;
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x820e9408
	ctx.lr = 0x82101F08;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82102a60
	ctx.lr = 0x82101F28;
	sub_82102A60(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101F2C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32792
	ctx.r4.u64 = ctx.r4.u64 | 32792;
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x820e9408
	ctx.lr = 0x82101F44;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82104b90
	ctx.lr = 0x82101F60;
	sub_82104B90(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101F64:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32789
	ctx.r4.u64 = ctx.r4.u64 | 32789;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x820e9408
	ctx.lr = 0x82101F7C;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82104798
	ctx.lr = 0x82101F9C;
	sub_82104798(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101FA0:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32788
	ctx.r4.u64 = ctx.r4.u64 | 32788;
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x820e9408
	ctx.lr = 0x82101FB8;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821042e8
	ctx.lr = 0x82101FD8;
	sub_821042E8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82101FDC:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32790
	ctx.r4.u64 = ctx.r4.u64 | 32790;
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x820e9408
	ctx.lr = 0x82101FF4;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82103da8
	ctx.lr = 0x82102014;
	sub_82103DA8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82102018:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32783
	ctx.r4.u64 = ctx.r4.u64 | 32783;
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x820e9408
	ctx.lr = 0x82102030;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82103a90
	ctx.lr = 0x82102060;
	sub_82103A90(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82102064:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32787
	ctx.r4.u64 = ctx.r4.u64 | 32787;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x820e9408
	ctx.lr = 0x8210207C;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821039e8
	ctx.lr = 0x82102098;
	sub_821039E8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_8210209C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32789
	ctx.r4.u64 = ctx.r4.u64 | 32789;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x820e9408
	ctx.lr = 0x821020B4;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// addi r8,r31,18
	ctx.r8.s64 = ctx.r31.s64 + 18;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82104798
	ctx.lr = 0x821020D4;
	sub_82104798(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_821020D8:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32788
	ctx.r4.u64 = ctx.r4.u64 | 32788;
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x820e9408
	ctx.lr = 0x821020F0;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// addi r8,r31,22
	ctx.r8.s64 = ctx.r31.s64 + 22;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821042e8
	ctx.lr = 0x82102110;
	sub_821042E8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82102114:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32790
	ctx.r4.u64 = ctx.r4.u64 | 32790;
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x820e9408
	ctx.lr = 0x8210212C;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// addi r8,r31,22
	ctx.r8.s64 = ctx.r31.s64 + 22;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82103da8
	ctx.lr = 0x8210214C;
	sub_82103DA8(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_82102150:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32783
	ctx.r4.u64 = ctx.r4.u64 | 32783;
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x820e9408
	ctx.lr = 0x82102168;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82101da4
	if (ctx.cr6.eq) goto loc_82101DA4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r31,11
	ctx.r9.s64 = ctx.r31.s64 + 11;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82103a90
	ctx.lr = 0x82102198;
	sub_82103A90(ctx, base);
	// b 0x82101da8
	goto loc_82101DA8;
loc_8210219C:
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,17
	ctx.r3.u64 = ctx.r3.u64 | 17;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821021AC"))) PPC_WEAK_FUNC(sub_821021AC);
PPC_FUNC_IMPL(__imp__sub_821021AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821021B0"))) PPC_WEAK_FUNC(sub_821021B0);
PPC_FUNC_IMPL(__imp__sub_821021B0) {
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
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// beq cr6,0x821021fc
	if (ctx.cr6.eq) goto loc_821021FC;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// stb r10,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r10.u8);
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// beq cr6,0x821021fc
	if (ctx.cr6.eq) goto loc_821021FC;
	// lwz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lbz r11,45(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 45);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stb r9,45(r10)
	PPC_STORE_U8(ctx.r10.u32 + 45, ctx.r9.u8);
loc_821021FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82102214;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// rlwinm r8,r9,0,28,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// beq cr6,0x82102234
	if (ctx.cr6.eq) goto loc_82102234;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r11,44(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 44);
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,44(r10)
	PPC_STORE_U8(ctx.r10.u32 + 44, ctx.r9.u8);
loc_82102234:
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

__attribute__((alias("__imp__sub_82102248"))) PPC_WEAK_FUNC(sub_82102248);
PPC_FUNC_IMPL(__imp__sub_82102248) {
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
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x8210228c
	if (!ctx.cr6.eq) goto loc_8210228C;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// bl 0x820f67c8
	ctx.lr = 0x82102278;
	sub_820F67C8(ctx, base);
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
loc_8210228C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// ori r9,r11,64
	ctx.r9.u64 = ctx.r11.u64 | 64;
	// stb r9,40(r31)
	PPC_STORE_U8(ctx.r31.u32 + 40, ctx.r9.u8);
	// lbz r11,45(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 45);
	// addi r8,r11,255
	ctx.r8.s64 = ctx.r11.s64 + 255;
	// stb r8,45(r10)
	PPC_STORE_U8(ctx.r10.u32 + 45, ctx.r8.u8);
	// bl 0x820e6990
	ctx.lr = 0x821022AC;
	sub_820E6990(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x820f5f48
	ctx.lr = 0x821022B8;
	sub_820F5F48(ctx, base);
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

__attribute__((alias("__imp__sub_821022CC"))) PPC_WEAK_FUNC(sub_821022CC);
PPC_FUNC_IMPL(__imp__sub_821022CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821022D0"))) PPC_WEAK_FUNC(sub_821022D0);
PPC_FUNC_IMPL(__imp__sub_821022D0) {
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
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x820fab90
	ctx.lr = 0x821022F8;
	sub_820FAB90(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82102320
	if (!ctx.cr6.eq) goto loc_82102320;
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x820f7d28
	ctx.lr = 0x82102314;
	sub_820F7D28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x82102324
	if (ctx.cr6.eq) goto loc_82102324;
loc_82102320:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82102324:
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

__attribute__((alias("__imp__sub_8210233C"))) PPC_WEAK_FUNC(sub_8210233C);
PPC_FUNC_IMPL(__imp__sub_8210233C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82102340"))) PPC_WEAK_FUNC(sub_82102340);
PPC_FUNC_IMPL(__imp__sub_82102340) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r11.s64 = ctx.r8.s64 + -1;
	// stw r7,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r7.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// subfe r9,r11,r8
	temp.u8 = (~ctx.r11.u32 + ctx.r8.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// addi r8,r10,23992
	ctx.r8.s64 = ctx.r10.s64 + 23992;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// rlwinm r7,r9,3,28,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x8;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stb r7,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8210238C"))) PPC_WEAK_FUNC(sub_8210238C);
PPC_FUNC_IMPL(__imp__sub_8210238C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82102390"))) PPC_WEAK_FUNC(sub_82102390);
PPC_FUNC_IMPL(__imp__sub_82102390) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,16136
	ctx.r9.s64 = ctx.r11.s64 + 16136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x821023cc
	if (ctx.cr6.eq) goto loc_821023CC;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32873
	ctx.r4.u64 = ctx.r4.u64 | 32873;
	// bl 0x820e9410
	ctx.lr = 0x821023C8;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821023CC:
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

__attribute__((alias("__imp__sub_821023E0"))) PPC_WEAK_FUNC(sub_821023E0);
PPC_FUNC_IMPL(__imp__sub_821023E0) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82102428;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 40);
	// rlwinm r5,r11,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r5,8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 8, ctx.xer);
	// bne cr6,0x82102458
	if (!ctx.cr6.eq) goto loc_82102458;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x820f67c8
	ctx.lr = 0x82102444;
	sub_820F67C8(ctx, base);
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
loc_82102458:
	// rlwinm r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,128
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 128, ctx.xer);
	// bne cr6,0x82102474
	if (!ctx.cr6.eq) goto loc_82102474;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r11,45(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 45);
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,45(r10)
	PPC_STORE_U8(ctx.r10.u32 + 45, ctx.r9.u8);
loc_82102474:
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lbz r11,44(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 44);
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,44(r10)
	PPC_STORE_U8(ctx.r10.u32 + 44, ctx.r9.u8);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x820f5f48
	ctx.lr = 0x8210248C;
	sub_820F5F48(ctx, base);
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

__attribute__((alias("__imp__sub_821024A0"))) PPC_WEAK_FUNC(sub_821024A0);
PPC_FUNC_IMPL(__imp__sub_821024A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r3,r10,27,8,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xFFFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821024B0"))) PPC_WEAK_FUNC(sub_821024B0);
PPC_FUNC_IMPL(__imp__sub_821024B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821024B8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lhz r11,22(r4)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 22);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// rlwinm r8,r11,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// lwz r29,16(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f31,22044(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 22044);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82102600
	if (ctx.cr6.eq) goto loc_82102600;
	// rlwinm r11,r11,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82102504
	if (!ctx.cr6.eq) goto loc_82102504;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// beq cr6,0x82102600
	if (ctx.cr6.eq) goto loc_82102600;
loc_82102504:
	// lhz r11,2(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// lhz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// extsh r4,r10
	ctx.r4.s64 = ctx.r10.s16;
	// bl 0x820e6080
	ctx.lr = 0x8210251C;
	sub_820E6080(ctx, base);
	// lhz r9,22(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// extsh r31,r3
	ctx.r31.s64 = ctx.r3.s16;
	// rlwinm r11,r9,30,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8210259c
	if (ctx.cr6.eq) goto loc_8210259C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82102588
	if (ctx.cr6.eq) goto loc_82102588;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x821025ac
	if (!ctx.cr6.eq) goto loc_821025AC;
	// lfs f1,44(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820ec830
	ctx.lr = 0x82102548;
	sub_820EC830(ctx, base);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// extsh r8,r31
	ctx.r8.s64 = ctx.r31.s16;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f6.u64);
	// lhz r31,94(r1)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// b 0x821025ac
	goto loc_821025AC;
loc_82102588:
	// lfs f1,44(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820ec830
	ctx.lr = 0x82102590;
	sub_820EC830(ctx, base);
	// subf r9,r31,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r31.s64;
	// extsh r31,r9
	ctx.r31.s64 = ctx.r9.s16;
	// b 0x821025ac
	goto loc_821025AC;
loc_8210259C:
	// lfs f1,44(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820ec830
	ctx.lr = 0x821025A4;
	sub_820EC830(ctx, base);
	// add r11,r3,r31
	ctx.r11.u64 = ctx.r3.u64 + ctx.r31.u64;
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
loc_821025AC:
	// extsh r11,r31
	ctx.r11.s64 = ctx.r31.s16;
	// cmpwi cr6,r11,2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2400, ctx.xer);
	// blt cr6,0x821025c4
	if (ctx.cr6.lt) goto loc_821025C4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f1,23040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f1.f64 = double(temp.f32);
	// b 0x821025f8
	goto loc_821025F8;
loc_821025C4:
	// cmpwi cr6,r11,-2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2400, ctx.xer);
	// bgt cr6,0x821025d8
	if (ctx.cr6.gt) goto loc_821025D8;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f1,-20792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -20792);
	ctx.f1.f64 = double(temp.f32);
	// b 0x821025f8
	goto loc_821025F8;
loc_821025D8:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,19576(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 19576);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
loc_821025F8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820faf70
	ctx.lr = 0x82102600;
	sub_820FAF70(ctx, base);
loc_82102600:
	// lhz r11,22(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// rlwinm r9,r11,0,18,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// addi r27,r10,22944
	ctx.r27.s64 = ctx.r10.s64 + 22944;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82102760
	if (ctx.cr6.eq) goto loc_82102760;
	// rlwinm r11,r11,0,22,22
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82102634
	if (!ctx.cr6.eq) goto loc_82102634;
	// lbz r11,40(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 40);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// beq cr6,0x82102760
	if (ctx.cr6.eq) goto loc_82102760;
loc_82102634:
	// lbz r5,5(r30)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r30.u32 + 5);
	// lbz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// bl 0x820e6080
	ctx.lr = 0x82102644;
	sub_820E6080(ctx, base);
	// lhz r10,22(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// rlwinm r9,r3,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// clrlwi r11,r10,30
	ctx.r11.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// lwzx r31,r9,r27
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r27.u32);
	// beq cr6,0x821026f8
	if (ctx.cr6.eq) goto loc_821026F8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821026cc
	if (ctx.cr6.eq) goto loc_821026CC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x8210271c
	if (!ctx.cr6.eq) goto loc_8210271C;
	// lfs f1,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820802c0
	ctx.lr = 0x82102674;
	sub_820802C0(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,23984(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23984);
	// fmul f12,f1,f0
	ctx.f12.f64 = ctx.f1.f64 * ctx.f0.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stfd f11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmuls f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmuls f4,f5,f31
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f31.f64));
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f3.u64);
	// lwz r31,92(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// b 0x8210271c
	goto loc_8210271C;
loc_821026CC:
	// lfs f1,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820802c0
	ctx.lr = 0x821026D4;
	sub_820802C0(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// neg r10,r31
	ctx.r10.s64 = -ctx.r31.s64;
	// lfd f0,24016(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 24016);
	// fmul f0,f1,f0
	ctx.f0.f64 = ctx.f1.f64 * ctx.f0.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// subf r31,r9,r10
	ctx.r31.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8210271c
	goto loc_8210271C;
loc_821026F8:
	// lfs f1,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820802c0
	ctx.lr = 0x82102700;
	sub_820802C0(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfd f0,24016(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 24016);
	// fmul f0,f1,f0
	ctx.f0.f64 = ctx.f1.f64 * ctx.f0.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
loc_8210271C:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmpwi cr6,r31,6400
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6400, ctx.xer);
	// ble cr6,0x8210272c
	if (!ctx.cr6.gt) goto loc_8210272C;
	// li r11,6400
	ctx.r11.s64 = 6400;
loc_8210272C:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfd f0,19592(r9)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 19592);
	// lfd f1,19584(r10)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + 19584);
	// fmul f2,f12,f0
	ctx.f2.f64 = ctx.f12.f64 * ctx.f0.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x82102754;
	sub_8207B7A8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// bl 0x820faef0
	ctx.lr = 0x82102760;
	sub_820FAEF0(ctx, base);
loc_82102760:
	// lhz r11,22(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82102828
	if (ctx.cr6.eq) goto loc_82102828;
	// rlwinm r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8210278c
	if (!ctx.cr6.eq) goto loc_8210278C;
	// lbz r11,40(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 40);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// beq cr6,0x82102828
	if (ctx.cr6.eq) goto loc_82102828;
loc_8210278C:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821022d0
	ctx.lr = 0x82102798;
	sub_821022D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82102828
	if (!ctx.cr6.eq) goto loc_82102828;
	// lwz r11,10(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 10);
	// lwz r10,6(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x820e60e8
	ctx.lr = 0x821027C0;
	sub_820E60E8(ctx, base);
	// lhz r9,22(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// rlwinm r11,r9,28,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x3;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821027f8
	if (ctx.cr6.eq) goto loc_821027F8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821027ec
	if (ctx.cr6.eq) goto loc_821027EC;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82102800
	if (!ctx.cr6.eq) goto loc_82102800;
	// lfs f0,64(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// b 0x82102800
	goto loc_82102800;
loc_821027EC:
	// lfs f0,64(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// b 0x82102800
	goto loc_82102800;
loc_821027F8:
	// lfs f0,64(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
loc_82102800:
	// lfs f0,1024(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 1024);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x82102818
	if (ctx.cr6.lt) goto loc_82102818;
	// lfs f0,1028(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 1028);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8210281c
	if (!ctx.cr6.gt) goto loc_8210281C;
loc_82102818:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
loc_8210281C:
	// stfs f1,64(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 64, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fa4d8
	ctx.lr = 0x82102828;
	sub_820FA4D8(ctx, base);
loc_82102828:
	// lhz r11,22(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821028f0
	if (ctx.cr6.eq) goto loc_821028F0;
	// rlwinm r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82102854
	if (!ctx.cr6.eq) goto loc_82102854;
	// lbz r11,40(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 40);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// beq cr6,0x821028f0
	if (ctx.cr6.eq) goto loc_821028F0;
loc_82102854:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821022d0
	ctx.lr = 0x82102860;
	sub_821022D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821028f0
	if (!ctx.cr6.eq) goto loc_821028F0;
	// lwz r11,18(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 18);
	// lwz r10,14(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 14);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f2,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820e60e8
	ctx.lr = 0x82102888;
	sub_820E60E8(ctx, base);
	// lhz r9,22(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 22);
	// rlwinm r11,r9,26,30,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x3;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821028c0
	if (ctx.cr6.eq) goto loc_821028C0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821028b4
	if (ctx.cr6.eq) goto loc_821028B4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x821028c8
	if (!ctx.cr6.eq) goto loc_821028C8;
	// lfs f0,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// b 0x821028c8
	goto loc_821028C8;
loc_821028B4:
	// lfs f0,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// b 0x821028c8
	goto loc_821028C8;
loc_821028C0:
	// lfs f0,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
loc_821028C8:
	// lfs f0,1032(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 1032);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x821028e0
	if (ctx.cr6.lt) goto loc_821028E0;
	// lfs f0,1036(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 1036);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x821028e4
	if (!ctx.cr6.gt) goto loc_821028E4;
loc_821028E0:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
loc_821028E4:
	// stfs f1,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 68, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820fa4d8
	ctx.lr = 0x821028F0;
	sub_820FA4D8(ctx, base);
loc_821028F0:
	// lbz r11,40(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 40);
	// ori r10,r11,16
	ctx.r10.u64 = ctx.r11.u64 | 16;
	// stb r10,40(r28)
	PPC_STORE_U8(ctx.r28.u32 + 40, ctx.r10.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82102908"))) PPC_WEAK_FUNC(sub_82102908);
PPC_FUNC_IMPL(__imp__sub_82102908) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82102910;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,2,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82102970
	if (ctx.cr6.eq) goto loc_82102970;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// bne cr6,0x82102944
	if (!ctx.cr6.eq) goto loc_82102944;
	// bl 0x820e6990
	ctx.lr = 0x82102940;
	sub_820E6990(ctx, base);
	// b 0x8210294c
	goto loc_8210294C;
loc_82102944:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
loc_8210294C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r8,r9,27,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0xFFFFFF;
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// add r7,r10,r3
	ctx.r7.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// b 0x821029d8
	goto loc_821029D8;
loc_82102970:
	// rlwinm r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// beq cr6,0x82102994
	if (ctx.cr6.eq) goto loc_82102994;
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// subf r7,r9,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r9.s64;
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// b 0x821029bc
	goto loc_821029BC;
loc_82102994:
	// lbz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r8,64
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 64, ctx.xer);
	// bne cr6,0x821029b0
	if (!ctx.cr6.eq) goto loc_821029B0;
	// lwz r10,24(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// b 0x821029b4
	goto loc_821029B4;
loc_821029B0:
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
loc_821029B4:
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
loc_821029BC:
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r10,r10,27,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xFFFFFF;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
loc_821029D8:
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// lhz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82102a10
	if (ctx.cr6.eq) goto loc_82102A10;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r29,20(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x820e6018
	ctx.lr = 0x821029FC;
	sub_820E6018(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// add r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 + ctx.r29.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
loc_82102A10:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82102A24;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// ori r11,r9,65535
	ctx.r11.u64 = ctx.r9.u64 | 65535;
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82102a3c
	if (ctx.cr6.eq) goto loc_82102A3C;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_82102A3C:
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x820f74b8
	ctx.lr = 0x82102A54;
	sub_820F74B8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82102A5C"))) PPC_WEAK_FUNC(sub_82102A5C);
PPC_FUNC_IMPL(__imp__sub_82102A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82102A60"))) PPC_WEAK_FUNC(sub_82102A60);
PPC_FUNC_IMPL(__imp__sub_82102A60) {
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
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82102340
	ctx.lr = 0x82102A84;
	sub_82102340(ctx, base);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r9,r11,24024
	ctx.r9.s64 = ctx.r11.s64 + 24024;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82102AB8"))) PPC_WEAK_FUNC(sub_82102AB8);
PPC_FUNC_IMPL(__imp__sub_82102AB8) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,24024
	ctx.r10.s64 = ctx.r11.s64 + 24024;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x82101cc0
	ctx.lr = 0x82102AE4;
	sub_82101CC0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82102b04
	if (ctx.cr6.eq) goto loc_82102B04;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32782
	ctx.r4.u64 = ctx.r4.u64 | 32782;
	// bl 0x820e9410
	ctx.lr = 0x82102B00;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82102B04:
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

__attribute__((alias("__imp__sub_82102B1C"))) PPC_WEAK_FUNC(sub_82102B1C);
PPC_FUNC_IMPL(__imp__sub_82102B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82102B20"))) PPC_WEAK_FUNC(sub_82102B20);
PPC_FUNC_IMPL(__imp__sub_82102B20) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82102b54
	if (!ctx.cr6.eq) goto loc_82102B54;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,7
	ctx.r4.s64 = ctx.r11.s64 + 7;
	// bl 0x820e6170
	ctx.lr = 0x82102B48;
	sub_820E6170(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x82102b58
	if (ctx.cr6.eq) goto loc_82102B58;
loc_82102B54:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82102B58:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82102B68"))) PPC_WEAK_FUNC(sub_82102B68);
PPC_FUNC_IMPL(__imp__sub_82102B68) {
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
	// bl 0x821021b0
	ctx.lr = 0x82102B80;
	sub_821021B0(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82102ba4
	if (!ctx.cr6.eq) goto loc_82102BA4;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r11,7
	ctx.r4.s64 = ctx.r11.s64 + 7;
	// bl 0x820e6170
	ctx.lr = 0x82102B9C;
	sub_820E6170(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82102be8
	if (ctx.cr6.eq) goto loc_82102BE8;
loc_82102BA4:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82102bc4
	if (ctx.cr6.eq) goto loc_82102BC4;
	// lwz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82102bc8
	if (!ctx.cr6.eq) goto loc_82102BC8;
loc_82102BC4:
	// stw r31,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r31.u32);
loc_82102BC8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82102BDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// bl 0x820fae68
	ctx.lr = 0x82102BE8;
	sub_820FAE68(ctx, base);
loc_82102BE8:
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

__attribute__((alias("__imp__sub_82102BFC"))) PPC_WEAK_FUNC(sub_82102BFC);
PPC_FUNC_IMPL(__imp__sub_82102BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82102C00"))) PPC_WEAK_FUNC(sub_82102C00);
PPC_FUNC_IMPL(__imp__sub_82102C00) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,24048
	ctx.r10.s64 = ctx.r11.s64 + 24048;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82102C10"))) PPC_WEAK_FUNC(sub_82102C10);
PPC_FUNC_IMPL(__imp__sub_82102C10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82102C18;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r4,8
	ctx.r30.s64 = ctx.r4.s64 + 8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82102C34:
	// lhz r10,2(r28)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r28.u32 + 2);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82102c94
	if (!ctx.cr6.lt) goto loc_82102C94;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,5
	ctx.r11.s64 = 5;
	// add r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 + ctx.r10.u64;
	// addi r9,r1,79
	ctx.r9.s64 = ctx.r1.s64 + 79;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82102C60:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x82102c60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82102C60;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lbz r4,82(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// bl 0x820ef3b0
	ctx.lr = 0x82102C78;
	sub_820EF3B0(ctx, base);
	// cmplw cr6,r3,r26
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82102c84
	if (!ctx.cr6.eq) goto loc_82102C84;
	// li r29,1
	ctx.r29.s64 = 1;
loc_82102C84:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// beq cr6,0x82102c34
	if (ctx.cr6.eq) goto loc_82102C34;
loc_82102C94:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82102CA0"))) PPC_WEAK_FUNC(sub_82102CA0);
PPC_FUNC_IMPL(__imp__sub_82102CA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82102CA8;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82102CDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x82102e10
	if (!ctx.cr6.eq) goto loc_82102E10;
	// lbz r11,9(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82102e04
	if (ctx.cr6.eq) goto loc_82102E04;
loc_82102D00:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x82102e04
	if (!ctx.cr6.eq) goto loc_82102E04;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82102D24;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r24,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r24.u32);
	// stw r24,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r24.u32);
	// lwz r6,32(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82102D50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82102dec
	if (ctx.cr6.eq) goto loc_82102DEC;
loc_82102D5C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x82102db0
	if (ctx.cr6.eq) goto loc_82102DB0;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// beq cr6,0x82102db0
	if (ctx.cr6.eq) goto loc_82102DB0;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x82102db0
	if (ctx.cr6.eq) goto loc_82102DB0;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// beq cr6,0x82102d94
	if (ctx.cr6.eq) goto loc_82102D94;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// beq cr6,0x82102d94
	if (ctx.cr6.eq) goto loc_82102D94;
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x82102dc8
	if (!ctx.cr6.eq) goto loc_82102DC8;
loc_82102D94:
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r11,13
	ctx.r4.s64 = ctx.r11.s64 + 13;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82102c10
	ctx.lr = 0x82102DA8;
	sub_82102C10(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82102dc8
	goto loc_82102DC8;
loc_82102DB0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 10);
	// bl 0x820ef3b0
	ctx.lr = 0x82102DBC;
	sub_820EF3B0(ctx, base);
	// subf r11,r3,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r3.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r30,r10,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_82102DC8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82102DE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82102d5c
	if (!ctx.cr6.eq) goto loc_82102D5C;
loc_82102DEC:
	// clrlwi r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	// lbz r10,9(r26)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r26.u32 + 9);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r28,r9,24
	ctx.r28.u64 = ctx.r9.u32 & 0xFF;
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82102d00
	if (ctx.cr6.lt) goto loc_82102D00;
loc_82102E04:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_82102E10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r4,11(r26)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r26.u32 + 11);
	// bl 0x820ef3b0
	ctx.lr = 0x82102E1C;
	sub_820EF3B0(ctx, base);
	// subf r11,r3,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r3.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82102E30"))) PPC_WEAK_FUNC(sub_82102E30);
PPC_FUNC_IMPL(__imp__sub_82102E30) {
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
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,24048
	ctx.r9.s64 = ctx.r11.s64 + 24048;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82102e6c
	if (ctx.cr6.eq) goto loc_82102E6C;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32795
	ctx.r4.u64 = ctx.r4.u64 | 32795;
	// bl 0x820e9410
	ctx.lr = 0x82102E68;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82102E6C:
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

__attribute__((alias("__imp__sub_82102E80"))) PPC_WEAK_FUNC(sub_82102E80);
PPC_FUNC_IMPL(__imp__sub_82102E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82102E88;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,-1
	ctx.r11.s64 = -1;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// sth r10,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, ctx.r10.u16);
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r3,r11,1,15,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1FFFE;
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82102EC8;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82102fa4
	if (ctx.cr6.eq) goto loc_82102FA4;
	// lwz r11,8(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8);
	// li r22,0
	ctx.r22.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r27,r11,8
	ctx.r27.s64 = ctx.r11.s64 + 8;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82102f58
	if (ctx.cr6.eq) goto loc_82102F58;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82102EF4:
	// rlwinm r11,r29,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 + ctx.r27.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x82102F08;
	sub_8207DAC0(ctx, base);
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x82102f44
	if (ctx.cr6.gt) goto loc_82102F44;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x82102f44
	if (ctx.cr6.lt) goto loc_82102F44;
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// rlwinm r10,r30,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0x1FFFE;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r30,r9,16
	ctx.r30.u64 = ctx.r9.u32 & 0xFFFF;
	// sthx r31,r10,r28
	PPC_STORE_U16(ctx.r10.u32 + ctx.r28.u32, ctx.r31.u16);
loc_82102F44:
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// blt cr6,0x82102ef4
	if (ctx.cr6.lt) goto loc_82102EF4;
loc_82102F58:
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82102f8c
	if (ctx.cr6.eq) goto loc_82102F8C;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// lwz r3,4(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820e6080
	ctx.lr = 0x82102F74;
	sub_820E6080(ctx, base);
	// rlwinm r10,r3,1,15,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1FFFE;
	// lhzx r9,r10,r28
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r28.u32);
	// rotlwi r8,r9,4
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// lwzx r7,r8,r27
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r27.u32);
	// stw r7,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r7.u32);
	// sth r9,0(r24)
	PPC_STORE_U16(ctx.r24.u32 + 0, ctx.r9.u16);
loc_82102F8C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207a630
	ctx.lr = 0x82102F94;
	sub_8207A630(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_82102FA4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82102FB8"))) PPC_WEAK_FUNC(sub_82102FB8);
PPC_FUNC_IMPL(__imp__sub_82102FB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFF0;
	// li r3,0
	ctx.r3.s64 = 0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// lfs f0,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82103004"))) PPC_WEAK_FUNC(sub_82103004);
PPC_FUNC_IMPL(__imp__sub_82103004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82103008"))) PPC_WEAK_FUNC(sub_82103008);
PPC_FUNC_IMPL(__imp__sub_82103008) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82103010;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r30,r10,8
	ctx.r30.s64 = ctx.r10.s64 + 8;
loc_82103030:
	// lwz r10,8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82103098
	if (!ctx.cr6.lt) goto loc_82103098;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,5
	ctx.r11.s64 = 5;
	// add r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 + ctx.r10.u64;
	// addi r9,r1,79
	ctx.r9.s64 = ctx.r1.s64 + 79;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82103064:
	// lbzu r11,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// stbu r11,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r11.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x82103064
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82103064;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lbz r4,82(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// bl 0x820ef3b0
	ctx.lr = 0x8210307C;
	sub_820EF3B0(ctx, base);
	// cmplw cr6,r3,r26
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82103088
	if (!ctx.cr6.eq) goto loc_82103088;
	// li r29,1
	ctx.r29.s64 = 1;
loc_82103088:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// beq cr6,0x82103030
	if (ctx.cr6.eq) goto loc_82103030;
loc_82103098:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821030A4"))) PPC_WEAK_FUNC(sub_821030A4);
PPC_FUNC_IMPL(__imp__sub_821030A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821030A8"))) PPC_WEAK_FUNC(sub_821030A8);
PPC_FUNC_IMPL(__imp__sub_821030A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821030B0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r29,r10,8
	ctx.r29.s64 = ctx.r10.s64 + 8;
loc_821030D0:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82103138
	if (!ctx.cr6.lt) goto loc_82103138;
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// li r11,6
	ctx.r11.s64 = 6;
	// add r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 + ctx.r10.u64;
	// addi r9,r1,79
	ctx.r9.s64 = ctx.r1.s64 + 79;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
loc_82103108:
	// lbzu r10,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r10,1(r9)
	ea = 1 + ctx.r9.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r9.u32 = ea;
	// bdnz 0x82103108
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82103108;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82102ca0
	ctx.lr = 0x82103128;
	sub_82102CA0(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// beq cr6,0x821030d0
	if (ctx.cr6.eq) goto loc_821030D0;
loc_82103138:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82103140"))) PPC_WEAK_FUNC(sub_82103140);
PPC_FUNC_IMPL(__imp__sub_82103140) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82103148;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r27,r10,8
	ctx.r27.s64 = ctx.r10.s64 + 8;
loc_82103168:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x821031b8
	if (!ctx.cr6.lt) goto loc_821031B8;
	// rlwinm r11,r31,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r4,r11,r27
	ctx.r4.u64 = ctx.r11.u64 + ctx.r27.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x82103194;
	sub_8207DAC0(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82102ca0
	ctx.lr = 0x821031A8;
	sub_82102CA0(ctx, base);
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// beq cr6,0x82103168
	if (ctx.cr6.eq) goto loc_82103168;
loc_821031B8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821031C0"))) PPC_WEAK_FUNC(sub_821031C0);
PPC_FUNC_IMPL(__imp__sub_821031C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r30,0
	ctx.r30.s64 = 0;
	// sth r11,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, ctx.r11.u16);
loc_821031D4:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8210324c
	if (!ctx.cr6.lt) goto loc_8210324C;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,6
	ctx.r9.s64 = 6;
	// add r31,r10,r8
	ctx.r31.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r8,r1,-33
	ctx.r8.s64 = ctx.r1.s64 + -33;
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r11,r11,7
	ctx.r11.s64 = ctx.r11.s64 + 7;
loc_8210320C:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r8)
	ea = 1 + ctx.r8.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x8210320c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8210320C;
	// lwz r11,-32(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x82103238
	if (!ctx.cr6.eq) goto loc_82103238;
	// lbz r11,-27(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + -27);
	// lbz r9,-28(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + -28);
	// sth r30,0(r5)
	PPC_STORE_U16(ctx.r5.u32 + 0, ctx.r30.u16);
	// stb r11,0(r7)
	PPC_STORE_U8(ctx.r7.u32 + 0, ctx.r11.u8);
	// stb r9,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r9.u8);
loc_82103238:
	// lhz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// beq cr6,0x821031d4
	if (ctx.cr6.eq) goto loc_821031D4;
loc_8210324C:
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82103258"))) PPC_WEAK_FUNC(sub_82103258);
PPC_FUNC_IMPL(__imp__sub_82103258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82103260;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFF0;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210328C;
	sub_8207DAC0(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// stw r9,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821032BC"))) PPC_WEAK_FUNC(sub_821032BC);
PPC_FUNC_IMPL(__imp__sub_821032BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821032C0"))) PPC_WEAK_FUNC(sub_821032C0);
PPC_FUNC_IMPL(__imp__sub_821032C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r3,-1
	ctx.r3.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
loc_821032D4:
	// clrlwi r11,r6,16
	ctx.r11.u64 = ctx.r6.u32 & 0xFFFF;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,5
	ctx.r10.s64 = 5;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r8,r1,-17
	ctx.r8.s64 = ctx.r1.s64 + -17;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r9,r9,7
	ctx.r9.s64 = ctx.r9.s64 + 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821032FC:
	// lbzu r10,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r10.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// stbu r10,1(r8)
	ea = 1 + ctx.r8.u32;
	PPC_STORE_U8(ea, ctx.r10.u8);
	ctx.r8.u32 = ea;
	// bdnz 0x821032fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821032FC;
	// lhz r8,-16(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8210331c
	if (!ctx.cr6.eq) goto loc_8210331C;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
loc_8210331C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r6,r11,16
	ctx.r6.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,65535
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65535, ctx.xer);
	// beq cr6,0x821032d4
	if (ctx.cr6.eq) goto loc_821032D4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82103334"))) PPC_WEAK_FUNC(sub_82103334);
PPC_FUNC_IMPL(__imp__sub_82103334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82103338"))) PPC_WEAK_FUNC(sub_82103338);
PPC_FUNC_IMPL(__imp__sub_82103338) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x820e6018
	ctx.lr = 0x82103364;
	sub_820E6018(ctx, base);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// ori r8,r11,65535
	ctx.r8.u64 = ctx.r11.u64 | 65535;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// clrlwi r3,r6,16
	ctx.r3.u64 = ctx.r6.u32 & 0xFFFF;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821033e8
	if (ctx.cr6.eq) goto loc_821033E8;
	// rlwinm r6,r10,13,29,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x7;
loc_82103390:
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// blt cr6,0x821033b0
	if (ctx.cr6.lt) goto loc_821033B0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r10,13(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 13);
	// b 0x821033c0
	goto loc_821033C0;
loc_821033B0:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
loc_821033C0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r7,r31
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x821033e8
	if (!ctx.cr6.gt) goto loc_821033E8;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82103390
	if (!ctx.cr6.eq) goto loc_82103390;
loc_821033E8:
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

__attribute__((alias("__imp__sub_82103400"))) PPC_WEAK_FUNC(sub_82103400);
PPC_FUNC_IMPL(__imp__sub_82103400) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82103408;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x8210358c
	if (!ctx.cr6.gt) goto loc_8210358C;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r27,r10,8
	ctx.r27.s64 = ctx.r10.s64 + 8;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// rlwinm r10,r10,13,29,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x7;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// clrlwi r25,r9,16
	ctx.r25.u64 = ctx.r9.u32 & 0xFFFF;
	// bgt cr6,0x82103474
	if (ctx.cr6.gt) goto loc_82103474;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82103464
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82103464;
	// bdzf 4*cr6+eq,0x82103464
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82103464;
	// bne cr6,0x8210346c
	if (!ctx.cr6.eq) goto loc_8210346C;
	// li r31,5
	ctx.r31.s64 = 5;
	// b 0x82103478
	goto loc_82103478;
loc_82103464:
	// li r31,6
	ctx.r31.s64 = 6;
	// b 0x82103478
	goto loc_82103478;
loc_8210346C:
	// li r31,16
	ctx.r31.s64 = 16;
	// b 0x82103478
	goto loc_82103478;
loc_82103474:
	// li r31,3
	ctx.r31.s64 = 3;
loc_82103478:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8210352c
	if (ctx.cr6.eq) goto loc_8210352C;
	// li r28,0
	ctx.r28.s64 = 0;
loc_82103488:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// bl 0x820e6018
	ctx.lr = 0x8210349C;
	sub_820E6018(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r10,r25,16
	ctx.r10.u64 = ctx.r25.u32 & 0xFFFF;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821034b8
	if (!ctx.cr6.eq) goto loc_821034B8;
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// b 0x821034c4
	goto loc_821034C4;
loc_821034B8:
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821034c4
	if (!ctx.cr6.eq) goto loc_821034C4;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
loc_821034C4:
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8210350c
	if (ctx.cr6.eq) goto loc_8210350C;
	// mullw r11,r28,r31
	ctx.r11.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r31.s32);
	// add r30,r11,r27
	ctx.r30.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207dac0
	ctx.lr = 0x821034E4;
	sub_8207DAC0(ctx, base);
	// mullw r11,r29,r31
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r31.s32);
	// add r29,r11,r27
	ctx.r29.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x821034FC;
	sub_8207DAC0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210350C;
	sub_8207DAC0(ctx, base);
loc_8210350C:
	// lwz r11,8(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// addi r10,r28,1
	ctx.r10.s64 = ctx.r28.s64 + 1;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r11,r9,16
	ctx.r11.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82103488
	if (ctx.cr6.lt) goto loc_82103488;
loc_8210352C:
	// clrlwi r10,r25,16
	ctx.r10.u64 = ctx.r25.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8210358c
	if (!ctx.cr6.eq) goto loc_8210358C;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r11,-2
	ctx.r5.s64 = ctx.r11.s64 + -2;
	// bl 0x820e6018
	ctx.lr = 0x8210354C;
	sub_820E6018(ctx, base);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
	// bl 0x8207dac0
	ctx.lr = 0x82103564;
	sub_8207DAC0(ctx, base);
	// mullw r11,r30,r31
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r31.s32);
	// add r30,r11,r27
	ctx.r30.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210357C;
	sub_8207DAC0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8210358C;
	sub_8207DAC0(ctx, base);
loc_8210358C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82103594"))) PPC_WEAK_FUNC(sub_82103594);
PPC_FUNC_IMPL(__imp__sub_82103594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82103598"))) PPC_WEAK_FUNC(sub_82103598);
PPC_FUNC_IMPL(__imp__sub_82103598) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r11,r10,13,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821035b0
	if (!ctx.cr6.eq) goto loc_821035B0;
	// b 0x82103008
	sub_82103008(ctx, base);
	return;
loc_821035B0:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821035bc
	if (!ctx.cr6.eq) goto loc_821035BC;
	// b 0x821030a8
	sub_821030A8(ctx, base);
	return;
loc_821035BC:
	// b 0x82103140
	sub_82103140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821035C0"))) PPC_WEAK_FUNC(sub_821035C0);
PPC_FUNC_IMPL(__imp__sub_821035C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// addi r9,r11,24048
	ctx.r9.s64 = ctx.r11.s64 + 24048;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lis r8,24
	ctx.r8.s64 = 1572864;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r7,r11,0,10,12
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x380000;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r10,r11,16,29,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0x7;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x82103604
	if (ctx.cr6.eq) goto loc_82103604;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82103604:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82103614:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r10,r10,13,29,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 13) & 0x7;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x8210363c
	if (ctx.cr6.lt) goto loc_8210363C;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lbz r10,13(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 13);
	// b 0x8210364c
	goto loc_8210364C;
loc_8210363C:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lbz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12);
loc_8210364C:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82103614
	if (ctx.cr6.lt) goto loc_82103614;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82103680"))) PPC_WEAK_FUNC(sub_82103680);
PPC_FUNC_IMPL(__imp__sub_82103680) {
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
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,-1
	ctx.r31.s64 = -1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r10,16,29,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x7;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// bgt cr6,0x821037c8
	if (ctx.cr6.gt) goto loc_821037C8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x821036fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821036FC;
	// bdzf 4*cr6+eq,0x82103750
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82103750;
	// bdzf 4*cr6+eq,0x82103760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82103760;
	// bne cr6,0x82103784
	if (!ctx.cr6.eq) goto loc_82103784;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x821036f4
	if (!ctx.cr6.lt) goto loc_821036F4;
	// lhz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x821037c8
	goto loc_821037C8;
loc_821036F4:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x821037c8
	goto loc_821037C8;
loc_821036FC:
	// lhz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// beq cr6,0x82103734
	if (ctx.cr6.eq) goto loc_82103734;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x821036f4
	if (!ctx.cr6.lt) goto loc_821036F4;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x821037c8
	goto loc_821037C8;
loc_82103734:
	// clrlwi r11,r10,16
	ctx.r11.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// bl 0x820e6018
	ctx.lr = 0x82103748;
	sub_820E6018(ctx, base);
	// clrlwi r31,r3,16
	ctx.r31.u64 = ctx.r3.u32 & 0xFFFF;
	// b 0x821037c8
	goto loc_821037C8;
loc_82103750:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82103338
	ctx.lr = 0x82103758;
	sub_82103338(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x821037c8
	goto loc_821037C8;
loc_82103760:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82103338
	ctx.lr = 0x82103768;
	sub_82103338(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82103760
	if (ctx.cr6.eq) goto loc_82103760;
	// b 0x821037c8
	goto loc_821037C8;
loc_82103784:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// clrlwi r10,r9,16
	ctx.r10.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x821037b0
	if (!ctx.cr6.lt) goto loc_821037B0;
	// lhz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r31,r11,16
	ctx.r31.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x821037b4
	goto loc_821037B4;
loc_821037B0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_821037B4:
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821037c8
	if (!ctx.cr6.eq) goto loc_821037C8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82103400
	ctx.lr = 0x821037C8;
	sub_82103400(ctx, base);
loc_821037C8:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// sth r31,4(r11)
	PPC_STORE_U16(ctx.r11.u32 + 4, ctx.r31.u16);
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

__attribute__((alias("__imp__sub_821037EC"))) PPC_WEAK_FUNC(sub_821037EC);
PPC_FUNC_IMPL(__imp__sub_821037EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821037F0"))) PPC_WEAK_FUNC(sub_821037F0);
PPC_FUNC_IMPL(__imp__sub_821037F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821037F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x82103680
	ctx.lr = 0x8210380C;
	sub_82103680(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82103854
	if (ctx.cr6.eq) goto loc_82103854;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// sth r7,0(r30)
	PPC_STORE_U16(ctx.r30.u32 + 0, ctx.r7.u16);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lbzx r5,r8,r6
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r6.u32);
	// stb r5,0(r29)
	PPC_STORE_U8(ctx.r29.u32 + 0, ctx.r5.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82103854:
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,20
	ctx.r3.u64 = ctx.r3.u64 | 20;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

