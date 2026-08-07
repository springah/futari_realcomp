#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_820F4D60"))) PPC_WEAK_FUNC(sub_820F4D60);
PPC_FUNC_IMPL(__imp__sub_820F4D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F4D68;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lfs f0,9388(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lwz r7,5(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x820f4dbc
	if (ctx.cr6.gt) goto loc_820F4DBC;
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// b 0x820f507c
	goto loc_820F507C;
loc_820F4DBC:
	// lbz r11,2(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 3);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r10,-9(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -9);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820f4e00
	if (ctx.cr6.lt) goto loc_820F4E00;
	// lwz r11,-5(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -5);
	// lbz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 44);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// stb r9,44(r29)
	PPC_STORE_U8(ctx.r29.u32 + 44, ctx.r9.u8);
	// b 0x820f507c
	goto loc_820F507C;
loc_820F4E00:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x820f507c
	if (!ctx.cr6.gt) goto loc_820F507C;
	// addi r8,r9,9
	ctx.r8.s64 = ctx.r9.s64 + 9;
loc_820F4E14:
	// lwz r6,-9(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -9);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820f4e3c
	if (ctx.cr6.lt) goto loc_820F4E3C;
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x820f4e54
	if (!ctx.cr6.gt) goto loc_820F4E54;
loc_820F4E3C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,9
	ctx.r8.s64 = ctx.r8.s64 + 9;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x820f4e14
	if (ctx.cr6.lt) goto loc_820F4E14;
	// b 0x820f507c
	goto loc_820F507C;
loc_820F4E54:
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r9,r11,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// lbz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fdivs f1,f12,f11
	ctx.f1.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// beq cr6,0x820f4fe8
	if (ctx.cr6.eq) goto loc_820F4FE8;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820f4f64
	if (ctx.cr6.eq) goto loc_820F4F64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// beq cr6,0x820f4ed4
	if (ctx.cr6.eq) goto loc_820F4ED4;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fmadds f11,f12,f1,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + ctx.f0.f64));
	// stfs f11,40(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// b 0x820f507c
	goto loc_820F507C;
loc_820F4ED4:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x820f4f2c
	if (ctx.cr6.lt) goto loc_820F4F2C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lfd f0,2064(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 2064);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f31,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
	// fsub f1,f1,f0
	ctx.f1.f64 = ctx.f1.f64 - ctx.f0.f64;
	// bl 0x8207c060
	ctx.lr = 0x820F4F08;
	sub_8207C060(ctx, base);
	// bl 0x8207ae60
	ctx.lr = 0x820F4F0C;
	sub_8207AE60(ctx, base);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fmadd f12,f1,f13,f31
	ctx.f12.f64 = ctx.f1.f64 * ctx.f13.f64 + ctx.f31.f64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,40(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// b 0x820f507c
	goto loc_820F507C;
loc_820F4F2C:
	// bl 0x8207ae60
	ctx.lr = 0x820F4F30;
	sub_8207AE60(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// bl 0x8207af40
	ctx.lr = 0x820F4F38;
	sub_8207AF40(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmadds f10,f11,f0,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f12.f64));
	// stfs f10,40(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// b 0x820f507c
	goto loc_820F507C;
loc_820F4F64:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// blt cr6,0x820f4fc0
	if (ctx.cr6.lt) goto loc_820F4FC0;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r4,r10,19528
	ctx.r4.s64 = ctx.r10.s64 + 19528;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r4,16
	ctx.r7.s64 = ctx.r4.s64 + 16;
	// addi r6,r9,14180
	ctx.r6.s64 = ctx.r9.s64 + 14180;
	// addi r5,r8,-5856
	ctx.r5.s64 = ctx.r8.s64 + -5856;
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f4c70
	ctx.lr = 0x820F4FB4;
	sub_820F4C70(ctx, base);
	// fsubs f0,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// fmadds f13,f1,f0,f30
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64 + ctx.f30.f64));
	// b 0x820f5078
	goto loc_820F5078;
loc_820F4FC0:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// addi r11,r9,19528
	ctx.r11.s64 = ctx.r9.s64 + 19528;
	// addi r6,r8,14188
	ctx.r6.s64 = ctx.r8.s64 + 14188;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
	// addi r5,r5,14164
	ctx.r5.s64 = ctx.r5.s64 + 14164;
	// b 0x820f5064
	goto loc_820F5064;
loc_820F4FE8:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// blt cr6,0x820f5044
	if (ctx.cr6.lt) goto loc_820F5044;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// addi r4,r11,19528
	ctx.r4.s64 = ctx.r11.s64 + 19528;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r7,r4,16
	ctx.r7.s64 = ctx.r4.s64 + 16;
	// addi r6,r9,14172
	ctx.r6.s64 = ctx.r9.s64 + 14172;
	// addi r5,r8,-5848
	ctx.r5.s64 = ctx.r8.s64 + -5848;
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f4c70
	ctx.lr = 0x820F5038;
	sub_820F4C70(ctx, base);
	// fsubs f0,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// fmadds f13,f1,f0,f30
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64 + ctx.f30.f64));
	// b 0x820f5078
	goto loc_820F5078;
loc_820F5044:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r11,r11,19528
	ctx.r11.s64 = ctx.r11.s64 + 19528;
	// addi r6,r9,-5832
	ctx.r6.s64 = ctx.r9.s64 + -5832;
	// addi r5,r8,-5840
	ctx.r5.s64 = ctx.r8.s64 + -5840;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
loc_820F5064:
	// addi r7,r11,24
	ctx.r7.s64 = ctx.r11.s64 + 24;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// bl 0x820f4c70
	ctx.lr = 0x820F5070;
	sub_820F4C70(ctx, base);
	// fsubs f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// fmadds f13,f1,f0,f31
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64 + ctx.f31.f64));
loc_820F5078:
	// stfs f13,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
loc_820F507C:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lhz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x820f5154
	if (ctx.cr6.lt) goto loc_820F5154;
	// beq cr6,0x820f50c4
	if (ctx.cr6.eq) goto loc_820F50C4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x820f51a0
	if (!ctx.cr6.lt) goto loc_820F51A0;
	// lfs f0,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,6400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6400, ctx.xer);
	// ble cr6,0x820f50b4
	if (!ctx.cr6.gt) goto loc_820F50B4;
	// li r11,6400
	ctx.r11.s64 = 6400;
loc_820F50B4:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x820f517c
	goto loc_820F517C;
