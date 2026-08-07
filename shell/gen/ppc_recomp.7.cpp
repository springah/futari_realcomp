#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_820976FC"))) PPC_WEAK_FUNC(sub_820976FC);
PPC_FUNC_IMPL(__imp__sub_820976FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097700"))) PPC_WEAK_FUNC(sub_82097700);
PPC_FUNC_IMPL(__imp__sub_82097700) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,14,15,17
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 14) & 0x1C000) | (ctx.r11.u64 & 0xFFFFFFFFFFFE3FFF);
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

__attribute__((alias("__imp__sub_8209771C"))) PPC_WEAK_FUNC(sub_8209771C);
PPC_FUNC_IMPL(__imp__sub_8209771C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097720"))) PPC_WEAK_FUNC(sub_82097720);
PPC_FUNC_IMPL(__imp__sub_82097720) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,18,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209772C"))) PPC_WEAK_FUNC(sub_8209772C);
PPC_FUNC_IMPL(__imp__sub_8209772C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097730"))) PPC_WEAK_FUNC(sub_82097730);
PPC_FUNC_IMPL(__imp__sub_82097730) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,20,9,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 20) & 0x700000) | (ctx.r11.u64 & 0xFFFFFFFFFF8FFFFF);
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

__attribute__((alias("__imp__sub_8209774C"))) PPC_WEAK_FUNC(sub_8209774C);
PPC_FUNC_IMPL(__imp__sub_8209774C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097750"))) PPC_WEAK_FUNC(sub_82097750);
PPC_FUNC_IMPL(__imp__sub_82097750) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,12,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209775C"))) PPC_WEAK_FUNC(sub_8209775C);
PPC_FUNC_IMPL(__imp__sub_8209775C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097760"))) PPC_WEAK_FUNC(sub_82097760);
PPC_FUNC_IMPL(__imp__sub_82097760) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,23,6,8
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 23) & 0x3800000) | (ctx.r11.u64 & 0xFFFFFFFFFC7FFFFF);
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

__attribute__((alias("__imp__sub_82097784"))) PPC_WEAK_FUNC(sub_82097784);
PPC_FUNC_IMPL(__imp__sub_82097784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097788"))) PPC_WEAK_FUNC(sub_82097788);
PPC_FUNC_IMPL(__imp__sub_82097788) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,9,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097794"))) PPC_WEAK_FUNC(sub_82097794);
PPC_FUNC_IMPL(__imp__sub_82097794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097798"))) PPC_WEAK_FUNC(sub_82097798);
PPC_FUNC_IMPL(__imp__sub_82097798) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,29,0,2
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 29) & 0xE0000000) | (ctx.r11.u64 & 0xFFFFFFFF1FFFFFFF);
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

