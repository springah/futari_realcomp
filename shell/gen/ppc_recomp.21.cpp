#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8212CF54"))) PPC_WEAK_FUNC(sub_8212CF54);
PPC_FUNC_IMPL(__imp__sub_8212CF54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212CF58"))) PPC_WEAK_FUNC(sub_8212CF58);
PPC_FUNC_IMPL(__imp__sub_8212CF58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f11,-22532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -22532);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-22536(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22536);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14000(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212d070
	if (ctx.cr6.lt) goto loc_8212D070;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r4,8
	ctx.r11.s64 = ctx.r4.s64 + 8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8212CF98:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212cfac
	if (!ctx.cr6.lt) goto loc_8212CFAC;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212cfb8
	goto loc_8212CFB8;
loc_8212CFAC:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212cfb8
	if (!ctx.cr6.gt) goto loc_8212CFB8;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212CFB8:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,-4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lhz r9,-10(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sth r9,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r9.u16);
	// bge cr6,0x8212cfe0
	if (!ctx.cr6.lt) goto loc_8212CFE0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212cfec
	goto loc_8212CFEC;
loc_8212CFE0:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212cfec
	if (!ctx.cr6.gt) goto loc_8212CFEC;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212CFEC:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lhz r9,-10(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sth r9,4(r10)
	PPC_STORE_U16(ctx.r10.u32 + 4, ctx.r9.u16);
	// bge cr6,0x8212d014
	if (!ctx.cr6.lt) goto loc_8212D014;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d020
	goto loc_8212D020;
loc_8212D014:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d020
	if (!ctx.cr6.gt) goto loc_8212D020;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D020:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lhz r9,-10(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sth r9,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r9.u16);
	// bge cr6,0x8212d048
	if (!ctx.cr6.lt) goto loc_8212D048;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d054
	goto loc_8212D054;
loc_8212D048:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d054
	if (!ctx.cr6.gt) goto loc_8212D054;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D054:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lhz r9,-10(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sthu r9,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x8212cf98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212CF98;
loc_8212D070:
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r7,r8,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r8.s64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-2
	ctx.r9.s64 = ctx.r11.s64 + -2;
	// add r11,r10,r4
	ctx.r11.u64 = ctx.r10.u64 + ctx.r4.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8212D094:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d0a8
	if (!ctx.cr6.lt) goto loc_8212D0A8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d0b4
	goto loc_8212D0B4;
loc_8212D0A8:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d0b4
	if (!ctx.cr6.gt) goto loc_8212D0B4;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D0B4:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lhz r10,-10(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sthu r10,2(r9)
	ea = 2 + ctx.r9.u32;
	PPC_STORE_U16(ea, ctx.r10.u16);
	ctx.r9.u32 = ea;
	// bdnz 0x8212d094
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D094;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212D0D4"))) PPC_WEAK_FUNC(sub_8212D0D4);
PPC_FUNC_IMPL(__imp__sub_8212D0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212D0D8"))) PPC_WEAK_FUNC(sub_8212D0D8);
PPC_FUNC_IMPL(__imp__sub_8212D0D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f11,-18352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -18352);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f12,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-22528(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22528);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,14000(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212d208
	if (ctx.cr6.lt) goto loc_8212D208;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r4,8
	ctx.r11.s64 = ctx.r4.s64 + 8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8212D120:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d134
	if (!ctx.cr6.lt) goto loc_8212D134;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d140
	goto loc_8212D140;
loc_8212D134:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x8212d140
	if (!ctx.cr6.gt) goto loc_8212D140;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D140:
	// fadds f9,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// lfs f0,-4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fmuls f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f7.u64);
	// lbz r9,-9(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// stb r9,1(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1, ctx.r9.u8);
	// bge cr6,0x8212d16c
	if (!ctx.cr6.lt) goto loc_8212D16C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d178
	goto loc_8212D178;
loc_8212D16C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x8212d178
	if (!ctx.cr6.gt) goto loc_8212D178;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D178:
	// fadds f9,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fmuls f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f7.u64);
	// lbz r9,-9(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// stb r9,2(r10)
	PPC_STORE_U8(ctx.r10.u32 + 2, ctx.r9.u8);
	// bge cr6,0x8212d1a4
	if (!ctx.cr6.lt) goto loc_8212D1A4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d1b0
	goto loc_8212D1B0;
loc_8212D1A4:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x8212d1b0
	if (!ctx.cr6.gt) goto loc_8212D1B0;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D1B0:
	// fadds f9,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fmuls f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f7.u64);
	// lbz r9,-9(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// stb r9,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r9.u8);
	// bge cr6,0x8212d1dc
	if (!ctx.cr6.lt) goto loc_8212D1DC;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d1e8
	goto loc_8212D1E8;
loc_8212D1DC:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x8212d1e8
	if (!ctx.cr6.gt) goto loc_8212D1E8;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D1E8:
	// fadds f0,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// fmuls f9,f0,f11
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f8.u64);
	// lbz r9,-9(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// stbu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8212d120
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D120;
loc_8212D208:
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// subf r10,r8,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8212D220:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d234
	if (!ctx.cr6.lt) goto loc_8212D234;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d240
	goto loc_8212D240;
loc_8212D234:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x8212d240
	if (!ctx.cr6.gt) goto loc_8212D240;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D240:
	// fadds f0,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// fmuls f9,f0,f11
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f8.u64);
	// lbz r10,-9(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + -9);
	// stbx r10,r8,r3
	PPC_STORE_U8(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// bdnz 0x8212d220
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D220;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212D268"))) PPC_WEAK_FUNC(sub_8212D268);
PPC_FUNC_IMPL(__imp__sub_8212D268) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f11,23064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23064);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-22524(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22524);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14000(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212d3d0
	if (ctx.cr6.lt) goto loc_8212D3D0;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r9,r4,8
	ctx.r9.s64 = ctx.r4.s64 + 8;
	// rlwinm r10,r11,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8212D2A8:
	// lfs f0,-8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d2bc
	if (!ctx.cr6.lt) goto loc_8212D2BC;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d2c8
	goto loc_8212D2C8;
loc_8212D2BC:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d2c8
	if (!ctx.cr6.gt) goto loc_8212D2C8;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D2C8:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r6,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 8;
	// stb r7,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r7.u8);
	// srawi r8,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 16;
	// stb r6,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r6.u8);
	// stb r8,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r8.u8);
	// bge cr6,0x8212d304
	if (!ctx.cr6.lt) goto loc_8212D304;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d310
	goto loc_8212D310;
loc_8212D304:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d310
	if (!ctx.cr6.gt) goto loc_8212D310;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D310:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r6,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 8;
	// stb r7,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r7.u8);
	// srawi r8,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 16;
	// stb r6,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r6.u8);
	// stb r8,6(r11)
	PPC_STORE_U8(ctx.r11.u32 + 6, ctx.r8.u8);
	// bge cr6,0x8212d34c
	if (!ctx.cr6.lt) goto loc_8212D34C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d358
	goto loc_8212D358;
loc_8212D34C:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d358
	if (!ctx.cr6.gt) goto loc_8212D358;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D358:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r6,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 8;
	// stb r7,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r7.u8);
	// srawi r8,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 16;
	// stb r6,8(r11)
	PPC_STORE_U8(ctx.r11.u32 + 8, ctx.r6.u8);
	// stb r8,9(r11)
	PPC_STORE_U8(ctx.r11.u32 + 9, ctx.r8.u8);
	// bge cr6,0x8212d394
	if (!ctx.cr6.lt) goto loc_8212D394;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d3a0
	goto loc_8212D3A0;
loc_8212D394:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d3a0
	if (!ctx.cr6.gt) goto loc_8212D3A0;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D3A0:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r6,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 8;
	// stb r7,10(r11)
	PPC_STORE_U8(ctx.r11.u32 + 10, ctx.r7.u8);
	// srawi r8,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 16;
	// stb r6,11(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11, ctx.r6.u8);
	// stbu r8,12(r11)
	ea = 12 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8212d2a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D2A8;
loc_8212D3D0:
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r10,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r10.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8212D3F8:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d40c
	if (!ctx.cr6.lt) goto loc_8212D40C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d418
	goto loc_8212D418;
loc_8212D40C:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d418
	if (!ctx.cr6.gt) goto loc_8212D418;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D418:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r7,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 8;
	// stb r8,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r8.u8);
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// stb r7,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r7.u8);
	// stbu r6,3(r11)
	ea = 3 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8212d3f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D3F8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212D44C"))) PPC_WEAK_FUNC(sub_8212D44C);
PPC_FUNC_IMPL(__imp__sub_8212D44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212D450"))) PPC_WEAK_FUNC(sub_8212D450);
PPC_FUNC_IMPL(__imp__sub_8212D450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f11,-22516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -22516);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-22520(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22520);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14000(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212d5a8
	if (ctx.cr6.lt) goto loc_8212D5A8;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r9,r4,8
	ctx.r9.s64 = ctx.r4.s64 + 8;
	// rlwinm r10,r11,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8212D490:
	// lfs f0,-8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d4a4
	if (!ctx.cr6.lt) goto loc_8212D4A4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d4b0
	goto loc_8212D4B0;
loc_8212D4A4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d4b0
	if (!ctx.cr6.gt) goto loc_8212D4B0;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D4B0:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r7,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 8;
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// stb r8,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r8.u8);
	// stb r7,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r7.u8);
	// stb r6,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r6.u8);
	// bge cr6,0x8212d4e8
	if (!ctx.cr6.lt) goto loc_8212D4E8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d4f4
	goto loc_8212D4F4;
loc_8212D4E8:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d4f4
	if (!ctx.cr6.gt) goto loc_8212D4F4;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D4F4:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r7,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 8;
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// stb r7,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r7.u8);
	// stb r8,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r8.u8);
	// stb r6,6(r11)
	PPC_STORE_U8(ctx.r11.u32 + 6, ctx.r6.u8);
	// bge cr6,0x8212d52c
	if (!ctx.cr6.lt) goto loc_8212D52C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d538
	goto loc_8212D538;
loc_8212D52C:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d538
	if (!ctx.cr6.gt) goto loc_8212D538;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D538:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r7,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 8;
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// stb r7,8(r11)
	PPC_STORE_U8(ctx.r11.u32 + 8, ctx.r7.u8);
	// stb r8,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r8.u8);
	// stb r6,9(r11)
	PPC_STORE_U8(ctx.r11.u32 + 9, ctx.r6.u8);
	// bge cr6,0x8212d570
	if (!ctx.cr6.lt) goto loc_8212D570;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d57c
	goto loc_8212D57C;
loc_8212D570:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d57c
	if (!ctx.cr6.gt) goto loc_8212D57C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D57C:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r8,-12(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r7,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 8;
	// srawi r6,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 16;
	// stb r8,10(r11)
	PPC_STORE_U8(ctx.r11.u32 + 10, ctx.r8.u8);
	// stb r7,11(r11)
	PPC_STORE_U8(ctx.r11.u32 + 11, ctx.r7.u8);
	// stbu r6,12(r11)
	ea = 12 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8212d490
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D490;
loc_8212D5A8:
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r10,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r10.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8212D5D0:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d5e4
	if (!ctx.cr6.lt) goto loc_8212D5E4;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d5f0
	goto loc_8212D5F0;
loc_8212D5E4:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d5f0
	if (!ctx.cr6.gt) goto loc_8212D5F0;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D5F0:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// srawi r8,r9,8
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 8;
	// srawi r7,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 16;
	// stb r8,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r8.u8);
	// stb r9,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r9.u8);
	// stbu r7,3(r11)
	ea = 3 + ctx.r11.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8212d5d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D5D0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212D620"))) PPC_WEAK_FUNC(sub_8212D620);
PPC_FUNC_IMPL(__imp__sub_8212D620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f11,23064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23064);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-22524(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22524);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14000(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212d750
	if (ctx.cr6.lt) goto loc_8212D750;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r9,r4,12
	ctx.r9.s64 = ctx.r4.s64 + 12;
	// rlwinm r10,r11,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r7,r3,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r3.s64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8212D664:
	// lfs f0,-12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d678
	if (!ctx.cr6.lt) goto loc_8212D678;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d684
	goto loc_8212D684;
loc_8212D678:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d684
	if (!ctx.cr6.gt) goto loc_8212D684;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D684:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfsx f0,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,12,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// stw r6,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r6.u32);
	// bge cr6,0x8212d6b0
	if (!ctx.cr6.lt) goto loc_8212D6B0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d6bc
	goto loc_8212D6BC;
loc_8212D6B0:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d6bc
	if (!ctx.cr6.gt) goto loc_8212D6BC;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D6BC:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,12,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// bge cr6,0x8212d6e8
	if (!ctx.cr6.lt) goto loc_8212D6E8;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d6f4
	goto loc_8212D6F4;
loc_8212D6E8:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d6f4
	if (!ctx.cr6.gt) goto loc_8212D6F4;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D6F4:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,12,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// stw r6,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// bge cr6,0x8212d720
	if (!ctx.cr6.lt) goto loc_8212D720;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d72c
	goto loc_8212D72C;
loc_8212D720:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d72c
	if (!ctx.cr6.gt) goto loc_8212D72C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D72C:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,12,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8212d664
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D664;
loc_8212D750:
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// subf r9,r8,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r3,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r3.s64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8212D76C:
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d780
	if (!ctx.cr6.lt) goto loc_8212D780;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d78c
	goto loc_8212D78C;
loc_8212D780:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d78c
	if (!ctx.cr6.gt) goto loc_8212D78C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D78C:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r8,r9,12,0,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFFF000;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8212d76c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D76C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212D7B0"))) PPC_WEAK_FUNC(sub_8212D7B0);
PPC_FUNC_IMPL(__imp__sub_8212D7B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f11,-22516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -22516);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,-22520(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22520);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,14000(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212d8e0
	if (ctx.cr6.lt) goto loc_8212D8E0;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r9,r4,12
	ctx.r9.s64 = ctx.r4.s64 + 12;
	// rlwinm r10,r11,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r7,r3,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r3.s64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8212D7F4:
	// lfs f0,-12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d808
	if (!ctx.cr6.lt) goto loc_8212D808;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d814
	goto loc_8212D814;
loc_8212D808:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d814
	if (!ctx.cr6.gt) goto loc_8212D814;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D814:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfsx f0,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// stw r6,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r6.u32);
	// bge cr6,0x8212d840
	if (!ctx.cr6.lt) goto loc_8212D840;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d84c
	goto loc_8212D84C;
loc_8212D840:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d84c
	if (!ctx.cr6.gt) goto loc_8212D84C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D84C:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// bge cr6,0x8212d878
	if (!ctx.cr6.lt) goto loc_8212D878;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d884
	goto loc_8212D884;
loc_8212D878:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d884
	if (!ctx.cr6.gt) goto loc_8212D884;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D884:
	// fmuls f10,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// stw r6,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// bge cr6,0x8212d8b0
	if (!ctx.cr6.lt) goto loc_8212D8B0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d8bc
	goto loc_8212D8BC;
loc_8212D8B0:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d8bc
	if (!ctx.cr6.gt) goto loc_8212D8BC;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D8BC:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r6,r10,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8212d7f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D7F4;
loc_8212D8E0:
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// subf r9,r8,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r3,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r3.s64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8212D8FC:
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d910
	if (!ctx.cr6.lt) goto loc_8212D910;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d91c
	goto loc_8212D91C;
loc_8212D910:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8212d91c
	if (!ctx.cr6.gt) goto loc_8212D91C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8212D91C:
	// fmuls f0,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fctiwz f10,f0
	ctx.f10.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8212d8fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D8FC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212D940"))) PPC_WEAK_FUNC(sub_8212D940);
PPC_FUNC_IMPL(__imp__sub_8212D940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfd f12,-22504(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + -22504);
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f10,-22520(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22520);
	ctx.f10.f64 = double(temp.f32);
	// lfd f11,-22512(r9)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r9.u32 + -22512);
	// lfs f13,14000(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14000);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x8212da58
	if (ctx.cr6.lt) goto loc_8212DA58;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// addi r9,r4,12
	ctx.r9.s64 = ctx.r4.s64 + 12;
	// rlwinm r10,r11,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r7,r3,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r3.s64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r31,-4
	ctx.r31.s64 = -4;
	// li r6,4
	ctx.r6.s64 = 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,8
	ctx.r10.s64 = 8;
loc_8212D99C:
	// lfs f0,-12(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212d9b0
	if (!ctx.cr6.lt) goto loc_8212D9B0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d9bc
	goto loc_8212D9BC;
loc_8212D9B0:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8212d9bc
	if (!ctx.cr6.gt) goto loc_8212D9BC;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D9BC:
	// fmul f9,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f0.f64 * ctx.f12.f64;
	// lfsx f0,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfiwx f8,r11,r31
	PPC_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.f8.u32);
	// bge cr6,0x8212d9dc
	if (!ctx.cr6.lt) goto loc_8212D9DC;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212d9e8
	goto loc_8212D9E8;
loc_8212D9DC:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8212d9e8
	if (!ctx.cr6.gt) goto loc_8212D9E8;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212D9E8:
	// fmul f9,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f0.f64 * ctx.f12.f64;
	// lfs f0,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfiwx f8,0,r11
	PPC_STORE_U32(ctx.r11.u32, ctx.f8.u32);
	// bge cr6,0x8212da08
	if (!ctx.cr6.lt) goto loc_8212DA08;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212da14
	goto loc_8212DA14;
loc_8212DA08:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8212da14
	if (!ctx.cr6.gt) goto loc_8212DA14;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212DA14:
	// fmul f9,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f0.f64 * ctx.f12.f64;
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfiwx f8,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.f8.u32);
	// bge cr6,0x8212da34
	if (!ctx.cr6.lt) goto loc_8212DA34;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212da40
	goto loc_8212DA40;
loc_8212DA34:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8212da40
	if (!ctx.cr6.gt) goto loc_8212DA40;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212DA40:
	// fmul f0,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 * ctx.f12.f64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fctiwz f9,f0
	ctx.f9.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f9,r11,r10
	PPC_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.f9.u32);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8212d99c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212D99C;
loc_8212DA58:
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x8212daa8
	if (!ctx.cr6.lt) goto loc_8212DAA8;
	// subf r9,r8,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r8.s64;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r3,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r3.s64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8212DA74:
	// lfsx f0,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8212da88
	if (!ctx.cr6.lt) goto loc_8212DA88;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212da94
	goto loc_8212DA94;
loc_8212DA88:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// ble cr6,0x8212da94
	if (!ctx.cr6.gt) goto loc_8212DA94;
	// fmr f0,f10
	ctx.f0.f64 = ctx.f10.f64;
loc_8212DA94:
	// fmul f0,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 * ctx.f12.f64;
	// fctiwz f9,f0
	ctx.f9.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f9,0,r11
	PPC_STORE_U32(ctx.r11.u32, ctx.f9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8212da74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212DA74;
loc_8212DAA8:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DAB0"))) PPC_WEAK_FUNC(sub_8212DAB0);
PPC_FUNC_IMPL(__imp__sub_8212DAB0) {
	PPC_FUNC_PROLOGUE();
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8212db28
	if (ctx.cr6.eq) goto loc_8212DB28;
	// bdz 0x8212dae0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8212DAE0;
	// bdz 0x8212daec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8212DAEC;
	// bdz 0x8212daf8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8212DAF8;
	// bdz 0x8212db04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8212DB04;
	// bdz 0x8212db10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8212DB10;
	// bdz 0x8212db1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8212DB1C;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-12752
	ctx.r3.s64 = ctx.r11.s64 + -12752;
	// blr 
	return;
loc_8212DAE0:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-12456
	ctx.r3.s64 = ctx.r11.s64 + -12456;
	// blr 
	return;
loc_8212DAEC:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-11672
	ctx.r3.s64 = ctx.r11.s64 + -11672;
	// blr 
	return;
loc_8212DAF8:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-10720
	ctx.r3.s64 = ctx.r11.s64 + -10720;
	// blr 
	return;
loc_8212DB04:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-11184
	ctx.r3.s64 = ctx.r11.s64 + -11184;
	// blr 
	return;
loc_8212DB10:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-10320
	ctx.r3.s64 = ctx.r11.s64 + -10320;
	// blr 
	return;
loc_8212DB1C:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-9920
	ctx.r3.s64 = ctx.r11.s64 + -9920;
	// blr 
	return;
loc_8212DB28:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-12072
	ctx.r3.s64 = ctx.r11.s64 + -12072;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DB34"))) PPC_WEAK_FUNC(sub_8212DB34);
PPC_FUNC_IMPL(__imp__sub_8212DB34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212DB38"))) PPC_WEAK_FUNC(sub_8212DB38);
PPC_FUNC_IMPL(__imp__sub_8212DB38) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// addi r3,r11,-27592
	ctx.r3.s64 = ctx.r11.s64 + -27592;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DB44"))) PPC_WEAK_FUNC(sub_8212DB44);
PPC_FUNC_IMPL(__imp__sub_8212DB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212DB48"))) PPC_WEAK_FUNC(sub_8212DB48);
PPC_FUNC_IMPL(__imp__sub_8212DB48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8212DB50;
	__savegprlr_29(ctx, base);
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,-48(r1)
	PPC_STORE_U32(ctx.r1.u32 + -48, ctx.r9.u32);
	// lfs f11,-48(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,-44(r1)
	PPC_STORE_U32(ctx.r1.u32 + -44, ctx.r8.u32);
	// lfs f10,-44(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	ctx.f10.f64 = double(temp.f32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// divwu. r10,r10,r7
	ctx.r10.u32 = ppc_divwu(ctx.r10.u32, ctx.r7.u32);
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// lwz r31,12(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r29,24(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// beq 0x8212dc28
	if (ctx.cr0.eq) goto loc_8212DC28;
	// rlwinm r30,r7,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r3,r11,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r11.s64;
loc_8212DB98:
	// li r11,32
	ctx.r11.s64 = 32;
	// dcbt r6,r11
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8212dc1c
	if (ctx.cr6.eq) goto loc_8212DC1C;
	// subf r8,r9,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r9.s64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// add r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 + ctx.r6.u64;
	// subf r8,r9,r31
	ctx.r8.s64 = ctx.r31.s64 - ctx.r9.s64;
	// subf r5,r9,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r9.s64;
loc_8212DBC0:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// lfsx f0,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// lfsx f9,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fnmsubs f13,f9,f10,f0
	ctx.f13.f64 = double(float(-(ctx.f9.f64 * ctx.f10.f64 - ctx.f0.f64)));
	// fmadds f0,f13,f11,f9
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfsx f0,r8,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, temp.u32);
	// fmadds f12,f0,f11,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// bne cr6,0x8212dbf4
	if (!ctx.cr6.eq) goto loc_8212DBF4;
	// stfsx f13,r5,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r11.u32, temp.u32);
	// b 0x8212dc14
	goto loc_8212DC14;
loc_8212DBF4:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8212dc04
	if (!ctx.cr6.eq) goto loc_8212DC04;
	// stfsx f12,r5,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r11.u32, temp.u32);
	// b 0x8212dc14
	goto loc_8212DC14;
loc_8212DC04:
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// beq cr6,0x8212dc10
	if (ctx.cr6.eq) goto loc_8212DC10;
	// fadds f0,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
loc_8212DC10:
	// stfsx f0,r5,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + ctx.r11.u32, temp.u32);
loc_8212DC14:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8212dbc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212DBC0;
loc_8212DC1C:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r6,r30,r6
	ctx.r6.u64 = ctx.r30.u64 + ctx.r6.u64;
	// bne 0x8212db98
	if (!ctx.cr0.eq) goto loc_8212DB98;
loc_8212DC28:
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8212DC2C"))) PPC_WEAK_FUNC(sub_8212DC2C);
PPC_FUNC_IMPL(__imp__sub_8212DC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212DC30"))) PPC_WEAK_FUNC(sub_8212DC30);
PPC_FUNC_IMPL(__imp__sub_8212DC30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// lfs f11,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f11.f64 = double(temp.f32);
	// stw r9,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f13,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8212dcd0
	if (ctx.cr6.eq) goto loc_8212DCD0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r11.s64;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
loc_8212DC7C:
	// lfsx f12,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fnmsubs f12,f10,f0,f9
	ctx.f12.f64 = double(float(-(ctx.f10.f64 * ctx.f0.f64 - ctx.f9.f64)));
	// fmadds f0,f12,f11,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f0.f64));
	// fmadds f13,f0,f11,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f11.f64 + ctx.f13.f64));
	// dcbt r0,r10
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8212dca4
	if (!ctx.cr6.eq) goto loc_8212DCA4;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8212dcc4
	goto loc_8212DCC4;
loc_8212DCA4:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x8212dcc0
	if (ctx.cr6.eq) goto loc_8212DCC0;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x8212dcbc
	if (!ctx.cr6.eq) goto loc_8212DCBC;
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8212dcc4
	goto loc_8212DCC4;
loc_8212DCBC:
	// fadds f12,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
loc_8212DCC0:
	// stfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_8212DCC4:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r11,16
	ctx.r10.s64 = ctx.r11.s64 + 16;
	// bdnz 0x8212dc7c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212DC7C;
loc_8212DCD0:
	// stfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DCDC"))) PPC_WEAK_FUNC(sub_8212DCDC);
PPC_FUNC_IMPL(__imp__sub_8212DCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212DCE0"))) PPC_WEAK_FUNC(sub_8212DCE0);
PPC_FUNC_IMPL(__imp__sub_8212DCE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r9.u32);
	// lfs f7,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f7.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f13,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8212ddbc
	if (ctx.cr6.eq) goto loc_8212DDBC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r9,4
	ctx.r11.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// subf r9,r9,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r9.s64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// li r8,12
	ctx.r8.s64 = 12;
loc_8212DD44:
	// lfs f9,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// fsubs f5,f8,f10
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// fnmsubs f9,f7,f13,f6
	ctx.f9.f64 = double(float(-(ctx.f7.f64 * ctx.f13.f64 - ctx.f6.f64)));
	// fnmsubs f8,f7,f12,f5
	ctx.f8.f64 = double(float(-(ctx.f7.f64 * ctx.f12.f64 - ctx.f5.f64)));
	// fmadds f13,f9,f0,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f0.f64 + ctx.f13.f64));
	// fmadds f12,f8,f0,f12
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f0.f64 + ctx.f12.f64));
	// fmadds f11,f13,f0,f11
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64 + ctx.f11.f64));
	// fmadds f10,f12,f0,f10
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64 + ctx.f10.f64));
	// dcbt r11,r8
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x8212dd84
	if (!ctx.cr6.eq) goto loc_8212DD84;
	// stfs f11,-4(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8212ddb0
	goto loc_8212DDB0;
loc_8212DD84:
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// beq cr6,0x8212dda8
	if (ctx.cr6.eq) goto loc_8212DDA8;
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// bne cr6,0x8212dda0
	if (!ctx.cr6.eq) goto loc_8212DDA0;
	// stfs f13,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8212ddb0
	goto loc_8212DDB0;
loc_8212DDA0:
	// fadds f9,f11,f9
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f9.f64));
	// fadds f8,f10,f8
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f8.f64));
loc_8212DDA8:
	// stfs f8,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
loc_8212DDB0:
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// bdnz 0x8212dd44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212DD44;
loc_8212DDBC:
	// stfs f11,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f10,4(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f13,0(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f12,4(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DDD0"))) PPC_WEAK_FUNC(sub_8212DDD0);
PPC_FUNC_IMPL(__imp__sub_8212DDD0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bne cr6,0x8212dde4
	if (!ctx.cr6.eq) goto loc_8212DDE4;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-9168
	ctx.r3.s64 = ctx.r11.s64 + -9168;
	// blr 
	return;
loc_8212DDE4:
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// bne cr6,0x8212ddf8
	if (!ctx.cr6.eq) goto loc_8212DDF8;
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-8992
	ctx.r3.s64 = ctx.r11.s64 + -8992;
	// blr 
	return;
loc_8212DDF8:
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// addi r3,r11,-9400
	ctx.r3.s64 = ctx.r11.s64 + -9400;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DE04"))) PPC_WEAK_FUNC(sub_8212DE04);
PPC_FUNC_IMPL(__imp__sub_8212DE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212DE08"))) PPC_WEAK_FUNC(sub_8212DE08);
PPC_FUNC_IMPL(__imp__sub_8212DE08) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 8, ctx.xer);
	// bne cr6,0x8212de48
	if (!ctx.cr6.eq) goto loc_8212DE48;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8212DE14:
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8212de24
	if (ctx.cr6.eq) goto loc_8212DE24;
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// bne cr6,0x8212de68
	if (!ctx.cr6.eq) goto loc_8212DE68;
loc_8212DE24:
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r8,r9,22092
	ctx.r8.s64 = ctx.r9.s64 + 22092;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r11,-3
	ctx.r7.s64 = ctx.r11.s64 + -3;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// blr 
	return;
loc_8212DE48:
	// cmplwi cr6,r4,16
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 16, ctx.xer);
	// bne cr6,0x8212de58
	if (!ctx.cr6.eq) goto loc_8212DE58;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8212de14
	goto loc_8212DE14;
loc_8212DE58:
	// cmplwi cr6,r4,32
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 32, ctx.xer);
	// bne cr6,0x8212de68
	if (!ctx.cr6.eq) goto loc_8212DE68;
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x8212de14
	goto loc_8212DE14;
loc_8212DE68:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DE70"))) PPC_WEAK_FUNC(sub_8212DE70);
PPC_FUNC_IMPL(__imp__sub_8212DE70) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r9,r4,3,13,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7FFF8;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8212dea0
	if (ctx.cr6.lt) goto loc_8212DEA0;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// divw r9,r10,r11
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r11.s32);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// addi r8,r8,-12
	ctx.r8.s64 = ctx.r8.s64 + -12;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// blr 
	return;
loc_8212DEA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DEA8"))) PPC_WEAK_FUNC(sub_8212DEA8);
PPC_FUNC_IMPL(__imp__sub_8212DEA8) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwinm r9,r4,3,13,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0x7FFF8;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8212ded8
	if (ctx.cr6.lt) goto loc_8212DED8;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// divw r9,r10,r11
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r11.s32);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// addi r8,r8,-12
	ctx.r8.s64 = ctx.r8.s64 + -12;
	// clrlwi r11,r8,16
	ctx.r11.u64 = ctx.r8.u32 & 0xFFFF;
	// b 0x8212dedc
	goto loc_8212DEDC;
loc_8212DED8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8212DEDC:
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// add r10,r11,r5
	ctx.r10.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// divwu r3,r10,r11
	ctx.r3.u32 = ppc_divwu(ctx.r10.u32, ctx.r11.u32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mullw r11,r3,r11
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r11.s32);
	// subf r10,r5,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r5.s64;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212DF04"))) PPC_WEAK_FUNC(sub_8212DF04);
PPC_FUNC_IMPL(__imp__sub_8212DF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212DF08"))) PPC_WEAK_FUNC(sub_8212DF08);
PPC_FUNC_IMPL(__imp__sub_8212DF08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f12,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f0,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fmuls f0,f10,f11
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// blt cr6,0x8212dfb4
	if (ctx.cr6.lt) goto loc_8212DFB4;
	// rlwinm r10,r5,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r11,r5,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8212DF44:
	// lfs f10,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f7,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// lfs f5,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// lfs f3,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fmadds f1,f13,f12,f9
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f1,4(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// fmadds f12,f13,f11,f8
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f11,f13,f12,f6
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmadds f9,f13,f11,f4
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f4.f64));
	// fmadds f8,f13,f1,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f8,8(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// fmuls f7,f11,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fmadds f11,f13,f9,f2
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f2.f64));
	// fmadds f5,f13,f8,f7
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f7.f64));
	// stfs f5,12(r4)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// fmadds f12,f13,f5,f6
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f6.f64));
	// bdnz 0x8212df44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212DF44;
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
loc_8212DFB4:
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// subf r11,r11,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r11.s64;
	// lfs f10,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r4,-4
	ctx.r10.s64 = ctx.r4.s64 + -4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f13,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8212DFD8:
	// fmuls f9,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f8,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// stfsu f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmadds f12,f10,f11,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// fmadds f13,f10,f13,f7
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// bdnz 0x8212dfd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212DFD8;
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212E004"))) PPC_WEAK_FUNC(sub_8212E004);
PPC_FUNC_IMPL(__imp__sub_8212E004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212E008"))) PPC_WEAK_FUNC(sub_8212E008);
PPC_FUNC_IMPL(__imp__sub_8212E008) {
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
	// bl 0x8208035c
	ctx.lr = 0x8212E01C;
	__savefpr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fadds f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f25,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f25.f64 = double(temp.f32);
	// lfs f28,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f28.f64 = double(temp.f32);
	// fcmpu cr6,f31,f25
	ctx.cr6.compare(ctx.f31.f64, ctx.f25.f64);
	// bge cr6,0x8212e050
	if (!ctx.cr6.lt) goto loc_8212E050;
	// fdivs f27,f0,f31
	ctx.f27.f64 = double(float(ctx.f0.f64 / ctx.f31.f64));
	// b 0x8212e054
	goto loc_8212E054;
loc_8212E050:
	// fmr f27,f28
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f28.f64;
loc_8212E054:
	// fsubs f12,f28,f27
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f27.f64));
	// lfs f11,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfd f30,19584(r11)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r11.u32 + 19584);
	// lfs f0,22944(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22944);
	ctx.f0.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f13,20700(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20700);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f8,f12,f31
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// fmuls f26,f9,f0
	ctx.f26.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fmuls f2,f8,f13
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212E090;
	sub_8207B7A8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// lfd f29,2072(r8)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r8.u32 + 2072);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x8212E0A4;
	sub_8207B7A8(ctx, base);
	// fmuls f7,f27,f31
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f27.f64 * ctx.f31.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// frsp f31,f1
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f0,23060(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 23060);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f7,f0
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212E0C0;
	sub_8207B7A8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// stfs f1,24(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x8212E0D0;
	sub_8207B7A8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// stfs f6,24(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// lfs f0,-22636(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -22636);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8212e130
	if (!ctx.cr6.lt) goto loc_8212E130;
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// bl 0x8207af40
	ctx.lr = 0x8212E0F0;
	sub_8207AF40(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fsubs f12,f28,f31
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// lfs f0,23040(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f11,f13,f13,f28
	ctx.f11.f64 = double(float(-(ctx.f13.f64 * ctx.f13.f64 - ctx.f28.f64)));
	// fsubs f10,f28,f13
	ctx.f10.f64 = double(float(ctx.f28.f64 - ctx.f13.f64));
	// fnmsubs f9,f13,f31,f28
	ctx.f9.f64 = double(float(-(ctx.f13.f64 * ctx.f31.f64 - ctx.f28.f64)));
	// fmuls f8,f11,f31
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fmuls f7,f10,f31
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fmsubs f5,f7,f0,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f0.f64 - ctx.f6.f64));
	// fsqrts f4,f5
	ctx.f4.f64 = double(float(sqrt(ctx.f5.f64)));
	// fsubs f3,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// fdivs f2,f3,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 / ctx.f12.f64));
	// stfs f2,28(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// b 0x8212e134
	goto loc_8212E134;
loc_8212E130:
	// stfs f25,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
loc_8212E134:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x820803a8
	ctx.lr = 0x8212E140;
	__restfpr_25(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212E150"))) PPC_WEAK_FUNC(sub_8212E150);
PPC_FUNC_IMPL(__imp__sub_8212E150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f12,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r5,4
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 4, ctx.xer);
	// lfs f11,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f9,f0,f13
	ctx.f9.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fmuls f0,f9,f10
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// blt cr6,0x8212e27c
	if (ctx.cr6.lt) goto loc_8212E27C;
	// rlwinm r10,r5,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lfs f10,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r11,r5,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFC;
	// lfs f9,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// fmr f8,f12
	ctx.f8.f64 = ctx.f12.f64;
	// fmr f7,f11
	ctx.f7.f64 = ctx.f11.f64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8212E19C:
	// lfs f6,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmuls f3,f12,f0
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmadds f2,f13,f10,f4
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmadds f11,f13,f8,f5
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f5.f64));
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmuls f10,f2,f0
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fmuls f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmadds f5,f13,f9,f3
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmuls f6,f12,f0
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmadds f4,f13,f7,f1
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f1.f64));
	// stfs f4,0(r4)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmadds f3,f13,f11,f10
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f10.f64));
	// stfs f3,0(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmuls f9,f5,f0
	ctx.f9.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmadds f10,f13,f5,f6
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f6.f64));
	// fmadds f11,f13,f2,f8
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 + ctx.f8.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmadds f6,f13,f4,f9
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + ctx.f9.f64));
	// stfs f6,0(r4)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f7,f13,f10,f12
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f12.f64));
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmadds f8,f13,f11,f1
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fmuls f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f4,f10,f0
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f2,f12,f0
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmadds f11,f13,f6,f4
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fmuls f10,f8,f0
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f9,f7,f0
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// fmadds f1,f13,f3,f5
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + ctx.f5.f64));
	// stfs f1,0(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmuls f6,f12,f0
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmadds f12,f13,f1,f10
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f10.f64));
	// fmadds f11,f13,f11,f9
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f9.f64));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmadds f10,f13,f8,f2
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f2.f64));
	// fmadds f9,f13,f7,f6
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmr f8,f12
	ctx.f8.f64 = ctx.f12.f64;
	// fmr f7,f11
	ctx.f7.f64 = ctx.f11.f64;
	// bdnz 0x8212e19c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212E19C;
	// stfs f12,24(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f10,16(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f9,20(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
loc_8212E27C:
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// subf r11,r11,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r11.s64;
	// lfs f13,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f8,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f7,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f7.f64 = double(temp.f32);
	// lfs f10,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8212E2A4:
	// fmuls f6,f10,f0
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f5,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f12,0(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfsu f12,4(r4)
	ea = 4 + ctx.r4.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f12.f64 = double(temp.f32);
	ctx.r4.u32 = ea;
	// fmuls f3,f12,f0
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f11,0(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmadds f12,f13,f8,f6
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f6.f64));
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// fmadds f11,f13,f7,f4
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f9,f13,f9,f3
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmadds f10,f13,f10,f2
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f2.f64));
	// fmr f8,f12
	ctx.f8.f64 = ctx.f12.f64;
	// fmr f7,f11
	ctx.f7.f64 = ctx.f11.f64;
	// bdnz 0x8212e2a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212E2A4;
	// stfs f10,16(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f9,20(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f12,24(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212E2F8"))) PPC_WEAK_FUNC(sub_8212E2F8);
PPC_FUNC_IMPL(__imp__sub_8212E2F8) {
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
	// bl 0x8208035c
	ctx.lr = 0x8212E30C;
	__savefpr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fadds f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f25,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f25.f64 = double(temp.f32);
	// lfs f28,14004(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14004);
	ctx.f28.f64 = double(temp.f32);
	// fcmpu cr6,f31,f25
	ctx.cr6.compare(ctx.f31.f64, ctx.f25.f64);
	// bge cr6,0x8212e340
	if (!ctx.cr6.lt) goto loc_8212E340;
	// fdivs f27,f0,f31
	ctx.f27.f64 = double(float(ctx.f0.f64 / ctx.f31.f64));
	// b 0x8212e344
	goto loc_8212E344;
loc_8212E340:
	// fmr f27,f28
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f28.f64;
loc_8212E344:
	// fsubs f12,f28,f27
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f27.f64));
	// lfs f11,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fdivs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfd f30,19584(r11)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r11.u32 + 19584);
	// lfs f0,22944(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22944);
	ctx.f0.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f13,20700(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20700);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f8,f12,f31
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// fmuls f26,f9,f0
	ctx.f26.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fmuls f2,f8,f13
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212E380;
	sub_8207B7A8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// lfd f29,2072(r8)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r8.u32 + 2072);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x8212E394;
	sub_8207B7A8(ctx, base);
	// fmuls f7,f27,f31
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f27.f64 * ctx.f31.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// frsp f31,f1
	ctx.f31.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f0,23060(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 23060);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f7,f0
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212E3B0;
	sub_8207B7A8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// stfs f1,32(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x8212E3C0;
	sub_8207B7A8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// stfs f6,32(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lfs f0,-22636(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -22636);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8212e420
	if (!ctx.cr6.lt) goto loc_8212E420;
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// bl 0x8207af40
	ctx.lr = 0x8212E3E0;
	sub_8207AF40(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fsubs f12,f28,f31
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// lfs f0,23040(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f11,f13,f13,f28
	ctx.f11.f64 = double(float(-(ctx.f13.f64 * ctx.f13.f64 - ctx.f28.f64)));
	// fsubs f10,f28,f13
	ctx.f10.f64 = double(float(ctx.f28.f64 - ctx.f13.f64));
	// fnmsubs f9,f13,f31,f28
	ctx.f9.f64 = double(float(-(ctx.f13.f64 * ctx.f31.f64 - ctx.f28.f64)));
	// fmuls f8,f11,f31
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fmuls f7,f10,f31
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fmsubs f5,f7,f0,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f0.f64 - ctx.f6.f64));
	// fsqrts f4,f5
	ctx.f4.f64 = double(float(sqrt(ctx.f5.f64)));
	// fsubs f3,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// fdivs f2,f3,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 / ctx.f12.f64));
	// stfs f2,36(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// b 0x8212e424
	goto loc_8212E424;
loc_8212E420:
	// stfs f25,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
loc_8212E424:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x820803a8
	ctx.lr = 0x8212E430;
	__restfpr_25(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212E440"))) PPC_WEAK_FUNC(sub_8212E440);
PPC_FUNC_IMPL(__imp__sub_8212E440) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bne cr6,0x8212e454
	if (!ctx.cr6.eq) goto loc_8212E454;
	// lis r3,3
	ctx.r3.s64 = 196608;
	// ori r3,r3,22960
	ctx.r3.u64 = ctx.r3.u64 | 22960;
	// blr 
	return;
loc_8212E454:
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// lis r3,5
	ctx.r3.s64 = 327680;
	// bne cr6,0x8212e468
	if (!ctx.cr6.eq) goto loc_8212E468;
	// ori r3,r3,45284
	ctx.r3.u64 = ctx.r3.u64 | 45284;
	// blr 
	return;
loc_8212E468:
	// ori r3,r3,51508
	ctx.r3.u64 = ctx.r3.u64 | 51508;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8212E470"))) PPC_WEAK_FUNC(sub_8212E470);
PPC_FUNC_IMPL(__imp__sub_8212E470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x8212E478;
	__savegprlr_19(ctx, base);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r27,r27,24
	ctx.r27.s64 = ctx.r27.s64 + 24;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,-19288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19288);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// lis r31,1
	ctx.r31.s64 = 65536;
	// lfs f12,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lfs f0,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f13.f64 = double(temp.f32);
	// ori r24,r8,20
	ctx.r24.u64 = ctx.r8.u64 | 20;
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// ori r25,r7,8
	ctx.r25.u64 = ctx.r7.u64 | 8;
	// ori r26,r31,4
	ctx.r26.u64 = ctx.r31.u64 | 4;
	// lis r21,1
	ctx.r21.s64 = 65536;
	// ori r20,r11,12
	ctx.r20.u64 = ctx.r11.u64 | 12;
	// li r23,1
	ctx.r23.s64 = 1;
	// cmpwi cr6,r6,4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 4, ctx.xer);
	// blt cr6,0x8212e72c
	if (ctx.cr6.lt) goto loc_8212E72C;
	// rlwinm r11,r6,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r6,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// add r10,r3,r24
	ctx.r10.u64 = ctx.r3.u64 + ctx.r24.u64;
	// add r8,r3,r25
	ctx.r8.u64 = ctx.r3.u64 + ctx.r25.u64;
	// add r7,r3,r26
	ctx.r7.u64 = ctx.r3.u64 + ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// add r11,r3,r21
	ctx.r11.u64 = ctx.r3.u64 + ctx.r21.u64;
	// addi r28,r4,8
	ctx.r28.s64 = ctx.r4.s64 + 8;
	// addi r31,r5,12
	ctx.r31.s64 = ctx.r5.s64 + 12;
	// subf r22,r5,r4
	ctx.r22.s64 = ctx.r4.s64 - ctx.r5.s64;
	// addi r23,r9,1
	ctx.r23.s64 = ctx.r9.s64 + 1;
loc_8212E4FC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r29,0(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// subf r29,r29,r9
	ctx.r29.s64 = ctx.r9.s64 - ctx.r29.s64;
	// subf r19,r30,r9
	ctx.r19.s64 = ctx.r9.s64 - ctx.r30.s64;
	// rlwinm r29,r29,2,16,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFC;
	// rlwinm r19,r19,2,16,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r29,r3
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfsx f7,r19,r3
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r3.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f7,f10,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f6,-8(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + -8, temp.u32);
	// stfs f6,0(r27)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// ble cr6,0x8212e548
	if (!ctx.cr6.gt) goto loc_8212E548;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x8212e568
	goto loc_8212E568;
loc_8212E548:
	// lwzx r29,r3,r20
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r20.u32);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8212e55c
	if (ctx.cr6.eq) goto loc_8212E55C;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212e560
	goto loc_8212E560;
loc_8212E55C:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8212E560:
	// stw r30,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
loc_8212E568:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,-8(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r9,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r29,0(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// clrlwi r9,r9,18
	ctx.r9.u64 = ctx.r9.u32 & 0x3FFF;
	// subf r19,r30,r9
	ctx.r19.s64 = ctx.r9.s64 - ctx.r30.s64;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// subf r29,r29,r9
	ctx.r29.s64 = ctx.r9.s64 - ctx.r29.s64;
	// rlwinm r19,r19,2,16,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFC;
	// rlwinm r29,r29,2,16,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r19,r3
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r29,r3
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmadds f6,f9,f10,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f6,-4(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + -4, temp.u32);
	// stfs f6,0(r27)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// ble cr6,0x8212e5d0
	if (!ctx.cr6.gt) goto loc_8212E5D0;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x8212e5f0
	goto loc_8212E5F0;
loc_8212E5D0:
	// lwzx r29,r3,r20
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r20.u32);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8212e5e4
	if (ctx.cr6.eq) goto loc_8212E5E4;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212e5e8
	goto loc_8212E5E8;
loc_8212E5E4:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8212E5E8:
	// stw r30,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
loc_8212E5F0:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,-4(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r9,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, temp.u32);
	// lwz r29,0(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// lwz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r9,18
	ctx.r9.u64 = ctx.r9.u32 & 0x3FFF;
	// subf r19,r30,r9
	ctx.r19.s64 = ctx.r9.s64 - ctx.r30.s64;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// subf r29,r29,r9
	ctx.r29.s64 = ctx.r9.s64 - ctx.r29.s64;
	// rlwinm r19,r19,2,16,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFC;
	// rlwinm r29,r29,2,16,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r19,r3
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r29,r3
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmadds f6,f9,f10,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f6,0(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f6,0(r27)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// ble cr6,0x8212e658
	if (!ctx.cr6.gt) goto loc_8212E658;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x8212e678
	goto loc_8212E678;
loc_8212E658:
	// lwzx r29,r3,r20
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r20.u32);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8212e66c
	if (ctx.cr6.eq) goto loc_8212E66C;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212e670
	goto loc_8212E670;
loc_8212E66C:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8212E670:
	// stw r30,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
loc_8212E678:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,0(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r9,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, temp.u32);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// lwz r29,0(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r9,r9,18
	ctx.r9.u64 = ctx.r9.u32 & 0x3FFF;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// subf r29,r29,r9
	ctx.r29.s64 = ctx.r9.s64 - ctx.r29.s64;
	// subf r19,r30,r9
	ctx.r19.s64 = ctx.r9.s64 - ctx.r30.s64;
	// rlwinm r29,r29,2,16,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFC;
	// rlwinm r19,r19,2,16,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r29,r3
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfsx f7,r19,r3
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + ctx.r3.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f7,f10,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f6,4(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f6,0(r27)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// ble cr6,0x8212e6e0
	if (!ctx.cr6.gt) goto loc_8212E6E0;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x8212e700
	goto loc_8212E700;
loc_8212E6E0:
	// lwzx r29,r3,r20
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r20.u32);
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8212e6f4
	if (ctx.cr6.eq) goto loc_8212E6F4;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212e6f8
	goto loc_8212E6F8;
loc_8212E6F4:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8212E6F8:
	// stw r30,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r30.u32);
	// stw r29,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
loc_8212E700:
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfsx f0,r22,r31
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// stfsx f0,r9,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r9,18
	ctx.r9.u64 = ctx.r9.u32 & 0x3FFF;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// bdnz 0x8212e4fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212E4FC;
loc_8212E72C:
	// cmplw cr6,r23,r6
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r6.u32, ctx.xer);
	// bgt cr6,0x8212e7f4
	if (ctx.cr6.gt) goto loc_8212E7F4;
	// subf r10,r23,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r23.s64;
	// rlwinm r11,r23,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r7,r11,r4
	ctx.r7.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r9,r11,r5
	ctx.r9.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r6,r3,r24
	ctx.r6.u64 = ctx.r3.u64 + ctx.r24.u64;
	// add r4,r3,r25
	ctx.r4.u64 = ctx.r3.u64 + ctx.r25.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r31,r3,r26
	ctx.r31.u64 = ctx.r3.u64 + ctx.r26.u64;
	// add r8,r3,r21
	ctx.r8.u64 = ctx.r3.u64 + ctx.r21.u64;
	// addi r5,r7,-8
	ctx.r5.s64 = ctx.r7.s64 + -8;
loc_8212E760:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// subf r7,r7,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r7.s64;
	// subf r30,r11,r10
	ctx.r30.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r7,r7,2,16,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFC;
	// rlwinm r30,r30,2,16,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFC;
	// lfsx f9,r7,r3
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfsx f7,r30,r3
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f7,f10,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f6,0(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f6,0(r27)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// ble cr6,0x8212e7ac
	if (!ctx.cr6.gt) goto loc_8212E7AC;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x8212e7cc
	goto loc_8212E7CC;
loc_8212E7AC:
	// lwzx r7,r3,r20
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r20.u32);
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8212e7c0
	if (ctx.cr6.eq) goto loc_8212E7C0;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212e7c4
	goto loc_8212E7C4;
loc_8212E7C0:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8212E7C4:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
loc_8212E7CC:
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// lfsu f0,4(r5)
	ea = 4 + ctx.r5.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r5.u32 = ea;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfsx f0,r11,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r7,r10,18
	ctx.r7.u64 = ctx.r10.u32 & 0x3FFF;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// bdnz 0x8212e760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212E760;
loc_8212E7F4:
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8212E7F8"))) PPC_WEAK_FUNC(sub_8212E7F8);
PPC_FUNC_IMPL(__imp__sub_8212E7F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8212E800;
	__savegprlr_25(ctx, base);
	// addis r28,r3,2
	ctx.r28.s64 = ctx.r3.s64 + 131072;
	// addis r27,r3,2
	ctx.r27.s64 = ctx.r3.s64 + 131072;
	// addi r28,r28,24
	ctx.r28.s64 = ctx.r28.s64 + 24;
	// addi r27,r27,28
	ctx.r27.s64 = ctx.r27.s64 + 28;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// blt cr6,0x8212e948
	if (ctx.cr6.lt) goto loc_8212E948;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addis r31,r3,2
	ctx.r31.s64 = ctx.r3.s64 + 131072;
	// addis r30,r3,2
	ctx.r30.s64 = ctx.r3.s64 + 131072;
	// addis r29,r3,2
	ctx.r29.s64 = ctx.r3.s64 + 131072;
	// lfs f11,-19288(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19288);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lfs f12,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r5,8
	ctx.r6.s64 = ctx.r5.s64 + 8;
	// lfs f13,14004(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14004);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r4,-4
	ctx.r5.s64 = ctx.r4.s64 + -4;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addis r9,r3,2
	ctx.r9.s64 = ctx.r3.s64 + 131072;
	// ori r4,r7,12
	ctx.r4.u64 = ctx.r7.u64 | 12;
loc_8212E870:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// subf r11,r11,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r11.s64;
	// subf r10,r7,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r26,r11,-1
	ctx.r26.s64 = ctx.r11.s64 + -1;
	// rlwinm r11,r11,2,15,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0x1FFFC;
	// rlwinm r26,r26,2,15,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0x1FFFC;
	// addi r25,r10,-1
	ctx.r25.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r10,2,15,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x1FFFC;
	// rlwinm r25,r25,2,15,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0x1FFFC;
	// lfsx f9,r11,r3
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r26,r3
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r3.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fmuls f6,f0,f8
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f8.f64));
	// lfsx f5,r10,r3
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r25,r3
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + ctx.r3.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f5,f10,f7
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f3,0(r6)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmadds f2,f10,f4,f6
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f4.f64 + ctx.f6.f64));
	// stfs f3,0(r28)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// stfs f2,4(r6)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f2,0(r27)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// ble cr6,0x8212e8e4
	if (!ctx.cr6.gt) goto loc_8212E8E4;
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// b 0x8212e904
	goto loc_8212E904;
loc_8212E8E4:
	// lwzx r11,r3,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8212e8f8
	if (ctx.cr6.eq) goto loc_8212E8F8;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8212e8fc
	goto loc_8212E8FC;
loc_8212E8F8:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_8212E8FC:
	// stw r7,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r7.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8212E904:
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f10,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// lfsu f0,8(r5)
	ea = 8 + ctx.r5.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r5.u32 = ea;
	// stfsx f10,r11,r3
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r8,r10,17
	ctx.r8.u64 = ctx.r10.u32 & 0x7FFF;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stfsx f0,r7,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,17
	ctx.r10.u64 = ctx.r11.u32 & 0x7FFF;
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// bdnz 0x8212e870
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8212E870;
loc_8212E948:
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8212E94C"))) PPC_WEAK_FUNC(sub_8212E94C);
PPC_FUNC_IMPL(__imp__sub_8212E94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212E950"))) PPC_WEAK_FUNC(sub_8212E950);
PPC_FUNC_IMPL(__imp__sub_8212E950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x8212E958;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82080344
	ctx.lr = 0x8212E960;
	__savefpr_19(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f19,-19184(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19184);
	ctx.f19.f64 = double(temp.f32);
	// bne cr6,0x8212e988
	if (!ctx.cr6.eq) goto loc_8212E988;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8212e9ac
	goto loc_8212E9AC;
loc_8212E988:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f19
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f19.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8212E9AC:
	// bl 0x8214dc28
	ctx.lr = 0x8212E9B0;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,4095
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4095, ctx.xer);
	// ble cr6,0x8212e9bc
	if (!ctx.cr6.gt) goto loc_8212E9BC;
	// li r3,4095
	ctx.r3.s64 = 4095;
loc_8212E9BC:
	// lis r11,2
	ctx.r11.s64 = 131072;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// ori r7,r11,39100
	ctx.r7.u64 = ctx.r11.u64 | 39100;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// ori r6,r10,18772
	ctx.r6.u64 = ctx.r10.u64 | 18772;
	// ori r5,r9,38784
	ctx.r5.u64 = ctx.r9.u64 | 38784;
	// stwx r3,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// ori r4,r8,59432
	ctx.r4.u64 = ctx.r8.u64 | 59432;
	// addi r30,r11,-22496
	ctx.r30.s64 = ctx.r11.s64 + -22496;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stwx r3,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stwx r3,r31,r5
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r3.u32);
	// addi r11,r11,22044
	ctx.r11.s64 = ctx.r11.s64 + 22044;
	// stwx r3,r31,r4
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lwz r8,80(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-22612(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22612);
	ctx.f11.f64 = double(temp.f32);
	// lfs f21,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f21.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// lfs f20,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f20.f64 = double(temp.f32);
	// blt cr6,0x8212ea30
	if (ctx.cr6.lt) goto loc_8212EA30;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-22624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22624);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8212ea48
	goto loc_8212EA48;
loc_8212EA30:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f12,26636(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 26636);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f13,f0,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64 + ctx.f12.f64));
	// lfs f0,-22624(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22624);
	ctx.f0.f64 = double(temp.f32);
loc_8212EA48:
	// fmuls f25,f13,f20
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = double(float(ctx.f13.f64 * ctx.f20.f64));
	// fcmpu cr6,f25,f0
	ctx.cr6.compare(ctx.f25.f64, ctx.f0.f64);
	// bge cr6,0x8212ea58
	if (!ctx.cr6.lt) goto loc_8212EA58;
	// fmr f25,f0
	ctx.f25.f64 = ctx.f0.f64;
loc_8212EA58:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,23040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f30,f25,f13
	ctx.f30.f64 = double(float(ctx.f25.f64 * ctx.f13.f64));
	// fcmpu cr6,f30,f0
	ctx.cr6.compare(ctx.f30.f64, ctx.f0.f64);
	// bge cr6,0x8212ea74
	if (!ctx.cr6.lt) goto loc_8212EA74;
	// fmr f30,f0
	ctx.f30.f64 = ctx.f0.f64;
	// b 0x8212ea80
	goto loc_8212EA80;
loc_8212EA74:
	// fcmpu cr6,f30,f21
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f21.f64);
	// ble cr6,0x8212ea80
	if (!ctx.cr6.gt) goto loc_8212EA80;
	// fmr f30,f21
	ctx.f30.f64 = ctx.f21.f64;
loc_8212EA80:
	// lwz r11,76(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,-19188(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19188);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8212eabc
	if (ctx.cr6.lt) goto loc_8212EABC;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// fmr f29,f21
	ctx.f29.f64 = ctx.f21.f64;
	// fmr f28,f21
	ctx.f28.f64 = ctx.f21.f64;
	// fmr f27,f21
	ctx.f27.f64 = ctx.f21.f64;
	// lfs f0,-19192(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19192);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x8212eb24
	goto loc_8212EB24;
loc_8212EABC:
	// fcmpu cr6,f0,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// blt cr6,0x8212eae8
	if (ctx.cr6.lt) goto loc_8212EAE8;
	// fsubs f13,f0,f11
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,-19192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19192);
	ctx.f0.f64 = double(temp.f32);
	// fmr f28,f21
	ctx.f28.f64 = ctx.f21.f64;
	// fmr f27,f21
	ctx.f27.f64 = ctx.f21.f64;
	// lfs f31,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f29,f13,f0
	ctx.f29.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x8212eb24
	goto loc_8212EB24;
loc_8212EAE8:
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfs f13,-19196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19196);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfs f31,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// fmr f29,f31
	ctx.f29.f64 = ctx.f31.f64;
	// blt cr6,0x8212eb18
	if (ctx.cr6.lt) goto loc_8212EB18;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f0,-19192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19192);
	ctx.f0.f64 = double(temp.f32);
	// fmr f27,f21
	ctx.f27.f64 = ctx.f21.f64;
	// fmuls f28,f13,f0
	ctx.f28.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x8212eb24
	goto loc_8212EB24;
loc_8212EB18:
	// lfs f13,-19192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19192);
	ctx.f13.f64 = double(temp.f32);
	// fmr f28,f31
	ctx.f28.f64 = ctx.f31.f64;
	// fmuls f27,f0,f13
	ctx.f27.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
loc_8212EB24:
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfs f0,-19200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19200);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EB40;
	sub_8214DC28(ctx, base);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r10,2128
	ctx.r8.u64 = ctx.r10.u64 | 2128;
	// ori r7,r9,2132
	ctx.r7.u64 = ctx.r9.u64 | 2132;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stwx r3,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u32);
	// lfs f0,-19204(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19204);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f30,f0
	ctx.f12.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EB78;
	sub_8214DC28(ctx, base);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r10,r5,10896
	ctx.r10.u64 = ctx.r5.u64 | 10896;
	// ori r9,r4,10900
	ctx.r9.u64 = ctx.r4.u64 | 10900;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// stwx r3,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// stwx r11,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// subfic r7,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r6,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwinm r11,r11,0,28,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// addi r11,r11,1020
	ctx.r11.s64 = ctx.r11.s64 + 1020;
	// clrldi r5,r11,32
	ctx.r5.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f30.f64));
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EBD4;
	sub_8214DC28(ctx, base);
	// lis r4,1
	ctx.r4.s64 = 65536;
	// fmuls f26,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f26.f64 = double(float(ctx.f31.f64 * ctx.f30.f64));
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// ori r10,r4,18152
	ctx.r10.u64 = ctx.r4.u64 | 18152;
	// lfs f0,-19208(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19208);
	ctx.f0.f64 = double(temp.f32);
	// stwx r3,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// fmuls f5,f26,f0
	ctx.f5.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EC00;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ec0c
	if (!ctx.cr6.eq) goto loc_8212EC0C;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EC0C:
	// addis r21,r31,1
	ctx.r21.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r21,r21,18176
	ctx.r21.s64 = ctx.r21.s64 + 18176;
	// lfs f0,-19212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19212);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,2048(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2048);
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stw r3,2056(r21)
	PPC_STORE_U32(ctx.r21.u32 + 2056, ctx.r3.u32);
	// subf r9,r3,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r3.s64;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// stw r8,2052(r21)
	PPC_STORE_U32(ctx.r21.u32 + 2052, ctx.r8.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EC44;
	sub_8214DC28(ctx, base);
	// addis r20,r31,1
	ctx.r20.s64 = ctx.r31.s64 + 65536;
	// addi r20,r20,20248
	ctx.r20.s64 = ctx.r20.s64 + 20248;
	// fmuls f12,f31,f25
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f25.f64));
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r7,2048(r20)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// stw r3,2056(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2056, ctx.r3.u32);
	// lfs f0,-19216(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19216);
	ctx.f0.f64 = double(temp.f32);
	// subf r5,r3,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r3.s64;
	// clrlwi r4,r5,23
	ctx.r4.u64 = ctx.r5.u32 & 0x1FF;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stw r4,2052(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2052, ctx.r4.u32);
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EC80;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ec8c
	if (!ctx.cr6.eq) goto loc_8212EC8C;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EC8C:
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addis r26,r31,2
	ctx.r26.s64 = ctx.r31.s64 + 131072;
	// addi r26,r26,-26756
	ctx.r26.s64 = ctx.r26.s64 + -26756;
	// lfs f0,-19220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19220);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f26,f0
	ctx.f0.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// stw r3,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r3.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212ECB4;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ecc0
	if (!ctx.cr6.eq) goto loc_8212ECC0;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212ECC0:
	// addis r22,r31,2
	ctx.r22.s64 = ctx.r31.s64 + 131072;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r22,r22,-26712
	ctx.r22.s64 = ctx.r22.s64 + -26712;
	// lfs f0,-19224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19224);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,2048(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2048);
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stw r3,2056(r22)
	PPC_STORE_U32(ctx.r22.u32 + 2056, ctx.r3.u32);
	// subf r9,r3,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r3.s64;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// stw r8,2052(r22)
	PPC_STORE_U32(ctx.r22.u32 + 2052, ctx.r8.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212ECF8;
	sub_8214DC28(ctx, base);
	// addis r23,r31,2
	ctx.r23.s64 = ctx.r31.s64 + 131072;
	// addi r23,r23,-24640
	ctx.r23.s64 = ctx.r23.s64 + -24640;
	// fmuls f12,f29,f25
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f29.f64 * ctx.f25.f64));
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r7,2048(r23)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r23.u32 + 2048);
	// stw r3,2056(r23)
	PPC_STORE_U32(ctx.r23.u32 + 2056, ctx.r3.u32);
	// lfs f0,-19228(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19228);
	ctx.f0.f64 = double(temp.f32);
	// subf r5,r3,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r3.s64;
	// clrlwi r4,r5,23
	ctx.r4.u64 = ctx.r5.u32 & 0x1FF;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stw r4,2052(r23)
	PPC_STORE_U32(ctx.r23.u32 + 2052, ctx.r4.u32);
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212ED34;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ed40
	if (!ctx.cr6.eq) goto loc_8212ED40;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212ED40:
	// fmuls f28,f28,f30
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f30.f64));
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addis r27,r31,2
	ctx.r27.s64 = ctx.r31.s64 + 131072;
	// addi r27,r27,-6108
	ctx.r27.s64 = ctx.r27.s64 + -6108;
	// lfs f0,-19232(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19232);
	ctx.f0.f64 = double(temp.f32);
	// stw r3,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// fmuls f0,f28,f0
	ctx.f0.f64 = double(float(ctx.f28.f64 * ctx.f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212ED6C;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ed78
	if (!ctx.cr6.eq) goto loc_8212ED78;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212ED78:
	// fmuls f31,f29,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f29.f64 * ctx.f30.f64));
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addis r11,r31,2
	ctx.r11.s64 = ctx.r31.s64 + 131072;
	// addi r11,r11,-6064
	ctx.r11.s64 = ctx.r11.s64 + -6064;
	// lfs f0,-19236(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19236);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,8192(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8192);
	// stw r3,8200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8200, ctx.r3.u32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// subf r8,r3,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r3.s64;
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// stw r7,8196(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8196, ctx.r7.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EDB4;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212edc0
	if (!ctx.cr6.eq) goto loc_8212EDC0;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EDC0:
	// addis r9,r31,2
	ctx.r9.s64 = ctx.r31.s64 + 131072;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// addi r9,r9,2152
	ctx.r9.s64 = ctx.r9.s64 + 2152;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r8,8192(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8192);
	// stw r11,8200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8200, ctx.r11.u32);
	// lfs f0,-19240(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19240);
	ctx.f0.f64 = double(temp.f32);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// clrlwi r6,r7,21
	ctx.r6.u64 = ctx.r7.u32 & 0x7FF;
	// stw r6,8196(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8196, ctx.r6.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EDFC;
	sub_8214DC28(ctx, base);
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// addi r5,r5,10372
	ctx.r5.s64 = ctx.r5.s64 + 10372;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lwz r11,8192(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8192);
	// stw r3,8200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8200, ctx.r3.u32);
	// lfs f0,-19244(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19244);
	ctx.f0.f64 = double(temp.f32);
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// fmuls f12,f26,f0
	ctx.f12.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// clrlwi r9,r10,21
	ctx.r9.u64 = ctx.r10.u32 & 0x7FF;
	// stw r9,8196(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8196, ctx.r9.u32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EE34;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ee40
	if (!ctx.cr6.eq) goto loc_8212EE40;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EE40:
	// addis r24,r31,2
	ctx.r24.s64 = ctx.r31.s64 + 131072;
	// fmuls f13,f27,f25
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f27.f64 * ctx.f25.f64));
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r24,r24,18588
	ctx.r24.s64 = ctx.r24.s64 + 18588;
	// lfs f0,-19248(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19248);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4096(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4096);
	// stw r3,4104(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4104, ctx.r3.u32);
	// subf r9,r3,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r3.s64;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// clrlwi r8,r9,22
	ctx.r8.u64 = ctx.r9.u32 & 0x3FF;
	// stw r8,4100(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4100, ctx.r8.u32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EE7C;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ee88
	if (!ctx.cr6.eq) goto loc_8212EE88;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EE88:
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r28,r28,-26440
	ctx.r28.s64 = ctx.r28.s64 + -26440;
	// lfs f0,-19252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19252);
	ctx.f0.f64 = double(temp.f32);
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// fmuls f0,f28,f0
	ctx.f0.f64 = double(float(ctx.f28.f64 * ctx.f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EEB0;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212eebc
	if (!ctx.cr6.eq) goto loc_8212EEBC;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EEBC:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// addi r11,r11,-26392
	ctx.r11.s64 = ctx.r11.s64 + -26392;
	// lfs f0,-19256(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19256);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lwz r9,8192(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8192);
	// stw r3,8200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8200, ctx.r3.u32);
	// subf r8,r3,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r3.s64;
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// stw r7,8196(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8196, ctx.r7.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EEF4;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ef00
	if (!ctx.cr6.eq) goto loc_8212EF00;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EF00:
	// addis r10,r31,3
	ctx.r10.s64 = ctx.r31.s64 + 196608;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r10,r10,-18176
	ctx.r10.s64 = ctx.r10.s64 + -18176;
	// lfs f0,-19260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19260);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,8192(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// fmuls f0,f26,f0
	ctx.f0.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// stw r3,8200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8200, ctx.r3.u32);
	// subf r8,r3,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r3.s64;
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// stw r7,8196(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8196, ctx.r7.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EF38;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212ef44
	if (!ctx.cr6.eq) goto loc_8212EF44;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EF44:
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addis r10,r31,3
	ctx.r10.s64 = ctx.r31.s64 + 196608;
	// addi r10,r10,-9956
	ctx.r10.s64 = ctx.r10.s64 + -9956;
	// lfs f0,-19264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19264);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f26,f0
	ctx.f0.f64 = double(float(ctx.f26.f64 * ctx.f0.f64));
	// lwz r9,8192(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// stw r3,8200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8200, ctx.r3.u32);
	// subf r8,r3,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r3.s64;
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// stw r7,8196(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8196, ctx.r7.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EF7C;
	sub_8214DC28(ctx, base);
	// addis r25,r31,3
	ctx.r25.s64 = ctx.r31.s64 + 196608;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r25,r25,-1740
	ctx.r25.s64 = ctx.r25.s64 + -1740;
	// lfs f0,-19268(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19268);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,4096(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4096);
	// fmuls f12,f25,f0
	ctx.f12.f64 = double(float(ctx.f25.f64 * ctx.f0.f64));
	// stw r3,4104(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4104, ctx.r3.u32);
	// subf r4,r3,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r3.s64;
	// clrlwi r3,r4,22
	ctx.r3.u64 = ctx.r4.u32 & 0x3FF;
	// stw r3,4100(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4100, ctx.r3.u32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212EFB4;
	sub_8214DC28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8212efc0
	if (!ctx.cr6.eq) goto loc_8212EFC0;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8212EFC0:
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lis r11,2
	ctx.r11.s64 = 131072;
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// ori r8,r10,55560
	ctx.r8.u64 = ctx.r10.u64 | 55560;
	// lwz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// ori r9,r11,63780
	ctx.r9.u64 = ctx.r11.u64 | 63780;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r7,r7,22692
	ctx.r7.u64 = ctx.r7.u64 | 22692;
	// ori r28,r11,22304
	ctx.r28.u64 = ctx.r11.u64 | 22304;
	// lwzx r11,r31,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwzx r10,r31,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// lis r27,2
	ctx.r27.s64 = 131072;
	// lwzx r9,r31,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r7,r8,20232
	ctx.r7.u64 = ctx.r8.u64 | 20232;
	// lwzx r10,r31,r28
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ori r28,r27,18572
	ctx.r28.u64 = ctx.r27.u64 | 18572;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwzx r8,r31,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	// ori r7,r9,47344
	ctx.r7.u64 = ctx.r9.u64 | 47344;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r9,r31,r28
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// ori r8,r10,10352
	ctx.r8.u64 = ctx.r10.u64 | 10352;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r7,r31,r7
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	// lis r28,1
	ctx.r28.s64 = 65536;
	// ori r9,r10,42952
	ctx.r9.u64 = ctx.r10.u64 | 42952;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwzx r10,r31,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// ori r7,r28,40880
	ctx.r7.u64 = ctx.r28.u64 | 40880;
	// lis r28,3
	ctx.r28.s64 = 196608;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// ori r10,r28,2364
	ctx.r10.u64 = ctx.r28.u64 | 2364;
	// lis r28,2
	ctx.r28.s64 = 131072;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r9,r31,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	// ori r8,r28,2136
	ctx.r8.u64 = ctx.r28.u64 | 2136;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r7,r31,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// lis r28,3
	ctx.r28.s64 = 196608;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lwzx r10,r31,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// ori r8,r28,18768
	ctx.r8.u64 = ctx.r28.u64 | 18768;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f0,-19272(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19272);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stwx r3,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lwz r9,72(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lfd f30,19584(r7)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r7.u32 + 19584);
	// lfs f13,-19276(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19276);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r7,r8,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fdivs f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 / ctx.f8.f64));
	// fdivs f2,f13,f7
	ctx.f2.f64 = double(float(ctx.f13.f64 / ctx.f7.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F0F0;
	sub_8207B7A8(ctx, base);
	// lwz r6,16(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// lwz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r4,r30,888
	ctx.r4.s64 = ctx.r30.s64 + 888;
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,32(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r28,40(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// lis r27,-32254
	ctx.r27.s64 = -2113798144;
	// lwz r8,36(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// lfsx f28,r3,r4
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r4.u32);
	ctx.f28.f64 = double(temp.f32);
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,12868(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12868);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r7,r28,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFFFFF0;
	// fmuls f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// lfs f10,-19280(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19280);
	ctx.f10.f64 = double(temp.f32);
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r19,24(r29)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// subf r9,r28,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r28.s64;
	// lfs f9,-22616(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + -22616);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r7,28(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r26,r30,376
	ctx.r26.s64 = ctx.r30.s64 + 376;
	// addi r8,r30,192
	ctx.r8.s64 = ctx.r30.s64 + 192;
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// fsqrts f0,f5
	ctx.f0.f64 = double(float(sqrt(ctx.f5.f64)));
	// lfs f12,-19284(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19284);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r30,504
	ctx.r9.s64 = ctx.r30.s64 + 504;
	// lfsx f2,r3,r26
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r26.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r3,r8
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f1.f64 = double(temp.f32);
	// addi r8,r30,632
	ctx.r8.s64 = ctx.r30.s64 + 632;
	// addi r3,r30,760
	ctx.r3.s64 = ctx.r30.s64 + 760;
	// addi r28,r30,1016
	ctx.r28.s64 = ctx.r30.s64 + 1016;
	// lfsx f27,r5,r9
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	ctx.f27.f64 = double(temp.f32);
	// addi r9,r30,2056
	ctx.r9.s64 = ctx.r30.s64 + 2056;
	// addi r26,r30,1536
	ctx.r26.s64 = ctx.r30.s64 + 1536;
	// lfsx f26,r5,r8
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	ctx.f26.f64 = double(temp.f32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f25,r5,r3
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	ctx.f25.f64 = double(temp.f32);
	// addi r27,r30,316
	ctx.r27.s64 = ctx.r30.s64 + 316;
	// lfsx f8,r4,r28
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r28.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r8,r30,2600
	ctx.r8.s64 = ctx.r30.s64 + 2600;
	// lfsx f5,r6,r9
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	ctx.f5.f64 = double(temp.f32);
	// addi r5,r30,132
	ctx.r5.s64 = ctx.r30.s64 + 132;
	// lfsx f6,r4,r26
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r26.u32);
	ctx.f6.f64 = double(temp.f32);
	// addi r3,r30,3144
	ctx.r3.s64 = ctx.r30.s64 + 3144;
	// addi r28,r30,3144
	ctx.r28.s64 = ctx.r30.s64 + 3144;
	// rlwinm r4,r19,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r10,r27
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r27.u32);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f4,r6,r8
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	ctx.f4.f64 = double(temp.f32);
	// lfsx f3,r10,r5
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	ctx.f3.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfsx f13,r4,r3
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f31,r9,r28
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	ctx.f31.f64 = double(temp.f32);
	// fnmsubs f24,f0,f10,f9
	ctx.f24.f64 = double(float(-(ctx.f0.f64 * ctx.f10.f64 - ctx.f9.f64)));
	// fmuls f11,f0,f11
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// fmuls f29,f28,f12
	ctx.f29.f64 = double(float(ctx.f28.f64 * ctx.f12.f64));
	// fmuls f10,f2,f24
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f24.f64));
	// fmuls f22,f1,f24
	ctx.f22.f64 = double(float(ctx.f1.f64 * ctx.f24.f64));
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fmuls f24,f10,f12
	ctx.f24.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmuls f23,f10,f12
	ctx.f23.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// bne cr6,0x8212f218
	if (!ctx.cr6.eq) goto loc_8212F218;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8212f23c
	goto loc_8212F23C;
loc_8212F218:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f2,f12
	ctx.f2.f64 = double(ctx.f12.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fmuls f12,f1,f19
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f19.f64));
	// fctidz f2,f12
	ctx.f2.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8212F23C:
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// ori r7,r8,8
	ctx.r7.u64 = ctx.r8.u64 | 8;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8212f280
	if (!ctx.cr6.eq) goto loc_8212F280;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r6,r8,12
	ctx.r6.u64 = ctx.r8.u64 | 12;
	// ori r5,r7,20
	ctx.r5.u64 = ctx.r7.u64 | 20;
	// stwx r9,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r9.u32);
	// stfsx f21,r11,r5
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f21.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r5.u32, temp.u32);
	// b 0x8212f28c
	goto loc_8212F28C;
loc_8212F280:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r8,r10,12
	ctx.r8.u64 = ctx.r10.u64 | 12;
	// stwx r9,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u32);
loc_8212F28C:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lfs f12,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lfs f2,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// ori r5,r11,2140
	ctx.r5.u64 = ctx.r11.u64 | 2140;
	// fneg f21,f13
	ctx.f21.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lfs f1,20(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// fneg f19,f31
	ctx.f19.u64 = ctx.f31.u64 ^ 0x8000000000000000;
	// ori r4,r10,2144
	ctx.r4.u64 = ctx.r10.u64 | 2144;
	// ori r3,r9,2148
	ctx.r3.u64 = ctx.r9.u64 | 2148;
	// addi r11,r11,2164
	ctx.r11.s64 = ctx.r11.s64 + 2164;
	// stfsx f12,r31,r5
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r10,r8,10908
	ctx.r10.u64 = ctx.r8.u64 | 10908;
	// stfsx f2,r31,r4
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stfsx f27,r31,r3
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// stfs f13,524(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 524, temp.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stfs f21,528(r11)
	temp.f32 = float(ctx.f21.f64);
	PPC_STORE_U32(ctx.r11.u32 + 528, temp.u32);
	// ori r9,r7,10912
	ctx.r9.u64 = ctx.r7.u64 | 10912;
	// ori r8,r6,10916
	ctx.r8.u64 = ctx.r6.u64 | 10916;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stfsx f12,r31,r10
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// addi r3,r3,10932
	ctx.r3.s64 = ctx.r3.s64 + 10932;
	// addi r11,r11,11980
	ctx.r11.s64 = ctx.r11.s64 + 11980;
	// stfsx f1,r31,r9
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// ori r10,r7,18160
	ctx.r10.u64 = ctx.r7.u64 | 18160;
	// stfsx f29,r31,r8
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// stfs f13,1036(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1036, temp.u32);
	// ori r9,r6,18164
	ctx.r9.u64 = ctx.r6.u64 | 18164;
	// stfs f21,1040(r3)
	temp.f32 = float(ctx.f21.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1040, temp.u32);
	// ori r8,r5,68
	ctx.r8.u64 = ctx.r5.u64 | 68;
	// stfs f13,2060(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2060, temp.u32);
	// ori r7,r4,72
	ctx.r7.u64 = ctx.r4.u64 | 72;
	// stfs f21,2064(r11)
	temp.f32 = float(ctx.f21.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2064, temp.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stfsx f22,r31,r10
	temp.f32 = float(ctx.f22.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// stfsx f10,r31,r9
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// ori r3,r6,22332
	ctx.r3.u64 = ctx.r6.u64 | 22332;
	// stfsx f26,r31,r8
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// ori r11,r5,22352
	ctx.r11.u64 = ctx.r5.u64 | 22352;
	// stfsx f25,r31,r7
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// ori r10,r4,22356
	ctx.r10.u64 = ctx.r4.u64 | 22356;
	// stfs f31,2060(r21)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r21.u32 + 2060, temp.u32);
	// stfs f19,2064(r21)
	temp.f32 = float(ctx.f19.f64);
	PPC_STORE_U32(ctx.r21.u32 + 2064, temp.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// stfs f31,2060(r20)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r20.u32 + 2060, temp.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// stfs f19,2064(r20)
	temp.f32 = float(ctx.f19.f64);
	PPC_STORE_U32(ctx.r20.u32 + 2064, temp.u32);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stfsx f8,r31,r3
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stfsx f7,r31,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// stfsx f6,r31,r10
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r28,1
	ctx.r28.s64 = 65536;
	// lis r27,1
	ctx.r27.s64 = 65536;
	// ori r9,r9,22360
	ctx.r9.u64 = ctx.r9.u64 | 22360;
	// ori r8,r8,22380
	ctx.r8.u64 = ctx.r8.u64 | 22380;
	// ori r7,r7,22384
	ctx.r7.u64 = ctx.r7.u64 | 22384;
	// ori r6,r6,38816
	ctx.r6.u64 = ctx.r6.u64 | 38816;
	// ori r5,r5,42980
	ctx.r5.u64 = ctx.r5.u64 | 42980;
	// ori r4,r4,43000
	ctx.r4.u64 = ctx.r4.u64 | 43000;
	// ori r3,r3,43004
	ctx.r3.u64 = ctx.r3.u64 | 43004;
	// ori r11,r11,43008
	ctx.r11.u64 = ctx.r11.u64 | 43008;
	// ori r10,r10,43028
	ctx.r10.u64 = ctx.r10.u64 | 43028;
	// ori r28,r28,43032
	ctx.r28.u64 = ctx.r28.u64 | 43032;
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// ori r27,r27,59464
	ctx.r27.u64 = ctx.r27.u64 | 59464;
	// stfsx f5,r31,r9
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lis r9,2
	ctx.r9.s64 = 131072;
	// stfsx f4,r31,r8
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lis r8,2
	ctx.r8.s64 = 131072;
	// stfsx f3,r31,r7
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// lis r7,3
	ctx.r7.s64 = 196608;
	// stfs f31,2060(r22)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r22.u32 + 2060, temp.u32);
	// lis r6,3
	ctx.r6.s64 = 196608;
	// ori r9,r9,39132
	ctx.r9.u64 = ctx.r9.u64 | 39132;
	// stfs f19,2064(r22)
	temp.f32 = float(ctx.f19.f64);
	PPC_STORE_U32(ctx.r22.u32 + 2064, temp.u32);
	// ori r8,r8,39136
	ctx.r8.u64 = ctx.r8.u64 | 39136;
	// stfs f31,2060(r23)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r23.u32 + 2060, temp.u32);
	// ori r7,r7,18808
	ctx.r7.u64 = ctx.r7.u64 | 18808;
	// stfs f19,2064(r23)
	temp.f32 = float(ctx.f19.f64);
	PPC_STORE_U32(ctx.r23.u32 + 2064, temp.u32);
	// ori r6,r6,18804
	ctx.r6.u64 = ctx.r6.u64 | 18804;
	// stfsx f8,r31,r5
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfsx f7,r31,r4
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfsx f6,r31,r3
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// stfsx f5,r31,r11
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f4,r31,r10
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stfsx f3,r31,r28
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// stfs f31,4108(r24)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r24.u32 + 4108, temp.u32);
	// stfs f19,4112(r24)
	temp.f32 = float(ctx.f19.f64);
	PPC_STORE_U32(ctx.r24.u32 + 4112, temp.u32);
	// stfsx f11,r31,r9
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stfsx f11,r31,r8
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// stfs f31,4108(r25)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4108, temp.u32);
	// stfs f19,4112(r25)
	temp.f32 = float(ctx.f19.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4112, temp.u32);
	// stfsx f9,r31,r7
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stfsx f9,r31,r6
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// lfs f29,23060(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 23060);
	ctx.f29.f64 = double(temp.f32);
	// lwz r4,68(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f0,f29
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F470;
	sub_8207B7A8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r3,1
	ctx.r3.s64 = 65536;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// ori r11,r3,38792
	ctx.r11.u64 = ctx.r3.u64 | 38792;
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f28.f64));
	// stfsx f12,r31,r11
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r10,68(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f2,f11,f29
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F49C;
	sub_8207B7A8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lis r9,1
	ctx.r9.s64 = 65536;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// ori r8,r9,59440
	ctx.r8.u64 = ctx.r9.u64 | 59440;
	// fmuls f9,f10,f28
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f28.f64));
	// stfsx f9,r31,r8
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// lwz r7,68(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f8,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f2,f8,f29
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F4C8;
	sub_8207B7A8(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lis r6,2
	ctx.r6.s64 = 131072;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// ori r5,r6,39108
	ctx.r5.u64 = ctx.r6.u64 | 39108;
	// fmuls f6,f7,f24
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f24.f64));
	// stfsx f6,r31,r5
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// lwz r4,68(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f5,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f2,f5,f29
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F4F4;
	sub_8207B7A8(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// lis r3,3
	ctx.r3.s64 = 196608;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// ori r11,r3,18780
	ctx.r11.u64 = ctx.r3.u64 | 18780;
	// fmuls f3,f4,f23
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f23.f64));
	// stfsx f3,r31,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f2,f2,f29
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F520;
	sub_8207B7A8(ctx, base);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addis r9,r31,3
	ctx.r9.s64 = ctx.r31.s64 + 196608;
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// addis r8,r31,3
	ctx.r8.s64 = ctx.r31.s64 + 196608;
	// addi r9,r9,18816
	ctx.r9.s64 = ctx.r9.s64 + 18816;
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addi r8,r8,20888
	ctx.r8.s64 = ctx.r8.s64 + 20888;
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,36
	ctx.r30.s64 = ctx.r30.s64 + 36;
	// stfs f0,2060(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2060, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f12,2064(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2064, temp.u32);
	// stfs f0,2060(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2060, temp.u32);
	// stfs f12,2064(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2064, temp.u32);
	// lwz r7,52(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,4(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// bl 0x8212e008
	ctx.lr = 0x8212F574;
	sub_8212E008(ctx, base);
	// lwz r6,56(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f10,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,8(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// bl 0x8212e008
	ctx.lr = 0x8212F58C;
	sub_8212E008(ctx, base);
	// lwz r5,60(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,12(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// bl 0x8212e008
	ctx.lr = 0x8212F5A4;
	sub_8212E008(ctx, base);
	// lwz r4,84(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f8,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f20
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f20.f64));
	// stfs f7,0(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82080390
	ctx.lr = 0x8212F5C4;
	__restfpr_19(ctx, base);
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8212F5C8"))) PPC_WEAK_FUNC(sub_8212F5C8);
PPC_FUNC_IMPL(__imp__sub_8212F5C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8212F5D0;
	__savegprlr_22(ctx, base);
	// addi r12,r1,-88
	ctx.r12.s64 = ctx.r1.s64 + -88;
	// bl 0x8208035c
	ctx.lr = 0x8212F5D8;
	__savefpr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8212e950
	ctx.lr = 0x8212F5E8;
	sub_8212E950(ctx, base);
	// lwz r8,80(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r29,r11,-22496
	ctx.r29.s64 = ctx.r11.s64 + -22496;
	// lfs f13,-22612(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22612);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lfs f25,14004(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f25.f64 = double(temp.f32);
	// blt cr6,0x8212f62c
	if (ctx.cr6.lt) goto loc_8212F62C;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,22044(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 22044);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f0,-22624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22624);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8212f650
	goto loc_8212F650;
loc_8212F62C:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f13,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f12,26636(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 26636);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f12,f0,f13,f12
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// lfs f13,22044(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22044);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-22624(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22624);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
loc_8212F650:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8212f65c
	if (!ctx.cr6.lt) goto loc_8212F65C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_8212F65C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,23040(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23040);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f31,f13,f12
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8212f678
	if (!ctx.cr6.lt) goto loc_8212F678;
	// fmr f31,f0
	ctx.f31.f64 = ctx.f0.f64;
	// b 0x8212f684
	goto loc_8212F684;
loc_8212F678:
	// fcmpu cr6,f31,f25
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f25.f64);
	// ble cr6,0x8212f684
	if (!ctx.cr6.gt) goto loc_8212F684;
	// fmr f31,f25
	ctx.f31.f64 = ctx.f25.f64;
loc_8212F684:
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lfs f0,-19200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19200);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212F6A0;
	sub_8214DC28(ctx, base);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r10,25092
	ctx.r8.u64 = ctx.r10.u64 | 25092;
	// ori r7,r9,25096
	ctx.r7.u64 = ctx.r9.u64 | 25096;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stwx r3,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// stwx r11,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r11.u32);
	// lfs f0,-19180(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19180);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f31,f0
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212F6D8;
	sub_8214DC28(ctx, base);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// ori r10,r5,33860
	ctx.r10.u64 = ctx.r5.u64 | 33860;
	// ori r9,r4,33864
	ctx.r9.u64 = ctx.r4.u64 | 33864;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// stwx r3,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// stwx r11,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// subfic r7,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r6,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rlwinm r11,r11,0,28,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFC0F;
	// addi r11,r11,1020
	ctx.r11.s64 = ctx.r11.s64 + 1020;
	// clrldi r5,r11,32
	ctx.r5.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212F734;
	sub_8214DC28(ctx, base);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// ori r9,r11,59428
	ctx.r9.u64 = ctx.r11.u64 | 59428;
	// ori r10,r4,63780
	ctx.r10.u64 = ctx.r4.u64 | 63780;
	// ori r6,r8,55560
	ctx.r6.u64 = ctx.r8.u64 | 55560;
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lwzx r11,r31,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// ori r5,r7,22692
	ctx.r5.u64 = ctx.r7.u64 | 22692;
	// lwzx r10,r31,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// lis r7,5
	ctx.r7.s64 = 327680;
	// lwzx r9,r31,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// ori r6,r4,22304
	ctx.r6.u64 = ctx.r4.u64 | 22304;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lwzx r10,r31,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ori r9,r7,41116
	ctx.r9.u64 = ctx.r7.u64 | 41116;
	// lis r5,3
	ctx.r5.s64 = 196608;
	// lwzx r8,r31,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// ori r7,r4,20232
	ctx.r7.u64 = ctx.r4.u64 | 20232;
	// lis r28,2
	ctx.r28.s64 = 131072;
	// lis r27,2
	ctx.r27.s64 = 131072;
	// ori r6,r5,18768
	ctx.r6.u64 = ctx.r5.u64 | 18768;
	// stwx r3,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ori r5,r28,18572
	ctx.r5.u64 = ctx.r28.u64 | 18572;
	// lwzx r9,r31,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r7.u32);
	// ori r4,r27,47344
	ctx.r4.u64 = ctx.r27.u64 | 47344;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r7,r31,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// addi r3,r29,504
	ctx.r3.s64 = ctx.r29.s64 + 504;
	// addi r6,r29,632
	ctx.r6.s64 = ctx.r29.s64 + 632;
	// lwzx r10,r31,r5
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r8,r31,r4
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r4.u32);
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r5,72(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// ori r5,r4,10352
	ctx.r5.u64 = ctx.r4.u64 | 10352;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ori r9,r9,42952
	ctx.r9.u64 = ctx.r9.u64 | 42952;
	// lis r28,1
	ctx.r28.s64 = 65536;
	// add r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwzx r11,r31,r5
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// ori r8,r28,40880
	ctx.r8.u64 = ctx.r28.u64 | 40880;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r9,r31,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// ori r5,r5,39096
	ctx.r5.u64 = ctx.r5.u64 | 39096;
	// lis r28,1
	ctx.r28.s64 = 65536;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r11,r31,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// ori r8,r28,38780
	ctx.r8.u64 = ctx.r28.u64 | 38780;
	// lis r28,3
	ctx.r28.s64 = 196608;
	// lwzx r9,r31,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r5,r28,2364
	ctx.r5.u64 = ctx.r28.u64 | 2364;
	// lis r28,2
	ctx.r28.s64 = 131072;
	// lwzx r10,r31,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// ori r8,r28,2136
	ctx.r8.u64 = ctx.r28.u64 | 2136;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f5,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// lwzx r9,r31,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r5.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r28,-32255
	ctx.r28.s64 = -2113863680;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwzx r10,r31,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f0,-19272(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19272);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r29,760
	ctx.r11.s64 = ctx.r29.s64 + 760;
	// lfd f31,19584(r28)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r28.u32 + 19584);
	// rlwinm r10,r4,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f29,r8,r3
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	ctx.f29.f64 = double(temp.f32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// lfs f13,-19276(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19276);
	ctx.f13.f64 = double(temp.f32);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// lfsx f28,r7,r6
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	ctx.f28.f64 = double(temp.f32);
	// lfsx f27,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fdivs f12,f5,f0
	ctx.f12.f64 = double(float(ctx.f5.f64 / ctx.f0.f64));
	// fdivs f2,f13,f12
	ctx.f2.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212F8B0;
	sub_8207B7A8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r6,20(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r8,r29,376
	ctx.r8.s64 = ctx.r29.s64 + 376;
	// lfs f0,12868(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12868);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r29,888
	ctx.r7.s64 = ctx.r29.s64 + 888;
	// addi r6,r29,192
	ctx.r6.s64 = ctx.r29.s64 + 192;
	// lfs f13,-19280(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19280);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22616(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -22616);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r10,r29,632
	ctx.r10.s64 = ctx.r29.s64 + 632;
	// lfsx f9,r3,r8
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfsx f30,r3,r7
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f7,r3,r6
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	ctx.f7.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fsqrts f6,f8
	ctx.f6.f64 = double(float(sqrt(ctx.f8.f64)));
	// fnmsubs f5,f6,f13,f12
	ctx.f5.f64 = double(float(-(ctx.f6.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f0,-19284(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19284);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f10,r9,r10
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f11,f30,f0
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// fmuls f13,f9,f5
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// fmuls f12,f7,f5
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// fmuls f26,f13,f0
	ctx.f26.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bne cr6,0x8212f934
	if (!ctx.cr6.eq) goto loc_8212F934;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8212f960
	goto loc_8212F960;
loc_8212F934:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f0
	ctx.f9.f64 = double(ctx.f0.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lfs f0,-19184(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19184);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8212F960:
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// addi r11,r11,22960
	ctx.r11.s64 = ctx.r11.s64 + 22960;
	// ori r7,r8,8
	ctx.r7.u64 = ctx.r8.u64 | 8;
	// addis r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 131072;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r5,r6
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8212f9ac
	if (!ctx.cr6.eq) goto loc_8212F9AC;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// lis r7,2
	ctx.r7.s64 = 131072;
	// ori r6,r8,12
	ctx.r6.u64 = ctx.r8.u64 | 12;
	// ori r5,r7,20
	ctx.r5.u64 = ctx.r7.u64 | 20;
	// rlwinm r4,r9,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stwx r4,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r4.u32);
	// stfsx f25,r11,r5
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r5.u32, temp.u32);
	// b 0x8212f9bc
	goto loc_8212F9BC;
loc_8212F9AC:
	// lis r10,2
	ctx.r10.s64 = 131072;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// ori r8,r10,12
	ctx.r8.u64 = ctx.r10.u64 | 12;
	// stwx r9,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u32);
loc_8212F9BC:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lfs f9,4(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// ori r9,r11,68
	ctx.r9.u64 = ctx.r11.u64 | 68;
	// lfs f8,20(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lis r8,5
	ctx.r8.s64 = 327680;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// ori r11,r10,25104
	ctx.r11.u64 = ctx.r10.u64 | 25104;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// stfsx f10,r31,r9
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// ori r10,r8,25108
	ctx.r10.u64 = ctx.r8.u64 | 25108;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// ori r9,r7,25112
	ctx.r9.u64 = ctx.r7.u64 | 25112;
	// addi r6,r29,3144
	ctx.r6.s64 = ctx.r29.s64 + 3144;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// addis r8,r31,5
	ctx.r8.s64 = ctx.r31.s64 + 327680;
	// ori r7,r5,33872
	ctx.r7.u64 = ctx.r5.u64 | 33872;
	// ori r5,r4,33876
	ctx.r5.u64 = ctx.r4.u64 | 33876;
	// addis r25,r31,6
	ctx.r25.s64 = ctx.r31.s64 + 393216;
	// ori r4,r3,33880
	ctx.r4.u64 = ctx.r3.u64 | 33880;
	// addi r8,r8,25128
	ctx.r8.s64 = ctx.r8.s64 + 25128;
	// addis r24,r31,6
	ctx.r24.s64 = ctx.r31.s64 + 393216;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// lis r28,5
	ctx.r28.s64 = 327680;
	// lis r27,5
	ctx.r27.s64 = 327680;
	// lis r26,5
	ctx.r26.s64 = 327680;
	// addi r25,r25,-31640
	ctx.r25.s64 = ctx.r25.s64 + -31640;
	// addi r24,r24,-30592
	ctx.r24.s64 = ctx.r24.s64 + -30592;
	// ori r3,r3,41124
	ctx.r3.u64 = ctx.r3.u64 | 41124;
	// ori r28,r28,41128
	ctx.r28.u64 = ctx.r28.u64 | 41128;
	// lwz r23,24(r30)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// ori r27,r27,23032
	ctx.r27.u64 = ctx.r27.u64 | 23032;
	// ori r26,r26,23036
	ctx.r26.u64 = ctx.r26.u64 | 23036;
	// rlwinm r23,r23,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r22,-32256
	ctx.r22.s64 = -2113929216;
	// lfsx f10,r23,r6
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfsx f29,r31,r9
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// fneg f7,f10
	ctx.f7.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f9,r31,r10
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stfs f10,524(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + 524, temp.u32);
	// stfs f7,528(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 528, temp.u32);
	// stfsx f0,r31,r7
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stfsx f8,r31,r5
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// stfsx f11,r31,r4
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// stfs f10,1036(r25)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r25.u32 + 1036, temp.u32);
	// stfs f7,1040(r25)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r25.u32 + 1040, temp.u32);
	// stfs f10,2060(r24)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r24.u32 + 2060, temp.u32);
	// stfs f7,2064(r24)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r24.u32 + 2064, temp.u32);
	// stfsx f12,r31,r3
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, temp.u32);
	// stfsx f13,r31,r28
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r28.u32, temp.u32);
	// stfsx f28,r31,r27
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
	// stfsx f27,r31,r26
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r26.u32, temp.u32);
	// lwz r11,68(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// lfs f29,23060(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 23060);
	ctx.f29.f64 = double(temp.f32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lfs f6,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f2,f6,f29
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212FAB0;
	sub_8207B7A8(ctx, base);
	// frsp f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f1.f64));
	// lis r10,1
	ctx.r10.s64 = 65536;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// ori r9,r10,59440
	ctx.r9.u64 = ctx.r10.u64 | 59440;
	// fmuls f4,f5,f30
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f30.f64));
	// stfsx f4,r31,r9
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// lwz r8,68(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f3,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f29
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f29.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8212FADC;
	sub_8207B7A8(ctx, base);
	// lis r7,3
	ctx.r7.s64 = 196608;
	// lfs f0,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addis r28,r31,5
	ctx.r28.s64 = ctx.r31.s64 + 327680;
	// frsp f2,f1
	ctx.f2.f64 = double(float(ctx.f1.f64));
	// addis r4,r31,6
	ctx.r4.s64 = ctx.r31.s64 + 393216;
	// addi r28,r28,22992
	ctx.r28.s64 = ctx.r28.s64 + 22992;
	// ori r6,r7,18780
	ctx.r6.u64 = ctx.r7.u64 | 18780;
	// addi r5,r29,3144
	ctx.r5.s64 = ctx.r29.s64 + 3144;
	// addi r4,r4,-24396
	ctx.r4.s64 = ctx.r4.s64 + -24396;
	// fmuls f1,f2,f26
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f26.f64));
	// stfsx f1,r31,r6
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r11,r11,-22324
	ctx.r11.s64 = ctx.r11.s64 + -22324;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r9,r5
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f12,2060(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 2060, temp.u32);
	// stfs f11,2064(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 2064, temp.u32);
	// stfs f12,2060(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2060, temp.u32);
	// stfs f11,2064(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2064, temp.u32);
	// lwz r8,52(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,4(r28)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4, temp.u32);
	// bl 0x8212e2f8
	ctx.lr = 0x8212FB4C;
	sub_8212E2F8(ctx, base);
	// lwz r7,56(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,8(r28)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8, temp.u32);
	// bl 0x8212e2f8
	ctx.lr = 0x8212FB64;
	sub_8212E2F8(ctx, base);
	// lwz r6,60(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f8,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,12(r28)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r28.u32 + 12, temp.u32);
	// bl 0x8212e2f8
	ctx.lr = 0x8212FB7C;
	sub_8212E2F8(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-88
	ctx.r12.s64 = ctx.r1.s64 + -88;
	// bl 0x820803a8
	ctx.lr = 0x8212FB88;
	__restfpr_25(ctx, base);
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8212FB8C"))) PPC_WEAK_FUNC(sub_8212FB8C);
PPC_FUNC_IMPL(__imp__sub_8212FB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8212FB90"))) PPC_WEAK_FUNC(sub_8212FB90);
PPC_FUNC_IMPL(__imp__sub_8212FB90) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8212f5c8
	ctx.lr = 0x8212FBB0;
	sub_8212F5C8(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r6,28(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// addis r9,r31,6
	ctx.r9.s64 = ctx.r31.s64 + 393216;
	// addi r11,r10,-22476
	ctx.r11.s64 = ctx.r10.s64 + -22476;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,3124
	ctx.r7.s64 = ctx.r11.s64 + 3124;
	// lfs f0,-22476(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -22476);
	ctx.f0.f64 = double(temp.f32);
	// addis r8,r31,6
	ctx.r8.s64 = ctx.r31.s64 + 393216;
	// addi r9,r9,-20252
	ctx.r9.s64 = ctx.r9.s64 + -20252;
	// addi r8,r8,-18180
	ctx.r8.s64 = ctx.r8.s64 + -18180;
	// lfsx f13,r5,r7
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,2060(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2060, temp.u32);
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,2064(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2064, temp.u32);
	// stfs f12,2060(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2060, temp.u32);
	// stfs f11,2064(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2064, temp.u32);
	// lwz r11,48(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8212fc08
	if (!ctx.cr6.eq) goto loc_8212FC08;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8212fc34
	goto loc_8212FC34;
loc_8212FC08:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,-19184(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19184);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_8212FC34:
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// addi r11,r11,-16108
	ctx.r11.s64 = ctx.r11.s64 + -16108;
	// lwz r9,2056(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2056);
	// lwz r8,2052(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2052);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8212fc68
	if (!ctx.cr6.eq) goto loc_8212FC68;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,2052(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2052, ctx.r8.u32);
	// stw r8,2060(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2060, ctx.r8.u32);
	// lfs f0,14004(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14004);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,2068(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2068, temp.u32);
	// b 0x8212fc70
	goto loc_8212FC70;
loc_8212FC68:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,2060(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2060, ctx.r10.u32);
loc_8212FC70:
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

__attribute__((alias("__imp__sub_8212FC88"))) PPC_WEAK_FUNC(sub_8212FC88);
PPC_FUNC_IMPL(__imp__sub_8212FC88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8212FC90;
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
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addis r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lfs f31,12868(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12868);
	ctx.f31.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// ori r4,r5,8
	ctx.r4.u64 = ctx.r5.u64 | 8;
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// fdivs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 / ctx.f0.f64));
	// stfs f1,0(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,-19272(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19272);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f30,f1,f0
	ctx.f30.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// fmadds f9,f10,f13,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f31.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stwx r8,r11,r4
	PPC_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r8.u32);
	// stfs f1,0(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// bl 0x8212e008
	ctx.lr = 0x8212FD18;
	sub_8212E008(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f0,-19200(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19200);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f7,f30,f0,f31
	ctx.f7.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FD34;
	sub_8214DC28(ctx, base);
	// fadds f5,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f30.f64 + ctx.f31.f64));
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// ori r10,r6,2128
	ctx.r10.u64 = ctx.r6.u64 | 2128;
	// ori r9,r5,2132
	ctx.r9.u64 = ctx.r5.u64 | 2132;
	// ori r8,r4,2136
	ctx.r8.u64 = ctx.r4.u64 | 2136;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stwx r3,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// stwx r11,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r30,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u32);
	// lfs f0,-19152(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19152);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f3,f30,f0,f31
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FD88;
	sub_8214DC28(ctx, base);
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r6,r6,2164
	ctx.r6.s64 = ctx.r6.s64 + 2164;
	// lfs f0,-19204(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19204);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,512(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 512);
	// fmadds f1,f30,f0,f31
	ctx.f1.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,520(r6)
	PPC_STORE_U32(ctx.r6.u32 + 520, ctx.r3.u32);
	// subf r3,r3,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r3.s64;
	// clrlwi r11,r3,25
	ctx.r11.u64 = ctx.r3.u32 & 0x7F;
	// stw r11,516(r6)
	PPC_STORE_U32(ctx.r6.u32 + 516, ctx.r11.u32);
	// fctidz f0,f1
	ctx.f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FDC0;
	sub_8214DC28(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lfs f0,-19156(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19156);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// fmadds f13,f30,f0,f31
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// ori r7,r9,10896
	ctx.r7.u64 = ctx.r9.u64 | 10896;
	// ori r6,r8,10900
	ctx.r6.u64 = ctx.r8.u64 | 10900;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// stwx r3,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stwx r11,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u32);
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FDF8;
	sub_8214DC28(ctx, base);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// ori r4,r5,10904
	ctx.r4.u64 = ctx.r5.u64 | 10904;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// stwx r3,r31,r4
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lfs f0,-19160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19160);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f11,f30,f0,f31
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FE20;
	sub_8214DC28(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,10932
	ctx.r10.s64 = ctx.r10.s64 + 10932;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// stw r3,1032(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1032, ctx.r3.u32);
	// lfs f0,-19164(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -19164);
	ctx.f0.f64 = double(temp.f32);
	// subf r7,r3,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r3.s64;
	// fmadds f9,f30,f0,f31
	ctx.f9.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// stw r6,1028(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1028, ctx.r6.u32);
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FE58;
	sub_8214DC28(ctx, base);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f0,-19208(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19208);
	ctx.f0.f64 = double(temp.f32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// fmadds f7,f30,f0,f31
	ctx.f7.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r11,r11,11980
	ctx.r11.s64 = ctx.r11.s64 + 11980;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r10,18152
	ctx.r8.u64 = ctx.r10.u64 | 18152;
	// lfs f0,-19168(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19168);
	ctx.f0.f64 = double(temp.f32);
	// ori r7,r9,18156
	ctx.r7.u64 = ctx.r9.u64 | 18156;
	// lwz r6,2048(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// fmadds f6,f30,f0,f31
	ctx.f6.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,2056(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2056, ctx.r3.u32);
	// subf r5,r3,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r3.s64;
	// fctidz f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r5,23
	ctx.r4.u64 = ctx.r5.u32 & 0x1FF;
	// stw r4,2052(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2052, ctx.r4.u32);
	// stwx r30,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// fctidz f4,f6
	ctx.f4.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u32);
	// bl 0x8214dc28
	ctx.lr = 0x8212FEC0;
	sub_8214DC28(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r10,r10,18176
	ctx.r10.s64 = ctx.r10.s64 + 18176;
	// lfs f0,-19212(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19212);
	ctx.f0.f64 = double(temp.f32);
	// lwz r8,2048(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2048);
	// fmadds f3,f30,f0,f31
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,2056(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2056, ctx.r3.u32);
	// subf r7,r3,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r3.s64;
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// stw r6,2052(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2052, ctx.r6.u32);
	// fctidz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FEF8;
	sub_8214DC28(ctx, base);
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r5,r5,20248
	ctx.r5.s64 = ctx.r5.s64 + 20248;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r11,2048(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2048);
	// ori r7,r10,22328
	ctx.r7.u64 = ctx.r10.u64 | 22328;
	// lfs f0,-19216(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19216);
	ctx.f0.f64 = double(temp.f32);
	// stw r3,2056(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2056, ctx.r3.u32);
	// ori r6,r9,22348
	ctx.r6.u64 = ctx.r9.u64 | 22348;
	// subf r3,r3,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r3.s64;
	// fmadds f1,f30,f0,f31
	ctx.f1.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// ori r4,r8,22376
	ctx.r4.u64 = ctx.r8.u64 | 22376;
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// stw r11,2052(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2052, ctx.r11.u32);
	// stwx r30,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// stwx r30,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u32);
	// stwx r30,r31,r4
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u32);
	// fctidz f0,f1
	ctx.f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FF54;
	sub_8214DC28(ctx, base);
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// addi r29,r29,-26752
	ctx.r29.s64 = ctx.r29.s64 + -26752;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r7,r9,38780
	ctx.r7.u64 = ctx.r9.u64 | 38780;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stwx r3,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmadds f10,f11,f30,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f30.f64 + ctx.f31.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FF90;
	sub_8214DC28(ctx, base);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// ori r4,r6,38812
	ctx.r4.u64 = ctx.r6.u64 | 38812;
	// lfs f0,-19220(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19220);
	ctx.f0.f64 = double(temp.f32);
	// stwx r30,r31,r4
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r30.u32);
	// fmadds f8,f30,f0,f31
	ctx.f8.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FFBC;
	sub_8214DC28(ctx, base);
	// addis r11,r31,2
	ctx.r11.s64 = ctx.r31.s64 + 131072;
	// addi r11,r11,-26712
	ctx.r11.s64 = ctx.r11.s64 + -26712;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r10,2048(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// stw r3,2056(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2056, ctx.r3.u32);
	// lfs f0,-19224(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19224);
	ctx.f0.f64 = double(temp.f32);
	// subf r8,r3,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r3.s64;
	// fmadds f6,f30,f0,f31
	ctx.f6.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r7,r8,23
	ctx.r7.u64 = ctx.r8.u32 & 0x1FF;
	// stw r7,2052(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2052, ctx.r7.u32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8212FFF4;
	sub_8214DC28(ctx, base);
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// addi r6,r6,-24640
	ctx.r6.s64 = ctx.r6.s64 + -24640;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r8,r4,42976
	ctx.r8.u64 = ctx.r4.u64 | 42976;
	// lwz r5,2048(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2048);
	// ori r7,r11,42996
	ctx.r7.u64 = ctx.r11.u64 | 42996;
	// stw r3,2056(r6)
	PPC_STORE_U32(ctx.r6.u32 + 2056, ctx.r3.u32);
	// subf r9,r3,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r3.s64;
	// ori r5,r10,43024
	ctx.r5.u64 = ctx.r10.u64 | 43024;
	// clrlwi r4,r9,23
	ctx.r4.u64 = ctx.r9.u32 & 0x1FF;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// stw r4,2052(r6)
	PPC_STORE_U32(ctx.r6.u32 + 2052, ctx.r4.u32);
	// stwx r30,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u32);
	// stwx r30,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// stwx r30,r31,r5
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u32);
	// lfs f0,-19228(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -19228);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f4,f30,f0,f31
	ctx.f4.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130050;
	sub_8214DC28(ctx, base);
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// addi r29,r29,-6104
	ctx.r29.s64 = ctx.r29.s64 + -6104;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r9,r11,59428
	ctx.r9.u64 = ctx.r11.u64 | 59428;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f2,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stwx r3,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r3.u32);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmadds f13,f0,f30,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f30.f64 + ctx.f31.f64));
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8213008C;
	sub_8214DC28(ctx, base);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// ori r5,r7,59460
	ctx.r5.u64 = ctx.r7.u64 | 59460;
	// lfs f0,-19232(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19232);
	ctx.f0.f64 = double(temp.f32);
	// stwx r30,r31,r5
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u32);
	// fmadds f11,f30,f0,f31
	ctx.f11.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821300B8;
	sub_8214DC28(ctx, base);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r4,r4,-6064
	ctx.r4.s64 = ctx.r4.s64 + -6064;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r11,8192(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8192);
	// stw r3,8200(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8200, ctx.r3.u32);
	// lfs f0,-19236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19236);
	ctx.f0.f64 = double(temp.f32);
	// subf r9,r3,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r3.s64;
	// fmadds f9,f30,f0,f31
	ctx.f9.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r8,r9,21
	ctx.r8.u64 = ctx.r9.u32 & 0x7FF;
	// stw r8,8196(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8196, ctx.r8.u32);
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821300F0;
	sub_8214DC28(ctx, base);
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// addi r6,r6,2152
	ctx.r6.s64 = ctx.r6.s64 + 2152;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r5,8192(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8192);
	// stw r3,8200(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8200, ctx.r3.u32);
	// lfs f0,-19240(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19240);
	ctx.f0.f64 = double(temp.f32);
	// subf r4,r3,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r3.s64;
	// fmadds f7,f30,f0,f31
	ctx.f7.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r3,r4,21
	ctx.r3.u64 = ctx.r4.u32 & 0x7FF;
	// stw r3,8196(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8196, ctx.r3.u32);
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130128;
	sub_8214DC28(ctx, base);
	// addis r11,r31,2
	ctx.r11.s64 = ctx.r31.s64 + 131072;
	// addi r11,r11,10372
	ctx.r11.s64 = ctx.r11.s64 + 10372;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r9,8192(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8192);
	// stw r3,8200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8200, ctx.r3.u32);
	// lfs f0,-19244(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19244);
	ctx.f0.f64 = double(temp.f32);
	// subf r8,r3,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r3.s64;
	// fmadds f5,f30,f0,f31
	ctx.f5.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// stw r7,8196(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8196, ctx.r7.u32);
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130160;
	sub_8214DC28(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// lfs f0,-19248(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19248);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f3,f30,f0,f31
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// addi r6,r6,18588
	ctx.r6.s64 = ctx.r6.s64 + 18588;
	// lwz r5,4096(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4096);
	// stw r3,4104(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4104, ctx.r3.u32);
	// subf r11,r3,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// clrlwi r10,r11,22
	ctx.r10.u64 = ctx.r11.u32 & 0x3FF;
	// fctidz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// stw r10,4100(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4100, ctx.r10.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130198;
	sub_8214DC28(ctx, base);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// addi r29,r29,-26436
	ctx.r29.s64 = ctx.r29.s64 + -26436;
	// ori r7,r9,39096
	ctx.r7.u64 = ctx.r9.u64 | 39096;
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f1,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f1
	ctx.f0.f64 = double(ctx.f1.s64);
	// stwx r3,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// fmadds f12,f13,f30,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f30.f64 + ctx.f31.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821301D4;
	sub_8214DC28(ctx, base);
	// lis r5,2
	ctx.r5.s64 = 131072;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// ori r3,r5,39128
	ctx.r3.u64 = ctx.r5.u64 | 39128;
	// lfs f0,-19252(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19252);
	ctx.f0.f64 = double(temp.f32);
	// stwx r30,r31,r3
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u32);
	// fmadds f10,f30,f0,f31
	ctx.f10.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130200;
	sub_8214DC28(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// lfs f0,-19256(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19256);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f8,f30,f0,f31
	ctx.f8.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// addi r11,r11,-26392
	ctx.r11.s64 = ctx.r11.s64 + -26392;
	// lwz r10,8192(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8192);
	// stw r3,8200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8200, ctx.r3.u32);
	// subf r8,r3,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r3.s64;
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// stw r7,8196(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8196, ctx.r7.u32);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130238;
	sub_8214DC28(ctx, base);
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r5,r5,-18176
	ctx.r5.s64 = ctx.r5.s64 + -18176;
	// lfs f0,-19260(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19260);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,8192(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8192);
	// fmadds f6,f30,f0,f31
	ctx.f6.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,8200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8200, ctx.r3.u32);
	// subf r3,r3,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r3.s64;
	// clrlwi r11,r3,21
	ctx.r11.u64 = ctx.r3.u32 & 0x7FF;
	// stw r11,8196(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8196, ctx.r11.u32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130270;
	sub_8214DC28(ctx, base);
	// addis r10,r31,3
	ctx.r10.s64 = ctx.r31.s64 + 196608;
	// addi r10,r10,-9956
	ctx.r10.s64 = ctx.r10.s64 + -9956;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r8,8192(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// stw r3,8200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8200, ctx.r3.u32);
	// lfs f0,-19264(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19264);
	ctx.f0.f64 = double(temp.f32);
	// subf r7,r3,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r3.s64;
	// fmadds f4,f30,f0,f31
	ctx.f4.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r6,r7,21
	ctx.r6.u64 = ctx.r7.u32 & 0x7FF;
	// stw r6,8196(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8196, ctx.r6.u32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821302A8;
	sub_8214DC28(ctx, base);
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addi r5,r5,-1740
	ctx.r5.s64 = ctx.r5.s64 + -1740;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lwz r4,4096(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4096);
	// stw r3,4104(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4104, ctx.r3.u32);
	// lfs f0,-19268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19268);
	ctx.f0.f64 = double(temp.f32);
	// subf r10,r3,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r3.s64;
	// fmadds f2,f30,f0,f31
	ctx.f2.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r9,r10,22
	ctx.r9.u64 = ctx.r10.u32 & 0x3FF;
	// stw r9,4100(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4100, ctx.r9.u32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821302E0;
	sub_8214DC28(ctx, base);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// addi r29,r29,18772
	ctx.r29.s64 = ctx.r29.s64 + 18772;
	// lis r8,3
	ctx.r8.s64 = 196608;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// ori r6,r8,18768
	ctx.r6.u64 = ctx.r8.u64 | 18768;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stwx r3,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// fmadds f11,f12,f30,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f30.f64 + ctx.f31.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8213031C;
	sub_8214DC28(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lis r3,3
	ctx.r3.s64 = 196608;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// ori r11,r3,18800
	ctx.r11.u64 = ctx.r3.u64 | 18800;
	// lfs f0,-19172(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19172);
	ctx.f0.f64 = double(temp.f32);
	// stwx r30,r31,r11
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// fmadds f9,f30,f0,f31
	ctx.f9.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130348;
	sub_8214DC28(ctx, base);
	// addis r9,r31,3
	ctx.r9.s64 = ctx.r31.s64 + 196608;
	// addi r9,r9,18816
	ctx.r9.s64 = ctx.r9.s64 + 18816;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r8,2048(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2048);
	// stw r3,2056(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2056, ctx.r3.u32);
	// lfs f0,-19176(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19176);
	ctx.f0.f64 = double(temp.f32);
	// subf r7,r3,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r3.s64;
	// fmadds f7,f30,f0,f31
	ctx.f7.f64 = double(float(ctx.f30.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// stw r6,2052(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2052, ctx.r6.u32);
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130380;
	sub_8214DC28(ctx, base);
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addi r5,r5,20888
	ctx.r5.s64 = ctx.r5.s64 + 20888;
	// lwz r4,2048(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2048);
	// stw r3,2056(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2056, ctx.r3.u32);
	// subf r3,r3,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r3.s64;
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// stw r11,2052(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2052, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_821303AC"))) PPC_WEAK_FUNC(sub_821303AC);
PPC_FUNC_IMPL(__imp__sub_821303AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821303B0"))) PPC_WEAK_FUNC(sub_821303B0);
PPC_FUNC_IMPL(__imp__sub_821303B0) {
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
	// stfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f29.u64);
	// stfd f30,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x8212fc88
	ctx.lr = 0x821303DC;
	sub_8212FC88(ctx, base);
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,22960
	ctx.r11.s64 = ctx.r11.s64 + 22960;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addis r9,r11,2
	ctx.r9.s64 = ctx.r11.s64 + 131072;
	// addis r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 131072;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lfs f31,12868(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12868);
	ctx.f31.f64 = double(temp.f32);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lfs f0,-19272(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19272);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// fmuls f29,f30,f0
	ctx.f29.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// ori r6,r7,8
	ctx.r6.u64 = ctx.r7.u64 | 8;
	// addi r3,r3,22992
	ctx.r3.s64 = ctx.r3.s64 + 22992;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 / ctx.f0.f64));
	// stfs f30,0(r8)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmadds f9,f10,f13,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f31.f64));
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// stwx r7,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r7.u32);
	// stfs f30,0(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// bl 0x8212e2f8
	ctx.lr = 0x8213045C;
	sub_8212E2F8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f0,-19200(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19200);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f7,f29,f0,f31
	ctx.f7.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130478;
	sub_8214DC28(ctx, base);
	// fadds f5,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(ctx.f29.f64 + ctx.f31.f64));
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// lis r11,5
	ctx.r11.s64 = 327680;
	// ori r10,r5,25092
	ctx.r10.u64 = ctx.r5.u64 | 25092;
	// ori r8,r11,25100
	ctx.r8.u64 = ctx.r11.u64 | 25100;
	// ori r9,r4,25096
	ctx.r9.u64 = ctx.r4.u64 | 25096;
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stwx r3,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r3.u32);
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
	// lfs f0,-19136(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19136);
	ctx.f0.f64 = double(temp.f32);
	// stwx r30,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u32);
	// fmadds f3,f29,f0,f31
	ctx.f3.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821304CC;
	sub_8214DC28(ctx, base);
	// addis r6,r31,5
	ctx.r6.s64 = ctx.r31.s64 + 327680;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r6,r6,25128
	ctx.r6.s64 = ctx.r6.s64 + 25128;
	// lfs f0,-19180(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19180);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,512(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 512);
	// fmadds f1,f29,f0,f31
	ctx.f1.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,520(r6)
	PPC_STORE_U32(ctx.r6.u32 + 520, ctx.r3.u32);
	// subf r3,r3,r4
	ctx.r3.s64 = ctx.r4.s64 - ctx.r3.s64;
	// clrlwi r11,r3,25
	ctx.r11.u64 = ctx.r3.u32 & 0x7F;
	// stw r11,516(r6)
	PPC_STORE_U32(ctx.r6.u32 + 516, ctx.r11.u32);
	// fctidz f0,f1
	ctx.f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130504;
	sub_8214DC28(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// lfs f0,-19156(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19156);
	ctx.f0.f64 = double(temp.f32);
	// ori r8,r9,33860
	ctx.r8.u64 = ctx.r9.u64 | 33860;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// stwx r3,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// fmadds f13,f29,f0,f31
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// ori r6,r7,33864
	ctx.r6.u64 = ctx.r7.u64 | 33864;
	// stwx r11,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r11.u32);
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8213053C;
	sub_8214DC28(ctx, base);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// ori r4,r5,33868
	ctx.r4.u64 = ctx.r5.u64 | 33868;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// stwx r3,r31,r4
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r3.u32);
	// lfs f0,-19140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19140);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f11,f29,f0,f31
	ctx.f11.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130564;
	sub_8214DC28(ctx, base);
	// addis r10,r31,6
	ctx.r10.s64 = ctx.r31.s64 + 393216;
	// addi r10,r10,-31640
	ctx.r10.s64 = ctx.r10.s64 + -31640;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r9,1024(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// stw r3,1032(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1032, ctx.r3.u32);
	// lfs f0,-19144(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -19144);
	ctx.f0.f64 = double(temp.f32);
	// subf r7,r3,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r3.s64;
	// fmadds f9,f29,f0,f31
	ctx.f9.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// stw r6,1028(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1028, ctx.r6.u32);
	// fctidz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8213059C;
	sub_8214DC28(ctx, base);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f0,-19148(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -19148);
	ctx.f0.f64 = double(temp.f32);
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// fmadds f7,f29,f0,f31
	ctx.f7.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r11,r11,-30592
	ctx.r11.s64 = ctx.r11.s64 + -30592;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// ori r8,r10,41116
	ctx.r8.u64 = ctx.r10.u64 | 41116;
	// lfs f0,-19168(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19168);
	ctx.f0.f64 = double(temp.f32);
	// ori r6,r9,41120
	ctx.r6.u64 = ctx.r9.u64 | 41120;
	// lwz r7,2048(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// fmadds f6,f29,f0,f31
	ctx.f6.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,2056(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2056, ctx.r3.u32);
	// subf r5,r3,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r3.s64;
	// fctidz f5,f7
	ctx.f5.s64 = (ctx.f7.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r4,r5,23
	ctx.r4.u64 = ctx.r5.u32 & 0x1FF;
	// stw r4,2052(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2052, ctx.r4.u32);
	// stwx r30,r31,r6
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u32);
	// fctidz f4,f6
	ctx.f4.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u32);
	// bl 0x8214dc28
	ctx.lr = 0x82130604;
	sub_8214DC28(ctx, base);
	// addis r10,r31,6
	ctx.r10.s64 = ctx.r31.s64 + 393216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r10,r10,-24396
	ctx.r10.s64 = ctx.r10.s64 + -24396;
	// lfs f0,-18424(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18424);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,2048(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2048);
	// fmadds f3,f29,f0,f31
	ctx.f3.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,2056(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2056, ctx.r3.u32);
	// subf r7,r3,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r3.s64;
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// stw r6,2052(r10)
	PPC_STORE_U32(ctx.r10.u32 + 2052, ctx.r6.u32);
	// fctidz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f2.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x8213063C;
	sub_8214DC28(ctx, base);
	// addis r5,r31,6
	ctx.r5.s64 = ctx.r31.s64 + 393216;
	// addi r5,r5,-22324
	ctx.r5.s64 = ctx.r5.s64 + -22324;
	// lwz r4,2048(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2048);
	// stw r3,2056(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2056, ctx.r3.u32);
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// stw r10,2052(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2052, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f30,-40(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8213067C"))) PPC_WEAK_FUNC(sub_8213067C);
PPC_FUNC_IMPL(__imp__sub_8213067C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130680"))) PPC_WEAK_FUNC(sub_82130680);
PPC_FUNC_IMPL(__imp__sub_82130680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f29.u64);
	// stfd f30,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x821303b0
	ctx.lr = 0x821306A8;
	sub_821303B0(ctx, base);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-19272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19272);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f29,f30,f0
	ctx.f29.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// lfs f0,-19132(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19132);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,12868(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12868);
	ctx.f31.f64 = double(temp.f32);
	// fmadds f0,f29,f0,f31
	ctx.f0.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x821306D8;
	sub_8214DC28(ctx, base);
	// addis r8,r31,6
	ctx.r8.s64 = ctx.r31.s64 + 393216;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r8,r8,-20252
	ctx.r8.s64 = ctx.r8.s64 + -20252;
	// lfs f0,-19136(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19136);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,2048(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2048);
	// fmadds f12,f29,f0,f31
	ctx.f12.f64 = double(float(ctx.f29.f64 * ctx.f0.f64 + ctx.f31.f64));
	// stw r3,2056(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2056, ctx.r3.u32);
	// subf r5,r3,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r3.s64;
	// clrlwi r4,r5,23
	ctx.r4.u64 = ctx.r5.u32 & 0x1FF;
	// stw r4,2052(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2052, ctx.r4.u32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8214dc28
	ctx.lr = 0x82130710;
	sub_8214DC28(ctx, base);
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// addi r11,r11,-18180
	ctx.r11.s64 = ctx.r11.s64 + -18180;
	// addis r9,r31,6
	ctx.r9.s64 = ctx.r31.s64 + 393216;
	// addi r9,r9,-16108
	ctx.r9.s64 = ctx.r9.s64 + -16108;
	// lwz r10,2048(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// stw r3,2056(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2056, ctx.r3.u32);
	// subf r8,r3,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r3.s64;
	// clrlwi r7,r8,23
	ctx.r7.u64 = ctx.r8.u32 & 0x1FF;
	// stw r7,2052(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2052, ctx.r7.u32);
	// lfs f10,2064(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2064);
	ctx.f10.f64 = double(temp.f32);
	// lwz r5,2052(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2052);
	// fdivs f9,f30,f10
	ctx.f9.f64 = double(float(ctx.f30.f64 / ctx.f10.f64));
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// stfs f30,2064(r9)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2064, temp.u32);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmadds f5,f9,f6,f31
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f6.f64 + ctx.f31.f64));
	// fctidz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r3,2052(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2052, ctx.r3.u32);
	// stw r3,2056(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2056, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-40(r1)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130790"))) PPC_WEAK_FUNC(sub_82130790);
PPC_FUNC_IMPL(__imp__sub_82130790) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x8213079c
	if (!ctx.cr6.eq) goto loc_8213079C;
	// b 0x8212fc88
	sub_8212FC88(ctx, base);
	return;
loc_8213079C:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x821307a8
	if (!ctx.cr6.eq) goto loc_821307A8;
	// b 0x821303b0
	sub_821303B0(ctx, base);
	return;
loc_821307A8:
	// b 0x82130680
	sub_82130680(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821307AC"))) PPC_WEAK_FUNC(sub_821307AC);
PPC_FUNC_IMPL(__imp__sub_821307AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821307B0"))) PPC_WEAK_FUNC(sub_821307B0);
PPC_FUNC_IMPL(__imp__sub_821307B0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x821307c4
	if (!ctx.cr6.eq) goto loc_821307C4;
	// b 0x8212e950
	sub_8212E950(ctx, base);
	return;
loc_821307C4:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x821307d0
	if (!ctx.cr6.eq) goto loc_821307D0;
	// b 0x8212f5c8
	sub_8212F5C8(ctx, base);
	return;
loc_821307D0:
	// b 0x8212fb90
	sub_8212FB90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821307D4"))) PPC_WEAK_FUNC(sub_821307D4);
PPC_FUNC_IMPL(__imp__sub_821307D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821307D8"))) PPC_WEAK_FUNC(sub_821307D8);
PPC_FUNC_IMPL(__imp__sub_821307D8) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130808;
	sub_8207DA20(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r3,r11,4
	ctx.r3.u64 = ctx.r11.u64 | 4;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// ori r11,r10,8
	ctx.r11.u64 = ctx.r10.u64 | 8;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// ori r10,r9,12
	ctx.r10.u64 = ctx.r9.u64 | 12;
	// stwx r30,r31,r3
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u32);
	// ori r9,r8,16
	ctx.r9.u64 = ctx.r8.u64 | 16;
	// ori r8,r7,20
	ctx.r8.u64 = ctx.r7.u64 | 20;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stwx r30,r31,r11
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u32);
	// ori r7,r6,24
	ctx.r7.u64 = ctx.r6.u64 | 24;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// stwx r30,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stfsx f31,r31,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,9388(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// stfsx f0,r31,r7
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stwx r6,r31,r4
	PPC_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130884"))) PPC_WEAK_FUNC(sub_82130884);
PPC_FUNC_IMPL(__imp__sub_82130884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130888"))) PPC_WEAK_FUNC(sub_82130888);
PPC_FUNC_IMPL(__imp__sub_82130888) {
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x821308B8;
	sub_8207DA20(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r11,2
	ctx.r11.s64 = 131072;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lfs f0,9388(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// lis r6,2
	ctx.r6.s64 = 131072;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// lis r3,2
	ctx.r3.s64 = 131072;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// ori r10,r10,8
	ctx.r10.u64 = ctx.r10.u64 | 8;
	// ori r9,r9,12
	ctx.r9.u64 = ctx.r9.u64 | 12;
	// ori r8,r8,16
	ctx.r8.u64 = ctx.r8.u64 | 16;
	// ori r7,r7,20
	ctx.r7.u64 = ctx.r7.u64 | 20;
	// ori r6,r6,24
	ctx.r6.u64 = ctx.r6.u64 | 24;
	// ori r5,r5,28
	ctx.r5.u64 = ctx.r5.u64 | 28;
	// rlwinm r4,r30,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// li r30,0
	ctx.r30.s64 = 0;
	// stfsx f31,r31,r8
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// stfsx f0,r31,r7
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stwx r4,r31,r11
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r4.u32);
	// stwx r30,r31,r3
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u32);
	// stfsx f0,r31,r6
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r6.u32, temp.u32);
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// stwx r4,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r4.u32);
	// stwx r4,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82130944"))) PPC_WEAK_FUNC(sub_82130944);
PPC_FUNC_IMPL(__imp__sub_82130944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82130948"))) PPC_WEAK_FUNC(sub_82130948);
PPC_FUNC_IMPL(__imp__sub_82130948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82130950;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,8
	ctx.r29.s64 = ctx.r3.s64 + 8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130970;
	sub_8207DA20(ctx, base);
	// lis r11,1
	ctx.r11.s64 = 65536;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r11,24
	ctx.r8.u64 = ctx.r11.u64 | 24;
	// addi r7,r7,36
	ctx.r7.s64 = ctx.r7.s64 + 36;
	// addi r28,r28,76
	ctx.r28.s64 = ctx.r28.s64 + 76;
	// lfs f31,9388(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stfsx f31,r29,r8
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r8.u32, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stwx r30,r29,r9
	PPC_STORE_U32(ctx.r29.u32 + ctx.r9.u32, ctx.r30.u32);
	// stfs f31,16(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 16, temp.u32);
	// stfs f31,20(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821309B8;
	sub_8207DA20(ctx, base);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// stfs f31,2076(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2076, temp.u32);
	// li r5,512
	ctx.r5.s64 = 512;
	// stfs f31,2080(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2080, temp.u32);
	// addi r29,r29,2164
	ctx.r29.s64 = ctx.r29.s64 + 2164;
	// stfs f31,2084(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2084, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x821309E0;
	sub_8207DA20(ctx, base);
	// lwz r6,520(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 520);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stfs f31,532(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 532, temp.u32);
	// neg r11,r6
	ctx.r11.s64 = -ctx.r6.s64;
	// stw r30,512(r29)
	PPC_STORE_U32(ctx.r29.u32 + 512, ctx.r30.u32);
	// addi r28,r28,2700
	ctx.r28.s64 = ctx.r28.s64 + 2700;
	// clrlwi r10,r11,25
	ctx.r10.u64 = ctx.r11.u32 & 0x7F;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,516(r29)
	PPC_STORE_U32(ctx.r29.u32 + 516, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130A10;
	sub_8207DA20(ctx, base);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// stfs f31,8220(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8220, temp.u32);
	// addi r29,r29,10932
	ctx.r29.s64 = ctx.r29.s64 + 10932;
	// stfs f31,8224(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8224, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,8228(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8228, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130A38;
	sub_8207DA20(ctx, base);
	// lwz r9,1032(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 1032);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stfs f31,1044(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 1044, temp.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r30,1024(r29)
	PPC_STORE_U32(ctx.r29.u32 + 1024, ctx.r30.u32);
	// addi r28,r28,11980
	ctx.r28.s64 = ctx.r28.s64 + 11980;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,1028(r29)
	PPC_STORE_U32(ctx.r29.u32 + 1028, ctx.r7.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130A68;
	sub_8207DA20(ctx, base);
	// lwz r6,2056(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r11,r6
	ctx.r11.s64 = -ctx.r6.s64;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// addi r29,r29,14052
	ctx.r29.s64 = ctx.r29.s64 + 14052;
	// clrlwi r10,r11,23
	ctx.r10.u64 = ctx.r11.u32 & 0x1FF;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r10.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130A98;
	sub_8207DA20(ctx, base);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r28,r28,18176
	ctx.r28.s64 = ctx.r28.s64 + 18176;
	// stfs f31,4116(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4116, temp.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stfs f31,4120(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4120, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,4096(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4096, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130ABC;
	sub_8207DA20(ctx, base);
	// lwz r9,2056(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// addi r29,r29,20248
	ctx.r29.s64 = ctx.r29.s64 + 20248;
	// clrlwi r7,r8,23
	ctx.r7.u64 = ctx.r8.u32 & 0x1FF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r7.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130AEC;
	sub_8207DA20(ctx, base);
	// lwz r9,2056(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2056);
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// stfs f31,2068(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stw r30,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r30.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r6,r6,22320
	ctx.r6.s64 = ctx.r6.s64 + 22320;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,22340
	ctx.r11.s64 = ctx.r11.s64 + 22340;
	// addi r10,r10,22368
	ctx.r10.s64 = ctx.r10.s64 + 22368;
	// clrlwi r7,r8,23
	ctx.r7.u64 = ctx.r8.u32 & 0x1FF;
	// addi r28,r28,22392
	ctx.r28.s64 = ctx.r28.s64 + 22392;
	// stw r7,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r7.u32);
	// stfs f31,0(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f31,4(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// li r5,16384
	ctx.r5.s64 = 16384;
	// stfs f31,16(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 16, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f31,0(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f31,4(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f31,24(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 24, temp.u32);
	// stfs f31,0(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,4(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,20(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130B58;
	sub_8207DA20(ctx, base);
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// stfs f31,16404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16404, temp.u32);
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// stfs f31,16408(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16408, temp.u32);
	// addi r6,r6,-26732
	ctx.r6.s64 = ctx.r6.s64 + -26732;
	// stw r30,16384(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16384, ctx.r30.u32);
	// addi r29,r29,-26712
	ctx.r29.s64 = ctx.r29.s64 + -26712;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f31,0(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f31,4(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f31,16(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 16, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130B90;
	sub_8207DA20(ctx, base);
	// lwz r11,2056(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2056);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stfs f31,2068(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r30,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r30.u32);
	// addi r28,r28,-24640
	ctx.r28.s64 = ctx.r28.s64 + -24640;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r9.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130BC0;
	sub_8207DA20(ctx, base);
	// addis r8,r31,2
	ctx.r8.s64 = ctx.r31.s64 + 131072;
	// addis r7,r31,2
	ctx.r7.s64 = ctx.r31.s64 + 131072;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// addi r8,r8,-22568
	ctx.r8.s64 = ctx.r8.s64 + -22568;
	// addi r7,r7,-22548
	ctx.r7.s64 = ctx.r7.s64 + -22548;
	// addi r6,r6,-22520
	ctx.r6.s64 = ctx.r6.s64 + -22520;
	// lwz r11,2056(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// addi r29,r29,-22496
	ctx.r29.s64 = ctx.r29.s64 + -22496;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r9.u32);
	// stfs f31,0(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f31,4(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f31,16(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// stfs f31,0(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f31,4(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f31,24(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 24, temp.u32);
	// stfs f31,0(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f31,4(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f31,20(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 20, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130C2C;
	sub_8207DA20(ctx, base);
	// addis r8,r31,2
	ctx.r8.s64 = ctx.r31.s64 + 131072;
	// stfs f31,16404(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16404, temp.u32);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// stfs f31,16408(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16408, temp.u32);
	// addi r8,r8,-6084
	ctx.r8.s64 = ctx.r8.s64 + -6084;
	// stw r30,16384(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16384, ctx.r30.u32);
	// addi r28,r28,-6064
	ctx.r28.s64 = ctx.r28.s64 + -6064;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f31,0(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f31,4(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stfs f31,16(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130C64;
	sub_8207DA20(ctx, base);
	// lwz r7,8200(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8200);
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// stfs f31,8212(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8212, temp.u32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// addi r29,r29,2152
	ctx.r29.s64 = ctx.r29.s64 + 2152;
	// clrlwi r11,r6,21
	ctx.r11.u64 = ctx.r6.u32 & 0x7FF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r11.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130C94;
	sub_8207DA20(ctx, base);
	// lwz r10,8200(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8200);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// stfs f31,8216(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 8216, temp.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r30,8192(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8192, ctx.r30.u32);
	// addi r28,r28,10372
	ctx.r28.s64 = ctx.r28.s64 + 10372;
	// clrlwi r8,r9,21
	ctx.r8.u64 = ctx.r9.u32 & 0x7FF;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,8196(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8196, ctx.r8.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130CC4;
	sub_8207DA20(ctx, base);
	// lwz r7,8200(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8200);
	// addis r29,r31,2
	ctx.r29.s64 = ctx.r31.s64 + 131072;
	// stfs f31,8212(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8212, temp.u32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// addi r29,r29,18588
	ctx.r29.s64 = ctx.r29.s64 + 18588;
	// clrlwi r11,r6,21
	ctx.r11.u64 = ctx.r6.u32 & 0x7FF;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130CF4;
	sub_8207DA20(ctx, base);
	// lwz r10,4104(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4104);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// stfs f31,4116(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4116, temp.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r30,4096(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4096, ctx.r30.u32);
	// addi r28,r28,22708
	ctx.r28.s64 = ctx.r28.s64 + 22708;
	// clrlwi r8,r9,22
	ctx.r8.u64 = ctx.r9.u32 & 0x3FF;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,4100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4100, ctx.r8.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130D24;
	sub_8207DA20(ctx, base);
	// addis r7,r31,3
	ctx.r7.s64 = ctx.r31.s64 + 196608;
	// stfs f31,16404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16404, temp.u32);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// stfs f31,16408(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16408, temp.u32);
	// addi r7,r7,-26416
	ctx.r7.s64 = ctx.r7.s64 + -26416;
	// stw r30,16384(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16384, ctx.r30.u32);
	// addi r29,r29,-26392
	ctx.r29.s64 = ctx.r29.s64 + -26392;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f31,0(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// stfs f31,4(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// stfs f31,20(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130D5C;
	sub_8207DA20(ctx, base);
	// lwz r6,8200(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8200);
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// stfs f31,8212(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 8212, temp.u32);
	// neg r11,r6
	ctx.r11.s64 = -ctx.r6.s64;
	// stw r30,8192(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8192, ctx.r30.u32);
	// addi r28,r28,-18176
	ctx.r28.s64 = ctx.r28.s64 + -18176;
	// clrlwi r10,r11,21
	ctx.r10.u64 = ctx.r11.u32 & 0x7FF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,8196(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8196, ctx.r10.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130D8C;
	sub_8207DA20(ctx, base);
	// lwz r9,8200(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8200);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// stfs f31,8216(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// addi r29,r29,-9956
	ctx.r29.s64 = ctx.r29.s64 + -9956;
	// clrlwi r7,r8,21
	ctx.r7.u64 = ctx.r8.u32 & 0x7FF;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r7.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130DBC;
	sub_8207DA20(ctx, base);
	// lwz r6,8200(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8200);
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// stfs f31,8212(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 8212, temp.u32);
	// neg r11,r6
	ctx.r11.s64 = -ctx.r6.s64;
	// stw r30,8192(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8192, ctx.r30.u32);
	// addi r28,r28,-1740
	ctx.r28.s64 = ctx.r28.s64 + -1740;
	// clrlwi r10,r11,21
	ctx.r10.u64 = ctx.r11.u32 & 0x7FF;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8196(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8196, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130DEC;
	sub_8207DA20(ctx, base);
	// lwz r9,4104(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4104);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// stfs f31,4116(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4116, temp.u32);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r30,4096(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4096, ctx.r30.u32);
	// addi r29,r29,2380
	ctx.r29.s64 = ctx.r29.s64 + 2380;
	// clrlwi r7,r8,22
	ctx.r7.u64 = ctx.r8.u32 & 0x3FF;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,4100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4100, ctx.r7.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130E1C;
	sub_8207DA20(ctx, base);
	// addis r6,r31,3
	ctx.r6.s64 = ctx.r31.s64 + 196608;
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// stfs f31,16404(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16404, temp.u32);
	// addi r6,r6,18792
	ctx.r6.s64 = ctx.r6.s64 + 18792;
	// stfs f31,16408(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16408, temp.u32);
	// addi r28,r28,18816
	ctx.r28.s64 = ctx.r28.s64 + 18816;
	// stw r30,16384(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16384, ctx.r30.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f31,0(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f31,4(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f31,20(r6)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 20, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130E54;
	sub_8207DA20(ctx, base);
	// addis r31,r31,3
	ctx.r31.s64 = ctx.r31.s64 + 196608;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// addi r31,r31,20888
	ctx.r31.s64 = ctx.r31.s64 + 20888;
	// lwz r11,2056(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r9.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130E84;
	sub_8207DA20(ctx, base);
	// lwz r8,2056(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2056);
	// stfs f31,2068(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 2068, temp.u32);
	// stw r30,2048(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2048, ctx.r30.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// stw r6,2052(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2052, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82130EA8"))) PPC_WEAK_FUNC(sub_82130EA8);
PPC_FUNC_IMPL(__imp__sub_82130EA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82130EB0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82130948
	ctx.lr = 0x82130EC0;
	sub_82130948(ctx, base);
	// addis r29,r30,3
	ctx.r29.s64 = ctx.r30.s64 + 196608;
	// lis r5,2
	ctx.r5.s64 = 131072;
	// addi r29,r29,22960
	ctx.r29.s64 = ctx.r29.s64 + 22960;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130ED8;
	sub_8207DA20(ctx, base);
	// lis r11,2
	ctx.r11.s64 = 131072;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// ori r7,r11,24
	ctx.r7.u64 = ctx.r11.u64 | 24;
	// addis r11,r30,5
	ctx.r11.s64 = ctx.r30.s64 + 327680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addis r28,r30,5
	ctx.r28.s64 = ctx.r30.s64 + 327680;
	// lis r8,2
	ctx.r8.s64 = 131072;
	// ori r6,r10,28
	ctx.r6.u64 = ctx.r10.u64 | 28;
	// addi r11,r11,22992
	ctx.r11.s64 = ctx.r11.s64 + 22992;
	// addi r28,r28,23040
	ctx.r28.s64 = ctx.r28.s64 + 23040;
	// lfs f31,9388(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// li r31,0
	ctx.r31.s64 = 0;
	// stfsx f31,r29,r7
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r7.u32, temp.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stfsx f31,r29,r6
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r6.u32, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stwx r31,r29,r8
	PPC_STORE_U32(ctx.r29.u32 + ctx.r8.u32, ctx.r31.u32);
	// stfs f31,16(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f31,28(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130F2C;
	sub_8207DA20(ctx, base);
	// addis r29,r30,5
	ctx.r29.s64 = ctx.r30.s64 + 327680;
	// stfs f31,2076(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2076, temp.u32);
	// li r5,512
	ctx.r5.s64 = 512;
	// stfs f31,2080(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2080, temp.u32);
	// addi r29,r29,25128
	ctx.r29.s64 = ctx.r29.s64 + 25128;
	// stfs f31,2084(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2084, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130F54;
	sub_8207DA20(ctx, base);
	// lwz r10,520(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 520);
	// addis r28,r30,5
	ctx.r28.s64 = ctx.r30.s64 + 327680;
	// stfs f31,532(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 532, temp.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r31,512(r29)
	PPC_STORE_U32(ctx.r29.u32 + 512, ctx.r31.u32);
	// addi r28,r28,25664
	ctx.r28.s64 = ctx.r28.s64 + 25664;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,516(r29)
	PPC_STORE_U32(ctx.r29.u32 + 516, ctx.r8.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130F84;
	sub_8207DA20(ctx, base);
	// addis r29,r30,6
	ctx.r29.s64 = ctx.r30.s64 + 393216;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// stfs f31,8220(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8220, temp.u32);
	// addi r29,r29,-31640
	ctx.r29.s64 = ctx.r29.s64 + -31640;
	// stfs f31,8224(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8224, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,8228(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8228, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r31.u32);
	// bl 0x8207da20
	ctx.lr = 0x82130FAC;
	sub_8207DA20(ctx, base);
	// lwz r7,1032(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 1032);
	// addis r28,r30,6
	ctx.r28.s64 = ctx.r30.s64 + 393216;
	// stfs f31,1044(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 1044, temp.u32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stw r31,1024(r29)
	PPC_STORE_U32(ctx.r29.u32 + 1024, ctx.r31.u32);
	// addi r28,r28,-30592
	ctx.r28.s64 = ctx.r28.s64 + -30592;
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,1028(r29)
	PPC_STORE_U32(ctx.r29.u32 + 1028, ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82130FDC;
	sub_8207DA20(ctx, base);
	// addis r29,r30,6
	ctx.r29.s64 = ctx.r30.s64 + 393216;
	// lwz r10,2056(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// addi r29,r29,-28520
	ctx.r29.s64 = ctx.r29.s64 + -28520;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// stw r8,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r8.u32);
	// bl 0x8207da20
	ctx.lr = 0x8213100C;
	sub_8207DA20(ctx, base);
	// addis r28,r30,6
	ctx.r28.s64 = ctx.r30.s64 + 393216;
	// stfs f31,4116(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4116, temp.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stfs f31,4120(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4120, temp.u32);
	// addi r28,r28,-24396
	ctx.r28.s64 = ctx.r28.s64 + -24396;
	// stw r31,4096(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4096, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82131030;
	sub_8207DA20(ctx, base);
	// lwz r7,2056(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r30,r30,6
	ctx.r30.s64 = ctx.r30.s64 + 393216;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// addi r30,r30,-22324
	ctx.r30.s64 = ctx.r30.s64 + -22324;
	// clrlwi r11,r6,23
	ctx.r11.u64 = ctx.r6.u32 & 0x1FF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82131060;
	sub_8207DA20(ctx, base);
	// lwz r10,2056(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2056);
	// stfs f31,2068(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2068, temp.u32);
	// stw r31,2048(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2048, ctx.r31.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// stw r8,2052(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2052, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82131084"))) PPC_WEAK_FUNC(sub_82131084);
PPC_FUNC_IMPL(__imp__sub_82131084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131088"))) PPC_WEAK_FUNC(sub_82131088);
PPC_FUNC_IMPL(__imp__sub_82131088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82131090;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82130ea8
	ctx.lr = 0x821310A0;
	sub_82130EA8(ctx, base);
	// addis r29,r30,6
	ctx.r29.s64 = ctx.r30.s64 + 393216;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// addi r29,r29,-20252
	ctx.r29.s64 = ctx.r29.s64 + -20252;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x821310B8;
	sub_8207DA20(ctx, base);
	// lwz r10,2056(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2056);
	// addis r28,r30,6
	ctx.r28.s64 = ctx.r30.s64 + 393216;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// addi r28,r28,-18180
	ctx.r28.s64 = ctx.r28.s64 + -18180;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// lfs f31,9388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,2068(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r31,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r31.u32);
	// stw r8,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r8.u32);
	// bl 0x8207da20
	ctx.lr = 0x821310F4;
	sub_8207DA20(ctx, base);
	// lwz r7,2056(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r30,r30,6
	ctx.r30.s64 = ctx.r30.s64 + 393216;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// addi r30,r30,-16108
	ctx.r30.s64 = ctx.r30.s64 + -16108;
	// clrlwi r11,r6,23
	ctx.r11.u64 = ctx.r6.u32 & 0x1FF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82131124;
	sub_8207DA20(ctx, base);
	// stfs f31,2072(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2072, temp.u32);
	// stfs f31,2076(r30)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2076, temp.u32);
	// stw r31,2048(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2048, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213113C"))) PPC_WEAK_FUNC(sub_8213113C);
PPC_FUNC_IMPL(__imp__sub_8213113C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82131140"))) PPC_WEAK_FUNC(sub_82131140);
PPC_FUNC_IMPL(__imp__sub_82131140) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x82131148;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080360
	ctx.lr = 0x82131150;
	__savefpr_26(ctx, base);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stw r5,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r5.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r6,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r6.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r4,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r4.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r7,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r7.u32);
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x8212e470
	ctx.lr = 0x82131184;
	sub_8212E470(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bl 0x8212df08
	ctx.lr = 0x82131198;
	sub_8212DF08(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f31,f12
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// ble cr6,0x821311b0
	if (!ctx.cr6.gt) goto loc_821311B0;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_821311B0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821320e0
	if (ctx.cr6.eq) goto loc_821320E0;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,2152
	ctx.r11.s64 = ctx.r11.s64 + 2152;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// stw r11,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r11.u32);
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,2156
	ctx.r10.s64 = ctx.r10.s64 + 2156;
	// addi r9,r9,2160
	ctx.r9.s64 = ctx.r9.s64 + 2160;
	// addi r8,r8,2696
	ctx.r8.s64 = ctx.r8.s64 + 2696;
	// stw r10,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r10.u32);
	// addi r7,r7,10920
	ctx.r7.s64 = ctx.r7.s64 + 10920;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// addi r6,r6,10924
	ctx.r6.s64 = ctx.r6.s64 + 10924;
	// stw r8,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r8.u32);
	// addi r5,r5,10928
	ctx.r5.s64 = ctx.r5.s64 + 10928;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stw r6,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r6.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r5,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,11976
	ctx.r4.s64 = ctx.r4.s64 + 11976;
	// addi r3,r3,14048
	ctx.r3.s64 = ctx.r3.s64 + 14048;
	// addi r11,r11,68
	ctx.r11.s64 = ctx.r11.s64 + 68;
	// stw r4,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r4.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 + 72;
	// addi r9,r9,18168
	ctx.r9.s64 = ctx.r9.s64 + 18168;
	// addi r8,r8,18172
	ctx.r8.s64 = ctx.r8.s64 + 18172;
	// stw r10,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r10.u32);
	// addi r7,r7,22340
	ctx.r7.s64 = ctx.r7.s64 + 22340;
	// stw r9,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r9.u32);
	// addi r6,r6,22368
	ctx.r6.s64 = ctx.r6.s64 + 22368;
	// stw r8,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r8.u32);
	// addi r5,r5,22320
	ctx.r5.s64 = ctx.r5.s64 + 22320;
	// stw r7,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r7.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// stw r6,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r6.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r5,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r5.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,-26732
	ctx.r4.s64 = ctx.r4.s64 + -26732;
	// addi r3,r3,-22568
	ctx.r3.s64 = ctx.r3.s64 + -22568;
	// addi r11,r11,20244
	ctx.r11.s64 = ctx.r11.s64 + 20244;
	// stw r4,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r4.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stw r11,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r11.u32);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// addi r10,r10,22316
	ctx.r10.s64 = ctx.r10.s64 + 22316;
	// addi r9,r9,22336
	ctx.r9.s64 = ctx.r9.s64 + 22336;
	// addi r8,r8,22364
	ctx.r8.s64 = ctx.r8.s64 + 22364;
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// addi r7,r7,22388
	ctx.r7.s64 = ctx.r7.s64 + 22388;
	// stw r9,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r9.u32);
	// addi r6,r6,-26740
	ctx.r6.s64 = ctx.r6.s64 + -26740;
	// stw r8,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
	// addi r5,r5,-26716
	ctx.r5.s64 = ctx.r5.s64 + -26716;
	// stw r7,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r7.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// stw r6,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r6.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r5,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r5.u32);
	// addis r11,r31,2
	ctx.r11.s64 = ctx.r31.s64 + 131072;
	// addi r4,r4,-26736
	ctx.r4.s64 = ctx.r4.s64 + -26736;
	// addi r3,r3,-24644
	ctx.r3.s64 = ctx.r3.s64 + -24644;
	// addi r11,r11,-22572
	ctx.r11.s64 = ctx.r11.s64 + -22572;
	// addis r8,r31,2
	ctx.r8.s64 = ctx.r31.s64 + 131072;
	// stw r4,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r4.u32);
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// stw r3,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r3.u32);
	// addi r8,r8,-22548
	ctx.r8.s64 = ctx.r8.s64 + -22548;
	// stw r11,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r11.u32);
	// addi r5,r5,-22496
	ctx.r5.s64 = ctx.r5.s64 + -22496;
	// lwz r25,580(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 580);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addis r24,r31,2
	ctx.r24.s64 = ctx.r31.s64 + 131072;
	// stw r5,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r5.u32);
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// addi r24,r24,22708
	ctx.r24.s64 = ctx.r24.s64 + 22708;
	// lwz r23,596(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 596);
	// addi r5,r5,-6084
	ctx.r5.s64 = ctx.r5.s64 + -6084;
	// lwz r21,588(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 588);
	// addis r22,r31,2
	ctx.r22.s64 = ctx.r31.s64 + 131072;
	// stw r24,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r24.u32);
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// addis r10,r31,2
	ctx.r10.s64 = ctx.r31.s64 + 131072;
	// addi r22,r22,-22500
	ctx.r22.s64 = ctx.r22.s64 + -22500;
	// addis r9,r31,2
	ctx.r9.s64 = ctx.r31.s64 + 131072;
	// addis r7,r31,2
	ctx.r7.s64 = ctx.r31.s64 + 131072;
	// stw r22,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// addis r20,r31,2
	ctx.r20.s64 = ctx.r31.s64 + 131072;
	// addis r19,r31,2
	ctx.r19.s64 = ctx.r31.s64 + 131072;
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// addis r24,r31,2
	ctx.r24.s64 = ctx.r31.s64 + 131072;
	// addi r10,r10,-22552
	ctx.r10.s64 = ctx.r10.s64 + -22552;
	// addi r9,r9,-22524
	ctx.r9.s64 = ctx.r9.s64 + -22524;
	// addi r7,r7,-22520
	ctx.r7.s64 = ctx.r7.s64 + -22520;
	// stw r10,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r10.u32);
	// addi r20,r20,-6092
	ctx.r20.s64 = ctx.r20.s64 + -6092;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r19,r19,-6068
	ctx.r19.s64 = ctx.r19.s64 + -6068;
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r5,r5,2148
	ctx.r5.s64 = ctx.r5.s64 + 2148;
	// stw r20,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r20.u32);
	// addi r24,r24,10368
	ctx.r24.s64 = ctx.r24.s64 + 10368;
	// stw r19,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r19.u32);
	// addis r6,r31,3
	ctx.r6.s64 = ctx.r31.s64 + 196608;
	// stw r5,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r5.u32);
	// addis r22,r31,2
	ctx.r22.s64 = ctx.r31.s64 + 131072;
	// stw r24,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r24.u32);
	// addi r6,r6,-26416
	ctx.r6.s64 = ctx.r6.s64 + -26416;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r6,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r6.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lwz r6,572(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 572);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// addis r7,r31,2
	ctx.r7.s64 = ctx.r31.s64 + 131072;
	// addis r27,r31,2
	ctx.r27.s64 = ctx.r31.s64 + 131072;
	// addis r26,r31,2
	ctx.r26.s64 = ctx.r31.s64 + 131072;
	// addi r22,r22,18584
	ctx.r22.s64 = ctx.r22.s64 + 18584;
	// addis r20,r31,2
	ctx.r20.s64 = ctx.r31.s64 + 131072;
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// stw r22,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r22.u32);
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addis r24,r31,3
	ctx.r24.s64 = ctx.r31.s64 + 196608;
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// addi r10,r10,2700
	ctx.r10.s64 = ctx.r10.s64 + 2700;
	// addi r9,r9,14052
	ctx.r9.s64 = ctx.r9.s64 + 14052;
	// addi r4,r4,2164
	ctx.r4.s64 = ctx.r4.s64 + 2164;
	// addi r3,r3,10932
	ctx.r3.s64 = ctx.r3.s64 + 10932;
	// addi r30,r30,11980
	ctx.r30.s64 = ctx.r30.s64 + 11980;
	// addi r8,r8,22392
	ctx.r8.s64 = ctx.r8.s64 + 22392;
	// addi r29,r29,20248
	ctx.r29.s64 = ctx.r29.s64 + 20248;
	// addi r28,r28,-24640
	ctx.r28.s64 = ctx.r28.s64 + -24640;
	// addi r7,r7,2152
	ctx.r7.s64 = ctx.r7.s64 + 2152;
	// addi r27,r27,10372
	ctx.r27.s64 = ctx.r27.s64 + 10372;
	// addi r26,r26,18588
	ctx.r26.s64 = ctx.r26.s64 + 18588;
	// addi r20,r20,22704
	ctx.r20.s64 = ctx.r20.s64 + 22704;
	// addi r19,r19,-26424
	ctx.r19.s64 = ctx.r19.s64 + -26424;
	// addi r5,r5,-26396
	ctx.r5.s64 = ctx.r5.s64 + -26396;
	// addi r24,r24,18792
	ctx.r24.s64 = ctx.r24.s64 + 18792;
	// addis r22,r31,2
	ctx.r22.s64 = ctx.r31.s64 + 131072;
	// stw r20,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r20.u32);
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// stw r19,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r19.u32);
	// addi r22,r22,-6064
	ctx.r22.s64 = ctx.r22.s64 + -6064;
	// stw r5,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r5.u32);
	// addi r20,r20,-26392
	ctx.r20.s64 = ctx.r20.s64 + -26392;
	// stw r24,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r24.u32);
	// stw r22,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r22.u32);
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// stw r20,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r20.u32);
	// addis r24,r31,3
	ctx.r24.s64 = ctx.r31.s64 + 196608;
	// mtctr r23
	ctx.ctr.u64 = ctx.r23.u64;
	// addis r22,r31,3
	ctx.r22.s64 = ctx.r31.s64 + 196608;
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r21.u32);
	// addi r19,r19,-18180
	ctx.r19.s64 = ctx.r19.s64 + -18180;
	// addi r5,r5,-9960
	ctx.r5.s64 = ctx.r5.s64 + -9960;
	// addi r24,r24,-1744
	ctx.r24.s64 = ctx.r24.s64 + -1744;
	// stw r19,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r19.u32);
	// addi r22,r22,2376
	ctx.r22.s64 = ctx.r22.s64 + 2376;
	// stw r5,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r5.u32);
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// stw r24,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r24.u32);
	// stw r22,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r22.u32);
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// addi r20,r20,18784
	ctx.r20.s64 = ctx.r20.s64 + 18784;
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// addis r24,r31,3
	ctx.r24.s64 = ctx.r31.s64 + 196608;
	// stw r20,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r20.u32);
	// addis r22,r31,3
	ctx.r22.s64 = ctx.r31.s64 + 196608;
	// addi r19,r19,18812
	ctx.r19.s64 = ctx.r19.s64 + 18812;
	// addi r20,r6,-4
	ctx.r20.s64 = ctx.r6.s64 + -4;
	// addi r5,r5,18788
	ctx.r5.s64 = ctx.r5.s64 + 18788;
	// stw r19,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r19.u32);
	// addi r24,r24,20884
	ctx.r24.s64 = ctx.r24.s64 + 20884;
	// stw r20,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r20.u32);
	// addi r22,r22,22956
	ctx.r22.s64 = ctx.r22.s64 + 22956;
	// stw r5,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r5.u32);
	// lis r18,-32256
	ctx.r18.s64 = -2113929216;
	// stw r24,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r24.u32);
	// lis r17,-32256
	ctx.r17.s64 = -2113929216;
	// stw r22,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r22.u32);
	// lis r16,-32256
	ctx.r16.s64 = -2113929216;
	// addi r19,r25,-4
	ctx.r19.s64 = ctx.r25.s64 + -4;
	// addis r6,r31,3
	ctx.r6.s64 = ctx.r31.s64 + 196608;
	// addis r5,r31,3
	ctx.r5.s64 = ctx.r31.s64 + 196608;
	// stw r19,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r19.u32);
	// addis r25,r31,3
	ctx.r25.s64 = ctx.r31.s64 + 196608;
	// lwz r19,84(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addis r24,r31,3
	ctx.r24.s64 = ctx.r31.s64 + 196608;
	// lfs f9,14004(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 14004);
	ctx.f9.f64 = double(temp.f32);
	// addis r23,r31,1
	ctx.r23.s64 = ctx.r31.s64 + 65536;
	// lfs f10,23040(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 23040);
	ctx.f10.f64 = double(temp.f32);
	// addis r22,r31,2
	ctx.r22.s64 = ctx.r31.s64 + 131072;
	// lfs f11,12864(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 12864);
	ctx.f11.f64 = double(temp.f32);
	// addis r21,r31,3
	ctx.r21.s64 = ctx.r31.s64 + 196608;
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// addi r6,r6,2380
	ctx.r6.s64 = ctx.r6.s64 + 2380;
	// addi r5,r5,-18176
	ctx.r5.s64 = ctx.r5.s64 + -18176;
	// addi r25,r25,-9956
	ctx.r25.s64 = ctx.r25.s64 + -9956;
	// addi r24,r24,-1740
	ctx.r24.s64 = ctx.r24.s64 + -1740;
	// addi r23,r23,18176
	ctx.r23.s64 = ctx.r23.s64 + 18176;
	// addi r22,r22,-26712
	ctx.r22.s64 = ctx.r22.s64 + -26712;
	// addi r21,r21,18816
	ctx.r21.s64 = ctx.r21.s64 + 18816;
	// addi r20,r20,20888
	ctx.r20.s64 = ctx.r20.s64 + 20888;
loc_82131548:
	// lwz r18,2048(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// lfs f13,2064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2064);
	ctx.f13.f64 = double(temp.f32);
	// lwz r17,2052(r11)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2052);
	// lfs f8,2068(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2068);
	ctx.f8.f64 = double(temp.f32);
	// lwz r16,2056(r11)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2056);
	// rlwinm r15,r18,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r14,2060(r11)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2060);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// std r20,328(r1)
	PPC_STORE_U64(ctx.r1.u32 + 328, ctx.r20.u64);
	// subf r18,r14,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r14.s64;
	// lwz r20,204(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r14,292(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// rlwinm r17,r17,2,21,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x7FC;
	// rlwinm r16,r16,2,21,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x7FC;
	// std r21,320(r1)
	PPC_STORE_U64(ctx.r1.u32 + 320, ctx.r21.u64);
	// rlwinm r18,r18,2,21,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x7FC;
	// lwz r21,100(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// std r19,312(r1)
	PPC_STORE_U64(ctx.r1.u32 + 312, ctx.r19.u64);
	// lfs f7,2072(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2072);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lwz r19,80(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f5,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r14,212(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lfsx f1,r17,r11
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fadds f2,f5,f6
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lfsx f6,r16,r11
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f13,f1
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// lfsx f1,r18,r11
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r11.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f13,f8,f6
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// lfs f4,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f8,f7,f1
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f1.f64));
	// stfs f5,2076(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2076, temp.u32);
	// lwz r16,268(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// stfs f13,2080(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2080, temp.u32);
	// lwz r21,108(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfs f8,2084(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2084, temp.u32);
	// lwz r20,116(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lfs f3,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// stfsx f3,r15,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r11.u32, temp.u32);
	// lwz r18,2048(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2048(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2048, ctx.r18.u32);
	// lfs f7,524(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 524);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,512(r4)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 512);
	// lfs f6,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lwz r17,516(r4)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r4.u32 + 516);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r17,r4
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r4.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,528(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 528);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f7,f5,f2
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f5.f64 + ctx.f2.f64));
	// stfsx f2,r18,r4
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r4.u32, temp.u32);
	// lwz r17,512(r4)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r4.u32 + 512);
	// lwz r18,516(r4)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 516);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// fmadds f1,f3,f2,f5
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f5.f64));
	// clrlwi r18,r18,25
	ctx.r18.u64 = ctx.r18.u32 & 0x7F;
	// stfs f1,532(r4)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r4.u32 + 532, temp.u32);
	// clrlwi r17,r17,25
	ctx.r17.u64 = ctx.r17.u32 & 0x7F;
	// stw r18,516(r4)
	PPC_STORE_U32(ctx.r4.u32 + 516, ctx.r18.u32);
	// stw r17,512(r4)
	PPC_STORE_U32(ctx.r4.u32 + 512, ctx.r17.u32);
	// lfs f13,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r18,8200(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8200);
	// lfs f8,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,8204(r10)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8204);
	// lfs f7,8208(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8208);
	ctx.f7.f64 = double(temp.f32);
	// lwz r16,8192(r10)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// lfs f5,8212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8212);
	ctx.f5.f64 = double(temp.f32);
	// lwz r15,8196(r10)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8196);
	// subf r15,r15,r16
	ctx.r15.s64 = ctx.r16.s64 - ctx.r15.s64;
	// rlwinm r15,r15,2,19,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x1FFC;
	// fadds f1,f8,f13
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// lfs f3,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,8216(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8216);
	ctx.f2.f64 = double(temp.f32);
	// subf r17,r17,r16
	ctx.r17.s64 = ctx.r16.s64 - ctx.r17.s64;
	// rlwinm r18,r18,2,19,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x1FFC;
	// lfsx f13,r15,r10
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r17,r17,2,19,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x1FFC;
	// fmuls f8,f13,f7
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// lfsx f7,r18,r10
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r10.u32);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,140(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f7,f5,f7
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f7.f64));
	// lwz r15,220(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// lwz r14,124(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lfsx f13,r17,r10
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwz r20,132(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// fmuls f5,f2,f13
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// stfs f8,8220(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8220, temp.u32);
	// stfs f5,8228(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8228, temp.u32);
	// stw r18,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r18.u32);
	// stfs f7,8224(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8224, temp.u32);
	// lwz r21,304(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// stfsx f6,r16,r10
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r10.u32, temp.u32);
	// lwz r18,8192(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lwz r19,228(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// stw r18,8192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8192, ctx.r18.u32);
	// lfs f2,1036(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1036);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,1024(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1024);
	// lfs f13,1040(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 1040);
	ctx.f13.f64 = double(temp.f32);
	// lwz r17,1028(r3)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1028);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f8,r17,r3
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r3.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f5,f8,f2,f1
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f2.f64 + ctx.f1.f64));
	// stfsx f5,r18,r3
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r3.u32, temp.u32);
	// lwz r18,1028(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1028);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// fmadds f2,f13,f5,f8
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f8.f64));
	// lwz r18,1024(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1024);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r17,r17,24
	ctx.r17.u64 = ctx.r17.u32 & 0xFF;
	// stfs f2,1044(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1044, temp.u32);
	// clrlwi r18,r18,24
	ctx.r18.u64 = ctx.r18.u32 & 0xFF;
	// lwz r15,84(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r17,1028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1028, ctx.r17.u32);
	// stw r18,1024(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1024, ctx.r18.u32);
	// lfs f1,2060(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 2060);
	ctx.f1.f64 = double(temp.f32);
	// lwz r18,2048(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2048);
	// lfs f5,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r17,2052(r30)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2052);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f8,r17,r30
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r30.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f2,f1,f8,f7
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f8.f64 + ctx.f7.f64));
	// lfs f13,2064(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 2064);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f2,r18,r30
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r30.u32, temp.u32);
	// fmadds f1,f2,f13,f8
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f8.f64));
	// stfs f1,2068(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2068, temp.u32);
	// lwz r17,2048(r30)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2048);
	// lwz r18,2052(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2052);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r18,2052(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2052, ctx.r18.u32);
	// stw r17,2048(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2048, ctx.r17.u32);
	// lfs f8,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r18,4096(r9)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4096);
	// lfs f1,4108(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4108);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,4100(r9)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4100);
	// lfs f2,4112(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4112);
	ctx.f2.f64 = double(temp.f32);
	// lwz r16,4104(r9)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4104);
	// lfs f30,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfs f13,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// fmuls f8,f8,f6
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// lfs f6,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r17,r17,2,20,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r17,r9
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r9.u32);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r17,r16,2,20,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFC;
	// fmuls f1,f7,f1
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f1.f64));
	// fadds f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f8.f64));
	// lfsx f8,r17,r9
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r9.u32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f1,4116(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4116, temp.u32);
	// fmuls f7,f8,f2
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f2.f64));
	// stfs f7,4120(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4120, temp.u32);
	// lwz r16,276(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// stfsx f5,r18,r9
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r9.u32, temp.u32);
	// lwz r18,4096(r9)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4096);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lwz r15,148(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r18,r18,22
	ctx.r18.u64 = ctx.r18.u32 & 0x3FF;
	// fadds f5,f13,f4
	ctx.f5.f64 = double(float(ctx.f13.f64 + ctx.f4.f64));
	// lwz r14,236(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// stw r18,4096(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4096, ctx.r18.u32);
	// lfs f4,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f1,2060(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 2060);
	ctx.f1.f64 = double(temp.f32);
	// lwz r18,2052(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f2,r18,r29
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r29.u32);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,2048(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2048);
	// fmadds f8,f2,f1,f4
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f4.f64));
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f4,2064(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 2064);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f5,f5,f13
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// lwz r21,156(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// fmadds f13,f4,f8,f2
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f8.f64 + ctx.f2.f64));
	// lwz r20,300(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// fadds f1,f7,f3
	ctx.f1.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// stfsx f8,r18,r29
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r29.u32, temp.u32);
	// lwz r18,2048(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2048);
	// lwz r17,2052(r29)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2052);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stfs f13,2068(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// lwz r18,164(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// stw r17,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r17.u32);
	// clrlwi r17,r16,23
	ctx.r17.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r17.u32);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f8,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f2,f8,f7,f1
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f1.f64));
	// lfs f13,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f4,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// stfs f13,4(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f2,16(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// lwz r18,244(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// lfs f8,20(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f2,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f13,f2,f8
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f8.f64));
	// lfs f8,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f1,f2,f7,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f7.f64 + ctx.f4.f64));
	// lfs f7,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f4,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmadds f2,f8,f1,f13
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f13.f64));
	// stfs f4,4(r18)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f2,24(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 24, temp.u32);
	// lwz r18,172(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f8,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f4,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f1,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f2,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f13,f1,f11
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmadds f1,f2,f8,f7
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + ctx.f7.f64));
	// lfs f8,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f1
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64));
	// stfs f4,4(r18)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f7,20(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lwz r18,284(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// lwz r17,180(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f4,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// lwz r21,8(r18)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f7,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r16,252(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// lwz r15,188(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r14,308(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lfs f2,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r17,r21,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,196(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// fmuls f8,f4,f1
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f1.f64));
	// lfs f4,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// stfs f2,0(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lwz r16,260(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// stfs f8,16(r18)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// stfs f7,4(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lfs f1,16400(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16400);
	ctx.f1.f64 = double(temp.f32);
	// lwz r21,16392(r8)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16392);
	// lfs f8,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r15,16388(r8)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16388);
	// lwz r18,16384(r8)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16384);
	// rlwinm r20,r18,2,0,29
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r15,r15,r18
	ctx.r15.s64 = ctx.r18.s64 - ctx.r15.s64;
	// lfs f2,16396(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16396);
	ctx.f2.f64 = double(temp.f32);
	// subf r18,r21,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r21.s64;
	// rlwinm r15,r15,2,18,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfsx f7,r15,r8
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r8.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f29,r18,r8
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r8.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f7,f7,f2
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// fmuls f1,f29,f1
	ctx.f1.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// stfs f7,16404(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16404, temp.u32);
	// stfs f1,16408(r8)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16408, temp.u32);
	// stfsx f13,r20,r8
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r20.u32 + ctx.r8.u32, temp.u32);
	// lwz r18,16384(r8)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16384);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,20
	ctx.r18.u64 = ctx.r18.u32 & 0xFFF;
	// stw r18,16384(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16384, ctx.r18.u32);
	// lwz r18,2048(r28)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2048);
	// lfs f13,2060(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 2060);
	ctx.f13.f64 = double(temp.f32);
	// lwz r15,2052(r28)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2052);
	// lfs f7,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f7,f7,f3
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// rlwinm r17,r15,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f1,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f2,2064(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 2064);
	ctx.f2.f64 = double(temp.f32);
	// lfsx f29,r17,r28
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r28.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmadds f1,f29,f13,f1
	ctx.f1.f64 = double(float(ctx.f29.f64 * ctx.f13.f64 + ctx.f1.f64));
	// stfsx f1,r18,r28
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r28.u32, temp.u32);
	// lwz r18,2048(r28)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// fmadds f13,f2,f1,f29
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f29.f64));
	// lwz r17,2052(r28)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2052);
	// clrlwi r15,r18,23
	ctx.r15.u64 = ctx.r18.u32 & 0x1FF;
	// lwz r18,88(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stfs f13,2068(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stw r15,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r15.u32);
	// lwz r15,104(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r17,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r17.u32);
	// lfs f1,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f2,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f2,f2,f1,f7
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f7.f64));
	// lfs f1,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r16,96(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stfs f13,4(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f7,0(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f2,16(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// lwz r18,92(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f7,20(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f2,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f29,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lfsx f28,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f28.f64 = double(temp.f32);
	// lwz r14,112(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// fmadds f1,f13,f28,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f28.f64 + ctx.f1.f64));
	// lfs f13,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f28,f7
	ctx.f7.f64 = double(float(ctx.f28.f64 * ctx.f7.f64));
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f29,4(r18)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lwz r21,120(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r20,128(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r19,136(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// fmadds f2,f1,f2,f7
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f2.f64 + ctx.f7.f64));
	// stfs f2,24(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 24, temp.u32);
	// lwz r18,144(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f1.f64 = double(temp.f32);
	// lfs f7,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f2,f1,f7,f13
	ctx.f2.f64 = double(float(ctx.f1.f64 * ctx.f7.f64 + ctx.f13.f64));
	// lfs f13,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f7,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// stfs f13,4(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmuls f13,f7,f11
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// lfs f1,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// stfs f2,0(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmuls f7,f1,f2
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// stfs f7,20(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lwz r18,152(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r17,16384(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16384);
	// lwz r16,16388(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16388);
	// lfs f1,16396(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16396);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// subf r16,r16,r17
	ctx.r16.s64 = ctx.r17.s64 - ctx.r16.s64;
	// rlwinm r16,r16,2,18,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x3FFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f1,f7,f1
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f1.f64));
	// stfs f1,16404(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16404, temp.u32);
	// stfsx f13,r17,r18
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r18.u32, temp.u32);
	// lwz r17,16384(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16384);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// stw r17,16384(r18)
	PPC_STORE_U32(ctx.r18.u32 + 16384, ctx.r17.u32);
	// lfs f1,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r18,160(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// lfs f7,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// stfs f2,0(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f13,16(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// stfs f7,4(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lfs f28,8212(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8212);
	ctx.f28.f64 = double(temp.f32);
	// lwz r18,8196(r7)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8196);
	// lfs f2,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f2,f2,f6
	ctx.f2.f64 = double(float(ctx.f2.f64 + ctx.f6.f64));
	// lwz r17,8192(r7)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8192);
	// lfsx f13,r18,r7
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f28,f13,f28
	ctx.f28.f64 = double(float(ctx.f13.f64 * ctx.f28.f64));
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,8204(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8204);
	ctx.f7.f64 = double(temp.f32);
	// lfs f29,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// fmadds f13,f13,f7,f2
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f2.f64));
	// lfs f27,8208(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8208);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f7,f27,f2,f28
	ctx.f7.f64 = double(float(ctx.f27.f64 * ctx.f2.f64 + ctx.f28.f64));
	// stfsx f13,r18,r7
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r7.u32, temp.u32);
	// lwz r18,8196(r7)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8196);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stfs f7,8216(r7)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8216, temp.u32);
	// lwz r17,8192(r7)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r18,8196(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8196, ctx.r18.u32);
	// stw r17,8192(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8192, ctx.r17.u32);
	// lfs f2,8204(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8204);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,8192(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8192);
	// lfs f13,8208(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8208);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,8196(r27)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8196);
	// lwz r16,168(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r15,176(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r14,192(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r21,200(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lfs f28,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// lwz r16,184(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lfsx f7,r17,r27
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r27.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f2,f7,f2,f29
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f2.f64 + ctx.f29.f64));
	// stfsx f2,r18,r27
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r27.u32, temp.u32);
	// lwz r18,8192(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8192);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lwz r17,8196(r27)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8196);
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// fmadds f13,f13,f2,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 + ctx.f7.f64));
	// stfs f13,8212(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r27.u32 + 8212, temp.u32);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stw r18,8192(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8192, ctx.r18.u32);
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r17,8196(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8196, ctx.r17.u32);
	// lwz r18,4100(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4100);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f2,r18,r26
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r26.u32);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,4096(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4096);
	// lfs f13,4108(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 4108);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f13,f13,f2,f28
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 + ctx.f28.f64));
	// lfs f29,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lfs f7,4112(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 4112);
	ctx.f7.f64 = double(temp.f32);
	// fadds f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
	// stfsx f13,r18,r26
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r26.u32, temp.u32);
	// fmadds f7,f7,f13,f2
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f2.f64));
	// stfs f7,4116(r26)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r26.u32 + 4116, temp.u32);
	// fadds f2,f29,f3
	ctx.f2.f64 = double(float(ctx.f29.f64 + ctx.f3.f64));
	// lwz r17,4096(r26)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4096);
	// lwz r18,4100(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4100);
	// addi r15,r18,1
	ctx.r15.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r18,208(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// clrlwi r15,r15,22
	ctx.r15.u64 = ctx.r15.u32 & 0x3FF;
	// clrlwi r17,r17,22
	ctx.r17.u64 = ctx.r17.u32 & 0x3FF;
	// stw r15,4100(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4100, ctx.r15.u32);
	// stw r17,4096(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4096, ctx.r17.u32);
	// lwz r17,16384(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16384);
	// lfs f13,16396(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16396);
	ctx.f13.f64 = double(temp.f32);
	// lwz r20,16388(r18)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16388);
	// lfs f7,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r15,r17,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r16,224(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// subf r17,r20,r17
	ctx.r17.s64 = ctx.r17.s64 - ctx.r20.s64;
	// rlwinm r17,r17,2,18,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x3FFC;
	// lfsx f29,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f13,f29,f13
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f13.f64));
	// stfs f13,16404(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16404, temp.u32);
	// stfsx f2,r15,r18
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r18.u32, temp.u32);
	// lwz r17,16384(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16384);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// stw r17,16384(r18)
	PPC_STORE_U32(ctx.r18.u32 + 16384, ctx.r17.u32);
	// lwz r18,216(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// lfs f2,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// fmuls f13,f7,f2
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f2.f64));
	// lfs f2,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f28,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// lfs f29,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lfsx f27,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f27.f64 = double(temp.f32);
	// stfs f28,4(r18)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f7,0(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmadds f13,f27,f2,f13
	ctx.f13.f64 = double(float(ctx.f27.f64 * ctx.f2.f64 + ctx.f13.f64));
	// stfs f13,20(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lwz r18,8196(r5)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8196);
	// lfs f7,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,8192(r5)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8192);
	// fadds f2,f7,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// lfs f13,8204(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8204);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,8208(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8208);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f27,r18,r5
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r5.u32);
	ctx.f27.f64 = double(temp.f32);
	// lwz r15,232(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lfs f26,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// fmadds f13,f27,f13,f2
	ctx.f13.f64 = double(float(ctx.f27.f64 * ctx.f13.f64 + ctx.f2.f64));
	// lfs f28,8212(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8212);
	ctx.f28.f64 = double(temp.f32);
	// lwz r14,240(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	// stfsx f13,r17,r5
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r5.u32, temp.u32);
	// lwz r18,8196(r5)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8196);
	// fmuls f28,f28,f27
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f27.f64));
	// lwz r17,8192(r5)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r21,248(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// fmadds f7,f7,f2,f28
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f2.f64 + ctx.f28.f64));
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stfs f7,8216(r5)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8216, temp.u32);
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// lwz r20,256(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// stw r17,8192(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8192, ctx.r17.u32);
	// stw r18,8196(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8196, ctx.r18.u32);
	// lfs f2,8204(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 8204);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,8196(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8196);
	// lfs f13,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r17,8192(r25)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8192);
	// lfs f7,8208(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 8208);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f28,r18,r25
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r25.u32);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f2,f2,f28,f26
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f28.f64 + ctx.f26.f64));
	// stfsx f2,r17,r25
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r25.u32, temp.u32);
	// lwz r17,8192(r25)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// fmadds f7,f2,f7,f28
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f7.f64 + ctx.f28.f64));
	// lwz r18,8196(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8196);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stfs f7,8212(r25)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8212, temp.u32);
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// stw r17,8192(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8192, ctx.r17.u32);
	// stw r18,8196(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8196, ctx.r18.u32);
	// lwz r18,4100(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4100);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,4096(r24)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4096);
	// lfs f2,4108(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 4108);
	ctx.f2.f64 = double(temp.f32);
	// fadds f3,f7,f3
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f3.f64));
	// lfsx f7,r18,r24
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r24.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f2,f2,f7,f13
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f7.f64 + ctx.f13.f64));
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f28,4112(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 4112);
	ctx.f28.f64 = double(temp.f32);
	// fadds f13,f2,f6
	ctx.f13.f64 = double(float(ctx.f2.f64 + ctx.f6.f64));
	// stfsx f13,r17,r24
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r24.u32, temp.u32);
	// lwz r17,4096(r24)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4096);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r18,4100(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4100);
	// clrlwi r17,r17,22
	ctx.r17.u64 = ctx.r17.u32 & 0x3FF;
	// fmadds f7,f13,f28,f7
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f28.f64 + ctx.f7.f64));
	// stfs f7,4116(r24)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r24.u32 + 4116, temp.u32);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// stw r17,4096(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4096, ctx.r17.u32);
	// lwz r18,264(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// clrlwi r16,r16,22
	ctx.r16.u64 = ctx.r16.u32 & 0x3FF;
	// stw r16,4100(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4100, ctx.r16.u32);
	// lfs f13,0(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f28,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f28.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f28,f28,f13
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f13.f64));
	// lfs f2,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fadds f7,f2,f29
	ctx.f7.f64 = double(float(ctx.f2.f64 + ctx.f29.f64));
	// lfs f27,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f27.f64 = double(temp.f32);
	// fsubs f2,f2,f29
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f29.f64));
	// lfsx f29,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f29.f64 = double(temp.f32);
	// lfs f26,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// lwz r17,272(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// stfs f26,4(r18)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmadds f29,f27,f29,f28
	ctx.f29.f64 = double(float(ctx.f27.f64 * ctx.f29.f64 + ctx.f28.f64));
	// stfs f29,20(r18)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// fadds f29,f1,f4
	ctx.f29.f64 = double(float(ctx.f1.f64 + ctx.f4.f64));
	// stfs f13,0(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fsubs f1,f1,f4
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f4.f64));
	// lfs f28,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// lwz r17,16384(r6)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16384);
	// lwz r18,16392(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16392);
	// fadds f8,f28,f8
	ctx.f8.f64 = double(float(ctx.f28.f64 + ctx.f8.f64));
	// lwz r16,16388(r6)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16388);
	// lfs f13,16396(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 16396);
	ctx.f13.f64 = double(temp.f32);
	// subf r18,r18,r17
	ctx.r18.s64 = ctx.r17.s64 - ctx.r18.s64;
	// lfs f4,16400(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 16400);
	ctx.f4.f64 = double(temp.f32);
	// subf r16,r16,r17
	ctx.r16.s64 = ctx.r17.s64 - ctx.r16.s64;
	// ld r19,312(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + 312);
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lwz r15,288(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// rlwinm r16,r16,2,18,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x3FFC;
	// fcmpu cr6,f31,f12
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f28,r18,r6
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r6.u32);
	ctx.f28.f64 = double(temp.f32);
	// lfsx f27,r16,r6
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r6.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f4,f28,f4
	ctx.f4.f64 = double(float(ctx.f28.f64 * ctx.f4.f64));
	// fmuls f13,f27,f13
	ctx.f13.f64 = double(float(ctx.f27.f64 * ctx.f13.f64));
	// stfs f13,16404(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 16404, temp.u32);
	// stfs f4,16408(r6)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r6.u32 + 16408, temp.u32);
	// fadds f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 + ctx.f5.f64));
	// stfsx f3,r17,r6
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r6.u32, temp.u32);
	// lwz r18,16384(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16384);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,20
	ctx.r18.u64 = ctx.r18.u32 & 0xFFF;
	// stw r18,16384(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16384, ctx.r18.u32);
	// lwz r18,2052(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 2052);
	// lfs f5,2060(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 2060);
	ctx.f5.f64 = double(temp.f32);
	// lwz r17,2048(r23)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r23.u32 + 2048);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f4,2064(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 2064);
	ctx.f4.f64 = double(temp.f32);
	// lfsx f3,r18,r23
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r23.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f13,f3,f5,f7
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f5.f64 + ctx.f7.f64));
	// fadds f7,f13,f30
	ctx.f7.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// stfsx f7,r17,r23
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r23.u32, temp.u32);
	// fmadds f5,f4,f7,f3
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f7.f64 + ctx.f3.f64));
	// stfs f5,2068(r23)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r23.u32 + 2068, temp.u32);
	// lwz r17,2048(r23)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r23.u32 + 2048);
	// lwz r18,2052(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 2052);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// lwz r18,572(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 572);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stw r16,2052(r23)
	PPC_STORE_U32(ctx.r23.u32 + 2052, ctx.r16.u32);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// lwz r16,280(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// stw r17,2048(r23)
	PPC_STORE_U32(ctx.r23.u32 + 2048, ctx.r17.u32);
	// lfsu f13,4(r18)
	ea = 4 + ctx.r18.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r18.u32 = ea;
	// stw r18,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r18.u32);
	// lwz r18,2052(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f3,2060(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 2060);
	ctx.f3.f64 = double(temp.f32);
	// lfsx f4,r18,r22
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r22.u32);
	ctx.f4.f64 = double(temp.f32);
	// lwz r18,2048(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2048);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,2064(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 2064);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f2,f4,f3,f2
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f3.f64 + ctx.f2.f64));
	// fadds f5,f2,f30
	ctx.f5.f64 = double(float(ctx.f2.f64 + ctx.f30.f64));
	// stfsx f5,r18,r22
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r22.u32, temp.u32);
	// lwz r18,2052(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2052);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lwz r17,2048(r22)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2048);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// fmadds f4,f5,f7,f4
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f7.f64 + ctx.f4.f64));
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stfs f4,2068(r22)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r22.u32 + 2068, temp.u32);
	// stw r18,2052(r22)
	PPC_STORE_U32(ctx.r22.u32 + 2052, ctx.r18.u32);
	// fsubs f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// stw r17,2048(r22)
	PPC_STORE_U32(ctx.r22.u32 + 2048, ctx.r17.u32);
	// lwz r18,8196(r19)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r19.u32 + 8196);
	// lfs f3,8204(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 8204);
	ctx.f3.f64 = double(temp.f32);
	// lwz r17,8192(r19)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r19.u32 + 8192);
	// lfs f2,8208(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 8208);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r18,r19
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r19.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f5,f7,f3,f29
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f3.f64 + ctx.f29.f64));
	// fadds f3,f5,f6
	ctx.f3.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// stfsx f3,r17,r19
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r19.u32, temp.u32);
	// lwz r17,8192(r19)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r19.u32 + 8192);
	// lwz r18,8196(r19)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r19.u32 + 8196);
	// addi r14,r18,1
	ctx.r14.s64 = ctx.r18.s64 + 1;
	// clrlwi r14,r14,21
	ctx.r14.u64 = ctx.r14.u32 & 0x7FF;
	// fmadds f2,f3,f2,f7
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f7.f64));
	// stfs f2,8212(r19)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r19.u32 + 8212, temp.u32);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stw r14,8196(r19)
	PPC_STORE_U32(ctx.r19.u32 + 8196, ctx.r14.u32);
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// lwz r18,296(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// ld r21,320(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + 320);
	// stw r17,8192(r19)
	PPC_STORE_U32(ctx.r19.u32 + 8192, ctx.r17.u32);
	// ld r20,328(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + 328);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f5.f64 = double(temp.f32);
	// lfs f2,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f2.f64 = double(temp.f32);
	// lfsx f7,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f3,f5,f7,f1
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f7.f64 + ctx.f1.f64));
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// fadds f1,f3,f6
	ctx.f1.f64 = double(float(ctx.f3.f64 + ctx.f6.f64));
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r17,r18
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r18.u32, temp.u32);
	// fmadds f7,f1,f2,f7
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f2.f64 + ctx.f7.f64));
	// stfs f7,8212(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// addi r14,r17,1
	ctx.r14.s64 = ctx.r17.s64 + 1;
	// clrlwi r14,r14,21
	ctx.r14.u64 = ctx.r14.u32 & 0x7FF;
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// stw r14,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r14.u32);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r17,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r17.u32);
	// lfs f6,2060(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 2060);
	ctx.f6.f64 = double(temp.f32);
	// lwz r17,2048(r21)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2048);
	// lwz r18,2052(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f2,r18,r21
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r21.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f1,f2,f6
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f6.f64));
	// lfs f5,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,2064(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 2064);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f8,f8,f10,f1
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + ctx.f1.f64));
	// stfsx f8,r17,r21
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r21.u32, temp.u32);
	// lwz r18,2052(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2052);
	// fmadds f7,f8,f3,f2
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f3.f64 + ctx.f2.f64));
	// lwz r17,2048(r21)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2048);
	// stfs f7,2068(r21)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r21.u32 + 2068, temp.u32);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// lwz r18,580(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 580);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r16,2052(r21)
	PPC_STORE_U32(ctx.r21.u32 + 2052, ctx.r16.u32);
	// stw r17,2048(r21)
	PPC_STORE_U32(ctx.r21.u32 + 2048, ctx.r17.u32);
	// lfs f8,2064(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 2064);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,2052(r20)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2052);
	// lfs f6,2060(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 2060);
	ctx.f6.f64 = double(temp.f32);
	// lwz r16,2048(r20)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// lfs f1,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f7,f1,f0
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfsx f3,r17,r20
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r20.u32);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r17,r16,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f2,f6,f3,f5
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f3.f64 + ctx.f5.f64));
	// stfsx f2,r17,r20
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r20.u32, temp.u32);
	// fmadds f5,f4,f13,f7
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfsu f5,4(r18)
	temp.f32 = float(ctx.f5.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// lwz r17,2048(r20)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// fmadds f6,f2,f8,f3
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + ctx.f3.f64));
	// stfs f6,2068(r20)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r20.u32 + 2068, temp.u32);
	// stw r18,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r18.u32);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r18,2052(r20)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2052);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r18,2052(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2052, ctx.r18.u32);
	// stw r17,2048(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2048, ctx.r17.u32);
	// ble cr6,0x821320bc
	if (!ctx.cr6.gt) goto loc_821320BC;
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x821320bc
	if (!ctx.cr6.lt) goto loc_821320BC;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
loc_821320BC:
	// fcmpu cr6,f31,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// bge cr6,0x821320d0
	if (!ctx.cr6.lt) goto loc_821320D0;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x821320d0
	if (!ctx.cr6.gt) goto loc_821320D0;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
loc_821320D0:
	// lwz r18,80(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r18,r18,4
	ctx.r18.s64 = ctx.r18.s64 + 4;
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// bdnz 0x82131548
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82131548;
loc_821320E0:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x820803ac
	ctx.lr = 0x821320EC;
	__restfpr_26(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821320F0"))) PPC_WEAK_FUNC(sub_821320F0);
PPC_FUNC_IMPL(__imp__sub_821320F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x821320F8;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8208034c
	ctx.lr = 0x82132100;
	__savefpr_21(ctx, base);
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r5.u32);
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stw r6,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r6.u32);
	// addis r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 196608;
	// stw r4,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r4.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r7,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r7.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// addi r3,r3,22960
	ctx.r3.s64 = ctx.r3.s64 + 22960;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x8212e7f8
	ctx.lr = 0x82132138;
	sub_8212E7F8(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r3,22992
	ctx.r3.s64 = ctx.r3.s64 + 22992;
	// bl 0x8212e150
	ctx.lr = 0x8213214C;
	sub_8212E150(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f31,f12
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// ble cr6,0x82132164
	if (!ctx.cr6.gt) goto loc_82132164;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_82132164:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821335a8
	if (ctx.cr6.eq) goto loc_821335A8;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,2152
	ctx.r11.s64 = ctx.r11.s64 + 2152;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,2156
	ctx.r10.s64 = ctx.r10.s64 + 2156;
	// addi r9,r9,2160
	ctx.r9.s64 = ctx.r9.s64 + 2160;
	// addi r8,r8,2696
	ctx.r8.s64 = ctx.r8.s64 + 2696;
	// stw r10,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r10.u32);
	// addi r7,r7,10920
	ctx.r7.s64 = ctx.r7.s64 + 10920;
	// stw r9,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r9.u32);
	// addi r6,r6,10924
	ctx.r6.s64 = ctx.r6.s64 + 10924;
	// stw r8,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r8.u32);
	// addi r5,r5,10928
	ctx.r5.s64 = ctx.r5.s64 + 10928;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stw r6,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, ctx.r6.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r5,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,11976
	ctx.r4.s64 = ctx.r4.s64 + 11976;
	// addi r3,r3,14048
	ctx.r3.s64 = ctx.r3.s64 + 14048;
	// addi r11,r11,68
	ctx.r11.s64 = ctx.r11.s64 + 68;
	// stw r4,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r4.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stw r11,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r11.u32);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addis r7,r31,5
	ctx.r7.s64 = ctx.r31.s64 + 327680;
	// addis r6,r31,5
	ctx.r6.s64 = ctx.r31.s64 + 327680;
	// addis r5,r31,5
	ctx.r5.s64 = ctx.r31.s64 + 327680;
	// addi r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 + 72;
	// addi r9,r9,18168
	ctx.r9.s64 = ctx.r9.s64 + 18168;
	// addi r8,r8,18172
	ctx.r8.s64 = ctx.r8.s64 + 18172;
	// stw r10,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r10.u32);
	// addi r7,r7,25116
	ctx.r7.s64 = ctx.r7.s64 + 25116;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// addi r6,r6,25120
	ctx.r6.s64 = ctx.r6.s64 + 25120;
	// stw r8,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r8.u32);
	// addi r5,r5,25124
	ctx.r5.s64 = ctx.r5.s64 + 25124;
	// stw r7,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r7.u32);
	// addis r4,r31,5
	ctx.r4.s64 = ctx.r31.s64 + 327680;
	// stw r6,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r6.u32);
	// addis r3,r31,6
	ctx.r3.s64 = ctx.r31.s64 + 393216;
	// stw r5,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r5.u32);
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// addi r4,r4,25660
	ctx.r4.s64 = ctx.r4.s64 + 25660;
	// addi r3,r3,-31652
	ctx.r3.s64 = ctx.r3.s64 + -31652;
	// addi r11,r11,-31648
	ctx.r11.s64 = ctx.r11.s64 + -31648;
	// stw r4,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r4.u32);
	// addis r10,r31,6
	ctx.r10.s64 = ctx.r31.s64 + 393216;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// addis r9,r31,6
	ctx.r9.s64 = ctx.r31.s64 + 393216;
	// stw r11,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r11.u32);
	// addis r8,r31,6
	ctx.r8.s64 = ctx.r31.s64 + 393216;
	// addis r7,r31,5
	ctx.r7.s64 = ctx.r31.s64 + 327680;
	// addis r6,r31,5
	ctx.r6.s64 = ctx.r31.s64 + 327680;
	// addis r5,r31,6
	ctx.r5.s64 = ctx.r31.s64 + 393216;
	// addi r10,r10,-31644
	ctx.r10.s64 = ctx.r10.s64 + -31644;
	// addi r9,r9,-30596
	ctx.r9.s64 = ctx.r9.s64 + -30596;
	// addi r8,r8,-28524
	ctx.r8.s64 = ctx.r8.s64 + -28524;
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// addi r7,r7,23032
	ctx.r7.s64 = ctx.r7.s64 + 23032;
	// stw r9,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r9.u32);
	// addi r6,r6,23036
	ctx.r6.s64 = ctx.r6.s64 + 23036;
	// stw r8,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// addi r5,r5,-24404
	ctx.r5.s64 = ctx.r5.s64 + -24404;
	// stw r7,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r7.u32);
	// addis r4,r31,6
	ctx.r4.s64 = ctx.r31.s64 + 393216;
	// stw r6,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r6.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r5,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r5.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,-24400
	ctx.r4.s64 = ctx.r4.s64 + -24400;
	// addi r3,r3,22340
	ctx.r3.s64 = ctx.r3.s64 + 22340;
	// addi r11,r11,20248
	ctx.r11.s64 = ctx.r11.s64 + 20248;
	// stw r4,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r4.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stw r3,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r3.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,20244
	ctx.r4.s64 = ctx.r4.s64 + 20244;
	// stw r11,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r11.u32);
	// addi r3,r3,22316
	ctx.r3.s64 = ctx.r3.s64 + 22316;
	// stw r4,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r4.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stw r3,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r3.u32);
	// addi r4,r4,22336
	ctx.r4.s64 = ctx.r4.s64 + 22336;
	// addi r30,r30,22364
	ctx.r30.s64 = ctx.r30.s64 + 22364;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r4,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r4.u32);
	// stw r30,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r30.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,22388
	ctx.r3.s64 = ctx.r3.s64 + 22388;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addi r4,r4,-26740
	ctx.r4.s64 = ctx.r4.s64 + -26740;
	// stw r3,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r3.u32);
	// addi r30,r30,-26716
	ctx.r30.s64 = ctx.r30.s64 + -26716;
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r4,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r4.u32);
	// stw r30,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r30.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-26736
	ctx.r3.s64 = ctx.r3.s64 + -26736;
	// addis r9,r31,2
	ctx.r9.s64 = ctx.r31.s64 + 131072;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// stw r3,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r3.u32);
	// addis r7,r31,2
	ctx.r7.s64 = ctx.r31.s64 + 131072;
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addi r10,r10,22368
	ctx.r10.s64 = ctx.r10.s64 + 22368;
	// addi r9,r9,-24640
	ctx.r9.s64 = ctx.r9.s64 + -24640;
	// addi r8,r8,22320
	ctx.r8.s64 = ctx.r8.s64 + 22320;
	// stw r10,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r10.u32);
	// addi r7,r7,-26732
	ctx.r7.s64 = ctx.r7.s64 + -26732;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r6,r6,-22568
	ctx.r6.s64 = ctx.r6.s64 + -22568;
	// stw r8,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r8.u32);
	// addi r4,r4,-24644
	ctx.r4.s64 = ctx.r4.s64 + -24644;
	// stw r7,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r7.u32);
	// addi r30,r30,-22572
	ctx.r30.s64 = ctx.r30.s64 + -22572;
	// stw r6,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r6.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r4,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r4.u32);
	// stw r30,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r30.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// addis r9,r31,5
	ctx.r9.s64 = ctx.r31.s64 + 327680;
	// addis r8,r31,5
	ctx.r8.s64 = ctx.r31.s64 + 327680;
	// addis r6,r31,6
	ctx.r6.s64 = ctx.r31.s64 + 393216;
	// addis r24,r31,5
	ctx.r24.s64 = ctx.r31.s64 + 327680;
	// addis r23,r31,6
	ctx.r23.s64 = ctx.r31.s64 + 393216;
	// addis r22,r31,6
	ctx.r22.s64 = ctx.r31.s64 + 393216;
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-22552
	ctx.r3.s64 = ctx.r3.s64 + -22552;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// addi r10,r10,2700
	ctx.r10.s64 = ctx.r10.s64 + 2700;
	// addi r7,r7,14052
	ctx.r7.s64 = ctx.r7.s64 + 14052;
	// addi r27,r27,2164
	ctx.r27.s64 = ctx.r27.s64 + 2164;
	// addi r26,r26,10932
	ctx.r26.s64 = ctx.r26.s64 + 10932;
	// addi r25,r25,11980
	ctx.r25.s64 = ctx.r25.s64 + 11980;
	// addi r9,r9,23040
	ctx.r9.s64 = ctx.r9.s64 + 23040;
	// addi r8,r8,25664
	ctx.r8.s64 = ctx.r8.s64 + 25664;
	// addi r6,r6,-28520
	ctx.r6.s64 = ctx.r6.s64 + -28520;
	// addi r24,r24,25128
	ctx.r24.s64 = ctx.r24.s64 + 25128;
	// addi r23,r23,-31640
	ctx.r23.s64 = ctx.r23.s64 + -31640;
	// addi r22,r22,-30592
	ctx.r22.s64 = ctx.r22.s64 + -30592;
	// addi r5,r5,22392
	ctx.r5.s64 = ctx.r5.s64 + 22392;
	// addi r4,r4,-22524
	ctx.r4.s64 = ctx.r4.s64 + -22524;
	// addi r30,r30,-22548
	ctx.r30.s64 = ctx.r30.s64 + -22548;
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r30.u32);
	// addi r3,r3,-22520
	ctx.r3.s64 = ctx.r3.s64 + -22520;
	// addi r4,r4,10372
	ctx.r4.s64 = ctx.r4.s64 + 10372;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r3,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// stw r4,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r4.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,18588
	ctx.r30.s64 = ctx.r30.s64 + 18588;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,-6084
	ctx.r3.s64 = ctx.r3.s64 + -6084;
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r30.u32);
	// addi r4,r4,-22500
	ctx.r4.s64 = ctx.r4.s64 + -22500;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r3,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,-6092
	ctx.r30.s64 = ctx.r30.s64 + -6092;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,-6088
	ctx.r3.s64 = ctx.r3.s64 + -6088;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r30.u32);
	// addi r4,r4,-6068
	ctx.r4.s64 = ctx.r4.s64 + -6068;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,2148
	ctx.r30.s64 = ctx.r30.s64 + 2148;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,10368
	ctx.r3.s64 = ctx.r3.s64 + 10368;
	// stw r30,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r30.u32);
	// addi r4,r4,18584
	ctx.r4.s64 = ctx.r4.s64 + 18584;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// stw r4,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r4.u32);
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// addi r30,r30,22704
	ctx.r30.s64 = ctx.r30.s64 + 22704;
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r3,r3,-26424
	ctx.r3.s64 = ctx.r3.s64 + -26424;
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// addi r4,r4,-26420
	ctx.r4.s64 = ctx.r4.s64 + -26420;
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// stw r4,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r4.u32);
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// addi r30,r30,-26416
	ctx.r30.s64 = ctx.r30.s64 + -26416;
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r3,r3,-9956
	ctx.r3.s64 = ctx.r3.s64 + -9956;
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r30.u32);
	// addi r4,r4,-1740
	ctx.r4.s64 = ctx.r4.s64 + -1740;
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r3,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r3.u32);
	// stw r4,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r4.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,18792
	ctx.r30.s64 = ctx.r30.s64 + 18792;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,18176
	ctx.r3.s64 = ctx.r3.s64 + 18176;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r30.u32);
	// addi r4,r4,-26712
	ctx.r4.s64 = ctx.r4.s64 + -26712;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r3,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r3.u32);
	// stw r4,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r4.u32);
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// addi r30,r30,-6064
	ctx.r30.s64 = ctx.r30.s64 + -6064;
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r3,r3,-26396
	ctx.r3.s64 = ctx.r3.s64 + -26396;
	// stw r30,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r30.u32);
	// addi r4,r4,-18180
	ctx.r4.s64 = ctx.r4.s64 + -18180;
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r3,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r3.u32);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// stw r4,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r4.u32);
	// addi r30,r30,-9960
	ctx.r30.s64 = ctx.r30.s64 + -9960;
	// addi r29,r29,-1744
	ctx.r29.s64 = ctx.r29.s64 + -1744;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r29,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r29.u32);
	// addi r4,r4,-22496
	ctx.r4.s64 = ctx.r4.s64 + -22496;
	// addi r3,r3,22708
	ctx.r3.s64 = ctx.r3.s64 + 22708;
	// addis r17,r31,3
	ctx.r17.s64 = ctx.r31.s64 + 196608;
	// lwz r18,748(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 748);
	// addis r16,r31,3
	ctx.r16.s64 = ctx.r31.s64 + 196608;
	// lwz r20,756(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r17,r17,18812
	ctx.r17.s64 = ctx.r17.s64 + 18812;
	// addi r16,r16,18788
	ctx.r16.s64 = ctx.r16.s64 + 18788;
	// addis r21,r31,3
	ctx.r21.s64 = ctx.r31.s64 + 196608;
	// stw r17,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r17.u32);
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// stw r16,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r16.u32);
	// addi r21,r21,2376
	ctx.r21.s64 = ctx.r21.s64 + 2376;
	// stw r18,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r18.u32);
	// addi r19,r19,18784
	ctx.r19.s64 = ctx.r19.s64 + 18784;
	// mtctr r20
	ctx.ctr.u64 = ctx.r20.u64;
	// addis r17,r31,3
	ctx.r17.s64 = ctx.r31.s64 + 196608;
	// stw r21,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r21.u32);
	// addis r16,r31,3
	ctx.r16.s64 = ctx.r31.s64 + 196608;
	// stw r19,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r19.u32);
	// addi r17,r17,20884
	ctx.r17.s64 = ctx.r17.s64 + 20884;
	// addi r16,r16,22956
	ctx.r16.s64 = ctx.r16.s64 + 22956;
	// addis r21,r31,6
	ctx.r21.s64 = ctx.r31.s64 + 393216;
	// stw r17,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r17.u32);
	// addis r19,r31,6
	ctx.r19.s64 = ctx.r31.s64 + 393216;
	// stw r16,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r16.u32);
	// addi r21,r21,-24396
	ctx.r21.s64 = ctx.r21.s64 + -24396;
	// addi r19,r19,-22324
	ctx.r19.s64 = ctx.r19.s64 + -22324;
	// addis r15,r31,6
	ctx.r15.s64 = ctx.r31.s64 + 393216;
	// stw r21,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r21.u32);
	// addis r14,r31,6
	ctx.r14.s64 = ctx.r31.s64 + 393216;
	// stw r19,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r19.u32);
	// lis r18,-32256
	ctx.r18.s64 = -2113929216;
	// lis r17,-32256
	ctx.r17.s64 = -2113929216;
	// lis r16,-32256
	ctx.r16.s64 = -2113929216;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// lfs f9,14004(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 14004);
	ctx.f9.f64 = double(temp.f32);
	// addi r15,r15,-22328
	ctx.r15.s64 = ctx.r15.s64 + -22328;
	// lfs f10,23040(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 23040);
	ctx.f10.f64 = double(temp.f32);
	// addi r14,r14,-20256
	ctx.r14.s64 = ctx.r14.s64 + -20256;
	// lfs f11,12864(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 12864);
	ctx.f11.f64 = double(temp.f32);
	// addis r21,r31,3
	ctx.r21.s64 = ctx.r31.s64 + 196608;
	// stw r15,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r15.u32);
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// stw r14,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r14.u32);
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// addi r30,r30,2152
	ctx.r30.s64 = ctx.r30.s64 + 2152;
	// addi r29,r29,2380
	ctx.r29.s64 = ctx.r29.s64 + 2380;
	// addi r28,r28,-18176
	ctx.r28.s64 = ctx.r28.s64 + -18176;
	// addi r21,r21,-26392
	ctx.r21.s64 = ctx.r21.s64 + -26392;
	// addi r20,r20,18816
	ctx.r20.s64 = ctx.r20.s64 + 18816;
	// addi r19,r19,20888
	ctx.r19.s64 = ctx.r19.s64 + 20888;
loc_82132608:
	// lwz r18,2048(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// lfs f13,2064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2064);
	ctx.f13.f64 = double(temp.f32);
	// lwz r17,2052(r11)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2052);
	// lfs f8,2068(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2068);
	ctx.f8.f64 = double(temp.f32);
	// lwz r16,2056(r11)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2056);
	// rlwinm r15,r18,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r14,2060(r11)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2060);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// std r19,440(r1)
	PPC_STORE_U64(ctx.r1.u32 + 440, ctx.r19.u64);
	// subf r14,r14,r18
	ctx.r14.s64 = ctx.r18.s64 - ctx.r14.s64;
	// lwz r19,100(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r18,396(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// rlwinm r17,r17,2,21,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x7FC;
	// rlwinm r16,r16,2,21,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x7FC;
	// std r20,416(r1)
	PPC_STORE_U64(ctx.r1.u32 + 416, ctx.r20.u64);
	// rlwinm r14,r14,2,21,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0x7FC;
	// lwz r20,260(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// lfs f7,2072(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2072);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// lwz r19,80(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r18,84(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f4,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lwz r20,268(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lfs f3,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,4(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lfs f5,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r19,108(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fadds f2,f5,f6
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lfsx f6,r17,r11
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f5,r16,r11
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// lfsx f6,r14,r11
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + ctx.r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f5,f8
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fmuls f8,f7,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// stfs f13,2076(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2076, temp.u32);
	// stfs f5,2080(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2080, temp.u32);
	// lwz r16,404(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// stfs f8,2084(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2084, temp.u32);
	// lwz r14,116(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stfsx f3,r15,r11
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r11.u32, temp.u32);
	// lwz r18,2048(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2048(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2048, ctx.r18.u32);
	// lfs f7,524(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 524);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,512(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 512);
	// lfs f6,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lwz r17,516(r27)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r27.u32 + 516);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r17,r27
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r27.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfs f3,528(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 528);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f5,f7,f2
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f7.f64 + ctx.f2.f64));
	// stfsx f2,r18,r27
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r27.u32, temp.u32);
	// lwz r17,512(r27)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r27.u32 + 512);
	// lwz r18,516(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 516);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// fmadds f13,f3,f2,f5
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f5.f64));
	// clrlwi r18,r18,25
	ctx.r18.u64 = ctx.r18.u32 & 0x7F;
	// stfs f13,532(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r27.u32 + 532, temp.u32);
	// clrlwi r17,r17,25
	ctx.r17.u64 = ctx.r17.u32 & 0x7F;
	// stw r18,516(r27)
	PPC_STORE_U32(ctx.r27.u32 + 516, ctx.r18.u32);
	// stw r17,512(r27)
	PPC_STORE_U32(ctx.r27.u32 + 512, ctx.r17.u32);
	// lfs f8,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,8200(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8200);
	// lwz r17,8204(r10)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8204);
	// lfs f5,8208(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8208);
	ctx.f5.f64 = double(temp.f32);
	// lwz r16,8192(r10)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// lfs f3,8212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8212);
	ctx.f3.f64 = double(temp.f32);
	// lwz r15,8196(r10)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8196);
	// subf r15,r15,r16
	ctx.r15.s64 = ctx.r16.s64 - ctx.r15.s64;
	// rlwinm r15,r15,2,19,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x1FFC;
	// fadds f13,f7,f8
	ctx.f13.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// lfs f2,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// subf r17,r17,r16
	ctx.r17.s64 = ctx.r16.s64 - ctx.r17.s64;
	// lfsx f8,r15,r10
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r18,r18,2,19,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x1FFC;
	// fmuls f5,f5,f8
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// rlwinm r17,r17,2,19,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x1FFC;
	// lfs f7,8216(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8216);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r15,276(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r14,124(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r20,356(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lfsx f8,r18,r10
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r18,284(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// lfsx f30,r17,r10
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r10.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f3,f8,f3
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f3.f64));
	// fmuls f8,f30,f7
	ctx.f8.f64 = double(float(ctx.f30.f64 * ctx.f7.f64));
	// stfs f3,8224(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8224, temp.u32);
	// stfs f8,8228(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8228, temp.u32);
	// lwz r17,140(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// stfs f5,8220(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8220, temp.u32);
	// lwz r19,132(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stfsx f6,r16,r10
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r10.u32, temp.u32);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// lwz r18,8192(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// stw r17,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r17.u32);
	// stw r18,8192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8192, ctx.r18.u32);
	// lfs f7,1036(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 1036);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,1024(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 1024);
	// lfs f8,1040(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 1040);
	ctx.f8.f64 = double(temp.f32);
	// lwz r16,1028(r26)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r26.u32 + 1028);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f3,r16,r26
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r26.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f7,f7,f3,f13
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f3.f64 + ctx.f13.f64));
	// stfsx f7,r18,r26
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r26.u32, temp.u32);
	// lwz r17,1024(r26)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r26.u32 + 1024);
	// lwz r18,1028(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 1028);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,24
	ctx.r18.u64 = ctx.r18.u32 & 0xFF;
	// fmadds f3,f7,f8,f3
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f3.f64));
	// stfs f3,1044(r26)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r26.u32 + 1044, temp.u32);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stw r18,1028(r26)
	PPC_STORE_U32(ctx.r26.u32 + 1028, ctx.r18.u32);
	// clrlwi r17,r17,24
	ctx.r17.u64 = ctx.r17.u32 & 0xFF;
	// lwz r15,80(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r17,1024(r26)
	PPC_STORE_U32(ctx.r26.u32 + 1024, ctx.r17.u32);
	// lfs f13,2060(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 2060);
	ctx.f13.f64 = double(temp.f32);
	// lwz r18,2052(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,2048(r25)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2048);
	// lfsx f8,r18,r25
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r25.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f3,f13,f8,f5
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f5.f64));
	// lfs f7,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,2064(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 2064);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f3,f13,f8
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f13.f64 + ctx.f8.f64));
	// lwz r14,88(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stfsx f3,r18,r25
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r25.u32, temp.u32);
	// lwz r18,2052(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2052);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// stfs f8,2068(r25)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2068, temp.u32);
	// lwz r18,2048(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r18,2048(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2048, ctx.r18.u32);
	// stw r17,2052(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2052, ctx.r17.u32);
	// lfs f3,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,4104(r7)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4104);
	// lfs f29,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lwz r17,4100(r7)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4100);
	// lfs f13,4108(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4108);
	ctx.f13.f64 = double(temp.f32);
	// lwz r16,4096(r7)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4096);
	// lfs f8,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f30,4112(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4112);
	ctx.f30.f64 = double(temp.f32);
	// rlwinm r15,r16,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// lfs f28,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// subf r17,r17,r16
	ctx.r17.s64 = ctx.r16.s64 - ctx.r17.s64;
	// fmuls f6,f3,f6
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f6.f64));
	// rlwinm r18,r18,2,20,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFC;
	// rlwinm r17,r17,2,20,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFC;
	// lfsx f3,r18,r7
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r7.u32);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,164(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// fmuls f3,f3,f30
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f30.f64));
	// fmuls f5,f29,f5
	ctx.f5.f64 = double(float(ctx.f29.f64 * ctx.f5.f64));
	// lwz r16,148(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r14,292(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// std r10,432(r1)
	PPC_STORE_U64(ctx.r1.u32 + 432, ctx.r10.u64);
	// lfsx f30,r17,r7
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r7.u32);
	ctx.f30.f64 = double(temp.f32);
	// std r7,448(r1)
	PPC_STORE_U64(ctx.r1.u32 + 448, ctx.r7.u64);
	// stfs f3,4120(r7)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4120, temp.u32);
	// fmuls f3,f30,f13
	ctx.f3.f64 = double(float(ctx.f30.f64 * ctx.f13.f64));
	// stfs f3,4116(r7)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4116, temp.u32);
	// stw r18,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r18.u32);
	// stfsx f7,r15,r7
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r7.u32, temp.u32);
	// lwz r18,4096(r7)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4096);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// std r11,424(r1)
	PPC_STORE_U64(ctx.r1.u32 + 424, ctx.r11.u64);
	// clrlwi r18,r18,22
	ctx.r18.u64 = ctx.r18.u32 & 0x3FF;
	// fadds f13,f5,f6
	ctx.f13.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lwz r20,156(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stw r18,4096(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4096, ctx.r18.u32);
	// lfs f29,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lwz r18,2052(r9)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2052);
	// lfs f6,2068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2068);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,2064(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2064);
	ctx.f7.f64 = double(temp.f32);
	// lwz r19,364(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// lfs f5,2072(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2072);
	ctx.f5.f64 = double(temp.f32);
	// lwz r17,300(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// lfs f27,0(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// fadds f13,f13,f4
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f4.f64));
	// stw r17,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r17.u32);
	// lfs f30,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lwz r10,2056(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2056);
	// lwz r15,2048(r9)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2048);
	// rlwinm r11,r15,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,2060(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2060);
	// subf r10,r10,r15
	ctx.r10.s64 = ctx.r15.s64 - ctx.r10.s64;
	// subf r18,r18,r15
	ctx.r18.s64 = ctx.r15.s64 - ctx.r18.s64;
	// fadds f30,f29,f30
	ctx.f30.f64 = double(float(ctx.f29.f64 + ctx.f30.f64));
	// subf r15,r7,r15
	ctx.r15.s64 = ctx.r15.s64 - ctx.r7.s64;
	// lfs f3,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r16,r10,2,21,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// rlwinm r18,r18,2,21,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x7FC;
	// rlwinm r15,r15,2,21,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x7FC;
	// lfsx f4,r16,r9
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f6,f4,f6
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f6.f64));
	// lfsx f4,r18,r9
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r9.u32);
	ctx.f4.f64 = double(temp.f32);
	// lfsx f29,r15,r9
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r9.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f7,f4,f7
	ctx.f7.f64 = double(float(ctx.f4.f64 * ctx.f7.f64));
	// fmuls f5,f5,f29
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f29.f64));
	// stfs f6,2080(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2080, temp.u32);
	// stfs f5,2084(r9)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2084, temp.u32);
	// fmuls f4,f13,f3
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
	// stfs f7,2076(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2076, temp.u32);
	// stfsx f1,r11,r9
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// lwz r18,2048(r9)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2048(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2048, ctx.r18.u32);
	// lfs f7,524(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 524);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,512(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 512);
	// lwz r16,516(r24)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r24.u32 + 516);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r16,r24
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r24.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f3,0(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f6,f13,f7,f30
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f30.f64));
	// lfs f1,528(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 528);
	ctx.f1.f64 = double(temp.f32);
	// stfsx f6,r18,r24
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r24.u32, temp.u32);
	// lwz r18,512(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 512);
	// lwz r17,516(r24)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r24.u32 + 516);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// fmadds f5,f1,f6,f13
	ctx.f5.f64 = double(float(ctx.f1.f64 * ctx.f6.f64 + ctx.f13.f64));
	// clrlwi r17,r17,25
	ctx.r17.u64 = ctx.r17.u32 & 0x7F;
	// stfs f5,532(r24)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r24.u32 + 532, temp.u32);
	// clrlwi r18,r18,25
	ctx.r18.u64 = ctx.r18.u32 & 0x7F;
	// stw r17,516(r24)
	PPC_STORE_U32(ctx.r24.u32 + 516, ctx.r17.u32);
	// stw r18,512(r24)
	PPC_STORE_U32(ctx.r24.u32 + 512, ctx.r18.u32);
	// lwz r18,8192(r8)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8192);
	// lwz r16,88(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r14,r18,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,8196(r8)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8196);
	// lfs f13,8208(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8208);
	ctx.f13.f64 = double(temp.f32);
	// lwz r15,8204(r8)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8204);
	// lfs f7,8212(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8212);
	ctx.f7.f64 = double(temp.f32);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// lwz r11,172(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f6,8216(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8216);
	ctx.f6.f64 = double(temp.f32);
	// lwz r10,308(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lfs f1,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r16,8200(r8)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8200);
	// rlwinm r17,r17,2,19,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x1FFC;
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// subf r18,r15,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r15.s64;
	// lwz r15,80(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r16,r16,2,19,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x1FFC;
	// lfs f30,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// rlwinm r18,r18,2,19,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x1FFC;
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f5,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r15,412(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// fadds f1,f5,f1
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f1.f64));
	// lfsx f5,r17,r8
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r8.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f13,f13,f5
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// lfsx f5,r18,r8
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r8.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f29,r16,r8
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r8.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f6,f5,f6
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f6.f64));
	// fmuls f7,f29,f7
	ctx.f7.f64 = double(float(ctx.f29.f64 * ctx.f7.f64));
	// stfs f13,8220(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8220, temp.u32);
	// stfs f6,8228(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8228, temp.u32);
	// stfs f7,8224(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8224, temp.u32);
	// stfsx f3,r14,r8
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r14.u32 + ctx.r8.u32, temp.u32);
	// lwz r18,8192(r8)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8192);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// stw r18,8192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8192, ctx.r18.u32);
	// lfs f7,1036(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 1036);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,1024(r23)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r23.u32 + 1024);
	// lwz r18,1028(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 1028);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r18,r23
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r23.u32);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f6,f7,f13,f1
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f1.f64));
	// lfs f5,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lfs f1,1040(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 1040);
	ctx.f1.f64 = double(temp.f32);
	// stfsx f6,r18,r23
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r23.u32, temp.u32);
	// lwz r18,1028(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 1028);
	// fmadds f13,f6,f1,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f13.f64));
	// stfs f13,1044(r23)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r23.u32 + 1044, temp.u32);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,1024(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 1024);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r17,r17,24
	ctx.r17.u64 = ctx.r17.u32 & 0xFF;
	// clrlwi r18,r18,24
	ctx.r18.u64 = ctx.r18.u32 & 0xFF;
	// stw r17,1028(r23)
	PPC_STORE_U32(ctx.r23.u32 + 1028, ctx.r17.u32);
	// stw r18,1024(r23)
	PPC_STORE_U32(ctx.r23.u32 + 1024, ctx.r18.u32);
	// lwz r18,2052(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,2048(r22)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2048);
	// lfsx f6,r18,r22
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r22.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f1,2060(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 2060);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f13,f1,f6,f5
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f6.f64 + ctx.f5.f64));
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f7,2064(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 2064);
	ctx.f7.f64 = double(temp.f32);
	// stfsx f13,r18,r22
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r22.u32, temp.u32);
	// fmadds f13,f13,f7,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f6.f64));
	// stfs f13,2068(r22)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r22.u32 + 2068, temp.u32);
	// lwz r18,2048(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2048);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,2052(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 2052);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stw r17,2048(r22)
	PPC_STORE_U32(ctx.r22.u32 + 2048, ctx.r17.u32);
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2052(r22)
	PPC_STORE_U32(ctx.r22.u32 + 2052, ctx.r18.u32);
	// lfs f7,4112(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4112);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lwz r18,4096(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4096);
	// lfs f13,4108(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4108);
	ctx.f13.f64 = double(temp.f32);
	// lwz r17,4100(r6)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4100);
	// rlwinm r14,r18,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r16,4104(r6)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4104);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// lwz r15,188(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// subf r18,r16,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r16.s64;
	// lwz r16,372(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// rlwinm r17,r17,2,20,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFC;
	// lwz r11,196(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// rlwinm r18,r18,2,20,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFC;
	// lwz r10,316(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r7,204(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lfs f29,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lwz r15,408(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	// lfs f26,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f3,f29,f3
	ctx.f3.f64 = double(float(ctx.f29.f64 * ctx.f3.f64));
	// fmuls f5,f26,f5
	ctx.f5.f64 = double(float(ctx.f26.f64 * ctx.f5.f64));
	// lfsx f29,r17,r6
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r6.u32);
	ctx.f29.f64 = double(temp.f32);
	// lfsx f26,r18,r6
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r6.u32);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f13,f29,f13
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f13.f64));
	// lfs f25,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// fmuls f7,f26,f7
	ctx.f7.f64 = double(float(ctx.f26.f64 * ctx.f7.f64));
	// stfs f13,4116(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4116, temp.u32);
	// lwz r11,212(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// stfs f7,4120(r6)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4120, temp.u32);
	// stfsx f1,r14,r6
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r14.u32 + ctx.r6.u32, temp.u32);
	// fadds f5,f5,f3
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f3.f64));
	// fadds f3,f5,f27
	ctx.f3.f64 = double(float(ctx.f5.f64 + ctx.f27.f64));
	// lwz r18,4096(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4096);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,324(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// clrlwi r17,r17,22
	ctx.r17.u64 = ctx.r17.u32 & 0x3FF;
	// stw r17,4096(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4096, ctx.r17.u32);
	// lfs f1,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f13.f64 = double(temp.f32);
	// lfs f5,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfsx f29,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f3,f3,f7
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f7.f64));
	// lfs f7,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f1,f13,f29,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f29.f64 + ctx.f1.f64));
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r16,r18
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// fmadds f13,f1,f7,f29
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f7.f64 + ctx.f29.f64));
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// stfs f13,2068(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// fadds f5,f5,f2
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f2.f64));
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// lwz r18,220(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f1,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f7,f7,f1,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f5.f64));
	// lfs f1,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfs f7,16(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// stfs f1,4(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f5,0(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lwz r18,380(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// lfs f5,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,20(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f29,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfsx f26,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f26.f64 = double(temp.f32);
	// fmadds f13,f26,f5,f13
	ctx.f13.f64 = double(float(ctx.f26.f64 * ctx.f5.f64 + ctx.f13.f64));
	// lfs f27,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f7,f7,f26
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f26.f64));
	// stfs f29,4(r18)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f13,0(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmadds f5,f27,f13,f7
	ctx.f5.f64 = double(float(ctx.f27.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f5,24(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 24, temp.u32);
	// lwz r18,228(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// lwz r17,332(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// lwz r16,236(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r15,400(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	// lwz r14,244(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// lfs f13,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r11,r18
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f1,f13,f5,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f5.f64 + ctx.f1.f64));
	// lfs f5,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f7,f1,f7
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f7.f64));
	// lfs f13,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f5,f11
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lwz r11,252(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// stfs f7,20(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lwz r17,340(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// stfs f13,4(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lwz r18,388(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lfs f7,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f1,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r16,8(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f27,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f27.f64 = double(temp.f32);
	// lfs f29,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// fmuls f13,f13,f27
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f27.f64));
	// stfs f7,4(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f13,16(r18)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// lwz r15,16384(r5)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16384);
	// rlwinm r10,r15,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,16396(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16396);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,16388(r5)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16388);
	// lfs f1,16400(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16400);
	ctx.f1.f64 = double(temp.f32);
	// lwz r16,16392(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16392);
	// subf r16,r16,r15
	ctx.r16.s64 = ctx.r15.s64 - ctx.r16.s64;
	// lfs f13,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// subf r18,r18,r15
	ctx.r18.s64 = ctx.r15.s64 - ctx.r18.s64;
	// rlwinm r16,r16,2,18,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfsx f26,r16,r5
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r5.u32);
	ctx.f26.f64 = double(temp.f32);
	// lfsx f27,r18,r5
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r5.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f7,f27,f7
	ctx.f7.f64 = double(float(ctx.f27.f64 * ctx.f7.f64));
	// fmuls f1,f26,f1
	ctx.f1.f64 = double(float(ctx.f26.f64 * ctx.f1.f64));
	// stfs f7,16404(r5)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16404, temp.u32);
	// stfs f1,16408(r5)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16408, temp.u32);
	// stfsx f5,r10,r5
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r5.u32, temp.u32);
	// lwz r18,16384(r5)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16384);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// lwz r18,92(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// clrlwi r16,r16,20
	ctx.r16.u64 = ctx.r16.u32 & 0xFFF;
	// stw r16,16384(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16384, ctx.r16.u32);
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f5,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f5.f64 = double(temp.f32);
	// lwz r16,2052(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f7,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,2048(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f27,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f27.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f26,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f26.f64 = double(temp.f32);
	// fadds f1,f1,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// fmadds f7,f26,f5,f7
	ctx.f7.f64 = double(float(ctx.f26.f64 * ctx.f5.f64 + ctx.f7.f64));
	// stfsx f7,r17,r18
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r18.u32, temp.u32);
	// fmadds f5,f7,f27,f26
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f27.f64 + ctx.f26.f64));
	// stfs f5,2068(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// lwz r18,348(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// lwz r17,96(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f27,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lwz r16,104(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r15,112(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r14,120(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lfsx f5,r11,r18
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	ctx.f5.f64 = double(temp.f32);
	// lwz r11,136(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// fmadds f7,f5,f7,f1
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f7.f64 + ctx.f1.f64));
	// lfs f5,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// stfs f1,0(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f27,4(r18)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f7,16(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// lwz r18,144(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lfs f7,20(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f1,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lfs f27,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f27.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f26,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f23,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f23.f64 = double(temp.f32);
	// lfs f24,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// fmadds f5,f23,f1,f5
	ctx.f5.f64 = double(float(ctx.f23.f64 * ctx.f1.f64 + ctx.f5.f64));
	// stfs f5,0(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmuls f1,f23,f7
	ctx.f1.f64 = double(float(ctx.f23.f64 * ctx.f7.f64));
	// fmadds f7,f27,f5,f1
	ctx.f7.f64 = double(float(ctx.f27.f64 * ctx.f5.f64 + ctx.f1.f64));
	// stfs f7,24(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 24, temp.u32);
	// stfs f26,4(r18)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lwz r18,152(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lfs f1,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f7,f5,f1,f24
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f24.f64));
	// lfs f1,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f5,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// lfs f27,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// stfs f7,0(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmuls f7,f7,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// stfs f7,20(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// stfs f1,4(r18)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmuls f1,f27,f11
	ctx.f1.f64 = double(float(ctx.f27.f64 * ctx.f11.f64));
	// lfs f5,16396(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16396);
	ctx.f5.f64 = double(temp.f32);
	// lfs f27,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lwz r16,16392(r4)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16392);
	// lfs f7,16400(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16400);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,16388(r4)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16388);
	// lfs f26,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// lwz r18,16384(r4)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16384);
	// rlwinm r15,r18,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// subf r18,r16,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r16.s64;
	// lwz r16,184(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// rlwinm r17,r17,2,18,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfsx f24,r17,r4
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r4.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f5,f24,f5
	ctx.f5.f64 = double(float(ctx.f24.f64 * ctx.f5.f64));
	// lfsx f23,r18,r4
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r4.u32);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f7,f23,f7
	ctx.f7.f64 = double(float(ctx.f23.f64 * ctx.f7.f64));
	// stfs f7,16408(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16408, temp.u32);
	// stfs f5,16404(r4)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16404, temp.u32);
	// stfsx f1,r15,r4
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r4.u32, temp.u32);
	// lwz r18,16384(r4)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16384);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,160(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// stw r17,16384(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16384, ctx.r17.u32);
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f24,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f7,f24,f7
	ctx.f7.f64 = double(float(ctx.f24.f64 * ctx.f7.f64));
	// lfs f5,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r17,168(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stfs f5,4(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f7,16(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// stfs f26,0(r18)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lwz r18,176(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lfs f5,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r14,8196(r30)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8196);
	// fadds f5,f5,f28
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f28.f64));
	// lwz r17,8192(r30)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8192);
	// rlwinm r14,r14,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,8204(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8204);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f23,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// lfs f26,8208(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8208);
	ctx.f26.f64 = double(temp.f32);
	// lwz r15,192(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lfs f22,8212(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8212);
	ctx.f22.f64 = double(temp.f32);
	// lwz r11,232(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lfsx f24,r14,r30
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + ctx.r30.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f22,f24,f22
	ctx.f22.f64 = double(float(ctx.f24.f64 * ctx.f22.f64));
	// fmadds f7,f24,f7,f5
	ctx.f7.f64 = double(float(ctx.f24.f64 * ctx.f7.f64 + ctx.f5.f64));
	// stfsx f7,r17,r30
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r30.u32, temp.u32);
	// fmadds f5,f5,f26,f22
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f26.f64 + ctx.f22.f64));
	// stfs f5,8216(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r30.u32 + 8216, temp.u32);
	// lwz r18,8196(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8196);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,8192(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8192);
	// addi r14,r18,1
	ctx.r14.s64 = ctx.r18.s64 + 1;
	// lwz r18,200(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// clrlwi r14,r14,21
	ctx.r14.u64 = ctx.r14.u32 & 0x7FF;
	// stw r17,8196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8196, ctx.r17.u32);
	// stw r14,8192(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8192, ctx.r14.u32);
	// lwz r14,224(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lfs f5,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// lfs f7,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f26,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f26.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f24,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmadds f7,f24,f7,f23
	ctx.f7.f64 = double(float(ctx.f24.f64 * ctx.f7.f64 + ctx.f23.f64));
	// stfsx f7,r16,r18
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f7,f26,f7,f24
	ctx.f7.f64 = double(float(ctx.f26.f64 * ctx.f7.f64 + ctx.f24.f64));
	// stfs f7,8212(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// addi r16,r17,1
	ctx.r16.s64 = ctx.r17.s64 + 1;
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// stw r17,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r17.u32);
	// stw r16,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r16.u32);
	// lwz r18,208(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f26,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// lwz r16,4096(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// fadds f2,f26,f2
	ctx.f2.f64 = double(float(ctx.f26.f64 + ctx.f2.f64));
	// lfsx f26,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f26.f64 = double(temp.f32);
	// lfs f7,4108(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4108);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f7,f26,f7,f5
	ctx.f7.f64 = double(float(ctx.f26.f64 * ctx.f7.f64 + ctx.f5.f64));
	// lfs f24,4112(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4112);
	ctx.f24.f64 = double(temp.f32);
	// fadds f5,f7,f28
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f28.f64));
	// stfsx f5,r16,r18
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f7,f24,f5,f26
	ctx.f7.f64 = double(float(ctx.f24.f64 * ctx.f5.f64 + ctx.f26.f64));
	// stfs f7,4116(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4116, temp.u32);
	// lwz r16,4096(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,22
	ctx.r17.u64 = ctx.r17.u32 & 0x3FF;
	// clrlwi r16,r16,22
	ctx.r16.u64 = ctx.r16.u32 & 0x3FF;
	// stw r17,4100(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4100, ctx.r17.u32);
	// stw r16,4096(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4096, ctx.r16.u32);
	// lwz r17,16388(r3)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16388);
	// lwz r16,16384(r3)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16384);
	// rlwinm r15,r16,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r18,16392(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16392);
	// subf r17,r17,r16
	ctx.r17.s64 = ctx.r16.s64 - ctx.r17.s64;
	// lfs f5,16400(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16400);
	ctx.f5.f64 = double(temp.f32);
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// lfs f7,16396(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16396);
	ctx.f7.f64 = double(temp.f32);
	// lwz r16,216(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// rlwinm r17,r17,2,18,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfs f24,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// fadds f27,f24,f27
	ctx.f27.f64 = double(float(ctx.f24.f64 + ctx.f27.f64));
	// lfsx f24,r17,r3
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r3.u32);
	ctx.f24.f64 = double(temp.f32);
	// lfs f26,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f7,f24,f7
	ctx.f7.f64 = double(float(ctx.f24.f64 * ctx.f7.f64));
	// lwz r10,240(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	// lwz r7,248(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// lfsx f23,r18,r3
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r3.u32);
	ctx.f23.f64 = double(temp.f32);
	// lwz r16,256(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// stfs f7,16404(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16404, temp.u32);
	// fmuls f5,f23,f5
	ctx.f5.f64 = double(float(ctx.f23.f64 * ctx.f5.f64));
	// stfs f5,16408(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16408, temp.u32);
	// lwz r14,304(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// stfsx f2,r15,r3
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r3.u32, temp.u32);
	// lwz r18,16384(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16384);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,264(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// stw r17,16384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16384, ctx.r17.u32);
	// lfs f5,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f2,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f7,f2,f26
	ctx.f7.f64 = double(float(ctx.f2.f64 * ctx.f26.f64));
	// lfs f2,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f24,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lwz r11,312(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f23,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f23.f64 = double(temp.f32);
	// fmadds f7,f23,f5,f7
	ctx.f7.f64 = double(float(ctx.f23.f64 * ctx.f5.f64 + ctx.f7.f64));
	// stfs f7,20(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// stfs f2,4(r18)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f26,0(r18)
	temp.f32 = float(ctx.f26.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lfs f2,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r17,8196(r28)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8196);
	// fadds f7,f2,f6
	ctx.f7.f64 = double(float(ctx.f2.f64 + ctx.f6.f64));
	// lwz r18,8192(r28)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8192);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f2,8204(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8204);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f26,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// lfsx f22,r17,r28
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r28.u32);
	ctx.f22.f64 = double(temp.f32);
	// lfs f5,8208(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8208);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f2,f2,f22,f7
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f22.f64 + ctx.f7.f64));
	// lfs f23,8212(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8212);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f23,f22,f23
	ctx.f23.f64 = double(float(ctx.f22.f64 * ctx.f23.f64));
	// stfsx f2,r18,r28
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r28.u32, temp.u32);
	// fmadds f7,f7,f5,f23
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f5.f64 + ctx.f23.f64));
	// stfs f7,8216(r28)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// lwz r17,8192(r28)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8192);
	// lwz r18,8196(r28)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8196);
	// addi r15,r18,1
	ctx.r15.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r18,272(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// clrlwi r15,r15,21
	ctx.r15.u64 = ctx.r15.u32 & 0x7FF;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r15,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r15.u32);
	// stw r17,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r17.u32);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f5.f64 = double(temp.f32);
	// lwz r15,8192(r18)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// lfs f7,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f7.f64 = double(temp.f32);
	// lfs f2,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r16,r15,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f23,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f23.f64 = double(temp.f32);
	// fmadds f5,f23,f5,f26
	ctx.f5.f64 = double(float(ctx.f23.f64 * ctx.f5.f64 + ctx.f26.f64));
	// stfsx f5,r16,r18
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f7,f5,f7,f23
	ctx.f7.f64 = double(float(ctx.f5.f64 * ctx.f7.f64 + ctx.f23.f64));
	// stfs f7,8212(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r15,288(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// addi r16,r17,1
	ctx.r16.s64 = ctx.r17.s64 + 1;
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r16,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r16.u32);
	// stw r17,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r17.u32);
	// lwz r16,280(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// lwz r18,296(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// lfs f7,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fadds f7,f7,f30
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f30.f64));
	// lfs f5,4108(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4108);
	ctx.f5.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4096(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// lfs f26,4112(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4112);
	ctx.f26.f64 = double(temp.f32);
	// rlwinm r16,r10,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f5,f30,f5,f2
	ctx.f5.f64 = double(float(ctx.f30.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fadds f2,f5,f6
	ctx.f2.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// stfsx f2,r16,r18
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f5,f2,f26,f30
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f26.f64 + ctx.f30.f64));
	// stfs f5,4116(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4116, temp.u32);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// addi r16,r17,1
	ctx.r16.s64 = ctx.r17.s64 + 1;
	// lwz r17,4096(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// addi r10,r17,1
	ctx.r10.s64 = ctx.r17.s64 + 1;
	// lwz r17,732(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 732);
	// clrlwi r16,r16,22
	ctx.r16.u64 = ctx.r16.u32 & 0x3FF;
	// clrlwi r10,r10,22
	ctx.r10.u64 = ctx.r10.u32 & 0x3FF;
	// stw r16,4100(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4100, ctx.r16.u32);
	// stw r10,4096(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4096, ctx.r10.u32);
	// lwz r18,320(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// lfs f2,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r16,8(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f5,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f23,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f30,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfs f26,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f26.f64 = double(temp.f32);
	// fadds f22,f23,f24
	ctx.f22.f64 = double(float(ctx.f23.f64 + ctx.f24.f64));
	// fsubs f24,f23,f24
	ctx.f24.f64 = double(float(ctx.f23.f64 - ctx.f24.f64));
	// lfs f23,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// lfsx f21,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f21.f64 = double(temp.f32);
	// fmuls f5,f21,f5
	ctx.f5.f64 = double(float(ctx.f21.f64 * ctx.f5.f64));
	// stfs f30,0(r18)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f23,4(r18)
	temp.f32 = float(ctx.f23.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmadds f5,f26,f30,f5
	ctx.f5.f64 = double(float(ctx.f26.f64 * ctx.f30.f64 + ctx.f5.f64));
	// stfs f5,20(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lfs f26,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// lwz r18,16384(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16384);
	// lfs f30,16396(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16396);
	ctx.f30.f64 = double(temp.f32);
	// lwz r15,16388(r29)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16388);
	// lwz r16,16392(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16392);
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// rlwinm r14,r18,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f26,f26,f13
	ctx.f26.f64 = double(float(ctx.f26.f64 + ctx.f13.f64));
	// subf r18,r15,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r15.s64;
	// lfs f5,16400(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16400);
	ctx.f5.f64 = double(temp.f32);
	// rlwinm r16,r16,2,18,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfsx f13,r16,r29
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r29.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f23,r18,r29
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r29.u32);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f5,f13,f5
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// fmuls f13,f23,f30
	ctx.f13.f64 = double(float(ctx.f23.f64 * ctx.f30.f64));
	// stfs f13,16404(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16404, temp.u32);
	// stfs f5,16408(r29)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16408, temp.u32);
	// stfsx f7,r14,r29
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r14.u32 + ctx.r29.u32, temp.u32);
	// lwz r18,16384(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16384);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r16,r18,20
	ctx.r16.u64 = ctx.r18.u32 & 0xFFF;
	// lwz r18,328(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// stw r16,16384(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16384, ctx.r16.u32);
	// lwz r16,2052(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// lwz r15,2048(r18)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfs f7,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f7,f13,f7,f22
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f7.f64 + ctx.f22.f64));
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f5,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f5.f64 = double(temp.f32);
	// fadds f8,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 + ctx.f8.f64));
	// stfsx f8,r15,r18
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r18.u32, temp.u32);
	// fmadds f7,f8,f5,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f5.f64 + ctx.f13.f64));
	// lfsu f13,4(r17)
	ea = 4 + ctx.r17.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r17.u32 = ea;
	// fadds f5,f1,f29
	ctx.f5.f64 = double(float(ctx.f1.f64 + ctx.f29.f64));
	// lwz r15,336(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	// stfs f7,2068(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// fsubs f1,f1,f29
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f29.f64));
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// stw r17,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r17.u32);
	// fadds f3,f27,f3
	ctx.f3.f64 = double(float(ctx.f27.f64 + ctx.f3.f64));
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// ld r20,416(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + 416);
	// addi r16,r17,1
	ctx.r16.s64 = ctx.r17.s64 + 1;
	// lwz r17,2048(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r16,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r16.u32);
	// stw r17,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r17.u32);
	// lwz r18,344(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	// lfs f7,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f30,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f30.f64 = double(temp.f32);
	// lfsx f8,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,2048(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// fmadds f7,f8,f7,f24
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f24.f64));
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f7,f7,f25
	ctx.f7.f64 = double(float(ctx.f7.f64 + ctx.f25.f64));
	// stfsx f7,r17,r18
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r18.u32, temp.u32);
	// fmadds f8,f7,f30,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f30.f64 + ctx.f8.f64));
	// stfs f8,2068(r18)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// lwz r18,352(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lfs f7,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f7.f64 = double(temp.f32);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// lfs f8,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f30,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f7,f7,f30,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f30.f64 + ctx.f5.f64));
	// fadds f6,f7,f6
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// stfsx f6,r16,r18
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f5,f6,f8,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f8.f64 + ctx.f30.f64));
	// stfs f5,8212(r18)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r16,8196(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// stw r17,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r17.u32);
	// clrlwi r17,r16,21
	ctx.r17.u64 = ctx.r16.u32 & 0x7FF;
	// lwz r16,360(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	// stw r17,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r17.u32);
	// lfs f7,8208(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 8208);
	ctx.f7.f64 = double(temp.f32);
	// lwz r18,8196(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8196);
	// lfs f8,8204(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 8204);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,8192(r21)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8192);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r18,r21
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r21.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f6,f8,f1
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f8.f64 + ctx.f1.f64));
	// fadds f1,f5,f28
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f28.f64));
	// stfsx f1,r17,r21
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r21.u32, temp.u32);
	// fadds f5,f26,f4
	ctx.f5.f64 = double(float(ctx.f26.f64 + ctx.f4.f64));
	// fmadds f8,f7,f1,f6
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f6.f64));
	// stfs f8,8212(r21)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r21.u32 + 8212, temp.u32);
	// lwz r17,8192(r21)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8192);
	// lwz r18,8196(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 8196);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r18,8196(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8196, ctx.r18.u32);
	// stw r17,8192(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8192, ctx.r17.u32);
	// lfs f7,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,2060(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 2060);
	ctx.f6.f64 = double(temp.f32);
	// lwz r17,2048(r20)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// lfs f4,2064(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 2064);
	ctx.f4.f64 = double(temp.f32);
	// lwz r18,2052(r20)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r18,r20
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r20.u32);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f8,f6,f1
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// ld r19,440(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + 440);
	// lwz r15,368(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// lwz r14,376(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	// fmadds f6,f5,f10,f8
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfsx f6,r17,r20
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r20.u32, temp.u32);
	// lwz r17,2048(r20)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// lwz r18,2052(r20)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2052);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// fmadds f5,f6,f4,f1
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f4.f64 + ctx.f1.f64));
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stfs f5,2068(r20)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r20.u32 + 2068, temp.u32);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r18,2052(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2052, ctx.r18.u32);
	// stw r17,2048(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2048, ctx.r17.u32);
	// lwz r18,2052(r19)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2052);
	// lfs f4,2060(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 2060);
	ctx.f4.f64 = double(temp.f32);
	// lwz r17,2048(r19)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2048);
	// lfs f1,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f8,2064(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 2064);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r18,r19
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r19.u32);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f6,f4,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f4.f64 + ctx.f7.f64));
	// stfsx f5,r17,r19
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r19.u32, temp.u32);
	// lwz r17,2048(r19)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2048);
	// fmadds f4,f5,f8,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64 + ctx.f6.f64));
	// lwz r18,2052(r19)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2052);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stfs f4,2068(r19)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r19.u32 + 2068, temp.u32);
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// lwz r18,384(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 384);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r16,2052(r19)
	PPC_STORE_U32(ctx.r19.u32 + 2052, ctx.r16.u32);
	// stw r17,2048(r19)
	PPC_STORE_U32(ctx.r19.u32 + 2048, ctx.r17.u32);
	// lfs f7,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f8,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f6.f64 = double(temp.f32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f5,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fmadds f3,f3,f10,f4
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfsx f3,r16,r18
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f8,f3,f6,f5
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f6.f64 + ctx.f5.f64));
	// stfs f8,2068(r18)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// lwz r18,392(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 392);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f6,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f6.f64 = double(temp.f32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfs f5,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f5.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f4,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f4,f4,f0
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// lfsx f3,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f8,f3,f6,f7
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f6.f64 + ctx.f7.f64));
	// stfsx f8,r16,r18
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fsubs f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f0.f64));
	// fmadds f7,f8,f5,f3
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fmuls f5,f1,f0
	ctx.f5.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stfs f7,2068(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// fmadds f3,f6,f2,f5
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f2.f64 + ctx.f5.f64));
	// lwz r18,740(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 740);
	// fmadds f2,f6,f13,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f4.f64));
	// ld r11,424(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 424);
	// fcmpu cr6,f31,f12
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// ld r10,432(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 432);
	// ld r7,448(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 448);
	// stfs f3,0(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfsu f2,4(r18)
	temp.f32 = float(ctx.f2.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// addi r18,r18,4
	ctx.r18.s64 = ctx.r18.s64 + 4;
	// stw r18,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r18.u32);
	// ble cr6,0x82133584
	if (!ctx.cr6.gt) goto loc_82133584;
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82133584
	if (!ctx.cr6.lt) goto loc_82133584;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
loc_82133584:
	// fcmpu cr6,f31,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f12.f64);
	// bge cr6,0x82133598
	if (!ctx.cr6.lt) goto loc_82133598;
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x82133598
	if (!ctx.cr6.gt) goto loc_82133598;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
loc_82133598:
	// lwz r18,84(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r18,r18,8
	ctx.r18.s64 = ctx.r18.s64 + 8;
	// stw r18,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r18.u32);
	// bdnz 0x82132608
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82132608;
loc_821335A8:
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080398
	ctx.lr = 0x821335B4;
	__restfpr_21(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821335B8"))) PPC_WEAK_FUNC(sub_821335B8);
PPC_FUNC_IMPL(__imp__sub_821335B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x821335C0;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080338
	ctx.lr = 0x821335C8;
	__savefpr_16(ctx, base);
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r5.u32);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// stw r6,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r6.u32);
	// addis r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 196608;
	// stw r4,796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 796, ctx.r4.u32);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r3,22960
	ctx.r3.s64 = ctx.r3.s64 + 22960;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x8212e7f8
	ctx.lr = 0x821335FC;
	sub_8212E7F8(ctx, base);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r3,22992
	ctx.r3.s64 = ctx.r3.s64 + 22992;
	// bl 0x8212e150
	ctx.lr = 0x82133610;
	sub_8212E150(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f29,f12
	ctx.cr6.compare(ctx.f29.f64, ctx.f12.f64);
	// ble cr6,0x82133628
	if (!ctx.cr6.gt) goto loc_82133628;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
loc_82133628:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82134cb4
	if (ctx.cr6.eq) goto loc_82134CB4;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,2152
	ctx.r11.s64 = ctx.r11.s64 + 2152;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// stw r11,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r11.u32);
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 65536;
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,2156
	ctx.r10.s64 = ctx.r10.s64 + 2156;
	// addi r9,r9,2160
	ctx.r9.s64 = ctx.r9.s64 + 2160;
	// addi r8,r8,2696
	ctx.r8.s64 = ctx.r8.s64 + 2696;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// addi r7,r7,10920
	ctx.r7.s64 = ctx.r7.s64 + 10920;
	// stw r9,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r9.u32);
	// addi r6,r6,10924
	ctx.r6.s64 = ctx.r6.s64 + 10924;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// addi r5,r5,10928
	ctx.r5.s64 = ctx.r5.s64 + 10928;
	// stw r7,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r7.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r5,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r5.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,11976
	ctx.r4.s64 = ctx.r4.s64 + 11976;
	// addi r3,r3,14048
	ctx.r3.s64 = ctx.r3.s64 + 14048;
	// addi r11,r11,68
	ctx.r11.s64 = ctx.r11.s64 + 68;
	// stw r4,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r3,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r3.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// addis r8,r31,1
	ctx.r8.s64 = ctx.r31.s64 + 65536;
	// addis r7,r31,6
	ctx.r7.s64 = ctx.r31.s64 + 393216;
	// addis r6,r31,5
	ctx.r6.s64 = ctx.r31.s64 + 327680;
	// addis r5,r31,5
	ctx.r5.s64 = ctx.r31.s64 + 327680;
	// addi r10,r10,72
	ctx.r10.s64 = ctx.r10.s64 + 72;
	// addi r9,r9,18168
	ctx.r9.s64 = ctx.r9.s64 + 18168;
	// addi r8,r8,18172
	ctx.r8.s64 = ctx.r8.s64 + 18172;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// addi r7,r7,-30592
	ctx.r7.s64 = ctx.r7.s64 + -30592;
	// stw r9,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r9.u32);
	// addi r6,r6,25116
	ctx.r6.s64 = ctx.r6.s64 + 25116;
	// stw r8,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r8.u32);
	// addi r5,r5,25120
	ctx.r5.s64 = ctx.r5.s64 + 25120;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addis r4,r31,5
	ctx.r4.s64 = ctx.r31.s64 + 327680;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// addis r3,r31,5
	ctx.r3.s64 = ctx.r31.s64 + 327680;
	// stw r5,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r5.u32);
	// addis r11,r31,6
	ctx.r11.s64 = ctx.r31.s64 + 393216;
	// addi r4,r4,25124
	ctx.r4.s64 = ctx.r4.s64 + 25124;
	// addi r3,r3,25660
	ctx.r3.s64 = ctx.r3.s64 + 25660;
	// addi r11,r11,-31652
	ctx.r11.s64 = ctx.r11.s64 + -31652;
	// stw r4,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r4.u32);
	// addis r10,r31,6
	ctx.r10.s64 = ctx.r31.s64 + 393216;
	// stw r3,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r3.u32);
	// addis r9,r31,6
	ctx.r9.s64 = ctx.r31.s64 + 393216;
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// addis r8,r31,6
	ctx.r8.s64 = ctx.r31.s64 + 393216;
	// addis r7,r31,6
	ctx.r7.s64 = ctx.r31.s64 + 393216;
	// addis r6,r31,5
	ctx.r6.s64 = ctx.r31.s64 + 327680;
	// addis r5,r31,5
	ctx.r5.s64 = ctx.r31.s64 + 327680;
	// addi r10,r10,-31648
	ctx.r10.s64 = ctx.r10.s64 + -31648;
	// addi r9,r9,-31644
	ctx.r9.s64 = ctx.r9.s64 + -31644;
	// addi r8,r8,-30596
	ctx.r8.s64 = ctx.r8.s64 + -30596;
	// stw r10,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r10.u32);
	// addi r7,r7,-28524
	ctx.r7.s64 = ctx.r7.s64 + -28524;
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// addi r6,r6,23032
	ctx.r6.s64 = ctx.r6.s64 + 23032;
	// stw r8,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r8.u32);
	// addi r5,r5,23036
	ctx.r5.s64 = ctx.r5.s64 + 23036;
	// stw r7,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r7.u32);
	// addis r4,r31,6
	ctx.r4.s64 = ctx.r31.s64 + 393216;
	// stw r6,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// addis r3,r31,6
	ctx.r3.s64 = ctx.r31.s64 + 393216;
	// stw r5,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r5.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,-24404
	ctx.r4.s64 = ctx.r4.s64 + -24404;
	// addi r3,r3,-24400
	ctx.r3.s64 = ctx.r3.s64 + -24400;
	// addi r11,r11,22340
	ctx.r11.s64 = ctx.r11.s64 + 22340;
	// stw r4,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r4.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// stw r3,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r3.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,20244
	ctx.r4.s64 = ctx.r4.s64 + 20244;
	// stw r11,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r11.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// stw r4,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, ctx.r4.u32);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,22316
	ctx.r3.s64 = ctx.r3.s64 + 22316;
	// addi r30,r30,22336
	ctx.r30.s64 = ctx.r30.s64 + 22336;
	// addi r4,r4,22364
	ctx.r4.s64 = ctx.r4.s64 + 22364;
	// stw r3,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// stw r30,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r30.u32);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// stw r4,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r4.u32);
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,22388
	ctx.r3.s64 = ctx.r3.s64 + 22388;
	// addi r30,r30,-26740
	ctx.r30.s64 = ctx.r30.s64 + -26740;
	// addi r4,r4,-26716
	ctx.r4.s64 = ctx.r4.s64 + -26716;
	// stw r3,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r3.u32);
	// stw r30,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, ctx.r30.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r4,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r4.u32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addis r8,r31,2
	ctx.r8.s64 = ctx.r31.s64 + 131072;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r6,r31,2
	ctx.r6.s64 = ctx.r31.s64 + 131072;
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r10,r10,20248
	ctx.r10.s64 = ctx.r10.s64 + 20248;
	// addi r9,r9,22368
	ctx.r9.s64 = ctx.r9.s64 + 22368;
	// addi r8,r8,-24640
	ctx.r8.s64 = ctx.r8.s64 + -24640;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r7,r7,22320
	ctx.r7.s64 = ctx.r7.s64 + 22320;
	// stw r9,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r9.u32);
	// addi r6,r6,-26732
	ctx.r6.s64 = ctx.r6.s64 + -26732;
	// stw r8,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r8.u32);
	// addi r5,r5,-22568
	ctx.r5.s64 = ctx.r5.s64 + -22568;
	// stw r7,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, ctx.r7.u32);
	// addi r3,r3,-26736
	ctx.r3.s64 = ctx.r3.s64 + -26736;
	// stw r6,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r6.u32);
	// addi r30,r30,-24644
	ctx.r30.s64 = ctx.r30.s64 + -24644;
	// stw r5,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r5.u32);
	// addi r4,r4,-22572
	ctx.r4.s64 = ctx.r4.s64 + -22572;
	// stw r3,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r3.u32);
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stw r4,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r4.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addis r7,r31,1
	ctx.r7.s64 = ctx.r31.s64 + 65536;
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// addis r24,r31,1
	ctx.r24.s64 = ctx.r31.s64 + 65536;
	// addis r9,r31,5
	ctx.r9.s64 = ctx.r31.s64 + 327680;
	// addis r8,r31,5
	ctx.r8.s64 = ctx.r31.s64 + 327680;
	// addis r6,r31,6
	ctx.r6.s64 = ctx.r31.s64 + 393216;
	// addis r23,r31,5
	ctx.r23.s64 = ctx.r31.s64 + 327680;
	// addis r22,r31,6
	ctx.r22.s64 = ctx.r31.s64 + 393216;
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r11,r11,76
	ctx.r11.s64 = ctx.r11.s64 + 76;
	// addi r10,r10,2700
	ctx.r10.s64 = ctx.r10.s64 + 2700;
	// addi r7,r7,14052
	ctx.r7.s64 = ctx.r7.s64 + 14052;
	// addi r26,r26,2164
	ctx.r26.s64 = ctx.r26.s64 + 2164;
	// addi r25,r25,10932
	ctx.r25.s64 = ctx.r25.s64 + 10932;
	// addi r24,r24,11980
	ctx.r24.s64 = ctx.r24.s64 + 11980;
	// addi r9,r9,23040
	ctx.r9.s64 = ctx.r9.s64 + 23040;
	// addi r8,r8,25664
	ctx.r8.s64 = ctx.r8.s64 + 25664;
	// addi r6,r6,-28520
	ctx.r6.s64 = ctx.r6.s64 + -28520;
	// addi r23,r23,25128
	ctx.r23.s64 = ctx.r23.s64 + 25128;
	// addi r22,r22,-31640
	ctx.r22.s64 = ctx.r22.s64 + -31640;
	// addi r5,r5,22392
	ctx.r5.s64 = ctx.r5.s64 + 22392;
	// addi r3,r3,-22552
	ctx.r3.s64 = ctx.r3.s64 + -22552;
	// addi r30,r30,-22524
	ctx.r30.s64 = ctx.r30.s64 + -22524;
	// addi r4,r4,-22548
	ctx.r4.s64 = ctx.r4.s64 + -22548;
	// stw r3,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r3.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r30,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r30.u32);
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// addi r3,r3,-22520
	ctx.r3.s64 = ctx.r3.s64 + -22520;
	// stw r4,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// addi r30,r30,10372
	ctx.r30.s64 = ctx.r30.s64 + 10372;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// stw r30,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r30.u32);
	// addi r4,r4,18588
	ctx.r4.s64 = ctx.r4.s64 + 18588;
	// addi r3,r3,-6084
	ctx.r3.s64 = ctx.r3.s64 + -6084;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r4,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r4.u32);
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,-22500
	ctx.r30.s64 = ctx.r30.s64 + -22500;
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addi r4,r4,-6092
	ctx.r4.s64 = ctx.r4.s64 + -6092;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r3,-6088
	ctx.r3.s64 = ctx.r3.s64 + -6088;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stw r3,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r3.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,-6068
	ctx.r30.s64 = ctx.r30.s64 + -6068;
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addi r4,r4,2148
	ctx.r4.s64 = ctx.r4.s64 + 2148;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// addi r3,r3,10368
	ctx.r3.s64 = ctx.r3.s64 + 10368;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r4,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,18584
	ctx.r30.s64 = ctx.r30.s64 + 18584;
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// addi r4,r4,22704
	ctx.r4.s64 = ctx.r4.s64 + 22704;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// addi r3,r3,-26424
	ctx.r3.s64 = ctx.r3.s64 + -26424;
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r4,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r4.u32);
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r30,r30,-26420
	ctx.r30.s64 = ctx.r30.s64 + -26420;
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// addi r4,r4,-26416
	ctx.r4.s64 = ctx.r4.s64 + -26416;
	// stw r30,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r30.u32);
	// addi r3,r3,-9956
	ctx.r3.s64 = ctx.r3.s64 + -9956;
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r4,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r4.u32);
	// stw r3,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r3.u32);
	// addis r4,r31,3
	ctx.r4.s64 = ctx.r31.s64 + 196608;
	// addi r30,r30,-1740
	ctx.r30.s64 = ctx.r30.s64 + -1740;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,18792
	ctx.r4.s64 = ctx.r4.s64 + 18792;
	// stw r30,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r30.u32);
	// addi r3,r3,18176
	ctx.r3.s64 = ctx.r3.s64 + 18176;
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r4,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r4.u32);
	// stw r3,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// addi r30,r30,-26712
	ctx.r30.s64 = ctx.r30.s64 + -26712;
	// addis r3,r31,3
	ctx.r3.s64 = ctx.r31.s64 + 196608;
	// addi r4,r4,-6064
	ctx.r4.s64 = ctx.r4.s64 + -6064;
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r30.u32);
	// addi r3,r3,-26396
	ctx.r3.s64 = ctx.r3.s64 + -26396;
	// addis r30,r31,3
	ctx.r30.s64 = ctx.r31.s64 + 196608;
	// stw r4,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r4.u32);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// stw r3,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r3.u32);
	// addi r30,r30,-18180
	ctx.r30.s64 = ctx.r30.s64 + -18180;
	// addi r29,r29,-9960
	ctx.r29.s64 = ctx.r29.s64 + -9960;
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// stw r30,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r30.u32);
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// stw r29,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r29.u32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// addi r28,r28,-1744
	ctx.r28.s64 = ctx.r28.s64 + -1744;
	// addi r4,r4,-22496
	ctx.r4.s64 = ctx.r4.s64 + -22496;
	// addi r3,r3,22708
	ctx.r3.s64 = ctx.r3.s64 + 22708;
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// lwz r21,812(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 812);
	// addi r20,r20,2376
	ctx.r20.s64 = ctx.r20.s64 + 2376;
	// stw r28,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r28.u32);
	// addi r19,r19,18784
	ctx.r19.s64 = ctx.r19.s64 + 18784;
	// stw r20,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r20.u32);
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// addis r27,r31,3
	ctx.r27.s64 = ctx.r31.s64 + 196608;
	// stw r19,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r19.u32);
	// addi r20,r20,18788
	ctx.r20.s64 = ctx.r20.s64 + 18788;
	// stw r21,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r21.u32);
	// addi r27,r27,18812
	ctx.r27.s64 = ctx.r27.s64 + 18812;
	// lwz r21,80(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r20,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r20.u32);
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// addis r20,r31,3
	ctx.r20.s64 = ctx.r31.s64 + 196608;
	// stw r27,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r27.u32);
	// addi r19,r19,-26392
	ctx.r19.s64 = ctx.r19.s64 + -26392;
	// addi r20,r20,20888
	ctx.r20.s64 = ctx.r20.s64 + 20888;
	// addis r27,r31,3
	ctx.r27.s64 = ctx.r31.s64 + 196608;
	// stw r19,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r19.u32);
	// stw r20,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r20.u32);
	// addis r19,r31,6
	ctx.r19.s64 = ctx.r31.s64 + 393216;
	// addi r27,r27,18816
	ctx.r27.s64 = ctx.r27.s64 + 18816;
	// addis r20,r31,6
	ctx.r20.s64 = ctx.r31.s64 + 393216;
	// addi r19,r19,-24396
	ctx.r19.s64 = ctx.r19.s64 + -24396;
	// stw r27,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r27.u32);
	// addi r20,r20,-20252
	ctx.r20.s64 = ctx.r20.s64 + -20252;
	// addis r27,r31,6
	ctx.r27.s64 = ctx.r31.s64 + 393216;
	// stw r19,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r19.u32);
	// stw r20,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r20.u32);
	// addis r19,r31,6
	ctx.r19.s64 = ctx.r31.s64 + 393216;
	// addi r27,r27,-22324
	ctx.r27.s64 = ctx.r27.s64 + -22324;
	// addis r20,r31,6
	ctx.r20.s64 = ctx.r31.s64 + 393216;
	// addi r19,r19,-18180
	ctx.r19.s64 = ctx.r19.s64 + -18180;
	// stw r27,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r27.u32);
	// addi r20,r20,-14032
	ctx.r20.s64 = ctx.r20.s64 + -14032;
	// addis r27,r31,6
	ctx.r27.s64 = ctx.r31.s64 + 393216;
	// stw r19,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r19.u32);
	// stw r20,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r20.u32);
	// addis r19,r31,3
	ctx.r19.s64 = ctx.r31.s64 + 196608;
	// addi r27,r27,-14036
	ctx.r27.s64 = ctx.r27.s64 + -14036;
	// addis r20,r31,6
	ctx.r20.s64 = ctx.r31.s64 + 393216;
	// addis r18,r31,6
	ctx.r18.s64 = ctx.r31.s64 + 393216;
	// stw r27,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r27.u32);
	// addi r19,r19,20884
	ctx.r19.s64 = ctx.r19.s64 + 20884;
	// addi r20,r20,-22328
	ctx.r20.s64 = ctx.r20.s64 + -22328;
	// addi r18,r18,-18184
	ctx.r18.s64 = ctx.r18.s64 + -18184;
	// stw r19,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r19.u32);
	// addis r27,r31,3
	ctx.r27.s64 = ctx.r31.s64 + 196608;
	// stw r20,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r20.u32);
	// addis r19,r31,6
	ctx.r19.s64 = ctx.r31.s64 + 393216;
	// stw r18,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r18.u32);
	// addi r27,r27,22956
	ctx.r27.s64 = ctx.r27.s64 + 22956;
	// addis r20,r31,6
	ctx.r20.s64 = ctx.r31.s64 + 393216;
	// lis r18,-32254
	ctx.r18.s64 = -2113798144;
	// stw r27,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r27.u32);
	// lis r17,-32256
	ctx.r17.s64 = -2113929216;
	// lis r16,-32256
	ctx.r16.s64 = -2113929216;
	// lis r15,-32256
	ctx.r15.s64 = -2113929216;
	// addi r19,r19,-20256
	ctx.r19.s64 = ctx.r19.s64 + -20256;
	// addi r20,r20,-16112
	ctx.r20.s64 = ctx.r20.s64 + -16112;
	// lfs f28,-19288(r18)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + -19288);
	ctx.f28.f64 = double(temp.f32);
	// addis r30,r31,2
	ctx.r30.s64 = ctx.r31.s64 + 131072;
	// stw r19,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r19.u32);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// stw r20,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r20.u32);
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// lwz r19,272(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// addis r27,r31,6
	ctx.r27.s64 = ctx.r31.s64 + 393216;
	// lwz r20,84(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lfs f1,14004(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 14004);
	ctx.f1.f64 = double(temp.f32);
	// addi r30,r30,2152
	ctx.r30.s64 = ctx.r30.s64 + 2152;
	// lfs f31,12868(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 12868);
	ctx.f31.f64 = double(temp.f32);
	// addi r29,r29,2380
	ctx.r29.s64 = ctx.r29.s64 + 2380;
	// lfs f5,23040(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 23040);
	ctx.f5.f64 = double(temp.f32);
	// addi r28,r28,-18176
	ctx.r28.s64 = ctx.r28.s64 + -18176;
	// addi r27,r27,-16108
	ctx.r27.s64 = ctx.r27.s64 + -16108;
	// lis r14,-32256
	ctx.r14.s64 = -2113929216;
	// lfs f30,12864(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 12864);
	ctx.f30.f64 = double(temp.f32);
loc_82133B44:
	// lwz r18,2048(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// lfs f0,2064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2064);
	ctx.f0.f64 = double(temp.f32);
	// lwz r17,2052(r11)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2052);
	// lfs f11,2068(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2068);
	ctx.f11.f64 = double(temp.f32);
	// lwz r16,2056(r11)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2056);
	// rlwinm r15,r18,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r14,2060(r11)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2060);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// std r27,464(r1)
	PPC_STORE_U64(ctx.r1.u32 + 464, ctx.r27.u64);
	// subf r14,r14,r18
	ctx.r14.s64 = ctx.r18.s64 - ctx.r14.s64;
	// lwz r27,284(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// lwz r18,104(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r17,r17,2,21,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x7FC;
	// rlwinm r16,r16,2,21,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x7FC;
	// std r29,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, ctx.r29.u64);
	// rlwinm r14,r14,2,21,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0x7FC;
	// lwz r29,420(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 420);
	// lfs f10,2072(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 2072);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// lfsx f2,r17,r11
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r18,88(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lfs f7,0(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r29,112(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lfs f6,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f3,4(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f8,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r27,292(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// fadds f4,f8,f9
	ctx.f4.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// lfsx f9,r16,r11
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// lfsx f2,r14,r11
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + ctx.r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f0,f9,f11
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfs f8,2076(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2076, temp.u32);
	// fmuls f11,f10,f2
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f2.f64));
	// stfs f0,2080(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2080, temp.u32);
	// stfs f11,2084(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 2084, temp.u32);
	// lwz r16,120(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stfsx f6,r15,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r11.u32, temp.u32);
	// lwz r18,2048(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// lwz r14,380(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2048(r11)
	PPC_STORE_U32(ctx.r11.u32 + 2048, ctx.r18.u32);
	// lfs f10,524(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 524);
	ctx.f10.f64 = double(temp.f32);
	// lwz r18,512(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 512);
	// lfs f9,0(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lwz r17,516(r26)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r26.u32 + 516);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f8,r17,r26
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r26.u32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f6,528(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 528);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f4,f8,f10,f4
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + ctx.f4.f64));
	// stfsx f4,r18,r26
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r26.u32, temp.u32);
	// lwz r17,512(r26)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r26.u32 + 512);
	// lwz r18,516(r26)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r26.u32 + 516);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// fmadds f2,f6,f4,f8
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f4.f64 + ctx.f8.f64));
	// clrlwi r18,r18,25
	ctx.r18.u64 = ctx.r18.u32 & 0x7F;
	// stfs f2,532(r26)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r26.u32 + 532, temp.u32);
	// clrlwi r17,r17,25
	ctx.r17.u64 = ctx.r17.u32 & 0x7F;
	// stw r18,516(r26)
	PPC_STORE_U32(ctx.r26.u32 + 516, ctx.r18.u32);
	// stw r17,512(r26)
	PPC_STORE_U32(ctx.r26.u32 + 512, ctx.r17.u32);
	// lfs f11,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r18,8200(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8200);
	// lwz r17,8204(r10)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8204);
	// lfs f10,8208(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8208);
	ctx.f10.f64 = double(temp.f32);
	// lwz r16,8192(r10)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// lfs f8,8212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8212);
	ctx.f8.f64 = double(temp.f32);
	// lwz r15,8196(r10)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8196);
	// subf r15,r15,r16
	ctx.r15.s64 = ctx.r16.s64 - ctx.r15.s64;
	// rlwinm r15,r15,2,19,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x1FFC;
	// lfs f6,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// fadds f4,f11,f0
	ctx.f4.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// subf r17,r17,r16
	ctx.r17.s64 = ctx.r16.s64 - ctx.r17.s64;
	// lfsx f2,r15,r10
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r10.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r18,r18,2,19,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x1FFC;
	// fmuls f11,f10,f2
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f2.f64));
	// rlwinm r17,r17,2,19,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x1FFC;
	// lfs f0,8216(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8216);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r15,128(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r14,300(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r29,136(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lfsx f10,r18,r10
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lwz r18,144(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lfsx f2,r17,r10
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r10.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f10,f10,f8
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f8.f64));
	// fmuls f8,f2,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// stfs f8,8228(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8228, temp.u32);
	// stfs f11,8220(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8220, temp.u32);
	// lwz r17,308(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stfs f10,8224(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8224, temp.u32);
	// lwz r27,456(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 456);
	// stfsx f9,r16,r10
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r10.u32, temp.u32);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// lwz r18,8192(r10)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8192);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// stw r18,8192(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8192, ctx.r18.u32);
	// lfs f2,1036(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 1036);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,1024(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 1024);
	// lfs f0,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r16,1028(r25)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r25.u32 + 1028);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r16,r25
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r25.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,1040(r25)
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + 1040);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f8,f2,f11,f4
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f4.f64));
	// stfsx f8,r18,r25
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r25.u32, temp.u32);
	// lwz r18,1028(r25)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r25.u32 + 1028);
	// lwz r17,1024(r25)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r25.u32 + 1024);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// fmadds f4,f8,f10,f11
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + ctx.f11.f64));
	// clrlwi r17,r17,24
	ctx.r17.u64 = ctx.r17.u32 & 0xFF;
	// stfs f4,1044(r25)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r25.u32 + 1044, temp.u32);
	// clrlwi r18,r18,24
	ctx.r18.u64 = ctx.r18.u32 & 0xFF;
	// lwz r15,80(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r17,1024(r25)
	PPC_STORE_U32(ctx.r25.u32 + 1024, ctx.r17.u32);
	// stw r18,1028(r25)
	PPC_STORE_U32(ctx.r25.u32 + 1028, ctx.r18.u32);
	// lfs f2,2060(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 2060);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,2052(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,2048(r24)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r24.u32 + 2048);
	// lfsx f11,r18,r24
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r24.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f8,f2,f11,f0
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f0.f64));
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f4,2064(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 2064);
	ctx.f4.f64 = double(temp.f32);
	// lwz r14,84(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfsx f8,r18,r24
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r24.u32, temp.u32);
	// lwz r18,2052(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 2052);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,2048(r24)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r24.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// fmadds f2,f8,f4,f11
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f4.f64 + ctx.f11.f64));
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stfs f2,2068(r24)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r24.u32 + 2068, temp.u32);
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r17,2052(r24)
	PPC_STORE_U32(ctx.r24.u32 + 2052, ctx.r17.u32);
	// stw r18,2048(r24)
	PPC_STORE_U32(ctx.r24.u32 + 2048, ctx.r18.u32);
	// lfs f27,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lwz r18,4104(r7)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4104);
	// lfs f8,4108(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4108);
	ctx.f8.f64 = double(temp.f32);
	// lwz r17,4100(r7)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4100);
	// lfs f4,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lwz r16,4096(r7)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4096);
	// lfs f2,4112(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4112);
	ctx.f2.f64 = double(temp.f32);
	// lfs f26,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// rlwinm r15,r16,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// lfs f11,0(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// subf r17,r17,r16
	ctx.r17.s64 = ctx.r16.s64 - ctx.r17.s64;
	// fmuls f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// rlwinm r18,r18,2,20,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFC;
	// rlwinm r17,r17,2,20,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFC;
	// lfsx f9,r18,r7
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r7.u32);
	ctx.f9.f64 = double(temp.f32);
	// lwz r18,168(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// fmuls f2,f9,f2
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f2.f64));
	// fmuls f0,f27,f0
	ctx.f0.f64 = double(float(ctx.f27.f64 * ctx.f0.f64));
	// lwz r16,152(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r14,388(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// std r10,472(r1)
	PPC_STORE_U64(ctx.r1.u32 + 472, ctx.r10.u64);
	// lfsx f9,r17,r7
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r7.u32);
	ctx.f9.f64 = double(temp.f32);
	// std r7,448(r1)
	PPC_STORE_U64(ctx.r1.u32 + 448, ctx.r7.u64);
	// fmuls f8,f9,f8
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// stfs f2,4120(r7)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4120, temp.u32);
	// stfs f8,4116(r7)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4116, temp.u32);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// stfsx f10,r15,r7
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r7.u32, temp.u32);
	// lwz r18,4096(r7)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4096);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// std r11,480(r1)
	PPC_STORE_U64(ctx.r1.u32 + 480, ctx.r11.u64);
	// clrlwi r18,r18,22
	ctx.r18.u64 = ctx.r18.u32 & 0x3FF;
	// fadds f2,f0,f11
	ctx.f2.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// lwz r29,160(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// stw r18,4096(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4096, ctx.r18.u32);
	// lfs f11,2068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2068);
	ctx.f11.f64 = double(temp.f32);
	// lwz r18,2052(r9)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2052);
	// lfs f27,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lfs f0,2064(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2064);
	ctx.f0.f64 = double(temp.f32);
	// lwz r27,316(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// lfs f10,2072(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2072);
	ctx.f10.f64 = double(temp.f32);
	// lwz r17,428(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 428);
	// lfs f9,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f25,0(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// fadds f7,f2,f7
	ctx.f7.f64 = double(float(ctx.f2.f64 + ctx.f7.f64));
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// lfs f8,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r10,2056(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2056);
	// lwz r15,2048(r9)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2048);
	// rlwinm r11,r15,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,2060(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2060);
	// subf r10,r10,r15
	ctx.r10.s64 = ctx.r15.s64 - ctx.r10.s64;
	// subf r18,r18,r15
	ctx.r18.s64 = ctx.r15.s64 - ctx.r18.s64;
	// fadds f8,f27,f8
	ctx.f8.f64 = double(float(ctx.f27.f64 + ctx.f8.f64));
	// rlwinm r16,r10,2,21,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// fmuls f9,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// subf r15,r7,r15
	ctx.r15.s64 = ctx.r15.s64 - ctx.r7.s64;
	// rlwinm r18,r18,2,21,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x7FC;
	// rlwinm r15,r15,2,21,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x7FC;
	// lfsx f2,r16,r9
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f11,f2,f11
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// lfsx f2,r18,r9
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// lfsx f27,r15,r9
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r9.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f0,f2,f0
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f0.f64));
	// fmuls f10,f10,f27
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f27.f64));
	// stfs f11,2080(r9)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2080, temp.u32);
	// stfs f10,2084(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2084, temp.u32);
	// stfs f0,2076(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 2076, temp.u32);
	// stfsx f3,r11,r9
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// lwz r18,2048(r9)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2048(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2048, ctx.r18.u32);
	// lfs f3,528(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 528);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,512(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 512);
	// lfs f0,524(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 524);
	ctx.f0.f64 = double(temp.f32);
	// lwz r16,516(r23)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r23.u32 + 516);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f2,r16,r23
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r23.u32);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f11,f2,f0,f8
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f0.f64 + ctx.f8.f64));
	// stfsx f11,r18,r23
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r23.u32, temp.u32);
	// lwz r17,516(r23)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r23.u32 + 516);
	// fmadds f10,f3,f11,f2
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f2.f64));
	// lwz r18,512(r23)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r23.u32 + 512);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// stfs f10,532(r23)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r23.u32 + 532, temp.u32);
	// clrlwi r18,r18,25
	ctx.r18.u64 = ctx.r18.u32 & 0x7F;
	// clrlwi r17,r17,25
	ctx.r17.u64 = ctx.r17.u32 & 0x7F;
	// stw r18,512(r23)
	PPC_STORE_U32(ctx.r23.u32 + 512, ctx.r18.u32);
	// stw r17,516(r23)
	PPC_STORE_U32(ctx.r23.u32 + 516, ctx.r17.u32);
	// lwz r18,8192(r8)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8192);
	// lwz r16,80(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r14,r18,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,8196(r8)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8196);
	// lfs f3,8208(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8208);
	ctx.f3.f64 = double(temp.f32);
	// lwz r15,8204(r8)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8204);
	// lfs f2,8212(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8212);
	ctx.f2.f64 = double(temp.f32);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// lwz r11,176(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lfs f0,8216(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8216);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,396(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lfs f8,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r16,8200(r8)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8200);
	// rlwinm r17,r17,2,19,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x1FFC;
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// subf r18,r15,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r15.s64;
	// lwz r15,84(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r16,r16,2,19,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x1FFC;
	// lfs f27,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// rlwinm r18,r18,2,19,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x1FFC;
	// lwz r11,184(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lfs f11,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r15,324(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// fadds f10,f11,f8
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f8.f64));
	// lfsx f8,r17,r8
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r8.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f8,f3,f8
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f8.f64));
	// lfsx f3,r18,r8
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r8.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfsx f11,r16,r8
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f3,f0
	ctx.f0.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fmuls f2,f11,f2
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f2.f64));
	// stfs f8,8220(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8220, temp.u32);
	// stfs f2,8224(r8)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8224, temp.u32);
	// stfs f0,8228(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 8228, temp.u32);
	// stfsx f7,r14,r8
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r14.u32 + ctx.r8.u32, temp.u32);
	// lwz r18,8192(r8)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8192);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,21
	ctx.r18.u64 = ctx.r18.u32 & 0x7FF;
	// stw r18,8192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8192, ctx.r18.u32);
	// lfs f3,1036(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 1036);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,1028(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 1028);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,1024(r22)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r22.u32 + 1024);
	// lfsx f8,r18,r22
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r22.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f2,f3,f8,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f8.f64 + ctx.f10.f64));
	// lfs f11,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,1040(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 1040);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f10,f2,f0,f8
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f0.f64 + ctx.f8.f64));
	// stfsx f2,r18,r22
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r22.u32, temp.u32);
	// lwz r18,1028(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 1028);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,1024(r22)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r22.u32 + 1024);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stfs f10,1044(r22)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r22.u32 + 1044, temp.u32);
	// clrlwi r17,r17,24
	ctx.r17.u64 = ctx.r17.u32 & 0xFF;
	// clrlwi r18,r18,24
	ctx.r18.u64 = ctx.r18.u32 & 0xFF;
	// stw r17,1028(r22)
	PPC_STORE_U32(ctx.r22.u32 + 1028, ctx.r17.u32);
	// stw r18,1024(r22)
	PPC_STORE_U32(ctx.r22.u32 + 1024, ctx.r18.u32);
	// lwz r17,2048(r21)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2048);
	// lfs f8,2064(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 2064);
	ctx.f8.f64 = double(temp.f32);
	// lwz r18,2052(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2052);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f3,r18,r21
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r21.u32);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f2,2060(r21)
	temp.u32 = PPC_LOAD_U32(ctx.r21.u32 + 2060);
	ctx.f2.f64 = double(temp.f32);
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f0,f2,f3,f11
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f3.f64 + ctx.f11.f64));
	// stfsx f0,r18,r21
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r21.u32, temp.u32);
	// fmadds f8,f0,f8,f3
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f8.f64 + ctx.f3.f64));
	// stfs f8,2068(r21)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r21.u32 + 2068, temp.u32);
	// lwz r18,2048(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2048);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,2052(r21)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r21.u32 + 2052);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// stw r17,2048(r21)
	PPC_STORE_U32(ctx.r21.u32 + 2048, ctx.r17.u32);
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2052(r21)
	PPC_STORE_U32(ctx.r21.u32 + 2052, ctx.r18.u32);
	// lfs f3,4112(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4112);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lwz r18,4096(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4096);
	// lfs f0,4108(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4108);
	ctx.f0.f64 = double(temp.f32);
	// lwz r17,4100(r6)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4100);
	// rlwinm r14,r18,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r16,4104(r6)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4104);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// lwz r15,192(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// subf r18,r16,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r16.s64;
	// lwz r16,332(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// rlwinm r17,r17,2,20,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFC;
	// lwz r11,200(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// rlwinm r18,r18,2,20,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFC;
	// lwz r10,440(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 440);
	// lwz r7,208(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lfs f8,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lwz r15,216(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// lfs f24,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f7,f8,f7
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// lfsx f8,r17,r6
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r6.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f11,f24,f11
	ctx.f11.f64 = double(float(ctx.f24.f64 * ctx.f11.f64));
	// lfsx f24,r18,r6
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r6.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f0,f8,f0
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lfs f23,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f8,f24,f3
	ctx.f8.f64 = double(float(ctx.f24.f64 * ctx.f3.f64));
	// stfs f0,4116(r6)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4116, temp.u32);
	// lwz r16,340(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// stfs f8,4120(r6)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4120, temp.u32);
	// stfsx f10,r14,r6
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r14.u32 + ctx.r6.u32, temp.u32);
	// fadds f7,f11,f7
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f7.f64));
	// fadds f3,f7,f25
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f25.f64));
	// lwz r18,4096(r6)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4096);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,22
	ctx.r18.u64 = ctx.r18.u32 & 0x3FF;
	// stw r18,4096(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4096, ctx.r18.u32);
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lwz r18,2052(r20)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2052);
	// fmuls f8,f3,f8
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f8.f64));
	// lfs f10,2060(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 2060);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r17,2048(r20)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f3,2064(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 2064);
	ctx.f3.f64 = double(temp.f32);
	// lfsx f0,r18,r20
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r20.u32);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r18,r17,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f7,f10,f0,f11
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f11.f64));
	// lfs f11,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f7,r18,r20
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r20.u32, temp.u32);
	// lwz r17,2048(r20)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2048);
	// fadds f11,f11,f6
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f6.f64));
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r18,2052(r20)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r20.u32 + 2052);
	// fmadds f10,f7,f3,f0
	ctx.f10.f64 = double(float(ctx.f7.f64 * ctx.f3.f64 + ctx.f0.f64));
	// stfs f10,2068(r20)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r20.u32 + 2068, temp.u32);
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// addi r14,r18,1
	ctx.r14.s64 = ctx.r18.s64 + 1;
	// lwz r18,404(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// stw r17,2048(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2048, ctx.r17.u32);
	// clrlwi r17,r14,23
	ctx.r17.u64 = ctx.r14.u32 & 0x1FF;
	// stw r17,2052(r20)
	PPC_STORE_U32(ctx.r20.u32 + 2052, ctx.r17.u32);
	// lfs f3,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f10,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f7,f10,f7,f11
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f7.f64 + ctx.f11.f64));
	// lfs f0,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f11,0(r18)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f7,16(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// lwz r18,224(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f7,20(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f0,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f0,f11,f3
	ctx.f10.f64 = double(float(ctx.f0.f64 * ctx.f11.f64 + ctx.f3.f64));
	// fmuls f0,f7,f0
	ctx.f0.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,4(r18)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f10,0(r18)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmadds f0,f7,f10,f0
	ctx.f0.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f0.f64));
	// stfs f0,24(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 24, temp.u32);
	// lwz r18,348(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// lwz r17,232(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lwz r16,436(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 436);
	// lwz r15,240(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	// lwz r14,356(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lfs f11,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,8(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f10,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f7,r11,r18
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r18.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f3,f11,f7,f3
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmuls f11,f3,f10
	ctx.f11.f64 = double(float(ctx.f3.f64 * ctx.f10.f64));
	// lfs f10,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// stfs f3,0(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmuls f7,f10,f30
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f30.f64));
	// stfs f0,4(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lwz r17,248(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// stfs f11,20(r18)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lwz r18,256(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// lfs f0,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,412(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// lwz r10,8(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f3,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r16,r10,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f25,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// lfsx f10,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f3,f10,f3
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f3.f64));
	// stfs f3,16(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// stfs f11,4(r18)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f0,0(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lfs f0,16396(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16396);
	ctx.f0.f64 = double(temp.f32);
	// lwz r15,16388(r5)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16388);
	// lfs f10,16400(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16400);
	ctx.f10.f64 = double(temp.f32);
	// lwz r16,16384(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16384);
	// lwz r18,16392(r5)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16392);
	// subf r15,r15,r16
	ctx.r15.s64 = ctx.r16.s64 - ctx.r15.s64;
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// lfs f11,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r15,r15,2,18,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f3,r15,r5
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r5.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f0,f3,f0
	ctx.f0.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// lfsx f24,r18,r5
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r5.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f10,f24,f10
	ctx.f10.f64 = double(float(ctx.f24.f64 * ctx.f10.f64));
	// stfs f10,16408(r5)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16408, temp.u32);
	// stfs f0,16404(r5)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16404, temp.u32);
	// stfsx f7,r16,r5
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r5.u32, temp.u32);
	// lwz r18,16384(r5)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16384);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,20
	ctx.r18.u64 = ctx.r18.u32 & 0xFFF;
	// stw r18,16384(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16384, ctx.r18.u32);
	// lfs f0,2060(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 2060);
	ctx.f0.f64 = double(temp.f32);
	// lwz r16,2048(r19)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2048);
	// lwz r18,2052(r19)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2052);
	// lfs f3,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f10,f10,f27
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f27.f64));
	// lfsx f7,r18,r19
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r19.u32);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r18,r16,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f3,f7,f0,f3
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f0.f64 + ctx.f3.f64));
	// lfs f0,2064(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 2064);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f3,r18,r19
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r19.u32, temp.u32);
	// lwz r17,2048(r19)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2048);
	// lwz r18,2052(r19)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r19.u32 + 2052);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r18,364(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// fmadds f7,f3,f0,f7
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f0.f64 + ctx.f7.f64));
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// stfs f7,2068(r19)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r19.u32 + 2068, temp.u32);
	// stw r16,2052(r19)
	PPC_STORE_U32(ctx.r19.u32 + 2052, ctx.r16.u32);
	// stw r17,2048(r19)
	PPC_STORE_U32(ctx.r19.u32 + 2048, ctx.r17.u32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f3,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// lwz r16,264(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f7,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r15,444(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	// lwz r14,92(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,372(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfsx f24,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f24.f64 = double(temp.f32);
	// lwz r16,100(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stfs f0,4(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmadds f3,f24,f3,f10
	ctx.f3.f64 = double(float(ctx.f24.f64 * ctx.f3.f64 + ctx.f10.f64));
	// stfs f3,16(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// stfs f10,0(r18)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lwz r18,108(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lfs f10,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f3,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f21,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f21.f64 = double(temp.f32);
	// lfs f0,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmadds f0,f21,f3,f7
	ctx.f0.f64 = double(float(ctx.f21.f64 * ctx.f3.f64 + ctx.f7.f64));
	// lfs f24,20(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 20);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f7,f21,f24
	ctx.f7.f64 = double(float(ctx.f21.f64 * ctx.f24.f64));
	// lfs f22,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f22.f64 = double(temp.f32);
	// stfs f0,0(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmadds f3,f22,f0,f7
	ctx.f3.f64 = double(float(ctx.f22.f64 * ctx.f0.f64 + ctx.f7.f64));
	// stfs f3,24(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 24, temp.u32);
	// lwz r18,116(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f7,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f3,f7,f0,f10
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f0.f64 + ctx.f10.f64));
	// lfs f10,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f7,f3,f0
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// lfs f0,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f7,20(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// stfs f3,0(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f10,4(r18)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f24,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lwz r15,16392(r4)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16392);
	// lfs f7,16396(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16396);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,16388(r4)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16388);
	// lfs f3,16400(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16400);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,16384(r4)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16384);
	// rlwinm r14,r18,2,0,29
	ctx.r14.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// subf r18,r15,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r15.s64;
	// rlwinm r17,r17,2,18,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfsx f22,r17,r4
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r4.u32);
	ctx.f22.f64 = double(temp.f32);
	// lfsx f21,r18,r4
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r4.u32);
	ctx.f21.f64 = double(temp.f32);
	// fmuls f7,f22,f7
	ctx.f7.f64 = double(float(ctx.f22.f64 * ctx.f7.f64));
	// fmuls f3,f21,f3
	ctx.f3.f64 = double(float(ctx.f21.f64 * ctx.f3.f64));
	// stfs f7,16404(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16404, temp.u32);
	// stfs f3,16408(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16408, temp.u32);
	// stfsx f0,r14,r4
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r14.u32 + ctx.r4.u32, temp.u32);
	// lwz r18,16384(r4)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16384);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,124(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// stw r17,16384(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16384, ctx.r17.u32);
	// lfs f3,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f22,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f22.f64 = double(temp.f32);
	// fmuls f7,f22,f7
	ctx.f7.f64 = double(float(ctx.f22.f64 * ctx.f7.f64));
	// stfs f3,4(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f24,0(r18)
	temp.f32 = float(ctx.f24.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f7,16(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 16, temp.u32);
	// lwz r18,132(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lfs f3,8204(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8204);
	ctx.f3.f64 = double(temp.f32);
	// lwz r17,8196(r30)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8196);
	// lfs f7,8208(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8208);
	ctx.f7.f64 = double(temp.f32);
	// lwz r16,8192(r30)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8192);
	// lfs f22,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f22.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f22,f22,f26
	ctx.f22.f64 = double(float(ctx.f22.f64 + ctx.f26.f64));
	// lwz r15,140(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f24,8212(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8212);
	ctx.f24.f64 = double(temp.f32);
	// lwz r14,148(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r11,156(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lfsx f21,r17,r30
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r30.u32);
	ctx.f21.f64 = double(temp.f32);
	// lwz r10,164(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lfs f20,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f20.f64 = double(temp.f32);
	// fmuls f24,f21,f24
	ctx.f24.f64 = double(float(ctx.f21.f64 * ctx.f24.f64));
	// fmadds f3,f21,f3,f22
	ctx.f3.f64 = double(float(ctx.f21.f64 * ctx.f3.f64 + ctx.f22.f64));
	// stfsx f3,r16,r30
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r30.u32, temp.u32);
	// lwz r18,8196(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8196);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// lwz r18,8192(r30)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8192);
	// fmadds f7,f22,f7,f24
	ctx.f7.f64 = double(float(ctx.f22.f64 * ctx.f7.f64 + ctx.f24.f64));
	// stfs f7,8216(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 8216, temp.u32);
	// stw r17,8196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8196, ctx.r17.u32);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// lwz r18,172(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// clrlwi r17,r16,21
	ctx.r17.u64 = ctx.r16.u32 & 0x7FF;
	// stw r17,8192(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8192, ctx.r17.u32);
	// lfs f3,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f3.f64 = double(temp.f32);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lfs f7,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f24,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f24.f64 = double(temp.f32);
	// lwz r14,196(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lfsx f22,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f22.f64 = double(temp.f32);
	// fmadds f3,f22,f3,f20
	ctx.f3.f64 = double(float(ctx.f22.f64 * ctx.f3.f64 + ctx.f20.f64));
	// stfsx f3,r16,r18
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f3,f24,f3,f22
	ctx.f3.f64 = double(float(ctx.f24.f64 * ctx.f3.f64 + ctx.f22.f64));
	// stfs f3,8212(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// addi r16,r17,1
	ctx.r16.s64 = ctx.r17.s64 + 1;
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r16,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r16.u32);
	// stw r17,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r17.u32);
	// lwz r18,180(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lfs f3,4108(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4108);
	ctx.f3.f64 = double(temp.f32);
	// lfs f24,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lwz r16,4096(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f6,f24,f6
	ctx.f6.f64 = double(float(ctx.f24.f64 + ctx.f6.f64));
	// lfsx f24,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmadds f3,f24,f3,f7
	ctx.f3.f64 = double(float(ctx.f24.f64 * ctx.f3.f64 + ctx.f7.f64));
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f22,4112(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4112);
	ctx.f22.f64 = double(temp.f32);
	// lwz r11,204(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// fadds f7,f3,f26
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f26.f64));
	// stfsx f7,r16,r18
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f3,f22,f7,f24
	ctx.f3.f64 = double(float(ctx.f22.f64 * ctx.f7.f64 + ctx.f24.f64));
	// stfs f3,4116(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4116, temp.u32);
	// lwz r16,4096(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,22
	ctx.r17.u64 = ctx.r17.u32 & 0x3FF;
	// clrlwi r16,r16,22
	ctx.r16.u64 = ctx.r16.u32 & 0x3FF;
	// stw r17,4100(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4100, ctx.r17.u32);
	// stw r16,4096(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4096, ctx.r16.u32);
	// lfs f3,16400(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16400);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,16384(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16384);
	// lfs f7,16396(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16396);
	ctx.f7.f64 = double(temp.f32);
	// lwz r17,16388(r3)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16388);
	// lfs f24,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lwz r16,16392(r3)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16392);
	// rlwinm r15,r18,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// subf r18,r16,r18
	ctx.r18.s64 = ctx.r18.s64 - ctx.r16.s64;
	// lwz r16,188(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// rlwinm r17,r17,2,18,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x3FFC;
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// lfsx f21,r17,r3
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r3.u32);
	ctx.f21.f64 = double(temp.f32);
	// lfs f22,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f22.f64 = double(temp.f32);
	// fmuls f7,f21,f7
	ctx.f7.f64 = double(float(ctx.f21.f64 * ctx.f7.f64));
	// lwz r10,212(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// fadds f22,f22,f10
	ctx.f22.f64 = double(float(ctx.f22.f64 + ctx.f10.f64));
	// lwz r7,220(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// lfsx f20,r18,r3
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r3.u32);
	ctx.f20.f64 = double(temp.f32);
	// fmuls f3,f20,f3
	ctx.f3.f64 = double(float(ctx.f20.f64 * ctx.f3.f64));
	// stfs f7,16404(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16404, temp.u32);
	// stfs f3,16408(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16408, temp.u32);
	// stfsx f6,r15,r3
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r3.u32, temp.u32);
	// lwz r15,268(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r18,16384(r3)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16384);
	// addi r17,r18,1
	ctx.r17.s64 = ctx.r18.s64 + 1;
	// lwz r18,228(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// clrlwi r17,r17,20
	ctx.r17.u64 = ctx.r17.u32 & 0xFFF;
	// stw r17,16384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16384, ctx.r17.u32);
	// lfs f7,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f24
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f24.f64));
	// lwz r17,8(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f20,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f20.f64 = double(temp.f32);
	// lfs f3,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f3.f64 = double(temp.f32);
	// lfs f7,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f20,f3,f6
	ctx.f6.f64 = double(float(ctx.f20.f64 * ctx.f3.f64 + ctx.f6.f64));
	// lfs f21,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f21.f64 = double(temp.f32);
	// lwz r14,280(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// stfs f6,20(r18)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// stfs f7,4(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// stfs f24,0(r18)
	temp.f32 = float(ctx.f24.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// lfs f20,8212(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8212);
	ctx.f20.f64 = double(temp.f32);
	// lfs f3,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lwz r18,8196(r28)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8196);
	// lfs f6,8204(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8204);
	ctx.f6.f64 = double(temp.f32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f7,f3,f2
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f2.f64));
	// lwz r17,8192(r28)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8192);
	// lfsx f19,r18,r28
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r28.u32);
	ctx.f19.f64 = double(temp.f32);
	// lfs f3,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f24,8208(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8208);
	ctx.f24.f64 = double(temp.f32);
	// fmadds f6,f6,f19,f7
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f19.f64 + ctx.f7.f64));
	// stfsx f6,r17,r28
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r28.u32, temp.u32);
	// fmuls f6,f19,f20
	ctx.f6.f64 = double(float(ctx.f19.f64 * ctx.f20.f64));
	// lwz r17,8192(r28)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8192);
	// lwz r18,8196(r28)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8196);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// lwz r18,236(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// stw r17,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r17.u32);
	// stw r16,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r16.u32);
	// fmadds f7,f7,f24,f6
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f24.f64 + ctx.f6.f64));
	// stfs f7,8216(r28)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// lfs f24,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f24.f64 = double(temp.f32);
	// lfs f6,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f6.f64 = double(temp.f32);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f20,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f20.f64 = double(temp.f32);
	// lfs f7,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f20,f6,f3
	ctx.f6.f64 = double(float(ctx.f20.f64 * ctx.f6.f64 + ctx.f3.f64));
	// stfsx f6,r16,r18
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f3,f6,f24,f20
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f24.f64 + ctx.f20.f64));
	// stfs f3,8212(r18)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// fadds f3,f0,f25
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f25.f64));
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// addi r16,r17,1
	ctx.r16.s64 = ctx.r17.s64 + 1;
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// stw r16,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r16.u32);
	// stw r17,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r17.u32);
	// lwz r18,244(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// lwz r17,252(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// lwz r16,260(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// lwz r11,4100(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// lfs f24,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// rlwinm r17,r11,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f27,f24,f27
	ctx.f27.f64 = double(float(ctx.f24.f64 + ctx.f27.f64));
	// lfs f6,4108(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4108);
	ctx.f6.f64 = double(temp.f32);
	// lwz r10,4096(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// lfs f20,4112(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 4112);
	ctx.f20.f64 = double(temp.f32);
	// ld r29,272(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + 272);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f24,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmadds f7,f24,f6,f7
	ctx.f7.f64 = double(float(ctx.f24.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fadds f6,f7,f2
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f2.f64));
	// stfsx f6,r11,r18
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r18.u32, temp.u32);
	// fmadds f7,f6,f20,f24
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f20.f64 + ctx.f24.f64));
	// stfs f7,4116(r18)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4116, temp.u32);
	// lwz r17,4100(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4100);
	// addi r11,r17,1
	ctx.r11.s64 = ctx.r17.s64 + 1;
	// lwz r17,4096(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 4096);
	// addi r10,r17,1
	ctx.r10.s64 = ctx.r17.s64 + 1;
	// lwz r17,796(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 796);
	// clrlwi r11,r11,22
	ctx.r11.u64 = ctx.r11.u32 & 0x3FF;
	// clrlwi r10,r10,22
	ctx.r10.u64 = ctx.r10.u32 & 0x3FF;
	// stw r11,4100(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4100, ctx.r11.u32);
	// stw r10,4096(r18)
	PPC_STORE_U32(ctx.r18.u32 + 4096, ctx.r10.u32);
	// lwz r18,288(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// lfs f7,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfsu f6,4(r17)
	ea = 4 + ctx.r17.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f6.f64 = double(temp.f32);
	ctx.r17.u32 = ea;
	// lfs f18,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f18.f64 = double(temp.f32);
	// lfs f24,0(r16)
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// lwz r16,8(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lfs f20,12(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	ctx.f20.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmuls f20,f20,f24
	ctx.f20.f64 = double(float(ctx.f20.f64 * ctx.f24.f64));
	// lfs f19,16(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	ctx.f19.f64 = double(temp.f32);
	// fadds f16,f18,f21
	ctx.f16.f64 = double(float(ctx.f18.f64 + ctx.f21.f64));
	// lfs f17,0(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	ctx.f17.f64 = double(temp.f32);
	// fsubs f21,f18,f21
	ctx.f21.f64 = double(float(ctx.f18.f64 - ctx.f21.f64));
	// lfsx f18,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f18.f64 = double(temp.f32);
	// stfs f24,0(r18)
	temp.f32 = float(ctx.f24.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// stfs f17,4(r18)
	temp.f32 = float(ctx.f17.f64);
	PPC_STORE_U32(ctx.r18.u32 + 4, temp.u32);
	// fmadds f20,f18,f19,f20
	ctx.f20.f64 = double(float(ctx.f18.f64 * ctx.f19.f64 + ctx.f20.f64));
	// stfs f20,20(r18)
	temp.f32 = float(ctx.f20.f64);
	PPC_STORE_U32(ctx.r18.u32 + 20, temp.u32);
	// lwz r16,16384(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16384);
	// lwz r18,16392(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16392);
	// lfs f24,16400(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16400);
	ctx.f24.f64 = double(temp.f32);
	// lwz r15,16388(r29)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16388);
	// lfs f20,16396(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 16396);
	ctx.f20.f64 = double(temp.f32);
	// subf r18,r18,r16
	ctx.r18.s64 = ctx.r16.s64 - ctx.r18.s64;
	// lfs f19,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f19.f64 = double(temp.f32);
	// subf r15,r15,r16
	ctx.r15.s64 = ctx.r16.s64 - ctx.r15.s64;
	// fadds f19,f19,f11
	ctx.f19.f64 = double(float(ctx.f19.f64 + ctx.f11.f64));
	// rlwinm r18,r18,2,18,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0x3FFC;
	// rlwinm r15,r15,2,18,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x3FFC;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f18,r18,r29
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + ctx.r29.u32);
	ctx.f18.f64 = double(temp.f32);
	// lfsx f17,r15,r29
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r29.u32);
	ctx.f17.f64 = double(temp.f32);
	// fmuls f24,f18,f24
	ctx.f24.f64 = double(float(ctx.f18.f64 * ctx.f24.f64));
	// fmuls f20,f17,f20
	ctx.f20.f64 = double(float(ctx.f17.f64 * ctx.f20.f64));
	// stfs f20,16404(r29)
	temp.f32 = float(ctx.f20.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16404, temp.u32);
	// stfs f24,16408(r29)
	temp.f32 = float(ctx.f24.f64);
	PPC_STORE_U32(ctx.r29.u32 + 16408, temp.u32);
	// stfsx f27,r16,r29
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r29.u32, temp.u32);
	// lwz r18,16384(r29)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16384);
	// addi r16,r18,1
	ctx.r16.s64 = ctx.r18.s64 + 1;
	// lwz r18,296(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// clrlwi r16,r16,20
	ctx.r16.u64 = ctx.r16.u32 & 0xFFF;
	// stw r16,16384(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16384, ctx.r16.u32);
	// lwz r15,2048(r18)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfs f27,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f27.f64 = double(temp.f32);
	// lwz r16,2052(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f24,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f24.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f20,r16,r18
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r18.u32);
	ctx.f20.f64 = double(temp.f32);
	// fmadds f27,f20,f27,f16
	ctx.f27.f64 = double(float(ctx.f20.f64 * ctx.f27.f64 + ctx.f16.f64));
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f4,f27,f4
	ctx.f4.f64 = double(float(ctx.f27.f64 + ctx.f4.f64));
	// stfsx f4,r15,r18
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r18.u32, temp.u32);
	// addi r15,r17,4
	ctx.r15.s64 = ctx.r17.s64 + 4;
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// fmadds f27,f4,f24,f20
	ctx.f27.f64 = double(float(ctx.f4.f64 * ctx.f24.f64 + ctx.f20.f64));
	// stfs f27,2068(r18)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// fsubs f0,f0,f25
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f25.f64));
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// ld r27,464(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + 464);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// fadds f9,f19,f9
	ctx.f9.f64 = double(float(ctx.f19.f64 + ctx.f9.f64));
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// fadds f8,f22,f8
	ctx.f8.f64 = double(float(ctx.f22.f64 + ctx.f8.f64));
	// stw r15,796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 796, ctx.r15.u32);
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// lwz r18,304(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f27,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f27.f64 = double(temp.f32);
	// fmuls f9,f9,f5
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f5.f64));
	// lfsx f4,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f4.f64 = double(temp.f32);
	// lwz r17,2048(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfs f25,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f25.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f27,f4,f27,f21
	ctx.f27.f64 = double(float(ctx.f4.f64 * ctx.f27.f64 + ctx.f21.f64));
	// fmuls f8,f8,f5
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// fadds f27,f27,f23
	ctx.f27.f64 = double(float(ctx.f27.f64 + ctx.f23.f64));
	// stfsx f27,r17,r18
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r17.u32 + ctx.r18.u32, temp.u32);
	// fmadds f4,f27,f25,f4
	ctx.f4.f64 = double(float(ctx.f27.f64 * ctx.f25.f64 + ctx.f4.f64));
	// stfs f4,2068(r18)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// lwz r18,312(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lfs f4,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f4.f64 = double(temp.f32);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// lfs f27,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f27.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f25,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f25.f64 = double(temp.f32);
	// fmadds f3,f4,f25,f3
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f25.f64 + ctx.f3.f64));
	// fadds f2,f3,f2
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f2.f64));
	// stfsx f2,r16,r18
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f4,f2,f27,f25
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f27.f64 + ctx.f25.f64));
	// stfs f4,8212(r18)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r16,8196(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// lwz r17,8192(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// stw r17,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r17.u32);
	// stw r16,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r16.u32);
	// lwz r18,320(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f3,8204(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8204);
	ctx.f3.f64 = double(temp.f32);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// lfsx f4,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f4,f3,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f3.f64 + ctx.f0.f64));
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f2,8208(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 8208);
	ctx.f2.f64 = double(temp.f32);
	// fadds f0,f3,f26
	ctx.f0.f64 = double(float(ctx.f3.f64 + ctx.f26.f64));
	// stfsx f0,r16,r18
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f4,f2,f0,f4
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f0.f64 + ctx.f4.f64));
	// stfs f4,8212(r18)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r18.u32 + 8212, temp.u32);
	// lwz r16,8192(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8192);
	// lwz r17,8196(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8196);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,21
	ctx.r17.u64 = ctx.r17.u32 & 0x7FF;
	// clrlwi r16,r16,21
	ctx.r16.u64 = ctx.r16.u32 & 0x7FF;
	// stw r17,8196(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8196, ctx.r17.u32);
	// stw r16,8192(r18)
	PPC_STORE_U32(ctx.r18.u32 + 8192, ctx.r16.u32);
	// lwz r16,2052(r27)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2052);
	// lwz r18,2048(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2048);
	// lfs f0,2068(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 2068);
	ctx.f0.f64 = double(temp.f32);
	// lwz r17,2056(r27)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2056);
	// subf r17,r17,r18
	ctx.r17.s64 = ctx.r18.s64 - ctx.r17.s64;
	// addi r15,r17,-1
	ctx.r15.s64 = ctx.r17.s64 + -1;
	// rlwinm r17,r17,2,21,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0x7FC;
	// fsubs f2,f1,f0
	ctx.f2.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// rlwinm r15,r15,2,21,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0x7FC;
	// fadds f25,f8,f9
	ctx.f25.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// subf r16,r16,r18
	ctx.r16.s64 = ctx.r18.s64 - ctx.r16.s64;
	// lwz r11,336(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	// lwz r14,328(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// addi r10,r16,-1
	ctx.r10.s64 = ctx.r16.s64 + -1;
	// ld r7,448(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 448);
	// lfsx f4,r17,r27
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r27.u32);
	ctx.f4.f64 = double(temp.f32);
	// rlwinm r17,r16,2,21,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0x7FC;
	// lfsx f3,r15,r27
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r27.u32);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f27,f4,f0
	ctx.f27.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f26,f3,f0
	ctx.f26.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// rlwinm r16,r10,2,21,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x7FC;
	// lfs f3,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// ld r11,480(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 480);
	// lfs f4,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// ld r10,472(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 472);
	// lfsx f24,r17,r27
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r27.u32);
	ctx.f24.f64 = double(temp.f32);
	// fmuls f4,f4,f5
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f5.f64));
	// fmuls f3,f3,f5
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f5.f64));
	// lfsx f23,r16,r27
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r27.u32);
	ctx.f23.f64 = double(temp.f32);
	// fmadds f27,f24,f2,f27
	ctx.f27.f64 = double(float(ctx.f24.f64 * ctx.f2.f64 + ctx.f27.f64));
	// stfs f27,2072(r27)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r27.u32 + 2072, temp.u32);
	// fmadds f2,f23,f2,f26
	ctx.f2.f64 = double(float(ctx.f23.f64 * ctx.f2.f64 + ctx.f26.f64));
	// stfs f2,2076(r27)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r27.u32 + 2076, temp.u32);
	// fmuls f2,f25,f31
	ctx.f2.f64 = double(float(ctx.f25.f64 * ctx.f31.f64));
	// ble cr6,0x821349b0
	if (!ctx.cr6.gt) goto loc_821349B0;
	// fsubs f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f28.f64));
	// b 0x821349d4
	goto loc_821349D4;
loc_821349B0:
	// lwz r17,2060(r27)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2060);
	// lwz r16,2052(r27)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2052);
	// cmplw cr6,r17,r16
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, ctx.r16.u32, ctx.xer);
	// beq cr6,0x821349c8
	if (ctx.cr6.eq) goto loc_821349C8;
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
	// b 0x821349cc
	goto loc_821349CC;
loc_821349C8:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f12.f64;
loc_821349CC:
	// stw r16,2056(r27)
	PPC_STORE_U32(ctx.r27.u32 + 2056, ctx.r16.u32);
	// stw r17,2052(r27)
	PPC_STORE_U32(ctx.r27.u32 + 2052, ctx.r17.u32);
loc_821349D4:
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// stfs f0,2068(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r27.u32 + 2068, temp.u32);
	// lwz r17,344(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	// std r11,448(r1)
	PPC_STORE_U64(ctx.r1.u32 + 448, ctx.r11.u64);
	// lwz r15,352(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// lwz r14,360(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	// stfsx f11,r18,r27
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r27.u32, temp.u32);
	// lwz r18,2048(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// stw r18,2048(r27)
	PPC_STORE_U32(ctx.r27.u32 + 2048, ctx.r18.u32);
	// rlwinm r18,r18,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f10,r18,r27
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r18.u32 + ctx.r27.u32, temp.u32);
	// lwz r18,2048(r27)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r27.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// clrlwi r16,r18,23
	ctx.r16.u64 = ctx.r18.u32 & 0x1FF;
	// lwz r18,368(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// stw r16,2048(r27)
	PPC_STORE_U32(ctx.r27.u32 + 2048, ctx.r16.u32);
	// lwz r16,2052(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f11,0(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,2048(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfs f0,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r17,r16,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f10,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r16,r11,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f27,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f9,f27,f0,f9
	ctx.f9.f64 = double(float(ctx.f27.f64 * ctx.f0.f64 + ctx.f9.f64));
	// stfsx f9,r16,r18
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f0,f9,f10,f27
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f27.f64));
	// stfs f0,2068(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r17.u32);
	// stw r16,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r16.u32);
	// lwz r18,376(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	// lfs f10,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f10.f64 = double(temp.f32);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f9,0(r15)
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f27,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f11,f27,f10,f11
	ctx.f11.f64 = double(float(ctx.f27.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfsx f11,r16,r18
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f10,f11,f0,f27
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64 + ctx.f27.f64));
	// stfs f10,2068(r18)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r16,2052(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lwz r17,2048(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r17,r17,23
	ctx.r17.u64 = ctx.r17.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r17,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r17.u32);
	// stw r16,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r16.u32);
	// lwz r18,384(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 384);
	// lwz r17,2052(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lfs f0,2060(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2060);
	ctx.f0.f64 = double(temp.f32);
	// lwz r16,2048(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// lfs f11,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r17,r17,2,0,29
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f10,2064(r18)
	temp.u32 = PPC_LOAD_U32(ctx.r18.u32 + 2064);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f27,r17,r18
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + ctx.r18.u32);
	ctx.f27.f64 = double(temp.f32);
	// fmadds f8,f27,f0,f8
	ctx.f8.f64 = double(float(ctx.f27.f64 * ctx.f0.f64 + ctx.f8.f64));
	// stfsx f8,r16,r18
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r18.u32, temp.u32);
	// fmadds f0,f8,f10,f27
	ctx.f0.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + ctx.f27.f64));
	// stfs f0,2068(r18)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r18.u32 + 2068, temp.u32);
	// lwz r16,2052(r18)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2052);
	// lwz r17,2048(r18)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r18.u32 + 2048);
	// addi r15,r17,1
	ctx.r15.s64 = ctx.r17.s64 + 1;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// lwz r17,392(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 392);
	// clrlwi r15,r15,23
	ctx.r15.u64 = ctx.r15.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r15,2048(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2048, ctx.r15.u32);
	// stw r16,2052(r18)
	PPC_STORE_U32(ctx.r18.u32 + 2052, ctx.r16.u32);
	// lwz r18,2052(r17)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2052);
	// lfs f10,2060(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 2060);
	ctx.f10.f64 = double(temp.f32);
	// lwz r16,2048(r17)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2048);
	// lfs f8,2064(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 2064);
	ctx.f8.f64 = double(temp.f32);
	// rlwinm r15,r18,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r14,400(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f0,f1,f13
	ctx.f0.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fmuls f9,f9,f13
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// lwz r18,416(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	// fadds f27,f6,f7
	ctx.f27.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// lwz r11,408(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	// fmuls f4,f4,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfsx f26,r15,r17
	temp.u32 = PPC_LOAD_U32(ctx.r15.u32 + ctx.r17.u32);
	ctx.f26.f64 = double(temp.f32);
	// fmuls f3,f3,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// lfs f25,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// fmadds f11,f26,f10,f11
	ctx.f11.f64 = double(float(ctx.f26.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfsx f11,r16,r17
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r16.u32 + ctx.r17.u32, temp.u32);
	// fmuls f10,f25,f13
	ctx.f10.f64 = double(float(ctx.f25.f64 * ctx.f13.f64));
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// fcmpu cr6,f29,f12
	ctx.cr6.compare(ctx.f29.f64, ctx.f12.f64);
	// lwz r18,804(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 804);
	// fmadds f9,f0,f7,f9
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f7.f64 + ctx.f9.f64));
	// fmuls f27,f27,f0
	ctx.f27.f64 = double(float(ctx.f27.f64 * ctx.f0.f64));
	// stfs f9,0(r18)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r18.u32 + 0, temp.u32);
	// fmadds f8,f11,f8,f26
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 + ctx.f26.f64));
	// stfs f8,2068(r17)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r17.u32 + 2068, temp.u32);
	// fmadds f7,f0,f6,f10
	ctx.f7.f64 = double(float(ctx.f0.f64 * ctx.f6.f64 + ctx.f10.f64));
	// stfsu f7,4(r18)
	temp.f32 = float(ctx.f7.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// lwz r16,2052(r17)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2052);
	// lwz r15,2048(r17)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2048);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// lwz r14,80(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// clrlwi r15,r15,23
	ctx.r15.u64 = ctx.r15.u32 & 0x1FF;
	// stw r16,2052(r17)
	PPC_STORE_U32(ctx.r17.u32 + 2052, ctx.r16.u32);
	// stw r15,2048(r17)
	PPC_STORE_U32(ctx.r17.u32 + 2048, ctx.r15.u32);
	// lwz r17,424(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 424);
	// lwz r16,2052(r17)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2052);
	// lfs f6,2060(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 2060);
	ctx.f6.f64 = double(temp.f32);
	// lwz r15,2048(r17)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2048);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,2064(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 2064);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r16,r17
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r17.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f6,f2
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f2.f64));
	// stfsx f9,r15,r17
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r17.u32, temp.u32);
	// fmadds f8,f9,f11,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f10.f64));
	// stfs f8,2068(r17)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r17.u32 + 2068, temp.u32);
	// lwz r16,2052(r17)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2052);
	// lwz r15,2048(r17)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2048);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r15,r15,1
	ctx.r15.s64 = ctx.r15.s64 + 1;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// clrlwi r15,r15,23
	ctx.r15.u64 = ctx.r15.u32 & 0x1FF;
	// stw r16,2052(r17)
	PPC_STORE_U32(ctx.r17.u32 + 2052, ctx.r16.u32);
	// stw r15,2048(r17)
	PPC_STORE_U32(ctx.r17.u32 + 2048, ctx.r15.u32);
	// lwz r17,432(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 432);
	// lfs f6,0(r14)
	temp.u32 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f11,f6,f13
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// lwz r16,2052(r17)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2052);
	// lfs f7,2060(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 2060);
	ctx.f7.f64 = double(temp.f32);
	// lwz r15,2048(r17)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2048);
	// lfs f2,2064(r17)
	temp.u32 = PPC_LOAD_U32(ctx.r17.u32 + 2064);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r16,r16,2,0,29
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u32 | (ctx.r16.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f8,f27,f31,f11
	ctx.f8.f64 = double(float(ctx.f27.f64 * ctx.f31.f64 + ctx.f11.f64));
	// rlwinm r15,r15,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsu f8,4(r18)
	temp.f32 = float(ctx.f8.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// stfsu f12,4(r18)
	temp.f32 = float(ctx.f12.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// stfsu f4,4(r18)
	temp.f32 = float(ctx.f4.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// stfsu f3,4(r18)
	temp.f32 = float(ctx.f3.f64);
	ea = 4 + ctx.r18.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r18.u32 = ea;
	// lfsx f10,r16,r17
	temp.u32 = PPC_LOAD_U32(ctx.r16.u32 + ctx.r17.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f7,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f7.f64 + ctx.f0.f64));
	// stfsx f9,r15,r17
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r15.u32 + ctx.r17.u32, temp.u32);
	// addi r18,r18,4
	ctx.r18.s64 = ctx.r18.s64 + 4;
	// stw r18,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r18.u32);
	// fmadds f7,f9,f2,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f2.f64 + ctx.f10.f64));
	// stfs f7,2068(r17)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r17.u32 + 2068, temp.u32);
	// lwz r18,2052(r17)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2052);
	// lwz r16,2048(r17)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r17.u32 + 2048);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// ld r11,448(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 448);
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// clrlwi r18,r18,23
	ctx.r18.u64 = ctx.r18.u32 & 0x1FF;
	// clrlwi r16,r16,23
	ctx.r16.u64 = ctx.r16.u32 & 0x1FF;
	// stw r18,2052(r17)
	PPC_STORE_U32(ctx.r17.u32 + 2052, ctx.r18.u32);
	// stw r16,2048(r17)
	PPC_STORE_U32(ctx.r17.u32 + 2048, ctx.r16.u32);
	// ble cr6,0x82134c90
	if (!ctx.cr6.gt) goto loc_82134C90;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82134c90
	if (!ctx.cr6.lt) goto loc_82134C90;
	// fadds f13,f13,f29
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f29.f64));
loc_82134C90:
	// fcmpu cr6,f29,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f29.f64, ctx.f12.f64);
	// bge cr6,0x82134ca4
	if (!ctx.cr6.lt) goto loc_82134CA4;
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x82134ca4
	if (!ctx.cr6.gt) goto loc_82134CA4;
	// fadds f13,f13,f29
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f29.f64));
loc_82134CA4:
	// lwz r18,88(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r18,r18,8
	ctx.r18.s64 = ctx.r18.s64 + 8;
	// stw r18,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r18.u32);
	// bdnz 0x82133b44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82133B44;
loc_82134CB4:
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080384
	ctx.lr = 0x82134CC0;
	__restfpr_16(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82134CC4"))) PPC_WEAK_FUNC(sub_82134CC4);
PPC_FUNC_IMPL(__imp__sub_82134CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82134CC8"))) PPC_WEAK_FUNC(sub_82134CC8);
PPC_FUNC_IMPL(__imp__sub_82134CC8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x82134cd4
	if (!ctx.cr6.eq) goto loc_82134CD4;
	// b 0x82130948
	sub_82130948(ctx, base);
	return;
loc_82134CD4:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x82134ce0
	if (!ctx.cr6.eq) goto loc_82134CE0;
	// b 0x82130ea8
	sub_82130EA8(ctx, base);
	return;
loc_82134CE0:
	// b 0x82131088
	sub_82131088(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82134CE4"))) PPC_WEAK_FUNC(sub_82134CE4);
PPC_FUNC_IMPL(__imp__sub_82134CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82134CE8"))) PPC_WEAK_FUNC(sub_82134CE8);
PPC_FUNC_IMPL(__imp__sub_82134CE8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82134d08
	if (!ctx.cr6.eq) goto loc_82134D08;
	// b 0x82131140
	sub_82131140(ctx, base);
	return;
loc_82134D08:
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82134d14
	if (!ctx.cr6.eq) goto loc_82134D14;
	// b 0x821320f0
	sub_821320F0(ctx, base);
	return;
loc_82134D14:
	// b 0x821335b8
	sub_821335B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82134D18"))) PPC_WEAK_FUNC(sub_82134D18);
PPC_FUNC_IMPL(__imp__sub_82134D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82134D20;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8208035c
	ctx.lr = 0x82134D28;
	__savefpr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f28,14004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 14004);
	ctx.f28.f64 = double(temp.f32);
	// stfs f28,0(r3)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfd f27,2432(r10)
	ctx.f27.u64 = PPC_LOAD_U64(ctx.r10.u32 + 2432);
	// lfd f26,19584(r9)
	ctx.f26.u64 = PPC_LOAD_U64(ctx.r9.u32 + 19584);
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// bl 0x8207b7a8
	ctx.lr = 0x82134D58;
	sub_8207B7A8(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// li r4,40
	ctx.r4.s64 = 40;
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f30,-19112(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -19112);
	ctx.f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x821307d8
	ctx.lr = 0x82134D78;
	sub_821307D8(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// lfs f0,-19116(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,9388(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// stfs f30,0(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f31,8(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f31,12(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f31,16(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f31,20(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f31,24(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f31,28(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// bl 0x8212e008
	ctx.lr = 0x82134DB4;
	sub_8212E008(ctx, base);
	// lis r28,-32254
	ctx.r28.s64 = -2113798144;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// addis r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 65536;
	// addi r27,r28,-22496
	ctx.r27.s64 = ctx.r28.s64 + -22496;
	// ori r11,r5,68
	ctx.r11.u64 = ctx.r5.u64 | 68;
	// ori r10,r4,72
	ctx.r10.u64 = ctx.r4.u64 | 72;
	// addi r26,r26,76
	ctx.r26.s64 = ctx.r26.s64 + 76;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,44(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lfs f13,48(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stfsx f13,r31,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82134DF4;
	sub_8207DA20(ctx, base);
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f13,8(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r25,r25,2164
	ctx.r25.s64 = ctx.r25.s64 + 2164;
	// stfs f0,2068(r26)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2068, temp.u32);
	// li r8,509
	ctx.r8.s64 = 509;
	// lfs f30,-22496(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -22496);
	ctx.f30.f64 = double(temp.f32);
	// li r7,508
	ctx.r7.s64 = 508;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stfs f30,2064(r26)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2064, temp.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// lfs f0,-19120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19120);
	ctx.f0.f64 = double(temp.f32);
	// li r6,83
	ctx.r6.s64 = 83;
	// stfs f13,2072(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2072, temp.u32);
	// li r5,512
	ctx.r5.s64 = 512;
	// stfs f31,2076(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2076, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,2080(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2080, temp.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f31,2084(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2084, temp.u32);
	// stw r30,2048(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2048, ctx.r30.u32);
	// stw r8,2052(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2052, ctx.r8.u32);
	// stw r7,2056(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2056, ctx.r7.u32);
	// stw r29,2060(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2060, ctx.r29.u32);
	// stfs f12,524(r25)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r25.u32 + 524, temp.u32);
	// stfs f0,528(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 528, temp.u32);
	// stw r6,520(r25)
	PPC_STORE_U32(ctx.r25.u32 + 520, ctx.r6.u32);
	// bl 0x8207da20
	ctx.lr = 0x82134E6C;
	sub_8207DA20(ctx, base);
	// stfs f31,532(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 532, temp.u32);
	// lwz r5,520(r25)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r25.u32 + 520);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stw r30,512(r25)
	PPC_STORE_U32(ctx.r25.u32 + 512, ctx.r30.u32);
	// neg r4,r5
	ctx.r4.s64 = -ctx.r5.s64;
	// addi r28,r28,2700
	ctx.r28.s64 = ctx.r28.s64 + 2700;
	// clrlwi r3,r4,25
	ctx.r3.u64 = ctx.r4.u32 & 0x7F;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// stw r3,516(r25)
	PPC_STORE_U32(ctx.r25.u32 + 516, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82134E9C;
	sub_8207DA20(ctx, base);
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,20(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stfs f0,8212(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8212, temp.u32);
	// lis r26,-32256
	ctx.r26.s64 = -2113929216;
	// stfs f30,8208(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8208, temp.u32);
	// addi r25,r25,10932
	ctx.r25.s64 = ctx.r25.s64 + 10932;
	// stfs f31,8220(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8220, temp.u32);
	// li r9,2039
	ctx.r9.s64 = 2039;
	// stfs f31,8224(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8224, temp.u32);
	// li r8,2038
	ctx.r8.s64 = 2038;
	// lfs f0,23060(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 23060);
	ctx.f0.f64 = double(temp.f32);
	// li r7,600
	ctx.r7.s64 = 600;
	// lfs f29,-20796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20796);
	ctx.f29.f64 = double(temp.f32);
	// li r6,211
	ctx.r6.s64 = 211;
	// lfs f25,12868(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 12868);
	ctx.f25.f64 = double(temp.f32);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// stfs f0,8216(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,8228(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8228, temp.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// stw r9,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r9.u32);
	// stw r8,8200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8200, ctx.r8.u32);
	// stw r7,8204(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8204, ctx.r7.u32);
	// stfs f25,1036(r25)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r25.u32 + 1036, temp.u32);
	// stfs f29,1040(r25)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r25.u32 + 1040, temp.u32);
	// stw r6,1032(r25)
	PPC_STORE_U32(ctx.r25.u32 + 1032, ctx.r6.u32);
	// bl 0x8207da20
	ctx.lr = 0x82134F14;
	sub_8207DA20(ctx, base);
	// lwz r11,1032(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 1032);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stfs f31,1044(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 1044, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r30,1024(r25)
	PPC_STORE_U32(ctx.r25.u32 + 1024, ctx.r30.u32);
	// addi r28,r28,11980
	ctx.r28.s64 = ctx.r28.s64 + 11980;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// li r3,311
	ctx.r3.s64 = 311;
	// stw r9,1028(r25)
	PPC_STORE_U32(ctx.r25.u32 + 1028, ctx.r9.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,2056(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2056, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f25,2060(r28)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2060, temp.u32);
	// stfs f29,2064(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82134F54;
	sub_8207DA20(ctx, base);
	// lwz r7,2056(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// li r8,1020
	ctx.r8.s64 = 1020;
	// lfs f0,36(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// lfs f13,40(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// addi r25,r25,14052
	ctx.r25.s64 = ctx.r25.s64 + 14052;
	// stfs f31,2068(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// clrlwi r11,r6,23
	ctx.r11.u64 = ctx.r6.u32 & 0x1FF;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r11.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f0,4108(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4108, temp.u32);
	// stw r8,4100(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4100, ctx.r8.u32);
	// stfs f13,4112(r25)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4112, temp.u32);
	// stw r29,4104(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4104, ctx.r29.u32);
	// bl 0x8207da20
	ctx.lr = 0x82134FA0;
	sub_8207DA20(ctx, base);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lfs f0,76(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 76);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stfs f31,4116(r25)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4116, temp.u32);
	// addi r28,r28,18176
	ctx.r28.s64 = ctx.r28.s64 + 18176;
	// li r9,409
	ctx.r9.s64 = 409;
	// lfs f30,-19124(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19124);
	ctx.f30.f64 = double(temp.f32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stfs f31,4120(r25)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4120, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,4096(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4096, ctx.r30.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f0,2060(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2060, temp.u32);
	// stfs f30,2064(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2064, temp.u32);
	// stw r9,2056(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2056, ctx.r9.u32);
	// bl 0x8207da20
	ctx.lr = 0x82134FE0;
	sub_8207DA20(ctx, base);
	// lwz r7,2056(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 65536;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// addi r25,r25,20248
	ctx.r25.s64 = ctx.r25.s64 + 20248;
	// clrlwi r3,r6,23
	ctx.r3.u64 = ctx.r6.u32 & 0x1FF;
	// li r8,257
	ctx.r8.s64 = 257;
	// stw r3,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r3.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f25,2060(r25)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2060, temp.u32);
	// stfs f29,2064(r25)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2064, temp.u32);
	// stw r8,2056(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2056, ctx.r8.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135020;
	sub_8207DA20(ctx, base);
	// lwz r8,2056(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2056);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// stfs f31,2068(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2068, temp.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stw r30,2048(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2048, ctx.r30.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// lfs f0,52(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// lfs f13,56(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,22320
	ctx.r11.s64 = ctx.r11.s64 + 22320;
	// lfs f12,60(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,22340
	ctx.r10.s64 = ctx.r10.s64 + 22340;
	// lfs f11,64(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r9,22368
	ctx.r9.s64 = ctx.r9.s64 + 22368;
	// lfs f10,68(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// lfs f9,72(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// stw r6,2052(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2052, ctx.r6.u32);
	// stfs f0,12(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f31,0(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stfs f31,4(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// stfs f31,16(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stw r29,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r29.u32);
	// stfs f31,0(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,4(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f13,12(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// stfs f12,16(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// stfs f11,20(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// stfs f31,24(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// stw r29,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r29.u32);
	// stfs f31,0(r9)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// stfs f31,4(r9)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// stfs f10,12(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// stfs f9,16(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// stfs f31,20(r9)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
	// bl 0x8207b7a8
	ctx.lr = 0x821350BC;
	sub_8207B7A8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lfs f0,84(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r11,3432
	ctx.r11.s64 = 3432;
	// addi r28,r28,22392
	ctx.r28.s64 = ctx.r28.s64 + 22392;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f28,16396(r28)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16396, temp.u32);
	// stw r11,16388(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16388, ctx.r11.u32);
	// stw r11,16392(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16392, ctx.r11.u32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,16400(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16400, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821350F4;
	sub_8207DA20(ctx, base);
	// addis r25,r31,2
	ctx.r25.s64 = ctx.r31.s64 + 131072;
	// addis r11,r31,2
	ctx.r11.s64 = ctx.r31.s64 + 131072;
	// stfs f31,16404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16404, temp.u32);
	// addi r25,r25,-26712
	ctx.r25.s64 = ctx.r25.s64 + -26712;
	// stfs f31,16408(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16408, temp.u32);
	// addi r11,r11,-26732
	ctx.r11.s64 = ctx.r11.s64 + -26732;
	// stw r30,16384(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16384, ctx.r30.u32);
	// li r10,383
	ctx.r10.s64 = 383;
	// lfs f0,20(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// lfs f13,76(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f31,0(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stfs f31,4(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f31,16(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stw r10,2056(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2056, ctx.r10.u32);
	// stfs f13,2060(r25)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2060, temp.u32);
	// stfs f30,2064(r25)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x8213514C;
	sub_8207DA20(ctx, base);
	// lwz r8,2056(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 2056);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// li r9,233
	ctx.r9.s64 = 233;
	// stfs f31,2068(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 2068, temp.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// stw r30,2048(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2048, ctx.r30.u32);
	// addi r28,r28,-24640
	ctx.r28.s64 = ctx.r28.s64 + -24640;
	// fmr f0,f25
	ctx.f0.f64 = ctx.f25.f64;
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,2052(r25)
	PPC_STORE_U32(ctx.r25.u32 + 2052, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f25,2060(r28)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2060, temp.u32);
	// stw r9,2056(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2056, ctx.r9.u32);
	// stfs f29,2064(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135190;
	sub_8207DA20(ctx, base);
	// lwz r11,2056(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r5,r31,2
	ctx.r5.s64 = ctx.r31.s64 + 131072;
	// addis r4,r31,2
	ctx.r4.s64 = ctx.r31.s64 + 131072;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r30,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r30.u32);
	// addi r5,r5,-22568
	ctx.r5.s64 = ctx.r5.s64 + -22568;
	// lfs f0,52(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// addis r3,r31,2
	ctx.r3.s64 = ctx.r31.s64 + 131072;
	// lfs f13,60(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r4,-22548
	ctx.r4.s64 = ctx.r4.s64 + -22548;
	// lfs f12,64(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// addi r3,r3,-22520
	ctx.r3.s64 = ctx.r3.s64 + -22520;
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// stw r9,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r9.u32);
	// stfs f0,12(r5)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// stfs f31,0(r5)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stw r29,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r29.u32);
	// stfs f31,4(r5)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// stfs f31,16(r5)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r5.u32 + 16, temp.u32);
	// stw r29,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r29.u32);
	// lfs f0,56(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12(r4)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f13,16(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// stfs f31,0(r4)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f31,4(r4)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f12,20(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 20, temp.u32);
	// stfs f31,24(r4)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 24, temp.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// lfs f0,68(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,72(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,0(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f31,4(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f31,20(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// bl 0x8207b7a8
	ctx.lr = 0x8213522C;
	sub_8207B7A8(ctx, base);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// lfs f0,84(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// addi r28,r28,-22496
	ctx.r28.s64 = ctx.r28.s64 + -22496;
	// li r11,3820
	ctx.r11.s64 = 3820;
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// li r5,16384
	ctx.r5.s64 = 16384;
	// stfs f28,16396(r28)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16396, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f10,16400(r28)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16400, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,16388(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16388, ctx.r11.u32);
	// stw r11,16392(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16392, ctx.r11.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135264;
	sub_8207DA20(ctx, base);
	// addis r8,r31,2
	ctx.r8.s64 = ctx.r31.s64 + 131072;
	// addis r25,r31,2
	ctx.r25.s64 = ctx.r31.s64 + 131072;
	// stfs f31,16404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16404, temp.u32);
	// addi r8,r8,-6084
	ctx.r8.s64 = ctx.r8.s64 + -6084;
	// stfs f31,16408(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16408, temp.u32);
	// addi r25,r25,-6064
	ctx.r25.s64 = ctx.r25.s64 + -6064;
	// stw r30,16384(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16384, ctx.r30.u32);
	// li r7,1511
	ctx.r7.s64 = 1511;
	// lfs f0,20(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// lfs f25,76(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 76);
	ctx.f25.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f31,0(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f31,4(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stw r29,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r29.u32);
	// stfs f0,12(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// stfs f31,16(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// stw r7,8200(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8200, ctx.r7.u32);
	// stfs f25,8204(r25)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8204, temp.u32);
	// stfs f30,8208(r25)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8208, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821352BC;
	sub_8207DA20(ctx, base);
	// lwz r3,8200(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8200);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// li r6,1061
	ctx.r6.s64 = 1061;
	// stfs f31,8212(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8212, temp.u32);
	// neg r11,r3
	ctx.r11.s64 = -ctx.r3.s64;
	// stw r30,8192(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8192, ctx.r30.u32);
	// addi r28,r28,2152
	ctx.r28.s64 = ctx.r28.s64 + 2152;
	// clrlwi r10,r11,21
	ctx.r10.u64 = ctx.r11.u32 & 0x7FF;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8196(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8196, ctx.r10.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f25,8204(r28)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8204, temp.u32);
	// stw r6,8200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8200, ctx.r6.u32);
	// stfs f25,8208(r28)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8208, temp.u32);
	// stfs f30,8212(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8212, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135300;
	sub_8207DA20(ctx, base);
	// lwz r8,8200(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8200);
	// addis r25,r31,2
	ctx.r25.s64 = ctx.r31.s64 + 131072;
	// li r9,853
	ctx.r9.s64 = 853;
	// stfs f31,8216(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// addi r25,r25,10372
	ctx.r25.s64 = ctx.r25.s64 + 10372;
	// clrlwi r6,r7,21
	ctx.r6.u64 = ctx.r7.u32 & 0x7FF;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r6.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f25,8204(r25)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8204, temp.u32);
	// stw r9,8200(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8200, ctx.r9.u32);
	// stfs f30,8208(r25)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8208, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135340;
	sub_8207DA20(ctx, base);
	// lwz r11,8200(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8200);
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// li r3,541
	ctx.r3.s64 = 541;
	// stfs f31,8212(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8212, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r30,8192(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8192, ctx.r30.u32);
	// addi r28,r28,18588
	ctx.r28.s64 = ctx.r28.s64 + 18588;
	// lfs f0,12868(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 12868);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi r9,r10,21
	ctx.r9.u64 = ctx.r10.u32 & 0x7FF;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// stw r9,8196(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8196, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,4104(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4104, ctx.r3.u32);
	// stfs f0,4108(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4108, temp.u32);
	// stfs f29,4112(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4112, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x82135384;
	sub_8207DA20(ctx, base);
	// lwz r8,4104(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4104);
	// stfs f31,4116(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4116, temp.u32);
	// stw r30,4096(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4096, ctx.r30.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// clrlwi r6,r7,22
	ctx.r6.u64 = ctx.r7.u32 & 0x3FF;
	// stw r6,4100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4100, ctx.r6.u32);
	// bl 0x8207b7a8
	ctx.lr = 0x821353A8;
	sub_8207B7A8(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// addis r28,r31,2
	ctx.r28.s64 = ctx.r31.s64 + 131072;
	// lfs f0,84(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1510
	ctx.r11.s64 = 1510;
	// addi r28,r28,22708
	ctx.r28.s64 = ctx.r28.s64 + 22708;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f28,16396(r28)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16396, temp.u32);
	// stw r11,16388(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16388, ctx.r11.u32);
	// stw r11,16392(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16392, ctx.r11.u32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f8,16400(r28)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16400, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821353E0;
	sub_8207DA20(ctx, base);
	// addis r11,r31,3
	ctx.r11.s64 = ctx.r31.s64 + 196608;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// stfs f31,16404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16404, temp.u32);
	// addis r25,r31,3
	ctx.r25.s64 = ctx.r31.s64 + 196608;
	// stfs f31,16408(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16408, temp.u32);
	// addi r11,r11,-26416
	ctx.r11.s64 = ctx.r11.s64 + -26416;
	// stw r30,16384(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16384, ctx.r30.u32);
	// addi r25,r25,-26392
	ctx.r25.s64 = ctx.r25.s64 + -26392;
	// li r10,1657
	ctx.r10.s64 = 1657;
	// lfs f0,-22624(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -22624);
	ctx.f0.f64 = double(temp.f32);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f31,0(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stfs f31,4(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r29.u32);
	// stfs f0,12(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// stfs f31,20(r11)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// stw r10,8200(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8200, ctx.r10.u32);
	// stfs f25,8204(r25)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8204, temp.u32);
	// stfs f30,8208(r25)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8208, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x8213543C;
	sub_8207DA20(ctx, base);
	// lwz r8,8200(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8200);
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// li r9,1103
	ctx.r9.s64 = 1103;
	// stfs f31,8212(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8212, temp.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// stw r30,8192(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8192, ctx.r30.u32);
	// addi r28,r28,-18176
	ctx.r28.s64 = ctx.r28.s64 + -18176;
	// clrlwi r6,r7,21
	ctx.r6.u64 = ctx.r7.u32 & 0x7FF;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,8196(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8196, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f25,8204(r28)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8204, temp.u32);
	// stw r9,8200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8200, ctx.r9.u32);
	// stfs f25,8208(r28)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8208, temp.u32);
	// stfs f30,8212(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8212, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135480;
	sub_8207DA20(ctx, base);
	// lwz r11,8200(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8200);
	// addis r25,r31,3
	ctx.r25.s64 = ctx.r31.s64 + 196608;
	// li r3,887
	ctx.r3.s64 = 887;
	// stfs f31,8216(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r30,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r30.u32);
	// addi r25,r25,-9956
	ctx.r25.s64 = ctx.r25.s64 + -9956;
	// clrlwi r9,r10,21
	ctx.r9.u64 = ctx.r10.u32 & 0x7FF;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// stw r9,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,8200(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8200, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f25,8204(r25)
	temp.f32 = float(ctx.f25.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8204, temp.u32);
	// stfs f30,8208(r25)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8208, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821354C0;
	sub_8207DA20(ctx, base);
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// lwz r7,8200(r25)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8200);
	// addi r28,r28,-1740
	ctx.r28.s64 = ctx.r28.s64 + -1740;
	// li r8,491
	ctx.r8.s64 = 491;
	// lfs f0,12868(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 12868);
	ctx.f0.f64 = double(temp.f32);
	// neg r6,r7
	ctx.r6.s64 = -ctx.r7.s64;
	// stfs f31,8212(r25)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8212, temp.u32);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// stw r30,8192(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8192, ctx.r30.u32);
	// clrlwi r3,r6,21
	ctx.r3.u64 = ctx.r6.u32 & 0x7FF;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,8196(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8196, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f0,4108(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4108, temp.u32);
	// stw r8,4104(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4104, ctx.r8.u32);
	// stfs f29,4112(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4112, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135504;
	sub_8207DA20(ctx, base);
	// lwz r11,4104(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4104);
	// stfs f31,4116(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 4116, temp.u32);
	// stw r30,4096(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4096, ctx.r30.u32);
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// fmr f1,f26
	ctx.f1.f64 = ctx.f26.f64;
	// clrlwi r9,r10,22
	ctx.r9.u64 = ctx.r10.u32 & 0x3FF;
	// stw r9,4100(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4100, ctx.r9.u32);
	// bl 0x8207b7a8
	ctx.lr = 0x82135528;
	sub_8207B7A8(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// addis r28,r31,3
	ctx.r28.s64 = ctx.r31.s64 + 196608;
	// lfs f0,84(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1438
	ctx.r11.s64 = 1438;
	// addi r28,r28,2380
	ctx.r28.s64 = ctx.r28.s64 + 2380;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f28,16396(r28)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16396, temp.u32);
	// stw r11,16388(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16388, ctx.r11.u32);
	// stw r11,16392(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16392, ctx.r11.u32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// stfs f6,16400(r28)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16400, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135560;
	sub_8207DA20(ctx, base);
	// addis r8,r31,3
	ctx.r8.s64 = ctx.r31.s64 + 196608;
	// addis r26,r31,3
	ctx.r26.s64 = ctx.r31.s64 + 196608;
	// stfs f31,16404(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16404, temp.u32);
	// addi r8,r8,18792
	ctx.r8.s64 = ctx.r8.s64 + 18792;
	// stfs f31,16408(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 16408, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r30,16384(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16384, ctx.r30.u32);
	// addi r26,r26,18816
	ctx.r26.s64 = ctx.r26.s64 + 18816;
	// lfs f0,120(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// li r6,131
	ctx.r6.s64 = 131;
	// lfs f30,124(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 124);
	ctx.f30.f64 = double(temp.f32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,0(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lfs f29,-19128(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19128);
	ctx.f29.f64 = double(temp.f32);
	// stfs f31,4(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stw r29,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r29.u32);
	// stfs f0,12(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 12, temp.u32);
	// stfs f0,16(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 16, temp.u32);
	// stfs f31,20(r8)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 20, temp.u32);
	// stw r6,2056(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2056, ctx.r6.u32);
	// stfs f30,2060(r26)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2060, temp.u32);
	// stfs f29,2064(r26)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821355C4;
	sub_8207DA20(ctx, base);
	// lwz r11,2056(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 2056);
	// addis r29,r31,3
	ctx.r29.s64 = ctx.r31.s64 + 196608;
	// li r3,113
	ctx.r3.s64 = 113;
	// stfs f31,2068(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2068, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r30,2048(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2048, ctx.r30.u32);
	// addi r29,r29,20888
	ctx.r29.s64 = ctx.r29.s64 + 20888;
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stw r9,2052(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2052, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,2056(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2056, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f30,2060(r29)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2060, temp.u32);
	// stfs f29,2064(r29)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135604;
	sub_8207DA20(ctx, base);
	// stfs f31,2068(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// lwz r8,2056(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2056);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r30.u32);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// clrlwi r6,r7,23
	ctx.r6.u64 = ctx.r7.u32 & 0x1FF;
	// stw r6,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r6.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x820803a8
	ctx.lr = 0x8213562C;
	__restfpr_25(ctx, base);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135630"))) PPC_WEAK_FUNC(sub_82135630);
PPC_FUNC_IMPL(__imp__sub_82135630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82135638;
	__savegprlr_25(ctx, base);
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82134d18
	ctx.lr = 0x82135650;
	sub_82134D18(ctx, base);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addis r3,r29,3
	ctx.r3.s64 = ctx.r29.s64 + 196608;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r3,22960
	ctx.r3.s64 = ctx.r3.s64 + 22960;
	// lfs f30,-19112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19112);
	ctx.f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82130888
	ctx.lr = 0x8213566C;
	sub_82130888(ctx, base);
	// addis r3,r29,5
	ctx.r3.s64 = ctx.r29.s64 + 327680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r3,22992
	ctx.r3.s64 = ctx.r3.s64 + 22992;
	// lfs f0,-19116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,9388(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// stfs f30,0(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f31,8(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f31,12(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f31,16(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f31,20(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f31,24(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f31,28(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f31,32(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f31,36(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// bl 0x8212e2f8
	ctx.lr = 0x821356B0;
	sub_8212E2F8(ctx, base);
	// lis r28,-32254
	ctx.r28.s64 = -2113798144;
	// lis r8,5
	ctx.r8.s64 = 327680;
	// lis r7,5
	ctx.r7.s64 = 327680;
	// addis r26,r29,5
	ctx.r26.s64 = ctx.r29.s64 + 327680;
	// addi r27,r28,-22496
	ctx.r27.s64 = ctx.r28.s64 + -22496;
	// ori r6,r8,23032
	ctx.r6.u64 = ctx.r8.u64 | 23032;
	// ori r11,r7,23036
	ctx.r11.u64 = ctx.r7.u64 | 23036;
	// addi r26,r26,23040
	ctx.r26.s64 = ctx.r26.s64 + 23040;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,44(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lfs f13,48(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f0,r29,r6
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r6.u32, temp.u32);
	// stfsx f13,r29,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r29.u32 + ctx.r11.u32, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821356F0;
	sub_8207DA20(ctx, base);
	// addis r25,r29,5
	ctx.r25.s64 = ctx.r29.s64 + 327680;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,8(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r25,r25,25128
	ctx.r25.s64 = ctx.r25.s64 + 25128;
	// stfs f0,2068(r26)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2068, temp.u32);
	// li r9,509
	ctx.r9.s64 = 509;
	// lfs f30,-22496(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + -22496);
	ctx.f30.f64 = double(temp.f32);
	// li r8,508
	ctx.r8.s64 = 508;
	// lfs f12,12(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// li r31,0
	ctx.r31.s64 = 0;
	// stfs f30,2064(r26)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2064, temp.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// lfs f0,-19120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19120);
	ctx.f0.f64 = double(temp.f32);
	// li r7,97
	ctx.r7.s64 = 97;
	// stfs f13,2072(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2072, temp.u32);
	// li r5,512
	ctx.r5.s64 = 512;
	// stfs f31,2076(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2076, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f31,2080(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2080, temp.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stfs f31,2084(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 2084, temp.u32);
	// stw r31,2048(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2048, ctx.r31.u32);
	// stw r9,2052(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2052, ctx.r9.u32);
	// stw r8,2056(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2056, ctx.r8.u32);
	// stw r30,2060(r26)
	PPC_STORE_U32(ctx.r26.u32 + 2060, ctx.r30.u32);
	// stfs f12,524(r25)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r25.u32 + 524, temp.u32);
	// stfs f0,528(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 528, temp.u32);
	// stw r7,520(r25)
	PPC_STORE_U32(ctx.r25.u32 + 520, ctx.r7.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135768;
	sub_8207DA20(ctx, base);
	// addis r28,r29,5
	ctx.r28.s64 = ctx.r29.s64 + 327680;
	// lwz r6,520(r25)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r25.u32 + 520);
	// stfs f31,532(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r25.u32 + 532, temp.u32);
	// addi r28,r28,25664
	ctx.r28.s64 = ctx.r28.s64 + 25664;
	// stw r31,512(r25)
	PPC_STORE_U32(ctx.r25.u32 + 512, ctx.r31.u32);
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// neg r11,r6
	ctx.r11.s64 = -ctx.r6.s64;
	// clrlwi r10,r11,25
	ctx.r10.u64 = ctx.r11.u32 & 0x7F;
	// stw r10,516(r25)
	PPC_STORE_U32(ctx.r25.u32 + 516, ctx.r10.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135798;
	sub_8207DA20(ctx, base);
	// addis r26,r29,6
	ctx.r26.s64 = ctx.r29.s64 + 393216;
	// lfs f0,20(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,8212(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8212, temp.u32);
	// addi r26,r26,-31640
	ctx.r26.s64 = ctx.r26.s64 + -31640;
	// stfs f30,8208(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8208, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f31,8220(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8220, temp.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stfs f31,8224(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8224, temp.u32);
	// li r6,1297
	ctx.r6.s64 = 1297;
	// stfs f31,8228(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8228, temp.u32);
	// li r5,1296
	ctx.r5.s64 = 1296;
	// lfs f0,23060(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 23060);
	ctx.f0.f64 = double(temp.f32);
	// li r4,600
	ctx.r4.s64 = 600;
	// stfs f0,8216(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 8216, temp.u32);
	// li r3,223
	ctx.r3.s64 = 223;
	// stw r5,8200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8200, ctx.r5.u32);
	// stw r4,8204(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8204, ctx.r4.u32);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// stw r31,8192(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8192, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,8196(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8196, ctx.r6.u32);
	// lfs f30,12868(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12868);
	ctx.f30.f64 = double(temp.f32);
	// stw r3,1032(r26)
	PPC_STORE_U32(ctx.r26.u32 + 1032, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lfs f29,-20796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -20796);
	ctx.f29.f64 = double(temp.f32);
	// stfs f30,1036(r26)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r26.u32 + 1036, temp.u32);
	// stfs f29,1040(r26)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r26.u32 + 1040, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135810;
	sub_8207DA20(ctx, base);
	// lwz r10,1032(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 1032);
	// addis r28,r29,6
	ctx.r28.s64 = ctx.r29.s64 + 393216;
	// li r11,293
	ctx.r11.s64 = 293;
	// stfs f31,1044(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 1044, temp.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r31,1024(r26)
	PPC_STORE_U32(ctx.r26.u32 + 1024, ctx.r31.u32);
	// addi r28,r28,-30592
	ctx.r28.s64 = ctx.r28.s64 + -30592;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,1028(r26)
	PPC_STORE_U32(ctx.r26.u32 + 1028, ctx.r8.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f30,2060(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2060, temp.u32);
	// stw r11,2056(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2056, ctx.r11.u32);
	// stfs f29,2064(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135850;
	sub_8207DA20(ctx, base);
	// lwz r6,2056(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r26,r29,6
	ctx.r26.s64 = ctx.r29.s64 + 393216;
	// li r7,1020
	ctx.r7.s64 = 1020;
	// lfs f0,36(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// neg r3,r6
	ctx.r3.s64 = -ctx.r6.s64;
	// lfs f13,40(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// addi r26,r26,-28520
	ctx.r26.s64 = ctx.r26.s64 + -28520;
	// stfs f31,2068(r28)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r11.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stfs f0,4108(r26)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r26.u32 + 4108, temp.u32);
	// stw r7,4100(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4100, ctx.r7.u32);
	// stfs f13,4112(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r26.u32 + 4112, temp.u32);
	// stw r30,4104(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4104, ctx.r30.u32);
	// bl 0x8207da20
	ctx.lr = 0x8213589C;
	sub_8207DA20(ctx, base);
	// addis r30,r29,6
	ctx.r30.s64 = ctx.r29.s64 + 393216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f30,124(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 124);
	ctx.f30.f64 = double(temp.f32);
	// addi r30,r30,-24396
	ctx.r30.s64 = ctx.r30.s64 + -24396;
	// stfs f31,4116(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 4116, temp.u32);
	// stfs f31,4120(r26)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r26.u32 + 4120, temp.u32);
	// stw r31,4096(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4096, ctx.r31.u32);
	// li r9,107
	ctx.r9.s64 = 107;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// lfs f29,-19128(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19128);
	ctx.f29.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f30,2060(r30)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2060, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f29,2064(r30)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2064, temp.u32);
	// stw r9,2056(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2056, ctx.r9.u32);
	// bl 0x8207da20
	ctx.lr = 0x821358DC;
	sub_8207DA20(ctx, base);
	// lwz r8,2056(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 2056);
	// addis r28,r29,6
	ctx.r28.s64 = ctx.r29.s64 + 393216;
	// stfs f31,2068(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 2068, temp.u32);
	// neg r6,r8
	ctx.r6.s64 = -ctx.r8.s64;
	// stw r31,2048(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2048, ctx.r31.u32);
	// addi r28,r28,-22324
	ctx.r28.s64 = ctx.r28.s64 + -22324;
	// clrlwi r3,r6,23
	ctx.r3.u64 = ctx.r6.u32 & 0x1FF;
	// li r7,127
	ctx.r7.s64 = 127;
	// stw r3,2052(r30)
	PPC_STORE_U32(ctx.r30.u32 + 2052, ctx.r3.u32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f30,2060(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2060, temp.u32);
	// stfs f29,2064(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2064, temp.u32);
	// stw r7,2056(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2056, ctx.r7.u32);
	// bl 0x8207da20
	ctx.lr = 0x8213591C;
	sub_8207DA20(ctx, base);
	// lwz r11,2056(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// neg r10,r11
	ctx.r10.s64 = -ctx.r11.s64;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// clrlwi r9,r10,23
	ctx.r9.u64 = ctx.r10.u32 & 0x1FF;
	// stw r9,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-88(r1)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213594C"))) PPC_WEAK_FUNC(sub_8213594C);
PPC_FUNC_IMPL(__imp__sub_8213594C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135950"))) PPC_WEAK_FUNC(sub_82135950);
PPC_FUNC_IMPL(__imp__sub_82135950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82135958;
	__savegprlr_28(ctx, base);
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82135630
	ctx.lr = 0x82135970;
	sub_82135630(ctx, base);
	// addis r29,r30,6
	ctx.r29.s64 = ctx.r30.s64 + 393216;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r29,-20252
	ctx.r29.s64 = ctx.r29.s64 + -20252;
	// li r9,103
	ctx.r9.s64 = 103;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f30,-22372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -22372);
	ctx.f30.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lfs f29,-19128(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19128);
	ctx.f29.f64 = double(temp.f32);
	// stfs f30,2060(r29)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2060, temp.u32);
	// stw r9,2056(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2056, ctx.r9.u32);
	// stfs f29,2064(r29)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821359A8;
	sub_8207DA20(ctx, base);
	// lwz r6,2056(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 2056);
	// addis r28,r30,6
	ctx.r28.s64 = ctx.r30.s64 + 393216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// neg r3,r6
	ctx.r3.s64 = -ctx.r6.s64;
	// addi r28,r28,-18180
	ctx.r28.s64 = ctx.r28.s64 + -18180;
	// clrlwi r11,r3,23
	ctx.r11.u64 = ctx.r3.u32 & 0x1FF;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r7,97
	ctx.r7.s64 = 97;
	// lfs f31,9388(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 9388);
	ctx.f31.f64 = double(temp.f32);
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stfs f31,2068(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r31.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r11,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r11.u32);
	// stfs f30,2060(r28)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2060, temp.u32);
	// stw r7,2056(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2056, ctx.r7.u32);
	// stfs f29,2064(r28)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2064, temp.u32);
	// bl 0x8207da20
	ctx.lr = 0x821359F4;
	sub_8207DA20(ctx, base);
	// lwz r10,2056(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 2056);
	// addis r29,r30,6
	ctx.r29.s64 = ctx.r30.s64 + 393216;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// stfs f31,2068(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r28.u32 + 2068, temp.u32);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r31,2048(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2048, ctx.r31.u32);
	// addi r29,r29,-16108
	ctx.r29.s64 = ctx.r29.s64 + -16108;
	// clrlwi r8,r9,23
	ctx.r8.u64 = ctx.r9.u32 & 0x1FF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r8,2052(r28)
	PPC_STORE_U32(ctx.r28.u32 + 2052, ctx.r8.u32);
	// bl 0x8207da20
	ctx.lr = 0x82135A24;
	sub_8207DA20(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r11,40
	ctx.r11.s64 = 40;
	// stfs f31,2068(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2068, temp.u32);
	// stfs f31,2072(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2072, temp.u32);
	// stw r31,2048(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2048, ctx.r31.u32);
	// stfs f31,2076(r29)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2076, temp.u32);
	// stw r11,2052(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2052, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,2056(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2056, ctx.r11.u32);
	// lfs f0,-19112(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -19112);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,2060(r29)
	PPC_STORE_U32(ctx.r29.u32 + 2060, ctx.r11.u32);
	// stfs f0,2064(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 2064, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-64(r1)
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135A68"))) PPC_WEAK_FUNC(sub_82135A68);
PPC_FUNC_IMPL(__imp__sub_82135A68) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x82135a7c
	if (!ctx.cr6.eq) goto loc_82135A7C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82134d18
	sub_82134D18(ctx, base);
	return;
loc_82135A7C:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x82135a90
	if (!ctx.cr6.eq) goto loc_82135A90;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82135630
	sub_82135630(ctx, base);
	return;
loc_82135A90:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82135950
	sub_82135950(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135A9C"))) PPC_WEAK_FUNC(sub_82135A9C);
PPC_FUNC_IMPL(__imp__sub_82135A9C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135AA0"))) PPC_WEAK_FUNC(sub_82135AA0);
PPC_FUNC_IMPL(__imp__sub_82135AA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82135AA8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// lwz r9,528(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 528);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r8,r3,32
	ctx.r8.s64 = ctx.r3.s64 + 32;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
loc_82135AC4:
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82135af0
	goto loc_82135AF0;
loc_82135ACC:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82135ae4
	if (ctx.cr6.eq) goto loc_82135AE4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82135ae8
	goto loc_82135AE8;
loc_82135AE4:
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
loc_82135AE8:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r27,60(r10)
	PPC_STORE_U32(ctx.r10.u32 + 60, ctx.r27.u32);
loc_82135AF0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82135acc
	if (!ctx.cr6.eq) goto loc_82135ACC;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82135b10
	if (ctx.cr6.eq) goto loc_82135B10;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,40
	ctx.r8.s64 = ctx.r8.s64 + 40;
	// cmplwi cr6,r7,13
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 13, ctx.xer);
	// blt cr6,0x82135ac4
	if (ctx.cr6.lt) goto loc_82135AC4;
loc_82135B10:
	// lwz r30,540(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 540);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r10,536(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// lwz r28,552(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 552);
	// addi r29,r11,-5536
	ctx.r29.s64 = ctx.r11.s64 + -5536;
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82135b6c
	if (ctx.cr6.eq) goto loc_82135B6C;
	// lwz r3,532(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82135b40
	if (ctx.cr6.eq) goto loc_82135B40;
	// bl 0x82114628
	ctx.lr = 0x82135B3C;
	sub_82114628(ctx, base);
	// stw r27,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r27.u32);
loc_82135B40:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82108aa8
	ctx.lr = 0x82135B58;
	sub_82108AA8(ctx, base);
	// stw r3,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82135bc0
	if (ctx.cr0.eq) goto loc_82135BC0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r30,536(r31)
	PPC_STORE_U32(ctx.r31.u32 + 536, ctx.r30.u32);
loc_82135B6C:
	// lwz r11,548(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 548);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82135bb8
	if (!ctx.cr6.gt) goto loc_82135BB8;
	// lwz r3,544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 544);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82135b8c
	if (ctx.cr6.eq) goto loc_82135B8C;
	// bl 0x82114628
	ctx.lr = 0x82135B88;
	sub_82114628(ctx, base);
	// stw r27,544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 544, ctx.r27.u32);
loc_82135B8C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82108aa8
	ctx.lr = 0x82135BA4;
	sub_82108AA8(ctx, base);
	// stw r3,544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 544, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82135bc0
	if (ctx.cr0.eq) goto loc_82135BC0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r28,548(r31)
	PPC_STORE_U32(ctx.r31.u32 + 548, ctx.r28.u32);
loc_82135BB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82135BC0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82135bb8
	goto loc_82135BB8;
}

__attribute__((alias("__imp__sub_82135BCC"))) PPC_WEAK_FUNC(sub_82135BCC);
PPC_FUNC_IMPL(__imp__sub_82135BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135BD0"))) PPC_WEAK_FUNC(sub_82135BD0);
PPC_FUNC_IMPL(__imp__sub_82135BD0) {
	PPC_FUNC_PROLOGUE();
	// li r11,13
	ctx.r11.s64 = 13;
	// divw r11,r4,r11
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r11.s32);
	// mulli r11,r11,13
	ctx.r11.s64 = ctx.r11.s64 * 13;
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// mulli r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 * 40;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
loc_82135BEC:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82135c04
	if (ctx.cr6.eq) goto loc_82135C04;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82135c08
	goto loc_82135C08;
loc_82135C04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82135C08:
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpw cr6,r10,r4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x82135bec
	if (!ctx.cr6.eq) goto loc_82135BEC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135C18"))) PPC_WEAK_FUNC(sub_82135C18);
PPC_FUNC_IMPL(__imp__sub_82135C18) {
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
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82135c54
	if (!ctx.cr6.lt) goto loc_82135C54;
	// bl 0x821d5474
	ctx.lr = 0x82135C48;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82135c54
	if (ctx.cr6.eq) goto loc_82135C54;
	// li r30,1
	ctx.r30.s64 = 1;
loc_82135C54:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82135c68
	if (ctx.cr6.eq) goto loc_82135C68;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82135cdc
	if (ctx.cr6.eq) goto loc_82135CDC;
loc_82135C68:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82135ccc
	if (ctx.cr6.gt) goto loc_82135CCC;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82108aa8
	ctx.lr = 0x82135C98;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82135cdc
	if (ctx.cr0.eq) goto loc_82135CDC;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// b 0x82135cdc
	goto loc_82135CDC;
loc_82135CCC:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,16296
	ctx.r3.s64 = ctx.r11.s64 + 16296;
	// bl 0x8208d988
	ctx.lr = 0x82135CD8;
	sub_8208D988(ctx, base);
	// twi 31,r0,22
loc_82135CDC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82135cf4
	if (ctx.cr6.eq) goto loc_82135CF4;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82135cf8
	goto loc_82135CF8;
loc_82135CF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82135CF8:
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

__attribute__((alias("__imp__sub_82135D10"))) PPC_WEAK_FUNC(sub_82135D10);
PPC_FUNC_IMPL(__imp__sub_82135D10) {
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
	// li r11,13
	ctx.r11.s64 = 13;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// divw r11,r4,r11
	ctx.r11.s32 = ppc_divw(ctx.r4.s32, ctx.r11.s32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mulli r11,r11,13
	ctx.r11.s64 = ctx.r11.s64 * 13;
	// subf r11,r11,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r11.s64;
	// mulli r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 * 40;
	// add r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r11,32(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
loc_82135D48:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82135d64
	if (ctx.cr6.eq) goto loc_82135D64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r30,0(r9)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x82135d68
	goto loc_82135D68;
loc_82135D64:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82135D68:
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82135d48
	if (!ctx.cr6.eq) goto loc_82135D48;
	// addi r3,r8,8
	ctx.r3.s64 = ctx.r8.s64 + 8;
	// bl 0x8210ea78
	ctx.lr = 0x82135D7C;
	sub_8210EA78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8214df00
	ctx.lr = 0x82135D84;
	sub_8214DF00(ctx, base);
	// lwz r11,528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 528, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82135DA8"))) PPC_WEAK_FUNC(sub_82135DA8);
PPC_FUNC_IMPL(__imp__sub_82135DA8) {
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
	// bl 0x82135c18
	ctx.lr = 0x82135DC8;
	sub_82135C18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82135e0c
	if (ctx.cr0.eq) goto loc_82135E0C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82135df8
	if (ctx.cr6.eq) goto loc_82135DF8;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x82135dfc
	goto loc_82135DFC;
loc_82135DF8:
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
loc_82135DFC:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_82135E0C:
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

__attribute__((alias("__imp__sub_82135E24"))) PPC_WEAK_FUNC(sub_82135E24);
PPC_FUNC_IMPL(__imp__sub_82135E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135E28"))) PPC_WEAK_FUNC(sub_82135E28);
PPC_FUNC_IMPL(__imp__sub_82135E28) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r9,12
	ctx.r9.s64 = 12;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82135E3C:
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r10,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r7,36(r11)
	PPC_STORE_U32(ctx.r11.u32 + 36, ctx.r7.u32);
	// stw r10,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bge 0x82135e3c
	if (!ctx.cr0.lt) goto loc_82135E3C;
	// stw r10,528(r3)
	PPC_STORE_U32(ctx.r3.u32 + 528, ctx.r10.u32);
	// stw r10,532(r3)
	PPC_STORE_U32(ctx.r3.u32 + 532, ctx.r10.u32);
	// stw r10,536(r3)
	PPC_STORE_U32(ctx.r3.u32 + 536, ctx.r10.u32);
	// stw r10,540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 540, ctx.r10.u32);
	// stw r10,544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 544, ctx.r10.u32);
	// stw r10,548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 548, ctx.r10.u32);
	// stw r10,552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 552, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82135EA0"))) PPC_WEAK_FUNC(sub_82135EA0);
PPC_FUNC_IMPL(__imp__sub_82135EA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82135EA8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r3,40
	ctx.r30.s64 = ctx.r3.s64 + 40;
	// li r29,13
	ctx.r29.s64 = 13;
loc_82135EB8:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82135eec
	if (ctx.cr6.eq) goto loc_82135EEC;
	// addi r28,r30,-32
	ctx.r28.s64 = ctx.r30.s64 + -32;
loc_82135EC8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82109678
	ctx.lr = 0x82135ED0;
	sub_82109678(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x8214dcf8
	ctx.lr = 0x82135ED8;
	sub_8214DCF8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82114628
	ctx.lr = 0x82135EE0;
	sub_82114628(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82135ec8
	if (!ctx.cr6.eq) goto loc_82135EC8;
loc_82135EEC:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// bne 0x82135eb8
	if (!ctx.cr0.eq) goto loc_82135EB8;
	// lwz r3,532(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82135f10
	if (ctx.cr6.eq) goto loc_82135F10;
	// bl 0x82114628
	ctx.lr = 0x82135F0C;
	sub_82114628(ctx, base);
	// stw r30,532(r31)
	PPC_STORE_U32(ctx.r31.u32 + 532, ctx.r30.u32);
loc_82135F10:
	// lwz r3,544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 544);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82135f24
	if (ctx.cr6.eq) goto loc_82135F24;
	// bl 0x82114628
	ctx.lr = 0x82135F20;
	sub_82114628(ctx, base);
	// stw r30,544(r31)
	PPC_STORE_U32(ctx.r31.u32 + 544, ctx.r30.u32);
loc_82135F24:
	// addi r31,r31,528
	ctx.r31.s64 = ctx.r31.s64 + 528;
	// li r30,12
	ctx.r30.s64 = 12;
loc_82135F2C:
	// addi r31,r31,-40
	ctx.r31.s64 = ctx.r31.s64 + -40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210ef58
	ctx.lr = 0x82135F38;
	sub_8210EF58(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82135f2c
	if (!ctx.cr0.lt) goto loc_82135F2C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82135F48"))) PPC_WEAK_FUNC(sub_82135F48);
PPC_FUNC_IMPL(__imp__sub_82135F48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82135F50;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8214df78
	ctx.lr = 0x82135F78;
	sub_8214DF78(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82135fcc
	if (ctx.cr0.lt) goto loc_82135FCC;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,13
	ctx.r11.s64 = 13;
	// lwz r10,48(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// divw r11,r10,r11
	ctx.r11.s32 = ppc_divw(ctx.r10.s32, ctx.r11.s32);
	// mulli r11,r11,13
	ctx.r11.s64 = ctx.r11.s64 * 13;
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// mulli r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 * 40;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x82135da8
	ctx.lr = 0x82135FA8;
	sub_82135DA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82135fd8
	if (ctx.cr0.eq) goto loc_82135FD8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// lwz r11,528(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,528(r31)
	PPC_STORE_U32(ctx.r31.u32 + 528, ctx.r11.u32);
loc_82135FCC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82135FD8:
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// bl 0x8214df00
	ctx.lr = 0x82135FE8;
	sub_8214DF00(ctx, base);
	// b 0x82135fcc
	goto loc_82135FCC;
}

__attribute__((alias("__imp__sub_82135FEC"))) PPC_WEAK_FUNC(sub_82135FEC);
PPC_FUNC_IMPL(__imp__sub_82135FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82135FF0"))) PPC_WEAK_FUNC(sub_82135FF0);
PPC_FUNC_IMPL(__imp__sub_82135FF0) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x82136000
	if (ctx.cr6.eq) goto loc_82136000;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82136010
	goto loc_82136010;
loc_82136000:
	// lwz r11,572(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 572);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82136010:
	// stw r11,572(r3)
	PPC_STORE_U32(ctx.r3.u32 + 572, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82136018"))) PPC_WEAK_FUNC(sub_82136018);
PPC_FUNC_IMPL(__imp__sub_82136018) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82136020;
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
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r8,r3,12
	ctx.r8.s64 = ctx.r3.s64 + 12;
loc_82136038:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r8
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r8.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8213605c
	if (!ctx.cr6.eq) goto loc_8213605C;
	// stwcx. r11,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82136038
	if (!ctx.cr0.eq) goto loc_82136038;
	// b 0x82136064
	goto loc_82136064;
loc_8213605C:
	// stwcx. r10,0,r8
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r8.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82136064:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r28,r11,-5536
	ctx.r28.s64 = ctx.r11.s64 + -5536;
	// addi r3,r28,84
	ctx.r3.s64 = ctx.r28.s64 + 84;
	// bl 0x821d5384
	ctx.lr = 0x82136074;
	__imp__RtlEnterCriticalSection(ctx, base);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// bne cr6,0x82136084
	if (!ctx.cr6.eq) goto loc_82136084;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// b 0x82136090
	goto loc_82136090;
loc_82136084:
	// addi r11,r30,5
	ctx.r11.s64 = ctx.r30.s64 + 5;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
loc_82136090:
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r3,r28,84
	ctx.r3.s64 = ctx.r28.s64 + 84;
	// bl 0x821d5394
	ctx.lr = 0x8213609C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821360A8"))) PPC_WEAK_FUNC(sub_821360A8);
PPC_FUNC_IMPL(__imp__sub_821360A8) {
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
	// addi r30,r3,36
	ctx.r30.s64 = ctx.r3.s64 + 36;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x821360CC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136114
	if (ctx.cr6.eq) goto loc_82136114;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821d5b04
	ctx.lr = 0x821360E8;
	__imp__KeSetEvent(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82088438
	ctx.lr = 0x821360F4;
	sub_82088438(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82136114
	if (ctx.cr6.eq) goto loc_82136114;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82136114
	if (ctx.cr6.eq) goto loc_82136114;
	// bl 0x82088d00
	ctx.lr = 0x8213610C;
	sub_82088D00(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82136114:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x8213611C;
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

__attribute__((alias("__imp__sub_82136134"))) PPC_WEAK_FUNC(sub_82136134);
PPC_FUNC_IMPL(__imp__sub_82136134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136138"))) PPC_WEAK_FUNC(sub_82136138);
PPC_FUNC_IMPL(__imp__sub_82136138) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-1904(r1)
	ea = -1904 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r31,r3,24
	ctx.r31.s64 = ctx.r3.s64 + 24;
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// beq cr6,0x821361a0
	if (ctx.cr6.eq) goto loc_821361A0;
	// clrldi r11,r4,32
	ctx.r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mulli r11,r11,-10000
	ctx.r11.s64 = ctx.r11.s64 * -10000;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// b 0x821361a4
	goto loc_821361A4;
loc_82136184:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r5,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r5.u32);
	// stw r3,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r3.u32);
loc_821361A0:
	// li r9,0
	ctx.r9.s64 = 0;
loc_821361A4:
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x821d5b94
	ctx.lr = 0x821361C4;
	__imp__KeWaitForMultipleObjects(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82136184
	if (ctx.cr6.eq) goto loc_82136184;
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// beq cr6,0x821361e0
	if (ctx.cr6.eq) goto loc_821361E0;
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x821361e4
	if (!ctx.cr6.eq) goto loc_821361E4;
loc_821361E0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_821361E4:
	// addi r1,r1,1904
	ctx.r1.s64 = ctx.r1.s64 + 1904;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821361F8"))) PPC_WEAK_FUNC(sub_821361F8);
PPC_FUNC_IMPL(__imp__sub_821361F8) {
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
	// bl 0x8208da10
	ctx.lr = 0x82136210;
	sub_8208DA10(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x821d5b04
	ctx.lr = 0x82136224;
	__imp__KeSetEvent(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82136138
	ctx.lr = 0x82136230;
	sub_82136138(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82136244;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82136264"))) PPC_WEAK_FUNC(sub_82136264);
PPC_FUNC_IMPL(__imp__sub_82136264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136268"))) PPC_WEAK_FUNC(sub_82136268);
PPC_FUNC_IMPL(__imp__sub_82136268) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82136270;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821362ec
	if (ctx.cr6.eq) goto loc_821362EC;
	// bl 0x821360a8
	ctx.lr = 0x8213628C;
	sub_821360A8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// stw r29,668(r30)
	PPC_STORE_U32(ctx.r30.u32 + 668, ctx.r29.u32);
	// beq cr6,0x821362e0
	if (ctx.cr6.eq) goto loc_821362E0;
	// lwz r31,336(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 336);
	// stw r29,128(r30)
	PPC_STORE_U32(ctx.r30.u32 + 128, ctx.r29.u32);
	// b 0x821362d4
	goto loc_821362D4;
loc_821362A8:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821362c0
	if (ctx.cr6.eq) goto loc_821362C0;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x821362c4
	goto loc_821362C4;
loc_821362C0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821362C4:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821362D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821362D4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821362a8
	if (!ctx.cr6.eq) goto loc_821362A8;
	// b 0x821362e8
	goto loc_821362E8;
loc_821362E0:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,128(r30)
	PPC_STORE_U32(ctx.r30.u32 + 128, ctx.r11.u32);
loc_821362E8:
	// stw r29,120(r30)
	PPC_STORE_U32(ctx.r30.u32 + 120, ctx.r29.u32);
loc_821362EC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821362F4"))) PPC_WEAK_FUNC(sub_821362F4);
PPC_FUNC_IMPL(__imp__sub_821362F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821362F8"))) PPC_WEAK_FUNC(sub_821362F8);
PPC_FUNC_IMPL(__imp__sub_821362F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82136300;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r25,r3,656
	ctx.r25.s64 = ctx.r3.s64 + 656;
loc_82136318:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r25
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r25.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r27,0,r25
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r25.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r27.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82136318
	if (!ctx.cr0.eq) goto loc_82136318;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// ld r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// clrldi r10,r29,32
	ctx.r10.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// std r10,0(r30)
	PPC_STORE_U64(ctx.r30.u32 + 0, ctx.r10.u64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136358
	if (ctx.cr6.eq) goto loc_82136358;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x8213635c
	if (!ctx.cr6.gt) goto loc_8213635C;
loc_82136358:
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
loc_8213635C:
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136370
	if (ctx.cr6.eq) goto loc_82136370;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x82136374
	if (!ctx.cr6.lt) goto loc_82136374;
loc_82136370:
	// stw r29,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
loc_82136374:
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8213638C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r3.u32);
	// lwz r28,120(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// lwz r11,148(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 148);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821363f4
	if (ctx.cr6.eq) goto loc_821363F4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// clrldi r10,r29,32
	ctx.r10.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// ld r3,22120(r11)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r11.u32 + 22120);
	// bl 0x8215a9f0
	ctx.lr = 0x821363B4;
	sub_8215A9F0(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// fdiv f0,f0,f1
	ctx.f0.f64 = ctx.f0.f64 / ctx.f1.f64;
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fdiv f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 / ctx.f12.f64;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x821363f4
	if (!ctx.cr6.gt) goto loc_821363F4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8214e1a0
	ctx.lr = 0x821363F4;
	sub_8214E1A0(ctx, base);
loc_821363F4:
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// lwz r8,152(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 152);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r8,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r8.u32);
loc_82136410:
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x82136410
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82136410;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// mftb r11
	ctx.r11.u64 = rt_mftb();
	// ld r10,680(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 680);
	// clrldi r28,r26,32
	ctx.r28.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// subf r3,r10,r28
	ctx.r3.s64 = ctx.r28.s64 - ctx.r10.s64;
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x8215a9f0
	ctx.lr = 0x8213643C;
	sub_8215A9F0(ctx, base);
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// std r28,680(r31)
	PPC_STORE_U64(ctx.r31.u32 + 680, ctx.r28.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,9384(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9384);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x82136018
	ctx.lr = 0x82136488;
	sub_82136018(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,120(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// li r29,1
	ctx.r29.s64 = 1;
	// lwz r9,668(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 668);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x821364b4
	if (ctx.cr6.eq) goto loc_821364B4;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// stw r11,668(r31)
	PPC_STORE_U32(ctx.r31.u32 + 668, ctx.r11.u32);
loc_821364B4:
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821364CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r3,22593
	ctx.r3.s64 = 1480654848;
	// li r5,52
	ctx.r5.s64 = 52;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// ori r3,r3,30002
	ctx.r3.u64 = ctx.r3.u64 | 30002;
	// bl 0x8215f690
	ctx.lr = 0x821364E0;
	sub_8215F690(ctx, base);
	// lwsync 
	// stw r30,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
	// stw r29,664(r31)
	PPC_STORE_U32(ctx.r31.u32 + 664, ctx.r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821364F4"))) PPC_WEAK_FUNC(sub_821364F4);
PPC_FUNC_IMPL(__imp__sub_821364F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821364F8"))) PPC_WEAK_FUNC(sub_821364F8);
PPC_FUNC_IMPL(__imp__sub_821364F8) {
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
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// bne cr6,0x82136538
	if (!ctx.cr6.eq) goto loc_82136538;
	// std r9,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, ctx.r9.u64);
	// std r9,8(r4)
	PPC_STORE_U64(ctx.r4.u32 + 8, ctx.r9.u64);
	// std r9,16(r4)
	PPC_STORE_U64(ctx.r4.u32 + 16, ctx.r9.u64);
	// std r9,24(r4)
	PPC_STORE_U64(ctx.r4.u32 + 24, ctx.r9.u64);
	// std r9,32(r4)
	PPC_STORE_U64(ctx.r4.u32 + 32, ctx.r9.u64);
	// b 0x82136610
	goto loc_82136610;
loc_82136538:
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 664);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x821365e0
	if (!ctx.cr6.eq) goto loc_821365E0;
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 660);
	// addi r6,r11,656
	ctx.r6.s64 = ctx.r11.s64 + 656;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// mulli r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 * 40;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r10,576
	ctx.r8.s64 = ctx.r10.s64 + 576;
	// std r9,576(r10)
	PPC_STORE_U64(ctx.r10.u32 + 576, ctx.r9.u64);
	// std r9,584(r10)
	PPC_STORE_U64(ctx.r10.u32 + 584, ctx.r9.u64);
	// std r9,592(r10)
	PPC_STORE_U64(ctx.r10.u32 + 592, ctx.r9.u64);
	// std r9,600(r10)
	PPC_STORE_U64(ctx.r10.u32 + 600, ctx.r9.u64);
	// std r9,608(r10)
	PPC_STORE_U64(ctx.r10.u32 + 608, ctx.r9.u64);
loc_82136570:
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 660);
	// xori r8,r10,1
	ctx.r8.u64 = ctx.r10.u64 ^ 1;
	// mulli r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 * 40;
	// mulli r7,r8,40
	ctx.r7.s64 = ctx.r8.s64 * 40;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + ctx.r11.u64;
	// addi r8,r8,576
	ctx.r8.s64 = ctx.r8.s64 + 576;
	// addi r10,r10,576
	ctx.r10.s64 = ctx.r10.s64 + 576;
loc_82136590:
	// mfmsr r4
	ctx.r4.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r5,0,r6
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r6.u32);
	ctx.r5.u64 = __builtin_bswap32(ctx.reserved.u32);
	// cmpw cr6,r5,r8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x821365b4
	if (!ctx.cr6.eq) goto loc_821365B4;
	// stwcx. r10,0,r6
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r6.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r4,1
	ctx.msr = (ctx.r4.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82136590
	if (!ctx.cr0.eq) goto loc_82136590;
	// b 0x821365bc
	goto loc_821365BC;
loc_821365B4:
	// stwcx. r5,0,r6
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r6.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r5.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r4,1
	ctx.msr = (ctx.r4.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_821365BC:
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lwsync 
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x821365d4
	if (!ctx.cr6.eq) goto loc_821365D4;
	// db16cyc 
	// b 0x82136570
	goto loc_82136570;
loc_821365D4:
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 660);
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// stw r10,660(r11)
	PPC_STORE_U32(ctx.r11.u32 + 660, ctx.r10.u32);
loc_821365E0:
	// lwz r8,660(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 660);
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r7,r31,-8
	ctx.r7.s64 = ctx.r31.s64 + -8;
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// mulli r8,r8,40
	ctx.r8.s64 = ctx.r8.s64 * 40;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 + ctx.r11.u64;
	// addi r10,r10,568
	ctx.r10.s64 = ctx.r10.s64 + 568;
loc_82136600:
	// ldu r8,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdu r8,8(r7)
	ea = 8 + ctx.r7.u32;
	PPC_STORE_U64(ea, ctx.r8.u64);
	ctx.r7.u32 = ea;
	// bdnz 0x82136600
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82136600;
	// stw r9,664(r11)
	PPC_STORE_U32(ctx.r11.u32 + 664, ctx.r9.u32);
loc_82136610:
	// mftb r10
	ctx.r10.u64 = rt_mftb();
	// ld r8,672(r11)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 672);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// subf r9,r8,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r8.s64;
	// addi r3,r7,-5536
	ctx.r3.s64 = ctx.r7.s64 + -5536;
	// std r9,8(r31)
	PPC_STORE_U64(ctx.r31.u32 + 8, ctx.r9.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// std r10,672(r11)
	PPC_STORE_U64(ctx.r11.u32 + 672, ctx.r10.u64);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82136018
	ctx.lr = 0x82136640;
	sub_82136018(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_8213665C"))) PPC_WEAK_FUNC(sub_8213665C);
PPC_FUNC_IMPL(__imp__sub_8213665C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136660"))) PPC_WEAK_FUNC(sub_82136660);
PPC_FUNC_IMPL(__imp__sub_82136660) {
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
	// bge cr6,0x8213669c
	if (!ctx.cr6.lt) goto loc_8213669C;
	// bl 0x821d5474
	ctx.lr = 0x82136690;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x8213669c
	if (ctx.cr6.eq) goto loc_8213669C;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8213669C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821366b0
	if (ctx.cr6.eq) goto loc_821366B0;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82136734
	if (ctx.cr6.eq) goto loc_82136734;
loc_821366B0:
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82136724
	if (ctx.cr6.gt) goto loc_82136724;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,196
	ctx.r4.s64 = 196;
	// bl 0x82108aa8
	ctx.lr = 0x821366E0;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82136734
	if (ctx.cr0.eq) goto loc_82136734;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821366F4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bdnz 0x821366f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821366F4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// b 0x82136734
	goto loc_82136734;
loc_82136724:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,16296
	ctx.r3.s64 = ctx.r11.s64 + 16296;
	// bl 0x8208d988
	ctx.lr = 0x82136730;
	sub_8208D988(ctx, base);
	// twi 31,r0,22
loc_82136734:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8213674c
	if (ctx.cr6.eq) goto loc_8213674C;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82136750
	goto loc_82136750;
loc_8213674C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82136750:
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

__attribute__((alias("__imp__sub_82136768"))) PPC_WEAK_FUNC(sub_82136768);
PPC_FUNC_IMPL(__imp__sub_82136768) {
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
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
loc_82136778:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r10,0,r11
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r11.u32);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r11
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r11.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82136778
	if (!ctx.cr0.eq) goto loc_82136778;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821367ac
	if (!ctx.cr6.eq) goto loc_821367AC;
	// li r11,15
	ctx.r11.s64 = 15;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x82114628
	ctx.lr = 0x821367AC;
	sub_82114628(ctx, base);
loc_821367AC:
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

__attribute__((alias("__imp__sub_821367C0"))) PPC_WEAK_FUNC(sub_821367C0);
PPC_FUNC_IMPL(__imp__sub_821367C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r16,21428(r29)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r29.u32 + 21428);
	// lwz r16,7440(r5)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 7440);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821367D0;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r3,r30,36
	ctx.r3.s64 = ctx.r30.s64 + 36;
	// bl 0x821d53a4
	ctx.lr = 0x821367F0;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r29,r11,14
	ctx.r29.u64 = ctx.r11.u64 | 14;
	// b 0x8213681c
	goto loc_8213681C;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r29,r11,14
	ctx.r29.u64 = ctx.r11.u64 | 14;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r30,148(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// b 0x82136914
	goto loc_82136914;
loc_8213681C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82139528
	ctx.lr = 0x82136828;
	sub_82139528(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r3.u32);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82139528
	ctx.lr = 0x82136848;
	sub_82139528(ctx, base);
	// stw r3,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82139528
	ctx.lr = 0x82136868;
	sub_82139528(ctx, base);
	// stw r3,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82139528
	ctx.lr = 0x82136888;
	sub_82139528(ctx, base);
	// stw r3,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// b 0x82136910
	goto loc_82136910;
loc_821368AC:
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821368d4
	if (ctx.cr6.eq) goto loc_821368D4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368d4
	if (ctx.cr6.eq) goto loc_821368D4;
	// bl 0x82136768
	ctx.lr = 0x821368C8;
	sub_82136768(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r29.u32);
	// b 0x821368d8
	goto loc_821368D8;
loc_821368D4:
	// li r29,0
	ctx.r29.s64 = 0;
loc_821368D8:
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821368f4
	if (ctx.cr6.eq) goto loc_821368F4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368f4
	if (ctx.cr6.eq) goto loc_821368F4;
	// bl 0x82136768
	ctx.lr = 0x821368F0;
	sub_82136768(ctx, base);
	// stw r29,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r29.u32);
loc_821368F4:
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82136910
	if (ctx.cr6.eq) goto loc_82136910;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82136910
	if (ctx.cr6.eq) goto loc_82136910;
	// bl 0x82136768
	ctx.lr = 0x8213690C;
	sub_82136768(ctx, base);
	// stw r29,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r29.u32);
loc_82136910:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_82136914:
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821367C8"))) PPC_WEAK_FUNC(sub_821367C8);
PPC_FUNC_IMPL(__imp__sub_821367C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821367D0;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-128
	ctx.r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r3,r30,36
	ctx.r3.s64 = ctx.r30.s64 + 36;
	// bl 0x821d53a4
	ctx.lr = 0x821367F0;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r29,r11,14
	ctx.r29.u64 = ctx.r11.u64 | 14;
	// b 0x8213681c
	goto loc_8213681C;
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// ori r29,r11,14
	ctx.r29.u64 = ctx.r11.u64 | 14;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r30,148(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// b 0x82136914
	goto loc_82136914;
loc_8213681C:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82139528
	ctx.lr = 0x82136828;
	sub_82139528(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r3.u32);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82139528
	ctx.lr = 0x82136848;
	sub_82139528(ctx, base);
	// stw r3,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82139528
	ctx.lr = 0x82136868;
	sub_82139528(ctx, base);
	// stw r3,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82139528
	ctx.lr = 0x82136888;
	sub_82139528(ctx, base);
	// stw r3,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821368ac
	if (ctx.cr0.eq) goto loc_821368AC;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368ac
	if (ctx.cr6.eq) goto loc_821368AC;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// b 0x82136910
	goto loc_82136910;
loc_821368AC:
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821368d4
	if (ctx.cr6.eq) goto loc_821368D4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368d4
	if (ctx.cr6.eq) goto loc_821368D4;
	// bl 0x82136768
	ctx.lr = 0x821368C8;
	sub_82136768(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r29.u32);
	// b 0x821368d8
	goto loc_821368D8;
loc_821368D4:
	// li r29,0
	ctx.r29.s64 = 0;
loc_821368D8:
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821368f4
	if (ctx.cr6.eq) goto loc_821368F4;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821368f4
	if (ctx.cr6.eq) goto loc_821368F4;
	// bl 0x82136768
	ctx.lr = 0x821368F0;
	sub_82136768(ctx, base);
	// stw r29,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r29.u32);
loc_821368F4:
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82136910
	if (ctx.cr6.eq) goto loc_82136910;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82136910
	if (ctx.cr6.eq) goto loc_82136910;
	// bl 0x82136768
	ctx.lr = 0x8213690C;
	sub_82136768(ctx, base);
	// stw r29,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r29.u32);
loc_82136910:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_82136914:
	// addi r1,r31,128
	ctx.r1.s64 = ctx.r31.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213691C"))) PPC_WEAK_FUNC(sub_8213691C);
PPC_FUNC_IMPL(__imp__sub_8213691C) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-16384
	ctx.r11.s64 = -1073741824;
	// ori r11,r11,23
	ctx.r11.u64 = ctx.r11.u64 | 23;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82136940"))) PPC_WEAK_FUNC(sub_82136940);
PPC_FUNC_IMPL(__imp__sub_82136940) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-19108
	ctx.r11.s64 = ctx.r11.s64 + -19108;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82136990
	if (ctx.cr6.eq) goto loc_82136990;
	// bl 0x821360a8
	ctx.lr = 0x82136970;
	sub_821360A8(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82136768
	ctx.lr = 0x82136978;
	sub_82136768(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82136768
	ctx.lr = 0x82136980;
	sub_82136768(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x82136768
	ctx.lr = 0x82136988;
	sub_82136768(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x82136768
	ctx.lr = 0x82136990;
	sub_82136768(ctx, base);
loc_82136990:
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

__attribute__((alias("__imp__sub_821369A4"))) PPC_WEAK_FUNC(sub_821369A4);
PPC_FUNC_IMPL(__imp__sub_821369A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821369A8"))) PPC_WEAK_FUNC(sub_821369A8);
PPC_FUNC_IMPL(__imp__sub_821369A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821369B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r26,r3,36
	ctx.r26.s64 = ctx.r3.s64 + 36;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
	// bl 0x821d5384
	ctx.lr = 0x821369D4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-32237
	ctx.r11.s64 = -2112684032;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r5,r11,25080
	ctx.r5.s64 = ctx.r11.s64 + 25080;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r27,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// bl 0x82088d88
	ctx.lr = 0x82136A00;
	sub_82088D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// beq 0x82136aa4
	if (ctx.cr0.eq) goto loc_82136AA4;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// beq cr6,0x82136a5c
	if (ctx.cr6.eq) goto loc_82136A5C;
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// beq cr6,0x82136a54
	if (ctx.cr6.eq) goto loc_82136A54;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// beq cr6,0x82136a4c
	if (ctx.cr6.eq) goto loc_82136A4C;
	// cmplwi cr6,r30,8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 8, ctx.xer);
	// beq cr6,0x82136a44
	if (ctx.cr6.eq) goto loc_82136A44;
	// addi r11,r30,-16
	ctx.r11.s64 = ctx.r30.s64 + -16;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// b 0x82136a60
	goto loc_82136A60;
loc_82136A44:
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x82136a60
	goto loc_82136A60;
loc_82136A4C:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82136a60
	goto loc_82136A60;
loc_82136A54:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82136a60
	goto loc_82136A60;
loc_82136A5C:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
loc_82136A60:
	// bl 0x82088b08
	ctx.lr = 0x82136A64;
	sub_82088B08(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x820889f0
	ctx.lr = 0x82136A70;
	sub_820889F0(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82088d48
	ctx.lr = 0x82136A78;
	sub_82088D48(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821d5b24
	ctx.lr = 0x82136A90;
	__imp__KeWaitForSingleObject(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82136ac0
	if (!ctx.cr6.eq) goto loc_82136AC0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82117ed8
	ctx.lr = 0x82136AA0;
	sub_82117ED8(ctx, base);
	// b 0x82136ac0
	goto loc_82136AC0;
loc_82136AA4:
	// bl 0x82089a10
	ctx.lr = 0x82136AA8;
	sub_82089A10(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt 0x82136ab8
	if (ctx.cr0.gt) goto loc_82136AB8;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x82136ac0
	goto loc_82136AC0;
loc_82136AB8:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r27,r11,32775
	ctx.r27.u64 = ctx.r11.u64 | 2147942400;
loc_82136AC0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821d5394
	ctx.lr = 0x82136AC8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82136AD4"))) PPC_WEAK_FUNC(sub_82136AD4);
PPC_FUNC_IMPL(__imp__sub_82136AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136AD8"))) PPC_WEAK_FUNC(sub_82136AD8);
PPC_FUNC_IMPL(__imp__sub_82136AD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82136AE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,36
	ctx.r30.s64 = ctx.r3.s64 + 36;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x821d5384
	ctx.lr = 0x82136AF8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r28,r31,32
	ctx.r28.s64 = ctx.r31.s64 + 32;
	// bl 0x82136768
	ctx.lr = 0x82136B04;
	sub_82136768(ctx, base);
	// addi r10,r29,16
	ctx.r10.s64 = ctx.r29.s64 + 16;
loc_82136B08:
	// mfmsr r9
	ctx.r9.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r10
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r10.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r10
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r10.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82136b08
	if (!ctx.cr0.eq) goto loc_82136B08;
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x82136B30;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82136B38"))) PPC_WEAK_FUNC(sub_82136B38);
PPC_FUNC_IMPL(__imp__sub_82136B38) {
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
	// bl 0x82136940
	ctx.lr = 0x82136B58;
	sub_82136940(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82136b68
	if (ctx.cr0.eq) goto loc_82136B68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82136B68;
	sub_82114628(ctx, base);
loc_82136B68:
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

__attribute__((alias("__imp__sub_82136B84"))) PPC_WEAK_FUNC(sub_82136B84);
PPC_FUNC_IMPL(__imp__sub_82136B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136B88"))) PPC_WEAK_FUNC(sub_82136B88);
PPC_FUNC_IMPL(__imp__sub_82136B88) {
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
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82136BB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82136bc0
	if (ctx.cr0.lt) goto loc_82136BC0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821367c8
	ctx.lr = 0x82136BC0;
	sub_821367C8(ctx, base);
loc_82136BC0:
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

__attribute__((alias("__imp__sub_82136BD4"))) PPC_WEAK_FUNC(sub_82136BD4);
PPC_FUNC_IMPL(__imp__sub_82136BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136BD8"))) PPC_WEAK_FUNC(sub_82136BD8);
PPC_FUNC_IMPL(__imp__sub_82136BD8) {
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
	// lwz r11,556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 556);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// b 0x82136c0c
	goto loc_82136C0C;
loc_82136BFC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82136c14
	if (ctx.cr6.eq) goto loc_82136C14;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_82136C0C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82136bfc
	if (!ctx.cr6.eq) goto loc_82136BFC;
loc_82136C14:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136c28
	if (ctx.cr6.eq) goto loc_82136C28;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r31,352
	ctx.r3.s64 = ctx.r31.s64 + 352;
	// bl 0x82118228
	ctx.lr = 0x82136C28;
	sub_82118228(ctx, base);
loc_82136C28:
	// lwz r11,336(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 336);
	// b 0x82136c40
	goto loc_82136C40;
loc_82136C30:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r30
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82136c48
	if (ctx.cr6.eq) goto loc_82136C48;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_82136C40:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82136c30
	if (!ctx.cr6.eq) goto loc_82136C30;
loc_82136C48:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136c5c
	if (ctx.cr6.eq) goto loc_82136C5C;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r31,132
	ctx.r3.s64 = ctx.r31.s64 + 132;
	// bl 0x82118228
	ctx.lr = 0x82136C5C;
	sub_82118228(ctx, base);
loc_82136C5C:
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

__attribute__((alias("__imp__sub_82136C74"))) PPC_WEAK_FUNC(sub_82136C74);
PPC_FUNC_IMPL(__imp__sub_82136C74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136C78"))) PPC_WEAK_FUNC(sub_82136C78);
PPC_FUNC_IMPL(__imp__sub_82136C78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82136C80;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r5,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r5.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,132(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r27,128(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82136CAC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// beq 0x82136cd4
	if (ctx.cr0.eq) goto loc_82136CD4;
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x82136cd4
	if (ctx.cr6.eq) goto loc_82136CD4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82136ad8
	ctx.lr = 0x82136CC8;
	sub_82136AD8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// b 0x82136cd8
	goto loc_82136CD8;
loc_82136CD4:
	// stw r29,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r29.u32);
loc_82136CD8:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r11.u32);
	// mftb r11
	ctx.r11.u64 = rt_mftb();
	// li r5,80
	ctx.r5.s64 = 80;
	// std r11,672(r31)
	PPC_STORE_U64(ctx.r31.u32 + 672, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,680(r31)
	PPC_STORE_U64(ctx.r31.u32 + 680, ctx.r11.u64);
	// addi r3,r31,576
	ctx.r3.s64 = ctx.r31.s64 + 576;
	// bl 0x8207da20
	ctx.lr = 0x82136D00;
	sub_8207DA20(ctx, base);
	// stw r29,664(r31)
	PPC_STORE_U32(ctx.r31.u32 + 664, ctx.r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821369a8
	ctx.lr = 0x82136D20;
	sub_821369A8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82136d3c
	if (ctx.cr0.lt) goto loc_82136D3C;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82136d40
	if (ctx.cr6.eq) goto loc_82136D40;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// b 0x82136d40
	goto loc_82136D40;
loc_82136D3C:
	// stw r27,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r27.u32);
loc_82136D40:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82136D48"))) PPC_WEAK_FUNC(sub_82136D48);
PPC_FUNC_IMPL(__imp__sub_82136D48) {
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
	// bl 0x82136660
	ctx.lr = 0x82136D68;
	sub_82136660(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82136dac
	if (ctx.cr0.eq) goto loc_82136DAC;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136d98
	if (ctx.cr6.eq) goto loc_82136D98;
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// b 0x82136d9c
	goto loc_82136D9C;
loc_82136D98:
	// stw r3,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
loc_82136D9C:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_82136DAC:
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

__attribute__((alias("__imp__sub_82136DC4"))) PPC_WEAK_FUNC(sub_82136DC4);
PPC_FUNC_IMPL(__imp__sub_82136DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136DC8"))) PPC_WEAK_FUNC(sub_82136DC8);
PPC_FUNC_IMPL(__imp__sub_82136DC8) {
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
	// bl 0x82136660
	ctx.lr = 0x82136DE8;
	sub_82136660(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82136e2c
	if (ctx.cr0.eq) goto loc_82136E2C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136e18
	if (ctx.cr6.eq) goto loc_82136E18;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x82136e1c
	goto loc_82136E1C;
loc_82136E18:
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
loc_82136E1C:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// stw r3,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_82136E2C:
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

__attribute__((alias("__imp__sub_82136E44"))) PPC_WEAK_FUNC(sub_82136E44);
PPC_FUNC_IMPL(__imp__sub_82136E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136E48"))) PPC_WEAK_FUNC(sub_82136E48);
PPC_FUNC_IMPL(__imp__sub_82136E48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82136E50;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82136e74
	if (!ctx.cr6.eq) goto loc_82136E74;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x82136d48
	ctx.lr = 0x82136E70;
	sub_82136D48(ctx, base);
	// b 0x82136eb8
	goto loc_82136EB8;
loc_82136E74:
	// bl 0x82136660
	ctx.lr = 0x82136E78;
	sub_82136660(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82136eb8
	if (ctx.cr0.eq) goto loc_82136EB8;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82136ea4
	if (ctx.cr6.eq) goto loc_82136EA4;
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// b 0x82136ea8
	goto loc_82136EA8;
loc_82136EA4:
	// stw r3,208(r30)
	PPC_STORE_U32(ctx.r30.u32 + 208, ctx.r3.u32);
loc_82136EA8:
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// lwz r11,212(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 212);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r30)
	PPC_STORE_U32(ctx.r30.u32 + 212, ctx.r11.u32);
loc_82136EB8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82136EC0"))) PPC_WEAK_FUNC(sub_82136EC0);
PPC_FUNC_IMPL(__imp__sub_82136EC0) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-19100
	ctx.r11.s64 = ctx.r11.s64 + -19100;
	// addi r10,r10,24644
	ctx.r10.s64 = ctx.r10.s64 + 24644;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r3,r3,132
	ctx.r3.s64 = ctx.r3.s64 + 132;
	// stw r30,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r4,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r4.u32);
	// stw r5,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r5.u32);
	// stw r6,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r6.u32);
	// stw r7,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r7.u32);
	// stw r8,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r8.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// stw r30,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
	// bl 0x82109a40
	ctx.lr = 0x82136F40;
	sub_82109A40(ctx, base);
	// addi r3,r31,352
	ctx.r3.s64 = ctx.r31.s64 + 352;
	// bl 0x82109a40
	ctx.lr = 0x82136F48;
	sub_82109A40(ctx, base);
	// addi r11,r31,576
	ctx.r11.s64 = ctx.r31.s64 + 576;
	// stw r30,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,656(r31)
	PPC_STORE_U32(ctx.r31.u32 + 656, ctx.r11.u32);
	// stw r30,660(r31)
	PPC_STORE_U32(ctx.r31.u32 + 660, ctx.r30.u32);
	// stw r30,664(r31)
	PPC_STORE_U32(ctx.r31.u32 + 664, ctx.r30.u32);
	// stw r30,668(r31)
	PPC_STORE_U32(ctx.r31.u32 + 668, ctx.r30.u32);
	// std r30,672(r31)
	PPC_STORE_U64(ctx.r31.u32 + 672, ctx.r30.u64);
	// std r30,680(r31)
	PPC_STORE_U64(ctx.r31.u32 + 680, ctx.r30.u64);
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

__attribute__((alias("__imp__sub_82136F84"))) PPC_WEAK_FUNC(sub_82136F84);
PPC_FUNC_IMPL(__imp__sub_82136F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82136F88"))) PPC_WEAK_FUNC(sub_82136F88);
PPC_FUNC_IMPL(__imp__sub_82136F88) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r3,r3,352
	ctx.r3.s64 = ctx.r3.s64 + 352;
	// addi r11,r11,-19100
	ctx.r11.s64 = ctx.r11.s64 + -19100;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,556(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 556);
	// b 0x82136fd4
	goto loc_82136FD4;
loc_82136FB8:
	// lwz r11,204(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 204, ctx.r9.u32);
loc_82136FD4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82136fb8
	if (!ctx.cr6.eq) goto loc_82136FB8;
	// stw r11,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r11.u32);
	// addi r31,r30,132
	ctx.r31.s64 = ctx.r30.s64 + 132;
	// stw r11,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, ctx.r11.u32);
	// lwz r10,336(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 336);
	// b 0x8213700c
	goto loc_8213700C;
loc_82136FF0:
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r8.u32);
loc_8213700C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82136ff0
	if (!ctx.cr6.eq) goto loc_82136FF0;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r11.u32);
	// bl 0x82118a58
	ctx.lr = 0x82137020;
	sub_82118A58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82118a58
	ctx.lr = 0x82137028;
	sub_82118A58(ctx, base);
	// addi r3,r30,64
	ctx.r3.s64 = ctx.r30.s64 + 64;
	// bl 0x82108b60
	ctx.lr = 0x82137030;
	sub_82108B60(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82136940
	ctx.lr = 0x82137038;
	sub_82136940(ctx, base);
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

__attribute__((alias("__imp__sub_82137050"))) PPC_WEAK_FUNC(sub_82137050);
PPC_FUNC_IMPL(__imp__sub_82137050) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82137078
	if (!ctx.cr6.eq) goto loc_82137078;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r3,132
	ctx.r3.s64 = ctx.r3.s64 + 132;
	// bl 0x82136d48
	ctx.lr = 0x82137074;
	sub_82136D48(ctx, base);
	// b 0x821370a4
	goto loc_821370A4;
loc_82137078:
	// lwz r11,336(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// b 0x82137090
	goto loc_82137090;
loc_82137080:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82137098
	if (ctx.cr6.eq) goto loc_82137098;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_82137090:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82137080
	if (!ctx.cr6.eq) goto loc_82137080;
loc_82137098:
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// addi r3,r3,132
	ctx.r3.s64 = ctx.r3.s64 + 132;
	// bl 0x82136e48
	ctx.lr = 0x821370A4;
	sub_82136E48(ctx, base);
loc_821370A4:
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r10,r10,14
	ctx.r10.u64 = ctx.r10.u64 | 14;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821370C8"))) PPC_WEAK_FUNC(sub_821370C8);
PPC_FUNC_IMPL(__imp__sub_821370C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821370D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,572(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 572);
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8213719c
	if (!ctx.cr6.eq) goto loc_8213719C;
	// lwz r11,556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 556);
	// addi r29,r3,352
	ctx.r29.s64 = ctx.r3.s64 + 352;
	// b 0x82137114
	goto loc_82137114;
loc_821370F8:
	// lwz r11,204(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 204);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,204(r29)
	PPC_STORE_U32(ctx.r29.u32 + 204, ctx.r9.u32);
loc_82137114:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821370f8
	if (!ctx.cr6.eq) goto loc_821370F8;
	// stw r27,212(r29)
	PPC_STORE_U32(ctx.r29.u32 + 212, ctx.r27.u32);
	// stw r27,208(r29)
	PPC_STORE_U32(ctx.r29.u32 + 208, ctx.r27.u32);
	// lwz r31,336(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 336);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82137204
	if (ctx.cr6.eq) goto loc_82137204;
loc_82137130:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x82137208
	if (ctx.cr6.lt) goto loc_82137208;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82137150
	if (ctx.cr6.eq) goto loc_82137150;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82137154
	goto loc_82137154;
loc_82137150:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
loc_82137154:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137168;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82137190
	if (ctx.cr0.eq) goto loc_82137190;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82136dc8
	ctx.lr = 0x8213717C;
	sub_82136DC8(ctx, base);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r10,r10,14
	ctx.r10.u64 = ctx.r10.u64 | 14;
	// and r26,r11,r10
	ctx.r26.u64 = ctx.r11.u64 & ctx.r10.u64;
loc_82137190:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82137130
	if (!ctx.cr6.eq) goto loc_82137130;
	// b 0x821371fc
	goto loc_821371FC;
loc_8213719C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82137204
	if (!ctx.cr6.eq) goto loc_82137204;
	// lwz r31,556(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 556);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82137204
	if (ctx.cr6.eq) goto loc_82137204;
loc_821371B0:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821371cc
	if (ctx.cr6.eq) goto loc_821371CC;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x821371d0
	goto loc_821371D0;
loc_821371CC:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_821371D0:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821371E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x821371f4
	if (!ctx.cr0.eq) goto loc_821371F4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r28,352
	ctx.r3.s64 = ctx.r28.s64 + 352;
	// bl 0x82118228
	ctx.lr = 0x821371F4;
	sub_82118228(ctx, base);
loc_821371F4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821371b0
	if (!ctx.cr6.eq) goto loc_821371B0;
loc_821371FC:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// blt cr6,0x82137208
	if (ctx.cr6.lt) goto loc_82137208;
loc_82137204:
	// stw r27,572(r28)
	PPC_STORE_U32(ctx.r28.u32 + 572, ctx.r27.u32);
loc_82137208:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137214"))) PPC_WEAK_FUNC(sub_82137214);
PPC_FUNC_IMPL(__imp__sub_82137214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137218"))) PPC_WEAK_FUNC(sub_82137218);
PPC_FUNC_IMPL(__imp__sub_82137218) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82137220;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// addi r28,r3,64
	ctx.r28.s64 = ctx.r3.s64 + 64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137240;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mftb r27
	ctx.r27.u64 = rt_mftb();
	// lwz r3,108(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 108);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137258;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,116(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 116);
	// bl 0x821390b0
	ctx.lr = 0x82137260;
	sub_821390B0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x82137294
	if (ctx.cr0.lt) goto loc_82137294;
	// lwz r11,572(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 572);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82137280
	if (ctx.cr6.eq) goto loc_82137280;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821370c8
	ctx.lr = 0x8213727C;
	sub_821370C8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82137280:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x82137294
	if (ctx.cr6.lt) goto loc_82137294;
	// lwz r3,112(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 112);
	// bl 0x82135aa0
	ctx.lr = 0x82137290;
	sub_82135AA0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82137294:
	// lwz r31,556(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 556);
	// b 0x821372d4
	goto loc_821372D4;
loc_8213729C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x821372f8
	if (ctx.cr6.lt) goto loc_821372F8;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821372bc
	if (ctx.cr6.eq) goto loc_821372BC;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x821372c0
	goto loc_821372C0;
loc_821372BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821372C0:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821372D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_821372D4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8213729c
	if (!ctx.cr6.eq) goto loc_8213729C;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt cr6,0x821372f8
	if (ctx.cr6.lt) goto loc_821372F8;
	// lwz r3,108(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 108);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821372F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821372F8:
	// mftb r11
	ctx.r11.u64 = rt_mftb();
	// li r9,-1
	ctx.r9.s64 = -1;
	// subf r10,r27,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r27.s64;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// cmpld cr6,r10,r9
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r9.u64, ctx.xer);
	// bgt cr6,0x82137320
	if (ctx.cr6.gt) goto loc_82137320;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821362f8
	ctx.lr = 0x82137320;
	sub_821362F8(ctx, base);
loc_82137320:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137334;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137340"))) PPC_WEAK_FUNC(sub_82137340);
PPC_FUNC_IMPL(__imp__sub_82137340) {
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
	// bl 0x82136f88
	ctx.lr = 0x82137360;
	sub_82136F88(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82137370
	if (ctx.cr0.eq) goto loc_82137370;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82137370;
	sub_82114628(ctx, base);
loc_82137370:
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

__attribute__((alias("__imp__sub_8213738C"))) PPC_WEAK_FUNC(sub_8213738C);
PPC_FUNC_IMPL(__imp__sub_8213738C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137390"))) PPC_WEAK_FUNC(sub_82137390);
PPC_FUNC_IMPL(__imp__sub_82137390) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82137398;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,104(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r29,0
	ctx.r29.s64 = 0;
	// rldicl r10,r9,63,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0x7FFFFFFFFFFFFFFF;
	// mulli r11,r11,1000
	ctx.r11.s64 = ctx.r11.s64 * 1000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// tdllei r9,0
	// divdu r11,r11,r9
	ctx.r11.u64 = ppc_divdu(ctx.r11.u64, ctx.r9.u64);
	// rotlwi r28,r11,0
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
loc_821373C4:
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// bl 0x8214e048
	ctx.lr = 0x821373D4;
	sub_8214E048(ctx, base);
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// b 0x821373f4
	goto loc_821373F4;
loc_821373DC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x821373fc
	if (!ctx.cr6.lt) goto loc_821373FC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82137218
	ctx.lr = 0x821373F0;
	sub_82137218(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_821373F4:
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x821373dc
	if (!ctx.cr0.lt) goto loc_821373DC;
loc_821373FC:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8213740c
	if (ctx.cr6.eq) goto loc_8213740C;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_8213740C:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8213742c
	if (ctx.cr6.lt) goto loc_8213742C;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82136138
	ctx.lr = 0x82137420;
	sub_82136138(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x821373c4
	if (!ctx.cr0.eq) goto loc_821373C4;
	// b 0x82137448
	goto loc_82137448;
loc_8213742C:
	// stw r29,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r29.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137448;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82137448:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137450"))) PPC_WEAK_FUNC(sub_82137450);
PPC_FUNC_IMPL(__imp__sub_82137450) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137480;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138718
	ctx.lr = 0x8213748C;
	sub_82138718(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821374A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821374C4"))) PPC_WEAK_FUNC(sub_821374C4);
PPC_FUNC_IMPL(__imp__sub_821374C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821374C8"))) PPC_WEAK_FUNC(sub_821374C8);
PPC_FUNC_IMPL(__imp__sub_821374C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821374D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821374F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821387d0
	ctx.lr = 0x82137504;
	sub_821387D0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137520;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213752C"))) PPC_WEAK_FUNC(sub_8213752C);
PPC_FUNC_IMPL(__imp__sub_8213752C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137530"))) PPC_WEAK_FUNC(sub_82137530);
PPC_FUNC_IMPL(__imp__sub_82137530) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82137538;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137560;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82138890
	ctx.lr = 0x82137578;
	sub_82138890(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137594;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821375A0"))) PPC_WEAK_FUNC(sub_821375A0);
PPC_FUNC_IMPL(__imp__sub_821375A0) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821375D0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821389a0
	ctx.lr = 0x821375E0;
	sub_821389A0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821375FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_82137618"))) PPC_WEAK_FUNC(sub_82137618);
PPC_FUNC_IMPL(__imp__sub_82137618) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821376a0
	sub_821376A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137620"))) PPC_WEAK_FUNC(sub_82137620);
PPC_FUNC_IMPL(__imp__sub_82137620) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82137450
	sub_82137450(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137628"))) PPC_WEAK_FUNC(sub_82137628);
PPC_FUNC_IMPL(__imp__sub_82137628) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82137530
	sub_82137530(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137630"))) PPC_WEAK_FUNC(sub_82137630);
PPC_FUNC_IMPL(__imp__sub_82137630) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821374c8
	sub_821374C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137638"))) PPC_WEAK_FUNC(sub_82137638);
PPC_FUNC_IMPL(__imp__sub_82137638) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821375a0
	sub_821375A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137640"))) PPC_WEAK_FUNC(sub_82137640);
PPC_FUNC_IMPL(__imp__sub_82137640) {
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
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x821385f0
	ctx.lr = 0x82137664;
	sub_821385F0(ctx, base);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// addi r11,r11,-19036
	ctx.r11.s64 = ctx.r11.s64 + -19036;
	// addi r10,r10,-19092
	ctx.r10.s64 = ctx.r10.s64 + -19092;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8213769C"))) PPC_WEAK_FUNC(sub_8213769C);
PPC_FUNC_IMPL(__imp__sub_8213769C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821376A0"))) PPC_WEAK_FUNC(sub_821376A0);
PPC_FUNC_IMPL(__imp__sub_821376A0) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-19092
	ctx.r11.s64 = ctx.r11.s64 + -19092;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x821386a8
	ctx.lr = 0x821376D8;
	sub_821386A8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821376e8
	if (ctx.cr0.eq) goto loc_821376E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x821376E8;
	sub_82114628(ctx, base);
loc_821376E8:
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

__attribute__((alias("__imp__sub_82137704"))) PPC_WEAK_FUNC(sub_82137704);
PPC_FUNC_IMPL(__imp__sub_82137704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137708"))) PPC_WEAK_FUNC(sub_82137708);
PPC_FUNC_IMPL(__imp__sub_82137708) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82137710;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x82108aa8
	ctx.lr = 0x8213774C;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82137770
	if (ctx.cr0.eq) goto loc_82137770;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82137640
	ctx.lr = 0x82137768;
	sub_82137640(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x82137774
	goto loc_82137774;
loc_82137770:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82137774:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82137788
	if (!ctx.cr6.eq) goto loc_82137788;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x821377d8
	goto loc_821377D8;
loc_82137788:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821377AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x821377bc
	if (ctx.cr0.lt) goto loc_821377BC;
	// stw r30,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
	// b 0x821377d8
	goto loc_821377D8;
loc_821377BC:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821377D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x821377D8;
	sub_82114628(ctx, base);
loc_821377D8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821377E4"))) PPC_WEAK_FUNC(sub_821377E4);
PPC_FUNC_IMPL(__imp__sub_821377E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821377E8"))) PPC_WEAK_FUNC(sub_821377E8);
PPC_FUNC_IMPL(__imp__sub_821377E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821377F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// lwz r8,212(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// bl 0x8214e698
	ctx.lr = 0x8213782C;
	sub_8214E698(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82137864
	if (ctx.cr0.lt) goto loc_82137864;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r8,236(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r7,220(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,228(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// bl 0x82137708
	ctx.lr = 0x82137854;
	sub_82137708(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82137864
	if (ctx.cr0.lt) goto loc_82137864;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82137864:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213786C"))) PPC_WEAK_FUNC(sub_8213786C);
PPC_FUNC_IMPL(__imp__sub_8213786C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137870"))) PPC_WEAK_FUNC(sub_82137870);
PPC_FUNC_IMPL(__imp__sub_82137870) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82137878;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821378A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138890
	ctx.lr = 0x821378BC;
	sub_82138890(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821378D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821378E4"))) PPC_WEAK_FUNC(sub_821378E4);
PPC_FUNC_IMPL(__imp__sub_821378E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821378E8"))) PPC_WEAK_FUNC(sub_821378E8);
PPC_FUNC_IMPL(__imp__sub_821378E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821378F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137918;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821384f0
	ctx.lr = 0x8213792C;
	sub_821384F0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137948;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137954"))) PPC_WEAK_FUNC(sub_82137954);
PPC_FUNC_IMPL(__imp__sub_82137954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137958"))) PPC_WEAK_FUNC(sub_82137958);
PPC_FUNC_IMPL(__imp__sub_82137958) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82137960;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137984;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x821389a0
	ctx.lr = 0x82137994;
	sub_821389A0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821379B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821379BC"))) PPC_WEAK_FUNC(sub_821379BC);
PPC_FUNC_IMPL(__imp__sub_821379BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821379C0"))) PPC_WEAK_FUNC(sub_821379C0);
PPC_FUNC_IMPL(__imp__sub_821379C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821379C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821379EC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138a60
	ctx.lr = 0x821379FC;
	sub_82138A60(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137A18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137A24"))) PPC_WEAK_FUNC(sub_82137A24);
PPC_FUNC_IMPL(__imp__sub_82137A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137A28"))) PPC_WEAK_FUNC(sub_82137A28);
PPC_FUNC_IMPL(__imp__sub_82137A28) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137A58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138528
	ctx.lr = 0x82137A64;
	sub_82138528(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137A80;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_82137A9C"))) PPC_WEAK_FUNC(sub_82137A9C);
PPC_FUNC_IMPL(__imp__sub_82137A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137AA0"))) PPC_WEAK_FUNC(sub_82137AA0);
PPC_FUNC_IMPL(__imp__sub_82137AA0) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137AD0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// bl 0x8214ed10
	ctx.lr = 0x82137ADC;
	sub_8214ED10(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137AF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_82137B0C"))) PPC_WEAK_FUNC(sub_82137B0C);
PPC_FUNC_IMPL(__imp__sub_82137B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137B10"))) PPC_WEAK_FUNC(sub_82137B10);
PPC_FUNC_IMPL(__imp__sub_82137B10) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// b 0x821387d0
	sub_821387D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B1C"))) PPC_WEAK_FUNC(sub_82137B1C);
PPC_FUNC_IMPL(__imp__sub_82137B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137B20"))) PPC_WEAK_FUNC(sub_82137B20);
PPC_FUNC_IMPL(__imp__sub_82137B20) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82137a28
	sub_82137A28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B28"))) PPC_WEAK_FUNC(sub_82137B28);
PPC_FUNC_IMPL(__imp__sub_82137B28) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821379c0
	sub_821379C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B30"))) PPC_WEAK_FUNC(sub_82137B30);
PPC_FUNC_IMPL(__imp__sub_82137B30) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82137958
	sub_82137958(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B38"))) PPC_WEAK_FUNC(sub_82137B38);
PPC_FUNC_IMPL(__imp__sub_82137B38) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82137bb8
	sub_82137BB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B40"))) PPC_WEAK_FUNC(sub_82137B40);
PPC_FUNC_IMPL(__imp__sub_82137B40) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821378e8
	sub_821378E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B48"))) PPC_WEAK_FUNC(sub_82137B48);
PPC_FUNC_IMPL(__imp__sub_82137B48) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82137870
	sub_82137870(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137B50"))) PPC_WEAK_FUNC(sub_82137B50);
PPC_FUNC_IMPL(__imp__sub_82137B50) {
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
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82137b74
	if (ctx.cr6.eq) goto loc_82137B74;
	// cmpwi cr6,r4,-2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -2, ctx.xer);
	// bne cr6,0x82137b90
	if (!ctx.cr6.eq) goto loc_82137B90;
loc_82137B74:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82137b98
	if (ctx.cr6.eq) goto loc_82137B98;
	// bl 0x8208da10
	ctx.lr = 0x82137B84;
	sub_8208DA10(ctx, base);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82137b98
	if (ctx.cr6.eq) goto loc_82137B98;
loc_82137B90:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82137b9c
	goto loc_82137B9C;
loc_82137B98:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82137B9C:
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

__attribute__((alias("__imp__sub_82137BB0"))) PPC_WEAK_FUNC(sub_82137BB0);
PPC_FUNC_IMPL(__imp__sub_82137BB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82137BB8"))) PPC_WEAK_FUNC(sub_82137BB8);
PPC_FUNC_IMPL(__imp__sub_82137BB8) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-19008
	ctx.r11.s64 = ctx.r11.s64 + -19008;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x821386a8
	ctx.lr = 0x82137BF0;
	sub_821386A8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82137c00
	if (ctx.cr0.eq) goto loc_82137C00;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82137C00;
	sub_82114628(ctx, base);
loc_82137C00:
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

__attribute__((alias("__imp__sub_82137C1C"))) PPC_WEAK_FUNC(sub_82137C1C);
PPC_FUNC_IMPL(__imp__sub_82137C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137C20"))) PPC_WEAK_FUNC(sub_82137C20);
PPC_FUNC_IMPL(__imp__sub_82137C20) {
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
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x82137cc4
	if (ctx.cr6.lt) goto loc_82137CC4;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// ble cr6,0x82137cb4
	if (!ctx.cr6.gt) goto loc_82137CB4;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x82137ca8
	if (ctx.cr6.eq) goto loc_82137CA8;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x82137c9c
	if (ctx.cr6.eq) goto loc_82137C9C;
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// beq cr6,0x82137c90
	if (ctx.cr6.eq) goto loc_82137C90;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x82137c80
	if (ctx.cr6.eq) goto loc_82137C80;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bne cr6,0x82137cc4
	if (!ctx.cr6.eq) goto loc_82137CC4;
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// bl 0x8214ffd8
	ctx.lr = 0x82137C7C;
	sub_8214FFD8(ctx, base);
	// b 0x82137cc8
	goto loc_82137CC8;
loc_82137C80:
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// bl 0x8214feb8
	ctx.lr = 0x82137C8C;
	sub_8214FEB8(ctx, base);
	// b 0x82137cc8
	goto loc_82137CC8;
loc_82137C90:
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// bl 0x8214ef50
	ctx.lr = 0x82137C98;
	sub_8214EF50(ctx, base);
	// b 0x82137ccc
	goto loc_82137CCC;
loc_82137C9C:
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// bl 0x8214ef18
	ctx.lr = 0x82137CA4;
	sub_8214EF18(ctx, base);
	// b 0x82137ccc
	goto loc_82137CCC;
loc_82137CA8:
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// bl 0x8214f6d0
	ctx.lr = 0x82137CB0;
	sub_8214F6D0(ctx, base);
	// b 0x82137ccc
	goto loc_82137CCC;
loc_82137CB4:
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// bl 0x821500d0
	ctx.lr = 0x82137CC0;
	sub_821500D0(ctx, base);
	// b 0x82137cc8
	goto loc_82137CC8;
loc_82137CC4:
	// bl 0x82138618
	ctx.lr = 0x82137CC8;
	sub_82138618(ctx, base);
loc_82137CC8:
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_82137CCC:
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

__attribute__((alias("__imp__sub_82137CE4"))) PPC_WEAK_FUNC(sub_82137CE4);
PPC_FUNC_IMPL(__imp__sub_82137CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137CE8"))) PPC_WEAK_FUNC(sub_82137CE8);
PPC_FUNC_IMPL(__imp__sub_82137CE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82137CF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x821385f0
	ctx.lr = 0x82137D04;
	sub_821385F0(ctx, base);
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// addi r11,r11,-18952
	ctx.r11.s64 = ctx.r11.s64 + -18952;
	// addi r10,r10,-19008
	ctx.r10.s64 = ctx.r10.s64 + -19008;
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x82137D34;
	sub_8207DA20(ctx, base);
	// addi r29,r31,88
	ctx.r29.s64 = ctx.r31.s64 + 88;
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207da20
	ctx.lr = 0x82137D48;
	sub_8207DA20(ctx, base);
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// stw r29,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137D5C"))) PPC_WEAK_FUNC(sub_82137D5C);
PPC_FUNC_IMPL(__imp__sub_82137D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137D60"))) PPC_WEAK_FUNC(sub_82137D60);
PPC_FUNC_IMPL(__imp__sub_82137D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82137D68;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,-2
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -2, ctx.xer);
	// beq cr6,0x82137d94
	if (ctx.cr6.eq) goto loc_82137D94;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137D94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82137D94:
	// lwz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r25,r11,-5536
	ctx.r25.s64 = ctx.r11.s64 + -5536;
	// bne cr6,0x82137dbc
	if (!ctx.cr6.eq) goto loc_82137DBC;
	// addi r28,r30,28
	ctx.r28.s64 = ctx.r30.s64 + 28;
	// addi r31,r30,68
	ctx.r31.s64 = ctx.r30.s64 + 68;
	// b 0x82137df8
	goto loc_82137DF8;
loc_82137DBC:
	// lwz r11,124(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 124);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82137dd4
	if (!ctx.cr6.eq) goto loc_82137DD4;
	// addi r28,r30,88
	ctx.r28.s64 = ctx.r30.s64 + 88;
	// addi r31,r30,128
	ctx.r31.s64 = ctx.r30.s64 + 128;
	// b 0x82137df8
	goto loc_82137DF8;
loc_82137DD4:
	// bl 0x821d5474
	ctx.lr = 0x82137DD8;
	__imp__KeGetCurrentProcessType(ctx, base);
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x82108aa8
	ctx.lr = 0x82137DF0;
	sub_82108AA8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r26,0
	ctx.r26.s64 = 0;
loc_82137DF8:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82137e0c
	if (!ctx.cr6.eq) goto loc_82137E0C;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x82137efc
	goto loc_82137EFC;
loc_82137E0C:
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207dac0
	ctx.lr = 0x82137E1C;
	sub_8207DAC0(ctx, base);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82137e2c
	if (ctx.cr6.eq) goto loc_82137E2C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,36(r28)
	PPC_STORE_U32(ctx.r28.u32 + 36, ctx.r11.u32);
loc_82137E2C:
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82137b50
	ctx.lr = 0x82137E3C;
	sub_82137B50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82137e54
	if (ctx.cr0.eq) goto loc_82137E54;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,148(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// bl 0x821500d0
	ctx.lr = 0x82137E50;
	sub_821500D0(ctx, base);
	// b 0x82137e84
	goto loc_82137E84;
loc_82137E54:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82137e8c
	if (ctx.cr6.eq) goto loc_82137E8C;
	// addic r11,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r11.s64 = ctx.r27.s64 + -1;
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// subfe r11,r11,r27
	temp.u8 = (~ctx.r11.u32 + ctx.r27.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r27.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x82137E84;
	sub_82138BC0(ctx, base);
loc_82137E84:
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82137efc
	goto loc_82137EFC;
loc_82137E8C:
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x82137EA4;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82137eb8
	if (!ctx.cr0.eq) goto loc_82137EB8;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x82137ef4
	goto loc_82137EF4;
loc_82137EB8:
	// addic r11,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r11.s64 = ctx.r27.s64 + -1;
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// subfe r11,r11,r27
	temp.u8 = (~ctx.r11.u32 + ctx.r27.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r27.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x82137EE4;
	sub_82138BC0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x82137efc
	if (!ctx.cr0.lt) goto loc_82137EFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82137EF4;
	sub_82114628(ctx, base);
loc_82137EF4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82114628
	ctx.lr = 0x82137EFC;
	sub_82114628(ctx, base);
loc_82137EFC:
	// cmpwi cr6,r27,-2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, -2, ctx.xer);
	// beq cr6,0x82137f18
	if (ctx.cr6.eq) goto loc_82137F18;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137F18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82137F18:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82137F24"))) PPC_WEAK_FUNC(sub_82137F24);
PPC_FUNC_IMPL(__imp__sub_82137F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82137F28"))) PPC_WEAK_FUNC(sub_82137F28);
PPC_FUNC_IMPL(__imp__sub_82137F28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82137F30;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137F50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82137f74
	if (!ctx.cr6.eq) goto loc_82137F74;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82137f74
	if (!ctx.cr6.eq) goto loc_82137F74;
	// lwz r3,148(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// bl 0x8214f6d0
	ctx.lr = 0x82137F70;
	sub_8214F6D0(ctx, base);
	// b 0x82137fe0
	goto loc_82137FE0;
loc_82137F74:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82108aa8
	ctx.lr = 0x82137F90;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82137fa4
	if (!ctx.cr0.eq) goto loc_82137FA4;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x82137fe0
	goto loc_82137FE0;
loc_82137FA4:
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// subfe r11,r11,r29
	temp.u8 = (~ctx.r11.u32 + ctx.r29.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x82137FD0;
	sub_82138BC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x82137fe0
	if (!ctx.cr0.lt) goto loc_82137FE0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82137FE0;
	sub_82114628(ctx, base);
loc_82137FE0:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82137FF4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138000"))) PPC_WEAK_FUNC(sub_82138000);
PPC_FUNC_IMPL(__imp__sub_82138000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82138008;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138028;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r27,r29,4
	ctx.r27.s64 = ctx.r29.s64 + 4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// bl 0x82137b50
	ctx.lr = 0x8213803C;
	sub_82137B50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82138050
	if (ctx.cr0.eq) goto loc_82138050;
	// lwz r3,148(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 148);
	// bl 0x8214ef18
	ctx.lr = 0x8213804C;
	sub_8214EF18(ctx, base);
	// b 0x821380b8
	goto loc_821380B8;
loc_82138050:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82108aa8
	ctx.lr = 0x8213806C;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82138080
	if (!ctx.cr0.eq) goto loc_82138080;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x821380b8
	goto loc_821380B8;
loc_82138080:
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// subfe r11,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x821380A8;
	sub_82138BC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x821380b8
	if (!ctx.cr0.lt) goto loc_821380B8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x821380B8;
	sub_82114628(ctx, base);
loc_821380B8:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821380CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821380D8"))) PPC_WEAK_FUNC(sub_821380D8);
PPC_FUNC_IMPL(__imp__sub_821380D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821380E0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821380FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82138118
	if (!ctx.cr6.eq) goto loc_82138118;
	// lwz r3,148(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// bl 0x8214ef50
	ctx.lr = 0x82138114;
	sub_8214EF50(ctx, base);
	// b 0x8213817c
	goto loc_8213817C;
loc_82138118:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82108aa8
	ctx.lr = 0x82138134;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82138148
	if (!ctx.cr0.eq) goto loc_82138148;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8213817c
	goto loc_8213817C;
loc_82138148:
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// addi r10,r30,4
	ctx.r10.s64 = ctx.r30.s64 + 4;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x8213816C;
	sub_82138BC0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x8213817c
	if (!ctx.cr0.lt) goto loc_8213817C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8213817C;
	sub_82114628(ctx, base);
loc_8213817C:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138190;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213819C"))) PPC_WEAK_FUNC(sub_8213819C);
PPC_FUNC_IMPL(__imp__sub_8213819C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821381A0"))) PPC_WEAK_FUNC(sub_821381A0);
PPC_FUNC_IMPL(__imp__sub_821381A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821381A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821381CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821381f4
	if (!ctx.cr6.eq) goto loc_821381F4;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x821381f4
	if (!ctx.cr6.eq) goto loc_821381F4;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,148(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	// bl 0x8214feb8
	ctx.lr = 0x821381EC;
	sub_8214FEB8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82138264
	goto loc_82138264;
loc_821381F4:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x82138210;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82138224
	if (!ctx.cr0.eq) goto loc_82138224;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x82138264
	goto loc_82138264;
loc_82138224:
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r10,10
	ctx.r10.s64 = 10;
	// subfe r11,r11,r29
	temp.u8 = (~ctx.r11.u32 + ctx.r29.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x82138254;
	sub_82138BC0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x82138264
	if (!ctx.cr0.lt) goto loc_82138264;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138264;
	sub_82114628(ctx, base);
loc_82138264:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138278;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138284"))) PPC_WEAK_FUNC(sub_82138284);
PPC_FUNC_IMPL(__imp__sub_82138284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138288"))) PPC_WEAK_FUNC(sub_82138288);
PPC_FUNC_IMPL(__imp__sub_82138288) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82138290;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821382B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x821382CC;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x821382e0
	if (!ctx.cr0.eq) goto loc_821382E0;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x8213831c
	goto loc_8213831C;
loc_821382E0:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,11
	ctx.r10.s64 = 11;
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x82138bc0
	ctx.lr = 0x8213830C;
	sub_82138BC0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge 0x8213831c
	if (!ctx.cr0.lt) goto loc_8213831C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x8213831C;
	sub_82114628(ctx, base);
loc_8213831C:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138330;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213833C"))) PPC_WEAK_FUNC(sub_8213833C);
PPC_FUNC_IMPL(__imp__sub_8213833C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138340"))) PPC_WEAK_FUNC(sub_82138340);
PPC_FUNC_IMPL(__imp__sub_82138340) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82138348;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,152
	ctx.r4.s64 = 152;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x82108aa8
	ctx.lr = 0x82138384;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821383a8
	if (ctx.cr0.eq) goto loc_821383A8;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82137ce8
	ctx.lr = 0x821383A0;
	sub_82137CE8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x821383ac
	goto loc_821383AC;
loc_821383A8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_821383AC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x821383c0
	if (!ctx.cr6.eq) goto loc_821383C0;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82138410
	goto loc_82138410;
loc_821383C0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821383E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x821383f4
	if (ctx.cr0.lt) goto loc_821383F4;
	// stw r30,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
	// b 0x82138410
	goto loc_82138410;
loc_821383F4:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8213840C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x82138410;
	sub_82114628(ctx, base);
loc_82138410:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213841C"))) PPC_WEAK_FUNC(sub_8213841C);
PPC_FUNC_IMPL(__imp__sub_8213841C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138420"))) PPC_WEAK_FUNC(sub_82138420);
PPC_FUNC_IMPL(__imp__sub_82138420) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82138428;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// lwz r8,212(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// bl 0x82150270
	ctx.lr = 0x82138464;
	sub_82150270(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x821384a8
	if (ctx.cr0.lt) goto loc_821384A8;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r8,244(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r7,220(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,236(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// bl 0x82138340
	ctx.lr = 0x8213848C;
	sub_82138340(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x821384a8
	if (ctx.cr0.lt) goto loc_821384A8;
	// lwz r4,228(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8214edc0
	ctx.lr = 0x821384A0;
	sub_8214EDC0(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_821384A8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821384B4"))) PPC_WEAK_FUNC(sub_821384B4);
PPC_FUNC_IMPL(__imp__sub_821384B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821384B8"))) PPC_WEAK_FUNC(sub_821384B8);
PPC_FUNC_IMPL(__imp__sub_821384B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// blt cr6,0x821384e4
	if (ctx.cr6.lt) goto loc_821384E4;
	// beq cr6,0x821384d8
	if (ctx.cr6.eq) goto loc_821384D8;
	// lwz r11,52(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_821384D8:
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
loc_821384E4:
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821384F0"))) PPC_WEAK_FUNC(sub_821384F0);
PPC_FUNC_IMPL(__imp__sub_821384F0) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138510;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_82138524"))) PPC_WEAK_FUNC(sub_82138524);
PPC_FUNC_IMPL(__imp__sub_82138524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138528"))) PPC_WEAK_FUNC(sub_82138528);
PPC_FUNC_IMPL(__imp__sub_82138528) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8213853C"))) PPC_WEAK_FUNC(sub_8213853C);
PPC_FUNC_IMPL(__imp__sub_8213853C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138540"))) PPC_WEAK_FUNC(sub_82138540);
PPC_FUNC_IMPL(__imp__sub_82138540) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138568;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138580;
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

__attribute__((alias("__imp__sub_82138594"))) PPC_WEAK_FUNC(sub_82138594);
PPC_FUNC_IMPL(__imp__sub_82138594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138598"))) PPC_WEAK_FUNC(sub_82138598);
PPC_FUNC_IMPL(__imp__sub_82138598) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821385C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821385DC;
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

__attribute__((alias("__imp__sub_821385F0"))) PPC_WEAK_FUNC(sub_821385F0);
PPC_FUNC_IMPL(__imp__sub_821385F0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// addi r11,r11,-18896
	ctx.r11.s64 = ctx.r11.s64 + -18896;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82138618"))) PPC_WEAK_FUNC(sub_82138618);
PPC_FUNC_IMPL(__imp__sub_82138618) {
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
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82138690
	if (ctx.cr6.lt) goto loc_82138690;
	// beq cr6,0x82138688
	if (ctx.cr6.eq) goto loc_82138688;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82138664
	if (ctx.cr6.lt) goto loc_82138664;
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x82138654
	if (ctx.cr6.eq) goto loc_82138654;
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// b 0x82138658
	goto loc_82138658;
loc_82138654:
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
loc_82138658:
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138660;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82138694
	goto loc_82138694;
loc_82138664:
	// addi r11,r4,16
	ctx.r11.s64 = ctx.r4.s64 + 16;
	// lwz r6,20(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r4,16(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138684;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82138694
	goto loc_82138694;
loc_82138688:
	// bl 0x82138598
	ctx.lr = 0x8213868C;
	sub_82138598(ctx, base);
	// b 0x82138694
	goto loc_82138694;
loc_82138690:
	// bl 0x82138540
	ctx.lr = 0x82138694;
	sub_82138540(ctx, base);
loc_82138694:
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

__attribute__((alias("__imp__sub_821386A8"))) PPC_WEAK_FUNC(sub_821386A8);
PPC_FUNC_IMPL(__imp__sub_821386A8) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-18896
	ctx.r11.s64 = ctx.r11.s64 + -18896;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq cr6,0x821386f8
	if (ctx.cr6.eq) goto loc_821386F8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821386F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x821386F4;
	sub_82114628(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_821386F8:
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_82138714"))) PPC_WEAK_FUNC(sub_82138714);
PPC_FUNC_IMPL(__imp__sub_82138714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138718"))) PPC_WEAK_FUNC(sub_82138718);
PPC_FUNC_IMPL(__imp__sub_82138718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82138720;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8213875c
	if (!ctx.cr6.eq) goto loc_8213875C;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8213875c
	if (!ctx.cr6.eq) goto loc_8213875C;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138758;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x821387c0
	goto loc_821387C0;
loc_8213875C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82108aa8
	ctx.lr = 0x82138778;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8213878c
	if (!ctx.cr0.eq) goto loc_8213878C;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x821387c0
	goto loc_821387C0;
loc_8213878C:
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// subfe r11,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// bl 0x82138bc0
	ctx.lr = 0x821387B0;
	sub_82138BC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x821387c0
	if (!ctx.cr0.lt) goto loc_821387C0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x821387C0;
	sub_82114628(ctx, base);
loc_821387C0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821387CC"))) PPC_WEAK_FUNC(sub_821387CC);
PPC_FUNC_IMPL(__imp__sub_821387CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821387D0"))) PPC_WEAK_FUNC(sub_821387D0);
PPC_FUNC_IMPL(__imp__sub_821387D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821387D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82138818
	if (!ctx.cr6.eq) goto loc_82138818;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82138818
	if (!ctx.cr6.eq) goto loc_82138818;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138814;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82138884
	goto loc_82138884;
loc_82138818:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x82138834;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82138848
	if (!ctx.cr0.eq) goto loc_82138848;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x82138884
	goto loc_82138884;
loc_82138848:
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// subfe r11,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// bl 0x82138bc0
	ctx.lr = 0x82138874;
	sub_82138BC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x82138884
	if (!ctx.cr0.lt) goto loc_82138884;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138884;
	sub_82114628(ctx, base);
loc_82138884:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138890"))) PPC_WEAK_FUNC(sub_82138890);
PPC_FUNC_IMPL(__imp__sub_82138890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82138898;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// li r26,0
	ctx.r26.s64 = 0;
	// bl 0x82137b50
	ctx.lr = 0x821388BC;
	sub_82137B50(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8208da10
	ctx.lr = 0x821388C4;
	sub_8208DA10(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821388e0
	if (!ctx.cr6.eq) goto loc_821388E0;
	// addi r11,r27,-1
	ctx.r11.s64 = ctx.r27.s64 + -1;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
loc_821388E0:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x8213890c
	if (ctx.cr6.eq) goto loc_8213890C;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138908;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82138990
	goto loc_82138990;
loc_8213890C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// addi r4,r28,24
	ctx.r4.s64 = ctx.r28.s64 + 24;
	// bl 0x82108aa8
	ctx.lr = 0x82138928;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8213893c
	if (!ctx.cr0.eq) goto loc_8213893C;
	// lis r26,-32761
	ctx.r26.s64 = -2147024896;
	// ori r26,r26,14
	ctx.r26.u64 = ctx.r26.u64 | 14;
	// b 0x82138990
	goto loc_82138990;
loc_8213893C:
	// addic r11,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// subfe r9,r11,r29
	temp.u8 = (~ctx.r11.u32 + ctx.r29.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x8207dac0
	ctx.lr = 0x82138974;
	sub_8207DAC0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x82138bc0
	ctx.lr = 0x82138980;
	sub_82138BC0(ctx, base);
	// mr. r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge 0x82138990
	if (!ctx.cr0.lt) goto loc_82138990;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138990;
	sub_82114628(ctx, base);
loc_82138990:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213899C"))) PPC_WEAK_FUNC(sub_8213899C);
PPC_FUNC_IMPL(__imp__sub_8213899C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821389A0"))) PPC_WEAK_FUNC(sub_821389A0);
PPC_FUNC_IMPL(__imp__sub_821389A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821389A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// bl 0x82137b50
	ctx.lr = 0x821389C4;
	sub_82137B50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x821389e8
	if (ctx.cr0.eq) goto loc_821389E8;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821389E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82138a54
	goto loc_82138A54;
loc_821389E8:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x82138A04;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82138a18
	if (!ctx.cr0.eq) goto loc_82138A18;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x82138a54
	goto loc_82138A54;
loc_82138A18:
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// subfe r11,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// bl 0x82138bc0
	ctx.lr = 0x82138A44;
	sub_82138BC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x82138a54
	if (!ctx.cr0.lt) goto loc_82138A54;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138A54;
	sub_82114628(ctx, base);
loc_82138A54:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138A60"))) PPC_WEAK_FUNC(sub_82138A60);
PPC_FUNC_IMPL(__imp__sub_82138A60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82138A68;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// bl 0x82137b50
	ctx.lr = 0x82138A84;
	sub_82137B50(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82138aa8
	if (ctx.cr0.eq) goto loc_82138AA8;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138AA4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82138b14
	goto loc_82138B14;
loc_82138AA8:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x82138AC4;
	sub_82108AA8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82138ad8
	if (!ctx.cr0.eq) goto loc_82138AD8;
	// lis r28,-32761
	ctx.r28.s64 = -2147024896;
	// ori r28,r28,14
	ctx.r28.u64 = ctx.r28.u64 | 14;
	// b 0x82138b14
	goto loc_82138B14;
loc_82138AD8:
	// addic r11,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r11.s64 = ctx.r30.s64 + -1;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// subfe r11,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// bl 0x82138bc0
	ctx.lr = 0x82138B04;
	sub_82138BC0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bge 0x82138b14
	if (!ctx.cr0.lt) goto loc_82138B14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138B14;
	sub_82114628(ctx, base);
loc_82138B14:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138B20"))) PPC_WEAK_FUNC(sub_82138B20);
PPC_FUNC_IMPL(__imp__sub_82138B20) {
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
	// bl 0x821386a8
	ctx.lr = 0x82138B40;
	sub_821386A8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82138b50
	if (ctx.cr0.eq) goto loc_82138B50;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138B50;
	sub_82114628(ctx, base);
loc_82138B50:
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

__attribute__((alias("__imp__sub_82138B6C"))) PPC_WEAK_FUNC(sub_82138B6C);
PPC_FUNC_IMPL(__imp__sub_82138B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138B70"))) PPC_WEAK_FUNC(sub_82138B70);
PPC_FUNC_IMPL(__imp__sub_82138B70) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82157850
	ctx.lr = 0x82138B90;
	sub_82157850(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82138ba8
	if (ctx.cr0.lt) goto loc_82138BA8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82138bac
	goto loc_82138BAC;
loc_82138BA8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82138BAC:
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

__attribute__((alias("__imp__sub_82138BC0"))) PPC_WEAK_FUNC(sub_82138BC0);
PPC_FUNC_IMPL(__imp__sub_82138BC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x82157518
	sub_82157518(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138BC8"))) PPC_WEAK_FUNC(sub_82138BC8);
PPC_FUNC_IMPL(__imp__sub_82138BC8) {
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
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82138c08
	if (!ctx.cr6.lt) goto loc_82138C08;
	// bl 0x821d5474
	ctx.lr = 0x82138BFC;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x82138c08
	if (ctx.cr6.eq) goto loc_82138C08;
	// li r30,1
	ctx.r30.s64 = 1;
loc_82138C08:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82138c1c
	if (ctx.cr6.eq) goto loc_82138C1C;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82138ca0
	if (ctx.cr6.eq) goto loc_82138CA0;
loc_82138C1C:
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82138c90
	if (ctx.cr6.gt) goto loc_82138C90;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,196
	ctx.r4.s64 = 196;
	// bl 0x82108aa8
	ctx.lr = 0x82138C4C;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82138ca0
	if (ctx.cr0.eq) goto loc_82138CA0;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82138C60:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// bdnz 0x82138c60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82138C60;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,216(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 216);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// b 0x82138ca0
	goto loc_82138CA0;
loc_82138C90:
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// addi r3,r11,16296
	ctx.r3.s64 = ctx.r11.s64 + 16296;
	// bl 0x8208d988
	ctx.lr = 0x82138C9C;
	sub_8208D988(ctx, base);
	// twi 31,r0,22
loc_82138CA0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82138cb8
	if (ctx.cr6.eq) goto loc_82138CB8;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82138cbc
	goto loc_82138CBC;
loc_82138CB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82138CBC:
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

__attribute__((alias("__imp__sub_82138CD4"))) PPC_WEAK_FUNC(sub_82138CD4);
PPC_FUNC_IMPL(__imp__sub_82138CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138CD8"))) PPC_WEAK_FUNC(sub_82138CD8);
PPC_FUNC_IMPL(__imp__sub_82138CD8) {
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
	// bl 0x82138bc8
	ctx.lr = 0x82138CF8;
	sub_82138BC8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82138d3c
	if (ctx.cr0.eq) goto loc_82138D3C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lwz r11,208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82138d28
	if (ctx.cr6.eq) goto loc_82138D28;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// b 0x82138d2c
	goto loc_82138D2C;
loc_82138D28:
	// stw r3,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r3.u32);
loc_82138D2C:
	// lwz r11,212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 212);
	// stw r3,208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 208, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
loc_82138D3C:
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

__attribute__((alias("__imp__sub_82138D54"))) PPC_WEAK_FUNC(sub_82138D54);
PPC_FUNC_IMPL(__imp__sub_82138D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82138D58"))) PPC_WEAK_FUNC(sub_82138D58);
PPC_FUNC_IMPL(__imp__sub_82138D58) {
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
	// addi r31,r3,8
	ctx.r31.s64 = ctx.r3.s64 + 8;
	// b 0x82138d88
	goto loc_82138D88;
loc_82138D78:
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82138d88
	if (ctx.cr6.eq) goto loc_82138D88;
	// bl 0x82114628
	ctx.lr = 0x82138D88;
	sub_82114628(ctx, base);
loc_82138D88:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8210bb88
	ctx.lr = 0x82138D90;
	sub_8210BB88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82138d78
	if (!ctx.cr0.eq) goto loc_82138D78;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82118a58
	ctx.lr = 0x82138DA0;
	sub_82118A58(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82108248
	ctx.lr = 0x82138DA8;
	sub_82108248(ctx, base);
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

__attribute__((alias("__imp__sub_82138DC0"))) PPC_WEAK_FUNC(sub_82138DC0);
PPC_FUNC_IMPL(__imp__sub_82138DC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82138DC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// b 0x82138dfc
	goto loc_82138DFC;
loc_82138DDC:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82138e34
	if (ctx.cr6.lt) goto loc_82138E34;
	// lwz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82138cd8
	ctx.lr = 0x82138DF4;
	sub_82138CD8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82138e04
	if (ctx.cr0.eq) goto loc_82138E04;
loc_82138DFC:
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82138e20
	goto loc_82138E20;
loc_82138E04:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82138e20
	if (ctx.cr6.eq) goto loc_82138E20;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x82138E20;
	sub_82114628(ctx, base);
loc_82138E20:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82138b70
	ctx.lr = 0x82138E2C;
	sub_82138B70(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82138ddc
	if (!ctx.cr0.eq) goto loc_82138DDC;
loc_82138E34:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138E40"))) PPC_WEAK_FUNC(sub_82138E40);
PPC_FUNC_IMPL(__imp__sub_82138E40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82138E48;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x82138dc0
	ctx.lr = 0x82138E58;
	sub_82138DC0(ctx, base);
	// lwz r30,212(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 212);
	// b 0x82138ec0
	goto loc_82138EC0;
loc_82138E60:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82138e7c
	if (ctx.cr6.eq) goto loc_82138E7C;
	// lwz r30,4(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82138e80
	goto loc_82138E80;
loc_82138E7C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82138E80:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82138ea4
	if (ctx.cr6.eq) goto loc_82138EA4;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82138ec0
	if (!ctx.cr6.eq) goto loc_82138EC0;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82138ec0
	if (!ctx.cr6.eq) goto loc_82138EC0;
loc_82138EA4:
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82118228
	ctx.lr = 0x82138EAC;
	sub_82118228(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82138ec0
	if (ctx.cr6.eq) goto loc_82138EC0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138EC0;
	sub_82114628(ctx, base);
loc_82138EC0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82138e60
	if (!ctx.cr6.eq) goto loc_82138E60;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82138ED0"))) PPC_WEAK_FUNC(sub_82138ED0);
PPC_FUNC_IMPL(__imp__sub_82138ED0) {
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
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82138EFC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82138f14
	if (ctx.cr6.eq) goto loc_82138F14;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x82138F14;
	sub_82114628(ctx, base);
loc_82138F14:
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

__attribute__((alias("__imp__sub_82138F30"))) PPC_WEAK_FUNC(sub_82138F30);
PPC_FUNC_IMPL(__imp__sub_82138F30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82138F38;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,212(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// b 0x82139010
	goto loc_82139010;
loc_82138F4C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,0(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82138f8c
	if (!ctx.cr6.eq) goto loc_82138F8C;
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82118228
	ctx.lr = 0x82138F70;
	sub_82118228(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82138ed0
	ctx.lr = 0x82138F7C;
	sub_82138ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82139010
	if (!ctx.cr0.lt) goto loc_82139010;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x82139010
	goto loc_82139010;
loc_82138F8C:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82139010
	if (!ctx.cr6.eq) goto loc_82139010;
	// lwz r31,212(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 212);
	// lwz r28,4(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x82138ff0
	goto loc_82138FF0;
loc_82138FA0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,0(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82138fc4
	if (ctx.cr6.eq) goto loc_82138FC4;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82138ff0
	if (!ctx.cr6.eq) goto loc_82138FF0;
loc_82138FC4:
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82118228
	ctx.lr = 0x82138FCC;
	sub_82118228(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82138ffc
	if (ctx.cr6.eq) goto loc_82138FFC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82138ed0
	ctx.lr = 0x82138FE4;
	sub_82138ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82138ff0
	if (!ctx.cr0.lt) goto loc_82138FF0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_82138FF0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82138fa0
	if (!ctx.cr6.eq) goto loc_82138FA0;
	// b 0x82139018
	goto loc_82139018;
loc_82138FFC:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82139010
	if (ctx.cr6.eq) goto loc_82139010;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82114628
	ctx.lr = 0x82139010;
	sub_82114628(ctx, base);
loc_82139010:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82138f4c
	if (!ctx.cr6.eq) goto loc_82138F4C;
loc_82139018:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139024"))) PPC_WEAK_FUNC(sub_82139024);
PPC_FUNC_IMPL(__imp__sub_82139024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82139028"))) PPC_WEAK_FUNC(sub_82139028);
PPC_FUNC_IMPL(__imp__sub_82139028) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82139030;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x82138dc0
	ctx.lr = 0x82139040;
	sub_82138DC0(ctx, base);
	// lwz r31,212(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 212);
	// b 0x82139098
	goto loc_82139098;
loc_82139048:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82139064
	if (ctx.cr6.eq) goto loc_82139064;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82139068
	goto loc_82139068;
loc_82139064:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82139068:
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8213907c
	if (ctx.cr6.eq) goto loc_8213907C;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8213909c
	if (!ctx.cr6.eq) goto loc_8213909C;
loc_8213907C:
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82118228
	ctx.lr = 0x82139084;
	sub_82118228(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82138ed0
	ctx.lr = 0x82139090;
	sub_82138ED0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8213909c
	if (!ctx.cr0.lt) goto loc_8213909C;
loc_82139098:
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8213909C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82139048
	if (!ctx.cr6.eq) goto loc_82139048;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821390B0"))) PPC_WEAK_FUNC(sub_821390B0);
PPC_FUNC_IMPL(__imp__sub_821390B0) {
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
	// bl 0x82138dc0
	ctx.lr = 0x821390C8;
	sub_82138DC0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821390d8
	if (ctx.cr0.lt) goto loc_821390D8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82138f30
	ctx.lr = 0x821390D8;
	sub_82138F30(ctx, base);
loc_821390D8:
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

__attribute__((alias("__imp__sub_821390EC"))) PPC_WEAK_FUNC(sub_821390EC);
PPC_FUNC_IMPL(__imp__sub_821390EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821390F0"))) PPC_WEAK_FUNC(sub_821390F0);
PPC_FUNC_IMPL(__imp__sub_821390F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821390F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8213911C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821384f0
	ctx.lr = 0x82139130;
	sub_821384F0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8213914C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139158"))) PPC_WEAK_FUNC(sub_82139158);
PPC_FUNC_IMPL(__imp__sub_82139158) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82139188;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82138a60
	ctx.lr = 0x82139198;
	sub_82138A60(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821391B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821391D0"))) PPC_WEAK_FUNC(sub_821391D0);
PPC_FUNC_IMPL(__imp__sub_821391D0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821391F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82138528
	ctx.lr = 0x82139204;
	sub_82138528(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,20(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82139220;
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

__attribute__((alias("__imp__sub_82139238"))) PPC_WEAK_FUNC(sub_82139238);
PPC_FUNC_IMPL(__imp__sub_82139238) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x8214e0e8
	sub_8214E0E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139240"))) PPC_WEAK_FUNC(sub_82139240);
PPC_FUNC_IMPL(__imp__sub_82139240) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8214e140
	sub_8214E140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213924C"))) PPC_WEAK_FUNC(sub_8213924C);
PPC_FUNC_IMPL(__imp__sub_8213924C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82139250"))) PPC_WEAK_FUNC(sub_82139250);
PPC_FUNC_IMPL(__imp__sub_82139250) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82139260"))) PPC_WEAK_FUNC(sub_82139260);
PPC_FUNC_IMPL(__imp__sub_82139260) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821390f0
	sub_821390F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139268"))) PPC_WEAK_FUNC(sub_82139268);
PPC_FUNC_IMPL(__imp__sub_82139268) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x821391d0
	sub_821391D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139270"))) PPC_WEAK_FUNC(sub_82139270);
PPC_FUNC_IMPL(__imp__sub_82139270) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82139158
	sub_82139158(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139278"))) PPC_WEAK_FUNC(sub_82139278);
PPC_FUNC_IMPL(__imp__sub_82139278) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x820d9438
	sub_820D9438(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139280"))) PPC_WEAK_FUNC(sub_82139280);
PPC_FUNC_IMPL(__imp__sub_82139280) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82139288
	sub_82139288(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139288"))) PPC_WEAK_FUNC(sub_82139288);
PPC_FUNC_IMPL(__imp__sub_82139288) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-18840
	ctx.r11.s64 = ctx.r11.s64 + -18840;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x821386a8
	ctx.lr = 0x821392C0;
	sub_821386A8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x821392d0
	if (ctx.cr0.eq) goto loc_821392D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82114628
	ctx.lr = 0x821392D0;
	sub_82114628(ctx, base);
loc_821392D0:
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

__attribute__((alias("__imp__sub_821392EC"))) PPC_WEAK_FUNC(sub_821392EC);
PPC_FUNC_IMPL(__imp__sub_821392EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821392F0"))) PPC_WEAK_FUNC(sub_821392F0);
PPC_FUNC_IMPL(__imp__sub_821392F0) {
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
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x821385f0
	ctx.lr = 0x82139314;
	sub_821385F0(ctx, base);
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// addi r11,r11,-18784
	ctx.r11.s64 = ctx.r11.s64 + -18784;
	// addi r10,r10,-18840
	ctx.r10.s64 = ctx.r10.s64 + -18840;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8213934C"))) PPC_WEAK_FUNC(sub_8213934C);
PPC_FUNC_IMPL(__imp__sub_8213934C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82139350"))) PPC_WEAK_FUNC(sub_82139350);
PPC_FUNC_IMPL(__imp__sub_82139350) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82139358;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// bl 0x82108aa8
	ctx.lr = 0x82139394;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x821393b8
	if (ctx.cr0.eq) goto loc_821393B8;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x821392f0
	ctx.lr = 0x821393B0;
	sub_821392F0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x821393bc
	goto loc_821393BC;
loc_821393B8:
	// li r30,0
	ctx.r30.s64 = 0;
loc_821393BC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x821393d0
	if (!ctx.cr6.eq) goto loc_821393D0;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82139420
	goto loc_82139420;
loc_821393D0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r30,4
	ctx.r29.s64 = ctx.r30.s64 + 4;
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821393F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82139404
	if (ctx.cr0.lt) goto loc_82139404;
	// stw r30,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r30.u32);
	// b 0x82139420
	goto loc_82139420;
loc_82139404:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8213941C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x82114628
	ctx.lr = 0x82139420;
	sub_82114628(ctx, base);
loc_82139420:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213942C"))) PPC_WEAK_FUNC(sub_8213942C);
PPC_FUNC_IMPL(__imp__sub_8213942C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82139430"))) PPC_WEAK_FUNC(sub_82139430);
PPC_FUNC_IMPL(__imp__sub_82139430) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82139438;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r29,r9
	ctx.r29.u64 = ctx.r9.u64;
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// bl 0x8214e318
	ctx.lr = 0x82139470;
	sub_8214E318(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821394a8
	if (ctx.cr0.lt) goto loc_821394A8;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r8,220(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,212(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82139350
	ctx.lr = 0x82139498;
	sub_82139350(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x821394a8
	if (ctx.cr0.lt) goto loc_821394A8;
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
loc_821394A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821394B0"))) PPC_WEAK_FUNC(sub_821394B0);
PPC_FUNC_IMPL(__imp__sub_821394B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821394B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821394DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82112038
	ctx.lr = 0x821394EC;
	sub_82112038(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82139500;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8213950C"))) PPC_WEAK_FUNC(sub_8213950C);
PPC_FUNC_IMPL(__imp__sub_8213950C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82139510"))) PPC_WEAK_FUNC(sub_82139510);
PPC_FUNC_IMPL(__imp__sub_82139510) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82139524"))) PPC_WEAK_FUNC(sub_82139524);
PPC_FUNC_IMPL(__imp__sub_82139524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82139528"))) PPC_WEAK_FUNC(sub_82139528);
PPC_FUNC_IMPL(__imp__sub_82139528) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,-5536
	ctx.r3.s64 = ctx.r11.s64 + -5536;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82108aa8
	ctx.lr = 0x82139560;
	sub_82108AA8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82139594
	if (ctx.cr0.eq) goto loc_82139594;
	// cntlzw r11,r31
	ctx.r11.u64 = ctx.r31.u32 == 0 ? 32 : __builtin_clz(ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// clrlwi r8,r30,24
	ctx.r8.u64 = ctx.r30.u32 & 0xFF;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// stb r9,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// b 0x82139598
	goto loc_82139598;
loc_82139594:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82139598:
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

__attribute__((alias("__imp__sub_821395B0"))) PPC_WEAK_FUNC(sub_821395B0);
PPC_FUNC_IMPL(__imp__sub_821395B0) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-18756
	ctx.r11.s64 = ctx.r11.s64 + -18756;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x821395dc
	if (ctx.cr0.eq) goto loc_821395DC;
	// bl 0x82114628
	ctx.lr = 0x821395DC;
	sub_82114628(ctx, base);
loc_821395DC:
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

__attribute__((alias("__imp__sub_821395F4"))) PPC_WEAK_FUNC(sub_821395F4);
PPC_FUNC_IMPL(__imp__sub_821395F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821395F8"))) PPC_WEAK_FUNC(sub_821395F8);
PPC_FUNC_IMPL(__imp__sub_821395F8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x82139600
	sub_82139600(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82139600"))) PPC_WEAK_FUNC(sub_82139600);
PPC_FUNC_IMPL(__imp__sub_82139600) {
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
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r11,r11,-18668
	ctx.r11.s64 = ctx.r11.s64 + -18668;
	// addi r10,r10,-18712
	ctx.r10.s64 = ctx.r10.s64 + -18712;
	// addi r9,r9,-18756
	ctx.r9.s64 = ctx.r9.s64 + -18756;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// clrlwi. r8,r4,31
	ctx.r8.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// beq 0x82139648
	if (ctx.cr0.eq) goto loc_82139648;
	// bl 0x82114628
	ctx.lr = 0x82139648;
	sub_82114628(ctx, base);
loc_82139648:
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

__attribute__((alias("__imp__sub_82139660"))) PPC_WEAK_FUNC(sub_82139660);
PPC_FUNC_IMPL(__imp__sub_82139660) {
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
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// bne cr6,0x8213968c
	if (!ctx.cr6.eq) goto loc_8213968C;
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x82112280
	ctx.lr = 0x8213968C;
	sub_82112280(ctx, base);
loc_8213968C:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821d5b04
	ctx.lr = 0x821396A4;
	__imp__KeSetEvent(ctx, base);
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

__attribute__((alias("__imp__sub_821396BC"))) PPC_WEAK_FUNC(sub_821396BC);
PPC_FUNC_IMPL(__imp__sub_821396BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821396C0"))) PPC_WEAK_FUNC(sub_821396C0);
PPC_FUNC_IMPL(__imp__sub_821396C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821396C8;
	__savegprlr_29(ctx, base);
	// ld r12,-4096(r1)
	ctx.r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-8064(r1)
	ea = -8064 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// ld r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 56);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r3,56
	ctx.r30.s64 = ctx.r3.s64 + 56;
	// cmpdi cr6,r11,0
	ctx.cr6.compare<int64_t>(ctx.r11.s64, 0, ctx.xer);
	// ble cr6,0x821396f4
	if (!ctx.cr6.gt) goto loc_821396F4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821d5b04
	ctx.lr = 0x821396F4;
	__imp__KeSetEvent(ctx, base);
loc_821396F4:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r29,r1,96
	ctx.r29.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// li r6,3
	ctx.r6.s64 = 3;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r3,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r3.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// bl 0x821d5b94
	ctx.lr = 0x82139740;
	__imp__KeWaitForMultipleObjects(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// bne cr6,0x821397a4
	if (!ctx.cr6.eq) goto loc_821397A4;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r1,1888
	ctx.r11.s64 = ctx.r1.s64 + 1888;
	// li r8,256
	ctx.r8.s64 = 256;
loc_82139754:
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r7,r11,-1024
	ctx.r7.s64 = ctx.r11.s64 + -1024;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82139760:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stfsu f0,1024(r7)
	temp.f32 = float(ctx.f0.f64);
	ea = 1024 + ctx.r7.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x82139760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82139760;
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bne 0x82139754
	if (!ctx.cr0.eq) goto loc_82139754;
	// addi r4,r1,1888
	ctx.r4.s64 = ctx.r1.s64 + 1888;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x821d5ba4
	ctx.lr = 0x82139788;
	__imp__XAudioSubmitRenderDriverFrame(ctx, base);
loc_82139788:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// ldarx r11,0,r30
	ctx.reserved.u64 = *(uint64_t*)(base + ctx.r30.u32);
	ctx.r11.u64 = __builtin_bswap64(ctx.reserved.u64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stdcx. r11,0,r30
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(base + ctx.r30.u32), ctx.reserved.s64, __builtin_bswap64(ctx.r11.s64));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x82139788
	if (!ctx.cr0.eq) goto loc_82139788;
loc_821397A4:
	// addi r1,r1,8064
	ctx.r1.s64 = ctx.r1.s64 + 8064;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821397AC"))) PPC_WEAK_FUNC(sub_821397AC);
PPC_FUNC_IMPL(__imp__sub_821397AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821397B0"))) PPC_WEAK_FUNC(sub_821397B0);
PPC_FUNC_IMPL(__imp__sub_821397B0) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// bl 0x821d5b04
	ctx.lr = 0x821397D8;
	__imp__KeSetEvent(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821397f0
	if (ctx.cr6.eq) goto loc_821397F0;
	// bl 0x821d5bb4
	ctx.lr = 0x821397EC;
	__imp__XAudioUnregisterRenderDriverClient(ctx, base);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
loc_821397F0:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_82139810"))) PPC_WEAK_FUNC(sub_82139810);
PPC_FUNC_IMPL(__imp__sub_82139810) {
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
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82139874
	if (ctx.cr6.eq) goto loc_82139874;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x82139874
	if (ctx.cr6.eq) goto loc_82139874;
	// addi r9,r3,16
	ctx.r9.s64 = ctx.r3.s64 + 16;
loc_8213983C:
	// mfmsr r10
	ctx.r10.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// lwarx r11,0,r9
	ctx.reserved.u32 = *(uint32_t*)(base + ctx.r9.u32);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r9
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(base + ctx.r9.u32), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8213983c
	if (!ctx.cr0.eq) goto loc_8213983C;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8213986c
	if (!ctx.cr6.eq) goto loc_8213986C;
	// li r11,15
	ctx.r11.s64 = 15;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x82114628
	ctx.lr = 0x8213986C;
	sub_82114628(ctx, base);
loc_8213986C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82139874:
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

