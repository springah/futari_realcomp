#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82181E10"))) PPC_WEAK_FUNC(sub_82181E10);
PPC_FUNC_IMPL(__imp__sub_82181E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// rlwinm r11,r4,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r4,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r7,r8,32
	ctx.r7.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// srad r10,r9,r7
	temp.u64 = ctx.r7.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r9.s64 < 0) & (((ctx.r9.s64 >> temp.u64) << temp.u64) != ctx.r9.s64);
	ctx.r10.s64 = ctx.r9.s64 >> temp.u64;
	// srd r7,r10,r11
	ctx.r7.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r11.u8 & 0x7F));
	// b 0x8209aa70
	sub_8209AA70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82181E38"))) PPC_WEAK_FUNC(sub_82181E38);
PPC_FUNC_IMPL(__imp__sub_82181E38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// add r11,r4,r6
	ctx.r11.u64 = ctx.r4.u64 + ctx.r6.u64;
	// rlwinm r10,r4,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r8,r9,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rldicr r9,r7,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// subf r11,r10,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r10.s64;
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// srad r7,r9,r8
	temp.u64 = ctx.r8.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r9.s64 < 0) & (((ctx.r9.s64 >> temp.u64) << temp.u64) != ctx.r9.s64);
	ctx.r7.s64 = ctx.r9.s64 >> temp.u64;
	// srd r7,r7,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r10.u8 & 0x7F));
	// b 0x8209a998
	sub_8209A998(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82181E64"))) PPC_WEAK_FUNC(sub_82181E64);
PPC_FUNC_IMPL(__imp__sub_82181E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181E68"))) PPC_WEAK_FUNC(sub_82181E68);
PPC_FUNC_IMPL(__imp__sub_82181E68) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 468);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82181E7C"))) PPC_WEAK_FUNC(sub_82181E7C);
PPC_FUNC_IMPL(__imp__sub_82181E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181E80"))) PPC_WEAK_FUNC(sub_82181E80);
PPC_FUNC_IMPL(__imp__sub_82181E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82181E88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,2
	ctx.r30.s64 = 2;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82181E98:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181eac
	if (ctx.cr6.eq) goto loc_82181EAC;
	// bl 0x820a4400
	ctx.lr = 0x82181EA8;
	sub_820A4400(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
loc_82181EAC:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82181e98
	if (!ctx.cr0.eq) goto loc_82181E98;
	// bl 0x82181b70
	ctx.lr = 0x82181EBC;
	sub_82181B70(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82181EC4"))) PPC_WEAK_FUNC(sub_82181EC4);
PPC_FUNC_IMPL(__imp__sub_82181EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181EC8"))) PPC_WEAK_FUNC(sub_82181EC8);
PPC_FUNC_IMPL(__imp__sub_82181EC8) {
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
	// bl 0x82181c60
	ctx.lr = 0x82181EE0;
	sub_82181C60(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r10,r31,20
	ctx.r10.s64 = ctx.r31.s64 + 20;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f0,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
loc_82181EF8:
	// stfs f0,-12(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12, temp.u32);
	// stw r11,-20(r10)
	PPC_STORE_U32(ctx.r10.u32 + -20, ctx.r11.u32);
	// stw r11,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r11.u32);
	// stfsu f0,4(r10)
	temp.f32 = float(ctx.f0.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82181ef8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82181EF8;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stb r9,48(r31)
	PPC_STORE_U8(ctx.r31.u32 + 48, ctx.r9.u8);
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lfs f13,1452(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 1452);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1460(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 1460);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1464(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1464, temp.u32);
	// stfs f13,1456(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1456, temp.u32);
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

__attribute__((alias("__imp__sub_82181F60"))) PPC_WEAK_FUNC(sub_82181F60);
PPC_FUNC_IMPL(__imp__sub_82181F60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82181F68;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,5120
	ctx.r9.s64 = ctx.r10.s64 + 5120;
	// lwz r30,-31336(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31336);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82181f9c
	if (ctx.cr6.eq) goto loc_82181F9C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82180ab0
	ctx.lr = 0x82181F94;
	sub_82180AB0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a630
	ctx.lr = 0x82181F9C;
	sub_8207A630(ctx, base);
loc_82181F9C:
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r30,r31,96
	ctx.r30.s64 = ctx.r31.s64 + 96;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181fb0
	if (ctx.cr6.eq) goto loc_82181FB0;
	// bl 0x8207a630
	ctx.lr = 0x82181FB0;
	sub_8207A630(ctx, base);
loc_82181FB0:
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
	ctx.lr = 0x82181FC8;
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
	ctx.lr = 0x82181FDC;
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
	ctx.lr = 0x82181FF4;
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

__attribute__((alias("__imp__sub_82182004"))) PPC_WEAK_FUNC(sub_82182004);
PPC_FUNC_IMPL(__imp__sub_82182004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182008"))) PPC_WEAK_FUNC(sub_82182008);
PPC_FUNC_IMPL(__imp__sub_82182008) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82182010;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-32156(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -32156);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82182144
	if (ctx.cr6.eq) goto loc_82182144;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82182144
	if (ctx.cr6.eq) goto loc_82182144;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r11,-31488
	ctx.r10.s64 = ctx.r11.s64 + -31488;
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r4,72(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x82182058;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// addi r7,r8,-31952
	ctx.r7.s64 = ctx.r8.s64 + -31952;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,72(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 72);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82182074;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x82182094;
	sub_8209D660(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r30,r11,-13008
	ctx.r30.s64 = ctx.r11.s64 + -13008;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82180978
	ctx.lr = 0x821820B0;
	sub_82180978(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r29,r10,-13016
	ctx.r29.s64 = ctx.r10.s64 + -13016;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82180978
	ctx.lr = 0x821820CC;
	sub_82180978(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r28,r9,-13024
	ctx.r28.s64 = ctx.r9.s64 + -13024;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82180978
	ctx.lr = 0x821820E8;
	sub_82180978(ctx, base);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r27,r8,-13032
	ctx.r27.s64 = ctx.r8.s64 + -13032;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82180978
	ctx.lr = 0x82182104;
	sub_82180978(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821813a0
	ctx.lr = 0x82182114;
	sub_821813A0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821813a0
	ctx.lr = 0x82182124;
	sub_821813A0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821813a0
	ctx.lr = 0x82182134;
	sub_821813A0(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821813a0
	ctx.lr = 0x82182144;
	sub_821813A0(ctx, base);
loc_82182144:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218214C"))) PPC_WEAK_FUNC(sub_8218214C);
PPC_FUNC_IMPL(__imp__sub_8218214C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182150"))) PPC_WEAK_FUNC(sub_82182150);
PPC_FUNC_IMPL(__imp__sub_82182150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r9,r3,376
	ctx.r9.s64 = ctx.r3.s64 + 376;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r3,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// rldicr r3,r6,63,63
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r5,r7,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r7.s64;
	// clrldi r9,r5,32
	ctx.r9.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// srad r5,r3,r9
	temp.u64 = ctx.r9.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r3.s64 < 0) & (((ctx.r3.s64 >> temp.u64) << temp.u64) != ctx.r3.s64);
	ctx.r5.s64 = ctx.r3.s64 >> temp.u64;
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stfsx f0,r8,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, temp.u32);
	// srd r3,r5,r7
	ctx.r3.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,6020(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6020, temp.u32);
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,6024(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6024, temp.u32);
	// lfs f11,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,6028(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6028, temp.u32);
	// ld r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// or r9,r3,r10
	ctx.r9.u64 = ctx.r3.u64 | ctx.r10.u64;
	// std r9,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r9.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821821BC"))) PPC_WEAK_FUNC(sub_821821BC);
PPC_FUNC_IMPL(__imp__sub_821821BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821821C0"))) PPC_WEAK_FUNC(sub_821821C0);
PPC_FUNC_IMPL(__imp__sub_821821C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// add r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 + ctx.r5.u64;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r3,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r7,r9,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r11,-31312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31312);
	// subf r10,r8,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r8.s64;
	// li r5,1
	ctx.r5.s64 = 1;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r5,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// srad r10,r9,r7
	temp.u64 = ctx.r7.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r9.s64 < 0) & (((ctx.r9.s64 >> temp.u64) << temp.u64) != ctx.r9.s64);
	ctx.r10.s64 = ctx.r9.s64 >> temp.u64;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// srd r7,r10,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r8.u8 & 0x7F));
	// b 0x8209a998
	sub_8209A998(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82182208"))) PPC_WEAK_FUNC(sub_82182208);
PPC_FUNC_IMPL(__imp__sub_82182208) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x82098b00
	sub_82098B00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82182224"))) PPC_WEAK_FUNC(sub_82182224);
PPC_FUNC_IMPL(__imp__sub_82182224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182228"))) PPC_WEAK_FUNC(sub_82182228);
PPC_FUNC_IMPL(__imp__sub_82182228) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f1,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r5,124(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82098c20
	ctx.lr = 0x82182254;
	sub_82098C20(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182264"))) PPC_WEAK_FUNC(sub_82182264);
PPC_FUNC_IMPL(__imp__sub_82182264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182268"))) PPC_WEAK_FUNC(sub_82182268);
PPC_FUNC_IMPL(__imp__sub_82182268) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x82098cc0
	sub_82098CC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82182284"))) PPC_WEAK_FUNC(sub_82182284);
PPC_FUNC_IMPL(__imp__sub_82182284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182288"))) PPC_WEAK_FUNC(sub_82182288);
PPC_FUNC_IMPL(__imp__sub_82182288) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,20796
	ctx.r8.s64 = ctx.r10.s64 + 20796;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// b 0x820986b8
	sub_820986B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821822B0"))) PPC_WEAK_FUNC(sub_821822B0);
PPC_FUNC_IMPL(__imp__sub_821822B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,20796
	ctx.r8.s64 = ctx.r10.s64 + 20796;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// b 0x82098860
	sub_82098860(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821822D8"))) PPC_WEAK_FUNC(sub_821822D8);
PPC_FUNC_IMPL(__imp__sub_821822D8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r7,r9,20796
	ctx.r7.s64 = ctx.r9.s64 + 20796;
	// lwz r11,-31312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31312);
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r3,32
	ctx.r5.s64 = ctx.r3.s64 + 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// clrldi r3,r5,32
	ctx.r3.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// rldicr r10,r4,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r9,r8,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r6,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// srd r7,r10,r3
	ctx.r7.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r3.u8 & 0x7F));
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r11,1164
	ctx.r9.s64 = ctx.r11.s64 + 1164;
	// lwz r6,1164(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1164);
	// rlwimi r6,r8,23,7,8
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 23) & 0x1800000) | (ctx.r6.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r6,1164(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1164, ctx.r6.u32);
	// ld r5,24(r10)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r10.u32 + 24);
	// or r4,r7,r5
	ctx.r4.u64 = ctx.r7.u64 | ctx.r5.u64;
	// std r4,24(r10)
	PPC_STORE_U64(ctx.r10.u32 + 24, ctx.r4.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218233C"))) PPC_WEAK_FUNC(sub_8218233C);
PPC_FUNC_IMPL(__imp__sub_8218233C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182340"))) PPC_WEAK_FUNC(sub_82182340);
PPC_FUNC_IMPL(__imp__sub_82182340) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,-31312(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r8,-860
	ctx.r7.s64 = ctx.r8.s64 + -860;
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,152(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// clrldi r9,r4,32
	ctx.r9.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// rldicr r7,r3,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r6,r7,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r9.u8 & 0x7F));
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// rlwimi r5,r8,13,16,18
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r8.u32, 13) & 0xE000) | (ctx.r5.u64 & 0xFFFFFFFFFFFF1FFF);
	// stwx r5,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r5.u32);
	// ld r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r11.u32 + 24);
	// or r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 | ctx.r4.u64;
	// std r3,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r3.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821823A0"))) PPC_WEAK_FUNC(sub_821823A0);
PPC_FUNC_IMPL(__imp__sub_821823A0) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r3,48
	ctx.r11.s64 = ctx.r3.s64 + 48;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r4,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,-31312(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r8,-860
	ctx.r7.s64 = ctx.r8.s64 + -860;
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,152(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// clrldi r9,r4,32
	ctx.r9.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// rldicr r7,r3,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r6,r7,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r9.u8 & 0x7F));
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// rlwimi r5,r8,10,19,21
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r8.u32, 10) & 0x1C00) | (ctx.r5.u64 & 0xFFFFFFFFFFFFE3FF);
	// stwx r5,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r5.u32);
	// ld r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r11.u32 + 24);
	// or r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 | ctx.r4.u64;
	// std r3,24(r11)
	PPC_STORE_U64(ctx.r11.u32 + 24, ctx.r3.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182400"))) PPC_WEAK_FUNC(sub_82182400);
PPC_FUNC_IMPL(__imp__sub_82182400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x82080364
	ctx.lr = 0x82182414;
	__savefpr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmuls f0,f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r31,0
	ctx.r31.s64 = 0;
	// lfs f31,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f27,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f27.f64 = double(temp.f32);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// fdivs f28,f27,f0
	ctx.f28.f64 = double(float(ctx.f27.f64 / ctx.f0.f64));
	// lfs f30,44(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	ctx.f30.f64 = double(temp.f32);
	// lfs f29,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f29.f64 = double(temp.f32);
loc_82182444:
	// clrldi r11,r31,32
	ctx.r11.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmuls f10,f11,f28
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f28.f64));
	// fmuls f1,f10,f29
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f29.f64));
	// bl 0x8207b1a8
	ctx.lr = 0x82182468;
	sub_8207B1A8(ctx, base);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stfsx f0,r10,r9
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// bne cr6,0x8218248c
	if (!ctx.cr6.eq) goto loc_8218248C;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fadds f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// b 0x82182490
	goto loc_82182490;
loc_8218248C:
	// fmadds f31,f0,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f30.f64 + ctx.f31.f64));
loc_82182490:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,7
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 7, ctx.xer);
	// blt cr6,0x82182444
	if (ctx.cr6.lt) goto loc_82182444;
	// li r10,7
	ctx.r10.s64 = 7;
	// fdivs f0,f27,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f27.f64 / ctx.f31.f64));
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821824AC:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821824ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821824AC;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// rldicr r11,r11,59,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 59) & 0xFFFFFFFFFFFFFFFF;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// lwz r11,-31312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31312);
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stfs f0,6304(r6)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6304, temp.u32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,6308(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6308, temp.u32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,6312(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6312, temp.u32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,6316(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 6316, temp.u32);
	// ld r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// std r4,8(r6)
	PPC_STORE_U64(ctx.r6.u32 + 8, ctx.r4.u64);
	// lfs f10,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stfs f10,6320(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6320, temp.u32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,6324(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6324, temp.u32);
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,6328(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6328, temp.u32);
	// lfs f7,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,6332(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6332, temp.u32);
	// ld r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// or r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 | ctx.r8.u64;
	// std r9,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r9.u64);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x820803b0
	ctx.lr = 0x82182548;
	__restfpr_27(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182558"))) PPC_WEAK_FUNC(sub_82182558);
PPC_FUNC_IMPL(__imp__sub_82182558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82182560;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,24(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// lwz r11,20(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r30,0
	ctx.r30.s64 = 0;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stb r30,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r30.u8);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stb r30,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r30.u8);
	// addi r7,r6,-1396
	ctx.r7.s64 = ctx.r6.s64 + -1396;
	// stb r30,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r30.u8);
	// addi r6,r5,840
	ctx.r6.s64 = ctx.r5.s64 + 840;
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// addi r5,r3,5120
	ctx.r5.s64 = ctx.r3.s64 + 5120;
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// lfs f31,21768(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r29,r31,96
	ctx.r29.s64 = ctx.r31.s64 + 96;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// stb r11,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r11.u8);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// std r4,72(r31)
	PPC_STORE_U64(ctx.r31.u32 + 72, ctx.r4.u64);
	// stfs f31,84(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// stfs f31,88(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// stfs f31,92(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 92, temp.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82182658;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82182668
	if (ctx.cr6.eq) goto loc_82182668;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8218266c
	goto loc_8218266C;
loc_82182668:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218266C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r5,12(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r27,4(r10)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r26,8(r10)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r25,0(r9)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// stw r6,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r6.u32);
	// stw r5,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r5.u32);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r27,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r27.u32);
	// stw r26,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r26.u32);
	// stw r25,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r25.u32);
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// stw r9,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// bl 0x8206c010
	ctx.lr = 0x82182700;
	sub_8206C010(ctx, base);
	// li r3,7216
	ctx.r3.s64 = 7216;
	// bl 0x82079fd8
	ctx.lr = 0x82182708;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82182734
	if (ctx.cr6.eq) goto loc_82182734;
	// clrlwi r4,r28,24
	ctx.r4.u64 = ctx.r28.u32 & 0xFF;
	// bl 0x82180b10
	ctx.lr = 0x82182718;
	sub_82180B10(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,-31336(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31336, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_82182734:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,-31336(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31336, ctx.r30.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218274C"))) PPC_WEAK_FUNC(sub_8218274C);
PPC_FUNC_IMPL(__imp__sub_8218274C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182750"))) PPC_WEAK_FUNC(sub_82182750);
PPC_FUNC_IMPL(__imp__sub_82182750) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x82182150
	sub_82182150(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218275C"))) PPC_WEAK_FUNC(sub_8218275C);
PPC_FUNC_IMPL(__imp__sub_8218275C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182760"))) PPC_WEAK_FUNC(sub_82182760);
PPC_FUNC_IMPL(__imp__sub_82182760) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r7,3
	ctx.r7.s64 = 3;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x8209a998
	sub_8209A998(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82182788"))) PPC_WEAK_FUNC(sub_82182788);
PPC_FUNC_IMPL(__imp__sub_82182788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82182790;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821827d8
	if (!ctx.cr6.eq) goto loc_821827D8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r7,r9,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// li r5,0
	ctx.r5.s64 = 0;
	// srd r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r8.u8 & 0x7F));
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x821827D0;
	sub_8209D660(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821827D8:
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r10,r31,48
	ctx.r10.s64 = ctx.r31.s64 + 48;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r7,20796
	ctx.r29.s64 = ctx.r7.s64 + 20796;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r31,32
	ctx.r9.s64 = ctx.r31.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r3,r6,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r4,r7,63,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r5,r29,-21656
	ctx.r5.s64 = ctx.r29.s64 + -21656;
	// srd r27,r4,r6
	ctx.r27.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (ctx.r6.u8 & 0x7F));
	// lwz r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// addi r7,r29,-21656
	ctx.r7.s64 = ctx.r29.s64 + -21656;
	// lwzx r9,r10,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// rlwinm r10,r31,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r5,r31,r10
	ctx.r5.u64 = ctx.r31.u64 + ctx.r10.u64;
	// lwzx r8,r3,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// rlwinm r10,r5,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwimi r8,r9,10,19,21
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 10) & 0x1C00) | (ctx.r8.u64 & 0xFFFFFFFFFFFFE3FF);
	// stwx r8,r3,r6
	PPC_STORE_U32(ctx.r3.u32 + ctx.r6.u32, ctx.r8.u32);
	// ld r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 24);
	// or r9,r27,r5
	ctx.r9.u64 = ctx.r27.u64 | ctx.r5.u64;
	// std r9,24(r6)
	PPC_STORE_U64(ctx.r6.u32 + 24, ctx.r9.u64);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lwzx r7,r3,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// rlwimi r7,r8,13,16,18
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 13) & 0xE000) | (ctx.r7.u64 & 0xFFFFFFFFFFFF1FFF);
	// stwx r7,r3,r9
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r7.u32);
	// ld r6,24(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// or r5,r27,r6
	ctx.r5.u64 = ctx.r27.u64 | ctx.r6.u64;
	// std r5,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r5.u64);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r6,1164(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1164);
	// rlwimi r6,r7,23,7,8
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 23) & 0x1800000) | (ctx.r6.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r6,1164(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1164, ctx.r6.u32);
	// addi r8,r10,1164
	ctx.r8.s64 = ctx.r10.s64 + 1164;
	// ld r5,24(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// or r3,r5,r27
	ctx.r3.u64 = ctx.r5.u64 | ctx.r27.u64;
	// std r3,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r3.u64);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r9,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r29.u32);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x821828C8;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwzx r5,r7,r29
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r29.u32);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x821828E8;
	sub_820986B8(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82098cc0
	ctx.lr = 0x82182900;
	sub_82098CC0(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82098c20
	ctx.lr = 0x82182920;
	sub_82098C20(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,52(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82098b00
	ctx.lr = 0x82182938;
	sub_82098B00(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,56(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x82182954;
	sub_8209D660(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218295C"))) PPC_WEAK_FUNC(sub_8218295C);
PPC_FUNC_IMPL(__imp__sub_8218295C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182960"))) PPC_WEAK_FUNC(sub_82182960);
PPC_FUNC_IMPL(__imp__sub_82182960) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r4,r11,21772
	ctx.r4.s64 = ctx.r11.s64 + 21772;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206c540
	ctx.lr = 0x8218298C;
	sub_8206C540(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
loc_821829B0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821829b0
	if (!ctx.cr6.eq) goto loc_821829B0;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821829D8;
	sub_82060368(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31352(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x82194df8
	ctx.lr = 0x82182A00;
	sub_82194DF8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182A14"))) PPC_WEAK_FUNC(sub_82182A14);
PPC_FUNC_IMPL(__imp__sub_82182A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182A18"))) PPC_WEAK_FUNC(sub_82182A18);
PPC_FUNC_IMPL(__imp__sub_82182A18) {
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
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82182A44;
	sub_820995F0(ctx, base);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r4,r9,-12992
	ctx.r4.s64 = ctx.r9.s64 + -12992;
	// bl 0x82182150
	ctx.lr = 0x82182A54;
	sub_82182150(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182A64"))) PPC_WEAK_FUNC(sub_82182A64);
PPC_FUNC_IMPL(__imp__sub_82182A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182A68"))) PPC_WEAK_FUNC(sub_82182A68);
PPC_FUNC_IMPL(__imp__sub_82182A68) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// bne cr6,0x82182adc
	if (!ctx.cr6.eq) goto loc_82182ADC;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r7,48(r11)
	PPC_STORE_U8(ctx.r11.u32 + 48, ctx.r7.u8);
	// lwz r8,-31348(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31348);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r9,r11,1516
	ctx.r9.s64 = ctx.r11.s64 + 1516;
	// stw r10,1424(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1424, ctx.r10.u32);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
loc_82182AB0:
	// stwu r10,32(r9)
	ea = 32 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82182ab0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82182AB0;
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lfs f0,1452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 1452);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1460(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 1460);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,1456(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1456, temp.u32);
	// stfs f13,1464(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1464, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82182ADC:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82182b58
	if (!ctx.cr6.eq) goto loc_82182B58;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,48(r11)
	PPC_STORE_U8(ctx.r11.u32 + 48, ctx.r9.u8);
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lfs f13,1460(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1460);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,1452(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1452);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1456(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1456, temp.u32);
	// stfs f13,1464(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1464, temp.u32);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
loc_82182B10:
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r7,r8,-2064
	ctx.r7.s64 = ctx.r8.s64 + -2064;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,264(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 264);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,24(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// bne cr6,0x82182b7c
	if (!ctx.cr6.eq) goto loc_82182B7C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82182bb0
	if (!ctx.cr6.eq) goto loc_82182BB0;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// b 0x82182b84
	goto loc_82182B84;
loc_82182B58:
	// lbz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 48);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82182b10
	if (ctx.cr6.eq) goto loc_82182B10;
	// stw r3,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r3.u32);
	// stw r4,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r4.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82182B7C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82182bb0
	if (!ctx.cr6.eq) goto loc_82182BB0;
loc_82182B84:
	// cmpw cr6,r9,r3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x82182bbc
	if (ctx.cr6.eq) goto loc_82182BBC;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82182bb0
	if (!ctx.cr6.eq) goto loc_82182BB0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82182960
	ctx.lr = 0x82182BA0;
	sub_82182960(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82182BB0:
	// cmpw cr6,r10,r3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x82182bbc
	if (ctx.cr6.eq) goto loc_82182BBC;
	// stw r3,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r3.u32);
loc_82182BBC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182BCC"))) PPC_WEAK_FUNC(sub_82182BCC);
PPC_FUNC_IMPL(__imp__sub_82182BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182BD0"))) PPC_WEAK_FUNC(sub_82182BD0);
PPC_FUNC_IMPL(__imp__sub_82182BD0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82182d0c
	if (ctx.cr6.eq) goto loc_82182D0C;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82182c20
	if (ctx.cr6.eq) goto loc_82182C20;
	// bl 0x8207a630
	ctx.lr = 0x82182C04;
	sub_8207A630(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// bl 0x82182960
	ctx.lr = 0x82182C18;
	sub_82182960(ctx, base);
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// b 0x82182d0c
	goto loc_82182D0C;
loc_82182C20:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82182c5c
	if (ctx.cr6.eq) goto loc_82182C5C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82182c44
	if (ctx.cr6.eq) goto loc_82182C44;
	// bl 0x820a4400
	ctx.lr = 0x82182C40;
	sub_820A4400(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
loc_82182C44:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_82182C5C:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r4,r9,4992
	ctx.r4.s64 = ctx.r9.s64 + 4992;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// bl 0x8207dac0
	ctx.lr = 0x82182C88;
	sub_8207DAC0(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r30.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r7,-2
	ctx.r7.s64 = -2;
	// lis r10,10280
	ctx.r10.s64 = 673710080;
	// stw r6,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// lis r5,56
	ctx.r5.s64 = 3670016;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r30.u32);
	// lwz r4,-31312(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31312);
	// ori r10,r10,390
	ctx.r10.u64 = ctx.r10.u64 | 390;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// ori r5,r5,16512
	ctx.r5.u64 = ctx.r5.u64 | 16512;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addis r11,r11,14152
	ctx.r11.s64 = ctx.r11.s64 + 927465472;
	// addi r11,r11,20823
	ctx.r11.s64 = ctx.r11.s64 + 20823;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r3,152(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 152);
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x82182CF8;
	sub_820B6770(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82182d0c
	if (ctx.cr6.eq) goto loc_82182D0C;
	// bl 0x8207a630
	ctx.lr = 0x82182D08;
	sub_8207A630(ctx, base);
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
loc_82182D0C:
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

__attribute__((alias("__imp__sub_82182D24"))) PPC_WEAK_FUNC(sub_82182D24);
PPC_FUNC_IMPL(__imp__sub_82182D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182D28"))) PPC_WEAK_FUNC(sub_82182D28);
PPC_FUNC_IMPL(__imp__sub_82182D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82182D30;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lwz r11,-32156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32156);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82182fb8
	if (ctx.cr6.eq) goto loc_82182FB8;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfs f13,104(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// lfs f0,300(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82182fb8
	if (!ctx.cr6.lt) goto loc_82182FB8;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,108(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// addi r25,r10,21768
	ctx.r25.s64 = ctx.r10.s64 + 21768;
	// lfs f31,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82182fb8
	if (ctx.cr6.eq) goto loc_82182FB8;
	// bl 0x82182a18
	ctx.lr = 0x82182D88;
	sub_82182A18(ctx, base);
	// lwz r11,-32156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32156);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// addi r30,r11,-31312
	ctx.r30.s64 = ctx.r11.s64 + -31312;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bge cr6,0x82182dbc
	if (!ctx.cr6.lt) goto loc_82182DBC;
	// lis r5,390
	ctx.r5.s64 = 25559040;
	// ori r5,r5,390
	ctx.r5.u64 = ctx.r5.u64 | 390;
	// b 0x82182dc4
	goto loc_82182DC4;
loc_82182DBC:
	// lis r5,262
	ctx.r5.s64 = 17170432;
	// ori r5,r5,262
	ctx.r5.u64 = ctx.r5.u64 | 262;
loc_82182DC4:
	// bl 0x820995f0
	ctx.lr = 0x82182DC8;
	sub_820995F0(ctx, base);
	// addi r4,r26,16
	ctx.r4.s64 = ctx.r26.s64 + 16;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82182150
	ctx.lr = 0x82182DD4;
	sub_82182150(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r10,-31488
	ctx.r9.s64 = ctx.r10.s64 + -31488;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r4,60(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// bl 0x8209ad40
	ctx.lr = 0x82182DF0;
	sub_8209AD40(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r6,r7,-31952
	ctx.r6.s64 = ctx.r7.s64 + -31952;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,60(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 60);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82182E0C;
	sub_8209AB80(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r28,r11,-32136
	ctx.r28.s64 = ctx.r11.s64 + -32136;
	// li r31,3
	ctx.r31.s64 = 3;
loc_82182E1C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82182788
	ctx.lr = 0x82182E28;
	sub_82182788(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,60
	ctx.r28.s64 = ctx.r28.s64 + 60;
	// bne 0x82182e1c
	if (!ctx.cr0.eq) goto loc_82182E1C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// lfs f13,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x82182e54
	if (!ctx.cr6.gt) goto loc_82182E54;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182e58
	goto loc_82182E58;
loc_82182E54:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182E58:
	// lfs f12,12(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,8(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 8, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182e70
	if (!ctx.cr6.gt) goto loc_82182E70;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182e74
	goto loc_82182E74;
loc_82182E70:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182E74:
	// lfs f12,24(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,12(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 12, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182e8c
	if (!ctx.cr6.gt) goto loc_82182E8C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182e90
	goto loc_82182E90;
loc_82182E8C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182E90:
	// lfs f12,28(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,24(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 24, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182ea8
	if (!ctx.cr6.gt) goto loc_82182EA8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182eac
	goto loc_82182EAC;
loc_82182EA8:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182EAC:
	// lfs f12,40(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,28(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 28, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182ec4
	if (!ctx.cr6.gt) goto loc_82182EC4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182ec8
	goto loc_82182EC8;
loc_82182EC4:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182EC8:
	// lfs f12,44(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,40(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 40, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182ee0
	if (!ctx.cr6.gt) goto loc_82182EE0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182ee4
	goto loc_82182EE4;
loc_82182EE0:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182EE4:
	// lfs f12,56(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,44(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 44, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182efc
	if (!ctx.cr6.gt) goto loc_82182EFC;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82182f00
	goto loc_82182F00;
loc_82182EFC:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82182F00:
	// lfs f12,60(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,56(r27)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 56, temp.u32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82182f14
	if (!ctx.cr6.gt) goto loc_82182F14;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_82182F14:
	// stfs f31,60(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r27.u32 + 60, temp.u32);
	// lwz r10,7200(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 7200);
	// li r29,4
	ctx.r29.s64 = 4;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// bne cr6,0x82182f2c
	if (!ctx.cr6.eq) goto loc_82182F2C;
	// li r29,3
	ctx.r29.s64 = 3;
loc_82182F2C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r25,-19932
	ctx.r7.s64 = ctx.r25.s64 + -19932;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r31,-31956(r9)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31956);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwzx r4,r8,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x82182F5C;
	sub_8209D800(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r5,r11,r29
	ctx.r5.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// bl 0x8207dac0
	ctx.lr = 0x82182F6C;
	sub_8207DAC0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x82182F7C;
	sub_8209D7F0(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r31,1
	ctx.r31.s64 = 1;
	// rldicr r29,r11,63,63
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u64, 63) & 0xFFFFFFFFFFFFFFFF;
loc_82182F88:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r31,32
	ctx.r10.s64 = ctx.r31.s64 + 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// srd r6,r29,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r29.u64 >> (ctx.r9.u8 & 0x7F));
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x82182FAC;
	sub_8209D660(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// blt cr6,0x82182f88
	if (ctx.cr6.lt) goto loc_82182F88;
loc_82182FB8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82182FC4"))) PPC_WEAK_FUNC(sub_82182FC4);
PPC_FUNC_IMPL(__imp__sub_82182FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182FC8"))) PPC_WEAK_FUNC(sub_82182FC8);
PPC_FUNC_IMPL(__imp__sub_82182FC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82182FD0;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080364
	ctx.lr = 0x82182FD8;
	__savefpr_27(ctx, base);
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// stw r3,644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 644, ctx.r3.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,-32156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32156);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82183644
	if (ctx.cr6.eq) goto loc_82183644;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfs f13,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r10,-2064
	ctx.r30.s64 = ctx.r10.s64 + -2064;
	// lfs f0,300(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82183644
	if (!ctx.cr6.lt) goto loc_82183644;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,108(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82183644
	if (ctx.cr6.eq) goto loc_82183644;
	// bl 0x82182a18
	ctx.lr = 0x82183028;
	sub_82182A18(ctx, base);
	// lwz r11,-32156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32156);
	// lfs f0,176(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,16
	ctx.r3.s64 = 16;
	// lfs f13,108(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfs f11,104(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x82183060;
	sub_82182150(ctx, base);
	// lwz r11,-32156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32156);
	// lfs f1,100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82182400
	ctx.lr = 0x8218306C;
	sub_82182400(ctx, base);
	// lwz r10,6952(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6952);
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lfs f27,308(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 308);
	ctx.f27.f64 = double(temp.f32);
	// li r25,0
	ctx.r25.s64 = 0;
	// lfs f28,304(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 304);
	ctx.f28.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f29,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f29.f64 = double(temp.f32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stw r11,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r11.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r9,6952(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6952);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// stw r11,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, ctx.r11.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r27,r11,-21836
	ctx.r27.s64 = ctx.r11.s64 + -21836;
	// addi r20,r10,-12368
	ctx.r20.s64 = ctx.r10.s64 + -12368;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r10,r5,-32148
	ctx.r10.s64 = ctx.r5.s64 + -32148;
	// lfs f30,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// mr r14,r25
	ctx.r14.u64 = ctx.r25.u64;
	// rldicr r26,r4,62,63
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r4.u64, 62) & 0xFFFFFFFFFFFFFFFF;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lis r19,-32224
	ctx.r19.s64 = -2111832064;
	// addi r18,r11,-31672
	ctx.r18.s64 = ctx.r11.s64 + -31672;
	// addi r22,r9,-12380
	ctx.r22.s64 = ctx.r9.s64 + -12380;
	// addi r17,r8,-31952
	ctx.r17.s64 = ctx.r8.s64 + -31952;
	// addi r16,r7,-31488
	ctx.r16.s64 = ctx.r7.s64 + -31488;
	// addi r15,r6,-32136
	ctx.r15.s64 = ctx.r6.s64 + -32136;
	// b 0x821830f8
	goto loc_821830F8;
loc_821830F0:
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r29,644(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
loc_821830F8:
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// rlwinm r30,r14,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwzx r5,r30,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x82183114;
	sub_8209A100(ctx, base);
	// mulli r24,r14,60
	ctx.r24.s64 = ctx.r14.s64 * 60;
	// add r23,r24,r15
	ctx.r23.u64 = ctx.r24.u64 + ctx.r15.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82180f10
	ctx.lr = 0x82183124;
	sub_82180F10(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bne cr6,0x82183188
	if (!ctx.cr6.eq) goto loc_82183188;
	// lwz r4,44(r16)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r16.u32 + 44);
	// bl 0x8209ad40
	ctx.lr = 0x82183140;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r4,44(r17)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r17.u32 + 44);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82183154;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// stfs f28,400(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f28,2000(r8)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2000, temp.u32);
	// stfs f27,2004(r8)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2004, temp.u32);
	// stfs f31,2008(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2008, temp.u32);
	// stfs f31,2012(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2012, temp.u32);
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// or r6,r7,r26
	ctx.r6.u64 = ctx.r7.u64 | ctx.r26.u64;
	// std r6,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r6.u64);
	// lwz r3,6952(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 6952);
	// b 0x821831a8
	goto loc_821831A8;
loc_82183188:
	// lwz r4,52(r16)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r16.u32 + 52);
	// bl 0x8209ad40
	ctx.lr = 0x82183190;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r4,52(r17)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r17.u32 + 52);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x821831A4;
	sub_8209AB80(ctx, base);
	// addi r3,r23,-60
	ctx.r3.s64 = ctx.r23.s64 + -60;
loc_821831A8:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82182788
	ctx.lr = 0x821831B0;
	sub_82182788(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// lfs f0,4424(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4424);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r9,r30,r22
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r22.u32);
	// lfs f13,4824(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4824);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r8,r30,r20
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r20.u32);
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r11,r1,156
	ctx.r11.s64 = ctx.r1.s64 + 156;
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f30,168(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,176(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f30,188(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f30,200(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f30,204(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
loc_8218320C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82183238
	if (ctx.cr6.eq) goto loc_82183238;
	// clrldi r10,r9,32
	ctx.r10.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// std r10,384(r1)
	PPC_STORE_U64(ctx.r1.u32 + 384, ctx.r10.u64);
	// lfd f13,384(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 384);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(ctx.f29.f64 / ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
loc_82183238:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82183264
	if (ctx.cr6.eq) goto loc_82183264;
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r10,344(r1)
	PPC_STORE_U64(ctx.r1.u32 + 344, ctx.r10.u64);
	// lfd f13,344(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 344);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(ctx.f29.f64 / ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,0(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_82183264:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8218320c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218320C;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r29,-31956(r19)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r19.u32 + -31956);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x8218328C;
	sub_8209D800(ctx, base);
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8207dac0
	ctx.lr = 0x821832A0;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x821832B0;
	sub_8209D7F0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// addi r21,r15,56
	ctx.r21.s64 = ctx.r15.s64 + 56;
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r6,r24,r21
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r21.u32);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820a2280
	ctx.lr = 0x821832EC;
	sub_820A2280(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r4,48(r16)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r16.u32 + 48);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x82183300;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r4,48(r17)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r17.u32 + 48);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82183314;
	sub_8209AB80(ctx, base);
	// lwzx r7,r30,r22
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r22.u32);
	// add r29,r24,r18
	ctx.r29.u64 = ctx.r24.u64 + ctx.r18.u64;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// std r7,376(r1)
	PPC_STORE_U64(ctx.r1.u32 + 376, ctx.r7.u64);
	// lfd f0,376(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 376);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stfs f31,2004(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 2004, temp.u32);
	// stfs f31,2008(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 2008, temp.u32);
	// stfs f31,2012(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 2012, temp.u32);
	// fdivs f11,f30,f12
	ctx.f11.f64 = double(float(ctx.f30.f64 / ctx.f12.f64));
	// stfs f11,2000(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 2000, temp.u32);
	// ld r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// or r4,r5,r26
	ctx.r4.u64 = ctx.r5.u64 | ctx.r26.u64;
	// std r4,0(r6)
	PPC_STORE_U64(ctx.r6.u32 + 0, ctx.r4.u64);
	// bl 0x82180f10
	ctx.lr = 0x82183360;
	sub_82180F10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82182788
	ctx.lr = 0x8218336C;
	sub_82182788(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// lfs f0,4424(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4424);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r9,r30,r22
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r22.u32);
	// lfs f13,4824(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4824);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r8,r30,r20
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r20.u32);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// addi r10,r1,284
	ctx.r10.s64 = ctx.r1.s64 + 284;
	// stfs f31,272(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f31,276(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stfs f31,280(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f31,284(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f31,292(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f30,296(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f31,300(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f31,304(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f31,312(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f30,316(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f30,328(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f30,332(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 332, temp.u32);
loc_821833C8:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821833f4
	if (ctx.cr6.eq) goto loc_821833F4;
	// clrldi r11,r9,32
	ctx.r11.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// std r11,392(r1)
	PPC_STORE_U64(ctx.r1.u32 + 392, ctx.r11.u64);
	// lfd f13,392(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 392);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(ctx.f29.f64 / ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,-4(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
loc_821833F4:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82183420
	if (ctx.cr6.eq) goto loc_82183420;
	// clrldi r11,r8,32
	ctx.r11.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r11,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, ctx.r11.u64);
	// lfd f13,352(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 352);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(ctx.f29.f64 / ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,0(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_82183420:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bdnz 0x821833c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821833C8;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r28,-31956(r19)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r19.u32 + -31956);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,4(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x82183448;
	sub_8209D800(ctx, base);
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8218345C;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x8218346C;
	sub_8209D7F0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// addi r6,r18,56
	ctx.r6.s64 = ctx.r18.s64 + 56;
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r6,r24,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r6.u32);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820a2280
	ctx.lr = 0x821834A8;
	sub_820A2280(ctx, base);
	// lwzx r8,r30,r20
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r20.u32);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// std r8,360(r1)
	PPC_STORE_U64(ctx.r1.u32 + 360, ctx.r8.u64);
	// stfs f31,416(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stfs f31,2000(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 2000, temp.u32);
	// lfd f0,360(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 360);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// stfs f31,2012(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 2012, temp.u32);
	// stfs f31,2008(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 2008, temp.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f30,f12
	ctx.f11.f64 = double(float(ctx.f30.f64 / ctx.f12.f64));
	// stfs f11,2004(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 2004, temp.u32);
	// ld r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// or r5,r6,r26
	ctx.r5.u64 = ctx.r6.u64 | ctx.r26.u64;
	// std r5,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r5.u64);
	// bl 0x82180f10
	ctx.lr = 0x821834F4;
	sub_82180F10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82182788
	ctx.lr = 0x82183500;
	sub_82182788(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// lfs f0,4424(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4424);
	ctx.f0.f64 = double(temp.f32);
	// lwzx r9,r30,r22
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r22.u32);
	// lfs f13,4824(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4824);
	ctx.f13.f64 = double(temp.f32);
	// lwzx r8,r30,r20
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r20.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r10,r1,220
	ctx.r10.s64 = ctx.r1.s64 + 220;
	// stfs f30,232(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stfs f30,252(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f30,264(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f30,268(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f31,208(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f31,212(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f31,216(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f31,220(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f31,236(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f31,240(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f31,248(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
loc_8218355C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82183588
	if (ctx.cr6.eq) goto loc_82183588;
	// clrldi r11,r9,32
	ctx.r11.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lfs f0,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// std r11,336(r1)
	PPC_STORE_U64(ctx.r1.u32 + 336, ctx.r11.u64);
	// lfd f13,336(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 336);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(ctx.f29.f64 / ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,-4(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
loc_82183588:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821835b4
	if (ctx.cr6.eq) goto loc_821835B4;
	// clrldi r11,r8,32
	ctx.r11.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r11,368(r1)
	PPC_STORE_U64(ctx.r1.u32 + 368, ctx.r11.u64);
	// lfd f13,368(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 368);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(ctx.f29.f64 / ctx.f11.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,0(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_821835B4:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bdnz 0x8218355c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218355C;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r30,-31956(r19)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r19.u32 + -31956);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x821835DC;
	sub_8209D800(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8207dac0
	ctx.lr = 0x821835F0;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x82183600;
	sub_8209D7F0(ctx, base);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwzx r6,r24,r21
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r21.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820a2280
	ctx.lr = 0x82183638;
	sub_820A2280(ctx, base);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// cmplwi cr6,r14,3
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 3, ctx.xer);
	// blt cr6,0x821830f0
	if (ctx.cr6.lt) goto loc_821830F0;
loc_82183644:
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x820803b0
	ctx.lr = 0x82183650;
	__restfpr_27(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82183654"))) PPC_WEAK_FUNC(sub_82183654);
PPC_FUNC_IMPL(__imp__sub_82183654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183658"))) PPC_WEAK_FUNC(sub_82183658);
PPC_FUNC_IMPL(__imp__sub_82183658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82183660;
	__savegprlr_28(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x8218368C;
	sub_820995F0(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r4,r10,-12992
	ctx.r4.s64 = ctx.r10.s64 + -12992;
	// bl 0x82182150
	ctx.lr = 0x8218369C;
	sub_82182150(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x821836B8;
	sub_820995F0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x821836D8;
	sub_8209D660(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r6,r7,-31488
	ctx.r6.s64 = ctx.r7.s64 + -31488;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,64(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x821836F4;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// addi r3,r4,-31952
	ctx.r3.s64 = ctx.r4.s64 + -31952;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,64(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82183710;
	sub_8209AB80(ctx, base);
	// lis r28,-32252
	ctx.r28.s64 = -2113667072;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r28,-21836
	ctx.r10.s64 = ctx.r28.s64 + -21836;
	// lfs f0,2224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 2224);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x8207ae60
	ctx.lr = 0x82183728;
	sub_8207AE60(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f10,-21836(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -21836);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r30,r11,-2064
	ctx.r30.s64 = ctx.r11.s64 + -2064;
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// lfs f0,312(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,160(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64 + ctx.f13.f64));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x82183760;
	sub_82182150(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f7,56(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// addi r28,r11,21768
	ctx.r28.s64 = ctx.r11.s64 + 21768;
	// lfs f11,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x82183784
	if (!ctx.cr6.gt) goto loc_82183784;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x82183788
	goto loc_82183788;
loc_82183784:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_82183788:
	// lfs f12,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,4(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f8,128(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fcmpu cr6,f9,f11
	ctx.cr6.compare(ctx.f9.f64, ctx.f11.f64);
	// ble cr6,0x821837a8
	if (!ctx.cr6.gt) goto loc_821837A8;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x821837ac
	goto loc_821837AC;
loc_821837A8:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_821837AC:
	// lfs f12,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// fadds f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// lfs f9,316(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 316);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,44(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ble cr6,0x821837d0
	if (!ctx.cr6.gt) goto loc_821837D0;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x821837d4
	goto loc_821837D4;
loc_821837D0:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_821837D4:
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,4(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f13,f0
	ctx.f5.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f5,136(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fcmpu cr6,f6,f11
	ctx.cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// ble cr6,0x821837f4
	if (!ctx.cr6.gt) goto loc_821837F4;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x821837f8
	goto loc_821837F8;
loc_821837F4:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_821837F8:
	// fsubs f0,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f12,16(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x82183814
	if (!ctx.cr6.gt) goto loc_82183814;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x82183818
	goto loc_82183818;
loc_82183814:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_82183818:
	// lfs f13,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,20(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f0,f13
	ctx.f5.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f5,144(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fcmpu cr6,f6,f11
	ctx.cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// ble cr6,0x82183838
	if (!ctx.cr6.gt) goto loc_82183838;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x8218383c
	goto loc_8218383C;
loc_82183838:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_8218383C:
	// lfs f13,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// ble cr6,0x82183858
	if (!ctx.cr6.gt) goto loc_82183858;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x8218385c
	goto loc_8218385C;
loc_82183858:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_8218385C:
	// lfs f12,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,20(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f5,152(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fcmpu cr6,f6,f11
	ctx.cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// ble cr6,0x8218387c
	if (!ctx.cr6.gt) goto loc_8218387C;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x82183880
	goto loc_82183880;
loc_8218387C:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_82183880:
	// lfs f12,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x8218389c
	if (!ctx.cr6.gt) goto loc_8218389C;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x821838a0
	goto loc_821838A0;
loc_8218389C:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_821838A0:
	// lfs f13,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,36(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f13,f0
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f5,160(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fcmpu cr6,f6,f11
	ctx.cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// ble cr6,0x821838c0
	if (!ctx.cr6.gt) goto loc_821838C0;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x821838c4
	goto loc_821838C4;
loc_821838C0:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_821838C4:
	// lfs f13,36(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// ble cr6,0x821838e0
	if (!ctx.cr6.gt) goto loc_821838E0;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x821838e4
	goto loc_821838E4;
loc_821838E0:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_821838E4:
	// lfs f12,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,36(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f5,168(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fcmpu cr6,f6,f11
	ctx.cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// ble cr6,0x82183904
	if (!ctx.cr6.gt) goto loc_82183904;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x82183908
	goto loc_82183908;
loc_82183904:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_82183908:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f13,48(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x82183924
	if (!ctx.cr6.gt) goto loc_82183924;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x82183928
	goto loc_82183928;
loc_82183924:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_82183928:
	// lfs f12,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,52(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f5,176(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fcmpu cr6,f6,f11
	ctx.cr6.compare(ctx.f6.f64, ctx.f11.f64);
	// ble cr6,0x82183948
	if (!ctx.cr6.gt) goto loc_82183948;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
	// b 0x8218394c
	goto loc_8218394C;
loc_82183948:
	// fmr f0,f7
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f7.f64;
loc_8218394C:
	// lfs f12,52(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// ble cr6,0x82183968
	if (!ctx.cr6.gt) goto loc_82183968;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x8218396c
	goto loc_8218396C;
loc_82183968:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_8218396C:
	// lfs f13,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,52(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f7,f13,f0
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f7,184(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// fcmpu cr6,f10,f11
	ctx.cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// ble cr6,0x8218398c
	if (!ctx.cr6.gt) goto loc_8218398C;
	// fmr f0,f8
	ctx.f0.f64 = ctx.f8.f64;
	// b 0x82183990
	goto loc_82183990;
loc_8218398C:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f9.f64;
loc_82183990:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r10,0
	ctx.r10.s64 = 0;
	// fsubs f0,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// lwz r30,-32152(r9)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32152);
	// li r7,24
	ctx.r7.s64 = 24;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r6,8
	ctx.r6.s64 = 8;
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8209dce0
	ctx.lr = 0x821839E4;
	sub_8209DCE0(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x8207dac0
	ctx.lr = 0x821839F8;
	sub_8207DAC0(ctx, base);
	// addi r4,r28,-1120
	ctx.r4.s64 = ctx.r28.s64 + -1120;
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207dac0
	ctx.lr = 0x82183A08;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x82183A18;
	sub_8209D7F0(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82183A20"))) PPC_WEAK_FUNC(sub_82183A20);
PPC_FUNC_IMPL(__imp__sub_82183A20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82183A28;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,-32156(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -32156);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82183c5c
	if (ctx.cr6.eq) goto loc_82183C5C;
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82183c5c
	if (ctx.cr6.eq) goto loc_82183C5C;
	// bl 0x82182a18
	ctx.lr = 0x82183A58;
	sub_82182A18(ctx, base);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lis r5,1024
	ctx.r5.s64 = 67108864;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1024
	ctx.r5.u64 = ctx.r5.u64 | 1024;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82183A78;
	sub_820995F0(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r10,-31488
	ctx.r9.s64 = ctx.r10.s64 + -31488;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,76(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x82183A94;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r6,r7,-31952
	ctx.r6.s64 = ctx.r7.s64 + -31952;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,76(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82183AB0;
	sub_8209AB80(ctx, base);
	// lwz r11,-32156(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -32156);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f12,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,2
	ctx.r3.s64 = 2;
	// lfs f13,76(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f11,f13,f12,f0
	ctx.f11.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - ctx.f0.f64)));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x82183AE4;
	sub_82182150(ctx, base);
	// lwz r11,-32156(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -32156);
	// lwz r10,-31312(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r9,r9,-32196
	ctx.r9.s64 = ctx.r9.s64 + -32196;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// lwz r8,72(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,152(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r5,-4(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + -4);
	// bl 0x8209d660
	ctx.lr = 0x82183B1C;
	sub_8209D660(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r3,1
	ctx.r3.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,1152(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1152);
	// rlwinm r7,r8,0,22,18
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFE3FF;
	// stw r7,1152(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1152, ctx.r7.u32);
	// ld r6,24(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// oris r10,r6,32768
	ctx.r10.u64 = ctx.r6.u64 | 2147483648;
	// std r10,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r10.u64);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,1152(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1152);
	// rlwinm r6,r7,0,19,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFF1FFF;
	// stw r6,1152(r8)
	PPC_STORE_U32(ctx.r8.u32 + 1152, ctx.r6.u32);
	// ld r10,24(r8)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// oris r9,r10,32768
	ctx.r9.u64 = ctx.r10.u64 | 2147483648;
	// std r9,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r9.u64);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r6,1164(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1164);
	// rlwimi r6,r3,24,7,8
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r3.u32, 24) & 0x1800000) | (ctx.r6.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r6,1164(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1164, ctx.r6.u32);
	// ld r3,24(r7)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r7.u32 + 24);
	// oris r10,r3,32768
	ctx.r10.u64 = ctx.r3.u64 | 2147483648;
	// std r10,24(r7)
	PPC_STORE_U64(ctx.r7.u32 + 24, ctx.r10.u64);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x82183B98;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x82183BB0;
	sub_820986B8(ctx, base);
	// li r11,4
	ctx.r11.s64 = 4;
	// lfs f10,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// addi r10,r7,-31208
	ctx.r10.s64 = ctx.r7.s64 + -31208;
	// lfs f6,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// addi r9,r31,-4
	ctx.r9.s64 = ctx.r31.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,-32156(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -32156);
	// lwz r6,72(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// lfs f4,-8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,-4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f3.f64 = double(temp.f32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmuls f12,f7,f4
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f4.f64));
	// fmuls f11,f5,f3
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f3.f64));
	// lfs f13,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
loc_82183C08:
	// lfs f0,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82183c1c
	if (!ctx.cr6.gt) goto loc_82183C1C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
	// b 0x82183c20
	goto loc_82183C20;
loc_82183C1C:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_82183C20:
	// lfs f10,16(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,12(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// fcmpu cr6,f10,f13
	ctx.cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// ble cr6,0x82183c38
	if (!ctx.cr6.gt) goto loc_82183C38;
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
	// b 0x82183c3c
	goto loc_82183C3C;
loc_82183C38:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
loc_82183C3C:
	// stfsu f0,16(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	ea = 16 + ctx.r9.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82183c08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82183C08;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,7200(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 7200);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,-31956(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31956);
	// bl 0x8206bf48
	ctx.lr = 0x82183C5C;
	sub_8206BF48(ctx, base);
loc_82183C5C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82183C64"))) PPC_WEAK_FUNC(sub_82183C64);
PPC_FUNC_IMPL(__imp__sub_82183C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183C68"))) PPC_WEAK_FUNC(sub_82183C68);
PPC_FUNC_IMPL(__imp__sub_82183C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82183C70;
	__savegprlr_25(ctx, base);
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82183CA8;
	sub_820995F0(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r4,r10,-12992
	ctx.r4.s64 = ctx.r10.s64 + -12992;
	// bl 0x82182150
	ctx.lr = 0x82183CB8;
	sub_82182150(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r5,-31340(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31340);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x82183CD4;
	sub_8209A100(ctx, base);
	// lis r29,-32225
	ctx.r29.s64 = -2111897600;
	// lis r28,-32225
	ctx.r28.s64 = -2111897600;
	// lfs f0,-14012(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + -14012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-14016(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -14016);
	ctx.f13.f64 = double(temp.f32);
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fctidz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82180690
	ctx.lr = 0x82183D00;
	sub_82180690(ctx, base);
	// lfs f0,-14012(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + -14012);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,-14016(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -14016);
	ctx.f13.f64 = double(temp.f32);
	// fctidz f12,f0
	ctx.f12.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fctidz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// stfd f11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82089f78
	ctx.lr = 0x82183D30;
	sub_82089F78(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x820990e0
	ctx.lr = 0x82183D44;
	sub_820990E0(ctx, base);
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r10,r6,-12976
	ctx.r10.s64 = ctx.r6.s64 + -12976;
	// addi r9,r1,152
	ctx.r9.s64 = ctx.r1.s64 + 152;
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82183D5C:
	// ldu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r11,8(r9)
	ea = 8 + ctx.r9.u32;
	PPC_STORE_U64(ea, ctx.r11.u64);
	ctx.r9.u32 = ea;
	// bdnz 0x82183d5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82183D5C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f12,172(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f11.f64 = double(temp.f32);
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// addi r25,r11,-2064
	ctx.r25.s64 = ctx.r11.s64 + -2064;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r11,-32156(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -32156);
	// lfs f0,100(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,104(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f10,172(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f9,188(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lfs f1,32(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206bc18
	ctx.lr = 0x82183DA4;
	sub_8206BC18(ctx, base);
	// lfs f0,28(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-14012(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + -14012);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,-14016(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -14016);
	ctx.f13.f64 = double(temp.f32);
	// fadds f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f10,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f11,44(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lfs f30,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f30.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f29,56(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 56);
	ctx.f29.f64 = double(temp.f32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f29,136(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r29,r10,-21836
	ctx.r29.s64 = ctx.r10.s64 + -21836;
	// lfs f31,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// stfs f30,156(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fsubs f3,f0,f7
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f7.f64));
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f0.f64));
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f0.f64));
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fsubs f4,f0,f8
	ctx.f4.f64 = double(float(ctx.f0.f64 - ctx.f8.f64));
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fadds f2,f7,f0
	ctx.f2.f64 = double(float(ctx.f7.f64 + ctx.f0.f64));
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fsubs f1,f7,f0
	ctx.f1.f64 = double(float(ctx.f7.f64 - ctx.f0.f64));
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmadds f8,f13,f0,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f0.f64 + ctx.f10.f64));
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmadds f7,f12,f0,f9
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f0.f64 + ctx.f9.f64));
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f0,6960(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 6960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6964(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 6964);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f9,f11,f3
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f3.f64));
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fdivs f12,f11,f6
	ctx.f12.f64 = double(float(ctx.f11.f64 / ctx.f6.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fdivs f10,f5,f4
	ctx.f10.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fdivs f6,f2,f1
	ctx.f6.f64 = double(float(ctx.f2.f64 / ctx.f1.f64));
	// stfs f6,124(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fadds f5,f0,f8
	ctx.f5.f64 = double(float(ctx.f0.f64 + ctx.f8.f64));
	// stfs f5,172(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fadds f4,f13,f7
	ctx.f4.f64 = double(float(ctx.f13.f64 + ctx.f7.f64));
	// stfs f4,188(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// bl 0x8206bcf0
	ctx.lr = 0x82183E74;
	sub_8206BCF0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209a998
	ctx.lr = 0x82183E98;
	sub_8209A998(ctx, base);
	// lfs f3,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lwz r9,-32156(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + -32156);
	// lfs f0,2228(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 2228);
	ctx.f0.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// fsubs f2,f30,f3
	ctx.f2.f64 = double(float(ctx.f30.f64 - ctx.f3.f64));
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
loc_82183EB8:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// ble cr6,0x82183ecc
	if (!ctx.cr6.gt) goto loc_82183ECC;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x82183ed0
	goto loc_82183ED0;
loc_82183ECC:
	// fmr f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f29.f64;
loc_82183ED0:
	// lfs f0,6968(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 6968);
	ctx.f0.f64 = double(temp.f32);
	// fadds f10,f0,f11
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// fmadds f9,f10,f13,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// ble cr6,0x82183ef4
	if (!ctx.cr6.gt) goto loc_82183EF4;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x82183ef8
	goto loc_82183EF8;
loc_82183EF4:
	// fmr f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f29.f64;
loc_82183EF8:
	// lfs f12,6972(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 6972);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lfs f9,-4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// fctid f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// fmadds f7,f10,f13,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f0.f64));
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcfid f4,f8
	ctx.f4.f64 = double(ctx.f8.s64);
	// fctid f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// stfs f2,-4(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// fcfid f3,f5
	ctx.f3.f64 = double(ctx.f5.s64);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82183f74
	if (ctx.cr6.eq) goto loc_82183F74;
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x82183f50
	if (!ctx.cr6.gt) goto loc_82183F50;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x82183f54
	goto loc_82183F54;
loc_82183F50:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82183F54:
	// lfs f13,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// ble cr6,0x82183f6c
	if (!ctx.cr6.gt) goto loc_82183F6C;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x82183f70
	goto loc_82183F70;
loc_82183F6C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f31.f64;
loc_82183F70:
	// stfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
loc_82183F74:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x82183eb8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82183EB8;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r5,1798
	ctx.r5.s64 = 117833728;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1798
	ctx.r5.u64 = ctx.r5.u64 | 1798;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82183F98;
	sub_820995F0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// li r12,1
	ctx.r12.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stfs f0,6048(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 6048, temp.u32);
	// lfs f13,20(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,6052(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 6052, temp.u32);
	// lfs f12,24(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,6056(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 6056, temp.u32);
	// lfs f11,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,6060(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 6060, temp.u32);
	// ld r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// or r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 | ctx.r12.u64;
	// std r7,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r7.u64);
	// bl 0x82182008
	ctx.lr = 0x82183FE0;
	sub_82182008(ctx, base);
	// lwz r11,-32156(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -32156);
	// lwz r6,24(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82184000
	if (ctx.cr6.eq) goto loc_82184000;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,6952(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6952);
	// bl 0x82182788
	ctx.lr = 0x82183FFC;
	sub_82182788(ctx, base);
	// lwz r11,-32156(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -32156);
loc_82184000:
	// lwz r11,68(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x821841c8
	if (ctx.cr6.gt) goto loc_821841C8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82184084
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82184084;
	// bdzf 4*cr6+eq,0x821840e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821840E4;
	// bne cr6,0x8218412c
	if (!ctx.cr6.eq) goto loc_8218412C;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r10,-31488
	ctx.r9.s64 = ctx.r10.s64 + -31488;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,24(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x8218403C;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r6,r7,-31952
	ctx.r6.s64 = ctx.r7.s64 + -31952;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,24(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82184058;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x82184070;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x821841c0
	goto loc_821841C0;
loc_82184084:
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r10,-31488
	ctx.r9.s64 = ctx.r10.s64 + -31488;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,24(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x821840A0;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r6,r7,-31952
	ctx.r6.s64 = ctx.r7.s64 + -31952;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,24(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x821840BC;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x821840D4;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x821841bc
	goto loc_821841BC;
loc_821840E4:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r29,2
	ctx.r29.s64 = 2;
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,-31488
	ctx.r10.s64 = ctx.r9.s64 + -31488;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r5,r10,28
	ctx.r5.s64 = ctx.r10.s64 + 28;
	// and r4,r6,r29
	ctx.r4.u64 = ctx.r6.u64 & ctx.r29.u64;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwzx r4,r11,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// bl 0x8209ad40
	ctx.lr = 0x8218411C;
	sub_8209AD40(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r10,-31952
	ctx.r11.s64 = ctx.r10.s64 + -31952;
	// addi r9,r11,28
	ctx.r9.s64 = ctx.r11.s64 + 28;
	// b 0x82184170
	goto loc_82184170;
loc_8218412C:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r29,2
	ctx.r29.s64 = 2;
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,-31488
	ctx.r10.s64 = ctx.r9.s64 + -31488;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r5,r10,32
	ctx.r5.s64 = ctx.r10.s64 + 32;
	// and r4,r6,r29
	ctx.r4.u64 = ctx.r6.u64 & ctx.r29.u64;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwzx r4,r11,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r5.u32);
	// bl 0x8209ad40
	ctx.lr = 0x82184164;
	sub_8209AD40(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r10,-31952
	ctx.r11.s64 = ctx.r10.s64 + -31952;
	// addi r9,r11,32
	ctx.r9.s64 = ctx.r11.s64 + 32;
loc_82184170:
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// addic r7,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r5,r29
	ctx.r4.u64 = ctx.r5.u64 & ctx.r29.u64;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwzx r4,r11,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// bl 0x8209ab80
	ctx.lr = 0x82184198;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x821841B0;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
loc_821841BC:
	// li r5,1
	ctx.r5.s64 = 1;
loc_821841C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x820986b8
	ctx.lr = 0x821841C8;
	sub_820986B8(ctx, base);
loc_821841C8:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,7200(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 7200);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,-31956(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31956);
	// bl 0x8206bf48
	ctx.lr = 0x821841E0;
	sub_8206BF48(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
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

__attribute__((alias("__imp__sub_821841F4"))) PPC_WEAK_FUNC(sub_821841F4);
PPC_FUNC_IMPL(__imp__sub_821841F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821841F8"))) PPC_WEAK_FUNC(sub_821841F8);
PPC_FUNC_IMPL(__imp__sub_821841F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82184200;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,6948(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6948);
	// lis r10,26646
	ctx.r10.s64 = 1746272256;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// ori r9,r10,33129
	ctx.r9.u64 = ctx.r10.u64 | 33129;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// mulhwu r10,r11,r9
	ctx.r10.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r9.u32)) >> 32;
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// rlwinm r9,r8,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,-31312(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// rlwinm r6,r7,26,6,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FFFFFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mulli r3,r6,91
	ctx.r3.s64 = ctx.r6.s64 * 91;
	// subf r9,r3,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r3.s64;
	// mulli r11,r9,60
	ctx.r11.s64 = ctx.r9.s64 * 60;
	// stw r9,6948(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6948, ctx.r9.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r8,r11,1488
	ctx.r8.s64 = ctx.r11.s64 + 1488;
	// stw r8,6952(r30)
	PPC_STORE_U32(ctx.r30.u32 + 6952, ctx.r8.u32);
	// lwz r7,152(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82184270;
	sub_820995F0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r29,r11,-12992
	ctx.r29.s64 = ctx.r11.s64 + -12992;
	// li r3,2
	ctx.r3.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82182150
	ctx.lr = 0x82184284;
	sub_82182150(ctx, base);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8218429c
	if (ctx.cr6.eq) goto loc_8218429C;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r5,-31872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31872);
	// b 0x821842a4
	goto loc_821842A4;
loc_8218429C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r5,-32204(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + -32204);
loc_821842A4:
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x821842B8;
	sub_8209A100(ctx, base);
	// lwz r3,6952(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6952);
	// bl 0x82180f10
	ctx.lr = 0x821842C0;
	sub_82180F10(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x821842DC;
	sub_820995F0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82182150
	ctx.lr = 0x821842E8;
	sub_82182150(ctx, base);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lwz r10,-31312(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r8,r9,-31488
	ctx.r8.s64 = ctx.r9.s64 + -31488;
	// lwz r11,-32156(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// lwz r6,152(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// bl 0x8209ad40
	ctx.lr = 0x82184314;
	sub_8209AD40(ctx, base);
	// lwz r11,-32156(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// lwz r10,-31312(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// addi r9,r4,-31952
	ctx.r9.s64 = ctx.r4.s64 + -31952;
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r7,152(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwzx r4,r6,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x8209ab80
	ctx.lr = 0x8218433C;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,1152(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1152);
	// rlwimi r8,r10,11,19,21
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x1C00) | (ctx.r8.u64 & 0xFFFFFFFFFFFFE3FF);
	// stw r8,1152(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1152, ctx.r8.u32);
	// ld r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// oris r6,r7,32768
	ctx.r6.u64 = ctx.r7.u64 | 2147483648;
	// std r6,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r6.u64);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,1152(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1152);
	// rlwimi r8,r10,14,16,18
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 14) & 0xE000) | (ctx.r8.u64 & 0xFFFFFFFFFFFF1FFF);
	// stw r8,1152(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1152, ctx.r8.u32);
	// ld r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// oris r6,r7,32768
	ctx.r6.u64 = ctx.r7.u64 | 2147483648;
	// std r6,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r6.u64);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,1164(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1164);
	// rlwimi r8,r10,24,7,8
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0x1800000) | (ctx.r8.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r8,1164(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1164, ctx.r8.u32);
	// ld r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 24);
	// oris r6,r7,32768
	ctx.r6.u64 = ctx.r7.u64 | 2147483648;
	// std r6,24(r9)
	PPC_STORE_U64(ctx.r9.u32 + 24, ctx.r6.u64);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x821843B8;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x821843D0;
	sub_820986B8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r29,r11,-21836
	ctx.r29.s64 = ctx.r11.s64 + -21836;
	// lfs f2,4824(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4824);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4424(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206beb0
	ctx.lr = 0x821843E8;
	sub_8206BEB0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209a998
	ctx.lr = 0x8218440C;
	sub_8209A998(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lfs f11,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x82184430
	if (ctx.cr6.eq) goto loc_82184430;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x82184434
	goto loc_82184434;
loc_82184430:
	// fmr f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f11.f64;
loc_82184434:
	// lfs f12,4424(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4424);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// bne cr6,0x82184448
	if (!ctx.cr6.eq) goto loc_82184448;
	// fmr f13,f11
	ctx.f13.f64 = ctx.f11.f64;
loc_82184448:
	// lfs f0,4824(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4824);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,-31312(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f13,56(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// li r12,1
	ctx.r12.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// rldicr r12,r12,61,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 61) & 0xFFFFFFFFFFFFFFFF;
	// lwz r11,152(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 152);
	// li r3,20
	ctx.r3.s64 = 20;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// fdivs f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f0.f64));
	// fmuls f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f12,2064(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 2064, temp.u32);
	// stfs f0,2068(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 2068, temp.u32);
	// stfs f10,2072(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 2072, temp.u32);
	// stfs f9,2076(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 2076, temp.u32);
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// or r8,r9,r12
	ctx.r8.u64 = ctx.r9.u64 | ctx.r12.u64;
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// fmuls f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f7,124(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x821844B4;
	sub_82182150(ctx, base);
	// lwz r11,-32156(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f31,21768(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// lfs f6,88(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,84(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,80(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f4,128(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f5,132(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x821844E8;
	sub_82182150(ctx, base);
	// lwz r11,-32156(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f3,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,92(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	ctx.f2.f64 = double(temp.f32);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f2,144(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x82184510;
	sub_82182150(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r4,-31956(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -31956);
	// bl 0x8206bf48
	ctx.lr = 0x82184528;
	sub_8206BF48(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,6952(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 6952);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,56(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a2280
	ctx.lr = 0x82184568;
	sub_820A2280(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82184574"))) PPC_WEAK_FUNC(sub_82184574);
PPC_FUNC_IMPL(__imp__sub_82184574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82184578"))) PPC_WEAK_FUNC(sub_82184578);
PPC_FUNC_IMPL(__imp__sub_82184578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82184580;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080330
	ctx.lr = 0x82184588;
	__savefpr_14(ctx, base);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// lwz r11,-32156(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -32156);
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82184cb4
	if (ctx.cr6.eq) goto loc_82184CB4;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x821845C8;
	sub_820995F0(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r4,r10,-12992
	ctx.r4.s64 = ctx.r10.s64 + -12992;
	// bl 0x82182150
	ctx.lr = 0x821845D8;
	sub_82182150(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lis r5,1798
	ctx.r5.s64 = 117833728;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1798
	ctx.r5.u64 = ctx.r5.u64 | 1798;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x821845F4;
	sub_820995F0(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r6,-32156(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + -32156);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8218460C:
	// lwz r9,112(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lwz r9,6948(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6948);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// beq cr6,0x82184660
	if (ctx.cr6.eq) goto loc_82184660;
	// lwz r8,112(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,-8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// stwx r4,r3,r31
	PPC_STORE_U32(ctx.r3.u32 + ctx.r31.u32, ctx.r4.u32);
	// lwz r8,112(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// lwz r9,6948(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6948);
	// addi r5,r9,95
	ctx.r5.s64 = ctx.r9.s64 + 95;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r4,r10,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r4,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r4.u32);
	// b 0x82184684
	goto loc_82184684;
loc_82184660:
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r7.u32);
	// lwz r9,6948(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6948);
	// addi r4,r9,95
	ctx.r4.s64 = ctx.r9.s64 + 95;
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r7,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r7.u32);
loc_82184684:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8218460c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218460C;
	// subfic r11,r31,-6984
	ctx.xer.ca = ctx.r31.u32 <= 4294960312;
	ctx.r11.s64 = -6984 - ctx.r31.s64;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// addi r21,r11,-21836
	ctx.r21.s64 = ctx.r11.s64 + -21836;
	// addi r24,r10,21768
	ctx.r24.s64 = ctx.r10.s64 + 21768;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,26646
	ctx.r5.s64 = 1746272256;
	// lis r4,21845
	ctx.r4.s64 = 1431633920;
	// lfs f13,324(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,144(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f20,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f20.f64 = double(temp.f32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lfs f17,332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 332);
	ctx.f17.f64 = double(temp.f32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lfs f31,0(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// addi r11,r11,-12976
	ctx.r11.s64 = ctx.r11.s64 + -12976;
	// lfs f22,328(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 328);
	ctx.f22.f64 = double(temp.f32);
	// lfs f19,308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 308);
	ctx.f19.f64 = double(temp.f32);
	// addi r22,r31,7168
	ctx.r22.s64 = ctx.r31.s64 + 7168;
	// lfs f18,304(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 304);
	ctx.f18.f64 = double(temp.f32);
	// addi r23,r31,6984
	ctx.r23.s64 = ctx.r31.s64 + 6984;
	// lfs f23,156(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 156);
	ctx.f23.f64 = double(temp.f32);
	// addi r25,r31,7112
	ctx.r25.s64 = ctx.r31.s64 + 7112;
	// lfs f15,104(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	ctx.f15.f64 = double(temp.f32);
	// ori r15,r5,33129
	ctx.r15.u64 = ctx.r5.u64 | 33129;
	// lfs f14,100(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 100);
	ctx.f14.f64 = double(temp.f32);
	// ori r17,r4,21846
	ctx.r17.u64 = ctx.r4.u64 | 21846;
	// lfs f16,56(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	ctx.f16.f64 = double(temp.f32);
	// rldicr r20,r3,63,63
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r3.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lfs f21,44(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	ctx.f21.f64 = double(temp.f32);
	// lis r14,-32224
	ctx.r14.s64 = -2111832064;
	// lfs f30,28(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	ctx.f30.f64 = double(temp.f32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r19,r10,-31952
	ctx.r19.s64 = ctx.r10.s64 + -31952;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r18,r9,-31488
	ctx.r18.s64 = ctx.r9.s64 + -31488;
	// addi r16,r8,-12928
	ctx.r16.s64 = ctx.r8.s64 + -12928;
	// b 0x8218474c
	goto loc_8218474C;
loc_82184748:
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
loc_8218474C:
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f0,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// add r27,r11,r6
	ctx.r27.u64 = ctx.r11.u64 + ctx.r6.u64;
	// lwz r26,132(r27)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r27.u32 + 132);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x82184778
	if (!ctx.cr6.gt) goto loc_82184778;
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fmadds f11,f12,f23,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f23.f64 + ctx.f0.f64));
	// stfs f11,0(r22)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r22.u32 + 0, temp.u32);
	// b 0x82184790
	goto loc_82184790;
loc_82184778:
	// fsubs f12,f20,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f20.f64 - ctx.f0.f64));
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f23,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f23.f64 + ctx.f0.f64));
	// stfs f10,0(r22)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r22.u32 + 0, temp.u32);
	// fcmpu cr6,f10,f11
	ctx.cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// blt cr6,0x82184c98
	if (ctx.cr6.lt) goto loc_82184C98;
loc_82184790:
	// lwz r9,144(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 144);
	// addi r10,r24,32
	ctx.r10.s64 = ctx.r24.s64 + 32;
	// lwz r11,6948(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 6948);
	// rlwinm r8,r26,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// addi r11,r11,91
	ctx.r11.s64 = ctx.r11.s64 + 91;
	// lwzx r9,r8,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// mulhwu r10,r11,r15
	ctx.r10.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r15.u32)) >> 32;
	// subf r7,r10,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r7,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r4,r5,26,6,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0x3FFFFFF;
	// mulli r3,r4,91
	ctx.r3.s64 = ctx.r4.s64 * 91;
	// subf r30,r3,r11
	ctx.r30.s64 = ctx.r11.s64 - ctx.r3.s64;
	// bgt cr6,0x821847e4
	if (ctx.cr6.gt) goto loc_821847E4;
	// lfs f0,0(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,8(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,12(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// b 0x82184950
	goto loc_82184950;
loc_821847E4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// blt cr6,0x8218491c
	if (ctx.cr6.lt) goto loc_8218491C;
	// addi r11,r26,-1
	ctx.r11.s64 = ctx.r26.s64 + -1;
	// addi r4,r30,4
	ctx.r4.s64 = ctx.r30.s64 + 4;
	// mulhw r10,r11,r17
	ctx.r10.s64 = (int64_t(ctx.r11.s32) * int64_t(ctx.r17.s32)) >> 32;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r7,r4,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r3,r7,r9
	ctx.r3.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r24,20
	ctx.r5.s64 = ctx.r24.s64 + 20;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r10,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfsx f0,r4,r5
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f9,f0,f21
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f21.f64));
	// fmr f11,f9
	ctx.f11.f64 = ctx.f9.f64;
	// bge cr6,0x8218484c
	if (!ctx.cr6.lt) goto loc_8218484C;
	// li r11,0
	ctx.r11.s64 = 0;
	// fmr f12,f15
	ctx.f12.f64 = ctx.f15.f64;
	// fmr f13,f14
	ctx.f13.f64 = ctx.f14.f64;
	// stw r11,16(r22)
	PPC_STORE_U32(ctx.r22.u32 + 16, ctx.r11.u32);
	// b 0x821848b0
	goto loc_821848B0;
loc_8218484C:
	// lwz r10,16(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// cmplwi cr6,r10,90
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 90, ctx.xer);
	// bge cr6,0x8218486c
	if (!ctx.cr6.lt) goto loc_8218486C;
	// addi r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 1;
	// fmr f12,f15
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f15.f64;
	// fmr f13,f14
	ctx.f13.f64 = ctx.f14.f64;
	// stw r11,16(r22)
	PPC_STORE_U32(ctx.r22.u32 + 16, ctx.r11.u32);
	// b 0x821848b0
	goto loc_821848B0;
loc_8218486C:
	// addi r10,r30,95
	ctx.r10.s64 = ctx.r30.s64 + 95;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// std r8,256(r1)
	PPC_STORE_U64(ctx.r1.u32 + 256, ctx.r8.u64);
	// lfd f12,256(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 256);
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// lwzx r4,r5,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,264(r1)
	PPC_STORE_U64(ctx.r1.u32 + 264, ctx.r3.u64);
	// lfd f7,264(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 264);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f12,f8,f13
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f13,f5,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
loc_821848B0:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x821848c0
	if (!ctx.cr6.lt) goto loc_821848C0;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// b 0x821848d4
	goto loc_821848D4;
loc_821848C0:
	// lfs f10,4824(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 4824);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// fcmpu cr6,f12,f10
	ctx.cr6.compare(ctx.f12.f64, ctx.f10.f64);
	// ble cr6,0x821848d4
	if (!ctx.cr6.gt) goto loc_821848D4;
	// fmr f12,f10
	ctx.f12.f64 = ctx.f10.f64;
loc_821848D4:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x821848f4
	if (!ctx.cr6.lt) goto loc_821848F4;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fmuls f0,f13,f18
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f18.f64));
	// fmuls f13,f12,f19
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f19.f64));
	// b 0x82184950
	goto loc_82184950;
loc_821848F4:
	// lfs f10,4424(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 4424);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// fcmpu cr6,f13,f10
	ctx.cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x82184908
	if (!ctx.cr6.gt) goto loc_82184908;
	// fmr f13,f10
	ctx.f13.f64 = ctx.f10.f64;
loc_82184908:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fmuls f0,f13,f18
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f18.f64));
	// fmuls f13,f12,f19
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f19.f64));
	// b 0x82184950
	goto loc_82184950;
loc_8218491C:
	// li r9,90
	ctx.r9.s64 = 90;
	// rlwinm r11,r26,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,16(r22)
	PPC_STORE_U32(ctx.r22.u32 + 16, ctx.r9.u32);
	// addi r8,r16,8
	ctx.r8.s64 = ctx.r16.s64 + 8;
	// addi r10,r16,4
	ctx.r10.s64 = ctx.r16.s64 + 4;
	// addi r7,r16,12
	ctx.r7.s64 = ctx.r16.s64 + 12;
	// lfsx f0,r11,r16
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f11,r11,r7
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f9,r11,r8
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// fadds f12,f0,f9
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// lfsx f13,r11,r10
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f12,f18,f20
	ctx.f0.f64 = double(float(-(ctx.f12.f64 * ctx.f18.f64 - ctx.f20.f64)));
	// fmuls f13,f13,f19
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f19.f64));
loc_82184950:
	// fmuls f12,f11,f23
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f23.f64));
	// lfs f11,4(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f9,f23
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f23.f64));
	// lfs f9,0(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f23
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f23.f64));
	// lfs f7,-8(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + -8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f13,f23
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f23.f64));
	// lfs f5,-4(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + -4);
	ctx.f5.f64 = double(temp.f32);
	// li r9,6
	ctx.r9.s64 = 6;
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r10,r1,264
	ctx.r10.s64 = ctx.r1.s64 + 264;
	// addi r11,r11,-8
	ctx.r11.s64 = ctx.r11.s64 + -8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fmadds f4,f11,f22,f12
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f22.f64 + ctx.f12.f64));
	// stfs f4,4(r25)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4, temp.u32);
	// fmadds f3,f9,f22,f10
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f22.f64 + ctx.f10.f64));
	// stfs f3,0(r25)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r25.u32 + 0, temp.u32);
	// fmadds f29,f7,f22,f8
	ctx.f29.f64 = double(float(ctx.f7.f64 * ctx.f22.f64 + ctx.f8.f64));
	// stfs f29,-8(r25)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r25.u32 + -8, temp.u32);
	// fmadds f28,f5,f22,f6
	ctx.f28.f64 = double(float(ctx.f5.f64 * ctx.f22.f64 + ctx.f6.f64));
	// stfs f28,-4(r25)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r25.u32 + -4, temp.u32);
	// lfs f2,0(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f4.f64));
	// fmuls f0,f2,f3
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f3.f64));
	// fctid f13,f1
	ctx.f13.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// fmadds f25,f3,f18,f29
	ctx.f25.f64 = double(float(ctx.f3.f64 * ctx.f18.f64 + ctx.f29.f64));
	// fmadds f24,f4,f19,f28
	ctx.f24.f64 = double(float(ctx.f4.f64 * ctx.f19.f64 + ctx.f28.f64));
	// fctid f12,f0
	ctx.f12.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f26,f11
	ctx.f26.f64 = double(float(ctx.f11.f64));
	// frsp f27,f10
	ctx.f27.f64 = double(float(ctx.f10.f64));
loc_821849D0:
	// ldu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U64(ea);
	ctx.r11.u32 = ea;
	// stdu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x821849d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821849D0;
	// lfs f0,284(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lfs f13,300(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f27,f30,f0
	ctx.f12.f64 = double(float(-(ctx.f27.f64 * ctx.f30.f64 - ctx.f0.f64)));
	// fnmsubs f11,f26,f30,f13
	ctx.f11.f64 = double(float(-(ctx.f26.f64 * ctx.f30.f64 - ctx.f13.f64)));
	// stfs f12,284(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f11,300(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// lfs f1,32(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206bc18
	ctx.lr = 0x82184A00;
	sub_8206BC18(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f5,284(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	ctx.f5.f64 = double(temp.f32);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// lfs f4,300(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	ctx.f4.f64 = double(temp.f32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lfs f1,-8(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + -8);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f16,232(r1)
	temp.f32 = float(ctx.f16.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lfs f0,-14016(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -14016);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fadds f10,f0,f30
	ctx.f10.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f20,252(r1)
	temp.f32 = float(ctx.f20.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// fmadds f3,f0,f30,f5
	ctx.f3.f64 = double(float(ctx.f0.f64 * ctx.f30.f64 + ctx.f5.f64));
	// stfs f31,196(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f31,200(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f31,208(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lfs f13,-14012(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -14012);
	ctx.f13.f64 = double(temp.f32);
	// fadds f9,f13,f30
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// stfs f31,216(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// fmadds f2,f13,f30,f4
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f30.f64 + ctx.f4.f64));
	// stfs f31,224(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f31,236(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f31,240(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// fadds f7,f10,f30
	ctx.f7.f64 = double(float(ctx.f10.f64 + ctx.f30.f64));
	// stfs f31,244(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// fsubs f6,f30,f10
	ctx.f6.f64 = double(float(ctx.f30.f64 - ctx.f10.f64));
	// stfs f31,248(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// fsubs f8,f10,f30
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f30.f64));
	// lfs f13,-4(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f30,f9
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f9.f64));
	// fadds f12,f9,f30
	ctx.f12.f64 = double(float(ctx.f9.f64 + ctx.f30.f64));
	// fsubs f11,f9,f30
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f30.f64));
	// fdivs f9,f7,f6
	ctx.f9.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// stfs f9,204(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// fdivs f10,f21,f8
	ctx.f10.f64 = double(float(ctx.f21.f64 / ctx.f8.f64));
	// stfs f10,192(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fadds f8,f1,f3
	ctx.f8.f64 = double(float(ctx.f1.f64 + ctx.f3.f64));
	// stfs f8,284(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// fadds f7,f13,f2
	ctx.f7.f64 = double(float(ctx.f13.f64 + ctx.f2.f64));
	// stfs f7,300(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// fdivs f6,f21,f0
	ctx.f6.f64 = double(float(ctx.f21.f64 / ctx.f0.f64));
	// stfs f6,212(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// fdivs f5,f12,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// stfs f5,220(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// bl 0x8206bcf0
	ctx.lr = 0x82184AB8;
	sub_8206BCF0(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209a998
	ctx.lr = 0x82184ADC;
	sub_8209A998(ctx, base);
	// ld r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 16);
	// lfs f4,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// ld r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r31.u32 + 24);
	// stfs f29,136(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f28,140(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stfs f27,144(r1)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f25,152(r1)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f28,156(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f26,164(r1)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f29,168(r1)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f24,172(r1)
	temp.f32 = float(ctx.f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f27,176(r1)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f26,180(r1)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f25,184(r1)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f24,188(r1)
	temp.f32 = float(ctx.f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// std r8,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r8.u64);
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r7,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r7.u64);
	// lfs f3,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f3.f64 = double(temp.f32);
	// fnmsubs f0,f4,f17,f3
	ctx.f0.f64 = double(float(-(ctx.f4.f64 * ctx.f17.f64 - ctx.f3.f64)));
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// stfs f31,160(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// ble cr6,0x82184c94
	if (!ctx.cr6.gt) goto loc_82184C94;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stfs f0,6048(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6048, temp.u32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,6052(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6052, temp.u32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,6056(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6056, temp.u32);
	// lfs f11,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,6060(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 6060, temp.u32);
	// ld r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// or r8,r9,r20
	ctx.r8.u64 = ctx.r9.u64 | ctx.r20.u64;
	// std r8,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r8.u64);
	// bl 0x82182008
	ctx.lr = 0x82184B8C;
	sub_82182008(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r4,68(r18)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r18.u32 + 68);
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x82184BA0;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r4,68(r19)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r19.u32 + 68);
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82184BB4;
	sub_8209AB80(ctx, base);
	// mulli r11,r30,60
	ctx.r11.s64 = ctx.r30.s64 * 60;
	// lwz r5,136(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 136);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// addi r3,r11,1488
	ctx.r3.s64 = ctx.r11.s64 + 1488;
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x82184bd4
	if (!ctx.cr6.eq) goto loc_82184BD4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82184BD4:
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// bl 0x82182788
	ctx.lr = 0x82184BE4;
	sub_82182788(ctx, base);
	// lwz r10,7200(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7200);
	// li r29,4
	ctx.r29.s64 = 4;
	// cmpwi cr6,r10,6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 6, ctx.xer);
	// bne cr6,0x82184bf8
	if (!ctx.cr6.eq) goto loc_82184BF8;
	// li r29,3
	ctx.r29.s64 = 3;
loc_82184BF8:
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r30,-31956(r14)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r14.u32 + -31956);
	// addi r8,r21,23672
	ctx.r8.s64 = ctx.r21.s64 + 23672;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x82184C24;
	sub_8209D800(ctx, base);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mullw r5,r29,r6
	ctx.r5.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r6.s32);
	// bl 0x8207dac0
	ctx.lr = 0x82184C34;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x82184C44;
	sub_8209D7F0(ctx, base);
	// lwz r4,140(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 140);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82184c90
	if (ctx.cr6.eq) goto loc_82184C90;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x82184c90
	if (!ctx.cr6.gt) goto loc_82184C90;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82183658
	ctx.lr = 0x82184C64;
	sub_82183658(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lis r5,1798
	ctx.r5.s64 = 117833728;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1798
	ctx.r5.u64 = ctx.r5.u64 | 1798;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82184C80;
	sub_820995F0(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// lwz r6,-32156(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32156);
	// b 0x82184c98
	goto loc_82184C98;
loc_82184C90:
	// lwz r29,80(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82184C94:
	// lwz r6,-32156(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + -32156);
loc_82184C98:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r25,r25,16
	ctx.r25.s64 = ctx.r25.s64 + 16;
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r23,r23,32
	ctx.r23.s64 = ctx.r23.s64 + 32;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bne 0x82184748
	if (!ctx.cr0.eq) goto loc_82184748;
loc_82184CB4:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8208037c
	ctx.lr = 0x82184CC0;
	__restfpr_14(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82184CC4"))) PPC_WEAK_FUNC(sub_82184CC4);
PPC_FUNC_IMPL(__imp__sub_82184CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82184CC8"))) PPC_WEAK_FUNC(sub_82184CC8);
PPC_FUNC_IMPL(__imp__sub_82184CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x82184CD0;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82080358
	ctx.lr = 0x82184CD8;
	__savefpr_24(ctx, base);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r26,r11,-21836
	ctx.r26.s64 = ctx.r11.s64 + -21836;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r11,-31348(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31348);
	// addi r27,r10,-2064
	ctx.r27.s64 = ctx.r10.s64 + -2064;
	// lfs f0,3952(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 3952);
	ctx.f0.f64 = double(temp.f32);
	// lwz r30,-31372(r8)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31372);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lfs f13,148(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r11,1408
	ctx.r29.s64 = ctx.r11.s64 + 1408;
	// lfs f11,1456(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 1456);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,1452(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 1452);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x82184d40
	if (!ctx.cr6.gt) goto loc_82184D40;
loc_82184D20:
	// lfs f11,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// stfs f10,48(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r29.u32 + 48, temp.u32);
	// lfs f8,44(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// fcmpu cr6,f7,f0
	ctx.cr6.compare(ctx.f7.f64, ctx.f0.f64);
	// bgt cr6,0x82184d20
	if (ctx.cr6.gt) goto loc_82184D20;
loc_82184D40:
	// lfs f0,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f0,152(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x82184d74
	if (!ctx.cr6.lt) goto loc_82184D74;
loc_82184D54:
	// lfs f11,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f10,48(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r29.u32 + 48, temp.u32);
	// lfs f8,44(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// fcmpu cr6,f7,f0
	ctx.cr6.compare(ctx.f7.f64, ctx.f0.f64);
	// blt cr6,0x82184d54
	if (ctx.cr6.lt) goto loc_82184D54;
loc_82184D74:
	// lfs f11,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f9,56(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,52(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lfs f0,156(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfs f13,164(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// fnmsubs f6,f10,f0,f11
	ctx.f6.f64 = double(float(-(ctx.f10.f64 * ctx.f0.f64 - ctx.f11.f64)));
	// stfs f6,48(r29)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r29.u32 + 48, temp.u32);
	// fnmsubs f0,f7,f0,f9
	ctx.f0.f64 = double(float(-(ctx.f7.f64 * ctx.f0.f64 - ctx.f9.f64)));
	// stfs f0,56(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 56, temp.u32);
	// stfs f0,-14024(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -14024, temp.u32);
	// lwz r8,156(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r5,480(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 480);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// fsubs f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// stfs f13,-31332(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -31332, temp.u32);
	// bl 0x8209a100
	ctx.lr = 0x82184DD4;
	sub_8209A100(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r6,112
	ctx.r6.s64 = 112;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8209b098
	ctx.lr = 0x82184DF0;
	sub_8209B098(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82097540
	ctx.lr = 0x82184E04;
	sub_82097540(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82097580
	ctx.lr = 0x82184E18;
	sub_82097580(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x820975e8
	ctx.lr = 0x82184E2C;
	sub_820975E8(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x82096e78
	ctx.lr = 0x82184E40;
	sub_82096E78(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x82098540
	ctx.lr = 0x82184E54;
	sub_82098540(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x82098570
	ctx.lr = 0x82184E68;
	sub_82098570(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x820985d8
	ctx.lr = 0x82184E7C;
	sub_820985D8(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82098608
	ctx.lr = 0x82184E90;
	sub_82098608(ctx, base);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// li r19,0
	ctx.r19.s64 = 0;
	// lis r28,-32225
	ctx.r28.s64 = -2111897600;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82184eb0
	if (!ctx.cr6.eq) goto loc_82184EB0;
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82184eb8
	if (ctx.cr6.eq) goto loc_82184EB8;
loc_82184EB0:
	// mr r11,r19
	ctx.r11.u64 = ctx.r19.u64;
	// stb r19,-14757(r28)
	PPC_STORE_U8(ctx.r28.u32 + -14757, ctx.r19.u8);
loc_82184EB8:
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209af10
	ctx.lr = 0x82184ECC;
	sub_8209AF10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82182bd0
	ctx.lr = 0x82184ED4;
	sub_82182BD0(ctx, base);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82184ef8
	if (!ctx.cr6.eq) goto loc_82184EF8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,-14757(r28)
	PPC_STORE_U8(ctx.r28.u32 + -14757, ctx.r11.u8);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x820803a4
	ctx.lr = 0x82184EF4;
	__restfpr_24(ctx, base);
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_82184EF8:
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r23,r10,1
	ctx.r23.u64 = ctx.r10.u64 | 1;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82184F18;
	sub_820995F0(ctx, base);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r4,r8,-12992
	ctx.r4.s64 = ctx.r8.s64 + -12992;
	// bl 0x82182150
	ctx.lr = 0x82184F28;
	sub_82182150(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,-31312(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r7,152(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 152);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r5,1152(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1152);
	// rlwimi r5,r11,11,19,21
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r11.u32, 11) & 0x1C00) | (ctx.r5.u64 & 0xFFFFFFFFFFFFE3FF);
	// stw r5,1152(r6)
	PPC_STORE_U32(ctx.r6.u32 + 1152, ctx.r5.u32);
	// ld r10,24(r6)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r6.u32 + 24);
	// oris r9,r10,32768
	ctx.r9.u64 = ctx.r10.u64 | 2147483648;
	// std r9,24(r6)
	PPC_STORE_U64(ctx.r6.u32 + 24, ctx.r9.u64);
	// lwz r8,152(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r6,1152(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1152);
	// rlwimi r6,r11,14,16,18
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r11.u32, 14) & 0xE000) | (ctx.r6.u64 & 0xFFFFFFFFFFFF1FFF);
	// stw r6,1152(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1152, ctx.r6.u32);
	// ld r5,24(r7)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r7.u32 + 24);
	// oris r11,r5,32768
	ctx.r11.u64 = ctx.r5.u64 | 2147483648;
	// std r11,24(r7)
	PPC_STORE_U64(ctx.r7.u32 + 24, ctx.r11.u64);
	// bl 0x821822d8
	ctx.lr = 0x82184F7C;
	sub_821822D8(ctx, base);
	// lwz r10,152(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 152);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x82184F90;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x82184FA8;
	sub_820986B8(ctx, base);
	// lis r21,-32225
	ctx.r21.s64 = -2111897600;
	// lis r20,-32225
	ctx.r20.s64 = -2111897600;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lfs f2,-14012(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + -14012);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-14016(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + -14016);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206beb0
	ctx.lr = 0x82184FC0;
	sub_8206BEB0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209a998
	ctx.lr = 0x82184FE4;
	sub_8209A998(ctx, base);
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// lfs f12,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x8218500c
	if (ctx.cr6.eq) goto loc_8218500C;
	// lfs f0,336(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfs f13,340(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f11,f13,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f10,44(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// b 0x82185034
	goto loc_82185034;
loc_8218500C:
	// lfs f11,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f12
	ctx.f10.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// lfs f9,24(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// lfs f0,340(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f7,f10,f0,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f12.f64));
	// stfs f7,44(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// fmadds f6,f8,f13,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f6,28(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 28, temp.u32);
loc_82185034:
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f31,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f25,348(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 348);
	ctx.f25.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f24,344(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 344);
	ctx.f24.f64 = double(temp.f32);
	// lfs f28,312(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 312);
	ctx.f28.f64 = double(temp.f32);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// lfs f29,292(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 292);
	ctx.f29.f64 = double(temp.f32);
	// lis r22,-32224
	ctx.r22.s64 = -2111832064;
	// lfs f27,160(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 160);
	ctx.f27.f64 = double(temp.f32);
	// lis r24,-32224
	ctx.r24.s64 = -2111832064;
	// lfs f30,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f30.f64 = double(temp.f32);
	// addi r26,r11,-31952
	ctx.r26.s64 = ctx.r11.s64 + -31952;
	// lfs f26,100(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 100);
	ctx.f26.f64 = double(temp.f32);
	// addi r25,r10,-31488
	ctx.r25.s64 = ctx.r10.s64 + -31488;
loc_82185074:
	// addi r11,r28,4
	ctx.r11.s64 = ctx.r28.s64 + 4;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82185264
	if (ctx.cr6.eq) goto loc_82185264;
	// addi r11,r28,2
	ctx.r11.s64 = ctx.r28.s64 + 2;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfsx f0,r29,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// fmadds f12,f13,f24,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f24.f64 + ctx.f0.f64));
	// stfsx f12,r29,r30
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r30.u32, temp.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bne cr6,0x821850e8
	if (!ctx.cr6.eq) goto loc_821850E8;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// bl 0x820995f0
	ctx.lr = 0x821850C0;
	sub_820995F0(ctx, base);
	// lfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f12,44(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f0,f13,f12
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// b 0x8218516c
	goto loc_8218516C;
loc_821850E8:
	// lis r5,1798
	ctx.r5.s64 = 117833728;
	// ori r5,r5,1798
	ctx.r5.u64 = ctx.r5.u64 | 1798;
	// bl 0x820995f0
	ctx.lr = 0x821850F4;
	sub_820995F0(ctx, base);
	// lfs f0,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfsx f12,r29,r30
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x82182150
	ctx.lr = 0x82185120;
	sub_82182150(ctx, base);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82185174
	if (!ctx.cr6.eq) goto loc_82185174;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82185144;
	sub_820995F0(ctx, base);
	// lfs f0,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,28(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfsx f11,r29,r30
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_8218516C:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82182150
	ctx.lr = 0x82185174;
	sub_82182150(ctx, base);
loc_82185174:
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r4,68(r25)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r25.u32 + 68);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x82185188;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r4,68(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 68);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x8218519C;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// rlwinm r9,r28,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwzx r5,r9,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x821851C0;
	sub_8209D660(ctx, base);
	// lwz r11,-32200(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -32200);
	// fmr f12,f25
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f25.f64;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821851e4
	if (!ctx.cr6.eq) goto loc_821851E4;
	// fmr f0,f28
	ctx.f0.f64 = ctx.f28.f64;
	// fmr f13,f26
	ctx.f13.f64 = ctx.f26.f64;
	// fmr f12,f27
	ctx.f12.f64 = ctx.f27.f64;
loc_821851E4:
	// lfsx f11,r29,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fsubs f9,f31,f11
	ctx.f9.f64 = double(float(ctx.f31.f64 - ctx.f11.f64));
	// lfs f11,-14016(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + -14016);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-14012(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + -14012);
	ctx.f10.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r4,-31956(r22)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r22.u32 + -31956);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f30,156(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fmuls f8,f9,f29
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f29.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fadds f6,f11,f8
	ctx.f6.f64 = double(float(ctx.f11.f64 + ctx.f8.f64));
	// fsubs f5,f13,f8
	ctx.f5.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// stfs f5,128(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f5,160(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fadds f4,f7,f10
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f10.f64));
	// stfs f4,164(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fsubs f3,f6,f13
	ctx.f3.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// stfs f3,144(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fneg f2,f7
	ctx.f2.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f2,148(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f3,176(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f4,180(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// bl 0x8206bf48
	ctx.lr = 0x82185264;
	sub_8206BF48(ctx, base);
loc_82185264:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// blt cr6,0x82185074
	if (ctx.cr6.lt) goto loc_82185074;
	// lfs f0,352(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x821852b8
	if (!ctx.cr6.gt) goto loc_821852B8;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185294
	if (ctx.cr6.eq) goto loc_82185294;
	// bl 0x820a4400
	ctx.lr = 0x82185290;
	sub_820A4400(ctx, base);
	// stw r19,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r19.u32);
loc_82185294:
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stfs f0,8(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// stfs f30,12(r30)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// stw r19,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r19.u32);
	// stw r19,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r19.u32);
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
loc_821852B8:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x820803a4
	ctx.lr = 0x821852C4;
	__restfpr_24(ctx, base);
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821852C8"))) PPC_WEAK_FUNC(sub_821852C8);
PPC_FUNC_IMPL(__imp__sub_821852C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821852D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r30,-31336(r10)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31336);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x82097540
	ctx.lr = 0x821852F4;
	sub_82097540(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x820975e8
	ctx.lr = 0x82185308;
	sub_820975E8(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x82096e78
	ctx.lr = 0x8218531C;
	sub_82096E78(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8209af10
	ctx.lr = 0x82185330;
	sub_8209AF10(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x82099388
	ctx.lr = 0x82185344;
	sub_82099388(ctx, base);
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r4,-21836
	ctx.r9.s64 = ctx.r4.s64 + -21836;
	// stw r3,-31340(r29)
	PPC_STORE_U32(ctx.r29.u32 + -31340, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,-32156(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// addi r7,r10,-2064
	ctx.r7.s64 = ctx.r10.s64 + -2064;
	// lfs f0,-21836(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfs f0,21768(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4424(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4424);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4824(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4824);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,356(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 356);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r6,24(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x821853d4
	if (ctx.cr6.eq) goto loc_821853D4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821841f8
	ctx.lr = 0x821853D4;
	sub_821841F8(ctx, base);
loc_821853D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82182fc8
	ctx.lr = 0x821853DC;
	sub_82182FC8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82183c68
	ctx.lr = 0x821853E8;
	sub_82183C68(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82182d28
	ctx.lr = 0x821853F4;
	sub_82182D28(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82183a20
	ctx.lr = 0x82185400;
	sub_82183A20(ctx, base);
	// lwz r11,-32156(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218541c
	if (ctx.cr6.eq) goto loc_8218541C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82183658
	ctx.lr = 0x8218541C;
	sub_82183658(ctx, base);
loc_8218541C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82184578
	ctx.lr = 0x82185424;
	sub_82184578(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 | 1;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820995f0
	ctx.lr = 0x82185440;
	sub_820995F0(ctx, base);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r4,r10,-12992
	ctx.r4.s64 = ctx.r10.s64 + -12992;
	// bl 0x82182150
	ctx.lr = 0x82185450;
	sub_82182150(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,1152(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1152);
	// rlwimi r7,r10,11,19,21
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x1C00) | (ctx.r7.u64 & 0xFFFFFFFFFFFFE3FF);
	// stw r7,1152(r8)
	PPC_STORE_U32(ctx.r8.u32 + 1152, ctx.r7.u32);
	// ld r6,24(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// oris r3,r6,32768
	ctx.r3.u64 = ctx.r6.u64 | 2147483648;
	// std r3,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r3.u64);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,1152(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1152);
	// rlwimi r7,r10,14,16,18
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 14) & 0xE000) | (ctx.r7.u64 & 0xFFFFFFFFFFFF1FFF);
	// stw r7,1152(r8)
	PPC_STORE_U32(ctx.r8.u32 + 1152, ctx.r7.u32);
	// ld r6,24(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// oris r3,r6,32768
	ctx.r3.u64 = ctx.r6.u64 | 2147483648;
	// std r3,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r3.u64);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,1164(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1164);
	// rlwimi r7,r10,23,7,8
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 23) & 0x1800000) | (ctx.r7.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r7,1164(r8)
	PPC_STORE_U32(ctx.r8.u32 + 1164, ctx.r7.u32);
	// ld r6,24(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 24);
	// oris r3,r6,32768
	ctx.r3.u64 = ctx.r6.u64 | 2147483648;
	// std r3,24(r8)
	PPC_STORE_U64(ctx.r8.u32 + 24, ctx.r3.u64);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82098860
	ctx.lr = 0x821854CC;
	sub_82098860(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x820986b8
	ctx.lr = 0x821854E4;
	sub_820986B8(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x82185504;
	sub_8209D660(ctx, base);
	// lwz r3,-31340(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31340);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218551c
	if (ctx.cr6.eq) goto loc_8218551C;
	// bl 0x820a4400
	ctx.lr = 0x82185514;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31340(r29)
	PPC_STORE_U32(ctx.r29.u32 + -31340, ctx.r11.u32);
loc_8218551C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82185524"))) PPC_WEAK_FUNC(sub_82185524);
PPC_FUNC_IMPL(__imp__sub_82185524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185528"))) PPC_WEAK_FUNC(sub_82185528);
PPC_FUNC_IMPL(__imp__sub_82185528) {
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
	// bl 0x82181508
	ctx.lr = 0x82185544;
	sub_82181508(ctx, base);
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r10,80(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,92(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// lwz r11,156(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82185578
	if (!ctx.cr6.eq) goto loc_82185578;
	// lwz r9,488(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 488);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82185578
	if (ctx.cr6.eq) goto loc_82185578;
	// stw r10,488(r11)
	PPC_STORE_U32(ctx.r11.u32 + 488, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82185594
	goto loc_82185594;
loc_82185578:
	// lwz r9,488(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 488);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x821855a8
	if (ctx.cr6.eq) goto loc_821855A8;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r9,488(r11)
	PPC_STORE_U32(ctx.r11.u32 + 488, ctx.r9.u32);
	// lwz r5,8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
loc_82185594:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// oris r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 2147483648;
	// bl 0x8209d660
	ctx.lr = 0x821855A8;
	sub_8209D660(ctx, base);
loc_821855A8:
	// bl 0x821852c8
	ctx.lr = 0x821855AC;
	sub_821852C8(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209af10
	ctx.lr = 0x821855C0;
	sub_8209AF10(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,500(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 500);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x821855D4;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,504(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 504);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x821855E8;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x82097540
	ctx.lr = 0x821855FC;
	sub_82097540(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x820972d8
	ctx.lr = 0x82185610;
	sub_820972D8(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x82096e78
	ctx.lr = 0x82185624;
	sub_82096E78(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x82097338
	ctx.lr = 0x82185638;
	sub_82097338(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x8218564C;
	sub_82096FD0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x82185660;
	sub_82097060(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82096eb0
	ctx.lr = 0x82185674;
	sub_82096EB0(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d628
	ctx.lr = 0x82185680;
	sub_8216D628(ctx, base);
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

__attribute__((alias("__imp__sub_82185698"))) PPC_WEAK_FUNC(sub_82185698);
PPC_FUNC_IMPL(__imp__sub_82185698) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8284(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821856AC"))) PPC_WEAK_FUNC(sub_821856AC);
PPC_FUNC_IMPL(__imp__sub_821856AC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821856B0"))) PPC_WEAK_FUNC(sub_821856B0);
PPC_FUNC_IMPL(__imp__sub_821856B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821856C4"))) PPC_WEAK_FUNC(sub_821856C4);
PPC_FUNC_IMPL(__imp__sub_821856C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821856C8"))) PPC_WEAK_FUNC(sub_821856C8);
PPC_FUNC_IMPL(__imp__sub_821856C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821856CC"))) PPC_WEAK_FUNC(sub_821856CC);
PPC_FUNC_IMPL(__imp__sub_821856CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821856D0"))) PPC_WEAK_FUNC(sub_821856D0);
PPC_FUNC_IMPL(__imp__sub_821856D0) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821856E0"))) PPC_WEAK_FUNC(sub_821856E0);
PPC_FUNC_IMPL(__imp__sub_821856E0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821856E4"))) PPC_WEAK_FUNC(sub_821856E4);
PPC_FUNC_IMPL(__imp__sub_821856E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821856E8"))) PPC_WEAK_FUNC(sub_821856E8);
PPC_FUNC_IMPL(__imp__sub_821856E8) {
	PPC_FUNC_PROLOGUE();
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185704"))) PPC_WEAK_FUNC(sub_82185704);
PPC_FUNC_IMPL(__imp__sub_82185704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185708"))) PPC_WEAK_FUNC(sub_82185708);
PPC_FUNC_IMPL(__imp__sub_82185708) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82185714
	if (!ctx.cr6.eq) goto loc_82185714;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82185714:
	// li r11,100
	ctx.r11.s64 = 100;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185728"))) PPC_WEAK_FUNC(sub_82185728);
PPC_FUNC_IMPL(__imp__sub_82185728) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218572C"))) PPC_WEAK_FUNC(sub_8218572C);
PPC_FUNC_IMPL(__imp__sub_8218572C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185730"))) PPC_WEAK_FUNC(sub_82185730);
PPC_FUNC_IMPL(__imp__sub_82185730) {
	PPC_FUNC_PROLOGUE();
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,100
	ctx.r11.s64 = 100;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185754"))) PPC_WEAK_FUNC(sub_82185754);
PPC_FUNC_IMPL(__imp__sub_82185754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185758"))) PPC_WEAK_FUNC(sub_82185758);
PPC_FUNC_IMPL(__imp__sub_82185758) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x821d5184
	ctx.lr = 0x82185774;
	__imp__XGetVideoMode(ctx, base);
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82185798
	if (ctx.cr6.eq) goto loc_82185798;
	// li r3,40
	ctx.r3.s64 = 40;
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
loc_82185798:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,80
	ctx.r3.s64 = 80;
	// cmplwi cr6,r11,1280
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1280, ctx.xer);
	// bgt cr6,0x821857ac
	if (ctx.cr6.gt) goto loc_821857AC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821857AC:
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

__attribute__((alias("__imp__sub_821857C0"))) PPC_WEAK_FUNC(sub_821857C0);
PPC_FUNC_IMPL(__imp__sub_821857C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r9,4
	ctx.r9.s64 = 4;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,1516
	ctx.r11.s64 = ctx.r3.s64 + 1516;
	// stw r10,1424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1424, ctx.r10.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_821857D8:
	// stwu r10,32(r11)
	ea = 32 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821857d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821857D8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821857E4"))) PPC_WEAK_FUNC(sub_821857E4);
PPC_FUNC_IMPL(__imp__sub_821857E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821857E8"))) PPC_WEAK_FUNC(sub_821857E8);
PPC_FUNC_IMPL(__imp__sub_821857E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821857EC"))) PPC_WEAK_FUNC(sub_821857EC);
PPC_FUNC_IMPL(__imp__sub_821857EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821857F0"))) PPC_WEAK_FUNC(sub_821857F0);
PPC_FUNC_IMPL(__imp__sub_821857F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821857F4"))) PPC_WEAK_FUNC(sub_821857F4);
PPC_FUNC_IMPL(__imp__sub_821857F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821857F8"))) PPC_WEAK_FUNC(sub_821857F8);
PPC_FUNC_IMPL(__imp__sub_821857F8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82185804
	if (!ctx.cr6.eq) goto loc_82185804;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82185804:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// stw r8,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185828"))) PPC_WEAK_FUNC(sub_82185828);
PPC_FUNC_IMPL(__imp__sub_82185828) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218582C"))) PPC_WEAK_FUNC(sub_8218582C);
PPC_FUNC_IMPL(__imp__sub_8218582C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185830"))) PPC_WEAK_FUNC(sub_82185830);
PPC_FUNC_IMPL(__imp__sub_82185830) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82185868"))) PPC_WEAK_FUNC(sub_82185868);
PPC_FUNC_IMPL(__imp__sub_82185868) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8218587c
	if (!ctx.cr6.eq) goto loc_8218587C;
	// lbz r11,6(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r11.u8);
	// blr 
	return;
loc_8218587C:
	// lbz r11,6(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// stb r11,5(r4)
	PPC_STORE_U8(ctx.r4.u32 + 5, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185888"))) PPC_WEAK_FUNC(sub_82185888);
PPC_FUNC_IMPL(__imp__sub_82185888) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82185890;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x821858a8
	if (!ctx.cr6.eq) goto loc_821858A8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_821858A8:
	// clrlwi r11,r29,31
	ctx.r11.u64 = ctx.r29.u32 & 0x1;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821858ec
	if (ctx.cr6.eq) goto loc_821858EC;
	// std r30,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r30.u64);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,2
	ctx.r10.s64 = 2;
	// std r30,8(r31)
	PPC_STORE_U64(ctx.r31.u32 + 8, ctx.r30.u64);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r11,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// stb r10,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r10.u8);
	// stb r11,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r11.u8);
	// stb r9,7(r31)
	PPC_STORE_U8(ctx.r31.u32 + 7, ctx.r9.u8);
	// stb r30,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r30.u8);
	// stb r30,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r30.u8);
	// stb r30,3(r31)
	PPC_STORE_U8(ctx.r31.u32 + 3, ctx.r30.u8);
	// stb r30,8(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8, ctx.r30.u8);
loc_821858EC:
	// rlwinm r11,r29,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82185908
	if (ctx.cr6.eq) goto loc_82185908;
	// li r5,5760
	ctx.r5.s64 = 5760;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x8207da20
	ctx.lr = 0x82185908;
	sub_8207DA20(ctx, base);
loc_82185908:
	// rlwinm r11,r29,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82185924
	if (ctx.cr6.eq) goto loc_82185924;
	// std r30,5776(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5776, ctx.r30.u64);
	// std r30,5784(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5784, ctx.r30.u64);
	// std r30,5792(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5792, ctx.r30.u64);
	// std r30,5800(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5800, ctx.r30.u64);
loc_82185924:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218592C"))) PPC_WEAK_FUNC(sub_8218592C);
PPC_FUNC_IMPL(__imp__sub_8218592C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185930"))) PPC_WEAK_FUNC(sub_82185930);
PPC_FUNC_IMPL(__imp__sub_82185930) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185934"))) PPC_WEAK_FUNC(sub_82185934);
PPC_FUNC_IMPL(__imp__sub_82185934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185938"))) PPC_WEAK_FUNC(sub_82185938);
PPC_FUNC_IMPL(__imp__sub_82185938) {
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
	// li r5,5808
	ctx.r5.s64 = 5808;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x8218595C;
	sub_8207DA20(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,3
	ctx.r11.s64 = 3;
	// std r30,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r30.u64);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,1
	ctx.r9.s64 = 1;
	// std r30,8(r31)
	PPC_STORE_U64(ctx.r31.u32 + 8, ctx.r30.u64);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r5,5760
	ctx.r5.s64 = 5760;
	// stb r10,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r10.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r11.u8);
	// stb r11,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r11.u8);
	// stb r9,7(r31)
	PPC_STORE_U8(ctx.r31.u32 + 7, ctx.r9.u8);
	// stb r30,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r30.u8);
	// stb r30,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r30.u8);
	// stb r30,3(r31)
	PPC_STORE_U8(ctx.r31.u32 + 3, ctx.r30.u8);
	// stb r30,8(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8, ctx.r30.u8);
	// bl 0x8207da20
	ctx.lr = 0x821859A4;
	sub_8207DA20(ctx, base);
	// std r30,5776(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5776, ctx.r30.u64);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r30,5784(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5784, ctx.r30.u64);
	// std r30,5792(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5792, ctx.r30.u64);
	// std r30,5800(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5800, ctx.r30.u64);
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

__attribute__((alias("__imp__sub_821859D0"))) PPC_WEAK_FUNC(sub_821859D0);
PPC_FUNC_IMPL(__imp__sub_821859D0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x821859f8
	if (!ctx.cr6.eq) goto loc_821859F8;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82185a00
	goto loc_82185A00;
loc_821859F8:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82185A00:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82185a24
	if (!ctx.cr6.eq) goto loc_82185A24;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,28024
	ctx.r10.s64 = ctx.r11.s64 + 28024;
	// stw r10,8284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8284, ctx.r10.u32);
	// blr 
	return;
loc_82185A24:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-29864
	ctx.r10.s64 = ctx.r11.s64 + -29864;
	// stw r10,8284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8284, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185A34"))) PPC_WEAK_FUNC(sub_82185A34);
PPC_FUNC_IMPL(__imp__sub_82185A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185A38"))) PPC_WEAK_FUNC(sub_82185A38);
PPC_FUNC_IMPL(__imp__sub_82185A38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82185A40;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r31,84(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82185aa0
	if (!ctx.cr6.eq) goto loc_82185AA0;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185a88
	if (ctx.cr6.eq) goto loc_82185A88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x82185A7C;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185a88
	if (ctx.cr6.eq) goto loc_82185A88;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
loc_82185A88:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82185aa0
	if (!ctx.cr6.eq) goto loc_82185AA0;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_82185AA0:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,22992
	ctx.r10.s64 = ctx.r11.s64 + 22992;
	// stw r10,8284(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8284, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82185AB4"))) PPC_WEAK_FUNC(sub_82185AB4);
PPC_FUNC_IMPL(__imp__sub_82185AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185AB8"))) PPC_WEAK_FUNC(sub_82185AB8);
PPC_FUNC_IMPL(__imp__sub_82185AB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r4,-31348(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// addi r11,r4,7296
	ctx.r11.s64 = ctx.r4.s64 + 7296;
	// addi r8,r11,5808
	ctx.r8.s64 = ctx.r11.s64 + 5808;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
loc_82185ACC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82185aec
	if (!ctx.cr0.eq) goto loc_82185AEC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82185acc
	if (!ctx.cr6.eq) goto loc_82185ACC;
loc_82185AEC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82185afc
	if (ctx.cr6.eq) goto loc_82185AFC;
loc_82185AF4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82185AFC:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r4,13104
	ctx.r8.s64 = ctx.r4.s64 + 13104;
	// addi r6,r4,4
	ctx.r6.s64 = ctx.r4.s64 + 4;
loc_82185B08:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// addi r7,r8,16
	ctx.r7.s64 = ctx.r8.s64 + 16;
loc_82185B14:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82185b34
	if (!ctx.cr0.eq) goto loc_82185B34;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bne cr6,0x82185b14
	if (!ctx.cr6.eq) goto loc_82185B14;
loc_82185B34:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82185af4
	if (!ctx.cr6.eq) goto loc_82185AF4;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpwi cr6,r5,2
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 2, ctx.xer);
	// blt cr6,0x82185b08
	if (ctx.cr6.lt) goto loc_82185B08;
	// addi r11,r4,13136
	ctx.r11.s64 = ctx.r4.s64 + 13136;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r8,r11,1408
	ctx.r8.s64 = ctx.r11.s64 + 1408;
loc_82185B5C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82185b7c
	if (!ctx.cr0.eq) goto loc_82185B7C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82185b5c
	if (!ctx.cr6.eq) goto loc_82185B5C;
loc_82185B7C:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82185af4
	if (!ctx.cr6.eq) goto loc_82185AF4;
	// addi r11,r4,14544
	ctx.r11.s64 = ctx.r4.s64 + 14544;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// addi r8,r11,12
	ctx.r8.s64 = ctx.r11.s64 + 12;
loc_82185B90:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82185bb0
	if (!ctx.cr0.eq) goto loc_82185BB0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82185b90
	if (!ctx.cr6.eq) goto loc_82185B90;
loc_82185BB0:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82185af4
	if (!ctx.cr6.eq) goto loc_82185AF4;
	// addi r11,r4,14556
	ctx.r11.s64 = ctx.r4.s64 + 14556;
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
loc_82185BC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82185be4
	if (!ctx.cr0.eq) goto loc_82185BE4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x82185bc4
	if (!ctx.cr6.eq) goto loc_82185BC4;
loc_82185BE4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82185af4
	if (!ctx.cr6.eq) goto loc_82185AF4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,14568(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 14568);
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// subf r6,r10,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r10.s64;
	// addic r5,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// subfe r3,r5,r6
	temp.u8 = (~ctx.r5.u32 + ctx.r6.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r5.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82185C14"))) PPC_WEAK_FUNC(sub_82185C14);
PPC_FUNC_IMPL(__imp__sub_82185C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185C18"))) PPC_WEAK_FUNC(sub_82185C18);
PPC_FUNC_IMPL(__imp__sub_82185C18) {
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
	// li r5,7272
	ctx.r5.s64 = 7272;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,-31348(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// addi r30,r31,7296
	ctx.r30.s64 = ctx.r31.s64 + 7296;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82185C48;
	sub_8207DA20(ctx, base);
	// li r5,5808
	ctx.r5.s64 = 5808;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x82185C58;
	sub_8207DAC0(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r31,13104
	ctx.r11.s64 = ctx.r31.s64 + 13104;
	// addi r3,r31,13136
	ctx.r3.s64 = ctx.r31.s64 + 13136;
	// li r5,1408
	ctx.r5.s64 = 1408;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,13104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13104, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,13108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13108, ctx.r8.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r7,13112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13112, ctx.r7.u32);
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r6,13116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13116, ctx.r6.u32);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,13120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13120, ctx.r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,13124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13124, ctx.r10.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,13128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13128, ctx.r9.u32);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,13132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 13132, ctx.r8.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207dac0
	ctx.lr = 0x82185CB4;
	sub_8207DAC0(ctx, base);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,-31352(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31352);
	// stw r5,14544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14544, ctx.r5.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r4,14548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14548, ctx.r4.u32);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stw r3,14552(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14552, ctx.r3.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,14556(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14556, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,14560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14560, ctx.r8.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r6,84(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// lwz r5,52(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// stw r5,14568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14568, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_82185D14"))) PPC_WEAK_FUNC(sub_82185D14);
PPC_FUNC_IMPL(__imp__sub_82185D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185D18"))) PPC_WEAK_FUNC(sub_82185D18);
PPC_FUNC_IMPL(__imp__sub_82185D18) {
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
	// li r5,7272
	ctx.r5.s64 = 7272;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,-31348(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// addi r30,r31,24
	ctx.r30.s64 = ctx.r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82185D48;
	sub_8207DA20(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,5808
	ctx.r5.s64 = 5808;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x82185D58;
	sub_8207DAC0(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r11,r31,5832
	ctx.r11.s64 = ctx.r31.s64 + 5832;
	// addi r3,r31,5864
	ctx.r3.s64 = ctx.r31.s64 + 5864;
	// li r5,1408
	ctx.r5.s64 = 1408;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,5832(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5832, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,5836(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5836, ctx.r8.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r7,5840(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5840, ctx.r7.u32);
	// lwz r6,12(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r6,5844(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5844, ctx.r6.u32);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r11,5848(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5848, ctx.r11.u32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,5852(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5852, ctx.r10.u32);
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r9,5856(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5856, ctx.r9.u32);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,5860(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5860, ctx.r8.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207dac0
	ctx.lr = 0x82185DB4;
	sub_8207DAC0(ctx, base);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,7272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7272, ctx.r6.u32);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r5,7276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7276, ctx.r5.u32);
	// lwz r4,8(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stw r4,7280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7280, ctx.r4.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,7284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7284, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,7288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7288, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82185E00"))) PPC_WEAK_FUNC(sub_82185E00);
PPC_FUNC_IMPL(__imp__sub_82185E00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82185E08;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185e20
	if (ctx.cr6.eq) goto loc_82185E20;
	// bl 0x8207a630
	ctx.lr = 0x82185E20;
	sub_8207A630(ctx, base);
loc_82185E20:
	// addi r31,r29,4
	ctx.r31.s64 = ctx.r29.s64 + 4;
	// li r30,2
	ctx.r30.s64 = 2;
loc_82185E28:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185e38
	if (ctx.cr6.eq) goto loc_82185E38;
	// bl 0x8207a630
	ctx.lr = 0x82185E38;
	sub_8207A630(ctx, base);
loc_82185E38:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x82185e28
	if (!ctx.cr0.eq) goto loc_82185E28;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185e54
	if (ctx.cr6.eq) goto loc_82185E54;
	// bl 0x8207a630
	ctx.lr = 0x82185E54;
	sub_8207A630(ctx, base);
loc_82185E54:
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185e64
	if (ctx.cr6.eq) goto loc_82185E64;
	// bl 0x8207a630
	ctx.lr = 0x82185E64;
	sub_8207A630(ctx, base);
loc_82185E64:
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82185e74
	if (ctx.cr6.eq) goto loc_82185E74;
	// bl 0x8207a630
	ctx.lr = 0x82185E74;
	sub_8207A630(ctx, base);
loc_82185E74:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82185E7C"))) PPC_WEAK_FUNC(sub_82185E7C);
PPC_FUNC_IMPL(__imp__sub_82185E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185E80"))) PPC_WEAK_FUNC(sub_82185E80);
PPC_FUNC_IMPL(__imp__sub_82185E80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82185E88;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82185ea0
	if (!ctx.cr6.eq) goto loc_82185EA0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82185EA0:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82185ebc
	if (!ctx.cr6.lt) goto loc_82185EBC;
	// stw r30,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r30.u32);
	// b 0x82185ec8
	goto loc_82185EC8;
loc_82185EBC:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x82185ec8
	if (!ctx.cr6.gt) goto loc_82185EC8;
	// stw r10,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
loc_82185EC8:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r31,r11,r29
	ctx.r31.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82185ee8
	if (!ctx.cr6.lt) goto loc_82185EE8;
	// stw r30,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r30.u32);
	// b 0x82185ef4
	goto loc_82185EF4;
loc_82185EE8:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x82185ef4
	if (!ctx.cr6.gt) goto loc_82185EF4;
	// stw r10,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r10.u32);
loc_82185EF4:
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// rlwinm r10,r25,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x2;
	// li r26,2
	ctx.r26.s64 = 2;
	// addi r9,r11,24
	ctx.r9.s64 = ctx.r11.s64 + 24;
	// li r28,1
	ctx.r28.s64 = 1;
	// mulli r11,r9,44
	ctx.r11.s64 = ctx.r9.s64 * 44;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r27,r11,r29
	ctx.r27.u64 = ctx.r11.u64 + ctx.r29.u64;
	// beq cr6,0x82185fa0
	if (ctx.cr6.eq) goto loc_82185FA0;
	// li r11,8
	ctx.r11.s64 = 8;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bl 0x82185758
	ctx.lr = 0x82185F30;
	sub_82185758(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stw r26,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r26,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r26.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stw r28,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r28.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r26,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r26.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// stw r28,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r28.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// stw r30,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r26,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r26.u32);
	// stw r30,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// stw r28,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r28.u32);
	// stw r30,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r30.u32);
loc_82185FA0:
	// rlwinm r11,r25,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82185fc8
	if (ctx.cr6.eq) goto loc_82185FC8;
	// li r11,16
	ctx.r11.s64 = 16;
	// stw r28,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// stw r30,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r30.u32);
	// stw r11,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// stw r30,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r30.u32);
	// stw r30,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r30.u32);
	// stw r11,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r11.u32);
loc_82185FC8:
	// rlwinm r11,r25,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82185fe8
	if (ctx.cr6.eq) goto loc_82185FE8;
	// stw r30,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r30.u32);
	// stw r30,28(r27)
	PPC_STORE_U32(ctx.r27.u32 + 28, ctx.r30.u32);
	// stw r30,32(r27)
	PPC_STORE_U32(ctx.r27.u32 + 32, ctx.r30.u32);
	// stw r30,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r30.u32);
	// stw r30,40(r27)
	PPC_STORE_U32(ctx.r27.u32 + 40, ctx.r30.u32);
loc_82185FE8:
	// rlwinm r11,r25,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8218600c
	if (ctx.cr6.eq) goto loc_8218600C;
	// li r11,90
	ctx.r11.s64 = 90;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// stw r28,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r28.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// stw r28,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r28.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
loc_8218600C:
	// rlwinm r11,r25,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82186030
	if (ctx.cr6.eq) goto loc_82186030;
	// stw r30,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// stw r26,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// stw r28,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r28.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
loc_82186030:
	// rlwinm r11,r25,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x40;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82186054
	if (ctx.cr6.eq) goto loc_82186054;
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stw r26,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r26.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stw r28,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r28.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
loc_82186054:
	// rlwinm r11,r25,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x80;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82186078
	if (ctx.cr6.eq) goto loc_82186078;
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r26,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r26.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// stw r28,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r28.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
loc_82186078:
	// rlwinm r11,r25,0,23,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8218609c
	if (ctx.cr6.eq) goto loc_8218609C;
	// stw r30,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r26,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r26.u32);
	// stw r30,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r30.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// stw r28,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r28.u32);
	// stw r30,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r30.u32);
loc_8218609C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821860A4"))) PPC_WEAK_FUNC(sub_821860A4);
PPC_FUNC_IMPL(__imp__sub_821860A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821860A8"))) PPC_WEAK_FUNC(sub_821860A8);
PPC_FUNC_IMPL(__imp__sub_821860A8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x821860b4
	if (!ctx.cr6.eq) goto loc_821860B4;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_821860B4:
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x821860d0
	if (!ctx.cr6.lt) goto loc_821860D0;
	// stw r10,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r10.u32);
	// b 0x821860dc
	goto loc_821860DC;
loc_821860D0:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x821860dc
	if (!ctx.cr6.gt) goto loc_821860DC;
	// stw r9,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r9.u32);
loc_821860DC:
	// lwz r11,28(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x821860f0
	if (!ctx.cr6.lt) goto loc_821860F0;
	// stw r10,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r10.u32);
	// b 0x821860fc
	goto loc_821860FC;
loc_821860F0:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x821860fc
	if (!ctx.cr6.gt) goto loc_821860FC;
	// stw r9,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r9.u32);
loc_821860FC:
	// lwz r11,28(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// addi r9,r5,-1
	ctx.r9.s64 = ctx.r5.s64 + -1;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// mulli r11,r11,44
	ctx.r11.s64 = ctx.r11.s64 * 44;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82186168
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186168;
	// bdzf 4*cr6+eq,0x821861ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821861AC;
	// bdzf 4*cr6+eq,0x821861ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821861EC;
	// bdzf 4*cr6+eq,0x82186230
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186230;
	// bdzf 4*cr6+eq,0x82186278
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186278;
	// bne cr6,0x821862bc
	if (!ctx.cr6.eq) goto loc_821862BC;
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r7,22
	ctx.r7.s64 = 22;
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// li r9,-2
	ctx.r9.s64 = -2;
	// stw r5,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r5.u32);
	// li r6,6
	ctx.r6.s64 = 6;
	// stw r4,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r4.u32);
	// b 0x821862e0
	goto loc_821862E0;
loc_82186168:
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// li r6,12
	ctx.r6.s64 = 12;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// li r4,-5
	ctx.r4.s64 = -5;
	// stw r9,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// stw r5,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// stw r4,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r4.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// blr 
	return;
loc_821861AC:
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// li r8,24
	ctx.r8.s64 = 24;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// stw r6,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r6.u32);
	// stw r5,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r5.u32);
	// stw r10,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r10.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// blr 
	return;
loc_821861EC:
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// li r7,31
	ctx.r7.s64 = 31;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// li r6,28
	ctx.r6.s64 = 28;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// li r4,-2
	ctx.r4.s64 = -2;
	// stw r9,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r9.u32);
	// stw r5,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r5.u32);
	// stw r4,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r4.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// blr 
	return;
loc_82186230:
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r8,34
	ctx.r8.s64 = 34;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// li r7,14
	ctx.r7.s64 = 14;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// stw r7,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// li r4,8
	ctx.r4.s64 = 8;
	// stw r6,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// stw r5,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r5.u32);
	// stw r4,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r4.u32);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// stw r3,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r3.u32);
	// blr 
	return;
loc_82186278:
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r7,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r7.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
	// stw r5,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r5.u32);
	// stw r4,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r4.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// blr 
	return;
loc_821862BC:
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// li r8,5
	ctx.r8.s64 = 5;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
loc_821862E0:
	// stw r9,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r9.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r9,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// stw r6,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r6.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821862F8"))) PPC_WEAK_FUNC(sub_821862F8);
PPC_FUNC_IMPL(__imp__sub_821862F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82186304
	if (!ctx.cr6.eq) goto loc_82186304;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82186304:
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,7
	ctx.r7.s64 = 7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82186320
	if (!ctx.cr6.lt) goto loc_82186320;
	// stw r10,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r10.u32);
	// b 0x8218632c
	goto loc_8218632C;
loc_82186320:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x8218632c
	if (!ctx.cr6.gt) goto loc_8218632C;
	// stw r7,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r7.u32);
loc_8218632C:
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lwz r9,28(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// bge cr6,0x82186350
	if (!ctx.cr6.lt) goto loc_82186350;
	// stw r10,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r10.u32);
	// b 0x8218635c
	goto loc_8218635C;
loc_82186350:
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// ble cr6,0x8218635c
	if (!ctx.cr6.gt) goto loc_8218635C;
	// stw r7,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r7.u32);
loc_8218635C:
	// addi r9,r5,-1
	ctx.r9.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r9,6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 6, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8218641c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8218641C;
	// bdzf 4*cr6+eq,0x82186430
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186430;
	// bdzf 4*cr6+eq,0x82186480
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186480;
	// bdzf 4*cr6+eq,0x82186500
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186500;
	// bdzf 4*cr6+eq,0x82186538
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82186538;
	// bne cr6,0x821865bc
	if (!ctx.cr6.eq) goto loc_821865BC;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r9,r9,4456
	ctx.r9.s64 = ctx.r9.s64 + 4456;
	// li r6,-158
	ctx.r6.s64 = -158;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r8,r11,28
	ctx.r8.s64 = ctx.r11.s64 + 28;
	// stw r6,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r6.u32);
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_821863B8:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x821863b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821863B8;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,52
	ctx.r8.s64 = ctx.r11.s64 + 52;
	// addi r10,r9,20
	ctx.r10.s64 = ctx.r9.s64 + 20;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_821863D4:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x821863d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821863D4;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,76
	ctx.r8.s64 = ctx.r11.s64 + 76;
	// addi r10,r9,44
	ctx.r10.s64 = ctx.r9.s64 + 44;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_821863F0:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x821863f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821863F0;
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r10,r11,100
	ctx.r10.s64 = ctx.r11.s64 + 100;
	// addi r11,r9,68
	ctx.r11.s64 = ctx.r9.s64 + 68;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8218640C:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8218640c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218640C;
	// blr 
	return;
loc_8218641C:
	// li r10,9
	ctx.r10.s64 = 9;
	// li r9,80
	ctx.r9.s64 = 80;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// blr 
	return;
loc_82186430:
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// li r10,-80
	ctx.r10.s64 = -80;
	// addi r9,r9,4552
	ctx.r9.s64 = ctx.r9.s64 + 4552;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// addi r8,r11,28
	ctx.r8.s64 = ctx.r11.s64 + 28;
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82186454:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82186454
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186454;
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r10,r11,52
	ctx.r10.s64 = ctx.r11.s64 + 52;
	// addi r11,r9,20
	ctx.r11.s64 = ctx.r9.s64 + 20;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82186470:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82186470
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186470;
	// blr 
	return;
loc_82186480:
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r9,r9,4600
	ctx.r9.s64 = ctx.r9.s64 + 4600;
	// addi r8,r11,28
	ctx.r8.s64 = ctx.r11.s64 + 28;
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8218649C:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x8218649c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218649C;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,52
	ctx.r8.s64 = ctx.r11.s64 + 52;
	// addi r10,r9,20
	ctx.r10.s64 = ctx.r9.s64 + 20;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_821864B8:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x821864b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821864B8;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,76
	ctx.r8.s64 = ctx.r11.s64 + 76;
	// addi r10,r9,44
	ctx.r10.s64 = ctx.r9.s64 + 44;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_821864D4:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x821864d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821864D4;
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r10,r11,100
	ctx.r10.s64 = ctx.r11.s64 + 100;
	// addi r11,r9,68
	ctx.r11.s64 = ctx.r9.s64 + 68;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_821864F0:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x821864f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821864F0;
	// blr 
	return;
loc_82186500:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// li r7,138
	ctx.r7.s64 = 138;
	// addi r8,r8,4696
	ctx.r8.s64 = ctx.r8.s64 + 4696;
	// addi r10,r11,28
	ctx.r10.s64 = ctx.r11.s64 + 28;
	// stw r7,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r7.u32);
	// addi r11,r8,-4
	ctx.r11.s64 = ctx.r8.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82186528:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82186528
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186528;
	// blr 
	return;
loc_82186538:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r7,6
	ctx.r7.s64 = 6;
	// li r9,-120
	ctx.r9.s64 = -120;
	// addi r10,r10,4720
	ctx.r10.s64 = ctx.r10.s64 + 4720;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// addi r8,r11,28
	ctx.r8.s64 = ctx.r11.s64 + 28;
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82186558:
	// lwzu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82186558
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186558;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,52
	ctx.r8.s64 = ctx.r11.s64 + 52;
	// addi r9,r10,20
	ctx.r9.s64 = ctx.r10.s64 + 20;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82186574:
	// lwzu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82186574
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186574;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,76
	ctx.r8.s64 = ctx.r11.s64 + 76;
	// addi r9,r10,44
	ctx.r9.s64 = ctx.r10.s64 + 44;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82186590:
	// lwzu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82186590
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186590;
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r9,r11,100
	ctx.r9.s64 = ctx.r11.s64 + 100;
	// addi r11,r10,68
	ctx.r11.s64 = ctx.r10.s64 + 68;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_821865AC:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x821865ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821865AC;
	// blr 
	return;
loc_821865BC:
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r8,-80
	ctx.r8.s64 = -80;
	// addi r9,r9,4816
	ctx.r9.s64 = ctx.r9.s64 + 4816;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r6,-240
	ctx.r6.s64 = -240;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// addi r8,r11,28
	ctx.r8.s64 = ctx.r11.s64 + 28;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// stw r6,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r6.u32);
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
loc_821865F0:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x821865f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821865F0;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,52
	ctx.r8.s64 = ctx.r11.s64 + 52;
	// addi r10,r9,20
	ctx.r10.s64 = ctx.r9.s64 + 20;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8218660C:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x8218660c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218660C;
	// li r7,6
	ctx.r7.s64 = 6;
	// addi r8,r11,76
	ctx.r8.s64 = ctx.r11.s64 + 76;
	// addi r10,r9,44
	ctx.r10.s64 = ctx.r9.s64 + 44;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_82186628:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x82186628
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186628;
	// li r8,6
	ctx.r8.s64 = 6;
	// addi r10,r11,100
	ctx.r10.s64 = ctx.r11.s64 + 100;
	// addi r11,r9,68
	ctx.r11.s64 = ctx.r9.s64 + 68;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82186644:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82186644
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186644;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186654"))) PPC_WEAK_FUNC(sub_82186654);
PPC_FUNC_IMPL(__imp__sub_82186654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186658"))) PPC_WEAK_FUNC(sub_82186658);
PPC_FUNC_IMPL(__imp__sub_82186658) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82186660;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82186678
	if (!ctx.cr6.eq) goto loc_82186678;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82186678:
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82186680:
	// stw r31,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r31.u32);
	// li r5,30
	ctx.r5.s64 = 30;
	// stw r31,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r31.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82185e80
	ctx.lr = 0x82186698;
	sub_82185E80(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821862f8
	ctx.lr = 0x821866A8;
	sub_821862F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821860a8
	ctx.lr = 0x821866B0;
	sub_821860A8(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,8
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 8, ctx.xer);
	// blt cr6,0x82186680
	if (ctx.cr6.lt) goto loc_82186680;
	// stw r28,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r28.u32);
	// stw r28,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821866CC"))) PPC_WEAK_FUNC(sub_821866CC);
PPC_FUNC_IMPL(__imp__sub_821866CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821866D0"))) PPC_WEAK_FUNC(sub_821866D0);
PPC_FUNC_IMPL(__imp__sub_821866D0) {
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
	// lwz r11,8268(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821866f8
	if (ctx.cr6.eq) goto loc_821866F8;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821866F8:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82186708;
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

__attribute__((alias("__imp__sub_82186738"))) PPC_WEAK_FUNC(sub_82186738);
PPC_FUNC_IMPL(__imp__sub_82186738) {
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
	// lwz r11,8296(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8296);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,7504
	ctx.r9.s64 = ctx.r10.s64 + 7504;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82186778
	if (!ctx.cr6.eq) goto loc_82186778;
	// lwz r9,148(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 148);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82186778
	if (!ctx.cr6.eq) goto loc_82186778;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x821867ac
	goto loc_821867AC;
loc_82186778:
	// lwz r9,256(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 256);
	// cmpwi cr6,r9,180
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 180, ctx.xer);
	// blt cr6,0x821867a8
	if (ctx.cr6.lt) goto loc_821867A8;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,7536
	ctx.r8.s64 = ctx.r9.s64 + 7536;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x821867a8
	if (!ctx.cr6.eq) goto loc_821867A8;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,23176
	ctx.r8.s64 = ctx.r9.s64 + 23176;
	// stw r8,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r8.u32);
	// b 0x821867ac
	goto loc_821867AC;
loc_821867A8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821867AC:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821867e4
	if (ctx.cr6.eq) goto loc_821867E4;
	// lwz r11,8276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821867cc
	if (ctx.cr6.eq) goto loc_821867CC;
	// lwz r10,8272(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8272);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821867CC:
	// lwz r11,8272(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8272);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x821867dc
	if (!ctx.cr6.eq) goto loc_821867DC;
	// bl 0x82185c18
	ctx.lr = 0x821867DC;
	sub_82185C18(ctx, base);
loc_821867DC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_821867E4:
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

__attribute__((alias("__imp__sub_821867F8"))) PPC_WEAK_FUNC(sub_821867F8);
PPC_FUNC_IMPL(__imp__sub_821867F8) {
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
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82186834
	if (!ctx.cr6.eq) goto loc_82186834;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8218683c
	goto loc_8218683C;
loc_82186834:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8218683C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821868b0
	if (ctx.cr6.eq) goto loc_821868B0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821868a4
	if (!ctx.cr6.eq) goto loc_821868A4;
	// lwz r11,8276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82186864
	if (ctx.cr6.eq) goto loc_82186864;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82186864:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82186874;
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
loc_821868A4:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,31272
	ctx.r10.s64 = ctx.r11.s64 + 31272;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821868B0:
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

__attribute__((alias("__imp__sub_821868C4"))) PPC_WEAK_FUNC(sub_821868C4);
PPC_FUNC_IMPL(__imp__sub_821868C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821868C8"))) PPC_WEAK_FUNC(sub_821868C8);
PPC_FUNC_IMPL(__imp__sub_821868C8) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r31,84(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8218693c
	if (!ctx.cr6.eq) goto loc_8218693C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82186920
	if (ctx.cr6.eq) goto loc_82186920;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x82186910;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82186920
	if (ctx.cr6.eq) goto loc_82186920;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_82186920:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218693c
	if (!ctx.cr6.eq) goto loc_8218693C;
	// li r11,512
	ctx.r11.s64 = 512;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
loc_8218693C:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,26616
	ctx.r10.s64 = ctx.r11.s64 + 26616;
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82186960"))) PPC_WEAK_FUNC(sub_82186960);
PPC_FUNC_IMPL(__imp__sub_82186960) {
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
	// lwz r11,8280(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8280);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821869dc
	if (ctx.cr6.eq) goto loc_821869DC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x821869e8
	if (!ctx.cr6.eq) goto loc_821869E8;
	// lwz r11,8276(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218699c
	if (ctx.cr6.eq) goto loc_8218699C;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218699C:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x821869AC;
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
loc_821869DC:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,26824
	ctx.r10.s64 = ctx.r11.s64 + 26824;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821869E8:
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

__attribute__((alias("__imp__sub_821869FC"))) PPC_WEAK_FUNC(sub_821869FC);
PPC_FUNC_IMPL(__imp__sub_821869FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186A00"))) PPC_WEAK_FUNC(sub_82186A00);
PPC_FUNC_IMPL(__imp__sub_82186A00) {
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
	// lwz r11,8280(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8280);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82186a94
	if (ctx.cr6.eq) goto loc_82186A94;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82186aec
	if (!ctx.cr6.eq) goto loc_82186AEC;
	// lwz r11,8276(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82186a54
	if (ctx.cr6.eq) goto loc_82186A54;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lbz r9,8284(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8284);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82186a54
	if (!ctx.cr6.eq) goto loc_82186A54;
	// lwz r11,8276(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8276);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82186A54:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82186A64;
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
loc_82186A94:
	// lbz r11,8284(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82186ae0
	if (!ctx.cr6.eq) goto loc_82186AE0;
	// lwz r11,8276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82186ab4
	if (ctx.cr6.eq) goto loc_82186AB4;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82186AB4:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82186AC4;
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
loc_82186AE0:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,26824
	ctx.r10.s64 = ctx.r11.s64 + 26824;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82186AEC:
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

__attribute__((alias("__imp__sub_82186B00"))) PPC_WEAK_FUNC(sub_82186B00);
PPC_FUNC_IMPL(__imp__sub_82186B00) {
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
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x82186B20;
	sub_8207DA20(ctx, base);
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// ori r10,r11,4097
	ctx.r10.u64 = ctx.r11.u64 | 4097;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// bl 0x82185d18
	ctx.lr = 0x82186B30;
	sub_82185D18(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// li r5,7272
	ctx.r5.s64 = 7272;
	// bl 0x8207dac0
	ctx.lr = 0x82186B40;
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

__attribute__((alias("__imp__sub_82186B54"))) PPC_WEAK_FUNC(sub_82186B54);
PPC_FUNC_IMPL(__imp__sub_82186B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186B58"))) PPC_WEAK_FUNC(sub_82186B58);
PPC_FUNC_IMPL(__imp__sub_82186B58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82186B60;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r29,3
	ctx.r29.s64 = 3;
	// li r26,2
	ctx.r26.s64 = 2;
	// li r28,1
	ctx.r28.s64 = 1;
	// std r30,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r30.u64);
	// li r5,5760
	ctx.r5.s64 = 5760;
	// std r30,8(r31)
	PPC_STORE_U64(ctx.r31.u32 + 8, ctx.r30.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// stb r26,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r26.u8);
	// stb r29,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r29.u8);
	// stb r29,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r29.u8);
	// stb r28,7(r31)
	PPC_STORE_U8(ctx.r31.u32 + 7, ctx.r28.u8);
	// stb r30,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r30.u8);
	// stb r30,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r30.u8);
	// stb r30,3(r31)
	PPC_STORE_U8(ctx.r31.u32 + 3, ctx.r30.u8);
	// stb r30,8(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8, ctx.r30.u8);
	// bl 0x8207da20
	ctx.lr = 0x82186BB4;
	sub_8207DA20(ctx, base);
	// std r30,5776(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5776, ctx.r30.u64);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// std r30,5784(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5784, ctx.r30.u64);
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// std r30,5792(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5792, ctx.r30.u64);
	// mtctr r26
	ctx.ctr.u64 = ctx.r26.u64;
	// std r30,5800(r31)
	PPC_STORE_U64(ctx.r31.u32 + 5800, ctx.r30.u64);
	// li r9,8
	ctx.r9.s64 = 8;
loc_82186BD4:
	// lwzu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// stw r29,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r29.u32);
	// bdnz 0x82186bd4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82186BD4;
	// li r5,30
	ctx.r5.s64 = 30;
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82185e80
	ctx.lr = 0x82186BFC;
	sub_82185E80(ctx, base);
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// li r11,100
	ctx.r11.s64 = 100;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// stw r28,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r28.u32);
	// stw r28,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82186C24"))) PPC_WEAK_FUNC(sub_82186C24);
PPC_FUNC_IMPL(__imp__sub_82186C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186C28"))) PPC_WEAK_FUNC(sub_82186C28);
PPC_FUNC_IMPL(__imp__sub_82186C28) {
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
	// lwz r31,-31348(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31348);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82186c64
	if (ctx.cr6.eq) goto loc_82186C64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82185e00
	ctx.lr = 0x82186C54;
	sub_82185E00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a630
	ctx.lr = 0x82186C5C;
	sub_8207A630(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31348(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31348, ctx.r11.u32);
loc_82186C64:
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

__attribute__((alias("__imp__sub_82186C7C"))) PPC_WEAK_FUNC(sub_82186C7C);
PPC_FUNC_IMPL(__imp__sub_82186C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186C80"))) PPC_WEAK_FUNC(sub_82186C80);
PPC_FUNC_IMPL(__imp__sub_82186C80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82186C88;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r10,14572(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14572, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82186CA8;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82186d08
	if (ctx.cr6.eq) goto loc_82186D08;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24631
	ctx.r4.s64 = ctx.r11.s64 + -24631;
	// bl 0x82060190
	ctx.lr = 0x82186CC4;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,22660
	ctx.r4.s64 = ctx.r10.s64 + 22660;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82186CD8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82186CE8;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r31,8276
	ctx.r6.s64 = ctx.r31.s64 + 8276;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82186D04;
	sub_821BD670(ctx, base);
	// b 0x82186d0c
	goto loc_82186D0C;
loc_82186D08:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82186D0C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,26320
	ctx.r6.s64 = ctx.r8.s64 + 26320;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r6,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82186D3C"))) PPC_WEAK_FUNC(sub_82186D3C);
PPC_FUNC_IMPL(__imp__sub_82186D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186D40"))) PPC_WEAK_FUNC(sub_82186D40);
PPC_FUNC_IMPL(__imp__sub_82186D40) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8276(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8276);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82186d64
	if (ctx.cr6.eq) goto loc_82186D64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,27776
	ctx.r10.s64 = ctx.r11.s64 + 27776;
	// stw r10,8284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8284, ctx.r10.u32);
	// blr 
	return;
loc_82186D64:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,23096
	ctx.r10.s64 = ctx.r11.s64 + 23096;
	// stw r10,8284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8284, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82186D74"))) PPC_WEAK_FUNC(sub_82186D74);
PPC_FUNC_IMPL(__imp__sub_82186D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186D78"))) PPC_WEAK_FUNC(sub_82186D78);
PPC_FUNC_IMPL(__imp__sub_82186D78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82186D80;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82186D90;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82186df0
	if (ctx.cr6.eq) goto loc_82186DF0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24637
	ctx.r4.s64 = ctx.r11.s64 + -24637;
	// bl 0x82060190
	ctx.lr = 0x82186DAC;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,22636
	ctx.r4.s64 = ctx.r10.s64 + 22636;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82186DC0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82186DD0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r31,8276
	ctx.r6.s64 = ctx.r31.s64 + 8276;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82186DEC;
	sub_821BD670(ctx, base);
	// b 0x82186df4
	goto loc_82186DF4;
loc_82186DF0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82186DF4:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,27968
	ctx.r6.s64 = ctx.r8.s64 + 27968;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r6,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82186E24"))) PPC_WEAK_FUNC(sub_82186E24);
PPC_FUNC_IMPL(__imp__sub_82186E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186E28"))) PPC_WEAK_FUNC(sub_82186E28);
PPC_FUNC_IMPL(__imp__sub_82186E28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82186E30;
	__savegprlr_28(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8268(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8268);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82186e4c
	if (ctx.cr6.eq) goto loc_82186E4C;
	// lwz r10,8264(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8264);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82186E4C:
	// lwz r11,8264(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8264);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x82186f2c
	if (ctx.cr6.eq) goto loc_82186F2C;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// beq cr6,0x82186eb0
	if (ctx.cr6.eq) goto loc_82186EB0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r30,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r30.u32);
	// stw r30,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r30.u32);
	// stw r30,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r30.u32);
	// stw r30,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r30.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x82186e9c
	if (ctx.cr6.eq) goto loc_82186E9C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
loc_82186E9C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-29864
	ctx.r10.s64 = ctx.r11.s64 + -29864;
	// stw r10,8284(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8284, ctx.r10.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82186EB0:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,264
	ctx.r3.s64 = 264;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r10,14572(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14572, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82186EC8;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82186fa0
	if (ctx.cr6.eq) goto loc_82186FA0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,-24638
	ctx.r4.s64 = ctx.r11.s64 + -24638;
	// bl 0x82060190
	ctx.lr = 0x82186EE8;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,22608
	ctx.r4.s64 = ctx.r10.s64 + 22608;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060190
	ctx.lr = 0x82186EFC;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82186F0C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r29,8276
	ctx.r6.s64 = ctx.r29.s64 + 8276;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82186F28;
	sub_821BD670(ctx, base);
	// b 0x82186fa4
	goto loc_82186FA4;
loc_82186F2C:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82186F34;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82186fa0
	if (ctx.cr6.eq) goto loc_82186FA0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-24638
	ctx.r11.s64 = ctx.r11.s64 + -24638;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x82060190
	ctx.lr = 0x82186F58;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r11,r10,22608
	ctx.r11.s64 = ctx.r10.s64 + 22608;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,-28
	ctx.r4.s64 = ctx.r11.s64 + -28;
	// bl 0x82060190
	ctx.lr = 0x82186F70;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82186F80;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r29,8276
	ctx.r6.s64 = ctx.r29.s64 + 8276;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82186F9C;
	sub_821BD670(ctx, base);
	// b 0x82186fa4
	goto loc_82186FA4;
loc_82186FA0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82186FA4:
	// lwz r10,36(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r31,r29,16
	ctx.r31.s64 = ctx.r29.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82186FCC;
	sub_820735C8(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82186FE8"))) PPC_WEAK_FUNC(sub_82186FE8);
PPC_FUNC_IMPL(__imp__sub_82186FE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82186FF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r10,14572(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 14572);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8218707c
	if (ctx.cr6.eq) goto loc_8218707C;
	// bl 0x82079fd8
	ctx.lr = 0x82187014;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821870e0
	if (ctx.cr6.eq) goto loc_821870E0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-24753
	ctx.r11.s64 = ctx.r11.s64 + -24753;
	// addi r4,r11,-192
	ctx.r4.s64 = ctx.r11.s64 + -192;
	// bl 0x82060190
	ctx.lr = 0x82187034;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r10,22108
	ctx.r11.s64 = ctx.r10.s64 + 22108;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// bl 0x82060190
	ctx.lr = 0x8218704C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218705C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r31,8280
	ctx.r6.s64 = ctx.r31.s64 + 8280;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82187078;
	sub_821BD670(ctx, base);
	// b 0x821870e4
	goto loc_821870E4;
loc_8218707C:
	// bl 0x82079fd8
	ctx.lr = 0x82187080;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821870e0
	if (ctx.cr6.eq) goto loc_821870E0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,-24753
	ctx.r4.s64 = ctx.r11.s64 + -24753;
	// bl 0x82060190
	ctx.lr = 0x8218709C;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,22108
	ctx.r4.s64 = ctx.r10.s64 + 22108;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821870B0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821870C0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r31,8280
	ctx.r6.s64 = ctx.r31.s64 + 8280;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x821870DC;
	sub_821BD670(ctx, base);
	// b 0x821870e4
	goto loc_821870E4;
loc_821870E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821870E4:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r10,r11,26976
	ctx.r10.s64 = ctx.r11.s64 + 26976;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187114"))) PPC_WEAK_FUNC(sub_82187114);
PPC_FUNC_IMPL(__imp__sub_82187114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187118"))) PPC_WEAK_FUNC(sub_82187118);
PPC_FUNC_IMPL(__imp__sub_82187118) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82187120;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82187130;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187190
	if (ctx.cr6.eq) goto loc_82187190;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24961
	ctx.r4.s64 = ctx.r11.s64 + -24961;
	// bl 0x82060190
	ctx.lr = 0x8218714C;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,22052
	ctx.r4.s64 = ctx.r10.s64 + 22052;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82187160;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82187170;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r31,8280
	ctx.r6.s64 = ctx.r31.s64 + 8280;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x8218718C;
	sub_821BD670(ctx, base);
	// b 0x82187194
	goto loc_82187194;
loc_82187190:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82187194:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,27136
	ctx.r6.s64 = ctx.r8.s64 + 27136;
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
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821871C4"))) PPC_WEAK_FUNC(sub_821871C4);
PPC_FUNC_IMPL(__imp__sub_821871C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821871C8"))) PPC_WEAK_FUNC(sub_821871C8);
PPC_FUNC_IMPL(__imp__sub_821871C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821871D0;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,80
	ctx.r30.s64 = ctx.r3.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x821871EC;
	sub_8207DA20(ctx, base);
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// ori r10,r11,4097
	ctx.r10.u64 = ctx.r11.u64 | 4097;
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bl 0x82185d18
	ctx.lr = 0x821871FC;
	sub_82185D18(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// li r5,7272
	ctx.r5.s64 = 7272;
	// bl 0x8207dac0
	ctx.lr = 0x8218720C;
	sub_8207DAC0(ctx, base);
	// li r4,7280
	ctx.r4.s64 = 7280;
	// li r3,8192
	ctx.r3.s64 = 8192;
	// bl 0x8210e878
	ctx.lr = 0x82187218;
	sub_8210E878(ctx, base);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x82187220;
	sub_82079FD8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r28,r11,22396
	ctx.r28.s64 = ctx.r11.s64 + 22396;
	// beq cr6,0x8218728c
	if (ctx.cr6.eq) goto loc_8218728C;
	// addi r4,r28,-64
	ctx.r4.s64 = ctx.r28.s64 + -64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x82187244;
	sub_82060190(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r28,-48
	ctx.r4.s64 = ctx.r28.s64 + -48;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206bb38
	ctx.lr = 0x82187254;
	sub_8206BB38(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r4,r28,-16
	ctx.r4.s64 = ctx.r28.s64 + -16;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060190
	ctx.lr = 0x82187264;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r8,8192
	ctx.r8.s64 = 8192;
	// addi r9,r31,8272
	ctx.r9.s64 = ctx.r31.s64 + 8272;
	// bl 0x82194c78
	ctx.lr = 0x82187284;
	sub_82194C78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82187290
	goto loc_82187290;
loc_8218728C:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82187290:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// li r3,264
	ctx.r3.s64 = 264;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r27,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821872B0;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218730c
	if (ctx.cr6.eq) goto loc_8218730C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,-24709
	ctx.r4.s64 = ctx.r11.s64 + -24709;
	// bl 0x82060190
	ctx.lr = 0x821872CC;
	sub_82060190(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821872DC;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821872EC;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,60
	ctx.r7.s64 = 60;
	// li r8,2
	ctx.r8.s64 = 2;
	// bl 0x821bd670
	ctx.lr = 0x82187308;
	sub_821BD670(ctx, base);
	// b 0x82187310
	goto loc_82187310;
loc_8218730C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_82187310:
	// lis r10,-32232
	ctx.r10.s64 = -2112356352;
	// stw r3,8296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8296, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r8,r10,26424
	ctx.r8.s64 = ctx.r10.s64 + 26424;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187340"))) PPC_WEAK_FUNC(sub_82187340);
PPC_FUNC_IMPL(__imp__sub_82187340) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82187348;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8192
	ctx.r3.s64 = 8192;
	// bl 0x82088378
	ctx.lr = 0x8218735C;
	sub_82088378(ctx, base);
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// lwz r11,-31352(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r3,52(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82187388
	if (!ctx.cr6.eq) goto loc_82187388;
	// b 0x8218739c
	goto loc_8218739C;
loc_82187388:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x82187390;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218739c
	if (!ctx.cr6.eq) goto loc_8218739C;
	// ld r31,96(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
loc_8218739C:
	// lwz r11,8288(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8288);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821873b8
	if (ctx.cr6.eq) goto loc_821873B8;
	// li r4,1
	ctx.r4.s64 = 1;
	// clrldi r3,r11,32
	ctx.r3.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// bl 0x82088378
	ctx.lr = 0x821873B4;
	sub_82088378(ctx, base);
	// add r31,r3,r31
	ctx.r31.u64 = ctx.r3.u64 + ctx.r31.u64;
loc_821873B8:
	// cmpld cr6,r28,r31
	ctx.cr6.compare<uint64_t>(ctx.r28.u64, ctx.r31.u64, ctx.xer);
	// ble cr6,0x82187408
	if (!ctx.cr6.gt) goto loc_82187408;
	// lwz r11,-31352(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r30,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r30.u32);
	// stw r30,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r30.u32);
	// stw r30,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r30.u32);
	// stw r30,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r30.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x821873f4
	if (ctx.cr6.eq) goto loc_821873F4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
loc_821873F4:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,28952
	ctx.r10.s64 = ctx.r11.s64 + 28952;
	// stw r10,72(r27)
	PPC_STORE_U32(ctx.r27.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82187408:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,29128
	ctx.r10.s64 = ctx.r11.s64 + 29128;
	// stw r10,72(r27)
	PPC_STORE_U32(ctx.r27.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218741C"))) PPC_WEAK_FUNC(sub_8218741C);
PPC_FUNC_IMPL(__imp__sub_8218741C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187420"))) PPC_WEAK_FUNC(sub_82187420);
PPC_FUNC_IMPL(__imp__sub_82187420) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82187428;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r29,r3,8288
	ctx.r29.s64 = ctx.r3.s64 + 8288;
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r27,8288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8288, ctx.r27.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82187444;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821874a4
	if (ctx.cr6.eq) goto loc_821874A4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,22316
	ctx.r30.s64 = ctx.r11.s64 + 22316;
	// addi r4,r30,-48
	ctx.r4.s64 = ctx.r30.s64 + -48;
	// bl 0x82060190
	ctx.lr = 0x82187464;
	sub_82060190(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r30,-32
	ctx.r4.s64 = ctx.r30.s64 + -32;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206bb38
	ctx.lr = 0x82187474;
	sub_8206BB38(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060190
	ctx.lr = 0x82187484;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// addi r8,r31,8272
	ctx.r8.s64 = ctx.r31.s64 + 8272;
	// bl 0x82194978
	ctx.lr = 0x821874A0;
	sub_82194978(ctx, base);
	// b 0x821874a8
	goto loc_821874A8;
loc_821874A4:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821874A8:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,29504
	ctx.r7.s64 = ctx.r8.s64 + 29504;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821874D4"))) PPC_WEAK_FUNC(sub_821874D4);
PPC_FUNC_IMPL(__imp__sub_821874D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821874D8"))) PPC_WEAK_FUNC(sub_821874D8);
PPC_FUNC_IMPL(__imp__sub_821874D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,29728
	ctx.r10.s64 = ctx.r11.s64 + 29728;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821874E8"))) PPC_WEAK_FUNC(sub_821874E8);
PPC_FUNC_IMPL(__imp__sub_821874E8) {
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
	// lwz r11,8280(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8280);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8218755c
	if (ctx.cr6.eq) goto loc_8218755C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82187568
	if (!ctx.cr6.eq) goto loc_82187568;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r4,r9,6640
	ctx.r4.s64 = ctx.r9.s64 + 6640;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r10,14572(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14572, ctx.r10.u32);
	// bl 0x820735c8
	ctx.lr = 0x8218752C;
	sub_820735C8(ctx, base);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
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
loc_8218755C:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,29912
	ctx.r10.s64 = ctx.r11.s64 + 29912;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82187568:
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

__attribute__((alias("__imp__sub_8218757C"))) PPC_WEAK_FUNC(sub_8218757C);
PPC_FUNC_IMPL(__imp__sub_8218757C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187580"))) PPC_WEAK_FUNC(sub_82187580);
PPC_FUNC_IMPL(__imp__sub_82187580) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82187588;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r3,8280
	ctx.r30.s64 = ctx.r3.s64 + 8280;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,8280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8280, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821875A4;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187604
	if (ctx.cr6.eq) goto loc_82187604;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24710
	ctx.r4.s64 = ctx.r11.s64 + -24710;
	// bl 0x82060190
	ctx.lr = 0x821875C0;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,22244
	ctx.r4.s64 = ctx.r10.s64 + 22244;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821875D4;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821875E4;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82187600;
	sub_821BD670(ctx, base);
	// b 0x82187608
	goto loc_82187608;
loc_82187604:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_82187608:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,29928
	ctx.r7.s64 = ctx.r8.s64 + 29928;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187634"))) PPC_WEAK_FUNC(sub_82187634);
PPC_FUNC_IMPL(__imp__sub_82187634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187638"))) PPC_WEAK_FUNC(sub_82187638);
PPC_FUNC_IMPL(__imp__sub_82187638) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82187640;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r3,8280
	ctx.r30.s64 = ctx.r3.s64 + 8280;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,8280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8280, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8218765C;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821876bc
	if (ctx.cr6.eq) goto loc_821876BC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24713
	ctx.r4.s64 = ctx.r11.s64 + -24713;
	// bl 0x82060190
	ctx.lr = 0x82187678;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,22208
	ctx.r4.s64 = ctx.r10.s64 + 22208;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218768C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218769C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x821876B8;
	sub_821BD670(ctx, base);
	// b 0x821876c0
	goto loc_821876C0;
loc_821876BC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_821876C0:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,29928
	ctx.r7.s64 = ctx.r8.s64 + 29928;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821876EC"))) PPC_WEAK_FUNC(sub_821876EC);
PPC_FUNC_IMPL(__imp__sub_821876EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821876F0"))) PPC_WEAK_FUNC(sub_821876F0);
PPC_FUNC_IMPL(__imp__sub_821876F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8272(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8272);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8218771c
	if (ctx.cr6.eq) goto loc_8218771C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8218774c
	if (ctx.cr6.eq) goto loc_8218774C;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// beq cr6,0x8218774c
	if (ctx.cr6.eq) goto loc_8218774C;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,30080
	ctx.r10.s64 = ctx.r11.s64 + 30080;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_8218771C:
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// ori r9,r11,4097
	ctx.r9.u64 = ctx.r11.u64 | 4097;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8218774c
	if (!ctx.cr6.eq) goto loc_8218774C;
	// lwz r11,8292(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8292);
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x8218774c
	if (!ctx.cr6.eq) goto loc_8218774C;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,29912
	ctx.r10.s64 = ctx.r11.s64 + 29912;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_8218774C:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,30264
	ctx.r10.s64 = ctx.r11.s64 + 30264;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218775C"))) PPC_WEAK_FUNC(sub_8218775C);
PPC_FUNC_IMPL(__imp__sub_8218775C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187760"))) PPC_WEAK_FUNC(sub_82187760);
PPC_FUNC_IMPL(__imp__sub_82187760) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82187768;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x82187778;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821877e8
	if (ctx.cr6.eq) goto loc_821877E8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,22192
	ctx.r30.s64 = ctx.r11.s64 + 22192;
	// addi r28,r31,8292
	ctx.r28.s64 = ctx.r31.s64 + 8292;
	// addi r4,r30,-48
	ctx.r4.s64 = ctx.r30.s64 + -48;
	// addi r27,r31,8272
	ctx.r27.s64 = ctx.r31.s64 + 8272;
	// bl 0x82060190
	ctx.lr = 0x821877A0;
	sub_82060190(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r30,-32
	ctx.r4.s64 = ctx.r30.s64 + -32;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206bb38
	ctx.lr = 0x821877B0;
	sub_8206BB38(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060190
	ctx.lr = 0x821877C0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r7,r31,80
	ctx.r7.s64 = ctx.r31.s64 + 80;
	// li r8,8192
	ctx.r8.s64 = 8192;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// bl 0x82194af0
	ctx.lr = 0x821877E4;
	sub_82194AF0(ctx, base);
	// b 0x821877ec
	goto loc_821877EC;
loc_821877E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821877EC:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,30448
	ctx.r6.s64 = ctx.r8.s64 + 30448;
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
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218781C"))) PPC_WEAK_FUNC(sub_8218781C);
PPC_FUNC_IMPL(__imp__sub_8218781C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187820"))) PPC_WEAK_FUNC(sub_82187820);
PPC_FUNC_IMPL(__imp__sub_82187820) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r31,84(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82187880
	if (!ctx.cr6.eq) goto loc_82187880;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187880
	if (ctx.cr6.eq) goto loc_82187880;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x82187868;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82187878
	if (!ctx.cr6.eq) goto loc_82187878;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82187884
	goto loc_82187884;
loc_82187878:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_82187880:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82187884:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218789c
	if (!ctx.cr6.eq) goto loc_8218789C;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,28648
	ctx.r10.s64 = ctx.r11.s64 + 28648;
	// b 0x821878bc
	goto loc_821878BC;
loc_8218789C:
	// lbz r11,8284(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 8284);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821878b4
	if (ctx.cr6.eq) goto loc_821878B4;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,30560
	ctx.r10.s64 = ctx.r11.s64 + 30560;
	// b 0x821878bc
	goto loc_821878BC;
loc_821878B4:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,29912
	ctx.r10.s64 = ctx.r11.s64 + 29912;
loc_821878BC:
	// stw r10,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821878D8"))) PPC_WEAK_FUNC(sub_821878D8);
PPC_FUNC_IMPL(__imp__sub_821878D8) {
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
	// lwz r11,8280(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8280);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82187954
	if (ctx.cr6.eq) goto loc_82187954;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82187960
	if (!ctx.cr6.eq) goto loc_82187960;
	// lwz r11,8276(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82187914
	if (ctx.cr6.eq) goto loc_82187914;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82187914:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82187924;
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
loc_82187954:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,30752
	ctx.r10.s64 = ctx.r11.s64 + 30752;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_82187960:
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

__attribute__((alias("__imp__sub_82187974"))) PPC_WEAK_FUNC(sub_82187974);
PPC_FUNC_IMPL(__imp__sub_82187974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187978"))) PPC_WEAK_FUNC(sub_82187978);
PPC_FUNC_IMPL(__imp__sub_82187978) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82187980;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82187990;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821879f0
	if (ctx.cr6.eq) goto loc_821879F0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24977
	ctx.r4.s64 = ctx.r11.s64 + -24977;
	// bl 0x82060190
	ctx.lr = 0x821879AC;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,22028
	ctx.r4.s64 = ctx.r10.s64 + 22028;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821879C0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821879D0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r31,8280
	ctx.r6.s64 = ctx.r31.s64 + 8280;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x821879EC;
	sub_821BD670(ctx, base);
	// b 0x821879f4
	goto loc_821879F4;
loc_821879F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821879F4:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,30936
	ctx.r6.s64 = ctx.r8.s64 + 30936;
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
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187A24"))) PPC_WEAK_FUNC(sub_82187A24);
PPC_FUNC_IMPL(__imp__sub_82187A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187A28"))) PPC_WEAK_FUNC(sub_82187A28);
PPC_FUNC_IMPL(__imp__sub_82187A28) {
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
	// lbz r11,8284(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8284);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82187aac
	if (ctx.cr6.eq) goto loc_82187AAC;
	// bl 0x82185ab8
	ctx.lr = 0x82187A4C;
	sub_82185AB8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82187aac
	if (!ctx.cr6.eq) goto loc_82187AAC;
	// lwz r11,8276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82187a6c
	if (ctx.cr6.eq) goto loc_82187A6C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82187A6C:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82187A7C;
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
loc_82187AAC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82187ad0
	if (ctx.cr6.eq) goto loc_82187AD0;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,30752
	ctx.r10.s64 = ctx.r11.s64 + 30752;
	// b 0x82187ad8
	goto loc_82187AD8;
loc_82187AD0:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,31096
	ctx.r10.s64 = ctx.r11.s64 + 31096;
loc_82187AD8:
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

__attribute__((alias("__imp__sub_82187AF0"))) PPC_WEAK_FUNC(sub_82187AF0);
PPC_FUNC_IMPL(__imp__sub_82187AF0) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r7,-1396
	ctx.r7.s64 = ctx.r7.s64 + -1396;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r31,-32251
	ctx.r31.s64 = -2113601536;
	// addi r6,r6,840
	ctx.r6.s64 = ctx.r6.s64 + 840;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// lwz r8,-31352(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31352);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r9,r31,4960
	ctx.r9.s64 = ctx.r31.s64 + 4960;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r6,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r6.u32);
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
	// stb r7,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r7.u8);
	// stb r7,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r7.u8);
	// stw r4,8276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8276, ctx.r4.u32);
	// stb r5,8284(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8284, ctx.r5.u8);
	// lwz r8,76(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// cmplwi cr6,r6,4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// blt cr6,0x82187bbc
	if (ctx.cr6.lt) goto loc_82187BBC;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82187bac
	if (ctx.cr6.eq) goto loc_82187BAC;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_82187BAC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_82187BBC:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,31272
	ctx.r10.s64 = ctx.r11.s64 + 31272;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82187BD0"))) PPC_WEAK_FUNC(sub_82187BD0);
PPC_FUNC_IMPL(__imp__sub_82187BD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82187BD8;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8276(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8276);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r3,8276
	ctx.r28.s64 = ctx.r3.s64 + 8276;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82187cc0
	if (ctx.cr6.eq) goto loc_82187CC0;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82187d0c
	if (!ctx.cr6.eq) goto loc_82187D0C;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,264
	ctx.r3.s64 = 264;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r10,14572(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14572, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82187C10;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187c78
	if (ctx.cr6.eq) goto loc_82187C78;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24645
	ctx.r4.s64 = ctx.r11.s64 + -24645;
	// bl 0x82060190
	ctx.lr = 0x82187C30;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,22552
	ctx.r4.s64 = ctx.r10.s64 + 22552;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82187C44;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82187C54;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82187C70;
	sub_821BD670(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82187c7c
	goto loc_82187C7C;
loc_82187C78:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82187C7C:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r7,6640
	ctx.r4.s64 = ctx.r7.s64 + 6640;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x820735c8
	ctx.lr = 0x82187CA4;
	sub_820735C8(ctx, base);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82187CC0:
	// li r3,8304
	ctx.r3.s64 = 8304;
	// bl 0x82079fd8
	ctx.lr = 0x82187CC8;
	sub_82079FD8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187ce4
	if (ctx.cr6.eq) goto loc_82187CE4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,8264
	ctx.r4.s64 = ctx.r31.s64 + 8264;
	// bl 0x82187af0
	ctx.lr = 0x82187CE0;
	sub_82187AF0(ctx, base);
	// b 0x82187ce8
	goto loc_82187CE8;
loc_82187CE4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82187CE8:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,28200
	ctx.r7.s64 = ctx.r8.s64 + 28200;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r7,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r7.u32);
loc_82187D0C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187D14"))) PPC_WEAK_FUNC(sub_82187D14);
PPC_FUNC_IMPL(__imp__sub_82187D14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187D18"))) PPC_WEAK_FUNC(sub_82187D18);
PPC_FUNC_IMPL(__imp__sub_82187D18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82187D20;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r3,8276
	ctx.r30.s64 = ctx.r3.s64 + 8276;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,8276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8276, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82187D3C;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187d9c
	if (ctx.cr6.eq) goto loc_82187D9C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24661
	ctx.r4.s64 = ctx.r11.s64 + -24661;
	// bl 0x82060190
	ctx.lr = 0x82187D58;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,22516
	ctx.r4.s64 = ctx.r10.s64 + 22516;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82187D6C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82187D7C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82187D98;
	sub_821BD670(ctx, base);
	// b 0x82187da0
	goto loc_82187DA0;
loc_82187D9C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_82187DA0:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,31696
	ctx.r7.s64 = ctx.r8.s64 + 31696;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r7,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187DCC"))) PPC_WEAK_FUNC(sub_82187DCC);
PPC_FUNC_IMPL(__imp__sub_82187DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187DD0"))) PPC_WEAK_FUNC(sub_82187DD0);
PPC_FUNC_IMPL(__imp__sub_82187DD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82187DD8;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r3,8276
	ctx.r30.s64 = ctx.r3.s64 + 8276;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,8276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8276, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82187DF4;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82187e54
	if (ctx.cr6.eq) goto loc_82187E54;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24677
	ctx.r4.s64 = ctx.r11.s64 + -24677;
	// bl 0x82060190
	ctx.lr = 0x82187E10;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,22492
	ctx.r4.s64 = ctx.r10.s64 + 22492;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82187E24;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82187E34;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82187E50;
	sub_821BD670(ctx, base);
	// b 0x82187e58
	goto loc_82187E58;
loc_82187E54:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_82187E58:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32232
	ctx.r8.s64 = -2112356352;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,31696
	ctx.r7.s64 = ctx.r8.s64 + 31696;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// stw r7,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82187E84"))) PPC_WEAK_FUNC(sub_82187E84);
PPC_FUNC_IMPL(__imp__sub_82187E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82187E88"))) PPC_WEAK_FUNC(sub_82187E88);
PPC_FUNC_IMPL(__imp__sub_82187E88) {
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
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82187ea8
	if (!ctx.cr6.eq) goto loc_82187EA8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82187EA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82189158
	ctx.lr = 0x82187EB4;
	sub_82189158(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82189158
	ctx.lr = 0x82187EC0;
	sub_82189158(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82189158
	ctx.lr = 0x82187ECC;
	sub_82189158(ctx, base);
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

__attribute__((alias("__imp__sub_82187EE0"))) PPC_WEAK_FUNC(sub_82187EE0);
PPC_FUNC_IMPL(__imp__sub_82187EE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82187EE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82187efc
	if (!ctx.cr6.eq) goto loc_82187EFC;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82187EFC:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,7
	ctx.r8.s64 = 7;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82187f18
	if (!ctx.cr6.lt) goto loc_82187F18;
	// stw r9,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// b 0x82187f24
	goto loc_82187F24;
loc_82187F18:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x82187f24
	if (!ctx.cr6.gt) goto loc_82187F24;
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
loc_82187F24:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// rlwinm r11,r11,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 7) & 0xFFFFFF80;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// bge cr6,0x82187f48
	if (!ctx.cr6.lt) goto loc_82187F48;
	// stw r9,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// b 0x82187f54
	goto loc_82187F54;
loc_82187F48:
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// ble cr6,0x82187f54
	if (!ctx.cr6.gt) goto loc_82187F54;
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
loc_82187F54:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// addi r5,r9,-2064
	ctx.r5.s64 = ctx.r9.s64 + -2064;
	// mulli r10,r10,44
	ctx.r10.s64 = ctx.r10.s64 * 44;
	// lfs f0,360(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f7,176(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 176);
	ctx.f7.f64 = double(temp.f32);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,1476(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1476, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,1480(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1480, ctx.r8.u32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,1484(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1484, temp.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// stw r4,1472(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1472, ctx.r4.u32);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// stfs f5,1516(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1516, temp.u32);
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x82187ff0
	if (!ctx.cr6.eq) goto loc_82187FF0;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r7,r9,-21836
	ctx.r7.s64 = ctx.r9.s64 + -21836;
	// lfs f13,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1512(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1512, temp.u32);
	// stfs f13,1508(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1508, temp.u32);
	// b 0x8218806c
	goto loc_8218806C;
loc_82187FF0:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lis r8,10922
	ctx.r8.s64 = 715784192;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// ori r7,r8,43691
	ctx.r7.u64 = ctx.r8.u64 | 43691;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mulhw r8,r9,r7
	ctx.r8.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32)) >> 32;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// addi r4,r4,4912
	ctx.r4.s64 = ctx.r4.s64 + 4912;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addi r7,r6,-21836
	ctx.r7.s64 = ctx.r6.s64 + -21836;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r30,6
	ctx.r30.s64 = 6;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// rlwinm r29,r8,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r6,4936
	ctx.r8.s64 = ctx.r6.s64 + 4936;
	// subf r9,r29,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r29.s64;
	// addi r8,r8,20
	ctx.r8.s64 = ctx.r8.s64 + 20;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r4
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f12,1512(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1512, temp.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// divw r4,r6,r30
	ctx.r4.s32 = ppc_divw(ctx.r6.s32, ctx.r30.s32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// lfs f11,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,1508(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1508, temp.u32);
loc_8218806C:
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lfs f11,364(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 364);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,368(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 368);
	ctx.f10.f64 = double(temp.f32);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// lfs f9,372(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 372);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,376(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 376);
	ctx.f8.f64 = double(temp.f32);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfs f0,44(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// frsp f6,f12
	ctx.f6.f64 = double(float(ctx.f12.f64));
	// lfs f12,312(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 312);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// stfs f5,1496(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1496, temp.u32);
	// lwz r7,28(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f2,f10
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// stfs f1,1488(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1488, temp.u32);
	// lwz r4,32(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// fmadds f5,f6,f9,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 + ctx.f13.f64));
	// stfs f5,1504(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1504, temp.u32);
	// lwz r8,36(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmadds f1,f2,f8,f13
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + ctx.f13.f64));
	// stfs f1,1500(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1500, temp.u32);
	// lwz r6,40(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmadds f8,f9,f7,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f7.f64 + ctx.f13.f64));
	// stfs f8,1492(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1492, temp.u32);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// stw r10,1544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1544, ctx.r10.u32);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// stw r9,1540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1540, ctx.r9.u32);
	// lwz r8,40(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f4,1528(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1528, temp.u32);
	// lwz r6,44(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f3,80(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f11,1532(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1532, temp.u32);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f7,1536(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1536, temp.u32);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bgt cr6,0x821881ac
	if (ctx.cr6.gt) goto loc_821881AC;
	// stw r10,1552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1552, ctx.r10.u32);
	// b 0x821881c0
	goto loc_821881C0;
loc_821881AC:
	// addi r10,r10,-5
	ctx.r10.s64 = ctx.r10.s64 + -5;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1552, ctx.r9.u32);
loc_821881C0:
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// stw r10,1576(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1576, ctx.r10.u32);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// stw r9,1572(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1572, ctx.r9.u32);
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,1560(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1560, temp.u32);
	// lwz r6,68(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f4,1564(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1564, temp.u32);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f3,80(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f11,1568(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1568, temp.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bgt cr6,0x82188248
	if (ctx.cr6.gt) goto loc_82188248;
	// stw r10,1584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1584, ctx.r10.u32);
	// b 0x8218825c
	goto loc_8218825C;
loc_82188248:
	// addi r10,r10,-5
	ctx.r10.s64 = ctx.r10.s64 + -5;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1584, ctx.r9.u32);
loc_8218825C:
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// stw r10,1608(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1608, ctx.r10.u32);
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// stw r9,1604(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1604, ctx.r9.u32);
	// lwz r8,88(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,1592(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1592, temp.u32);
	// lwz r6,92(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f4,1596(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1596, temp.u32);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f3,80(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f11,1600(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1600, temp.u32);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bgt cr6,0x821882e4
	if (ctx.cr6.gt) goto loc_821882E4;
	// stw r10,1616(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1616, ctx.r10.u32);
	// b 0x821882f8
	goto loc_821882F8;
loc_821882E4:
	// addi r10,r10,-5
	ctx.r10.s64 = ctx.r10.s64 + -5;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1616(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1616, ctx.r9.u32);
loc_821882F8:
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// stw r10,1640(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1640, ctx.r10.u32);
	// lwz r9,104(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// stw r9,1636(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1636, ctx.r9.u32);
	// lwz r8,112(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,1624(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1624, temp.u32);
	// lwz r6,116(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// stfs f4,1628(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1628, temp.u32);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f3,80(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f12,1632(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1632, temp.u32);
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bgt cr6,0x82188380
	if (ctx.cr6.gt) goto loc_82188380;
	// stw r10,1648(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1648, ctx.r10.u32);
	// b 0x82188394
	goto loc_82188394;
loc_82188380:
	// addi r10,r10,-5
	ctx.r10.s64 = ctx.r10.s64 + -5;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1648(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1648, ctx.r9.u32);
loc_82188394:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f12,168(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,164(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 164);
	ctx.f11.f64 = double(temp.f32);
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// stw r6,1448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1448, ctx.r6.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// stw r6,1444(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1444, ctx.r6.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmadds f7,f8,f12,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f7,1436(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1436, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmadds f3,f4,f12,f11
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f3,1452(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1452, temp.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r9,r10,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r10.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82188434
	if (ctx.cr0.eq) goto loc_82188434;
	// lfs f13,192(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
loc_82188434:
	// stfs f13,1460(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1460, temp.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r10,1468(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1468, ctx.r10.u32);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x82188490
	if (!ctx.cr6.eq) goto loc_82188490;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,1416(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1416, temp.u32);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfs f6,1420(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1420, temp.u32);
	// b 0x821884bc
	goto loc_821884BC;
loc_82188490:
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfs f13,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1420(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1420, temp.u32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,1416(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1416, temp.u32);
loc_821884BC:
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwz r10,-31376(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31376);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f10,1408(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1408, temp.u32);
	// lwz r7,28(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfs f6,1412(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1412, temp.u32);
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addic r4,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r4.s64 = ctx.r5.s64 + -1;
	// subfe r11,r4,r5
	temp.u8 = (~ctx.r4.u32 + ctx.r5.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r4.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,1428(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1428, ctx.r11.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r8,1432(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1432, ctx.r8.u32);
	// beq cr6,0x8218853c
	if (ctx.cr6.eq) goto loc_8218853C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82182a68
	ctx.lr = 0x8218853C;
	sub_82182A68(ctx, base);
loc_8218853C:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stw r11,-31400(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31400, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188550"))) PPC_WEAK_FUNC(sub_82188550);
PPC_FUNC_IMPL(__imp__sub_82188550) {
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
	// li r5,1408
	ctx.r5.s64 = 1408;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x82188570;
	sub_8207DA20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82186658
	ctx.lr = 0x8218857C;
	sub_82186658(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,1428(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1428, ctx.r10.u32);
	// stw r10,1432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1432, ctx.r10.u32);
	// addi r10,r31,1516
	ctx.r10.s64 = ctx.r31.s64 + 1516;
	// stw r11,1424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1424, ctx.r11.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_821885A0:
	// stwu r11,32(r10)
	ea = 32 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x821885a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821885A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82187ee0
	ctx.lr = 0x821885B4;
	sub_82187EE0(ctx, base);
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

__attribute__((alias("__imp__sub_821885CC"))) PPC_WEAK_FUNC(sub_821885CC);
PPC_FUNC_IMPL(__imp__sub_821885CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821885D0"))) PPC_WEAK_FUNC(sub_821885D0);
PPC_FUNC_IMPL(__imp__sub_821885D0) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// stb r10,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r10.u8);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x82187ee0
	ctx.lr = 0x821885FC;
	sub_82187EE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,16(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82189158
	ctx.lr = 0x8218860C;
	sub_82189158(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82189158
	ctx.lr = 0x82188618;
	sub_82189158(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82189158
	ctx.lr = 0x82188624;
	sub_82189158(ctx, base);
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

__attribute__((alias("__imp__sub_82188638"))) PPC_WEAK_FUNC(sub_82188638);
PPC_FUNC_IMPL(__imp__sub_82188638) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r31,-31348(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// beq cr6,0x82188668
	if (ctx.cr6.eq) goto loc_82188668;
	// li r5,7272
	ctx.r5.s64 = 7272;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// bl 0x8207dac0
	ctx.lr = 0x82188668;
	sub_8207DAC0(ctx, base);
loc_82188668:
	// li r5,5808
	ctx.r5.s64 = 5808;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r31,24
	ctx.r4.s64 = ctx.r31.s64 + 24;
	// bl 0x8207dac0
	ctx.lr = 0x82188678;
	sub_8207DAC0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,5832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5832);
	// addi r4,r31,5864
	ctx.r4.s64 = ctx.r31.s64 + 5864;
	// li r5,1408
	ctx.r5.s64 = 1408;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r9,5836(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5836);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r8,5840(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5840);
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r7,5844(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5844);
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// lwz r3,5848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5848);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// lwz r11,5852(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5852);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r11.u32);
	// lwz r10,5856(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5856);
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lwz r9,5860(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5860);
	// stw r9,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207dac0
	ctx.lr = 0x821886D0;
	sub_8207DAC0(ctx, base);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,7272(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7272);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// lwz r6,7276(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7276);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// lwz r5,7280(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7280);
	// stw r5,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r5.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r11,7284(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7284);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r10,7288(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 7288);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r8,6(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 6);
	// stb r8,5(r9)
	PPC_STORE_U8(ctx.r9.u32 + 5, ctx.r8.u8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82187ee0
	ctx.lr = 0x82188718;
	sub_82187EE0(ctx, base);
	// lwz r31,16(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82189158
	ctx.lr = 0x82188728;
	sub_82189158(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82189158
	ctx.lr = 0x82188734;
	sub_82189158(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x82189158
	ctx.lr = 0x82188740;
	sub_82189158(ctx, base);
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

__attribute__((alias("__imp__sub_82188754"))) PPC_WEAK_FUNC(sub_82188754);
PPC_FUNC_IMPL(__imp__sub_82188754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188758"))) PPC_WEAK_FUNC(sub_82188758);
PPC_FUNC_IMPL(__imp__sub_82188758) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82188760;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// li r5,7272
	ctx.r5.s64 = 7272;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,24
	ctx.r3.s64 = ctx.r3.s64 + 24;
	// bl 0x8207da20
	ctx.lr = 0x82188778;
	sub_8207DA20(ctx, base);
	// li r5,7272
	ctx.r5.s64 = 7272;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r24,7296
	ctx.r3.s64 = ctx.r24.s64 + 7296;
	// bl 0x8207da20
	ctx.lr = 0x82188788;
	sub_8207DA20(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// li r3,5808
	ctx.r3.s64 = 5808;
	// stw r31,14568(r24)
	PPC_STORE_U32(ctx.r24.u32 + 14568, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82188798;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821887a8
	if (ctx.cr6.eq) goto loc_821887A8;
	// bl 0x82185938
	ctx.lr = 0x821887A4;
	sub_82185938(ctx, base);
	// b 0x821887ac
	goto loc_821887AC;
loc_821887A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821887AC:
	// li r27,2
	ctx.r27.s64 = 2;
	// stw r3,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r3.u32);
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// li r25,1
	ctx.r25.s64 = 1;
	// li r29,8
	ctx.r29.s64 = 8;
	// li r30,3
	ctx.r30.s64 = 3;
loc_821887C8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82079fd8
	ctx.lr = 0x821887D0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188800
	if (ctx.cr6.eq) goto loc_82188800;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r25.u32);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r30.u32);
	// b 0x82188804
	goto loc_82188804;
loc_82188800:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82188804:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stwu r11,4(r26)
	ea = 4 + ctx.r26.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r26.u32 = ea;
	// bne 0x821887c8
	if (!ctx.cr0.eq) goto loc_821887C8;
	// li r3,1656
	ctx.r3.s64 = 1656;
	// bl 0x82079fd8
	ctx.lr = 0x82188818;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188828
	if (ctx.cr6.eq) goto loc_82188828;
	// bl 0x82188550
	ctx.lr = 0x82188824;
	sub_82188550(ctx, base);
	// b 0x8218882c
	goto loc_8218882C;
loc_82188828:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8218882C:
	// stw r3,12(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12, ctx.r3.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82079fd8
	ctx.lr = 0x82188838;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188864
	if (ctx.cr6.eq) goto loc_82188864;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// li r11,100
	ctx.r11.s64 = 100;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x82188868
	goto loc_82188868;
loc_82188864:
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
loc_82188868:
	// stw r10,16(r24)
	PPC_STORE_U32(ctx.r24.u32 + 16, ctx.r10.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82079fd8
	ctx.lr = 0x82188874;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188894
	if (ctx.cr6.eq) goto loc_82188894;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r25.u32);
	// stw r25,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r25.u32);
	// b 0x82188898
	goto loc_82188898;
loc_82188894:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_82188898:
	// stw r11,20(r24)
	PPC_STORE_U32(ctx.r24.u32 + 20, ctx.r11.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r31,14572(r24)
	PPC_STORE_U32(ctx.r24.u32 + 14572, ctx.r31.u32);
	// stw r31,14576(r24)
	PPC_STORE_U32(ctx.r24.u32 + 14576, ctx.r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821888B0"))) PPC_WEAK_FUNC(sub_821888B0);
PPC_FUNC_IMPL(__imp__sub_821888B0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// b 0x82188638
	sub_82188638(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821888B8"))) PPC_WEAK_FUNC(sub_821888B8);
PPC_FUNC_IMPL(__imp__sub_821888B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821888C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r5,7272
	ctx.r5.s64 = 7272;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,-31348(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// addi r3,r31,7296
	ctx.r3.s64 = ctx.r31.s64 + 7296;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// bl 0x8207da20
	ctx.lr = 0x821888E0;
	sub_8207DA20(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,14568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14568, ctx.r30.u32);
	// bl 0x82186b58
	ctx.lr = 0x821888F0;
	sub_82186B58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821885d0
	ctx.lr = 0x821888F8;
	sub_821885D0(ctx, base);
	// stw r30,14572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14572, ctx.r30.u32);
	// stw r30,14576(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14576, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188908"))) PPC_WEAK_FUNC(sub_82188908);
PPC_FUNC_IMPL(__imp__sub_82188908) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82188910;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lwz r31,-31348(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31348);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82188954
	if (!ctx.cr6.eq) goto loc_82188954;
	// li r3,14584
	ctx.r3.s64 = 14584;
	// bl 0x82079fd8
	ctx.lr = 0x8218892C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188944
	if (ctx.cr6.eq) goto loc_82188944;
	// bl 0x82188758
	ctx.lr = 0x82188938;
	sub_82188758(ctx, base);
	// stw r3,-31348(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31348, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82188944:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31348(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31348, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82188954:
	// li r5,7272
	ctx.r5.s64 = 7272;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,7296
	ctx.r3.s64 = ctx.r31.s64 + 7296;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// bl 0x8207da20
	ctx.lr = 0x82188968;
	sub_8207DA20(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,14568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14568, ctx.r30.u32);
	// bl 0x82186b58
	ctx.lr = 0x82188978;
	sub_82186B58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821885d0
	ctx.lr = 0x82188980;
	sub_821885D0(ctx, base);
	// stw r30,14572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14572, ctx.r30.u32);
	// stw r30,14576(r31)
	PPC_STORE_U32(ctx.r31.u32 + 14576, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188990"))) PPC_WEAK_FUNC(sub_82188990);
PPC_FUNC_IMPL(__imp__sub_82188990) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82188998;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8268(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821889b4
	if (ctx.cr6.eq) goto loc_821889B4;
	// lwz r10,8264(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8264);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_821889B4:
	// lwz r11,8264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8264);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x82188b38
	if (ctx.cr6.gt) goto loc_82188B38;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82188b38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82188B38;
	// bdzf 4*cr6+eq,0x82188a4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82188A4C;
	// bdzf 4*cr6+eq,0x82188b38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82188B38;
	// bdzf 4*cr6+eq,0x82188b24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82188B24;
	// bne cr6,0x82188a4c
	if (!ctx.cr6.eq) goto loc_82188A4C;
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// ori r9,r11,4097
	ctx.r9.u64 = ctx.r11.u64 | 4097;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82188a4c
	if (!ctx.cr6.eq) goto loc_82188A4C;
	// lwz r11,8280(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8280);
	// cmplwi cr6,r11,8192
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8192, ctx.xer);
	// bne cr6,0x82188a4c
	if (!ctx.cr6.eq) goto loc_82188A4C;
	// lbz r11,8273(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8273);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82188a14
	if (!ctx.cr6.eq) goto loc_82188A14;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// bl 0x82188638
	ctx.lr = 0x82188A14;
	sub_82188638(ctx, base);
loc_82188A14:
	// bl 0x82185c18
	ctx.lr = 0x82188A18;
	sub_82185C18(ctx, base);
loc_82188A18:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82188A28;
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
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82188A4C:
	// lbz r11,8272(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82188a6c
	if (ctx.cr6.eq) goto loc_82188A6C;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,32024
	ctx.r10.s64 = ctx.r11.s64 + 32024;
	// stw r10,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82188A6C:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82188A74;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188adc
	if (ctx.cr6.eq) goto loc_82188ADC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24693
	ctx.r4.s64 = ctx.r11.s64 + -24693;
	// bl 0x82060190
	ctx.lr = 0x82188A94;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,22472
	ctx.r4.s64 = ctx.r10.s64 + 22472;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82188AA8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82188AB8;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r31,8276
	ctx.r6.s64 = ctx.r31.s64 + 8276;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x82188AD4;
	sub_821BD670(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82188ae0
	goto loc_82188AE0;
loc_82188ADC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82188AE0:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r7,6640
	ctx.r4.s64 = ctx.r7.s64 + 6640;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x820735c8
	ctx.lr = 0x82188B08;
	sub_820735C8(ctx, base);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82188B24:
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,28024
	ctx.r10.s64 = ctx.r11.s64 + 28024;
	// stw r10,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82188B38:
	// lbz r11,8272(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82188a18
	if (ctx.cr6.eq) goto loc_82188A18;
	// lis r11,-32232
	ctx.r11.s64 = -2112356352;
	// addi r10,r11,32208
	ctx.r10.s64 = ctx.r11.s64 + 32208;
	// stw r10,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188B58"))) PPC_WEAK_FUNC(sub_82188B58);
PPC_FUNC_IMPL(__imp__sub_82188B58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82188B60;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x82188B70;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82188be0
	if (ctx.cr6.eq) goto loc_82188BE0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,22456
	ctx.r30.s64 = ctx.r11.s64 + 22456;
	// addi r28,r31,8280
	ctx.r28.s64 = ctx.r31.s64 + 8280;
	// addi r4,r30,-48
	ctx.r4.s64 = ctx.r30.s64 + -48;
	// addi r27,r31,8264
	ctx.r27.s64 = ctx.r31.s64 + 8264;
	// bl 0x82060190
	ctx.lr = 0x82188B98;
	sub_82060190(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r4,r30,-32
	ctx.r4.s64 = ctx.r30.s64 + -32;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206bb38
	ctx.lr = 0x82188BA8;
	sub_8206BB38(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060190
	ctx.lr = 0x82188BB8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r7,r31,72
	ctx.r7.s64 = ctx.r31.s64 + 72;
	// li r8,8192
	ctx.r8.s64 = 8192;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// bl 0x82194af0
	ctx.lr = 0x82188BDC;
	sub_82194AF0(ctx, base);
	// b 0x82188be4
	goto loc_82188BE4;
loc_82188BE0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82188BE4:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-30320
	ctx.r6.s64 = ctx.r8.s64 + -30320;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r6,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r6.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188C14"))) PPC_WEAK_FUNC(sub_82188C14);
PPC_FUNC_IMPL(__imp__sub_82188C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188C18"))) PPC_WEAK_FUNC(sub_82188C18);
PPC_FUNC_IMPL(__imp__sub_82188C18) {
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
	// addi r9,r3,16
	ctx.r9.s64 = ctx.r3.s64 + 16;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r8,r3,44
	ctx.r8.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// addi r6,r10,-1396
	ctx.r6.s64 = ctx.r10.s64 + -1396;
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r9,r8,16
	ctx.r9.s64 = ctx.r8.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r5,r7,840
	ctx.r5.s64 = ctx.r7.s64 + 840;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r8,r3,4976
	ctx.r8.s64 = ctx.r3.s64 + 4976;
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// addi r3,r31,72
	ctx.r3.s64 = ctx.r31.s64 + 72;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stb r11,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stb r11,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r11.u8);
	// stw r4,8268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8268, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r10.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r10,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r10.u8);
	// stb r10,8272(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8272, ctx.r10.u8);
	// stb r11,8273(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8273, ctx.r11.u8);
	// bl 0x8207da20
	ctx.lr = 0x82188CCC;
	sub_8207DA20(ctx, base);
	// lis r7,-32231
	ctx.r7.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r6,r7,-29864
	ctx.r6.s64 = ctx.r7.s64 + -29864;
	// stw r6,8284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8284, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_82188CF0"))) PPC_WEAK_FUNC(sub_82188CF0);
PPC_FUNC_IMPL(__imp__sub_82188CF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188CF4"))) PPC_WEAK_FUNC(sub_82188CF4);
PPC_FUNC_IMPL(__imp__sub_82188CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188CF8"))) PPC_WEAK_FUNC(sub_82188CF8);
PPC_FUNC_IMPL(__imp__sub_82188CF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82188D04"))) PPC_WEAK_FUNC(sub_82188D04);
PPC_FUNC_IMPL(__imp__sub_82188D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188D08"))) PPC_WEAK_FUNC(sub_82188D08);
PPC_FUNC_IMPL(__imp__sub_82188D08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82188D10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,-13972
	ctx.r29.s64 = ctx.r11.s64 + -13972;
	// lwz r11,-13972(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -13972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82188d90
	if (ctx.cr6.eq) goto loc_82188D90;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
loc_82188D34:
	// lwz r31,-31364(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31364);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82188D50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x82188d78
	if (ctx.cr6.eq) goto loc_82188D78;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82188D78;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82188D78:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82188d34
	if (!ctx.cr6.eq) goto loc_82188D34;
loc_82188D90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188D98"))) PPC_WEAK_FUNC(sub_82188D98);
PPC_FUNC_IMPL(__imp__sub_82188D98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82188DA0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r29,r11,-13972
	ctx.r29.s64 = ctx.r11.s64 + -13972;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,-13972(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -13972);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82188e24
	if (ctx.cr6.eq) goto loc_82188E24;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
loc_82188DC8:
	// lwz r31,-31364(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31364);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82188DE4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x82188e0c
	if (ctx.cr6.eq) goto loc_82188E0C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82188E0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82188E0C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82188dc8
	if (!ctx.cr6.eq) goto loc_82188DC8;
loc_82188E24:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188E2C"))) PPC_WEAK_FUNC(sub_82188E2C);
PPC_FUNC_IMPL(__imp__sub_82188E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188E30"))) PPC_WEAK_FUNC(sub_82188E30);
PPC_FUNC_IMPL(__imp__sub_82188E30) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mulli r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 * 28;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,272(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188E48"))) PPC_WEAK_FUNC(sub_82188E48);
PPC_FUNC_IMPL(__imp__sub_82188E48) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// lwz r3,272(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188E58"))) PPC_WEAK_FUNC(sub_82188E58);
PPC_FUNC_IMPL(__imp__sub_82188E58) {
	PPC_FUNC_PROLOGUE();
	// b 0x821ca108
	sub_821CA108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188E5C"))) PPC_WEAK_FUNC(sub_82188E5C);
PPC_FUNC_IMPL(__imp__sub_82188E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188E60"))) PPC_WEAK_FUNC(sub_82188E60);
PPC_FUNC_IMPL(__imp__sub_82188E60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82188E68;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// mulli r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 * 28;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r29,r9,-32240
	ctx.r29.s64 = ctx.r9.s64 + -32240;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r11,r31,268
	ctx.r11.s64 = ctx.r31.s64 + 268;
	// bl 0x821d5384
	ctx.lr = 0x82188E94;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r30,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// stw r30,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f0,21768(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// bl 0x821d5394
	ctx.lr = 0x82188EB0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188EB8"))) PPC_WEAK_FUNC(sub_82188EB8);
PPC_FUNC_IMPL(__imp__sub_82188EB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82188EC0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r31,-31364(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// lwz r10,272(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82188f0c
	if (ctx.cr6.eq) goto loc_82188F0C;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r31,268
	ctx.r11.s64 = ctx.r31.s64 + 268;
	// addi r29,r10,-32240
	ctx.r29.s64 = ctx.r10.s64 + -32240;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x82188EF0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r30,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r30.u32);
	// lfs f0,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// bl 0x821d5394
	ctx.lr = 0x82188F0C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82188F0C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188F14"))) PPC_WEAK_FUNC(sub_82188F14);
PPC_FUNC_IMPL(__imp__sub_82188F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188F18"))) PPC_WEAK_FUNC(sub_82188F18);
PPC_FUNC_IMPL(__imp__sub_82188F18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82188F20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// li r31,28
	ctx.r31.s64 = 28;
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r11,-31364(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31364);
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
loc_82188F38:
	// lwz r10,272(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82188f50
	if (ctx.cr6.eq) goto loc_82188F50;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821ca108
	ctx.lr = 0x82188F4C;
	sub_821CA108(ctx, base);
	// lwz r11,-31364(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31364);
loc_82188F50:
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r31,196
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 196, ctx.xer);
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
	// ble cr6,0x82188f38
	if (!ctx.cr6.gt) goto loc_82188F38;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188F6C"))) PPC_WEAK_FUNC(sub_82188F6C);
PPC_FUNC_IMPL(__imp__sub_82188F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82188F70"))) PPC_WEAK_FUNC(sub_82188F70);
PPC_FUNC_IMPL(__imp__sub_82188F70) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// lwz r10,272(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x821ca108
	sub_821CA108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82188F8C"))) PPC_WEAK_FUNC(sub_82188F8C);
PPC_FUNC_IMPL(__imp__sub_82188F8C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82188F90"))) PPC_WEAK_FUNC(sub_82188F90);
PPC_FUNC_IMPL(__imp__sub_82188F90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82188F98;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r31,r11,23168
	ctx.r31.s64 = ctx.r11.s64 + 23168;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_82188FB4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82188fe0
	if (ctx.cr6.eq) goto loc_82188FE0;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// addi r8,r31,124
	ctx.r8.s64 = ctx.r31.s64 + 124;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x82188fb4
	if (ctx.cr6.lt) goto loc_82188FB4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82188FE0:
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// addi r8,r31,8
	ctx.r8.s64 = ctx.r31.s64 + 8;
	// stb r9,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r9.u8);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r6,15
	ctx.r6.s64 = 15;
	// rlwinm r30,r7,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// lwzx r4,r30,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r8.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_82189008:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82189008
	if (!ctx.cr6.eq) goto loc_82189008;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8218902C;
	sub_82060368(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f1,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ca7e0
	ctx.lr = 0x82189044;
	sub_821CA7E0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218904C"))) PPC_WEAK_FUNC(sub_8218904C);
PPC_FUNC_IMPL(__imp__sub_8218904C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189050"))) PPC_WEAK_FUNC(sub_82189050);
PPC_FUNC_IMPL(__imp__sub_82189050) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,-31364(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31364);
	// addi r10,r10,300
	ctx.r10.s64 = ctx.r10.s64 + 300;
loc_82189064:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82189088
	if (ctx.cr6.eq) goto loc_82189088;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,28
	ctx.r10.s64 = ctx.r10.s64 + 28;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// ble cr6,0x82189064
	if (!ctx.cr6.gt) goto loc_82189064;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82188f90
	sub_82188F90(ctx, base);
	return;
loc_82189088:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x82188f90
	sub_82188F90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189090"))) PPC_WEAK_FUNC(sub_82189090);
PPC_FUNC_IMPL(__imp__sub_82189090) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,272
	ctx.r11.s64 = ctx.r11.s64 + 272;
loc_821890A0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821890c4
	if (ctx.cr6.eq) goto loc_821890C4;
	// addic. r3,r3,1
	ctx.xer.ca = ctx.r3.u32 > 4294967294;
	ctx.r3.s64 = ctx.r3.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// ble 0x821890a0
	if (!ctx.cr0.gt) goto loc_821890A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82188f90
	sub_82188F90(ctx, base);
	return;
loc_821890C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82188f90
	sub_82188F90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821890CC"))) PPC_WEAK_FUNC(sub_821890CC);
PPC_FUNC_IMPL(__imp__sub_821890CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821890D0"))) PPC_WEAK_FUNC(sub_821890D0);
PPC_FUNC_IMPL(__imp__sub_821890D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821890D8;
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
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,4436
	ctx.r10.s64 = ctx.r11.s64 + 4436;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82189104
	if (ctx.cr6.eq) goto loc_82189104;
	// bl 0x82088d00
	ctx.lr = 0x82189100;
	sub_82088D00(ctx, base);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
loc_82189104:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189118
	if (ctx.cr6.eq) goto loc_82189118;
	// bl 0x8207a630
	ctx.lr = 0x82189114;
	sub_8207A630(ctx, base);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
loc_82189118:
	// bl 0x821ca9f0
	ctx.lr = 0x8218911C;
	sub_821CA9F0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x82189130;
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
	ctx.lr = 0x82189148;
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

__attribute__((alias("__imp__sub_82189158"))) PPC_WEAK_FUNC(sub_82189158);
PPC_FUNC_IMPL(__imp__sub_82189158) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-13956
	ctx.r9.s64 = ctx.r11.s64 + -13956;
	// lwzx r31,r10,r9
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821891c0
	if (ctx.cr6.eq) goto loc_821891C0;
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,264(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 264);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f12,f0
	ctx.f31.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
loc_821891AC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x821caa60
	ctx.lr = 0x821891B4;
	sub_821CAA60(ctx, base);
	// lwzu r3,4(r31)
	ea = 4 + ctx.r31.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821891ac
	if (!ctx.cr6.eq) goto loc_821891AC;
loc_821891C0:
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

__attribute__((alias("__imp__sub_821891D8"))) PPC_WEAK_FUNC(sub_821891D8);
PPC_FUNC_IMPL(__imp__sub_821891D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821891E0;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r29,r11,21768
	ctx.r29.s64 = ctx.r11.s64 + 21768;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r31,r29,1208
	ctx.r31.s64 = ctx.r29.s64 + 1208;
	// lis r26,-32224
	ctx.r26.s64 = -2111832064;
loc_821891FC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x82189224
	if (ctx.cr6.lt) goto loc_82189224;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// bge cr6,0x82189224
	if (!ctx.cr6.lt) goto loc_82189224;
	// lwz r11,-31364(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31364);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// b 0x82189228
	goto loc_82189228;
loc_82189224:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_82189228:
	// bl 0x821ca2e8
	ctx.lr = 0x8218922C;
	sub_821CA2E8(ctx, base);
	// addi r11,r29,1208
	ctx.r11.s64 = ctx.r29.s64 + 1208;
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x821891fc
	if (ctx.cr6.lt) goto loc_821891FC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// addi r27,r11,-14004
	ctx.r27.s64 = ctx.r11.s64 + -14004;
	// lwz r11,-14004(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -14004);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821892f4
	if (ctx.cr6.eq) goto loc_821892F4;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r29,15
	ctx.r29.s64 = 15;
loc_82189268:
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,-31364(r26)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31364);
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stb r28,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
loc_82189280:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82189280
	if (!ctx.cr6.eq) goto loc_82189280;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821892A4;
	sub_82060368(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,580
	ctx.r3.s64 = ctx.r31.s64 + 580;
	// bl 0x8206b268
	ctx.lr = 0x821892B0;
	sub_8206B268(ctx, base);
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x821892c4
	if (ctx.cr6.lt) goto loc_821892C4;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x821892C4;
	sub_8207A630(ctx, base);
loc_821892C4:
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// addi r3,r31,604
	ctx.r3.s64 = ctx.r31.s64 + 604;
	// stb r28,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
	// bl 0x8206b3a0
	ctx.lr = 0x821892DC;
	sub_8206B3A0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82189268
	if (!ctx.cr6.eq) goto loc_82189268;
loc_821892F4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-29456
	ctx.r9.s64 = ctx.r11.s64 + -29456;
	// stw r10,92(r25)
	PPC_STORE_U32(ctx.r25.u32 + 92, ctx.r10.u32);
	// stw r9,72(r25)
	PPC_STORE_U32(ctx.r25.u32 + 72, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189310"))) PPC_WEAK_FUNC(sub_82189310);
PPC_FUNC_IMPL(__imp__sub_82189310) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82189318;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r22,r11,22976
	ctx.r22.s64 = ctx.r11.s64 + 22976;
	// li r26,15
	ctx.r26.s64 = 15;
	// addi r28,r22,8
	ctx.r28.s64 = ctx.r22.s64 + 8;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// li r23,-1
	ctx.r23.s64 = -1;
	// lis r24,-32224
	ctx.r24.s64 = -2111832064;
loc_82189340:
	// lwz r10,-8(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + -8);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x821894c4
	if (ctx.cr6.lt) goto loc_821894C4;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// bge cr6,0x821894c4
	if (!ctx.cr6.lt) goto loc_821894C4;
	// lwz r11,-31364(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31364);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r30,r11,12
	ctx.r30.s64 = ctx.r11.s64 + 12;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821894c4
	if (ctx.cr6.eq) goto loc_821894C4;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
loc_82189380:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82189380
	if (!ctx.cr6.eq) goto loc_82189380;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821893A4;
	sub_82060368(ctx, base);
	// lwz r11,-31352(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31352);
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r30,20
	ctx.r6.s64 = ctx.r30.s64 + 20;
	// addi r5,r30,12
	ctx.r5.s64 = ctx.r30.s64 + 12;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82194df8
	ctx.lr = 0x821893C8;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821893CC;
	sub_82193870(ctx, base);
	// lwz r10,36(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r31,r25,16
	ctx.r31.s64 = ctx.r25.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r25)
	PPC_STORE_U32(ctx.r25.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// lwz r9,-4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8218944c
	if (ctx.cr6.eq) goto loc_8218944C;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r26.u32);
	// stw r29,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stb r29,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r29.u8);
loc_82189404:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82189404
	if (!ctx.cr6.eq) goto loc_82189404;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x82189428;
	sub_82060368(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821936e8
	ctx.lr = 0x82189434;
	sub_821936E8(ctx, base);
	// stw r3,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x821894c4
	if (!ctx.cr6.eq) goto loc_821894C4;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x8210e878
	ctx.lr = 0x82189448;
	sub_8210E878(ctx, base);
	// b 0x821894c4
	goto loc_821894C4;
loc_8218944C:
	// stw r23,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r23.u32);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r26.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
loc_82189464:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82189464
	if (!ctx.cr6.eq) goto loc_82189464;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x82189488;
	sub_82060368(ctx, base);
	// lwz r11,-31352(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31352);
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r30,16
	ctx.r6.s64 = ctx.r30.s64 + 16;
	// addi r5,r30,8
	ctx.r5.s64 = ctx.r30.s64 + 8;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82194df8
	ctx.lr = 0x821894AC;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821894B0;
	sub_82193870(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
loc_821894C4:
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// addi r11,r22,88
	ctx.r11.s64 = ctx.r22.s64 + 88;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82189340
	if (ctx.cr6.lt) goto loc_82189340;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-28200
	ctx.r10.s64 = ctx.r11.s64 + -28200;
	// stw r10,72(r25)
	PPC_STORE_U32(ctx.r25.u32 + 72, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821894E8"))) PPC_WEAK_FUNC(sub_821894E8);
PPC_FUNC_IMPL(__imp__sub_821894E8) {
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
	// lwz r4,88(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,84(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// bl 0x821cb248
	ctx.lr = 0x82189508;
	sub_821CB248(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-27888
	ctx.r10.s64 = ctx.r11.s64 + -27888;
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

__attribute__((alias("__imp__sub_82189528"))) PPC_WEAK_FUNC(sub_82189528);
PPC_FUNC_IMPL(__imp__sub_82189528) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r4,r10,23288
	ctx.r4.s64 = ctx.r10.s64 + 23288;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x82189568;
	sub_82060368(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,88
	ctx.r6.s64 = ctx.r31.s64 + 88;
	// lwz r11,-31352(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31352);
	// addi r5,r31,84
	ctx.r5.s64 = ctx.r31.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x82194df8
	ctx.lr = 0x82189590;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x82189594;
	sub_82193870(ctx, base);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,-27416
	ctx.r9.s64 = ctx.r10.s64 + -27416;
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

__attribute__((alias("__imp__sub_821895D0"))) PPC_WEAK_FUNC(sub_821895D0);
PPC_FUNC_IMPL(__imp__sub_821895D0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-27352
	ctx.r10.s64 = ctx.r11.s64 + -27352;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821895E0"))) PPC_WEAK_FUNC(sub_821895E0);
PPC_FUNC_IMPL(__imp__sub_821895E0) {
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
	// lis r5,-32231
	ctx.r5.s64 = -2112290816;
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
	// addi r6,r6,4436
	ctx.r6.s64 = ctx.r6.s64 + 4436;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r5,r5,-27184
	ctx.r5.s64 = ctx.r5.s64 + -27184;
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
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// stw r5,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189684"))) PPC_WEAK_FUNC(sub_82189684);
PPC_FUNC_IMPL(__imp__sub_82189684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189688"))) PPC_WEAK_FUNC(sub_82189688);
PPC_FUNC_IMPL(__imp__sub_82189688) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218969C"))) PPC_WEAK_FUNC(sub_8218969C);
PPC_FUNC_IMPL(__imp__sub_8218969C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821896A0"))) PPC_WEAK_FUNC(sub_821896A0);
PPC_FUNC_IMPL(__imp__sub_821896A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// stb r3,124(r11)
	PPC_STORE_U8(ctx.r11.u32 + 124, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821896B0"))) PPC_WEAK_FUNC(sub_821896B0);
PPC_FUNC_IMPL(__imp__sub_821896B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-24408
	ctx.r9.s64 = ctx.r11.s64 + -24408;
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821896C8"))) PPC_WEAK_FUNC(sub_821896C8);
PPC_FUNC_IMPL(__imp__sub_821896C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821896D4"))) PPC_WEAK_FUNC(sub_821896D4);
PPC_FUNC_IMPL(__imp__sub_821896D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821896D8"))) PPC_WEAK_FUNC(sub_821896D8);
PPC_FUNC_IMPL(__imp__sub_821896D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r3,29
	ctx.r10.s64 = ctx.r3.s64 + 29;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwzx r11,r9,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821896fc
	if (ctx.cr6.eq) goto loc_821896FC;
	// lwz r3,188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// blr 
	return;
loc_821896FC:
	// li r3,8
	ctx.r3.s64 = 8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189704"))) PPC_WEAK_FUNC(sub_82189704);
PPC_FUNC_IMPL(__imp__sub_82189704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189708"))) PPC_WEAK_FUNC(sub_82189708);
PPC_FUNC_IMPL(__imp__sub_82189708) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r3,29
	ctx.r10.s64 = ctx.r3.s64 + 29;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwzx r11,r9,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189734
	if (ctx.cr6.eq) goto loc_82189734;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_82189734:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218973C"))) PPC_WEAK_FUNC(sub_8218973C);
PPC_FUNC_IMPL(__imp__sub_8218973C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189740"))) PPC_WEAK_FUNC(sub_82189740);
PPC_FUNC_IMPL(__imp__sub_82189740) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82189748;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// addi r30,r11,116
	ctx.r30.s64 = ctx.r11.s64 + 116;
	// addi r29,r11,124
	ctx.r29.s64 = ctx.r11.s64 + 124;
loc_82189760:
	// lbzx r11,r29,r31
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r31.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189794
	if (ctx.cr6.eq) goto loc_82189794;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189794
	if (ctx.cr6.eq) goto loc_82189794;
	// lwz r11,188(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82189794
	if (!ctx.cr6.eq) goto loc_82189794;
	// bl 0x82191a28
	ctx.lr = 0x82189788;
	sub_82191A28(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821897b0
	if (!ctx.cr6.eq) goto loc_821897B0;
loc_82189794:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r31,2
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2, ctx.xer);
	// blt cr6,0x82189760
	if (ctx.cr6.lt) goto loc_82189760;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_821897B0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821897BC"))) PPC_WEAK_FUNC(sub_821897BC);
PPC_FUNC_IMPL(__imp__sub_821897BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821897C0"))) PPC_WEAK_FUNC(sub_821897C0);
PPC_FUNC_IMPL(__imp__sub_821897C0) {
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
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r3,116(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821897f4
	if (ctx.cr6.eq) goto loc_821897F4;
	// bl 0x82191a28
	ctx.lr = 0x821897E4;
	sub_82191A28(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821897f8
	if (!ctx.cr6.eq) goto loc_821897F8;
loc_821897F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821897F8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189808"))) PPC_WEAK_FUNC(sub_82189808);
PPC_FUNC_IMPL(__imp__sub_82189808) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// addi r10,r11,116
	ctx.r10.s64 = ctx.r11.s64 + 116;
loc_82189818:
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189874
	if (ctx.cr6.eq) goto loc_82189874;
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// lwz r11,192(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 192);
	// addi r7,r8,6816
	ctx.r7.s64 = ctx.r8.s64 + 6816;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8218984c
	if (ctx.cr6.eq) goto loc_8218984C;
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r7,r8,6808
	ctx.r7.s64 = ctx.r8.s64 + 6808;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82189850
	if (!ctx.cr6.eq) goto loc_82189850;
loc_8218984C:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82189850:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189874
	if (ctx.cr6.eq) goto loc_82189874;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// blt cr6,0x82189818
	if (ctx.cr6.lt) goto loc_82189818;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82189874:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218987C"))) PPC_WEAK_FUNC(sub_8218987C);
PPC_FUNC_IMPL(__imp__sub_8218987C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189880"))) PPC_WEAK_FUNC(sub_82189880);
PPC_FUNC_IMPL(__imp__sub_82189880) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// ori r4,r4,32769
	ctx.r4.u64 = ctx.r4.u64 | 32769;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r3,40(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x821898d0
	if (!ctx.cr6.lt) goto loc_821898D0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x82088f60
	ctx.lr = 0x821898C8;
	sub_82088F60(ctx, base);
	// stw r31,92(r30)
	PPC_STORE_U32(ctx.r30.u32 + 92, ctx.r31.u32);
	// b 0x821898d8
	goto loc_821898D8;
loc_821898D0:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82088f60
	ctx.lr = 0x821898D8;
	sub_82088F60(ctx, base);
loc_821898D8:
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

__attribute__((alias("__imp__sub_821898F0"))) PPC_WEAK_FUNC(sub_821898F0);
PPC_FUNC_IMPL(__imp__sub_821898F0) {
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
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189928
	if (ctx.cr6.eq) goto loc_82189928;
	// li r4,60
	ctx.r4.s64 = 60;
	// bl 0x821bd1b8
	ctx.lr = 0x8218991C;
	sub_821BD1B8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189a00
	if (ctx.cr6.eq) goto loc_82189A00;
loc_82189928:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r10,-31352(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r11,116(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189958
	if (ctx.cr6.eq) goto loc_82189958;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8218995c
	if (ctx.cr6.eq) goto loc_8218995C;
loc_82189958:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218995C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218996c
	if (ctx.cr6.eq) goto loc_8218996C;
	// li r9,1
	ctx.r9.s64 = 1;
loc_8218996C:
	// lwz r11,120(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189988
	if (ctx.cr6.eq) goto loc_82189988;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8218998c
	if (ctx.cr6.eq) goto loc_8218998C;
loc_82189988:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218998C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218999c
	if (ctx.cr6.eq) goto loc_8218999C;
	// ori r9,r9,2
	ctx.r9.u64 = ctx.r9.u64 | 2;
loc_8218999C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r3,28
	ctx.r3.s64 = 28;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r9,14576(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14576, ctx.r9.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821899B0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821899e4
	if (ctx.cr6.eq) goto loc_821899E4;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r31.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r9,r11,5288
	ctx.r9.s64 = ctx.r11.s64 + 5288;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r8,r10,6640
	ctx.r8.s64 = ctx.r10.s64 + 6640;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821899e8
	goto loc_821899E8;
loc_821899E4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821899E8:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82189A00:
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

__attribute__((alias("__imp__sub_82189A18"))) PPC_WEAK_FUNC(sub_82189A18);
PPC_FUNC_IMPL(__imp__sub_82189A18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82189A20;
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
	// addi r9,r11,4420
	ctx.r9.s64 = ctx.r11.s64 + 4420;
	// addi r30,r10,-1408
	ctx.r30.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x82189A48;
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
	ctx.lr = 0x82189A60;
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

__attribute__((alias("__imp__sub_82189A70"))) PPC_WEAK_FUNC(sub_82189A70);
PPC_FUNC_IMPL(__imp__sub_82189A70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82189A78;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,2
	ctx.r27.s64 = 2;
	// addi r30,r3,112
	ctx.r30.s64 = ctx.r3.s64 + 112;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// li r28,0
	ctx.r28.s64 = 0;
loc_82189A8C:
	// lwz r31,4(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82189aa4
	if (ctx.cr6.eq) goto loc_82189AA4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82192128
	ctx.lr = 0x82189AA0;
	sub_82192128(ctx, base);
	// stw r27,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
loc_82189AA4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	PPC_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// bne 0x82189a8c
	if (!ctx.cr0.eq) goto loc_82189A8C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189AB8"))) PPC_WEAK_FUNC(sub_82189AB8);
PPC_FUNC_IMPL(__imp__sub_82189AB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82189AC0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r27,2
	ctx.r27.s64 = 2;
	// addi r10,r11,4404
	ctx.r10.s64 = ctx.r11.s64 + 4404;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r3,116
	ctx.r29.s64 = ctx.r3.s64 + 116;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
loc_82189AE0:
	// lwz r30,0(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82189af8
	if (ctx.cr6.eq) goto loc_82189AF8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82192128
	ctx.lr = 0x82189AF4;
	sub_82192128(ctx, base);
	// stw r27,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r27.u32);
loc_82189AF8:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x82189ae0
	if (!ctx.cr0.eq) goto loc_82189AE0;
	// lwz r29,76(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// addi r28,r11,5288
	ctx.r28.s64 = ctx.r11.s64 + 5288;
	// beq cr6,0x82189b6c
	if (ctx.cr6.eq) goto loc_82189B6C;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82189B24;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189b50
	if (ctx.cr6.eq) goto loc_82189B50;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r29.u32);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,6640
	ctx.r9.s64 = ctx.r10.s64 + 6640;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x82189b54
	goto loc_82189B54;
loc_82189B50:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82189B54:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82189B6C:
	// lwz r29,80(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82189bc8
	if (ctx.cr6.eq) goto loc_82189BC8;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82189B80;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189bac
	if (ctx.cr6.eq) goto loc_82189BAC;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r29.u32);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,6640
	ctx.r9.s64 = ctx.r10.s64 + 6640;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x82189bb0
	goto loc_82189BB0;
loc_82189BAC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82189BB0:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82189BC8:
	// lwz r29,84(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82189c24
	if (ctx.cr6.eq) goto loc_82189C24;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82189BDC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189c08
	if (ctx.cr6.eq) goto loc_82189C08;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r29.u32);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,6640
	ctx.r9.s64 = ctx.r10.s64 + 6640;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x82189c0c
	goto loc_82189C0C;
loc_82189C08:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82189C0C:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82189C24:
	// lwz r29,88(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82189c80
	if (ctx.cr6.eq) goto loc_82189C80;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x82189C38;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189c64
	if (ctx.cr6.eq) goto loc_82189C64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r29.u32);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,6640
	ctx.r9.s64 = ctx.r10.s64 + 6640;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x82189c68
	goto loc_82189C68;
loc_82189C64:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82189C68:
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r31,16
	ctx.r9.s64 = ctx.r31.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_82189C80:
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lwz r29,-31348(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31348);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82189ca4
	if (ctx.cr6.eq) goto loc_82189CA4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82185e00
	ctx.lr = 0x82189C98;
	sub_82185E00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207a630
	ctx.lr = 0x82189CA0;
	sub_8207A630(ctx, base);
	// stw r30,-31348(r28)
	PPC_STORE_U32(ctx.r28.u32 + -31348, ctx.r30.u32);
loc_82189CA4:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x82189CB8;
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
	ctx.lr = 0x82189CD0;
	sub_82173A18(ctx, base);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189CE0"))) PPC_WEAK_FUNC(sub_82189CE0);
PPC_FUNC_IMPL(__imp__sub_82189CE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82189CE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r11,120(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189d98
	if (ctx.cr6.eq) goto loc_82189D98;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82189d98
	if (!ctx.cr6.eq) goto loc_82189D98;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82189D18;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189d78
	if (ctx.cr6.eq) goto loc_82189D78;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24621
	ctx.r4.s64 = ctx.r11.s64 + -24621;
	// bl 0x82060190
	ctx.lr = 0x82189D34;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,23564
	ctx.r4.s64 = ctx.r10.s64 + 23564;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82189D48;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82189D58;
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
	ctx.lr = 0x82189D74;
	sub_821BD670(ctx, base);
	// b 0x82189d7c
	goto loc_82189D7C;
loc_82189D78:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82189D7C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
loc_82189D98:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-26384
	ctx.r10.s64 = ctx.r11.s64 + -26384;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189DAC"))) PPC_WEAK_FUNC(sub_82189DAC);
PPC_FUNC_IMPL(__imp__sub_82189DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189DB0"))) PPC_WEAK_FUNC(sub_82189DB0);
PPC_FUNC_IMPL(__imp__sub_82189DB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82189DB8;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r11,116(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189e68
	if (ctx.cr6.eq) goto loc_82189E68;
	// lwz r11,188(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 188);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82189e68
	if (!ctx.cr6.eq) goto loc_82189E68;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82189DE8;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189e48
	if (ctx.cr6.eq) goto loc_82189E48;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24622
	ctx.r4.s64 = ctx.r11.s64 + -24622;
	// bl 0x82060190
	ctx.lr = 0x82189E04;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,23540
	ctx.r4.s64 = ctx.r10.s64 + 23540;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82189E18;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82189E28;
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
	ctx.lr = 0x82189E44;
	sub_821BD670(ctx, base);
	// b 0x82189e4c
	goto loc_82189E4C;
loc_82189E48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82189E4C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
loc_82189E68:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-25376
	ctx.r10.s64 = ctx.r11.s64 + -25376;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82189E7C"))) PPC_WEAK_FUNC(sub_82189E7C);
PPC_FUNC_IMPL(__imp__sub_82189E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189E80"))) PPC_WEAK_FUNC(sub_82189E80);
PPC_FUNC_IMPL(__imp__sub_82189E80) {
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
	// bl 0x82189808
	ctx.lr = 0x82189E94;
	sub_82189808(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82189eac
	if (ctx.cr6.eq) goto loc_82189EAC;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-25168
	ctx.r10.s64 = ctx.r11.s64 + -25168;
	// stw r10,72(r6)
	PPC_STORE_U32(ctx.r6.u32 + 72, ctx.r10.u32);
loc_82189EAC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82189EBC"))) PPC_WEAK_FUNC(sub_82189EBC);
PPC_FUNC_IMPL(__imp__sub_82189EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82189EC0"))) PPC_WEAK_FUNC(sub_82189EC0);
PPC_FUNC_IMPL(__imp__sub_82189EC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82189EC8;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r29,r3,44
	ctx.r29.s64 = ctx.r3.s64 + 44;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// lwz r10,-31352(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// addi r11,r29,16
	ctx.r11.s64 = ctx.r29.s64 + 16;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r4,r7,4420
	ctx.r4.s64 = ctx.r7.s64 + 4420;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
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
	// stb r9,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r9.u8);
	// stb r9,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r9.u8);
	// stw r30,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// lwz r3,76(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x8218a010
	if (!ctx.cr6.lt) goto loc_8218A010;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x82189F7C;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82189fdc
	if (ctx.cr6.eq) goto loc_82189FDC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24629
	ctx.r4.s64 = ctx.r11.s64 + -24629;
	// bl 0x82060190
	ctx.lr = 0x82189F98;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,23524
	ctx.r4.s64 = ctx.r10.s64 + 23524;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x82189FAC;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82189FBC;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,3
	ctx.r8.s64 = 3;
	// bl 0x821bd670
	ctx.lr = 0x82189FD8;
	sub_821BD670(ctx, base);
	// b 0x82189fe0
	goto loc_82189FE0;
loc_82189FDC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82189FE0:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r8,r10,-24960
	ctx.r8.s64 = ctx.r10.s64 + -24960;
	// stw r11,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8218A010:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-26384
	ctx.r10.s64 = ctx.r11.s64 + -26384;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218A028"))) PPC_WEAK_FUNC(sub_8218A028);
PPC_FUNC_IMPL(__imp__sub_8218A028) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218A030;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82189a70
	ctx.lr = 0x8218A03C;
	sub_82189A70(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r28,r29,44
	ctx.r28.s64 = ctx.r29.s64 + 44;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// addi r30,r11,-12356
	ctx.r30.s64 = ctx.r11.s64 + -12356;
	// addi r29,r29,112
	ctx.r29.s64 = ctx.r29.s64 + 112;
loc_8218A054:
	// li r3,196
	ctx.r3.s64 = 196;
	// bl 0x82079fd8
	ctx.lr = 0x8218A05C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218a074
	if (ctx.cr6.eq) goto loc_8218A074;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x82193c28
	ctx.lr = 0x8218A070;
	sub_82193C28(ctx, base);
	// b 0x8218a078
	goto loc_8218A078;
loc_8218A074:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8218A078:
	// stwu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r29.u32 = ea;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// stw r11,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r31,2
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2, ctx.xer);
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r27.u32);
	// blt cr6,0x8218a054
	if (ctx.cr6.lt) goto loc_8218A054;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218A0A8"))) PPC_WEAK_FUNC(sub_8218A0A8);
PPC_FUNC_IMPL(__imp__sub_8218A0A8) {
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
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r8,68(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8218a16c
	if (ctx.cr6.eq) goto loc_8218A16C;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// stw r30,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r30.u32);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x8218a0f4
	if (ctx.cr6.lt) goto loc_8218A0F4;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x8218a100
	goto loc_8218A100;
loc_8218A0F4:
	// addi r9,r10,6
	ctx.r9.s64 = ctx.r10.s64 + 6;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
loc_8218A100:
	// li r9,1
	ctx.r9.s64 = 1;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x8218a11c
	if (!ctx.cr6.lt) goto loc_8218A11C;
	// slw r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// and r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 & ctx.r8.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8218a16c
	if (ctx.cr6.eq) goto loc_8218A16C;
loc_8218A11C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8218a16c
	if (!ctx.cr6.eq) goto loc_8218A16C;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r30,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r30.u32);
	// stw r30,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r30.u32);
	// stw r30,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r30.u32);
	// stw r30,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r30.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// beq cr6,0x8218a150
	if (ctx.cr6.eq) goto loc_8218A150;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
loc_8218A150:
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8218a16c
	if (ctx.cr6.eq) goto loc_8218A16C;
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8218a16c
	if (!ctx.cr6.eq) goto loc_8218A16C;
	// stw r9,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r9.u32);
loc_8218A16C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8218a1e8
	if (ctx.cr6.eq) goto loc_8218A1E8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// stw r30,40(r9)
	PPC_STORE_U32(ctx.r9.u32 + 40, ctx.r30.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x8218a1e8
	if (ctx.cr6.eq) goto loc_8218A1E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82189a70
	ctx.lr = 0x8218A1A0;
	sub_82189A70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8218a028
	ctx.lr = 0x8218A1A8;
	sub_8218A028(ctx, base);
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82079fd8
	ctx.lr = 0x8218A1B0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218a1c0
	if (ctx.cr6.eq) goto loc_8218A1C0;
	// bl 0x82189ec0
	ctx.lr = 0x8218A1BC;
	sub_82189EC0(ctx, base);
	// b 0x8218a1c4
	goto loc_8218A1C4;
loc_8218A1C0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218A1C4:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,-26960
	ctx.r7.s64 = ctx.r8.s64 + -26960;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
loc_8218A1E8:
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

__attribute__((alias("__imp__sub_8218A200"))) PPC_WEAK_FUNC(sub_8218A200);
PPC_FUNC_IMPL(__imp__sub_8218A200) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-24408
	ctx.r9.s64 = ctx.r11.s64 + -24408;
	// stw r10,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A218"))) PPC_WEAK_FUNC(sub_8218A218);
PPC_FUNC_IMPL(__imp__sub_8218A218) {
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
	// li r3,88
	ctx.r3.s64 = 88;
	// bl 0x82079fd8
	ctx.lr = 0x8218A238;
	sub_82079FD8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218a250
	if (ctx.cr6.eq) goto loc_8218A250;
	// bl 0x82191820
	ctx.lr = 0x8218A248;
	sub_82191820(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218a254
	goto loc_8218A254;
loc_8218A250:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218A254:
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82079fd8
	ctx.lr = 0x8218A260;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218a274
	if (ctx.cr6.eq) goto loc_8218A274;
	// bl 0x82193a60
	ctx.lr = 0x8218A26C;
	sub_82193A60(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218a278
	goto loc_8218A278;
loc_8218A274:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218A278:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82079fd8
	ctx.lr = 0x8218A284;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218a298
	if (ctx.cr6.eq) goto loc_8218A298;
	// bl 0x821895e0
	ctx.lr = 0x8218A290;
	sub_821895E0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218a29c
	goto loc_8218A29C;
loc_8218A298:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218A29C:
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// li r3,452
	ctx.r3.s64 = 452;
	// bl 0x82079fd8
	ctx.lr = 0x8218A2A8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218a2b8
	if (ctx.cr6.eq) goto loc_8218A2B8;
	// bl 0x821954f0
	ctx.lr = 0x8218A2B4;
	sub_821954F0(ctx, base);
	// b 0x8218a2bc
	goto loc_8218A2BC;
loc_8218A2B8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218A2BC:
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
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
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82189880
	ctx.lr = 0x8218A330;
	sub_82189880(ctx, base);
	// lis r6,-32231
	ctx.r6.s64 = -2112290816;
	// addi r5,r6,-24408
	ctx.r5.s64 = ctx.r6.s64 + -24408;
	// stw r5,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8218A354"))) PPC_WEAK_FUNC(sub_8218A354);
PPC_FUNC_IMPL(__imp__sub_8218A354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A358"))) PPC_WEAK_FUNC(sub_8218A358);
PPC_FUNC_IMPL(__imp__sub_8218A358) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218A360;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
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
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r4,r7,4404
	ctx.r4.s64 = ctx.r7.s64 + 4404;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
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
	// stb r9,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r9.u8);
	// stb r9,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r9.u8);
	// stw r30,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// stw r30,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r30.u32);
	// stw r30,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r30.u32);
	// stw r30,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r30.u32);
	// bl 0x82188908
	ctx.lr = 0x8218A404;
	sub_82188908(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r29,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// addi r10,r31,112
	ctx.r10.s64 = ctx.r31.s64 + 112;
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// addi r8,r31,124
	ctx.r8.s64 = ctx.r31.s64 + 124;
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8218A42C:
	// stbx r30,r8,r11
	PPC_STORE_U8(ctx.r8.u32 + ctx.r11.u32, ctx.r30.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwu r30,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r30.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8218a42c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218A42C;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-24040
	ctx.r10.s64 = ctx.r11.s64 + -24040;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218A454"))) PPC_WEAK_FUNC(sub_8218A454);
PPC_FUNC_IMPL(__imp__sub_8218A454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A458"))) PPC_WEAK_FUNC(sub_8218A458);
PPC_FUNC_IMPL(__imp__sub_8218A458) {
	PPC_FUNC_PROLOGUE();
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12640
	ctx.r10.u64 = ctx.r11.u64 | 12640;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218A474"))) PPC_WEAK_FUNC(sub_8218A474);
PPC_FUNC_IMPL(__imp__sub_8218A474) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A478"))) PPC_WEAK_FUNC(sub_8218A478);
PPC_FUNC_IMPL(__imp__sub_8218A478) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218A48C"))) PPC_WEAK_FUNC(sub_8218A48C);
PPC_FUNC_IMPL(__imp__sub_8218A48C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A490"))) PPC_WEAK_FUNC(sub_8218A490);
PPC_FUNC_IMPL(__imp__sub_8218A490) {
	PPC_FUNC_PROLOGUE();
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12632
	ctx.r10.u64 = ctx.r11.u64 | 12632;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218A4AC"))) PPC_WEAK_FUNC(sub_8218A4AC);
PPC_FUNC_IMPL(__imp__sub_8218A4AC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A4B0"))) PPC_WEAK_FUNC(sub_8218A4B0);
PPC_FUNC_IMPL(__imp__sub_8218A4B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218A4C4"))) PPC_WEAK_FUNC(sub_8218A4C4);
PPC_FUNC_IMPL(__imp__sub_8218A4C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A4C8"))) PPC_WEAK_FUNC(sub_8218A4C8);
PPC_FUNC_IMPL(__imp__sub_8218A4C8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// li r5,104
	ctx.r5.s64 = 104;
	// b 0x8207dac0
	sub_8207DAC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218A4EC"))) PPC_WEAK_FUNC(sub_8218A4EC);
PPC_FUNC_IMPL(__imp__sub_8218A4EC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