__attribute__((alias("__imp__sub_820977BC"))) PPC_WEAK_FUNC(sub_820977BC);
PPC_FUNC_IMPL(__imp__sub_820977BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820977C0"))) PPC_WEAK_FUNC(sub_820977C0);
PPC_FUNC_IMPL(__imp__sub_820977C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,3,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820977CC"))) PPC_WEAK_FUNC(sub_820977CC);
PPC_FUNC_IMPL(__imp__sub_820977CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820977D0"))) PPC_WEAK_FUNC(sub_820977D0);
PPC_FUNC_IMPL(__imp__sub_820977D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,26,3,5
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 26) & 0x1C000000) | (ctx.r11.u64 & 0xFFFFFFFFE3FFFFFF);
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

__attribute__((alias("__imp__sub_820977EC"))) PPC_WEAK_FUNC(sub_820977EC);
PPC_FUNC_IMPL(__imp__sub_820977EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820977F0"))) PPC_WEAK_FUNC(sub_820977F0);
PPC_FUNC_IMPL(__imp__sub_820977F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10548(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,6,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820977FC"))) PPC_WEAK_FUNC(sub_820977FC);
PPC_FUNC_IMPL(__imp__sub_820977FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097800"))) PPC_WEAK_FUNC(sub_82097800);
PPC_FUNC_IMPL(__imp__sub_82097800) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10499(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10499, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097814"))) PPC_WEAK_FUNC(sub_82097814);
PPC_FUNC_IMPL(__imp__sub_82097814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097818"))) PPC_WEAK_FUNC(sub_82097818);
PPC_FUNC_IMPL(__imp__sub_82097818) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10499(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10499);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097820"))) PPC_WEAK_FUNC(sub_82097820);
PPC_FUNC_IMPL(__imp__sub_82097820) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10498(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10498, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097834"))) PPC_WEAK_FUNC(sub_82097834);
PPC_FUNC_IMPL(__imp__sub_82097834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097838"))) PPC_WEAK_FUNC(sub_82097838);
PPC_FUNC_IMPL(__imp__sub_82097838) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10498(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10498);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097840"))) PPC_WEAK_FUNC(sub_82097840);
PPC_FUNC_IMPL(__imp__sub_82097840) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10497(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10497, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 268435456;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097854"))) PPC_WEAK_FUNC(sub_82097854);
PPC_FUNC_IMPL(__imp__sub_82097854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097858"))) PPC_WEAK_FUNC(sub_82097858);
PPC_FUNC_IMPL(__imp__sub_82097858) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10497(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10497);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097860"))) PPC_WEAK_FUNC(sub_82097860);
PPC_FUNC_IMPL(__imp__sub_82097860) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10495(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10495, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097874"))) PPC_WEAK_FUNC(sub_82097874);
PPC_FUNC_IMPL(__imp__sub_82097874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097878"))) PPC_WEAK_FUNC(sub_82097878);
PPC_FUNC_IMPL(__imp__sub_82097878) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10495(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10495);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097880"))) PPC_WEAK_FUNC(sub_82097880);
PPC_FUNC_IMPL(__imp__sub_82097880) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10494(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10494, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097894"))) PPC_WEAK_FUNC(sub_82097894);
PPC_FUNC_IMPL(__imp__sub_82097894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097898"))) PPC_WEAK_FUNC(sub_82097898);
PPC_FUNC_IMPL(__imp__sub_82097898) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10494(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10494);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820978A0"))) PPC_WEAK_FUNC(sub_820978A0);
PPC_FUNC_IMPL(__imp__sub_820978A0) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10493(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10493, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 536870912;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820978B4"))) PPC_WEAK_FUNC(sub_820978B4);
PPC_FUNC_IMPL(__imp__sub_820978B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820978B8"))) PPC_WEAK_FUNC(sub_820978B8);
PPC_FUNC_IMPL(__imp__sub_820978B8) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10493(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10493);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820978C0"))) PPC_WEAK_FUNC(sub_820978C0);
PPC_FUNC_IMPL(__imp__sub_820978C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,10564(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10564);
	// subfic r10,r4,0
	ctx.xer.ca = ctx.r4.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r4.s64;
	// li r9,4096
	ctx.r9.s64 = 4096;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r11,0,0,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFC0;
	// and r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 & ctx.r9.u64;
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// li r12,1
	ctx.r12.s64 = 1;
	// stw r10,10420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10420, ctx.r10.u32);
	// stw r11,10564(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10564, ctx.r11.u32);
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r10,r10,128
	ctx.r10.u64 = ctx.r10.u64 | 128;
	// rldicr r12,r12,44,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// std r10,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r10.u64);
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097904"))) PPC_WEAK_FUNC(sub_82097904);
PPC_FUNC_IMPL(__imp__sub_82097904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097908"))) PPC_WEAK_FUNC(sub_82097908);
PPC_FUNC_IMPL(__imp__sub_82097908) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10564(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10564);
	// clrlwi r3,r11,26
	ctx.r3.u64 = ctx.r11.u32 & 0x3F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097914"))) PPC_WEAK_FUNC(sub_82097914);
PPC_FUNC_IMPL(__imp__sub_82097914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097918"))) PPC_WEAK_FUNC(sub_82097918);
PPC_FUNC_IMPL(__imp__sub_82097918) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12032(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12032);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097920"))) PPC_WEAK_FUNC(sub_82097920);
PPC_FUNC_IMPL(__imp__sub_82097920) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,12884(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12884);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f0,9388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bne cr6,0x82097954
	if (!ctx.cr6.eq) goto loc_82097954;
	// lfs f12,10836(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10836);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// beq cr6,0x82097958
	if (ctx.cr6.eq) goto loc_82097958;
loc_82097954:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82097958:
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// rlwimi r11,r10,11,20,20
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x800) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r11.u32);
	// bne cr6,0x8209797c
	if (!ctx.cr6.eq) goto loc_8209797C;
	// lfs f12,10844(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10844);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// beq cr6,0x82097980
	if (ctx.cr6.eq) goto loc_82097980;
loc_8209797C:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82097980:
	// li r12,1
	ctx.r12.s64 = 1;
	// stfs f13,10832(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10832, temp.u32);
	// rlwimi r11,r10,12,19,19
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 12) & 0x1000) | (ctx.r11.u64 & 0xFFFFFFFFFFFFEFFF);
	// stfs f13,10840(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10840, temp.u32);
	// rldicr r12,r12,45,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 45) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r11.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// li r12,1
	ctx.r12.s64 = 1;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// rldicr r12,r12,43,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 43) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820979C4"))) PPC_WEAK_FUNC(sub_820979C4);
PPC_FUNC_IMPL(__imp__sub_820979C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820979C8"))) PPC_WEAK_FUNC(sub_820979C8);
PPC_FUNC_IMPL(__imp__sub_820979C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,10832(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10832);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12888(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12888);
	ctx.f0.f64 = double(temp.f32);
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

__attribute__((alias("__imp__sub_820979E4"))) PPC_WEAK_FUNC(sub_820979E4);
PPC_FUNC_IMPL(__imp__sub_820979E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820979E8"))) PPC_WEAK_FUNC(sub_820979E8);
PPC_FUNC_IMPL(__imp__sub_820979E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f12,10832(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10832);
	ctx.f12.f64 = double(temp.f32);
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f13,28(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,9388(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 9388);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bne cr6,0x82097a10
	if (!ctx.cr6.eq) goto loc_82097A10;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x82097a14
	if (ctx.cr6.eq) goto loc_82097A14;
loc_82097A10:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82097A14:
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// lfs f12,10840(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10840);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// rlwimi r11,r10,11,20,20
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 11) & 0x800) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r11.u32);
	// bne cr6,0x82097a38
	if (!ctx.cr6.eq) goto loc_82097A38;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x82097a3c
	if (ctx.cr6.eq) goto loc_82097A3C;
loc_82097A38:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82097A3C:
	// li r12,1
	ctx.r12.s64 = 1;
	// stfs f13,10836(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10836, temp.u32);
	// rlwimi r11,r10,12,19,19
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 12) & 0x1000) | (ctx.r11.u64 & 0xFFFFFFFFFFFFEFFF);
	// stfs f13,10844(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10844, temp.u32);
	// rldicr r12,r12,44,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 44) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r11.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// li r12,1
	ctx.r12.s64 = 1;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// rldicr r12,r12,42,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 42) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097A80"))) PPC_WEAK_FUNC(sub_82097A80);
PPC_FUNC_IMPL(__imp__sub_82097A80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,10836(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10836);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097A90"))) PPC_WEAK_FUNC(sub_82097A90);
PPC_FUNC_IMPL(__imp__sub_82097A90) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r11,r4,15,16,16
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 15) & 0x8000) | (ctx.r11.u64 & 0xFFFFFFFFFFFF7FFF);
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

__attribute__((alias("__imp__sub_82097AAC"))) PPC_WEAK_FUNC(sub_82097AAC);
PPC_FUNC_IMPL(__imp__sub_82097AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097AB0"))) PPC_WEAK_FUNC(sub_82097AB0);
PPC_FUNC_IMPL(__imp__sub_82097AB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwinm r3,r11,17,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097ABC"))) PPC_WEAK_FUNC(sub_82097ABC);
PPC_FUNC_IMPL(__imp__sub_82097ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097AC0"))) PPC_WEAK_FUNC(sub_82097AC0);
PPC_FUNC_IMPL(__imp__sub_82097AC0) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r4,16
	ctx.r11.u64 = ctx.r4.u32 & 0xFFFF;
	// stw r11,10752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10752, ctx.r11.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// oris r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 524288;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097AD8"))) PPC_WEAK_FUNC(sub_82097AD8);
PPC_FUNC_IMPL(__imp__sub_82097AD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10752(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10752);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097AE0"))) PPC_WEAK_FUNC(sub_82097AE0);
PPC_FUNC_IMPL(__imp__sub_82097AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12616(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12616);
	// li r12,1
	ctx.r12.s64 = 1;
	// lwz r9,10460(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// stw r4,12036(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12036, ctx.r4.u32);
	// rldicr r12,r12,37,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r11,r9,0,0,27
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFFFF0) | (ctx.r11.u64 & 0xFFFFFFFF0000000F);
	// stw r11,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097B18"))) PPC_WEAK_FUNC(sub_82097B18);
PPC_FUNC_IMPL(__imp__sub_82097B18) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12036(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12036);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097B20"))) PPC_WEAK_FUNC(sub_82097B20);
PPC_FUNC_IMPL(__imp__sub_82097B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12620(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12620);
	// li r12,1
	ctx.r12.s64 = 1;
	// lwz r9,10460(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// stw r4,12040(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12040, ctx.r4.u32);
	// rldicr r12,r12,37,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r9,r11,4,24,27
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 4) & 0xF0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFF0F);
	// stw r9,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, ctx.r9.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097B58"))) PPC_WEAK_FUNC(sub_82097B58);
PPC_FUNC_IMPL(__imp__sub_82097B58) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12040(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12040);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097B60"))) PPC_WEAK_FUNC(sub_82097B60);
PPC_FUNC_IMPL(__imp__sub_82097B60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12624(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12624);
	// li r12,1
	ctx.r12.s64 = 1;
	// lwz r9,10460(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// stw r4,12044(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12044, ctx.r4.u32);
	// rldicr r12,r12,37,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r9,r11,8,20,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFF0FF);
	// stw r9,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, ctx.r9.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097B98"))) PPC_WEAK_FUNC(sub_82097B98);
PPC_FUNC_IMPL(__imp__sub_82097B98) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12044(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12044);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097BA0"))) PPC_WEAK_FUNC(sub_82097BA0);
PPC_FUNC_IMPL(__imp__sub_82097BA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,12628(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12628);
	// li r12,1
	ctx.r12.s64 = 1;
	// lwz r9,10460(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10460);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// stw r4,12048(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12048, ctx.r4.u32);
	// rldicr r12,r12,37,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 & ctx.r4.u64;
	// rlwimi r9,r11,12,16,19
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 12) & 0xF000) | (ctx.r9.u64 & 0xFFFFFFFFFFFF0FFF);
	// stw r9,10460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10460, ctx.r9.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097BD8"))) PPC_WEAK_FUNC(sub_82097BD8);
PPC_FUNC_IMPL(__imp__sub_82097BD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12048(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12048);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097BE0"))) PPC_WEAK_FUNC(sub_82097BE0);
PPC_FUNC_IMPL(__imp__sub_82097BE0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,12060(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12060, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097BE8"))) PPC_WEAK_FUNC(sub_82097BE8);
PPC_FUNC_IMPL(__imp__sub_82097BE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12060(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12060);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097BF0"))) PPC_WEAK_FUNC(sub_82097BF0);
PPC_FUNC_IMPL(__imp__sub_82097BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// li r12,1
	ctx.r12.s64 = 1;
	// stfs f0,12068(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12068, temp.u32);
	// lfs f13,12864(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12864);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,54,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// sth r11,10598(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10598, ctx.r11.u16);
	// sth r11,10596(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10596, ctx.r11.u16);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097C38"))) PPC_WEAK_FUNC(sub_82097C38);
PPC_FUNC_IMPL(__imp__sub_82097C38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,12068(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12068);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097C48"))) PPC_WEAK_FUNC(sub_82097C48);
PPC_FUNC_IMPL(__imp__sub_82097C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// li r12,1
	ctx.r12.s64 = 1;
	// stfs f0,12072(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12072, temp.u32);
	// lfs f13,12884(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12884);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,53,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 53) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10602(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10602, ctx.r11.u16);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097C88"))) PPC_WEAK_FUNC(sub_82097C88);
PPC_FUNC_IMPL(__imp__sub_82097C88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,12072(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12072);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097C98"))) PPC_WEAK_FUNC(sub_82097C98);
PPC_FUNC_IMPL(__imp__sub_82097C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// li r12,1
	ctx.r12.s64 = 1;
	// stfs f0,12076(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12076, temp.u32);
	// lfs f13,12884(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12884);
	ctx.f13.f64 = double(temp.f32);
	// rldicr r12,r12,53,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 53) & 0xFFFFFFFFFFFFFFFF;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r11,-12(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10600(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10600, ctx.r11.u16);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097CD8"))) PPC_WEAK_FUNC(sub_82097CD8);
PPC_FUNC_IMPL(__imp__sub_82097CD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,12076(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12076);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097CE8"))) PPC_WEAK_FUNC(sub_82097CE8);
PPC_FUNC_IMPL(__imp__sub_82097CE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r11,r11,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097D08"))) PPC_WEAK_FUNC(sub_82097D08);
PPC_FUNC_IMPL(__imp__sub_82097D08) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,0,28,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097D2C"))) PPC_WEAK_FUNC(sub_82097D2C);
PPC_FUNC_IMPL(__imp__sub_82097D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097D30"))) PPC_WEAK_FUNC(sub_82097D30);
PPC_FUNC_IMPL(__imp__sub_82097D30) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r11,0,24,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF0FF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097D54"))) PPC_WEAK_FUNC(sub_82097D54);
PPC_FUNC_IMPL(__imp__sub_82097D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097D58"))) PPC_WEAK_FUNC(sub_82097D58);
PPC_FUNC_IMPL(__imp__sub_82097D58) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFFFF000;
	// rlwinm r11,r11,0,20,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF0FFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097D7C"))) PPC_WEAK_FUNC(sub_82097D7C);
PPC_FUNC_IMPL(__imp__sub_82097D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097D80"))) PPC_WEAK_FUNC(sub_82097D80);
PPC_FUNC_IMPL(__imp__sub_82097D80) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,0,16,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097DA4"))) PPC_WEAK_FUNC(sub_82097DA4);
PPC_FUNC_IMPL(__imp__sub_82097DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097DA8"))) PPC_WEAK_FUNC(sub_82097DA8);
PPC_FUNC_IMPL(__imp__sub_82097DA8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,20,0,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0xFFF00000;
	// rlwinm r11,r11,0,12,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF0FFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097DCC"))) PPC_WEAK_FUNC(sub_82097DCC);
PPC_FUNC_IMPL(__imp__sub_82097DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097DD0"))) PPC_WEAK_FUNC(sub_82097DD0);
PPC_FUNC_IMPL(__imp__sub_82097DD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r10,r4,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF000000;
	// rlwinm r11,r11,0,8,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF0FFFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097DF4"))) PPC_WEAK_FUNC(sub_82097DF4);
PPC_FUNC_IMPL(__imp__sub_82097DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097DF8"))) PPC_WEAK_FUNC(sub_82097DF8);
PPC_FUNC_IMPL(__imp__sub_82097DF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwimi r11,r4,28,0,3
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 28) & 0xF0000000) | (ctx.r11.u64 & 0xFFFFFFFF0FFFFFFF);
	// stw r11,10540(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10540, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,8192
	ctx.r11.u64 = ctx.r11.u64 | 8192;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097E14"))) PPC_WEAK_FUNC(sub_82097E14);
PPC_FUNC_IMPL(__imp__sub_82097E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097E18"))) PPC_WEAK_FUNC(sub_82097E18);
PPC_FUNC_IMPL(__imp__sub_82097E18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r11,r11,0,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// or r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 | ctx.r4.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097E38"))) PPC_WEAK_FUNC(sub_82097E38);
PPC_FUNC_IMPL(__imp__sub_82097E38) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,0,28,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097E5C"))) PPC_WEAK_FUNC(sub_82097E5C);
PPC_FUNC_IMPL(__imp__sub_82097E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097E60"))) PPC_WEAK_FUNC(sub_82097E60);
PPC_FUNC_IMPL(__imp__sub_82097E60) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r11,r11,0,24,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF0FF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097E84"))) PPC_WEAK_FUNC(sub_82097E84);
PPC_FUNC_IMPL(__imp__sub_82097E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097E88"))) PPC_WEAK_FUNC(sub_82097E88);
PPC_FUNC_IMPL(__imp__sub_82097E88) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFFFF000;
	// rlwinm r11,r11,0,20,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFF0FFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097EAC"))) PPC_WEAK_FUNC(sub_82097EAC);
PPC_FUNC_IMPL(__imp__sub_82097EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097EB0"))) PPC_WEAK_FUNC(sub_82097EB0);
PPC_FUNC_IMPL(__imp__sub_82097EB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r11,r11,0,16,11
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFF0FFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097ED4"))) PPC_WEAK_FUNC(sub_82097ED4);
PPC_FUNC_IMPL(__imp__sub_82097ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097ED8"))) PPC_WEAK_FUNC(sub_82097ED8);
PPC_FUNC_IMPL(__imp__sub_82097ED8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,20,0,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0xFFF00000;
	// rlwinm r11,r11,0,12,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF0FFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097EFC"))) PPC_WEAK_FUNC(sub_82097EFC);
PPC_FUNC_IMPL(__imp__sub_82097EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F00"))) PPC_WEAK_FUNC(sub_82097F00);
PPC_FUNC_IMPL(__imp__sub_82097F00) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,24,0,7
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF000000;
	// rlwinm r11,r11,0,8,3
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFF0FFFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F24"))) PPC_WEAK_FUNC(sub_82097F24);
PPC_FUNC_IMPL(__imp__sub_82097F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F28"))) PPC_WEAK_FUNC(sub_82097F28);
PPC_FUNC_IMPL(__imp__sub_82097F28) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwimi r11,r4,28,0,3
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 28) & 0xF0000000) | (ctx.r11.u64 & 0xFFFFFFFF0FFFFFFF);
	// stw r11,10544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F44"))) PPC_WEAK_FUNC(sub_82097F44);
PPC_FUNC_IMPL(__imp__sub_82097F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F48"))) PPC_WEAK_FUNC(sub_82097F48);
PPC_FUNC_IMPL(__imp__sub_82097F48) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F54"))) PPC_WEAK_FUNC(sub_82097F54);
PPC_FUNC_IMPL(__imp__sub_82097F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F58"))) PPC_WEAK_FUNC(sub_82097F58);
PPC_FUNC_IMPL(__imp__sub_82097F58) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,28,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F64"))) PPC_WEAK_FUNC(sub_82097F64);
PPC_FUNC_IMPL(__imp__sub_82097F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F68"))) PPC_WEAK_FUNC(sub_82097F68);
PPC_FUNC_IMPL(__imp__sub_82097F68) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,24,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F74"))) PPC_WEAK_FUNC(sub_82097F74);
PPC_FUNC_IMPL(__imp__sub_82097F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F78"))) PPC_WEAK_FUNC(sub_82097F78);
PPC_FUNC_IMPL(__imp__sub_82097F78) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,20,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F84"))) PPC_WEAK_FUNC(sub_82097F84);
PPC_FUNC_IMPL(__imp__sub_82097F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F88"))) PPC_WEAK_FUNC(sub_82097F88);
PPC_FUNC_IMPL(__imp__sub_82097F88) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097F94"))) PPC_WEAK_FUNC(sub_82097F94);
PPC_FUNC_IMPL(__imp__sub_82097F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097F98"))) PPC_WEAK_FUNC(sub_82097F98);
PPC_FUNC_IMPL(__imp__sub_82097F98) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,12,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097FA4"))) PPC_WEAK_FUNC(sub_82097FA4);
PPC_FUNC_IMPL(__imp__sub_82097FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097FA8"))) PPC_WEAK_FUNC(sub_82097FA8);
PPC_FUNC_IMPL(__imp__sub_82097FA8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10540);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097FB4"))) PPC_WEAK_FUNC(sub_82097FB4);
PPC_FUNC_IMPL(__imp__sub_82097FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097FB8"))) PPC_WEAK_FUNC(sub_82097FB8);
PPC_FUNC_IMPL(__imp__sub_82097FB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10540(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10540);
	// rlwinm r3,r11,4,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097FC4"))) PPC_WEAK_FUNC(sub_82097FC4);
PPC_FUNC_IMPL(__imp__sub_82097FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097FC8"))) PPC_WEAK_FUNC(sub_82097FC8);
PPC_FUNC_IMPL(__imp__sub_82097FC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097FD4"))) PPC_WEAK_FUNC(sub_82097FD4);
PPC_FUNC_IMPL(__imp__sub_82097FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097FD8"))) PPC_WEAK_FUNC(sub_82097FD8);
PPC_FUNC_IMPL(__imp__sub_82097FD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,28,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097FE4"))) PPC_WEAK_FUNC(sub_82097FE4);
PPC_FUNC_IMPL(__imp__sub_82097FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097FE8"))) PPC_WEAK_FUNC(sub_82097FE8);
PPC_FUNC_IMPL(__imp__sub_82097FE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,24,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82097FF4"))) PPC_WEAK_FUNC(sub_82097FF4);
PPC_FUNC_IMPL(__imp__sub_82097FF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82097FF8"))) PPC_WEAK_FUNC(sub_82097FF8);
PPC_FUNC_IMPL(__imp__sub_82097FF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,20,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098004"))) PPC_WEAK_FUNC(sub_82098004);
PPC_FUNC_IMPL(__imp__sub_82098004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098008"))) PPC_WEAK_FUNC(sub_82098008);
PPC_FUNC_IMPL(__imp__sub_82098008) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098014"))) PPC_WEAK_FUNC(sub_82098014);
PPC_FUNC_IMPL(__imp__sub_82098014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098018"))) PPC_WEAK_FUNC(sub_82098018);
PPC_FUNC_IMPL(__imp__sub_82098018) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,12,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098024"))) PPC_WEAK_FUNC(sub_82098024);
PPC_FUNC_IMPL(__imp__sub_82098024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098028"))) PPC_WEAK_FUNC(sub_82098028);
PPC_FUNC_IMPL(__imp__sub_82098028) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10544);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098034"))) PPC_WEAK_FUNC(sub_82098034);
PPC_FUNC_IMPL(__imp__sub_82098034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098038"))) PPC_WEAK_FUNC(sub_82098038);
PPC_FUNC_IMPL(__imp__sub_82098038) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r3,r11,4,28,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098044"))) PPC_WEAK_FUNC(sub_82098044);
PPC_FUNC_IMPL(__imp__sub_82098044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098048"))) PPC_WEAK_FUNC(sub_82098048);
PPC_FUNC_IMPL(__imp__sub_82098048) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// li r11,1087
	ctx.r11.s64 = 1087;
	// bne cr6,0x82098058
	if (!ctx.cr6.eq) goto loc_82098058;
	// li r11,1024
	ctx.r11.s64 = 1024;
loc_82098058:
	// stw r11,10572(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10572, ctx.r11.u32);
	// cntlzw r11,r4
	ctx.r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lwz r10,10564(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10564);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// rlwimi r10,r11,16,15,15
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 16) & 0x10000) | (ctx.r10.u64 & 0xFFFFFFFFFFFEFFFF);
	// stw r10,10564(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10564, ctx.r10.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098088"))) PPC_WEAK_FUNC(sub_82098088);
PPC_FUNC_IMPL(__imp__sub_82098088) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10572(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10572);
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098094"))) PPC_WEAK_FUNC(sub_82098094);
PPC_FUNC_IMPL(__imp__sub_82098094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098098"))) PPC_WEAK_FUNC(sub_82098098);
PPC_FUNC_IMPL(__imp__sub_82098098) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12616(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12616);
	// stw r4,12204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12204, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r8,10372(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10372);
	// rlwinm r11,r8,16,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x820980d0
	if (ctx.cr6.eq) goto loc_820980D0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x820980d0
	if (ctx.cr6.eq) goto loc_820980D0;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x820980d0
	if (ctx.cr6.eq) goto loc_820980D0;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_820980D0:
	// rlwinm r10,r8,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0x1;
	// xor. r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm r9,r11,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// not r7,r10
	ctx.r7.u64 = ~ctx.r10.u64;
	// addi r9,r9,-3
	ctx.r9.s64 = ctx.r9.s64 + -3;
	// rlwinm r11,r11,17,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// li r12,1
	ctx.r12.s64 = 1;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// rldicr r12,r12,56,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// rlwimi r11,r8,0,16,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFFFFFFFFF0FFFF) | (ctx.r11.u64 & 0xF0000);
	// stw r11,10372(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10372, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098128"))) PPC_WEAK_FUNC(sub_82098128);
PPC_FUNC_IMPL(__imp__sub_82098128) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12204(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12204);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098130"))) PPC_WEAK_FUNC(sub_82098130);
PPC_FUNC_IMPL(__imp__sub_82098130) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12620(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12620);
	// stw r4,12208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12208, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r8,10380(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10380);
	// rlwinm r11,r8,16,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82098168
	if (ctx.cr6.eq) goto loc_82098168;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82098168
	if (ctx.cr6.eq) goto loc_82098168;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x82098168
	if (ctx.cr6.eq) goto loc_82098168;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82098168:
	// rlwinm r10,r8,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0x1;
	// xor. r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm r9,r11,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// not r7,r10
	ctx.r7.u64 = ~ctx.r10.u64;
	// addi r9,r9,-3
	ctx.r9.s64 = ctx.r9.s64 + -3;
	// rlwinm r11,r11,17,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// li r12,1
	ctx.r12.s64 = 1;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// rldicr r12,r12,54,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 54) & 0xFFFFFFFFFFFFFFFF;
	// rlwimi r11,r8,0,16,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFFFFFFFFF0FFFF) | (ctx.r11.u64 & 0xF0000);
	// stw r11,10380(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10380, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820981C0"))) PPC_WEAK_FUNC(sub_820981C0);
PPC_FUNC_IMPL(__imp__sub_820981C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12208);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820981C8"))) PPC_WEAK_FUNC(sub_820981C8);
PPC_FUNC_IMPL(__imp__sub_820981C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12624(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12624);
	// stw r4,12212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12212, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r8,10384(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10384);
	// rlwinm r11,r8,16,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82098200
	if (ctx.cr6.eq) goto loc_82098200;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82098200
	if (ctx.cr6.eq) goto loc_82098200;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x82098200
	if (ctx.cr6.eq) goto loc_82098200;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82098200:
	// rlwinm r10,r8,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0x1;
	// xor. r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm r9,r11,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// not r7,r10
	ctx.r7.u64 = ~ctx.r10.u64;
	// addi r9,r9,-3
	ctx.r9.s64 = ctx.r9.s64 + -3;
	// rlwinm r11,r11,17,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// li r12,1
	ctx.r12.s64 = 1;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// rldicr r12,r12,53,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 53) & 0xFFFFFFFFFFFFFFFF;
	// rlwimi r11,r8,0,16,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFFFFFFFFF0FFFF) | (ctx.r11.u64 & 0xF0000);
	// stw r11,10384(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10384, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098258"))) PPC_WEAK_FUNC(sub_82098258);
PPC_FUNC_IMPL(__imp__sub_82098258) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12212(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12212);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098260"))) PPC_WEAK_FUNC(sub_82098260);
PPC_FUNC_IMPL(__imp__sub_82098260) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12628(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12628);
	// stw r4,12216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12216, ctx.r4.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r8,10388(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10388);
	// rlwinm r11,r8,16,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xF;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x82098298
	if (ctx.cr6.eq) goto loc_82098298;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82098298
	if (ctx.cr6.eq) goto loc_82098298;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// beq cr6,0x82098298
	if (ctx.cr6.eq) goto loc_82098298;
	// cmplwi cr6,r11,12
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 12, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_82098298:
	// rlwinm r10,r8,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0x1;
	// xor. r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// rlwinm r9,r11,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addi r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 3;
	// not r7,r10
	ctx.r7.u64 = ~ctx.r10.u64;
	// addi r9,r9,-3
	ctx.r9.s64 = ctx.r9.s64 + -3;
	// rlwinm r11,r11,17,0,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// and r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 & ctx.r10.u64;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// li r12,1
	ctx.r12.s64 = 1;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// rldicr r12,r12,52,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 52) & 0xFFFFFFFFFFFFFFFF;
	// rlwimi r11,r8,0,16,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFFFFFFFFFF0FFFF) | (ctx.r11.u64 & 0xF0000);
	// stw r11,10388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10388, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820982F0"))) PPC_WEAK_FUNC(sub_820982F0);
PPC_FUNC_IMPL(__imp__sub_820982F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12216(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12216);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820982F8"))) PPC_WEAK_FUNC(sub_820982F8);
PPC_FUNC_IMPL(__imp__sub_820982F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10624(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10624, temp.u32);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// rldicr r12,r12,47,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 47) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209831C"))) PPC_WEAK_FUNC(sub_8209831C);
PPC_FUNC_IMPL(__imp__sub_8209831C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098320"))) PPC_WEAK_FUNC(sub_82098320);
PPC_FUNC_IMPL(__imp__sub_82098320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,10624(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10624);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098330"))) PPC_WEAK_FUNC(sub_82098330);
PPC_FUNC_IMPL(__imp__sub_82098330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10620(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10620, temp.u32);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// rldicr r12,r12,48,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 48) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098354"))) PPC_WEAK_FUNC(sub_82098354);
PPC_FUNC_IMPL(__imp__sub_82098354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098358"))) PPC_WEAK_FUNC(sub_82098358);
PPC_FUNC_IMPL(__imp__sub_82098358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,10620(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10620);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098368"))) PPC_WEAK_FUNC(sub_82098368);
PPC_FUNC_IMPL(__imp__sub_82098368) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10616(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10616);
	// li r12,1
	ctx.r12.s64 = 1;
	// rlwimi r4,r11,0,0,29
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0xFFFFFFFC) | (ctx.r4.u64 & 0xFFFFFFFF00000003);
	// rldicr r12,r12,49,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 49) & 0xFFFFFFFFFFFFFFFF;
	// stw r4,10616(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10616, ctx.r4.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209838C"))) PPC_WEAK_FUNC(sub_8209838C);
PPC_FUNC_IMPL(__imp__sub_8209838C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098390"))) PPC_WEAK_FUNC(sub_82098390);
PPC_FUNC_IMPL(__imp__sub_82098390) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10616(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10616);
	// clrlwi r3,r11,30
	ctx.r3.u64 = ctx.r11.u32 & 0x3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209839C"))) PPC_WEAK_FUNC(sub_8209839C);
PPC_FUNC_IMPL(__imp__sub_8209839C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820983A0"))) PPC_WEAK_FUNC(sub_820983A0);
PPC_FUNC_IMPL(__imp__sub_820983A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10688(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10688);
	// li r12,1
	ctx.r12.s64 = 1;
	// rlwimi r4,r11,0,0,30
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0xFFFFFFFE) | (ctx.r4.u64 & 0xFFFFFFFF00000001);
	// rldicr r12,r12,35,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 35) & 0xFFFFFFFFFFFFFFFF;
	// stw r4,10688(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10688, ctx.r4.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820983C4"))) PPC_WEAK_FUNC(sub_820983C4);
PPC_FUNC_IMPL(__imp__sub_820983C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820983C8"))) PPC_WEAK_FUNC(sub_820983C8);
PPC_FUNC_IMPL(__imp__sub_820983C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10688(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10688);
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820983D4"))) PPC_WEAK_FUNC(sub_820983D4);
PPC_FUNC_IMPL(__imp__sub_820983D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820983D8"))) PPC_WEAK_FUNC(sub_820983D8);
PPC_FUNC_IMPL(__imp__sub_820983D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r11,r4,21,10,10
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 21) & 0x200000) | (ctx.r11.u64 & 0xFFFFFFFFFFDFFFFF);
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

__attribute__((alias("__imp__sub_820983F4"))) PPC_WEAK_FUNC(sub_820983F4);
PPC_FUNC_IMPL(__imp__sub_820983F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820983F8"))) PPC_WEAK_FUNC(sub_820983F8);
PPC_FUNC_IMPL(__imp__sub_820983F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10568(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwinm r3,r11,11,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 11) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098404"))) PPC_WEAK_FUNC(sub_82098404);
PPC_FUNC_IMPL(__imp__sub_82098404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098408"))) PPC_WEAK_FUNC(sub_82098408);
PPC_FUNC_IMPL(__imp__sub_82098408) {
	PPC_FUNC_PROLOGUE();
	// li r12,1
	ctx.r12.s64 = 1;
	// stw r4,10456(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10456, ctx.r4.u32);
	// ld r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// rldicr r12,r12,38,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 38) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098424"))) PPC_WEAK_FUNC(sub_82098424);
PPC_FUNC_IMPL(__imp__sub_82098424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098428"))) PPC_WEAK_FUNC(sub_82098428);
PPC_FUNC_IMPL(__imp__sub_82098428) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10456);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098430"))) PPC_WEAK_FUNC(sub_82098430);
PPC_FUNC_IMPL(__imp__sub_82098430) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r11,r4,4,27,27
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0x10) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFEF);
	// stw r11,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209844C"))) PPC_WEAK_FUNC(sub_8209844C);
PPC_FUNC_IMPL(__imp__sub_8209844C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098450"))) PPC_WEAK_FUNC(sub_82098450);
PPC_FUNC_IMPL(__imp__sub_82098450) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwinm r3,r11,28,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209845C"))) PPC_WEAK_FUNC(sub_8209845C);
PPC_FUNC_IMPL(__imp__sub_8209845C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098460"))) PPC_WEAK_FUNC(sub_82098460);
PPC_FUNC_IMPL(__imp__sub_82098460) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10556(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r11,r4,24,0,7
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 24) & 0xFF000000) | (ctx.r11.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r11,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	ctx.r11.u64 = ctx.r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209847C"))) PPC_WEAK_FUNC(sub_8209847C);
PPC_FUNC_IMPL(__imp__sub_8209847C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098480"))) PPC_WEAK_FUNC(sub_82098480);
PPC_FUNC_IMPL(__imp__sub_82098480) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10556(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10556);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098488"))) PPC_WEAK_FUNC(sub_82098488);
PPC_FUNC_IMPL(__imp__sub_82098488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10700(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10700, temp.u32);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,32,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820984AC"))) PPC_WEAK_FUNC(sub_820984AC);
PPC_FUNC_IMPL(__imp__sub_820984AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820984B0"))) PPC_WEAK_FUNC(sub_820984B0);
PPC_FUNC_IMPL(__imp__sub_820984B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10700(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10700);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820984B8"))) PPC_WEAK_FUNC(sub_820984B8);
PPC_FUNC_IMPL(__imp__sub_820984B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10692(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10692, temp.u32);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,34,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 34) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820984DC"))) PPC_WEAK_FUNC(sub_820984DC);
PPC_FUNC_IMPL(__imp__sub_820984DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820984E0"))) PPC_WEAK_FUNC(sub_820984E0);
PPC_FUNC_IMPL(__imp__sub_820984E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10692);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820984E8"))) PPC_WEAK_FUNC(sub_820984E8);
PPC_FUNC_IMPL(__imp__sub_820984E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10704(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10704, temp.u32);
	// ld r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098504"))) PPC_WEAK_FUNC(sub_82098504);
PPC_FUNC_IMPL(__imp__sub_82098504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098508"))) PPC_WEAK_FUNC(sub_82098508);
PPC_FUNC_IMPL(__imp__sub_82098508) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10704(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10704);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098510"))) PPC_WEAK_FUNC(sub_82098510);
PPC_FUNC_IMPL(__imp__sub_82098510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10696(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10696, temp.u32);
	// li r12,1
	ctx.r12.s64 = 1;
	// ld r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// rldicr r12,r12,33,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 33) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r10,r12
	ctx.r11.u64 = ctx.r10.u64 | ctx.r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098534"))) PPC_WEAK_FUNC(sub_82098534);
PPC_FUNC_IMPL(__imp__sub_82098534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098538"))) PPC_WEAK_FUNC(sub_82098538);
PPC_FUNC_IMPL(__imp__sub_82098538) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,10696(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10696);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098540"))) PPC_WEAK_FUNC(sub_82098540);
PPC_FUNC_IMPL(__imp__sub_82098540) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r11,r4,20,9,11
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 20) & 0x700000) | (ctx.r11.u64 & 0xFFFFFFFFFF8FFFFF);
	// stw r11,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209855C"))) PPC_WEAK_FUNC(sub_8209855C);
PPC_FUNC_IMPL(__imp__sub_8209855C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098560"))) PPC_WEAK_FUNC(sub_82098560);
PPC_FUNC_IMPL(__imp__sub_82098560) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwinm r3,r11,12,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209856C"))) PPC_WEAK_FUNC(sub_8209856C);
PPC_FUNC_IMPL(__imp__sub_8209856C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098570"))) PPC_WEAK_FUNC(sub_82098570);
PPC_FUNC_IMPL(__imp__sub_82098570) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// lbz r10,10943(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10943);
	// rlwimi r11,r4,17,12,14
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 17) & 0xE0000) | (ctx.r11.u64 & 0xFFFFFFFFFFF1FFFF);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r11.u32);
	// bne 0x820985a8
	if (!ctx.cr0.eq) goto loc_820985A8;
	// rlwinm r11,r11,0,12,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0000;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820985a8
	if (!ctx.cr6.eq) goto loc_820985A8;
	// ld r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// li r12,-257
	ctx.r12.s64 = -257;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// b 0x820985b0
	goto loc_820985B0;
loc_820985A8:
	// ld r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
loc_820985B0:
	// std r11,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, ctx.r11.u64);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820985C4"))) PPC_WEAK_FUNC(sub_820985C4);
PPC_FUNC_IMPL(__imp__sub_820985C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820985C8"))) PPC_WEAK_FUNC(sub_820985C8);
PPC_FUNC_IMPL(__imp__sub_820985C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwinm r3,r11,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820985D4"))) PPC_WEAK_FUNC(sub_820985D4);
PPC_FUNC_IMPL(__imp__sub_820985D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820985D8"))) PPC_WEAK_FUNC(sub_820985D8);
PPC_FUNC_IMPL(__imp__sub_820985D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,3,28,28
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0x8) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFF7);
	// stw r11,10560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10560, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820985F4"))) PPC_WEAK_FUNC(sub_820985F4);
PPC_FUNC_IMPL(__imp__sub_820985F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820985F8"))) PPC_WEAK_FUNC(sub_820985F8);
PPC_FUNC_IMPL(__imp__sub_820985F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwinm r3,r11,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098604"))) PPC_WEAK_FUNC(sub_82098604);
PPC_FUNC_IMPL(__imp__sub_82098604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098608"))) PPC_WEAK_FUNC(sub_82098608);
PPC_FUNC_IMPL(__imp__sub_82098608) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,2,29,29
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 2) & 0x4) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r11,10560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10560, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098624"))) PPC_WEAK_FUNC(sub_82098624);
PPC_FUNC_IMPL(__imp__sub_82098624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098628"))) PPC_WEAK_FUNC(sub_82098628);
PPC_FUNC_IMPL(__imp__sub_82098628) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098634"))) PPC_WEAK_FUNC(sub_82098634);
PPC_FUNC_IMPL(__imp__sub_82098634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098638"))) PPC_WEAK_FUNC(sub_82098638);
PPC_FUNC_IMPL(__imp__sub_82098638) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwimi r11,r4,5,26,26
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 5) & 0x20) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFDF);
	// stw r11,10560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10560, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098654"))) PPC_WEAK_FUNC(sub_82098654);
PPC_FUNC_IMPL(__imp__sub_82098654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098658"))) PPC_WEAK_FUNC(sub_82098658);
PPC_FUNC_IMPL(__imp__sub_82098658) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,10560(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10560);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098664"))) PPC_WEAK_FUNC(sub_82098664);
PPC_FUNC_IMPL(__imp__sub_82098664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098668"))) PPC_WEAK_FUNC(sub_82098668);
PPC_FUNC_IMPL(__imp__sub_82098668) {
	PPC_FUNC_PROLOGUE();
	// stb r4,10562(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10562, ctx.r4.u8);
	// ld r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,256
	ctx.r11.u64 = ctx.r11.u64 | 256;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209867C"))) PPC_WEAK_FUNC(sub_8209867C);
PPC_FUNC_IMPL(__imp__sub_8209867C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098680"))) PPC_WEAK_FUNC(sub_82098680);
PPC_FUNC_IMPL(__imp__sub_82098680) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10562(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10562);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098688"))) PPC_WEAK_FUNC(sub_82098688);
PPC_FUNC_IMPL(__imp__sub_82098688) {
	PPC_FUNC_PROLOGUE();
	// stw r4,13804(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13804, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098690"))) PPC_WEAK_FUNC(sub_82098690);
PPC_FUNC_IMPL(__imp__sub_82098690) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,13804(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13804);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098698"))) PPC_WEAK_FUNC(sub_82098698);
PPC_FUNC_IMPL(__imp__sub_82098698) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwimi r11,r4,23,2,8
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 23) & 0x3F800000) | (ctx.r11.u64 & 0xFFFFFFFFC07FFFFF);
	// stw r11,12028(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12028, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820986A8"))) PPC_WEAK_FUNC(sub_820986A8);
PPC_FUNC_IMPL(__imp__sub_820986A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,12028(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12028);
	// rlwinm r3,r11,9,25,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0x7F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820986B4"))) PPC_WEAK_FUNC(sub_820986B4);
PPC_FUNC_IMPL(__imp__sub_820986B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820986B8"))) PPC_WEAK_FUNC(sub_820986B8);
PPC_FUNC_IMPL(__imp__sub_820986B8) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820986C0;
	__savegprlr_29(ctx, base);
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// lbz r9,12100(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12100);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,12792
	ctx.r8.s64 = ctx.r8.s64 + 12792;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,22,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 22) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,11,20,20
	ctx.r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 11) & 0x800) | (ctx.r29.u64 & 0xFFFFFFFFFFFFF7FF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,21,9,10
	ctx.r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 21) & 0x600000) | (ctx.r31.u64 & 0xFFFFFFFFFF9FFFFF);
	// rlwimi r31,r9,21,4,6
	ctx.r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 21) & 0xE000000) | (ctx.r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
	// lbz r9,12178(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12178);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r29.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82098780"))) PPC_WEAK_FUNC(sub_82098780);
PPC_FUNC_IMPL(__imp__sub_82098780) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r11,r10,21,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x1;
	// rlwinm r10,r9,11,21,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 11) & 0x7FF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820987B4"))) PPC_WEAK_FUNC(sub_820987B4);
PPC_FUNC_IMPL(__imp__sub_820987B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820987B8"))) PPC_WEAK_FUNC(sub_820987B8);
PPC_FUNC_IMPL(__imp__sub_820987B8) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12178(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12178);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rldicr r5,r5,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r30,r31,31,13,31
	ctx.r30.u64 = (__builtin_rotateleft32(ctx.r31.u32, 31) & 0x7FFFF) | (ctx.r30.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r30,r31,31,1,11
	ctx.r30.u64 = (__builtin_rotateleft32(ctx.r31.u32, 31) & 0x7FF00000) | (ctx.r30.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r31,r30,13,20,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 13) & 0xFFF;
	// srd r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// and r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 & ctx.r9.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,12178
	ctx.r9.s64 = ctx.r11.s64 + 12178;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12178(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12178, ctx.r6.u8);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209884C"))) PPC_WEAK_FUNC(sub_8209884C);
PPC_FUNC_IMPL(__imp__sub_8209884C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098850"))) PPC_WEAK_FUNC(sub_82098850);
PPC_FUNC_IMPL(__imp__sub_82098850) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12178(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12178);
	// rlwinm r3,r11,31,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098860"))) PPC_WEAK_FUNC(sub_82098860);
PPC_FUNC_IMPL(__imp__sub_82098860) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82098868;
	__savegprlr_29(ctx, base);
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// add r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// lbz r9,12100(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12100);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r8,12792
	ctx.r8.s64 = ctx.r8.s64 + 12792;
	// rlwinm r7,r5,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// addi r4,r4,32
	ctx.r4.s64 = ctx.r4.s64 + 32;
	// lwz r31,12(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// li r30,1
	ctx.r30.s64 = 1;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// rlwinm r6,r6,21,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 21) & 0x1;
	// lwzx r8,r9,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r29,r7,10,21,21
	ctx.r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 10) & 0x400) | (ctx.r29.u64 & 0xFFFFFFFFFFFFFBFF);
	// or r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r29,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r29.u32);
	// rldicr r6,r30,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r30.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// andc r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// clrldi r8,r4,32
	ctx.r8.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// srd r8,r6,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r8.u8 & 0x7F));
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwimi r31,r9,19,11,12
	ctx.r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 19) & 0x180000) | (ctx.r31.u64 & 0xFFFFFFFFFFE7FFFF);
	// rlwimi r31,r9,19,4,6
	ctx.r31.u64 = (__builtin_rotateleft32(ctx.r9.u32, 19) & 0xE000000) | (ctx.r31.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r31,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r31.u32);
	// lbz r9,12178(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 12178);
	// rotlwi r10,r31,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r31.u32, 0);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// rlwinm r10,r9,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwimi r6,r7,31,13,31
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FFFF) | (ctx.r6.u64 & 0xFFFFFFFFFFF80000);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwimi r6,r7,31,1,11
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 31) & 0x7FF00000) | (ctx.r6.u64 & 0xFFFFFFFF800FFFFF);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// rlwinm r7,r6,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 13) & 0xFFF;
	// and r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ctx.r10.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwimi r10,r29,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r29.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82098928"))) PPC_WEAK_FUNC(sub_82098928);
PPC_FUNC_IMPL(__imp__sub_82098928) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r11,r10,22,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// rlwinm r10,r9,13,19,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1FFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8209895C"))) PPC_WEAK_FUNC(sub_8209895C);
PPC_FUNC_IMPL(__imp__sub_8209895C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098960"))) PPC_WEAK_FUNC(sub_82098960);
PPC_FUNC_IMPL(__imp__sub_82098960) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12178(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12178);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// li r8,1
	ctx.r8.s64 = 1;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rldicr r31,r8,63,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r5,r30,31,13,31
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r30.u32, 31) & 0x7FFFF) | (ctx.r5.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r5,r30,31,1,11
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r30.u32, 31) & 0x7FF00000) | (ctx.r5.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r30,r7,32
	ctx.r30.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r7,r5,13,20,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 13) & 0xFFF;
	// srd r5,r31,r30
	ctx.r5.u64 = ctx.r30.u8 & 0x40 ? 0 : (ctx.r31.u64 >> (ctx.r30.u8 & 0x7F));
	// and r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ctx.r9.u64;
	// addi r9,r11,12178
	ctx.r9.s64 = ctx.r11.s64 + 12178;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12178(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12178, ctx.r6.u8);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820989EC"))) PPC_WEAK_FUNC(sub_820989EC);
PPC_FUNC_IMPL(__imp__sub_820989EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820989F0"))) PPC_WEAK_FUNC(sub_820989F0);
PPC_FUNC_IMPL(__imp__sub_820989F0) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12178(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12178);
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098A00"))) PPC_WEAK_FUNC(sub_82098A00);
PPC_FUNC_IMPL(__imp__sub_82098A00) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r9,r9,63,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// srd r10,r9,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r10.u8 & 0x7F));
	// rlwimi r8,r5,23,7,8
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r5.u32, 23) & 0x1800000) | (ctx.r8.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r8,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098A3C"))) PPC_WEAK_FUNC(sub_82098A3C);
PPC_FUNC_IMPL(__imp__sub_82098A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098A40"))) PPC_WEAK_FUNC(sub_82098A40);
PPC_FUNC_IMPL(__imp__sub_82098A40) {
	PPC_FUNC_PROLOGUE();
	// mulli r11,r4,24
	ctx.r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r11,1164(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1164);
	// rlwinm r3,r11,9,30,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 9) & 0x3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098A54"))) PPC_WEAK_FUNC(sub_82098A54);
PPC_FUNC_IMPL(__imp__sub_82098A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098A58"))) PPC_WEAK_FUNC(sub_82098A58);
PPC_FUNC_IMPL(__imp__sub_82098A58) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// lbz r9,12178(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12178);
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r9,r9,0,30,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// rlwinm r9,r6,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r4,16(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rldicr r5,r5,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// mr r30,r8
	ctx.r30.u64 = ctx.r8.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwimi r30,r31,31,13,31
	ctx.r30.u64 = (__builtin_rotateleft32(ctx.r31.u32, 31) & 0x7FFFF) | (ctx.r30.u64 & 0xFFFFFFFFFFF80000);
	// andc r8,r6,r9
	ctx.r8.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// rlwimi r30,r31,31,1,11
	ctx.r30.u64 = (__builtin_rotateleft32(ctx.r31.u32, 31) & 0x7FF00000) | (ctx.r30.u64 & 0xFFFFFFFF800FFFFF);
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rlwinm r31,r30,13,20,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 13) & 0xFFF;
	// srd r7,r5,r7
	ctx.r7.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r7.u8 & 0x7F));
	// and r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 & ctx.r9.u64;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addi r9,r11,12178
	ctx.r9.s64 = ctx.r11.s64 + 12178;
	// rlwimi r8,r4,0,0,29
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r8.u64 & 0xFFFFFFFF00000003);
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stb r6,12178(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12178, ctx.r6.u8);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098AEC"))) PPC_WEAK_FUNC(sub_82098AEC);
PPC_FUNC_IMPL(__imp__sub_82098AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098AF0"))) PPC_WEAK_FUNC(sub_82098AF0);
PPC_FUNC_IMPL(__imp__sub_82098AF0) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r11,12178(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12178);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098B00"))) PPC_WEAK_FUNC(sub_82098B00);
PPC_FUNC_IMPL(__imp__sub_82098B00) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm. r9,r10,0,20,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x800;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82098b20
	if (!ctx.cr0.eq) goto loc_82098B20;
	// rlwinm. r10,r10,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82098b5c
	if (ctx.cr0.eq) goto loc_82098B5C;
loc_82098B20:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,12792
	ctx.r10.s64 = ctx.r10.s64 + 12792;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// li r6,1
	ctx.r6.s64 = 1;
	// clrldi r7,r7,32
	ctx.r7.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// rldicr r6,r6,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// srd r8,r6,r7
	ctx.r8.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// rlwimi r9,r10,25,4,6
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 25) & 0xE000000) | (ctx.r9.u64 & 0xFFFFFFFFF1FFFFFF);
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
loc_82098B5C:
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,12100(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12100, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098B68"))) PPC_WEAK_FUNC(sub_82098B68);
PPC_FUNC_IMPL(__imp__sub_82098B68) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,12100(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12100);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098B74"))) PPC_WEAK_FUNC(sub_82098B74);
PPC_FUNC_IMPL(__imp__sub_82098B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098B78"))) PPC_WEAK_FUNC(sub_82098B78);
PPC_FUNC_IMPL(__imp__sub_82098B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// lfs f0,12892(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12892);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r10,r10,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// srd r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwimi r8,r9,5,23,26
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0x1E0) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFE1F);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098BD4"))) PPC_WEAK_FUNC(sub_82098BD4);
PPC_FUNC_IMPL(__imp__sub_82098BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098BD8"))) PPC_WEAK_FUNC(sub_82098BD8);
PPC_FUNC_IMPL(__imp__sub_82098BD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mulli r11,r4,24
	ctx.r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,1172(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1172);
	// lfs f0,12880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12880);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r11,23,0,8
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 23) & 0xFF800000;
	// srawi r11,r11,28
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 28;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098C1C"))) PPC_WEAK_FUNC(sub_82098C1C);
PPC_FUNC_IMPL(__imp__sub_82098C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098C20"))) PPC_WEAK_FUNC(sub_82098C20);
PPC_FUNC_IMPL(__imp__sub_82098C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// lfs f0,12860(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12860);
	ctx.f0.f64 = double(temp.f32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r10,r10,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// srd r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r9.u8 & 0x7F));
	// lfs f13,36(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwimi r8,r9,12,10,19
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 12) & 0x3FF000) | (ctx.r8.u64 & 0xFFFFFFFFFFC00FFF);
	// stw r8,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r8.u32);
	// ld r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098C7C"))) PPC_WEAK_FUNC(sub_82098C7C);
PPC_FUNC_IMPL(__imp__sub_82098C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098C80"))) PPC_WEAK_FUNC(sub_82098C80);
PPC_FUNC_IMPL(__imp__sub_82098C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mulli r11,r4,24
	ctx.r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,1168(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1168);
	// lfs f0,12896(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12896);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r11,10,0,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 10) & 0xFFFFFC00;
	// srawi r11,r11,22
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3FFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 22;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
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

__attribute__((alias("__imp__sub_82098CC0"))) PPC_WEAK_FUNC(sub_82098CC0);
PPC_FUNC_IMPL(__imp__sub_82098CC0) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,3180
	ctx.r11.s64 = ctx.r4.s64 + 3180;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82098d20
	if (ctx.cr6.eq) goto loc_82098D20;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r11,r11,30,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0xF;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x82098cf4
	if (ctx.cr6.gt) goto loc_82098CF4;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_82098CF4:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r9,r11,2,26,29
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 2) & 0x3C) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFC3);
	// rldicr r11,r7,63,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// srd r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r10.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
loc_82098D20:
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,12126(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12126, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098D2C"))) PPC_WEAK_FUNC(sub_82098D2C);
PPC_FUNC_IMPL(__imp__sub_82098D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098D30"))) PPC_WEAK_FUNC(sub_82098D30);
PPC_FUNC_IMPL(__imp__sub_82098D30) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,12126(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12126);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098D3C"))) PPC_WEAK_FUNC(sub_82098D3C);
PPC_FUNC_IMPL(__imp__sub_82098D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098D40"))) PPC_WEAK_FUNC(sub_82098D40);
PPC_FUNC_IMPL(__imp__sub_82098D40) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,3180
	ctx.r11.s64 = ctx.r4.s64 + 3180;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82098da0
	if (ctx.cr6.eq) goto loc_82098DA0;
	// lwz r11,44(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// rlwinm r11,r11,26,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xF;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x82098d74
	if (ctx.cr6.lt) goto loc_82098D74;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
loc_82098D74:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwimi r9,r11,6,22,25
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r11.u32, 6) & 0x3C0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFC3F);
	// rldicr r11,r7,63,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// clrldi r10,r8,32
	ctx.r10.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// srd r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r10.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
loc_82098DA0:
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// stb r5,12152(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12152, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098DAC"))) PPC_WEAK_FUNC(sub_82098DAC);
PPC_FUNC_IMPL(__imp__sub_82098DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098DB0"))) PPC_WEAK_FUNC(sub_82098DB0);
PPC_FUNC_IMPL(__imp__sub_82098DB0) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,12152(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12152);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098DBC"))) PPC_WEAK_FUNC(sub_82098DBC);
PPC_FUNC_IMPL(__imp__sub_82098DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098DC0"))) PPC_WEAK_FUNC(sub_82098DC0);
PPC_FUNC_IMPL(__imp__sub_82098DC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addic r10,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// subfe r10,r10,r5
	temp.u8 = (~ctx.r10.u32 + ctx.r5.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// li r8,1
	ctx.r8.s64 = 1;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// rldicr r8,r8,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// rlwimi r10,r7,0,0,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// srd r11,r8,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098E04"))) PPC_WEAK_FUNC(sub_82098E04);
PPC_FUNC_IMPL(__imp__sub_82098E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098E08"))) PPC_WEAK_FUNC(sub_82098E08);
PPC_FUNC_IMPL(__imp__sub_82098E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mulli r11,r4,24
	ctx.r11.s64 = ctx.r4.s64 * 24;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r11,1172(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1172);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098E2C"))) PPC_WEAK_FUNC(sub_82098E2C);
PPC_FUNC_IMPL(__imp__sub_82098E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82098E30"))) PPC_WEAK_FUNC(sub_82098E30);
PPC_FUNC_IMPL(__imp__sub_82098E30) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,10,19,21
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 10) & 0x1C00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFE3FF);
	// li r8,1
	ctx.r8.s64 = 1;
	// stwx r9,r11,r3
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// clrldi r11,r10,32
	ctx.r11.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r10,r8,63,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r11.u8 & 0x7F));
	// ld r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82098E68"))) PPC_WEAK_FUNC(sub_82098E68);
PPC_FUNC_IMPL(__imp__sub_82098E68) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 * 24;
	// lwzx r11,r11,r3
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// rlwinm r3,r11,22,29,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0x7;
	// blr 
	return;
}