loc_820F50C4:
	// lfs f0,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lhz r11,94(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2400, ctx.xer);
	// blt cr6,0x820f50fc
	if (ctx.cr6.lt) goto loc_820F50FC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,23040(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F50FC:
	// cmpwi cr6,r11,-2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2400, ctx.xer);
	// bgt cr6,0x820f5120
	if (ctx.cr6.gt) goto loc_820F5120;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-20792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -20792);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F5120:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfs f0,19576(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 19576);
	ctx.f0.f64 = double(temp.f32);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f0,40(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F5154:
	// lfs f0,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,6400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6400, ctx.xer);
	// ble cr6,0x820f5170
	if (!ctx.cr6.gt) goto loc_820F5170;
	// li r11,6400
	ctx.r11.s64 = 6400;
loc_820F5170:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
loc_820F517C:
	// fcfid f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfd f0,19592(r9)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 19592);
	// lfd f1,19584(r10)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + 19584);
	// fmul f2,f12,f0
	ctx.f2.f64 = ctx.f12.f64 * ctx.f0.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x820F5198;
	sub_8207B7A8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// stfs f11,40(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r29.u32 + 40, temp.u32);
loc_820F51A0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F51B0"))) PPC_WEAK_FUNC(sub_820F51B0);
PPC_FUNC_IMPL(__imp__sub_820F51B0) {
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
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// beq cr6,0x820f52c4
	if (ctx.cr6.eq) goto loc_820F52C4;
	// lhz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x820f53d8
	if (ctx.cr6.gt) goto loc_820F53D8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820f5268
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5268;
	// bdzf 4*cr6+eq,0x820f5220
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5220;
	// bdzf 4*cr6+eq,0x820f528c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F528C;
	// bne cr6,0x820f52a8
	if (!ctx.cr6.eq) goto loc_820F52A8;
	// lfs f0,120(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// bl 0x820f6dc8
	ctx.lr = 0x820F520C;
	sub_820F6DC8(ctx, base);
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
loc_820F5220:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5234;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r9,31(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 31);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f53d8
	if (ctx.cr6.eq) goto loc_820F53D8;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,124(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x820f6df8
	ctx.lr = 0x820F5254;
	sub_820F6DF8(ctx, base);
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
loc_820F5268:
	// lfs f0,128(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x820f6e68
	ctx.lr = 0x820F5278;
	sub_820F6E68(ctx, base);
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
loc_820F528C:
	// lfs f1,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820f70e8
	ctx.lr = 0x820F5294;
	sub_820F70E8(ctx, base);
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
loc_820F52A8:
	// lfs f1,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820f7110
	ctx.lr = 0x820F52B0;
	sub_820F7110(ctx, base);
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
loc_820F52C4:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f53bc
	if (ctx.cr6.eq) goto loc_820F53BC;
	// lhz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x820f53d8
	if (ctx.cr6.gt) goto loc_820F53D8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820f5360
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5360;
	// bdzf 4*cr6+eq,0x820f53d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F53D8;
	// bdzf 4*cr6+eq,0x820f5384
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5384;
	// bne cr6,0x820f53a0
	if (!ctx.cr6.eq) goto loc_820F53A0;
	// lfs f0,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// bl 0x820fa6b8
	ctx.lr = 0x820F5304;
	sub_820FA6B8(ctx, base);
	// lbz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f53d8
	if (ctx.cr6.eq) goto loc_820F53D8;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820f5344
	if (!ctx.cr6.eq) goto loc_820F5344;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x820fa218
	ctx.lr = 0x820F5330;
	sub_820FA218(ctx, base);
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
loc_820F5344:
	// clrlwi r11,r11,25
	ctx.r11.u64 = ctx.r11.u32 & 0x7F;
	// stb r11,44(r31)
	PPC_STORE_U8(ctx.r31.u32 + 44, ctx.r11.u8);
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
loc_820F5360:
	// lfs f0,60(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x820fa6e8
	ctx.lr = 0x820F5370;
	sub_820FA6E8(ctx, base);
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
loc_820F5384:
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
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
loc_820F53A0:
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
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
loc_820F53BC:
	// lhz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// lfs f1,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,-5
	ctx.r9.s64 = ctx.r9.s64 + -5;
	// clrlwi r4,r9,16
	ctx.r4.u64 = ctx.r9.u32 & 0xFFFF;
	// bl 0x820eb3f0
	ctx.lr = 0x820F53D8;
	sub_820EB3F0(ctx, base);
loc_820F53D8:
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

__attribute__((alias("__imp__sub_820F53EC"))) PPC_WEAK_FUNC(sub_820F53EC);
PPC_FUNC_IMPL(__imp__sub_820F53EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F53F0"))) PPC_WEAK_FUNC(sub_820F53F0);
PPC_FUNC_IMPL(__imp__sub_820F53F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F53F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820f54c8
	if (ctx.cr6.eq) goto loc_820F54C8;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820f5424
	if (ctx.cr6.eq) goto loc_820F5424;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lfs f1,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// b 0x820f5574
	goto loc_820F5574;
loc_820F5424:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820f54c8
	if (ctx.cr6.eq) goto loc_820F54C8;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820f5588
	if (!ctx.cr6.eq) goto loc_820F5588;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5588
	if (ctx.cr6.eq) goto loc_820F5588;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5458;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5588
	if (ctx.cr6.eq) goto loc_820F5588;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f548c
	if (ctx.cr6.eq) goto loc_820F548C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5484;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x820f5490
	goto loc_820F5490;
loc_820F548C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_820F5490:
	// lwz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820e6990
	ctx.lr = 0x820F5498;
	sub_820E6990(ctx, base);
	// subf r11,r30,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r30.s64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// bctrl 
	ctx.lr = 0x820F54C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F54C8:
	// lbz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// bne cr6,0x820f5588
	if (!ctx.cr6.eq) goto loc_820F5588;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f556c
	if (ctx.cr6.eq) goto loc_820F556C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F54FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f556c
	if (ctx.cr6.eq) goto loc_820F556C;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5530
	if (ctx.cr6.eq) goto loc_820F5530;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5528;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x820f5534
	goto loc_820F5534;
loc_820F5530:
	// li r30,0
	ctx.r30.s64 = 0;
loc_820F5534:
	// lwz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x820e6990
	ctx.lr = 0x820F553C;
	sub_820E6990(ctx, base);
	// subf r11,r30,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r30.s64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// bctrl 
	ctx.lr = 0x820F5564;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F556C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f1,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f1.f64 = double(temp.f32);
loc_820F5574:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F5588;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F5588:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5590"))) PPC_WEAK_FUNC(sub_820F5590);
PPC_FUNC_IMPL(__imp__sub_820F5590) {
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
	// lhz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x820f55bc
	if (ctx.cr6.eq) goto loc_820F55BC;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x820f561c
	if (!ctx.cr6.eq) goto loc_820F561C;
loc_820F55BC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f55e8
	if (ctx.cr6.eq) goto loc_820F55E8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F55E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f5614
	if (!ctx.cr6.eq) goto loc_820F5614;
loc_820F55E8:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f561c
	if (ctx.cr6.eq) goto loc_820F561C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F560C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f561c
	if (ctx.cr6.eq) goto loc_820F561C;
loc_820F5614:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f53f0
	ctx.lr = 0x820F561C;
	sub_820F53F0(ctx, base);
loc_820F561C:
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

__attribute__((alias("__imp__sub_820F5630"))) PPC_WEAK_FUNC(sub_820F5630);
PPC_FUNC_IMPL(__imp__sub_820F5630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lhz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820f5668
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5668;
	// bdzf 4*cr6+eq,0x820f5668
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5668;
	// bdzf 4*cr6+eq,0x820f5678
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F5678;
	// bne cr6,0x820f568c
	if (!ctx.cr6.eq) goto loc_820F568C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// blr 
	return;
loc_820F5668:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// blr 
	return;
loc_820F5678:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,19568
	ctx.r10.s64 = ctx.r11.s64 + 19568;
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// blr 
	return;
loc_820F568C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,19568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 19568);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F569C"))) PPC_WEAK_FUNC(sub_820F569C);
PPC_FUNC_IMPL(__imp__sub_820F569C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F56A0"))) PPC_WEAK_FUNC(sub_820F56A0);
PPC_FUNC_IMPL(__imp__sub_820F56A0) {
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
	// lwz r11,212(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,216(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x820f56dc
	if (!ctx.cr6.lt) goto loc_820F56DC;
	// bl 0x821d5474
	ctx.lr = 0x820F56D0;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x820f56dc
	if (ctx.cr6.eq) goto loc_820F56DC;
	// li r30,1
	ctx.r30.s64 = 1;
loc_820F56DC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f56f0
	if (ctx.cr6.eq) goto loc_820F56F0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820f5780
	if (ctx.cr6.eq) goto loc_820F5780;
loc_820F56F0:
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820f5770
	if (ctx.cr6.gt) goto loc_820F5770;
	// lis r4,8343
	ctx.r4.s64 = 546766848;
	// li r3,196
	ctx.r3.s64 = 196;
	// bl 0x82088c48
	ctx.lr = 0x820F5710;
	sub_82088C48(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f5780
	if (ctx.cr6.eq) goto loc_820F5780;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r11,r3,20
	ctx.r11.s64 = ctx.r3.s64 + 20;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820F5724:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r11,-16
	ctx.r9.s64 = ctx.r11.s64 + -16;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// addi r6,r11,20
	ctx.r6.s64 = ctx.r11.s64 + 20;
	// stw r10,-12(r11)
	PPC_STORE_U32(ctx.r11.u32 + -12, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// bdnz 0x820f5724
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820F5724;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r10,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r10.u32);
	// b 0x820f5780
	goto loc_820F5780;
loc_820F5770:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,16296
	ctx.r3.s64 = ctx.r11.s64 + 16296;
	// bl 0x8208d988
	ctx.lr = 0x820F577C;
	sub_8208D988(ctx, base);
	// twi 31,r0,22
loc_820F5780:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f5798
	if (ctx.cr6.eq) goto loc_820F5798;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x820f579c
	goto loc_820F579C;
loc_820F5798:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820F579C:
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

__attribute__((alias("__imp__sub_820F57B4"))) PPC_WEAK_FUNC(sub_820F57B4);
PPC_FUNC_IMPL(__imp__sub_820F57B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F57B8"))) PPC_WEAK_FUNC(sub_820F57B8);
PPC_FUNC_IMPL(__imp__sub_820F57B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r6,r11,16136
	ctx.r6.s64 = ctx.r11.s64 + 16136;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r8,19608
	ctx.r5.s64 = ctx.r8.s64 + 19608;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// addi r4,r7,19604
	ctx.r4.s64 = ctx.r7.s64 + 19604;
	// lfs f0,9388(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// li r10,128
	ctx.r10.s64 = 128;
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// stb r10,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F5818"))) PPC_WEAK_FUNC(sub_820F5818);
PPC_FUNC_IMPL(__imp__sub_820F5818) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820eb0e0
	sub_820EB0E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5820"))) PPC_WEAK_FUNC(sub_820F5820);
PPC_FUNC_IMPL(__imp__sub_820F5820) {
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
	// bl 0x820f4d60
	ctx.lr = 0x820F5838;
	sub_820F4D60(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5868
	if (ctx.cr6.eq) goto loc_820F5868;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x820f7bc0
	ctx.lr = 0x820F5854;
	sub_820F7BC0(ctx, base);
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
loc_820F5868:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5898
	if (ctx.cr6.eq) goto loc_820F5898;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 3);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bl 0x820fa8e0
	ctx.lr = 0x820F5884;
	sub_820FA8E0(ctx, base);
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
loc_820F5898:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f51b0
	ctx.lr = 0x820F58A4;
	sub_820F51B0(ctx, base);
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

__attribute__((alias("__imp__sub_820F58B8"))) PPC_WEAK_FUNC(sub_820F58B8);
PPC_FUNC_IMPL(__imp__sub_820F58B8) {
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
	// bl 0x820f56a0
	ctx.lr = 0x820F58D8;
	sub_820F56A0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f591c
	if (ctx.cr6.eq) goto loc_820F591C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r10,208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f5908
	if (ctx.cr6.eq) goto loc_820F5908;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x820f590c
	goto loc_820F590C;
loc_820F5908:
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
loc_820F590C:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// stw r3,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_820F591C:
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

__attribute__((alias("__imp__sub_820F5934"))) PPC_WEAK_FUNC(sub_820F5934);
PPC_FUNC_IMPL(__imp__sub_820F5934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5938"))) PPC_WEAK_FUNC(sub_820F5938);
PPC_FUNC_IMPL(__imp__sub_820F5938) {
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
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r10,19608
	ctx.r8.s64 = ctx.r10.s64 + 19608;
	// addi r7,r9,19604
	ctx.r7.s64 = ctx.r9.s64 + 19604;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// beq cr6,0x820f59a0
	if (ctx.cr6.eq) goto loc_820F59A0;
	// lwz r4,228(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 228);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820f59a0
	if (ctx.cr6.eq) goto loc_820F59A0;
loc_820F597C:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820f5998
	if (ctx.cr6.eq) goto loc_820F5998;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820f597c
	if (!ctx.cr6.eq) goto loc_820F597C;
	// b 0x820f59a0
	goto loc_820F59A0;
loc_820F5998:
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x820e9d30
	ctx.lr = 0x820F59A0;
	sub_820E9D30(ctx, base);
loc_820F59A0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,16136
	ctx.r10.s64 = ctx.r11.s64 + 16136;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_820F59C0"))) PPC_WEAK_FUNC(sub_820F59C0);
PPC_FUNC_IMPL(__imp__sub_820F59C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F59C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r6,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lhz r4,0(r7)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820F5A08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5a84
	if (ctx.cr6.lt) goto loc_820F5A84;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f5a4c
	if (ctx.cr6.eq) goto loc_820F5A4C;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lhz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lwz r3,56(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x820ed750
	ctx.lr = 0x820F5A48;
	sub_820ED750(ctx, base);
	// b 0x820f5a5c
	goto loc_820F5A5C;
loc_820F5A4C:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// bl 0x820e6918
	ctx.lr = 0x820F5A5C;
	sub_820E6918(ctx, base);
loc_820F5A5C:
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5a80
	if (ctx.cr6.lt) goto loc_820F5A80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f5630
	ctx.lr = 0x820F5A70;
	sub_820F5630(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x820f58b8
	ctx.lr = 0x820F5A80;
	sub_820F58B8(ctx, base);
loc_820F5A80:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_820F5A84:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5A8C"))) PPC_WEAK_FUNC(sub_820F5A8C);
PPC_FUNC_IMPL(__imp__sub_820F5A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5A90"))) PPC_WEAK_FUNC(sub_820F5A90);
PPC_FUNC_IMPL(__imp__sub_820F5A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F5A98;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// stw r6,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r6.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lhz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820F5AD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5b5c
	if (ctx.cr6.lt) goto loc_820F5B5C;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f5b00
	if (ctx.cr6.eq) goto loc_820F5B00;
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,10
	ctx.r3.u64 = ctx.r3.u64 | 10;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F5B00:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// bl 0x820e6918
	ctx.lr = 0x820F5B18;
	sub_820E6918(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5b58
	if (ctx.cr6.lt) goto loc_820F5B58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f5630
	ctx.lr = 0x820F5B2C;
	sub_820F5630(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x820f58b8
	ctx.lr = 0x820F5B3C;
	sub_820F58B8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f1,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F5B58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F5B58:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_820F5B5C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5B64"))) PPC_WEAK_FUNC(sub_820F5B64);
PPC_FUNC_IMPL(__imp__sub_820F5B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5B68"))) PPC_WEAK_FUNC(sub_820F5B68);
PPC_FUNC_IMPL(__imp__sub_820F5B68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F5B70;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r3,28
	ctx.r29.s64 = ctx.r3.s64 + 28;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f5bb8
	if (ctx.cr6.eq) goto loc_820F5BB8;
	// lwz r4,228(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 228);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820f5bb8
	if (ctx.cr6.eq) goto loc_820F5BB8;
loc_820F5B94:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820f5bb0
	if (ctx.cr6.eq) goto loc_820F5BB0;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x820f5b94
	if (!ctx.cr6.eq) goto loc_820F5B94;
	// b 0x820f5bb8
	goto loc_820F5BB8;
loc_820F5BB0:
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x820e9d30
	ctx.lr = 0x820F5BB8;
	sub_820E9D30(ctx, base);
loc_820F5BB8:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lhz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820F5BE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5c68
	if (ctx.cr6.lt) goto loc_820F5C68;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f5c38
	if (ctx.cr6.eq) goto loc_820F5C38;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// beq cr6,0x820f5c24
	if (ctx.cr6.eq) goto loc_820F5C24;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// bl 0x820ed750
	ctx.lr = 0x820F5C20;
	sub_820ED750(ctx, base);
	// b 0x820f5c48
	goto loc_820F5C48;
loc_820F5C24:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r3,56(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x820ed750
	ctx.lr = 0x820F5C34;
	sub_820ED750(ctx, base);
	// b 0x820f5c48
	goto loc_820F5C48;
loc_820F5C38:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// bl 0x820e6918
	ctx.lr = 0x820F5C48;
	sub_820E6918(ctx, base);
loc_820F5C48:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5c64
	if (ctx.cr6.lt) goto loc_820F5C64;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,24
	ctx.r3.s64 = ctx.r11.s64 + 24;
	// bl 0x820f58b8
	ctx.lr = 0x820F5C64;
	sub_820F58B8(ctx, base);
loc_820F5C64:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820F5C68:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5C70"))) PPC_WEAK_FUNC(sub_820F5C70);
PPC_FUNC_IMPL(__imp__sub_820F5C70) {
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
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// stw r6,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r6.u32);
	// bl 0x820f5b68
	ctx.lr = 0x820F5C98;
	sub_820F5B68(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5cac
	if (ctx.cr6.lt) goto loc_820F5CAC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f5630
	ctx.lr = 0x820F5CAC;
	sub_820F5630(ctx, base);
loc_820F5CAC:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
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

__attribute__((alias("__imp__sub_820F5CC4"))) PPC_WEAK_FUNC(sub_820F5CC4);
PPC_FUNC_IMPL(__imp__sub_820F5CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5CC8"))) PPC_WEAK_FUNC(sub_820F5CC8);
PPC_FUNC_IMPL(__imp__sub_820F5CC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,140(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F5CF0"))) PPC_WEAK_FUNC(sub_820F5CF0);
PPC_FUNC_IMPL(__imp__sub_820F5CF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F5CF4"))) PPC_WEAK_FUNC(sub_820F5CF4);
PPC_FUNC_IMPL(__imp__sub_820F5CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5CF8"))) PPC_WEAK_FUNC(sub_820F5CF8);
PPC_FUNC_IMPL(__imp__sub_820F5CF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F5D20"))) PPC_WEAK_FUNC(sub_820F5D20);
PPC_FUNC_IMPL(__imp__sub_820F5D20) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F5D24"))) PPC_WEAK_FUNC(sub_820F5D24);
PPC_FUNC_IMPL(__imp__sub_820F5D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5D28"))) PPC_WEAK_FUNC(sub_820F5D28);
PPC_FUNC_IMPL(__imp__sub_820F5D28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F5D30;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stb r10,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r10.u8);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x820e9408
	ctx.lr = 0x820F5D68;
	sub_820E9408(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5e28
	if (ctx.cr6.eq) goto loc_820F5E28;
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
	ctx.lr = 0x820F5D94;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f5db8
	if (ctx.cr6.eq) goto loc_820F5DB8;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x82101420
	ctx.lr = 0x820F5DB4;
	sub_82101420(ctx, base);
	// b 0x820f5dbc
	goto loc_820F5DBC;
loc_820F5DB8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_820F5DBC:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5e28
	if (ctx.cr6.eq) goto loc_820F5E28;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5DEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f5e70
	if (ctx.cr6.lt) goto loc_820F5E70;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5E0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// beq cr6,0x820f5e74
	if (ctx.cr6.eq) goto loc_820F5E74;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F5E28:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// stb r28,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r28.u8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// beq cr6,0x820f5e70
	if (ctx.cr6.eq) goto loc_820F5E70;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f5e5c
	if (ctx.cr6.eq) goto loc_820F5E5C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5E5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F5E5C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x820e9410
	ctx.lr = 0x820F5E6C;
	sub_820E9410(ctx, base);
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
loc_820F5E70:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820F5E74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5E7C"))) PPC_WEAK_FUNC(sub_820F5E7C);
PPC_FUNC_IMPL(__imp__sub_820F5E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5E80"))) PPC_WEAK_FUNC(sub_820F5E80);
PPC_FUNC_IMPL(__imp__sub_820F5E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F5E88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r3,r11,204
	ctx.r3.s64 = ctx.r11.s64 + 204;
	// bl 0x821d5384
	ctx.lr = 0x820F5EA0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f5ef8
	if (ctx.cr6.eq) goto loc_820F5EF8;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_820F5EB4:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lbz r9,40(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 40);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,32
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 32, ctx.xer);
	// bne cr6,0x820f5edc
	if (!ctx.cr6.eq) goto loc_820F5EDC;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x820f6a20
	ctx.lr = 0x820F5ED8;
	sub_820F6A20(ctx, base);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_820F5EDC:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blt cr6,0x820f5eb4
	if (ctx.cr6.lt) goto loc_820F5EB4;
loc_820F5EF8:
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
loc_820F5EFC:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f5f2c
	if (ctx.cr6.eq) goto loc_820F5F2C;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f5f2c
	if (ctx.cr6.eq) goto loc_820F5F2C;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x820f6a20
	ctx.lr = 0x820F5F28;
	sub_820F6A20(ctx, base);
	// b 0x820f5efc
	goto loc_820F5EFC;
loc_820F5F2C:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r3,r11,204
	ctx.r3.s64 = ctx.r11.s64 + 204;
	// bl 0x821d5394
	ctx.lr = 0x820F5F38;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F5F44"))) PPC_WEAK_FUNC(sub_820F5F44);
PPC_FUNC_IMPL(__imp__sub_820F5F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5F48"))) PPC_WEAK_FUNC(sub_820F5F48);
PPC_FUNC_IMPL(__imp__sub_820F5F48) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 44);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r11,45(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 45);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F5F88"))) PPC_WEAK_FUNC(sub_820F5F88);
PPC_FUNC_IMPL(__imp__sub_820F5F88) {
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
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f5fc4
	if (ctx.cr6.eq) goto loc_820F5FC4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F5FB8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r3,r31
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r31.u32, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x820f5fc8
	if (ctx.cr6.eq) goto loc_820F5FC8;
loc_820F5FC4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820F5FC8:
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

__attribute__((alias("__imp__sub_820F5FDC"))) PPC_WEAK_FUNC(sub_820F5FDC);
PPC_FUNC_IMPL(__imp__sub_820F5FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F5FE0"))) PPC_WEAK_FUNC(sub_820F5FE0);
PPC_FUNC_IMPL(__imp__sub_820F5FE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F5FFC"))) PPC_WEAK_FUNC(sub_820F5FFC);
PPC_FUNC_IMPL(__imp__sub_820F5FFC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6000"))) PPC_WEAK_FUNC(sub_820F6000);
PPC_FUNC_IMPL(__imp__sub_820F6000) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F601C"))) PPC_WEAK_FUNC(sub_820F601C);
PPC_FUNC_IMPL(__imp__sub_820F601C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6020"))) PPC_WEAK_FUNC(sub_820F6020);
PPC_FUNC_IMPL(__imp__sub_820F6020) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F603C"))) PPC_WEAK_FUNC(sub_820F603C);
PPC_FUNC_IMPL(__imp__sub_820F603C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6040"))) PPC_WEAK_FUNC(sub_820F6040);
PPC_FUNC_IMPL(__imp__sub_820F6040) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F605C"))) PPC_WEAK_FUNC(sub_820F605C);
PPC_FUNC_IMPL(__imp__sub_820F605C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6060"))) PPC_WEAK_FUNC(sub_820F6060);
PPC_FUNC_IMPL(__imp__sub_820F6060) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F607C"))) PPC_WEAK_FUNC(sub_820F607C);
PPC_FUNC_IMPL(__imp__sub_820F607C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6080"))) PPC_WEAK_FUNC(sub_820F6080);
PPC_FUNC_IMPL(__imp__sub_820F6080) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F60A4"))) PPC_WEAK_FUNC(sub_820F60A4);
PPC_FUNC_IMPL(__imp__sub_820F60A4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F60A8"))) PPC_WEAK_FUNC(sub_820F60A8);
PPC_FUNC_IMPL(__imp__sub_820F60A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f60c4
	if (ctx.cr6.eq) goto loc_820F60C4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_820F60C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F60CC"))) PPC_WEAK_FUNC(sub_820F60CC);
PPC_FUNC_IMPL(__imp__sub_820F60CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F60D0"))) PPC_WEAK_FUNC(sub_820F60D0);
PPC_FUNC_IMPL(__imp__sub_820F60D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f60ec
	if (ctx.cr6.eq) goto loc_820F60EC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_820F60EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F60F4"))) PPC_WEAK_FUNC(sub_820F60F4);
PPC_FUNC_IMPL(__imp__sub_820F60F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F60F8"))) PPC_WEAK_FUNC(sub_820F60F8);
PPC_FUNC_IMPL(__imp__sub_820F60F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F6100;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f6160
	if (ctx.cr6.eq) goto loc_820F6160;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_820F6120:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820F6138;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x820f6144
	if (!ctx.cr6.lt) goto loc_820F6144;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_820F6144:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blt cr6,0x820f6120
	if (ctx.cr6.lt) goto loc_820F6120;
loc_820F6160:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F616C"))) PPC_WEAK_FUNC(sub_820F616C);
PPC_FUNC_IMPL(__imp__sub_820F616C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6170"))) PPC_WEAK_FUNC(sub_820F6170);
PPC_FUNC_IMPL(__imp__sub_820F6170) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// addi r8,r10,19612
	ctx.r8.s64 = ctx.r10.s64 + 19612;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r6,r9,16136
	ctx.r6.s64 = ctx.r9.s64 + 16136;
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r11.u8);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stb r11,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, ctx.r11.u8);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// stw r7,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r7.u32);
	// stb r11,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r11.u8);
	// stb r11,45(r3)
	PPC_STORE_U8(ctx.r3.u32 + 45, ctx.r11.u8);
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F61D4"))) PPC_WEAK_FUNC(sub_820F61D4);
PPC_FUNC_IMPL(__imp__sub_820F61D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F61D8"))) PPC_WEAK_FUNC(sub_820F61D8);
PPC_FUNC_IMPL(__imp__sub_820F61D8) {
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
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r11,19612
	ctx.r9.s64 = ctx.r11.s64 + 19612;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x820f622c
	if (ctx.cr6.eq) goto loc_820F622C;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x820f622c
	if (ctx.cr6.eq) goto loc_820F622C;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
loc_820F622C:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f62a4
	if (ctx.cr6.eq) goto loc_820F62A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f5e80
	ctx.lr = 0x820F6240;
	sub_820F5E80(ctx, base);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f6294
	if (ctx.cr6.eq) goto loc_820F6294;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_820F6254:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f6278
	if (ctx.cr6.eq) goto loc_820F6278;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6278;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F6278:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blt cr6,0x820f6254
	if (ctx.cr6.lt) goto loc_820F6254;
loc_820F6294:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x820e9410
	ctx.lr = 0x820F62A4;
	sub_820E9410(ctx, base);
loc_820F62A4:
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
loc_820F62A8:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f62e4
	if (ctx.cr6.eq) goto loc_820F62E4;
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f62e4
	if (ctx.cr6.eq) goto loc_820F62E4;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f62a8
	if (ctx.cr6.eq) goto loc_820F62A8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F62E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f62a8
	goto loc_820F62A8;
loc_820F62E4:
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820f62f8
	if (ctx.cr6.eq) goto loc_820F62F8;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x820f6300
	if (!ctx.cr6.eq) goto loc_820F6300;
loc_820F62F8:
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_820F6300:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,16136
	ctx.r10.s64 = ctx.r11.s64 + 16136;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_820F6328"))) PPC_WEAK_FUNC(sub_820F6328);
PPC_FUNC_IMPL(__imp__sub_820F6328) {
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
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820f63c8
	if (!ctx.cr6.eq) goto loc_820F63C8;
	// bl 0x820e6990
	ctx.lr = 0x820F6350;
	sub_820E6990(ctx, base);
	// lbz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stb r11,44(r31)
	PPC_STORE_U8(ctx.r31.u32 + 44, ctx.r11.u8);
	// beq cr6,0x820f63d4
	if (ctx.cr6.eq) goto loc_820F63D4;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_820F6374:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,2,2
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20000000;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820f639c
	if (ctx.cr6.eq) goto loc_820F639C;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82102908
	ctx.lr = 0x820F6398;
	sub_82102908(ctx, base);
	// b 0x820f63a8
	goto loc_820F63A8;
loc_820F639C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// bl 0x820f7578
	ctx.lr = 0x820F63A8;
	sub_820F7578(ctx, base);
loc_820F63A8:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lbz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 24);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blt cr6,0x820f6374
	if (ctx.cr6.lt) goto loc_820F6374;
	// b 0x820f63d4
	goto loc_820F63D4;
loc_820F63C8:
	// lbz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 32);
	// ori r10,r11,64
	ctx.r10.u64 = ctx.r11.u64 | 64;
	// stb r10,32(r31)
	PPC_STORE_U8(ctx.r31.u32 + 32, ctx.r10.u8);
loc_820F63D4:
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

__attribute__((alias("__imp__sub_820F63F0"))) PPC_WEAK_FUNC(sub_820F63F0);
PPC_FUNC_IMPL(__imp__sub_820F63F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x820F63F8;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// lwz r7,20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// lwz r26,308(r6)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r6.u32 + 308);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r27.u32);
	// stw r27,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r27.u32);
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,32(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820F6450;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// stb r11,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// rotlwi r3,r11,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// bl 0x820e9408
	ctx.lr = 0x820F6474;
	sub_820E9408(ctx, base);
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// addic r9,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// ori r7,r10,14
	ctx.r7.u64 = ctx.r10.u64 | 14;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r23,r27
	ctx.r23.u64 = ctx.r27.u64;
	// and r29,r6,r7
	ctx.r29.u64 = ctx.r6.u64 & ctx.r7.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820f65f8
	if (ctx.cr6.lt) goto loc_820F65F8;
	// lis r11,-30009
	ctx.r11.s64 = -1966669824;
	// ori r22,r11,25
	ctx.r22.u64 = ctx.r11.u64 | 25;
loc_820F64A0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820f6670
	if (ctx.cr6.eq) goto loc_820F6670;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f64c0
	if (ctx.cr6.eq) goto loc_820F64C0;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// b 0x820f64d0
	goto loc_820F64D0;
loc_820F64C0:
	// lbz r11,6(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 6);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_820F64D0:
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82101cd0
	ctx.lr = 0x820F64E8;
	sub_82101CD0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f65d0
	if (ctx.cr6.lt) goto loc_820F65D0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r9,9
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 9, ctx.xer);
	// bne cr6,0x820f652c
	if (!ctx.cr6.eq) goto loc_820F652C;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r10,27,8,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0xFFFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpw cr6,r11,r24
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x820f652c
	if (!ctx.cr6.lt) goto loc_820F652C;
	// li r30,1
	ctx.r30.s64 = 1;
	// b 0x820f65a4
	goto loc_820F65A4;
loc_820F652C:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6540;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f6588
	if (ctx.cr6.lt) goto loc_820F6588;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r11,r9,27
	ctx.r11.u64 = ctx.r9.u32 & 0x1F;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// blt cr6,0x820f6570
	if (ctx.cr6.lt) goto loc_820F6570;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bgt cr6,0x820f6570
	if (ctx.cr6.gt) goto loc_820F6570;
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
loc_820F6570:
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// rlwinm r8,r25,2,22,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x3FC;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// clrlwi r25,r7,24
	ctx.r25.u64 = ctx.r7.u32 & 0xFF;
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
loc_820F6588:
	// cmpw cr6,r29,r22
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x820f65a0
	if (!ctx.cr6.eq) goto loc_820F65A0;
	// li r23,1
	ctx.r23.s64 = 1;
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// b 0x820f65ac
	goto loc_820F65AC;
loc_820F65A0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_820F65A4:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820f65d4
	if (ctx.cr6.lt) goto loc_820F65D4;
loc_820F65AC:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F65C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820f65f0
	if (ctx.cr6.eq) goto loc_820F65F0;
loc_820F65D0:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_820F65D4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f65f0
	if (ctx.cr6.eq) goto loc_820F65F0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F65F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F65F0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x820f64a0
	if (!ctx.cr6.lt) goto loc_820F64A0;
loc_820F65F8:
	// clrlwi r30,r25,24
	ctx.r30.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820f6640
	if (ctx.cr6.eq) goto loc_820F6640;
loc_820F6604:
	// addi r11,r30,255
	ctx.r11.s64 = ctx.r30.s64 + 255;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r9,r11,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x3FC;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f6638
	if (ctx.cr6.eq) goto loc_820F6638;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6638;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F6638:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820f6604
	if (!ctx.cr6.eq) goto loc_820F6604;
loc_820F6640:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stb r27,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r27.u8);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f6660
	if (ctx.cr6.eq) goto loc_820F6660;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x820e9410
	ctx.lr = 0x820F665C;
	sub_820E9410(ctx, base);
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
loc_820F6660:
	// stw r27,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r27.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_820F6670:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820f65f8
	if (ctx.cr6.lt) goto loc_820F65F8;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x820f6694
	if (ctx.cr6.eq) goto loc_820F6694;
	// clrlwi r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820f6694
	if (!ctx.cr6.eq) goto loc_820F6694;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// b 0x820f65f8
	goto loc_820F65F8;
loc_820F6694:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stb r25,24(r31)
	PPC_STORE_U8(ctx.r31.u32 + 24, ctx.r25.u8);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f66b4
	if (ctx.cr6.eq) goto loc_820F66B4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F66B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F66B4:
	// li r11,3
	ctx.r11.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F66C8"))) PPC_WEAK_FUNC(sub_820F66C8);
PPC_FUNC_IMPL(__imp__sub_820F66C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F66D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x820f6798
	if (ctx.cr6.eq) goto loc_820F6798;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x820f6708
	if (!ctx.cr6.eq) goto loc_820F6708;
	// lwz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820f6798
	if (!ctx.cr6.eq) goto loc_820F6798;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820f6798
	if (ctx.cr6.eq) goto loc_820F6798;
loc_820F6708:
	// li r11,5
	ctx.r11.s64 = 5;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// beq cr6,0x820f672c
	if (ctx.cr6.eq) goto loc_820F672C;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x820f5e80
	ctx.lr = 0x820F6728;
	sub_820F5E80(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_820F672C:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f6774
	if (ctx.cr6.eq) goto loc_820F6774;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820f6748
	if (ctx.cr6.eq) goto loc_820F6748;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x820f6760
	goto loc_820F6760;
loc_820F6748:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6758;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_820F6760:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6774;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F6774:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820f6798
	if (ctx.cr6.eq) goto loc_820F6798;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x820f679c
	if (!ctx.cr6.eq) goto loc_820F679C;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F6798:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820F679C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F67A4"))) PPC_WEAK_FUNC(sub_820F67A4);
PPC_FUNC_IMPL(__imp__sub_820F67A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F67A8"))) PPC_WEAK_FUNC(sub_820F67A8);
PPC_FUNC_IMPL(__imp__sub_820F67A8) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// stw r4,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F67C8"))) PPC_WEAK_FUNC(sub_820F67C8);
PPC_FUNC_IMPL(__imp__sub_820F67C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_820F67D8:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x820f67f4
	if (ctx.cr6.eq) goto loc_820F67F4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820f67d8
	if (!ctx.cr6.eq) goto loc_820F67D8;
	// blr 
	return;
loc_820F67F4:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// stw r11,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6818"))) PPC_WEAK_FUNC(sub_820F6818);
PPC_FUNC_IMPL(__imp__sub_820F6818) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6844"))) PPC_WEAK_FUNC(sub_820F6844);
PPC_FUNC_IMPL(__imp__sub_820F6844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6848"))) PPC_WEAK_FUNC(sub_820F6848);
PPC_FUNC_IMPL(__imp__sub_820F6848) {
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
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f68ac
	if (ctx.cr6.eq) goto loc_820F68AC;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// bne cr6,0x820f68a4
	if (!ctx.cr6.eq) goto loc_820F68A4;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,172(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F688C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820F68A4:
	// li r11,1
	ctx.r11.s64 = 1;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
loc_820F68AC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F68BC"))) PPC_WEAK_FUNC(sub_820F68BC);
PPC_FUNC_IMPL(__imp__sub_820F68BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F68C0"))) PPC_WEAK_FUNC(sub_820F68C0);
PPC_FUNC_IMPL(__imp__sub_820F68C0) {
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
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r3,-1
	ctx.r3.s64 = -1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f6924
	if (ctx.cr6.eq) goto loc_820F6924;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// bne cr6,0x820f691c
	if (!ctx.cr6.eq) goto loc_820F691C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,176(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 176);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F6904;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820F691C:
	// li r11,0
	ctx.r11.s64 = 0;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
loc_820F6924:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6934"))) PPC_WEAK_FUNC(sub_820F6934);
PPC_FUNC_IMPL(__imp__sub_820F6934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6938"))) PPC_WEAK_FUNC(sub_820F6938);
PPC_FUNC_IMPL(__imp__sub_820F6938) {
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
	// bl 0x820f61d8
	ctx.lr = 0x820F6958;
	sub_820F61D8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f6978
	if (ctx.cr6.eq) goto loc_820F6978;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// bl 0x820e9410
	ctx.lr = 0x820F6974;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820F6978:
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

__attribute__((alias("__imp__sub_820F6990"))) PPC_WEAK_FUNC(sub_820F6990);
PPC_FUNC_IMPL(__imp__sub_820F6990) {
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
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x820f69dc
	if (!ctx.cr6.eq) goto loc_820F69DC;
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f69dc
	if (ctx.cr6.eq) goto loc_820F69DC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F69CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f69dc
	if (ctx.cr6.eq) goto loc_820F69DC;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_820F69DC:
	// lbz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 32);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// bne cr6,0x820f6a0c
	if (!ctx.cr6.eq) goto loc_820F6A0C;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x820f6a0c
	if (!ctx.cr6.eq) goto loc_820F6A0C;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r11,32(r31)
	PPC_STORE_U8(ctx.r31.u32 + 32, ctx.r11.u8);
	// bl 0x820f6328
	ctx.lr = 0x820F6A0C;
	sub_820F6328(ctx, base);
loc_820F6A0C:
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

__attribute__((alias("__imp__sub_820F6A20"))) PPC_WEAK_FUNC(sub_820F6A20);
PPC_FUNC_IMPL(__imp__sub_820F6A20) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x821023e0
	sub_821023E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6A28"))) PPC_WEAK_FUNC(sub_820F6A28);
PPC_FUNC_IMPL(__imp__sub_820F6A28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820F6A30;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x820f6b24
	if (ctx.cr6.gt) goto loc_820F6B24;
	// lbz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// cmpw cr6,r4,r10
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820f6b24
	if (ctx.cr6.eq) goto loc_820F6B24;
	// addic r10,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// subfe r9,r10,r4
	temp.u8 = (~ctx.r10.u32 + ctx.r4.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r4.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r4.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwimi r11,r9,5,26,26
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x20) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// clrlwi r8,r11,24
	ctx.r8.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// stb r8,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, ctx.r8.u8);
	// cmplwi cr6,r7,32
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 32, ctx.xer);
	// bne cr6,0x820f6a88
	if (!ctx.cr6.eq) goto loc_820F6A88;
	// bl 0x820e6990
	ctx.lr = 0x820F6A80;
	sub_820E6990(ctx, base);
	// stw r3,116(r30)
	PPC_STORE_U32(ctx.r30.u32 + 116, ctx.r3.u32);
	// b 0x820f6abc
	goto loc_820F6ABC;
loc_820F6A88:
	// lwz r31,116(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 116);
	// bl 0x820e6990
	ctx.lr = 0x820F6A90;
	sub_820E6990(ctx, base);
	// lwz r11,68(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// addi r10,r30,64
	ctx.r10.s64 = ctx.r30.s64 + 64;
	// subf r8,r31,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r31.s64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820f6abc
	if (ctx.cr6.eq) goto loc_820F6ABC;
loc_820F6AA4:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820f6aa4
	if (!ctx.cr6.eq) goto loc_820F6AA4;
loc_820F6ABC:
	// lwz r31,48(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r29,r30,44
	ctx.r29.s64 = ctx.r30.s64 + 44;
loc_820F6AC4:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820f6ae8
	if (ctx.cr6.eq) goto loc_820F6AE8;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa5e8
	ctx.lr = 0x820F6AD8;
	sub_820FA5E8(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820f6ac4
	if (!ctx.cr6.lt) goto loc_820F6AC4;
loc_820F6AE8:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x820f6b24
	if (!ctx.cr6.eq) goto loc_820F6B24;
	// lwz r31,36(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addi r30,r31,204
	ctx.r30.s64 = ctx.r31.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F6B00;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F6B1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F6B24;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_820F6B24:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6B30"))) PPC_WEAK_FUNC(sub_820F6B30);
PPC_FUNC_IMPL(__imp__sub_820F6B30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F6B38;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f6b70
	if (ctx.cr6.eq) goto loc_820F6B70;
loc_820F6B50:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa3f8
	ctx.lr = 0x820F6B5C;
	sub_820FA3F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f6b7c
	if (!ctx.cr6.eq) goto loc_820F6B7C;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f6b50
	if (!ctx.cr6.eq) goto loc_820F6B50;
loc_820F6B70:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F6B7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6B88"))) PPC_WEAK_FUNC(sub_820F6B88);
PPC_FUNC_IMPL(__imp__sub_820F6B88) {
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
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f6bc0
	if (ctx.cr6.eq) goto loc_820F6BC0;
loc_820F6BAC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa470
	ctx.lr = 0x820F6BB4;
	sub_820FA470(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f6bac
	if (!ctx.cr6.eq) goto loc_820F6BAC;
loc_820F6BC0:
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

__attribute__((alias("__imp__sub_820F6BD8"))) PPC_WEAK_FUNC(sub_820F6BD8);
PPC_FUNC_IMPL(__imp__sub_820F6BD8) {
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
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f6c10
	if (ctx.cr6.eq) goto loc_820F6C10;
loc_820F6BFC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa4d8
	ctx.lr = 0x820F6C04;
	sub_820FA4D8(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f6bfc
	if (!ctx.cr6.eq) goto loc_820F6BFC;
loc_820F6C10:
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

__attribute__((alias("__imp__sub_820F6C28"))) PPC_WEAK_FUNC(sub_820F6C28);
PPC_FUNC_IMPL(__imp__sub_820F6C28) {
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
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f6c60
	if (ctx.cr6.eq) goto loc_820F6C60;
loc_820F6C4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa530
	ctx.lr = 0x820F6C54;
	sub_820FA530(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f6c4c
	if (!ctx.cr6.eq) goto loc_820F6C4C;
loc_820F6C60:
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

__attribute__((alias("__imp__sub_820F6C78"))) PPC_WEAK_FUNC(sub_820F6C78);
PPC_FUNC_IMPL(__imp__sub_820F6C78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F6C80;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f6cb0
	if (ctx.cr6.eq) goto loc_820F6CB0;
loc_820F6C98:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa598
	ctx.lr = 0x820F6CA4;
	sub_820FA598(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f6c98
	if (!ctx.cr6.eq) goto loc_820F6C98;
loc_820F6CB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6CB8"))) PPC_WEAK_FUNC(sub_820F6CB8);
PPC_FUNC_IMPL(__imp__sub_820F6CB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820F6CC0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r27,r11,44
	ctx.r27.s64 = ctx.r11.s64 + 44;
loc_820F6CE0:
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x820f6d08
	if (ctx.cr6.eq) goto loc_820F6D08;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa5b0
	ctx.lr = 0x820F6CFC;
	sub_820FA5B0(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820f6ce0
	if (!ctx.cr6.lt) goto loc_820F6CE0;
loc_820F6D08:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6D10"))) PPC_WEAK_FUNC(sub_820F6D10);
PPC_FUNC_IMPL(__imp__sub_820F6D10) {
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
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r30,r3,44
	ctx.r30.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f6d50
	if (ctx.cr6.eq) goto loc_820F6D50;
loc_820F6D34:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa5d0
	ctx.lr = 0x820F6D3C;
	sub_820FA5D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f6d6c
	if (!ctx.cr6.eq) goto loc_820F6D6C;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f6d34
	if (!ctx.cr6.eq) goto loc_820F6D34;
loc_820F6D50:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820F6D54:
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
loc_820F6D6C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820f6d54
	goto loc_820F6D54;
}

__attribute__((alias("__imp__sub_820F6D74"))) PPC_WEAK_FUNC(sub_820F6D74);
PPC_FUNC_IMPL(__imp__sub_820F6D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6D78"))) PPC_WEAK_FUNC(sub_820F6D78);
PPC_FUNC_IMPL(__imp__sub_820F6D78) {
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
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6DA0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f6db4
	if (!ctx.cr6.eq) goto loc_820F6DB4;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x820e7950
	ctx.lr = 0x820F6DB4;
	sub_820E7950(ctx, base);
loc_820F6DB4:
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

__attribute__((alias("__imp__sub_820F6DC8"))) PPC_WEAK_FUNC(sub_820F6DC8);
PPC_FUNC_IMPL(__imp__sub_820F6DC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820f6de0
	if (ctx.cr6.lt) goto loc_820F6DE0;
	// stfs f1,120(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// b 0x820f6de4
	goto loc_820F6DE4;
loc_820F6DE0:
	// stfs f0,120(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
loc_820F6DE4:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x820f6b88
	sub_820F6B88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6DF0"))) PPC_WEAK_FUNC(sub_820F6DF0);
PPC_FUNC_IMPL(__imp__sub_820F6DF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6DF4"))) PPC_WEAK_FUNC(sub_820F6DF4);
PPC_FUNC_IMPL(__imp__sub_820F6DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6DF8"))) PPC_WEAK_FUNC(sub_820F6DF8);
PPC_FUNC_IMPL(__imp__sub_820F6DF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F6E00;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bne cr6,0x820f6e60
	if (!ctx.cr6.eq) goto loc_820F6E60;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820f6e34
	if (ctx.cr6.lt) goto loc_820F6E34;
	// stfs f1,124(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// b 0x820f6e38
	goto loc_820F6E38;
loc_820F6E34:
	// stfs f0,124(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 124, temp.u32);
loc_820F6E38:
	// lwz r31,48(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r29,r30,44
	ctx.r29.s64 = ctx.r30.s64 + 44;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820f6e60
	if (ctx.cr6.eq) goto loc_820F6E60;
loc_820F6E48:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,124(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 124);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820fa518
	ctx.lr = 0x820F6E54;
	sub_820FA518(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820f6e48
	if (!ctx.cr6.eq) goto loc_820F6E48;
loc_820F6E60:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6E68"))) PPC_WEAK_FUNC(sub_820F6E68);
PPC_FUNC_IMPL(__imp__sub_820F6E68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,128(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x820f6c28
	sub_820F6C28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6E78"))) PPC_WEAK_FUNC(sub_820F6E78);
PPC_FUNC_IMPL(__imp__sub_820F6E78) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6E7C"))) PPC_WEAK_FUNC(sub_820F6E7C);
PPC_FUNC_IMPL(__imp__sub_820F6E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6E80"))) PPC_WEAK_FUNC(sub_820F6E80);
PPC_FUNC_IMPL(__imp__sub_820F6E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F6E88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bne cr6,0x820f6ec8
	if (!ctx.cr6.eq) goto loc_820F6EC8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6EB8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,2(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r11,r9,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// b 0x820f6ecc
	goto loc_820F6ECC;
loc_820F6EC8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_820F6ECC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6EE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r9,r29,2,22,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0x3FC;
	// add r11,r3,r9
	ctx.r11.u64 = ctx.r3.u64 + ctx.r9.u64;
	// add r8,r11,r30
	ctx.r8.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r3,3(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6EF8"))) PPC_WEAK_FUNC(sub_820F6EF8);
PPC_FUNC_IMPL(__imp__sub_820F6EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,128(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,100(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6F08"))) PPC_WEAK_FUNC(sub_820F6F08);
PPC_FUNC_IMPL(__imp__sub_820F6F08) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f6f58
	if (ctx.cr6.eq) goto loc_820F6F58;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f6f48
	if (ctx.cr6.eq) goto loc_820F6F48;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6F48;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F6F48:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r11,r11,-255
	ctx.r11.s64 = ctx.r11.s64 + -255;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_820F6F58:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6F68"))) PPC_WEAK_FUNC(sub_820F6F68);
PPC_FUNC_IMPL(__imp__sub_820F6F68) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f6fb4
	if (ctx.cr6.eq) goto loc_820F6FB4;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f6fa8
	if (ctx.cr6.eq) goto loc_820F6FA8;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F6FA8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F6FA8:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_820F6FB4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6FC4"))) PPC_WEAK_FUNC(sub_820F6FC4);
PPC_FUNC_IMPL(__imp__sub_820F6FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6FC8"))) PPC_WEAK_FUNC(sub_820F6FC8);
PPC_FUNC_IMPL(__imp__sub_820F6FC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x820f6818
	sub_820F6818(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F6FE0"))) PPC_WEAK_FUNC(sub_820F6FE0);
PPC_FUNC_IMPL(__imp__sub_820F6FE0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F6FE4"))) PPC_WEAK_FUNC(sub_820F6FE4);
PPC_FUNC_IMPL(__imp__sub_820F6FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F6FE8"))) PPC_WEAK_FUNC(sub_820F6FE8);
PPC_FUNC_IMPL(__imp__sub_820F6FE8) {
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
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f7078
	if (ctx.cr6.eq) goto loc_820F7078;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f7038
	if (ctx.cr6.eq) goto loc_820F7038;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7038;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F7038:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe. r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820f7078
	if (ctx.cr0.eq) goto loc_820F7078;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r11,36(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f707c
	if (ctx.cr6.eq) goto loc_820F707C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F7074;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f707c
	goto loc_820F707C;
loc_820F7078:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_820F707C:
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

__attribute__((alias("__imp__sub_820F7094"))) PPC_WEAK_FUNC(sub_820F7094);
PPC_FUNC_IMPL(__imp__sub_820F7094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F7098"))) PPC_WEAK_FUNC(sub_820F7098);
PPC_FUNC_IMPL(__imp__sub_820F7098) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F70C4"))) PPC_WEAK_FUNC(sub_820F70C4);
PPC_FUNC_IMPL(__imp__sub_820F70C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F70C8"))) PPC_WEAK_FUNC(sub_820F70C8);
PPC_FUNC_IMPL(__imp__sub_820F70C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F70E4"))) PPC_WEAK_FUNC(sub_820F70E4);
PPC_FUNC_IMPL(__imp__sub_820F70E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F70E8"))) PPC_WEAK_FUNC(sub_820F70E8);
PPC_FUNC_IMPL(__imp__sub_820F70E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820f7108
	if (ctx.cr6.eq) goto loc_820F7108;
loc_820F70F8:
	// stfs f1,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820f70f8
	if (!ctx.cr6.eq) goto loc_820F70F8;
loc_820F7108:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F7110"))) PPC_WEAK_FUNC(sub_820F7110);
PPC_FUNC_IMPL(__imp__sub_820F7110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820f7130
	if (ctx.cr6.eq) goto loc_820F7130;
loc_820F7120:
	// stfs f1,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 68, temp.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820f7120
	if (!ctx.cr6.eq) goto loc_820F7120;
loc_820F7130:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F7138"))) PPC_WEAK_FUNC(sub_820F7138);
PPC_FUNC_IMPL(__imp__sub_820F7138) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F7140;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r29,r11,44
	ctx.r29.s64 = ctx.r11.s64 + 44;
loc_820F7158:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820f7178
	if (ctx.cr6.eq) goto loc_820F7178;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa070
	ctx.lr = 0x820F716C;
	sub_820FA070(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820f7158
	if (!ctx.cr6.lt) goto loc_820F7158;
loc_820F7178:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F7180"))) PPC_WEAK_FUNC(sub_820F7180);
PPC_FUNC_IMPL(__imp__sub_820F7180) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820F7188;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r31,48(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r26,r11,44
	ctx.r26.s64 = ctx.r11.s64 + 44;
loc_820F71AC:
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x820f71d8
	if (ctx.cr6.eq) goto loc_820F71D8;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa0e0
	ctx.lr = 0x820F71CC;
	sub_820FA0E0(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820f71ac
	if (!ctx.cr6.lt) goto loc_820F71AC;
loc_820F71D8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F71E0"))) PPC_WEAK_FUNC(sub_820F71E0);
PPC_FUNC_IMPL(__imp__sub_820F71E0) {
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
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// bne cr6,0x820f722c
	if (!ctx.cr6.eq) goto loc_820F722C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F721C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,2(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r11,r9,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// b 0x820f7230
	goto loc_820F7230;
loc_820F722C:
	// li r30,0
	ctx.r30.s64 = 0;
loc_820F7230:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7244;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r9,r3,r30
	ctx.r9.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lbz r3,2(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
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

__attribute__((alias("__imp__sub_820F7264"))) PPC_WEAK_FUNC(sub_820F7264);
PPC_FUNC_IMPL(__imp__sub_820F7264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F7268"))) PPC_WEAK_FUNC(sub_820F7268);
PPC_FUNC_IMPL(__imp__sub_820F7268) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F7270;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r11,20656
	ctx.r8.s64 = ctx.r11.s64 + 20656;
	// addi r7,r9,20640
	ctx.r7.s64 = ctx.r9.s64 + 20640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f72b8
	if (ctx.cr6.eq) goto loc_820F72B8;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lhz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 1);
	// bl 0x820ec7b0
	ctx.lr = 0x820F72B8;
	sub_820EC7B0(ctx, base);
loc_820F72B8:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820f7308
	if (ctx.cr6.eq) goto loc_820F7308;
loc_820F72C8:
	// lwz r30,4(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820F72FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820f72c8
	if (!ctx.cr6.eq) goto loc_820F72C8;
loc_820F7308:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f7344
	if (ctx.cr6.eq) goto loc_820F7344;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f7340
	if (ctx.cr6.eq) goto loc_820F7340;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F733C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f7344
	goto loc_820F7344;
loc_820F7340:
	// bl 0x8207a630
	ctx.lr = 0x820F7344;
	sub_8207A630(ctx, base);
loc_820F7344:
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x820f736c
	if (!ctx.cr6.eq) goto loc_820F736C;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F736C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F736C:
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7388;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r8,r9,16136
	ctx.r8.s64 = ctx.r9.s64 + 16136;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r8.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// bl 0x820f8548
	ctx.lr = 0x820F73A4;
	sub_820F8548(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F73AC"))) PPC_WEAK_FUNC(sub_820F73AC);
PPC_FUNC_IMPL(__imp__sub_820F73AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F73B0"))) PPC_WEAK_FUNC(sub_820F73B0);
PPC_FUNC_IMPL(__imp__sub_820F73B0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820f7f30
	sub_820F7F30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F73B8"))) PPC_WEAK_FUNC(sub_820F73B8);
PPC_FUNC_IMPL(__imp__sub_820F73B8) {
	PPC_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F73C0"))) PPC_WEAK_FUNC(sub_820F73C0);
PPC_FUNC_IMPL(__imp__sub_820F73C0) {
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
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F73F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r7,r7,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r7,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r7.u8);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820F7418;
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

__attribute__((alias("__imp__sub_820F742C"))) PPC_WEAK_FUNC(sub_820F742C);
PPC_FUNC_IMPL(__imp__sub_820F742C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F7430"))) PPC_WEAK_FUNC(sub_820F7430);
PPC_FUNC_IMPL(__imp__sub_820F7430) {
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
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x820f747c
	if (!ctx.cr6.eq) goto loc_820F747C;
	// bl 0x820f6d10
	ctx.lr = 0x820F7458;
	sub_820F6D10(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f747c
	if (!ctx.cr6.eq) goto loc_820F747C;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7478;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f74a0
	goto loc_820F74A0;
loc_820F747C:
	// lwz r31,48(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r30,r30,44
	ctx.r30.s64 = ctx.r30.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f74a0
	if (ctx.cr6.eq) goto loc_820F74A0;
loc_820F748C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fb1f8
	ctx.lr = 0x820F7494;
	sub_820FB1F8(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f748c
	if (!ctx.cr6.eq) goto loc_820F748C;
loc_820F74A0:
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

__attribute__((alias("__imp__sub_820F74B8"))) PPC_WEAK_FUNC(sub_820F74B8);
PPC_FUNC_IMPL(__imp__sub_820F74B8) {
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
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F74EC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x820f7518
	if (ctx.cr6.gt) goto loc_820F7518;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7514;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f755c
	goto loc_820F755C;
loc_820F7518:
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r10,r31,64
	ctx.r10.s64 = ctx.r31.s64 + 64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820f7540
	if (ctx.cr6.eq) goto loc_820F7540;
loc_820F7528:
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x820f7540
	if (ctx.cr6.gt) goto loc_820F7540;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820f7528
	if (!ctx.cr6.eq) goto loc_820F7528;
loc_820F7540:
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r30,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r30.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_820F755C:
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

__attribute__((alias("__imp__sub_820F7574"))) PPC_WEAK_FUNC(sub_820F7574);
PPC_FUNC_IMPL(__imp__sub_820F7574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F7578"))) PPC_WEAK_FUNC(sub_820F7578);
PPC_FUNC_IMPL(__imp__sub_820F7578) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,76
	ctx.r11.s64 = ctx.r3.s64 + 76;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F7598"))) PPC_WEAK_FUNC(sub_820F7598);
PPC_FUNC_IMPL(__imp__sub_820F7598) {
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
	// addi r11,r4,-3
	ctx.r11.s64 = ctx.r4.s64 + -3;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x820f7698
	if (ctx.cr6.gt) goto loc_820F7698;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820f7614
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F7614;
	// bdzf 4*cr6+eq,0x820f7674
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F7674;
	// bne cr6,0x820f76b4
	if (!ctx.cr6.eq) goto loc_820F76B4;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x820f7698
	if (!ctx.cr6.lt) goto loc_820F7698;
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F75FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f769c
	if (!ctx.cr6.eq) goto loc_820F769C;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x820ec880
	ctx.lr = 0x820F7610;
	sub_820EC880(ctx, base);
	// b 0x820f769c
	goto loc_820F769C;
loc_820F7614:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bge cr6,0x820f7698
	if (!ctx.cr6.lt) goto loc_820F7698;
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r9,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
	// lhz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 1);
	// bl 0x820ec798
	ctx.lr = 0x820F7640;
	sub_820EC798(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820F7654;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f769c
	if (!ctx.cr6.eq) goto loc_820F769C;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7670;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f769c
	goto loc_820F769C;
loc_820F7674:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f7698
	if (ctx.cr6.eq) goto loc_820F7698;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lhz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 1);
	// bl 0x820ec7b0
	ctx.lr = 0x820F7698;
	sub_820EC7B0(ctx, base);
loc_820F7698:
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
loc_820F769C:
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
loc_820F76B4:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bge cr6,0x820f7698
	if (!ctx.cr6.lt) goto loc_820F7698;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f76ec
	if (ctx.cr6.eq) goto loc_820F76EC;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lhz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 1);
	// bl 0x820ec7b0
	ctx.lr = 0x820F76EC;
	sub_820EC7B0(ctx, base);
loc_820F76EC:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7700;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f769c
	if (!ctx.cr6.eq) goto loc_820F769C;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F771C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f769c
	goto loc_820F769C;
}

__attribute__((alias("__imp__sub_820F7720"))) PPC_WEAK_FUNC(sub_820F7720);
PPC_FUNC_IMPL(__imp__sub_820F7720) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F7728;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7744;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// addi r31,r3,2
	ctx.r31.s64 = ctx.r3.s64 + 2;
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,2
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 2, ctx.xer);
	// bne cr6,0x820f7770
	if (!ctx.cr6.eq) goto loc_820F7770;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f71e0
	ctx.lr = 0x820F7764;
	sub_820F71E0(ctx, base);
	// rlwinm r11,r3,2,22,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
loc_820F7770:
	// clrlwi r9,r29,24
	ctx.r9.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f77a0
	if (ctx.cr6.eq) goto loc_820F77A0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820F7780:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// blt cr6,0x820f7780
	if (ctx.cr6.lt) goto loc_820F7780;
loc_820F77A0:
	// lbz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F77AC"))) PPC_WEAK_FUNC(sub_820F77AC);
PPC_FUNC_IMPL(__imp__sub_820F77AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F77B0"))) PPC_WEAK_FUNC(sub_820F77B0);
PPC_FUNC_IMPL(__imp__sub_820F77B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F77B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F77D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// addi r31,r3,2
	ctx.r31.s64 = ctx.r3.s64 + 2;
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,2
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 2, ctx.xer);
	// bne cr6,0x820f7804
	if (!ctx.cr6.eq) goto loc_820F7804;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f71e0
	ctx.lr = 0x820F77F8;
	sub_820F71E0(ctx, base);
	// rlwinm r11,r3,2,22,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0x3FC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
loc_820F7804:
	// clrlwi r9,r29,24
	ctx.r9.u64 = ctx.r29.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f7834
	if (ctx.cr6.eq) goto loc_820F7834;
	// li r11,0
	ctx.r11.s64 = 0;
loc_820F7814:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// blt cr6,0x820f7814
	if (ctx.cr6.lt) goto loc_820F7814;
loc_820F7834:
	// rlwinm r11,r28,2,22,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0x3FC;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lwz r3,1(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F7848"))) PPC_WEAK_FUNC(sub_820F7848);
PPC_FUNC_IMPL(__imp__sub_820F7848) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820F7850;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820f7980
	if (!ctx.cr6.eq) goto loc_820F7980;
	// bl 0x820f71e0
	ctx.lr = 0x820F7874;
	sub_820F71E0(ctx, base);
	// clrlwi r27,r3,24
	ctx.r27.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x820f788c
	if (!ctx.cr6.eq) goto loc_820F788C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x820F7888;
	sub_82079FD8(ctx, base);
	// b 0x820f78d0
	goto loc_820F78D0;
loc_820F788C:
	// lis r11,1365
	ctx.r11.s64 = 89456640;
	// ori r10,r11,21845
	ctx.r10.u64 = ctx.r11.u64 | 21845;
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820f78b8
	if (ctx.cr6.gt) goto loc_820F78B8;
	// rlwinm r11,r27,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r27,r11
	ctx.r9.u64 = ctx.r27.u64 + ctx.r11.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// ble cr6,0x820f78bc
	if (!ctx.cr6.gt) goto loc_820F78BC;
loc_820F78B8:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_820F78BC:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,93
	ctx.r4.u64 = ctx.r4.u64 | 93;
	// bl 0x820e9408
	ctx.lr = 0x820F78D0;
	sub_820E9408(ctx, base);
loc_820F78D0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f7908
	if (ctx.cr6.eq) goto loc_820F7908;
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
	// addic. r30,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r30.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// blt 0x820f7900
	if (ctx.cr0.lt) goto loc_820F7900;
loc_820F78EC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820f57b8
	ctx.lr = 0x820F78F4;
	sub_820F57B8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// bge 0x820f78ec
	if (!ctx.cr0.lt) goto loc_820F78EC;
loc_820F7900:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x820f790c
	goto loc_820F790C;
loc_820F7908:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820F790C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// beq cr6,0x820f79d4
	if (ctx.cr6.eq) goto loc_820F79D4;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r28,64(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
loc_820F7924:
	// clrlwi r30,r4,24
	ctx.r30.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x820f798c
	if (!ctx.cr6.lt) goto loc_820F798C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,104(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// bl 0x820f6e80
	ctx.lr = 0x820F793C;
	sub_820F6E80(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x820e7ae8
	ctx.lr = 0x820F7948;
	sub_820E7AE8(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// bl 0x820f5c70
	ctx.lr = 0x820F796C;
	sub_820F5C70(ctx, base);
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// bge cr6,0x820f7924
	if (!ctx.cr6.lt) goto loc_820F7924;
loc_820F7980:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820F798C:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x820f7980
	if (ctx.cr6.lt) goto loc_820F7980;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x820f7980
	if (ctx.cr6.eq) goto loc_820F7980;
	// li r30,0
	ctx.r30.s64 = 0;
loc_820F79A0:
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820f53f0
	ctx.lr = 0x820F79B8;
	sub_820F53F0(ctx, base);
	// addi r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 1;
	// clrlwi r30,r10,24
	ctx.r30.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x820f79a0
	if (ctx.cr6.lt) goto loc_820F79A0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820F79D4:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F79E4"))) PPC_WEAK_FUNC(sub_820F79E4);
PPC_FUNC_IMPL(__imp__sub_820F79E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F79E8"))) PPC_WEAK_FUNC(sub_820F79E8);
PPC_FUNC_IMPL(__imp__sub_820F79E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82080368
	ctx.lr = 0x820F79F8;
	__savefpr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lfs f31,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f29.f64 = double(temp.f32);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lhz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 1);
	// lfs f28,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f28.f64 = double(temp.f32);
	// bl 0x820ed130
	ctx.lr = 0x820F7A1C;
	sub_820ED130(ctx, base);
	// fmuls f0,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x820803b4
	ctx.lr = 0x820F7A38;
	__restfpr_28(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F7A44"))) PPC_WEAK_FUNC(sub_820F7A44);
PPC_FUNC_IMPL(__imp__sub_820F7A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F7A48"))) PPC_WEAK_FUNC(sub_820F7A48);
PPC_FUNC_IMPL(__imp__sub_820F7A48) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addi r9,r3,64
	ctx.r9.s64 = ctx.r3.s64 + 64;
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_820F7A60:
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820f7a94
	if (!ctx.cr6.eq) goto loc_820F7A94;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r5,r6,27
	ctx.r5.u64 = ctx.r6.u32 & 0x1F;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x820f7aa4
	if (ctx.cr6.eq) goto loc_820F7AA4;
	// cmpw cr6,r10,r3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, ctx.xer);
	// ble cr6,0x820f7a94
	if (!ctx.cr6.gt) goto loc_820F7A94;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_820F7A94:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820f7a60
	if (!ctx.cr6.eq) goto loc_820F7A60;
	// blr 
	return;
loc_820F7AA4:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F7AAC"))) PPC_WEAK_FUNC(sub_820F7AAC);
PPC_FUNC_IMPL(__imp__sub_820F7AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F7AB0"))) PPC_WEAK_FUNC(sub_820F7AB0);
PPC_FUNC_IMPL(__imp__sub_820F7AB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820F7AB8;
	__savegprlr_26(ctx, base);
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x820e6990
	ctx.lr = 0x820F7AD0;
	sub_820E6990(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r26,48(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207da20
	ctx.lr = 0x820F7AE8;
	sub_8207DA20(ctx, base);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r6,r31,64
	ctx.r6.s64 = ctx.r31.s64 + 64;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x820f7b74
	if (ctx.cr6.eq) goto loc_820F7B74;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r10,-4
	ctx.r7.s64 = ctx.r10.s64 + -4;
loc_820F7B04:
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplw cr6,r9,r26
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x820f7b68
	if (!ctx.cr6.eq) goto loc_820F7B68;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r10,9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 9, ctx.xer);
	// beq cr6,0x820f7b30
	if (ctx.cr6.eq) goto loc_820F7B30;
	// cmpwi cr6,r10,18
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 18, ctx.xer);
	// bne cr6,0x820f7b68
	if (!ctx.cr6.eq) goto loc_820F7B68;
loc_820F7B30:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmpw cr6,r10,r27
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r27.s32, ctx.xer);
	// ble cr6,0x820f7b68
	if (!ctx.cr6.gt) goto loc_820F7B68;
	// lwz r10,7(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 7);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x820f7b68
	if (ctx.cr6.lt) goto loc_820F7B68;
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x820f7b68
	if (ctx.cr6.gt) goto loc_820F7B68;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r7.u32 = ea;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x820f7b74
	if (!ctx.cr6.eq) goto loc_820F7B74;
	// cmpwi cr6,r8,256
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 256, ctx.xer);
	// beq cr6,0x820f7b74
	if (ctx.cr6.eq) goto loc_820F7B74;
loc_820F7B68:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x820f7b04
	if (!ctx.cr6.eq) goto loc_820F7B04;
loc_820F7B74:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x820f7bb8
	if (!ctx.cr6.gt) goto loc_820F7BB8;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820f7b9c
	if (ctx.cr6.eq) goto loc_820F7B9C;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820F7B9C:
	// addi r5,r8,-1
	ctx.r5.s64 = ctx.r8.s64 + -1;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820e6080
	ctx.lr = 0x820F7BAC;
	sub_820E6080(ctx, base);
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_820F7BB8:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F7BC0"))) PPC_WEAK_FUNC(sub_820F7BC0);
PPC_FUNC_IMPL(__imp__sub_820F7BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F7BC8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r29,r4,24
	ctx.r29.u64 = ctx.r4.u32 & 0xFF;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820f7bec
	if (!ctx.cr6.eq) goto loc_820F7BEC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// b 0x820f7c18
	goto loc_820F7C18;
loc_820F7BEC:
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// bne cr6,0x820f7c04
	if (!ctx.cr6.eq) goto loc_820F7C04;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 128, temp.u32);
	// b 0x820f7c18
	goto loc_820F7C18;
loc_820F7C04:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bne cr6,0x820f7c18
	if (!ctx.cr6.eq) goto loc_820F7C18;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 124, temp.u32);
loc_820F7C18:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f71e0
	ctx.lr = 0x820F7C20;
	sub_820F71E0(ctx, base);
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820f7c70
	if (ctx.cr6.eq) goto loc_820F7C70;
	// li r31,0
	ctx.r31.s64 = 0;
loc_820F7C30:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,104(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 104);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lhz r9,3(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 3);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820f7c60
	if (!ctx.cr6.eq) goto loc_820F7C60;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820f51b0
	ctx.lr = 0x820F7C60;
	sub_820F51B0(ctx, base);
loc_820F7C60:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x820f7c30
	if (ctx.cr6.lt) goto loc_820F7C30;
loc_820F7C70:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820f7ca4
	if (!ctx.cr6.eq) goto loc_820F7CA4;
	// lwz r31,48(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r30,r30,44
	ctx.r30.s64 = ctx.r30.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f7d20
	if (ctx.cr6.eq) goto loc_820F7D20;
loc_820F7C88:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa470
	ctx.lr = 0x820F7C90;
	sub_820FA470(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f7c88
	if (!ctx.cr6.eq) goto loc_820F7C88;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F7CA4:
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// bne cr6,0x820f7cbc
	if (!ctx.cr6.eq) goto loc_820F7CBC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f6c28
	ctx.lr = 0x820F7CB4;
	sub_820F6C28(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F7CBC:
	// cmplwi cr6,r29,2
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2, ctx.xer);
	// bne cr6,0x820f7d08
	if (!ctx.cr6.eq) goto loc_820F7D08;
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// bne cr6,0x820f7d08
	if (!ctx.cr6.eq) goto loc_820F7D08;
	// lwz r31,48(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r29,r30,44
	ctx.r29.s64 = ctx.r30.s64 + 44;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820f7d20
	if (ctx.cr6.eq) goto loc_820F7D20;
loc_820F7CE8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,124(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 124);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820fa518
	ctx.lr = 0x820F7CF4;
	sub_820FA518(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820f7ce8
	if (!ctx.cr6.eq) goto loc_820F7CE8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F7D08:
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// beq cr6,0x820f7d18
	if (ctx.cr6.eq) goto loc_820F7D18;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// bne cr6,0x820f7d20
	if (!ctx.cr6.eq) goto loc_820F7D20;
loc_820F7D18:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f6bd8
	ctx.lr = 0x820F7D20;
	sub_820F6BD8(ctx, base);
loc_820F7D20:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F7D28"))) PPC_WEAK_FUNC(sub_820F7D28);
PPC_FUNC_IMPL(__imp__sub_820F7D28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F7D30;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f7dac
	if (ctx.cr6.eq) goto loc_820F7DAC;
	// bl 0x820f71e0
	ctx.lr = 0x820F7D50;
	sub_820F71E0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820f7dac
	if (ctx.cr6.eq) goto loc_820F7DAC;
loc_820F7D60:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x820f7dac
	if (!ctx.cr6.eq) goto loc_820F7DAC;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// rlwinm r11,r11,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1FE;
	// clrlwi r7,r30,24
	ctx.r7.u64 = ctx.r30.u32 & 0xFF;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r6,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lhz r3,3(r4)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r4.u32 + 3);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820f7d9c
	if (!ctx.cr6.eq) goto loc_820F7D9C;
	// li r29,1
	ctx.r29.s64 = 1;
loc_820F7D9C:
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820f7d60
	if (ctx.cr6.lt) goto loc_820F7D60;
loc_820F7DAC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F7DB8"))) PPC_WEAK_FUNC(sub_820F7DB8);
PPC_FUNC_IMPL(__imp__sub_820F7DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820F7DC0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r10,r11,19572
	ctx.r10.s64 = ctx.r11.s64 + 19572;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x820f8510
	ctx.lr = 0x820F7DEC;
	sub_820F8510(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r27,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r27.u32);
	// addi r7,r9,20656
	ctx.r7.s64 = ctx.r9.s64 + 20656;
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// addi r6,r8,20640
	ctx.r6.s64 = ctx.r8.s64 + 20640;
	// stw r28,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r28.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// addi r3,r5,16136
	ctx.r3.s64 = ctx.r5.s64 + 16136;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// addi r9,r31,64
	ctx.r9.s64 = ctx.r31.s64 + 64;
	// stw r29,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// addi r10,r31,76
	ctx.r10.s64 = ctx.r31.s64 + 76;
	// stb r11,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r11.u8);
	// stw r3,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r9,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r9.u32);
	// lfs f0,14004(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// lfs f13,9388(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 9388);
	ctx.f13.f64 = double(temp.f32);
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stfs f0,124(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r11.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x820F7EA8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// addi r3,r4,19616
	ctx.r3.s64 = ctx.r4.s64 + 19616;
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lfsx f0,r9,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// cmpwi cr6,r11,2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2400, ctx.xer);
	// blt cr6,0x820f7ee0
	if (ctx.cr6.lt) goto loc_820F7EE0;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,23040(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820f7f14
	goto loc_820F7F14;
loc_820F7EE0:
	// cmpwi cr6,r11,-2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2400, ctx.xer);
	// bgt cr6,0x820f7ef4
	if (ctx.cr6.gt) goto loc_820F7EF4;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,-20792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -20792);
	ctx.f0.f64 = double(temp.f32);
	// b 0x820f7f14
	goto loc_820F7F14;
loc_820F7EF4:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,19576(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 19576);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
loc_820F7F14:
	// stfs f0,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f7598
	ctx.lr = 0x820F7F24;
	sub_820F7598(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F7F30"))) PPC_WEAK_FUNC(sub_820F7F30);
PPC_FUNC_IMPL(__imp__sub_820F7F30) {
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
	// bl 0x820f7268
	ctx.lr = 0x820F7F50;
	sub_820F7268(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f7f70
	if (ctx.cr6.eq) goto loc_820F7F70;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32875
	ctx.r4.u64 = ctx.r4.u64 | 32875;
	// bl 0x820e9410
	ctx.lr = 0x820F7F6C;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820F7F70:
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

__attribute__((alias("__imp__sub_820F7F88"))) PPC_WEAK_FUNC(sub_820F7F88);
PPC_FUNC_IMPL(__imp__sub_820F7F88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F7F90;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820f8050
	if (!ctx.cr6.eq) goto loc_820F8050;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F7FBC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f8004
	if (!ctx.cr6.eq) goto loc_820F8004;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f6d78
	ctx.lr = 0x820F7FCC;
	sub_820F6D78(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x820f7fe8
	if (ctx.cr6.eq) goto loc_820F7FE8;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x820f8004
	if (!ctx.cr6.eq) goto loc_820F8004;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F7FE8:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f7598
	ctx.lr = 0x820F7FF4;
	sub_820F7598(ctx, base);
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,8
	ctx.r3.u64 = ctx.r3.u64 | 8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F8004:
	// lwz r31,48(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// addi r28,r30,44
	ctx.r28.s64 = ctx.r30.s64 + 44;
loc_820F800C:
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820f8030
	if (ctx.cr6.eq) goto loc_820F8030;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa210
	ctx.lr = 0x820F801C;
	sub_820FA210(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820f800c
	if (!ctx.cr6.lt) goto loc_820F800C;
	// b 0x820f8070
	goto loc_820F8070;
loc_820F8030:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x820f8070
	if (ctx.cr6.lt) goto loc_820F8070;
	// bl 0x820e6990
	ctx.lr = 0x820F803C;
	sub_820E6990(ctx, base);
	// stw r3,108(r30)
	PPC_STORE_U32(ctx.r30.u32 + 108, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820f7598
	ctx.lr = 0x820F804C;
	sub_820F7598(ctx, base);
	// b 0x820f8070
	goto loc_820F8070;
loc_820F8050:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bge cr6,0x820f8068
	if (!ctx.cr6.lt) goto loc_820F8068;
	// lbz r11,60(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 60);
	// ori r10,r11,64
	ctx.r10.u64 = ctx.r11.u64 | 64;
	// stb r10,60(r30)
	PPC_STORE_U8(ctx.r30.u32 + 60, ctx.r10.u8);
	// b 0x820f8070
	goto loc_820F8070;
loc_820F8068:
	// lis r29,-30009
	ctx.r29.s64 = -1966669824;
	// ori r29,r29,6
	ctx.r29.u64 = ctx.r29.u64 | 6;
loc_820F8070:
	// lwz r31,36(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// addi r30,r31,204
	ctx.r30.s64 = ctx.r31.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8080;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r11,240(r31)
	PPC_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F809C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F80A4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F80B0"))) PPC_WEAK_FUNC(sub_820F80B0);
PPC_FUNC_IMPL(__imp__sub_820F80B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F80B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bne cr6,0x820f80e8
	if (!ctx.cr6.eq) goto loc_820F80E8;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// li r29,1
	ctx.r29.s64 = 1;
	// rlwinm r11,r11,0,27,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, ctx.r11.u8);
loc_820F80E8:
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x820f815c
	if (ctx.cr6.eq) goto loc_820F815C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x820f8114
	if (!ctx.cr6.eq) goto loc_820F8114;
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820f815c
	if (!ctx.cr6.eq) goto loc_820F815C;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820f815c
	if (ctx.cr6.eq) goto loc_820F815C;
	// b 0x820f811c
	goto loc_820F811C;
loc_820F8114:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x820f8124
	if (ctx.cr6.eq) goto loc_820F8124;
loc_820F811C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
loc_820F8124:
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f7598
	ctx.lr = 0x820F8130;
	sub_820F7598(ctx, base);
	// addi r28,r31,44
	ctx.r28.s64 = ctx.r31.s64 + 44;
	// lwz r31,48(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
loc_820F8138:
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820f815c
	if (ctx.cr6.eq) goto loc_820F815C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa218
	ctx.lr = 0x820F814C;
	sub_820FA218(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x820f8138
	if (!ctx.cr6.lt) goto loc_820F8138;
loc_820F815C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8168"))) PPC_WEAK_FUNC(sub_820F8168);
PPC_FUNC_IMPL(__imp__sub_820F8168) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820F8170;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// beq cr6,0x820f84f4
	if (ctx.cr6.eq) goto loc_820F84F4;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x820f8338
	if (ctx.cr6.eq) goto loc_820F8338;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x820f8338
	if (ctx.cr6.eq) goto loc_820F8338;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x820f8210
	if (!ctx.cr6.eq) goto loc_820F8210;
	// lwz r11,48(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820f81d8
	if (ctx.cr6.eq) goto loc_820F81D8;
loc_820F81B4:
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f8210
	if (ctx.cr6.eq) goto loc_820F8210;
	// lwz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x820f8210
	if (!ctx.cr6.eq) goto loc_820F8210;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820f81b4
	if (!ctx.cr6.eq) goto loc_820F81B4;
loc_820F81D8:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820f7598
	ctx.lr = 0x820F81E4;
	sub_820F7598(ctx, base);
	// lbz r11,60(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 60);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// bne cr6,0x820f8210
	if (!ctx.cr6.eq) goto loc_820F8210;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r11,r11,0,26,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r11,60(r29)
	PPC_STORE_U8(ctx.r29.u32 + 60, ctx.r11.u8);
	// bl 0x820f7f88
	ctx.lr = 0x820F8208;
	sub_820F7F88(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f84f4
	if (ctx.cr6.lt) goto loc_820F84F4;
loc_820F8210:
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x820f8264
	if (!ctx.cr6.eq) goto loc_820F8264;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820f71e0
	ctx.lr = 0x820F822C;
	sub_820F71E0(ctx, base);
	// clrlwi r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820f8264
	if (ctx.cr6.eq) goto loc_820F8264;
	// li r31,0
	ctx.r31.s64 = 0;
loc_820F823C:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 104);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820f5590
	ctx.lr = 0x820F8254;
	sub_820F5590(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// clrlwi r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x820f823c
	if (ctx.cr6.lt) goto loc_820F823C;
loc_820F8264:
	// lwz r31,48(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	// addi r30,r29,44
	ctx.r30.s64 = ctx.r29.s64 + 44;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f8288
	if (ctx.cr6.eq) goto loc_820F8288;
loc_820F8274:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fb148
	ctx.lr = 0x820F827C;
	sub_820FB148(ctx, base);
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f8274
	if (!ctx.cr6.eq) goto loc_820F8274;
loc_820F8288:
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// addi r30,r29,64
	ctx.r30.s64 = ctx.r29.s64 + 64;
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f82e8
	if (ctx.cr6.eq) goto loc_820F82E8;
loc_820F8298:
	// lwz r11,36(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x820f82e8
	if (ctx.cr6.gt) goto loc_820F82E8;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
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
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820F82DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f8298
	if (!ctx.cr6.eq) goto loc_820F8298;
loc_820F82E8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r11,14152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 14152);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f83ac
	if (ctx.cr6.eq) goto loc_820F83AC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8208a498
	ctx.lr = 0x820F8300;
	sub_8208A498(ctx, base);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mulli r9,r10,1000
	ctx.r9.s64 = ctx.r10.s64 * 1000;
	// rotldi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u64, 1);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// ld r11,-5872(r11)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r11.u32 + -5872);
	// divd r8,r9,r11
	ctx.r8.s64 = ppc_divd(ctx.r9.s64, ctx.r11.s64);
	// andc r6,r11,r7
	ctx.r6.u64 = ctx.r11.u64 & ~ctx.r7.u64;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// tdllei r11,0
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// tdlgei r6,-1
	// clrlwi r3,r5,1
	ctx.r3.u64 = ctx.r5.u32 & 0x7FFFFFFF;
	// b 0x820f83b0
	goto loc_820F83B0;
loc_820F8338:
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x820f86d8
	ctx.lr = 0x820F8340;
	sub_820F86D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8350
	if (ctx.cr6.eq) goto loc_820F8350;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820f6b88
	ctx.lr = 0x820F8350;
	sub_820F6B88(ctx, base);
loc_820F8350:
	// lwz r11,48(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	// addi r9,r29,44
	ctx.r9.s64 = ctx.r29.s64 + 44;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820f8398
	if (ctx.cr6.eq) goto loc_820F8398;
loc_820F8360:
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f838c
	if (ctx.cr6.eq) goto loc_820F838C;
	// lwz r8,40(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r8,4
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 4, ctx.xer);
	// beq cr6,0x820f8210
	if (ctx.cr6.eq) goto loc_820F8210;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f838c
	if (ctx.cr6.eq) goto loc_820F838C;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// beq cr6,0x820f8210
	if (ctx.cr6.eq) goto loc_820F8210;
loc_820F838C:
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820f8360
	if (!ctx.cr6.eq) goto loc_820F8360;
loc_820F8398:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820f7598
	ctx.lr = 0x820F83A4;
	sub_820F7598(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820F83AC:
	// bl 0x82089758
	ctx.lr = 0x820F83B0;
	sub_82089758(ctx, base);
loc_820F83B0:
	// lwz r11,36(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lwz r31,68(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// lwz r11,100(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// add r27,r11,r3
	ctx.r27.u64 = ctx.r11.u64 + ctx.r3.u64;
	// beq cr6,0x820f8448
	if (ctx.cr6.eq) goto loc_820F8448;
loc_820F83C8:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r28,4(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpw cr6,r11,r27
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r27.s32, ctx.xer);
	// bgt cr6,0x820f8448
	if (ctx.cr6.gt) goto loc_820F8448;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r11,r10,27
	ctx.r11.u64 = ctx.r10.u32 & 0x1F;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x820f83f4
	if (ctx.cr6.eq) goto loc_820F83F4;
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// bne cr6,0x820f843c
	if (!ctx.cr6.eq) goto loc_820F843C;
loc_820F83F4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82102b20
	ctx.lr = 0x820F83FC;
	sub_82102B20(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8434
	if (ctx.cr6.eq) goto loc_820F8434;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r31,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r31.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x820f843c
	if (ctx.cr6.eq) goto loc_820F843C;
loc_820F841C:
	// lwz r31,4(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821023e0
	ctx.lr = 0x820F8424;
	sub_821023E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f841c
	if (!ctx.cr6.eq) goto loc_820F841C;
	// b 0x820f843c
	goto loc_820F843C;
loc_820F8434:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821023e0
	ctx.lr = 0x820F843C;
	sub_821023E0(ctx, base);
loc_820F843C:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820f83c8
	if (!ctx.cr6.eq) goto loc_820F83C8;
loc_820F8448:
	// lwz r31,80(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// addi r28,r29,76
	ctx.r28.s64 = ctx.r29.s64 + 76;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820f84f4
	if (ctx.cr6.eq) goto loc_820F84F4;
loc_820F8458:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r30,4(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 40);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,128
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 128, ctx.xer);
	// bne cr6,0x820f84e8
	if (!ctx.cr6.eq) goto loc_820F84E8;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r8,0,1,1
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40000000;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820f848c
	if (ctx.cr6.eq) goto loc_820F848C;
	// lwz r27,20(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// b 0x820f84a4
	goto loc_820F84A4;
loc_820F848C:
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,64
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64, ctx.xer);
	// bne cr6,0x820f84a0
	if (!ctx.cr6.eq) goto loc_820F84A0;
	// lwz r27,24(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// b 0x820f84a4
	goto loc_820F84A4;
loc_820F84A0:
	// lwz r27,28(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
loc_820F84A4:
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r26,84(r10)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// bl 0x821024a0
	ctx.lr = 0x820F84B4;
	sub_821024A0(ctx, base);
	// subf r9,r27,r26
	ctx.r9.s64 = ctx.r26.s64 - ctx.r27.s64;
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x820f84e8
	if (ctx.cr6.lt) goto loc_820F84E8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r31,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r31.u32);
	// stw r31,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r31.u32);
	// bl 0x82102908
	ctx.lr = 0x820F84E8;
	sub_82102908(ctx, base);
loc_820F84E8:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x820f8458
	if (!ctx.cr6.eq) goto loc_820F8458;
loc_820F84F4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F84FC"))) PPC_WEAK_FUNC(sub_820F84FC);
PPC_FUNC_IMPL(__imp__sub_820F84FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8500"))) PPC_WEAK_FUNC(sub_820F8500);
PPC_FUNC_IMPL(__imp__sub_820F8500) {
	PPC_FUNC_PROLOGUE();
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820f80b0
	sub_820F80B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F850C"))) PPC_WEAK_FUNC(sub_820F850C);
PPC_FUNC_IMPL(__imp__sub_820F850C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8510"))) PPC_WEAK_FUNC(sub_820F8510);
PPC_FUNC_IMPL(__imp__sub_820F8510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r9,20684
	ctx.r8.s64 = ctx.r9.s64 + 20684;
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r11.u16);
	// lfs f0,14004(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8544"))) PPC_WEAK_FUNC(sub_820F8544);
PPC_FUNC_IMPL(__imp__sub_820F8544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8548"))) PPC_WEAK_FUNC(sub_820F8548);
PPC_FUNC_IMPL(__imp__sub_820F8548) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,20684
	ctx.r10.s64 = ctx.r11.s64 + 20684;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8558"))) PPC_WEAK_FUNC(sub_820F8558);
PPC_FUNC_IMPL(__imp__sub_820F8558) {
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
	// addi r9,r11,20684
	ctx.r9.s64 = ctx.r11.s64 + 20684;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x820f8594
	if (ctx.cr6.eq) goto loc_820F8594;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32886
	ctx.r4.u64 = ctx.r4.u64 | 32886;
	// bl 0x820e9410
	ctx.lr = 0x820F8590;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820F8594:
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

__attribute__((alias("__imp__sub_820F85A8"))) PPC_WEAK_FUNC(sub_820F85A8);
PPC_FUNC_IMPL(__imp__sub_820F85A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F85B0;
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
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x820e6990
	ctx.lr = 0x820F85C8;
	sub_820E6990(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r30,1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 1, ctx.xer);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// rlwinm r11,r10,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// beq cr6,0x820f8614
	if (ctx.cr6.eq) goto loc_820F8614;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// bne cr6,0x820f8634
	if (!ctx.cr6.eq) goto loc_820F8634;
	// sth r29,8(r31)
	PPC_STORE_U16(ctx.r31.u32 + 8, ctx.r29.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// beq cr6,0x820f8634
	if (ctx.cr6.eq) goto loc_820F8634;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F8614:
	// sth r29,8(r31)
	PPC_STORE_U16(ctx.r31.u32 + 8, ctx.r29.u16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// beq cr6,0x820f8634
	if (ctx.cr6.eq) goto loc_820F8634;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_820F8634:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F863C"))) PPC_WEAK_FUNC(sub_820F863C);
PPC_FUNC_IMPL(__imp__sub_820F863C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8640"))) PPC_WEAK_FUNC(sub_820F8640);
PPC_FUNC_IMPL(__imp__sub_820F8640) {
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
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x820f86a0
	if (ctx.cr6.eq) goto loc_820F86A0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x820f8684
	if (ctx.cr6.eq) goto loc_820F8684;
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
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
loc_820F8684:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfd f0,20704(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 20704);
	// fmul f1,f13,f0
	ctx.f1.f64 = ctx.f13.f64 * ctx.f0.f64;
	// bl 0x8207ae60
	ctx.lr = 0x820F8698;
	sub_8207AE60(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// b 0x820f86c0
	goto loc_820F86C0;
loc_820F86A0:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f2,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfd f1,19584(r11)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r11.u32 + 19584);
	// bl 0x8207b7a8
	ctx.lr = 0x820F86B0;
	sub_8207B7A8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,20700(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20700);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_820F86C0:
	// stfs f12,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
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

__attribute__((alias("__imp__sub_820F86D8"))) PPC_WEAK_FUNC(sub_820F86D8);
PPC_FUNC_IMPL(__imp__sub_820F86D8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x820f8798
	if (!ctx.cr6.eq) goto loc_820F8798;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,14004(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x820f8754
	if (ctx.cr6.eq) goto loc_820F8754;
	// bl 0x820e6990
	ctx.lr = 0x820F8714;
	sub_820E6990(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// subf r9,r11,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r11.s64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
	// stfs f8,20(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// b 0x820f8758
	goto loc_820F8758;
loc_820F8754:
	// stfs f31,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
loc_820F8758:
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x820f878c
	if (ctx.cr6.lt) goto loc_820F878C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f31,4(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F8784;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820f8840
	goto loc_820F8840;
loc_820F878C:
	// bl 0x820f8640
	ctx.lr = 0x820F8790;
	sub_820F8640(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820f8840
	goto loc_820F8840;
loc_820F8798:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x820f883c
	if (!ctx.cr6.eq) goto loc_820F883C;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x820f8804
	if (ctx.cr6.eq) goto loc_820F8804;
	// bl 0x820e6990
	ctx.lr = 0x820F87B8;
	sub_820E6990(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// subf r8,r11,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r11.s64;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfs f0,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 / ctx.f10.f64));
	// fsubs f7,f0,f8
	ctx.f7.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// stfs f7,20(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// b 0x820f8808
	goto loc_820F8808;
loc_820F8804:
	// stfs f31,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
loc_820F8808:
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x820f878c
	if (ctx.cr6.gt) goto loc_820F878C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f31,4(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F8834;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820f8840
	goto loc_820F8840;
loc_820F883C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820F8840:
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

__attribute__((alias("__imp__sub_820F8858"))) PPC_WEAK_FUNC(sub_820F8858);
PPC_FUNC_IMPL(__imp__sub_820F8858) {
	PPC_FUNC_PROLOGUE();
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addi r11,r3,72
	ctx.r11.s64 = ctx.r3.s64 + 72;
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
loc_820F886C:
	// mfmsr r7
	ctx.r7.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r8,0,r6
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r6.u32);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r9,0,r6
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r6.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f886c
	if (!ctx.cr0.eq) goto loc_820F886C;
	// lwz r9,-16(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820f8904
	if (!ctx.cr6.eq) goto loc_820F8904;
loc_820F8890:
	// mfmsr r8
	ctx.r8.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r9,0,r11
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r11.u32);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r10,0,r11
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r11.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f8890
	if (!ctx.cr0.eq) goto loc_820F8890;
	// lbz r11,60(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// beq cr6,0x820f88c4
	if (ctx.cr6.eq) goto loc_820F88C4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f88c4
	if (ctx.cr6.eq) goto loc_820F88C4;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, ctx.r11.u8);
loc_820F88C4:
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r3,64
	ctx.r8.s64 = ctx.r3.s64 + 64;
loc_820F88CC:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r8
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r8.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f88cc
	if (!ctx.cr0.eq) goto loc_820F88CC;
	// addi r4,r3,68
	ctx.r4.s64 = ctx.r3.s64 + 68;
loc_820F88E8:
	// mfmsr r6
	ctx.r6.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r7,0,r4
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r4.u32);
	ctx.r7.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r5,0,r4
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r4.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r5.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r6,1
	ctx.msr = (ctx.r6.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f88e8
	if (!ctx.cr0.eq) goto loc_820F88E8;
	// blr 
	return;
loc_820F8904:
	// addi r11,r3,68
	ctx.r11.s64 = ctx.r3.s64 + 68;
loc_820F8908:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r11.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r5,0,r11
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r11.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r5.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f8908
	if (!ctx.cr0.eq) goto loc_820F8908;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8924"))) PPC_WEAK_FUNC(sub_820F8924);
PPC_FUNC_IMPL(__imp__sub_820F8924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8928"))) PPC_WEAK_FUNC(sub_820F8928);
PPC_FUNC_IMPL(__imp__sub_820F8928) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// b 0x820f4160
	sub_820F4160(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8930"))) PPC_WEAK_FUNC(sub_820F8930);
PPC_FUNC_IMPL(__imp__sub_820F8930) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// b 0x820f41e8
	sub_820F41E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8938"))) PPC_WEAK_FUNC(sub_820F8938);
PPC_FUNC_IMPL(__imp__sub_820F8938) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F8958"))) PPC_WEAK_FUNC(sub_820F8958);
PPC_FUNC_IMPL(__imp__sub_820F8958) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F895C"))) PPC_WEAK_FUNC(sub_820F895C);
PPC_FUNC_IMPL(__imp__sub_820F895C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8960"))) PPC_WEAK_FUNC(sub_820F8960);
PPC_FUNC_IMPL(__imp__sub_820F8960) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F8968;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x820be318
	ctx.lr = 0x820F8980;
	sub_820BE318(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3e28
	ctx.lr = 0x820F8990;
	sub_820F3E28(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ea8
	ctx.lr = 0x820F8998;
	sub_820F3EA8(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r28,r31,64
	ctx.r28.s64 = ctx.r31.s64 + 64;
	// bl 0x820f3f10
	ctx.lr = 0x820F89A8;
	sub_820F3F10(ctx, base);
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// stb r11,64(r31)
	PPC_STORE_U8(ctx.r31.u32 + 64, ctx.r11.u8);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// stb r10,65(r31)
	PPC_STORE_U8(ctx.r31.u32 + 65, ctx.r10.u8);
	// lbz r9,2(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// stb r9,66(r31)
	PPC_STORE_U8(ctx.r31.u32 + 66, ctx.r9.u8);
	// lbz r8,3(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stb r8,67(r31)
	PPC_STORE_U8(ctx.r31.u32 + 67, ctx.r8.u8);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r6,60(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 60);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820F89DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8a0c
	if (ctx.cr6.eq) goto loc_820F8A0C;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F89FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x8215a990
	ctx.lr = 0x820F8A0C;
	sub_8215A990(ctx, base);
loc_820F8A0C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ec8
	ctx.lr = 0x820F8A14;
	sub_820F3EC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8a38
	if (ctx.cr6.eq) goto loc_820F8A38;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3eb8
	ctx.lr = 0x820F8A24;
	sub_820F3EB8(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820f3ec0
	ctx.lr = 0x820F8A30;
	sub_820F3EC0(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// b 0x820f8a50
	goto loc_820F8A50;
loc_820F8A38:
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r31,71
	ctx.r11.s64 = ctx.r31.s64 + 71;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_820F8A48:
	// stbu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x820f8a48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_820F8A48;
loc_820F8A50:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8A64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8A70"))) PPC_WEAK_FUNC(sub_820F8A70);
PPC_FUNC_IMPL(__imp__sub_820F8A70) {
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
	// addi r31,r3,204
	ctx.r31.s64 = ctx.r3.s64 + 204;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8A94;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,240(r30)
	PPC_STORE_U32(ctx.r30.u32 + 240, ctx.r11.u32);
	// bl 0x821d5394
	ctx.lr = 0x820F8AA4;
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

__attribute__((alias("__imp__sub_820F8ABC"))) PPC_WEAK_FUNC(sub_820F8ABC);
PPC_FUNC_IMPL(__imp__sub_820F8ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8AC0"))) PPC_WEAK_FUNC(sub_820F8AC0);
PPC_FUNC_IMPL(__imp__sub_820F8AC0) {
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
	// addi r31,r11,204
	ctx.r31.s64 = ctx.r11.s64 + 204;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8AE8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addic. r3,r30,-12
	ctx.xer.ca = ctx.r30.u32 > 11;
	ctx.r3.s64 = ctx.r30.s64 + -12;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x820f8b04
	if (ctx.cr0.eq) goto loc_820F8B04;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8B04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F8B04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F8B0C;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_820F8B28"))) PPC_WEAK_FUNC(sub_820F8B28);
PPC_FUNC_IMPL(__imp__sub_820F8B28) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,204
	ctx.r30.s64 = ctx.r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8B50;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x820f8b68
	if (ctx.cr6.lt) goto loc_820F8B68;
loc_820F8B5C:
	// lis r31,-30009
	ctx.r31.s64 = -1966669824;
	// ori r31,r31,6
	ctx.r31.u64 = ctx.r31.u64 | 6;
	// b 0x820f8b98
	goto loc_820F8B98;
loc_820F8B68:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x820f8b5c
	if (ctx.cr6.lt) goto loc_820F8B5C;
	// lwz r11,-12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// addi r3,r31,-12
	ctx.r3.s64 = ctx.r31.s64 + -12;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8B94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_820F8B98:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F8BA0;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_820F8BBC"))) PPC_WEAK_FUNC(sub_820F8BBC);
PPC_FUNC_IMPL(__imp__sub_820F8BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8BC0"))) PPC_WEAK_FUNC(sub_820F8BC0);
PPC_FUNC_IMPL(__imp__sub_820F8BC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F8BC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r30,r11,204
	ctx.r30.s64 = ctx.r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8BE4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// addi r3,r31,-12
	ctx.r3.s64 = ctx.r31.s64 + -12;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// subfe r4,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r9,r4,-1
	ctx.r9.s64 = ctx.r4.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r5,r8,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r11,-12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8C18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F8C24;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8C30"))) PPC_WEAK_FUNC(sub_820F8C30);
PPC_FUNC_IMPL(__imp__sub_820F8C30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F8C38;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8C54;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,72(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x820f8cac
	if (ctx.cr6.gt) goto loc_820F8CAC;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x820f8c84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F8C84;
	// bdzf 4*cr6+eq,0x820f8c8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F8C8C;
	// bdzf 4*cr6+eq,0x820f8c94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F8C94;
	// bdzf 4*cr6+eq,0x820f8c9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_820F8C9C;
	// bne cr6,0x820f8ca4
	if (!ctx.cr6.eq) goto loc_820F8CA4;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x820f8ca8
	goto loc_820F8CA8;
loc_820F8C84:
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x820f8ca8
	goto loc_820F8CA8;
loc_820F8C8C:
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x820f8ca8
	goto loc_820F8CA8;
loc_820F8C94:
	// li r11,8
	ctx.r11.s64 = 8;
	// b 0x820f8ca8
	goto loc_820F8CA8;
loc_820F8C9C:
	// li r11,16
	ctx.r11.s64 = 16;
	// b 0x820f8ca8
	goto loc_820F8CA8;
loc_820F8CA4:
	// li r11,32
	ctx.r11.s64 = 32;
loc_820F8CA8:
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_820F8CAC:
	// lhz r11,64(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 64);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r9,r11,25,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x40;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// bl 0x821d5394
	ctx.lr = 0x820F8CC8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8CD4"))) PPC_WEAK_FUNC(sub_820F8CD4);
PPC_FUNC_IMPL(__imp__sub_820F8CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8CD8"))) PPC_WEAK_FUNC(sub_820F8CD8);
PPC_FUNC_IMPL(__imp__sub_820F8CD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820F8CE0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8CFC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x820f8d24
	if (!ctx.cr6.eq) goto loc_820F8D24;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ori r28,r28,87
	ctx.r28.u64 = ctx.r28.u64 | 87;
	// bl 0x821d5394
	ctx.lr = 0x820F8D18;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820F8D24:
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// lwz r27,68(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// bl 0x820f3f48
	ctx.lr = 0x820F8D30;
	sub_820F3F48(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x820f8960
	ctx.lr = 0x820F8D3C;
	sub_820F8960(ctx, base);
	// lhz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// stw r10,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r10.u32);
	// bl 0x821d5394
	ctx.lr = 0x820F8D50;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8D5C"))) PPC_WEAK_FUNC(sub_820F8D5C);
PPC_FUNC_IMPL(__imp__sub_820F8D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8D60"))) PPC_WEAK_FUNC(sub_820F8D60);
PPC_FUNC_IMPL(__imp__sub_820F8D60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F8D68;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r29,r11,204
	ctx.r29.s64 = ctx.r11.s64 + 204;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8D88;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8db8
	if (ctx.cr6.eq) goto loc_820F8DB8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8DAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f8de4
	if (ctx.cr6.lt) goto loc_820F8DE4;
loc_820F8DB8:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f8de4
	if (ctx.cr6.eq) goto loc_820F8DE4;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8DE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820F8DE4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F8DEC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8DFC"))) PPC_WEAK_FUNC(sub_820F8DFC);
PPC_FUNC_IMPL(__imp__sub_820F8DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8E00"))) PPC_WEAK_FUNC(sub_820F8E00);
PPC_FUNC_IMPL(__imp__sub_820F8E00) {
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
	// lwz r3,88(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stfs f1,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8e34
	if (ctx.cr6.eq) goto loc_820F8E34;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8E34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F8E34:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8E44"))) PPC_WEAK_FUNC(sub_820F8E44);
PPC_FUNC_IMPL(__imp__sub_820F8E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F8E48"))) PPC_WEAK_FUNC(sub_820F8E48);
PPC_FUNC_IMPL(__imp__sub_820F8E48) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r30,r11,204
	ctx.r30.s64 = ctx.r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8E78;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8e98
	if (ctx.cr6.eq) goto loc_820F8E98;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8E98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F8E98:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f8eac
	if (ctx.cr6.eq) goto loc_820F8EAC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820f8e48
	ctx.lr = 0x820F8EAC;
	sub_820F8E48(ctx, base);
loc_820F8EAC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F8EB4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8ED0"))) PPC_WEAK_FUNC(sub_820F8ED0);
PPC_FUNC_IMPL(__imp__sub_820F8ED0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,88(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F8EEC"))) PPC_WEAK_FUNC(sub_820F8EEC);
PPC_FUNC_IMPL(__imp__sub_820F8EEC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8EF0"))) PPC_WEAK_FUNC(sub_820F8EF0);
PPC_FUNC_IMPL(__imp__sub_820F8EF0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,88(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F8F0C"))) PPC_WEAK_FUNC(sub_820F8F0C);
PPC_FUNC_IMPL(__imp__sub_820F8F0C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F8F10"))) PPC_WEAK_FUNC(sub_820F8F10);
PPC_FUNC_IMPL(__imp__sub_820F8F10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820F8F18;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r27,r11,204
	ctx.r27.s64 = ctx.r11.s64 + 204;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F8F3C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f8f6c
	if (ctx.cr6.eq) goto loc_820F8F6C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8F68;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_820F8F6C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F8F74;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F8F80"))) PPC_WEAK_FUNC(sub_820F8F80);
PPC_FUNC_IMPL(__imp__sub_820F8F80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F8F88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r4,88(r30)
	PPC_STORE_U32(ctx.r30.u32 + 88, ctx.r4.u32);
	// beq cr6,0x820f9030
	if (ctx.cr6.eq) goto loc_820F9030;
	// lwz r11,92(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f9030
	if (ctx.cr6.eq) goto loc_820F9030;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r31,56(r9)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r8,328(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 328);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x820f8fe0
	if (ctx.cr6.eq) goto loc_820F8FE0;
	// addic. r4,r31,320
	ctx.xer.ca = ctx.r31.u32 > 4294966975;
	ctx.r4.s64 = ctx.r31.s64 + 320;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x820f8fe0
	if (ctx.cr0.eq) goto loc_820F8FE0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F8FE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F8FE0:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f9030
	if (ctx.cr6.eq) goto loc_820F9030;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// addi r29,r30,12
	ctx.r29.s64 = ctx.r30.s64 + 12;
	// lwz r28,72(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r30,12(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lhz r31,76(r31)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820F9014;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,28(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// clrlwi r5,r3,16
	ctx.r5.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820F9030;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9030:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F9038"))) PPC_WEAK_FUNC(sub_820F9038);
PPC_FUNC_IMPL(__imp__sub_820F9038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F9040;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r28,r11,204
	ctx.r28.s64 = ctx.r11.s64 + 204;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F905C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lhz r11,64(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwinm r10,r11,19,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0x1;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x820f911c
	if (ctx.cr6.eq) goto loc_820F911C;
	// addic r10,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r10.s64 = ctx.r30.s64 + -1;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// subfe r9,r10,r30
	temp.u8 = (~ctx.r10.u32 + ctx.r30.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// rlwimi r11,r9,13,18,18
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 13) & 0x2000) | (ctx.r11.u64 & 0xFFFFFFFFFFFFDFFF);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r11,64(r31)
	PPC_STORE_U16(ctx.r31.u32 + 64, ctx.r11.u16);
	// beq cr6,0x820f911c
	if (ctx.cr6.eq) goto loc_820F911C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x820f90b0
	if (ctx.cr6.eq) goto loc_820F90B0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F90AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820f9118
	goto loc_820F9118;
loc_820F90B0:
	// rlwinm r11,r11,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f911c
	if (ctx.cr6.eq) goto loc_820F911C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F90D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f911c
	if (ctx.cr6.lt) goto loc_820F911C;
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// addi r11,r31,-12
	ctx.r11.s64 = ctx.r31.s64 + -12;
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// sth r9,64(r31)
	PPC_STORE_U16(ctx.r31.u32 + 64, ctx.r9.u16);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x820f8a70
	ctx.lr = 0x820F90F4;
	sub_820F8A70(ctx, base);
	// lhz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// rlwinm r7,r8,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r7,4096
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 4096, ctx.xer);
	// bne cr6,0x820f911c
	if (!ctx.cr6.eq) goto loc_820F911C;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9118;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9118:
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_820F911C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F9124;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F9130"))) PPC_WEAK_FUNC(sub_820F9130);
PPC_FUNC_IMPL(__imp__sub_820F9130) {
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
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f9168
	if (ctx.cr6.eq) goto loc_820F9168;
	// lwz r3,88(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9168;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9168:
	// lbz r11,60(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// beq cr6,0x820f9184
	if (ctx.cr6.eq) goto loc_820F9184;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f9184
	if (ctx.cr6.eq) goto loc_820F9184;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r11.u8);
loc_820F9184:
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r31,64
	ctx.r8.s64 = ctx.r31.s64 + 64;
loc_820F918C:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r8
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r8.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f918c
	if (!ctx.cr0.eq) goto loc_820F918C;
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

__attribute__((alias("__imp__sub_820F91B8"))) PPC_WEAK_FUNC(sub_820F91B8);
PPC_FUNC_IMPL(__imp__sub_820F91B8) {
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
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// ori r10,r11,1024
	ctx.r10.u64 = ctx.r11.u64 | 1024;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// sth r10,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r10.u16);
	// beq cr6,0x820f91fc
	if (ctx.cr6.eq) goto loc_820F91FC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F91F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r9.u32);
loc_820F91FC:
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

__attribute__((alias("__imp__sub_820F9210"))) PPC_WEAK_FUNC(sub_820F9210);
PPC_FUNC_IMPL(__imp__sub_820F9210) {
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
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,512
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 512, ctx.xer);
	// bne cr6,0x820f936c
	if (!ctx.cr6.eq) goto loc_820F936C;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// lbz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 60);
	// rlwinm r9,r9,0,23,21
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// sth r9,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, ctx.r9.u16);
	// beq cr6,0x820f936c
	if (ctx.cr6.eq) goto loc_820F936C;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,114
	ctx.r4.s64 = ctx.r1.s64 + 114;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9268;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f936c
	if (ctx.cr6.lt) goto loc_820F936C;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lbz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r3,308(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 308);
	// bl 0x820ef3b0
	ctx.lr = 0x820F9290;
	sub_820EF3B0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820f936c
	if (ctx.cr6.eq) goto loc_820F936C;
	// lbz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 60);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,255
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 255, ctx.xer);
	// beq cr6,0x820f92b0
	if (ctx.cr6.eq) goto loc_820F92B0;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
loc_820F92B0:
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r10,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lwz r11,16(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f92dc
	if (ctx.cr6.eq) goto loc_820F92DC;
	// lhz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
loc_820F92DC:
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r1,116
	ctx.r6.s64 = ctx.r1.s64 + 116;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lhz r4,114(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// lwz r11,80(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// li r7,1
	ctx.r7.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820F9310;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f936c
	if (ctx.cr6.lt) goto loc_820F936C;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,16(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f936c
	if (ctx.cr6.eq) goto loc_820F936C;
	// lhz r10,5(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 5);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820f936c
	if (ctx.cr6.eq) goto loc_820F936C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f2,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lfs f1,64(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,40(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lhz r7,5(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 5);
	// rlwinm r4,r7,31,30,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x3;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x820F936C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F936C:
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

__attribute__((alias("__imp__sub_820F9380"))) PPC_WEAK_FUNC(sub_820F9380);
PPC_FUNC_IMPL(__imp__sub_820F9380) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820F9388;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F93B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820f93c4
	if (!ctx.cr6.eq) goto loc_820F93C4;
	// lwz r28,80(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820f93d8
	if (!ctx.cr6.eq) goto loc_820F93D8;
loc_820F93C4:
	// lhz r11,76(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 76);
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f93dc
	if (ctx.cr6.eq) goto loc_820F93DC;
loc_820F93D8:
	// li r31,1
	ctx.r31.s64 = 1;
loc_820F93DC:
	// li r5,28
	ctx.r5.s64 = 28;
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x8207da20
	ctx.lr = 0x820F93F0;
	sub_8207DA20(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x820f949c
	if (ctx.cr6.eq) goto loc_820F949C;
	// lwz r11,92(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 92);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f943c
	if (ctx.cr6.eq) goto loc_820F943C;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r11,56(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r10,308(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 308);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f949c
	if (ctx.cr6.eq) goto loc_820F949C;
	// lhz r8,316(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 316);
	// stw r11,101(r1)
	PPC_STORE_U32(ctx.r1.u32 + 101, ctx.r11.u32);
	// stw r10,97(r1)
	PPC_STORE_U32(ctx.r1.u32 + 97, ctx.r10.u32);
	// sth r8,95(r1)
	PPC_STORE_U16(ctx.r1.u32 + 95, ctx.r8.u16);
	// b 0x820f9448
	goto loc_820F9448;
loc_820F943C:
	// stw r29,101(r1)
	PPC_STORE_U32(ctx.r1.u32 + 101, ctx.r29.u32);
	// stw r29,97(r1)
	PPC_STORE_U32(ctx.r1.u32 + 97, ctx.r29.u32);
	// sth r9,95(r1)
	PPC_STORE_U16(ctx.r1.u32 + 95, ctx.r9.u16);
loc_820F9448:
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r27.u8);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x820f945c
	if (!ctx.cr6.eq) goto loc_820F945C;
	// sth r9,93(r1)
	PPC_STORE_U16(ctx.r1.u32 + 93, ctx.r9.u16);
	// b 0x820f9468
	goto loc_820F9468;
loc_820F945C:
	// addi r3,r30,24
	ctx.r3.s64 = ctx.r30.s64 + 24;
	// bl 0x820f3f48
	ctx.lr = 0x820F9464;
	sub_820F3F48(ctx, base);
	// sth r3,93(r1)
	PPC_STORE_U16(ctx.r1.u32 + 93, ctx.r3.u16);
loc_820F9468:
	// addi r11,r30,12
	ctx.r11.s64 = ctx.r30.s64 + 12;
	// stw r28,89(r1)
	PPC_STORE_U32(ctx.r1.u32 + 89, ctx.r28.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,105(r1)
	PPC_STORE_U32(ctx.r1.u32 + 105, ctx.r11.u32);
	// lbz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 108);
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rldicr r8,r9,8,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// rldicr r7,r7,24,39
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 24) & 0xFFFFFFFFFF000000;
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x820e8970
	ctx.lr = 0x820F949C;
	sub_820E8970(ctx, base);
loc_820F949C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F94A4"))) PPC_WEAK_FUNC(sub_820F94A4);
PPC_FUNC_IMPL(__imp__sub_820F94A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F94A8"))) PPC_WEAK_FUNC(sub_820F94A8);
PPC_FUNC_IMPL(__imp__sub_820F94A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820F94B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f94e8
	if (ctx.cr6.eq) goto loc_820F94E8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// bl 0x820f3f50
	ctx.lr = 0x820F94E4;
	sub_820F3F50(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_820F94E8:
	// addi r28,r30,24
	ctx.r28.s64 = ctx.r30.s64 + 24;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820f3ea8
	ctx.lr = 0x820F94F4;
	sub_820F3EA8(ctx, base);
	// lhz r11,76(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 76);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,2048
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2048, ctx.xer);
	// beq cr6,0x820f9510
	if (ctx.cr6.eq) goto loc_820F9510;
	// lbz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r25.u32 + 0);
loc_820F9510:
	// clrlwi r29,r11,24
	ctx.r29.u64 = ctx.r11.u32 & 0xFF;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820f9558
	if (ctx.cr6.eq) goto loc_820F9558;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820f3eb8
	ctx.lr = 0x820F9530;
	sub_820F3EB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820f3ec8
	ctx.lr = 0x820F953C;
	sub_820F3EC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// beq cr6,0x820f9550
	if (ctx.cr6.eq) goto loc_820F9550;
	// bl 0x820f3ec0
	ctx.lr = 0x820F954C;
	sub_820F3EC0(ctx, base);
	// b 0x820f9554
	goto loc_820F9554;
loc_820F9550:
	// bl 0x820f3ea8
	ctx.lr = 0x820F9554;
	sub_820F3EA8(ctx, base);
loc_820F9554:
	// add r10,r3,r30
	ctx.r10.u64 = ctx.r3.u64 + ctx.r30.u64;
loc_820F9558:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820f9574
	if (!ctx.cr6.eq) goto loc_820F9574;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x820f95f4
	if (!ctx.cr6.lt) goto loc_820F95F4;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820f9604
	if (ctx.cr6.eq) goto loc_820F9604;
loc_820F9574:
	// cmplwi cr6,r29,255
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 255, ctx.xer);
	// beq cr6,0x820f960c
	if (ctx.cr6.eq) goto loc_820F960C;
	// mullw r11,r29,r3
	ctx.r11.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x820f95bc
	if (!ctx.cr6.gt) goto loc_820F95BC;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820f95c4
	if (ctx.cr6.gt) goto loc_820F95C4;
	// subf r11,r30,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r30.s64;
	// twllei r3,0
	// divwu r10,r11,r3
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r3.u32);
	// divwu r8,r11,r3
	ctx.r8.u32 = ppc_divwu(ctx.r11.u32, ctx.r3.u32);
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// mullw r6,r8,r3
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// subf r5,r7,r29
	ctx.r5.s64 = ctx.r29.s64 - ctx.r7.s64;
	// subf r11,r6,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r6.s64;
	// clrlwi r29,r5,24
	ctx.r29.u64 = ctx.r5.u32 & 0xFF;
	// b 0x820f9624
	goto loc_820F9624;
loc_820F95BC:
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820f95ec
	if (!ctx.cr6.gt) goto loc_820F95EC;
loc_820F95C4:
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// bge cr6,0x820f95f0
	if (!ctx.cr6.lt) goto loc_820F95F0;
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// li r29,0
	ctx.r29.s64 = 0;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stw r31,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// stb r29,0(r25)
	PPC_STORE_U8(ctx.r25.u32 + 0, ctx.r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_820F95EC:
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
loc_820F95F0:
	// ble cr6,0x820f962c
	if (!ctx.cr6.gt) goto loc_820F962C;
loc_820F95F4:
	// lis r3,-30009
	ctx.r3.s64 = -1966669824;
	// ori r3,r3,25
	ctx.r3.u64 = ctx.r3.u64 | 25;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_820F9604:
	// cmplwi cr6,r29,255
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 255, ctx.xer);
	// bne cr6,0x820f962c
	if (!ctx.cr6.eq) goto loc_820F962C;
loc_820F960C:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x820f962c
	if (!ctx.cr6.gt) goto loc_820F962C;
	// subf r11,r30,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r30.s64;
	// divwu r10,r11,r3
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r3.u32);
	// mullw r8,r10,r3
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf r11,r8,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r8.s64;
loc_820F9624:
	// add r31,r11,r30
	ctx.r31.u64 = ctx.r11.u64 + ctx.r30.u64;
	// twllei r3,0
loc_820F962C:
	// stw r31,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// stb r29,0(r25)
	PPC_STORE_U8(ctx.r25.u32 + 0, ctx.r29.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F9640"))) PPC_WEAK_FUNC(sub_820F9640);
PPC_FUNC_IMPL(__imp__sub_820F9640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820F9648;
	__savegprlr_26(ctx, base);
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820f9870
	if (ctx.cr6.eq) goto loc_820F9870;
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820f969c
	if (ctx.cr6.eq) goto loc_820F969C;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x820f969c
	if (!ctx.cr6.eq) goto loc_820F969C;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820f9870
	if (ctx.cr6.eq) goto loc_820F9870;
loc_820F969C:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// ori r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 | 32;
	// sth r9,76(r29)
	PPC_STORE_U16(ctx.r29.u32 + 76, ctx.r9.u16);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820F96C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,88(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 88);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// clrlwi r28,r3,16
	ctx.r28.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r11,56(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820F96E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f9870
	if (ctx.cr6.lt) goto loc_820F9870;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820f9870
	if (ctx.cr6.eq) goto loc_820F9870;
	// cmplwi cr6,r28,9
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 9, ctx.xer);
	// bge cr6,0x820f9870
	if (!ctx.cr6.lt) goto loc_820F9870;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820f9870
	if (ctx.cr6.eq) goto loc_820F9870;
	// cmplwi cr6,r30,9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 9, ctx.xer);
	// bge cr6,0x820f9870
	if (!ctx.cr6.lt) goto loc_820F9870;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// lfs f31,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// bne cr6,0x820f9730
	if (!ctx.cr6.eq) goto loc_820F9730;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820f9730
	if (ctx.cr6.eq) goto loc_820F9730;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f30,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// b 0x820f9744
	goto loc_820F9744;
loc_820F9730:
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x820e60e8
	ctx.lr = 0x820F9740;
	sub_820E60E8(ctx, base);
	// fadds f0,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f29.f64));
loc_820F9744:
	// stfs f0,100(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 100, temp.u32);
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// stfs f30,104(r29)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r29.u32 + 104, temp.u32);
	// bne cr6,0x820f97a4
	if (!ctx.cr6.eq) goto loc_820F97A4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,14296
	ctx.r31.s64 = ctx.r11.s64 + 14296;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f13,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// stfs f31,4(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f31,8(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// lfs f13,21000(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21000);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8207af40
	ctx.lr = 0x820F9784;
	sub_8207AF40(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,28(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfs f31,32(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// bl 0x8207ae60
	ctx.lr = 0x820F9798;
	sub_8207AE60(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,36(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// b 0x820f97e8
	goto loc_820F97E8;
loc_820F97A4:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,21000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21000);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8207af40
	ctx.lr = 0x820F97B8;
	sub_8207AF40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// addi r31,r11,14296
	ctx.r31.s64 = ctx.r11.s64 + 14296;
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f31,8(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// bl 0x8207ae60
	ctx.lr = 0x820F97D4;
	sub_8207AE60(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// stfs f31,28(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f31,32(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f31,36(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
loc_820F97E8:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r7,r10,14248
	ctx.r7.s64 = ctx.r10.s64 + 14248;
	// addi r11,r11,20712
	ctx.r11.s64 = ctx.r11.s64 + 20712;
	// rlwinm r10,r30,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// li r6,1
	ctx.r6.s64 = 1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r30,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r30.u32);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// stw r28,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r28.u32);
	// bne cr6,0x820f9834
	if (!ctx.cr6.eq) goto loc_820F9834;
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r10,244(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 244);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820f9834
	if (ctx.cr6.eq) goto loc_820F9834;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// ori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 | 1;
loc_820F9834:
	// lwz r11,20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r10,14196
	ctx.r4.s64 = ctx.r10.s64 + 14196;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x82161890
	ctx.lr = 0x820F984C;
	sub_82161890(ctx, base);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r3,r29,12
	ctx.r3.s64 = ctx.r29.s64 + 12;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r6,r9,-5824
	ctx.r6.s64 = ctx.r9.s64 + -5824;
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820F9870;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9870:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F9884"))) PPC_WEAK_FUNC(sub_820F9884);
PPC_FUNC_IMPL(__imp__sub_820F9884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F9888"))) PPC_WEAK_FUNC(sub_820F9888);
PPC_FUNC_IMPL(__imp__sub_820F9888) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F98AC"))) PPC_WEAK_FUNC(sub_820F98AC);
PPC_FUNC_IMPL(__imp__sub_820F98AC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F98B0"))) PPC_WEAK_FUNC(sub_820F98B0);
PPC_FUNC_IMPL(__imp__sub_820F98B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820F98D4"))) PPC_WEAK_FUNC(sub_820F98D4);
PPC_FUNC_IMPL(__imp__sub_820F98D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820F98D8"))) PPC_WEAK_FUNC(sub_820F98D8);
PPC_FUNC_IMPL(__imp__sub_820F98D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x820F98E0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// mr r23,r9
	ctx.r23.u64 = ctx.r9.u64;
	// mr r24,r8
	ctx.r24.u64 = ctx.r8.u64;
	// addi r9,r11,16136
	ctx.r9.s64 = ctx.r11.s64 + 16136;
	// addi r8,r10,19572
	ctx.r8.s64 = ctx.r10.s64 + 19572;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r28,r3,24
	ctx.r28.s64 = ctx.r3.s64 + 24;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// addi r27,r3,16
	ctx.r27.s64 = ctx.r3.s64 + 16;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// bl 0x820be318
	ctx.lr = 0x820F9930;
	sub_820BE318(ctx, base);
	// addic r7,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r7.s64 = ctx.r24.s64 + -1;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r30,0
	ctx.r30.s64 = 0;
	// subfe r6,r7,r24
	temp.u8 = (~ctx.r7.u32 + ctx.r24.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r24.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r24.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// addic r5,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r5.s64 = ctx.r25.s64 + -1;
	// stw r23,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r23.u32);
	// stb r30,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r30.u8);
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// subfe r11,r5,r25
	temp.u8 = (~ctx.r5.u32 + ctx.r25.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r25.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r5.u64 + ctx.r25.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r30,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r30.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// rlwimi r11,r6,1,30,30
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 1) & 0x2) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// rlwimi r10,r11,3,27,28
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 3) & 0x18) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// rlwinm r9,r10,0,20,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFF8;
	// rlwinm r9,r9,0,27,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFF81F;
	// sth r9,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r9.u16);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x820F9998;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x820f3e28
	ctx.lr = 0x820F99B0;
	sub_820F3E28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F99BC"))) PPC_WEAK_FUNC(sub_820F99BC);
PPC_FUNC_IMPL(__imp__sub_820F99BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F99C0"))) PPC_WEAK_FUNC(sub_820F99C0);
PPC_FUNC_IMPL(__imp__sub_820F99C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F99C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r30,r11,204
	ctx.r30.s64 = ctx.r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x820F99E4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// extsh r11,r29
	ctx.r11.s64 = ctx.r29.s16;
	// cmpwi cr6,r11,2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2400, ctx.xer);
	// blt cr6,0x820f99fc
	if (ctx.cr6.lt) goto loc_820F99FC;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f1,23040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f1.f64 = double(temp.f32);
	// b 0x820f9a30
	goto loc_820F9A30;
loc_820F99FC:
	// cmpwi cr6,r11,-2400
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -2400, ctx.xer);
	// bgt cr6,0x820f9a10
	if (ctx.cr6.gt) goto loc_820F9A10;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f1,-20792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -20792);
	ctx.f1.f64 = double(temp.f32);
	// b 0x820f9a30
	goto loc_820F9A30;
loc_820F9A10:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,19576(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 19576);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
loc_820F9A30:
	// addi r3,r31,-12
	ctx.r3.s64 = ctx.r31.s64 + -12;
	// bl 0x820f8e48
	ctx.lr = 0x820F9A38;
	sub_820F8E48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x820F9A40;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F9A4C"))) PPC_WEAK_FUNC(sub_820F9A4C);
PPC_FUNC_IMPL(__imp__sub_820F9A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820F9A50"))) PPC_WEAK_FUNC(sub_820F9A50);
PPC_FUNC_IMPL(__imp__sub_820F9A50) {
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
	// cmpwi cr6,r4,3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 3, ctx.xer);
	// bne cr6,0x820f9a8c
	if (!ctx.cr6.eq) goto loc_820F9A8C;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x820f9abc
	if (!ctx.cr6.lt) goto loc_820F9ABC;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r4,13
	ctx.r4.s64 = 13;
	// b 0x820f9ab0
	goto loc_820F9AB0;
loc_820F9A8C:
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// bne cr6,0x820f9abc
	if (!ctx.cr6.eq) goto loc_820F9ABC;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x820f9abc
	if (ctx.cr6.lt) goto loc_820F9ABC;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x820f9abc
	if (!ctx.cr6.lt) goto loc_820F9ABC;
	// li r11,5
	ctx.r11.s64 = 5;
	// li r4,14
	ctx.r4.s64 = 14;
loc_820F9AB0:
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9ABC;
	sub_820F9380(ctx, base);
loc_820F9ABC:
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_820F9AD8"))) PPC_WEAK_FUNC(sub_820F9AD8);
PPC_FUNC_IMPL(__imp__sub_820F9AD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820F9AE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820f9da8
	if (!ctx.cr6.eq) goto loc_820F9DA8;
	// rlwinm r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// beq cr6,0x820f9da8
	if (ctx.cr6.eq) goto loc_820F9DA8;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x820f9da8
	if (!ctx.cr6.lt) goto loc_820F9DA8;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// ble cr6,0x820f9b5c
	if (!ctx.cr6.gt) goto loc_820F9B5C;
	// addi r8,r3,68
	ctx.r8.s64 = ctx.r3.s64 + 68;
loc_820F9B24:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r8
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r8.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820f9b48
	if (!ctx.cr6.eq) goto loc_820F9B48;
	// stwcx. r28,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r28.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f9b24
	if (!ctx.cr0.eq) goto loc_820F9B24;
	// b 0x820f9b50
	goto loc_820F9B50;
loc_820F9B48:
	// stwcx. r11,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_820F9B50:
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x820f9b78
	if (!ctx.cr6.eq) goto loc_820F9B78;
loc_820F9B5C:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r9,r11,0,18,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820f9c28
	if (ctx.cr6.eq) goto loc_820F9C28;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x820f9c28
	if (!ctx.cr6.eq) goto loc_820F9C28;
loc_820F9B78:
	// lwz r29,84(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r30,5
	ctx.r30.s64 = 5;
	// cmpwi cr6,r29,3
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 3, ctx.xer);
	// blt cr6,0x820f9ba0
	if (ctx.cr6.lt) goto loc_820F9BA0;
	// cmpwi cr6,r29,5
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 5, ctx.xer);
	// bge cr6,0x820f9ba0
	if (!ctx.cr6.lt) goto loc_820F9BA0;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9BA0;
	sub_820F9380(ctx, base);
loc_820F9BA0:
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// lwz r30,96(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820f9d6c
	if (ctx.cr6.eq) goto loc_820F9D6C;
	// cmpwi cr6,r29,4
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 4, ctx.xer);
	// bge cr6,0x820f9d6c
	if (!ctx.cr6.lt) goto loc_820F9D6C;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r3,56(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x820ed1f8
	ctx.lr = 0x820F9BD4;
	sub_820ED1F8(ctx, base);
	// stw r28,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r28.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,148(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 148);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820F9BF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r28,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r28.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r31,100
	ctx.r5.s64 = ctx.r31.s64 + 100;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9C18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f91b8
	ctx.lr = 0x820F9C20;
	sub_820F91B8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F9C28:
	// addi r8,r31,64
	ctx.r8.s64 = ctx.r31.s64 + 64;
loc_820F9C2C:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r8
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r8.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x820f9c50
	if (!ctx.cr6.eq) goto loc_820F9C50;
	// stwcx. r28,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r28.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x820f9c2c
	if (!ctx.cr0.eq) goto loc_820F9C2C;
	// b 0x820f9c58
	goto loc_820F9C58;
loc_820F9C50:
	// stwcx. r11,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_820F9C58:
	// mr r11,r11
	ctx.r11.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820f9c90
	if (ctx.cr6.eq) goto loc_820F9C90;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9C70;
	sub_820F9380(ctx, base);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f9c90
	if (ctx.cr6.eq) goto loc_820F9C90;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9C90;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9C90:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f9da8
	if (ctx.cr6.eq) goto loc_820F9DA8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9CB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820f9da8
	if (ctx.cr6.lt) goto loc_820F9DA8;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x820f9cec
	if (!ctx.cr6.eq) goto loc_820F9CEC;
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,8192
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8192, ctx.xer);
	// beq cr6,0x820f9cec
	if (ctx.cr6.eq) goto loc_820F9CEC;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x820f9cec
	if (!ctx.cr6.eq) goto loc_820F9CEC;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// sth r11,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
loc_820F9CEC:
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bge cr6,0x820f9d28
	if (!ctx.cr6.lt) goto loc_820F9D28;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x820f9d20
	if (!ctx.cr6.eq) goto loc_820F9D20;
	// li r30,3
	ctx.r30.s64 = 3;
	// li r4,13
	ctx.r4.s64 = 13;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9D14;
	sub_820F9380(ctx, base);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F9D20:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// blt cr6,0x820f9da8
	if (ctx.cr6.lt) goto loc_820F9DA8;
loc_820F9D28:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x820f9da8
	if (ctx.cr6.eq) goto loc_820F9DA8;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// beq cr6,0x820f9da8
	if (ctx.cr6.eq) goto loc_820F9DA8;
	// rlwinm r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// beq cr6,0x820f9da8
	if (ctx.cr6.eq) goto loc_820F9DA8;
	// li r30,5
	ctx.r30.s64 = 5;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bge cr6,0x820f9d68
	if (!ctx.cr6.lt) goto loc_820F9D68;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9D68;
	sub_820F9380(ctx, base);
loc_820F9D68:
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
loc_820F9D6C:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f9d90
	if (ctx.cr6.eq) goto loc_820F9D90;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9D88;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820F9D90:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x820f9da8
	if (!ctx.cr6.eq) goto loc_820F9DA8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f91b8
	ctx.lr = 0x820F9DA8;
	sub_820F91B8(ctx, base);
loc_820F9DA8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820F9DB0"))) PPC_WEAK_FUNC(sub_820F9DB0);
PPC_FUNC_IMPL(__imp__sub_820F9DB0) {
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
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r9,r11,256
	ctx.r9.u64 = ctx.r11.u64 | 256;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// sth r9,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, ctx.r9.u16);
	// beq cr6,0x820f9e04
	if (ctx.cr6.eq) goto loc_820F9E04;
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x820f9e04
	if (ctx.cr6.eq) goto loc_820F9E04;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r3,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// stw r3,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
loc_820F9E04:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f9e24
	if (ctx.cr6.eq) goto loc_820F9E24;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9E24;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9E24:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820f9e40
	if (ctx.cr6.eq) goto loc_820F9E40;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9E40;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9E40:
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820f9e64
	if (ctx.cr6.eq) goto loc_820F9E64;
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
	ctx.lr = 0x820F9E64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820F9E64:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// li r30,5
	ctx.r30.s64 = 5;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x820f9e8c
	if (ctx.cr6.lt) goto loc_820F9E8C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x820f9e8c
	if (!ctx.cr6.lt) goto loc_820F9E8C;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9E8C;
	sub_820F9380(ctx, base);
loc_820F9E8C:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r4,r31,16
	ctx.r4.s64 = ctx.r31.s64 + 16;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9EAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9EB8;
	sub_820F9380(ctx, base);
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

__attribute__((alias("__imp__sub_820F9ED0"))) PPC_WEAK_FUNC(sub_820F9ED0);
PPC_FUNC_IMPL(__imp__sub_820F9ED0) {
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
	// lhz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x820f9ef8
	if (!ctx.cr6.eq) goto loc_820F9EF8;
	// bl 0x820f9db0
	ctx.lr = 0x820F9EF8;
	sub_820F9DB0(ctx, base);
loc_820F9EF8:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,16136
	ctx.r10.s64 = ctx.r11.s64 + 16136;
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

__attribute__((alias("__imp__sub_820F9F18"))) PPC_WEAK_FUNC(sub_820F9F18);
PPC_FUNC_IMPL(__imp__sub_820F9F18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820F9F20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x820fa060
	if (ctx.cr6.eq) goto loc_820FA060;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x820f9f58
	if (!ctx.cr6.eq) goto loc_820F9F58;
	// lhz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x820fa060
	if (!ctx.cr6.eq) goto loc_820FA060;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x820fa060
	if (!ctx.cr6.eq) goto loc_820FA060;
loc_820F9F58:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x820f9fdc
	if (ctx.cr6.eq) goto loc_820F9FDC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x820f9f70
	if (!ctx.cr6.eq) goto loc_820F9F70;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820f9fdc
	if (ctx.cr6.eq) goto loc_820F9FDC;
loc_820F9F70:
	// li r30,5
	ctx.r30.s64 = 5;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x820f9f94
	if (ctx.cr6.lt) goto loc_820F9F94;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x820f9f94
	if (!ctx.cr6.lt) goto loc_820F9F94;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f9380
	ctx.lr = 0x820F9F94;
	sub_820F9380(ctx, base);
loc_820F9F94:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa060
	if (ctx.cr6.eq) goto loc_820FA060;
	// lbz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// bne cr6,0x820fa060
	if (!ctx.cr6.eq) goto loc_820FA060;
	// rlwinm r11,r11,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// beq cr6,0x820fa060
	if (ctx.cr6.eq) goto loc_820FA060;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820F9FD0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820F9FDC:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// blt cr6,0x820fa028
	if (ctx.cr6.lt) goto loc_820FA028;
	// bne cr6,0x820fa060
	if (!ctx.cr6.eq) goto loc_820FA060;
	// li r11,4
	ctx.r11.s64 = 4;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// beq cr6,0x820fa060
	if (ctx.cr6.eq) goto loc_820FA060;
	// stb r29,60(r31)
	PPC_STORE_U8(ctx.r31.u32 + 60, ctx.r29.u8);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FA010;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// sth r8,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_820FA028:
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r4,1
	ctx.r4.s64 = 1;
	// clrlwi r9,r11,17
	ctx.r9.u64 = ctx.r11.u32 & 0x7FFF;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// rlwinm r9,r9,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// ori r8,r9,32768
	ctx.r8.u64 = ctx.r9.u64 | 32768;
	// sth r8,76(r31)
	PPC_STORE_U16(ctx.r31.u32 + 76, ctx.r8.u16);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x820FA05C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_820FA060:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA06C"))) PPC_WEAK_FUNC(sub_820FA06C);
PPC_FUNC_IMPL(__imp__sub_820FA06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA070"))) PPC_WEAK_FUNC(sub_820FA070);
PPC_FUNC_IMPL(__imp__sub_820FA070) {
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
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fa0ac
	if (ctx.cr6.eq) goto loc_820FA0AC;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x820f5cc8
	ctx.lr = 0x820FA0A4;
	sub_820F5CC8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fa0c4
	if (ctx.cr6.lt) goto loc_820FA0C4;
loc_820FA0AC:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fa0c4
	if (ctx.cr6.eq) goto loc_820FA0C4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x820f5cc8
	ctx.lr = 0x820FA0C4;
	sub_820F5CC8(ctx, base);
loc_820FA0C4:
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

__attribute__((alias("__imp__sub_820FA0DC"))) PPC_WEAK_FUNC(sub_820FA0DC);
PPC_FUNC_IMPL(__imp__sub_820FA0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA0E0"))) PPC_WEAK_FUNC(sub_820FA0E0);
PPC_FUNC_IMPL(__imp__sub_820FA0E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820FA0E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fa120
	if (ctx.cr6.eq) goto loc_820FA120;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x820f5cf8
	ctx.lr = 0x820FA118;
	sub_820F5CF8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fa144
	if (ctx.cr6.lt) goto loc_820FA144;
loc_820FA120:
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fa144
	if (ctx.cr6.eq) goto loc_820FA144;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x820f5cf8
	ctx.lr = 0x820FA144;
	sub_820F5CF8(ctx, base);
loc_820FA144:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA14C"))) PPC_WEAK_FUNC(sub_820FA14C);
PPC_FUNC_IMPL(__imp__sub_820FA14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA150"))) PPC_WEAK_FUNC(sub_820FA150);
PPC_FUNC_IMPL(__imp__sub_820FA150) {
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
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,22040
	ctx.r10.s64 = ctx.r11.s64 + 22040;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820fa190
	if (ctx.cr6.eq) goto loc_820FA190;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FA190;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FA190:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fa1b0
	if (ctx.cr6.eq) goto loc_820FA1B0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FA1B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FA1B0:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fa1ec
	if (ctx.cr6.eq) goto loc_820FA1EC;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fa1e8
	if (ctx.cr6.eq) goto loc_820FA1E8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x820FA1E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x820fa1ec
	goto loc_820FA1EC;
loc_820FA1E8:
	// bl 0x8207a630
	ctx.lr = 0x820FA1EC;
	sub_8207A630(ctx, base);
loc_820FA1EC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r10,r11,16136
	ctx.r10.s64 = ctx.r11.s64 + 16136;
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

__attribute__((alias("__imp__sub_820FA20C"))) PPC_WEAK_FUNC(sub_820FA20C);
PPC_FUNC_IMPL(__imp__sub_820FA20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA210"))) PPC_WEAK_FUNC(sub_820FA210);
PPC_FUNC_IMPL(__imp__sub_820FA210) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x820f6328
	sub_820F6328(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA218"))) PPC_WEAK_FUNC(sub_820FA218);
PPC_FUNC_IMPL(__imp__sub_820FA218) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FA220;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fa27c
	if (ctx.cr6.eq) goto loc_820FA27C;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x820fa26c
	if (!ctx.cr6.eq) goto loc_820FA26C;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa268
	if (ctx.cr6.eq) goto loc_820FA268;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FA260;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x820fa26c
	if (!ctx.cr6.eq) goto loc_820FA26C;
loc_820FA268:
	// li r29,1
	ctx.r29.s64 = 1;
loc_820FA26C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x820f66c8
	ctx.lr = 0x820FA278;
	sub_820F66C8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_820FA27C:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x820fa298
	if (ctx.cr6.eq) goto loc_820FA298;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x820e8af8
	ctx.lr = 0x820FA290;
	sub_820E8AF8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_820FA298:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA2A4"))) PPC_WEAK_FUNC(sub_820FA2A4);
PPC_FUNC_IMPL(__imp__sub_820FA2A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA2A8"))) PPC_WEAK_FUNC(sub_820FA2A8);
PPC_FUNC_IMPL(__imp__sub_820FA2A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f31,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f31.f64 = double(temp.f32);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f30,56(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f79e8
	ctx.lr = 0x820FA2D0;
	sub_820F79E8(ctx, base);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-24(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA2F0"))) PPC_WEAK_FUNC(sub_820FA2F0);
PPC_FUNC_IMPL(__imp__sub_820FA2F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f31,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f31.f64 = double(temp.f32);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f30,60(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f6ef8
	ctx.lr = 0x820FA318;
	sub_820F6EF8(ctx, base);
	// fadds f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-24(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA338"))) PPC_WEAK_FUNC(sub_820FA338);
PPC_FUNC_IMPL(__imp__sub_820FA338) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FA340;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x820e9408
	ctx.lr = 0x820FA36C;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fa3c4
	if (ctx.cr6.eq) goto loc_820FA3C4;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820f6170
	ctx.lr = 0x820FA384;
	sub_820F6170(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x820fa3cc
	if (!ctx.cr6.eq) goto loc_820FA3CC;
loc_820FA390:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
loc_820FA398:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820fa3b8
	if (ctx.cr6.eq) goto loc_820FA3B8;
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
	ctx.lr = 0x820FA3B8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FA3B8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FA3C4:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x820fa390
	goto loc_820FA390;
loc_820FA3CC:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820f63f0
	ctx.lr = 0x820FA3DC;
	sub_820F63F0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fa398
	if (ctx.cr6.lt) goto loc_820FA398;
	// stw r31,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA3F4"))) PPC_WEAK_FUNC(sub_820FA3F4);
PPC_FUNC_IMPL(__imp__sub_820FA3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA3F8"))) PPC_WEAK_FUNC(sub_820FA3F8);
PPC_FUNC_IMPL(__imp__sub_820FA3F8) {
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
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa434
	if (ctx.cr6.eq) goto loc_820FA434;
	// bl 0x820f5f88
	ctx.lr = 0x820FA424;
	sub_820F5F88(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa434
	if (ctx.cr6.eq) goto loc_820FA434;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x820fa458
	goto loc_820FA458;
loc_820FA434:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa454
	if (ctx.cr6.eq) goto loc_820FA454;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x820f5f88
	ctx.lr = 0x820FA448;
	sub_820F5F88(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x820fa458
	if (!ctx.cr6.eq) goto loc_820FA458;
loc_820FA454:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820FA458:
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

__attribute__((alias("__imp__sub_820FA470"))) PPC_WEAK_FUNC(sub_820FA470);
PPC_FUNC_IMPL(__imp__sub_820FA470) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fa4b8
	if (ctx.cr6.eq) goto loc_820FA4B8;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f31,40(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f79e8
	ctx.lr = 0x820FA4A8;
	sub_820F79E8(ctx, base);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x820f5fe0
	ctx.lr = 0x820FA4B8;
	sub_820F5FE0(ctx, base);
loc_820FA4B8:
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

__attribute__((alias("__imp__sub_820FA4D4"))) PPC_WEAK_FUNC(sub_820FA4D4);
PPC_FUNC_IMPL(__imp__sub_820FA4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA4D8"))) PPC_WEAK_FUNC(sub_820FA4D8);
PPC_FUNC_IMPL(__imp__sub_820FA4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lhz r10,5(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 5);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lfs f2,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,64(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// b 0x820f6000
	sub_820F6000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA510"))) PPC_WEAK_FUNC(sub_820FA510);
PPC_FUNC_IMPL(__imp__sub_820FA510) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA514"))) PPC_WEAK_FUNC(sub_820FA514);
PPC_FUNC_IMPL(__imp__sub_820FA514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA518"))) PPC_WEAK_FUNC(sub_820FA518);
PPC_FUNC_IMPL(__imp__sub_820FA518) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x820f6020
	sub_820F6020(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA528"))) PPC_WEAK_FUNC(sub_820FA528);
PPC_FUNC_IMPL(__imp__sub_820FA528) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA52C"))) PPC_WEAK_FUNC(sub_820FA52C);
PPC_FUNC_IMPL(__imp__sub_820FA52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA530"))) PPC_WEAK_FUNC(sub_820FA530);
PPC_FUNC_IMPL(__imp__sub_820FA530) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fa578
	if (ctx.cr6.eq) goto loc_820FA578;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f31,44(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f6ef8
	ctx.lr = 0x820FA568;
	sub_820F6EF8(ctx, base);
	// fadds f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bl 0x820f6040
	ctx.lr = 0x820FA578;
	sub_820F6040(ctx, base);
loc_820FA578:
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

__attribute__((alias("__imp__sub_820FA594"))) PPC_WEAK_FUNC(sub_820FA594);
PPC_FUNC_IMPL(__imp__sub_820FA594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA598"))) PPC_WEAK_FUNC(sub_820FA598);
PPC_FUNC_IMPL(__imp__sub_820FA598) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x820f6060
	sub_820F6060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA5A8"))) PPC_WEAK_FUNC(sub_820FA5A8);
PPC_FUNC_IMPL(__imp__sub_820FA5A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA5AC"))) PPC_WEAK_FUNC(sub_820FA5AC);
PPC_FUNC_IMPL(__imp__sub_820FA5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA5B0"))) PPC_WEAK_FUNC(sub_820FA5B0);
PPC_FUNC_IMPL(__imp__sub_820FA5B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x820f6080
	sub_820F6080(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA5C8"))) PPC_WEAK_FUNC(sub_820FA5C8);
PPC_FUNC_IMPL(__imp__sub_820FA5C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA5CC"))) PPC_WEAK_FUNC(sub_820FA5CC);
PPC_FUNC_IMPL(__imp__sub_820FA5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA5D0"))) PPC_WEAK_FUNC(sub_820FA5D0);
PPC_FUNC_IMPL(__imp__sub_820FA5D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa5e0
	if (ctx.cr6.eq) goto loc_820FA5E0;
	// b 0x820f60a8
	sub_820F60A8(ctx, base);
	return;
loc_820FA5E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA5E8"))) PPC_WEAK_FUNC(sub_820FA5E8);
PPC_FUNC_IMPL(__imp__sub_820FA5E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fa5f8
	if (ctx.cr6.eq) goto loc_820FA5F8;
	// b 0x820f60d0
	sub_820F60D0(ctx, base);
	return;
loc_820FA5F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA600"))) PPC_WEAK_FUNC(sub_820FA600);
PPC_FUNC_IMPL(__imp__sub_820FA600) {
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
	// bne cr6,0x820fa684
	if (!ctx.cr6.eq) goto loc_820FA684;
	// lbz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// bl 0x820f7720
	ctx.lr = 0x820FA634;
	sub_820F7720(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820fa684
	if (ctx.cr6.eq) goto loc_820FA684;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FA648:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,24(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lhz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r7,2
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 2, ctx.xer);
	// bne cr6,0x820fa674
	if (!ctx.cr6.eq) goto loc_820FA674;
	// lhz r10,3(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 3);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820fa69c
	if (ctx.cr6.eq) goto loc_820FA69C;
loc_820FA674:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820fa648
	if (ctx.cr6.lt) goto loc_820FA648;
loc_820FA684:
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
loc_820FA69C:
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

__attribute__((alias("__imp__sub_820FA6B4"))) PPC_WEAK_FUNC(sub_820FA6B4);
PPC_FUNC_IMPL(__imp__sub_820FA6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA6B8"))) PPC_WEAK_FUNC(sub_820FA6B8);
PPC_FUNC_IMPL(__imp__sub_820FA6B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x820fa6d0
	if (ctx.cr6.lt) goto loc_820FA6D0;
	// stfs f1,56(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// b 0x820fa6d4
	goto loc_820FA6D4;
loc_820FA6D0:
	// stfs f0,56(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
loc_820FA6D4:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x820fa470
	sub_820FA470(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA6E0"))) PPC_WEAK_FUNC(sub_820FA6E0);
PPC_FUNC_IMPL(__imp__sub_820FA6E0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA6E4"))) PPC_WEAK_FUNC(sub_820FA6E4);
PPC_FUNC_IMPL(__imp__sub_820FA6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA6E8"))) PPC_WEAK_FUNC(sub_820FA6E8);
PPC_FUNC_IMPL(__imp__sub_820FA6E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,60(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x820fa530
	sub_820FA530(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA6F8"))) PPC_WEAK_FUNC(sub_820FA6F8);
PPC_FUNC_IMPL(__imp__sub_820FA6F8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FA6FC"))) PPC_WEAK_FUNC(sub_820FA6FC);
PPC_FUNC_IMPL(__imp__sub_820FA6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FA700"))) PPC_WEAK_FUNC(sub_820FA700);
PPC_FUNC_IMPL(__imp__sub_820FA700) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820FA708;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 4, ctx.xer);
	// bne cr6,0x820fa854
	if (!ctx.cr6.eq) goto loc_820FA854;
	// lbz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// bl 0x820f7720
	ctx.lr = 0x820FA734;
	sub_820F7720(ctx, base);
	// clrlwi r26,r3,24
	ctx.r26.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x820fa74c
	if (!ctx.cr6.eq) goto loc_820FA74C;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x820FA748;
	sub_82079FD8(ctx, base);
	// b 0x820fa790
	goto loc_820FA790;
loc_820FA74C:
	// lis r11,1365
	ctx.r11.s64 = 89456640;
	// ori r10,r11,21845
	ctx.r10.u64 = ctx.r11.u64 | 21845;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820fa778
	if (ctx.cr6.gt) goto loc_820FA778;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r26,r11
	ctx.r9.u64 = ctx.r26.u64 + ctx.r11.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// ble cr6,0x820fa77c
	if (!ctx.cr6.gt) goto loc_820FA77C;
loc_820FA778:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_820FA77C:
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,93
	ctx.r4.u64 = ctx.r4.u64 | 93;
	// bl 0x820e9408
	ctx.lr = 0x820FA790;
	sub_820E9408(ctx, base);
loc_820FA790:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fa7c8
	if (ctx.cr6.eq) goto loc_820FA7C8;
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
	// addic. r30,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r30.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// blt 0x820fa7c0
	if (ctx.cr0.lt) goto loc_820FA7C0;
loc_820FA7AC:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820f57b8
	ctx.lr = 0x820FA7B4;
	sub_820F57B8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,48
	ctx.r29.s64 = ctx.r29.s64 + 48;
	// bge 0x820fa7ac
	if (!ctx.cr0.lt) goto loc_820FA7AC;
loc_820FA7C0:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// b 0x820fa7cc
	goto loc_820FA7CC;
loc_820FA7C8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_820FA7CC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// beq cr6,0x820fa860
	if (ctx.cr6.eq) goto loc_820FA860;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// lwz r29,64(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
loc_820FA7E8:
	// clrlwi r30,r5,24
	ctx.r30.u64 = ctx.r5.u32 & 0xFF;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bge cr6,0x820fa854
	if (!ctx.cr6.lt) goto loc_820FA854;
	// lwz r28,0(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lbz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x820f77b0
	ctx.lr = 0x820FA804;
	sub_820F77B0(ctx, base);
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820FA818;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x820f59c0
	ctx.lr = 0x820FA840;
	sub_820F59C0(ctx, base);
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// clrlwi r5,r8,24
	ctx.r5.u64 = ctx.r8.u32 & 0xFF;
	// bge cr6,0x820fa7e8
	if (!ctx.cr6.lt) goto loc_820FA7E8;
loc_820FA854:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_820FA860:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA870"))) PPC_WEAK_FUNC(sub_820FA870);
PPC_FUNC_IMPL(__imp__sub_820FA870) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FA878;
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
	// bne cr6,0x820fa8d8
	if (!ctx.cr6.eq) goto loc_820FA8D8;
	// lbz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + 48);
	// bl 0x820f7720
	ctx.lr = 0x820FA8A0;
	sub_820F7720(ctx, base);
	// clrlwi r29,r3,24
	ctx.r29.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x820fa8d8
	if (ctx.cr6.eq) goto loc_820FA8D8;
	// li r31,0
	ctx.r31.s64 = 0;
loc_820FA8B0:
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
	// bl 0x820f53f0
	ctx.lr = 0x820FA8C8;
	sub_820F53F0(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// clrlwi r31,r10,24
	ctx.r31.u64 = ctx.r10.u32 & 0xFF;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x820fa8b0
	if (ctx.cr6.lt) goto loc_820FA8B0;
loc_820FA8D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FA8E0"))) PPC_WEAK_FUNC(sub_820FA8E0);
PPC_FUNC_IMPL(__imp__sub_820FA8E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FA8E8;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r29,r4,24
	ctx.r29.u64 = ctx.r4.u32 & 0xFF;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820fa914
	if (!ctx.cr6.eq) goto loc_820FA914;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,14004(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,56(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// b 0x820fa928
	goto loc_820FA928;
loc_820FA914:
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// bne cr6,0x820fa928
	if (!ctx.cr6.eq) goto loc_820FA928;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,60(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 60, temp.u32);
loc_820FA928:
	// lbz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + 48);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x820f7720
	ctx.lr = 0x820FA934;
	sub_820F7720(ctx, base);
	// clrlwi r28,r3,24
	ctx.r28.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x820fa984
	if (ctx.cr6.eq) goto loc_820FA984;
	// li r31,0
	ctx.r31.s64 = 0;
loc_820FA944:
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
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lhz r9,3(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 3);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplw cr6,r8,r29
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820fa974
	if (!ctx.cr6.eq) goto loc_820FA974;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820f51b0
	ctx.lr = 0x820FA974;
	sub_820F51B0(ctx, base);
loc_820FA974:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x820fa944
	if (ctx.cr6.lt) goto loc_820FA944;
loc_820FA984:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x820fa9c8
	if (!ctx.cr6.eq) goto loc_820FA9C8;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820faa50
	if (ctx.cr6.eq) goto loc_820FAA50;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lfs f31,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,56(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f79e8
	ctx.lr = 0x820FA9A8;
	sub_820F79E8(ctx, base);
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x820f5fe0
	ctx.lr = 0x820FA9B8;
	sub_820F5FE0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FA9C8:
	// cmplwi cr6,r29,1
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1, ctx.xer);
	// bne cr6,0x820faa0c
	if (!ctx.cr6.eq) goto loc_820FAA0C;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820faa50
	if (ctx.cr6.eq) goto loc_820FAA50;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lfs f31,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,60(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x820f6ef8
	ctx.lr = 0x820FA9EC;
	sub_820F6EF8(ctx, base);
	// fadds f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bl 0x820f6040
	ctx.lr = 0x820FA9FC;
	sub_820F6040(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FAA0C:
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// beq cr6,0x820faa1c
	if (ctx.cr6.eq) goto loc_820FAA1C;
	// cmplwi cr6,r29,4
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 4, ctx.xer);
	// bne cr6,0x820faa50
	if (!ctx.cr6.eq) goto loc_820FAA50;
loc_820FAA1C:
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820faa50
	if (ctx.cr6.eq) goto loc_820FAA50;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820faa50
	if (ctx.cr6.eq) goto loc_820FAA50;
	// lhz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820faa50
	if (ctx.cr6.eq) goto loc_820FAA50;
	// lfs f2,68(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,64(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820f6000
	ctx.lr = 0x820FAA50;
	sub_820F6000(ctx, base);
loc_820FAA50:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FAA60"))) PPC_WEAK_FUNC(sub_820FAA60);
PPC_FUNC_IMPL(__imp__sub_820FAA60) {
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
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820faaac
	if (ctx.cr6.eq) goto loc_820FAAAC;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820faaac
	if (ctx.cr6.eq) goto loc_820FAAAC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FAA94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820FAAAC:
	// li r11,0
	ctx.r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FAAC4"))) PPC_WEAK_FUNC(sub_820FAAC4);
PPC_FUNC_IMPL(__imp__sub_820FAAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FAAC8"))) PPC_WEAK_FUNC(sub_820FAAC8);
PPC_FUNC_IMPL(__imp__sub_820FAAC8) {
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
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fab14
	if (ctx.cr6.eq) goto loc_820FAB14;
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fab14
	if (ctx.cr6.eq) goto loc_820FAB14;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FAAFC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820FAB14:
	// li r11,0
	ctx.r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FAB2C"))) PPC_WEAK_FUNC(sub_820FAB2C);
PPC_FUNC_IMPL(__imp__sub_820FAB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FAB30"))) PPC_WEAK_FUNC(sub_820FAB30);
PPC_FUNC_IMPL(__imp__sub_820FAB30) {
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
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fab60
	if (ctx.cr6.eq) goto loc_820FAB60;
	// bl 0x820f6848
	ctx.lr = 0x820FAB4C;
	sub_820F6848(ctx, base);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820FAB60:
	// li r11,0
	ctx.r11.s64 = 0;
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FAB78"))) PPC_WEAK_FUNC(sub_820FAB78);
PPC_FUNC_IMPL(__imp__sub_820FAB78) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fab88
	if (ctx.cr6.eq) goto loc_820FAB88;
	// b 0x820f68c0
	sub_820F68C0(ctx, base);
	return;
loc_820FAB88:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820FAB90"))) PPC_WEAK_FUNC(sub_820FAB90);
PPC_FUNC_IMPL(__imp__sub_820FAB90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820FAB98;
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
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fac1c
	if (ctx.cr6.eq) goto loc_820FAC1C;
	// lbz r4,48(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x820f7720
	ctx.lr = 0x820FABC0;
	sub_820F7720(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820fac1c
	if (ctx.cr6.eq) goto loc_820FAC1C;
loc_820FABD0:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x820fac1c
	if (!ctx.cr6.eq) goto loc_820FAC1C;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// rlwinm r11,r11,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1FE;
	// clrlwi r7,r30,24
	ctx.r7.u64 = ctx.r30.u32 & 0xFF;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r6,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// lhz r3,3(r4)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r4.u32 + 3);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x820fac0c
	if (!ctx.cr6.eq) goto loc_820FAC0C;
	// li r29,1
	ctx.r29.s64 = 1;
loc_820FAC0C:
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x820fabd0
	if (ctx.cr6.lt) goto loc_820FABD0;
loc_820FAC1C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FAC28"))) PPC_WEAK_FUNC(sub_820FAC28);
PPC_FUNC_IMPL(__imp__sub_820FAC28) {
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
	// bl 0x820fa150
	ctx.lr = 0x820FAC48;
	sub_820FA150(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820fac68
	if (ctx.cr6.eq) goto loc_820FAC68;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32776
	ctx.r4.u64 = ctx.r4.u64 | 32776;
	// bl 0x820e9410
	ctx.lr = 0x820FAC64;
	sub_820E9410(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820FAC68:
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

__attribute__((alias("__imp__sub_820FAC80"))) PPC_WEAK_FUNC(sub_820FAC80);
PPC_FUNC_IMPL(__imp__sub_820FAC80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FAC88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x820fa700
	ctx.lr = 0x820FAC9C;
	sub_820FA700(ctx, base);
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,32780
	ctx.r4.u64 = ctx.r4.u64 | 32780;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x820e9408
	ctx.lr = 0x820FACB8;
	sub_820E9408(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820facd4
	if (ctx.cr6.eq) goto loc_820FACD4;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x820f6170
	ctx.lr = 0x820FACD0;
	sub_820F6170(ctx, base);
	// b 0x820facd8
	goto loc_820FACD8;
loc_820FACD4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_820FACD8:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// bne cr6,0x820fad20
	if (!ctx.cr6.eq) goto loc_820FAD20;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
loc_820FACEC:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820fad0c
	if (ctx.cr6.eq) goto loc_820FAD0C;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820FAD0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820FAD0C:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820FAD20:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820facec
	if (ctx.cr6.lt) goto loc_820FACEC;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x820f5d28
	ctx.lr = 0x820FAD34;
	sub_820F5D28(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820facec
	if (ctx.cr6.lt) goto loc_820FACEC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa870
	ctx.lr = 0x820FAD48;
	sub_820FA870(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FAD54"))) PPC_WEAK_FUNC(sub_820FAD54);
PPC_FUNC_IMPL(__imp__sub_820FAD54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FAD58"))) PPC_WEAK_FUNC(sub_820FAD58);
PPC_FUNC_IMPL(__imp__sub_820FAD58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820FAD60;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x820fa700
	ctx.lr = 0x820FAD74;
	sub_820FA700(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// blt cr6,0x820fadb0
	if (ctx.cr6.lt) goto loc_820FADB0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa338
	ctx.lr = 0x820FAD9C;
	sub_820FA338(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fadb0
	if (ctx.cr6.lt) goto loc_820FADB0;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_820FADB0:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x820fade4
	if (ctx.cr6.eq) goto loc_820FADE4;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fade4
	if (ctx.cr6.eq) goto loc_820FADE4;
	// lhz r11,5(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 5);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x820fade4
	if (ctx.cr6.eq) goto loc_820FADE4;
	// lfs f2,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x820f6000
	ctx.lr = 0x820FADE4;
	sub_820F6000(ctx, base);
loc_820FADE4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x820fadf4
	if (ctx.cr6.lt) goto loc_820FADF4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa870
	ctx.lr = 0x820FADF4;
	sub_820FA870(ctx, base);
loc_820FADF4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820FAE00"))) PPC_WEAK_FUNC(sub_820FAE00);
PPC_FUNC_IMPL(__imp__sub_820FAE00) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,52(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820fae2c
	if (ctx.cr6.eq) goto loc_820FAE2C;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r4,41(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 41);
	// b 0x820fae30
	goto loc_820FAE30;
loc_820FAE2C:
	// li r4,-1
	ctx.r4.s64 = -1;
loc_820FAE30:
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820fa338
	ctx.lr = 0x820FAE40;
	sub_820FA338(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x820fae50
	if (ctx.cr6.lt) goto loc_820FAE50;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_820FAE50:
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

__attribute__((alias("__imp__sub_820FAE64"))) PPC_WEAK_FUNC(sub_820FAE64);
PPC_FUNC_IMPL(__imp__sub_820FAE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820FAE68"))) PPC_WEAK_FUNC(sub_820FAE68);
PPC_FUNC_IMPL(__imp__sub_820FAE68) {
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
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x820faed0
	if (ctx.cr6.eq) goto loc_820FAED0;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x820faed0
	if (!ctx.cr6.eq) goto loc_820FAED0;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x820e8af8
	ctx.lr = 0x820FAEA4;
	sub_820E8AF8(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// bl 0x820f6328
	ctx.lr = 0x820FAEBC;
	sub_820F6328(ctx, base);
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
loc_820FAED0:
	// lbz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 32);
	// ori r10,r11,128
	ctx.r10.u64 = ctx.r11.u64 | 128;
	// stb r10,32(r31)
	PPC_STORE_U8(ctx.r31.u32 + 32, ctx.r10.u8);
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

