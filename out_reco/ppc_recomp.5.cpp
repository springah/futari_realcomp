#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8808FFE0"))) PPC_WEAK_FUNC(sub_8808FFE0);
PPC_FUNC_IMPL(__imp__sub_8808FFE0) {
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
	// bl 0x8808fab8
	ctx.lr = 0x8808FFF0;
	sub_8808FAB8(ctx, base);
	// bl 0x8808ff58
	ctx.lr = 0x8808FFF4;
	sub_8808FF58(ctx, base);
	// bl 0x8808d930
	ctx.lr = 0x8808FFF8;
	sub_8808D930(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090008"))) PPC_WEAK_FUNC(sub_88090008);
PPC_FUNC_IMPL(__imp__sub_88090008) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r11,r11,23472
	ctx.r11.s64 = ctx.r11.s64 + 23472;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_88090020:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x88090020
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88090020;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 + 28;
	// addi r9,r11,28
	ctx.r9.s64 = ctx.r11.s64 + 28;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8809003C:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8809003c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809003C;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r3,60
	ctx.r10.s64 = ctx.r3.s64 + 60;
	// addi r11,r11,60
	ctx.r11.s64 = ctx.r11.s64 + 60;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88090058:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88090058
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88090058;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090068"))) PPC_WEAK_FUNC(sub_88090068);
PPC_FUNC_IMPL(__imp__sub_88090068) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r11,-10976
	ctx.r10.s64 = ctx.r11.s64 + -10976;
	// stw r4,-10976(r11)
	PPC_STORE_U32(ctx.r11.u32 + -10976, ctx.r4.u32);
	// stw r3,-20(r10)
	PPC_STORE_U32(ctx.r10.u32 + -20, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809007C"))) PPC_WEAK_FUNC(sub_8809007C);
PPC_FUNC_IMPL(__imp__sub_8809007C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090080"))) PPC_WEAK_FUNC(sub_88090080);
PPC_FUNC_IMPL(__imp__sub_88090080) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r10,23632
	ctx.r11.s64 = ctx.r10.s64 + 23632;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880900A0"))) PPC_WEAK_FUNC(sub_880900A0);
PPC_FUNC_IMPL(__imp__sub_880900A0) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,-10976
	ctx.r31.s64 = ctx.r11.s64 + -10976;
	// lwz r11,-20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880900f8
	if (ctx.cr6.eq) goto loc_880900F8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8824ead0
	ctx.lr = 0x880900D4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r10,r11,23632
	ctx.r10.s64 = ctx.r11.s64 + 23632;
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mullw r9,r11,r30
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r11,r9,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// bl 0x8824eae0
	ctx.lr = 0x880900F8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_880900F8:
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

__attribute__((alias("__imp__sub_88090110"))) PPC_WEAK_FUNC(sub_88090110);
PPC_FUNC_IMPL(__imp__sub_88090110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88090118;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r11,-10980
	ctx.r31.s64 = ctx.r11.s64 + -10980;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8824ead0
	ctx.lr = 0x88090134;
	__imp__RtlEnterCriticalSection(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r30,r10,23568
	ctx.r30.s64 = ctx.r10.s64 + 23568;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r30,64
	ctx.r9.s64 = ctx.r30.s64 + 64;
	// lwzx r29,r10,r9
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8824eae0
	ctx.lr = 0x88090158;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x880901ac
	if (ctx.cr6.eq) goto loc_880901AC;
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r9,r10,13168
	ctx.r9.s64 = ctx.r10.s64 + 13168;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,12(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x880901AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_880901AC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880901B4"))) PPC_WEAK_FUNC(sub_880901B4);
PPC_FUNC_IMPL(__imp__sub_880901B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880901B8"))) PPC_WEAK_FUNC(sub_880901B8);
PPC_FUNC_IMPL(__imp__sub_880901B8) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r30,r11,-10996
	ctx.r30.s64 = ctx.r11.s64 + -10996;
	// add r11,r3,r10
	ctx.r11.u64 = ctx.r3.u64 + ctx.r10.u64;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,23632
	ctx.r10.s64 = ctx.r10.s64 + 23632;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880901F4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r31,0(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
loc_88090208:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x88090208
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88090208;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x8824eae0
	ctx.lr = 0x88090218;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88090268
	if (ctx.cr6.eq) goto loc_88090268;
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x88073bd0
	ctx.lr = 0x88090230;
	sub_88073BD0(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r31,90(r1)
	PPC_STORE_U32(ctx.r1.u32 + 90, ctx.r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x88090254;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x88090268;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88090268:
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

__attribute__((alias("__imp__sub_88090280"))) PPC_WEAK_FUNC(sub_88090280);
PPC_FUNC_IMPL(__imp__sub_88090280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88090288;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r27,8
	ctx.r27.s64 = 8;
	// addi r26,r11,23472
	ctx.r26.s64 = ctx.r11.s64 + 23472;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r29,r26,160
	ctx.r29.s64 = ctx.r26.s64 + 160;
	// li r28,3
	ctx.r28.s64 = 3;
	// addi r31,r11,-10996
	ctx.r31.s64 = ctx.r11.s64 + -10996;
loc_880902A8:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x8824ead0
	ctx.lr = 0x880902B0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r10,r29,-4
	ctx.r10.s64 = ctx.r29.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r30,0(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_880902C4:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x880902c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880902C4;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x8824eae0
	ctx.lr = 0x880902D4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88090320
	if (ctx.cr6.eq) goto loc_88090320;
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x88073bd0
	ctx.lr = 0x880902EC;
	sub_88073BD0(ctx, base);
	// stw r30,90(r1)
	PPC_STORE_U32(ctx.r1.u32 + 90, ctx.r30.u32);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r28.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8809030C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x88090320;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88090320:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,24
	ctx.r29.s64 = ctx.r29.s64 + 24;
	// bne 0x880902a8
	if (!ctx.cr0.eq) goto loc_880902A8;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// li r5,96
	ctx.r5.s64 = 96;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88090350;
	sub_88073BD0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090360"))) PPC_WEAK_FUNC(sub_88090360);
PPC_FUNC_IMPL(__imp__sub_88090360) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88090368;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,256
	ctx.r10.s64 = 256;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r28,r11,23472
	ctx.r28.s64 = ctx.r11.s64 + 23472;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r28,352
	ctx.r11.s64 = ctx.r28.s64 + 352;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_8809038C:
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8809038c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809038C;
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r11,r11,-24560
	ctx.r11.s64 = ctx.r11.s64 + -24560;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
loc_880903A8:
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r26,0(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// bge cr6,0x88090424
	if (!ctx.cr6.lt) goto loc_88090424;
	// addi r10,r28,352
	ctx.r10.s64 = ctx.r28.s64 + 352;
	// rlwinm r30,r11,3,0,28
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r27,r10,4
	ctx.r27.s64 = ctx.r10.s64 + 4;
	// lwzx r11,r30,r27
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// bne cr6,0x88090424
	if (!ctx.cr6.eq) goto loc_88090424;
	// cmplwi cr6,r26,3
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 3, ctx.xer);
	// bge cr6,0x88090424
	if (!ctx.cr6.lt) goto loc_88090424;
	// rlwinm r11,r26,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r28,4
	ctx.r10.s64 = ctx.r28.s64 + 4;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x880903F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65535, ctx.xer);
	// beq cr6,0x88090424
	if (ctx.cr6.eq) goto loc_88090424;
	// addi r10,r28,352
	ctx.r10.s64 = ctx.r28.s64 + 352;
	// stwx r11,r30,r27
	PPC_STORE_U32(ctx.r30.u32 + ctx.r27.u32, ctx.r11.u32);
	// addi r29,r29,12
	ctx.r29.s64 = ctx.r29.s64 + 12;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// cmplwi cr6,r29,1884
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 1884, ctx.xer);
	// stwx r26,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r26.u32);
	// blt cr6,0x880903a8
	if (ctx.cr6.lt) goto loc_880903A8;
loc_88090424:
	// addi r11,r25,-157
	ctx.r11.s64 = ctx.r25.s64 + -157;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090438"))) PPC_WEAK_FUNC(sub_88090438);
PPC_FUNC_IMPL(__imp__sub_88090438) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809043C"))) PPC_WEAK_FUNC(sub_8809043C);
PPC_FUNC_IMPL(__imp__sub_8809043C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090440"))) PPC_WEAK_FUNC(sub_88090440);
PPC_FUNC_IMPL(__imp__sub_88090440) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r11,r11,19664
	ctx.r11.s64 = ctx.r11.s64 + 19664;
	// addi r8,r9,-10988
	ctx.r8.s64 = ctx.r9.s64 + -10988;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88090468
	if (ctx.cr6.eq) goto loc_88090468;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r11.u32);
	// stw r10,-10988(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10988, ctx.r10.u32);
	// blr 
	return;
loc_88090468:
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,1080
	ctx.r10.s64 = ctx.r10.s64 + 1080;
	// stw r11,-10988(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10988, ctx.r11.u32);
	// stw r10,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090480"))) PPC_WEAK_FUNC(sub_88090480);
PPC_FUNC_IMPL(__imp__sub_88090480) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88090488;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r28,r11,-10992
	ctx.r28.s64 = ctx.r11.s64 + -10992;
	// lwz r11,-4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88090568
	if (ctx.cr6.eq) goto loc_88090568;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880904B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// stw r11,8(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88090568
	if (!ctx.cr6.eq) goto loc_88090568;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r11,r11,23632
	ctx.r11.s64 = ctx.r11.s64 + 23632;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// li r25,8
	ctx.r25.s64 = 8;
	// addi r31,r11,16
	ctx.r31.s64 = ctx.r11.s64 + 16;
loc_880904E0:
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880904EC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r29,-16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// beq cr6,0x88090528
	if (ctx.cr6.eq) goto loc_88090528;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8809051c
	if (!ctx.cr6.eq) goto loc_8809051C;
	// li r30,-1
	ctx.r30.s64 = -1;
	// stw r26,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// b 0x88090528
	goto loc_88090528;
loc_8809051C:
	// lwz r9,-4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// divwu r30,r8,r11
	ctx.r30.u32 = ppc_divwu(ctx.r8.u32, ctx.r11.u32);
loc_88090528:
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// bl 0x8824eae0
	ctx.lr = 0x88090530;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x88090558
	if (ctx.cr6.eq) goto loc_88090558;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x88090558
	if (ctx.cr6.eq) goto loc_88090558;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bge cr6,0x88090550
	if (!ctx.cr6.lt) goto loc_88090550;
	// bl 0x880901b8
	ctx.lr = 0x8809054C;
	sub_880901B8(ctx, base);
	// b 0x88090558
	goto loc_88090558;
loc_88090550:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x88090110
	ctx.lr = 0x88090558;
	sub_88090110(ctx, base);
loc_88090558:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// bne 0x880904e0
	if (!ctx.cr0.eq) goto loc_880904E0;
loc_88090568:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090570"))) PPC_WEAK_FUNC(sub_88090570);
PPC_FUNC_IMPL(__imp__sub_88090570) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-10996(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -10996);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x880901b8
	sub_880901B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090584"))) PPC_WEAK_FUNC(sub_88090584);
PPC_FUNC_IMPL(__imp__sub_88090584) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090588"))) PPC_WEAK_FUNC(sub_88090588);
PPC_FUNC_IMPL(__imp__sub_88090588) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88090590;
	__savegprlr_25(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// addi r29,r11,-10976
	ctx.r29.s64 = ctx.r11.s64 + -10976;
	// add r11,r3,r9
	ctx.r11.u64 = ctx.r3.u64 + ctx.r9.u64;
	// addi r30,r10,23472
	ctx.r30.s64 = ctx.r10.s64 + 23472;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r30,160
	ctx.r9.s64 = ctx.r30.s64 + 160;
	// lwz r11,-20(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -20);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// add r31,r10,r9
	ctx.r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880906d0
	if (ctx.cr6.eq) goto loc_880906D0;
	// bl 0x880901b8
	ctx.lr = 0x880905D8;
	sub_880901B8(ctx, base);
	// cmplwi cr6,r27,256
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 256, ctx.xer);
	// bge cr6,0x880906d0
	if (!ctx.cr6.lt) goto loc_880906D0;
	// rlwinm r10,r27,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r30,352
	ctx.r11.s64 = ctx.r30.s64 + 352;
	// addi r9,r30,352
	ctx.r9.s64 = ctx.r30.s64 + 352;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwzx r11,r10,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r10,r10,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x880906d0
	if (!ctx.cr6.lt) goto loc_880906D0;
	// cmplwi cr6,r10,65535
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 65535, ctx.xer);
	// beq cr6,0x880906d0
	if (ctx.cr6.eq) goto loc_880906D0;
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r30,28
	ctx.r9.s64 = ctx.r30.s64 + 28;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880906d0
	if (ctx.cr6.eq) goto loc_880906D0;
	// addi r9,r30,4
	ctx.r9.s64 = ctx.r30.s64 + 4;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// lwzx r3,r11,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88090644;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880906d0
	if (!ctx.cr6.eq) goto loc_880906D0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8824ead0
	ctx.lr = 0x88090654;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// stw r25,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r25.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8824eae0
	ctx.lr = 0x88090680;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,97
	ctx.r3.s64 = ctx.r1.s64 + 97;
	// bl 0x88073bd0
	ctx.lr = 0x88090690;
	sub_88073BD0(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r31,118(r1)
	PPC_STORE_U32(ctx.r1.u32 + 118, ctx.r31.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,-20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + -20);
	// stb r7,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r7.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r6,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, ctx.r6.u16);
	// stw r8,106(r1)
	PPC_STORE_U32(ctx.r1.u32 + 106, ctx.r8.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880906C4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88090110
	ctx.lr = 0x880906D0;
	sub_88090110(ctx, base);
loc_880906D0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880906D8"))) PPC_WEAK_FUNC(sub_880906D8);
PPC_FUNC_IMPL(__imp__sub_880906D8) {
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
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r5,2048
	ctx.r5.s64 = 2048;
	// addi r30,r11,23568
	ctx.r30.s64 = ctx.r11.s64 + 23568;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,256
	ctx.r3.s64 = ctx.r30.s64 + 256;
	// bl 0x88073bd0
	ctx.lr = 0x88090704;
	sub_88073BD0(ctx, base);
	// addi r3,r30,64
	ctx.r3.s64 = ctx.r30.s64 + 64;
	// li r5,192
	ctx.r5.s64 = 192;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88090714;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// addi r31,r11,-10980
	ctx.r31.s64 = ctx.r11.s64 + -10980;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,1080
	ctx.r10.s64 = ctx.r10.s64 + 1080;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// stw r11,-8(r31)
	PPC_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
	// stw r10,-12(r31)
	PPC_STORE_U32(ctx.r31.u32 + -12, ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r9,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r9.u32);
	// beq cr6,0x88090788
	if (ctx.cr6.eq) goto loc_88090788;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x88090758;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x88090788
	if (ctx.cr6.lt) goto loc_88090788;
	// lhz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x88090784
	if (ctx.cr6.eq) goto loc_88090784;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
loc_8809077C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8809077c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8809077C;
loc_88090784:
	// bl 0x88090360
	ctx.lr = 0x88090788;
	sub_88090360(ctx, base);
loc_88090788:
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

__attribute__((alias("__imp__sub_880907A0"))) PPC_WEAK_FUNC(sub_880907A0);
PPC_FUNC_IMPL(__imp__sub_880907A0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r10,r10,-11004
	ctx.r10.s64 = ctx.r10.s64 + -11004;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x880907c0
	if (ctx.cr6.lt) goto loc_880907C0;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880907C0:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r5,6,20,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFC0;
	// clrlwi r9,r4,26
	ctx.r9.u64 = ctx.r4.u32 & 0x3F;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880907E8"))) PPC_WEAK_FUNC(sub_880907E8);
PPC_FUNC_IMPL(__imp__sub_880907E8) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r10,23440
	ctx.r11.s64 = ctx.r10.s64 + 23440;
	// clrlwi r8,r4,19
	ctx.r8.u64 = ctx.r4.u32 & 0x1FFF;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// clrlwi r6,r5,20
	ctx.r6.u64 = ctx.r5.u32 & 0xFFF;
	// stwx r8,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r8.u32);
	// stwx r6,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090818"))) PPC_WEAK_FUNC(sub_88090818);
PPC_FUNC_IMPL(__imp__sub_88090818) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x88090820;
	__savegprlr_24(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r11,r11,-11004
	ctx.r11.s64 = ctx.r11.s64 + -11004;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x88090938
	if (!ctx.cr6.lt) goto loc_88090938;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r8,-30628
	ctx.r8.s64 = -2007236608;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r8,23440
	ctx.r10.s64 = ctx.r8.s64 + 23440;
	// rlwinm r6,r9,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r7,r4,16
	ctx.r7.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r4,r10,4
	ctx.r4.s64 = ctx.r10.s64 + 4;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lis r26,-30597
	ctx.r26.s64 = -2005204992;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// li r27,9
	ctx.r27.s64 = 9;
	// addi r3,r9,32
	ctx.r3.s64 = ctx.r9.s64 + 32;
	// lwzx r10,r6,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// addi r31,r8,32
	ctx.r31.s64 = ctx.r8.s64 + 32;
	// lwz r29,12(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwzx r11,r6,r4
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	// rlwinm r3,r3,27,5,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r6,r31,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r4,r10,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// neg r10,r3
	ctx.r10.s64 = -ctx.r3.s64;
	// neg r7,r6
	ctx.r7.s64 = -ctx.r6.s64;
	// or r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 | ctx.r11.u64;
	// lis r11,31
	ctx.r11.s64 = 2031616;
	// clrlwi r31,r7,26
	ctx.r31.u64 = ctx.r7.u32 & 0x3F;
	// ori r7,r11,31
	ctx.r7.u64 = ctx.r11.u64 | 31;
	// lwz r11,-11892(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11892);
	// clrlwi r4,r10,26
	ctx.r4.u64 = ctx.r10.u32 & 0x3F;
	// clrlwi r28,r9,27
	ctx.r28.u64 = ctx.r9.u32 & 0x1F;
	// clrlwi r6,r8,27
	ctx.r6.u64 = ctx.r8.u32 & 0x1F;
loc_880908B4:
	// li r10,11
	ctx.r10.s64 = 11;
	// rlwinm r9,r31,9,0,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 9) & 0xFFFFFE00;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// add r30,r9,r29
	ctx.r30.u64 = ctx.r9.u64 + ctx.r29.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
loc_880908D0:
	// lwzx r10,r10,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// clrlwi r25,r10,2
	ctx.r25.u64 = ctx.r10.u32 & 0x3FFFFFFF;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8809090c
	if (ctx.cr6.eq) goto loc_8809090C;
	// lis r25,4352
	ctx.r25.s64 = 285212672;
	// add r24,r10,r3
	ctx.r24.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwimi r25,r10,28,4,5
	ctx.r25.u64 = (__builtin_rotateleft32(ctx.r10.u32, 28) & 0xC000000) | (ctx.r25.u64 & 0xFFFFFFFFF3FFFFFF);
	// rlwinm r10,r9,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// stw r25,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// stwu r24,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r24.u32);
	ctx.r11.u32 = ea;
	// or r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 | ctx.r6.u64;
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// stwu r5,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_8809090C:
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// clrlwi r8,r10,26
	ctx.r8.u64 = ctx.r10.u32 & 0x3F;
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// bdnz 0x880908d0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880908D0;
	// addi r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 1;
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// clrlwi r31,r10,26
	ctx.r31.u64 = ctx.r10.u32 & 0x3F;
	// addi r6,r6,32
	ctx.r6.s64 = ctx.r6.s64 + 32;
	// bne 0x880908b4
	if (!ctx.cr0.eq) goto loc_880908B4;
	// stw r11,-11892(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11892, ctx.r11.u32);
loc_88090938:
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809093C"))) PPC_WEAK_FUNC(sub_8809093C);
PPC_FUNC_IMPL(__imp__sub_8809093C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090940"))) PPC_WEAK_FUNC(sub_88090940);
PPC_FUNC_IMPL(__imp__sub_88090940) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r10,r10,-11004
	ctx.r10.s64 = ctx.r10.s64 + -11004;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r9,r4,21
	ctx.r9.u64 = ctx.r4.u32 & 0x7FF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r8,r5,21
	ctx.r8.u64 = ctx.r5.u32 & 0x7FF;
	// subfic r7,r9,2048
	ctx.xer.ca = ctx.r9.u32 <= 2048;
	ctx.r7.s64 = 2048 - ctx.r9.s64;
	// subfic r6,r8,2048
	ctx.xer.ca = ctx.r8.u32 <= 2048;
	ctx.r6.s64 = 2048 - ctx.r8.s64;
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090980"))) PPC_WEAK_FUNC(sub_88090980);
PPC_FUNC_IMPL(__imp__sub_88090980) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88090988;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r29,r11,-11000
	ctx.r29.s64 = ctx.r11.s64 + -11000;
	// lwz r11,-4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880909ec
	if (ctx.cr6.eq) goto loc_880909EC;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880909e4
	if (ctx.cr6.eq) goto loc_880909E4;
	// li r31,0
	ctx.r31.s64 = 0;
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
loc_880909B8:
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880909d0
	if (ctx.cr6.eq) goto loc_880909D0;
	// bl 0x88083758
	ctx.lr = 0x880909C8;
	sub_88083758(ctx, base);
	// lwz r11,-4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_880909D0:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
	// blt cr6,0x880909b8
	if (ctx.cr6.lt) goto loc_880909B8;
loc_880909E4:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x88083758
	ctx.lr = 0x880909EC;
	sub_88083758(ctx, base);
loc_880909EC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-4(r29)
	PPC_STORE_U32(ctx.r29.u32 + -4, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880909FC"))) PPC_WEAK_FUNC(sub_880909FC);
PPC_FUNC_IMPL(__imp__sub_880909FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090A00"))) PPC_WEAK_FUNC(sub_88090A00);
PPC_FUNC_IMPL(__imp__sub_88090A00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88090A08;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,-1
	ctx.r26.s64 = -1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x880836d0
	ctx.lr = 0x88090A24;
	sub_880836D0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r28,r11,-11000
	ctx.r28.s64 = ctx.r11.s64 + -11000;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,-4(r28)
	PPC_STORE_U32(ctx.r28.u32 + -4, ctx.r3.u32);
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88090A44;
	sub_88073BD0(ctx, base);
	// li r25,0
	ctx.r25.s64 = 0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// ori r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 32768;
loc_88090A58:
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x880836d0
	ctx.lr = 0x88090A6C;
	sub_880836D0(ctx, base);
	// lwz r29,-4(r28)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + -4);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r3.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88090A84;
	sub_88073BD0(ctx, base);
	// stwx r30,r31,r29
	PPC_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r30.u32);
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r31,64
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 64, ctx.xer);
	// blt cr6,0x88090a58
	if (ctx.cr6.lt) goto loc_88090A58;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r10,r11,23440
	ctx.r10.s64 = ctx.r11.s64 + 23440;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_88090AB0:
	// subfic r9,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r9.s64 = 15 - ctx.r11.s64;
	// stw r25,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r25.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// stwu r8,8(r10)
	ea = 8 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x88090ab0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88090AB0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090AD0"))) PPC_WEAK_FUNC(sub_88090AD0);
PPC_FUNC_IMPL(__imp__sub_88090AD0) {
	PPC_FUNC_PROLOGUE();
	// lis r5,128
	ctx.r5.s64 = 8388608;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,32896
	ctx.r5.u64 = ctx.r5.u64 | 32896;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// b 0x88090818
	sub_88090818(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090AE4"))) PPC_WEAK_FUNC(sub_88090AE4);
PPC_FUNC_IMPL(__imp__sub_88090AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090AE8"))) PPC_WEAK_FUNC(sub_88090AE8);
PPC_FUNC_IMPL(__imp__sub_88090AE8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-22560
	ctx.r11.s64 = ctx.r11.s64 + -22560;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r6,-8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// lwz r3,-8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090B1C"))) PPC_WEAK_FUNC(sub_88090B1C);
PPC_FUNC_IMPL(__imp__sub_88090B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090B20"))) PPC_WEAK_FUNC(sub_88090B20);
PPC_FUNC_IMPL(__imp__sub_88090B20) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,1500
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1500, ctx.xer);
	// bge cr6,0x88090b3c
	if (!ctx.cr6.lt) goto loc_88090B3C;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,17440
	ctx.r9.s64 = ctx.r11.s64 + 17440;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
loc_88090B3C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090B44"))) PPC_WEAK_FUNC(sub_88090B44);
PPC_FUNC_IMPL(__imp__sub_88090B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090B48"))) PPC_WEAK_FUNC(sub_88090B48);
PPC_FUNC_IMPL(__imp__sub_88090B48) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88090b70
	if (!ctx.cr6.eq) goto loc_88090B70;
loc_88090B68:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x88090bd8
	goto loc_88090BD8;
loc_88090B70:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r30,r11,17440
	ctx.r30.s64 = ctx.r11.s64 + 17440;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88090b68
	if (ctx.cr6.eq) goto loc_88090B68;
	// lis r10,-30719
	ctx.r10.s64 = -2013200384;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,-22560
	ctx.r10.s64 = ctx.r10.s64 + -22560;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r6,-8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8);
	// lwz r5,-8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8);
	// rlwinm r4,r6,27,5,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r3,r5,0,29,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// or r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 | ctx.r4.u64;
	// rlwinm r3,r11,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x8808d5b0
	ctx.lr = 0x88090BC0;
	sub_8808D5B0(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r11,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + ctx.r30.u32, ctx.r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_88090BD8:
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

__attribute__((alias("__imp__sub_88090BF0"))) PPC_WEAK_FUNC(sub_88090BF0);
PPC_FUNC_IMPL(__imp__sub_88090BF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090BF4"))) PPC_WEAK_FUNC(sub_88090BF4);
PPC_FUNC_IMPL(__imp__sub_88090BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090BF8"))) PPC_WEAK_FUNC(sub_88090BF8);
PPC_FUNC_IMPL(__imp__sub_88090BF8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090BFC"))) PPC_WEAK_FUNC(sub_88090BFC);
PPC_FUNC_IMPL(__imp__sub_88090BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090C00"))) PPC_WEAK_FUNC(sub_88090C00);
PPC_FUNC_IMPL(__imp__sub_88090C00) {
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
	// li r31,0
	ctx.r31.s64 = 0;
loc_88090C14:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8808d5b0
	ctx.lr = 0x88090C1C;
	sub_8808D5B0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,512
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 512, ctx.xer);
	// blt cr6,0x88090c14
	if (ctx.cr6.lt) goto loc_88090C14;
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

__attribute__((alias("__imp__sub_88090C3C"))) PPC_WEAK_FUNC(sub_88090C3C);
PPC_FUNC_IMPL(__imp__sub_88090C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090C40"))) PPC_WEAK_FUNC(sub_88090C40);
PPC_FUNC_IMPL(__imp__sub_88090C40) {
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
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r5,4000
	ctx.r5.s64 = 4000;
	// addi r31,r11,17440
	ctx.r31.s64 = ctx.r11.s64 + 17440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-4000
	ctx.r3.s64 = ctx.r31.s64 + -4000;
	// bl 0x88073bd0
	ctx.lr = 0x88090C68;
	sub_88073BD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,6000
	ctx.r5.s64 = 6000;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88090C78;
	sub_88073BD0(ctx, base);
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

__attribute__((alias("__imp__sub_88090C8C"))) PPC_WEAK_FUNC(sub_88090C8C);
PPC_FUNC_IMPL(__imp__sub_88090C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090C90"))) PPC_WEAK_FUNC(sub_88090C90);
PPC_FUNC_IMPL(__imp__sub_88090C90) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r11,r5,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r10,r6,0,29,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// rlwinm r3,r9,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// b 0x8808d640
	sub_8808D640(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090CB4"))) PPC_WEAK_FUNC(sub_88090CB4);
PPC_FUNC_IMPL(__imp__sub_88090CB4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090CB8"))) PPC_WEAK_FUNC(sub_88090CB8);
PPC_FUNC_IMPL(__imp__sub_88090CB8) {
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
	// lis r11,-30700
	ctx.r11.s64 = -2011955200;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r31,r11,-22896
	ctx.r31.s64 = ctx.r11.s64 + -22896;
	// beq cr6,0x88090cfc
	if (ctx.cr6.eq) goto loc_88090CFC;
	// rlwinm r11,r5,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r10,r6,0,29,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// rlwinm r3,r9,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x8808d640
	ctx.lr = 0x88090CFC;
	sub_8808D640(ctx, base);
loc_88090CFC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88090d0c
	if (ctx.cr6.eq) goto loc_88090D0C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
loc_88090D0C:
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

__attribute__((alias("__imp__sub_88090D24"))) PPC_WEAK_FUNC(sub_88090D24);
PPC_FUNC_IMPL(__imp__sub_88090D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88090D28"))) PPC_WEAK_FUNC(sub_88090D28);
PPC_FUNC_IMPL(__imp__sub_88090D28) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r11,r5,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r10,r6,0,29,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// rlwinm r3,r9,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// b 0x8808d640
	sub_8808D640(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090D4C"))) PPC_WEAK_FUNC(sub_88090D4C);
PPC_FUNC_IMPL(__imp__sub_88090D4C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88090D50"))) PPC_WEAK_FUNC(sub_88090D50);
PPC_FUNC_IMPL(__imp__sub_88090D50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88090D58;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,13440
	ctx.r11.s64 = ctx.r11.s64 + 13440;
	// lis r10,-30700
	ctx.r10.s64 = -2011955200;
	// addi r7,r11,4000
	ctx.r7.s64 = ctx.r11.s64 + 4000;
	// addi r30,r10,-22896
	ctx.r30.s64 = ctx.r10.s64 + -22896;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwzx r10,r8,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88090db0
	if (ctx.cr6.eq) goto loc_88090DB0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88090d98
	if (ctx.cr6.eq) goto loc_88090D98;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
loc_88090D98:
	// lwzx r10,r8,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_88090DB0:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
loc_88090DB8:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x88090dd8
	if (ctx.cr6.eq) goto loc_88090DD8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r9,500
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 500, ctx.xer);
	// blt cr6,0x88090db8
	if (ctx.cr6.lt) goto loc_88090DB8;
	// b 0x88090e3c
	goto loc_88090E3C;
loc_88090DD8:
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r28,r11,4
	ctx.r28.s64 = ctx.r11.s64 + 4;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r27,-32768
	ctx.r27.s64 = -2147483648;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// stwx r27,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r27.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stwx r5,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + ctx.r28.u32, ctx.r5.u32);
	// stwx r9,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u32);
	// beq cr6,0x88090e3c
	if (ctx.cr6.eq) goto loc_88090E3C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88090e3c
	if (ctx.cr6.eq) goto loc_88090E3C;
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r11,r11,-22560
	ctx.r11.s64 = ctx.r11.s64 + -22560;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r6,r8,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r3,r7,0,29,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// or r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 | ctx.r6.u64;
	// rlwinm r3,r11,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x8808d640
	ctx.lr = 0x88090E3C;
	sub_8808D640(ctx, base);
loc_88090E3C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x88090e4c
	if (ctx.cr6.eq) goto loc_88090E4C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
loc_88090E4C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090E58"))) PPC_WEAK_FUNC(sub_88090E58);
PPC_FUNC_IMPL(__imp__sub_88090E58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88090E60;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,13440
	ctx.r11.s64 = ctx.r11.s64 + 13440;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r6,r11,4000
	ctx.r6.s64 = ctx.r11.s64 + 4000;
	// lwzx r10,r7,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88090e98
	if (ctx.cr6.eq) goto loc_88090E98;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88090E98:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
loc_88090EA0:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88090ec8
	if (ctx.cr6.eq) goto loc_88090EC8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r9,500
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 500, ctx.xer);
	// blt cr6,0x88090ea0
	if (ctx.cr6.lt) goto loc_88090EA0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88090EC8:
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r30,r11,4
	ctx.r30.s64 = ctx.r11.s64 + 4;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// stwx r29,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, ctx.r29.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stwx r5,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + ctx.r30.u32, ctx.r5.u32);
	// stwx r9,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r9.u32);
	// beq cr6,0x88090f2c
	if (ctx.cr6.eq) goto loc_88090F2C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88090f2c
	if (ctx.cr6.eq) goto loc_88090F2C;
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r11,r11,-22560
	ctx.r11.s64 = ctx.r11.s64 + -22560;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// rlwinm r6,r8,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r3,r7,0,29,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFF07;
	// or r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 | ctx.r6.u64;
	// rlwinm r3,r11,29,3,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// bl 0x8808d640
	ctx.lr = 0x88090F2C;
	sub_8808D640(ctx, base);
loc_88090F2C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88090F38"))) PPC_WEAK_FUNC(sub_88090F38);
PPC_FUNC_IMPL(__imp__sub_88090F38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88090F40;
	__savegprlr_25(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// srawi r10,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 16;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// mulli r9,r9,52
	ctx.r9.s64 = ctx.r9.s64 * 52;
	// lwz r11,-11016(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11016);
	// lis r8,-30719
	ctx.r8.s64 = -2013200384;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-18548
	ctx.r6.s64 = ctx.r8.s64 + -18548;
	// li r5,0
	ctx.r5.s64 = 0;
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r31,r7,r6
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r7,r9,3
	ctx.r7.s64 = ctx.r9.s64 + 3;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// slw r9,r5,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r7.u8 & 0x3F));
	// lbz r30,12(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// slw r29,r6,r10
	ctx.r29.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// li r28,256
	ctx.r28.s64 = 256;
	// subfic r27,r4,344
	ctx.xer.ca = ctx.r4.u32 <= 344;
	ctx.r27.s64 = 344 - ctx.r4.s64;
	// addi r26,r9,-1
	ctx.r26.s64 = ctx.r9.s64 + -1;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// subf r29,r6,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r6.s64;
	// sraw r11,r28,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r28.s32 < 0) & (((ctx.r28.s32 >> temp.u32) << temp.u32) != ctx.r28.s32);
	ctx.r11.s64 = ctx.r28.s32 >> temp.u32;
	// extsb r9,r30
	ctx.r9.s64 = ctx.r30.s8;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// rlwinm r6,r27,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// or r29,r26,r29
	ctx.r29.u64 = ctx.r26.u64 | ctx.r29.u64;
	// rotlw r28,r5,r10
	ctx.r28.u64 = __builtin_rotateleft32(ctx.r5.u32, ctx.r10.u8 & 0x1F);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88091060
	if (ctx.cr6.eq) goto loc_88091060;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
	// lis r5,4352
	ctx.r5.s64 = 285212672;
	// lwz r11,-11892(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -11892);
loc_88090FFC:
	// addic. r9,r9,-32
	ctx.xer.ca = ctx.r9.u32 > 31;
	ctx.r9.s64 = ctx.r9.s64 + -32;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// beq 0x88091044
	if (ctx.cr0.eq) goto loc_88091044;
	// subfic r26,r10,8
	ctx.xer.ca = ctx.r10.u32 <= 8;
	ctx.r26.s64 = 8 - ctx.r10.s64;
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// and r25,r9,r30
	ctx.r25.u64 = ctx.r9.u64 & ctx.r30.u64;
	// srw r9,r9,r26
	ctx.r9.u64 = ctx.r26.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r26.u8 & 0x3F));
	// slw r9,r9,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// subf r9,r9,r31
	ctx.r9.s64 = ctx.r31.s64 - ctx.r9.s64;
	// slw r26,r25,r10
	ctx.r26.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r25.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// or r25,r8,r6
	ctx.r25.u64 = ctx.r8.u64 | ctx.r6.u64;
	// or r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 | ctx.r26.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r25,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r25.u32);
	ctx.r11.u32 = ea;
	// stwu r29,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r29.u32);
	ctx.r11.u32 = ea;
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_88091044:
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// add r8,r28,r8
	ctx.r8.u64 = ctx.r28.u64 + ctx.r8.u64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88090ffc
	if (!ctx.cr6.eq) goto loc_88090FFC;
	// stw r11,-11892(r27)
	PPC_STORE_U32(ctx.r27.u32 + -11892, ctx.r11.u32);
loc_88091060:
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091064"))) PPC_WEAK_FUNC(sub_88091064);
PPC_FUNC_IMPL(__imp__sub_88091064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091068"))) PPC_WEAK_FUNC(sub_88091068);
PPC_FUNC_IMPL(__imp__sub_88091068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88091070;
	__savegprlr_25(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// srawi r10,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 16;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// mulli r9,r9,52
	ctx.r9.s64 = ctx.r9.s64 * 52;
	// lwz r11,-11016(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11016);
	// lis r8,-30719
	ctx.r8.s64 = -2013200384;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-18560
	ctx.r6.s64 = ctx.r8.s64 + -18560;
	// li r5,0
	ctx.r5.s64 = 0;
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r31,r7,r6
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// rlwinm r10,r7,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r7,r9,3
	ctx.r7.s64 = ctx.r9.s64 + 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// slw r9,r4,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r7.u8 & 0x3F));
	// lbz r30,12(r11)
	ctx.r30.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// slw r28,r5,r10
	ctx.r28.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r10.u8 & 0x3F));
	// li r29,256
	ctx.r29.s64 = 256;
	// addi r27,r9,-1
	ctx.r27.s64 = ctx.r9.s64 + -1;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// subf r26,r5,r28
	ctx.r26.s64 = ctx.r28.s64 - ctx.r5.s64;
	// sraw r11,r29,r10
	temp.u32 = ctx.r10.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r29.s32 < 0) & (((ctx.r29.s32 >> temp.u32) << temp.u32) != ctx.r29.s32);
	ctx.r11.s64 = ctx.r29.s32 >> temp.u32;
	// extsb r9,r30
	ctx.r9.s64 = ctx.r30.s8;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// addi r6,r6,32
	ctx.r6.s64 = ctx.r6.s64 + 32;
	// rlwinm r8,r8,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r5,r6,16
	ctx.r5.u64 = ctx.r6.u32 & 0xFFFF;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// or r29,r27,r26
	ctx.r29.u64 = ctx.r27.u64 | ctx.r26.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8809118c
	if (ctx.cr6.eq) goto loc_8809118C;
	// lis r26,-30597
	ctx.r26.s64 = -2005204992;
	// lis r27,4352
	ctx.r27.s64 = 285212672;
	// lwz r11,-11892(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -11892);
loc_88091128:
	// addic. r9,r9,-32
	ctx.xer.ca = ctx.r9.u32 > 31;
	ctx.r9.s64 = ctx.r9.s64 + -32;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// beq 0x88091174
	if (ctx.cr0.eq) goto loc_88091174;
	// and r6,r9,r30
	ctx.r6.u64 = ctx.r9.u64 & ctx.r30.u64;
	// stw r27,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r27.u32);
	// subfic r25,r10,8
	ctx.xer.ca = ctx.r10.u32 <= 8;
	ctx.r25.s64 = 8 - ctx.r10.s64;
	// slw r6,r6,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// srw r9,r9,r25
	ctx.r9.u64 = ctx.r25.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r25.u8 & 0x3F));
	// slw r9,r9,r7
	ctx.r9.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// addi r6,r6,768
	ctx.r6.s64 = ctx.r6.s64 + 768;
	// add r9,r9,r31
	ctx.r9.u64 = ctx.r9.u64 + ctx.r31.u64;
	// rlwinm r6,r6,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// or r25,r5,r8
	ctx.r25.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 | ctx.r6.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// stwu r25,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r25.u32);
	ctx.r11.u32 = ea;
	// stwu r29,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r29.u32);
	ctx.r11.u32 = ea;
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_88091174:
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// add r8,r28,r8
	ctx.r8.u64 = ctx.r28.u64 + ctx.r8.u64;
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88091128
	if (!ctx.cr6.eq) goto loc_88091128;
	// stw r11,-11892(r26)
	PPC_STORE_U32(ctx.r26.u32 + -11892, ctx.r11.u32);
loc_8809118C:
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091190"))) PPC_WEAK_FUNC(sub_88091190);
PPC_FUNC_IMPL(__imp__sub_88091190) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r11,11776(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11776);
	// clrlwi r3,r11,1
	ctx.r3.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880911A0"))) PPC_WEAK_FUNC(sub_880911A0);
PPC_FUNC_IMPL(__imp__sub_880911A0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// oris r11,r3,32768
	ctx.r11.u64 = ctx.r3.u64 | 2147483648;
	// stw r11,11776(r10)
	PPC_STORE_U32(ctx.r10.u32 + 11776, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880911B0"))) PPC_WEAK_FUNC(sub_880911B0);
PPC_FUNC_IMPL(__imp__sub_880911B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11012(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11012);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880911C0"))) PPC_WEAK_FUNC(sub_880911C0);
PPC_FUNC_IMPL(__imp__sub_880911C0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// stw r11,-11012(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11012, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880911D0"))) PPC_WEAK_FUNC(sub_880911D0);
PPC_FUNC_IMPL(__imp__sub_880911D0) {
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
	// lis r31,-30597
	ctx.r31.s64 = -2005204992;
	// lwz r3,-11016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -11016);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880911f4
	if (ctx.cr6.eq) goto loc_880911F4;
	// bl 0x88083758
	ctx.lr = 0x880911F4;
	sub_88083758(ctx, base);
loc_880911F4:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-11016(r31)
	PPC_STORE_U32(ctx.r31.u32 + -11016, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_88091210"))) PPC_WEAK_FUNC(sub_88091210);
PPC_FUNC_IMPL(__imp__sub_88091210) {
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
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r3,5200
	ctx.r3.s64 = 5200;
	// bl 0x880836d0
	ctx.lr = 0x88091234;
	sub_880836D0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r31,r11,-11008
	ctx.r31.s64 = ctx.r11.s64 + -11008;
	// stw r3,-8(r31)
	PPC_STORE_U32(ctx.r31.u32 + -8, ctx.r3.u32);
	// beq cr6,0x88091274
	if (ctx.cr6.eq) goto loc_88091274;
	// li r5,5200
	ctx.r5.s64 = 5200;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88091254;
	sub_88073BD0(ctx, base);
	// lis r8,-30683
	ctx.r8.s64 = -2010841088;
	// lis r9,-32640
	ctx.r9.s64 = -2139095040;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r9,r9,32896
	ctx.r9.u64 = ctx.r9.u64 | 32896;
	// stw r11,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,11776(r8)
	PPC_STORE_U32(ctx.r8.u32 + 11776, ctx.r9.u32);
loc_88091274:
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

__attribute__((alias("__imp__sub_88091288"))) PPC_WEAK_FUNC(sub_88091288);
PPC_FUNC_IMPL(__imp__sub_88091288) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88091290;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r30,r11,-11012
	ctx.r30.s64 = ctx.r11.s64 + -11012;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8809135c
	if (ctx.cr6.eq) goto loc_8809135C;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_880912C0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880912e4
	if (ctx.cr6.eq) goto loc_880912E4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 + 52;
	// cmplwi cr6,r29,100
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 100, ctx.xer);
	// blt cr6,0x880912c0
	if (ctx.cr6.lt) goto loc_880912C0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_880912E4:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// mulli r31,r29,52
	ctx.r31.s64 = ctx.r29.s64 * 52;
	// lwz r9,11776(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11776);
	// add r11,r31,r10
	ctx.r11.u64 = ctx.r31.u64 + ctx.r10.u64;
	// stwx r9,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// li r6,39
	ctx.r6.s64 = 39;
	// li r4,40
	ctx.r4.s64 = 40;
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// bl 0x88070678
	ctx.lr = 0x88091310;
	sub_88070678(ctx, base);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// add r8,r31,r10
	ctx.r8.u64 = ctx.r31.u64 + ctx.r10.u64;
	// clrlwi r5,r28,16
	ctx.r5.u64 = ctx.r28.u32 & 0xFFFF;
	// stb r9,51(r8)
	PPC_STORE_U8(ctx.r8.u32 + 51, ctx.r9.u8);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// add r4,r11,r29
	ctx.r4.u64 = ctx.r11.u64 + ctx.r29.u64;
	// beq cr6,0x88091350
	if (ctx.cr6.eq) goto loc_88091350;
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// addi r3,r10,3896
	ctx.r3.s64 = ctx.r10.s64 + 3896;
	// bl 0x880939f0
	ctx.lr = 0x88091348;
	sub_880939F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88091350:
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// addi r3,r10,4200
	ctx.r3.s64 = ctx.r10.s64 + 4200;
	// bl 0x880939f0
	ctx.lr = 0x8809135C;
	sub_880939F0(ctx, base);
loc_8809135C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091364"))) PPC_WEAK_FUNC(sub_88091364);
PPC_FUNC_IMPL(__imp__sub_88091364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091368"))) PPC_WEAK_FUNC(sub_88091368);
PPC_FUNC_IMPL(__imp__sub_88091368) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88091370;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// addi r4,r11,11780
	ctx.r4.s64 = ctx.r11.s64 + 11780;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// bl 0x88070590
	ctx.lr = 0x88091398;
	sub_88070590(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x88070590
	ctx.lr = 0x880913A8;
	sub_88070590(ctx, base);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88091288
	ctx.lr = 0x880913BC;
	sub_88091288(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880913C4"))) PPC_WEAK_FUNC(sub_880913C4);
PPC_FUNC_IMPL(__imp__sub_880913C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880913C8"))) PPC_WEAK_FUNC(sub_880913C8);
PPC_FUNC_IMPL(__imp__sub_880913C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880913CC"))) PPC_WEAK_FUNC(sub_880913CC);
PPC_FUNC_IMPL(__imp__sub_880913CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880913D0"))) PPC_WEAK_FUNC(sub_880913D0);
PPC_FUNC_IMPL(__imp__sub_880913D0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880913D4"))) PPC_WEAK_FUNC(sub_880913D4);
PPC_FUNC_IMPL(__imp__sub_880913D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880913D8"))) PPC_WEAK_FUNC(sub_880913D8);
PPC_FUNC_IMPL(__imp__sub_880913D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lbz r11,-13965(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -13965);
	// clrlwi r3,r11,28
	ctx.r3.u64 = ctx.r11.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880913E8"))) PPC_WEAK_FUNC(sub_880913E8);
PPC_FUNC_IMPL(__imp__sub_880913E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// subfe r9,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r10,13264
	ctx.r11.s64 = ctx.r10.s64 + 13264;
	// mulli r8,r9,88
	ctx.r8.s64 = ctx.r9.s64 * 88;
	// addi r7,r11,12
	ctx.r7.s64 = ctx.r11.s64 + 12;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091408"))) PPC_WEAK_FUNC(sub_88091408);
PPC_FUNC_IMPL(__imp__sub_88091408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// subfe r9,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r10,13264
	ctx.r11.s64 = ctx.r10.s64 + 13264;
	// mulli r8,r9,88
	ctx.r8.s64 = ctx.r9.s64 * 88;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091428"))) PPC_WEAK_FUNC(sub_88091428);
PPC_FUNC_IMPL(__imp__sub_88091428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// subfe r9,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r11,r10,13264
	ctx.r11.s64 = ctx.r10.s64 + 13264;
	// mulli r8,r9,88
	ctx.r8.s64 = ctx.r9.s64 * 88;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r8,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091448"))) PPC_WEAK_FUNC(sub_88091448);
PPC_FUNC_IMPL(__imp__sub_88091448) {
	PPC_FUNC_PROLOGUE();
	// lis r4,-30628
	ctx.r4.s64 = -2007236608;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r11,r4,13264
	ctx.r11.s64 = ctx.r4.s64 + 13264;
	// addi r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 24;
	// lwz r7,13264(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13264);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// andc r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// lwz r8,92(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 92);
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// andc r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 & ~ctx.r6.u64;
	// stw r9,13264(r4)
	PPC_STORE_U32(ctx.r4.u32 + 13264, ctx.r9.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r7.u32);
	// stw r8,88(r11)
	PPC_STORE_U32(ctx.r11.u32 + 88, ctx.r8.u32);
loc_88091484:
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_88091498:
	// lwz r7,-20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -20);
	// and r4,r7,r9
	ctx.r4.u64 = ctx.r7.u64 & ctx.r9.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x880914e0
	if (ctx.cr6.eq) goto loc_880914E0;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x880914c4
	if (!ctx.cr6.eq) goto loc_880914C4;
	// lwz r7,-8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// b 0x880914e4
	goto loc_880914E4;
loc_880914C4:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// bne 0x880914e4
	if (!ctx.cr0.eq) goto loc_880914E4;
	// lwz r7,-4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// or r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// b 0x880914e4
	goto loc_880914E4;
loc_880914E0:
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
loc_880914E4:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rotlwi r9,r9,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// bdnz 0x88091498
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88091498;
	// stw r8,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r8.u32);
	// addic. r5,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// addi r10,r10,88
	ctx.r10.s64 = ctx.r10.s64 + 88;
	// bne 0x88091484
	if (!ctx.cr0.eq) goto loc_88091484;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091504"))) PPC_WEAK_FUNC(sub_88091504);
PPC_FUNC_IMPL(__imp__sub_88091504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091508"))) PPC_WEAK_FUNC(sub_88091508);
PPC_FUNC_IMPL(__imp__sub_88091508) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// lis r12,0
	ctx.r12.s64 = 0;
	// addi r8,r10,13264
	ctx.r8.s64 = ctx.r10.s64 + 13264;
	// ori r12,r12,45311
	ctx.r12.u64 = ctx.r12.u64 | 45311;
	// lhz r10,-10828(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + -10828);
	// addi r9,r11,-10828
	ctx.r9.s64 = ctx.r11.s64 + -10828;
	// and r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 & ctx.r12.u64;
	// lis r12,0
	ctx.r12.s64 = 0;
	// stw r10,92(r8)
	PPC_STORE_U32(ctx.r8.u32 + 92, ctx.r10.u32);
	// lhz r11,-4(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + -4);
	// ori r12,r12,45311
	ctx.r12.u64 = ctx.r12.u64 | 45311;
	// and r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 & ctx.r12.u64;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091544"))) PPC_WEAK_FUNC(sub_88091544);
PPC_FUNC_IMPL(__imp__sub_88091544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091548"))) PPC_WEAK_FUNC(sub_88091548);
PPC_FUNC_IMPL(__imp__sub_88091548) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809154C"))) PPC_WEAK_FUNC(sub_8809154C);
PPC_FUNC_IMPL(__imp__sub_8809154C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091550"))) PPC_WEAK_FUNC(sub_88091550);
PPC_FUNC_IMPL(__imp__sub_88091550) {
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
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r5,176
	ctx.r5.s64 = 176;
	// addi r31,r11,13264
	ctx.r31.s64 = ctx.r11.s64 + 13264;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88091578;
	sub_88073BD0(ctx, base);
	// li r11,16
	ctx.r11.s64 = 16;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_880915AC"))) PPC_WEAK_FUNC(sub_880915AC);
PPC_FUNC_IMPL(__imp__sub_880915AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880915B0"))) PPC_WEAK_FUNC(sub_880915B0);
PPC_FUNC_IMPL(__imp__sub_880915B0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// ori r8,r11,512
	ctx.r8.u64 = ctx.r11.u64 | 512;
	// or r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 | ctx.r5.u64;
	// rlwimi r6,r7,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// lwz r11,-11932(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11932);
	// rlwinm r6,r6,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// stw r11,-11932(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11932, ctx.r11.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880915EC"))) PPC_WEAK_FUNC(sub_880915EC);
PPC_FUNC_IMPL(__imp__sub_880915EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880915F0"))) PPC_WEAK_FUNC(sub_880915F0);
PPC_FUNC_IMPL(__imp__sub_880915F0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091600"))) PPC_WEAK_FUNC(sub_88091600);
PPC_FUNC_IMPL(__imp__sub_88091600) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmplwi cr6,r4,8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 8, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8809164c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809164C;
	// bdzf 4*cr6+eq,0x8809166c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809166C;
	// bdzf 4*cr6+eq,0x8809168c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809168C;
	// bdzf 4*cr6+eq,0x880916ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880916AC;
	// bdzf 4*cr6+eq,0x880916d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_880916D8;
	// bdzf 4*cr6+eq,0x88091704
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88091704;
	// bdzf 4*cr6+eq,0x88091720
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88091720;
	// bne cr6,0x8809172c
	if (!ctx.cr6.eq) goto loc_8809172C;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// blr 
	return;
loc_8809164C:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r8,r11,15,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF0000;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// blr 
	return;
loc_8809166C:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// blr 
	return;
loc_8809168C:
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// blr 
	return;
loc_880916AC:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r8,r11,15,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF0000;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r6,r10,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r4,r6,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// blr 
	return;
loc_880916D8:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r6,r10,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r4,r6,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// blr 
	return;
loc_88091704:
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// blr 
	return;
loc_88091720:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r8,r11,15,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF0000;
	// b 0x88091734
	goto loc_88091734;
loc_8809172C:
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r8,r11,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
loc_88091734:
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r7,40(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r5,r7,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r7.s64;
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091754"))) PPC_WEAK_FUNC(sub_88091754);
PPC_FUNC_IMPL(__imp__sub_88091754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091758"))) PPC_WEAK_FUNC(sub_88091758);
PPC_FUNC_IMPL(__imp__sub_88091758) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r4,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 26) & 0xFC000000;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091774"))) PPC_WEAK_FUNC(sub_88091774);
PPC_FUNC_IMPL(__imp__sub_88091774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091778"))) PPC_WEAK_FUNC(sub_88091778);
PPC_FUNC_IMPL(__imp__sub_88091778) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// lis r4,128
	ctx.r4.s64 = 8388608;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// ori r4,r4,32896
	ctx.r4.u64 = ctx.r4.u64 | 32896;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r5,4352
	ctx.r5.s64 = 285212672;
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// stw r4,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r4.u32);
	// stw r8,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r8.u32);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r6,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r6.u32);
	// stw r7,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r7.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880917BC"))) PPC_WEAK_FUNC(sub_880917BC);
PPC_FUNC_IMPL(__imp__sub_880917BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880917C0"))) PPC_WEAK_FUNC(sub_880917C0);
PPC_FUNC_IMPL(__imp__sub_880917C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r4,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// lwz r11,-11892(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11892);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 | ctx.r4.u64;
	// stwu r6,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r11.u32 = ea;
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r10,r5,16
	ctx.r10.u64 = ctx.r5.u32 & 0xFFFF;
	// or r9,r4,r10
	ctx.r9.u64 = ctx.r4.u64 | ctx.r10.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stwu r4,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r11.u32 = ea;
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,-11892(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11892, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091834"))) PPC_WEAK_FUNC(sub_88091834);
PPC_FUNC_IMPL(__imp__sub_88091834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091838"))) PPC_WEAK_FUNC(sub_88091838);
PPC_FUNC_IMPL(__imp__sub_88091838) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r11,-11032
	ctx.r10.s64 = ctx.r11.s64 + -11032;
	// lwz r11,-11032(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11032);
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809184C"))) PPC_WEAK_FUNC(sub_8809184C);
PPC_FUNC_IMPL(__imp__sub_8809184C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091850"))) PPC_WEAK_FUNC(sub_88091850);
PPC_FUNC_IMPL(__imp__sub_88091850) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11032
	ctx.r31.s64 = ctx.r11.s64 + -11032;
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88091878
	if (ctx.cr6.eq) goto loc_88091878;
	// bl 0x88083758
	ctx.lr = 0x88091878;
	sub_88083758(ctx, base);
loc_88091878:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88091888
	if (ctx.cr6.eq) goto loc_88091888;
	// bl 0x88083758
	ctx.lr = 0x88091888;
	sub_88083758(ctx, base);
loc_88091888:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r11,-8(r31)
	PPC_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_880918AC"))) PPC_WEAK_FUNC(sub_880918AC);
PPC_FUNC_IMPL(__imp__sub_880918AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880918B0"))) PPC_WEAK_FUNC(sub_880918B0);
PPC_FUNC_IMPL(__imp__sub_880918B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880918B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11020
	ctx.r31.s64 = ctx.r11.s64 + -11020;
	// lwz r3,-20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880918d4
	if (ctx.cr6.eq) goto loc_880918D4;
	// bl 0x88083758
	ctx.lr = 0x880918D4;
	sub_88083758(ctx, base);
loc_880918D4:
	// li r29,-1
	ctx.r29.s64 = -1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x880836d0
	ctx.lr = 0x880918EC;
	sub_880836D0(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,-20(r31)
	PPC_STORE_U32(ctx.r31.u32 + -20, ctx.r3.u32);
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_88091900:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x88091900
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88091900;
	// lis r30,-30683
	ctx.r30.s64 = -2010841088;
	// lwz r3,-12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,5000
	ctx.r11.s64 = 5000;
	// stw r10,-16(r31)
	PPC_STORE_U32(ctx.r31.u32 + -16, ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,11796(r30)
	PPC_STORE_U32(ctx.r30.u32 + 11796, ctx.r11.u32);
	// beq cr6,0x88091930
	if (ctx.cr6.eq) goto loc_88091930;
	// bl 0x88083758
	ctx.lr = 0x8809192C;
	sub_88083758(ctx, base);
	// lwz r11,11796(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11796);
loc_88091930:
	// mulli r3,r11,52
	ctx.r3.s64 = ctx.r11.s64 * 52;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x880836d0
	ctx.lr = 0x88091944;
	sub_880836D0(ctx, base);
	// lwz r11,11796(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11796);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,-12(r31)
	PPC_STORE_U32(ctx.r31.u32 + -12, ctx.r3.u32);
	// mulli r29,r11,52
	ctx.r29.s64 = ctx.r11.s64 * 52;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88091960;
	sub_88073BD0(ctx, base);
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// add r11,r29,r30
	ctx.r11.u64 = ctx.r29.u64 + ctx.r30.u64;
	// stw r30,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r9,12956
	ctx.r3.s64 = ctx.r9.s64 + 12956;
	// stw r11,-8(r31)
	PPC_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
	// li r5,52
	ctx.r5.s64 = 52;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88091988;
	sub_88073BD0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091990"))) PPC_WEAK_FUNC(sub_88091990);
PPC_FUNC_IMPL(__imp__sub_88091990) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x88091998;
	__savegprlr_23(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88091c24
	if (ctx.cr6.eq) goto loc_88091C24;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lwz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// extsh r31,r6
	ctx.r31.s64 = ctx.r6.s16;
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// add r7,r5,r9
	ctx.r7.u64 = ctx.r5.u64 + ctx.r9.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// add r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 + ctx.r9.u64;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r29,r7,-1
	ctx.r29.s64 = ctx.r7.s64 + -1;
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// addi r28,r9,-1
	ctx.r28.s64 = ctx.r9.s64 + -1;
	// cmpwi cr6,r11,7424
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7424, ctx.xer);
	// blt cr6,0x88091b04
	if (ctx.cr6.lt) goto loc_88091B04;
	// cmpwi cr6,r5,512
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 512, ctx.xer);
	// bge cr6,0x88091b04
	if (!ctx.cr6.lt) goto loc_88091B04;
	// add r9,r11,r8
	ctx.r9.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r5,r29
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r29.s32, ctx.xer);
	// bge cr6,0x88091c24
	if (!ctx.cr6.lt) goto loc_88091C24;
	// lis r25,-30597
	ctx.r25.s64 = -2005204992;
	// srawi r26,r29,8
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0xFF) != 0);
	ctx.r26.s64 = ctx.r29.s32 >> 8;
	// lwz r11,-11892(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -11892);
loc_88091A0C:
	// srawi r9,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 8;
	// subf r4,r5,r29
	ctx.r4.s64 = ctx.r29.s64 - ctx.r5.s64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// cmpw cr6,r9,r26
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x88091a30
	if (ctx.cr6.eq) goto loc_88091A30;
	// rlwinm r9,r5,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFF00;
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// addi r4,r9,255
	ctx.r4.s64 = ctx.r9.s64 + 255;
loc_88091A30:
	// addi r9,r4,1
	ctx.r9.s64 = ctx.r4.s64 + 1;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// cmpw cr6,r28,r6
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r6.s32, ctx.xer);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// bge cr6,0x88091ae4
	if (!ctx.cr6.lt) goto loc_88091AE4;
	// srawi r30,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r30.s64 = ctx.r6.s32 >> 8;
loc_88091A4C:
	// srawi r7,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 8;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// cmpw cr6,r7,r30
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x88091a64
	if (ctx.cr6.eq) goto loc_88091A64;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// subfic r9,r9,255
	ctx.xer.ca = ctx.r9.u32 <= 255;
	ctx.r9.s64 = 255 - ctx.r9.s64;
loc_88091A64:
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r9,1
	ctx.r24.s64 = ctx.r9.s64 + 1;
	// stw r10,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r24,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r24.u32);
	// rlwinm r23,r8,16,0,15
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// stw r23,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r23.u32);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r7,10(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// or r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// lwz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// blt cr6,0x88091a4c
	if (ctx.cr6.lt) goto loc_88091A4C;
loc_88091AE4:
	// add r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 + ctx.r5.u64;
	// add r9,r4,r31
	ctx.r9.u64 = ctx.r4.u64 + ctx.r31.u64;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// addi r31,r9,1
	ctx.r31.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r5,r29
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x88091a0c
	if (ctx.cr6.lt) goto loc_88091A0C;
	// stw r11,-11892(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11892, ctx.r11.u32);
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_88091B04:
	// cmpwi cr6,r10,7424
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7424, ctx.xer);
	// blt cr6,0x88091c24
	if (ctx.cr6.lt) goto loc_88091C24;
	// cmpwi cr6,r31,512
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 512, ctx.xer);
	// bge cr6,0x88091c24
	if (!ctx.cr6.lt) goto loc_88091C24;
	// mr r29,r10
	ctx.r29.u64 = ctx.r10.u64;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmpw cr6,r31,r28
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x88091c24
	if (!ctx.cr6.lt) goto loc_88091C24;
	// lis r25,-30597
	ctx.r25.s64 = -2005204992;
	// srawi r26,r28,8
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0xFF) != 0);
	ctx.r26.s64 = ctx.r28.s32 >> 8;
	// lwz r11,-11892(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -11892);
loc_88091B30:
	// srawi r9,r31,8
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r31.s32 >> 8;
	// subf r4,r31,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r31.s64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// cmpw cr6,r9,r26
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r26.s32, ctx.xer);
	// beq cr6,0x88091b54
	if (ctx.cr6.eq) goto loc_88091B54;
	// rlwinm r9,r31,0,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0xFFFFFF00;
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r31.s64;
	// addi r4,r9,255
	ctx.r4.s64 = ctx.r9.s64 + 255;
loc_88091B54:
	// addi r9,r4,1
	ctx.r9.s64 = ctx.r4.s64 + 1;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// cmpw cr6,r29,r6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r6.s32, ctx.xer);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// bge cr6,0x88091c08
	if (!ctx.cr6.lt) goto loc_88091C08;
	// srawi r30,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r30.s64 = ctx.r6.s32 >> 8;
loc_88091B70:
	// srawi r7,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 8;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// cmpw cr6,r7,r30
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r30.s32, ctx.xer);
	// beq cr6,0x88091b88
	if (ctx.cr6.eq) goto loc_88091B88;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// subfic r9,r9,255
	ctx.xer.ca = ctx.r9.u32 <= 255;
	ctx.r9.s64 = 255 - ctx.r9.s64;
loc_88091B88:
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r24,r10,16,0,15
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addi r23,r9,1
	ctx.r23.s64 = ctx.r9.s64 + 1;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r24,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r24.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r23,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r23.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// lwz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// lhz r9,10(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// or r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 | ctx.r7.u64;
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// lwz r9,40(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// rlwinm r7,r7,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// or r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 | ctx.r9.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// lwz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// blt cr6,0x88091b70
	if (ctx.cr6.lt) goto loc_88091B70;
loc_88091C08:
	// add r10,r4,r31
	ctx.r10.u64 = ctx.r4.u64 + ctx.r31.u64;
	// add r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r31,r28
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r28.s32, ctx.xer);
	// blt cr6,0x88091b30
	if (ctx.cr6.lt) goto loc_88091B30;
	// stw r11,-11892(r25)
	PPC_STORE_U32(ctx.r25.u32 + -11892, ctx.r11.u32);
loc_88091C24:
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091C28"))) PPC_WEAK_FUNC(sub_88091C28);
PPC_FUNC_IMPL(__imp__sub_88091C28) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88091C30;
	__savegprlr_29(ctx, base);
	// lis r30,-30628
	ctx.r30.s64 = -2007236608;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,128
	ctx.r4.s64 = 8388608;
	// addi r29,r30,12956
	ctx.r29.s64 = ctx.r30.s64 + 12956;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r10,r10,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r4,r4,32896
	ctx.r4.u64 = ctx.r4.u64 | 32896;
	// lis r31,4352
	ctx.r31.s64 = 285212672;
	// stw r9,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r10.u32);
	// stw r8,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r8.u32);
	// stw r7,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r7.u32);
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// stw r6,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r6.u32);
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// stw r5,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r5.u32);
	// stw r4,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r4.u32);
	// stw r31,12956(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12956, ctx.r31.u32);
	// stw r10,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r10.u32);
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091C98"))) PPC_WEAK_FUNC(sub_88091C98);
PPC_FUNC_IMPL(__imp__sub_88091C98) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1500
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1500, ctx.xer);
	// bge cr6,0x88091d54
	if (!ctx.cr6.lt) goto loc_88091D54;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r10,17440
	ctx.r11.s64 = ctx.r10.s64 + 17440;
	// lwzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88091d54
	if (ctx.cr6.eq) goto loc_88091D54;
	// lis r9,-30719
	ctx.r9.s64 = -2013200384;
	// lwz r6,20(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r8,r9,-22560
	ctx.r8.s64 = ctx.r9.s64 + -22560;
	// lwz r3,16(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r31,r8,4
	ctx.r31.s64 = ctx.r8.s64 + 4;
	// lwz r5,12(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// add r30,r7,r8
	ctx.r30.u64 = ctx.r7.u64 + ctx.r8.u64;
	// lwz r8,24(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// add r4,r7,r31
	ctx.r4.u64 = ctx.r7.u64 + ctx.r31.u64;
	// stw r6,-4448(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4448, ctx.r6.u32);
	// lis r6,128
	ctx.r6.s64 = 8388608;
	// stw r10,-4468(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4468, ctx.r10.u32);
	// rlwinm r9,r9,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,-4476(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4476, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r30,-8(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + -8);
	// ori r6,r6,32896
	ctx.r6.u64 = ctx.r6.u64 | 32896;
	// lwz r31,-8(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + -8);
	// lis r4,4352
	ctx.r4.s64 = 285212672;
	// stw r8,-4444(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4444, ctx.r8.u32);
	// add r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 + ctx.r30.u64;
	// add r8,r3,r31
	ctx.r8.u64 = ctx.r3.u64 + ctx.r31.u64;
	// stw r9,-4472(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4472, ctx.r9.u32);
	// stw r7,-4440(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4440, ctx.r7.u32);
	// addi r3,r11,-4484
	ctx.r3.s64 = ctx.r11.s64 + -4484;
	// stw r6,-4436(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4436, ctx.r6.u32);
	// stw r5,-4456(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4456, ctx.r5.u32);
	// stw r8,-4452(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4452, ctx.r8.u32);
	// stw r4,-4484(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4484, ctx.r4.u32);
	// stw r9,-4480(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4480, ctx.r9.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_88091D54:
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091D64"))) PPC_WEAK_FUNC(sub_88091D64);
PPC_FUNC_IMPL(__imp__sub_88091D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091D68"))) PPC_WEAK_FUNC(sub_88091D68);
PPC_FUNC_IMPL(__imp__sub_88091D68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mulli r9,r3,52
	ctx.r9.s64 = ctx.r3.s64 * 52;
	// lwz r10,-11032(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11032);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,-11892(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -11892);
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// lwz r5,32(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r4,28(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// rlwinm r3,r4,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// or r9,r3,r5
	ctx.r9.u64 = ctx.r3.u64 | ctx.r5.u64;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r6,r9,32
	ctx.r6.s64 = ctx.r9.s64 + 32;
	// addis r5,r8,32
	ctx.r5.s64 = ctx.r8.s64 + 2097152;
	// clrlwi r4,r6,16
	ctx.r4.u64 = ctx.r6.u32 & 0xFFFF;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r8,36(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// rlwinm r5,r8,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stwu r4,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r11.u32 = ea;
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,-11892(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11892, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88091DE8"))) PPC_WEAK_FUNC(sub_88091DE8);
PPC_FUNC_IMPL(__imp__sub_88091DE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88091DF0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r30,r11,-11032
	ctx.r30.s64 = ctx.r11.s64 + -11032;
	// lwz r31,8(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x88091ee8
	if (!ctx.cr6.lt) goto loc_88091EE8;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1500
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1500, ctx.xer);
	// bge cr6,0x88091ee8
	if (!ctx.cr6.lt) goto loc_88091EE8;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,17440
	ctx.r8.s64 = ctx.r10.s64 + 17440;
	// lwzx r11,r9,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88091ee8
	if (ctx.cr6.eq) goto loc_88091EE8;
	// lis r9,-30719
	ctx.r9.s64 = -2013200384;
	// lwz r6,4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// addi r11,r9,-22560
	ctx.r11.s64 = ctx.r9.s64 + -22560;
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r29,24(r4)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// lis r28,128
	ctx.r28.s64 = 8388608;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// subf r26,r11,r31
	ctx.r26.s64 = ctx.r31.s64 - ctx.r11.s64;
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r5,r5,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r10,-8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + -8);
	// ori r28,r28,32896
	ctx.r28.u64 = ctx.r28.u64 | 32896;
	// lwz r11,-8(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// lis r9,4352
	ctx.r9.s64 = 285212672;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// stw r5,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r5.u32);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// li r11,52
	ctx.r11.s64 = 52;
	// stw r25,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r25.u32);
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// clrlwi r5,r4,16
	ctx.r5.u64 = ctx.r4.u32 & 0xFFFF;
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// divw r4,r26,r11
	ctx.r4.s32 = ppc_divw(ctx.r26.s32, ctx.r11.s32);
	// stw r28,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r28.u32);
	// addi r3,r10,7528
	ctx.r3.s64 = ctx.r10.s64 + 7528;
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// stw r7,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r7.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bl 0x880939f0
	ctx.lr = 0x88091ED4;
	sub_880939F0(ctx, base);
	// addi r11,r31,52
	ctx.r11.s64 = ctx.r31.s64 + 52;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88091EE8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88091EF4"))) PPC_WEAK_FUNC(sub_88091EF4);
PPC_FUNC_IMPL(__imp__sub_88091EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88091EF8"))) PPC_WEAK_FUNC(sub_88091EF8);
PPC_FUNC_IMPL(__imp__sub_88091EF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88091F00;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// addi r30,r10,-11032
	ctx.r30.s64 = ctx.r10.s64 + -11032;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x88092000
	if (!ctx.cr6.lt) goto loc_88092000;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -8);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88092000
	if (ctx.cr6.eq) goto loc_88092000;
	// lwz r31,8(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x88092000
	if (!ctx.cr6.lt) goto loc_88092000;
	// lis r5,-30719
	ctx.r5.s64 = -2013200384;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r5,-22560
	ctx.r10.s64 = ctx.r5.s64 + -22560;
	// lwz r29,16(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// clrlwi r5,r8,16
	ctx.r5.u64 = ctx.r8.u32 & 0xFFFF;
	// lwz r28,12(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lis r8,128
	ctx.r8.s64 = 8388608;
	// subf r27,r11,r31
	ctx.r27.s64 = ctx.r31.s64 - ctx.r11.s64;
	// rlwinm r4,r4,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// lwz r10,-8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// ori r8,r8,32896
	ctx.r8.u64 = ctx.r8.u64 | 32896;
	// lwz r9,-8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// li r26,0
	ctx.r26.s64 = 0;
	// add r11,r7,r10
	ctx.r11.u64 = ctx.r7.u64 + ctx.r10.u64;
	// stw r4,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r4.u32);
	// add r10,r3,r9
	ctx.r10.u64 = ctx.r3.u64 + ctx.r9.u64;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// lis r7,4352
	ctx.r7.s64 = 285212672;
	// stw r5,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r5.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// li r4,52
	ctx.r4.s64 = 52;
	// stw r26,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r26.u32);
	// lis r3,-30711
	ctx.r3.s64 = -2012676096;
	// stw r8,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// stw r28,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r28.u32);
	// divw r4,r27,r4
	ctx.r4.s32 = ppc_divw(ctx.r27.s32, ctx.r4.s32);
	// stw r29,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r29.u32);
	// addi r3,r3,7528
	ctx.r3.s64 = ctx.r3.s64 + 7528;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// bl 0x880939f0
	ctx.lr = 0x88091FEC;
	sub_880939F0(ctx, base);
	// addi r11,r31,52
	ctx.r11.s64 = ctx.r31.s64 + 52;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_88092000:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809200C"))) PPC_WEAK_FUNC(sub_8809200C);
PPC_FUNC_IMPL(__imp__sub_8809200C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092010"))) PPC_WEAK_FUNC(sub_88092010);
PPC_FUNC_IMPL(__imp__sub_88092010) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,11800(r10)
	PPC_STORE_U32(ctx.r10.u32 + 11800, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092020"))) PPC_WEAK_FUNC(sub_88092020);
PPC_FUNC_IMPL(__imp__sub_88092020) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r11,11800(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11800);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-11052
	ctx.r11.s64 = ctx.r11.s64 + -11052;
	// lhz r9,224(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 224);
	// lhz r10,220(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 220);
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// rlwimi r10,r9,16,0,15
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFFFF0000) | (ctx.r10.u64 & 0xFFFFFFFF0000FFFF);
	// xor r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r10.u32);
	// and r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ctx.r10.u64;
	// rlwinm r8,r9,0,17,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x88092074
	if (ctx.cr6.eq) goto loc_88092074;
	// lwz r10,-12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x88092090
	goto loc_88092090;
loc_88092074:
	// rlwinm r10,r9,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,-12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// li r3,1
	ctx.r3.s64 = 1;
loc_88092090:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,-12(r11)
	PPC_STORE_U32(ctx.r11.u32 + -12, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_880920A4"))) PPC_WEAK_FUNC(sub_880920A4);
PPC_FUNC_IMPL(__imp__sub_880920A4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880920A8"))) PPC_WEAK_FUNC(sub_880920A8);
PPC_FUNC_IMPL(__imp__sub_880920A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r11,-11048
	ctx.r11.s64 = ctx.r11.s64 + -11048;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addic r8,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// subfe r4,r8,r10
	temp.u8 = (~ctx.r8.u32 + ctx.r10.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r8.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_880920DC"))) PPC_WEAK_FUNC(sub_880920DC);
PPC_FUNC_IMPL(__imp__sub_880920DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880920E0"))) PPC_WEAK_FUNC(sub_880920E0);
PPC_FUNC_IMPL(__imp__sub_880920E0) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addic r10,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// addi r31,r11,-11048
	ctx.r31.s64 = ctx.r11.s64 + -11048;
	// subfe r4,r10,r3
	temp.u8 = (~ctx.r10.u32 + ctx.r3.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r10.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092114
	if (ctx.cr6.eq) goto loc_88092114;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// stw r3,-16(r31)
	PPC_STORE_U32(ctx.r31.u32 + -16, ctx.r3.u32);
loc_88092114:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88092138
	if (ctx.cr6.eq) goto loc_88092138;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x88092134;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
loc_88092138:
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

__attribute__((alias("__imp__sub_8809214C"))) PPC_WEAK_FUNC(sub_8809214C);
PPC_FUNC_IMPL(__imp__sub_8809214C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092150"))) PPC_WEAK_FUNC(sub_88092150);
PPC_FUNC_IMPL(__imp__sub_88092150) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r3,-11064(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11064);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809215C"))) PPC_WEAK_FUNC(sub_8809215C);
PPC_FUNC_IMPL(__imp__sub_8809215C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092160"))) PPC_WEAK_FUNC(sub_88092160);
PPC_FUNC_IMPL(__imp__sub_88092160) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092170
	if (ctx.cr6.eq) goto loc_88092170;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_88092170:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11064(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11064);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092188"))) PPC_WEAK_FUNC(sub_88092188);
PPC_FUNC_IMPL(__imp__sub_88092188) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809218C"))) PPC_WEAK_FUNC(sub_8809218C);
PPC_FUNC_IMPL(__imp__sub_8809218C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092190"))) PPC_WEAK_FUNC(sub_88092190);
PPC_FUNC_IMPL(__imp__sub_88092190) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092194"))) PPC_WEAK_FUNC(sub_88092194);
PPC_FUNC_IMPL(__imp__sub_88092194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092198"))) PPC_WEAK_FUNC(sub_88092198);
PPC_FUNC_IMPL(__imp__sub_88092198) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809219C"))) PPC_WEAK_FUNC(sub_8809219C);
PPC_FUNC_IMPL(__imp__sub_8809219C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880921A0"))) PPC_WEAK_FUNC(sub_880921A0);
PPC_FUNC_IMPL(__imp__sub_880921A0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880921A4"))) PPC_WEAK_FUNC(sub_880921A4);
PPC_FUNC_IMPL(__imp__sub_880921A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880921A8"))) PPC_WEAK_FUNC(sub_880921A8);
PPC_FUNC_IMPL(__imp__sub_880921A8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r10,r11,-11044
	ctx.r10.s64 = ctx.r11.s64 + -11044;
	// stw r4,-11044(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11044, ctx.r4.u32);
	// stw r3,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880921BC"))) PPC_WEAK_FUNC(sub_880921BC);
PPC_FUNC_IMPL(__imp__sub_880921BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880921C0"))) PPC_WEAK_FUNC(sub_880921C0);
PPC_FUNC_IMPL(__imp__sub_880921C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30704
	ctx.r11.s64 = -2012217344;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addi r11,r11,1200
	ctx.r11.s64 = ctx.r11.s64 + 1200;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880921dc
	if (!ctx.cr6.eq) goto loc_880921DC;
	// lis r11,-30711
	ctx.r11.s64 = -2012676096;
	// addi r11,r11,8608
	ctx.r11.s64 = ctx.r11.s64 + 8608;
loc_880921DC:
	// stw r11,-11052(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11052, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880921E4"))) PPC_WEAK_FUNC(sub_880921E4);
PPC_FUNC_IMPL(__imp__sub_880921E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880921E8"))) PPC_WEAK_FUNC(sub_880921E8);
PPC_FUNC_IMPL(__imp__sub_880921E8) {
	PPC_FUNC_PROLOGUE();
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r6,r7,-11052
	ctx.r6.s64 = ctx.r7.s64 + -11052;
	// lis r8,-30711
	ctx.r8.s64 = -2012676096;
	// lis r5,-30683
	ctx.r5.s64 = -2010841088;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-12(r6)
	PPC_STORE_U32(ctx.r6.u32 + -12, ctx.r11.u32);
	// addi r8,r8,8608
	ctx.r8.s64 = ctx.r8.s64 + 8608;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r10,-8(r6)
	PPC_STORE_U32(ctx.r6.u32 + -8, ctx.r10.u32);
	// stw r9,-4(r6)
	PPC_STORE_U32(ctx.r6.u32 + -4, ctx.r9.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r8,-11052(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11052, ctx.r8.u32);
	// stw r11,11800(r5)
	PPC_STORE_U32(ctx.r5.u32 + 11800, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092228"))) PPC_WEAK_FUNC(sub_88092228);
PPC_FUNC_IMPL(__imp__sub_88092228) {
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
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r31,r11,12928
	ctx.r31.s64 = ctx.r11.s64 + 12928;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x88092248;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r9,r10,-11076
	ctx.r9.s64 = ctx.r10.s64 + -11076;
	// lwz r11,-4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// lwz r10,-11076(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11076);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r31,r7,27,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x8824eae0
	ctx.lr = 0x8809226C;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

__attribute__((alias("__imp__sub_88092284"))) PPC_WEAK_FUNC(sub_88092284);
PPC_FUNC_IMPL(__imp__sub_88092284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092288"))) PPC_WEAK_FUNC(sub_88092288);
PPC_FUNC_IMPL(__imp__sub_88092288) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88092290;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r11,11804(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11804);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x88092308
	if (ctx.cr6.eq) goto loc_88092308;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r31,r11,12928
	ctx.r31.s64 = ctx.r11.s64 + 12928;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880922B4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,-11072(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11072, ctx.r11.u32);
	// bl 0x8824eae0
	ctx.lr = 0x880922C8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880922D0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,-11072(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11072);
	// bl 0x8824eae0
	ctx.lr = 0x880922DC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x88092308
	if (ctx.cr6.eq) goto loc_88092308;
loc_880922E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88082ca0
	ctx.lr = 0x880922EC;
	sub_88082CA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880922F4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,-11072(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11072);
	// bl 0x8824eae0
	ctx.lr = 0x88092300;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x880922e4
	if (!ctx.cr6.eq) goto loc_880922E4;
loc_88092308:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88092310"))) PPC_WEAK_FUNC(sub_88092310);
PPC_FUNC_IMPL(__imp__sub_88092310) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88092318;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,13008
	ctx.r30.s64 = ctx.r11.s64 + 13008;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r3,r30,-80
	ctx.r3.s64 = ctx.r30.s64 + -80;
	// bl 0x8824ead0
	ctx.lr = 0x88092334;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-11076
	ctx.r11.s64 = ctx.r11.s64 + -11076;
	// add r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 + ctx.r10.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,-788(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -788);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88092388
	if (!ctx.cr6.eq) goto loc_88092388;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + -4);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// clrlwi r8,r8,26
	ctx.r8.u64 = ctx.r8.u32 & 0x3F;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x88092388
	if (ctx.cr6.eq) goto loc_88092388;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r8.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// stwx r31,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + ctx.r30.u32, ctx.r31.u32);
loc_88092388:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x88092398
	if (ctx.cr6.eq) goto loc_88092398;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
loc_88092398:
	// addi r3,r30,-80
	ctx.r3.s64 = ctx.r30.s64 + -80;
	// bl 0x8824eae0
	ctx.lr = 0x880923A0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880923A8"))) PPC_WEAK_FUNC(sub_880923A8);
PPC_FUNC_IMPL(__imp__sub_880923A8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r9,r10,-11344
	ctx.r9.s64 = ctx.r10.s64 + -11344;
	// subf r10,r3,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r3.s64;
loc_880923B8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x880923b8
	if (!ctx.cr6.eq) goto loc_880923B8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880923D0"))) PPC_WEAK_FUNC(sub_880923D0);
PPC_FUNC_IMPL(__imp__sub_880923D0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// beq cr6,0x88092400
	if (ctx.cr6.eq) goto loc_88092400;
	// addi r9,r10,-11600
	ctx.r9.s64 = ctx.r10.s64 + -11600;
	// subf r10,r3,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r3.s64;
loc_880923E8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x880923e8
	if (!ctx.cr6.eq) goto loc_880923E8;
	// blr 
	return;
loc_88092400:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r8,r10,-11600
	ctx.r8.s64 = ctx.r10.s64 + -11600;
	// addi r9,r11,11852
	ctx.r9.s64 = ctx.r11.s64 + 11852;
	// lwz r7,11852(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11852);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lbz r4,12(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 12);
	// stw r7,-11600(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11600, ctx.r7.u32);
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// stw r5,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r5.u32);
	// stb r4,12(r8)
	PPC_STORE_U8(ctx.r8.u32 + 12, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092430"))) PPC_WEAK_FUNC(sub_88092430);
PPC_FUNC_IMPL(__imp__sub_88092430) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-11856
	ctx.r10.s64 = ctx.r10.s64 + -11856;
	// addi r9,r9,12932
	ctx.r9.s64 = ctx.r9.s64 + 12932;
loc_88092444:
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stbx r8,r11,r10
	PPC_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x88092444
	if (!ctx.cr6.eq) goto loc_88092444;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809245C"))) PPC_WEAK_FUNC(sub_8809245C);
PPC_FUNC_IMPL(__imp__sub_8809245C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092460"))) PPC_WEAK_FUNC(sub_88092460);
PPC_FUNC_IMPL(__imp__sub_88092460) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88092468;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r11,11804(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11804);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x880924e0
	if (ctx.cr6.eq) goto loc_880924E0;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r31,r11,12928
	ctx.r31.s64 = ctx.r11.s64 + 12928;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x8809248C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r30,-30597
	ctx.r30.s64 = -2005204992;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,-11860(r30)
	PPC_STORE_U32(ctx.r30.u32 + -11860, ctx.r11.u32);
	// bl 0x8824eae0
	ctx.lr = 0x880924A0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880924A8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,-11860(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11860);
	// bl 0x8824eae0
	ctx.lr = 0x880924B4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x880924e0
	if (ctx.cr6.eq) goto loc_880924E0;
loc_880924BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x88082ca0
	ctx.lr = 0x880924C4;
	sub_88082CA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8824ead0
	ctx.lr = 0x880924CC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r29,-11860(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + -11860);
	// bl 0x8824eae0
	ctx.lr = 0x880924D8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x880924bc
	if (!ctx.cr6.eq) goto loc_880924BC;
loc_880924E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880924E8"))) PPC_WEAK_FUNC(sub_880924E8);
PPC_FUNC_IMPL(__imp__sub_880924E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880924F0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r10,6784
	ctx.r31.s64 = ctx.r10.s64 + 6784;
	// lis r11,-30700
	ctx.r11.s64 = -2011955200;
	// addi r3,r31,6144
	ctx.r3.s64 = ctx.r31.s64 + 6144;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r27,r11,-22880
	ctx.r27.s64 = ctx.r11.s64 + -22880;
	// li r26,0
	ctx.r26.s64 = 0;
	// bl 0x8824ead0
	ctx.lr = 0x8809251C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r11,-11876(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11876);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8809259c
	if (!ctx.cr6.lt) goto loc_8809259C;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// lwz r10,11808(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11808);
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x8809259c
	if (!ctx.cr6.eq) goto loc_8809259C;
	// addi r7,r31,4
	ctx.r7.s64 = ctx.r31.s64 + 4;
	// stwx r30,r11,r31
	PPC_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r30.u32);
	// addi r6,r31,8
	ctx.r6.s64 = ctx.r31.s64 + 8;
	// addi r5,r31,12
	ctx.r5.s64 = ctx.r31.s64 + 12;
	// addi r4,r31,20
	ctx.r4.s64 = ctx.r31.s64 + 20;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// stwx r29,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r29.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r27,r11,r6
	PPC_STORE_U32(ctx.r11.u32 + ctx.r6.u32, ctx.r27.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// stwx r28,r11,r5
	PPC_STORE_U32(ctx.r11.u32 + ctx.r5.u32, ctx.r28.u32);
	// stwx r3,r11,r4
	PPC_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r3.u32);
	// cmplwi cr6,r10,256
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 256, ctx.xer);
	// stw r10,11808(r9)
	PPC_STORE_U32(ctx.r9.u32 + 11808, ctx.r10.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r7.u32);
	// blt cr6,0x8809259c
	if (ctx.cr6.lt) goto loc_8809259C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,11808(r9)
	PPC_STORE_U32(ctx.r9.u32 + 11808, ctx.r11.u32);
loc_8809259C:
	// addi r3,r31,6144
	ctx.r3.s64 = ctx.r31.s64 + 6144;
	// bl 0x8824eae0
	ctx.lr = 0x880925A4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880925B0"))) PPC_WEAK_FUNC(sub_880925B0);
PPC_FUNC_IMPL(__imp__sub_880925B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-11864
	ctx.r11.s64 = ctx.r11.s64 + -11864;
	// lwz r10,-12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x880925e4
	if (!ctx.cr6.lt) goto loc_880925E4;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r3,3(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 3);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_880925E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880925EC"))) PPC_WEAK_FUNC(sub_880925EC);
PPC_FUNC_IMPL(__imp__sub_880925EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880925F0"))) PPC_WEAK_FUNC(sub_880925F0);
PPC_FUNC_IMPL(__imp__sub_880925F0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-11864
	ctx.r11.s64 = ctx.r11.s64 + -11864;
	// lwz r10,-12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x88092620
	if (!ctx.cr6.lt) goto loc_88092620;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r3,2(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// blr 
	return;
loc_88092620:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092628"))) PPC_WEAK_FUNC(sub_88092628);
PPC_FUNC_IMPL(__imp__sub_88092628) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-11864
	ctx.r11.s64 = ctx.r11.s64 + -11864;
	// lwz r10,-12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12);
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x88092658
	if (!ctx.cr6.lt) goto loc_88092658;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// blr 
	return;
loc_88092658:
	// lis r3,2
	ctx.r3.s64 = 131072;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092660"))) PPC_WEAK_FUNC(sub_88092660);
PPC_FUNC_IMPL(__imp__sub_88092660) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88092664"))) PPC_WEAK_FUNC(sub_88092664);
PPC_FUNC_IMPL(__imp__sub_88092664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092668"))) PPC_WEAK_FUNC(sub_88092668);
PPC_FUNC_IMPL(__imp__sub_88092668) {
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
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11068
	ctx.r31.s64 = ctx.r11.s64 + -11068;
	// lbz r11,-276(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88092790
	if (ctx.cr6.eq) goto loc_88092790;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
loc_88092698:
	// addi r9,r31,-532
	ctx.r9.s64 = ctx.r31.s64 + -532;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stbx r8,r11,r10
	PPC_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x88092698
	if (!ctx.cr6.eq) goto loc_88092698;
	// addi r10,r31,-276
	ctx.r10.s64 = ctx.r31.s64 + -276;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
loc_880926B8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x880926b8
	if (!ctx.cr6.eq) goto loc_880926B8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_880926CC:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x880926cc
	if (!ctx.cr6.eq) goto loc_880926CC;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x88082990
	ctx.lr = 0x88092704;
	sub_88082990(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x88092768
	if (ctx.cr6.eq) goto loc_88092768;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88082b88
	ctx.lr = 0x88092718;
	sub_88082B88(ctx, base);
	// cmplwi cr6,r3,3184
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3184, ctx.xer);
	// bne cr6,0x88092768
	if (!ctx.cr6.eq) goto loc_88092768;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x880836d0
	ctx.lr = 0x88092730;
	sub_880836D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092780
	if (ctx.cr6.eq) goto loc_88092780;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,3184
	ctx.r5.s64 = 3184;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88082d48
	ctx.lr = 0x88092754;
	sub_88082D48(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88092768
	if (ctx.cr6.eq) goto loc_88092768;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,3184
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3184, ctx.xer);
	// beq cr6,0x88092788
	if (ctx.cr6.eq) goto loc_88092788;
loc_88092768:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092780
	if (ctx.cr6.eq) goto loc_88092780;
	// bl 0x88083758
	ctx.lr = 0x88092778;
	sub_88083758(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_88092780:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x88092790
	if (ctx.cr6.eq) goto loc_88092790;
loc_88092788:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88083178
	ctx.lr = 0x88092790;
	sub_88083178(ctx, base);
loc_88092790:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
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

__attribute__((alias("__imp__sub_880927A8"))) PPC_WEAK_FUNC(sub_880927A8);
PPC_FUNC_IMPL(__imp__sub_880927A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880927B0;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// lis r9,-30683
	ctx.r9.s64 = -2010841088;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// std r30,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r30.u64);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// std r30,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r30.u64);
	// stw r30,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r30.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,11804(r9)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11804);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88082ca8
	ctx.lr = 0x880927F4;
	sub_88082CA8(ctx, base);
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88082d48
	ctx.lr = 0x88092810;
	sub_88082D48(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88083170
	ctx.lr = 0x88092818;
	sub_88083170(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x88092828
	if (!ctx.cr6.eq) goto loc_88092828;
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x8809287c
	if (!ctx.cr6.eq) goto loc_8809287C;
loc_88092828:
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// li r31,-1
	ctx.r31.s64 = -1;
loc_88092830:
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x88082c38
	ctx.lr = 0x88092840;
	sub_88082C38(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88092830
	if (!ctx.cr6.eq) goto loc_88092830;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88082ec8
	ctx.lr = 0x8809285C;
	sub_88082EC8(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x88092874
	if (ctx.cr6.eq) goto loc_88092874;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x8809287c
	goto loc_8809287C;
loc_88092874:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8809288c
	if (!ctx.cr6.eq) goto loc_8809288C;
loc_8809287C:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x88073bd0
	ctx.lr = 0x8809288C;
	sub_88073BD0(ctx, base);
loc_8809288C:
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x88083178
	ctx.lr = 0x88092894;
	sub_88083178(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880928A0"))) PPC_WEAK_FUNC(sub_880928A0);
PPC_FUNC_IMPL(__imp__sub_880928A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r3,11804(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11804);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x880928b8
	if (!ctx.cr6.eq) goto loc_880928B8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880928B8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88082b88
	sub_88082B88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880928C0"))) PPC_WEAK_FUNC(sub_880928C0);
PPC_FUNC_IMPL(__imp__sub_880928C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r3,11804(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 11804);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x88083178
	sub_88083178(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880928D4"))) PPC_WEAK_FUNC(sub_880928D4);
PPC_FUNC_IMPL(__imp__sub_880928D4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880928D8"))) PPC_WEAK_FUNC(sub_880928D8);
PPC_FUNC_IMPL(__imp__sub_880928D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11856
	ctx.r31.s64 = ctx.r11.s64 + -11856;
	// lbz r11,256(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 256);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88092950
	if (ctx.cr6.eq) goto loc_88092950;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_88092904:
	// addi r9,r31,256
	ctx.r9.s64 = ctx.r31.s64 + 256;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stbx r8,r11,r10
	PPC_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x88092904
	if (!ctx.cr6.eq) goto loc_88092904;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_88092920:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88092920
	if (!ctx.cr6.eq) goto loc_88092920;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_88092934:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x88092934
	if (!ctx.cr6.eq) goto loc_88092934;
	// b 0x88092994
	goto loc_88092994;
loc_88092950:
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,11816
	ctx.r4.s64 = ctx.r11.s64 + 11816;
	// li r5,13
	ctx.r5.s64 = 13;
	// bl 0x88072260
	ctx.lr = 0x88092964;
	sub_88072260(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_88092968:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88092968
	if (!ctx.cr6.eq) goto loc_88092968;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8809297C:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x8809297c
	if (!ctx.cr6.eq) goto loc_8809297C;
loc_88092994:
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,16384
	ctx.r8.s64 = 1073741824;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-32768
	ctx.r4.s64 = -2147483648;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x88082990
	ctx.lr = 0x880929B4;
	sub_88082990(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880929C8"))) PPC_WEAK_FUNC(sub_880929C8);
PPC_FUNC_IMPL(__imp__sub_880929C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880929D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11068
	ctx.r31.s64 = ctx.r11.s64 + -11068;
	// lwz r11,-16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88092a0c
	if (ctx.cr6.eq) goto loc_88092A0C;
	// lwz r3,-20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// bl 0x88082bf8
	ctx.lr = 0x880929F0;
	sub_88082BF8(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// bl 0x88082bf0
	ctx.lr = 0x880929FC;
	sub_88082BF0(ctx, base);
	// lwz r3,-16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// bl 0x88083178
	ctx.lr = 0x88092A04;
	sub_88083178(ctx, base);
	// lwz r3,-20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// bl 0x88083178
	ctx.lr = 0x88092A0C;
	sub_88083178(ctx, base);
loc_88092A0C:
	// lwz r11,-796(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -796);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88092a6c
	if (ctx.cr6.eq) goto loc_88092A6C;
	// lwz r9,-808(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -808);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88092a5c
	if (ctx.cr6.eq) goto loc_88092A5C;
	// li r30,0
	ctx.r30.s64 = 0;
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
loc_88092A30:
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092a48
	if (ctx.cr6.eq) goto loc_88092A48;
	// bl 0x88083758
	ctx.lr = 0x88092A40;
	sub_88083758(ctx, base);
	// lwz r11,-796(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -796);
	// lwz r9,-808(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -808);
loc_88092A48:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,20
	ctx.r30.s64 = ctx.r30.s64 + 20;
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// blt cr6,0x88092a30
	if (ctx.cr6.lt) goto loc_88092A30;
loc_88092A5C:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x88083758
	ctx.lr = 0x88092A64;
	sub_88083758(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-796(r31)
	PPC_STORE_U32(ctx.r31.u32 + -796, ctx.r11.u32);
loc_88092A6C:
	// lis r30,-30683
	ctx.r30.s64 = -2010841088;
	// lwz r3,11804(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 11804);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x88092a88
	if (ctx.cr6.eq) goto loc_88092A88;
	// bl 0x88083178
	ctx.lr = 0x88092A80;
	sub_88083178(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,11804(r30)
	PPC_STORE_U32(ctx.r30.u32 + 11804, ctx.r11.u32);
loc_88092A88:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092aa0
	if (ctx.cr6.eq) goto loc_88092AA0;
	// bl 0x88083758
	ctx.lr = 0x88092A98;
	sub_88083758(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_88092AA0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88092AA8"))) PPC_WEAK_FUNC(sub_88092AA8);
PPC_FUNC_IMPL(__imp__sub_88092AA8) {
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
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r10,-11864
	ctx.r10.s64 = ctx.r10.s64 + -11864;
	// lwz r9,-12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	// cmplw cr6,r3,r9
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x88092ad4
	if (!ctx.cr6.lt) goto loc_88092AD4;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x88092ae8
	if (!ctx.cr6.eq) goto loc_88092AE8;
loc_88092AD4:
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
loc_88092AE8:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x880927a8
	ctx.lr = 0x88092B0C;
	sub_880927A8(ctx, base);
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

__attribute__((alias("__imp__sub_88092B20"))) PPC_WEAK_FUNC(sub_88092B20);
PPC_FUNC_IMPL(__imp__sub_88092B20) {
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
	// lis r11,-30700
	ctx.r11.s64 = -2011955200;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r31,r11,-22880
	ctx.r31.s64 = ctx.r11.s64 + -22880;
	// bl 0x88092aa8
	ctx.lr = 0x88092B44;
	sub_88092AA8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88092b64
	if (ctx.cr6.eq) goto loc_88092B64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x88092b5c
	if (ctx.cr6.eq) goto loc_88092B5C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8813a6a0
	ctx.lr = 0x88092B5C;
	sub_8813A6A0(ctx, base);
loc_88092B5C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x88092b68
	goto loc_88092B68;
loc_88092B64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_88092B68:
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

__attribute__((alias("__imp__sub_88092B80"))) PPC_WEAK_FUNC(sub_88092B80);
PPC_FUNC_IMPL(__imp__sub_88092B80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88092B88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,-11876
	ctx.r30.s64 = ctx.r11.s64 + -11876;
	// lwz r11,-11876(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11876);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x88092bc0
	if (!ctx.cr6.lt) goto loc_88092BC0;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x88092bc4
	goto loc_88092BC4;
loc_88092BC0:
	// lis r3,2
	ctx.r3.s64 = 131072;
loc_88092BC4:
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x880836d0
	ctx.lr = 0x88092BD4;
	sub_880836D0(ctx, base);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// add r8,r31,r10
	ctx.r8.u64 = ctx.r31.u64 + ctx.r10.u64;
	// lis r7,-30628
	ctx.r7.s64 = -2007236608;
	// rlwinm r29,r8,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r7,12928
	ctx.r28.s64 = ctx.r7.s64 + 12928;
	// add r6,r29,r11
	ctx.r6.u64 = ctx.r29.u64 + ctx.r11.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r9,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// bl 0x8824eae0
	ctx.lr = 0x88092C00;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r5,r29,r11
	ctx.r5.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r4,12(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// bl 0x88092aa8
	ctx.lr = 0x88092C14;
	sub_88092AA8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8824ead0
	ctx.lr = 0x88092C1C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88092C24"))) PPC_WEAK_FUNC(sub_88092C24);
PPC_FUNC_IMPL(__imp__sub_88092C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092C28"))) PPC_WEAK_FUNC(sub_88092C28);
PPC_FUNC_IMPL(__imp__sub_88092C28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071140
	ctx.lr = 0x88092C30;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r26,r11,-11072
	ctx.r26.s64 = ctx.r11.s64 + -11072;
	// lwz r3,-16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + -16);
	// bl 0x88082bf0
	ctx.lr = 0x88092C48;
	sub_88082BF0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092ecc
	if (ctx.cr6.eq) goto loc_88092ECC;
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r24,0
	ctx.r24.s64 = 0;
	// li r23,1
	ctx.r23.s64 = 1;
	// lis r22,-30597
	ctx.r22.s64 = -2005204992;
	// addi r25,r10,11808
	ctx.r25.s64 = ctx.r10.s64 + 11808;
	// addi r29,r11,13008
	ctx.r29.s64 = ctx.r11.s64 + 13008;
loc_88092C6C:
	// addi r3,r29,-80
	ctx.r3.s64 = ctx.r29.s64 + -80;
	// bl 0x8824ead0
	ctx.lr = 0x88092C74;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,-11860(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + -11860);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88092ca0
	if (ctx.cr6.eq) goto loc_88092CA0;
	// addi r3,r29,-6224
	ctx.r3.s64 = ctx.r29.s64 + -6224;
	// li r5,6144
	ctx.r5.s64 = 6144;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88092C90;
	sub_88073BD0(ctx, base);
	// lwz r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// stw r24,-11860(r22)
	PPC_STORE_U32(ctx.r22.u32 + -11860, ctx.r24.u32);
	// stw r11,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// b 0x88092eb0
	goto loc_88092EB0;
loc_88092CA0:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88092d30
	if (ctx.cr6.eq) goto loc_88092D30;
	// lwz r9,-804(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + -804);
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88092d08
	if (ctx.cr6.eq) goto loc_88092D08;
	// lwz r10,-792(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + -792);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
loc_88092CC4:
	// add r11,r31,r10
	ctx.r11.u64 = ctx.r31.u64 + ctx.r10.u64;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x88092cf8
	if (!ctx.cr6.eq) goto loc_88092CF8;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88092cec
	if (ctx.cr6.eq) goto loc_88092CEC;
	// bl 0x88083758
	ctx.lr = 0x88092CE4;
	sub_88083758(ctx, base);
	// lwz r9,-804(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + -804);
	// lwz r10,-792(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + -792);
loc_88092CEC:
	// add r11,r31,r10
	ctx.r11.u64 = ctx.r31.u64 + ctx.r10.u64;
	// stw r24,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r24.u32);
	// stw r24,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r24.u32);
loc_88092CF8:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x88092cc4
	if (ctx.cr6.lt) goto loc_88092CC4;
loc_88092D08:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88092D18;
	sub_88073BD0(ctx, base);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// stw r24,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r24.u32);
	// stw r24,-8(r26)
	PPC_STORE_U32(ctx.r26.u32 + -8, ctx.r24.u32);
	// stw r24,-4(r26)
	PPC_STORE_U32(ctx.r26.u32 + -4, ctx.r24.u32);
	// b 0x88092eb0
	goto loc_88092EB0;
loc_88092D30:
	// lwz r31,4(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// addi r10,r29,-6224
	ctx.r10.s64 = ctx.r29.s64 + -6224;
	// addi r11,r29,-6224
	ctx.r11.s64 = ctx.r29.s64 + -6224;
	// rlwinm r9,r31,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// add r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 + ctx.r9.u64;
	// addi r8,r29,-6224
	ctx.r8.s64 = ctx.r29.s64 + -6224;
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwzx r5,r7,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwzx r30,r7,r8
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwzx r27,r7,r6
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x88092e48
	if (ctx.cr6.eq) goto loc_88092E48;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-792(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -792);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// rlwinm r28,r10,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r28,r11
	ctx.r10.u64 = ctx.r28.u64 + ctx.r11.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88092dbc
	if (ctx.cr6.eq) goto loc_88092DBC;
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88092da4
	if (!ctx.cr6.eq) goto loc_88092DA4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88092b80
	ctx.lr = 0x88092D9C;
	sub_88092B80(ctx, base);
	// lwz r11,-792(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -792);
	// lwz r31,4(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_88092DA4:
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r4,12(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// bl 0x88072260
	ctx.lr = 0x88092DB8;
	sub_88072260(ctx, base);
	// b 0x88092ddc
	goto loc_88092DDC;
loc_88092DBC:
	// addi r3,r29,-80
	ctx.r3.s64 = ctx.r29.s64 + -80;
	// bl 0x8824eae0
	ctx.lr = 0x88092DC4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88092aa8
	ctx.lr = 0x88092DD0;
	sub_88092AA8(ctx, base);
	// addi r3,r29,-80
	ctx.r3.s64 = ctx.r29.s64 + -80;
	// bl 0x8824ead0
	ctx.lr = 0x88092DD8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r31,4(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_88092DDC:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r29,-6224
	ctx.r8.s64 = ctx.r29.s64 + -6224;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// addi r9,r29,-6224
	ctx.r9.s64 = ctx.r29.s64 + -6224;
	// addi r10,r29,-6224
	ctx.r10.s64 = ctx.r29.s64 + -6224;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r7,r9,20
	ctx.r7.s64 = ctx.r9.s64 + 20;
	// addi r6,r10,8
	ctx.r6.s64 = ctx.r10.s64 + 8;
	// stwx r24,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r24.u32);
	// stwx r23,r11,r7
	PPC_STORE_U32(ctx.r11.u32 + ctx.r7.u32, ctx.r23.u32);
	// lwzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88092e2c
	if (ctx.cr6.eq) goto loc_88092E2C;
	// addi r9,r29,-6224
	ctx.r9.s64 = ctx.r29.s64 + -6224;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r9,12
	ctx.r10.s64 = ctx.r9.s64 + 12;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bctrl 
	ctx.lr = 0x88092E28;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,4(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
loc_88092E2C:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// stw r11,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// blt cr6,0x88092eb0
	if (ctx.cr6.lt) goto loc_88092EB0;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stw r23,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r23.u32);
	// b 0x88092eb0
	goto loc_88092EB0;
loc_88092E48:
	// lwz r8,-8(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + -8);
	// lwz r11,-4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -4);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x88092eb0
	if (ctx.cr6.eq) goto loc_88092EB0;
	// lwz r9,-792(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + -792);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_88092E60:
	// lwzx r3,r10,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x88092e98
	if (ctx.cr6.eq) goto loc_88092E98;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,26
	ctx.r11.u64 = ctx.r11.u32 & 0x3F;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bne cr6,0x88092e60
	if (!ctx.cr6.eq) goto loc_88092E60;
	// b 0x88092eac
	goto loc_88092EAC;
loc_88092E98:
	// stw r11,-4(r26)
	PPC_STORE_U32(ctx.r26.u32 + -4, ctx.r11.u32);
	// bl 0x88092b80
	ctx.lr = 0x88092EA0;
	sub_88092B80(ctx, base);
	// lwz r11,-4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + -4);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r11,r11,26
	ctx.r11.u64 = ctx.r11.u32 & 0x3F;
loc_88092EAC:
	// stw r11,-4(r26)
	PPC_STORE_U32(ctx.r26.u32 + -4, ctx.r11.u32);
loc_88092EB0:
	// addi r3,r29,-80
	ctx.r3.s64 = ctx.r29.s64 + -80;
	// bl 0x8824eae0
	ctx.lr = 0x88092EB8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,-16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + -16);
	// bl 0x88082bf0
	ctx.lr = 0x88092EC4;
	sub_88082BF0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88092c6c
	if (!ctx.cr6.eq) goto loc_88092C6C;
loc_88092ECC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88082f70
	ctx.lr = 0x88092ED4;
	sub_88082F70(ctx, base);
}

__attribute__((alias("__imp__sub_88092ED4"))) PPC_WEAK_FUNC(sub_88092ED4);
PPC_FUNC_IMPL(__imp__sub_88092ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88092ED8"))) PPC_WEAK_FUNC(sub_88092ED8);
PPC_FUNC_IMPL(__imp__sub_88092ED8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x88092EE0;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r11,13008
	ctx.r30.s64 = ctx.r11.s64 + 13008;
	// addi r3,r30,-80
	ctx.r3.s64 = ctx.r30.s64 + -80;
	// bl 0x8824eaf0
	ctx.lr = 0x88092EF8;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// addi r3,r30,-6224
	ctx.r3.s64 = ctx.r30.s64 + -6224;
	// li r5,6144
	ctx.r5.s64 = 6144;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88092F08;
	sub_88073BD0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lis r10,-30683
	ctx.r10.s64 = -2010841088;
	// addi r31,r11,-11084
	ctx.r31.s64 = ctx.r11.s64 + -11084;
	// addi r27,r10,11832
	ctx.r27.s64 = ctx.r10.s64 + 11832;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r28,-776(r31)
	PPC_STORE_U32(ctx.r31.u32 + -776, ctx.r28.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,-24(r27)
	PPC_STORE_U32(ctx.r27.u32 + -24, ctx.r11.u32);
	// stw r10,-20(r27)
	PPC_STORE_U32(ctx.r27.u32 + -20, ctx.r10.u32);
	// bl 0x88073bd0
	ctx.lr = 0x88092F3C;
	sub_88073BD0(ctx, base);
	// stw r28,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// bl 0x880928d8
	ctx.lr = 0x88092F5C;
	sub_880928D8(ctx, base);
	// stw r3,-28(r27)
	PPC_STORE_U32(ctx.r27.u32 + -28, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x880931cc
	if (ctx.cr6.eq) goto loc_880931CC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88082b88
	ctx.lr = 0x88092F70;
	sub_88082B88(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x880927a8
	ctx.lr = 0x88092F84;
	sub_880927A8(ctx, base);
	// lbz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 108);
	// lbz r8,109(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 109);
	// lbz r6,110(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 110);
	// rlwimi r8,r7,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r11,111(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 111);
	// lbz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 104);
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// lbz r5,105(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 105);
	// lbz r10,107(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 107);
	// rlwimi r6,r3,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// lbz r9,103(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 103);
	// rlwimi r5,r4,8,16,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwimi r11,r6,8,0,23
	ctx.r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r11.u64 & 0xFFFFFFFF000000FF);
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
	// stw r11,-792(r31)
	PPC_STORE_U32(ctx.r31.u32 + -792, ctx.r11.u32);
	// lbz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 100);
	// lbz r7,101(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 101);
	// lbz r4,106(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 106);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r3,102(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 102);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwimi r4,r6,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r3,r5,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwimi r10,r4,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r3,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// addi r7,r8,16
	ctx.r7.s64 = ctx.r8.s64 + 16;
	// stw r10,-784(r31)
	PPC_STORE_U32(ctx.r31.u32 + -784, ctx.r10.u32);
	// stw r9,-788(r31)
	PPC_STORE_U32(ctx.r31.u32 + -788, ctx.r9.u32);
	// cmplw cr6,r7,r10
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x880931cc
	if (!ctx.cr6.eq) goto loc_880931CC;
	// cmplw cr6,r30,r9
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x880931cc
	if (!ctx.cr6.eq) goto loc_880931CC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r29,-1
	ctx.r29.s64 = -1;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x880836d0
	ctx.lr = 0x88093030;
	sub_880836D0(ctx, base);
	// stw r3,-780(r31)
	PPC_STORE_U32(ctx.r31.u32 + -780, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880931cc
	if (ctx.cr6.eq) goto loc_880931CC;
	// lwz r30,-792(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -792);
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x88073bd0
	ctx.lr = 0x88093054;
	sub_88073BD0(ctx, base);
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,4
	ctx.r6.s64 = 4;
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x880836d0
	ctx.lr = 0x88093070;
	sub_880836D0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880931cc
	if (ctx.cr6.eq) goto loc_880931CC;
	// lwz r11,-792(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -792);
	// li r5,16
	ctx.r5.s64 = 16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x880927a8
	ctx.lr = 0x88093094;
	sub_880927A8(ctx, base);
	// lwz r5,-792(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + -792);
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x88093148
	if (ctx.cr6.eq) goto loc_88093148;
	// lwz r10,-780(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -780);
	// addi r11,r30,2
	ctx.r11.s64 = ctx.r30.s64 + 2;
	// lwz r6,-788(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + -788);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_880930B4:
	// lbz r8,-2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + -2);
	// lbz r9,-1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// sth r9,-8(r10)
	PPC_STORE_U16(ctx.r10.u32 + -8, ctx.r9.u16);
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stb r3,-6(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6, ctx.r3.u8);
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// stb r9,-5(r10)
	PPC_STORE_U8(ctx.r10.u32 + -5, ctx.r9.u8);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r4,5(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r3,3(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// rlwimi r3,r9,8,16,23
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r3.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// rlwimi r8,r3,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r4,r8,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// lbz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// lbz r9,9(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 9);
	// lbz r4,7(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 7);
	// lbz r3,6(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// rlwimi r4,r3,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwimi r8,r4,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r8,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r9.u32);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x88093148
	if (!ctx.cr6.lt) goto loc_88093148;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bgt cr6,0x88093148
	if (ctx.cr6.gt) goto loc_88093148;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmplw cr6,r7,r5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x880930b4
	if (ctx.cr6.lt) goto loc_880930B4;
loc_88093148:
	// cmplw cr6,r7,r5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x880931bc
	if (!ctx.cr6.eq) goto loc_880931BC;
	// bl 0x88092668
	ctx.lr = 0x88093154;
	sub_88092668(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88082ca8
	ctx.lr = 0x88093168;
	sub_88082CA8(ctx, base);
	// stw r3,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r3.u32);
	// lis r11,-30711
	ctx.r11.s64 = -2012676096;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,11304
	ctx.r5.s64 = ctx.r11.s64 + 11304;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88083200
	ctx.lr = 0x8809318C;
	sub_88083200(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x88083030
	ctx.lr = 0x88093198;
	sub_88083030(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8808f6c0
	ctx.lr = 0x880931A4;
	sub_8808F6C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x88082f98
	ctx.lr = 0x880931B0;
	sub_88082F98(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x880831c0
	ctx.lr = 0x880931B8;
	sub_880831C0(ctx, base);
	// li r28,1
	ctx.r28.s64 = 1;
loc_880931BC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88083758
	ctx.lr = 0x880931C4;
	sub_88083758(ctx, base);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x880931d0
	if (!ctx.cr6.eq) goto loc_880931D0;
loc_880931CC:
	// bl 0x880929c8
	ctx.lr = 0x880931D0;
	sub_880929C8(ctx, base);
loc_880931D0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880931DC"))) PPC_WEAK_FUNC(sub_880931DC);
PPC_FUNC_IMPL(__imp__sub_880931DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880931E0"))) PPC_WEAK_FUNC(sub_880931E0);
PPC_FUNC_IMPL(__imp__sub_880931E0) {
	PPC_FUNC_PROLOGUE();
	// li r11,32
	ctx.r11.s64 = 32;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// sth r11,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, ctx.r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880931F0"))) PPC_WEAK_FUNC(sub_880931F0);
PPC_FUNC_IMPL(__imp__sub_880931F0) {
	PPC_FUNC_PROLOGUE();
	// li r11,32
	ctx.r11.s64 = 32;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
	// sth r11,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, ctx.r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093200"))) PPC_WEAK_FUNC(sub_88093200);
PPC_FUNC_IMPL(__imp__sub_88093200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// addic r9,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// subfe r8,r9,r3
	temp.u8 = (~ctx.r9.u32 + ctx.r3.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lwz r11,-11892(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11892);
	// oris r7,r8,49152
	ctx.r7.u64 = ctx.r8.u64 | 3221225472;
	// stw r7,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,-11892(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11892, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093224"))) PPC_WEAK_FUNC(sub_88093224);
PPC_FUNC_IMPL(__imp__sub_88093224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093228"))) PPC_WEAK_FUNC(sub_88093228);
PPC_FUNC_IMPL(__imp__sub_88093228) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r11,-11892(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11892);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r11,-11892(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11892, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093244"))) PPC_WEAK_FUNC(sub_88093244);
PPC_FUNC_IMPL(__imp__sub_88093244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093248"))) PPC_WEAK_FUNC(sub_88093248);
PPC_FUNC_IMPL(__imp__sub_88093248) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r8,r10,-11892
	ctx.r8.s64 = ctx.r10.s64 + -11892;
	// lwz r11,4(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stw r11,-11892(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11892, ctx.r11.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093264"))) PPC_WEAK_FUNC(sub_88093264);
PPC_FUNC_IMPL(__imp__sub_88093264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093268"))) PPC_WEAK_FUNC(sub_88093268);
PPC_FUNC_IMPL(__imp__sub_88093268) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8809326C"))) PPC_WEAK_FUNC(sub_8809326C);
PPC_FUNC_IMPL(__imp__sub_8809326C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093270"))) PPC_WEAK_FUNC(sub_88093270);
PPC_FUNC_IMPL(__imp__sub_88093270) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11892
	ctx.r31.s64 = ctx.r11.s64 + -11892;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88093298
	if (ctx.cr6.eq) goto loc_88093298;
	// bl 0x88083758
	ctx.lr = 0x88093298;
	sub_88083758(ctx, base);
loc_88093298:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_880932B4"))) PPC_WEAK_FUNC(sub_880932B4);
PPC_FUNC_IMPL(__imp__sub_880932B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880932B8"))) PPC_WEAK_FUNC(sub_880932B8);
PPC_FUNC_IMPL(__imp__sub_880932B8) {
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
	// li r31,-1
	ctx.r31.s64 = -1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lis r3,10
	ctx.r3.s64 = 655360;
	// bl 0x880836d0
	ctx.lr = 0x880932E0;
	sub_880836D0(ctx, base);
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// addi r10,r11,-11892
	ctx.r10.s64 = ctx.r11.s64 + -11892;
	// stw r3,-11892(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11892, ctx.r3.u32);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_88093308"))) PPC_WEAK_FUNC(sub_88093308);
PPC_FUNC_IMPL(__imp__sub_88093308) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11976
	ctx.r31.s64 = ctx.r11.s64 + -11976;
	// mtctr r3
	ctx.ctr.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8809334c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809334C;
	// bdzf 4*cr6+eq,0x88093358
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88093358;
	// bdzf 4*cr6+eq,0x8809338c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809338C;
	// bdzf 4*cr6+eq,0x8809338c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8809338C;
	// bne cr6,0x88093378
	if (!ctx.cr6.eq) goto loc_88093378;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x8809338c
	goto loc_8809338C;
loc_8809334C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8809338c
	goto loc_8809338C;
loc_88093358:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809336c
	if (ctx.cr6.eq) goto loc_8809336C;
	// bl 0x88082980
	ctx.lr = 0x88093368;
	sub_88082980(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_8809336C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8809338c
	goto loc_8809338C;
loc_88093378:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8809338c
	if (ctx.cr6.eq) goto loc_8809338C;
	// bl 0x88082980
	ctx.lr = 0x88093388;
	sub_88082980(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
loc_8809338C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
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

__attribute__((alias("__imp__sub_880933A4"))) PPC_WEAK_FUNC(sub_880933A4);
PPC_FUNC_IMPL(__imp__sub_880933A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880933A8"))) PPC_WEAK_FUNC(sub_880933A8);
PPC_FUNC_IMPL(__imp__sub_880933A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880933AC"))) PPC_WEAK_FUNC(sub_880933AC);
PPC_FUNC_IMPL(__imp__sub_880933AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880933B0"))) PPC_WEAK_FUNC(sub_880933B0);
PPC_FUNC_IMPL(__imp__sub_880933B0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880933B4"))) PPC_WEAK_FUNC(sub_880933B4);
PPC_FUNC_IMPL(__imp__sub_880933B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880933B8"))) PPC_WEAK_FUNC(sub_880933B8);
PPC_FUNC_IMPL(__imp__sub_880933B8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880933BC"))) PPC_WEAK_FUNC(sub_880933BC);
PPC_FUNC_IMPL(__imp__sub_880933BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880933C0"))) PPC_WEAK_FUNC(sub_880933C0);
PPC_FUNC_IMPL(__imp__sub_880933C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880933C4"))) PPC_WEAK_FUNC(sub_880933C4);
PPC_FUNC_IMPL(__imp__sub_880933C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880933C8"))) PPC_WEAK_FUNC(sub_880933C8);
PPC_FUNC_IMPL(__imp__sub_880933C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880933CC"))) PPC_WEAK_FUNC(sub_880933CC);
PPC_FUNC_IMPL(__imp__sub_880933CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880933D0"))) PPC_WEAK_FUNC(sub_880933D0);
PPC_FUNC_IMPL(__imp__sub_880933D0) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r31,r11,-11892
	ctx.r31.s64 = ctx.r11.s64 + -11892;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880933f8
	if (ctx.cr6.eq) goto loc_880933F8;
	// bl 0x88083758
	ctx.lr = 0x880933F8;
	sub_88083758(ctx, base);
loc_880933F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x8808cdf8
	ctx.lr = 0x88093404;
	sub_8808CDF8(ctx, base);
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

__attribute__((alias("__imp__sub_88093418"))) PPC_WEAK_FUNC(sub_88093418);
PPC_FUNC_IMPL(__imp__sub_88093418) {
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
	// bl 0x8808fb90
	ctx.lr = 0x88093428;
	sub_8808FB90(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r11,-11968(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11968, ctx.r11.u32);
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// lis r3,-30597
	ctx.r3.s64 = -2005204992;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-11952(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11952, ctx.r11.u32);
	// stw r10,-11964(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11964, ctx.r10.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// stw r9,-11956(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11956, ctx.r9.u32);
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// stw r10,-11960(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11960, ctx.r10.u32);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r9,-11936(r4)
	PPC_STORE_U32(ctx.r4.u32 + -11936, ctx.r9.u32);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r11,-11940(r3)
	PPC_STORE_U32(ctx.r3.u32 + -11940, ctx.r11.u32);
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// lis r3,-30597
	ctx.r3.s64 = -2005204992;
	// stw r10,-11944(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11944, ctx.r10.u32);
	// stw r9,-11948(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11948, ctx.r9.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// stw r11,-11932(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11932, ctx.r11.u32);
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// stw r10,-11928(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11928, ctx.r10.u32);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r9,-11924(r4)
	PPC_STORE_U32(ctx.r4.u32 + -11924, ctx.r9.u32);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r11,-11920(r3)
	PPC_STORE_U32(ctx.r3.u32 + -11920, ctx.r11.u32);
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// lis r3,-30597
	ctx.r3.s64 = -2005204992;
	// stw r10,-11916(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11916, ctx.r10.u32);
	// stw r9,-11912(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11912, ctx.r9.u32);
	// stw r11,-11908(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11908, ctx.r11.u32);
	// stw r10,-11904(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11904, ctx.r10.u32);
	// stw r9,-11900(r4)
	PPC_STORE_U32(ctx.r4.u32 + -11900, ctx.r9.u32);
	// stw r11,-11896(r3)
	PPC_STORE_U32(ctx.r3.u32 + -11896, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880934DC"))) PPC_WEAK_FUNC(sub_880934DC);
PPC_FUNC_IMPL(__imp__sub_880934DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880934E0"))) PPC_WEAK_FUNC(sub_880934E0);
PPC_FUNC_IMPL(__imp__sub_880934E0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r11,r11,-29424
	ctx.r11.s64 = ctx.r11.s64 + -29424;
	// addi r8,r9,-10960
	ctx.r8.s64 = ctx.r9.s64 + -10960;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88093508
	if (ctx.cr6.eq) goto loc_88093508;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r11.u32);
	// stw r10,-10960(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10960, ctx.r10.u32);
	// blr 
	return;
loc_88093508:
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-2064
	ctx.r10.s64 = ctx.r10.s64 + -2064;
	// stw r11,-10960(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10960, ctx.r11.u32);
	// stw r10,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093520"))) PPC_WEAK_FUNC(sub_88093520);
PPC_FUNC_IMPL(__imp__sub_88093520) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30697
	ctx.r11.s64 = -2011758592;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r11,r11,-29568
	ctx.r11.s64 = ctx.r11.s64 + -29568;
	// addi r8,r9,-10968
	ctx.r8.s64 = ctx.r9.s64 + -10968;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88093548
	if (ctx.cr6.eq) goto loc_88093548;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r11.u32);
	// stw r10,-10968(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10968, ctx.r10.u32);
	// blr 
	return;
loc_88093548:
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-2056
	ctx.r10.s64 = ctx.r10.s64 + -2056;
	// stw r11,-10968(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10968, ctx.r11.u32);
	// stw r10,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093560"))) PPC_WEAK_FUNC(sub_88093560);
PPC_FUNC_IMPL(__imp__sub_88093560) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-10684
	ctx.r11.s64 = ctx.r11.s64 + -10684;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880935a0
	if (!ctx.cr6.eq) goto loc_880935A0;
	// stw r10,-8(r11)
	PPC_STORE_U32(ctx.r11.u32 + -8, ctx.r10.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,-4(r11)
	PPC_STORE_U32(ctx.r11.u32 + -4, ctx.r9.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_880935A0:
	// li r31,-1
	ctx.r31.s64 = -1;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lis r3,10
	ctx.r3.s64 = 655360;
	// bl 0x880836d0
	ctx.lr = 0x880935B8;
	sub_880836D0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r11,-11968(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11968, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r10,-11964(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11964, ctx.r10.u32);
	// stw r9,-11960(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11960, ctx.r9.u32);
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// stw r11,-11956(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11956, ctx.r11.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r10,-11952(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11952, ctx.r10.u32);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r9,-11948(r4)
	PPC_STORE_U32(ctx.r4.u32 + -11948, ctx.r9.u32);
	// lis r4,-30597
	ctx.r4.s64 = -2005204992;
	// stw r11,-11944(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11944, ctx.r11.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// stw r10,-11940(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11940, ctx.r10.u32);
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// stw r9,-11936(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11936, ctx.r9.u32);
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r11,-11932(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11932, ctx.r11.u32);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// stw r10,-11920(r4)
	PPC_STORE_U32(ctx.r4.u32 + -11920, ctx.r10.u32);
	// stw r9,-11916(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11916, ctx.r9.u32);
	// addi r4,r5,-11892
	ctx.r4.s64 = ctx.r5.s64 + -11892;
	// stw r11,-11912(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11912, ctx.r11.u32);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// stw r10,-11908(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11908, ctx.r10.u32);
	// lis r7,-30597
	ctx.r7.s64 = -2005204992;
	// lis r6,-30597
	ctx.r6.s64 = -2005204992;
	// stw r3,-11892(r5)
	PPC_STORE_U32(ctx.r5.u32 + -11892, ctx.r3.u32);
	// stw r3,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r3.u32);
	// stw r9,-11904(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11904, ctx.r9.u32);
	// stw r11,-11900(r7)
	PPC_STORE_U32(ctx.r7.u32 + -11900, ctx.r11.u32);
	// stw r10,-11896(r6)
	PPC_STORE_U32(ctx.r6.u32 + -11896, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_88093674"))) PPC_WEAK_FUNC(sub_88093674);
PPC_FUNC_IMPL(__imp__sub_88093674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093678"))) PPC_WEAK_FUNC(sub_88093678);
PPC_FUNC_IMPL(__imp__sub_88093678) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// b 0x880900a0
	sub_880900A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88093680"))) PPC_WEAK_FUNC(sub_88093680);
PPC_FUNC_IMPL(__imp__sub_88093680) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r10,r3,29
	ctx.r10.u64 = ctx.r3.u32 & 0x7;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// rlwinm r9,r10,1,23,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1FE;
	// addi r11,r11,23632
	ctx.r11.s64 = ctx.r11.s64 + 23632;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r6,r8,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x880936d8
	if (!ctx.cr6.eq) goto loc_880936D8;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,-16944
	ctx.r7.s64 = ctx.r11.s64 + -16944;
	// add r9,r10,r6
	ctx.r9.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r8,r11,-16944
	ctx.r8.s64 = ctx.r11.s64 + -16944;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r11,-16944
	ctx.r6.s64 = ctx.r11.s64 + -16944;
	// addi r4,r7,4
	ctx.r4.s64 = ctx.r7.s64 + 4;
	// addi r3,r8,8
	ctx.r3.s64 = ctx.r8.s64 + 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r5,r6
	PPC_STORE_U32(ctx.r5.u32 + ctx.r6.u32, ctx.r9.u32);
	// stwx r9,r5,r4
	PPC_STORE_U32(ctx.r5.u32 + ctx.r4.u32, ctx.r9.u32);
	// stwx r9,r5,r3
	PPC_STORE_U32(ctx.r5.u32 + ctx.r3.u32, ctx.r9.u32);
loc_880936D8:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,-16944
	ctx.r9.s64 = ctx.r11.s64 + -16944;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880936F0"))) PPC_WEAK_FUNC(sub_880936F0);
PPC_FUNC_IMPL(__imp__sub_880936F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880936F4"))) PPC_WEAK_FUNC(sub_880936F4);
PPC_FUNC_IMPL(__imp__sub_880936F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880936F8"))) PPC_WEAK_FUNC(sub_880936F8);
PPC_FUNC_IMPL(__imp__sub_880936F8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880936FC"))) PPC_WEAK_FUNC(sub_880936FC);
PPC_FUNC_IMPL(__imp__sub_880936FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093700"))) PPC_WEAK_FUNC(sub_88093700);
PPC_FUNC_IMPL(__imp__sub_88093700) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093704"))) PPC_WEAK_FUNC(sub_88093704);
PPC_FUNC_IMPL(__imp__sub_88093704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093708"))) PPC_WEAK_FUNC(sub_88093708);
PPC_FUNC_IMPL(__imp__sub_88093708) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r3,r11,6688
	ctx.r3.s64 = ctx.r11.s64 + 6688;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88073bd0
	sub_88073BD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809371C"))) PPC_WEAK_FUNC(sub_8809371C);
PPC_FUNC_IMPL(__imp__sub_8809371C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093720"))) PPC_WEAK_FUNC(sub_88093720);
PPC_FUNC_IMPL(__imp__sub_88093720) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30706
	ctx.r11.s64 = -2012348416;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r11,r11,19664
	ctx.r11.s64 = ctx.r11.s64 + 19664;
	// addi r8,r9,-10988
	ctx.r8.s64 = ctx.r9.s64 + -10988;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88093748
	if (ctx.cr6.eq) goto loc_88093748;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r11.u32);
	// stw r10,-10988(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10988, ctx.r10.u32);
	// blr 
	return;
loc_88093748:
	// lis r10,-30711
	ctx.r10.s64 = -2012676096;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,1080
	ctx.r10.s64 = ctx.r10.s64 + 1080;
	// stw r11,-10988(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10988, ctx.r11.u32);
	// stw r10,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093760"))) PPC_WEAK_FUNC(sub_88093760);
PPC_FUNC_IMPL(__imp__sub_88093760) {
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
	// clrlwi r3,r3,29
	ctx.r3.u64 = ctx.r3.u32 & 0x7;
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// rlwinm r11,r3,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1FE;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r9,6688
	ctx.r11.s64 = ctx.r9.s64 + 6688;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// stwx r4,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r4.u32);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// stwx r31,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r31.u32);
	// stwx r10,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r10.u32);
	// bl 0x88090588
	ctx.lr = 0x880937B4;
	sub_88090588(ctx, base);
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

__attribute__((alias("__imp__sub_880937C8"))) PPC_WEAK_FUNC(sub_880937C8);
PPC_FUNC_IMPL(__imp__sub_880937C8) {
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
	// clrlwi r3,r3,29
	ctx.r3.u64 = ctx.r3.u32 & 0x7;
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// rlwinm r11,r3,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x1FE;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r9,6688
	ctx.r11.s64 = ctx.r9.s64 + 6688;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// clrlwi r4,r4,24
	ctx.r4.u64 = ctx.r4.u32 & 0xFF;
	// li r31,1
	ctx.r31.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stwx r4,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r4.u32);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// stwx r31,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r31.u32);
	// stwx r10,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r10.u32);
	// bl 0x88090588
	ctx.lr = 0x8809381C;
	sub_88090588(ctx, base);
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

__attribute__((alias("__imp__sub_88093830"))) PPC_WEAK_FUNC(sub_88093830);
PPC_FUNC_IMPL(__imp__sub_88093830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r8,-30628
	ctx.r8.s64 = -2007236608;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r7,r8,6688
	ctx.r7.s64 = ctx.r8.s64 + 6688;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,6688(r8)
	PPC_STORE_U32(ctx.r8.u32 + 6688, ctx.r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lhz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
	// lhz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r11,2(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// b 0x88090588
	sub_88090588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809387C"))) PPC_WEAK_FUNC(sub_8809387C);
PPC_FUNC_IMPL(__imp__sub_8809387C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093880"))) PPC_WEAK_FUNC(sub_88093880);
PPC_FUNC_IMPL(__imp__sub_88093880) {
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
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// clrlwi r31,r3,29
	ctx.r31.u64 = ctx.r3.u32 & 0x7;
	// lwz r11,-10996(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -10996);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880938ac
	if (ctx.cr6.eq) goto loc_880938AC;
	// clrlwi r3,r31,24
	ctx.r3.u64 = ctx.r31.u32 & 0xFF;
	// bl 0x880901b8
	ctx.lr = 0x880938AC;
	sub_880901B8(ctx, base);
loc_880938AC:
	// rlwinm r11,r31,1,23,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0x1FE;
	// clrlwi r9,r31,24
	ctx.r9.u64 = ctx.r31.u32 & 0xFF;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r10,6688
	ctx.r11.s64 = ctx.r10.s64 + 6688;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r10,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r10.u32);
	// stwx r10,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r10.u32);
	// stwx r10,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_880938F0"))) PPC_WEAK_FUNC(sub_880938F0);
PPC_FUNC_IMPL(__imp__sub_880938F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880938F8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,6688
	ctx.r11.s64 = ctx.r11.s64 + 6688;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// li r30,8
	ctx.r30.s64 = 8;
	// addi r31,r11,-4
	ctx.r31.s64 = ctx.r11.s64 + -4;
	// lis r27,-30597
	ctx.r27.s64 = -2005204992;
loc_88093918:
	// lwz r11,-10996(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -10996);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8809392c
	if (ctx.cr6.eq) goto loc_8809392C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880901b8
	ctx.lr = 0x8809392C;
	sub_880901B8(ctx, base);
loc_8809392C:
	// stw r28,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// stwu r28,12(r31)
	ea = 12 + ctx.r31.u32;
	PPC_STORE_U32(ea, ctx.r28.u32);
	ctx.r31.u32 = ea;
	// bne 0x88093918
	if (!ctx.cr0.eq) goto loc_88093918;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8809394C"))) PPC_WEAK_FUNC(sub_8809394C);
PPC_FUNC_IMPL(__imp__sub_8809394C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093950"))) PPC_WEAK_FUNC(sub_88093950);
PPC_FUNC_IMPL(__imp__sub_88093950) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x88093958;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// li r28,-1
	ctx.r28.s64 = -1;
	// addi r29,r11,-11892
	ctx.r29.s64 = ctx.r11.s64 + -11892;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r27,512
	ctx.r27.s64 = 512;
	// addi r30,r11,2592
	ctx.r30.s64 = ctx.r11.s64 + 2592;
	// li r26,0
	ctx.r26.s64 = 0;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_88093984:
	// lwz r31,0(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r26,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r26,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r26.u32);
	// beq cr6,0x880939b4
	if (ctx.cr6.eq) goto loc_880939B4;
loc_88093998:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880939A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,0(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x88093998
	if (!ctx.cr6.eq) goto loc_88093998;
loc_880939B4:
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bne 0x88093984
	if (!ctx.cr0.eq) goto loc_88093984;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// addi r8,r9,-11032
	ctx.r8.s64 = ctx.r9.s64 + -11032;
	// lwz r9,-11032(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11032);
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r26,-948(r8)
	PPC_STORE_U32(ctx.r8.u32 + -948, ctx.r26.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880939F0"))) PPC_WEAK_FUNC(sub_880939F0);
PPC_FUNC_IMPL(__imp__sub_880939F0) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r31,-30597
	ctx.r31.s64 = -2005204992;
	// lwz r10,-11980(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -11980);
	// cmplwi cr6,r10,30000
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 30000, ctx.xer);
	// bge cr6,0x88093a64
	if (!ctx.cr6.lt) goto loc_88093A64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r9,2592
	ctx.r7.s64 = ctx.r9.s64 + 2592;
	// lis r6,-30633
	ctx.r6.s64 = -2007564288;
	// rlwinm r9,r5,3,20,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFF8;
	// addi r8,r7,4
	ctx.r8.s64 = ctx.r7.s64 + 4;
	// addi r6,r6,-29728
	ctx.r6.s64 = ctx.r6.s64 + -29728;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lwzx r10,r9,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r11.u32);
	// stw r6,-11980(r31)
	PPC_STORE_U32(ctx.r31.u32 + -11980, ctx.r6.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r5,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// stw r4,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// beq cr6,0x88093a60
	if (ctx.cr6.eq) goto loc_88093A60;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_88093A60:
	// stwx r11,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r11.u32);
loc_88093A64:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093A6C"))) PPC_WEAK_FUNC(sub_88093A6C);
PPC_FUNC_IMPL(__imp__sub_88093A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093A70"))) PPC_WEAK_FUNC(sub_88093A70);
PPC_FUNC_IMPL(__imp__sub_88093A70) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093A74"))) PPC_WEAK_FUNC(sub_88093A74);
PPC_FUNC_IMPL(__imp__sub_88093A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093A78"))) PPC_WEAK_FUNC(sub_88093A78);
PPC_FUNC_IMPL(__imp__sub_88093A78) {
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
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// addi r3,r11,2592
	ctx.r3.s64 = ctx.r11.s64 + 2592;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88093A98;
	sub_88073BD0(ctx, base);
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// lis r5,5
	ctx.r5.s64 = 327680;
	// addi r3,r10,-29728
	ctx.r3.s64 = ctx.r10.s64 + -29728;
	// ori r5,r5,32320
	ctx.r5.u64 = ctx.r5.u64 | 32320;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88093AB0;
	sub_88073BD0(ctx, base);
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,-11980(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11980, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093AD0"))) PPC_WEAK_FUNC(sub_88093AD0);
PPC_FUNC_IMPL(__imp__sub_88093AD0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093AD4"))) PPC_WEAK_FUNC(sub_88093AD4);
PPC_FUNC_IMPL(__imp__sub_88093AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093AD8"))) PPC_WEAK_FUNC(sub_88093AD8);
PPC_FUNC_IMPL(__imp__sub_88093AD8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093ADC"))) PPC_WEAK_FUNC(sub_88093ADC);
PPC_FUNC_IMPL(__imp__sub_88093ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093AE0"))) PPC_WEAK_FUNC(sub_88093AE0);
PPC_FUNC_IMPL(__imp__sub_88093AE0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093AE4"))) PPC_WEAK_FUNC(sub_88093AE4);
PPC_FUNC_IMPL(__imp__sub_88093AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093AE8"))) PPC_WEAK_FUNC(sub_88093AE8);
PPC_FUNC_IMPL(__imp__sub_88093AE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,1800(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1800);
	// addi r11,r3,200
	ctx.r11.s64 = ctx.r3.s64 + 200;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_88093AFC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88093b14
	if (ctx.cr6.eq) goto loc_88093B14;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x88093b28
	if (ctx.cr6.eq) goto loc_88093B28;
loc_88093B14:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x88093afc
	if (ctx.cr6.lt) goto loc_88093AFC;
	// blr 
	return;
loc_88093B28:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093B34"))) PPC_WEAK_FUNC(sub_88093B34);
PPC_FUNC_IMPL(__imp__sub_88093B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093B38"))) PPC_WEAK_FUNC(sub_88093B38);
PPC_FUNC_IMPL(__imp__sub_88093B38) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,1800(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1800);
	// addi r11,r3,200
	ctx.r11.s64 = ctx.r3.s64 + 200;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88093b74
	if (ctx.cr6.eq) goto loc_88093B74;
loc_88093B4C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88093b64
	if (ctx.cr6.eq) goto loc_88093B64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x88093b7c
	if (ctx.cr6.eq) goto loc_88093B7C;
loc_88093B64:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x88093b4c
	if (ctx.cr6.lt) goto loc_88093B4C;
loc_88093B74:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88093B7C:
	// stw r5,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093B8C"))) PPC_WEAK_FUNC(sub_88093B8C);
PPC_FUNC_IMPL(__imp__sub_88093B8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093B90"))) PPC_WEAK_FUNC(sub_88093B90);
PPC_FUNC_IMPL(__imp__sub_88093B90) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,1800(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1800);
	// addi r11,r3,200
	ctx.r11.s64 = ctx.r3.s64 + 200;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88093bcc
	if (ctx.cr6.eq) goto loc_88093BCC;
loc_88093BA4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88093bbc
	if (ctx.cr6.eq) goto loc_88093BBC;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x88093bd4
	if (ctx.cr6.eq) goto loc_88093BD4;
loc_88093BBC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x88093ba4
	if (ctx.cr6.lt) goto loc_88093BA4;
loc_88093BCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88093BD4:
	// li r10,129
	ctx.r10.s64 = 129;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,60(r11)
	PPC_STORE_U32(ctx.r11.u32 + 60, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88093BE4"))) PPC_WEAK_FUNC(sub_88093BE4);
PPC_FUNC_IMPL(__imp__sub_88093BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093BE8"))) PPC_WEAK_FUNC(sub_88093BE8);
PPC_FUNC_IMPL(__imp__sub_88093BE8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x88093BF0;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,1800(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1800);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,20
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 20, ctx.xer);
	// bge cr6,0x88093cf4
	if (!ctx.cr6.lt) goto loc_88093CF4;
	// lwz r10,1804(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1804);
	// li r28,1
	ctx.r28.s64 = 1;
	// stw r11,1800(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1800, ctx.r11.u32);
	// addic. r11,r10,1
	ctx.xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r11.s64 = ctx.r10.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,1804(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1804, ctx.r11.u32);
	// bne 0x88093c28
	if (!ctx.cr0.eq) goto loc_88093C28;
	// stw r28,1804(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1804, ctx.r28.u32);
loc_88093C28:
	// lis r29,-30671
	ctx.r29.s64 = -2010054656;
	// li r22,0
	ctx.r22.s64 = 0;
	// lis r11,16838
	ctx.r11.s64 = 1103495168;
	// lis r10,128
	ctx.r10.s64 = 8388608;
	// addi r31,r20,200
	ctx.r31.s64 = ctx.r20.s64 + 200;
	// lwz r30,4200(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4200);
	// mr r16,r22
	ctx.r16.u64 = ctx.r22.u64;
	// li r21,36
	ctx.r21.s64 = 36;
	// ori r25,r11,20077
	ctx.r25.u64 = ctx.r11.u64 | 20077;
	// li r26,5
	ctx.r26.s64 = 5;
	// li r23,192
	ctx.r23.s64 = 192;
	// ori r27,r10,4112
	ctx.r27.u64 = ctx.r10.u64 | 4112;
	// li r17,28800
	ctx.r17.s64 = 28800;
	// li r18,80
	ctx.r18.s64 = 80;
	// li r19,7
	ctx.r19.s64 = 7;
loc_88093C64:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88093ce4
	if (!ctx.cr6.eq) goto loc_88093CE4;
	// mullw r11,r30,r25
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r25.s32);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r26.u32);
	// stw r23,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r23.u32);
	// stw r22,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r22.u32);
	// stw r27,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r27.u32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// stw r30,4200(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4200, ctx.r30.u32);
	// lhz r11,4200(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 4200);
	// clrlwi r9,r11,28
	ctx.r9.u64 = ctx.r11.u32 & 0xF;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// blt cr6,0x88093cc4
	if (ctx.cr6.lt) goto loc_88093CC4;
	// stw r17,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r17.u32);
	// stw r18,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r18.u32);
	// stw r19,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r19.u32);
loc_88093CC4:
	// lwz r11,1804(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 1804);
	// mr r5,r21
	ctx.r5.u64 = ctx.r21.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bl 0x88072260
	ctx.lr = 0x88093CDC;
	sub_88072260(ctx, base);
	// addic. r21,r21,-36
	ctx.xer.ca = ctx.r21.u32 > 35;
	ctx.r21.s64 = ctx.r21.s64 + -36;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq 0x88093d00
	if (ctx.cr0.eq) goto loc_88093D00;
loc_88093CE4:
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// cmpwi cr6,r16,20
	ctx.cr6.compare<int32_t>(ctx.r16.s32, 20, ctx.xer);
	// blt cr6,0x88093c64
	if (ctx.cr6.lt) goto loc_88093C64;
loc_88093CF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
loc_88093D00:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88093D0C"))) PPC_WEAK_FUNC(sub_88093D0C);
PPC_FUNC_IMPL(__imp__sub_88093D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88093D10"))) PPC_WEAK_FUNC(sub_88093D10);
PPC_FUNC_IMPL(__imp__sub_88093D10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x88093D18;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,1800(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1800);
	// addi r11,r3,200
	ctx.r11.s64 = ctx.r3.s64 + 200;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ble cr6,0x8809403c
	if (!ctx.cr6.gt) goto loc_8809403C;
	// lis r25,-30671
	ctx.r25.s64 = -2010054656;
	// lis r17,-30597
	ctx.r17.s64 = -2005204992;
	// addi r31,r11,48
	ctx.r31.s64 = ctx.r11.s64 + 48;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// lis r7,80
	ctx.r7.s64 = 5242880;
	// lwz r26,4200(r25)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4200);
	// lis r11,-30683
	ctx.r11.s64 = -2010841088;
	// lwz r24,-11932(r17)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r17.u32 + -11932);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// ori r18,r9,20077
	ctx.r18.u64 = ctx.r9.u64 | 20077;
	// ori r16,r8,43691
	ctx.r16.u64 = ctx.r8.u64 | 43691;
	// ori r15,r7,20560
	ctx.r15.u64 = ctx.r7.u64 | 20560;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// lis r20,-30667
	ctx.r20.s64 = -2009792512;
	// lis r19,-30667
	ctx.r19.s64 = -2009792512;
	// addi r27,r11,12000
	ctx.r27.s64 = ctx.r11.s64 + 12000;
	// addi r14,r10,9552
	ctx.r14.s64 = ctx.r10.s64 + 9552;
loc_88093D8C:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8809400c
	if (ctx.cr6.eq) goto loc_8809400C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r29,4(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r28,8(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88093dc4
	if (ctx.cr6.eq) goto loc_88093DC4;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r28,r10,r28
	ctx.r28.u64 = ctx.r10.u64 + ctx.r28.u64;
loc_88093DC4:
	// lwz r11,-28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -28);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,-28(r31)
	PPC_STORE_U32(ctx.r31.u32 + -28, ctx.r11.u32);
	// bge 0x88093f14
	if (!ctx.cr0.lt) goto loc_88093F14;
	// lwz r11,-24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -24);
	// stw r11,-28(r31)
	PPC_STORE_U32(ctx.r31.u32 + -28, ctx.r11.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// beq cr6,0x88093df0
	if (ctx.cr6.eq) goto loc_88093DF0;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
loc_88093DF0:
	// mullw r11,r26,r18
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r18.s32);
	// lwz r8,-32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// lwz r9,-44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// stw r29,12364(r20)
	PPC_STORE_U32(ctx.r20.u32 + 12364, ctx.r29.u32);
	// stw r28,12372(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12372, ctx.r28.u32);
	// stw r4,12376(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12376, ctx.r4.u32);
	// addi r30,r11,12345
	ctx.r30.s64 = ctx.r11.s64 + 12345;
	// addi r10,r27,-64
	ctx.r10.s64 = ctx.r27.s64 + -64;
	// stw r30,4200(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4200, ctx.r30.u32);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// stw r5,12384(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12384, ctx.r5.u32);
	// lhz r11,4200(r25)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r25.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r27,48
	ctx.r11.s64 = ctx.r27.s64 + 48;
	// bne cr6,0x88093e3c
	if (!ctx.cr6.eq) goto loc_88093E3C;
	// addi r11,r27,72
	ctx.r11.s64 = ctx.r27.s64 + 72;
loc_88093E3C:
	// lwzx r3,r7,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r11.u32);
	// stw r3,12380(r19)
	PPC_STORE_U32(ctx.r19.u32 + 12380, ctx.r3.u32);
	// bl 0x880f25b8
	ctx.lr = 0x88093E48;
	sub_880F25B8(ctx, base);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88093e60
	if (ctx.cr6.eq) goto loc_88093E60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_88093E60:
	// mullw r11,r30,r18
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r18.s32);
	// addi r26,r11,12345
	ctx.r26.s64 = ctx.r11.s64 + 12345;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r26,4200(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4200, ctx.r26.u32);
	// lhz r8,4200(r25)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r25.u32 + 4200);
	// mulhwu r7,r8,r16
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r16.u32)) >> 32;
	// rlwinm r11,r7,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0x3FFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r5,r6,5,0,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// subf r11,r10,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// clrlwi r11,r9,23
	ctx.r11.u64 = ctx.r9.u32 & 0x1FF;
	// beq cr6,0x88093ef8
	if (ctx.cr6.eq) goto loc_88093EF8;
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// addic. r10,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r10.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r7,r3,24
	ctx.r7.s64 = ctx.r3.s64 + 24;
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// beq 0x88093ed8
	if (ctx.cr0.eq) goto loc_88093ED8;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r9,r8,r14
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r14.u32);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
loc_88093ED8:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x88093ef8
	if (ctx.cr6.eq) goto loc_88093EF8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r14
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r14.u32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r9.u32);
loc_88093EF8:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x88093f14
	if (!ctx.cr6.gt) goto loc_88093F14;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88093f14
	if (ctx.cr6.eq) goto loc_88093F14;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
loc_88093F14:
	// lwz r11,-40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,-40(r31)
	PPC_STORE_U32(ctx.r31.u32 + -40, ctx.r11.u32);
	// bge 0x88093f48
	if (!ctx.cr0.lt) goto loc_88093F48;
	// lwz r11,-32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// lwz r10,-36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -36);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-32(r31)
	PPC_STORE_U32(ctx.r31.u32 + -32, ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r10,-40(r31)
	PPC_STORE_U32(ctx.r31.u32 + -40, ctx.r10.u32);
	// blt cr6,0x88093f48
	if (ctx.cr6.lt) goto loc_88093F48;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-32(r31)
	PPC_STORE_U32(ctx.r31.u32 + -32, ctx.r11.u32);
loc_88093F48:
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r10,-44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// add r30,r11,r27
	ctx.r30.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bge cr6,0x88093f98
	if (!ctx.cr6.lt) goto loc_88093F98;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x881538c0
	ctx.lr = 0x88093F74;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88093f98
	if (ctx.cr6.eq) goto loc_88093F98;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// oris r10,r11,545
	ctx.r10.u64 = ctx.r11.u64 | 35717120;
	// ori r10,r10,32768
	ctx.r10.u64 = ctx.r10.u64 | 32768;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,-8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
loc_88093F98:
	// lwz r11,-32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// addi r9,r27,-64
	ctx.r9.s64 = ctx.r27.s64 + -64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r11,r8,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x88093FC0;
	sub_881538C0(ctx, base);
	// lwz r7,-44(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// lwz r11,-20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// cmpwi cr6,r7,3
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 3, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// bge cr6,0x88093fe4
	if (!ctx.cr6.lt) goto loc_88093FE4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809400c
	if (ctx.cr6.eq) goto loc_8809400C;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// b 0x88093ff0
	goto loc_88093FF0;
loc_88093FE4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8809400c
	if (ctx.cr6.eq) goto loc_8809400C;
	// lis r10,531
	ctx.r10.s64 = 34799616;
loc_88093FF0:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// stw r15,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r15.u32);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r24,-11932(r17)
	PPC_STORE_U32(ctx.r17.u32 + -11932, ctx.r24.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_8809400C:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r9,1
	ctx.r11.s64 = ctx.r9.s64 + 1;
	// addi r7,r8,80
	ctx.r7.s64 = ctx.r8.s64 + 80;
	// lwz r6,1800(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1800);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x88093d8c
	if (ctx.cr6.lt) goto loc_88093D8C;
	// stw r24,-11932(r17)
	PPC_STORE_U32(ctx.r17.u32 + -11932, ctx.r24.u32);
loc_8809403C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88094044"))) PPC_WEAK_FUNC(sub_88094044);
PPC_FUNC_IMPL(__imp__sub_88094044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094048"))) PPC_WEAK_FUNC(sub_88094048);
PPC_FUNC_IMPL(__imp__sub_88094048) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,2332(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2332);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094050"))) PPC_WEAK_FUNC(sub_88094050);
PPC_FUNC_IMPL(__imp__sub_88094050) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,2328(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2328);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094058"))) PPC_WEAK_FUNC(sub_88094058);
PPC_FUNC_IMPL(__imp__sub_88094058) {
	PPC_FUNC_PROLOGUE();
	// stw r4,2328(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2328, ctx.r4.u32);
	// stw r5,2332(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2332, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094064"))) PPC_WEAK_FUNC(sub_88094064);
PPC_FUNC_IMPL(__imp__sub_88094064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094068"))) PPC_WEAK_FUNC(sub_88094068);
PPC_FUNC_IMPL(__imp__sub_88094068) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094070"))) PPC_WEAK_FUNC(sub_88094070);
PPC_FUNC_IMPL(__imp__sub_88094070) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094084"))) PPC_WEAK_FUNC(sub_88094084);
PPC_FUNC_IMPL(__imp__sub_88094084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094088"))) PPC_WEAK_FUNC(sub_88094088);
PPC_FUNC_IMPL(__imp__sub_88094088) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094090"))) PPC_WEAK_FUNC(sub_88094090);
PPC_FUNC_IMPL(__imp__sub_88094090) {
	PPC_FUNC_PROLOGUE();
	// stw r4,2296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2296, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094098"))) PPC_WEAK_FUNC(sub_88094098);
PPC_FUNC_IMPL(__imp__sub_88094098) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,12342(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12342, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880940AC"))) PPC_WEAK_FUNC(sub_880940AC);
PPC_FUNC_IMPL(__imp__sub_880940AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880940B0"))) PPC_WEAK_FUNC(sub_880940B0);
PPC_FUNC_IMPL(__imp__sub_880940B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r3,-11984(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -11984);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880940BC"))) PPC_WEAK_FUNC(sub_880940BC);
PPC_FUNC_IMPL(__imp__sub_880940BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880940C0"))) PPC_WEAK_FUNC(sub_880940C0);
PPC_FUNC_IMPL(__imp__sub_880940C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880940D8"))) PPC_WEAK_FUNC(sub_880940D8);
PPC_FUNC_IMPL(__imp__sub_880940D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8809410c
	if (!ctx.cr6.eq) goto loc_8809410C;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8809410c
	if (ctx.cr6.eq) goto loc_8809410C;
	// lis r10,-30640
	ctx.r10.s64 = -2008023040;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,31696
	ctx.r8.s64 = ctx.r10.s64 + 31696;
	// lwzx r10,r9,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r7,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
loc_8809410C:
	// lis r11,-30633
	ctx.r11.s64 = -2007564288;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// addi r11,r11,-29840
	ctx.r11.s64 = ctx.r11.s64 + -29840;
	// beq cr6,0x88094130
	if (ctx.cr6.eq) goto loc_88094130;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stw r7,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
loc_88094130:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// subf r5,r7,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094154"))) PPC_WEAK_FUNC(sub_88094154);
PPC_FUNC_IMPL(__imp__sub_88094154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094158"))) PPC_WEAK_FUNC(sub_88094158);
PPC_FUNC_IMPL(__imp__sub_88094158) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094160"))) PPC_WEAK_FUNC(sub_88094160);
PPC_FUNC_IMPL(__imp__sub_88094160) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094168"))) PPC_WEAK_FUNC(sub_88094168);
PPC_FUNC_IMPL(__imp__sub_88094168) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094180"))) PPC_WEAK_FUNC(sub_88094180);
PPC_FUNC_IMPL(__imp__sub_88094180) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094194"))) PPC_WEAK_FUNC(sub_88094194);
PPC_FUNC_IMPL(__imp__sub_88094194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88094198"))) PPC_WEAK_FUNC(sub_88094198);
PPC_FUNC_IMPL(__imp__sub_88094198) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,176(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x880941b0
	if (ctx.cr6.lt) goto loc_880941B0;
	// lwz r10,192(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
loc_880941B0:
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880941C0"))) PPC_WEAK_FUNC(sub_880941C0);
PPC_FUNC_IMPL(__imp__sub_880941C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,172(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x880941d8
	if (ctx.cr6.lt) goto loc_880941D8;
	// lwz r10,188(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// blr 
	return;
loc_880941D8:
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880941E8"))) PPC_WEAK_FUNC(sub_880941E8);
PPC_FUNC_IMPL(__imp__sub_880941E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,184(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880941F8"))) PPC_WEAK_FUNC(sub_880941F8);
PPC_FUNC_IMPL(__imp__sub_880941F8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 168, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88094200"))) PPC_WEAK_FUNC(sub_88094200);
PPC_FUNC_IMPL(__imp__sub_88094200) {
	PPC_FUNC_PROLOGUE();
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// blr 
	return;
}

