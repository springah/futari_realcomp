#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8218A4F0"))) PPC_WEAK_FUNC(sub_8218A4F0);
PPC_FUNC_IMPL(__imp__sub_8218A4F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A4F4"))) PPC_WEAK_FUNC(sub_8218A4F4);
PPC_FUNC_IMPL(__imp__sub_8218A4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A4F8"))) PPC_WEAK_FUNC(sub_8218A4F8);
PPC_FUNC_IMPL(__imp__sub_8218A4F8) {
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
	// lis r5,13
	ctx.r5.s64 = 851968;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,12472
	ctx.r5.u64 = ctx.r5.u64 | 12472;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x8218A51C;
	sub_8207DA20(ctx, base);
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
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

__attribute__((alias("__imp__sub_8218A540"))) PPC_WEAK_FUNC(sub_8218A540);
PPC_FUNC_IMPL(__imp__sub_8218A540) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8218A548;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,99
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 99, ctx.xer);
	// lwz r31,-31356(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// blt cr6,0x8218a570
	if (ctx.cr6.lt) goto loc_8218A570;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8218A570:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218a584
	if (!ctx.cr6.eq) goto loc_8218A584;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8218A584:
	// rlwinm r25,r26,3,0,28
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r25,r11
	ctx.r30.u64 = ctx.r25.u64 + ctx.r11.u64;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8218a5a4
	if (!ctx.cr6.eq) goto loc_8218A5A4;
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8218A5A4:
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & ctx.r11.u64;
	// subf r27,r7,r9
	ctx.r27.s64 = ctx.r9.s64 - ctx.r7.s64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207a030
	ctx.lr = 0x8218A5C0;
	sub_8207A030(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218a5d8
	if (!ctx.cr6.eq) goto loc_8218A5D8;
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8218A5D8:
	// lwz r28,0(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r24,4(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x8218A5F0;
	sub_8207DAC0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// subf r5,r11,r24
	ctx.r5.s64 = ctx.r24.s64 - ctx.r11.s64;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8218a618
	if (!ctx.cr6.gt) goto loc_8218A618;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// subf r5,r11,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r11.s64;
loc_8218A618:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x8218a624
	if (!ctx.cr6.gt) goto loc_8218A624;
	// bl 0x8207dac0
	ctx.lr = 0x8218A624;
	sub_8207DAC0(ctx, base);
loc_8218A624:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a8a0
	ctx.lr = 0x8218A62C;
	sub_8207A8A0(ctx, base);
	// add r11,r25,r29
	ctx.r11.u64 = ctx.r25.u64 + ctx.r29.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r27,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r27.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpwi cr6,r26,98
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 98, ctx.xer);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bge cr6,0x8218a67c
	if (!ctx.cr6.lt) goto loc_8218A67C;
	// subfic r10,r26,98
	ctx.xer.ca = ctx.r26.u32 <= 98;
	ctx.r10.s64 = 98 - ctx.r26.s64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8218A658:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// subfic r8,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r10.s64;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addme r6,r7
	{ uint8_t _ca = (ctx.r7.u32 + 0xFFFFFFFF < ctx.r7.u32) | (ctx.r7.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r6.u64 = ctx.r7.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// and r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ctx.r10.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218a658
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218A658;
loc_8218A67C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218A688"))) PPC_WEAK_FUNC(sub_8218A688);
PPC_FUNC_IMPL(__imp__sub_8218A688) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x8218A690;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmpwi cr6,r3,99
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 99, ctx.xer);
	// lwz r30,-31356(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// blt cr6,0x8218a6c0
	if (ctx.cr6.lt) goto loc_8218A6C0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_8218A6C0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218a6d4
	if (!ctx.cr6.eq) goto loc_8218A6D4;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_8218A6D4:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8218a6e8
	if (!ctx.cr6.eq) goto loc_8218A6E8;
loc_8218A6DC:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_8218A6E8:
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x8218a6dc
	if (!ctx.cr6.gt) goto loc_8218A6DC;
	// rlwinm r24,r22,3,0,28
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// add r31,r24,r11
	ctx.r31.u64 = ctx.r24.u64 + ctx.r11.u64;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r11,r9,1,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// subf r11,r7,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r7.s64;
	// add r23,r11,r10
	ctx.r23.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8207a030
	ctx.lr = 0x8218A71C;
	sub_8207A030(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218a734
	if (!ctx.cr6.eq) goto loc_8218A734;
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_8218A734:
	// lwz r26,0(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r21,4(r30)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x8218A74C;
	sub_8207DAC0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r27,r11,r29
	ctx.r27.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r25,r11,r26
	ctx.r25.u64 = ctx.r11.u64 + ctx.r26.u64;
	// subf r26,r11,r21
	ctx.r26.s64 = ctx.r21.s64 - ctx.r11.s64;
	// bl 0x8207dac0
	ctx.lr = 0x8218A76C;
	sub_8207DAC0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r3,r27,r28
	ctx.r3.u64 = ctx.r27.u64 + ctx.r28.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8218a788
	if (!ctx.cr6.gt) goto loc_8218A788;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// add r25,r11,r25
	ctx.r25.u64 = ctx.r11.u64 + ctx.r25.u64;
	// subf r26,r11,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r11.s64;
loc_8218A788:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// ble cr6,0x8218a79c
	if (!ctx.cr6.gt) goto loc_8218A79C;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8218A79C;
	sub_8207DAC0(ctx, base);
loc_8218A79C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a8a0
	ctx.lr = 0x8218A7A4;
	sub_8207A8A0(ctx, base);
	// add r11,r24,r29
	ctx.r11.u64 = ctx.r24.u64 + ctx.r29.u64;
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// stw r23,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r23.u32);
	// cmpwi cr6,r22,98
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 98, ctx.xer);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stw r28,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// bge cr6,0x8218a7f0
	if (!ctx.cr6.lt) goto loc_8218A7F0;
	// subfic r10,r22,98
	ctx.xer.ca = ctx.r22.u32 <= 98;
	ctx.r10.s64 = 98 - ctx.r22.s64;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8218A7CC:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// subfic r8,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r10.s64;
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// addme r6,r7
	{ uint8_t _ca = (ctx.r7.u32 + 0xFFFFFFFF < ctx.r7.u32) | (ctx.r7.u32 + 0xFFFFFFFF + ctx.xer.ca < ctx.xer.ca); // FIX 2026-07-24: insn was silently dropped by the recompiler
	ctx.r6.u64 = ctx.r7.u64 + 0xFFFFFFFFFFFFFFFFull + ctx.xer.ca;
	ctx.xer.ca = _ca; }
	// and r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 & ctx.r10.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218a7cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218A7CC;
loc_8218A7F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218A7FC"))) PPC_WEAK_FUNC(sub_8218A7FC);
PPC_FUNC_IMPL(__imp__sub_8218A7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A800"))) PPC_WEAK_FUNC(sub_8218A800);
PPC_FUNC_IMPL(__imp__sub_8218A800) {
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
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,99
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 99, ctx.xer);
	// lwz r10,-31356(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31356);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// blt cr6,0x8218a838
	if (ctx.cr6.lt) goto loc_8218A838;
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
loc_8218A838:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8218a854
	if (!ctx.cr6.eq) goto loc_8218A854;
loc_8218A840:
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
loc_8218A854:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8218a870
	if (!ctx.cr6.eq) goto loc_8218A870;
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
loc_8218A870:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,4(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8218a898
	if (!ctx.cr6.eq) goto loc_8218A898;
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
loc_8218A898:
	// blt cr6,0x8218a840
	if (ctx.cr6.lt) goto loc_8218A840;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x8218a8bc
	if (!ctx.cr6.gt) goto loc_8218A8BC;
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x8218a840
	if (ctx.cr6.lt) goto loc_8218A840;
	// lwz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8218A8BC;
	sub_8207DAC0(ctx, base);
loc_8218A8BC:
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

__attribute__((alias("__imp__sub_8218A8D0"))) PPC_WEAK_FUNC(sub_8218A8D0);
PPC_FUNC_IMPL(__imp__sub_8218A8D0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// cmpwi cr6,r3,99
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 99, ctx.xer);
	// lwz r11,-31356(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// blt cr6,0x8218a8e8
	if (ctx.cr6.lt) goto loc_8218A8E8;
loc_8218A8E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8218A8E8:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218a8e0
	if (ctx.cr6.eq) goto loc_8218A8E0;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218A904"))) PPC_WEAK_FUNC(sub_8218A904);
PPC_FUNC_IMPL(__imp__sub_8218A904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218A908"))) PPC_WEAK_FUNC(sub_8218A908);
PPC_FUNC_IMPL(__imp__sub_8218A908) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218A910;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r26,-31356(r11)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// bne cr6,0x8218a938
	if (!ctx.cr6.eq) goto loc_8218A938;
loc_8218A92C:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8218A938:
	// cmpwi cr6,r30,792
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 792, ctx.xer);
	// blt cr6,0x8218a92c
	if (ctx.cr6.lt) goto loc_8218A92C;
	// li r3,792
	ctx.r3.s64 = 792;
	// bl 0x8207a030
	ctx.lr = 0x8218A948;
	sub_8207A030(ctx, base);
	// li r5,792
	ctx.r5.s64 = 792;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// bl 0x8207da20
	ctx.lr = 0x8218A958;
	sub_8207DA20(ctx, base);
	// li r11,99
	ctx.r11.s64 = 99;
	// addi r31,r25,4
	ctx.r31.s64 = ctx.r25.s64 + 4;
	// li r29,792
	ctx.r29.s64 = 792;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// subf r27,r25,r28
	ctx.r27.s64 = ctx.r28.s64 - ctx.r25.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r7,r11,12480
	ctx.r7.u64 = ctx.r11.u64 | 12480;
	// li r6,-1
	ctx.r6.s64 = -1;
loc_8218A984:
	// lwzx r11,r27,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r10.u32);
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r29,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r29.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8218a9a0
	if (!ctx.cr6.eq) goto loc_8218A9A0;
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// b 0x8218a9d4
	goto loc_8218A9D4;
loc_8218A9A0:
	// cmpwi cr6,r9,792
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 792, ctx.xer);
	// blt cr6,0x8218a9d0
	if (ctx.cr6.lt) goto loc_8218A9D0;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmpw cr6,r9,r30
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r30.s32, ctx.xer);
	// bgt cr6,0x8218a9d0
	if (ctx.cr6.gt) goto loc_8218A9D0;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bgt cr6,0x8218a9d0
	if (ctx.cr6.gt) goto loc_8218A9D0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8218a9d0
	if (ctx.cr6.lt) goto loc_8218A9D0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// b 0x8218a9d4
	goto loc_8218A9D4;
loc_8218A9D0:
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
loc_8218A9D4:
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x8218a984
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218A984;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8207a030
	ctx.lr = 0x8218A9E8;
	sub_8207A030(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218aa08
	if (!ctx.cr6.eq) goto loc_8218AA08;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x8218A9FC;
	sub_8207A8A0(ctx, base);
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8218AA08:
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218aa18
	if (ctx.cr6.eq) goto loc_8218AA18;
	// bl 0x8207a8a0
	ctx.lr = 0x8218AA18;
	sub_8207A8A0(ctx, base);
loc_8218AA18:
	// stw r30,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r30.u32);
	// li r5,792
	ctx.r5.s64 = 792;
	// stw r29,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r29.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8218AA30;
	sub_8207DAC0(ctx, base);
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// li r29,99
	ctx.r29.s64 = 99;
loc_8218AA38:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8218aa64
	if (ctx.cr6.eq) goto loc_8218AA64;
	// blt cr6,0x8218aa64
	if (ctx.cr6.lt) goto loc_8218AA64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
	// lwzx r5,r31,r27
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8218AA64;
	sub_8207DAC0(ctx, base);
loc_8218AA64:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// bne 0x8218aa38
	if (!ctx.cr0.eq) goto loc_8218AA38;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8207a8a0
	ctx.lr = 0x8218AA7C;
	sub_8207A8A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218AA88"))) PPC_WEAK_FUNC(sub_8218AA88);
PPC_FUNC_IMPL(__imp__sub_8218AA88) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x8207a8a0
	sub_8207A8A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218AA98"))) PPC_WEAK_FUNC(sub_8218AA98);
PPC_FUNC_IMPL(__imp__sub_8218AA98) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218AA9C"))) PPC_WEAK_FUNC(sub_8218AA9C);
PPC_FUNC_IMPL(__imp__sub_8218AA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218AAA0"))) PPC_WEAK_FUNC(sub_8218AAA0);
PPC_FUNC_IMPL(__imp__sub_8218AAA0) {
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
	// li r11,792
	ctx.r11.s64 = 792;
	// li r3,792
	ctx.r3.s64 = 792;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x8207a030
	ctx.lr = 0x8218AAC4;
	sub_8207A030(ctx, base);
	// li r10,99
	ctx.r10.s64 = 99;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8218AAD8:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218aad8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218AAD8;
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

__attribute__((alias("__imp__sub_8218AB00"))) PPC_WEAK_FUNC(sub_8218AB00);
PPC_FUNC_IMPL(__imp__sub_8218AB00) {
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
	// lis r5,13
	ctx.r5.s64 = 851968;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// ori r5,r5,12472
	ctx.r5.u64 = ctx.r5.u64 | 12472;
	// b 0x8207dac0
	sub_8207DAC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218AB28"))) PPC_WEAK_FUNC(sub_8218AB28);
PPC_FUNC_IMPL(__imp__sub_8218AB28) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218AB2C"))) PPC_WEAK_FUNC(sub_8218AB2C);
PPC_FUNC_IMPL(__imp__sub_8218AB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218AB30"))) PPC_WEAK_FUNC(sub_8218AB30);
PPC_FUNC_IMPL(__imp__sub_8218AB30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218AB38;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218abe0
	if (ctx.cr6.eq) goto loc_8218ABE0;
	// lis r5,13
	ctx.r5.s64 = 851968;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,12480
	ctx.r5.u64 = ctx.r5.u64 | 12480;
	// bl 0x8207da20
	ctx.lr = 0x8218AB5C;
	sub_8207DA20(ctx, base);
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// ori r10,r11,2048
	ctx.r10.u64 = ctx.r11.u64 | 2048;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8218abe0
	if (ctx.cr6.eq) goto loc_8218ABE0;
	// lis r29,-32224
	ctx.r29.s64 = -2111832064;
	// lwz r11,-31352(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31352);
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,40(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x8218abc4
	if (!ctx.cr6.lt) goto loc_8218ABC4;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,12
	ctx.r4.s64 = ctx.r31.s64 + 12;
	// bl 0x82088f68
	ctx.lr = 0x8218AB98;
	sub_82088F68(ctx, base);
	// lwz r11,-31352(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -31352);
	// addi r30,r31,32
	ctx.r30.s64 = ctx.r31.s64 + 32;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,40(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// bl 0x820891a8
	ctx.lr = 0x8218ABB4;
	sub_820891A8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218abc4
	if (ctx.cr6.eq) goto loc_8218ABC4;
	// li r11,0
	ctx.r11.s64 = 0;
	// std r11,0(r30)
	PPC_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
loc_8218ABC4:
	// addi r3,r31,40
	ctx.r3.s64 = ctx.r31.s64 + 40;
	// bl 0x82089e40
	ctx.lr = 0x8218ABCC;
	sub_82089E40(ctx, base);
	// lis r5,13
	ctx.r5.s64 = 851968;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r5,r5,12472
	ctx.r5.u64 = ctx.r5.u64 | 12472;
	// addi r3,r28,8
	ctx.r3.s64 = ctx.r28.s64 + 8;
	// bl 0x8207dac0
	ctx.lr = 0x8218ABE0;
	sub_8207DAC0(ctx, base);
loc_8218ABE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218ABE8"))) PPC_WEAK_FUNC(sub_8218ABE8);
PPC_FUNC_IMPL(__imp__sub_8218ABE8) {
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
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ac20
	if (ctx.cr6.eq) goto loc_8218AC20;
	// li r4,45
	ctx.r4.s64 = 45;
	// bl 0x821bd1b8
	ctx.lr = 0x8218AC14;
	sub_821BD1B8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218ac50
	if (ctx.cr6.eq) goto loc_8218AC50;
loc_8218AC20:
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218AC38;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_8218AC50:
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

__attribute__((alias("__imp__sub_8218AC68"))) PPC_WEAK_FUNC(sub_8218AC68);
PPC_FUNC_IMPL(__imp__sub_8218AC68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218AC70;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218ac8c
	if (ctx.cr6.eq) goto loc_8218AC8C;
	// lwz r10,136(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218AC8C:
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8218acc0
	if (!ctx.cr6.eq) goto loc_8218ACC0;
	// lwz r4,152(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// bl 0x8218a908
	ctx.lr = 0x8218ACA4;
	sub_8218A908(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8218acf4
	if (ctx.cr6.eq) goto loc_8218ACF4;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218acc0
	if (ctx.cr6.eq) goto loc_8218ACC0;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218ACC0:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218ACD0;
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
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8218ACF4:
	// li r25,0
	ctx.r25.s64 = 0;
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// addi r28,r31,160
	ctx.r28.s64 = ctx.r31.s64 + 160;
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// li r29,-1
	ctx.r29.s64 = -1;
	// ori r26,r11,2048
	ctx.r26.u64 = ctx.r11.u64 | 2048;
loc_8218AD10:
	// lis r5,13
	ctx.r5.s64 = 851968;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,12480
	ctx.r5.u64 = ctx.r5.u64 | 12480;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207da20
	ctx.lr = 0x8218AD24;
	sub_8207DA20(ctx, base);
	// li r5,108
	ctx.r5.s64 = 108;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8218a800
	ctx.lr = 0x8218AD34;
	sub_8218A800(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8218ad54
	if (ctx.cr6.eq) goto loc_8218AD54;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x8218ad94
	if (!ctx.cr6.eq) goto loc_8218AD94;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r25,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
	// b 0x8218ada0
	goto loc_8218ADA0;
loc_8218AD54:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8218ad94
	if (!ctx.cr6.eq) goto loc_8218AD94;
	// lwz r11,172(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 172);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8218ad94
	if (!ctx.cr6.eq) goto loc_8218AD94;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// beq cr6,0x8218adac
	if (ctx.cr6.eq) goto loc_8218ADAC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218adac
	if (ctx.cr6.eq) goto loc_8218ADAC;
	// addi r4,r28,8
	ctx.r4.s64 = ctx.r28.s64 + 8;
	// li r5,104
	ctx.r5.s64 = 104;
	// bl 0x8207dac0
	ctx.lr = 0x8218AD90;
	sub_8207DAC0(ctx, base);
	// b 0x8218adac
	goto loc_8218ADAC;
loc_8218AD94:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
loc_8218ADA0:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r29,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r29.u32);
loc_8218ADAC:
	// addi r30,r30,104
	ctx.r30.s64 = ctx.r30.s64 + 104;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// cmpwi cr6,r30,10296
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 10296, ctx.xer);
	// blt cr6,0x8218ad10
	if (ctx.cr6.lt) goto loc_8218AD10;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// ori r9,r11,12640
	ctx.r9.u64 = ctx.r11.u64 | 12640;
	// addi r8,r10,-21528
	ctx.r8.s64 = ctx.r10.s64 + -21528;
	// stwx r8,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218ADD8"))) PPC_WEAK_FUNC(sub_8218ADD8);
PPC_FUNC_IMPL(__imp__sub_8218ADD8) {
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
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218ae00
	if (ctx.cr6.eq) goto loc_8218AE00;
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218AE00:
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8218ae1c
	if (ctx.cr6.eq) goto loc_8218AE1C;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8218ae1c
	if (ctx.cr6.eq) goto loc_8218AE1C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
loc_8218AE1C:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218AE28;
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

__attribute__((alias("__imp__sub_8218AE58"))) PPC_WEAK_FUNC(sub_8218AE58);
PPC_FUNC_IMPL(__imp__sub_8218AE58) {
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
	// li r30,0
	ctx.r30.s64 = 0;
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
	// bne cr6,0x8218ae9c
	if (!ctx.cr6.eq) goto loc_8218AE9C;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8218aea4
	goto loc_8218AEA4;
loc_8218AE9C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218AEA4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218af0c
	if (ctx.cr6.eq) goto loc_8218AF0C;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ori r10,r11,12628
	ctx.r10.u64 = ctx.r11.u64 | 12628;
	// lwzx r11,r31,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// bne cr6,0x8218aed4
	if (!ctx.cr6.eq) goto loc_8218AED4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218aee4
	if (ctx.cr6.eq) goto loc_8218AEE4;
	// li r10,5
	ctx.r10.s64 = 5;
	// b 0x8218aee0
	goto loc_8218AEE0;
loc_8218AED4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218aee4
	if (ctx.cr6.eq) goto loc_8218AEE4;
	// li r10,8
	ctx.r10.s64 = 8;
loc_8218AEE0:
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218AEE4:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218AEF4;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_8218AF0C:
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

__attribute__((alias("__imp__sub_8218AF24"))) PPC_WEAK_FUNC(sub_8218AF24);
PPC_FUNC_IMPL(__imp__sub_8218AF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218AF28"))) PPC_WEAK_FUNC(sub_8218AF28);
PPC_FUNC_IMPL(__imp__sub_8218AF28) {
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
	// bne cr6,0x8218af9c
	if (!ctx.cr6.eq) goto loc_8218AF9C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218af80
	if (ctx.cr6.eq) goto loc_8218AF80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x8218AF70;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218af80
	if (ctx.cr6.eq) goto loc_8218AF80;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_8218AF80:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218af9c
	if (!ctx.cr6.eq) goto loc_8218AF9C;
	// li r11,512
	ctx.r11.s64 = 512;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
loc_8218AF9C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-20904
	ctx.r10.s64 = ctx.r11.s64 + -20904;
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

__attribute__((alias("__imp__sub_8218AFC0"))) PPC_WEAK_FUNC(sub_8218AFC0);
PPC_FUNC_IMPL(__imp__sub_8218AFC0) {
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
	// lis r11,13
	ctx.r11.s64 = 851968;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r10,r11,12636
	ctx.r10.u64 = ctx.r11.u64 | 12636;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8218b04c
	if (ctx.cr6.eq) goto loc_8218B04C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218b058
	if (!ctx.cr6.eq) goto loc_8218B058;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12628
	ctx.r10.u64 = ctx.r11.u64 | 12628;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218b00c
	if (ctx.cr6.eq) goto loc_8218B00C;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218B00C:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218B01C;
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
loc_8218B04C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-20696
	ctx.r10.s64 = ctx.r11.s64 + -20696;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8218B058:
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

__attribute__((alias("__imp__sub_8218B06C"))) PPC_WEAK_FUNC(sub_8218B06C);
PPC_FUNC_IMPL(__imp__sub_8218B06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B070"))) PPC_WEAK_FUNC(sub_8218B070);
PPC_FUNC_IMPL(__imp__sub_8218B070) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218B078;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,148(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,4388
	ctx.r10.s64 = ctx.r11.s64 + 4388;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8218b09c
	if (ctx.cr6.eq) goto loc_8218B09C;
	// bl 0x8207a630
	ctx.lr = 0x8218B09C;
	sub_8207A630(ctx, base);
loc_8218B09C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218b0d8
	if (ctx.cr6.eq) goto loc_8218B0D8;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// stw r28,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r28.u32);
loc_8218B0D8:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r29,r31,108
	ctx.r29.s64 = ctx.r31.s64 + 108;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8218b0f0
	if (ctx.cr6.lt) goto loc_8218B0F0;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B0F0;
	sub_8207A630(ctx, base);
loc_8218B0F0:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r28,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r28.u32);
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// sth r28,4(r29)
	PPC_STORE_U16(ctx.r29.u32 + 4, ctx.r28.u16);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8218b118
	if (ctx.cr6.lt) goto loc_8218B118;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B118;
	sub_8207A630(ctx, base);
loc_8218B118:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r28.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r29,r11,-1408
	ctx.r29.s64 = ctx.r11.s64 + -1408;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stb r28,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r28.u8);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B13C;
	sub_82173A18(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r30,r9,-1456
	ctx.r30.s64 = ctx.r9.s64 + -1456;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B154;
	sub_82173A18(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218B164"))) PPC_WEAK_FUNC(sub_8218B164);
PPC_FUNC_IMPL(__imp__sub_8218B164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B168"))) PPC_WEAK_FUNC(sub_8218B168);
PPC_FUNC_IMPL(__imp__sub_8218B168) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218B170;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,4372
	ctx.r9.s64 = ctx.r10.s64 + 4372;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218b1c0
	if (ctx.cr6.eq) goto loc_8218B1C0;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// stw r28,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r28.u32);
loc_8218B1C0:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r29,r31,116
	ctx.r29.s64 = ctx.r31.s64 + 116;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8218b1d8
	if (ctx.cr6.lt) goto loc_8218B1D8;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B1D8;
	sub_8207A630(ctx, base);
loc_8218B1D8:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r28,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r28.u32);
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// sth r28,4(r29)
	PPC_STORE_U16(ctx.r29.u32 + 4, ctx.r28.u16);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8218b200
	if (ctx.cr6.lt) goto loc_8218B200;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B200;
	sub_8207A630(ctx, base);
loc_8218B200:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r28.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r29,r11,-1408
	ctx.r29.s64 = ctx.r11.s64 + -1408;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stb r28,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r28.u8);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B224;
	sub_82173A18(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r30,r9,-1456
	ctx.r30.s64 = ctx.r9.s64 + -1456;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B23C;
	sub_82173A18(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218B24C"))) PPC_WEAK_FUNC(sub_8218B24C);
PPC_FUNC_IMPL(__imp__sub_8218B24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B250"))) PPC_WEAK_FUNC(sub_8218B250);
PPC_FUNC_IMPL(__imp__sub_8218B250) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218B258;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,4356
	ctx.r9.s64 = ctx.r10.s64 + 4356;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218b2a8
	if (ctx.cr6.eq) goto loc_8218B2A8;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// stw r28,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r28.u32);
loc_8218B2A8:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r29,r31,108
	ctx.r29.s64 = ctx.r31.s64 + 108;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8218b2c0
	if (ctx.cr6.lt) goto loc_8218B2C0;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B2C0;
	sub_8207A630(ctx, base);
loc_8218B2C0:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r28,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r28.u32);
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// sth r28,4(r29)
	PPC_STORE_U16(ctx.r29.u32 + 4, ctx.r28.u16);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8218b2e8
	if (ctx.cr6.lt) goto loc_8218B2E8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B2E8;
	sub_8207A630(ctx, base);
loc_8218B2E8:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r28.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r29,r11,-1408
	ctx.r29.s64 = ctx.r11.s64 + -1408;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stb r28,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r28.u8);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B30C;
	sub_82173A18(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r30,r9,-1456
	ctx.r30.s64 = ctx.r9.s64 + -1456;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B324;
	sub_82173A18(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218B334"))) PPC_WEAK_FUNC(sub_8218B334);
PPC_FUNC_IMPL(__imp__sub_8218B334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B338"))) PPC_WEAK_FUNC(sub_8218B338);
PPC_FUNC_IMPL(__imp__sub_8218B338) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218B340;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,4340
	ctx.r9.s64 = ctx.r10.s64 + 4340;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,76(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218b390
	if (ctx.cr6.eq) goto loc_8218B390;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// stw r28,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r28.u32);
loc_8218B390:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// addi r29,r31,116
	ctx.r29.s64 = ctx.r31.s64 + 116;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8218b3a8
	if (ctx.cr6.lt) goto loc_8218B3A8;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B3A8;
	sub_8207A630(ctx, base);
loc_8218B3A8:
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r28,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r28.u32);
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// sth r28,4(r29)
	PPC_STORE_U16(ctx.r29.u32 + 4, ctx.r28.u16);
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8218b3d0
	if (ctx.cr6.lt) goto loc_8218B3D0;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8218B3D0;
	sub_8207A630(ctx, base);
loc_8218B3D0:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r28.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r29,r11,-1408
	ctx.r29.s64 = ctx.r11.s64 + -1408;
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stb r28,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r28.u8);
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B3F4;
	sub_82173A18(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r30,r9,-1456
	ctx.r30.s64 = ctx.r9.s64 + -1456;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218B40C;
	sub_82173A18(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218B41C"))) PPC_WEAK_FUNC(sub_8218B41C);
PPC_FUNC_IMPL(__imp__sub_8218B41C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B420"))) PPC_WEAK_FUNC(sub_8218B420);
PPC_FUNC_IMPL(__imp__sub_8218B420) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218B428;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r10,r11,12648
	ctx.r10.u64 = ctx.r11.u64 | 12648;
	// lwzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8218b460
	if (!ctx.cr6.eq) goto loc_8218B460;
	// addis r28,r3,13
	ctx.r28.s64 = ctx.r3.s64 + 851968;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// addi r28,r28,12644
	ctx.r28.s64 = ctx.r28.s64 + 12644;
	// ori r5,r11,12368
	ctx.r5.u64 = ctx.r11.u64 | 12368;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8218b554
	if (ctx.cr6.eq) goto loc_8218B554;
loc_8218B460:
	// addis r29,r31,13
	ctx.r29.s64 = ctx.r31.s64 + 851968;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r29,12640
	ctx.r29.s64 = ctx.r29.s64 + 12640;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218b480
	if (ctx.cr6.eq) goto loc_8218B480;
	// bl 0x8207a8a0
	ctx.lr = 0x8218B47C;
	sub_8207A8A0(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
loc_8218B480:
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12620
	ctx.r10.u64 = ctx.r11.u64 | 12620;
	// lwzx r11,r31,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218b49c
	if (ctx.cr6.eq) goto loc_8218B49C;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218B49C:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218B4A4;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218b50c
	if (ctx.cr6.eq) goto loc_8218B50C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24573
	ctx.r4.s64 = ctx.r11.s64 + -24573;
	// bl 0x82060190
	ctx.lr = 0x8218B4C0;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,24144
	ctx.r4.s64 = ctx.r10.s64 + 24144;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218B4D4;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218B4E4;
	sub_821CCF40(ctx, base);
	// addis r6,r31,13
	ctx.r6.s64 = ctx.r31.s64 + 851968;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r6,12628
	ctx.r6.s64 = ctx.r6.s64 + 12628;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x8218B504;
	sub_821BD670(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218b510
	goto loc_8218B510;
loc_8218B50C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218B510:
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
	ctx.lr = 0x8218B538;
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
loc_8218B554:
	// addis r27,r31,13
	ctx.r27.s64 = ctx.r31.s64 + 851968;
	// addi r3,r31,248
	ctx.r3.s64 = ctx.r31.s64 + 248;
	// addi r27,r27,12640
	ctx.r27.s64 = ctx.r27.s64 + 12640;
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x8218B568;
	sub_8207DAC0(ctx, base);
	// lis r11,13
	ctx.r11.s64 = 851968;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// ori r29,r11,12472
	ctx.r29.u64 = ctx.r11.u64 | 12472;
	// stw r29,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r29.u32);
	// bl 0x8207a8a0
	ctx.lr = 0x8218B57C;
	sub_8207A8A0(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// addic. r11,r31,136
	ctx.xer.ca = ctx.r31.u32 > 4294967159;
	ctx.r11.s64 = ctx.r31.s64 + 136;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r30.u32);
	// beq 0x8218b5a4
	if (ctx.cr0.eq) goto loc_8218B5A4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218b5a4
	if (ctx.cr6.eq) goto loc_8218B5A4;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// bl 0x8207dac0
	ctx.lr = 0x8218B5A4;
	sub_8207DAC0(ctx, base);
loc_8218B5A4:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218B5B4;
	sub_820735C8(ctx, base);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lis r9,13
	ctx.r9.s64 = 851968;
	// ori r8,r9,12636
	ctx.r8.u64 = ctx.r9.u64 | 12636;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwzx r3,r31,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// bl 0x8210e878
	ctx.lr = 0x8218B5E0;
	sub_8210E878(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218B5E8"))) PPC_WEAK_FUNC(sub_8218B5E8);
PPC_FUNC_IMPL(__imp__sub_8218B5E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218B5F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r9,r3,13
	ctx.r9.s64 = ctx.r3.s64 + 851968;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// addi r9,r9,12620
	ctx.r9.s64 = ctx.r9.s64 + 12620;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r11,r11,12616
	ctx.r11.u64 = ctx.r11.u64 | 12616;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218b61c
	if (ctx.cr6.eq) goto loc_8218B61C;
	// lwzx r8,r3,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_8218B61C:
	// lwzx r11,r31,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8218b66c
	if (ctx.cr6.eq) goto loc_8218B66C;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8218b638
	if (ctx.cr6.eq) goto loc_8218B638;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8218b74c
	if (ctx.cr6.eq) goto loc_8218B74C;
loc_8218B638:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218B648;
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
loc_8218B66C:
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8218b738
	if (!ctx.cr6.eq) goto loc_8218B738;
	// lwz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8218b738
	if (!ctx.cr6.eq) goto loc_8218B738;
	// lis r10,13
	ctx.r10.s64 = 851968;
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// ori r8,r10,12636
	ctx.r8.u64 = ctx.r10.u64 | 12636;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lwzx r6,r31,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r8.u32);
	// cmplw cr6,r6,r7
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8218b738
	if (!ctx.cr6.eq) goto loc_8218B738;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12624
	ctx.r10.u64 = ctx.r11.u64 | 12624;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8218b638
	if (!ctx.cr6.eq) goto loc_8218B638;
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82079fd8
	ctx.lr = 0x8218B6C4;
	sub_82079FD8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218b700
	if (ctx.cr6.eq) goto loc_8218B700;
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// addis r8,r31,13
	ctx.r8.s64 = ctx.r31.s64 + 851968;
	// addis r7,r31,13
	ctx.r7.s64 = ctx.r31.s64 + 851968;
	// addis r6,r31,13
	ctx.r6.s64 = ctx.r31.s64 + 851968;
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// addi r8,r8,12648
	ctx.r8.s64 = ctx.r8.s64 + 12648;
	// addi r7,r7,12644
	ctx.r7.s64 = ctx.r7.s64 + 12644;
	// addi r6,r6,12640
	ctx.r6.s64 = ctx.r6.s64 + 12640;
	// addi r5,r11,-104
	ctx.r5.s64 = ctx.r11.s64 + -104;
	// addi r4,r31,248
	ctx.r4.s64 = ctx.r31.s64 + 248;
	// bl 0x82193508
	ctx.lr = 0x8218B6FC;
	sub_82193508(ctx, base);
	// b 0x8218b704
	goto loc_8218B704;
loc_8218B700:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218B704:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r9,13
	ctx.r9.s64 = 851968;
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// ori r7,r9,12632
	ctx.r7.u64 = ctx.r9.u64 | 12632;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r6,r8,-19424
	ctx.r6.s64 = ctx.r8.s64 + -19424;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stwx r6,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r6.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8218B738:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218b74c
	if (ctx.cr6.eq) goto loc_8218B74C;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218B74C:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218B754;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218b7c0
	if (ctx.cr6.eq) goto loc_8218B7C0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24581
	ctx.r4.s64 = ctx.r11.s64 + -24581;
	// bl 0x82060190
	ctx.lr = 0x8218B774;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,24064
	ctx.r4.s64 = ctx.r10.s64 + 24064;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218B788;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218B798;
	sub_821CCF40(ctx, base);
	// addis r6,r31,13
	ctx.r6.s64 = ctx.r31.s64 + 851968;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r6,r6,12628
	ctx.r6.s64 = ctx.r6.s64 + 12628;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x8218B7B8;
	sub_821BD670(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218b7c4
	goto loc_8218B7C4;
loc_8218B7C0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218B7C4:
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
	ctx.lr = 0x8218B7EC;
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
}

__attribute__((alias("__imp__sub_8218B808"))) PPC_WEAK_FUNC(sub_8218B808);
PPC_FUNC_IMPL(__imp__sub_8218B808) {
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
	// lwz r30,-31356(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x8218b85c
	if (!ctx.cr6.eq) goto loc_8218B85C;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218B83C;
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
	// b 0x8218b90c
	goto loc_8218B90C;
loc_8218B85C:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpwi cr6,r3,99
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 99, ctx.xer);
	// blt cr6,0x8218b870
	if (ctx.cr6.lt) goto loc_8218B870;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8218b890
	goto loc_8218B890;
loc_8218B870:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218b884
	if (!ctx.cr6.eq) goto loc_8218B884;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8218b890
	goto loc_8218B890;
loc_8218B884:
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8218B890:
	// addi r4,r31,136
	ctx.r4.s64 = ctx.r31.s64 + 136;
	// bl 0x8218a800
	ctx.lr = 0x8218B898;
	sub_8218A800(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lis r11,13
	ctx.r11.s64 = 851968;
	// beq cr6,0x8218b8b4
	if (ctx.cr6.eq) goto loc_8218B8B4;
	// ori r9,r11,12616
	ctx.r9.u64 = ctx.r11.u64 | 12616;
	// li r10,3
	ctx.r10.s64 = 3;
	// stwx r10,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// b 0x8218b8f8
	goto loc_8218B8F8;
loc_8218B8B4:
	// ori r8,r11,12616
	ctx.r8.u64 = ctx.r11.u64 | 12616;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r10,99
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 99, ctx.xer);
	// stwx r9,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r9.u32);
	// blt cr6,0x8218b8d4
	if (ctx.cr6.lt) goto loc_8218B8D4;
loc_8218B8CC:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8218b8ec
	goto loc_8218B8EC;
loc_8218B8D4:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218b8cc
	if (ctx.cr6.eq) goto loc_8218B8CC;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8218B8EC:
	// lis r10,13
	ctx.r10.s64 = 851968;
	// ori r9,r10,12636
	ctx.r9.u64 = ctx.r10.u64 | 12636;
	// stwx r11,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u32);
loc_8218B8F8:
	// lis r11,13
	ctx.r11.s64 = 851968;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// ori r9,r11,12632
	ctx.r9.u64 = ctx.r11.u64 | 12632;
	// addi r8,r10,-18968
	ctx.r8.s64 = ctx.r10.s64 + -18968;
	// stwx r8,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r8.u32);
loc_8218B90C:
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

__attribute__((alias("__imp__sub_8218B924"))) PPC_WEAK_FUNC(sub_8218B924);
PPC_FUNC_IMPL(__imp__sub_8218B924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218B928"))) PPC_WEAK_FUNC(sub_8218B928);
PPC_FUNC_IMPL(__imp__sub_8218B928) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8218B930;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// addi r8,r8,-1396
	ctx.r8.s64 = ctx.r8.s64 + -1396;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r7,r7,840
	ctx.r7.s64 = ctx.r7.s64 + 840;
	// stb r11,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// lis r30,13
	ctx.r30.s64 = 851968;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lis r9,13
	ctx.r9.s64 = 851968;
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// lis r8,13
	ctx.r8.s64 = 851968;
	// stw r7,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r7.u32);
	// addi r7,r3,4356
	ctx.r7.s64 = ctx.r3.s64 + 4356;
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// li r26,15
	ctx.r26.s64 = 15;
	// stb r11,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// ori r10,r30,12640
	ctx.r10.u64 = ctx.r30.u64 | 12640;
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// ori r9,r9,12620
	ctx.r9.u64 = ctx.r9.u64 | 12620;
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// ori r8,r8,12624
	ctx.r8.u64 = ctx.r8.u64 | 12624;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// li r30,7
	ctx.r30.s64 = 7;
	// stb r11,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r11.u8);
	// addi r3,r31,136
	ctx.r3.s64 = ctx.r31.s64 + 136;
	// stw r5,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r5.u32);
	// lis r5,13
	ctx.r5.s64 = 851968;
	// stw r4,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r27,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r27.u8);
	// ori r5,r5,12480
	ctx.r5.u64 = ctx.r5.u64 | 12480;
	// stb r27,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r27.u8);
	// addi r29,r31,80
	ctx.r29.s64 = ctx.r31.s64 + 80;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// addi r28,r31,108
	ctx.r28.s64 = ctx.r31.s64 + 108;
	// stw r26,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r26.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// stb r11,84(r31)
	PPC_STORE_U8(ctx.r31.u32 + 84, ctx.r11.u8);
	// stw r30,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// sth r11,112(r31)
	PPC_STORE_U16(ctx.r31.u32 + 112, ctx.r11.u16);
	// stwx r6,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u32);
	// stbx r11,r31,r8
	PPC_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u8);
	// stwx r11,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r11.u32);
	// bl 0x8207da20
	ctx.lr = 0x8218BA24;
	sub_8207DA20(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r30,r9,24032
	ctx.r30.s64 = ctx.r9.s64 + 24032;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r4,r30,-20
	ctx.r4.s64 = ctx.r30.s64 + -20;
	// bl 0x82060368
	ctx.lr = 0x8218BA3C;
	sub_82060368(ctx, base);
	// addi r4,r30,-8
	ctx.r4.s64 = ctx.r30.s64 + -8;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82061760
	ctx.lr = 0x8218BA4C;
	sub_82061760(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207adf0
	ctx.lr = 0x8218BA54;
	sub_8207ADF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206a848
	ctx.lr = 0x8218BA64;
	sub_8206A848(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r11,-31352(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31352);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8218bab8
	if (ctx.cr6.eq) goto loc_8218BAB8;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// bne cr6,0x8218bab4
	if (!ctx.cr6.eq) goto loc_8218BAB4;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
loc_8218BAB4:
	// stw r27,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r27.u32);
loc_8218BAB8:
	// lis r11,13
	ctx.r11.s64 = 851968;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// ori r9,r11,12632
	ctx.r9.u64 = ctx.r11.u64 | 12632;
	// addi r8,r10,-18424
	ctx.r8.s64 = ctx.r10.s64 + -18424;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r8,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218BAD8"))) PPC_WEAK_FUNC(sub_8218BAD8);
PPC_FUNC_IMPL(__imp__sub_8218BAD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218BAE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r10,7504
	ctx.r9.s64 = ctx.r10.s64 + 7504;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8218bb18
	if (!ctx.cr6.eq) goto loc_8218BB18;
	// lwz r9,148(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 148);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8218bb18
	if (!ctx.cr6.eq) goto loc_8218BB18;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8218bb4c
	goto loc_8218BB4C;
loc_8218BB18:
	// lwz r9,256(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 256);
	// cmpwi cr6,r9,180
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 180, ctx.xer);
	// blt cr6,0x8218bb48
	if (ctx.cr6.lt) goto loc_8218BB48;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r9,7536
	ctx.r8.s64 = ctx.r9.s64 + 7536;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8218bb48
	if (!ctx.cr6.eq) goto loc_8218BB48;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,23176
	ctx.r8.s64 = ctx.r9.s64 + 23176;
	// stw r8,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r8.u32);
	// b 0x8218bb4c
	goto loc_8218BB4C;
loc_8218BB48:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8218BB4C:
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218bca0
	if (ctx.cr6.eq) goto loc_8218BCA0;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// lis r10,13
	ctx.r10.s64 = 851968;
	// ori r9,r11,12628
	ctx.r9.u64 = ctx.r11.u64 | 12628;
	// ori r11,r10,12624
	ctx.r11.u64 = ctx.r10.u64 | 12624;
	// lwzx r10,r31,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218bb7c
	if (ctx.cr6.eq) goto loc_8218BB7C;
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_8218BB7C:
	// lwzx r11,r31,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// li r3,264
	ctx.r3.s64 = 264;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8218bbf4
	if (ctx.cr6.eq) goto loc_8218BBF4;
	// bl 0x82079fd8
	ctx.lr = 0x8218BB90;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218bc64
	if (ctx.cr6.eq) goto loc_8218BC64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// addi r4,r11,-24582
	ctx.r4.s64 = ctx.r11.s64 + -24582;
	// bl 0x82060190
	ctx.lr = 0x8218BBAC;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,23992
	ctx.r4.s64 = ctx.r10.s64 + 23992;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060190
	ctx.lr = 0x8218BBC0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218BBD0;
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
	ctx.lr = 0x8218BBEC;
	sub_821BD670(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218bc68
	goto loc_8218BC68;
loc_8218BBF4:
	// bl 0x82079fd8
	ctx.lr = 0x8218BBF8;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218bc64
	if (ctx.cr6.eq) goto loc_8218BC64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-24582
	ctx.r11.s64 = ctx.r11.s64 + -24582;
	// addi r4,r11,-7
	ctx.r4.s64 = ctx.r11.s64 + -7;
	// bl 0x82060190
	ctx.lr = 0x8218BC18;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r11,r10,23992
	ctx.r11.s64 = ctx.r10.s64 + 23992;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,-24
	ctx.r4.s64 = ctx.r11.s64 + -24;
	// bl 0x82060190
	ctx.lr = 0x8218BC30;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218BC40;
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
	ctx.lr = 0x8218BC5C;
	sub_821BD670(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218bc68
	goto loc_8218BC68;
loc_8218BC64:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8218BC68:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r8,6640
	ctx.r4.s64 = ctx.r8.s64 + 6640;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x820735c8
	ctx.lr = 0x8218BC8C;
	sub_820735C8(ctx, base);
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
loc_8218BCA0:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218BCA8"))) PPC_WEAK_FUNC(sub_8218BCA8);
PPC_FUNC_IMPL(__imp__sub_8218BCA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218BCB0;
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
	// beq cr6,0x8218bd40
	if (ctx.cr6.eq) goto loc_8218BD40;
	// bl 0x82079fd8
	ctx.lr = 0x8218BCD4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218bda8
	if (ctx.cr6.eq) goto loc_8218BDA8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-24606
	ctx.r11.s64 = ctx.r11.s64 + -24606;
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// bl 0x82060190
	ctx.lr = 0x8218BCF4;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r10,23820
	ctx.r11.s64 = ctx.r10.s64 + 23820;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,-40
	ctx.r4.s64 = ctx.r11.s64 + -40;
	// bl 0x82060190
	ctx.lr = 0x8218BD0C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218BD1C;
	sub_821CCF40(ctx, base);
	// addis r6,r31,13
	ctx.r6.s64 = ctx.r31.s64 + 851968;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r6,12636
	ctx.r6.s64 = ctx.r6.s64 + 12636;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x8218BD3C;
	sub_821BD670(ctx, base);
	// b 0x8218bdac
	goto loc_8218BDAC;
loc_8218BD40:
	// bl 0x82079fd8
	ctx.lr = 0x8218BD44;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218bda8
	if (ctx.cr6.eq) goto loc_8218BDA8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,-24606
	ctx.r4.s64 = ctx.r11.s64 + -24606;
	// bl 0x82060190
	ctx.lr = 0x8218BD60;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,23820
	ctx.r4.s64 = ctx.r10.s64 + 23820;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218BD74;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218BD84;
	sub_821CCF40(ctx, base);
	// addis r6,r31,13
	ctx.r6.s64 = ctx.r31.s64 + 851968;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r6,12636
	ctx.r6.s64 = ctx.r6.s64 + 12636;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x8218BDA4;
	sub_821BD670(ctx, base);
	// b 0x8218bdac
	goto loc_8218BDAC;
loc_8218BDA8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8218BDAC:
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
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r10,r11,-20544
	ctx.r10.s64 = ctx.r11.s64 + -20544;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218BDDC"))) PPC_WEAK_FUNC(sub_8218BDDC);
PPC_FUNC_IMPL(__imp__sub_8218BDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218BDE0"))) PPC_WEAK_FUNC(sub_8218BDE0);
PPC_FUNC_IMPL(__imp__sub_8218BDE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218BDE8;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218BDF8;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218be5c
	if (ctx.cr6.eq) goto loc_8218BE5C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24613
	ctx.r4.s64 = ctx.r11.s64 + -24613;
	// bl 0x82060190
	ctx.lr = 0x8218BE18;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,23748
	ctx.r4.s64 = ctx.r10.s64 + 23748;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218BE2C;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218BE3C;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x8218BE58;
	sub_821BD670(ctx, base);
	// b 0x8218be60
	goto loc_8218BE60;
loc_8218BE5C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8218BE60:
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r9,13
	ctx.r9.s64 = 851968;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// ori r8,r9,12628
	ctx.r8.u64 = ctx.r9.u64 | 12628;
	// addi r31,r30,16
	ctx.r31.s64 = ctx.r30.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// lwzx r11,r30,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218be94
	if (ctx.cr6.eq) goto loc_8218BE94;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218BE94:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218BEA4;
	sub_820735C8(ctx, base);
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
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218BEC0"))) PPC_WEAK_FUNC(sub_8218BEC0);
PPC_FUNC_IMPL(__imp__sub_8218BEC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218BEC8;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,136(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r25,r3,136
	ctx.r25.s64 = ctx.r3.s64 + 136;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8218bf78
	if (ctx.cr6.eq) goto loc_8218BF78;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// ble cr6,0x8218bf34
	if (!ctx.cr6.gt) goto loc_8218BF34;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x8218bf34
	if (ctx.cr6.gt) goto loc_8218BF34;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218bf00
	if (ctx.cr6.eq) goto loc_8218BF00;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_8218BF00:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218BF10;
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
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8218BF34:
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218bf44
	if (ctx.cr6.eq) goto loc_8218BF44;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_8218BF44:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218BF54;
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
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8218BF78:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// bl 0x8207a030
	ctx.lr = 0x8218BF80;
	sub_8207A030(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r3.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x8218BF8C;
	sub_82079FD8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x8218c034
	if (ctx.cr6.eq) goto loc_8218C034;
	// li r27,15
	ctx.r27.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// addi r29,r31,80
	ctx.r29.s64 = ctx.r31.s64 + 80;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8218BFC8;
	sub_820601F8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// addi r4,r31,108
	ctx.r4.s64 = ctx.r31.s64 + 108;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// sth r30,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r30.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x8218BFEC;
	sub_82063CC8(ctx, base);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r27.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r30.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x8218C00C;
	sub_820601F8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// lwz r8,152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82194af0
	ctx.lr = 0x8218C030;
	sub_82194AF0(ctx, base);
	// b 0x8218c038
	goto loc_8218C038;
loc_8218C034:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218C038:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r9,13
	ctx.r9.s64 = 851968;
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// ori r7,r9,12640
	ctx.r7.u64 = ctx.r9.u64 | 12640;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r6,r8,-21400
	ctx.r6.s64 = ctx.r8.s64 + -21400;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stwx r6,r31,r7
	PPC_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r6.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C06C"))) PPC_WEAK_FUNC(sub_8218C06C);
PPC_FUNC_IMPL(__imp__sub_8218C06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C070"))) PPC_WEAK_FUNC(sub_8218C070);
PPC_FUNC_IMPL(__imp__sub_8218C070) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218C078;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r29,r3,80
	ctx.r29.s64 = ctx.r3.s64 + 80;
	// addi r31,r11,24252
	ctx.r31.s64 = ctx.r11.s64 + 24252;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r4,r31,-20
	ctx.r4.s64 = ctx.r31.s64 + -20;
	// li r5,10
	ctx.r5.s64 = 10;
	// bl 0x82060368
	ctx.lr = 0x8218C09C;
	sub_82060368(ctx, base);
	// addi r4,r31,-8
	ctx.r4.s64 = ctx.r31.s64 + -8;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82061760
	ctx.lr = 0x8218C0AC;
	sub_82061760(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207adf0
	ctx.lr = 0x8218C0B4;
	sub_8207ADF0(ctx, base);
	// addi r27,r30,108
	ctx.r27.s64 = ctx.r30.s64 + 108;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8206a848
	ctx.lr = 0x8218C0C8;
	sub_8206A848(ctx, base);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x8218C0D0;
	sub_82079FD8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq cr6,0x8218c16c
	if (ctx.cr6.eq) goto loc_8218C16C;
	// li r25,15
	ctx.r25.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// li r28,-1
	ctx.r28.s64 = -1;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8218C108;
	sub_820601F8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r31.u16);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x8218C12C;
	sub_82063CC8(ctx, base);
	// stw r25,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r25.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x8218C14C;
	sub_820601F8(ctx, base);
	// addi r8,r30,136
	ctx.r8.s64 = ctx.r30.s64 + 136;
	// addi r7,r30,152
	ctx.r7.s64 = ctx.r30.s64 + 152;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82194978
	ctx.lr = 0x8218C168;
	sub_82194978(ctx, base);
	// b 0x8218c170
	goto loc_8218C170;
loc_8218C16C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8218C170:
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r9,13
	ctx.r9.s64 = 851968;
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// ori r7,r9,12640
	ctx.r7.u64 = ctx.r9.u64 | 12640;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r6,r8,-16704
	ctx.r6.s64 = ctx.r8.s64 + -16704;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r10,r30,16
	ctx.r10.s64 = ctx.r30.s64 + 16;
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stwx r6,r30,r7
	PPC_STORE_U32(ctx.r30.u32 + ctx.r7.u32, ctx.r6.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C1A4"))) PPC_WEAK_FUNC(sub_8218C1A4);
PPC_FUNC_IMPL(__imp__sub_8218C1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C1A8"))) PPC_WEAK_FUNC(sub_8218C1A8);
PPC_FUNC_IMPL(__imp__sub_8218C1A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218C1B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r29,r3,44
	ctx.r29.s64 = ctx.r3.s64 + 44;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r7,r10,-1396
	ctx.r7.s64 = ctx.r10.s64 + -1396;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r11,r29,16
	ctx.r11.s64 = ctx.r29.s64 + 16;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r6,r9,840
	ctx.r6.s64 = ctx.r9.s64 + 840;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r3,r8,4388
	ctx.r3.s64 = ctx.r8.s64 + 4388;
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// li r25,15
	ctx.r25.s64 = 15;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// addi r11,r31,108
	ctx.r11.s64 = ctx.r31.s64 + 108;
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// stw r4,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r4.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stb r26,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r26.u8);
	// stb r26,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r26.u8);
	// stw r30,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
	// stw r25,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r25.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stb r30,84(r31)
	PPC_STORE_U8(ctx.r31.u32 + 84, ctx.r30.u8);
	// lwz r27,-31356(r28)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31356);
	// stw r10,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r10.u32);
	// stw r30,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// sth r30,112(r31)
	PPC_STORE_U16(ctx.r31.u32 + 112, ctx.r30.u16);
	// stw r5,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r5.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r30.u32);
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
	// beq cr6,0x8218c2a8
	if (ctx.cr6.eq) goto loc_8218C2A8;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c298
	if (ctx.cr6.eq) goto loc_8218C298;
	// bl 0x8207a8a0
	ctx.lr = 0x8218C298;
	sub_8207A8A0(ctx, base);
loc_8218C298:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207a630
	ctx.lr = 0x8218C2A0;
	sub_8207A630(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,-31356(r28)
	PPC_STORE_U32(ctx.r28.u32 + -31356, ctx.r30.u32);
loc_8218C2A8:
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82079fd8
	ctx.lr = 0x8218C2B0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c2c4
	if (ctx.cr6.eq) goto loc_8218C2C4;
	// bl 0x8218aaa0
	ctx.lr = 0x8218C2BC;
	sub_8218AAA0(ctx, base);
	// stw r3,-31356(r28)
	PPC_STORE_U32(ctx.r28.u32 + -31356, ctx.r3.u32);
	// b 0x8218c2cc
	goto loc_8218C2CC;
loc_8218C2C4:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,-31356(r28)
	PPC_STORE_U32(ctx.r28.u32 + -31356, ctx.r30.u32);
loc_8218C2CC:
	// li r5,10296
	ctx.r5.s64 = 10296;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x8218C2DC;
	sub_8207DA20(ctx, base);
	// li r10,99
	ctx.r10.s64 = 99;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8218C2E8:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,104
	ctx.r11.s64 = ctx.r11.s64 + 104;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// bdnz 0x8218c2e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218C2E8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8218c350
	if (ctx.cr6.eq) goto loc_8218C350;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// bne cr6,0x8218c34c
	if (!ctx.cr6.eq) goto loc_8218C34C;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
loc_8218C34C:
	// stw r26,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r26.u32);
loc_8218C350:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218C358;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c3d4
	if (ctx.cr6.eq) goto loc_8218C3D4;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// addi r4,r11,-24566
	ctx.r4.s64 = ctx.r11.s64 + -24566;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x8218C384;
	sub_82060368(ctx, base);
	// stw r25,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r25.u32);
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r4,r10,24216
	ctx.r4.s64 = ctx.r10.s64 + 24216;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060368
	ctx.lr = 0x8218C3A4;
	sub_82060368(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821ccf40
	ctx.lr = 0x8218C3B4;
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
	ctx.lr = 0x8218C3D0;
	sub_821BD670(ctx, base);
	// b 0x8218c3d8
	goto loc_8218C3D8;
loc_8218C3D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218C3D8:
	// lis r11,13
	ctx.r11.s64 = 851968;
	// stw r3,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r3.u32);
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// ori r8,r11,12640
	ctx.r8.u64 = ctx.r11.u64 | 12640;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r10,-16272
	ctx.r7.s64 = ctx.r10.s64 + -16272;
	// stw r11,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r7,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C410"))) PPC_WEAK_FUNC(sub_8218C410);
PPC_FUNC_IMPL(__imp__sub_8218C410) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8218C418;
	__savegprlr_24(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31356(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31356);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218c454
	if (ctx.cr6.eq) goto loc_8218C454;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// bl 0x8218a540
	ctx.lr = 0x8218C438;
	sub_8218A540(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8218c488
	if (ctx.cr6.eq) goto loc_8218C488;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218c454
	if (ctx.cr6.eq) goto loc_8218C454;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218C454:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218C464;
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
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8218C488:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x8218C490;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c500
	if (ctx.cr6.eq) goto loc_8218C500;
	// lwz r11,-31356(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31356);
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r28,r31,80
	ctx.r28.s64 = ctx.r31.s64 + 80;
	// lwz r27,4(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r26,0(r11)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x820608b0
	ctx.lr = 0x8218C4BC;
	sub_820608B0(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// addi r4,r31,116
	ctx.r4.s64 = ctx.r31.s64 + 116;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063ba8
	ctx.lr = 0x8218C4CC;
	sub_82063BA8(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820608b0
	ctx.lr = 0x8218C4DC;
	sub_820608B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// bl 0x82194c78
	ctx.lr = 0x8218C4FC;
	sub_82194C78(ctx, base);
	// b 0x8218c504
	goto loc_8218C504;
loc_8218C500:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8218C504:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-21032
	ctx.r6.s64 = ctx.r8.s64 + -21032;
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
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C534"))) PPC_WEAK_FUNC(sub_8218C534);
PPC_FUNC_IMPL(__imp__sub_8218C534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C538"))) PPC_WEAK_FUNC(sub_8218C538);
PPC_FUNC_IMPL(__imp__sub_8218C538) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218C540;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r3,r8,-1396
	ctx.r3.s64 = ctx.r8.s64 + -1396;
	// stb r11,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// addi r9,r7,840
	ctx.r9.s64 = ctx.r7.s64 + 840;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// addi r8,r6,4372
	ctx.r8.s64 = ctx.r6.s64 + 4372;
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// li r7,15
	ctx.r7.s64 = 15;
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// li r6,7
	ctx.r6.s64 = 7;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// stb r11,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// addi r29,r31,88
	ctx.r29.s64 = ctx.r31.s64 + 88;
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// addi r30,r3,24184
	ctx.r30.s64 = ctx.r3.s64 + 24184;
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// addi r28,r31,116
	ctx.r28.s64 = ctx.r31.s64 + 116;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stb r11,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r11.u8);
	// stw r4,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r4.u32);
	// addi r4,r30,-20
	ctx.r4.s64 = ctx.r30.s64 + -20;
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// stb r27,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r27.u8);
	// stb r27,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r27.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r7.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stb r11,92(r31)
	PPC_STORE_U8(ctx.r31.u32 + 92, ctx.r11.u8);
	// stw r6,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r6.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// sth r11,120(r31)
	PPC_STORE_U16(ctx.r31.u32 + 120, ctx.r11.u16);
	// bl 0x82060368
	ctx.lr = 0x8218C614;
	sub_82060368(ctx, base);
	// addi r4,r30,-8
	ctx.r4.s64 = ctx.r30.s64 + -8;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82061760
	ctx.lr = 0x8218C624;
	sub_82061760(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207adf0
	ctx.lr = 0x8218C62C;
	sub_8207ADF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206a848
	ctx.lr = 0x8218C63C;
	sub_8206A848(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8218c690
	if (ctx.cr6.eq) goto loc_8218C690;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// bne cr6,0x8218c68c
	if (!ctx.cr6.eq) goto loc_8218C68C;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
loc_8218C68C:
	// stw r27,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r27.u32);
loc_8218C690:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-15344
	ctx.r10.s64 = ctx.r11.s64 + -15344;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C6A8"))) PPC_WEAK_FUNC(sub_8218C6A8);
PPC_FUNC_IMPL(__imp__sub_8218C6A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8218C6B0;
	__savegprlr_24(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x8218C6C0;
	sub_82079FD8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x8218c77c
	if (ctx.cr6.eq) goto loc_8218C77C;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r27,15
	ctx.r27.s64 = 15;
	// addi r29,r31,88
	ctx.r29.s64 = ctx.r31.s64 + 88;
	// li r28,-1
	ctx.r28.s64 = -1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,-31356(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r25,4(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r24,0(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// bl 0x820601f8
	ctx.lr = 0x8218C70C;
	sub_820601F8(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// addi r4,r31,116
	ctx.r4.s64 = ctx.r31.s64 + 116;
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// sth r30,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r30.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x8218C730;
	sub_82063CC8(ctx, base);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r27.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r30.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x8218C750;
	sub_820601F8(ctx, base);
	// addis r9,r31,13
	ctx.r9.s64 = ctx.r31.s64 + 851968;
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// addi r9,r9,12624
	ctx.r9.s64 = ctx.r9.s64 + 12624;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82194c78
	ctx.lr = 0x8218C774;
	sub_82194C78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8218c780
	goto loc_8218C780;
loc_8218C77C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218C780:
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
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8218C7A0;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c800
	if (ctx.cr6.eq) goto loc_8218C800;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,-24590
	ctx.r4.s64 = ctx.r11.s64 + -24590;
	// bl 0x82060190
	ctx.lr = 0x8218C7BC;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,23956
	ctx.r4.s64 = ctx.r10.s64 + 23956;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218C7D0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218C7E0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,2
	ctx.r8.s64 = 2;
	// bl 0x821bd670
	ctx.lr = 0x8218C7FC;
	sub_821BD670(ctx, base);
	// b 0x8218c804
	goto loc_8218C804;
loc_8218C800:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8218C804:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r8,r10,-17704
	ctx.r8.s64 = ctx.r10.s64 + -17704;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C834"))) PPC_WEAK_FUNC(sub_8218C834);
PPC_FUNC_IMPL(__imp__sub_8218C834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C838"))) PPC_WEAK_FUNC(sub_8218C838);
PPC_FUNC_IMPL(__imp__sub_8218C838) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218C840;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-31356(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// bl 0x82088378
	ctx.lr = 0x8218C860;
	sub_82088378(ctx, base);
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r9,-31352(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// lwz r3,52(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c898
	if (ctx.cr6.eq) goto loc_8218C898;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x8218C88C;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218c898
	if (!ctx.cr6.eq) goto loc_8218C898;
	// ld r31,96(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
loc_8218C898:
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12640
	ctx.r10.u64 = ctx.r11.u64 | 12640;
	// lwzx r11,r28,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218c8bc
	if (ctx.cr6.eq) goto loc_8218C8BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// clrldi r3,r11,32
	ctx.r3.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// bl 0x82088378
	ctx.lr = 0x8218C8B8;
	sub_82088378(ctx, base);
	// add r31,r3,r31
	ctx.r31.u64 = ctx.r3.u64 + ctx.r31.u64;
loc_8218C8BC:
	// cmpld cr6,r29,r31
	ctx.cr6.compare<uint64_t>(ctx.r29.u64, ctx.r31.u64, ctx.xer);
	// ble cr6,0x8218c938
	if (!ctx.cr6.gt) goto loc_8218C938;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// lwz r10,-31352(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// addi r9,r11,-16928
	ctx.r9.s64 = ctx.r11.s64 + -16928;
	// stw r9,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r9.u32);
	// lwz r8,76(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r31,84(r8)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// bne cr6,0x8218c914
	if (!ctx.cr6.eq) goto loc_8218C914;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218c914
	if (ctx.cr6.eq) goto loc_8218C914;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x8218C8FC;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218c90c
	if (!ctx.cr6.eq) goto loc_8218C90C;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8218c918
	goto loc_8218C918;
loc_8218C90C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_8218C914:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8218C918:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218c944
	if (!ctx.cr6.eq) goto loc_8218C944;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-17240
	ctx.r10.s64 = ctx.r11.s64 + -17240;
	// stw r10,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8218C938:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-14680
	ctx.r10.s64 = ctx.r11.s64 + -14680;
	// stw r10,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r10.u32);
loc_8218C944:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218C94C"))) PPC_WEAK_FUNC(sub_8218C94C);
PPC_FUNC_IMPL(__imp__sub_8218C94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218C950"))) PPC_WEAK_FUNC(sub_8218C950);
PPC_FUNC_IMPL(__imp__sub_8218C950) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218C958;
	__savegprlr_25(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r26,r3,13
	ctx.r26.s64 = ctx.r3.s64 + 851968;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r26,r26,12640
	ctx.r26.s64 = ctx.r26.s64 + 12640;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r31,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8218C978;
	sub_82079FD8(ctx, base);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ca18
	if (ctx.cr6.eq) goto loc_8218CA18;
	// li r27,15
	ctx.r27.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r29,r30,88
	ctx.r29.s64 = ctx.r30.s64 + 88;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8218C9B0;
	sub_820601F8(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// addi r4,r30,116
	ctx.r4.s64 = ctx.r30.s64 + 116;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, ctx.r31.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82063cc8
	ctx.lr = 0x8218C9D4;
	sub_82063CC8(ctx, base);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r27.u32);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x820601f8
	ctx.lr = 0x8218C9F4;
	sub_820601F8(ctx, base);
	// addis r8,r30,13
	ctx.r8.s64 = ctx.r30.s64 + 851968;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// addi r8,r8,12624
	ctx.r8.s64 = ctx.r8.s64 + 12624;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82194978
	ctx.lr = 0x8218CA14;
	sub_82194978(ctx, base);
	// b 0x8218ca1c
	goto loc_8218CA1C;
loc_8218CA18:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8218CA1C:
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,-14280
	ctx.r7.s64 = ctx.r8.s64 + -14280;
	// addi r10,r30,16
	ctx.r10.s64 = ctx.r30.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r7,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r7.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218CA48"))) PPC_WEAK_FUNC(sub_8218CA48);
PPC_FUNC_IMPL(__imp__sub_8218CA48) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r30,84(r10)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8218caa8
	if (!ctx.cr6.eq) goto loc_8218CAA8;
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218caa8
	if (ctx.cr6.eq) goto loc_8218CAA8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x8218CA90;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218caa0
	if (!ctx.cr6.eq) goto loc_8218CAA0;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8218caac
	goto loc_8218CAAC;
loc_8218CAA0:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r30)
	PPC_STORE_U32(ctx.r30.u32 + 52, ctx.r11.u32);
loc_8218CAA8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8218CAAC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218cac4
	if (!ctx.cr6.eq) goto loc_8218CAC4;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-17240
	ctx.r10.s64 = ctx.r11.s64 + -17240;
	// b 0x8218cb44
	goto loc_8218CB44;
loc_8218CAC4:
	// lis r11,13
	ctx.r11.s64 = 851968;
	// addi r30,r31,144
	ctx.r30.s64 = ctx.r31.s64 + 144;
	// ori r10,r11,12632
	ctx.r10.u64 = ctx.r11.u64 | 12632;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8218caec
	if (ctx.cr6.eq) goto loc_8218CAEC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x8218ab30
	ctx.lr = 0x8218CAE8;
	sub_8218AB30(ctx, base);
	// b 0x8218cb28
	goto loc_8218CB28;
loc_8218CAEC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8218cb14
	if (ctx.cr6.eq) goto loc_8218CB14;
	// lis r5,13
	ctx.r5.s64 = 851968;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r5,r5,12480
	ctx.r5.u64 = ctx.r5.u64 | 12480;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207da20
	ctx.lr = 0x8218CB08;
	sub_8207DA20(ctx, base);
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// ori r10,r11,2048
	ctx.r10.u64 = ctx.r11.u64 | 2048;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
loc_8218CB14:
	// lis r5,13
	ctx.r5.s64 = 851968;
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r3,r31,152
	ctx.r3.s64 = ctx.r31.s64 + 152;
	// ori r5,r5,12472
	ctx.r5.u64 = ctx.r5.u64 | 12472;
	// bl 0x8207dac0
	ctx.lr = 0x8218CB28;
	sub_8207DAC0(ctx, base);
loc_8218CB28:
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// bl 0x8218a688
	ctx.lr = 0x8218CB3C;
	sub_8218A688(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-14000
	ctx.r10.s64 = ctx.r11.s64 + -14000;
loc_8218CB44:
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8218CB60"))) PPC_WEAK_FUNC(sub_8218CB60);
PPC_FUNC_IMPL(__imp__sub_8218CB60) {
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
	// lis r11,13
	ctx.r11.s64 = 851968;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r10,r11,12636
	ctx.r10.u64 = ctx.r11.u64 | 12636;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8218cbec
	if (ctx.cr6.eq) goto loc_8218CBEC;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218cbf8
	if (!ctx.cr6.eq) goto loc_8218CBF8;
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12628
	ctx.r10.u64 = ctx.r11.u64 | 12628;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218cbac
	if (ctx.cr6.eq) goto loc_8218CBAC;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218CBAC:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218CBBC;
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
loc_8218CBEC:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-13752
	ctx.r10.s64 = ctx.r11.s64 + -13752;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8218CBF8:
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

__attribute__((alias("__imp__sub_8218CC0C"))) PPC_WEAK_FUNC(sub_8218CC0C);
PPC_FUNC_IMPL(__imp__sub_8218CC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CC10"))) PPC_WEAK_FUNC(sub_8218CC10);
PPC_FUNC_IMPL(__imp__sub_8218CC10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218CC18;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,13
	ctx.r30.s64 = ctx.r3.s64 + 851968;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r30,12636
	ctx.r30.s64 = ctx.r30.s64 + 12636;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8218CC38;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218cc98
	if (ctx.cr6.eq) goto loc_8218CC98;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24597
	ctx.r4.s64 = ctx.r11.s64 + -24597;
	// bl 0x82060190
	ctx.lr = 0x8218CC54;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,23920
	ctx.r4.s64 = ctx.r10.s64 + 23920;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218CC68;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218CC78;
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
	ctx.lr = 0x8218CC94;
	sub_821BD670(ctx, base);
	// b 0x8218cc9c
	goto loc_8218CC9C;
loc_8218CC98:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8218CC9C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,-13472
	ctx.r7.s64 = ctx.r8.s64 + -13472;
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

__attribute__((alias("__imp__sub_8218CCC8"))) PPC_WEAK_FUNC(sub_8218CCC8);
PPC_FUNC_IMPL(__imp__sub_8218CCC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218CCD0;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,13
	ctx.r30.s64 = ctx.r3.s64 + 851968;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r30,12636
	ctx.r30.s64 = ctx.r30.s64 + 12636;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8218CCF0;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218cd50
	if (ctx.cr6.eq) goto loc_8218CD50;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24598
	ctx.r4.s64 = ctx.r11.s64 + -24598;
	// bl 0x82060190
	ctx.lr = 0x8218CD0C;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,23884
	ctx.r4.s64 = ctx.r10.s64 + 23884;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218CD20;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218CD30;
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
	ctx.lr = 0x8218CD4C;
	sub_821BD670(ctx, base);
	// b 0x8218cd54
	goto loc_8218CD54;
loc_8218CD50:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8218CD54:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,-13472
	ctx.r7.s64 = ctx.r8.s64 + -13472;
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

__attribute__((alias("__imp__sub_8218CD80"))) PPC_WEAK_FUNC(sub_8218CD80);
PPC_FUNC_IMPL(__imp__sub_8218CD80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218CD88;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,13
	ctx.r30.s64 = ctx.r3.s64 + 851968;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r30,12636
	ctx.r30.s64 = ctx.r30.s64 + 12636;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// stw r28,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8218CDA8;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ce08
	if (ctx.cr6.eq) goto loc_8218CE08;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24605
	ctx.r4.s64 = ctx.r11.s64 + -24605;
	// bl 0x82060190
	ctx.lr = 0x8218CDC4;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r4,r10,23856
	ctx.r4.s64 = ctx.r10.s64 + 23856;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218CDD8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218CDE8;
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
	ctx.lr = 0x8218CE04;
	sub_821BD670(ctx, base);
	// b 0x8218ce0c
	goto loc_8218CE0C;
loc_8218CE08:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8218CE0C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r7,r8,-13472
	ctx.r7.s64 = ctx.r8.s64 + -13472;
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

__attribute__((alias("__imp__sub_8218CE38"))) PPC_WEAK_FUNC(sub_8218CE38);
PPC_FUNC_IMPL(__imp__sub_8218CE38) {
	PPC_FUNC_PROLOGUE();
	// lis r11,13
	ctx.r11.s64 = 851968;
	// ori r10,r11,12624
	ctx.r10.u64 = ctx.r11.u64 | 12624;
	// lwzx r11,r3,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x8218ce74
	if (ctx.cr6.eq) goto loc_8218CE74;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8218ce64
	if (ctx.cr6.eq) goto loc_8218CE64;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-13752
	ctx.r10.s64 = ctx.r11.s64 + -13752;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_8218CE64:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-13296
	ctx.r10.s64 = ctx.r11.s64 + -13296;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_8218CE74:
	// lis r11,2320
	ctx.r11.s64 = 152043520;
	// lwz r10,144(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// ori r11,r11,2048
	ctx.r11.u64 = ctx.r11.u64 | 2048;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8218cea4
	if (!ctx.cr6.eq) goto loc_8218CEA4;
	// lwz r10,156(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8218cea4
	if (!ctx.cr6.eq) goto loc_8218CEA4;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-12928
	ctx.r10.s64 = ctx.r11.s64 + -12928;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_8218CEA4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-13112
	ctx.r10.s64 = ctx.r11.s64 + -13112;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218CEB4"))) PPC_WEAK_FUNC(sub_8218CEB4);
PPC_FUNC_IMPL(__imp__sub_8218CEB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CEB8"))) PPC_WEAK_FUNC(sub_8218CEB8);
PPC_FUNC_IMPL(__imp__sub_8218CEB8) {
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
	// lwz r11,-31356(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31356);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218cf18
	if (!ctx.cr6.eq) goto loc_8218CF18;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218CEE8;
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
loc_8218CF18:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r3,99
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 99, ctx.xer);
	// blt cr6,0x8218cf2c
	if (ctx.cr6.lt) goto loc_8218CF2C;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8218cf4c
	goto loc_8218CF4C;
loc_8218CF2C:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218cf40
	if (!ctx.cr6.eq) goto loc_8218CF40;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8218cf4c
	goto loc_8218CF4C;
loc_8218CF40:
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
loc_8218CF4C:
	// addi r4,r31,144
	ctx.r4.s64 = ctx.r31.s64 + 144;
	// bl 0x8218a800
	ctx.lr = 0x8218CF54;
	sub_8218A800(ctx, base);
	// lis r11,13
	ctx.r11.s64 = 851968;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ori r9,r11,12624
	ctx.r9.u64 = ctx.r11.u64 | 12624;
	// beq cr6,0x8218cf7c
	if (ctx.cr6.eq) goto loc_8218CF7C;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x8218cf74
	if (ctx.cr6.eq) goto loc_8218CF74;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x8218cf80
	goto loc_8218CF80;
loc_8218CF74:
	// li r10,2
	ctx.r10.s64 = 2;
	// b 0x8218cf80
	goto loc_8218CF80;
loc_8218CF7C:
	// li r10,1
	ctx.r10.s64 = 1;
loc_8218CF80:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stwx r10,r31,r9
	PPC_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// addi r10,r11,-12744
	ctx.r10.s64 = ctx.r11.s64 + -12744;
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

__attribute__((alias("__imp__sub_8218CFA4"))) PPC_WEAK_FUNC(sub_8218CFA4);
PPC_FUNC_IMPL(__imp__sub_8218CFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218CFA8"))) PPC_WEAK_FUNC(sub_8218CFA8);
PPC_FUNC_IMPL(__imp__sub_8218CFA8) {
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
	// bne cr6,0x8218d008
	if (!ctx.cr6.eq) goto loc_8218D008;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218d008
	if (ctx.cr6.eq) goto loc_8218D008;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x8218CFF0;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218d000
	if (!ctx.cr6.eq) goto loc_8218D000;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8218d00c
	goto loc_8218D00C;
loc_8218D000:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_8218D008:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8218D00C:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218d024
	if (!ctx.cr6.eq) goto loc_8218D024;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-17240
	ctx.r10.s64 = ctx.r11.s64 + -17240;
	// b 0x8218d02c
	goto loc_8218D02C;
loc_8218D024:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-12616
	ctx.r10.s64 = ctx.r11.s64 + -12616;
loc_8218D02C:
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

__attribute__((alias("__imp__sub_8218D048"))) PPC_WEAK_FUNC(sub_8218D048);
PPC_FUNC_IMPL(__imp__sub_8218D048) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8218D050;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r9,-1396
	ctx.r3.s64 = ctx.r9.s64 + -1396;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r8,r8,840
	ctx.r8.s64 = ctx.r8.s64 + 840;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// stb r11,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stb r11,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r11.u8);
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// stb r11,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r11.u8);
	// lis r30,13
	ctx.r30.s64 = 851968;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lis r3,13
	ctx.r3.s64 = 851968;
	// stb r11,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r11.u8);
	// li r26,1
	ctx.r26.s64 = 1;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// addi r10,r9,4340
	ctx.r10.s64 = ctx.r9.s64 + 4340;
	// stw r8,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r8.u32);
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// ori r8,r30,12632
	ctx.r8.u64 = ctx.r30.u64 | 12632;
	// stb r11,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r11.u8);
	// ori r3,r3,12628
	ctx.r3.u64 = ctx.r3.u64 | 12628;
	// stb r11,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r11.u8);
	// li r28,7
	ctx.r28.s64 = 7;
	// stb r11,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r11.u8);
	// addi r30,r31,88
	ctx.r30.s64 = ctx.r31.s64 + 88;
	// stw r11,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// addi r29,r31,116
	ctx.r29.s64 = ctx.r31.s64 + 116;
	// stb r11,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r11.u8);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r4,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r4.u32);
	// stb r26,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r26.u8);
	// stb r26,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r26.u8);
	// stw r5,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r5.u32);
	// lwz r10,-31352(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31352);
	// stw r9,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r9.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// stb r11,92(r31)
	PPC_STORE_U8(ctx.r31.u32 + 92, ctx.r11.u8);
	// stw r28,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r28.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r11.u32);
	// sth r11,120(r31)
	PPC_STORE_U16(ctx.r31.u32 + 120, ctx.r11.u16);
	// stwx r6,r31,r3
	PPC_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r6.u32);
	// stwx r7,r31,r8
	PPC_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// lwz r7,76(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r5,76(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// blt cr6,0x8218d164
	if (ctx.cr6.lt) goto loc_8218D164;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8218d150
	if (ctx.cr6.eq) goto loc_8218D150;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
loc_8218D150:
	// li r11,2
	ctx.r11.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8218D164:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r28,r11,23716
	ctx.r28.s64 = ctx.r11.s64 + 23716;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r28,-88
	ctx.r4.s64 = ctx.r28.s64 + -88;
	// bl 0x82060368
	ctx.lr = 0x8218D17C;
	sub_82060368(ctx, base);
	// addi r4,r28,-8
	ctx.r4.s64 = ctx.r28.s64 + -8;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82061760
	ctx.lr = 0x8218D18C;
	sub_82061760(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207adf0
	ctx.lr = 0x8218D194;
	sub_8207ADF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8206a848
	ctx.lr = 0x8218D1A4;
	sub_8206A848(ctx, base);
	// lwz r11,-31352(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// beq cr6,0x8218d1f4
	if (ctx.cr6.eq) goto loc_8218D1F4;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r7,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r7.u32);
	// bne cr6,0x8218d1f0
	if (!ctx.cr6.eq) goto loc_8218D1F0;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r8,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
loc_8218D1F0:
	// stw r26,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r26.u32);
loc_8218D1F4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-12376
	ctx.r10.s64 = ctx.r11.s64 + -12376;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218D20C"))) PPC_WEAK_FUNC(sub_8218D20C);
PPC_FUNC_IMPL(__imp__sub_8218D20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D210"))) PPC_WEAK_FUNC(sub_8218D210);
PPC_FUNC_IMPL(__imp__sub_8218D210) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218D21C"))) PPC_WEAK_FUNC(sub_8218D21C);
PPC_FUNC_IMPL(__imp__sub_8218D21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D220"))) PPC_WEAK_FUNC(sub_8218D220);
PPC_FUNC_IMPL(__imp__sub_8218D220) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218D22C"))) PPC_WEAK_FUNC(sub_8218D22C);
PPC_FUNC_IMPL(__imp__sub_8218D22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D230"))) PPC_WEAK_FUNC(sub_8218D230);
PPC_FUNC_IMPL(__imp__sub_8218D230) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218D238;
	__savegprlr_27(ctx, base);
	// addi r11,r4,36
	ctx.r11.s64 = ctx.r4.s64 + 36;
	// addi r10,r4,25
	ctx.r10.s64 = ctx.r4.s64 + 25;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r31,4096
	ctx.r31.s64 = 268435456;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r4,r9
	ctx.r7.u64 = ctx.r4.u64 + ctx.r9.u64;
	// add r6,r4,r11
	ctx.r6.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r7,7,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r4,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	// li r7,9
	ctx.r7.s64 = 9;
	// stw r10,428(r9)
	PPC_STORE_U32(ctx.r9.u32 + 428, ctx.r10.u32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stwx r7,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r7.u32);
	// lis r4,8192
	ctx.r4.s64 = 536870912;
	// addi r8,r11,456
	ctx.r8.s64 = ctx.r11.s64 + 456;
	// ori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 | 1;
	// stw r8,436(r9)
	PPC_STORE_U32(ctx.r9.u32 + 436, ctx.r8.u32);
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r10,456(r11)
	PPC_STORE_U32(ctx.r11.u32 + 456, ctx.r10.u32);
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// stb r7,464(r11)
	PPC_STORE_U8(ctx.r11.u32 + 464, ctx.r7.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r6,r3,9
	ctx.r6.u64 = ctx.r3.u64 | 9;
	// ori r3,r9,2
	ctx.r3.u64 = ctx.r9.u64 | 2;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r8,3
	ctx.r8.u64 = ctx.r8.u64 | 3;
	// ori r4,r4,4
	ctx.r4.u64 = ctx.r4.u64 | 4;
	// lis r30,4096
	ctx.r30.s64 = 268435456;
	// ori r31,r31,5
	ctx.r31.u64 = ctx.r31.u64 | 5;
	// lis r29,4096
	ctx.r29.s64 = 268435456;
	// ori r30,r30,6
	ctx.r30.u64 = ctx.r30.u64 | 6;
	// lis r28,4096
	ctx.r28.s64 = 268435456;
	// ori r29,r29,7
	ctx.r29.u64 = ctx.r29.u64 | 7;
	// ld r27,40(r5)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r5.u32 + 40);
	// ori r28,r28,8
	ctx.r28.u64 = ctx.r28.u64 | 8;
	// std r27,472(r11)
	PPC_STORE_U64(ctx.r11.u32 + 472, ctx.r27.u64);
	// stw r6,480(r11)
	PPC_STORE_U32(ctx.r11.u32 + 480, ctx.r6.u32);
	// stb r10,488(r11)
	PPC_STORE_U8(ctx.r11.u32 + 488, ctx.r10.u8);
	// lwz r6,48(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// stw r6,496(r11)
	PPC_STORE_U32(ctx.r11.u32 + 496, ctx.r6.u32);
	// stw r3,504(r11)
	PPC_STORE_U32(ctx.r11.u32 + 504, ctx.r3.u32);
	// stb r7,512(r11)
	PPC_STORE_U8(ctx.r11.u32 + 512, ctx.r7.u8);
	// stw r9,520(r11)
	PPC_STORE_U32(ctx.r11.u32 + 520, ctx.r9.u32);
	// stw r8,528(r11)
	PPC_STORE_U32(ctx.r11.u32 + 528, ctx.r8.u32);
	// stb r10,536(r11)
	PPC_STORE_U8(ctx.r11.u32 + 536, ctx.r10.u8);
	// lbz r3,68(r5)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + 68);
	// stw r3,544(r11)
	PPC_STORE_U32(ctx.r11.u32 + 544, ctx.r3.u32);
	// stw r4,552(r11)
	PPC_STORE_U32(ctx.r11.u32 + 552, ctx.r4.u32);
	// stb r10,560(r11)
	PPC_STORE_U8(ctx.r11.u32 + 560, ctx.r10.u8);
	// lbz r9,69(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 69);
	// stw r9,568(r11)
	PPC_STORE_U32(ctx.r11.u32 + 568, ctx.r9.u32);
	// stw r31,576(r11)
	PPC_STORE_U32(ctx.r11.u32 + 576, ctx.r31.u32);
	// stb r10,584(r11)
	PPC_STORE_U8(ctx.r11.u32 + 584, ctx.r10.u8);
	// lbz r8,70(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 70);
	// stw r8,592(r11)
	PPC_STORE_U32(ctx.r11.u32 + 592, ctx.r8.u32);
	// stw r30,600(r11)
	PPC_STORE_U32(ctx.r11.u32 + 600, ctx.r30.u32);
	// stb r10,608(r11)
	PPC_STORE_U8(ctx.r11.u32 + 608, ctx.r10.u8);
	// lbz r7,71(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + 71);
	// stw r7,616(r11)
	PPC_STORE_U32(ctx.r11.u32 + 616, ctx.r7.u32);
	// stw r29,624(r11)
	PPC_STORE_U32(ctx.r11.u32 + 624, ctx.r29.u32);
	// stb r10,632(r11)
	PPC_STORE_U8(ctx.r11.u32 + 632, ctx.r10.u8);
	// lbz r6,72(r5)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r5.u32 + 72);
	// stw r6,640(r11)
	PPC_STORE_U32(ctx.r11.u32 + 640, ctx.r6.u32);
	// stw r28,648(r11)
	PPC_STORE_U32(ctx.r11.u32 + 648, ctx.r28.u32);
	// stb r10,656(r11)
	PPC_STORE_U8(ctx.r11.u32 + 656, ctx.r10.u8);
	// lwz r5,76(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// stw r5,664(r11)
	PPC_STORE_U32(ctx.r11.u32 + 664, ctx.r5.u32);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218D36C"))) PPC_WEAK_FUNC(sub_8218D36C);
PPC_FUNC_IMPL(__imp__sub_8218D36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D370"))) PPC_WEAK_FUNC(sub_8218D370);
PPC_FUNC_IMPL(__imp__sub_8218D370) {
	PPC_FUNC_PROLOGUE();
	// lwz r9,372(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r10,376
	ctx.r10.s64 = ctx.r10.s64 + 376;
loc_8218D38C:
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r4,r8
	ctx.cr6.compare<uint64_t>(ctx.r4.u64, ctx.r8.u64, ctx.xer);
	// beq cr6,0x8218d3ac
	if (ctx.cr6.eq) goto loc_8218D3AC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8218d38c
	if (ctx.cr6.lt) goto loc_8218D38C;
	// blr 
	return;
loc_8218D3AC:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218D3B4"))) PPC_WEAK_FUNC(sub_8218D3B4);
PPC_FUNC_IMPL(__imp__sub_8218D3B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D3B8"))) PPC_WEAK_FUNC(sub_8218D3B8);
PPC_FUNC_IMPL(__imp__sub_8218D3B8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218D3BC"))) PPC_WEAK_FUNC(sub_8218D3BC);
PPC_FUNC_IMPL(__imp__sub_8218D3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D3C0"))) PPC_WEAK_FUNC(sub_8218D3C0);
PPC_FUNC_IMPL(__imp__sub_8218D3C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218D3CC"))) PPC_WEAK_FUNC(sub_8218D3CC);
PPC_FUNC_IMPL(__imp__sub_8218D3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D3D0"))) PPC_WEAK_FUNC(sub_8218D3D0);
PPC_FUNC_IMPL(__imp__sub_8218D3D0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218D3DC"))) PPC_WEAK_FUNC(sub_8218D3DC);
PPC_FUNC_IMPL(__imp__sub_8218D3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D3E0"))) PPC_WEAK_FUNC(sub_8218D3E0);
PPC_FUNC_IMPL(__imp__sub_8218D3E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218D3EC"))) PPC_WEAK_FUNC(sub_8218D3EC);
PPC_FUNC_IMPL(__imp__sub_8218D3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D3F0"))) PPC_WEAK_FUNC(sub_8218D3F0);
PPC_FUNC_IMPL(__imp__sub_8218D3F0) {
	PPC_FUNC_PROLOGUE();
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// li r11,8
	ctx.r11.s64 = 8;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// sth r10,8(r4)
	PPC_STORE_U16(ctx.r4.u32 + 8, ctx.r10.u16);
	// li r7,4
	ctx.r7.s64 = 4;
	// sth r9,10(r4)
	PPC_STORE_U16(ctx.r4.u32 + 10, ctx.r9.u16);
	// li r6,5
	ctx.r6.s64 = 5;
	// sth r8,12(r4)
	PPC_STORE_U16(ctx.r4.u32 + 12, ctx.r8.u16);
	// li r5,6
	ctx.r5.s64 = 6;
	// sth r7,14(r4)
	PPC_STORE_U16(ctx.r4.u32 + 14, ctx.r7.u16);
	// li r3,7
	ctx.r3.s64 = 7;
	// sth r6,16(r4)
	PPC_STORE_U16(ctx.r4.u32 + 16, ctx.r6.u16);
	// sth r5,18(r4)
	PPC_STORE_U16(ctx.r4.u32 + 18, ctx.r5.u16);
	// sth r3,20(r4)
	PPC_STORE_U16(ctx.r4.u32 + 20, ctx.r3.u16);
	// sth r11,22(r4)
	PPC_STORE_U16(ctx.r4.u32 + 22, ctx.r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218D43C"))) PPC_WEAK_FUNC(sub_8218D43C);
PPC_FUNC_IMPL(__imp__sub_8218D43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D440"))) PPC_WEAK_FUNC(sub_8218D440);
PPC_FUNC_IMPL(__imp__sub_8218D440) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,100
	ctx.r11.s64 = 100;
	// li r10,101
	ctx.r10.s64 = 101;
	// li r9,102
	ctx.r9.s64 = 102;
	// stw r11,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r11.u32);
	// li r8,103
	ctx.r8.s64 = 103;
	// stw r10,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r10.u32);
	// stw r9,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r9.u32);
	// li r7,104
	ctx.r7.s64 = 104;
	// stw r8,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r8.u32);
	// li r6,110
	ctx.r6.s64 = 110;
	// li r11,111
	ctx.r11.s64 = 111;
	// stw r7,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r7.u32);
	// li r10,112
	ctx.r10.s64 = 112;
	// stw r6,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r6.u32);
	// li r9,113
	ctx.r9.s64 = 113;
	// stw r11,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r11.u32);
	// li r8,114
	ctx.r8.s64 = 114;
	// stw r10,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r10.u32);
	// stw r9,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r9.u32);
	// li r7,120
	ctx.r7.s64 = 120;
	// stw r8,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r8.u32);
	// li r6,121
	ctx.r6.s64 = 121;
	// li r11,122
	ctx.r11.s64 = 122;
	// stw r7,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, ctx.r7.u32);
	// li r10,123
	ctx.r10.s64 = 123;
	// stw r6,644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 644, ctx.r6.u32);
	// li r9,124
	ctx.r9.s64 = 124;
	// stw r11,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, ctx.r11.u32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stw r10,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, ctx.r10.u32);
	// stw r9,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r9.u32);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r6,r1,640
	ctx.r6.s64 = ctx.r1.s64 + 640;
	// li r11,200
	ctx.r11.s64 = 200;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// li r10,201
	ctx.r10.s64 = 201;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// li r9,202
	ctx.r9.s64 = 202;
	// stw r11,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r11.u32);
	// li r8,203
	ctx.r8.s64 = 203;
	// stw r10,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r10.u32);
	// stw r9,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r9.u32);
	// li r7,204
	ctx.r7.s64 = 204;
	// stw r8,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r8.u32);
	// li r6,210
	ctx.r6.s64 = 210;
	// li r11,211
	ctx.r11.s64 = 211;
	// stw r7,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r7.u32);
	// li r10,212
	ctx.r10.s64 = 212;
	// stw r6,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r6.u32);
	// li r9,213
	ctx.r9.s64 = 213;
	// stw r11,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r11.u32);
	// li r8,214
	ctx.r8.s64 = 214;
	// stw r10,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r10.u32);
	// li r7,220
	ctx.r7.s64 = 220;
	// stw r9,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r9.u32);
	// stw r8,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r8.u32);
	// li r6,221
	ctx.r6.s64 = 221;
	// li r11,222
	ctx.r11.s64 = 222;
	// stw r7,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r7.u32);
	// li r10,223
	ctx.r10.s64 = 223;
	// stw r6,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r6.u32);
	// li r9,224
	ctx.r9.s64 = 224;
	// stw r11,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r11.u32);
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// stw r10,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r10.u32);
	// addi r7,r1,576
	ctx.r7.s64 = ctx.r1.s64 + 576;
	// stw r9,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, ctx.r9.u32);
	// stw r8,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r8.u32);
	// addi r6,r1,448
	ctx.r6.s64 = ctx.r1.s64 + 448;
	// li r11,300
	ctx.r11.s64 = 300;
	// stw r7,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r7.u32);
	// li r10,310
	ctx.r10.s64 = 310;
	// stw r6,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r6.u32);
	// li r9,320
	ctx.r9.s64 = 320;
	// stw r11,20(r1)
	PPC_STORE_U32(ctx.r1.u32 + 20, ctx.r11.u32);
	// addi r8,r1,20
	ctx.r8.s64 = ctx.r1.s64 + 20;
	// stw r10,16(r1)
	PPC_STORE_U32(ctx.r1.u32 + 16, ctx.r10.u32);
	// stw r9,24(r1)
	PPC_STORE_U32(ctx.r1.u32 + 24, ctx.r9.u32);
	// addi r7,r1,16
	ctx.r7.s64 = ctx.r1.s64 + 16;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// addi r6,r1,24
	ctx.r6.s64 = ctx.r1.s64 + 24;
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
	// li r11,400
	ctx.r11.s64 = 400;
	// li r10,401
	ctx.r10.s64 = 401;
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// li r9,402
	ctx.r9.s64 = 402;
	// stw r11,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r11.u32);
	// stw r10,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, ctx.r10.u32);
	// li r8,403
	ctx.r8.s64 = 403;
	// stw r9,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r9.u32);
	// li r7,404
	ctx.r7.s64 = 404;
	// li r6,410
	ctx.r6.s64 = 410;
	// stw r8,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r8.u32);
	// li r11,411
	ctx.r11.s64 = 411;
	// stw r7,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r7.u32);
	// li r10,412
	ctx.r10.s64 = 412;
	// stw r6,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r6.u32);
	// li r9,413
	ctx.r9.s64 = 413;
	// stw r11,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r11.u32);
	// stw r10,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r10.u32);
	// li r8,414
	ctx.r8.s64 = 414;
	// stw r9,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r9.u32);
	// li r7,420
	ctx.r7.s64 = 420;
	// li r6,421
	ctx.r6.s64 = 421;
	// stw r8,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r8.u32);
	// li r11,422
	ctx.r11.s64 = 422;
	// stw r7,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r7.u32);
	// li r10,423
	ctx.r10.s64 = 423;
	// stw r6,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r6.u32);
	// li r9,424
	ctx.r9.s64 = 424;
	// stw r11,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r11.u32);
	// stw r10,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r10.u32);
	// addi r8,r1,704
	ctx.r8.s64 = ctx.r1.s64 + 704;
	// stw r9,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r9.u32);
	// addi r7,r1,512
	ctx.r7.s64 = ctx.r1.s64 + 512;
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// stw r8,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r8.u32);
	// li r11,500
	ctx.r11.s64 = 500;
	// stw r7,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r7.u32);
	// li r10,501
	ctx.r10.s64 = 501;
	// stw r6,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r6.u32);
	// li r9,502
	ctx.r9.s64 = 502;
	// stw r11,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r11.u32);
	// stw r10,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r10.u32);
	// li r8,510
	ctx.r8.s64 = 510;
	// stw r9,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r9.u32);
	// li r7,511
	ctx.r7.s64 = 511;
	// li r6,512
	ctx.r6.s64 = 512;
	// stw r8,64(r1)
	PPC_STORE_U32(ctx.r1.u32 + 64, ctx.r8.u32);
	// li r11,520
	ctx.r11.s64 = 520;
	// stw r7,68(r1)
	PPC_STORE_U32(ctx.r1.u32 + 68, ctx.r7.u32);
	// li r10,521
	ctx.r10.s64 = 521;
	// stw r6,72(r1)
	PPC_STORE_U32(ctx.r1.u32 + 72, ctx.r6.u32);
	// li r9,522
	ctx.r9.s64 = 522;
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// stw r10,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// stw r9,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r9.u32);
	// addi r7,r1,64
	ctx.r7.s64 = ctx.r1.s64 + 64;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stw r8,48(r1)
	PPC_STORE_U32(ctx.r1.u32 + 48, ctx.r8.u32);
	// li r11,600
	ctx.r11.s64 = 600;
	// stw r7,52(r1)
	PPC_STORE_U32(ctx.r1.u32 + 52, ctx.r7.u32);
	// li r10,601
	ctx.r10.s64 = 601;
	// stw r6,56(r1)
	PPC_STORE_U32(ctx.r1.u32 + 56, ctx.r6.u32);
	// li r9,602
	ctx.r9.s64 = 602;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r8,610
	ctx.r8.s64 = 610;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// li r7,611
	ctx.r7.s64 = 611;
	// li r6,612
	ctx.r6.s64 = 612;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// li r11,620
	ctx.r11.s64 = 620;
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// li r10,621
	ctx.r10.s64 = 621;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// li r9,622
	ctx.r9.s64 = 622;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// stw r9,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r8,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, ctx.r8.u32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stw r7,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, ctx.r7.u32);
	// stw r6,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r6.u32);
	// addi r10,r1,48
	ctx.r10.s64 = ctx.r1.s64 + 48;
	// stw r11,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r11.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stw r10,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r10.u32);
	// addi r7,r1,32
	ctx.r7.s64 = ctx.r1.s64 + 32;
	// stw r9,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r9.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r8,760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 760, ctx.r8.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r7,764(r1)
	PPC_STORE_U32(ctx.r1.u32 + 764, ctx.r7.u32);
	// stw r6,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r6.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stw r11,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r11.u32);
	// li r9,700
	ctx.r9.s64 = 700;
	// li r8,701
	ctx.r8.s64 = 701;
	// stw r10,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r10.u32);
	// li r7,702
	ctx.r7.s64 = 702;
	// stw r9,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r9.u32);
	// li r6,703
	ctx.r6.s64 = 703;
	// stw r8,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r8.u32);
	// li r11,704
	ctx.r11.s64 = 704;
	// stw r7,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r7.u32);
	// stw r6,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r6.u32);
	// li r10,710
	ctx.r10.s64 = 710;
	// stw r11,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r11.u32);
	// li r9,711
	ctx.r9.s64 = 711;
	// li r8,712
	ctx.r8.s64 = 712;
	// stw r10,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r10.u32);
	// li r7,713
	ctx.r7.s64 = 713;
	// stw r9,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r9.u32);
	// li r6,714
	ctx.r6.s64 = 714;
	// stw r8,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r8.u32);
	// li r11,720
	ctx.r11.s64 = 720;
	// stw r7,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r7.u32);
	// stw r6,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r6.u32);
	// li r10,721
	ctx.r10.s64 = 721;
	// stw r11,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r11.u32);
	// li r9,722
	ctx.r9.s64 = 722;
	// li r8,723
	ctx.r8.s64 = 723;
	// stw r10,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r10.u32);
	// li r7,724
	ctx.r7.s64 = 724;
	// stw r9,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r9.u32);
	// addi r6,r1,352
	ctx.r6.s64 = ctx.r1.s64 + 352;
	// stw r8,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r8.u32);
	// addi r11,r1,416
	ctx.r11.s64 = ctx.r1.s64 + 416;
	// stw r7,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r7.u32);
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// stw r6,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r6.u32);
	// stw r11,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r11.u32);
	// li r9,800
	ctx.r9.s64 = 800;
	// li r8,801
	ctx.r8.s64 = 801;
	// stw r10,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r10.u32);
	// li r7,802
	ctx.r7.s64 = 802;
	// stw r9,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r9.u32);
	// li r6,803
	ctx.r6.s64 = 803;
	// stw r8,548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 548, ctx.r8.u32);
	// li r11,804
	ctx.r11.s64 = 804;
	// stw r7,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r7.u32);
	// li r10,810
	ctx.r10.s64 = 810;
	// stw r6,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r6.u32);
	// stw r11,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r11.u32);
	// li r9,811
	ctx.r9.s64 = 811;
	// li r8,812
	ctx.r8.s64 = 812;
	// stw r10,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r10.u32);
	// li r7,813
	ctx.r7.s64 = 813;
	// stw r9,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r9.u32);
	// li r6,814
	ctx.r6.s64 = 814;
	// stw r8,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r8.u32);
	// li r11,820
	ctx.r11.s64 = 820;
	// stw r7,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r7.u32);
	// stw r6,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r6.u32);
	// li r10,821
	ctx.r10.s64 = 821;
	// stw r11,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, ctx.r11.u32);
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, ctx.r10.u32);
	// addi r8,r1,736
	ctx.r8.s64 = ctx.r1.s64 + 736;
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,822
	ctx.r6.s64 = 822;
	// li r3,824
	ctx.r3.s64 = 824;
	// li r4,823
	ctx.r4.s64 = 823;
	// stw r6,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, ctx.r6.u32);
	// lwzx r11,r9,r8
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r10,r1,544
	ctx.r10.s64 = ctx.r1.s64 + 544;
	// addi r9,r1,608
	ctx.r9.s64 = ctx.r1.s64 + 608;
	// stw r4,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r4.u32);
	// addi r8,r1,672
	ctx.r8.s64 = ctx.r1.s64 + 672;
	// stw r3,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r3.u32);
	// stw r10,32(r1)
	PPC_STORE_U32(ctx.r1.u32 + 32, ctx.r10.u32);
	// rlwinm r6,r5,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r9.u32);
	// stw r8,40(r1)
	PPC_STORE_U32(ctx.r1.u32 + 40, ctx.r8.u32);
	// lwzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218D868"))) PPC_WEAK_FUNC(sub_8218D868);
PPC_FUNC_IMPL(__imp__sub_8218D868) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	// rlwinm r10,r4,1,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x2;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218D87C"))) PPC_WEAK_FUNC(sub_8218D87C);
PPC_FUNC_IMPL(__imp__sub_8218D87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D880"))) PPC_WEAK_FUNC(sub_8218D880);
PPC_FUNC_IMPL(__imp__sub_8218D880) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8218D88C"))) PPC_WEAK_FUNC(sub_8218D88C);
PPC_FUNC_IMPL(__imp__sub_8218D88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218D890"))) PPC_WEAK_FUNC(sub_8218D890);
PPC_FUNC_IMPL(__imp__sub_8218D890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218D898;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x8218da4c
	if (ctx.cr6.gt) goto loc_8218DA4C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8218d934
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8218D934;
	// bdzf 4*cr6+eq,0x8218d93c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8218D93C;
	// bdzf 4*cr6+eq,0x8218d97c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8218D97C;
	// bdzf 4*cr6+eq,0x8218da44
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8218DA44;
	// bne cr6,0x8218da44
	if (!ctx.cr6.eq) goto loc_8218DA44;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r3,40(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// bge cr6,0x8218d924
	if (!ctx.cr6.lt) goto loc_8218D924;
	// addi r30,r31,40
	ctx.r30.s64 = ctx.r31.s64 + 40;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r7,r31,48
	ctx.r7.s64 = ctx.r31.s64 + 48;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// bl 0x82158278
	ctx.lr = 0x8218D900;
	sub_82158278(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8218d924
	if (!ctx.cr6.eq) goto loc_8218D924;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a030
	ctx.lr = 0x8218D910;
	sub_8207A030(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218D924:
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218D934:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_8218D93C:
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r7,r31,52
	ctx.r7.s64 = ctx.r31.s64 + 52;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8218D950:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218d950
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218D950;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x82089a18
	ctx.lr = 0x8218D96C;
	sub_82089A18(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218D97C:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// bl 0x82089490
	ctx.lr = 0x8218D98C;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,996
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 996, ctx.xer);
	// bgt cr6,0x8218da2c
	if (ctx.cr6.gt) goto loc_8218DA2C;
	// beq cr6,0x8218da4c
	if (ctx.cr6.eq) goto loc_8218DA4C;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218d9a8
	if (ctx.cr6.eq) goto loc_8218D9A8;
	// cmplwi cr6,r3,18
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 18, ctx.xer);
	// b 0x8218da30
	goto loc_8218DA30;
loc_8218D9A8:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218da34
	if (ctx.cr6.eq) goto loc_8218DA34;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8218D9BC:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// li r5,196
	ctx.r5.s64 = 196;
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r4,r30,r11
	ctx.r4.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mulli r11,r8,196
	ctx.r11.s64 = ctx.r8.s64 * 196;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8218D9E0;
	sub_8207DAC0(ctx, base);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,196
	ctx.r30.s64 = ctx.r30.s64 + 196;
	// lwz r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r29,r5
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8218d9bc
	if (ctx.cr6.lt) goto loc_8218D9BC;
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// subfc r8,r10,r9
	ctx.xer.ca = ctx.r9.u32 >= ctx.r10.u32;
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r7,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// stw r6,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218DA2C:
	// cmplwi cr6,r3,1627
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1627, ctx.xer);
loc_8218DA30:
	// bne cr6,0x8218d924
	if (!ctx.cr6.eq) goto loc_8218D924;
loc_8218DA34:
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218DA44:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8218DA4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218DA54"))) PPC_WEAK_FUNC(sub_8218DA54);
PPC_FUNC_IMPL(__imp__sub_8218DA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218DA58"))) PPC_WEAK_FUNC(sub_8218DA58);
PPC_FUNC_IMPL(__imp__sub_8218DA58) {
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
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// addi r9,r11,4328
	ctx.r9.s64 = ctx.r11.s64 + 4328;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// bne cr6,0x8218da8c
	if (!ctx.cr6.eq) goto loc_8218DA8C;
	// bl 0x82089e18
	ctx.lr = 0x8218DA8C;
	sub_82089E18(ctx, base);
loc_8218DA8C:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218da9c
	if (ctx.cr6.eq) goto loc_8218DA9C;
	// bl 0x8207a8a0
	ctx.lr = 0x8218DA9C;
	sub_8207A8A0(ctx, base);
loc_8218DA9C:
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

__attribute__((alias("__imp__sub_8218DABC"))) PPC_WEAK_FUNC(sub_8218DABC);
PPC_FUNC_IMPL(__imp__sub_8218DABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218DAC0"))) PPC_WEAK_FUNC(sub_8218DAC0);
PPC_FUNC_IMPL(__imp__sub_8218DAC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r5,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r5.u32);
	// addi r9,r10,4328
	ctx.r9.s64 = ctx.r10.s64 + 4328;
	// li r8,100
	ctx.r8.s64 = 100;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// beq cr6,0x8218db0c
	if (ctx.cr6.eq) goto loc_8218DB0C;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
loc_8218DB0C:
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8218DB18:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8218db18
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218DB18;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218DB24"))) PPC_WEAK_FUNC(sub_8218DB24);
PPC_FUNC_IMPL(__imp__sub_8218DB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218DB28"))) PPC_WEAK_FUNC(sub_8218DB28);
PPC_FUNC_IMPL(__imp__sub_8218DB28) {
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
	ctx.lr = 0x8218DB48;
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

__attribute__((alias("__imp__sub_8218DB78"))) PPC_WEAK_FUNC(sub_8218DB78);
PPC_FUNC_IMPL(__imp__sub_8218DB78) {
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
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218dba0
	if (ctx.cr6.eq) goto loc_8218DBA0;
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218DBA0:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218DBB0;
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

__attribute__((alias("__imp__sub_8218DBE0"))) PPC_WEAK_FUNC(sub_8218DBE0);
PPC_FUNC_IMPL(__imp__sub_8218DBE0) {
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
	// lwz r11,92(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218dc08
	if (ctx.cr6.eq) goto loc_8218DC08;
	// lwz r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218DC08:
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x8218DC18;
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

__attribute__((alias("__imp__sub_8218DC48"))) PPC_WEAK_FUNC(sub_8218DC48);
PPC_FUNC_IMPL(__imp__sub_8218DC48) {
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
	ctx.lr = 0x8218DC68;
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

__attribute__((alias("__imp__sub_8218DC98"))) PPC_WEAK_FUNC(sub_8218DC98);
PPC_FUNC_IMPL(__imp__sub_8218DC98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218DCA0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218dcfc
	if (ctx.cr6.eq) goto loc_8218DCFC;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218dcfc
	if (!ctx.cr6.eq) goto loc_8218DCFC;
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218dce0
	if (ctx.cr6.eq) goto loc_8218DCE0;
	// bl 0x8207a8a0
	ctx.lr = 0x8218DCDC;
	sub_8207A8A0(ctx, base);
	// stw r30,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
loc_8218DCE0:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218dcf4
	if (ctx.cr6.eq) goto loc_8218DCF4;
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
loc_8218DCF4:
	// addi r3,r31,132
	ctx.r3.s64 = ctx.r31.s64 + 132;
	// bl 0x82089e18
	ctx.lr = 0x8218DCFC;
	sub_82089E18(ctx, base);
loc_8218DCFC:
	// lwz r11,132(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 132);
	// addi r3,r31,132
	ctx.r3.s64 = ctx.r31.s64 + 132;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8218dd90
	if (ctx.cr6.eq) goto loc_8218DD90;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82089490
	ctx.lr = 0x8218DD18;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218dd38
	if (ctx.cr6.eq) goto loc_8218DD38;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218dd34
	if (ctx.cr6.eq) goto loc_8218DD34;
	// bl 0x8207a8a0
	ctx.lr = 0x8218DD30;
	sub_8207A8A0(ctx, base);
	// stw r30,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
loc_8218DD34:
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
loc_8218DD38:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218dd84
	if (ctx.cr6.eq) goto loc_8218DD84;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218dd84
	if (ctx.cr6.eq) goto loc_8218DD84;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218dd64
	if (ctx.cr6.eq) goto loc_8218DD64;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218DD64:
	// lwz r11,124(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8218dd84
	if (ctx.cr6.gt) goto loc_8218DD84;
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
loc_8218DD84:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-9144
	ctx.r10.s64 = ctx.r11.s64 + -9144;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8218DD90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218DD98"))) PPC_WEAK_FUNC(sub_8218DD98);
PPC_FUNC_IMPL(__imp__sub_8218DD98) {
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
	ctx.lr = 0x8218DDB8;
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

__attribute__((alias("__imp__sub_8218DDE8"))) PPC_WEAK_FUNC(sub_8218DDE8);
PPC_FUNC_IMPL(__imp__sub_8218DDE8) {
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
	ctx.lr = 0x8218DE08;
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

__attribute__((alias("__imp__sub_8218DE38"))) PPC_WEAK_FUNC(sub_8218DE38);
PPC_FUNC_IMPL(__imp__sub_8218DE38) {
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
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218de7c
	if (ctx.cr6.eq) goto loc_8218DE7C;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218de7c
	if (!ctx.cr6.eq) goto loc_8218DE7C;
	// stw r30,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// addi r3,r3,84
	ctx.r3.s64 = ctx.r3.s64 + 84;
	// bl 0x82089e18
	ctx.lr = 0x8218DE78;
	sub_82089E18(ctx, base);
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
loc_8218DE7C:
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r3,r31,84
	ctx.r3.s64 = ctx.r31.s64 + 84;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8218dec4
	if (ctx.cr6.eq) goto loc_8218DEC4;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82089490
	ctx.lr = 0x8218DE98;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218dea4
	if (ctx.cr6.eq) goto loc_8218DEA4;
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
loc_8218DEA4:
	// lwz r11,1184(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1184);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218deb8
	if (ctx.cr6.eq) goto loc_8218DEB8;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218DEB8:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-9432
	ctx.r10.s64 = ctx.r11.s64 + -9432;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8218DEC4:
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

__attribute__((alias("__imp__sub_8218DEDC"))) PPC_WEAK_FUNC(sub_8218DEDC);
PPC_FUNC_IMPL(__imp__sub_8218DEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218DEE0"))) PPC_WEAK_FUNC(sub_8218DEE0);
PPC_FUNC_IMPL(__imp__sub_8218DEE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218DEE8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r11,4312
	ctx.r9.s64 = ctx.r11.s64 + 4312;
	// addi r7,r3,84
	ctx.r7.s64 = ctx.r3.s64 + 84;
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8218df28
	if (!ctx.cr6.eq) goto loc_8218DF28;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218df20
	if (ctx.cr6.eq) goto loc_8218DF20;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218DF20;
	sub_821BD1B8(ctx, base);
loc_8218DF20:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82089e18
	ctx.lr = 0x8218DF28;
	sub_82089E18(ctx, base);
loc_8218DF28:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218DF3C;
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
	ctx.lr = 0x8218DF54;
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

__attribute__((alias("__imp__sub_8218DF64"))) PPC_WEAK_FUNC(sub_8218DF64);
PPC_FUNC_IMPL(__imp__sub_8218DF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218DF68"))) PPC_WEAK_FUNC(sub_8218DF68);
PPC_FUNC_IMPL(__imp__sub_8218DF68) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-9352
	ctx.r10.s64 = ctx.r11.s64 + -9352;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218DF78"))) PPC_WEAK_FUNC(sub_8218DF78);
PPC_FUNC_IMPL(__imp__sub_8218DF78) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// addi r10,r11,-8344
	ctx.r10.s64 = ctx.r11.s64 + -8344;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218DF8C"))) PPC_WEAK_FUNC(sub_8218DF8C);
PPC_FUNC_IMPL(__imp__sub_8218DF8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218DF90"))) PPC_WEAK_FUNC(sub_8218DF90);
PPC_FUNC_IMPL(__imp__sub_8218DF90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218DF98;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r11,4296
	ctx.r9.s64 = ctx.r11.s64 + 4296;
	// addi r7,r3,92
	ctx.r7.s64 = ctx.r3.s64 + 92;
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8218dfd8
	if (!ctx.cr6.eq) goto loc_8218DFD8;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218dfd0
	if (ctx.cr6.eq) goto loc_8218DFD0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218DFD0;
	sub_821BD1B8(ctx, base);
loc_8218DFD0:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82089e18
	ctx.lr = 0x8218DFD8;
	sub_82089E18(ctx, base);
loc_8218DFD8:
	// lwz r3,1152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218dff0
	if (ctx.cr6.eq) goto loc_8218DFF0;
	// bl 0x8207a8a0
	ctx.lr = 0x8218DFE8;
	sub_8207A8A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,1152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1152, ctx.r11.u32);
loc_8218DFF0:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218E004;
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
	ctx.lr = 0x8218E01C;
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

__attribute__((alias("__imp__sub_8218E02C"))) PPC_WEAK_FUNC(sub_8218E02C);
PPC_FUNC_IMPL(__imp__sub_8218E02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E030"))) PPC_WEAK_FUNC(sub_8218E030);
PPC_FUNC_IMPL(__imp__sub_8218E030) {
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
	// lwz r3,368(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// bl 0x82088d00
	ctx.lr = 0x8218E04C;
	sub_82088D00(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-9248
	ctx.r8.s64 = ctx.r11.s64 + -9248;
	// stw r10,368(r31)
	PPC_STORE_U32(ctx.r31.u32 + 368, ctx.r10.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r9.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8218E07C"))) PPC_WEAK_FUNC(sub_8218E07C);
PPC_FUNC_IMPL(__imp__sub_8218E07C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E080"))) PPC_WEAK_FUNC(sub_8218E080);
PPC_FUNC_IMPL(__imp__sub_8218E080) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,96(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8218e094
	if (ctx.cr6.eq) goto loc_8218E094;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
loc_8218E094:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-9248
	ctx.r10.s64 = ctx.r11.s64 + -9248;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218E0A4"))) PPC_WEAK_FUNC(sub_8218E0A4);
PPC_FUNC_IMPL(__imp__sub_8218E0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E0A8"))) PPC_WEAK_FUNC(sub_8218E0A8);
PPC_FUNC_IMPL(__imp__sub_8218E0A8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218E0C0"))) PPC_WEAK_FUNC(sub_8218E0C0);
PPC_FUNC_IMPL(__imp__sub_8218E0C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218E0C8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r3,272
	ctx.r3.s64 = ctx.r3.s64 + 272;
	// addi r9,r11,4280
	ctx.r9.s64 = ctx.r11.s64 + 4280;
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,272(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 272);
	// stw r9,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// bne cr6,0x8218e10c
	if (!ctx.cr6.eq) goto loc_8218E10C;
	// bl 0x82089e18
	ctx.lr = 0x8218E0F4;
	sub_82089E18(ctx, base);
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e10c
	if (ctx.cr6.eq) goto loc_8218E10C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218E108;
	sub_821BD1B8(ctx, base);
	// stw r28,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r28.u32);
loc_8218E10C:
	// addi r11,r30,272
	ctx.r11.s64 = ctx.r30.s64 + 272;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r31,r11,16
	ctx.r31.s64 = ctx.r11.s64 + 16;
	// li r27,15
	ctx.r27.s64 = 15;
loc_8218E11C:
	// addi r31,r31,-80
	ctx.r31.s64 = ctx.r31.s64 + -80;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8218e134
	if (ctx.cr6.lt) goto loc_8218E134;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8218E134;
	sub_8207A630(ctx, base);
loc_8218E134:
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// bge 0x8218e11c
	if (!ctx.cr0.lt) goto loc_8218E11C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r30,44
	ctx.r3.s64 = ctx.r30.s64 + 44;
	// addi r31,r11,-1408
	ctx.r31.s64 = ctx.r11.s64 + -1408;
	// stw r31,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r31.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218E15C;
	sub_82173A18(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r30,16
	ctx.r3.s64 = ctx.r30.s64 + 16;
	// addi r29,r10,-1456
	ctx.r29.s64 = ctx.r10.s64 + -1456;
	// stw r29,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r29.u32);
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218E174;
	sub_82173A18(ctx, base);
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218E184"))) PPC_WEAK_FUNC(sub_8218E184);
PPC_FUNC_IMPL(__imp__sub_8218E184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E188"))) PPC_WEAK_FUNC(sub_8218E188);
PPC_FUNC_IMPL(__imp__sub_8218E188) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218E190;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r11,4264
	ctx.r9.s64 = ctx.r11.s64 + 4264;
	// addi r7,r3,132
	ctx.r7.s64 = ctx.r3.s64 + 132;
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8218e1d0
	if (!ctx.cr6.eq) goto loc_8218E1D0;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e1c8
	if (ctx.cr6.eq) goto loc_8218E1C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218E1C8;
	sub_821BD1B8(ctx, base);
loc_8218E1C8:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82089e18
	ctx.lr = 0x8218E1D0;
	sub_82089E18(ctx, base);
loc_8218E1D0:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e1e8
	if (ctx.cr6.eq) goto loc_8218E1E8;
	// bl 0x8207a8a0
	ctx.lr = 0x8218E1E0;
	sub_8207A8A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
loc_8218E1E8:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218E1FC;
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
	ctx.lr = 0x8218E214;
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

__attribute__((alias("__imp__sub_8218E224"))) PPC_WEAK_FUNC(sub_8218E224);
PPC_FUNC_IMPL(__imp__sub_8218E224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E228"))) PPC_WEAK_FUNC(sub_8218E228);
PPC_FUNC_IMPL(__imp__sub_8218E228) {
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
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218e2b4
	if (ctx.cr6.eq) goto loc_8218E2B4;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218e2b4
	if (!ctx.cr6.eq) goto loc_8218E2B4;
	// lwz r3,140(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e274
	if (ctx.cr6.eq) goto loc_8218E274;
	// bl 0x8207a8a0
	ctx.lr = 0x8218E270;
	sub_8207A8A0(ctx, base);
	// stw r30,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
loc_8218E274:
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x82089e18
	ctx.lr = 0x8218E27C;
	sub_82089E18(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218e290
	if (ctx.cr6.eq) goto loc_8218E290;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218E290:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-8808
	ctx.r10.s64 = ctx.r11.s64 + -8808;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8218E29C:
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
loc_8218E2B4:
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8218e29c
	if (ctx.cr6.eq) goto loc_8218E29C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82089490
	ctx.lr = 0x8218E2D0;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e2f4
	if (ctx.cr6.eq) goto loc_8218E2F4;
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e290
	if (ctx.cr6.eq) goto loc_8218E290;
	// bl 0x8207a8a0
	ctx.lr = 0x8218E2E8;
	sub_8207A8A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// b 0x8218e290
	goto loc_8218E290;
loc_8218E2F4:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e308
	if (ctx.cr6.eq) goto loc_8218E308;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218E308;
	sub_821BD1B8(ctx, base);
loc_8218E308:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218e290
	if (ctx.cr6.eq) goto loc_8218E290;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r10,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// b 0x8218e29c
	goto loc_8218E29C;
}

__attribute__((alias("__imp__sub_8218E324"))) PPC_WEAK_FUNC(sub_8218E324);
PPC_FUNC_IMPL(__imp__sub_8218E324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E328"))) PPC_WEAK_FUNC(sub_8218E328);
PPC_FUNC_IMPL(__imp__sub_8218E328) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218E330;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r11,4248
	ctx.r9.s64 = ctx.r11.s64 + 4248;
	// addi r7,r3,112
	ctx.r7.s64 = ctx.r3.s64 + 112;
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8218e370
	if (!ctx.cr6.eq) goto loc_8218E370;
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e368
	if (ctx.cr6.eq) goto loc_8218E368;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218E368;
	sub_821BD1B8(ctx, base);
loc_8218E368:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82089e18
	ctx.lr = 0x8218E370;
	sub_82089E18(ctx, base);
loc_8218E370:
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e388
	if (ctx.cr6.eq) goto loc_8218E388;
	// bl 0x8207a8a0
	ctx.lr = 0x8218E380;
	sub_8207A8A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
loc_8218E388:
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8207a8a0
	ctx.lr = 0x8218E390;
	sub_8207A8A0(ctx, base);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// bl 0x8207a8a0
	ctx.lr = 0x8218E398;
	sub_8207A8A0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218E3AC;
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
	ctx.lr = 0x8218E3C4;
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

__attribute__((alias("__imp__sub_8218E3D4"))) PPC_WEAK_FUNC(sub_8218E3D4);
PPC_FUNC_IMPL(__imp__sub_8218E3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E3D8"))) PPC_WEAK_FUNC(sub_8218E3D8);
PPC_FUNC_IMPL(__imp__sub_8218E3D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-8728
	ctx.r10.s64 = ctx.r11.s64 + -8728;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218E3E8"))) PPC_WEAK_FUNC(sub_8218E3E8);
PPC_FUNC_IMPL(__imp__sub_8218E3E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218E3F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r9,r11,4232
	ctx.r9.s64 = ctx.r11.s64 + 4232;
	// addi r7,r3,112
	ctx.r7.s64 = ctx.r3.s64 + 112;
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8218e430
	if (!ctx.cr6.eq) goto loc_8218E430;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e428
	if (ctx.cr6.eq) goto loc_8218E428;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218E428;
	sub_821BD1B8(ctx, base);
loc_8218E428:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82089e18
	ctx.lr = 0x8218E430;
	sub_82089E18(ctx, base);
loc_8218E430:
	// lwz r3,276(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e448
	if (ctx.cr6.eq) goto loc_8218E448;
	// bl 0x8207a8a0
	ctx.lr = 0x8218E440;
	sub_8207A8A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
loc_8218E448:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x8218E45C;
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
	ctx.lr = 0x8218E474;
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

__attribute__((alias("__imp__sub_8218E484"))) PPC_WEAK_FUNC(sub_8218E484);
PPC_FUNC_IMPL(__imp__sub_8218E484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E488"))) PPC_WEAK_FUNC(sub_8218E488);
PPC_FUNC_IMPL(__imp__sub_8218E488) {
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
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218e4dc
	if (ctx.cr6.eq) goto loc_8218E4DC;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218e4dc
	if (!ctx.cr6.eq) goto loc_8218E4DC;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r3,r3,92
	ctx.r3.s64 = ctx.r3.s64 + 92;
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// bl 0x82089e18
	ctx.lr = 0x8218E4C8;
	sub_82089E18(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r30,1156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1156, ctx.r30.u32);
	// addi r9,r11,-8344
	ctx.r9.s64 = ctx.r11.s64 + -8344;
	// b 0x8218e534
	goto loc_8218E534;
loc_8218E4DC:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r3,r31,92
	ctx.r3.s64 = ctx.r31.s64 + 92;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8218e53c
	if (ctx.cr6.eq) goto loc_8218E53C;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82089490
	ctx.lr = 0x8218E4F8;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e520
	if (ctx.cr6.eq) goto loc_8218E520;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r8,r11,-8344
	ctx.r8.s64 = ctx.r11.s64 + -8344;
	// stw r10,1156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1156, ctx.r10.u32);
	// stw r9,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r9.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// b 0x8218e53c
	goto loc_8218E53C;
loc_8218E520:
	// lwz r3,1156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1156);
	// bl 0x8210e878
	ctx.lr = 0x8218E528;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-9352
	ctx.r9.s64 = ctx.r11.s64 + -9352;
loc_8218E534:
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_8218E53C:
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

__attribute__((alias("__imp__sub_8218E554"))) PPC_WEAK_FUNC(sub_8218E554);
PPC_FUNC_IMPL(__imp__sub_8218E554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E558"))) PPC_WEAK_FUNC(sub_8218E558);
PPC_FUNC_IMPL(__imp__sub_8218E558) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,15
	ctx.r11.s64 = 15;
	// addi r4,r4,24
	ctx.r4.s64 = ctx.r4.s64 + 24;
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stb r10,16(r31)
	PPC_STORE_U8(ctx.r31.u32 + 16, ctx.r10.u8);
	// ld r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
loc_8218E5A4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8218e5a4
	if (!ctx.cr6.eq) goto loc_8218E5A4;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8218E5C4;
	sub_82060368(ctx, base);
	// ld r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r30.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r10,40(r31)
	PPC_STORE_U64(ctx.r31.u32 + 40, ctx.r10.u64);
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// stw r7,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
	// lwz r6,44(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// stb r5,68(r31)
	PPC_STORE_U8(ctx.r31.u32 + 68, ctx.r5.u8);
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stb r10,69(r31)
	PPC_STORE_U8(ctx.r31.u32 + 69, ctx.r10.u8);
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r7,112(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	// stb r7,70(r31)
	PPC_STORE_U8(ctx.r31.u32 + 70, ctx.r7.u8);
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r4,136(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 136);
	// stb r4,71(r31)
	PPC_STORE_U8(ctx.r31.u32 + 71, ctx.r4.u8);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// stb r9,72(r31)
	PPC_STORE_U8(ctx.r31.u32 + 72, ctx.r9.u8);
	// lwz r7,44(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8218E640"))) PPC_WEAK_FUNC(sub_8218E640);
PPC_FUNC_IMPL(__imp__sub_8218E640) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218E648;
	__savegprlr_27(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,1160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1160);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r9,1024
	ctx.r9.s64 = 1024;
	// ld r3,1168(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 1168);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r28,r31,132
	ctx.r28.s64 = ctx.r31.s64 + 132;
	// addi r27,r11,25116
	ctx.r27.s64 = ctx.r11.s64 + 25116;
	// stw r9,1156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1156, ctx.r9.u32);
	// addi r9,r31,1156
	ctx.r9.s64 = ctx.r31.s64 + 1156;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r7,r27,-100
	ctx.r7.s64 = ctx.r27.s64 + -100;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82158bc0
	ctx.lr = 0x8218E68C;
	sub_82158BC0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e698
	if (ctx.cr6.eq) goto loc_8218E698;
	// bl 0x8210e878
	ctx.lr = 0x8218E698;
	sub_8210E878(ctx, base);
loc_8218E698:
	// li r10,7
	ctx.r10.s64 = 7;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,84
	ctx.r30.s64 = ctx.r31.s64 + 84;
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// addi r11,r30,-4
	ctx.r11.s64 = ctx.r30.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8218E6B0:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218e6b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218E6B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,1180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1180);
	// lwz r3,1176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1176);
	// bl 0x8207da20
	ctx.lr = 0x8218E6C8;
	sub_8207DA20(ctx, base);
	// std r29,112(r31)
	PPC_STORE_U64(ctx.r31.u32 + 112, ctx.r29.u64);
	// std r29,120(r31)
	PPC_STORE_U64(ctx.r31.u32 + 120, ctx.r29.u64);
	// stw r29,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r29.u32);
	// addi r8,r31,112
	ctx.r8.s64 = ctx.r31.s64 + 112;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// li r7,20
	ctx.r7.s64 = 20;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r6,1176(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1176);
	// lwz r5,1180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1180);
	// lwz r3,1188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1188);
	// bl 0x821583d8
	ctx.lr = 0x8218E6F4;
	sub_821583D8(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218e700
	if (ctx.cr6.eq) goto loc_8218E700;
	// bl 0x8210e878
	ctx.lr = 0x8218E700;
	sub_8210E878(ctx, base);
loc_8218E700:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218E708;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e764
	if (ctx.cr6.eq) goto loc_8218E764;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-24522
	ctx.r4.s64 = ctx.r11.s64 + -24522;
	// bl 0x82060190
	ctx.lr = 0x8218E724;
	sub_82060190(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060190
	ctx.lr = 0x8218E734;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218E744;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,80
	ctx.r6.s64 = ctx.r31.s64 + 80;
	// li r7,300
	ctx.r7.s64 = 300;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8218E760;
	sub_821BD670(ctx, base);
	// b 0x8218e768
	goto loc_8218E768;
loc_8218E764:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8218E768:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r8,r10,-8648
	ctx.r8.s64 = ctx.r10.s64 + -8648;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218E798"))) PPC_WEAK_FUNC(sub_8218E798);
PPC_FUNC_IMPL(__imp__sub_8218E798) {
	PPC_FUNC_PROLOGUE();
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
	// stw r8,1188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1188, ctx.r8.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// blt cr6,0x8218e7d4
	if (ctx.cr6.lt) goto loc_8218E7D4;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-9432
	ctx.r10.s64 = ctx.r11.s64 + -9432;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_8218E7D4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-6592
	ctx.r10.s64 = ctx.r11.s64 + -6592;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218E7E4"))) PPC_WEAK_FUNC(sub_8218E7E4);
PPC_FUNC_IMPL(__imp__sub_8218E7E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218E7E8"))) PPC_WEAK_FUNC(sub_8218E7E8);
PPC_FUNC_IMPL(__imp__sub_8218E7E8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-6248
	ctx.r10.s64 = ctx.r11.s64 + -6248;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218E7F8"))) PPC_WEAK_FUNC(sub_8218E7F8);
PPC_FUNC_IMPL(__imp__sub_8218E7F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218E800;
	__savegprlr_27(ctx, base);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lis r30,-32251
	ctx.r30.s64 = -2113601536;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r29,-32251
	ctx.r29.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r28,-32251
	ctx.r28.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// li r31,7
	ctx.r31.s64 = 7;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r27,r30,-1396
	ctx.r27.s64 = ctx.r30.s64 + -1396;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r9,r29,840
	ctx.r9.s64 = ctx.r29.s64 + 840;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r29,r28,4312
	ctx.r29.s64 = ctx.r28.s64 + 4312;
	// stw r27,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r27.u32);
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// stb r11,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r11.u8);
	// stb r11,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r11.u8);
	// stb r11,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r11.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stb r11,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r11.u8);
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// stb r30,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r30.u8);
	// stw r4,1160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1160, ctx.r4.u32);
	// std r5,1168(r3)
	PPC_STORE_U64(ctx.r3.u32 + 1168, ctx.r5.u64);
	// stw r6,1176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1176, ctx.r6.u32);
	// stw r7,1180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1180, ctx.r7.u32);
	// stw r8,1184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1184, ctx.r8.u32);
loc_8218E8A8:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8218e8a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218E8A8;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-6168
	ctx.r10.s64 = ctx.r11.s64 + -6168;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218E8C0"))) PPC_WEAK_FUNC(sub_8218E8C0);
PPC_FUNC_IMPL(__imp__sub_8218E8C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218E8C8;
	__savegprlr_28(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,1148(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1148);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r9,1024
	ctx.r9.s64 = 1024;
	// lwz r3,1160(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1160);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r30,r31,120
	ctx.r30.s64 = ctx.r31.s64 + 120;
	// addi r29,r11,24944
	ctx.r29.s64 = ctx.r11.s64 + 24944;
	// stw r9,1144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1144, ctx.r9.u32);
	// addi r9,r31,1144
	ctx.r9.s64 = ctx.r31.s64 + 1144;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r7,r29,-100
	ctx.r7.s64 = ctx.r29.s64 + -100;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82158b28
	ctx.lr = 0x8218E90C;
	sub_82158B28(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e934
	if (ctx.cr6.eq) goto loc_8218E934;
loc_8218E914:
	// bl 0x8210e878
	ctx.lr = 0x8218E918;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8344
	ctx.r9.s64 = ctx.r11.s64 + -8344;
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8218E934:
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r7,r31,92
	ctx.r7.s64 = ctx.r31.s64 + 92;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8218E948:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218e948
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218E948;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r6,1152(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1152);
	// lwz r5,1156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1156);
	// lwz r3,1160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1160);
	// bl 0x821586b8
	ctx.lr = 0x8218E964;
	sub_821586B8(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x8218e914
	if (!ctx.cr6.eq) goto loc_8218E914;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218E974;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218e9d0
	if (ctx.cr6.eq) goto loc_8218E9D0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-24537
	ctx.r4.s64 = ctx.r11.s64 + -24537;
	// bl 0x82060190
	ctx.lr = 0x8218E990;
	sub_82060190(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060190
	ctx.lr = 0x8218E9A0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218E9B0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,80
	ctx.r6.s64 = ctx.r31.s64 + 80;
	// li r7,300
	ctx.r7.s64 = 300;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8218E9CC;
	sub_821BD670(ctx, base);
	// b 0x8218e9d4
	goto loc_8218E9D4;
loc_8218E9D0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8218E9D4:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r7,r10,-7032
	ctx.r7.s64 = ctx.r10.s64 + -7032;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218EA08"))) PPC_WEAK_FUNC(sub_8218EA08);
PPC_FUNC_IMPL(__imp__sub_8218EA08) {
	PPC_FUNC_PROLOGUE();
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
	// stw r8,1160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1160, ctx.r8.u32);
	// lwz r7,76(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// blt cr6,0x8218ea4c
	if (ctx.cr6.lt) goto loc_8218EA4C;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-8344
	ctx.r9.s64 = ctx.r11.s64 + -8344;
	// stw r10,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
loc_8218EA4C:
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x8218ea74
	if (!ctx.cr6.lt) goto loc_8218EA74;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// beq cr6,0x8218ea8c
	if (ctx.cr6.eq) goto loc_8218EA8C;
loc_8218EA74:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,-8344
	ctx.r9.s64 = ctx.r11.s64 + -8344;
	// stw r10,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
loc_8218EA8C:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-5952
	ctx.r10.s64 = ctx.r11.s64 + -5952;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218EA9C"))) PPC_WEAK_FUNC(sub_8218EA9C);
PPC_FUNC_IMPL(__imp__sub_8218EA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218EAA0"))) PPC_WEAK_FUNC(sub_8218EAA0);
PPC_FUNC_IMPL(__imp__sub_8218EAA0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-5624
	ctx.r10.s64 = ctx.r11.s64 + -5624;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218EAB0"))) PPC_WEAK_FUNC(sub_8218EAB0);
PPC_FUNC_IMPL(__imp__sub_8218EAB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218EAB8;
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stb r30,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r30.u8);
	// addi r3,r9,-1396
	ctx.r3.s64 = ctx.r9.s64 + -1396;
	// stb r30,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r30.u8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stb r30,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r30.u8);
	// addi r10,r8,840
	ctx.r10.s64 = ctx.r8.s64 + 840;
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// addi r8,r5,4296
	ctx.r8.s64 = ctx.r5.s64 + 4296;
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// stw r10,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r10.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r6,1156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1156, ctx.r6.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// stw r30,1152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1152, ctx.r30.u32);
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// stb r9,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r9.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r7.u32);
	// stw r4,1148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1148, ctx.r4.u32);
	// bl 0x8207a030
	ctx.lr = 0x8218EB64;
	sub_8207A030(ctx, base);
	// stw r3,1152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1152, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r5,1156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1156);
	// bl 0x8207dac0
	ctx.lr = 0x8218EB74;
	sub_8207DAC0(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// addi r10,r31,88
	ctx.r10.s64 = ctx.r31.s64 + 88;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8218EB84:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8218eb84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218EB84;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r30,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-5472
	ctx.r10.s64 = ctx.r11.s64 + -5472;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218EBA8"))) PPC_WEAK_FUNC(sub_8218EBA8);
PPC_FUNC_IMPL(__imp__sub_8218EBA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218EBB0;
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
	ctx.lr = 0x8218EBC0;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ec20
	if (ctx.cr6.eq) goto loc_8218EC20;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24538
	ctx.r4.s64 = ctx.r11.s64 + -24538;
	// bl 0x82060190
	ctx.lr = 0x8218EBDC;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,24544
	ctx.r4.s64 = ctx.r10.s64 + 24544;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218EBF0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218EC00;
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
	ctx.lr = 0x8218EC1C;
	sub_821BD670(ctx, base);
	// b 0x8218ec24
	goto loc_8218EC24;
loc_8218EC20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8218EC24:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32231
	ctx.r8.s64 = -2112290816;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-9248
	ctx.r6.s64 = ctx.r8.s64 + -9248;
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

__attribute__((alias("__imp__sub_8218EC54"))) PPC_WEAK_FUNC(sub_8218EC54);
PPC_FUNC_IMPL(__imp__sub_8218EC54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218EC58"))) PPC_WEAK_FUNC(sub_8218EC58);
PPC_FUNC_IMPL(__imp__sub_8218EC58) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218EC60;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8218ed04
	if (!ctx.cr6.eq) goto loc_8218ED04;
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218EC80;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ece0
	if (ctx.cr6.eq) goto loc_8218ECE0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24545
	ctx.r4.s64 = ctx.r11.s64 + -24545;
	// bl 0x82060190
	ctx.lr = 0x8218EC9C;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,24524
	ctx.r4.s64 = ctx.r10.s64 + 24524;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218ECB0;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218ECC0;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,84
	ctx.r6.s64 = ctx.r31.s64 + 84;
	// li r7,120
	ctx.r7.s64 = 120;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8218ECDC;
	sub_821BD670(ctx, base);
	// b 0x8218ece4
	goto loc_8218ECE4;
loc_8218ECE0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8218ECE4:
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// b 0x8218ed2c
	goto loc_8218ED2C;
loc_8218ED04:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,72(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// bl 0x82190898
	ctx.lr = 0x8218ED18;
	sub_82190898(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8218edbc
	if (!ctx.cr6.eq) goto loc_8218EDBC;
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8218edbc
	if (ctx.cr6.eq) goto loc_8218EDBC;
loc_8218ED2C:
	// lwz r11,272(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 272);
	// addi r7,r31,272
	ctx.r7.s64 = ctx.r31.s64 + 272;
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8218edf4
	if (ctx.cr6.eq) goto loc_8218EDF4;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ed54
	if (ctx.cr6.eq) goto loc_8218ED54;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218ED50;
	sub_821BD1B8(ctx, base);
	// stw r29,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
loc_8218ED54:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82089490
	ctx.lr = 0x8218ED64;
	sub_82089490(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ed8c
	if (ctx.cr6.eq) goto loc_8218ED8C;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r29,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8218ED8C:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218eda8
	if (ctx.cr6.eq) goto loc_8218EDA8;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r29,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8218EDA8:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-11336
	ctx.r10.s64 = ctx.r11.s64 + -11336;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8218EDBC:
	// addi r3,r31,272
	ctx.r3.s64 = ctx.r31.s64 + 272;
	// bl 0x82089e18
	ctx.lr = 0x8218EDC4;
	sub_82089E18(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ede0
	if (ctx.cr6.eq) goto loc_8218EDE0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821bd1b8
	ctx.lr = 0x8218EDD8;
	sub_821BD1B8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
loc_8218EDE0:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,-5208
	ctx.r9.s64 = ctx.r11.s64 + -5208;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
loc_8218EDF4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218EDFC"))) PPC_WEAK_FUNC(sub_8218EDFC);
PPC_FUNC_IMPL(__imp__sub_8218EDFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218EE00"))) PPC_WEAK_FUNC(sub_8218EE00);
PPC_FUNC_IMPL(__imp__sub_8218EE00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218EE08;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ld r10,88(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 88);
	// addi r30,r3,112
	ctx.r30.s64 = ctx.r3.s64 + 112;
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
	// std r10,116(r3)
	PPC_STORE_U64(ctx.r3.u32 + 116, ctx.r10.u64);
	// bne cr6,0x8218ee3c
	if (!ctx.cr6.eq) goto loc_8218EE3C;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x8207a030
	ctx.lr = 0x8218EE38;
	sub_8207A030(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r3.u32);
loc_8218EE3C:
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x8218EE4C;
	sub_8207DA20(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r7,r31,132
	ctx.r7.s64 = ctx.r31.s64 + 132;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
loc_8218EE68:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218ee68
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218EE68;
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r6,124(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82158948
	ctx.lr = 0x8218EE84;
	sub_82158948(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218ee90
	if (ctx.cr6.eq) goto loc_8218EE90;
	// bl 0x8210e878
	ctx.lr = 0x8218EE90;
	sub_8210E878(ctx, base);
loc_8218EE90:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218EE98;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218eef8
	if (ctx.cr6.eq) goto loc_8218EEF8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24546
	ctx.r4.s64 = ctx.r11.s64 + -24546;
	// bl 0x82060190
	ctx.lr = 0x8218EEB4;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,24504
	ctx.r4.s64 = ctx.r10.s64 + 24504;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218EEC8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218EED8;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,80
	ctx.r6.s64 = ctx.r31.s64 + 80;
	// li r7,120
	ctx.r7.s64 = 120;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8218EEF4;
	sub_821BD670(ctx, base);
	// b 0x8218eefc
	goto loc_8218EEFC;
loc_8218EEF8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8218EEFC:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r7,r10,-9064
	ctx.r7.s64 = ctx.r10.s64 + -9064;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218EF30"))) PPC_WEAK_FUNC(sub_8218EF30);
PPC_FUNC_IMPL(__imp__sub_8218EF30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218EF38;
	__savegprlr_28(ctx, base);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r30,-32251
	ctx.r30.s64 = -2113601536;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// lis r29,-32251
	ctx.r29.s64 = -2113601536;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// addi r28,r6,-1396
	ctx.r28.s64 = ctx.r6.s64 + -1396;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// addi r9,r30,840
	ctx.r9.s64 = ctx.r30.s64 + 840;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r28,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r28.u32);
	// addi r30,r29,4264
	ctx.r30.s64 = ctx.r29.s64 + 4264;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
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
	// stw r7,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r7.u32);
	// stb r6,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r6.u8);
	// stb r6,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r6.u8);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r31,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r31.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218efe0
	if (ctx.cr6.eq) goto loc_8218EFE0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_8218EFE0:
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// std r5,88(r3)
	PPC_STORE_U64(ctx.r3.u32 + 88, ctx.r5.u64);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r10,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r10.u32);
	// stw r8,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r8.u32);
	// beq cr6,0x8218f000
	if (ctx.cr6.eq) goto loc_8218F000;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
loc_8218F000:
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r11.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r11.u32);
	// addi r10,r3,128
	ctx.r10.s64 = ctx.r3.s64 + 128;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8218F014:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8218f014
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218F014;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-4608
	ctx.r10.s64 = ctx.r11.s64 + -4608;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218F02C"))) PPC_WEAK_FUNC(sub_8218F02C);
PPC_FUNC_IMPL(__imp__sub_8218F02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218F030"))) PPC_WEAK_FUNC(sub_8218F030);
PPC_FUNC_IMPL(__imp__sub_8218F030) {
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
	// addi r4,r3,272
	ctx.r4.s64 = ctx.r3.s64 + 272;
	// std r11,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r11.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r11.u64);
	// std r11,288(r3)
	PPC_STORE_U64(ctx.r3.u32 + 288, ctx.r11.u64);
	// stw r11,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r11.u32);
	// lwz r3,368(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// bl 0x82157e30
	ctx.lr = 0x8218F064;
	sub_82157E30(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f084
	if (ctx.cr6.eq) goto loc_8218F084;
	// bl 0x8210e878
	ctx.lr = 0x8218F070;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// b 0x8218f098
	goto loc_8218F098;
loc_8218F084:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r8,r10,-8144
	ctx.r8.s64 = ctx.r10.s64 + -8144;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_8218F098:
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8218F0B0"))) PPC_WEAK_FUNC(sub_8218F0B0);
PPC_FUNC_IMPL(__imp__sub_8218F0B0) {
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
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r10.u32);
	// addi r6,r3,272
	ctx.r6.s64 = ctx.r3.s64 + 272;
	// std r11,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r11.u64);
	// addi r5,r3,376
	ctx.r5.s64 = ctx.r3.s64 + 376;
	// std r11,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r11.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,288(r3)
	PPC_STORE_U64(ctx.r3.u32 + 288, ctx.r11.u64);
	// stw r11,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r11.u32);
	// lwz r4,372(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// lwz r3,368(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// bl 0x82157f90
	ctx.lr = 0x8218F0F4;
	sub_82157F90(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f114
	if (ctx.cr6.eq) goto loc_8218F114;
	// bl 0x8210e878
	ctx.lr = 0x8218F100;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// b 0x8218f128
	goto loc_8218F128;
loc_8218F114:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r8,r10,-4048
	ctx.r8.s64 = ctx.r10.s64 + -4048;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_8218F128:
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8218F140"))) PPC_WEAK_FUNC(sub_8218F140);
PPC_FUNC_IMPL(__imp__sub_8218F140) {
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
	// addi r4,r3,272
	ctx.r4.s64 = ctx.r3.s64 + 272;
	// std r11,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r11.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r11.u64);
	// std r11,288(r3)
	PPC_STORE_U64(ctx.r3.u32 + 288, ctx.r11.u64);
	// stw r11,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r11.u32);
	// lwz r3,368(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// bl 0x821580d8
	ctx.lr = 0x8218F174;
	sub_821580D8(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f194
	if (ctx.cr6.eq) goto loc_8218F194;
	// bl 0x8210e878
	ctx.lr = 0x8218F180;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// b 0x8218f1a8
	goto loc_8218F1A8;
loc_8218F194:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r8,r10,-3920
	ctx.r8.s64 = ctx.r10.s64 + -3920;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_8218F1A8:
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8218F1C0"))) PPC_WEAK_FUNC(sub_8218F1C0);
PPC_FUNC_IMPL(__imp__sub_8218F1C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8218F1C8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// std r28,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r28.u64);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r28,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r28.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r28,288(r3)
	PPC_STORE_U64(ctx.r3.u32 + 288, ctx.r28.u64);
	// stw r28,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r28.u32);
	// addi r24,r3,272
	ctx.r24.s64 = ctx.r3.s64 + 272;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r3,40(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// bl 0x820891a8
	ctx.lr = 0x8218F204;
	sub_820891A8(ctx, base);
	// lwz r8,372(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// ble cr6,0x8218f248
	if (!ctx.cr6.gt) goto loc_8218F248;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r10,r31,376
	ctx.r10.s64 = ctx.r31.s64 + 376;
loc_8218F220:
	// ld r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// cmpld cr6,r8,r7
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r7.u64, ctx.xer);
	// beq cr6,0x8218f244
	if (ctx.cr6.eq) goto loc_8218F244;
	// lwz r7,372(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8218f220
	if (ctx.cr6.lt) goto loc_8218F220;
	// b 0x8218f248
	goto loc_8218F248;
loc_8218F244:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8218F248:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// stw r9,424(r31)
	PPC_STORE_U32(ctx.r31.u32 + 424, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8218f2dc
	if (!ctx.cr6.gt) goto loc_8218F2DC;
	// lis r11,4096
	ctx.r11.s64 = 268435456;
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// addi r29,r31,420
	ctx.r29.s64 = ctx.r31.s64 + 420;
	// addi r30,r31,160
	ctx.r30.s64 = ctx.r31.s64 + 160;
	// li r25,1
	ctx.r25.s64 = 1;
	// ori r26,r11,32785
	ctx.r26.u64 = ctx.r11.u64 | 32785;
loc_8218F270:
	// addi r5,r30,-48
	ctx.r5.s64 = ctx.r30.s64 + -48;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8218d230
	ctx.lr = 0x8218F280;
	sub_8218D230(ctx, base);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// addi r27,r27,16
	ctx.r27.s64 = ctx.r27.s64 + 16;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,19
	ctx.r10.s64 = ctx.r11.s64 + 19;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r25,464(r11)
	PPC_STORE_U8(ctx.r11.u32 + 464, ctx.r25.u8);
	// stwx r26,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r26.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// stw r6,472(r11)
	PPC_STORE_U32(ctx.r11.u32 + 472, ctx.r6.u32);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwu r11,12(r29)
	ea = 12 + ctx.r29.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r29.u32 = ea;
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplw cr6,r28,r5
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8218f270
	if (ctx.cr6.lt) goto loc_8218F270;
loc_8218F2DC:
	// lwz r11,424(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 424);
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// addi r6,r31,428
	ctx.r6.s64 = ctx.r31.s64 + 428;
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r11,r11,47
	ctx.r11.s64 = ctx.r11.s64 + 47;
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 368);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r31.u32);
	// bl 0x82158188
	ctx.lr = 0x8218F300;
	sub_82158188(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f328
	if (ctx.cr6.eq) goto loc_8218F328;
	// bl 0x8210e878
	ctx.lr = 0x8218F30C;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8218F328:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// addi r8,r10,-3776
	ctx.r8.s64 = ctx.r10.s64 + -3776;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218F348"))) PPC_WEAK_FUNC(sub_8218F348);
PPC_FUNC_IMPL(__imp__sub_8218F348) {
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
	// addi r5,r3,272
	ctx.r5.s64 = ctx.r3.s64 + 272;
	// std r11,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r11.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r11.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,288(r3)
	PPC_STORE_U64(ctx.r3.u32 + 288, ctx.r11.u64);
	// stw r11,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r11.u32);
	// lwz r3,368(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// bl 0x82158038
	ctx.lr = 0x8218F380;
	sub_82158038(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f3a0
	if (ctx.cr6.eq) goto loc_8218F3A0;
	// bl 0x8210e878
	ctx.lr = 0x8218F38C;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// b 0x8218f3b4
	goto loc_8218F3B4;
loc_8218F3A0:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r8,r10,-3648
	ctx.r8.s64 = ctx.r10.s64 + -3648;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
loc_8218F3B4:
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8218F3CC"))) PPC_WEAK_FUNC(sub_8218F3CC);
PPC_FUNC_IMPL(__imp__sub_8218F3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218F3D0"))) PPC_WEAK_FUNC(sub_8218F3D0);
PPC_FUNC_IMPL(__imp__sub_8218F3D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218F3D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// stw r29,372(r3)
	PPC_STORE_U32(ctx.r3.u32 + 372, ctx.r29.u32);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// li r27,1
	ctx.r27.s64 = 1;
loc_8218F3F4:
	// addi r11,r30,47
	ctx.r11.s64 = ctx.r30.s64 + 47;
	// lwz r10,-31352(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31352);
	// addi r9,r30,102
	ctx.r9.s64 = ctx.r30.s64 + 102;
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// stdx r29,r8,r31
	PPC_STORE_U64(ctx.r8.u32 + ctx.r31.u32, ctx.r29.u64);
	// stwx r27,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r27.u32);
	// lwz r6,76(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r10,76(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// bne cr6,0x8218f428
	if (!ctx.cr6.eq) goto loc_8218F428;
	// lwz r11,40(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
loc_8218F428:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x8218f478
	if (!ctx.cr6.lt) goto loc_8218F478;
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x8218f478
	if (!ctx.cr6.eq) goto loc_8218F478;
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,47
	ctx.r11.s64 = ctx.r11.s64 + 47;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x820891a8
	ctx.lr = 0x8218F45C;
	sub_820891A8(ctx, base);
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// addi r10,r11,102
	ctx.r10.s64 = ctx.r11.s64 + 102;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r29.u32);
	// lwz r11,372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,372(r31)
	PPC_STORE_U32(ctx.r31.u32 + 372, ctx.r8.u32);
loc_8218F478:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8218f3f4
	if (ctx.cr6.lt) goto loc_8218F3F4;
	// std r29,272(r31)
	PPC_STORE_U64(ctx.r31.u32 + 272, ctx.r29.u64);
	// addi r7,r31,272
	ctx.r7.s64 = ctx.r31.s64 + 272;
	// std r29,280(r31)
	PPC_STORE_U64(ctx.r31.u32 + 280, ctx.r29.u64);
	// addi r6,r31,408
	ctx.r6.s64 = ctx.r31.s64 + 408;
	// std r29,288(r31)
	PPC_STORE_U64(ctx.r31.u32 + 288, ctx.r29.u64);
	// stw r29,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r29.u32);
	// addi r5,r31,376
	ctx.r5.s64 = ctx.r31.s64 + 376;
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 368);
	// lwz r4,372(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 372);
	// bl 0x82157ee0
	ctx.lr = 0x8218F4AC;
	sub_82157EE0(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f4d4
	if (ctx.cr6.eq) goto loc_8218F4D4;
	// bl 0x8210e878
	ctx.lr = 0x8218F4B8;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8218F4D4:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// addi r8,r10,-3256
	ctx.r8.s64 = ctx.r10.s64 + -3256;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218F4F4"))) PPC_WEAK_FUNC(sub_8218F4F4);
PPC_FUNC_IMPL(__imp__sub_8218F4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218F4F8"))) PPC_WEAK_FUNC(sub_8218F4F8);
PPC_FUNC_IMPL(__imp__sub_8218F4F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218F500;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r30,r3,272
	ctx.r30.s64 = ctx.r3.s64 + 272;
	// lwz r10,-31352(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// li r5,1
	ctx.r5.s64 = 1;
	// ori r4,r4,32778
	ctx.r4.u64 = ctx.r4.u64 | 32778;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// lwz r29,40(r8)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// std r11,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r11.u64);
	// std r11,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r11.u64);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// std r11,288(r31)
	PPC_STORE_U64(ctx.r31.u32 + 288, ctx.r11.u64);
	// stw r11,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// bl 0x82088f60
	ctx.lr = 0x8218F548;
	sub_82088F60(ctx, base);
	// addi r10,r31,368
	ctx.r10.s64 = ctx.r31.s64 + 368;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r8,r31,300
	ctx.r8.s64 = ctx.r31.s64 + 300;
	// addi r7,r31,360
	ctx.r7.s64 = ctx.r31.s64 + 360;
	// li r6,8
	ctx.r6.s64 = 8;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82157c80
	ctx.lr = 0x8218F56C;
	sub_82157C80(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f594
	if (ctx.cr6.eq) goto loc_8218F594;
	// bl 0x8210e878
	ctx.lr = 0x8218F578;
	sub_8210E878(ctx, base);
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8064
	ctx.r9.s64 = ctx.r11.s64 + -8064;
	// stw r10,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218F594:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r11,-5032
	ctx.r9.s64 = ctx.r11.s64 + -5032;
	// addi r8,r10,-3120
	ctx.r8.s64 = ctx.r10.s64 + -3120;
	// stw r9,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// stw r8,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218F5B4"))) PPC_WEAK_FUNC(sub_8218F5B4);
PPC_FUNC_IMPL(__imp__sub_8218F5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218F5B8"))) PPC_WEAK_FUNC(sub_8218F5B8);
PPC_FUNC_IMPL(__imp__sub_8218F5B8) {
	PPC_FUNC_PROLOGUE();
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,368(r3)
	PPC_STORE_U32(ctx.r3.u32 + 368, ctx.r10.u32);
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// std r11,272(r3)
	PPC_STORE_U64(ctx.r3.u32 + 272, ctx.r11.u64);
	// std r11,280(r3)
	PPC_STORE_U64(ctx.r3.u32 + 280, ctx.r11.u64);
	// addi r8,r9,-2824
	ctx.r8.s64 = ctx.r9.s64 + -2824;
	// std r11,288(r3)
	PPC_STORE_U64(ctx.r3.u32 + 288, ctx.r11.u64);
	// stw r11,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r11.u32);
	// stw r8,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218F5E4"))) PPC_WEAK_FUNC(sub_8218F5E4);
PPC_FUNC_IMPL(__imp__sub_8218F5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218F5E8"))) PPC_WEAK_FUNC(sub_8218F5E8);
PPC_FUNC_IMPL(__imp__sub_8218F5E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8218F5F0;
	__savegprlr_25(ctx, base);
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// addi r8,r8,-1396
	ctx.r8.s64 = ctx.r8.s64 + -1396;
	// lis r29,-32251
	ctx.r29.s64 = -2113601536;
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stb r30,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r30.u8);
	// addi r3,r3,840
	ctx.r3.s64 = ctx.r3.s64 + 840;
	// stb r30,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r30.u8);
	// addi r10,r29,4280
	ctx.r10.s64 = ctx.r29.s64 + 4280;
	// stb r30,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r30.u8);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// addi r28,r31,112
	ctx.r28.s64 = ctx.r31.s64 + 112;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r3,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// addi r11,r28,16
	ctx.r11.s64 = ctx.r28.s64 + 16;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// stb r30,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r30.u8);
	// stb r30,59(r31)
	PPC_STORE_U8(ctx.r31.u32 + 59, ctx.r30.u8);
	// stw r30,60(r31)
	PPC_STORE_U32(ctx.r31.u32 + 60, ctx.r30.u32);
	// stb r30,58(r31)
	PPC_STORE_U8(ctx.r31.u32 + 58, ctx.r30.u8);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r7,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r7.u32);
	// stb r8,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r8.u8);
	// stb r8,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r8.u8);
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
loc_8218F69C:
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r30,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r30.u32);
	// stb r30,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// bdnz 0x8218f69c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218F69C;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// stw r5,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r5.u32);
	// ble cr6,0x8218f6c0
	if (!ctx.cr6.gt) goto loc_8218F6C0;
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
loc_8218F6C0:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8218f708
	if (!ctx.cr6.gt) goto loc_8218F708;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// addi r26,r4,-4
	ctx.r26.s64 = ctx.r4.s64 + -4;
	// addi r25,r31,96
	ctx.r25.s64 = ctx.r31.s64 + 96;
loc_8218F6DC:
	// lwzu r11,4(r26)
	ea = 4 + ctx.r26.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r26.u32 = ea;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stwu r11,4(r25)
	ea = 4 + ctx.r25.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r25.u32 = ea;
	// bl 0x82062920
	ctx.lr = 0x8218F6F0;
	sub_82062920(ctx, base);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r29,r29,80
	ctx.r29.s64 = ctx.r29.s64 + 80;
	// addi r28,r28,80
	ctx.r28.s64 = ctx.r28.s64 + 80;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8218f6dc
	if (ctx.cr6.lt) goto loc_8218F6DC;
loc_8218F708:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// addi r10,r11,-2632
	ctx.r10.s64 = ctx.r11.s64 + -2632;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218F728"))) PPC_WEAK_FUNC(sub_8218F728);
PPC_FUNC_IMPL(__imp__sub_8218F728) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8218F730;
	__savegprlr_24(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,140(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218f954
	if (ctx.cr6.eq) goto loc_8218F954;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8218f954
	if (ctx.cr6.eq) goto loc_8218F954;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8218f954
	if (!ctx.cr6.gt) goto loc_8218F954;
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// li r26,15
	ctx.r26.s64 = 15;
loc_8218F770:
	// lwz r11,140(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 140);
	// li r3,4
	ctx.r3.s64 = 4;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r29,8(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82079fd8
	ctx.lr = 0x8218F788;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218f7a0
	if (ctx.cr6.eq) goto loc_8218F7A0;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// b 0x8218f7a4
	goto loc_8218F7A4;
loc_8218F7A0:
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
loc_8218F7A4:
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// beq cr6,0x8218f848
	if (ctx.cr6.eq) goto loc_8218F848;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_8218F7BC:
	// stw r26,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r26.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// stb r30,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, ctx.r30.u8);
	// lwz r11,140(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 140);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x8218e558
	ctx.lr = 0x8218F7E4;
	sub_8218E558(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82062920
	ctx.lr = 0x8218F7F0;
	sub_82062920(ctx, base);
	// lwz r9,276(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8218f804
	if (ctx.cr6.lt) goto loc_8218F804;
	// lwz r3,256(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// bl 0x8207a630
	ctx.lr = 0x8218F804;
	sub_8207A630(ctx, base);
loc_8218F804:
	// stw r26,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r26.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stw r30,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r30,256(r1)
	PPC_STORE_U8(ctx.r1.u32 + 256, ctx.r30.u8);
	// bl 0x82062080
	ctx.lr = 0x8218F81C;
	sub_82062080(ctx, base);
	// lwz r11,196(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8218f830
	if (ctx.cr6.lt) goto loc_8218F830;
	// lwz r3,176(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// bl 0x8207a630
	ctx.lr = 0x8218F830;
	sub_8207A630(ctx, base);
loc_8218F830:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r26,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r26.u32);
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// addi r31,r31,48
	ctx.r31.s64 = ctx.r31.s64 + 48;
	// stb r30,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, ctx.r30.u8);
	// bne 0x8218f7bc
	if (!ctx.cr0.eq) goto loc_8218F7BC;
loc_8218F848:
	// lwz r11,104(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218f908
	if (ctx.cr6.eq) goto loc_8218F908;
	// add r4,r25,r11
	ctx.r4.u64 = ctx.r25.u64 + ctx.r11.u64;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8218f86c
	if (!ctx.cr6.gt) goto loc_8218F86C;
	// twi 31,r0,22
loc_8218F86C:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// ble cr6,0x8218f884
	if (!ctx.cr6.gt) goto loc_8218F884;
	// twi 31,r0,22
loc_8218F884:
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// ld r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// ld r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x82062200
	ctx.lr = 0x8218F89C;
	sub_82062200(ctx, base);
	// lwz r11,104(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 104);
	// add r3,r25,r11
	ctx.r3.u64 = ctx.r25.u64 + ctx.r11.u64;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8218f8b8
	if (!ctx.cr6.gt) goto loc_8218F8B8;
	// twi 31,r0,22
loc_8218F8B8:
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// ble cr6,0x8218f8d8
	if (!ctx.cr6.gt) goto loc_8218F8D8;
	// twi 31,r0,22
loc_8218F8D8:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r11.u32);
	// ble cr6,0x8218f8f0
	if (!ctx.cr6.gt) goto loc_8218F8F0;
	// twi 31,r0,22
loc_8218F8F0:
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// ld r6,136(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// ld r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// ld r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x8206ad38
	ctx.lr = 0x8218F908;
	sub_8206AD38(ctx, base);
loc_8218F908:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218f924
	if (ctx.cr6.eq) goto loc_8218F924;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82062350
	ctx.lr = 0x8218F91C;
	sub_82062350(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8207a630
	ctx.lr = 0x8218F924;
	sub_8207A630(ctx, base);
loc_8218F924:
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207a630
	ctx.lr = 0x8218F938;
	sub_8207A630(ctx, base);
	// lwz r11,140(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 140);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r27,r27,16
	ctx.r27.s64 = ctx.r27.s64 + 16;
	// addi r25,r25,24
	ctx.r25.s64 = ctx.r25.s64 + 24;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r24,r10
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8218f770
	if (ctx.cr6.lt) goto loc_8218F770;
loc_8218F954:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-8808
	ctx.r10.s64 = ctx.r11.s64 + -8808;
	// stw r10,72(r28)
	PPC_STORE_U32(ctx.r28.u32 + 72, ctx.r10.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218F968"))) PPC_WEAK_FUNC(sub_8218F968);
PPC_FUNC_IMPL(__imp__sub_8218F968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218F970;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// addi r30,r31,144
	ctx.r30.s64 = ctx.r31.s64 + 144;
	// bl 0x8207a030
	ctx.lr = 0x8218F984;
	sub_8207A030(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// stw r3,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r3.u32);
	// bl 0x8207da20
	ctx.lr = 0x8218F994;
	sub_8207DA20(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r10,r31,112
	ctx.r10.s64 = ctx.r31.s64 + 112;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8218F9A8:
	// stwu r8,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218f9a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218F9A8;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// lwz r9,140(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// bl 0x82089010
	ctx.lr = 0x8218F9D0;
	sub_82089010(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// beq cr6,0x8218f9ec
	if (ctx.cr6.eq) goto loc_8218F9EC;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-8808
	ctx.r10.s64 = ctx.r11.s64 + -8808;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8218F9EC:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218F9F4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218fa54
	if (ctx.cr6.eq) goto loc_8218FA54;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24557
	ctx.r4.s64 = ctx.r11.s64 + -24557;
	// bl 0x82060190
	ctx.lr = 0x8218FA10;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,24436
	ctx.r4.s64 = ctx.r10.s64 + 24436;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218FA24;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218FA34;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,84
	ctx.r6.s64 = ctx.r31.s64 + 84;
	// li r7,120
	ctx.r7.s64 = 120;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8218FA50;
	sub_821BD670(ctx, base);
	// b 0x8218fa58
	goto loc_8218FA58;
loc_8218FA54:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8218FA58:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r6,r10,-7640
	ctx.r6.s64 = ctx.r10.s64 + -7640;
	// addi r5,r9,-2264
	ctx.r5.s64 = ctx.r9.s64 + -2264;
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r6,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r6.u32);
	// stw r5,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218FA98"))) PPC_WEAK_FUNC(sub_8218FA98);
PPC_FUNC_IMPL(__imp__sub_8218FA98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8218FAA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,7
	ctx.r9.s64 = 7;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r29,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r29.u32);
	// addi r8,r3,144
	ctx.r8.s64 = ctx.r3.s64 + 144;
	// addi r11,r10,-4
	ctx.r11.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
loc_8218FAC8:
	// stwu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218fac8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218FAC8;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// bl 0x82089010
	ctx.lr = 0x8218FAEC;
	sub_82089010(ctx, base);
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x8218FAF4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218fb54
	if (ctx.cr6.eq) goto loc_8218FB54;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24558
	ctx.r4.s64 = ctx.r11.s64 + -24558;
	// bl 0x82060190
	ctx.lr = 0x8218FB10;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,24416
	ctx.r4.s64 = ctx.r10.s64 + 24416;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x8218FB24;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x8218FB34;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,84
	ctx.r6.s64 = ctx.r31.s64 + 84;
	// li r7,120
	ctx.r7.s64 = 120;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8218FB50;
	sub_821BD670(ctx, base);
	// b 0x8218fb58
	goto loc_8218FB58;
loc_8218FB54:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8218FB58:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r3.u32);
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r7,r10,-7640
	ctx.r7.s64 = ctx.r10.s64 + -7640;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// addi r6,r9,-1688
	ctx.r6.s64 = ctx.r9.s64 + -1688;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// stw r6,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r6.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218FB94"))) PPC_WEAK_FUNC(sub_8218FB94);
PPC_FUNC_IMPL(__imp__sub_8218FB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218FB98"))) PPC_WEAK_FUNC(sub_8218FB98);
PPC_FUNC_IMPL(__imp__sub_8218FB98) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-1384
	ctx.r10.s64 = ctx.r11.s64 + -1384;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218FBA8"))) PPC_WEAK_FUNC(sub_8218FBA8);
PPC_FUNC_IMPL(__imp__sub_8218FBA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8218FBB0;
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
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
	// lis r27,8191
	ctx.r27.s64 = 536805376;
	// stb r30,28(r31)
	PPC_STORE_U8(ctx.r31.u32 + 28, ctx.r30.u8);
	// addi r6,r6,-1396
	ctx.r6.s64 = ctx.r6.s64 + -1396;
	// stb r30,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r30.u8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stb r30,31(r31)
	PPC_STORE_U8(ctx.r31.u32 + 31, ctx.r30.u8);
	// addi r4,r4,840
	ctx.r4.s64 = ctx.r4.s64 + 840;
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r3,r3,4248
	ctx.r3.s64 = ctx.r3.s64 + 4248;
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stb r30,30(r31)
	PPC_STORE_U8(ctx.r31.u32 + 30, ctx.r30.u8);
	// li r26,1
	ctx.r26.s64 = 1;
	// ori r10,r27,65535
	ctx.r10.u64 = ctx.r27.u64 | 65535;
	// stw r4,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r4.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// li r27,-1
	ctx.r27.s64 = -1;
	// stb r30,56(r31)
	PPC_STORE_U8(ctx.r31.u32 + 56, ctx.r30.u8);
	// cmplw cr6,r5,r10
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, ctx.xer);
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
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// rlwinm r3,r5,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r26,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r26.u8);
	// stb r26,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r26.u8);
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
	// stw r5,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r5.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r7,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r7.u32);
	// stw r8,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r8.u32);
	// stw r9,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r9.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
	// ble cr6,0x8218fc80
	if (!ctx.cr6.gt) goto loc_8218FC80;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8218FC80:
	// bl 0x8207a030
	ctx.lr = 0x8218FC84;
	sub_8207A030(ctx, base);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8218fcbc
	if (!ctx.cr6.gt) goto loc_8218FCBC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8218FC9C:
	// ldx r9,r11,r29
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r11.u32 + ctx.r29.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,88(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stdx r9,r8,r11
	PPC_STORE_U64(ctx.r8.u32 + ctx.r11.u32, ctx.r9.u64);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lwz r7,92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8218fc9c
	if (ctx.cr6.lt) goto loc_8218FC9C;
loc_8218FCBC:
	// lis r10,481
	ctx.r10.s64 = 31522816;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// ori r9,r10,57825
	ctx.r9.u64 = ctx.r10.u64 | 57825;
	// mulli r3,r11,136
	ctx.r3.s64 = ctx.r11.s64 * 136;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8218fcd8
	if (!ctx.cr6.gt) goto loc_8218FCD8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8218FCD8:
	// bl 0x8207a030
	ctx.lr = 0x8218FCDC;
	sub_8207A030(ctx, base);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// mulli r5,r11,136
	ctx.r5.s64 = ctx.r11.s64 * 136;
	// bl 0x8207da20
	ctx.lr = 0x8218FCF0;
	sub_8207DA20(ctx, base);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r27,7
	ctx.r27.s64 = 7;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x8218fd6c
	if (!ctx.cr6.gt) goto loc_8218FD6C;
	// addi r6,r28,-4
	ctx.r6.s64 = ctx.r28.s64 + -4;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// li r7,8
	ctx.r7.s64 = 8;
	// li r28,2
	ctx.r28.s64 = 2;
	// li r29,3
	ctx.r29.s64 = 3;
	// li r3,4
	ctx.r3.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,6
	ctx.r5.s64 = 6;
loc_8218FD24:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwzu r8,4(r6)
	ea = 4 + ctx.r6.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r6.u32 = ea;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r10,r10,136
	ctx.r10.s64 = ctx.r10.s64 + 136;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// sth r26,8(r11)
	PPC_STORE_U16(ctx.r11.u32 + 8, ctx.r26.u16);
	// sth r28,10(r11)
	PPC_STORE_U16(ctx.r11.u32 + 10, ctx.r28.u16);
	// sth r29,12(r11)
	PPC_STORE_U16(ctx.r11.u32 + 12, ctx.r29.u16);
	// sth r3,14(r11)
	PPC_STORE_U16(ctx.r11.u32 + 14, ctx.r3.u16);
	// sth r4,16(r11)
	PPC_STORE_U16(ctx.r11.u32 + 16, ctx.r4.u16);
	// sth r5,18(r11)
	PPC_STORE_U16(ctx.r11.u32 + 18, ctx.r5.u16);
	// sth r27,20(r11)
	PPC_STORE_U16(ctx.r11.u32 + 20, ctx.r27.u16);
	// sth r7,22(r11)
	PPC_STORE_U16(ctx.r11.u32 + 22, ctx.r7.u16);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8218fd24
	if (ctx.cr6.lt) goto loc_8218FD24;
loc_8218FD6C:
	// addi r11,r31,108
	ctx.r11.s64 = ctx.r31.s64 + 108;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_8218FD78:
	// stwu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8218fd78
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8218FD78;
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218fd90
	if (ctx.cr6.eq) goto loc_8218FD90;
	// stw r30,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
loc_8218FD90:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r30,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-1128
	ctx.r10.s64 = ctx.r11.s64 + -1128;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218FDAC"))) PPC_WEAK_FUNC(sub_8218FDAC);
PPC_FUNC_IMPL(__imp__sub_8218FDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218FDB0"))) PPC_WEAK_FUNC(sub_8218FDB0);
PPC_FUNC_IMPL(__imp__sub_8218FDB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8218FDB8;
	__savegprlr_27(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218fe10
	if (ctx.cr6.eq) goto loc_8218FE10;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8218fe10
	if (!ctx.cr6.eq) goto loc_8218FE10;
	// lwz r3,276(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// stw r28,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r28.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218fdf4
	if (ctx.cr6.eq) goto loc_8218FDF4;
	// bl 0x8207a8a0
	ctx.lr = 0x8218FDF0;
	sub_8207A8A0(ctx, base);
	// stw r28,276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 276, ctx.r28.u32);
loc_8218FDF4:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218fe08
	if (ctx.cr6.eq) goto loc_8218FE08;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8218FE08:
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x82089e18
	ctx.lr = 0x8218FE10;
	sub_82089E18(ctx, base);
loc_8218FE10:
	// lwz r11,112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x8218ffbc
	if (ctx.cr6.eq) goto loc_8218FFBC;
	// lwz r11,276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218ffb0
	if (ctx.cr6.eq) goto loc_8218FFB0;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218ffb0
	if (ctx.cr6.eq) goto loc_8218FFB0;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bl 0x82060f40
	ctx.lr = 0x8218FE44;
	sub_82060F40(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x8218feec
	if (!ctx.cr6.gt) goto loc_8218FEEC;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// li r29,15
	ctx.r29.s64 = 15;
loc_8218FE5C:
	// lwz r11,276(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stw r29,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// stw r28,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r28.u32);
	// stb r28,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r28.u8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8218e558
	ctx.lr = 0x8218FE80;
	sub_8218E558(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82062920
	ctx.lr = 0x8218FE8C;
	sub_82062920(ctx, base);
	// lwz r9,244(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8218fea0
	if (ctx.cr6.lt) goto loc_8218FEA0;
	// lwz r3,224(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// bl 0x8207a630
	ctx.lr = 0x8218FEA0;
	sub_8207A630(ctx, base);
loc_8218FEA0:
	// stw r29,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r29.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r28,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r28,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, ctx.r28.u8);
	// bl 0x82062080
	ctx.lr = 0x8218FEB8;
	sub_82062080(ctx, base);
	// lwz r11,164(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8218fecc
	if (ctx.cr6.lt) goto loc_8218FECC;
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// bl 0x8207a630
	ctx.lr = 0x8218FECC;
	sub_8207A630(ctx, base);
loc_8218FECC:
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// stw r29,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r29.u32);
	// addi r30,r30,48
	ctx.r30.s64 = ctx.r30.s64 + 48;
	// stw r28,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r28.u32);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// stb r28,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, ctx.r28.u8);
	// blt cr6,0x8218fe5c
	if (ctx.cr6.lt) goto loc_8218FE5C;
loc_8218FEEC:
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ff64
	if (ctx.cr6.eq) goto loc_8218FF64;
	// bl 0x82062198
	ctx.lr = 0x8218FEFC;
	sub_82062198(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8218ff14
	if (!ctx.cr6.gt) goto loc_8218FF14;
	// twi 31,r0,22
loc_8218FF14:
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// ble cr6,0x8218ff34
	if (!ctx.cr6.gt) goto loc_8218FF34;
	// twi 31,r0,22
loc_8218FF34:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// ble cr6,0x8218ff4c
	if (!ctx.cr6.gt) goto loc_8218FF4C;
	// twi 31,r0,22
loc_8218FF4C:
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// ld r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// ld r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// ld r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x8206ad38
	ctx.lr = 0x8218FF64;
	sub_8206AD38(ctx, base);
loc_8218FF64:
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8218ff80
	if (ctx.cr6.eq) goto loc_8218FF80;
	// lwz r10,276(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_8218FF80:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8218ff9c
	if (ctx.cr6.eq) goto loc_8218FF9C;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82062350
	ctx.lr = 0x8218FF94;
	sub_82062350(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8207a630
	ctx.lr = 0x8218FF9C;
	sub_8207A630(ctx, base);
loc_8218FF9C:
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207a630
	ctx.lr = 0x8218FFB0;
	sub_8207A630(ctx, base);
loc_8218FFB0:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-7208
	ctx.r10.s64 = ctx.r11.s64 + -7208;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_8218FFBC:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218FFC4"))) PPC_WEAK_FUNC(sub_8218FFC4);
PPC_FUNC_IMPL(__imp__sub_8218FFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8218FFC8"))) PPC_WEAK_FUNC(sub_8218FFC8);
PPC_FUNC_IMPL(__imp__sub_8218FFC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8218FFD0;
	__savegprlr_29(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,84(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r11,8
	ctx.r11.s64 = 8;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// sth r9,148(r3)
	PPC_STORE_U16(ctx.r3.u32 + 148, ctx.r9.u16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// sth r8,150(r3)
	PPC_STORE_U16(ctx.r3.u32 + 150, ctx.r8.u16);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// sth r7,152(r3)
	PPC_STORE_U16(ctx.r3.u32 + 152, ctx.r7.u16);
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r3,7
	ctx.r3.s64 = 7;
	// sth r6,154(r31)
	PPC_STORE_U16(ctx.r31.u32 + 154, ctx.r6.u16);
	// addi r30,r31,140
	ctx.r30.s64 = ctx.r31.s64 + 140;
	// sth r5,156(r31)
	PPC_STORE_U16(ctx.r31.u32 + 156, ctx.r5.u16);
	// sth r4,158(r31)
	PPC_STORE_U16(ctx.r31.u32 + 158, ctx.r4.u16);
	// sth r3,160(r31)
	PPC_STORE_U16(ctx.r31.u32 + 160, ctx.r3.u16);
	// sth r11,162(r31)
	PPC_STORE_U16(ctx.r31.u32 + 162, ctx.r11.u16);
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x82190090
	if (!ctx.cr6.eq) goto loc_82190090;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r3,40(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// blt cr6,0x82190064
	if (ctx.cr6.lt) goto loc_82190064;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-8728
	ctx.r10.s64 = ctx.r11.s64 + -8728;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82190064:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x820891a8
	ctx.lr = 0x8219006C;
	sub_820891A8(ctx, base);
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82089148
	ctx.lr = 0x8219008C;
	sub_82089148(ctx, base);
	// b 0x821900ac
	goto loc_821900AC;
loc_82190090:
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820890e8
	ctx.lr = 0x821900AC;
	sub_820890E8(ctx, base);
loc_821900AC:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207a030
	ctx.lr = 0x821900B4;
	sub_8207A030(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r3,276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 276, ctx.r3.u32);
	// addi r7,r31,112
	ctx.r7.s64 = ctx.r31.s64 + 112;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821900CC:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821900cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821900CC;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,276(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 276);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82089a18
	ctx.lr = 0x821900E8;
	sub_82089A18(ctx, base);
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x821900F0;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82190150
	if (ctx.cr6.eq) goto loc_82190150;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-24565
	ctx.r4.s64 = ctx.r11.s64 + -24565;
	// bl 0x82060190
	ctx.lr = 0x8219010C;
	sub_82060190(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,24396
	ctx.r4.s64 = ctx.r10.s64 + 24396;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060190
	ctx.lr = 0x82190120;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x82190130;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r6,r31,80
	ctx.r6.s64 = ctx.r31.s64 + 80;
	// li r7,120
	ctx.r7.s64 = 120;
	// li r8,1
	ctx.r8.s64 = 1;
	// bl 0x821bd670
	ctx.lr = 0x8219014C;
	sub_821BD670(ctx, base);
	// b 0x82190154
	goto loc_82190154;
loc_82190150:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82190154:
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// stw r3,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// addi r7,r10,-592
	ctx.r7.s64 = ctx.r10.s64 + -592;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// stw r7,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r7.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82190188"))) PPC_WEAK_FUNC(sub_82190188);
PPC_FUNC_IMPL(__imp__sub_82190188) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,92(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x821901ac
	if (ctx.cr6.lt) goto loc_821901AC;
	// cmplwi cr6,r11,100
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 100, ctx.xer);
	// bgt cr6,0x821901ac
	if (ctx.cr6.gt) goto loc_821901AC;
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-56
	ctx.r10.s64 = ctx.r11.s64 + -56;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_821901AC:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,-8728
	ctx.r10.s64 = ctx.r11.s64 + -8728;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821901BC"))) PPC_WEAK_FUNC(sub_821901BC);
PPC_FUNC_IMPL(__imp__sub_821901BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821901C0"))) PPC_WEAK_FUNC(sub_821901C0);
PPC_FUNC_IMPL(__imp__sub_821901C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821901C8;
	__savegprlr_29(ctx, base);
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r30,r8,-1396
	ctx.r30.s64 = ctx.r8.s64 + -1396;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lis r31,-32251
	ctx.r31.s64 = -2113601536;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// lis r29,-32251
	ctx.r29.s64 = -2113601536;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// li r8,7
	ctx.r8.s64 = 7;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r9,r31,840
	ctx.r9.s64 = ctx.r31.s64 + 840;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r30,r29,4232
	ctx.r30.s64 = ctx.r29.s64 + 4232;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// li r31,1
	ctx.r31.s64 = 1;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// li r29,100
	ctx.r29.s64 = 100;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// addi r10,r3,108
	ctx.r10.s64 = ctx.r3.s64 + 108;
	// stb r11,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r11.u8);
	// stb r11,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r11.u8);
	// stb r11,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r11.u8);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stb r11,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r11.u8);
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stb r31,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r31.u8);
	// stb r31,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r31.u8);
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// stw r5,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r5.u32);
	// stw r29,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r29.u32);
	// stw r6,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r6.u32);
	// stw r7,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r7.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// stw r11,276(r3)
	PPC_STORE_U32(ctx.r3.u32 + 276, ctx.r11.u32);
loc_82190280:
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82190280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82190280;
	// lwz r10,108(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82190298
	if (ctx.cr6.eq) goto loc_82190298;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_82190298:
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// addi r10,r11,392
	ctx.r10.s64 = ctx.r11.s64 + 392;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821902A8"))) PPC_WEAK_FUNC(sub_821902A8);
PPC_FUNC_IMPL(__imp__sub_821902A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821902AC"))) PPC_WEAK_FUNC(sub_821902AC);
PPC_FUNC_IMPL(__imp__sub_821902AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821902B0"))) PPC_WEAK_FUNC(sub_821902B0);
PPC_FUNC_IMPL(__imp__sub_821902B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplw cr6,r10,r4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82190308
	if (ctx.cr6.eq) goto loc_82190308;
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// lwz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r8,r4,18
	ctx.r8.s64 = ctx.r4.s64 + 18;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stwx r9,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r9.u32);
	// lwzx r10,r6,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// beq cr6,0x82190304
	if (ctx.cr6.eq) goto loc_82190304;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82190304
	if (!ctx.cr6.eq) goto loc_82190304;
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// addi r10,r10,18
	ctx.r10.s64 = ctx.r10.s64 + 18;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// stw r8,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
loc_82190304:
	// stw r4,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r4.u32);
loc_82190308:
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 52);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190310"))) PPC_WEAK_FUNC(sub_82190310);
PPC_FUNC_IMPL(__imp__sub_82190310) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190318"))) PPC_WEAK_FUNC(sub_82190318);
PPC_FUNC_IMPL(__imp__sub_82190318) {
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
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8219034c
	if (!ctx.cr6.eq) goto loc_8219034C;
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
loc_8219034C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x82190354;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82190360
	if (!ctx.cr6.eq) goto loc_82190360;
	// ld r31,96(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
loc_82190360:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_82190378"))) PPC_WEAK_FUNC(sub_82190378);
PPC_FUNC_IMPL(__imp__sub_82190378) {
	PPC_FUNC_PROLOGUE();
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r3,72
	ctx.r9.s64 = ctx.r3.s64 + 72;
	// stw r10,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r10.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stw r10,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r10.u32);
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x821903a8
	if (!ctx.cr6.eq) goto loc_821903A8;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_821903A8:
	// li r9,1
	ctx.r9.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821903B8"))) PPC_WEAK_FUNC(sub_821903B8);
PPC_FUNC_IMPL(__imp__sub_821903B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821903C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82190418
	if (!ctx.cr6.eq) goto loc_82190418;
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82190418
	if (ctx.cr6.eq) goto loc_82190418;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x821903F0;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82190414
	if (!ctx.cr6.eq) goto loc_82190414;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82190408
	if (ctx.cr6.eq) goto loc_82190408;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_82190408:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_82190414:
	// stw r29,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
loc_82190418:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82190424
	if (ctx.cr6.eq) goto loc_82190424;
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
loc_82190424:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82190430"))) PPC_WEAK_FUNC(sub_82190430);
PPC_FUNC_IMPL(__imp__sub_82190430) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82190454
	if (!ctx.cr6.eq) goto loc_82190454;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8219044c
	if (ctx.cr6.eq) goto loc_8219044C;
	// lwz r11,52(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_8219044C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82190454:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82190464
	if (ctx.cr6.eq) goto loc_82190464;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_82190464:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219046C"))) PPC_WEAK_FUNC(sub_8219046C);
PPC_FUNC_IMPL(__imp__sub_8219046C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190470"))) PPC_WEAK_FUNC(sub_82190470);
PPC_FUNC_IMPL(__imp__sub_82190470) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82190478;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x821904d8
	if (!ctx.cr6.eq) goto loc_821904D8;
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821904b8
	if (ctx.cr6.eq) goto loc_821904B8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x821904A8;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821904b8
	if (ctx.cr6.eq) goto loc_821904B8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_821904B8:
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821904cc
	if (ctx.cr6.eq) goto loc_821904CC;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x821904d8
	if (ctx.cr6.eq) goto loc_821904D8;
loc_821904CC:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r29,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r29.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_821904D8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821904E0"))) PPC_WEAK_FUNC(sub_821904E0);
PPC_FUNC_IMPL(__imp__sub_821904E0) {
	PPC_FUNC_PROLOGUE();
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821904EC"))) PPC_WEAK_FUNC(sub_821904EC);
PPC_FUNC_IMPL(__imp__sub_821904EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821904F0"))) PPC_WEAK_FUNC(sub_821904F0);
PPC_FUNC_IMPL(__imp__sub_821904F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821904F8"))) PPC_WEAK_FUNC(sub_821904F8);
PPC_FUNC_IMPL(__imp__sub_821904F8) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x8219051c
	if (ctx.cr6.lt) goto loc_8219051C;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bgt cr6,0x8219051c
	if (ctx.cr6.gt) goto loc_8219051C;
	// mulli r11,r4,132
	ctx.r11.s64 = ctx.r4.s64 * 132;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// and r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 & ctx.r5.u64;
	// blr 
	return;
loc_8219051C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190524"))) PPC_WEAK_FUNC(sub_82190524);
PPC_FUNC_IMPL(__imp__sub_82190524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190528"))) PPC_WEAK_FUNC(sub_82190528);
PPC_FUNC_IMPL(__imp__sub_82190528) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// ble cr6,0x82190538
	if (!ctx.cr6.gt) goto loc_82190538;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82190538:
	// mulli r11,r4,132
	ctx.r11.s64 = ctx.r4.s64 * 132;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// and r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 & ctx.r5.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219054C"))) PPC_WEAK_FUNC(sub_8219054C);
PPC_FUNC_IMPL(__imp__sub_8219054C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190550"))) PPC_WEAK_FUNC(sub_82190550);
PPC_FUNC_IMPL(__imp__sub_82190550) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x82190574
	if (ctx.cr6.lt) goto loc_82190574;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bgt cr6,0x82190574
	if (ctx.cr6.gt) goto loc_82190574;
	// mulli r11,r4,132
	ctx.r11.s64 = ctx.r4.s64 * 132;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// and r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 & ctx.r5.u64;
	// blr 
	return;
loc_82190574:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219057C"))) PPC_WEAK_FUNC(sub_8219057C);
PPC_FUNC_IMPL(__imp__sub_8219057C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190580"))) PPC_WEAK_FUNC(sub_82190580);
PPC_FUNC_IMPL(__imp__sub_82190580) {
	PPC_FUNC_PROLOGUE();
	// li r11,-1
	ctx.r11.s64 = -1;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r11.u32);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// stw r9,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219059C"))) PPC_WEAK_FUNC(sub_8219059C);
PPC_FUNC_IMPL(__imp__sub_8219059C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821905A0"))) PPC_WEAK_FUNC(sub_821905A0);
PPC_FUNC_IMPL(__imp__sub_821905A0) {
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
	// mulli r11,r4,132
	ctx.r11.s64 = ctx.r4.s64 * 132;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r31,r11,56
	ctx.r31.s64 = ctx.r11.s64 + 56;
	// bl 0x82089db8
	ctx.lr = 0x821905CC;
	sub_82089DB8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8219060c
	if (!ctx.cr6.eq) goto loc_8219060C;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r1,82
	ctx.r11.s64 = ctx.r1.s64 + 82;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r10,r31,118
	ctx.r10.s64 = ctx.r31.s64 + 118;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_821905EC:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// sthu r9,2(r10)
	ea = 2 + ctx.r10.u32;
	PPC_STORE_U16(ea, ctx.r9.u16);
	ctx.r10.u32 = ea;
	// bdnz 0x821905ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821905EC;
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
loc_8219060C:
	// li r5,132
	ctx.r5.s64 = 132;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207da20
	ctx.lr = 0x8219061C;
	sub_8207DA20(ctx, base);
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

__attribute__((alias("__imp__sub_82190630"))) PPC_WEAK_FUNC(sub_82190630);
PPC_FUNC_IMPL(__imp__sub_82190630) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219063C"))) PPC_WEAK_FUNC(sub_8219063C);
PPC_FUNC_IMPL(__imp__sub_8219063C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190640"))) PPC_WEAK_FUNC(sub_82190640);
PPC_FUNC_IMPL(__imp__sub_82190640) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82190650
	if (ctx.cr6.eq) goto loc_82190650;
	// lwz r11,68(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_82190650:
	// lwz r3,64(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190658"))) PPC_WEAK_FUNC(sub_82190658);
PPC_FUNC_IMPL(__imp__sub_82190658) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82190660;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r3,24
	ctx.r29.s64 = ctx.r3.s64 + 24;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_82190674:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82088f70
	ctx.lr = 0x8219067C;
	sub_82088F70(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// lwz r11,40(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821906e0
	if (!ctx.cr6.eq) goto loc_821906E0;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82088f68
	ctx.lr = 0x8219069C;
	sub_82088F68(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821906dc
	if (ctx.cr6.eq) goto loc_821906DC;
	// addi r10,r30,48
	ctx.r10.s64 = ctx.r30.s64 + 48;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_821906B0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x821906d4
	if (ctx.cr6.eq) goto loc_821906D4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821906b0
	if (ctx.cr6.eq) goto loc_821906B0;
loc_821906D4:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821906e0
	if (ctx.cr6.eq) goto loc_821906E0;
loc_821906DC:
	// stw r28,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r28.u32);
loc_821906E0:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x82190674
	if (ctx.cr6.lt) goto loc_82190674;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821906F8"))) PPC_WEAK_FUNC(sub_821906F8);
PPC_FUNC_IMPL(__imp__sub_821906F8) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// bne cr6,0x82190704
	if (!ctx.cr6.eq) goto loc_82190704;
	// lwz r4,40(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
loc_82190704:
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// blt cr6,0x82190714
	if (ctx.cr6.lt) goto loc_82190714;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82190714:
	// addi r11,r4,6
	ctx.r11.s64 = ctx.r4.s64 + 6;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190724"))) PPC_WEAK_FUNC(sub_82190724);
PPC_FUNC_IMPL(__imp__sub_82190724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190728"))) PPC_WEAK_FUNC(sub_82190728);
PPC_FUNC_IMPL(__imp__sub_82190728) {
	PPC_FUNC_PROLOGUE();
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190734"))) PPC_WEAK_FUNC(sub_82190734);
PPC_FUNC_IMPL(__imp__sub_82190734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190738"))) PPC_WEAK_FUNC(sub_82190738);
PPC_FUNC_IMPL(__imp__sub_82190738) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190740"))) PPC_WEAK_FUNC(sub_82190740);
PPC_FUNC_IMPL(__imp__sub_82190740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r10,4
	ctx.r10.s64 = 4;
	// subfc r9,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi r3,r7,31
	ctx.r3.u64 = ctx.r7.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190758"))) PPC_WEAK_FUNC(sub_82190758);
PPC_FUNC_IMPL(__imp__sub_82190758) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8219076C"))) PPC_WEAK_FUNC(sub_8219076C);
PPC_FUNC_IMPL(__imp__sub_8219076C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190770"))) PPC_WEAK_FUNC(sub_82190770);
PPC_FUNC_IMPL(__imp__sub_82190770) {
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
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x821d51a4
	ctx.lr = 0x82190798;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821907a8
	if (ctx.cr6.eq) goto loc_821907A8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
loc_821907A8:
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// bl 0x821d51a4
	ctx.lr = 0x821907C0;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821907d0
	if (ctx.cr6.eq) goto loc_821907D0;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_821907D0:
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821d51a4
	ctx.lr = 0x821907E8;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821907f8
	if (ctx.cr6.eq) goto loc_821907F8;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
loc_821907F8:
	// lis r4,512
	ctx.r4.s64 = 33554432;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// ori r4,r4,7
	ctx.r4.u64 = ctx.r4.u64 | 7;
	// bl 0x821d51a4
	ctx.lr = 0x82190810;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82190820
	if (ctx.cr6.eq) goto loc_82190820;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_82190820:
	// lis r4,2560
	ctx.r4.s64 = 167772160;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// bl 0x821d51a4
	ctx.lr = 0x82190838;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82190848
	if (ctx.cr6.eq) goto loc_82190848;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
loc_82190848:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lbz r9,-31359(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + -31359);
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82190870"))) PPC_WEAK_FUNC(sub_82190870);
PPC_FUNC_IMPL(__imp__sub_82190870) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190878"))) PPC_WEAK_FUNC(sub_82190878);
PPC_FUNC_IMPL(__imp__sub_82190878) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190880"))) PPC_WEAK_FUNC(sub_82190880);
PPC_FUNC_IMPL(__imp__sub_82190880) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190894"))) PPC_WEAK_FUNC(sub_82190894);
PPC_FUNC_IMPL(__imp__sub_82190894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190898"))) PPC_WEAK_FUNC(sub_82190898);
PPC_FUNC_IMPL(__imp__sub_82190898) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821908d0
	if (ctx.cr6.eq) goto loc_821908D0;
	// lis r9,21
	ctx.r9.s64 = 1376256;
	// ori r8,r9,4335
	ctx.r8.u64 = ctx.r9.u64 | 4335;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x821908cc
	if (!ctx.cr6.gt) goto loc_821908CC;
	// lis r9,21
	ctx.r9.s64 = 1376256;
	// ori r8,r9,4337
	ctx.r8.u64 = ctx.r9.u64 | 4337;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x821908d0
	if (!ctx.cr6.gt) goto loc_821908D0;
loc_821908CC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_821908D0:
	// lwz r11,48(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r10,52(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821908ec
	if (ctx.cr6.eq) goto loc_821908EC;
	// li r3,1
	ctx.r3.s64 = 1;
loc_821908EC:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821908FC"))) PPC_WEAK_FUNC(sub_821908FC);
PPC_FUNC_IMPL(__imp__sub_821908FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190900"))) PPC_WEAK_FUNC(sub_82190900);
PPC_FUNC_IMPL(__imp__sub_82190900) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190908"))) PPC_WEAK_FUNC(sub_82190908);
PPC_FUNC_IMPL(__imp__sub_82190908) {
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
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x821d51a4
	ctx.lr = 0x82190934;
	__imp__XNotifyGetNext(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82190944
	if (ctx.cr6.eq) goto loc_82190944;
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
loc_82190944:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82190a20
	if (ctx.cr6.eq) goto loc_82190A20;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8219099c
	if (ctx.cr6.eq) goto loc_8219099C;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82190a24
	if (!ctx.cr6.eq) goto loc_82190A24;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,997
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 997, ctx.xer);
	// beq cr6,0x82190a24
	if (ctx.cr6.eq) goto loc_82190A24;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82190a24
	if (ctx.cr6.eq) goto loc_82190A24;
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82190a24
	if (!ctx.cr6.eq) goto loc_82190A24;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r10,14572(r11)
	PPC_STORE_U32(ctx.r11.u32 + 14572, ctx.r10.u32);
	// b 0x82190a24
	goto loc_82190A24;
loc_8219099C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r30,40(r9)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x821909c8
	if (ctx.cr6.lt) goto loc_821909C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82089478
	ctx.lr = 0x821909C4;
	sub_82089478(ctx, base);
	// b 0x82190a24
	goto loc_82190A24;
loc_821909C8:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x82088378
	ctx.lr = 0x821909D4;
	sub_82088378(ctx, base);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r8,r31,24
	ctx.r8.s64 = ctx.r31.s64 + 24;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r11,r8,-4
	ctx.r11.s64 = ctx.r8.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821909EC:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821909ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821909EC;
	// lwz r11,56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addi r7,r31,52
	ctx.r7.s64 = ctx.r31.s64 + 52;
	// li r4,1
	ctx.r4.s64 = 1;
	// ori r5,r11,256
	ctx.r5.u64 = ctx.r11.u64 | 256;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089488
	ctx.lr = 0x82190A0C;
	sub_82089488(ctx, base);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x82190a24
	if (!ctx.cr6.eq) goto loc_82190A24;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// b 0x82190a24
	goto loc_82190A24;
loc_82190A20:
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
loc_82190A24:
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

__attribute__((alias("__imp__sub_82190A3C"))) PPC_WEAK_FUNC(sub_82190A3C);
PPC_FUNC_IMPL(__imp__sub_82190A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190A40"))) PPC_WEAK_FUNC(sub_82190A40);
PPC_FUNC_IMPL(__imp__sub_82190A40) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190A50"))) PPC_WEAK_FUNC(sub_82190A50);
PPC_FUNC_IMPL(__imp__sub_82190A50) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,4204
	ctx.r9.s64 = ctx.r10.s64 + 4204;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// addi r10,r3,72
	ctx.r10.s64 = ctx.r3.s64 + 72;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r11.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190A90"))) PPC_WEAK_FUNC(sub_82190A90);
PPC_FUNC_IMPL(__imp__sub_82190A90) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,68
	ctx.r10.s64 = ctx.r3.s64 + 68;
loc_82190A98:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82190abc
	if (ctx.cr6.lt) goto loc_82190ABC;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x82190abc
	if (ctx.cr6.gt) goto loc_82190ABC;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// rlwinm r8,r8,0,31,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82190ad4
	if (!ctx.cr6.eq) goto loc_82190AD4;
loc_82190ABC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,132
	ctx.r10.s64 = ctx.r10.s64 + 132;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82190a98
	if (ctx.cr6.lt) goto loc_82190A98;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_82190AD4:
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190AE0"))) PPC_WEAK_FUNC(sub_82190AE0);
PPC_FUNC_IMPL(__imp__sub_82190AE0) {
	PPC_FUNC_PROLOGUE();
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r3,60
	ctx.r10.s64 = ctx.r3.s64 + 60;
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
loc_82190AF0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x82190b10
	if (ctx.cr6.lt) goto loc_82190B10;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bgt cr6,0x82190b10
	if (ctx.cr6.gt) goto loc_82190B10;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// and r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 & ctx.r4.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82190b28
	if (!ctx.cr6.eq) goto loc_82190B28;
loc_82190B10:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,132
	ctx.r10.s64 = ctx.r10.s64 + 132;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// blt cr6,0x82190af0
	if (ctx.cr6.lt) goto loc_82190AF0;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// blr 
	return;
loc_82190B28:
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190B34"))) PPC_WEAK_FUNC(sub_82190B34);
PPC_FUNC_IMPL(__imp__sub_82190B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190B38"))) PPC_WEAK_FUNC(sub_82190B38);
PPC_FUNC_IMPL(__imp__sub_82190B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lhz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r11,4104
	ctx.r9.s64 = ctx.r11.s64 + 4104;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82190B5C:
	// and r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 & ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82190b70
	if (ctx.cr6.eq) goto loc_82190B70;
	// lwz r10,-4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// or r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 | ctx.r6.u64;
loc_82190B70:
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// and r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 & ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82190b88
	if (ctx.cr6.eq) goto loc_82190B88;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// or r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 | ctx.r6.u64;
loc_82190B88:
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// and r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 & ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82190ba0
	if (ctx.cr6.eq) goto loc_82190BA0;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// or r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 | ctx.r6.u64;
loc_82190BA0:
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// and r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 & ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82190bb8
	if (ctx.cr6.eq) goto loc_82190BB8;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// or r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 | ctx.r6.u64;
loc_82190BB8:
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bdnz 0x82190b5c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82190B5C;
	// clrlwi r11,r8,31
	ctx.r11.u64 = ctx.r8.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82190bd4
	if (ctx.cr6.eq) goto loc_82190BD4;
	// oris r6,r6,4
	ctx.r6.u64 = ctx.r6.u64 | 262144;
loc_82190BD4:
	// rlwinm r11,r8,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82190be4
	if (ctx.cr6.eq) goto loc_82190BE4;
	// oris r6,r6,8
	ctx.r6.u64 = ctx.r6.u64 | 524288;
loc_82190BE4:
	// rlwinm r11,r8,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82190bf4
	if (ctx.cr6.eq) goto loc_82190BF4;
	// oris r6,r6,2
	ctx.r6.u64 = ctx.r6.u64 | 131072;
loc_82190BF4:
	// rlwinm r11,r8,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82190c04
	if (ctx.cr6.eq) goto loc_82190C04;
	// oris r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 | 65536;
loc_82190C04:
	// lbz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// ble cr6,0x82190c14
	if (!ctx.cr6.gt) goto loc_82190C14;
	// ori r6,r6,16384
	ctx.r6.u64 = ctx.r6.u64 | 16384;
loc_82190C14:
	// lbz r11,3(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// ble cr6,0x82190c24
	if (!ctx.cr6.gt) goto loc_82190C24;
	// ori r6,r6,32768
	ctx.r6.u64 = ctx.r6.u64 | 32768;
loc_82190C24:
	// lhz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// cmpwi cr6,r31,8689
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 8689, ctx.xer);
	// bgt cr6,0x82190c44
	if (ctx.cr6.gt) goto loc_82190C44;
	// rlwinm r11,r6,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82190c48
	if (ctx.cr6.eq) goto loc_82190C48;
loc_82190C44:
	// li r5,1
	ctx.r5.s64 = 1;
loc_82190C48:
	// cmpwi cr6,r31,-8689
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -8689, ctx.xer);
	// blt cr6,0x82190c60
	if (ctx.cr6.lt) goto loc_82190C60;
	// rlwinm r11,r6,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x20;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82190c64
	if (ctx.cr6.eq) goto loc_82190C64;
loc_82190C60:
	// li r7,1
	ctx.r7.s64 = 1;
loc_82190C64:
	// lhz r11,6(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// cmpwi cr6,r4,8689
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8689, ctx.xer);
	// bgt cr6,0x82190c84
	if (ctx.cr6.gt) goto loc_82190C84;
	// rlwinm r11,r6,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x40;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82190c88
	if (ctx.cr6.eq) goto loc_82190C88;
loc_82190C84:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82190C88:
	// cmpwi cr6,r4,-8689
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -8689, ctx.xer);
	// blt cr6,0x82190ca0
	if (ctx.cr6.lt) goto loc_82190CA0;
	// rlwinm r11,r6,0,24,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x80;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82190ca4
	if (ctx.cr6.eq) goto loc_82190CA4;
loc_82190CA0:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82190CA4:
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// rlwinm r11,r6,0,28,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// lwz r8,-31348(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31348);
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r8,1444(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1444);
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// bgt cr6,0x82190e60
	if (ctx.cr6.gt) goto loc_82190E60;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82190d38
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82190D38;
	// bdzf 4*cr6+eq,0x82190d9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82190D9C;
	// bne cr6,0x82190e00
	if (!ctx.cr6.eq) goto loc_82190E00;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// subfic r8,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r10.s64;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// subfe r8,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r7,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// li r9,128
	ctx.r9.s64 = 128;
	// subfe r7,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r6,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r10.s64;
	// li r6,64
	ctx.r6.s64 = 64;
	// and r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// and r8,r7,r6
	ctx.r8.u64 = ctx.r7.u64 & ctx.r6.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r7,32
	ctx.r7.s64 = 32;
	// subfic r5,r5,0
	ctx.xer.ca = ctx.r5.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r5.s64;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// and r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 & ctx.r7.u64;
	// subfe r8,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,16
	ctx.r9.s64 = 16;
	// or r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 | ctx.r10.u64;
	// and r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 & ctx.r9.u64;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 | ctx.r11.u64;
	// b 0x82190e60
	goto loc_82190E60;
loc_82190D38:
	// clrlwi r8,r7,24
	ctx.r8.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// subfic r6,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r8.s64;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r7,r7,0
	ctx.xer.ca = ctx.r7.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r7.s64;
	// li r10,128
	ctx.r10.s64 = 128;
	// subfe r7,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r6,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r9.s64;
	// li r6,16
	ctx.r6.s64 = 16;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// and r8,r7,r6
	ctx.r8.u64 = ctx.r7.u64 & ctx.r6.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r7,32
	ctx.r7.s64 = 32;
	// subfic r5,r5,0
	ctx.xer.ca = ctx.r5.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r5.s64;
	// or r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 | ctx.r8.u64;
	// and r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 & ctx.r7.u64;
	// subfe r8,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r9,64
	ctx.r9.s64 = 64;
	// or r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 | ctx.r10.u64;
	// and r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 & ctx.r9.u64;
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 | ctx.r11.u64;
	// b 0x82190e60
	goto loc_82190E60;
loc_82190D9C:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// subfic r6,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r9.s64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// subfe r7,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r6,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r8.s64;
	// li r8,128
	ctx.r8.s64 = 128;
	// subfe r6,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r10,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r9.s64;
	// li r10,64
	ctx.r10.s64 = 64;
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// and r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 & ctx.r8.u64;
	// and r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 & ctx.r10.u64;
	// subfe r9,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r5,r5,0
	ctx.xer.ca = ctx.r5.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r5.s64;
	// li r6,16
	ctx.r6.s64 = 16;
	// or r10,r8,r7
	ctx.r10.u64 = ctx.r8.u64 | ctx.r7.u64;
	// and r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 & ctx.r6.u64;
	// li r8,32
	ctx.r8.s64 = 32;
	// subfe r7,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// and r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 & ctx.r8.u64;
	// or r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// b 0x82190e60
	goto loc_82190E60;
loc_82190E00:
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// subfic r5,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r8.s64;
	// clrlwi r8,r7,24
	ctx.r8.u64 = ctx.r7.u32 & 0xFF;
	// subfe r7,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r6,r6,0
	ctx.xer.ca = ctx.r6.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r6.s64;
	// li r10,128
	ctx.r10.s64 = 128;
	// subfe r6,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfic r5,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r8.s64;
	// li r5,32
	ctx.r5.s64 = 32;
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// and r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 & ctx.r5.u64;
	// subfe r8,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r8.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 & ctx.r10.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r9.s64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// and r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	// subfe r6,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// li r7,16
	ctx.r7.s64 = 16;
	// or r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 | ctx.r8.u64;
	// and r10,r6,r7
	ctx.r10.u64 = ctx.r6.u64 & ctx.r7.u64;
	// or r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 | ctx.r10.u64;
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_82190E60:
	// cmpwi cr6,r31,16384
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 16384, ctx.xer);
	// ble cr6,0x82190e6c
	if (!ctx.cr6.gt) goto loc_82190E6C;
	// oris r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 65536;
loc_82190E6C:
	// cmpwi cr6,r31,-16384
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -16384, ctx.xer);
	// bge cr6,0x82190e78
	if (!ctx.cr6.lt) goto loc_82190E78;
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
loc_82190E78:
	// cmpwi cr6,r4,16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 16384, ctx.xer);
	// ble cr6,0x82190e84
	if (!ctx.cr6.gt) goto loc_82190E84;
	// oris r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 262144;
loc_82190E84:
	// cmpwi cr6,r4,-16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -16384, ctx.xer);
	// bge cr6,0x82190e90
	if (!ctx.cr6.lt) goto loc_82190E90;
	// oris r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 524288;
loc_82190E90:
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpwi cr6,r10,12288
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 12288, ctx.xer);
	// ble cr6,0x82190ea4
	if (!ctx.cr6.gt) goto loc_82190EA4;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
loc_82190EA4:
	// cmpwi cr6,r10,-12288
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -12288, ctx.xer);
	// bge cr6,0x82190eb0
	if (!ctx.cr6.lt) goto loc_82190EB0;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
loc_82190EB0:
	// lhz r10,10(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmpwi cr6,r10,12288
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 12288, ctx.xer);
	// ble cr6,0x82190ec4
	if (!ctx.cr6.gt) goto loc_82190EC4;
	// oris r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 4194304;
loc_82190EC4:
	// cmpwi cr6,r10,-12288
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -12288, ctx.xer);
	// oris r3,r11,128
	ctx.r3.u64 = ctx.r11.u64 | 8388608;
	// blt cr6,0x82190ed4
	if (ctx.cr6.lt) goto loc_82190ED4;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82190ED4:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190EDC"))) PPC_WEAK_FUNC(sub_82190EDC);
PPC_FUNC_IMPL(__imp__sub_82190EDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82190EE0"))) PPC_WEAK_FUNC(sub_82190EE0);
PPC_FUNC_IMPL(__imp__sub_82190EE0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82190EF0"))) PPC_WEAK_FUNC(sub_82190EF0);
PPC_FUNC_IMPL(__imp__sub_82190EF0) {
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
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r10,r11,4192
	ctx.r10.s64 = ctx.r11.s64 + 4192;
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// stb r30,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r30.u8);
	// li r5,660
	ctx.r5.s64 = 660;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// stw r9,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// bl 0x8207da20
	ctx.lr = 0x82190F40;
	sub_8207DA20(ctx, base);
	// li r8,20
	ctx.r8.s64 = 20;
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r8,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
	// stw r7,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r6,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r6.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_82190F80"))) PPC_WEAK_FUNC(sub_82190F80);
PPC_FUNC_IMPL(__imp__sub_82190F80) {
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
	// li r3,-1
	ctx.r3.s64 = -1;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// stw r3,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// bge cr6,0x82190fe4
	if (!ctx.cr6.lt) goto loc_82190FE4;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82088f70
	ctx.lr = 0x82190FB4;
	sub_82088F70(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82190fcc
	if (!ctx.cr6.eq) goto loc_82190FCC;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// b 0x82190fe0
	goto loc_82190FE0;
loc_82190FCC:
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,48
	ctx.r4.s64 = ctx.r31.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82088f68
	ctx.lr = 0x82190FE0;
	sub_82088F68(ctx, base);
loc_82190FE0:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
loc_82190FE4:
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

__attribute__((alias("__imp__sub_82190FFC"))) PPC_WEAK_FUNC(sub_82190FFC);
PPC_FUNC_IMPL(__imp__sub_82190FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191000"))) PPC_WEAK_FUNC(sub_82191000);
PPC_FUNC_IMPL(__imp__sub_82191000) {
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
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x821910b0
	if (ctx.cr6.gt) goto loc_821910B0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821910ac
	if (ctx.cr6.eq) goto loc_821910AC;
	// bdz 0x821910b0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_821910B0;
	// bdz 0x82191044
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82191044;
	// bdz 0x8219105c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8219105C;
	// b 0x82191084
	goto loc_82191084;
loc_82191044:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82089478
	ctx.lr = 0x82191050;
	sub_82089478(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// b 0x821910b0
	goto loc_821910B0;
loc_8219105C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x821910b0
	if (ctx.cr6.eq) goto loc_821910B0;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// b 0x821910b0
	goto loc_821910B0;
loc_82191084:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x821910b0
	if (!ctx.cr6.eq) goto loc_821910B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x82190f80
	ctx.lr = 0x821910AC;
	sub_82190F80(ctx, base);
loc_821910AC:
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
loc_821910B0:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x821d51a4
	ctx.lr = 0x821910C4;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821910e0
	if (ctx.cr6.eq) goto loc_821910E0;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r30.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bl 0x82190658
	ctx.lr = 0x821910E0;
	sub_82190658(ctx, base);
loc_821910E0:
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

__attribute__((alias("__imp__sub_821910F8"))) PPC_WEAK_FUNC(sub_821910F8);
PPC_FUNC_IMPL(__imp__sub_821910F8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191108"))) PPC_WEAK_FUNC(sub_82191108);
PPC_FUNC_IMPL(__imp__sub_82191108) {
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
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,4180
	ctx.r9.s64 = ctx.r10.s64 + 4180;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r8,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r8.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// bl 0x82190658
	ctx.lr = 0x8219114C;
	sub_82190658(ctx, base);
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

__attribute__((alias("__imp__sub_82191164"))) PPC_WEAK_FUNC(sub_82191164);
PPC_FUNC_IMPL(__imp__sub_82191164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191168"))) PPC_WEAK_FUNC(sub_82191168);
PPC_FUNC_IMPL(__imp__sub_82191168) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r10,4168
	ctx.r8.s64 = ctx.r10.s64 + 4168;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r11,-32212(r9)
	PPC_STORE_U8(ctx.r9.u32 + -32212, ctx.r11.u8);
	// bl 0x82088d00
	ctx.lr = 0x8219119C;
	sub_82088D00(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82088d00
	ctx.lr = 0x821911A4;
	sub_82088D00(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x82088d00
	ctx.lr = 0x821911AC;
	sub_82088D00(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r6,r7,-1456
	ctx.r6.s64 = ctx.r7.s64 + -1456;
	// stw r6,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_821911CC"))) PPC_WEAK_FUNC(sub_821911CC);
PPC_FUNC_IMPL(__imp__sub_821911CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821911D0"))) PPC_WEAK_FUNC(sub_821911D0);
PPC_FUNC_IMPL(__imp__sub_821911D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821911D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// bl 0x82157ae8
	ctx.lr = 0x821911E8;
	sub_82157AE8(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r31,r11,-31359
	ctx.r31.s64 = ctx.r11.s64 + -31359;
	// lbz r11,-853(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -853);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82191318
	if (!ctx.cr6.eq) goto loc_82191318;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
loc_82191204:
	// lwz r11,-31352(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,76(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821912f0
	if (ctx.cr6.eq) goto loc_821912F0;
	// lwz r10,40(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bge cr6,0x821912f0
	if (!ctx.cr6.lt) goto loc_821912F0;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,40(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8219123c
	if (!ctx.cr6.eq) goto loc_8219123C;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
loc_8219123C:
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x821912f0
	if (!ctx.cr6.lt) goto loc_821912F0;
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x821912f0
	if (!ctx.cr6.eq) goto loc_821912F0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82157be0
	ctx.lr = 0x82191268;
	sub_82157BE0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821912f0
	if (!ctx.cr6.eq) goto loc_821912F0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821912f0
	if (ctx.cr6.eq) goto loc_821912F0;
	// lbz r11,-853(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -853);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821912e0
	if (!ctx.cr6.eq) goto loc_821912E0;
loc_82191288:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,8000
	ctx.r6.s64 = 8000;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82157b00
	ctx.lr = 0x821912A0;
	sub_82157B00(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82157af8
	ctx.lr = 0x821912AC;
	sub_82157AF8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r28,258
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 258, ctx.xer);
	// beq cr6,0x821912e0
	if (ctx.cr6.eq) goto loc_821912E0;
	// lbz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821912d8
	if (!ctx.cr6.eq) goto loc_821912D8;
	// lbz r11,-853(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -853);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82191288
	if (ctx.cr6.eq) goto loc_82191288;
	// b 0x821912e0
	goto loc_821912E0;
loc_821912D8:
	// rlwinm r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
loc_821912E0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821912f0
	if (ctx.cr6.eq) goto loc_821912F0;
	// bl 0x82157bf8
	ctx.lr = 0x821912EC;
	sub_82157BF8(ctx, base);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
loc_821912F0:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// li r12,4983
	ctx.r12.s64 = 4983;
	// subfic r9,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r8,r12
	ctx.r11.u64 = ctx.r8.u64 & ctx.r12.u64;
	// addi r3,r11,17
	ctx.r3.s64 = ctx.r11.s64 + 17;
	// bl 0x82089e08
	ctx.lr = 0x8219130C;
	sub_82089E08(ctx, base);
	// lbz r7,-853(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + -853);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82191204
	if (ctx.cr6.eq) goto loc_82191204;
loc_82191318:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191328
	if (ctx.cr6.eq) goto loc_82191328;
	// bl 0x82157bf8
	ctx.lr = 0x82191328;
	sub_82157BF8(ctx, base);
loc_82191328:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82157af0
	ctx.lr = 0x82191330;
	sub_82157AF0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8219133C"))) PPC_WEAK_FUNC(sub_8219133C);
PPC_FUNC_IMPL(__imp__sub_8219133C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191340"))) PPC_WEAK_FUNC(sub_82191340);
PPC_FUNC_IMPL(__imp__sub_82191340) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82191348;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,588(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 588);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r31,r3,64
	ctx.r31.s64 = ctx.r3.s64 + 64;
	// stw r25,588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 588, ctx.r25.u32);
	// mr r30,r25
	ctx.r30.u64 = ctx.r25.u64;
	// li r26,28
	ctx.r26.s64 = 28;
	// stw r11,592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 592, ctx.r11.u32);
	// li r27,29
	ctx.r27.s64 = 29;
	// li r29,27
	ctx.r29.s64 = 27;
loc_82191374:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x821905a0
	ctx.lr = 0x82191380;
	sub_821905A0(ctx, base);
	// lwz r11,-8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821913cc
	if (ctx.cr6.eq) goto loc_821913CC;
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// addic. r3,r31,112
	ctx.xer.ca = ctx.r31.u32 > 4294967183;
	ctx.r3.s64 = ctx.r31.s64 + 112;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bne 0x821913a4
	if (!ctx.cr0.eq) goto loc_821913A4;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// b 0x821913a8
	goto loc_821913A8;
loc_821913A4:
	// bl 0x82190b38
	ctx.lr = 0x821913A8;
	sub_82190B38(ctx, base);
loc_821913A8:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r3,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r3.u32);
	// xor r10,r11,r3
	ctx.r10.u64 = ctx.r11.u64 ^ ctx.r3.u64;
	// and r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 & ctx.r3.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// lwz r8,588(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 588);
	// or r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stw r7,588(r28)
	PPC_STORE_U32(ctx.r28.u32 + 588, ctx.r7.u32);
loc_821913CC:
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82089dc8
	ctx.lr = 0x821913E0;
	sub_82089DC8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82191458
	if (!ctx.cr6.eq) goto loc_82191458;
	// lhz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82191458
	if (ctx.cr6.eq) goto loc_82191458;
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82191458
	if (!ctx.cr6.eq) goto loc_82191458;
	// lhz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,65
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 65, ctx.xer);
	// blt cr6,0x82191424
	if (ctx.cr6.lt) goto loc_82191424;
	// cmplwi cr6,r11,90
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 90, ctx.xer);
	// bgt cr6,0x82191424
	if (ctx.cr6.gt) goto loc_82191424;
	// addi r11,r11,-64
	ctx.r11.s64 = ctx.r11.s64 + -64;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// b 0x82191458
	goto loc_82191458;
loc_82191424:
	// cmplwi cr6,r11,110
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 110, ctx.xer);
	// beq cr6,0x82191454
	if (ctx.cr6.eq) goto loc_82191454;
	// cmplwi cr6,r11,190
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 190, ctx.xer);
	// beq cr6,0x82191454
	if (ctx.cr6.eq) goto loc_82191454;
	// cmplwi cr6,r11,13
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 13, ctx.xer);
	// bne cr6,0x82191444
	if (!ctx.cr6.eq) goto loc_82191444;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// b 0x82191458
	goto loc_82191458;
loc_82191444:
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bne cr6,0x82191458
	if (!ctx.cr6.eq) goto loc_82191458;
	// stw r27,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r27.u32);
	// b 0x82191458
	goto loc_82191458;
loc_82191454:
	// stw r29,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r29.u32);
loc_82191458:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r31,r31,132
	ctx.r31.s64 = ctx.r31.s64 + 132;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x82191374
	if (ctx.cr6.lt) goto loc_82191374;
	// lwz r11,588(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 588);
	// addi r8,r28,56
	ctx.r8.s64 = ctx.r28.s64 + 56;
	// lwz r10,592(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 592);
	// li r7,5
	ctx.r7.s64 = 5;
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// and r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 & ctx.r11.u64;
	// stw r6,596(r28)
	PPC_STORE_U32(ctx.r28.u32 + 596, ctx.r6.u32);
	// stw r6,600(r28)
	PPC_STORE_U32(ctx.r28.u32 + 600, ctx.r6.u32);
loc_82191488:
	// li r9,24
	ctx.r9.s64 = 24;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r8,20
	ctx.r11.s64 = ctx.r8.s64 + 20;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82191498:
	// lwz r9,44(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 44);
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82191514
	if (ctx.cr6.eq) goto loc_82191514;
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x821914c4
	if (ctx.cr6.eq) goto loc_821914C4;
	// lwz r9,48(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 48);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// b 0x82191514
	goto loc_82191514;
loc_821914C4:
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// and r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82191510
	if (ctx.cr6.eq) goto loc_82191510;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x821914e8
	if (!ctx.cr6.eq) goto loc_821914E8;
	// lwz r9,48(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 48);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_821914E8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// bne 0x82191514
	if (!ctx.cr0.eq) goto loc_82191514;
	// lwz r9,52(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 52);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// lwz r6,16(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// stw r5,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r5.u32);
	// b 0x82191514
	goto loc_82191514;
loc_82191510:
	// stw r25,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
loc_82191514:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// bdnz 0x82191498
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82191498;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,132
	ctx.r8.s64 = ctx.r8.s64 + 132;
	// bne 0x82191488
	if (!ctx.cr0.eq) goto loc_82191488;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x821d51a4
	ctx.lr = 0x82191540;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82191554
	if (!ctx.cr6.eq) goto loc_82191554;
	// lwz r11,32(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821915b8
	if (ctx.cr6.eq) goto loc_821915B8;
loc_82191554:
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// stw r25,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r25.u32);
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// li r30,1
	ctx.r30.s64 = 1;
loc_82191564:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82089db8
	ctx.lr = 0x82191570;
	sub_82089DB8(ctx, base);
	// cmplwi cr6,r3,1167
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1167, ctx.xer);
	// beq cr6,0x8219157c
	if (ctx.cr6.eq) goto loc_8219157C;
	// or r29,r30,r29
	ctx.r29.u64 = ctx.r30.u64 | ctx.r29.u64;
loc_8219157C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// rotlwi r30,r30,1
	ctx.r30.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x82191564
	if (ctx.cr6.lt) goto loc_82191564;
	// lwz r11,28(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// stw r29,28(r28)
	PPC_STORE_U32(ctx.r28.u32 + 28, ctx.r29.u32);
	// xor r10,r11,r29
	ctx.r10.u64 = ctx.r11.u64 ^ ctx.r29.u64;
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r9.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x821915b4
	if (ctx.cr6.eq) goto loc_821915B4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
loc_821915B4:
	// stw r25,32(r28)
	PPC_STORE_U32(ctx.r28.u32 + 32, ctx.r25.u32);
loc_821915B8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821915C0"))) PPC_WEAK_FUNC(sub_821915C0);
PPC_FUNC_IMPL(__imp__sub_821915C0) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x82191620
	if (ctx.cr6.lt) goto loc_82191620;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x82191620
	if (!ctx.cr6.lt) goto loc_82191620;
	// bl 0x821905a0
	ctx.lr = 0x821915F0;
	sub_821905A0(ctx, base);
	// mulli r11,r31,132
	ctx.r11.s64 = ctx.r31.s64 * 132;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addic. r3,r11,176
	ctx.xer.ca = ctx.r11.u32 > 4294967119;
	ctx.r3.s64 = ctx.r11.s64 + 176;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x82191610
	if (!ctx.cr0.eq) goto loc_82191610;
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r3,r3,8
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFFFF;
	// rlwinm r3,r3,0,20,17
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// b 0x82191624
	goto loc_82191624;
loc_82191610:
	// bl 0x82190b38
	ctx.lr = 0x82191614;
	sub_82190B38(ctx, base);
	// clrlwi r3,r3,8
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFFFF;
	// rlwinm r3,r3,0,20,17
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// b 0x82191624
	goto loc_82191624;
loc_82191620:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82191624:
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

__attribute__((alias("__imp__sub_8219163C"))) PPC_WEAK_FUNC(sub_8219163C);
PPC_FUNC_IMPL(__imp__sub_8219163C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191640"))) PPC_WEAK_FUNC(sub_82191640);
PPC_FUNC_IMPL(__imp__sub_82191640) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82191648;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,4168
	ctx.r10.s64 = ctx.r11.s64 + 4168;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stb r30,12(r31)
	PPC_STORE_U8(ctx.r31.u32 + 12, ctx.r30.u8);
	// stw r30,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// bl 0x82089e10
	ctx.lr = 0x8219167C;
	sub_82089E10(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82089e10
	ctx.lr = 0x82191688;
	sub_82089E10(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82089e10
	ctx.lr = 0x82191694;
	sub_82089E10(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// addi r29,r31,44
	ctx.r29.s64 = ctx.r31.s64 + 44;
	// stw r30,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8215a928
	ctx.lr = 0x821916B0;
	sub_8215A928(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821916bc
	if (ctx.cr6.eq) goto loc_821916BC;
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
loc_821916BC:
	// bl 0x82157c08
	ctx.lr = 0x821916C0;
	sub_82157C08(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// lis r9,-32231
	ctx.r9.s64 = -2112290816;
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r30,-32212(r11)
	PPC_STORE_U8(ctx.r11.u32 + -32212, ctx.r30.u8);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r9,4560
	ctx.r5.s64 = ctx.r9.s64 + 4560;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088d88
	ctx.lr = 0x821916F0;
	sub_82088D88(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82191700"))) PPC_WEAK_FUNC(sub_82191700);
PPC_FUNC_IMPL(__imp__sub_82191700) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82191708;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,4216
	ctx.r10.s64 = ctx.r11.s64 + 4216;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82191750
	if (ctx.cr6.eq) goto loc_82191750;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82191738;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_82191750:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191780
	if (ctx.cr6.eq) goto loc_82191780;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82191768;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_82191780:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821917b0
	if (ctx.cr6.eq) goto loc_821917B0;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x82191798;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_821917B0:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821917e0
	if (ctx.cr6.eq) goto loc_821917E0;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// addi r4,r11,6640
	ctx.r4.s64 = ctx.r11.s64 + 6640;
	// bl 0x820735c8
	ctx.lr = 0x821917C8;
	sub_820735C8(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_821917E0:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821917F4;
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
	ctx.lr = 0x8219180C;
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

__attribute__((alias("__imp__sub_8219181C"))) PPC_WEAK_FUNC(sub_8219181C);
PPC_FUNC_IMPL(__imp__sub_8219181C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191820"))) PPC_WEAK_FUNC(sub_82191820);
PPC_FUNC_IMPL(__imp__sub_82191820) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82191828;
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r29,r3,44
	ctx.r29.s64 = ctx.r3.s64 + 44;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// addi r7,r10,-1396
	ctx.r7.s64 = ctx.r10.s64 + -1396;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r11,r29,16
	ctx.r11.s64 = ctx.r29.s64 + 16;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r6,r9,840
	ctx.r6.s64 = ctx.r9.s64 + 840;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r5,r8,4216
	ctx.r5.s64 = ctx.r8.s64 + 4216;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// li r3,60
	ctx.r3.s64 = 60;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
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
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// stb r10,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r10.u8);
	// stb r10,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r10.u8);
	// bl 0x82079fd8
	ctx.lr = 0x821918BC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821918d0
	if (ctx.cr6.eq) goto loc_821918D0;
	// bl 0x82191640
	ctx.lr = 0x821918C8;
	sub_82191640(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821918d4
	goto loc_821918D4;
loc_821918D0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821918D4:
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82079fd8
	ctx.lr = 0x821918E0;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191924
	if (ctx.cr6.eq) goto loc_82191924;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r8,r10,4180
	ctx.r8.s64 = ctx.r10.s64 + 4180;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r30,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r30.u32);
	// bl 0x82190658
	ctx.lr = 0x82191920;
	sub_82190658(ctx, base);
	// b 0x82191928
	goto loc_82191928;
loc_82191924:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
loc_82191928:
	// stw r28,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r28.u32);
	// li r3,716
	ctx.r3.s64 = 716;
	// bl 0x82079fd8
	ctx.lr = 0x82191934;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191950
	if (ctx.cr6.eq) goto loc_82191950;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x82190ef0
	ctx.lr = 0x82191948;
	sub_82190EF0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82191954
	goto loc_82191954;
loc_82191950:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82191954:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82079fd8
	ctx.lr = 0x82191960;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821919b0
	if (ctx.cr6.eq) goto loc_821919B0;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r11,r3,72
	ctx.r11.s64 = ctx.r3.s64 + 72;
	// addi r7,r8,4204
	ctx.r7.s64 = ctx.r8.s64 + 4204;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r6,16(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r30.u32);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// stw r30,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r30.u32);
	// stw r30,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r30.u32);
	// stw r30,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r30.u32);
	// stw r30,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r30.u32);
	// stw r30,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// b 0x821919b4
	goto loc_821919B4;
loc_821919B0:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821919B4:
	// stw r10,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r7,20(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// lwz r11,84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82191A24"))) PPC_WEAK_FUNC(sub_82191A24);
PPC_FUNC_IMPL(__imp__sub_82191A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191A28"))) PPC_WEAK_FUNC(sub_82191A28);
PPC_FUNC_IMPL(__imp__sub_82191A28) {
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
	// lwz r11,172(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82191a80
	if (ctx.cr6.eq) goto loc_82191A80;
	// lwz r11,176(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82191a80
	if (!ctx.cr6.eq) goto loc_82191A80;
	// lbz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 180);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82191a80
	if (!ctx.cr6.eq) goto loc_82191A80;
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x82088370
	ctx.lr = 0x82191A70;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82191a80
	if (ctx.cr6.eq) goto loc_82191A80;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,180(r31)
	PPC_STORE_U8(ctx.r31.u32 + 180, ctx.r11.u8);
loc_82191A80:
	// lbz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 180);
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

__attribute__((alias("__imp__sub_82191A98"))) PPC_WEAK_FUNC(sub_82191A98);
PPC_FUNC_IMPL(__imp__sub_82191A98) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191A9C"))) PPC_WEAK_FUNC(sub_82191A9C);
PPC_FUNC_IMPL(__imp__sub_82191A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191AA0"))) PPC_WEAK_FUNC(sub_82191AA0);
PPC_FUNC_IMPL(__imp__sub_82191AA0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82191a28
	sub_82191A28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82191AA4"))) PPC_WEAK_FUNC(sub_82191AA4);
PPC_FUNC_IMPL(__imp__sub_82191AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191AA8"))) PPC_WEAK_FUNC(sub_82191AA8);
PPC_FUNC_IMPL(__imp__sub_82191AA8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32231
	ctx.r11.s64 = -2112290816;
	// stw r4,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r4.u32);
	// addi r10,r11,6808
	ctx.r10.s64 = ctx.r11.s64 + 6808;
	// stw r10,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191ABC"))) PPC_WEAK_FUNC(sub_82191ABC);
PPC_FUNC_IMPL(__imp__sub_82191ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82191AC0"))) PPC_WEAK_FUNC(sub_82191AC0);
PPC_FUNC_IMPL(__imp__sub_82191AC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,188(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82191AC8"))) PPC_WEAK_FUNC(sub_82191AC8);
PPC_FUNC_IMPL(__imp__sub_82191AC8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// lwz r11,192(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// addi r9,r10,6816
	ctx.r9.s64 = ctx.r10.s64 + 6816;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82191af0
	if (ctx.cr6.eq) goto loc_82191AF0;
	// lis r10,-32231
	ctx.r10.s64 = -2112290816;
	// addi r9,r10,6808
	ctx.r9.s64 = ctx.r10.s64 + 6808;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x82191af4
	if (!ctx.cr6.eq) goto loc_82191AF4;
loc_82191AF0:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82191AF4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

