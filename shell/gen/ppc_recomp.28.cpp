#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82174E24"))) PPC_WEAK_FUNC(sub_82174E24);
PPC_FUNC_IMPL(__imp__sub_82174E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82174E28"))) PPC_WEAK_FUNC(sub_82174E28);
PPC_FUNC_IMPL(__imp__sub_82174E28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 29, ctx.xer);
	// beq cr6,0x82174e74
	if (ctx.cr6.eq) goto loc_82174E74;
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bne cr6,0x82174e74
	if (!ctx.cr6.eq) goto loc_82174E74;
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
loc_82174E74:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174E80"))) PPC_WEAK_FUNC(sub_82174E80);
PPC_FUNC_IMPL(__imp__sub_82174E80) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r11,r11,-9
	ctx.r11.s64 = ctx.r11.s64 + -9;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82174ff4
	if (ctx.cr6.gt) goto loc_82174FF4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82174ee0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174EE0;
	// bdzf 4*cr6+eq,0x82174f30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82174F30;
	// bne cr6,0x82174f8c
	if (!ctx.cr6.eq) goto loc_82174F8C;
	// lbz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r10,3(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// lbz r7,5(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
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
loc_82174EE0:
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lbz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r8,3(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r7,r10,8
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 8);
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// lbz r5,2(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// or r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 | ctx.r8.u64;
	// lbz r11,5(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// rlwinm r10,r6,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r8,r4,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// or r6,r8,r5
	ctx.r6.u64 = ctx.r8.u64 | ctx.r5.u64;
	// or r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 | ctx.r11.u64;
	// rlwinm r4,r6,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// rldicr r3,r5,32,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r4,r3
	ctx.r11.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 | ctx.r9.u64;
	// blr 
	return;
loc_82174F30:
	// lbz r10,7(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lbz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// lbz r9,6(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r6,3(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r11,r7,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// rlwinm r5,r8,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// or r7,r11,r6
	ctx.r7.u64 = ctx.r11.u64 | ctx.r6.u64;
	// lbz r4,5(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// lbz r8,1(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r5,r7,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r5,r10
	ctx.r11.u64 = ctx.r5.u64 | ctx.r10.u64;
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// rldicr r7,r10,32,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// or r3,r6,r8
	ctx.r3.u64 = ctx.r6.u64 | ctx.r8.u64;
	// blr 
	return;
loc_82174F8C:
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lbz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// lbz r9,7(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// lbz r4,3(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r11,r6,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// rlwinm r5,r8,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r7,6(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// or r6,r11,r4
	ctx.r6.u64 = ctx.r11.u64 | ctx.r4.u64;
	// lbz r8,2(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// lbz r10,5(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r3,r6,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r4,r9,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r3,r8
	ctx.r9.u64 = ctx.r3.u64 | ctx.r8.u64;
	// or r11,r4,r7
	ctx.r11.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// or r4,r6,r10
	ctx.r4.u64 = ctx.r6.u64 | ctx.r10.u64;
	// rldicr r3,r4,32,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 | ctx.r7.u64;
	// or r3,r11,r5
	ctx.r3.u64 = ctx.r11.u64 | ctx.r5.u64;
	// blr 
	return;
loc_82174FF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82174FFC"))) PPC_WEAK_FUNC(sub_82174FFC);
PPC_FUNC_IMPL(__imp__sub_82174FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175000"))) PPC_WEAK_FUNC(sub_82175000);
PPC_FUNC_IMPL(__imp__sub_82175000) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,7(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// lbz r8,3(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// extsb r9,r11
	ctx.r9.s64 = ctx.r11.s8;
	// lbz r10,6(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// lbz r5,2(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// rotlwi r4,r8,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 8);
	// rlwinm r6,r9,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r7,5(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// or r8,r4,r5
	ctx.r8.u64 = ctx.r4.u64 | ctx.r5.u64;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// or r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 | ctx.r10.u64;
	// lbz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r4,r8,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r5,r10,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
	// or r3,r5,r7
	ctx.r3.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r10,r3,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r8,r6
	ctx.r6.u64 = ctx.r8.u64 | ctx.r6.u64;
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// or r5,r7,r9
	ctx.r5.u64 = ctx.r7.u64 | ctx.r9.u64;
	// rldicr r4,r5,32,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF00000000;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// std r3,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r3.u64);
	// lfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217506C"))) PPC_WEAK_FUNC(sub_8217506C);
PPC_FUNC_IMPL(__imp__sub_8217506C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175070"))) PPC_WEAK_FUNC(sub_82175070);
PPC_FUNC_IMPL(__imp__sub_82175070) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82175078;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,36(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175094;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x821750D0;
	sub_82174818(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821750D8"))) PPC_WEAK_FUNC(sub_821750D8);
PPC_FUNC_IMPL(__imp__sub_821750D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821750E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,32(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175100;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217513C;
	sub_82174818(ctx, base);
	// lwz r6,40(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	// add r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 + ctx.r6.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217514C"))) PPC_WEAK_FUNC(sub_8217514C);
PPC_FUNC_IMPL(__imp__sub_8217514C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175150"))) PPC_WEAK_FUNC(sub_82175150);
PPC_FUNC_IMPL(__imp__sub_82175150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82175158;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,24(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175178;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x821751B4;
	sub_82174818(ctx, base);
	// lwz r6,28(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// add r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 + ctx.r6.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821751C4"))) PPC_WEAK_FUNC(sub_821751C4);
PPC_FUNC_IMPL(__imp__sub_821751C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821751C8"))) PPC_WEAK_FUNC(sub_821751C8);
PPC_FUNC_IMPL(__imp__sub_821751C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821751D0;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x821752bc
	if (!ctx.cr6.eq) goto loc_821752BC;
	// lwz r31,16(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175200;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// beq cr6,0x821752a0
	if (ctx.cr6.eq) goto loc_821752A0;
loc_8217523C:
	// add r11,r27,r26
	ctx.r11.u64 = ctx.r27.u64 + ctx.r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r31,r11,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82174818
	ctx.lr = 0x82175250;
	sub_82174818(ctx, base);
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
loc_8217525C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82175280
	if (ctx.cr6.eq) goto loc_82175280;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8217525c
	if (ctx.cr6.eq) goto loc_8217525C;
loc_82175280:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821752ac
	if (ctx.cr6.eq) goto loc_821752AC;
	// ble cr6,0x82175294
	if (!ctx.cr6.gt) goto loc_82175294;
	// addi r26,r31,1
	ctx.r26.s64 = ctx.r31.s64 + 1;
	// b 0x82175298
	goto loc_82175298;
loc_82175294:
	// mr r27,r31
	ctx.r27.u64 = ctx.r31.u64;
loc_82175298:
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// blt cr6,0x8217523c
	if (ctx.cr6.lt) goto loc_8217523C;
loc_821752A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_821752AC:
	// stw r31,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_821752BC:
	// lwz r31,20(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821752D4;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lbzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// add r31,r31,r11
	ctx.r31.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r30,r10,-11
	ctx.r30.s64 = ctx.r10.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175314;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// lbz r31,0(r28)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x82175354;
	sub_82174818(ctx, base);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r31,r3,r31
	ctx.r31.u64 = ctx.r3.u64 + ctx.r31.u64;
	// cmplw cr6,r31,r5
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r5.u32, ctx.xer);
	// bge cr6,0x821752a0
	if (!ctx.cr6.lt) goto loc_821752A0;
loc_82175364:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82174818
	ctx.lr = 0x82175370;
	sub_82174818(ctx, base);
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x821752a0
	if (!ctx.cr6.eq) goto loc_821752A0;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821753b4
	if (ctx.cr6.eq) goto loc_821753B4;
	// lbzu r30,1(r28)
	ea = 1 + ctx.r28.u32;
	ctx.r30.u64 = PPC_LOAD_U8(ea);
	ctx.r28.u32 = ea;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// bl 0x82174818
	ctx.lr = 0x82175398;
	sub_82174818(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r31,r3,r30
	ctx.r31.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82175364
	if (ctx.cr6.lt) goto loc_82175364;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_821753B4:
	// bl 0x82174818
	ctx.lr = 0x821753B8;
	sub_82174818(ctx, base);
	// stw r3,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821753C8"))) PPC_WEAK_FUNC(sub_821753C8);
PPC_FUNC_IMPL(__imp__sub_821753C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821753D0;
	__savegprlr_24(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x821754e4
	if (!ctx.cr6.eq) goto loc_821754E4;
	// bl 0x821751c8
	ctx.lr = 0x821753F4;
	sub_821751C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217540c
	if (!ctx.cr6.eq) goto loc_8217540C;
loc_82175400:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8217540C:
	// lwz r29,4(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175424;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x82175400
	if (ctx.cr6.eq) goto loc_82175400;
	// lwz r25,80(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8217546C:
	// add r11,r28,r26
	ctx.r11.u64 = ctx.r28.u64 + ctx.r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rlwinm r30,r11,31,1,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82174818
	ctx.lr = 0x82175480;
	sub_82174818(ctx, base);
	// add r31,r3,r29
	ctx.r31.u64 = ctx.r3.u64 + ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82174a60
	ctx.lr = 0x8217548C;
	sub_82174A60(ctx, base);
	// cmplw cr6,r3,r25
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x821754b8
	if (ctx.cr6.eq) goto loc_821754B8;
	// bge cr6,0x821754a0
	if (!ctx.cr6.lt) goto loc_821754A0;
	// addi r26,r30,1
	ctx.r26.s64 = ctx.r30.s64 + 1;
	// b 0x821754a4
	goto loc_821754A4;
loc_821754A0:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
loc_821754A4:
	// cmplw cr6,r26,r28
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8217546c
	if (ctx.cr6.lt) goto loc_8217546C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_821754B8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82173f78
	ctx.lr = 0x821754C0;
	sub_82173F78(ctx, base);
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// add r10,r3,r31
	ctx.r10.u64 = ctx.r3.u64 + ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,0(r24)
	PPC_STORE_U64(ctx.r24.u32 + 0, ctx.r9.u64);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_821754E4:
	// bl 0x821751c8
	ctx.lr = 0x821754E8;
	sub_821751C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82175400
	if (ctx.cr6.eq) goto loc_82175400;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217550C;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// beq cr6,0x82175400
	if (ctx.cr6.eq) goto loc_82175400;
	// lwz r30,80(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8217554C:
	// add r11,r31,r28
	ctx.r11.u64 = ctx.r31.u64 + ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rlwinm r29,r11,31,1,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82174818
	ctx.lr = 0x82175560;
	sub_82174818(ctx, base);
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8217558c
	if (ctx.cr6.eq) goto loc_8217558C;
	// bge cr6,0x82175574
	if (!ctx.cr6.lt) goto loc_82175574;
	// addi r28,r29,1
	ctx.r28.s64 = ctx.r29.s64 + 1;
	// b 0x82175578
	goto loc_82175578;
loc_82175574:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82175578:
	// cmplw cr6,r28,r31
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x8217554c
	if (ctx.cr6.lt) goto loc_8217554C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8217558C:
	// cmplw cr6,r28,r31
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x82175400
	if (!ctx.cr6.lt) goto loc_82175400;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r28,96(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821755B4;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x821755F0;
	sub_82174818(ctx, base);
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,0(r24)
	PPC_STORE_U64(ctx.r24.u32 + 0, ctx.r4.u64);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82175628"))) PPC_WEAK_FUNC(sub_82175628);
PPC_FUNC_IMPL(__imp__sub_82175628) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217563c
	if (ctx.cr6.lt) goto loc_8217563C;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x82175640
	goto loc_82175640;
loc_8217563C:
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
loc_82175640:
	// b 0x821753c8
	sub_821753C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82175644"))) PPC_WEAK_FUNC(sub_82175644);
PPC_FUNC_IMPL(__imp__sub_82175644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175648"))) PPC_WEAK_FUNC(sub_82175648);
PPC_FUNC_IMPL(__imp__sub_82175648) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82175650;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175678;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x821756B4;
	sub_82174818(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// add r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r5.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821756E0"))) PPC_WEAK_FUNC(sub_821756E0);
PPC_FUNC_IMPL(__imp__sub_821756E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// b 0x82174af8
	sub_82174AF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821756EC"))) PPC_WEAK_FUNC(sub_821756EC);
PPC_FUNC_IMPL(__imp__sub_821756EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821756F0"))) PPC_WEAK_FUNC(sub_821756F0);
PPC_FUNC_IMPL(__imp__sub_821756F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821756F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174930
	ctx.lr = 0x82175708;
	sub_82174930(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r31,36(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175724;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x82175760;
	sub_82174818(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82175768"))) PPC_WEAK_FUNC(sub_82175768);
PPC_FUNC_IMPL(__imp__sub_82175768) {
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
	// bl 0x82174930
	ctx.lr = 0x82175784;
	sub_82174930(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x821750d8
	ctx.lr = 0x82175790;
	sub_821750D8(ctx, base);
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

__attribute__((alias("__imp__sub_821757A4"))) PPC_WEAK_FUNC(sub_821757A4);
PPC_FUNC_IMPL(__imp__sub_821757A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821757A8"))) PPC_WEAK_FUNC(sub_821757A8);
PPC_FUNC_IMPL(__imp__sub_821757A8) {
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
	// bl 0x821749c8
	ctx.lr = 0x821757C4;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x821757D0;
	sub_82175150(ctx, base);
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

__attribute__((alias("__imp__sub_821757E4"))) PPC_WEAK_FUNC(sub_821757E4);
PPC_FUNC_IMPL(__imp__sub_821757E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821757E8"))) PPC_WEAK_FUNC(sub_821757E8);
PPC_FUNC_IMPL(__imp__sub_821757E8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 31, ctx.xer);
	// beq cr6,0x82175804
	if (ctx.cr6.eq) goto loc_82175804;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// lfd f1,88(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + 88);
	// blr 
	return;
loc_82175804:
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// lbz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// extsb r8,r10
	ctx.r8.s64 = ctx.r10.s8;
	// lbz r9,7(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// lbz r4,3(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3);
	// rotlwi r11,r7,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 8);
	// rlwinm r5,r8,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,6(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// or r7,r11,r4
	ctx.r7.u64 = ctx.r11.u64 | ctx.r4.u64;
	// lbz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// lbz r8,5(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rlwinm r3,r7,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r4,r9,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 | ctx.r10.u64;
	// or r11,r4,r6
	ctx.r11.u64 = ctx.r4.u64 | ctx.r6.u64;
	// rlwinm r7,r10,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// or r4,r6,r8
	ctx.r4.u64 = ctx.r6.u64 | ctx.r8.u64;
	// rldicr r3,r4,32,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000;
	// or r11,r3,r5
	ctx.r11.u64 = ctx.r3.u64 | ctx.r5.u64;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82175874"))) PPC_WEAK_FUNC(sub_82175874);
PPC_FUNC_IMPL(__imp__sub_82175874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175878"))) PPC_WEAK_FUNC(sub_82175878);
PPC_FUNC_IMPL(__imp__sub_82175878) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82175880;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82175908
	if (!ctx.cr6.eq) goto loc_82175908;
	// lwz r30,16(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r29,r11,-11
	ctx.r29.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821758B0;
	sub_82174AF8(ctx, base);
	// add r10,r29,r30
	ctx.r10.u64 = ctx.r29.u64 + ctx.r30.u64;
	// lbzx r9,r29,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x821758EC;
	sub_82174818(ctx, base);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r4,r3,r6
	ctx.r4.u64 = ctx.r3.u64 + ctx.r6.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82060190
	ctx.lr = 0x821758FC;
	sub_82060190(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_82175908:
	// lwz r31,20(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217591C;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// add r29,r31,r30
	ctx.r29.u64 = ctx.r31.u64 + ctx.r30.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lbzx r11,r31,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + ctx.r30.u32);
	// addi r28,r11,-11
	ctx.r28.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217595C;
	sub_82174AF8(ctx, base);
	// add r11,r28,r29
	ctx.r11.u64 = ctx.r28.u64 + ctx.r29.u64;
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r29.u32);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r31,r11,r30
	ctx.r31.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbzx r11,r11,r30
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r30.u32);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821759A0;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// bl 0x82174818
	ctx.lr = 0x821759DC;
	sub_82174818(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82174818
	ctx.lr = 0x821759E8;
	sub_82174818(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,15
	ctx.r29.s64 = 15;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stb r30,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r30.u8);
	// beq cr6,0x82175a40
	if (ctx.cr6.eq) goto loc_82175A40;
loc_82175A08:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82174818
	ctx.lr = 0x82175A14;
	sub_82174818(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x82174818
	ctx.lr = 0x82175A24;
	sub_82174818(ctx, base);
	// subf r11,r3,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r3.s64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// bl 0x82073510
	ctx.lr = 0x82175A34;
	sub_82073510(ctx, base);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82175a08
	if (!ctx.cr6.eq) goto loc_82175A08;
loc_82175A40:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82060b10
	ctx.lr = 0x82175A4C;
	sub_82060B10(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ld r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// bl 0x82060a98
	ctx.lr = 0x82175A64;
	sub_82060A98(ctx, base);
	// ld r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82175aa4
	if (!ctx.cr6.lt) goto loc_82175AA4;
loc_82175A7C:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82175a98
	if (ctx.cr6.eq) goto loc_82175A98;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
loc_82175A98:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82175a7c
	if (ctx.cr6.lt) goto loc_82175A7C;
loc_82175AA4:
	// stw r29,24(r26)
	PPC_STORE_U32(ctx.r26.u32 + 24, ctx.r29.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r30.u8);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820601f8
	ctx.lr = 0x82175AC4;
	sub_820601F8(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82175ad8
	if (ctx.cr6.lt) goto loc_82175AD8;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8207a630
	ctx.lr = 0x82175AD8;
	sub_8207A630(ctx, base);
loc_82175AD8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82175AE4"))) PPC_WEAK_FUNC(sub_82175AE4);
PPC_FUNC_IMPL(__imp__sub_82175AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175AE8"))) PPC_WEAK_FUNC(sub_82175AE8);
PPC_FUNC_IMPL(__imp__sub_82175AE8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x82175B20;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82175b40
	if (!ctx.cr6.eq) goto loc_82175B40;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r11,-20780
	ctx.r3.s64 = ctx.r11.s64 + -20780;
	// bl 0x8207bc98
	ctx.lr = 0x82175B3C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82175B40;
	sub_8207B288(ctx, base);
loc_82175B40:
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

__attribute__((alias("__imp__sub_82175B5C"))) PPC_WEAK_FUNC(sub_82175B5C);
PPC_FUNC_IMPL(__imp__sub_82175B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175B60"))) PPC_WEAK_FUNC(sub_82175B60);
PPC_FUNC_IMPL(__imp__sub_82175B60) {
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
	// lwz r11,24(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82175b88
	if (ctx.cr6.lt) goto loc_82175B88;
	// lwz r5,4(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// b 0x82175b8c
	goto loc_82175B8C;
loc_82175B88:
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
loc_82175B8C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82175ae8
	ctx.lr = 0x82175B94;
	sub_82175AE8(ctx, base);
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

__attribute__((alias("__imp__sub_82175BAC"))) PPC_WEAK_FUNC(sub_82175BAC);
PPC_FUNC_IMPL(__imp__sub_82175BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175BB0"))) PPC_WEAK_FUNC(sub_82175BB0);
PPC_FUNC_IMPL(__imp__sub_82175BB0) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174118
	ctx.lr = 0x82175BCC;
	sub_82174118(ctx, base);
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x82175cd8
	if (ctx.cr6.gt) goto loc_82175CD8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82175c40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175C40;
	// bdzf 4*cr6+eq,0x82175c70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175C70;
	// bdzf 4*cr6+eq,0x82175cd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175CD8;
	// bdzf 4*cr6+eq,0x82175cd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175CD8;
	// bdzf 4*cr6+eq,0x82175cd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175CD8;
	// bdzf 4*cr6+eq,0x82175cd8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175CD8;
	// bdzf 4*cr6+eq,0x82175c9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175C9C;
	// bne cr6,0x82175cb8
	if (!ctx.cr6.eq) goto loc_82175CB8;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x82175c18
	if (!ctx.cr6.eq) goto loc_82175C18;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82175C18:
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
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
loc_82175C40:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174b90
	ctx.lr = 0x82175C48;
	sub_82174B90(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
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
loc_82175C70:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174e80
	ctx.lr = 0x82175C78;
	sub_82174E80(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
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
loc_82175C9C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174e28
	ctx.lr = 0x82175CA4;
	sub_82174E28(ctx, base);
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
loc_82175CB8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x821757e8
	ctx.lr = 0x82175CC0;
	sub_821757E8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
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
loc_82175CD8:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-20856
	ctx.r3.s64 = ctx.r11.s64 + -20856;
	// bl 0x8207bc98
	ctx.lr = 0x82175CE4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82175CE8;
	sub_8207B288(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f1,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f1.f64 = double(temp.f32);
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

__attribute__((alias("__imp__sub_82175D04"))) PPC_WEAK_FUNC(sub_82175D04);
PPC_FUNC_IMPL(__imp__sub_82175D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175D08"))) PPC_WEAK_FUNC(sub_82175D08);
PPC_FUNC_IMPL(__imp__sub_82175D08) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82174118
	ctx.lr = 0x82175D24;
	sub_82174118(ctx, base);
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x82175e14
	if (ctx.cr6.gt) goto loc_82175E14;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82175d88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175D88;
	// bdzf 4*cr6+eq,0x82175da4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175DA4;
	// bdzf 4*cr6+eq,0x82175e14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175E14;
	// bdzf 4*cr6+eq,0x82175e14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175E14;
	// bdzf 4*cr6+eq,0x82175e14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175E14;
	// bdzf 4*cr6+eq,0x82175e14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175E14;
	// bdzf 4*cr6+eq,0x82175dc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175DC4;
	// bne cr6,0x82175dec
	if (!ctx.cr6.eq) goto loc_82175DEC;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x82175d70
	if (!ctx.cr6.eq) goto loc_82175D70;
	// li r11,1
	ctx.r11.s64 = 1;
loc_82175D70:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
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
loc_82175D88:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174b90
	ctx.lr = 0x82175D90;
	sub_82174B90(ctx, base);
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
loc_82175DA4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174e80
	ctx.lr = 0x82175DAC;
	sub_82174E80(ctx, base);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
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
loc_82175DC4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174e28
	ctx.lr = 0x82175DCC;
	sub_82174E28(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
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
loc_82175DEC:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x821757e8
	ctx.lr = 0x82175DF4;
	sub_821757E8(ctx, base);
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
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
loc_82175E14:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-20932
	ctx.r3.s64 = ctx.r11.s64 + -20932;
	// bl 0x8207bc98
	ctx.lr = 0x82175E20;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82175E24;
	sub_8207B288(ctx, base);
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

__attribute__((alias("__imp__sub_82175E3C"))) PPC_WEAK_FUNC(sub_82175E3C);
PPC_FUNC_IMPL(__imp__sub_82175E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175E40"))) PPC_WEAK_FUNC(sub_82175E40);
PPC_FUNC_IMPL(__imp__sub_82175E40) {
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
	// bl 0x82174118
	ctx.lr = 0x82175E5C;
	sub_82174118(ctx, base);
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x82175f84
	if (ctx.cr6.gt) goto loc_82175F84;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82175ebc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175EBC;
	// bdzf 4*cr6+eq,0x82175ee0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175EE0;
	// bdzf 4*cr6+eq,0x82175f84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175F84;
	// bdzf 4*cr6+eq,0x82175f84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175F84;
	// bdzf 4*cr6+eq,0x82175f84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175F84;
	// bdzf 4*cr6+eq,0x82175f84
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175F84;
	// bdzf 4*cr6+eq,0x82175f10
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82175F10;
	// bne cr6,0x82175f48
	if (!ctx.cr6.eq) goto loc_82175F48;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// bne cr6,0x82175f98
	if (!ctx.cr6.eq) goto loc_82175F98;
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
loc_82175EBC:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174b90
	ctx.lr = 0x82175EC4;
	sub_82174B90(ctx, base);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r3,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
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
loc_82175EE0:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174e80
	ctx.lr = 0x82175EE8;
	sub_82174E80(ctx, base);
	// cmpdi cr6,r3,0
	ctx.cr6.compare<int64_t>(ctx.r3.s64, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x82175ef8
	if (!ctx.cr6.eq) goto loc_82175EF8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82175EF8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
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
loc_82175F10:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x82174e28
	ctx.lr = 0x82175F18;
	sub_82174E28(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x82175ef8
	if (!ctx.cr6.eq) goto loc_82175EF8;
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
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82175F48:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x821757e8
	ctx.lr = 0x82175F50;
	sub_821757E8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfd f0,88(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 88);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x82175ef8
	if (!ctx.cr6.eq) goto loc_82175EF8;
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
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82175F84:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-20968
	ctx.r3.s64 = ctx.r11.s64 + -20968;
	// bl 0x8207bc98
	ctx.lr = 0x82175F90;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82175F94;
	sub_8207B288(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82175F98:
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

__attribute__((alias("__imp__sub_82175FAC"))) PPC_WEAK_FUNC(sub_82175FAC);
PPC_FUNC_IMPL(__imp__sub_82175FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82175FB0"))) PPC_WEAK_FUNC(sub_82175FB0);
PPC_FUNC_IMPL(__imp__sub_82175FB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82175FB8;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x8217609c
	if (!ctx.cr6.eq) goto loc_8217609C;
	// lwz r29,4(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r31,r29,1
	ctx.r31.s64 = ctx.r29.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82175FEC;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8217614c
	if (ctx.cr6.eq) goto loc_8217614C;
	// li r29,15
	ctx.r29.s64 = 15;
loc_82176034:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82174818
	ctx.lr = 0x82176040;
	sub_82174818(ctx, base);
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + ctx.r30.u64;
	// bl 0x82174a60
	ctx.lr = 0x82176048;
	sub_82174A60(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x82175878
	ctx.lr = 0x82176058;
	sub_82175878(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8206b268
	ctx.lr = 0x82176064;
	sub_8206B268(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82176078
	if (ctx.cr6.lt) goto loc_82176078;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82176078;
	sub_8207A630(ctx, base);
loc_82176078:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r27.u32);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// stb r27,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r27.u8);
	// blt cr6,0x82176034
	if (ctx.cr6.lt) goto loc_82176034;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217609C:
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821760B4;
	sub_82174AF8(ctx, base);
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r11,r10,-12
	ctx.r11.s64 = ctx.r10.s64 + -12;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mullw r11,r11,r3
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// beq cr6,0x8217614c
	if (ctx.cr6.eq) goto loc_8217614C;
	// li r29,15
	ctx.r29.s64 = 15;
loc_821760F4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82174818
	ctx.lr = 0x82176100;
	sub_82174818(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x82175878
	ctx.lr = 0x82176110;
	sub_82175878(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8206b268
	ctx.lr = 0x8217611C;
	sub_8206B268(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82176130
	if (ctx.cr6.lt) goto loc_82176130;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8207a630
	ctx.lr = 0x82176130;
	sub_8207A630(ctx, base);
loc_82176130:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// stw r27,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r27.u32);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// stb r27,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r27.u8);
	// blt cr6,0x821760f4
	if (ctx.cr6.lt) goto loc_821760F4;
loc_8217614C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82176154"))) PPC_WEAK_FUNC(sub_82176154);
PPC_FUNC_IMPL(__imp__sub_82176154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176158"))) PPC_WEAK_FUNC(sub_82176158);
PPC_FUNC_IMPL(__imp__sub_82176158) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217615C"))) PPC_WEAK_FUNC(sub_8217615C);
PPC_FUNC_IMPL(__imp__sub_8217615C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176160"))) PPC_WEAK_FUNC(sub_82176160);
PPC_FUNC_IMPL(__imp__sub_82176160) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,268(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176168"))) PPC_WEAK_FUNC(sub_82176168);
PPC_FUNC_IMPL(__imp__sub_82176168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,188(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 188, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176170"))) PPC_WEAK_FUNC(sub_82176170);
PPC_FUNC_IMPL(__imp__sub_82176170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,308(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176178"))) PPC_WEAK_FUNC(sub_82176178);
PPC_FUNC_IMPL(__imp__sub_82176178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,180(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176180"))) PPC_WEAK_FUNC(sub_82176180);
PPC_FUNC_IMPL(__imp__sub_82176180) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,176(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176188"))) PPC_WEAK_FUNC(sub_82176188);
PPC_FUNC_IMPL(__imp__sub_82176188) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176194"))) PPC_WEAK_FUNC(sub_82176194);
PPC_FUNC_IMPL(__imp__sub_82176194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176198"))) PPC_WEAK_FUNC(sub_82176198);
PPC_FUNC_IMPL(__imp__sub_82176198) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 236);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821761A0"))) PPC_WEAK_FUNC(sub_821761A0);
PPC_FUNC_IMPL(__imp__sub_821761A0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821761d0
	if (ctx.cr6.eq) goto loc_821761D0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x821761d0
	if (ctx.cr6.eq) goto loc_821761D0;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x821761d0
	if (ctx.cr6.eq) goto loc_821761D0;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x821761d0
	if (ctx.cr6.eq) goto loc_821761D0;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// bne cr6,0x821761d4
	if (!ctx.cr6.eq) goto loc_821761D4;
loc_821761D0:
	// li r11,1
	ctx.r11.s64 = 1;
loc_821761D4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821761DC"))) PPC_WEAK_FUNC(sub_821761DC);
PPC_FUNC_IMPL(__imp__sub_821761DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821761E0"))) PPC_WEAK_FUNC(sub_821761E0);
PPC_FUNC_IMPL(__imp__sub_821761E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821761F8"))) PPC_WEAK_FUNC(sub_821761F8);
PPC_FUNC_IMPL(__imp__sub_821761F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82176208:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82176208
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82176208;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,255
	ctx.r9.s64 = 255;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// stb r11,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r11.u8);
	// lfs f0,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176238"))) PPC_WEAK_FUNC(sub_82176238);
PPC_FUNC_IMPL(__imp__sub_82176238) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217623C"))) PPC_WEAK_FUNC(sub_8217623C);
PPC_FUNC_IMPL(__imp__sub_8217623C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176240"))) PPC_WEAK_FUNC(sub_82176240);
PPC_FUNC_IMPL(__imp__sub_82176240) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176244"))) PPC_WEAK_FUNC(sub_82176244);
PPC_FUNC_IMPL(__imp__sub_82176244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176248"))) PPC_WEAK_FUNC(sub_82176248);
PPC_FUNC_IMPL(__imp__sub_82176248) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82176260
	if (!ctx.cr6.gt) goto loc_82176260;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82176260:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82176270
	if (!ctx.cr6.lt) goto loc_82176270;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82176270:
	// lfs f0,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82176288
	if (ctx.cr6.lt) goto loc_82176288;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82176288:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176290"))) PPC_WEAK_FUNC(sub_82176290);
PPC_FUNC_IMPL(__imp__sub_82176290) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176294"))) PPC_WEAK_FUNC(sub_82176294);
PPC_FUNC_IMPL(__imp__sub_82176294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176298"))) PPC_WEAK_FUNC(sub_82176298);
PPC_FUNC_IMPL(__imp__sub_82176298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lfs f1,324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 324);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821762A4"))) PPC_WEAK_FUNC(sub_821762A4);
PPC_FUNC_IMPL(__imp__sub_821762A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821762A8"))) PPC_WEAK_FUNC(sub_821762A8);
PPC_FUNC_IMPL(__imp__sub_821762A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821762BC"))) PPC_WEAK_FUNC(sub_821762BC);
PPC_FUNC_IMPL(__imp__sub_821762BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821762C0"))) PPC_WEAK_FUNC(sub_821762C0);
PPC_FUNC_IMPL(__imp__sub_821762C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821762C8;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x82080364
	ctx.lr = 0x821762D0;
	__savefpr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r31,r3,64
	ctx.r31.s64 = ctx.r3.s64 + 64;
	// addi r30,r3,436
	ctx.r30.s64 = ctx.r3.s64 + 436;
	// addi r29,r3,32
	ctx.r29.s64 = ctx.r3.s64 + 32;
	// lfs f29,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f29.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f31,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// li r28,4
	ctx.r28.s64 = 4;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// stfs f29,64(r3)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f29,76(r3)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f31,72(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f31,68(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lfs f30,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f30.f64 = double(temp.f32);
loc_82176310:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82176494
	if (ctx.cr6.gt) goto loc_82176494;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x821763d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821763D8;
	// bdzf 4*cr6+eq,0x8217637c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217637C;
	// bne cr6,0x82176444
	if (!ctx.cr6.eq) goto loc_82176444;
	// lbz r11,2(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 2);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82176354
	if (ctx.cr6.eq) goto loc_82176354;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,0(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// stfs f11,4(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
loc_82176354:
	// lbz r11,3(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 3);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82176494
	if (ctx.cr6.eq) goto loc_82176494;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// b 0x82176494
	goto loc_82176494;
loc_8217637C:
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bne cr6,0x82176394
	if (!ctx.cr6.eq) goto loc_82176394;
	// lfs f0,24(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// beq cr6,0x82176494
	if (ctx.cr6.eq) goto loc_82176494;
loc_82176394:
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f11,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,0(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lfs f10,20(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// lfs f8,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// stfs f9,4(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f7,24(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// lfs f5,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// stfs f6,8(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// lfs f4,24(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// stfs f3,12(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// b 0x82176494
	goto loc_82176494;
loc_821763D8:
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82176494
	if (ctx.cr6.eq) goto loc_82176494;
	// fmuls f28,f0,f30
	ctx.f28.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x8207ae60
	ctx.lr = 0x821763F0;
	sub_8207AE60(ctx, base);
	// frsp f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = double(float(ctx.f1.f64));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// bl 0x8207af40
	ctx.lr = 0x821763FC;
	sub_8207AF40(ctx, base);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f0,f27
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f27.f64));
	// lfs f10,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f12,f27
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f27.f64));
	// lfs f8,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f27
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f27.f64));
	// fmuls f6,f8,f27
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f27.f64));
	// fmadds f5,f12,f13,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f5,8(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fmsubs f4,f0,f13,f9
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 - ctx.f9.f64));
	// stfs f4,0(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fmadds f3,f8,f13,f7
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f3,12(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// fmsubs f2,f10,f13,f6
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 - ctx.f6.f64));
	// stfs f2,4(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// b 0x82176494
	goto loc_82176494;
loc_82176444:
	// lfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bne cr6,0x8217645c
	if (!ctx.cr6.eq) goto loc_8217645C;
	// lfs f0,32(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x82176494
	if (ctx.cr6.eq) goto loc_82176494;
loc_8217645C:
	// lfs f0,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,32(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f0,f12,f11
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f12.f64 + ctx.f11.f64));
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f13,f11,f12
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f6,f0,f10,f8
	ctx.f6.f64 = double(float(ctx.f0.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f9,0(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fmadds f5,f13,f8,f10
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f8.f64 + ctx.f10.f64));
	// stfs f7,8(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// stfs f6,4(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f5,12(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
loc_82176494:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x82176310
	if (!ctx.cr0.eq) goto loc_82176310;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x820803b0
	ctx.lr = 0x821764AC;
	__restfpr_27(ctx, base);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821764B0"))) PPC_WEAK_FUNC(sub_821764B0);
PPC_FUNC_IMPL(__imp__sub_821764B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r10,524
	ctx.r10.s64 = 524;
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821764cc
	if (!ctx.cr0.eq) goto loc_821764CC;
	// twi 31,r0,22
loc_821764CC:
	// lwz r3,512(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 512);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821764D4"))) PPC_WEAK_FUNC(sub_821764D4);
PPC_FUNC_IMPL(__imp__sub_821764D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821764D8"))) PPC_WEAK_FUNC(sub_821764D8);
PPC_FUNC_IMPL(__imp__sub_821764D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r10,524
	ctx.r10.s64 = 524;
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821764f4
	if (!ctx.cr0.eq) goto loc_821764F4;
	// twi 31,r0,22
loc_821764F4:
	// stw r4,512(r11)
	PPC_STORE_U32(ctx.r11.u32 + 512, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821764FC"))) PPC_WEAK_FUNC(sub_821764FC);
PPC_FUNC_IMPL(__imp__sub_821764FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176500"))) PPC_WEAK_FUNC(sub_82176500);
PPC_FUNC_IMPL(__imp__sub_82176500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r9,524
	ctx.r9.s64 = 524;
	// lwz r8,256(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176520
	if (!ctx.cr0.eq) goto loc_82176520;
	// twi 31,r0,22
loc_82176520:
	// stfs f1,504(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 504, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217653c
	if (!ctx.cr0.eq) goto loc_8217653C;
	// twi 31,r0,22
loc_8217653C:
	// stfs f2,508(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 508, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176544"))) PPC_WEAK_FUNC(sub_82176544);
PPC_FUNC_IMPL(__imp__sub_82176544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176548"))) PPC_WEAK_FUNC(sub_82176548);
PPC_FUNC_IMPL(__imp__sub_82176548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r9,524
	ctx.r9.s64 = 524;
	// lwz r8,256(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176568
	if (!ctx.cr0.eq) goto loc_82176568;
	// twi 31,r0,22
loc_82176568:
	// stfs f1,496(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 496, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82176584
	if (!ctx.cr0.eq) goto loc_82176584;
	// twi 31,r0,22
loc_82176584:
	// stfs f2,500(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 500, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217658C"))) PPC_WEAK_FUNC(sub_8217658C);
PPC_FUNC_IMPL(__imp__sub_8217658C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176590"))) PPC_WEAK_FUNC(sub_82176590);
PPC_FUNC_IMPL(__imp__sub_82176590) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r9,524
	ctx.r9.s64 = 524;
	// lwz r8,256(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821765b0
	if (!ctx.cr0.eq) goto loc_821765B0;
	// twi 31,r0,22
loc_821765B0:
	// stb r4,478(r10)
	PPC_STORE_U8(ctx.r10.u32 + 478, ctx.r4.u8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821765cc
	if (!ctx.cr0.eq) goto loc_821765CC;
	// twi 31,r0,22
loc_821765CC:
	// stb r5,479(r10)
	PPC_STORE_U8(ctx.r10.u32 + 479, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821765D4"))) PPC_WEAK_FUNC(sub_821765D4);
PPC_FUNC_IMPL(__imp__sub_821765D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821765D8"))) PPC_WEAK_FUNC(sub_821765D8);
PPC_FUNC_IMPL(__imp__sub_821765D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,252(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 252);
	// li r8,524
	ctx.r8.s64 = 524;
	// lwz r9,256(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	// addi r11,r4,240
	ctx.r11.s64 = ctx.r4.s64 + 240;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821765f8
	if (!ctx.cr0.eq) goto loc_821765F8;
	// twi 31,r0,22
loc_821765F8:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176610
	if (!ctx.cr0.eq) goto loc_82176610;
	// twi 31,r0,22
loc_82176610:
	// lfs f0,480(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,484(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 484);
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

__attribute__((alias("__imp__sub_82176624"))) PPC_WEAK_FUNC(sub_82176624);
PPC_FUNC_IMPL(__imp__sub_82176624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176628"))) PPC_WEAK_FUNC(sub_82176628);
PPC_FUNC_IMPL(__imp__sub_82176628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r9,524
	ctx.r9.s64 = 524;
	// lwz r8,256(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176648
	if (!ctx.cr0.eq) goto loc_82176648;
	// twi 31,r0,22
loc_82176648:
	// stfs f1,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176664
	if (!ctx.cr0.eq) goto loc_82176664;
	// twi 31,r0,22
loc_82176664:
	// stfs f2,484(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176680
	if (!ctx.cr0.eq) goto loc_82176680;
	// twi 31,r0,22
loc_82176680:
	// stfs f3,488(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 488, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176688"))) PPC_WEAK_FUNC(sub_82176688);
PPC_FUNC_IMPL(__imp__sub_82176688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r9,524
	ctx.r9.s64 = 524;
	// lwz r8,256(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821766ac
	if (!ctx.cr0.eq) goto loc_821766AC;
	// twi 31,r0,22
loc_821766AC:
	// lfs f0,24(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821766cc
	if (!ctx.cr0.eq) goto loc_821766CC;
	// twi 31,r0,22
loc_821766CC:
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,484(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821766D8"))) PPC_WEAK_FUNC(sub_821766D8);
PPC_FUNC_IMPL(__imp__sub_821766D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r9,524
	ctx.r9.s64 = 524;
	// lwz r8,256(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821766f8
	if (!ctx.cr0.eq) goto loc_821766F8;
	// twi 31,r0,22
loc_821766F8:
	// stfs f1,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82176714
	if (!ctx.cr0.eq) goto loc_82176714;
	// twi 31,r0,22
loc_82176714:
	// stfs f2,484(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217671C"))) PPC_WEAK_FUNC(sub_8217671C);
PPC_FUNC_IMPL(__imp__sub_8217671C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176720"))) PPC_WEAK_FUNC(sub_82176720);
PPC_FUNC_IMPL(__imp__sub_82176720) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r10,524
	ctx.r10.s64 = 524;
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217673c
	if (!ctx.cr0.eq) goto loc_8217673C;
	// twi 31,r0,22
loc_8217673C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176748"))) PPC_WEAK_FUNC(sub_82176748);
PPC_FUNC_IMPL(__imp__sub_82176748) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r10,524
	ctx.r10.s64 = 524;
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82176764
	if (!ctx.cr0.eq) goto loc_82176764;
	// twi 31,r0,22
loc_82176764:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176770"))) PPC_WEAK_FUNC(sub_82176770);
PPC_FUNC_IMPL(__imp__sub_82176770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,28
	ctx.r11.s64 = ctx.r1.s64 + 28;
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x82176790
	if (ctx.cr6.gt) goto loc_82176790;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
loc_82176790:
	// lwz r10,268(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// stfs f0,180(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// addi r11,r3,180
	ctx.r11.s64 = ctx.r3.s64 + 180;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f0,f11
	ctx.f0.f64 = double(float(ctx.f11.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x821767c8
	if (ctx.cr6.lt) goto loc_821767C8;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
loc_821767C8:
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 184, temp.u32);
	// stb r10,177(r3)
	PPC_STORE_U8(ctx.r3.u32 + 177, ctx.r10.u8);
	// stb r10,179(r3)
	PPC_STORE_U8(ctx.r3.u32 + 179, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821767E0"))) PPC_WEAK_FUNC(sub_821767E0);
PPC_FUNC_IMPL(__imp__sub_821767E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,456(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 456);
	// lwz r10,452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 452);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x82176814
	if (!ctx.cr6.eq) goto loc_82176814;
	// lwz r11,480(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 480);
	// lwz r10,476(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 476);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82176818
	if (ctx.cr6.eq) goto loc_82176818;
loc_82176814:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82176818:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176820"))) PPC_WEAK_FUNC(sub_82176820);
PPC_FUNC_IMPL(__imp__sub_82176820) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82176828;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,152(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82176850
	if (ctx.cr6.eq) goto loc_82176850;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176850;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82176850:
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// bl 0x8207a630
	ctx.lr = 0x82176858;
	sub_8207A630(ctx, base);
	// addi r31,r31,160
	ctx.r31.s64 = ctx.r31.s64 + 160;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x821768d4
	if (ctx.cr0.eq) goto loc_821768D4;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82176878:
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
	// blt cr6,0x82176894
	if (ctx.cr6.lt) goto loc_82176894;
	// twi 31,r0,22
loc_82176894:
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821768b4
	if (ctx.cr6.eq) goto loc_821768B4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821768B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821768B4:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176878
	if (ctx.cr6.lt) goto loc_82176878;
loc_821768D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821768DC"))) PPC_WEAK_FUNC(sub_821768DC);
PPC_FUNC_IMPL(__imp__sub_821768DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821768E0"))) PPC_WEAK_FUNC(sub_821768E0);
PPC_FUNC_IMPL(__imp__sub_821768E0) {
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
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r3,-31016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31016);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82176920
	if (!ctx.cr6.eq) goto loc_82176920;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82079fd8
	ctx.lr = 0x82176908;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82176918
	if (ctx.cr6.eq) goto loc_82176918;
	// bl 0x82167b28
	ctx.lr = 0x82176914;
	sub_82167B28(ctx, base);
	// b 0x8217691c
	goto loc_8217691C;
loc_82176918:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8217691C:
	// stw r3,-31016(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31016, ctx.r3.u32);
loc_82176920:
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

__attribute__((alias("__imp__sub_82176934"))) PPC_WEAK_FUNC(sub_82176934);
PPC_FUNC_IMPL(__imp__sub_82176934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176938"))) PPC_WEAK_FUNC(sub_82176938);
PPC_FUNC_IMPL(__imp__sub_82176938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,76(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	// li r8,524
	ctx.r8.s64 = 524;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176960
	if (!ctx.cr0.eq) goto loc_82176960;
	// twi 31,r0,22
loc_82176960:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r9,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x82176978
	if (!ctx.cr0.eq) goto loc_82176978;
	// twi 31,r0,22
loc_82176978:
	// lfs f0,480(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,484(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 484);
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

__attribute__((alias("__imp__sub_8217698C"))) PPC_WEAK_FUNC(sub_8217698C);
PPC_FUNC_IMPL(__imp__sub_8217698C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176990"))) PPC_WEAK_FUNC(sub_82176990);
PPC_FUNC_IMPL(__imp__sub_82176990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// li r9,524
	ctx.r9.s64 = 524;
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821769bc
	if (!ctx.cr0.eq) goto loc_821769BC;
	// twi 31,r0,22
loc_821769BC:
	// lfs f0,24(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r7,r8,r9
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821769dc
	if (!ctx.cr0.eq) goto loc_821769DC;
	// twi 31,r0,22
loc_821769DC:
	// lfs f0,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,484(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821769E8"))) PPC_WEAK_FUNC(sub_821769E8);
PPC_FUNC_IMPL(__imp__sub_821769E8) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,524
	ctx.r10.s64 = 524;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lwz r11,268(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// lwz r9,272(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 272);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82176a0c
	if (!ctx.cr0.eq) goto loc_82176A0C;
	// twi 31,r0,22
loc_82176A0C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176A18"))) PPC_WEAK_FUNC(sub_82176A18);
PPC_FUNC_IMPL(__imp__sub_82176A18) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,524
	ctx.r10.s64 = 524;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r11.u8);
	// lwz r11,268(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// lwz r9,272(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 272);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x82176a3c
	if (!ctx.cr0.eq) goto loc_82176A3C;
	// twi 31,r0,22
loc_82176A3C:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176A48"))) PPC_WEAK_FUNC(sub_82176A48);
PPC_FUNC_IMPL(__imp__sub_82176A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x8208035c
	ctx.lr = 0x82176A58;
	__savefpr_25(ctx, base);
	// lwz r11,432(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 432);
	// addi r8,r3,416
	ctx.r8.s64 = ctx.r3.s64 + 416;
	// lwz r10,428(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r7,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82176c80
	if (ctx.cr0.eq) goto loc_82176C80;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r6,r3,240
	ctx.r6.s64 = ctx.r3.s64 + 240;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,524
	ctx.r4.s64 = 524;
	// lfs f11,96(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-19612(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,21768(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
loc_82176AA0:
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r3,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r5,r3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x82176abc
	if (ctx.cr6.lt) goto loc_82176ABC;
	// twi 31,r0,22
loc_82176ABC:
	// lwz r9,16(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lwz r11,12(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// subf r3,r11,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r9,r3,r4
	ctx.r9.s32 = ppc_divw(ctx.r3.s32, ctx.r4.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82176adc
	if (ctx.cr6.lt) goto loc_82176ADC;
	// twi 31,r0,22
loc_82176ADC:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,520(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 520);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bgt cr6,0x82176c60
	if (ctx.cr6.gt) goto loc_82176C60;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x82176b1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82176B1C;
	// bdzf 4*cr6+eq,0x82176b3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82176B3C;
	// bne cr6,0x82176b80
	if (!ctx.cr6.eq) goto loc_82176B80;
	// lfs f10,440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 440);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,4(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f9,444(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 444);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,8(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// b 0x82176c60
	goto loc_82176C60;
loc_82176B1C:
	// lfs f10,440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 440);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,4(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f9,444(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 444);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,8(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f8,456(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 456);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// stfs f7,12(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// b 0x82176c60
	goto loc_82176C60;
loc_82176B3C:
	// lfs f10,456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 456);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,460(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 460);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// lfs f6,440(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 440);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,444(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 444);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f3,f7,f12
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fadds f2,f4,f6
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// stfs f2,12(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fadds f1,f3,f5
	ctx.f1.f64 = double(float(ctx.f3.f64 + ctx.f5.f64));
	// stfs f1,16(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// fsubs f10,f6,f4
	ctx.f10.f64 = double(float(ctx.f6.f64 - ctx.f4.f64));
	// stfs f10,4(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fsubs f9,f5,f3
	ctx.f9.f64 = double(float(ctx.f5.f64 - ctx.f3.f64));
	// stfs f9,8(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// b 0x82176c60
	goto loc_82176C60;
loc_82176B80:
	// lwz r9,432(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 432);
	// lfs f10,440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 440);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,444(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 444);
	ctx.f9.f64 = double(temp.f32);
	// mulli r9,r9,148
	ctx.r9.s64 = ctx.r9.s64 * 148;
	// lfs f7,64(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,72(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f4,f7,f13
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// lfs f8,68(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f1,f3,f13
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// lfs f5,76(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f29,f8,f0
	ctx.f29.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f2,f5,f13
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmuls f28,f5,f0
	ctx.f28.f64 = double(float(ctx.f5.f64 * ctx.f0.f64));
	// fmuls f31,f7,f0
	ctx.f31.f64 = double(float(ctx.f7.f64 * ctx.f0.f64));
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// fmuls f30,f3,f0
	ctx.f30.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// addi r9,r11,132
	ctx.r9.s64 = ctx.r11.s64 + 132;
	// lfs f26,164(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	ctx.f26.f64 = double(temp.f32);
	// fadds f27,f4,f6
	ctx.f27.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// fmuls f8,f8,f26
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f26.f64));
	// lfs f25,160(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	ctx.f25.f64 = double(temp.f32);
	// fmuls f5,f5,f26
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f26.f64));
	// fadds f26,f1,f2
	ctx.f26.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fadds f6,f31,f6
	ctx.f6.f64 = double(float(ctx.f31.f64 + ctx.f6.f64));
	// fadds f2,f30,f2
	ctx.f2.f64 = double(float(ctx.f30.f64 + ctx.f2.f64));
	// fadds f31,f29,f31
	ctx.f31.f64 = double(float(ctx.f29.f64 + ctx.f31.f64));
	// fadds f30,f28,f30
	ctx.f30.f64 = double(float(ctx.f28.f64 + ctx.f30.f64));
	// fadds f4,f29,f4
	ctx.f4.f64 = double(float(ctx.f29.f64 + ctx.f4.f64));
	// fadds f1,f28,f1
	ctx.f1.f64 = double(float(ctx.f28.f64 + ctx.f1.f64));
	// fmadds f8,f7,f25,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f25.f64 + ctx.f8.f64));
	// fmadds f7,f3,f25,f5
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f25.f64 + ctx.f5.f64));
	// fsubs f5,f27,f8
	ctx.f5.f64 = double(float(ctx.f27.f64 - ctx.f8.f64));
	// fsubs f3,f26,f7
	ctx.f3.f64 = double(float(ctx.f26.f64 - ctx.f7.f64));
	// fsubs f6,f6,f8
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f8.f64));
	// fsubs f2,f2,f7
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f7.f64));
	// fsubs f31,f31,f8
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f8.f64));
	// fsubs f30,f30,f7
	ctx.f30.f64 = double(float(ctx.f30.f64 - ctx.f7.f64));
	// fsubs f8,f4,f8
	ctx.f8.f64 = double(float(ctx.f4.f64 - ctx.f8.f64));
	// fsubs f7,f1,f7
	ctx.f7.f64 = double(float(ctx.f1.f64 - ctx.f7.f64));
	// fadds f5,f5,f10
	ctx.f5.f64 = double(float(ctx.f5.f64 + ctx.f10.f64));
	// stfs f5,4(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// fadds f4,f3,f9
	ctx.f4.f64 = double(float(ctx.f3.f64 + ctx.f9.f64));
	// stfs f4,8(r10)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// fadds f3,f6,f10
	ctx.f3.f64 = double(float(ctx.f6.f64 + ctx.f10.f64));
	// stfs f3,12(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fadds f2,f2,f9
	ctx.f2.f64 = double(float(ctx.f2.f64 + ctx.f9.f64));
	// stfs f2,16(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// fadds f1,f31,f10
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f10.f64));
	// stfs f1,20(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// fadds f6,f30,f9
	ctx.f6.f64 = double(float(ctx.f30.f64 + ctx.f9.f64));
	// stfs f6,24(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// fadds f5,f8,f10
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// stfs f5,28(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// fadds f4,f7,f9
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// stfs f4,32(r10)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r10.u32 + 32, temp.u32);
loc_82176C60:
	// lwz r11,16(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r3,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r5,r3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x82176aa0
	if (ctx.cr6.lt) goto loc_82176AA0;
loc_82176C80:
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x820803a8
	ctx.lr = 0x82176C88;
	__restfpr_25(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82176C94"))) PPC_WEAK_FUNC(sub_82176C94);
PPC_FUNC_IMPL(__imp__sub_82176C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176C98"))) PPC_WEAK_FUNC(sub_82176C98);
PPC_FUNC_IMPL(__imp__sub_82176C98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82176CA0;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,256(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// li r29,524
	ctx.r29.s64 = 524;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// addi r30,r3,240
	ctx.r30.s64 = ctx.r3.s64 + 240;
	// li r27,1
	ctx.r27.s64 = 1;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x82176ebc
	if (!ctx.cr6.gt) goto loc_82176EBC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// lfs f31,-19608(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -19608);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f30.f64 = double(temp.f32);
loc_82176CE4:
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176d00
	if (ctx.cr6.lt) goto loc_82176D00;
	// twi 31,r0,22
loc_82176D00:
	// add r31,r28,r10
	ctx.r31.u64 = ctx.r28.u64 + ctx.r10.u64;
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176d24
	if (ctx.cr6.lt) goto loc_82176D24;
	// twi 31,r0,22
loc_82176D24:
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplwi cr6,r9,7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 7, ctx.xer);
	// bne cr6,0x82176e94
	if (!ctx.cr6.eq) goto loc_82176E94;
	// lbz r10,436(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 436);
	// addi r11,r31,436
	ctx.r11.s64 = ctx.r31.s64 + 436;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82176e94
	if (ctx.cr6.eq) goto loc_82176E94;
	// lbz r10,437(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 437);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82176e94
	if (ctx.cr6.eq) goto loc_82176E94;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// mulli r10,r10,148
	ctx.r10.s64 = ctx.r10.s64 * 148;
	// lfs f9,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,72(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// lfs f4,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f4.f64 = double(temp.f32);
	// fadds f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// lfs f6,68(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f8,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// fadds f3,f4,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// fadds f2,f4,f6
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f6.f64));
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r10,r11,132
	ctx.r10.s64 = ctx.r11.s64 + 132;
	// fmuls f1,f7,f30
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f30.f64));
	// lfs f0,160(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f5,f31
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f31.f64));
	// fmuls f12,f8,f0
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lfs f8,164(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f4,f0
	ctx.f7.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f5,f3,f30
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f30.f64));
	// fmuls f4,f2,f31
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f31.f64));
	// fmadds f3,f9,f8,f12
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f12.f64));
	// fmadds f2,f6,f8,f7
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsubs f1,f1,f3
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f3.f64));
	// fsubs f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f3.f64));
	// fsubs f12,f5,f2
	ctx.f12.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f9,f4,f2
	ctx.f9.f64 = double(float(ctx.f4.f64 - ctx.f2.f64));
	// fadds f0,f1,f10
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f10.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fadds f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f10.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fadds f11,f9,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82176df4
	if (ctx.cr6.lt) goto loc_82176DF4;
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
loc_82176DF4:
	// fcmpu cr6,f12,f11
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x82176e04
	if (ctx.cr6.lt) goto loc_82176E04;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
loc_82176E04:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// blt cr6,0x82176e14
	if (ctx.cr6.lt) goto loc_82176E14;
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
loc_82176E14:
	// fcmpu cr6,f11,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x82176e24
	if (ctx.cr6.lt) goto loc_82176E24;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
loc_82176E24:
	// lwz r6,520(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 520);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,0(r6)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f13,4(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// stfs f12,8(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// stfs f11,12(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// lwz r11,516(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 516);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82176e8c
	if (ctx.cr6.eq) goto loc_82176E8C;
	// lwz r26,520(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 520);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// bl 0x8206e7f8
	ctx.lr = 0x82176E6C;
	sub_8206E7F8(ctx, base);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r26.u32 + 4, temp.u32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r26)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r26.u32 + 8, temp.u32);
	// lfs f11,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,12(r26)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r26.u32 + 12, temp.u32);
loc_82176E8C:
	// lwz r11,520(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 520);
	// b 0x82176e98
	goto loc_82176E98;
loc_82176E94:
	// lwz r11,516(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 516);
loc_82176E98:
	// stw r11,516(r31)
	PPC_STORE_U32(ctx.r31.u32 + 516, ctx.r11.u32);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addi r28,r28,524
	ctx.r28.s64 = ctx.r28.s64 + 524;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r29
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176ce4
	if (ctx.cr6.lt) goto loc_82176CE4;
loc_82176EBC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82176ECC"))) PPC_WEAK_FUNC(sub_82176ECC);
PPC_FUNC_IMPL(__imp__sub_82176ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82176ED0"))) PPC_WEAK_FUNC(sub_82176ED0);
PPC_FUNC_IMPL(__imp__sub_82176ED0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82176ED8;
	__savegprlr_22(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,256(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// li r24,524
	ctx.r24.s64 = 524;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// addi r27,r3,240
	ctx.r27.s64 = ctx.r3.s64 + 240;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r23,0
	ctx.r23.s64 = 0;
	// divw r8,r9,r24
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r24.s32);
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x82177094
	if (!ctx.cr6.gt) goto loc_82177094;
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
loc_82176F0C:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r24
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r24.s32);
	// cmplw cr6,r26,r8
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176f28
	if (ctx.cr6.lt) goto loc_82176F28;
	// twi 31,r0,22
loc_82176F28:
	// add r28,r25,r11
	ctx.r28.u64 = ctx.r25.u64 + ctx.r11.u64;
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bgt cr6,0x82177074
	if (ctx.cr6.gt) goto loc_82177074;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8217706c
	if (ctx.cr6.eq) goto loc_8217706C;
	// bdz 0x82177074
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82177074;
	// bdz 0x82176f60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82176F60;
	// bdz 0x82176f9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82176F9C;
	// bdz 0x82177074
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82177074;
	// bdz 0x82177074
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_82177074;
	// b 0x8217706c
	goto loc_8217706C;
loc_82176F60:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82176f84
	if (ctx.cr6.eq) goto loc_82176F84;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176F84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82176F84:
	// lwz r3,520(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// bl 0x8207a630
	ctx.lr = 0x82176F8C;
	sub_8207A630(ctx, base);
	// lwz r3,276(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 276);
	// bl 0x8207a630
	ctx.lr = 0x82176F94;
	sub_8207A630(ctx, base);
	// lwz r3,424(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 424);
	// b 0x82177070
	goto loc_82177070;
loc_82176F9C:
	// lwz r31,520(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// addi r11,r31,48
	ctx.r11.s64 = ctx.r31.s64 + 48;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi. r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82177024
	if (ctx.cr0.eq) goto loc_82177024;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
loc_82176FC0:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176fdc
	if (ctx.cr6.lt) goto loc_82176FDC;
	// twi 31,r0,22
loc_82176FDC:
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82176ffc
	if (ctx.cr6.eq) goto loc_82176FFC;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82176FFC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82176FFC:
	// lwz r31,520(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r11,r31,48
	ctx.r11.s64 = ctx.r31.s64 + 48;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r30,r7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82176fc0
	if (ctx.cr6.lt) goto loc_82176FC0;
loc_82177024:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8217705c
	if (ctx.cr6.eq) goto loc_8217705C;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// addi r30,r31,48
	ctx.r30.s64 = ctx.r31.s64 + 48;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82177040
	if (ctx.cr6.eq) goto loc_82177040;
	// bl 0x8207a630
	ctx.lr = 0x82177040;
	sub_8207A630(ctx, base);
loc_82177040:
	// stw r23,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r23.u32);
	// stw r23,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r23.u32);
	// stw r23,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r23.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82177054;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a630
	ctx.lr = 0x8217705C;
	sub_8207A630(ctx, base);
loc_8217705C:
	// lwz r3,276(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 276);
	// bl 0x8207a630
	ctx.lr = 0x82177064;
	sub_8207A630(ctx, base);
	// lwz r3,424(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 424);
	// b 0x82177070
	goto loc_82177070;
loc_8217706C:
	// lwz r3,520(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
loc_82177070:
	// bl 0x8207a630
	ctx.lr = 0x82177074;
	sub_8207A630(ctx, base);
loc_82177074:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r25,r25,524
	ctx.r25.s64 = ctx.r25.s64 + 524;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r24
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r24.s32);
	// cmplw cr6,r26,r8
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82176f0c
	if (ctx.cr6.lt) goto loc_82176F0C;
loc_82177094:
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821770a8
	if (!ctx.cr6.gt) goto loc_821770A8;
	// twi 31,r0,22
loc_821770A8:
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r8,16(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x821770c8
	if (!ctx.cr6.gt) goto loc_821770C8;
	// twi 31,r0,22
loc_821770C8:
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// bne cr6,0x8217710c
	if (!ctx.cr6.eq) goto loc_8217710C;
	// twi 31,r0,22
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
loc_821770EC:
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r11,r11,524
	ctx.r11.s64 = ctx.r11.s64 + 524;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x82177124
	if (ctx.cr6.gt) goto loc_82177124;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82177114
	if (ctx.cr6.eq) goto loc_82177114;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x82177118
	goto loc_82177118;
loc_8217710C:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x821770ec
	goto loc_821770EC;
loc_82177114:
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
loc_82177118:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82177128
	if (!ctx.cr6.lt) goto loc_82177128;
loc_82177124:
	// twi 31,r0,22
loc_82177128:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206db28
	ctx.lr = 0x82177140;
	sub_8206DB28(ctx, base);
	// lwz r10,432(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 432);
	// addi r4,r22,416
	ctx.r4.s64 = ctx.r22.s64 + 416;
	// lwz r11,428(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 428);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82177158
	if (!ctx.cr6.gt) goto loc_82177158;
	// twi 31,r0,22
loc_82177158:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x82177170
	if (!ctx.cr6.gt) goto loc_82177170;
	// twi 31,r0,22
loc_82177170:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206f498
	ctx.lr = 0x82177188;
	sub_8206F498(ctx, base);
	// lwz r10,456(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 456);
	// addi r4,r22,440
	ctx.r4.s64 = ctx.r22.s64 + 440;
	// lwz r11,452(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 452);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821771a0
	if (!ctx.cr6.gt) goto loc_821771A0;
	// twi 31,r0,22
loc_821771A0:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x821771b8
	if (!ctx.cr6.gt) goto loc_821771B8;
	// twi 31,r0,22
loc_821771B8:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206f498
	ctx.lr = 0x821771D0;
	sub_8206F498(ctx, base);
	// lwz r11,480(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 480);
	// addi r4,r22,464
	ctx.r4.s64 = ctx.r22.s64 + 464;
	// lwz r10,476(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 476);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x821771e8
	if (!ctx.cr6.gt) goto loc_821771E8;
	// twi 31,r0,22
loc_821771E8:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x82177200
	if (!ctx.cr6.gt) goto loc_82177200;
	// twi 31,r0,22
loc_82177200:
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206f498
	ctx.lr = 0x82177218;
	sub_8206F498(ctx, base);
	// addi r3,r22,516
	ctx.r3.s64 = ctx.r22.s64 + 516;
	// bl 0x82066558
	ctx.lr = 0x82177220;
	sub_82066558(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177228"))) PPC_WEAK_FUNC(sub_82177228);
PPC_FUNC_IMPL(__imp__sub_82177228) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82177230;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,344(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,348(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// addi r29,r3,332
	ctx.r29.s64 = ctx.r3.s64 + 332;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82177258
	if (!ctx.cr6.gt) goto loc_82177258;
	// twi 31,r0,22
loc_82177258:
	// lwz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_82177260:
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82177274
	if (!ctx.cr6.gt) goto loc_82177274;
	// twi 31,r0,22
loc_82177274:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82177288
	if (ctx.cr6.eq) goto loc_82177288;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8217728c
	if (ctx.cr6.eq) goto loc_8217728C;
loc_82177288:
	// twi 31,r0,22
loc_8217728C:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8217730c
	if (ctx.cr6.eq) goto loc_8217730C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x821772fc
	if (!ctx.cr6.eq) goto loc_821772FC;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821772A4:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821772b4
	if (ctx.cr6.lt) goto loc_821772B4;
	// twi 31,r0,22
loc_821772B4:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821772D4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82177304
	if (!ctx.cr6.eq) goto loc_82177304;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821772E4:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821772f4
	if (ctx.cr6.lt) goto loc_821772F4;
	// twi 31,r0,22
loc_821772F4:
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// b 0x82177260
	goto loc_82177260;
loc_821772FC:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821772a4
	goto loc_821772A4;
loc_82177304:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821772e4
	goto loc_821772E4;
loc_8217730C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82177314"))) PPC_WEAK_FUNC(sub_82177314);
PPC_FUNC_IMPL(__imp__sub_82177314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177318"))) PPC_WEAK_FUNC(sub_82177318);
PPC_FUNC_IMPL(__imp__sub_82177318) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82177320;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,408(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// li r10,12
	ctx.r10.s64 = 12;
	// lwz r9,404(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r29,r3,392
	ctx.r29.s64 = ctx.r3.s64 + 392;
	// subf r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x821774a8
	if (ctx.cr0.eq) goto loc_821774A8;
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82177358
	if (!ctx.cr6.gt) goto loc_82177358;
	// twi 31,r0,22
loc_82177358:
	// lwz r31,0(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_82177360:
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82177374
	if (!ctx.cr6.gt) goto loc_82177374;
	// twi 31,r0,22
loc_82177374:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82177388
	if (ctx.cr6.eq) goto loc_82177388;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8217738c
	if (ctx.cr6.eq) goto loc_8217738C;
loc_82177388:
	// twi 31,r0,22
loc_8217738C:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82177460
	if (ctx.cr6.eq) goto loc_82177460;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82177440
	if (!ctx.cr6.eq) goto loc_82177440;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821773A4:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821773b4
	if (ctx.cr6.lt) goto loc_821773B4;
	// twi 31,r0,22
loc_821773B4:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82177418
	if (!ctx.cr6.eq) goto loc_82177418;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82177448
	if (!ctx.cr6.eq) goto loc_82177448;
	// twi 31,r0,22
loc_821773CC:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821773dc
	if (ctx.cr6.lt) goto loc_821773DC;
	// twi 31,r0,22
loc_821773DC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82177450
	if (!ctx.cr6.eq) goto loc_82177450;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_821773EC:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x821773fc
	if (ctx.cr6.lt) goto loc_821773FC;
	// twi 31,r0,22
loc_821773FC:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82177418;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82177418:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82177458
	if (!ctx.cr6.eq) goto loc_82177458;
	// twi 31,r0,22
	// li r11,0
	ctx.r11.s64 = 0;
loc_82177428:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82177438
	if (ctx.cr6.lt) goto loc_82177438;
	// twi 31,r0,22
loc_82177438:
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// b 0x82177360
	goto loc_82177360;
loc_82177440:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821773a4
	goto loc_821773A4;
loc_82177448:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821773cc
	goto loc_821773CC;
loc_82177450:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821773ec
	goto loc_821773EC;
loc_82177458:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x82177428
	goto loc_82177428;
loc_82177460:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82177474
	if (!ctx.cr6.gt) goto loc_82177474;
	// twi 31,r0,22
loc_82177474:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x8217748c
	if (!ctx.cr6.gt) goto loc_8217748C;
	// twi 31,r0,22
loc_8217748C:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
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
	// bl 0x82061c78
	ctx.lr = 0x821774A8;
	sub_82061C78(ctx, base);
loc_821774A8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821774B0"))) PPC_WEAK_FUNC(sub_821774B0);
PPC_FUNC_IMPL(__imp__sub_821774B0) {
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
	// lwz r11,388(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82177578
	if (ctx.cr6.eq) goto loc_82177578;
	// lwz r10,384(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	// addi r31,r3,360
	ctx.r31.s64 = ctx.r3.s64 + 360;
	// lwz r11,360(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
loc_821774E4:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// beq cr6,0x821774fc
	if (ctx.cr6.eq) goto loc_821774FC;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82177500
	if (ctx.cr6.eq) goto loc_82177500;
loc_821774FC:
	// twi 31,r0,22
loc_82177500:
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82177548
	if (ctx.cr6.eq) goto loc_82177548;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177540
	if (!ctx.cr6.eq) goto loc_82177540;
	// twi 31,r0,22
loc_82177514:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82177524
	if (!ctx.cr6.eq) goto loc_82177524;
	// twi 31,r0,22
loc_82177524:
	// addi r3,r8,40
	ctx.r3.s64 = ctx.r8.s64 + 40;
	// bl 0x82176820
	ctx.lr = 0x8217752C;
	sub_82176820(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206fce0
	ctx.lr = 0x82177534;
	sub_8206FCE0(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x821774e4
	goto loc_821774E4;
loc_82177540:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82177514
	goto loc_82177514;
loc_82177548:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8206f1e8
	ctx.lr = 0x82177558;
	sub_8206F1E8(ctx, base);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r9.u32);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r8,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r8.u32);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r7,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r7.u32);
loc_82177578:
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

__attribute__((alias("__imp__sub_8217758C"))) PPC_WEAK_FUNC(sub_8217758C);
PPC_FUNC_IMPL(__imp__sub_8217758C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82177590"))) PPC_WEAK_FUNC(sub_82177590);
PPC_FUNC_IMPL(__imp__sub_82177590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82177598;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r30,144(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// std r5,224(r1)
	PPC_STORE_U64(ctx.r1.u32 + 224, ctx.r5.u64);
	// li r5,148
	ctx.r5.s64 = 148;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// bl 0x8207da20
	ctx.lr = 0x821775C0;
	sub_8207DA20(ctx, base);
	// stw r31,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// stw r30,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r30.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175648
	ctx.lr = 0x821775D8;
	sub_82175648(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r31,r11,-21836
	ctx.r31.s64 = ctx.r11.s64 + -21836;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,3308
	ctx.r5.s64 = ctx.r31.s64 + 3308;
	// bl 0x82175ae8
	ctx.lr = 0x821775F0;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x821775F4;
	sub_82175BB0(ctx, base);
	// stfs f1,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4, temp.u32);
	// addi r5,r31,3316
	ctx.r5.s64 = ctx.r31.s64 + 3316;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175ae8
	ctx.lr = 0x82177608;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217760C;
	sub_82175D08(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217827c
	if (ctx.cr6.eq) goto loc_8217827C;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,2
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 2, ctx.xer);
	// beq cr6,0x82177634
	if (ctx.cr6.eq) goto loc_82177634;
	// cmplwi cr6,r3,3
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 3, ctx.xer);
	// bne cr6,0x8217763c
	if (!ctx.cr6.eq) goto loc_8217763C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,13(r29)
	PPC_STORE_U8(ctx.r29.u32 + 13, ctx.r11.u8);
	// b 0x82177638
	goto loc_82177638;
loc_82177634:
	// stb r30,13(r29)
	PPC_STORE_U8(ctx.r29.u32 + 13, ctx.r30.u8);
loc_82177638:
	// stb r30,12(r29)
	PPC_STORE_U8(ctx.r29.u32 + 12, ctx.r30.u8);
loc_8217763C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r10,255
	ctx.r10.s64 = 255;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// addi r4,r31,3324
	ctx.r4.s64 = ctx.r31.s64 + 3324;
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// stfs f0,80(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 80, temp.u32);
	// stw r10,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r10.u32);
	// stfs f0,76(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 76, temp.u32);
	// addi r25,r29,36
	ctx.r25.s64 = ctx.r29.s64 + 36;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// bl 0x821753c8
	ctx.lr = 0x82177680;
	sub_821753C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217769c
	if (!ctx.cr6.eq) goto loc_8217769C;
	// addi r4,r31,3324
	ctx.r4.s64 = ctx.r31.s64 + 3324;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177698;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217769C;
	sub_8207B288(ctx, base);
loc_8217769C:
	// lwz r11,8(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821776b0
	if (ctx.cr6.eq) goto loc_821776B0;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x821777f0
	if (!ctx.cr6.eq) goto loc_821777F0;
loc_821776B0:
	// addi r4,r31,3332
	ctx.r4.s64 = ctx.r31.s64 + 3332;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x821776C8;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821776e4
	if (!ctx.cr6.eq) goto loc_821776E4;
	// addi r4,r31,3332
	ctx.r4.s64 = ctx.r31.s64 + 3332;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x821776E0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821776E4;
	sub_8207B288(ctx, base);
loc_821776E4:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x821749c8
	ctx.lr = 0x821776EC;
	sub_821749C8(ctx, base);
	// lwz r26,88(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r28,24(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r11,-11
	ctx.r27.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82177708;
	sub_82174AF8(ctx, base);
	// add r10,r27,r28
	ctx.r10.u64 = ctx.r27.u64 + ctx.r28.u64;
	// lbzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x82177744;
	sub_82174818(ctx, base);
	// lwz r6,28(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 28);
	// addi r4,r31,3336
	ctx.r4.s64 = ctx.r31.s64 + 3336;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// add r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 + ctx.r6.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r3,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177768;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177784
	if (!ctx.cr6.eq) goto loc_82177784;
	// addi r4,r31,3336
	ctx.r4.s64 = ctx.r31.s64 + 3336;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177780;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177784;
	sub_8207B288(ctx, base);
loc_82177784:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x821749c8
	ctx.lr = 0x8217778C;
	sub_821749C8(ctx, base);
	// lwz r26,88(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r28,24(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r11,-11
	ctx.r27.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821777A8;
	sub_82174AF8(ctx, base);
	// add r10,r27,r28
	ctx.r10.u64 = ctx.r27.u64 + ctx.r28.u64;
	// lbzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x821777E4;
	sub_82174818(ctx, base);
	// lwz r6,28(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// stw r5,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r5.u32);
loc_821777F0:
	// addi r4,r31,3344
	ctx.r4.s64 = ctx.r31.s64 + 3344;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177808;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177824
	if (!ctx.cr6.eq) goto loc_82177824;
	// addi r4,r31,3344
	ctx.r4.s64 = ctx.r31.s64 + 3344;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177820;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177824;
	sub_8207B288(ctx, base);
loc_82177824:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217782C;
	sub_82175D08(ctx, base);
	// clrlwi r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	// stw r3,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217786c
	if (ctx.cr6.eq) goto loc_8217786C;
	// addi r5,r31,3352
	ctx.r5.s64 = ctx.r31.s64 + 3352;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217784C;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x82177850;
	sub_82175BB0(ctx, base);
	// stfs f1,28(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 28, temp.u32);
	// addi r5,r31,3356
	ctx.r5.s64 = ctx.r31.s64 + 3356;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x82177864;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x82177868;
	sub_82175BB0(ctx, base);
	// stfs f1,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 32, temp.u32);
loc_8217786C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821778b8
	if (ctx.cr6.eq) goto loc_821778B8;
	// addi r5,r31,3360
	ctx.r5.s64 = ctx.r31.s64 + 3360;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217788C;
	sub_82175AE8(ctx, base);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// addi r27,r29,52
	ctx.r27.s64 = ctx.r29.s64 + 52;
loc_82177894:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175648
	ctx.lr = 0x821778A4;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x821778A8;
	sub_82175BB0(ctx, base);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stfsu f1,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	ea = 4 + ctx.r27.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r27.u32 = ea;
	// cmplwi cr6,r28,3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 3, ctx.xer);
	// blt cr6,0x82177894
	if (ctx.cr6.lt) goto loc_82177894;
loc_821778B8:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,14,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x3FE00;
	// rlwinm r10,r10,0,21,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFE07FF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177a08
	if (ctx.cr6.eq) goto loc_82177A08;
	// rlwinm r11,r11,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217791c
	if (ctx.cr6.eq) goto loc_8217791C;
	// addi r4,r31,3368
	ctx.r4.s64 = ctx.r31.s64 + 3368;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x821778F0;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217790c
	if (!ctx.cr6.eq) goto loc_8217790C;
	// addi r4,r31,3368
	ctx.r4.s64 = ctx.r31.s64 + 3368;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177908;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217790C;
	sub_8207B288(ctx, base);
loc_8217790C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x82177914;
	sub_82175D08(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// stw r11,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r11.u32);
loc_8217791C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217796c
	if (ctx.cr6.eq) goto loc_8217796C;
	// addi r4,r31,3372
	ctx.r4.s64 = ctx.r31.s64 + 3372;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177944;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177960
	if (!ctx.cr6.eq) goto loc_82177960;
	// addi r4,r31,3372
	ctx.r4.s64 = ctx.r31.s64 + 3372;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x8217795C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177960;
	sub_8207B288(ctx, base);
loc_82177960:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x82177968;
	sub_82175D08(ctx, base);
	// stw r3,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
loc_8217796C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821779e0
	if (ctx.cr6.eq) goto loc_821779E0;
	// addi r4,r31,3376
	ctx.r4.s64 = ctx.r31.s64 + 3376;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177994;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821779b0
	if (!ctx.cr6.eq) goto loc_821779B0;
	// addi r4,r31,3376
	ctx.r4.s64 = ctx.r31.s64 + 3376;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x821779AC;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821779B0;
	sub_8207B288(ctx, base);
loc_821779B0:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// addi r27,r25,-4
	ctx.r27.s64 = ctx.r25.s64 + -4;
loc_821779B8:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175648
	ctx.lr = 0x821779C8;
	sub_82175648(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x821779CC;
	sub_82175D08(ctx, base);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// stwu r3,4(r27)
	ea = 4 + ctx.r27.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r27.u32 = ea;
	// cmplwi cr6,r28,4
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 4, ctx.xer);
	// blt cr6,0x821779b8
	if (ctx.cr6.lt) goto loc_821779B8;
	// b 0x82177a08
	goto loc_82177A08;
loc_821779E0:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// rlwinm r10,r11,0,24,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x82177a08
	if (!ctx.cr6.eq) goto loc_82177A08;
	// lis r11,-32640
	ctx.r11.s64 = -2139095040;
	// ori r11,r11,33023
	ctx.r11.u64 = ctx.r11.u64 | 33023;
	// stw r11,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// stw r11,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// stw r11,8(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8, ctx.r11.u32);
	// stw r11,12(r25)
	PPC_STORE_U32(ctx.r25.u32 + 12, ctx.r11.u32);
loc_82177A08:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,23,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1FC;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177c14
	if (ctx.cr6.eq) goto loc_82177C14;
	// rlwinm r11,r11,0,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82177aa4
	if (ctx.cr6.eq) goto loc_82177AA4;
	// addi r4,r31,3384
	ctx.r4.s64 = ctx.r31.s64 + 3384;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177A3C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177a58
	if (!ctx.cr6.eq) goto loc_82177A58;
	// addi r4,r31,3384
	ctx.r4.s64 = ctx.r31.s64 + 3384;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177A54;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177A58;
	sub_8207B288(ctx, base);
loc_82177A58:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175e40
	ctx.lr = 0x82177A60;
	sub_82175E40(ctx, base);
	// stb r3,68(r29)
	PPC_STORE_U8(ctx.r29.u32 + 68, ctx.r3.u8);
	// addi r4,r31,3388
	ctx.r4.s64 = ctx.r31.s64 + 3388;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177A7C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177a98
	if (!ctx.cr6.eq) goto loc_82177A98;
	// addi r4,r31,3388
	ctx.r4.s64 = ctx.r31.s64 + 3388;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177A94;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177A98;
	sub_8207B288(ctx, base);
loc_82177A98:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175e40
	ctx.lr = 0x82177AA0;
	sub_82175E40(ctx, base);
	// stb r3,69(r29)
	PPC_STORE_U8(ctx.r29.u32 + 69, ctx.r3.u8);
loc_82177AA4:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177af4
	if (ctx.cr6.eq) goto loc_82177AF4;
	// addi r4,r31,3392
	ctx.r4.s64 = ctx.r31.s64 + 3392;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177ACC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177ae8
	if (!ctx.cr6.eq) goto loc_82177AE8;
	// addi r4,r31,3392
	ctx.r4.s64 = ctx.r31.s64 + 3392;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177AE4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177AE8;
	sub_8207B288(ctx, base);
loc_82177AE8:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175bb0
	ctx.lr = 0x82177AF0;
	sub_82175BB0(ctx, base);
	// stfs f1,72(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 72, temp.u32);
loc_82177AF4:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,25,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x60;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177b84
	if (ctx.cr6.eq) goto loc_82177B84;
	// addi r4,r31,3400
	ctx.r4.s64 = ctx.r31.s64 + 3400;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177B1C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177b38
	if (!ctx.cr6.eq) goto loc_82177B38;
	// addi r4,r31,3400
	ctx.r4.s64 = ctx.r31.s64 + 3400;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177B34;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177B38;
	sub_8207B288(ctx, base);
loc_82177B38:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175bb0
	ctx.lr = 0x82177B40;
	sub_82175BB0(ctx, base);
	// stfs f1,76(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 76, temp.u32);
	// addi r4,r31,3404
	ctx.r4.s64 = ctx.r31.s64 + 3404;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177B5C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177b78
	if (!ctx.cr6.eq) goto loc_82177B78;
	// addi r4,r31,3404
	ctx.r4.s64 = ctx.r31.s64 + 3404;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177B74;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177B78;
	sub_8207B288(ctx, base);
loc_82177B78:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175bb0
	ctx.lr = 0x82177B80;
	sub_82175BB0(ctx, base);
	// stfs f1,80(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 80, temp.u32);
loc_82177B84:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,23,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x180;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177c14
	if (ctx.cr6.eq) goto loc_82177C14;
	// addi r4,r31,3408
	ctx.r4.s64 = ctx.r31.s64 + 3408;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177BAC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177bc8
	if (!ctx.cr6.eq) goto loc_82177BC8;
	// addi r4,r31,3408
	ctx.r4.s64 = ctx.r31.s64 + 3408;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177BC4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177BC8;
	sub_8207B288(ctx, base);
loc_82177BC8:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175bb0
	ctx.lr = 0x82177BD0;
	sub_82175BB0(ctx, base);
	// stfs f1,84(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 84, temp.u32);
	// addi r4,r31,3412
	ctx.r4.s64 = ctx.r31.s64 + 3412;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177BEC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177c08
	if (!ctx.cr6.eq) goto loc_82177C08;
	// addi r4,r31,3412
	ctx.r4.s64 = ctx.r31.s64 + 3412;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177C04;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177C08;
	sub_8207B288(ctx, base);
loc_82177C08:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175bb0
	ctx.lr = 0x82177C10;
	sub_82175BB0(ctx, base);
	// stfs f1,88(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 88, temp.u32);
loc_82177C14:
	// lbz r11,13(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 13);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82177da8
	if (ctx.cr6.eq) goto loc_82177DA8;
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,16,20
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xF800;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177da8
	if (ctx.cr6.eq) goto loc_82177DA8;
	// rlwinm r11,r11,0,20,20
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82177c78
	if (ctx.cr6.eq) goto loc_82177C78;
	// addi r4,r31,3416
	ctx.r4.s64 = ctx.r31.s64 + 3416;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177C54;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177c70
	if (!ctx.cr6.eq) goto loc_82177C70;
	// addi r4,r31,3416
	ctx.r4.s64 = ctx.r31.s64 + 3416;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177C6C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177C70;
	sub_8207B288(ctx, base);
loc_82177C70:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,92(r29)
	PPC_STORE_U64(ctx.r29.u32 + 92, ctx.r11.u64);
loc_82177C78:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,16,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177cc4
	if (ctx.cr6.eq) goto loc_82177CC4;
	// addi r4,r31,3420
	ctx.r4.s64 = ctx.r31.s64 + 3420;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177CA0;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177cbc
	if (!ctx.cr6.eq) goto loc_82177CBC;
	// addi r4,r31,3420
	ctx.r4.s64 = ctx.r31.s64 + 3420;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177CB8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177CBC;
	sub_8207B288(ctx, base);
loc_82177CBC:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,100(r29)
	PPC_STORE_U64(ctx.r29.u32 + 100, ctx.r11.u64);
loc_82177CC4:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177d10
	if (ctx.cr6.eq) goto loc_82177D10;
	// addi r4,r31,3424
	ctx.r4.s64 = ctx.r31.s64 + 3424;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177CEC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177d08
	if (!ctx.cr6.eq) goto loc_82177D08;
	// addi r4,r31,3424
	ctx.r4.s64 = ctx.r31.s64 + 3424;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177D04;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177D08;
	sub_8207B288(ctx, base);
loc_82177D08:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,108(r29)
	PPC_STORE_U64(ctx.r29.u32 + 108, ctx.r11.u64);
loc_82177D10:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177d5c
	if (ctx.cr6.eq) goto loc_82177D5C;
	// addi r4,r31,3428
	ctx.r4.s64 = ctx.r31.s64 + 3428;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177D38;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177d54
	if (!ctx.cr6.eq) goto loc_82177D54;
	// addi r4,r31,3428
	ctx.r4.s64 = ctx.r31.s64 + 3428;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177D50;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177D54;
	sub_8207B288(ctx, base);
loc_82177D54:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,116(r29)
	PPC_STORE_U64(ctx.r29.u32 + 116, ctx.r11.u64);
loc_82177D5C:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177da8
	if (ctx.cr6.eq) goto loc_82177DA8;
	// addi r4,r31,3432
	ctx.r4.s64 = ctx.r31.s64 + 3432;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177D84;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177da0
	if (!ctx.cr6.eq) goto loc_82177DA0;
	// addi r4,r31,3432
	ctx.r4.s64 = ctx.r31.s64 + 3432;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177D9C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177DA0;
	sub_8207B288(ctx, base);
loc_82177DA0:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,124(r29)
	PPC_STORE_U64(ctx.r29.u32 + 124, ctx.r11.u64);
loc_82177DA8:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177e58
	if (ctx.cr6.eq) goto loc_82177E58;
	// addi r4,r31,3436
	ctx.r4.s64 = ctx.r31.s64 + 3436;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177DD0;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177dec
	if (!ctx.cr6.eq) goto loc_82177DEC;
	// addi r4,r31,3436
	ctx.r4.s64 = ctx.r31.s64 + 3436;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177DE8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177DEC;
	sub_8207B288(ctx, base);
loc_82177DEC:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x821749c8
	ctx.lr = 0x82177DF4;
	sub_821749C8(ctx, base);
	// lwz r26,88(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r28,24(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r11,-11
	ctx.r27.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x82177E10;
	sub_82174AF8(ctx, base);
	// add r10,r27,r28
	ctx.r10.u64 = ctx.r27.u64 + ctx.r28.u64;
	// lbzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x82177E4C;
	sub_82174818(ctx, base);
	// lwz r6,28(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// stw r5,140(r29)
	PPC_STORE_U32(ctx.r29.u32 + 140, ctx.r5.u32);
loc_82177E58:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// rlwinm r10,r11,0,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82177ea4
	if (ctx.cr6.eq) goto loc_82177EA4;
	// addi r4,r31,3440
	ctx.r4.s64 = ctx.r31.s64 + 3440;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177E80;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177e9c
	if (!ctx.cr6.eq) goto loc_82177E9C;
	// addi r4,r31,3440
	ctx.r4.s64 = ctx.r31.s64 + 3440;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177E98;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177E9C;
	sub_8207B288(ctx, base);
loc_82177E9C:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,132(r29)
	PPC_STORE_U64(ctx.r29.u32 + 132, ctx.r11.u64);
loc_82177EA4:
	// lwz r11,8(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x82178048
	if (ctx.cr6.eq) goto loc_82178048;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82178284
	if (!ctx.cr6.eq) goto loc_82178284;
	// addi r4,r31,3548
	ctx.r4.s64 = ctx.r31.s64 + 3548;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82177ED0;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177eec
	if (!ctx.cr6.eq) goto loc_82177EEC;
	// addi r4,r31,3548
	ctx.r4.s64 = ctx.r31.s64 + 3548;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177EE8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177EEC;
	sub_8207B288(ctx, base);
loc_82177EEC:
	// addi r4,r31,3552
	ctx.r4.s64 = ctx.r31.s64 + 3552;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821753c8
	ctx.lr = 0x82177F04;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82177f20
	if (!ctx.cr6.eq) goto loc_82177F20;
	// addi r4,r31,3552
	ctx.r4.s64 = ctx.r31.s64 + 3552;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177F1C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177F20;
	sub_8207B288(ctx, base);
loc_82177F20:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x82177F28;
	sub_82175BB0(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3560
	ctx.r4.s64 = ctx.r31.s64 + 3560;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// bl 0x821753c8
	ctx.lr = 0x82177F48;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82177f64
	if (!ctx.cr6.eq) goto loc_82177F64;
	// addi r4,r31,3560
	ctx.r4.s64 = ctx.r31.s64 + 3560;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177F60;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177F64;
	sub_8207B288(ctx, base);
loc_82177F64:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x82177F6C;
	sub_82175BB0(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3568
	ctx.r4.s64 = ctx.r31.s64 + 3568;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// bl 0x821753c8
	ctx.lr = 0x82177F8C;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82177fa8
	if (!ctx.cr6.eq) goto loc_82177FA8;
	// addi r4,r31,3568
	ctx.r4.s64 = ctx.r31.s64 + 3568;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177FA4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177FA8;
	sub_8207B288(ctx, base);
loc_82177FA8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x82177FB0;
	sub_82175BB0(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3576
	ctx.r4.s64 = ctx.r31.s64 + 3576;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// bl 0x821753c8
	ctx.lr = 0x82177FD0;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82177fec
	if (!ctx.cr6.eq) goto loc_82177FEC;
	// addi r4,r31,3576
	ctx.r4.s64 = ctx.r31.s64 + 3576;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82177FE8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82177FEC;
	sub_8207B288(ctx, base);
loc_82177FEC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x82177FF4;
	sub_82175BB0(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3584
	ctx.r4.s64 = ctx.r31.s64 + 3584;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// bl 0x821753c8
	ctx.lr = 0x82178014;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82178030
	if (!ctx.cr6.eq) goto loc_82178030;
	// addi r4,r31,3584
	ctx.r4.s64 = ctx.r31.s64 + 3584;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x8217802C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82178030;
	sub_8207B288(ctx, base);
loc_82178030:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x82178038;
	sub_82175BB0(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// stfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82178048:
	// addi r4,r31,3444
	ctx.r4.s64 = ctx.r31.s64 + 3444;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82178060;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217807c
	if (!ctx.cr6.eq) goto loc_8217807C;
	// addi r4,r31,3444
	ctx.r4.s64 = ctx.r31.s64 + 3444;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82178078;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217807C;
	sub_8207B288(ctx, base);
loc_8217807C:
	// addi r4,r31,3452
	ctx.r4.s64 = ctx.r31.s64 + 3452;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821753c8
	ctx.lr = 0x82178094;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821780b0
	if (!ctx.cr6.eq) goto loc_821780B0;
	// addi r4,r31,3452
	ctx.r4.s64 = ctx.r31.s64 + 3452;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x821780AC;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821780B0;
	sub_8207B288(ctx, base);
loc_821780B0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x821780B8;
	sub_82175D08(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3460
	ctx.r4.s64 = ctx.r31.s64 + 3460;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821753c8
	ctx.lr = 0x821780D8;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821780f4
	if (!ctx.cr6.eq) goto loc_821780F4;
	// addi r4,r31,3460
	ctx.r4.s64 = ctx.r31.s64 + 3460;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x821780F0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821780F4;
	sub_8207B288(ctx, base);
loc_821780F4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x821780FC;
	sub_82175D08(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3476
	ctx.r4.s64 = ctx.r31.s64 + 3476;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821753c8
	ctx.lr = 0x8217811C;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82178138
	if (!ctx.cr6.eq) goto loc_82178138;
	// addi r4,r31,3476
	ctx.r4.s64 = ctx.r31.s64 + 3476;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82178134;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82178138;
	sub_8207B288(ctx, base);
loc_82178138:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x82178140;
	sub_82175BB0(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3492
	ctx.r4.s64 = ctx.r31.s64 + 3492;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// bl 0x821753c8
	ctx.lr = 0x82178160;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217817c
	if (!ctx.cr6.eq) goto loc_8217817C;
	// addi r4,r31,3492
	ctx.r4.s64 = ctx.r31.s64 + 3492;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82178178;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217817C;
	sub_8207B288(ctx, base);
loc_8217817C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175e40
	ctx.lr = 0x82178184;
	sub_82175E40(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3520
	ctx.r4.s64 = ctx.r31.s64 + 3520;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// stb r3,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r3.u8);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821753c8
	ctx.lr = 0x821781A4;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821781c0
	if (!ctx.cr6.eq) goto loc_821781C0;
	// addi r4,r31,3520
	ctx.r4.s64 = ctx.r31.s64 + 3520;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x821781BC;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821781C0;
	sub_8207B288(ctx, base);
loc_821781C0:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821749c8
	ctx.lr = 0x821781C8;
	sub_821749C8(ctx, base);
	// lwz r26,80(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r28,24(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// addi r27,r11,-11
	ctx.r27.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x821781E4;
	sub_82174AF8(ctx, base);
	// add r10,r27,r28
	ctx.r10.u64 = ctx.r27.u64 + ctx.r28.u64;
	// lbzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + ctx.r28.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x82178220;
	sub_82174818(ctx, base);
	// lwz r6,28(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 28);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// addi r4,r31,3536
	ctx.r4.s64 = ctx.r31.s64 + 3536;
	// add r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 + ctx.r6.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// bl 0x821753c8
	ctx.lr = 0x82178248;
	sub_821753C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82178264
	if (!ctx.cr6.eq) goto loc_82178264;
	// addi r4,r31,3536
	ctx.r4.s64 = ctx.r31.s64 + 3536;
	// addi r3,r31,1056
	ctx.r3.s64 = ctx.r31.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x82178260;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x82178264;
	sub_8207B288(ctx, base);
loc_82178264:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x8217826C;
	sub_82175D08(ctx, base);
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// stw r3,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_8217827C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,12(r29)
	PPC_STORE_U8(ctx.r29.u32 + 12, ctx.r11.u8);
loc_82178284:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217828C"))) PPC_WEAK_FUNC(sub_8217828C);
PPC_FUNC_IMPL(__imp__sub_8217828C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178290"))) PPC_WEAK_FUNC(sub_82178290);
PPC_FUNC_IMPL(__imp__sub_82178290) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82178298;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,300
	ctx.r30.s64 = ctx.r3.s64 + 300;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x821746a0
	ctx.lr = 0x821782B0;
	sub_821746A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8217831c
	if (ctx.cr6.eq) goto loc_8217831C;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x821782D4;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217831c
	if (ctx.cr6.eq) goto loc_8217831C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x821782E8;
	sub_82175D08(ctx, base);
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// li r8,524
	ctx.r8.s64 = 524;
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217830c
	if (ctx.cr6.lt) goto loc_8217830C;
	// twi 31,r0,22
loc_8217830C:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8217831C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178328"))) PPC_WEAK_FUNC(sub_82178328);
PPC_FUNC_IMPL(__imp__sub_82178328) {
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
	// addi r4,r4,64
	ctx.r4.s64 = ctx.r4.s64 + 64;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x820601f8
	ctx.lr = 0x82178360;
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

__attribute__((alias("__imp__sub_82178378"))) PPC_WEAK_FUNC(sub_82178378);
PPC_FUNC_IMPL(__imp__sub_82178378) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82178380;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r6,20(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r29,r3,8
	ctx.r29.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// addi r30,r4,4
	ctx.r30.s64 = ctx.r4.s64 + 4;
	// blt cr6,0x821783ac
	if (ctx.cr6.lt) goto loc_821783AC;
	// lwz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x821783b0
	goto loc_821783B0;
loc_821783AC:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
loc_821783B0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// bl 0x820654f8
	ctx.lr = 0x821783BC;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821783e0
	if (!ctx.cr6.eq) goto loc_821783E0;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821783d8
	if (ctx.cr6.lt) goto loc_821783D8;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821783D8;
	sub_8207A630(ctx, base);
loc_821783D8:
	// li r29,0
	ctx.r29.s64 = 0;
	// b 0x82178410
	goto loc_82178410;
loc_821783E0:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820601f8
	ctx.lr = 0x821783F4;
	sub_820601F8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// stb r29,176(r28)
	PPC_STORE_U8(ctx.r28.u32 + 176, ctx.r29.u8);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82178410
	if (ctx.cr6.lt) goto loc_82178410;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82178410;
	sub_8207A630(ctx, base);
loc_82178410:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stb r29,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r29.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178428"))) PPC_WEAK_FUNC(sub_82178428);
PPC_FUNC_IMPL(__imp__sub_82178428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x82178430;
	__savegprlr_19(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r26,44
	ctx.r26.s64 = 44;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// std r7,304(r1)
	PPC_STORE_U64(ctx.r1.u32 + 304, ctx.r7.u64);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// mr r21,r6
	ctx.r21.u64 = ctx.r6.u64;
	// addi r29,r3,16
	ctx.r29.s64 = ctx.r3.s64 + 16;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// divw. r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82178690
	if (ctx.cr0.eq) goto loc_82178690;
	// lwz r19,308(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// lwz r22,304(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// li r23,15
	ctx.r23.s64 = 15;
loc_82178478:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178494
	if (ctx.cr6.lt) goto loc_82178494;
	// twi 31,r0,22
loc_82178494:
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r22
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r22.u32, ctx.xer);
	// lwz r11,44(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// bne cr6,0x821784b4
	if (!ctx.cr6.eq) goto loc_821784B4;
	// cmplw cr6,r11,r19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r19.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x821784b8
	if (ctx.cr6.eq) goto loc_821784B8;
loc_821784B4:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_821784B8:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82178670
	if (ctx.cr6.eq) goto loc_82178670;
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r23.u32);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r25.u32);
	// stb r25,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r25.u8);
loc_821784D4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821784d4
	if (!ctx.cr6.eq) goto loc_821784D4;
	// subf r11,r24,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r24.s64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821784FC;
	sub_82060368(ctx, base);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178518
	if (ctx.cr6.lt) goto loc_82178518;
	// twi 31,r0,22
loc_82178518:
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r31,r11,12
	ctx.r31.s64 = ctx.r11.s64 + 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820704e8
	ctx.lr = 0x8217852C;
	sub_820704E8(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// bne cr6,0x8217853c
	if (!ctx.cr6.eq) goto loc_8217853C;
	// twi 31,r0,22
loc_8217853C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// beq cr6,0x82178558
	if (ctx.cr6.eq) goto loc_82178558;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8217855c
	if (ctx.cr6.eq) goto loc_8217855C;
loc_82178558:
	// twi 31,r0,22
loc_8217855C:
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x821785a0
	if (ctx.cr6.eq) goto loc_821785A0;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
	// lwz r6,32(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82178580
	if (ctx.cr6.lt) goto loc_82178580;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82178584
	goto loc_82178584;
loc_82178580:
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
loc_82178584:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x820654f8
	ctx.lr = 0x82178590;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821785a0
	if (ctx.cr6.lt) goto loc_821785A0;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// b 0x821785b4
	goto loc_821785B4;
loc_821785A0:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
loc_821785B4:
	// ld r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// blt cr6,0x821785d0
	if (ctx.cr6.lt) goto loc_821785D0;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x821785D0;
	sub_8207A630(ctx, base);
loc_821785D0:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// stw r23,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r23.u32);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// stw r25,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r25.u32);
	// stb r25,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r25.u8);
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821785f8
	if (ctx.cr6.lt) goto loc_821785F8;
	// twi 31,r0,22
loc_821785F8:
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// lwz r31,104(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// beq cr6,0x8217861c
	if (ctx.cr6.eq) goto loc_8217861C;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82178620
	if (ctx.cr6.eq) goto loc_82178620;
loc_8217861C:
	// twi 31,r0,22
loc_82178620:
	// lwz r30,108(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82178670
	if (ctx.cr6.eq) goto loc_82178670;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// bne cr6,0x8217869c
	if (!ctx.cr6.eq) goto loc_8217869C;
	// twi 31,r0,22
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_82178644:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82178654
	if (!ctx.cr6.eq) goto loc_82178654;
	// twi 31,r0,22
loc_82178654:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r3,r30,40
	ctx.r3.s64 = ctx.r30.s64 + 40;
	// bl 0x821753c8
	ctx.lr = 0x82178664;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821786a4
	if (!ctx.cr6.eq) goto loc_821786A4;
loc_82178670:
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r27,r27,44
	ctx.r27.s64 = ctx.r27.s64 + 44;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178478
	if (ctx.cr6.lt) goto loc_82178478;
loc_82178690:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_8217869C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x82178644
	goto loc_82178644;
loc_821786A4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82178770
	if (!ctx.cr6.eq) goto loc_82178770;
	// twi 31,r0,22
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_821786B4:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x821786c4
	if (!ctx.cr6.eq) goto loc_821786C4;
	// twi 31,r0,22
loc_821786C4:
	// lwz r11,48(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r31,r10,-19056
	ctx.r31.s64 = ctx.r10.s64 + -19056;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// addi r5,r31,-36
	ctx.r5.s64 = ctx.r31.s64 + -36;
	// stw r11,0(r21)
	PPC_STORE_U32(ctx.r21.u32 + 0, ctx.r11.u32);
	// bl 0x82175ae8
	ctx.lr = 0x821786E4;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x821786E8;
	sub_82175BB0(ctx, base);
	// stfs f1,20(r21)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r21.u32 + 20, temp.u32);
	// addi r5,r31,-28
	ctx.r5.s64 = ctx.r31.s64 + -28;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x821786FC;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x82178700;
	sub_82175BB0(ctx, base);
	// stfs f1,24(r21)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r21.u32 + 24, temp.u32);
	// addi r5,r31,-20
	ctx.r5.s64 = ctx.r31.s64 + -20;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x82178714;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x82178718;
	sub_82175D08(ctx, base);
	// stw r3,4(r21)
	PPC_STORE_U32(ctx.r21.u32 + 4, ctx.r3.u32);
	// addi r5,r31,-12
	ctx.r5.s64 = ctx.r31.s64 + -12;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8217872C;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x82178730;
	sub_82175D08(ctx, base);
	// stw r3,8(r21)
	PPC_STORE_U32(ctx.r21.u32 + 8, ctx.r3.u32);
	// addi r5,r31,-8
	ctx.r5.s64 = ctx.r31.s64 + -8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x82178744;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x82178748;
	sub_82175D08(ctx, base);
	// stw r3,12(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8217875C;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x82178760;
	sub_82175D08(ctx, base);
	// stw r3,16(r21)
	PPC_STORE_U32(ctx.r21.u32 + 16, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
loc_82178770:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// b 0x821786b4
	goto loc_821786B4;
}

__attribute__((alias("__imp__sub_82178778"))) PPC_WEAK_FUNC(sub_82178778);
PPC_FUNC_IMPL(__imp__sub_82178778) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x82178780;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r7,256(r1)
	PPC_STORE_U64(ctx.r1.u32 + 256, ctx.r7.u64);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// bl 0x821746a0
	ctx.lr = 0x821787A0;
	sub_821746A0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r26,r11,-20780
	ctx.r26.s64 = ctx.r11.s64 + -20780;
	// beq cr6,0x8217881c
	if (ctx.cr6.eq) goto loc_8217881C;
	// addi r5,r26,1648
	ctx.r5.s64 = ctx.r26.s64 + 1648;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x821787C4;
	sub_82175AE8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// bl 0x821753c8
	ctx.lr = 0x821787DC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217881c
	if (ctx.cr6.eq) goto loc_8217881C;
	// addi r5,r26,1656
	ctx.r5.s64 = ctx.r26.s64 + 1656;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x821787F8;
	sub_82175AE8(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821753c8
	ctx.lr = 0x82178804;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217881c
	if (ctx.cr6.eq) goto loc_8217881C;
loc_82178810:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
loc_8217881C:
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// li r28,44
	ctx.r28.s64 = 44;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r8,r9,r28
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82178964
	if (ctx.cr0.eq) goto loc_82178964;
	// lwz r22,260(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// lwz r25,256(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
loc_82178848:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r28
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178864
	if (ctx.cr6.lt) goto loc_82178864;
	// twi 31,r0,22
loc_82178864:
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r25
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r25.u32, ctx.xer);
	// lwz r11,44(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// bne cr6,0x82178884
	if (!ctx.cr6.eq) goto loc_82178884;
	// cmplw cr6,r11,r22
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r22.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x82178888
	if (ctx.cr6.eq) goto loc_82178888;
loc_82178884:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_82178888:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82178944
	if (!ctx.cr6.eq) goto loc_82178944;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r28
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821788b0
	if (ctx.cr6.lt) goto loc_821788B0;
	// twi 31,r0,22
loc_821788B0:
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r4,r26,1664
	ctx.r4.s64 = ctx.r26.s64 + 1664;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x821753c8
	ctx.lr = 0x821788DC;
	sub_821753C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x821788f8
	if (!ctx.cr6.eq) goto loc_821788F8;
	// addi r4,r26,1664
	ctx.r4.s64 = ctx.r26.s64 + 1664;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8207bc98
	ctx.lr = 0x821788F4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x821788F8;
	sub_8207B288(ctx, base);
loc_821788F8:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x82178910;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82178944
	if (ctx.cr6.eq) goto loc_82178944;
	// addi r5,r26,1672
	ctx.r5.s64 = ctx.r26.s64 + 1672;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8217892C;
	sub_82175AE8(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// bl 0x821753c8
	ctx.lr = 0x82178938;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82178810
	if (!ctx.cr6.eq) goto loc_82178810;
loc_82178944:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r29,r29,44
	ctx.r29.s64 = ctx.r29.s64 + 44;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r28
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178848
	if (ctx.cr6.lt) goto loc_82178848;
loc_82178964:
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r24)
	PPC_STORE_U64(ctx.r24.u32 + 0, ctx.r11.u64);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178980"))) PPC_WEAK_FUNC(sub_82178980);
PPC_FUNC_IMPL(__imp__sub_82178980) {
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
	// lbz r11,12(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 12);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82178a9c
	if (!ctx.cr6.eq) goto loc_82178A9C;
	// lwz r8,16(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x821789c0
	if (!ctx.cr6.eq) goto loc_821789C0;
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,20(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82178a9c
	if (ctx.cr6.eq) goto loc_82178A9C;
loc_821789C0:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_821789C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x821789e8
	if (ctx.cr6.eq) goto loc_821789E8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821789c4
	if (ctx.cr6.eq) goto loc_821789C4;
loc_821789E8:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82178a24
	if (!ctx.cr6.eq) goto loc_82178A24;
	// lwz r10,20(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
loc_821789F8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x82178a1c
	if (ctx.cr6.eq) goto loc_82178A1C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821789f8
	if (ctx.cr6.eq) goto loc_821789F8;
loc_82178A1C:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82178a9c
	if (ctx.cr6.eq) goto loc_82178A9C;
loc_82178A24:
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r5,20(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// rotlwi r4,r8,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// lwz r11,132(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82178428
	ctx.lr = 0x82178A54;
	sub_82178428(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stb r3,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r3.u8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82178a9c
	if (ctx.cr6.eq) goto loc_82178A9C;
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lwz r8,108(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// stw r7,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
loc_82178A9C:
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

__attribute__((alias("__imp__sub_82178AB0"))) PPC_WEAK_FUNC(sub_82178AB0);
PPC_FUNC_IMPL(__imp__sub_82178AB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,404(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r9,r3,392
	ctx.r9.s64 = ctx.r3.s64 + 392;
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// li r7,12
	ctx.r7.s64 = 12;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82178ae8
	if (!ctx.cr6.eq) goto loc_82178AE8;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82178af4
	goto loc_82178AF4;
loc_82178AE8:
	// lwz r11,20(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r8,r7
	ctx.r8.s32 = ppc_divw(ctx.r8.s32, ctx.r7.s32);
loc_82178AF4:
	// lwz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// subf r3,r10,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r7,r3,r7
	ctx.r7.s32 = ppc_divw(ctx.r3.s32, ctx.r7.s32);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82178b34
	if (!ctx.cr6.lt) goto loc_82178B34;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82178b1c
	if (ctx.cr6.eq) goto loc_82178B1C;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// stw r4,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r4.u32);
	// stw r5,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
loc_82178B1C:
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// stw r11,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82178B34:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82178b40
	if (!ctx.cr6.gt) goto loc_82178B40;
	// twi 31,r0,22
loc_82178B40:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206f380
	ctx.lr = 0x82178B60;
	sub_8206F380(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178B70"))) PPC_WEAK_FUNC(sub_82178B70);
PPC_FUNC_IMPL(__imp__sub_82178B70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stfs f1,308(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 308, temp.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x82178B88;
	sub_82079FD8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82178ba0
	if (ctx.cr6.eq) goto loc_82178BA0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82178ba4
	goto loc_82178BA4;
loc_82178BA0:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82178BA4:
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bl 0x8207a630
	ctx.lr = 0x82178BB8;
	sub_8207A630(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178BC8"))) PPC_WEAK_FUNC(sub_82178BC8);
PPC_FUNC_IMPL(__imp__sub_82178BC8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82178BD0;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,456(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 456);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r10,452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 452);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// addi r31,r3,440
	ctx.r31.s64 = ctx.r3.s64 + 440;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r23,524
	ctx.r23.s64 = 524;
	// li r30,0
	ctx.r30.s64 = 0;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82178c74
	if (ctx.cr0.eq) goto loc_82178C74;
	// addi r28,r3,240
	ctx.r28.s64 = ctx.r3.s64 + 240;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82178C04:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178c20
	if (ctx.cr6.lt) goto loc_82178C20;
	// twi 31,r0,22
loc_82178C20:
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwzx r10,r29,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r10.u32);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r7,r8,r23
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r23.s32);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82178c40
	if (ctx.cr6.lt) goto loc_82178C40;
	// twi 31,r0,22
loc_82178C40:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,520(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 520);
	// bl 0x8206e258
	ctx.lr = 0x82178C54;
	sub_8206E258(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r30,r7
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82178c04
	if (ctx.cr6.lt) goto loc_82178C04;
loc_82178C74:
	// lwz r11,480(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 480);
	// addi r28,r27,464
	ctx.r28.s64 = ctx.r27.s64 + 464;
	// lwz r10,476(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 476);
	// li r24,0
	ctx.r24.s64 = 0;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82178d70
	if (ctx.cr0.eq) goto loc_82178D70;
	// addi r25,r27,240
	ctx.r25.s64 = ctx.r27.s64 + 240;
	// li r27,0
	ctx.r27.s64 = 0;
loc_82178C98:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178cb4
	if (ctx.cr6.lt) goto loc_82178CB4;
	// twi 31,r0,22
loc_82178CB4:
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// lwz r9,16(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// lwzx r10,r27,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r10.u32);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r7,r8,r23
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r23.s32);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82178cd4
	if (ctx.cr6.lt) goto loc_82178CD4;
	// twi 31,r0,22
loc_82178CD4:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r11,520(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 520);
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi. r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x82178d50
	if (ctx.cr0.eq) goto loc_82178D50;
	// li r30,0
	ctx.r30.s64 = 0;
loc_82178D00:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178d1c
	if (ctx.cr6.lt) goto loc_82178D1C;
	// twi 31,r0,22
loc_82178D1C:
	// add r4,r30,r10
	ctx.r4.u64 = ctx.r30.u64 + ctx.r10.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8206e258
	ctx.lr = 0x82178D28;
	sub_8206E258(ctx, base);
	// lwz r11,520(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 520);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r11,r11,48
	ctx.r11.s64 = ctx.r11.s64 + 48;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r31,r7
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82178d00
	if (ctx.cr6.lt) goto loc_82178D00;
loc_82178D50:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82178c98
	if (ctx.cr6.lt) goto loc_82178C98;
loc_82178D70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82178D78"))) PPC_WEAK_FUNC(sub_82178D78);
PPC_FUNC_IMPL(__imp__sub_82178D78) {
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
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// stw r4,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x82178da0
	if (!ctx.cr6.eq) goto loc_82178DA0;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82178dac
	goto loc_82178DAC;
loc_82178DA0:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
loc_82178DAC:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r6,r8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82178ddc
	if (!ctx.cr6.lt) goto loc_82178DDC;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_82178DDC:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82178de8
	if (!ctx.cr6.gt) goto loc_82178DE8;
	// twi 31,r0,22
loc_82178DE8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r6,r1,140
	ctx.r6.s64 = ctx.r1.s64 + 140;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x820697e0
	ctx.lr = 0x82178E08;
	sub_820697E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178E18"))) PPC_WEAK_FUNC(sub_82178E18);
PPC_FUNC_IMPL(__imp__sub_82178E18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// li r3,4
	ctx.r3.s64 = 4;
	// stfs f1,324(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 324, temp.u32);
	// bl 0x82079fd8
	ctx.lr = 0x82178E34;
	sub_82079FD8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82178e4c
	if (ctx.cr6.eq) goto loc_82178E4C;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82178e50
	goto loc_82178E50;
loc_82178E4C:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82178E50:
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bl 0x8207a630
	ctx.lr = 0x82178E64;
	sub_8207A630(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82178E74"))) PPC_WEAK_FUNC(sub_82178E74);
PPC_FUNC_IMPL(__imp__sub_82178E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82178E78"))) PPC_WEAK_FUNC(sub_82178E78);
PPC_FUNC_IMPL(__imp__sub_82178E78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c95c
	ctx.lr = 0x82178E80;
	__savegprlr_17(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,256(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// li r18,524
	ctx.r18.s64 = 524;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r25,r3,240
	ctx.r25.s64 = ctx.r3.s64 + 240;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r24,0
	ctx.r24.s64 = 0;
	// divw r8,r9,r18
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r18.s32);
	// li r22,0
	ctx.r22.s64 = 0;
	// addic. r21,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r21.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq 0x8217915c
	if (ctx.cr0.eq) goto loc_8217915C;
	// addi r20,r3,284
	ctx.r20.s64 = ctx.r3.s64 + 284;
	// li r23,0
	ctx.r23.s64 = 0;
	// li r17,100
	ctx.r17.s64 = 100;
	// li r19,255
	ctx.r19.s64 = 255;
loc_82178EC0:
	// subf r11,r22,r21
	ctx.r11.s64 = ctx.r21.s64 - ctx.r22.s64;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x82178ED4;
	sub_82175648(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x82178ED8;
	sub_82175D08(ctx, base);
	// lwz r11,12(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 12);
	// lwz r9,16(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + 16);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r7,r8,r18
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r18.s32);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82178ef8
	if (ctx.cr6.lt) goto loc_82178EF8;
	// twi 31,r0,22
loc_82178EF8:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82178f68
	if (!ctx.cr6.eq) goto loc_82178F68;
	// lwz r11,520(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 520);
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r11,48
	ctx.r30.s64 = ctx.r11.s64 + 48;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// lwz r11,60(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi. r10,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82179150
	if (ctx.cr0.eq) goto loc_82179150;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82178f3c
	if (ctx.cr6.lt) goto loc_82178F3C;
	// twi 31,r0,22
loc_82178F3C:
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// bl 0x82178e78
	ctx.lr = 0x82178F44;
	sub_82178E78(ctx, base);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r10,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82178f3c
	if (ctx.cr6.lt) goto loc_82178F3C;
	// b 0x82179150
	goto loc_82179150;
loc_82178F68:
	// lbz r10,436(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 436);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82179150
	if (ctx.cr6.eq) goto loc_82179150;
	// lbz r10,437(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 437);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82179150
	if (ctx.cr6.eq) goto loc_82179150;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x82178f98
	if (!ctx.cr6.eq) goto loc_82178F98;
	// lwz r11,520(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 520);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x82178e78
	ctx.lr = 0x82178F94;
	sub_82178E78(ctx, base);
	// b 0x82179150
	goto loc_82179150;
loc_82178F98:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82179150
	if (!ctx.cr6.eq) goto loc_82179150;
	// lbz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82179150
	if (ctx.cr6.eq) goto loc_82179150;
	// lwz r11,508(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 508);
	// lwz r10,504(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 504);
	// lwz r9,432(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mulli r11,r9,148
	ctx.r11.s64 = ctx.r9.s64 * 148;
	// divw r7,r8,r17
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r17.s32);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplw cr6,r24,r7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82178fd4
	if (ctx.cr6.lt) goto loc_82178FD4;
	// twi 31,r0,22
loc_82178FD4:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r30,r23,r10
	ctx.r30.u64 = ctx.r23.u64 + ctx.r10.u64;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r23,r23,100
	ctx.r23.s64 = ctx.r23.s64 + 100;
	// stw r9,92(r30)
	PPC_STORE_U32(ctx.r30.u32 + 92, ctx.r9.u32);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r8,88(r30)
	PPC_STORE_U32(ctx.r30.u32 + 88, ctx.r8.u32);
	// lfs f0,308(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r7,156(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// stw r7,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r7.u32);
	// lwz r6,228(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 228);
	// stw r6,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r6.u32);
	// lwz r5,232(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 232);
	// stw r5,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r5.u32);
	// lfs f13,440(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,16(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// lfs f12,444(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,20(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// lfs f11,448(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,24(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// stw r4,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r4.u32);
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stfs f8,32(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f7,88(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,36(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r30.u32 + 36, temp.u32);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f4,96(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// stfs f2,40(r30)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r30.u32 + 40, temp.u32);
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// lfd f1,104(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f1
	ctx.f0.f64 = double(ctx.f1.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// stfs f13,44(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 44, temp.u32);
	// lwz r3,140(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 140);
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821790c0
	if (ctx.cr6.eq) goto loc_821790C0;
	// lfs f0,160(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// lfs f13,164(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// b 0x821790cc
	goto loc_821790CC;
loc_821790C0:
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 48, temp.u32);
	// lfs f13,128(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
loc_821790CC:
	// stfs f13,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 52, temp.u32);
	// addi r27,r30,68
	ctx.r27.s64 = ctx.r30.s64 + 68;
	// lfs f0,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r31,48
	ctx.r29.s64 = ctx.r31.s64 + 48;
	// stfs f0,56(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// li r28,4
	ctx.r28.s64 = 4;
	// lfs f13,68(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,60(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 60, temp.u32);
	// lfs f12,72(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,64(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 64, temp.u32);
	// lfs f11,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,68(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 68, temp.u32);
loc_821790FC:
	// lwz r10,472(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 472);
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// beq cr6,0x82179120
	if (ctx.cr6.eq) goto loc_82179120;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// rlwinm r8,r11,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF00;
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// divwu r6,r7,r19
	ctx.r6.u32 = ppc_divwu(ctx.r7.u32, ctx.r19.u32);
	// or r11,r6,r8
	ctx.r11.u64 = ctx.r6.u64 | ctx.r8.u64;
loc_82179120:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r4,236(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 236);
	// bl 0x8206d328
	ctx.lr = 0x8217912C;
	sub_8206D328(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stwu r3,4(r27)
	ea = 4 + ctx.r27.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r27.u32 = ea;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// bne 0x821790fc
	if (!ctx.cr0.eq) goto loc_821790FC;
	// lwz r11,516(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 516);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,96(r30)
	PPC_STORE_U32(ctx.r30.u32 + 96, ctx.r11.u32);
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82178d78
	ctx.lr = 0x82179150;
	sub_82178D78(ctx, base);
loc_82179150:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// cmplw cr6,r22,r21
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r21.u32, ctx.xer);
	// blt cr6,0x82178ec0
	if (ctx.cr6.lt) goto loc_82178EC0;
loc_8217915C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9ac
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179164"))) PPC_WEAK_FUNC(sub_82179164);
PPC_FUNC_IMPL(__imp__sub_82179164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179168"))) PPC_WEAK_FUNC(sub_82179168);
PPC_FUNC_IMPL(__imp__sub_82179168) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c95c
	ctx.lr = 0x82179170;
	__savegprlr_17(ctx, base);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x82080368
	ctx.lr = 0x82179178;
	__savefpr_28(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,256(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// li r17,524
	ctx.r17.s64 = 524;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// addi r18,r3,240
	ctx.r18.s64 = ctx.r3.s64 + 240;
	// mr r21,r23
	ctx.r21.u64 = ctx.r23.u64;
	// divw. r8,r9,r17
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r17.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x821795b8
	if (ctx.cr0.eq) goto loc_821795B8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r22,1
	ctx.r22.s64 = 1;
	// li r19,36
	ctx.r19.s64 = 36;
	// lfs f28,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f28.f64 = double(temp.f32);
loc_821791B4:
	// lwz r11,12(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// lwz r10,16(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r17
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r17.s32);
	// cmplw cr6,r21,r8
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821791d0
	if (ctx.cr6.lt) goto loc_821791D0;
	// twi 31,r0,22
loc_821791D0:
	// mulli r10,r21,524
	ctx.r10.s64 = ctx.r21.s64 * 524;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// addi r30,r28,436
	ctx.r30.s64 = ctx.r28.s64 + 436;
	// addi r11,r28,476
	ctx.r11.s64 = ctx.r28.s64 + 476;
	// bne cr6,0x82179208
	if (!ctx.cr6.eq) goto loc_82179208;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// addi r10,r30,-4
	ctx.r10.s64 = ctx.r30.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_821791F8:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x821791f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821791F8;
	// b 0x8217959c
	goto loc_8217959C;
loc_82179208:
	// lwz r11,432(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 432);
	// mulli r10,r11,148
	ctx.r10.s64 = ctx.r11.s64 * 148;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// addi r31,r10,132
	ctx.r31.s64 = ctx.r10.s64 + 132;
	// mulli r11,r9,148
	ctx.r11.s64 = ctx.r9.s64 * 148;
	// lbz r8,144(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 144);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r29,r11,132
	ctx.r29.s64 = ctx.r11.s64 + 132;
	// bne cr6,0x8217959c
	if (!ctx.cr6.eq) goto loc_8217959C;
	// lbz r11,13(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 13);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821794c4
	if (ctx.cr6.eq) goto loc_821794C4;
	// lbz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821794c4
	if (!ctx.cr6.eq) goto loc_821794C4;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r31,108
	ctx.r6.s64 = ctx.r31.s64 + 108;
	// lfs f13,184(r20)
	temp.u32 = PPC_LOAD_U32(ctx.r20.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stb r22,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r22.u8);
	// lbz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 68);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stb r11,2(r30)
	PPC_STORE_U8(ctx.r30.u32 + 2, ctx.r11.u8);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lbz r10,69(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 69);
	// fdivs f30,f11,f10
	ctx.f30.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// stb r10,3(r30)
	PPC_STORE_U8(ctx.r30.u32 + 3, ctx.r10.u8);
	// lfs f2,72(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// lfs f1,72(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206cea0
	ctx.lr = 0x82179290;
	sub_8206CEA0(ctx, base);
	// stfs f1,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// addi r27,r31,116
	ctx.r27.s64 = ctx.r31.s64 + 116;
	// lfs f2,76(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lfs f1,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206ce40
	ctx.lr = 0x821792AC;
	sub_8206CE40(ctx, base);
	// stfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lfs f2,80(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// bl 0x8206ce40
	ctx.lr = 0x821792C4;
	sub_8206CE40(ctx, base);
	// stfs f1,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// addi r27,r31,124
	ctx.r27.s64 = ctx.r31.s64 + 124;
	// lfs f2,84(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 84);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// bl 0x8206ce40
	ctx.lr = 0x821792E0;
	sub_8206CE40(ctx, base);
	// stfs f1,28(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// lfs f2,88(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// bl 0x8206ce40
	ctx.lr = 0x821792F8;
	sub_8206CE40(ctx, base);
	// stfs f1,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// addi r6,r29,56
	ctx.r6.s64 = ctx.r29.s64 + 56;
	// ld r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 92);
	// addi r5,r31,56
	ctx.r5.s64 = ctx.r31.s64 + 56;
	// ld r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 132);
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206d0f0
	ctx.lr = 0x8217931C;
	sub_8206D0F0(ctx, base);
	// lwz r5,52(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f8,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r23.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r23.u32);
	// fmr f3,f30
	ctx.f3.f64 = ctx.f30.f64;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f6,f9
	ctx.f6.f64 = double(ctx.f9.s64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f1,f6
	ctx.f1.f64 = double(float(ctx.f6.f64));
	// frsp f2,f7
	ctx.f2.f64 = double(float(ctx.f7.f64));
	// bl 0x8206ce40
	ctx.lr = 0x82179358;
	sub_8206CE40(ctx, base);
	// bl 0x8206c5f8
	ctx.lr = 0x8217935C;
	sub_8206C5F8(ctx, base);
	// fctidz f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfiwx f5,r30,r19
	PPC_STORE_U32(ctx.r30.u32 + ctx.r19.u32, ctx.f5.u32);
	// addi r25,r31,100
	ctx.r25.s64 = ctx.r31.s64 + 100;
	// addi r26,r28,44
	ctx.r26.s64 = ctx.r28.s64 + 44;
	// addi r27,r31,36
	ctx.r27.s64 = ctx.r31.s64 + 36;
	// subf r24,r31,r29
	ctx.r24.s64 = ctx.r29.s64 - ctx.r31.s64;
	// li r30,4
	ctx.r30.s64 = 4;
loc_82179378:
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// lwzx r4,r24,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r27.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206cf78
	ctx.lr = 0x8217938C;
	sub_8206CF78(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r3,4(r26)
	ea = 4 + ctx.r26.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r26.u32 = ea;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// bne 0x82179378
	if (!ctx.cr0.eq) goto loc_82179378;
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x8217959c
	if (!ctx.cr6.eq) goto loc_8217959C;
	// lwz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f29,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// beq cr6,0x821793d8
	if (ctx.cr6.eq) goto loc_821793D8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206cba0
	ctx.lr = 0x821793CC;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f29,f1
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_821793D8:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stfs f31,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 28, temp.u32);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f29,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// beq cr6,0x82179410
	if (ctx.cr6.eq) goto loc_82179410;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206cba0
	ctx.lr = 0x82179404;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f29,f1
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_82179410:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stfs f31,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r9,144(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// lfs f31,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// lfs f29,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// beq cr6,0x82179448
	if (ctx.cr6.eq) goto loc_82179448;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206cba0
	ctx.lr = 0x8217943C;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f29,f1
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_82179448:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stfs f31,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 36, temp.u32);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f29,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// beq cr6,0x82179480
	if (ctx.cr6.eq) goto loc_82179480;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206cba0
	ctx.lr = 0x82179474;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f29,f1
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_82179480:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stfs f31,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 40, temp.u32);
	// lwz r10,144(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 144);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f29,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// beq cr6,0x821794b8
	if (ctx.cr6.eq) goto loc_821794B8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206cba0
	ctx.lr = 0x821794AC;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f29,f1
	ctx.f13.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_821794B8:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stfs f31,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// b 0x8217959c
	goto loc_8217959C;
loc_821794C4:
	// stb r22,0(r30)
	PPC_STORE_U8(ctx.r30.u32 + 0, ctx.r22.u8);
	// lbz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 68);
	// stb r11,2(r30)
	PPC_STORE_U8(ctx.r30.u32 + 2, ctx.r11.u8);
	// lbz r10,69(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 69);
	// stb r10,3(r30)
	PPC_STORE_U8(ctx.r30.u32 + 3, ctx.r10.u8);
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,16(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// lfs f13,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// lfs f12,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,24(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 24, temp.u32);
	// lfs f11,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,28(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 28, temp.u32);
	// lfs f10,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,32(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r30.u32 + 32, temp.u32);
	// lfs f9,56(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,4(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r30.u32 + 4, temp.u32);
	// lfs f8,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,8(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 8, temp.u32);
	// lfs f7,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,12(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 12, temp.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// stw r9,48(r28)
	PPC_STORE_U32(ctx.r28.u32 + 48, ctx.r9.u32);
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stw r8,52(r28)
	PPC_STORE_U32(ctx.r28.u32 + 52, ctx.r8.u32);
	// lwz r7,44(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// stw r7,56(r28)
	PPC_STORE_U32(ctx.r28.u32 + 56, ctx.r7.u32);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// stw r6,60(r28)
	PPC_STORE_U32(ctx.r28.u32 + 60, ctx.r6.u32);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r5,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r5.u32);
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// bne cr6,0x8217959c
	if (!ctx.cr6.eq) goto loc_8217959C;
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r10,520(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,28(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// lwz r8,144(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r9,520(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,32(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 32, temp.u32);
	// lwz r7,144(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r6,520(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lfs f12,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,36(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 36, temp.u32);
	// lwz r4,520(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,40(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 40, temp.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lfs f10,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,44(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 44, temp.u32);
loc_8217959C:
	// lwz r11,16(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 16);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// lwz r10,12(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r17
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r17.s32);
	// cmplw cr6,r21,r8
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821791b4
	if (ctx.cr6.lt) goto loc_821791B4;
loc_821795B8:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x820803b4
	ctx.lr = 0x821795C4;
	__restfpr_28(ctx, base);
	// b 0x8207c9ac
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821795C8"))) PPC_WEAK_FUNC(sub_821795C8);
PPC_FUNC_IMPL(__imp__sub_821795C8) {
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
	// addi r3,r3,392
	ctx.r3.s64 = ctx.r3.s64 + 392;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821795f0
	if (!ctx.cr6.gt) goto loc_821795F0;
	// twi 31,r0,22
loc_821795F0:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r4,392
	ctx.r31.s64 = ctx.r4.s64 + 392;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// lwz r11,408(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 408);
	// lwz r9,404(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 404);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82179614
	if (!ctx.cr6.gt) goto loc_82179614;
	// twi 31,r0,22
loc_82179614:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x82179634
	if (!ctx.cr6.gt) goto loc_82179634;
	// twi 31,r0,22
loc_82179634:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// ld r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// bl 0x82073080
	ctx.lr = 0x82179650;
	sub_82073080(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82179664
	if (!ctx.cr6.gt) goto loc_82179664;
	// twi 31,r0,22
loc_82179664:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// ble cr6,0x8217967c
	if (!ctx.cr6.gt) goto loc_8217967C;
	// twi 31,r0,22
loc_8217967C:
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ld r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82061c78
	ctx.lr = 0x82179698;
	sub_82061C78(ctx, base);
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

__attribute__((alias("__imp__sub_821796AC"))) PPC_WEAK_FUNC(sub_821796AC);
PPC_FUNC_IMPL(__imp__sub_821796AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821796B0"))) PPC_WEAK_FUNC(sub_821796B0);
PPC_FUNC_IMPL(__imp__sub_821796B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821796B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 236, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82079fd8
	ctx.lr = 0x821796D0;
	sub_82079FD8(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821796ec
	if (ctx.cr6.eq) goto loc_821796EC;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// b 0x821796f0
	goto loc_821796F0;
loc_821796EC:
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
loc_821796F0:
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// bl 0x82178bc8
	ctx.lr = 0x82179708;
	sub_82178BC8(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8217975c
	if (ctx.cr0.eq) goto loc_8217975C;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82179730
	if (ctx.cr6.lt) goto loc_82179730;
	// twi 31,r0,22
loc_82179730:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwzx r3,r30,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	// bl 0x821796b0
	ctx.lr = 0x8217973C;
	sub_821796B0(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82179730
	if (ctx.cr6.lt) goto loc_82179730;
loc_8217975C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179768
	if (ctx.cr6.eq) goto loc_82179768;
	// bl 0x8207a630
	ctx.lr = 0x82179768;
	sub_8207A630(ctx, base);
loc_82179768:
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207a630
	ctx.lr = 0x8217977C;
	sub_8207A630(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179784"))) PPC_WEAK_FUNC(sub_82179784);
PPC_FUNC_IMPL(__imp__sub_82179784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179788"))) PPC_WEAK_FUNC(sub_82179788);
PPC_FUNC_IMPL(__imp__sub_82179788) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82179790;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 228, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 232, ctx.r5.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x82079fd8
	ctx.lr = 0x821797B0;
	sub_82079FD8(ctx, base);
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821797cc
	if (ctx.cr6.eq) goto loc_821797CC;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// b 0x821797d0
	goto loc_821797D0;
loc_821797CC:
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
loc_821797D0:
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// bl 0x82178bc8
	ctx.lr = 0x821797E8;
	sub_82178BC8(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82179840
	if (ctx.cr0.eq) goto loc_82179840;
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82179810
	if (ctx.cr6.lt) goto loc_82179810;
	// twi 31,r0,22
loc_82179810:
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwzx r3,r30,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82179788
	ctx.lr = 0x82179820;
	sub_82179788(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82179810
	if (ctx.cr6.lt) goto loc_82179810;
loc_82179840:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217984c
	if (ctx.cr6.eq) goto loc_8217984C;
	// bl 0x8207a630
	ctx.lr = 0x8217984C;
	sub_8207A630(ctx, base);
loc_8217984C:
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207a630
	ctx.lr = 0x82179860;
	sub_8207A630(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179868"))) PPC_WEAK_FUNC(sub_82179868);
PPC_FUNC_IMPL(__imp__sub_82179868) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82179870;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,456(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 456);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 452);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x821798ac
	if (!ctx.cr6.eq) goto loc_821798AC;
	// lwz r11,480(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 480);
	// lwz r10,476(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 476);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x821798b0
	if (ctx.cr6.eq) goto loc_821798B0;
loc_821798AC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_821798B0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82179928
	if (ctx.cr6.eq) goto loc_82179928;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r30,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r9.s32 >> 2;
	// bl 0x82178bc8
	ctx.lr = 0x821798D4;
	sub_82178BC8(ctx, base);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// srawi r28,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r28.s64 = ctx.r6.s32 >> 2;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x82179928
	if (!ctx.cr6.lt) goto loc_82179928;
	// rlwinm r29,r30,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_821798F0:
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
	// blt cr6,0x8217990c
	if (ctx.cr6.lt) goto loc_8217990C;
	// twi 31,r0,22
loc_8217990C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// bl 0x82179868
	ctx.lr = 0x82179918;
	sub_82179868(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x821798f0
	if (ctx.cr6.lt) goto loc_821798F0;
loc_82179928:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179930"))) PPC_WEAK_FUNC(sub_82179930);
PPC_FUNC_IMPL(__imp__sub_82179930) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82179938;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r11,5260
	ctx.r10.s64 = ctx.r11.s64 + 5260;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821774b0
	ctx.lr = 0x82179950;
	sub_821774B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82176ed0
	ctx.lr = 0x82179958;
	sub_82176ED0(ctx, base);
	// lwz r3,528(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 528);
	// addi r29,r30,516
	ctx.r29.s64 = ctx.r30.s64 + 516;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217996c
	if (ctx.cr6.eq) goto loc_8217996C;
	// bl 0x8207a630
	ctx.lr = 0x8217996C;
	sub_8207A630(ctx, base);
loc_8217996C:
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// bl 0x8207a630
	ctx.lr = 0x82179984;
	sub_8207A630(ctx, base);
	// lwz r3,504(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 504);
	// addi r29,r30,492
	ctx.r29.s64 = ctx.r30.s64 + 492;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179998
	if (ctx.cr6.eq) goto loc_82179998;
	// bl 0x8207a630
	ctx.lr = 0x82179998;
	sub_8207A630(ctx, base);
loc_82179998:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821799AC;
	sub_8207A630(ctx, base);
	// lwz r3,476(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 476);
	// addi r29,r30,464
	ctx.r29.s64 = ctx.r30.s64 + 464;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821799c0
	if (ctx.cr6.eq) goto loc_821799C0;
	// bl 0x8207a630
	ctx.lr = 0x821799C0;
	sub_8207A630(ctx, base);
loc_821799C0:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821799D4;
	sub_8207A630(ctx, base);
	// lwz r3,452(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 452);
	// addi r29,r30,440
	ctx.r29.s64 = ctx.r30.s64 + 440;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821799e8
	if (ctx.cr6.eq) goto loc_821799E8;
	// bl 0x8207a630
	ctx.lr = 0x821799E8;
	sub_8207A630(ctx, base);
loc_821799E8:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821799FC;
	sub_8207A630(ctx, base);
	// lwz r3,428(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 428);
	// addi r29,r30,416
	ctx.r29.s64 = ctx.r30.s64 + 416;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179a10
	if (ctx.cr6.eq) goto loc_82179A10;
	// bl 0x8207a630
	ctx.lr = 0x82179A10;
	sub_8207A630(ctx, base);
loc_82179A10:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82179A24;
	sub_8207A630(ctx, base);
	// lwz r3,404(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 404);
	// addi r29,r30,392
	ctx.r29.s64 = ctx.r30.s64 + 392;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179a38
	if (ctx.cr6.eq) goto loc_82179A38;
	// bl 0x8207a630
	ctx.lr = 0x82179A38;
	sub_8207A630(ctx, base);
loc_82179A38:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82179A4C;
	sub_8207A630(ctx, base);
	// addi r3,r30,360
	ctx.r3.s64 = ctx.r30.s64 + 360;
	// bl 0x8206dd60
	ctx.lr = 0x82179A54;
	sub_8206DD60(ctx, base);
	// lwz r3,344(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 344);
	// addi r29,r30,332
	ctx.r29.s64 = ctx.r30.s64 + 332;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179a68
	if (ctx.cr6.eq) goto loc_82179A68;
	// bl 0x8207a630
	ctx.lr = 0x82179A68;
	sub_8207A630(ctx, base);
loc_82179A68:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82179A7C;
	sub_8207A630(ctx, base);
	// lwz r3,252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 252);
	// addi r29,r30,240
	ctx.r29.s64 = ctx.r30.s64 + 240;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179a90
	if (ctx.cr6.eq) goto loc_82179A90;
	// bl 0x8207a630
	ctx.lr = 0x82179A90;
	sub_8207A630(ctx, base);
loc_82179A90:
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82179AA4;
	sub_8207A630(ctx, base);
	// lwz r11,88(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 88);
	// addi r28,r30,64
	ctx.r28.s64 = ctx.r30.s64 + 64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82179abc
	if (ctx.cr6.lt) goto loc_82179ABC;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82179ABC;
	sub_8207A630(ctx, base);
loc_82179ABC:
	// li r27,15
	ctx.r27.s64 = 15;
	// stw r31,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r31.u32);
	// addi r29,r30,36
	ctx.r29.s64 = ctx.r30.s64 + 36;
	// stw r27,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r27.u32);
	// stb r31,4(r28)
	PPC_STORE_U8(ctx.r28.u32 + 4, ctx.r31.u8);
	// lwz r11,60(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82179ae4
	if (ctx.cr6.lt) goto loc_82179AE4;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82179AE4;
	sub_8207A630(ctx, base);
loc_82179AE4:
	// stw r27,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r27.u32);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// stb r31,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r31.u8);
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82179b08
	if (ctx.cr6.lt) goto loc_82179B08;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82179B08;
	sub_8207A630(ctx, base);
loc_82179B08:
	// stw r27,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r27.u32);
	// stw r31,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r31.u32);
	// stb r31,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r31.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179B1C"))) PPC_WEAK_FUNC(sub_82179B1C);
PPC_FUNC_IMPL(__imp__sub_82179B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179B20"))) PPC_WEAK_FUNC(sub_82179B20);
PPC_FUNC_IMPL(__imp__sub_82179B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82179B28;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,432(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 432);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mulli r11,r11,148
	ctx.r11.s64 = ctx.r11.s64 * 148;
	// li r28,0
	ctx.r28.s64 = 0;
	// add r30,r11,r4
	ctx.r30.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x82179b84
	if (!ctx.cr6.eq) goto loc_82179B84;
	// lwz r11,520(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 520);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179b74
	if (ctx.cr6.eq) goto loc_82179B74;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82179B74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82179B74:
	// lwz r11,520(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 520);
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r28,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r28.u32);
loc_82179B84:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82179bfc
	if (!ctx.cr6.eq) goto loc_82179BFC;
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r10,276(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 276);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lwz r9,156(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r8,276(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 276);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r7,156(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r6,276(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 276);
	// lfs f12,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lwz r4,276(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 276);
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,12(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lfs f10,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,276(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 276);
	// stfs f10,16(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// bl 0x8207a630
	ctx.lr = 0x82179BE8;
	sub_8207A630(ctx, base);
	// stw r28,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r28.u32);
	// lwz r11,520(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 520);
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// addi r4,r11,48
	ctx.r4.s64 = ctx.r11.s64 + 48;
	// bl 0x8206d970
	ctx.lr = 0x82179BFC;
	sub_8206D970(ctx, base);
loc_82179BFC:
	// lbz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r11,144(r30)
	PPC_STORE_U8(ctx.r30.u32 + 144, ctx.r11.u8);
	// bne cr6,0x82179cac
	if (!ctx.cr6.eq) goto loc_82179CAC;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,148(r30)
	PPC_STORE_U32(ctx.r30.u32 + 148, ctx.r11.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r10,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r10.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r9,156(r30)
	PPC_STORE_U32(ctx.r30.u32 + 156, ctx.r9.u32);
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 160, temp.u32);
	// lfs f13,36(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,164(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 164, temp.u32);
	// lwz r8,56(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// stw r8,184(r30)
	PPC_STORE_U32(ctx.r30.u32 + 184, ctx.r8.u32);
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// stw r7,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r7.u32);
	// lwz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// stw r6,172(r30)
	PPC_STORE_U32(ctx.r30.u32 + 172, ctx.r6.u32);
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// stw r5,176(r30)
	PPC_STORE_U32(ctx.r30.u32 + 176, ctx.r5.u32);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r4,180(r30)
	PPC_STORE_U32(ctx.r30.u32 + 180, ctx.r4.u32);
	// lfs f12,60(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,188(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 188, temp.u32);
	// lfs f11,64(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,192(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r30.u32 + 192, temp.u32);
	// lfs f10,68(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,196(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r30.u32 + 196, temp.u32);
	// lbz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 72);
	// stb r3,200(r30)
	PPC_STORE_U8(ctx.r30.u32 + 200, ctx.r3.u8);
	// lbz r11,73(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 73);
	// stb r11,201(r30)
	PPC_STORE_U8(ctx.r30.u32 + 201, ctx.r11.u8);
	// lfs f9,76(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,204(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r30.u32 + 204, temp.u32);
	// lfs f8,80(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,208(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 208, temp.u32);
	// lfs f7,84(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,212(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r30.u32 + 212, temp.u32);
	// lfs f6,88(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,216(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 216, temp.u32);
	// lfs f5,92(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,220(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r30.u32 + 220, temp.u32);
loc_82179CAC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179CB4"))) PPC_WEAK_FUNC(sub_82179CB4);
PPC_FUNC_IMPL(__imp__sub_82179CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82179CB8"))) PPC_WEAK_FUNC(sub_82179CB8);
PPC_FUNC_IMPL(__imp__sub_82179CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82179CC0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r9,432(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 432);
	// mulli r11,r9,148
	ctx.r11.s64 = ctx.r9.s64 * 148;
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r29,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r29.u32);
	// stw r29,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r29.u32);
	// bne cr6,0x82179d0c
	if (!ctx.cr6.eq) goto loc_82179D0C;
	// lwz r11,520(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 520);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r10.u32);
	// lwz r9,520(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 520);
	// stw r29,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r29.u32);
loc_82179D0C:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82179da8
	if (!ctx.cr6.eq) goto loc_82179DA8;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82079fd8
	ctx.lr = 0x82179D20;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82179d44
	if (ctx.cr6.eq) goto loc_82179D44;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// stw r29,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r29.u32);
	// stw r29,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r29.u32);
	// b 0x82179d48
	goto loc_82179D48;
loc_82179D44:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82179D48:
	// stw r11,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// lwz r10,520(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 520);
	// lfs f0,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r9,520(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 520);
	// lwz r8,156(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// lfs f13,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r7,520(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 520);
	// lfs f12,36(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lwz r6,156(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// stfs f12,8(r6)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// lwz r5,520(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 520);
	// lfs f11,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lwz r4,156(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// stfs f11,12(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// lwz r11,520(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 520);
	// lfs f10,44(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// lwz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// stfs f10,16(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lwz r11,520(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 520);
	// addi r4,r11,48
	ctx.r4.s64 = ctx.r11.s64 + 48;
	// bl 0x8206d970
	ctx.lr = 0x82179DA8;
	sub_8206D970(ctx, base);
loc_82179DA8:
	// lbz r11,144(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r11,16(r31)
	PPC_STORE_U8(ctx.r31.u32 + 16, ctx.r11.u8);
	// bne cr6,0x82179e60
	if (!ctx.cr6.eq) goto loc_82179E60;
	// lwz r11,148(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 148);
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r10,152(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 152);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r9,140(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 140);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// lwz r8,156(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 156);
	// stw r8,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// lfs f0,160(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lfs f13,164(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 36, temp.u32);
	// lwz r7,48(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// stw r7,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
	// lwz r6,52(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// stw r6,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r6.u32);
	// lwz r5,56(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// stw r5,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r5.u32);
	// lwz r4,60(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// stw r4,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r4.u32);
	// lfs f12,440(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 440);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,60(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 60, temp.u32);
	// lfs f11,444(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 444);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,64(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// lfs f10,448(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 448);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,68(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lwz r3,472(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 472);
	// stw r3,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// lbz r11,438(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 438);
	// stb r11,72(r31)
	PPC_STORE_U8(ctx.r31.u32 + 72, ctx.r11.u8);
	// lbz r10,439(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 439);
	// stb r10,73(r31)
	PPC_STORE_U8(ctx.r31.u32 + 73, ctx.r10.u8);
	// lfs f9,452(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 452);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,76(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 76, temp.u32);
	// lfs f8,456(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 456);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,80(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 80, temp.u32);
	// lfs f7,460(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 460);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,84(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 84, temp.u32);
	// lfs f6,464(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 464);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,88(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 88, temp.u32);
	// lfs f5,468(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 468);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,92(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + 92, temp.u32);
loc_82179E60:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179E68"))) PPC_WEAK_FUNC(sub_82179E68);
PPC_FUNC_IMPL(__imp__sub_82179E68) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x82178e78
	sub_82178E78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82179E70"))) PPC_WEAK_FUNC(sub_82179E70);
PPC_FUNC_IMPL(__imp__sub_82179E70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x82179E78;
	__savegprlr_22(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,388(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217a0bc
	if (ctx.cr6.eq) goto loc_8217A0BC;
	// lwz r11,256(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// li r23,524
	ctx.r23.s64 = 524;
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// addi r27,r3,240
	ctx.r27.s64 = ctx.r3.s64 + 240;
	// li r24,1
	ctx.r24.s64 = 1;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r23
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8217a0b4
	if (!ctx.cr6.gt) goto loc_8217A0B4;
	// addi r31,r3,360
	ctx.r31.s64 = ctx.r3.s64 + 360;
	// mr r26,r23
	ctx.r26.u64 = ctx.r23.u64;
	// li r25,15
	ctx.r25.s64 = 15;
	// li r28,0
	ctx.r28.s64 = 0;
loc_82179EC0:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r23
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82179edc
	if (ctx.cr6.lt) goto loc_82179EDC;
	// twi 31,r0,22
loc_82179EDC:
	// lwzx r4,r26,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + ctx.r11.u32);
	// add r29,r26,r11
	ctx.r29.u64 = ctx.r26.u64 + ctx.r11.u64;
	// stw r25,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r25.u32);
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r28.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stb r28,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r28.u8);
loc_82179EF4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82179ef4
	if (!ctx.cr6.eq) goto loc_82179EF4;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x82179F18;
	sub_82060368(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820712d0
	ctx.lr = 0x82179F24;
	sub_820712D0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// bne cr6,0x82179f34
	if (!ctx.cr6.eq) goto loc_82179F34;
	// twi 31,r0,22
loc_82179F34:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x82179f50
	if (ctx.cr6.eq) goto loc_82179F50;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82179f54
	if (ctx.cr6.eq) goto loc_82179F54;
loc_82179F50:
	// twi 31,r0,22
loc_82179F54:
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82179f98
	if (ctx.cr6.eq) goto loc_82179F98;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// addi r11,r3,12
	ctx.r11.s64 = ctx.r3.s64 + 12;
	// lwz r6,32(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x82179f78
	if (ctx.cr6.lt) goto loc_82179F78;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x82179f7c
	goto loc_82179F7C;
loc_82179F78:
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
loc_82179F7C:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x820654f8
	ctx.lr = 0x82179F88;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82179f98
	if (ctx.cr6.lt) goto loc_82179F98;
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// b 0x82179fac
	goto loc_82179FAC;
loc_82179F98:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r30,r1,88
	ctx.r30.s64 = ctx.r1.s64 + 88;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
loc_82179FAC:
	// ld r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// blt cr6,0x82179fc8
	if (ctx.cr6.lt) goto loc_82179FC8;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x82179FC8;
	sub_8207A630(ctx, base);
loc_82179FC8:
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r25,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r25.u32);
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r28.u32);
	// stb r28,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r28.u8);
	// beq cr6,0x82179ff0
	if (ctx.cr6.eq) goto loc_82179FF0;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82179ff4
	if (ctx.cr6.eq) goto loc_82179FF4;
loc_82179FF0:
	// twi 31,r0,22
loc_82179FF4:
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8217a094
	if (ctx.cr6.eq) goto loc_8217A094;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217a0c4
	if (!ctx.cr6.eq) goto loc_8217A0C4;
	// twi 31,r0,22
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8217A010:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8217a020
	if (!ctx.cr6.eq) goto loc_8217A020;
	// twi 31,r0,22
loc_8217A020:
	// lwz r11,40(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// addi r3,r8,40
	ctx.r3.s64 = ctx.r8.s64 + 40;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8217a094
	if (!ctx.cr6.eq) goto loc_8217A094;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217a0cc
	if (!ctx.cr6.eq) goto loc_8217A0CC;
	// twi 31,r0,22
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8217A044:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8217a054
	if (!ctx.cr6.eq) goto loc_8217A054;
	// twi 31,r0,22
loc_8217A054:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82179b20
	ctx.lr = 0x8217A05C;
	sub_82179B20(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217a084
	if (!ctx.cr6.eq) goto loc_8217A084;
	// lbz r11,144(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217a084
	if (!ctx.cr6.eq) goto loc_8217A084;
	// addi r5,r29,132
	ctx.r5.s64 = ctx.r29.s64 + 132;
	// addi r4,r29,92
	ctx.r4.s64 = ctx.r29.s64 + 92;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82178980
	ctx.lr = 0x8217A084;
	sub_82178980(ctx, base);
loc_8217A084:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ld r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r30.u32 + 0);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8206ddd8
	ctx.lr = 0x8217A094;
	sub_8206DDD8(ctx, base);
loc_8217A094:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r26,r26,524
	ctx.r26.s64 = ctx.r26.s64 + 524;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r23
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
	// cmplw cr6,r24,r8
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82179ec0
	if (ctx.cr6.lt) goto loc_82179EC0;
loc_8217A0B4:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x821774b0
	ctx.lr = 0x8217A0BC;
	sub_821774B0(ctx, base);
loc_8217A0BC:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_8217A0C4:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8217a010
	goto loc_8217A010;
loc_8217A0CC:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8217a044
	goto loc_8217A044;
}

__attribute__((alias("__imp__sub_8217A0D4"))) PPC_WEAK_FUNC(sub_8217A0D4);
PPC_FUNC_IMPL(__imp__sub_8217A0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217A0D8"))) PPC_WEAK_FUNC(sub_8217A0D8);
PPC_FUNC_IMPL(__imp__sub_8217A0D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8217A0E0;
	__savegprlr_24(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,177(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 177);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217a284
	if (!ctx.cr6.eq) goto loc_8217A284;
	// bl 0x821774b0
	ctx.lr = 0x8217A0F8;
	sub_821774B0(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82179168
	ctx.lr = 0x8217A100;
	sub_82179168(ctx, base);
	// lwz r11,256(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 256);
	// lwz r10,252(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 252);
	// li r26,524
	ctx.r26.s64 = 524;
	// addi r30,r25,240
	ctx.r30.s64 = ctx.r25.s64 + 240;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// li r28,1
	ctx.r28.s64 = 1;
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8217a284
	if (!ctx.cr6.gt) goto loc_8217A284;
	// mr r27,r26
	ctx.r27.u64 = ctx.r26.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r24,15
	ctx.r24.s64 = 15;
loc_8217A130:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217a14c
	if (ctx.cr6.lt) goto loc_8217A14C;
	// twi 31,r0,22
loc_8217A14C:
	// add r31,r27,r11
	ctx.r31.u64 = ctx.r27.u64 + ctx.r11.u64;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217a180
	if (ctx.cr6.eq) goto loc_8217A180;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x8217a180
	if (ctx.cr6.eq) goto loc_8217A180;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// beq cr6,0x8217a180
	if (ctx.cr6.eq) goto loc_8217A180;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// beq cr6,0x8217a180
	if (ctx.cr6.eq) goto loc_8217A180;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// bne cr6,0x8217a184
	if (!ctx.cr6.eq) goto loc_8217A184;
loc_8217A180:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8217A184:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217a264
	if (ctx.cr6.eq) goto loc_8217A264;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8206d4a8
	ctx.lr = 0x8217A198;
	sub_8206D4A8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82179cb8
	ctx.lr = 0x8217A1A4;
	sub_82179CB8(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r24.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
loc_8217A1B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217a1b8
	if (!ctx.cr6.eq) goto loc_8217A1B8;
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8217A1DC;
	sub_82060368(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,360
	ctx.r3.s64 = ctx.r25.s64 + 360;
	// bl 0x8206dc08
	ctx.lr = 0x8217A1E8;
	sub_8206DC08(ctx, base);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// li r5,148
	ctx.r5.s64 = 148;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bl 0x8207dac0
	ctx.lr = 0x8217A204;
	sub_8207DAC0(ctx, base);
	// lwz r9,264(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r31,160
	ctx.r3.s64 = ctx.r31.s64 + 160;
	// stw r9,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r9.u32);
	// lwz r8,268(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// stw r8,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r8.u32);
	// bl 0x8206d7e0
	ctx.lr = 0x8217A220;
	sub_8206D7E0(ctx, base);
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x8217a234
	if (ctx.cr6.lt) goto loc_8217A234;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8217A234;
	sub_8207A630(ctx, base);
loc_8217A234:
	// lwz r3,284(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// stw r24,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r24.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// beq cr6,0x8217a250
	if (ctx.cr6.eq) goto loc_8217A250;
	// bl 0x8207a630
	ctx.lr = 0x8217A250;
	sub_8207A630(ctx, base);
loc_8217A250:
	// stw r29,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, ctx.r29.u32);
	// stw r29,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r29.u32);
	// stw r29,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r29.u32);
	// lwz r3,272(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// bl 0x8207a630
	ctx.lr = 0x8217A264;
	sub_8207A630(ctx, base);
loc_8217A264:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r27,r27,524
	ctx.r27.s64 = ctx.r27.s64 + 524;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217a130
	if (ctx.cr6.lt) goto loc_8217A130;
loc_8217A284:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217A28C"))) PPC_WEAK_FUNC(sub_8217A28C);
PPC_FUNC_IMPL(__imp__sub_8217A28C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217A290"))) PPC_WEAK_FUNC(sub_8217A290);
PPC_FUNC_IMPL(__imp__sub_8217A290) {
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
	// lwz r11,532(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 532);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,528(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 528);
	// addi r31,r3,516
	ctx.r31.s64 = ctx.r3.s64 + 516;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8217a2e0
	if (!ctx.cr6.eq) goto loc_8217A2E0;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206e258
	ctx.lr = 0x8217A2D4;
	sub_8206E258(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82179868
	ctx.lr = 0x8217A2E0;
	sub_82179868(ctx, base);
loc_8217A2E0:
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

__attribute__((alias("__imp__sub_8217A2F8"))) PPC_WEAK_FUNC(sub_8217A2F8);
PPC_FUNC_IMPL(__imp__sub_8217A2F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8217A300;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r11,5260
	ctx.r10.s64 = ctx.r11.s64 + 5260;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r22,15
	ctx.r22.s64 = 15;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r11,r3,36
	ctx.r11.s64 = ctx.r3.s64 + 36;
	// stw r22,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r22.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r31.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stb r31,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r31.u8);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// stw r22,60(r30)
	PPC_STORE_U32(ctx.r30.u32 + 60, ctx.r22.u32);
	// addi r11,r30,64
	ctx.r11.s64 = ctx.r30.s64 + 64;
	// stw r31,56(r30)
	PPC_STORE_U32(ctx.r30.u32 + 56, ctx.r31.u32);
	// addi r26,r30,8
	ctx.r26.s64 = ctx.r30.s64 + 8;
	// stb r31,40(r30)
	PPC_STORE_U8(ctx.r30.u32 + 40, ctx.r31.u8);
	// addi r24,r30,240
	ctx.r24.s64 = ctx.r30.s64 + 240;
	// stw r22,88(r30)
	PPC_STORE_U32(ctx.r30.u32 + 88, ctx.r22.u32);
	// stw r31,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r31.u32);
	// stb r31,68(r30)
	PPC_STORE_U8(ctx.r30.u32 + 68, ctx.r31.u8);
	// stw r31,132(r30)
	PPC_STORE_U32(ctx.r30.u32 + 132, ctx.r31.u32);
	// stw r31,136(r30)
	PPC_STORE_U32(ctx.r30.u32 + 136, ctx.r31.u32);
	// stw r31,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r31.u32);
	// stw r31,144(r30)
	PPC_STORE_U32(ctx.r30.u32 + 144, ctx.r31.u32);
	// stw r31,160(r30)
	PPC_STORE_U32(ctx.r30.u32 + 160, ctx.r31.u32);
	// stw r31,164(r30)
	PPC_STORE_U32(ctx.r30.u32 + 164, ctx.r31.u32);
	// stw r31,168(r30)
	PPC_STORE_U32(ctx.r30.u32 + 168, ctx.r31.u32);
	// stw r31,172(r30)
	PPC_STORE_U32(ctx.r30.u32 + 172, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217A384;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a394
	if (ctx.cr6.eq) goto loc_8217A394;
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r24.u32);
	// b 0x8217a398
	goto loc_8217A398;
loc_8217A394:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A398:
	// stw r3,0(r24)
	PPC_STORE_U32(ctx.r24.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r24)
	PPC_STORE_U32(ctx.r24.u32 + 12, ctx.r31.u32);
	// addi r29,r30,332
	ctx.r29.s64 = ctx.r30.s64 + 332;
	// stw r31,16(r24)
	PPC_STORE_U32(ctx.r24.u32 + 16, ctx.r31.u32);
	// stw r31,20(r24)
	PPC_STORE_U32(ctx.r24.u32 + 20, ctx.r31.u32);
	// stw r31,284(r30)
	PPC_STORE_U32(ctx.r30.u32 + 284, ctx.r31.u32);
	// stw r31,288(r30)
	PPC_STORE_U32(ctx.r30.u32 + 288, ctx.r31.u32);
	// stw r31,292(r30)
	PPC_STORE_U32(ctx.r30.u32 + 292, ctx.r31.u32);
	// stw r31,296(r30)
	PPC_STORE_U32(ctx.r30.u32 + 296, ctx.r31.u32);
	// stw r31,300(r30)
	PPC_STORE_U32(ctx.r30.u32 + 300, ctx.r31.u32);
	// stw r31,304(r30)
	PPC_STORE_U32(ctx.r30.u32 + 304, ctx.r31.u32);
	// stw r31,312(r30)
	PPC_STORE_U32(ctx.r30.u32 + 312, ctx.r31.u32);
	// stw r31,316(r30)
	PPC_STORE_U32(ctx.r30.u32 + 316, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217A3D4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a3e4
	if (ctx.cr6.eq) goto loc_8217A3E4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a3e8
	goto loc_8217A3E8;
loc_8217A3E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A3E8:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,360
	ctx.r29.s64 = ctx.r30.s64 + 360;
	// bl 0x82079fd8
	ctx.lr = 0x8217A404;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a414
	if (ctx.cr6.eq) goto loc_8217A414;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a418
	goto loc_8217A418;
loc_8217A414:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A418:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,228
	ctx.r3.s64 = 228;
	// bl 0x82079fd8
	ctx.lr = 0x8217A424;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a434
	if (ctx.cr6.eq) goto loc_8217A434;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
loc_8217A434:
	// addic. r10,r11,4
	ctx.xer.ca = ctx.r11.u32 > 4294967291;
	ctx.r10.s64 = ctx.r11.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8217a440
	if (ctx.cr0.eq) goto loc_8217A440;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
loc_8217A440:
	// addic. r10,r11,8
	ctx.xer.ca = ctx.r11.u32 > 4294967287;
	ctx.r10.s64 = ctx.r11.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8217a44c
	if (ctx.cr0.eq) goto loc_8217A44C;
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
loc_8217A44C:
	// li r27,1
	ctx.r27.s64 = 1;
	// stb r31,225(r11)
	PPC_STORE_U8(ctx.r11.u32 + 225, ctx.r31.u8);
	// li r3,4
	ctx.r3.s64 = 4;
	// stb r27,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r27.u8);
	// addi r28,r30,392
	ctx.r28.s64 = ctx.r30.s64 + 392;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// stb r27,225(r11)
	PPC_STORE_U8(ctx.r11.u32 + 225, ctx.r27.u8);
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r11,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r10,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r10.u32);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// stw r9,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r9.u32);
	// stw r31,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217A488;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a498
	if (ctx.cr6.eq) goto loc_8217A498;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// b 0x8217a49c
	goto loc_8217A49C;
loc_8217A498:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A49C:
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// addi r29,r30,416
	ctx.r29.s64 = ctx.r30.s64 + 416;
	// stw r31,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r31.u32);
	// stw r31,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217A4B8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a4c8
	if (ctx.cr6.eq) goto loc_8217A4C8;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a4cc
	goto loc_8217A4CC;
loc_8217A4C8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A4CC:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,440
	ctx.r29.s64 = ctx.r30.s64 + 440;
	// bl 0x82079fd8
	ctx.lr = 0x8217A4E8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a4f8
	if (ctx.cr6.eq) goto loc_8217A4F8;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a4fc
	goto loc_8217A4FC;
loc_8217A4F8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A4FC:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,464
	ctx.r29.s64 = ctx.r30.s64 + 464;
	// bl 0x82079fd8
	ctx.lr = 0x8217A518;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a528
	if (ctx.cr6.eq) goto loc_8217A528;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a52c
	goto loc_8217A52C;
loc_8217A528:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A52C:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,492
	ctx.r29.s64 = ctx.r30.s64 + 492;
	// bl 0x82079fd8
	ctx.lr = 0x8217A548;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a558
	if (ctx.cr6.eq) goto loc_8217A558;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a55c
	goto loc_8217A55C;
loc_8217A558:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A55C:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,516
	ctx.r29.s64 = ctx.r30.s64 + 516;
	// bl 0x82079fd8
	ctx.lr = 0x8217A578;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a588
	if (ctx.cr6.eq) goto loc_8217A588;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a58c
	goto loc_8217A58C;
loc_8217A588:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A58C:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r25.u32);
	// bl 0x820601f8
	ctx.lr = 0x8217A5B4;
	sub_820601F8(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stb r27,177(r30)
	PPC_STORE_U8(ctx.r30.u32 + 177, ctx.r27.u8);
	// lis r8,-32640
	ctx.r8.s64 = -2139095040;
	// stb r27,178(r30)
	PPC_STORE_U8(ctx.r30.u32 + 178, ctx.r27.u8);
	// stb r27,179(r30)
	PPC_STORE_U8(ctx.r30.u32 + 179, ctx.r27.u8);
	// li r11,2
	ctx.r11.s64 = 2;
	// ori r7,r8,32896
	ctx.r7.u64 = ctx.r8.u64 | 32896;
	// stb r31,176(r30)
	PPC_STORE_U8(ctx.r30.u32 + 176, ctx.r31.u8);
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stb r31,148(r30)
	PPC_STORE_U8(ctx.r30.u32 + 148, ctx.r31.u8);
	// lfs f31,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f31.f64 = double(temp.f32);
	// stb r31,356(r30)
	PPC_STORE_U8(ctx.r30.u32 + 356, ctx.r31.u8);
	// stfs f0,180(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 180, temp.u32);
	// addi r10,r30,196
	ctx.r10.s64 = ctx.r30.s64 + 196;
	// stfs f0,184(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 184, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stfs f31,188(r30)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 188, temp.u32);
	// addi r11,r1,200
	ctx.r11.s64 = ctx.r1.s64 + 200;
	// stfs f0,308(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 308, temp.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stfs f0,152(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 152, temp.u32);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r31.u32);
	// stfs f0,212(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 212, temp.u32);
	// stfs f0,216(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 216, temp.u32);
	// stfs f0,220(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 220, temp.u32);
	// stfs f0,224(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 224, temp.u32);
	// stw r31,228(r30)
	PPC_STORE_U32(ctx.r30.u32 + 228, ctx.r31.u32);
	// stw r31,232(r30)
	PPC_STORE_U32(ctx.r30.u32 + 232, ctx.r31.u32);
	// stw r7,236(r30)
	PPC_STORE_U32(ctx.r30.u32 + 236, ctx.r7.u32);
	// stw r31,196(r30)
	PPC_STORE_U32(ctx.r30.u32 + 196, ctx.r31.u32);
	// stw r31,200(r30)
	PPC_STORE_U32(ctx.r30.u32 + 200, ctx.r31.u32);
	// stw r31,204(r30)
	PPC_STORE_U32(ctx.r30.u32 + 204, ctx.r31.u32);
	// stfs f31,208(r30)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 208, temp.u32);
loc_8217A63C:
	// stw r31,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r31.u32);
	// stw r31,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r31.u32);
	// stw r31,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r31.u32);
	// stw r31,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r31.u32);
	// stw r31,120(r11)
	PPC_STORE_U32(ctx.r11.u32 + 120, ctx.r31.u32);
	// stw r31,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r31.u32);
	// stw r31,128(r11)
	PPC_STORE_U32(ctx.r11.u32 + 128, ctx.r31.u32);
	// stw r31,132(r11)
	PPC_STORE_U32(ctx.r11.u32 + 132, ctx.r31.u32);
	// stw r31,136(r11)
	PPC_STORE_U32(ctx.r11.u32 + 136, ctx.r31.u32);
	// stw r31,140(r11)
	PPC_STORE_U32(ctx.r11.u32 + 140, ctx.r31.u32);
	// stw r31,144(r11)
	PPC_STORE_U32(ctx.r11.u32 + 144, ctx.r31.u32);
	// stwu r31,148(r11)
	ea = 148 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8217a63c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217A63C;
	// li r5,524
	ctx.r5.s64 = 524;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8207da20
	ctx.lr = 0x8217A680;
	sub_8207DA20(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r1,512
	ctx.r11.s64 = ctx.r1.s64 + 512;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8217A690:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8217a690
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217A690;
	// li r10,10
	ctx.r10.s64 = 10;
	// stfs f31,536(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// li r8,255
	ctx.r8.s64 = 255;
	// stfs f31,540(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// addi r11,r1,552
	ctx.r11.s64 = ctx.r1.s64 + 552;
	// stb r27,516(r1)
	PPC_STORE_U8(ctx.r1.u32 + 516, ctx.r27.u8);
	// stb r27,517(r1)
	PPC_STORE_U8(ctx.r1.u32 + 517, ctx.r27.u8);
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// stw r8,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r8.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8217A6C0:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8217a6c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217A6C0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stfs f31,576(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stfs f31,580(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stb r27,556(r1)
	PPC_STORE_U8(ctx.r1.u32 + 556, ctx.r27.u8);
	// stw r8,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r8.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stb r31,557(r1)
	PPC_STORE_U8(ctx.r1.u32 + 557, ctx.r31.u8);
	// stw r31,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r31.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
loc_8217A6F0:
	// subfic r9,r11,3
	ctx.xer.ca = ctx.r11.u32 <= 3;
	ctx.r9.s64 = 3 - ctx.r11.s64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8217a6f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217A6F0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x8206da08
	ctx.lr = 0x8217A70C;
	sub_8206DA08(ctx, base);
	// lwz r11,24(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217a720
	if (ctx.cr6.lt) goto loc_8217A720;
	// lwz r3,4(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8217A720;
	sub_8207A630(ctx, base);
loc_8217A720:
	// stw r22,24(r23)
	PPC_STORE_U32(ctx.r23.u32 + 24, ctx.r22.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,20(r23)
	PPC_STORE_U32(ctx.r23.u32 + 20, ctx.r31.u32);
	// stb r31,4(r23)
	PPC_STORE_U8(ctx.r23.u32 + 4, ctx.r31.u8);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217A73C"))) PPC_WEAK_FUNC(sub_8217A73C);
PPC_FUNC_IMPL(__imp__sub_8217A73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217A740"))) PPC_WEAK_FUNC(sub_8217A740);
PPC_FUNC_IMPL(__imp__sub_8217A740) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8217A748;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r27,44
	ctx.r27.s64 = 44;
	// addi r10,r11,5240
	ctx.r10.s64 = ctx.r11.s64 + 5240;
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r30,r3,16
	ctx.r30.s64 = ctx.r3.s64 + 16;
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// divw. r6,r7,r27
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x8217a8a4
	if (ctx.cr0.eq) goto loc_8217A8A4;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
loc_8217A784:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217a7a0
	if (ctx.cr6.lt) goto loc_8217A7A0;
	// twi 31,r0,22
loc_8217A7A0:
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
loc_8217A7BC:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r6,r7,r27
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r27.s32);
	// cmplw cr6,r28,r6
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217a7d8
	if (ctx.cr6.lt) goto loc_8217A7D8;
	// twi 31,r0,22
loc_8217A7D8:
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// beq cr6,0x8217a7f8
	if (ctx.cr6.eq) goto loc_8217A7F8;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8217a7fc
	if (ctx.cr6.eq) goto loc_8217A7FC;
loc_8217A7F8:
	// twi 31,r0,22
loc_8217A7FC:
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8217a884
	if (ctx.cr6.eq) goto loc_8217A884;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217a874
	if (!ctx.cr6.eq) goto loc_8217A874;
	// twi 31,r0,22
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8217A814:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8217a824
	if (!ctx.cr6.eq) goto loc_8217A824;
	// twi 31,r0,22
loc_8217A824:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217a87c
	if (!ctx.cr6.eq) goto loc_8217A87C;
	// twi 31,r0,22
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8217A834:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8217a844
	if (!ctx.cr6.eq) goto loc_8217A844;
	// twi 31,r0,22
loc_8217A844:
	// lwz r31,48(r8)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8217a860
	if (ctx.cr6.eq) goto loc_8217A860;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82167ee8
	ctx.lr = 0x8217A858;
	sub_82167EE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a630
	ctx.lr = 0x8217A860;
	sub_8207A630(ctx, base);
loc_8217A860:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82071ad8
	ctx.lr = 0x8217A868;
	sub_82071AD8(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8217a7bc
	goto loc_8217A7BC;
loc_8217A874:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8217a814
	goto loc_8217A814;
loc_8217A87C:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8217a834
	goto loc_8217A834;
loc_8217A884:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r29,r29,44
	ctx.r29.s64 = ctx.r29.s64 + 44;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217a784
	if (ctx.cr6.lt) goto loc_8217A784;
loc_8217A8A4:
	// lwz r3,100(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 100);
	// addi r31,r25,88
	ctx.r31.s64 = ctx.r25.s64 + 88;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a8b8
	if (ctx.cr6.eq) goto loc_8217A8B8;
	// bl 0x8207a630
	ctx.lr = 0x8217A8B8;
	sub_8207A630(ctx, base);
loc_8217A8B8:
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// stw r26,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8217A8CC;
	sub_8207A630(ctx, base);
	// lwz r3,76(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 76);
	// addi r31,r25,64
	ctx.r31.s64 = ctx.r25.s64 + 64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a8e0
	if (ctx.cr6.eq) goto loc_8217A8E0;
	// bl 0x8207a630
	ctx.lr = 0x8217A8E0;
	sub_8207A630(ctx, base);
loc_8217A8E0:
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// stw r26,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8217A8F4;
	sub_8207A630(ctx, base);
	// lwz r3,52(r25)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r25.u32 + 52);
	// addi r31,r25,40
	ctx.r31.s64 = ctx.r25.s64 + 40;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a908
	if (ctx.cr6.eq) goto loc_8217A908;
	// bl 0x8207a630
	ctx.lr = 0x8217A908;
	sub_8207A630(ctx, base);
loc_8217A908:
	// stw r26,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r26.u32);
	// stw r26,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8217A91C;
	sub_8207A630(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a938
	if (ctx.cr6.eq) goto loc_8217A938;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x8206ec10
	ctx.lr = 0x8217A930;
	sub_8206EC10(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x8217A938;
	sub_8207A630(ctx, base);
loc_8217A938:
	// stw r26,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r26.u32);
	// stw r26,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r26.u32);
	// stw r26,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8217A94C;
	sub_8207A630(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// stw r10,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217A960"))) PPC_WEAK_FUNC(sub_8217A960);
PPC_FUNC_IMPL(__imp__sub_8217A960) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8217A968;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,5240
	ctx.r10.s64 = ctx.r11.s64 + 5240;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r10,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// addi r29,r30,16
	ctx.r29.s64 = ctx.r30.s64 + 16;
	// stb r31,12(r30)
	PPC_STORE_U8(ctx.r30.u32 + 12, ctx.r31.u8);
	// bl 0x82079fd8
	ctx.lr = 0x8217A994;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a9a4
	if (ctx.cr6.eq) goto loc_8217A9A4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a9a8
	goto loc_8217A9A8;
loc_8217A9A4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A9A8:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,40
	ctx.r29.s64 = ctx.r30.s64 + 40;
	// bl 0x82079fd8
	ctx.lr = 0x8217A9C4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217a9d4
	if (ctx.cr6.eq) goto loc_8217A9D4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217a9d8
	goto loc_8217A9D8;
loc_8217A9D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217A9D8:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,64
	ctx.r29.s64 = ctx.r30.s64 + 64;
	// bl 0x82079fd8
	ctx.lr = 0x8217A9F4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217aa04
	if (ctx.cr6.eq) goto loc_8217AA04;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217aa08
	goto loc_8217AA08;
loc_8217AA04:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217AA08:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// addi r29,r30,88
	ctx.r29.s64 = ctx.r30.s64 + 88;
	// bl 0x82079fd8
	ctx.lr = 0x8217AA24;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217aa34
	if (ctx.cr6.eq) goto loc_8217AA34;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8217aa38
	goto loc_8217AA38;
loc_8217AA34:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217AA38:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r31.u32);
	// stw r31,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r31.u32);
	// stw r31,112(r30)
	PPC_STORE_U32(ctx.r30.u32 + 112, ctx.r31.u32);
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stw r31,116(r30)
	PPC_STORE_U32(ctx.r30.u32 + 116, ctx.r31.u32);
	// stfs f0,124(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 124, temp.u32);
	// stb r31,120(r30)
	PPC_STORE_U8(ctx.r30.u32 + 120, ctx.r31.u8);
	// stfs f0,128(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 128, temp.u32);
	// stw r31,136(r30)
	PPC_STORE_U32(ctx.r30.u32 + 136, ctx.r31.u32);
	// stfs f0,132(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 132, temp.u32);
	// stw r31,140(r30)
	PPC_STORE_U32(ctx.r30.u32 + 140, ctx.r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217AA7C"))) PPC_WEAK_FUNC(sub_8217AA7C);
PPC_FUNC_IMPL(__imp__sub_8217AA7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217AA80"))) PPC_WEAK_FUNC(sub_8217AA80);
PPC_FUNC_IMPL(__imp__sub_8217AA80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8217AA88;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r11,-1456
	ctx.r10.s64 = ctx.r11.s64 + -1456;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// stb r29,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r29.u8);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8217AAD4;
	sub_820601F8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8217a2f8
	ctx.lr = 0x8217AAE4;
	sub_8217A2F8(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r7,r9,5268
	ctx.r7.s64 = ctx.r9.s64 + 5268;
	// addi r6,r8,5280
	ctx.r6.s64 = ctx.r8.s64 + 5280;
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r5,16
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 16, ctx.xer);
	// blt cr6,0x8217ab10
	if (ctx.cr6.lt) goto loc_8217AB10;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8217AB10;
	sub_8207A630(ctx, base);
loc_8217AB10:
	// stw r28,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r29.u32);
	// stb r29,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r29.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217AB28"))) PPC_WEAK_FUNC(sub_8217AB28);
PPC_FUNC_IMPL(__imp__sub_8217AB28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8217AB30;
	__savegprlr_26(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// std r5,272(r1)
	PPC_STORE_U64(ctx.r1.u32 + 272, ctx.r5.u64);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r27,r11,-20780
	ctx.r27.s64 = ctx.r11.s64 + -20780;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r5,r27,1996
	ctx.r5.s64 = ctx.r27.s64 + 1996;
	// bl 0x82175ae8
	ctx.lr = 0x8217AB58;
	sub_82175AE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217AB64;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8217AB70;
	sub_82175150(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// addi r5,r27,2004
	ctx.r5.s64 = ctx.r27.s64 + 2004;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175ae8
	ctx.lr = 0x8217AB84;
	sub_82175AE8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r5,r27,2016
	ctx.r5.s64 = ctx.r27.s64 + 2016;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,28(r28)
	PPC_STORE_U32(ctx.r28.u32 + 28, ctx.r9.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217ABA8;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217ABAC;
	sub_82175D08(ctx, base);
	// stw r3,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r3.u32);
	// addi r5,r27,2028
	ctx.r5.s64 = ctx.r27.s64 + 2028;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175ae8
	ctx.lr = 0x8217ABC0;
	sub_82175AE8(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r28,28
	ctx.r29.s64 = ctx.r28.s64 + 28;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
loc_8217ABCC:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175648
	ctx.lr = 0x8217ABDC;
	sub_82175648(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217ABE0;
	sub_82175D08(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stwu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r29.u32 = ea;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// blt cr6,0x8217abcc
	if (ctx.cr6.lt) goto loc_8217ABCC;
	// addi r4,r27,2044
	ctx.r4.s64 = ctx.r27.s64 + 2044;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217AC08;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ac24
	if (!ctx.cr6.eq) goto loc_8217AC24;
	// addi r4,r27,2044
	ctx.r4.s64 = ctx.r27.s64 + 2044;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217AC20;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217AC24;
	sub_8207B288(ctx, base);
loc_8217AC24:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x8217AC2C;
	sub_82175D08(ctx, base);
	// stw r3,8(r28)
	PPC_STORE_U32(ctx.r28.u32 + 8, ctx.r3.u32);
	// addi r4,r27,2052
	ctx.r4.s64 = ctx.r27.s64 + 2052;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217AC48;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ac64
	if (!ctx.cr6.eq) goto loc_8217AC64;
	// addi r4,r27,2052
	ctx.r4.s64 = ctx.r27.s64 + 2052;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217AC60;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217AC64;
	sub_8207B288(ctx, base);
loc_8217AC64:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x8217AC6C;
	sub_82175D08(ctx, base);
	// lwz r11,8(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// stw r3,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8217b148
	if (ctx.cr6.gt) goto loc_8217B148;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217acc0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217ACC0;
	// bdzf 4*cr6+eq,0x8217b148
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217B148;
	// bdzf 4*cr6+eq,0x8217ad30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217AD30;
	// bdzf 4*cr6+eq,0x8217ae64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217AE64;
	// bdzf 4*cr6+eq,0x8217b148
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217B148;
	// bdzf 4*cr6+eq,0x8217b148
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217B148;
	// bne cr6,0x8217b13c
	if (!ctx.cr6.eq) goto loc_8217B13C;
	// addi r5,r27,2064
	ctx.r5.s64 = ctx.r27.s64 + 2064;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217ACB0;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217ACB4;
	sub_82175D08(ctx, base);
	// stw r3,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r3.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217ACC0:
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82079fd8
	ctx.lr = 0x8217ACC8;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217acf0
	if (ctx.cr6.eq) goto loc_8217ACF0;
	// li r9,9
	ctx.r9.s64 = 9;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8217ACE4:
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8217ace4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217ACE4;
	// b 0x8217acf4
	goto loc_8217ACF4;
loc_8217ACF0:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217ACF4:
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r11,520(r28)
	PPC_STORE_U32(ctx.r28.u32 + 520, ctx.r11.u32);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8217AD04:
	// stwu r31,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8217ad04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217AD04;
	// addi r5,r27,2080
	ctx.r5.s64 = ctx.r27.s64 + 2080;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x8217AD1C;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217AD20;
	sub_82175D08(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217AD30:
	// addi r29,r28,128
	ctx.r29.s64 = ctx.r28.s64 + 128;
	// li r30,2
	ctx.r30.s64 = 2;
loc_8217AD38:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82079fd8
	ctx.lr = 0x8217AD40;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ad68
	if (ctx.cr6.eq) goto loc_8217AD68;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r11,r3,-4
	ctx.r11.s64 = ctx.r3.s64 + -4;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8217AD58:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8217ad58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217AD58;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8217ad6c
	goto loc_8217AD6C;
loc_8217AD68:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217AD6C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r11,148(r29)
	ea = 148 + ctx.r29.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r29.u32 = ea;
	// bne 0x8217ad38
	if (!ctx.cr0.eq) goto loc_8217AD38;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8217AD80;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ad94
	if (ctx.cr6.eq) goto loc_8217AD94;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// b 0x8217ad98
	goto loc_8217AD98;
loc_8217AD94:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217AD98:
	// stw r11,520(r28)
	PPC_STORE_U32(ctx.r28.u32 + 520, ctx.r11.u32);
	// li r3,540
	ctx.r3.s64 = 540;
	// bl 0x82079fd8
	ctx.lr = 0x8217ADA4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ade8
	if (ctx.cr6.eq) goto loc_8217ADE8;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// addi r4,r27,-4294
	ctx.r4.s64 = ctx.r27.s64 + -4294;
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82060368
	ctx.lr = 0x8217ADD0;
	sub_82060368(ctx, base);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,4(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x8217a2f8
	ctx.lr = 0x8217ADE0;
	sub_8217A2F8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x8217adec
	goto loc_8217ADEC;
loc_8217ADE8:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217ADEC:
	// lwz r10,520(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lfs f0,308(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,520(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stfs f0,308(r8)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 308, temp.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217AE0C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ae20
	if (ctx.cr6.eq) goto loc_8217AE20;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x8217ae24
	goto loc_8217AE24;
loc_8217AE20:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217AE24:
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r31.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// bl 0x8207a630
	ctx.lr = 0x8217AE38;
	sub_8207A630(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lwz r5,232(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + 232);
	// lwz r4,228(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 228);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x82179788
	ctx.lr = 0x8217AE4C;
	sub_82179788(ctx, base);
	// lwz r10,520(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// lwz r4,236(r26)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r26.u32 + 236);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x821796b0
	ctx.lr = 0x8217AE5C;
	sub_821796B0(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217AE64:
	// addi r29,r28,128
	ctx.r29.s64 = ctx.r28.s64 + 128;
	// li r30,2
	ctx.r30.s64 = 2;
loc_8217AE6C:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82079fd8
	ctx.lr = 0x8217AE74;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ae98
	if (ctx.cr6.eq) goto loc_8217AE98;
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
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// b 0x8217ae9c
	goto loc_8217AE9C;
loc_8217AE98:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217AE9C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r11,148(r29)
	ea = 148 + ctx.r29.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r29.u32 = ea;
	// bne 0x8217ae6c
	if (!ctx.cr0.eq) goto loc_8217AE6C;
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82079fd8
	ctx.lr = 0x8217AEB0;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217aefc
	if (ctx.cr6.eq) goto loc_8217AEFC;
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r31.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r31.u32);
	// addi r30,r29,48
	ctx.r30.s64 = ctx.r29.s64 + 48;
	// bl 0x82079fd8
	ctx.lr = 0x8217AED0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217aee0
	if (ctx.cr6.eq) goto loc_8217AEE0;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x8217aee4
	goto loc_8217AEE4;
loc_8217AEE0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8217AEE4:
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
	// stw r31,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r31.u32);
	// b 0x8217af00
	goto loc_8217AF00;
loc_8217AEFC:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217AF00:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,520(r28)
	PPC_STORE_U32(ctx.r28.u32 + 520, ctx.r11.u32);
	// addi r4,r27,2088
	ctx.r4.s64 = ctx.r27.s64 + 2088;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 72, temp.u32);
	// lwz r9,520(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// stb r31,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r31.u8);
	// bl 0x821753c8
	ctx.lr = 0x8217AF30;
	sub_821753C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217af4c
	if (!ctx.cr6.eq) goto loc_8217AF4C;
	// addi r4,r27,2088
	ctx.r4.s64 = ctx.r27.s64 + 2088;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217AF48;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217AF4C;
	sub_8207B288(ctx, base);
loc_8217AF4C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x8217AF54;
	sub_82175D08(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2100
	ctx.r4.s64 = ctx.r27.s64 + 2100;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217AF74;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217af90
	if (!ctx.cr6.eq) goto loc_8217AF90;
	// addi r4,r27,2100
	ctx.r4.s64 = ctx.r27.s64 + 2100;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217AF8C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217AF90;
	sub_8207B288(ctx, base);
loc_8217AF90:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x8217AF98;
	sub_82175D08(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2116
	ctx.r4.s64 = ctx.r27.s64 + 2116;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217AFB8;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217afd4
	if (!ctx.cr6.eq) goto loc_8217AFD4;
	// addi r4,r27,2116
	ctx.r4.s64 = ctx.r27.s64 + 2116;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217AFD0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217AFD4;
	sub_8207B288(ctx, base);
loc_8217AFD4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175bb0
	ctx.lr = 0x8217AFDC;
	sub_82175BB0(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2136
	ctx.r4.s64 = ctx.r27.s64 + 2136;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// stfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217AFFC;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217b018
	if (!ctx.cr6.eq) goto loc_8217B018;
	// addi r4,r27,2136
	ctx.r4.s64 = ctx.r27.s64 + 2136;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217B014;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B018;
	sub_8207B288(ctx, base);
loc_8217B018:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175e40
	ctx.lr = 0x8217B020;
	sub_82175E40(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2160
	ctx.r4.s64 = ctx.r27.s64 + 2160;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stb r3,16(r11)
	PPC_STORE_U8(ctx.r11.u32 + 16, ctx.r3.u8);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217B040;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217b05c
	if (!ctx.cr6.eq) goto loc_8217B05C;
	// addi r4,r27,2160
	ctx.r4.s64 = ctx.r27.s64 + 2160;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217B058;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B05C;
	sub_8207B288(ctx, base);
loc_8217B05C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175e40
	ctx.lr = 0x8217B064;
	sub_82175E40(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2184
	ctx.r4.s64 = ctx.r27.s64 + 2184;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stb r3,17(r11)
	PPC_STORE_U8(ctx.r11.u32 + 17, ctx.r3.u8);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217B084;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217b0a0
	if (!ctx.cr6.eq) goto loc_8217B0A0;
	// addi r4,r27,2184
	ctx.r4.s64 = ctx.r27.s64 + 2184;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217B09C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B0A0;
	sub_8207B288(ctx, base);
loc_8217B0A0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175e40
	ctx.lr = 0x8217B0A8;
	sub_82175E40(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2204
	ctx.r4.s64 = ctx.r27.s64 + 2204;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stb r3,18(r11)
	PPC_STORE_U8(ctx.r11.u32 + 18, ctx.r3.u8);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217B0C8;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217b0e4
	if (!ctx.cr6.eq) goto loc_8217B0E4;
	// addi r4,r27,2204
	ctx.r4.s64 = ctx.r27.s64 + 2204;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217B0E0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B0E4;
	sub_8207B288(ctx, base);
loc_8217B0E4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175e40
	ctx.lr = 0x8217B0EC;
	sub_82175E40(ctx, base);
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// addi r4,r27,2232
	ctx.r4.s64 = ctx.r27.s64 + 2232;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// stb r3,19(r11)
	PPC_STORE_U8(ctx.r11.u32 + 19, ctx.r3.u8);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821753c8
	ctx.lr = 0x8217B10C;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217b128
	if (!ctx.cr6.eq) goto loc_8217B128;
	// addi r4,r27,2232
	ctx.r4.s64 = ctx.r27.s64 + 2232;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217B124;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B128;
	sub_8207B288(ctx, base);
loc_8217B128:
	// lwz r11,520(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 520);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,20(r11)
	PPC_STORE_U64(ctx.r11.u32 + 20, ctx.r10.u64);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217B13C:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82079fd8
	ctx.lr = 0x8217B144;
	sub_82079FD8(ctx, base);
	// stw r3,520(r28)
	PPC_STORE_U32(ctx.r28.u32 + 520, ctx.r3.u32);
loc_8217B148:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217B150"))) PPC_WEAK_FUNC(sub_8217B150);
PPC_FUNC_IMPL(__imp__sub_8217B150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8217B158;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,256(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// li r30,524
	ctx.r30.s64 = 524;
	// lwz r9,252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r11,r3,240
	ctx.r11.s64 = ctx.r3.s64 + 240;
	// divw r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// cmplw cr6,r4,r7
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8217b1b0
	if (!ctx.cr6.lt) goto loc_8217B1B0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// cmplw cr6,r4,r8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217b1a0
	if (ctx.cr6.lt) goto loc_8217B1A0;
	// twi 31,r0,22
loc_8217B1A0:
	// mulli r11,r29,524
	ctx.r11.s64 = ctx.r29.s64 * 524;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8217B1B0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217a290
	ctx.lr = 0x8217B1B8;
	sub_8217A290(ctx, base);
	// lwz r11,532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r9,528(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// addi r8,r31,516
	ctx.r8.s64 = ctx.r31.s64 + 516;
	// li r10,0
	ctx.r10.s64 = 0;
	// subf r6,r9,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r9.s64;
	// li r7,0
	ctx.r7.s64 = 0;
	// srawi. r5,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq 0x8217b258
	if (ctx.cr0.eq) goto loc_8217B258;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8217B1DC:
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r9,16(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// subf r6,r11,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r11.s64;
	// srawi r4,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 2;
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x8217b1f8
	if (ctx.cr6.lt) goto loc_8217B1F8;
	// twi 31,r0,22
loc_8217B1F8:
	// lwzx r9,r5,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8217b224
	if (ctx.cr6.gt) goto loc_8217B224;
	// lwz r6,256(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 256);
	// addi r11,r9,240
	ctx.r11.s64 = ctx.r9.s64 + 240;
	// lwz r4,252(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 252);
	// subf r3,r4,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r4.s64;
	// divw r6,r3,r30
	ctx.r6.s32 = ppc_divw(ctx.r3.s32, ctx.r30.s32);
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// cmplw cr6,r29,r6
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217b26c
	if (ctx.cr6.lt) goto loc_8217B26C;
loc_8217B224:
	// lwz r11,256(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 256);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lwz r9,252(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 252);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// lwz r6,16(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r4,12(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// subf r3,r9,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r9.s64;
	// subf r9,r4,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r4.s64;
	// divw r11,r3,r30
	ctx.r11.s32 = ppc_divw(ctx.r3.s32, ctx.r30.s32);
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r7,r6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217b1dc
	if (ctx.cr6.lt) goto loc_8217B1DC;
loc_8217B258:
	// bl 0x8210e878
	ctx.lr = 0x8217B25C;
	sub_8210E878(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B260;
	sub_8207B288(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8217B26C:
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r11,r10,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r10.s64;
	// subf r7,r9,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw r6,r7,r30
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r30.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217b28c
	if (ctx.cr6.lt) goto loc_8217B28C;
	// twi 31,r0,22
loc_8217B28C:
	// mulli r11,r11,524
	ctx.r11.s64 = ctx.r11.s64 * 524;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217B29C"))) PPC_WEAK_FUNC(sub_8217B29C);
PPC_FUNC_IMPL(__imp__sub_8217B29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217B2A0"))) PPC_WEAK_FUNC(sub_8217B2A0);
PPC_FUNC_IMPL(__imp__sub_8217B2A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8217B2A8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r23,r4
	ctx.r23.u64 = ctx.r4.u64;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// bl 0x8217a290
	ctx.lr = 0x8217B2BC;
	sub_8217A290(ctx, base);
	// lwz r11,532(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r10,528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// addi r30,r31,516
	ctx.r30.s64 = ctx.r31.s64 + 516;
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8217b390
	if (ctx.cr0.eq) goto loc_8217B390;
	// mr r28,r24
	ctx.r28.u64 = ctx.r24.u64;
	// li r25,524
	ctx.r25.s64 = 524;
loc_8217B2E8:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217b304
	if (ctx.cr6.lt) goto loc_8217B304;
	// twi 31,r0,22
loc_8217B304:
	// lwzx r11,r28,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// addi r31,r11,240
	ctx.r31.s64 = ctx.r11.s64 + 240;
	// lwz r10,256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 256);
	// lwz r9,252(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 252);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// divw r7,r8,r25
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r25.s32);
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// ble cr6,0x8217b35c
	if (!ctx.cr6.gt) goto loc_8217B35C;
	// addi r27,r11,300
	ctx.r27.s64 = ctx.r11.s64 + 300;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821746a0
	ctx.lr = 0x8217B330;
	sub_821746A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8217b35c
	if (ctx.cr6.eq) goto loc_8217B35C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821753c8
	ctx.lr = 0x8217B350;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217b39c
	if (!ctx.cr6.eq) goto loc_8217B39C;
loc_8217B35C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// subf r7,r10,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r10.s64;
	// subf r6,r8,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r8.s64;
	// divw r11,r7,r25
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r25.s32);
	// srawi r5,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 2;
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// cmplw cr6,r29,r5
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8217b2e8
	if (ctx.cr6.lt) goto loc_8217B2E8;
loc_8217B390:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_8217B39C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175d08
	ctx.lr = 0x8217B3A4;
	sub_82175D08(ctx, base);
	// add r11,r3,r26
	ctx.r11.u64 = ctx.r3.u64 + ctx.r26.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217B3BC"))) PPC_WEAK_FUNC(sub_8217B3BC);
PPC_FUNC_IMPL(__imp__sub_8217B3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217B3C0"))) PPC_WEAK_FUNC(sub_8217B3C0);
PPC_FUNC_IMPL(__imp__sub_8217B3C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217b3d4
	if (ctx.cr6.lt) goto loc_8217B3D4;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x8217b3d8
	goto loc_8217B3D8;
loc_8217B3D4:
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
loc_8217B3D8:
	// b 0x8217b2a0
	sub_8217B2A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217B3DC"))) PPC_WEAK_FUNC(sub_8217B3DC);
PPC_FUNC_IMPL(__imp__sub_8217B3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217B3E0"))) PPC_WEAK_FUNC(sub_8217B3E0);
PPC_FUNC_IMPL(__imp__sub_8217B3E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8217B3E8;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x8217a290
	ctx.lr = 0x8217B3F8;
	sub_8217A290(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8217B400;
	sub_82079FD8(ctx, base);
	// li r26,0
	ctx.r26.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217b41c
	if (ctx.cr6.eq) goto loc_8217B41C;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// b 0x8217b420
	goto loc_8217B420;
loc_8217B41C:
	// stw r26,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r26.u32);
loc_8217B420:
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82079fd8
	ctx.lr = 0x8217B428;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217b434
	if (ctx.cr6.eq) goto loc_8217B434;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
loc_8217B434:
	// addic. r11,r3,4
	ctx.xer.ca = ctx.r3.u32 > 4294967291;
	ctx.r11.s64 = ctx.r3.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8217b440
	if (ctx.cr0.eq) goto loc_8217B440;
	// stw r26,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
loc_8217B440:
	// addic. r11,r3,8
	ctx.xer.ca = ctx.r3.u32 > 4294967287;
	ctx.r11.s64 = ctx.r3.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8217b44c
	if (ctx.cr0.eq) goto loc_8217B44C;
	// stw r26,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
loc_8217B44C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, ctx.r11.u8);
	// stb r26,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r26.u8);
	// addi r27,r30,516
	ctx.r27.s64 = ctx.r30.s64 + 516;
	// stw r3,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// mr r25,r26
	ctx.r25.u64 = ctx.r26.u64;
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r11.u8);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r11,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r11.u32);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r11,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r11,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r11.u32);
	// lwz r11,532(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 532);
	// lwz r10,528(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 528);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r26,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r26.u32);
	// beq 0x8217b5bc
	if (ctx.cr0.eq) goto loc_8217B5BC;
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
	// li r23,524
	ctx.r23.s64 = 524;
	// li r28,28
	ctx.r28.s64 = 28;
loc_8217B4A4:
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r25,r8
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217b4c0
	if (ctx.cr6.lt) goto loc_8217B4C0;
	// twi 31,r0,22
loc_8217B4C0:
	// lwzx r11,r24,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r11.u32);
	// lwz r10,256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 256);
	// lwz r9,252(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 252);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// divw r7,r8,r23
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r23.s32);
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// ble cr6,0x8217b59c
	if (!ctx.cr6.gt) goto loc_8217B59C;
	// addi r30,r11,300
	ctx.r30.s64 = ctx.r11.s64 + 300;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821746a0
	ctx.lr = 0x8217B4E8;
	sub_821746A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8217b59c
	if (ctx.cr6.eq) goto loc_8217B59C;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8217b504
	if (!ctx.cr6.gt) goto loc_8217B504;
	// twi 31,r0,22
loc_8217B504:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ble cr6,0x8217b51c
	if (!ctx.cr6.gt) goto loc_8217B51C;
	// twi 31,r0,22
loc_8217B51C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82061140
	ctx.lr = 0x8217B538;
	sub_82061140(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82175fb0
	ctx.lr = 0x8217B544;
	sub_82175FB0(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r10,r9,r28
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8217b59c
	if (ctx.cr0.eq) goto loc_8217B59C;
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8217b56c
	if (ctx.cr6.lt) goto loc_8217B56C;
	// twi 31,r0,22
loc_8217B56C:
	// add r5,r29,r11
	ctx.r5.u64 = ctx.r29.u64 + ctx.r11.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x8206e500
	ctx.lr = 0x8217B57C;
	sub_8206E500(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,28
	ctx.r29.s64 = ctx.r29.s64 + 28;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r10,r9,r28
	ctx.r10.s32 = ppc_divw(ctx.r9.s32, ctx.r28.s32);
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8217b56c
	if (ctx.cr6.lt) goto loc_8217B56C;
loc_8217B59C:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// lwz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r25,r8
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217b4a4
	if (ctx.cr6.lt) goto loc_8217B4A4;
loc_8217B5BC:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8217b5d0
	if (!ctx.cr6.gt) goto loc_8217B5D0;
	// twi 31,r0,22
loc_8217B5D0:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x8217b5e8
	if (!ctx.cr6.gt) goto loc_8217B5E8;
	// twi 31,r0,22
loc_8217B5E8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82061140
	ctx.lr = 0x8217B604;
	sub_82061140(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217b618
	if (!ctx.cr6.gt) goto loc_8217B618;
	// twi 31,r0,22
loc_8217B618:
	// lwz r10,152(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82072eb8
	ctx.lr = 0x8217B654;
	sub_82072EB8(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// ld r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82071b80
	ctx.lr = 0x8217B684;
	sub_82071B80(ctx, base);
	// lwz r3,152(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// bl 0x8207a630
	ctx.lr = 0x8217B68C;
	sub_8207A630(ctx, base);
	// stw r26,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r26.u32);
	// stw r26,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r26.u32);
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x8207a630
	ctx.lr = 0x8217B69C;
	sub_8207A630(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217B6A4"))) PPC_WEAK_FUNC(sub_8217B6A4);
PPC_FUNC_IMPL(__imp__sub_8217B6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217B6A8"))) PPC_WEAK_FUNC(sub_8217B6A8);
PPC_FUNC_IMPL(__imp__sub_8217B6A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8217B6B0;
	__savegprlr_25(ctx, base);
	// stwu r1,-2320(r1)
	ea = -2320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,44(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r26,r11,-20780
	ctx.r26.s64 = ctx.r11.s64 + -20780;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r26,1176
	ctx.r4.s64 = ctx.r26.s64 + 1176;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217B6F4;
	sub_821753C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217b8ac
	if (ctx.cr6.eq) goto loc_8217B8AC;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r31,r26,1160
	ctx.r31.s64 = ctx.r26.s64 + 1160;
	// bl 0x821749c8
	ctx.lr = 0x8217B70C;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82175150
	ctx.lr = 0x8217B718;
	sub_82175150(ctx, base);
loc_8217B718:
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// beq cr6,0x8217b73c
	if (ctx.cr6.eq) goto loc_8217B73C;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8217b718
	if (ctx.cr6.eq) goto loc_8217B718;
loc_8217B73C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8217b8ac
	if (!ctx.cr6.eq) goto loc_8217B8AC;
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r5,r26,1216
	ctx.r5.s64 = ctx.r26.s64 + 1216;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217B760;
	sub_82175AE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217B76C;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8217B778;
	sub_82175150(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r11,-31868(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31868);
loc_8217B780:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// beq cr6,0x8217b7a4
	if (ctx.cr6.eq) goto loc_8217B7A4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8217b780
	if (ctx.cr6.eq) goto loc_8217B780;
loc_8217B7A4:
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// beq cr6,0x8217b7e8
	if (ctx.cr6.eq) goto loc_8217B7E8;
	// addi r5,r26,1224
	ctx.r5.s64 = ctx.r26.s64 + 1224;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217B7C8;
	sub_82175AE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217B7D4;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8217B7E0;
	sub_82175150(ctx, base);
	// addi r4,r26,1236
	ctx.r4.s64 = ctx.r26.s64 + 1236;
	// b 0x8217b8a0
	goto loc_8217B8A0;
loc_8217B7E8:
	// addi r4,r26,1312
	ctx.r4.s64 = ctx.r26.s64 + 1312;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x8217B7F8;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217b868
	if (ctx.cr6.eq) goto loc_8217B868;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175bb0
	ctx.lr = 0x8217B80C;
	sub_82175BB0(ctx, base);
	// lfs f0,1156(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 1156);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x8217b868
	if (ctx.cr6.lt) goto loc_8217B868;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175bb0
	ctx.lr = 0x8217B820;
	sub_82175BB0(ctx, base);
	// lfs f0,1156(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 1156);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8217b8b4
	if (!ctx.cr6.gt) goto loc_8217B8B4;
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r5,r26,1420
	ctx.r5.s64 = ctx.r26.s64 + 1420;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217B848;
	sub_82175AE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217B854;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8217B860;
	sub_82175150(ctx, base);
	// addi r4,r26,1428
	ctx.r4.s64 = ctx.r26.s64 + 1428;
	// b 0x8217b8a0
	goto loc_8217B8A0;
loc_8217B868:
	// lwz r11,44(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r5,r26,1320
	ctx.r5.s64 = ctx.r26.s64 + 1320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217B884;
	sub_82175AE8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217B890;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x82175150
	ctx.lr = 0x8217B89C;
	sub_82175150(ctx, base);
	// addi r4,r26,1332
	ctx.r4.s64 = ctx.r26.s64 + 1332;
loc_8217B8A0:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8207a8a8
	ctx.lr = 0x8217B8AC;
	sub_8207A8A8(ctx, base);
loc_8217B8AC:
	// bl 0x8210e878
	ctx.lr = 0x8217B8B0;
	sub_8210E878(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217B8B4;
	sub_8207B288(ctx, base);
loc_8217B8B4:
	// lwz r10,32(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 32);
	// li r9,44
	ctx.r9.s64 = 44;
	// lwz r8,28(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 28);
	// addi r28,r25,16
	ctx.r28.s64 = ctx.r25.s64 + 16;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x8217b924
	if (ctx.cr0.eq) goto loc_8217B924;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
loc_8217B8D8:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r7,16(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r6,r10,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r10.s64;
	// divw r5,r6,r9
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r9.s32);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8217b8f4
	if (ctx.cr6.lt) goto loc_8217B8F4;
	// twi 31,r0,22
loc_8217B8F4:
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r7,r30
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8217b944
	if (ctx.cr6.eq) goto loc_8217B944;
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r7,12(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// addi r8,r8,44
	ctx.r8.s64 = ctx.r8.s64 + 44;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// divw r5,r6,r9
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r9.s32);
	// cmplw cr6,r11,r5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x8217b8d8
	if (ctx.cr6.lt) goto loc_8217B8D8;
loc_8217B924:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8217B92C;
	sub_82079FD8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217b9a0
	if (ctx.cr6.eq) goto loc_8217B9A0;
	// addi r10,r1,156
	ctx.r10.s64 = ctx.r1.s64 + 156;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8217b9a4
	goto loc_8217B9A4;
loc_8217B944:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r8,16(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217b960
	if (ctx.cr6.lt) goto loc_8217B960;
	// twi 31,r0,22
loc_8217B960:
	// mulli r8,r11,44
	ctx.r8.s64 = ctx.r11.s64 * 44;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r6,16(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r5,r10,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r10.s64;
	// divw r4,r5,r9
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r9.s32);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x8217b994
	if (ctx.cr6.lt) goto loc_8217B994;
	// twi 31,r0,22
loc_8217B994:
	// lwzx r3,r10,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// addi r1,r1,2320
	ctx.r1.s64 = ctx.r1.s64 + 2320;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8217B9A0:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8217B9A4:
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// addi r3,r1,156
	ctx.r3.s64 = ctx.r1.s64 + 156;
	// bl 0x82070138
	ctx.lr = 0x8217B9B0;
	sub_82070138(ctx, base);
	// lwz r11,136(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 136);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// addi r4,r26,1480
	ctx.r4.s64 = ctx.r26.s64 + 1480;
	// stw r9,136(r25)
	PPC_STORE_U32(ctx.r25.u32 + 136, ctx.r9.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r11.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r27.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217B9F0;
	sub_821753C8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8217ba0c
	if (!ctx.cr6.eq) goto loc_8217BA0C;
	// addi r4,r26,1480
	ctx.r4.s64 = ctx.r26.s64 + 1480;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217BA08;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217BA0C;
	sub_8207B288(ctx, base);
loc_8217BA0C:
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x8217BA14;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ba2c
	if (ctx.cr6.eq) goto loc_8217BA2C;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// b 0x8217ba30
	goto loc_8217BA30;
loc_8217BA2C:
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r27.u32);
loc_8217BA30:
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r27.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r27.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r27.u32);
	// bl 0x82175fb0
	ctx.lr = 0x8217BA48;
	sub_82175FB0(ctx, base);
	// lwz r11,124(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217ba5c
	if (!ctx.cr6.gt) goto loc_8217BA5C;
	// twi 31,r0,22
loc_8217BA5C:
	// lwz r29,112(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8217BA64:
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217ba70
	if (!ctx.cr6.gt) goto loc_8217BA70;
	// twi 31,r0,22
loc_8217BA70:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8217ba84
	if (ctx.cr6.eq) goto loc_8217BA84;
	// lwz r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8217ba88
	if (ctx.cr6.eq) goto loc_8217BA88;
loc_8217BA84:
	// twi 31,r0,22
loc_8217BA88:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8217bc38
	if (ctx.cr6.eq) goto loc_8217BC38;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8217bb90
	if (!ctx.cr6.eq) goto loc_8217BB90;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8217BAA0:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8217bab0
	if (ctx.cr6.lt) goto loc_8217BAB0;
	// twi 31,r0,22
loc_8217BAB0:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r31,r30,4
	ctx.r31.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217bac4
	if (ctx.cr6.lt) goto loc_8217BAC4;
	// lwz r31,0(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
loc_8217BAC4:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x821753c8
	ctx.lr = 0x8217BADC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217baf8
	if (!ctx.cr6.eq) goto loc_8217BAF8;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217BAF4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217BAF8;
	sub_8207B288(ctx, base);
loc_8217BAF8:
	// addi r4,r26,1488
	ctx.r4.s64 = ctx.r26.s64 + 1488;
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821753c8
	ctx.lr = 0x8217BB10;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217bb2c
	if (!ctx.cr6.eq) goto loc_8217BB2C;
	// addi r4,r26,1488
	ctx.r4.s64 = ctx.r26.s64 + 1488;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217BB28;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217BB2C;
	sub_8207B288(ctx, base);
loc_8217BB2C:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// li r3,20
	ctx.r3.s64 = 20;
	// std r11,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r11.u64);
	// bl 0x82079fd8
	ctx.lr = 0x8217BB3C;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217bb98
	if (ctx.cr6.eq) goto loc_8217BB98;
	// addi r4,r26,1496
	ctx.r4.s64 = ctx.r26.s64 + 1496;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821753c8
	ctx.lr = 0x8217BB60;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217bb7c
	if (!ctx.cr6.eq) goto loc_8217BB7C;
	// addi r4,r26,1496
	ctx.r4.s64 = ctx.r26.s64 + 1496;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8207bc98
	ctx.lr = 0x8217BB78;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217BB7C;
	sub_8207B288(ctx, base);
loc_8217BB7C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x821680d0
	ctx.lr = 0x8217BB88;
	sub_821680D0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8217bb9c
	goto loc_8217BB9C;
loc_8217BB90:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8217baa0
	goto loc_8217BAA0;
loc_8217BB98:
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_8217BB9C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8217bc28
	if (!ctx.cr6.eq) goto loc_8217BC28;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8217BBAC:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8217bbbc
	if (ctx.cr6.lt) goto loc_8217BBBC;
	// twi 31,r0,22
loc_8217BBBC:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,156
	ctx.r3.s64 = ctx.r1.s64 + 156;
	// bl 0x8206d590
	ctx.lr = 0x8217BBC8;
	sub_8206D590(ctx, base);
	// lwz r10,192(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r9,196(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r31,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r31.u32);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r8,0(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8217BBF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8217bc30
	if (!ctx.cr6.eq) goto loc_8217BC30;
	// twi 31,r0,22
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8217BC08:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8217bc18
	if (ctx.cr6.lt) goto loc_8217BC18;
	// twi 31,r0,22
loc_8217BC18:
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r30,r30,28
	ctx.r30.s64 = ctx.r30.s64 + 28;
	// lwz r11,124(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// b 0x8217ba64
	goto loc_8217BA64;
loc_8217BC28:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8217bbac
	goto loc_8217BBAC;
loc_8217BC30:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8217bc08
	goto loc_8217BC08;
loc_8217BC38:
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206d6d0
	ctx.lr = 0x8217BC44;
	sub_8206D6D0(ctx, base);
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r31,144(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// beq cr6,0x8217bc64
	if (ctx.cr6.eq) goto loc_8217BC64;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x82061380
	ctx.lr = 0x8217BC5C;
	sub_82061380(ctx, base);
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x8207a630
	ctx.lr = 0x8217BC64;
	sub_8207A630(ctx, base);
loc_8217BC64:
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r27.u32);
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r27.u32);
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r27.u32);
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x8207a630
	ctx.lr = 0x8217BC78;
	sub_8207A630(ctx, base);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,156(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82070018
	ctx.lr = 0x8217BCA8;
	sub_82070018(ctx, base);
	// lwz r3,180(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x8207a630
	ctx.lr = 0x8217BCB0;
	sub_8207A630(ctx, base);
	// stw r27,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r27.u32);
	// stw r27,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r27.u32);
	// lwz r3,156(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x8207a630
	ctx.lr = 0x8217BCC0;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,2320
	ctx.r1.s64 = ctx.r1.s64 + 2320;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217BCCC"))) PPC_WEAK_FUNC(sub_8217BCCC);
PPC_FUNC_IMPL(__imp__sub_8217BCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217BCD0"))) PPC_WEAK_FUNC(sub_8217BCD0);
PPC_FUNC_IMPL(__imp__sub_8217BCD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8217BCD8;
	__savegprlr_24(ctx, base);
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,752(r1)
	PPC_STORE_U64(ctx.r1.u32 + 752, ctx.r5.u64);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r11,756(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r24,r11,1
	ctx.r24.s64 = ctx.r11.s64 + 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82174af8
	ctx.lr = 0x8217BCF8;
	sub_82174AF8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217bf08
	if (ctx.cr6.eq) goto loc_8217BF08;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r5,524
	ctx.r5.s64 = 524;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r31.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// stw r31,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r31.u32);
	// stw r31,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r31.u32);
	// stw r31,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r31.u32);
	// stw r31,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r31.u32);
	// stw r31,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r31.u32);
	// stw r31,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r31.u32);
	// stw r31,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r31.u32);
	// stw r31,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r31.u32);
	// stw r31,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r31.u32);
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r31.u32);
	// stw r31,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r31.u32);
	// stw r31,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r31.u32);
	// stw r31,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r31.u32);
	// stw r31,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r31.u32);
	// stw r31,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r31.u32);
	// stw r31,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r31.u32);
	// stw r31,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r31.u32);
	// stw r31,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r31.u32);
	// stw r31,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r31.u32);
	// stw r31,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r31.u32);
	// stw r31,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r31.u32);
	// stw r31,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r31.u32);
	// stw r31,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r31.u32);
	// stw r31,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r31.u32);
	// bl 0x8207da20
	ctx.lr = 0x8217BD7C;
	sub_8207DA20(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r1,544
	ctx.r11.s64 = ctx.r1.s64 + 544;
	// mr r9,r31
	ctx.r9.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8217BD8C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8217bd8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217BD8C;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r28,r9,-21836
	ctx.r28.s64 = ctx.r9.s64 + -21836;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r7,255
	ctx.r7.s64 = 255;
	// addi r9,r1,584
	ctx.r9.s64 = ctx.r1.s64 + 584;
	// stb r11,548(r1)
	PPC_STORE_U8(ctx.r1.u32 + 548, ctx.r11.u8);
	// stb r11,549(r1)
	PPC_STORE_U8(ctx.r1.u32 + 549, ctx.r11.u8);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stw r7,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r7.u32);
	// stfs f0,568(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stfs f0,572(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 572, temp.u32);
loc_8217BDCC:
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8217bdcc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217BDCC;
	// addi r10,r28,-3237
	ctx.r10.s64 = ctx.r28.s64 + -3237;
	// stfs f0,608(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// addi r9,r28,-3221
	ctx.r9.s64 = ctx.r28.s64 + -3221;
	// stfs f0,612(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r30.u32);
	// stw r10,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r10.u32);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// stb r11,588(r1)
	PPC_STORE_U8(ctx.r1.u32 + 588, ctx.r11.u8);
	// stb r11,589(r1)
	PPC_STORE_U8(ctx.r1.u32 + 589, ctx.r11.u8);
	// stw r7,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r7.u32);
	// stw r31,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r31.u32);
	// stw r9,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r9.u32);
	// stb r31,204(r1)
	PPC_STORE_U8(ctx.r1.u32 + 204, ctx.r31.u8);
	// bl 0x82174af8
	ctx.lr = 0x8217BE10;
	sub_82174AF8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217bf08
	if (ctx.cr6.eq) goto loc_8217BF08;
	// addi r30,r26,240
	ctx.r30.s64 = ctx.r26.s64 + 240;
	// li r25,524
	ctx.r25.s64 = 524;
loc_8217BE20:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175648
	ctx.lr = 0x8217BE30;
	sub_82175648(ctx, base);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// ld r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r27,r9,r25
	ctx.r27.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// bl 0x8217ab28
	ctx.lr = 0x8217BE54;
	sub_8217AB28(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x8217bea4
	if (ctx.cr6.gt) goto loc_8217BEA4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217be88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217BE88;
	// bdzf 4*cr6+eq,0x8217bea4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217BEA4;
	// bdzf 4*cr6+eq,0x8217be90
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217BE90;
	// bne cr6,0x8217be98
	if (!ctx.cr6.eq) goto loc_8217BE98;
	// lwz r11,488(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 488);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,488(r26)
	PPC_STORE_U32(ctx.r26.u32 + 488, ctx.r11.u32);
	// b 0x8217bea4
	goto loc_8217BEA4;
loc_8217BE88:
	// addi r3,r26,416
	ctx.r3.s64 = ctx.r26.s64 + 416;
	// b 0x8217be9c
	goto loc_8217BE9C;
loc_8217BE90:
	// addi r3,r26,440
	ctx.r3.s64 = ctx.r26.s64 + 440;
	// b 0x8217be9c
	goto loc_8217BE9C;
loc_8217BE98:
	// addi r3,r26,464
	ctx.r3.s64 = ctx.r26.s64 + 464;
loc_8217BE9C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8206e258
	ctx.lr = 0x8217BEA4;
	sub_8206E258(ctx, base);
loc_8217BEA4:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206da08
	ctx.lr = 0x8217BEB0;
	sub_8206DA08(ctx, base);
	// addi r4,r28,3608
	ctx.r4.s64 = ctx.r28.s64 + 3608;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217BEC8;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217bee4
	if (!ctx.cr6.eq) goto loc_8217BEE4;
	// addi r4,r28,3608
	ctx.r4.s64 = ctx.r28.s64 + 3608;
	// addi r3,r28,1056
	ctx.r3.s64 = ctx.r28.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x8217BEE0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217BEE4;
	sub_8207B288(ctx, base);
loc_8217BEE4:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8217bcd0
	ctx.lr = 0x8217BEF4;
	sub_8217BCD0(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217BF00;
	sub_82174AF8(ctx, base);
	// cmplw cr6,r29,r3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8217be20
	if (ctx.cr6.lt) goto loc_8217BE20;
loc_8217BF08:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217BF10"))) PPC_WEAK_FUNC(sub_8217BF10);
PPC_FUNC_IMPL(__imp__sub_8217BF10) {
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
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82176ed0
	ctx.lr = 0x8217BF2C;
	sub_82176ED0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,488(r31)
	PPC_STORE_U32(ctx.r31.u32 + 488, ctx.r11.u32);
	// addi r4,r31,132
	ctx.r4.s64 = ctx.r31.s64 + 132;
	// addi r30,r10,-18236
	ctx.r30.s64 = ctx.r10.s64 + -18236;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r5,r30,-8
	ctx.r5.s64 = ctx.r30.s64 + -8;
	// bl 0x82175ae8
	ctx.lr = 0x8217BF4C;
	sub_82175AE8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// bl 0x8217bcd0
	ctx.lr = 0x8217BF60;
	sub_8217BCD0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,292
	ctx.r4.s64 = ctx.r31.s64 + 292;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82175648
	ctx.lr = 0x8217BF70;
	sub_82175648(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x82175ae8
	ctx.lr = 0x8217BF80;
	sub_82175AE8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r11,r1,152
	ctx.r11.s64 = ctx.r1.s64 + 152;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r8.u32);
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r7,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r7.u32);
loc_8217BFA0:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x8217bfa0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217BFA0;
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// li r5,52
	ctx.r5.s64 = 52;
	// bl 0x8207dac0
	ctx.lr = 0x8217BFBC;
	sub_8207DAC0(ctx, base);
	// addi r3,r31,492
	ctx.r3.s64 = ctx.r31.s64 + 492;
	// ld r5,160(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// ld r6,168(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// lwz r4,488(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// ld r7,176(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 176);
	// ld r8,184(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 184);
	// ld r9,192(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// ld r10,200(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 200);
	// bl 0x8206e368
	ctx.lr = 0x8217BFE0;
	sub_8206E368(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
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

__attribute__((alias("__imp__sub_8217BFF8"))) PPC_WEAK_FUNC(sub_8217BFF8);
PPC_FUNC_IMPL(__imp__sub_8217BFF8) {
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
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8217c024
	if (!ctx.cr6.eq) goto loc_8217C024;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r11,-27289
	ctx.r3.s64 = ctx.r11.s64 + -27289;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217C024:
	// bl 0x8217b150
	ctx.lr = 0x8217C028;
	sub_8217B150(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C03C"))) PPC_WEAK_FUNC(sub_8217C03C);
PPC_FUNC_IMPL(__imp__sub_8217C03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C040"))) PPC_WEAK_FUNC(sub_8217C040);
PPC_FUNC_IMPL(__imp__sub_8217C040) {
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
	// bl 0x8217b150
	ctx.lr = 0x8217C050;
	sub_8217B150(ctx, base);
	// lwz r11,520(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 520);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C068"))) PPC_WEAK_FUNC(sub_8217C068);
PPC_FUNC_IMPL(__imp__sub_8217C068) {
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
	// bl 0x8217b150
	ctx.lr = 0x8217C078;
	sub_8217B150(ctx, base);
	// addi r3,r3,476
	ctx.r3.s64 = ctx.r3.s64 + 476;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C08C"))) PPC_WEAK_FUNC(sub_8217C08C);
PPC_FUNC_IMPL(__imp__sub_8217C08C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C090"))) PPC_WEAK_FUNC(sub_8217C090);
PPC_FUNC_IMPL(__imp__sub_8217C090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8217C098;
	__savegprlr_28(ctx, base);
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,132(r3)
	PPC_STORE_U64(ctx.r3.u32 + 132, ctx.r4.u64);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// std r4,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r4.u64);
	// addi r29,r3,132
	ctx.r29.s64 = ctx.r3.s64 + 132;
	// addi r30,r11,-18844
	ctx.r30.s64 = ctx.r11.s64 + -18844;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r5,r30,-84
	ctx.r5.s64 = ctx.r30.s64 + -84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175ae8
	ctx.lr = 0x8217C0D8;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r30,-72
	ctx.r5.s64 = ctx.r30.s64 + -72;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,296(r31)
	PPC_STORE_U32(ctx.r31.u32 + 296, ctx.r8.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217C0FC;
	sub_82175AE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r30,-68
	ctx.r5.s64 = ctx.r30.s64 + -68;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 312, ctx.r6.u32);
	// lwz r11,4(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r11,316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217C120;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217C124;
	sub_82175D08(ctx, base);
	// stw r3,264(r31)
	PPC_STORE_U32(ctx.r31.u32 + 264, ctx.r3.u32);
	// addi r5,r30,-56
	ctx.r5.s64 = ctx.r30.s64 + -56;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217C138;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217C13C;
	sub_82175D08(ctx, base);
	// stw r3,268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 268, ctx.r3.u32);
	// addi r5,r30,-44
	ctx.r5.s64 = ctx.r30.s64 + -44;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217C150;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r5,r30,-28
	ctx.r5.s64 = ctx.r30.s64 + -28;
	// addi r4,r1,216
	ctx.r4.s64 = ctx.r1.s64 + 216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,300(r31)
	PPC_STORE_U32(ctx.r31.u32 + 300, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,304(r31)
	PPC_STORE_U32(ctx.r31.u32 + 304, ctx.r8.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217C174;
	sub_82175AE8(ctx, base);
	// addi r5,r30,-20
	ctx.r5.s64 = ctx.r30.s64 + -20;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217C184;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217C188;
	sub_82175BB0(ctx, base);
	// addi r5,r30,-12
	ctx.r5.s64 = ctx.r30.s64 + -12;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x8217C19C;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217C1A0;
	sub_82175BB0(ctx, base);
	// addi r5,r30,-4
	ctx.r5.s64 = ctx.r30.s64 + -4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8217C1B4;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217C1B8;
	sub_82175BB0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x8217C1CC;
	sub_82175AE8(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217C1D0;
	sub_82175BB0(ctx, base);
	// li r30,1
	ctx.r30.s64 = 1;
	// stfs f1,212(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 212, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f29,216(r31)
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r31.u32 + 216, temp.u32);
	// stfs f30,220(r31)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r31.u32 + 220, temp.u32);
	// stfs f31,224(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 224, temp.u32);
	// stb r30,176(r31)
	PPC_STORE_U8(ctx.r31.u32 + 176, ctx.r30.u8);
	// bl 0x8217bf10
	ctx.lr = 0x8217C1F0;
	sub_8217BF10(ctx, base);
	// rlwinm r7,r28,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8217c220
	if (!ctx.cr6.eq) goto loc_8217C220;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82176770
	ctx.lr = 0x8217C20C;
	sub_82176770(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8217C220:
	// stb r30,179(r31)
	PPC_STORE_U8(ctx.r31.u32 + 179, ctx.r30.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217C238"))) PPC_WEAK_FUNC(sub_8217C238);
PPC_FUNC_IMPL(__imp__sub_8217C238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8217C240;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,152(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,-2064
	ctx.r8.s64 = ctx.r10.s64 + -2064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f13,124(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// fadds f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f13,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f13
	ctx.cr6.compare(ctx.f31.f64, ctx.f13.f64);
	// bge cr6,0x8217c288
	if (!ctx.cr6.lt) goto loc_8217C288;
loc_8217C27C:
	// fadds f31,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// fcmpu cr6,f31,f13
	ctx.cr6.compare(ctx.f31.f64, ctx.f13.f64);
	// blt cr6,0x8217c27c
	if (ctx.cr6.lt) goto loc_8217C27C;
loc_8217C288:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// blt cr6,0x8217c29c
	if (ctx.cr6.lt) goto loc_8217C29C;
loc_8217C290:
	// fsubs f31,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bge cr6,0x8217c290
	if (!ctx.cr6.lt) goto loc_8217C290;
loc_8217C29C:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// li r30,1
	ctx.r30.s64 = 1;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217C2AC;
	sub_82174AF8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// ble cr6,0x8217c308
	if (!ctx.cr6.gt) goto loc_8217C308;
	// addi r29,r31,160
	ctx.r29.s64 = ctx.r31.s64 + 160;
loc_8217C2B8:
	// addi r5,r30,-1
	ctx.r5.s64 = ctx.r30.s64 + -1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175648
	ctx.lr = 0x8217C2C8;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217C2CC;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// bge cr6,0x8217c2f0
	if (!ctx.cr6.lt) goto loc_8217C2F0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175648
	ctx.lr = 0x8217C2E4;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8217C2E8;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// ble cr6,0x8217c308
	if (!ctx.cr6.gt) goto loc_8217C308;
loc_8217C2F0:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217C300;
	sub_82174AF8(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8217c2b8
	if (ctx.cr6.lt) goto loc_8217C2B8;
loc_8217C308:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217C314;
	sub_82174AF8(ctx, base);
	// divwu r10,r30,r3
	ctx.r10.u32 = ppc_divwu(ctx.r30.u32, ctx.r3.u32);
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// mullw r9,r10,r3
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r3.s32);
	// subf r5,r9,r30
	ctx.r5.s64 = ctx.r30.s64 - ctx.r9.s64;
	// cmpw cr6,r5,r11
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8217c458
	if (ctx.cr6.eq) goto loc_8217C458;
	// stw r5,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r5.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r4,r31,168
	ctx.r4.s64 = ctx.r31.s64 + 168;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// bl 0x82175648
	ctx.lr = 0x8217C348;
	sub_82175648(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217C354;
	sub_821749C8(ctx, base);
	// lwz r26,0(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r30,24(r26)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r29,r11,-11
	ctx.r29.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217C370;
	sub_82174AF8(ctx, base);
	// add r10,r29,r30
	ctx.r10.u64 = ctx.r29.u64 + ctx.r30.u64;
	// lbzx r9,r29,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r29.u32 + ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217C3AC;
	sub_82174818(ctx, base);
	// lwz r6,28(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 28);
	// lwz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r30,r31,8
	ctx.r30.s64 = ctx.r31.s64 + 8;
	// add r29,r3,r6
	ctx.r29.u64 = ctx.r3.u64 + ctx.r6.u64;
	// cmplwi cr6,r5,16
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 16, ctx.xer);
	// blt cr6,0x8217c3cc
	if (ctx.cr6.lt) goto loc_8217C3CC;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x8217c3d0
	goto loc_8217C3D0;
loc_8217C3CC:
	// addi r4,r30,4
	ctx.r4.s64 = ctx.r30.s64 + 4;
loc_8217C3D0:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// ld r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r31.u32 + 140);
	// bl 0x82178778
	ctx.lr = 0x8217C3E4;
	sub_82178778(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c430
	if (!ctx.cr6.eq) goto loc_8217C430;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217c404
	if (ctx.cr6.lt) goto loc_8217C404;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x8217c408
	goto loc_8217C408;
loc_8217C404:
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
loc_8217C408:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8210e878
	ctx.lr = 0x8217C410;
	sub_8210E878(ctx, base);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stb r28,176(r31)
	PPC_STORE_U8(ctx.r31.u32 + 176, ctx.r28.u8);
	// std r11,140(r31)
	PPC_STORE_U64(ctx.r31.u32 + 140, ctx.r11.u64);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8217C430:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,140(r31)
	PPC_STORE_U64(ctx.r31.u32 + 140, ctx.r9.u64);
	// bl 0x8217c090
	ctx.lr = 0x8217C458;
	sub_8217C090(ctx, base);
loc_8217C458:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217C464"))) PPC_WEAK_FUNC(sub_8217C464);
PPC_FUNC_IMPL(__imp__sub_8217C464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C468"))) PPC_WEAK_FUNC(sub_8217C468);
PPC_FUNC_IMPL(__imp__sub_8217C468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8217C470;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r27,r5,0,27,27
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x10;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// bne cr6,0x8217c494
	if (!ctx.cr6.eq) goto loc_8217C494;
	// addi r3,r31,64
	ctx.r3.s64 = ctx.r31.s64 + 64;
loc_8217C494:
	// clrlwi r11,r26,29
	ctx.r11.u64 = ctx.r26.u32 & 0x7;
	// rlwinm r11,r11,0,31,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c4d8
	if (!ctx.cr6.eq) goto loc_8217C4D8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8217C4A8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217c4a8
	if (!ctx.cr6.eq) goto loc_8217C4A8;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x820654f8
	ctx.lr = 0x8217C4D0;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8217c6b0
	if (ctx.cr6.eq) goto loc_8217C6B0;
loc_8217C4D8:
	// lbz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217c4f0
	if (ctx.cr6.eq) goto loc_8217C4F0;
	// rlwinm r11,r26,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c6b0
	if (!ctx.cr6.eq) goto loc_8217C6B0;
loc_8217C4F0:
	// rlwinm r11,r26,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217c504
	if (ctx.cr6.eq) goto loc_8217C504;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217a0d8
	ctx.lr = 0x8217C504;
	sub_8217A0D8(ctx, base);
loc_8217C504:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r31,8
	ctx.r29.s64 = ctx.r31.s64 + 8;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// blt cr6,0x8217c528
	if (ctx.cr6.lt) goto loc_8217C528;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x8217c52c
	goto loc_8217C52C;
loc_8217C528:
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
loc_8217C52C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// ld r7,140(r31)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r31.u32 + 140);
	// bl 0x82178778
	ctx.lr = 0x8217C540;
	sub_82178778(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c588
	if (!ctx.cr6.eq) goto loc_8217C588;
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217c560
	if (ctx.cr6.lt) goto loc_8217C560;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x8217c564
	goto loc_8217C564;
loc_8217C560:
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
loc_8217C564:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8210e878
	ctx.lr = 0x8217C56C;
	sub_8210E878(ctx, base);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r28.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stb r28,176(r31)
	PPC_STORE_U8(ctx.r31.u32 + 176, ctx.r28.u8);
	// std r11,140(r31)
	PPC_STORE_U64(ctx.r31.u32 + 140, ctx.r11.u64);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217C588:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8217C58C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217c58c
	if (!ctx.cr6.eq) goto loc_8217C58C;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8217C5B4;
	sub_82060368(ctx, base);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8217c5e8
	if (!ctx.cr6.eq) goto loc_8217C5E8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8217C5C0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217c5c0
	if (!ctx.cr6.eq) goto loc_8217C5C0;
	// subf r11,r30,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r30.s64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r31,64
	ctx.r3.s64 = ctx.r31.s64 + 64;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8217C5E8;
	sub_82060368(ctx, base);
loc_8217C5E8:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r30,r10,-18984
	ctx.r30.s64 = ctx.r10.s64 + -18984;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r5,r30,-20
	ctx.r5.s64 = ctx.r30.s64 + -20;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// ld r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r9,140(r31)
	PPC_STORE_U64(ctx.r31.u32 + 140, ctx.r9.u64);
	// bl 0x82175ae8
	ctx.lr = 0x8217C618;
	sub_82175AE8(ctx, base);
	// bl 0x82175d08
	ctx.lr = 0x8217C61C;
	sub_82175D08(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8217c694
	if (ctx.cr6.lt) goto loc_8217C694;
	// bne cr6,0x8217c6b0
	if (!ctx.cr6.eq) goto loc_8217C6B0;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r5,r30,-12
	ctx.r5.s64 = ctx.r30.s64 + -12;
	// stb r11,148(r31)
	PPC_STORE_U8(ctx.r31.u32 + 148, ctx.r11.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175ae8
	ctx.lr = 0x8217C640;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r8.u32);
	// bl 0x82175ae8
	ctx.lr = 0x8217C664;
	sub_82175AE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r5,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r5.u32);
	// lwz r11,4(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r11,172(r31)
	PPC_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// stw r6,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r6.u32);
	// bl 0x8217c238
	ctx.lr = 0x8217C68C;
	sub_8217C238(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8217C694:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// bl 0x8217c090
	ctx.lr = 0x8217C6B0;
	sub_8217C090(ctx, base);
loc_8217C6B0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217C6B8"))) PPC_WEAK_FUNC(sub_8217C6B8);
PPC_FUNC_IMPL(__imp__sub_8217C6B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8217c6cc
	if (ctx.cr6.lt) goto loc_8217C6CC;
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x8217c6d0
	goto loc_8217C6D0;
loc_8217C6CC:
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
loc_8217C6D0:
	// b 0x8217c468
	sub_8217C468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217C6D4"))) PPC_WEAK_FUNC(sub_8217C6D4);
PPC_FUNC_IMPL(__imp__sub_8217C6D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C6D8"))) PPC_WEAK_FUNC(sub_8217C6D8);
PPC_FUNC_IMPL(__imp__sub_8217C6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lfs f13,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x8217c700
	if (!ctx.cr6.lt) goto loc_8217C700;
loc_8217C6F4:
	// fadds f1,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// blt cr6,0x8217c6f4
	if (ctx.cr6.lt) goto loc_8217C6F4;
loc_8217C700:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x8217c714
	if (ctx.cr6.lt) goto loc_8217C714;
loc_8217C708:
	// fsubs f1,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x8217c708
	if (!ctx.cr6.lt) goto loc_8217C708;
loc_8217C714:
	// lbz r11,148(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 148);
	// stfs f1,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8217c238
	sub_8217C238(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217C72C"))) PPC_WEAK_FUNC(sub_8217C72C);
PPC_FUNC_IMPL(__imp__sub_8217C72C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C730"))) PPC_WEAK_FUNC(sub_8217C730);
PPC_FUNC_IMPL(__imp__sub_8217C730) {
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
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8217c760
	if (!ctx.cr6.eq) goto loc_8217C760;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r4,r11,-27289
	ctx.r4.s64 = ctx.r11.s64 + -27289;
	// b 0x8217c76c
	goto loc_8217C76C;
loc_8217C760:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217b150
	ctx.lr = 0x8217C768;
	sub_8217B150(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8217C76C:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217C778;
	sub_82178AB0(ctx, base);
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

__attribute__((alias("__imp__sub_8217C790"))) PPC_WEAK_FUNC(sub_8217C790);
PPC_FUNC_IMPL(__imp__sub_8217C790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,148(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217c7a0
	if (ctx.cr6.eq) goto loc_8217C7A0;
	// b 0x8217c6d8
	sub_8217C6D8(ctx, base);
	return;
loc_8217C7A0:
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r10,524
	ctx.r10.s64 = 524;
	// lwz r9,256(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217c7bc
	if (!ctx.cr0.eq) goto loc_8217C7BC;
	// twi 31,r0,22
loc_8217C7BC:
	// stfs f1,492(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 492, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C7C4"))) PPC_WEAK_FUNC(sub_8217C7C4);
PPC_FUNC_IMPL(__imp__sub_8217C7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C7C8"))) PPC_WEAK_FUNC(sub_8217C7C8);
PPC_FUNC_IMPL(__imp__sub_8217C7C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x8217C7D0;
	__savegprlr_21(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,316(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217C7E4;
	sub_82174AF8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r24,r11,-27289
	ctx.r24.s64 = ctx.r11.s64 + -27289;
	// beq cr6,0x8217ca24
	if (ctx.cr6.eq) goto loc_8217CA24;
	// lwz r11,324(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 324);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f13,120(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// bge cr6,0x8217ca24
	if (!ctx.cr6.lt) goto loc_8217CA24;
	// addi r27,r29,312
	ctx.r27.s64 = ctx.r29.s64 + 312;
loc_8217C820:
	// lwz r11,320(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// stw r5,320(r29)
	PPC_STORE_U32(ctx.r29.u32 + 320, ctx.r5.u32);
	// bl 0x82175648
	ctx.lr = 0x8217C838;
	sub_82175648(ctx, base);
	// addi r4,r24,9225
	ctx.r4.s64 = ctx.r24.s64 + 9225;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217C84C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c868
	if (!ctx.cr6.eq) goto loc_8217C868;
	// addi r4,r24,9225
	ctx.r4.s64 = ctx.r24.s64 + 9225;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217C864;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217C868;
	sub_8207B288(ctx, base);
loc_8217C868:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217C870;
	sub_82175D08(ctx, base);
	// stw r3,324(r29)
	PPC_STORE_U32(ctx.r29.u32 + 324, ctx.r3.u32);
	// lwz r11,320(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x82175648
	ctx.lr = 0x8217C888;
	sub_82175648(ctx, base);
	// addi r4,r24,9233
	ctx.r4.s64 = ctx.r24.s64 + 9233;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217C89C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c8b8
	if (!ctx.cr6.eq) goto loc_8217C8B8;
	// addi r4,r24,9233
	ctx.r4.s64 = ctx.r24.s64 + 9233;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217C8B4;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217C8B8;
	sub_8207B288(ctx, base);
loc_8217C8B8:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175d08
	ctx.lr = 0x8217C8C0;
	sub_82175D08(ctx, base);
	// stw r3,328(r29)
	PPC_STORE_U32(ctx.r29.u32 + 328, ctx.r3.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r5,320(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82175648
	ctx.lr = 0x8217C8D4;
	sub_82175648(ctx, base);
	// addi r4,r24,9241
	ctx.r4.s64 = ctx.r24.s64 + 9241;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217C8EC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c908
	if (!ctx.cr6.eq) goto loc_8217C908;
	// addi r4,r24,9241
	ctx.r4.s64 = ctx.r24.s64 + 9241;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217C904;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217C908;
	sub_8207B288(ctx, base);
loc_8217C908:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175d08
	ctx.lr = 0x8217C910;
	sub_82175D08(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8217ca00
	if (!ctx.cr6.eq) goto loc_8217CA00;
	// addi r4,r24,9249
	ctx.r4.s64 = ctx.r24.s64 + 9249;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r25.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x821753c8
	ctx.lr = 0x8217C930;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c94c
	if (!ctx.cr6.eq) goto loc_8217C94C;
	// addi r4,r24,9249
	ctx.r4.s64 = ctx.r24.s64 + 9249;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217C948;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217C94C;
	sub_8207B288(ctx, base);
loc_8217C94C:
	// addi r4,r24,9257
	ctx.r4.s64 = ctx.r24.s64 + 9257;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821753c8
	ctx.lr = 0x8217C964;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217c980
	if (!ctx.cr6.eq) goto loc_8217C980;
	// addi r4,r24,9257
	ctx.r4.s64 = ctx.r24.s64 + 9257;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217C97C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217C980;
	sub_8207B288(ctx, base);
loc_8217C980:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821749c8
	ctx.lr = 0x8217C988;
	sub_821749C8(ctx, base);
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r31,24(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217C9A4;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r8.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217C9E0;
	sub_82174818(ctx, base);
	// lwz r6,28(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lbz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8217ca00
	if (ctx.cr6.eq) goto loc_8217CA00;
	// addi r4,r24,2280
	ctx.r4.s64 = ctx.r24.s64 + 2280;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217CA00;
	sub_82178AB0(ctx, base);
loc_8217CA00:
	// lwz r11,324(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 324);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// blt cr6,0x8217c820
	if (ctx.cr6.lt) goto loc_8217C820;
loc_8217CA24:
	// lwz r11,276(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 276);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// bge cr6,0x8217cb5c
	if (!ctx.cr6.lt) goto loc_8217CB5C;
	// addi r31,r29,292
	ctx.r31.s64 = ctx.r29.s64 + 292;
loc_8217CA4C:
	// lwz r11,272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
	// stw r5,272(r29)
	PPC_STORE_U32(ctx.r29.u32 + 272, ctx.r5.u32);
	// bl 0x82175648
	ctx.lr = 0x8217CA64;
	sub_82175648(ctx, base);
	// addi r4,r24,9265
	ctx.r4.s64 = ctx.r24.s64 + 9265;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CA78;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ca94
	if (!ctx.cr6.eq) goto loc_8217CA94;
	// addi r4,r24,9265
	ctx.r4.s64 = ctx.r24.s64 + 9265;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CA90;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CA94;
	sub_8207B288(ctx, base);
loc_8217CA94:
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwz r5,272(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// std r11,284(r29)
	PPC_STORE_U64(ctx.r29.u32 + 284, ctx.r11.u64);
	// bl 0x82175648
	ctx.lr = 0x8217CAAC;
	sub_82175648(ctx, base);
	// addi r4,r24,9273
	ctx.r4.s64 = ctx.r24.s64 + 9273;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CAC0;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217cadc
	if (!ctx.cr6.eq) goto loc_8217CADC;
	// addi r4,r24,9273
	ctx.r4.s64 = ctx.r24.s64 + 9273;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CAD8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CADC;
	sub_8207B288(ctx, base);
loc_8217CADC:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175d08
	ctx.lr = 0x8217CAE4;
	sub_82175D08(ctx, base);
	// stw r3,276(r29)
	PPC_STORE_U32(ctx.r29.u32 + 276, ctx.r3.u32);
	// lwz r11,272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x82175648
	ctx.lr = 0x8217CAFC;
	sub_82175648(ctx, base);
	// addi r4,r24,9281
	ctx.r4.s64 = ctx.r24.s64 + 9281;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CB10;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217cb2c
	if (!ctx.cr6.eq) goto loc_8217CB2C;
	// addi r4,r24,9281
	ctx.r4.s64 = ctx.r24.s64 + 9281;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CB28;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CB2C;
	sub_8207B288(ctx, base);
loc_8217CB2C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175d08
	ctx.lr = 0x8217CB34;
	sub_82175D08(ctx, base);
	// stw r3,280(r29)
	PPC_STORE_U32(ctx.r29.u32 + 280, ctx.r3.u32);
	// lwz r11,276(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 276);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f12,184(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f12.f64 = double(temp.f32);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8217ca4c
	if (ctx.cr6.lt) goto loc_8217CA4C;
loc_8217CB5C:
	// lwz r11,256(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 256);
	// li r21,524
	ctx.r21.s64 = 524;
	// lwz r10,252(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 252);
	// li r22,1
	ctx.r22.s64 = 1;
	// addi r23,r29,240
	ctx.r23.s64 = ctx.r29.s64 + 240;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r27,r22
	ctx.r27.u64 = ctx.r22.u64;
	// divw r8,r9,r21
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r21.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8217cca0
	if (!ctx.cr6.gt) goto loc_8217CCA0;
loc_8217CB84:
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// lwz r11,16(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r21
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r21.s32);
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217cba0
	if (ctx.cr6.lt) goto loc_8217CBA0;
	// twi 31,r0,22
loc_8217CBA0:
	// mulli r11,r27,524
	ctx.r11.s64 = ctx.r27.s64 * 524;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// stb r25,428(r31)
	PPC_STORE_U8(ctx.r31.u32 + 428, ctx.r25.u8);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// mulli r10,r11,148
	ctx.r10.s64 = ctx.r11.s64 * 148;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// addi r30,r11,132
	ctx.r30.s64 = ctx.r11.s64 + 132;
	// mulli r11,r8,148
	ctx.r11.s64 = ctx.r8.s64 * 148;
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r28,r11,132
	ctx.r28.s64 = ctx.r11.s64 + 132;
	// bge cr6,0x8217cc84
	if (!ctx.cr6.lt) goto loc_8217CC84;
loc_8217CBE0:
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stb r22,428(r31)
	PPC_STORE_U8(ctx.r31.u32 + 428, ctx.r22.u8);
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// ld r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r31.u32 + 24);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// bl 0x82177590
	ctx.lr = 0x8217CC18;
	sub_82177590(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217cc34
	if (!ctx.cr6.eq) goto loc_8217CC34;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82178980
	ctx.lr = 0x8217CC34;
	sub_82178980(ctx, base);
loc_8217CC34:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217cc74
	if (ctx.cr6.eq) goto loc_8217CC74;
	// lwz r26,140(r30)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8217cc58
	if (!ctx.cr6.eq) goto loc_8217CC58;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// b 0x8217cc68
	goto loc_8217CC68;
loc_8217CC58:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8217b150
	ctx.lr = 0x8217CC64;
	sub_8217B150(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8217CC68:
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217CC74;
	sub_82178AB0(ctx, base);
loc_8217CC74:
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8217cbe0
	if (ctx.cr6.lt) goto loc_8217CBE0;
loc_8217CC84:
	// lwz r11,16(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r21
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r21.s32);
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217cb84
	if (ctx.cr6.lt) goto loc_8217CB84;
loc_8217CCA0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217CCA8"))) PPC_WEAK_FUNC(sub_8217CCA8);
PPC_FUNC_IMPL(__imp__sub_8217CCA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x8217CCB0;
	__savegprlr_21(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,316(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82174af8
	ctx.lr = 0x8217CCC8;
	sub_82174AF8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r24,r11,-27289
	ctx.r24.s64 = ctx.r11.s64 + -27289;
	// beq cr6,0x8217cf18
	if (ctx.cr6.eq) goto loc_8217CF18;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82174af8
	ctx.lr = 0x8217CCE4;
	sub_82174AF8(ctx, base);
	// lwz r11,320(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8217cf18
	if (!ctx.cr6.lt) goto loc_8217CF18;
loc_8217CCF4:
	// lwz r11,328(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 328);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bgt cr6,0x8217cf18
	if (ctx.cr6.gt) goto loc_8217CF18;
	// lwz r11,320(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// addi r31,r29,312
	ctx.r31.s64 = ctx.r29.s64 + 312;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r5,320(r29)
	PPC_STORE_U32(ctx.r29.u32 + 320, ctx.r5.u32);
	// bl 0x82175648
	ctx.lr = 0x8217CD34;
	sub_82175648(ctx, base);
	// addi r4,r24,9161
	ctx.r4.s64 = ctx.r24.s64 + 9161;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r25.u32);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CD48;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217cd64
	if (!ctx.cr6.eq) goto loc_8217CD64;
	// addi r4,r24,9161
	ctx.r4.s64 = ctx.r24.s64 + 9161;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CD60;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CD64;
	sub_8207B288(ctx, base);
loc_8217CD64:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217CD6C;
	sub_82175D08(ctx, base);
	// stw r3,324(r29)
	PPC_STORE_U32(ctx.r29.u32 + 324, ctx.r3.u32);
	// lwz r11,320(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x82175648
	ctx.lr = 0x8217CD84;
	sub_82175648(ctx, base);
	// addi r4,r24,9169
	ctx.r4.s64 = ctx.r24.s64 + 9169;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CD98;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217cdb4
	if (!ctx.cr6.eq) goto loc_8217CDB4;
	// addi r4,r24,9169
	ctx.r4.s64 = ctx.r24.s64 + 9169;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CDB0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CDB4;
	sub_8207B288(ctx, base);
loc_8217CDB4:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175d08
	ctx.lr = 0x8217CDBC;
	sub_82175D08(ctx, base);
	// stw r3,328(r29)
	PPC_STORE_U32(ctx.r29.u32 + 328, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r5,320(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82175648
	ctx.lr = 0x8217CDD0;
	sub_82175648(ctx, base);
	// addi r4,r24,9177
	ctx.r4.s64 = ctx.r24.s64 + 9177;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CDE8;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ce04
	if (!ctx.cr6.eq) goto loc_8217CE04;
	// addi r4,r24,9177
	ctx.r4.s64 = ctx.r24.s64 + 9177;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CE00;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CE04;
	sub_8207B288(ctx, base);
loc_8217CE04:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175d08
	ctx.lr = 0x8217CE0C;
	sub_82175D08(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8217cefc
	if (!ctx.cr6.eq) goto loc_8217CEFC;
	// addi r4,r24,9185
	ctx.r4.s64 = ctx.r24.s64 + 9185;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r25.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x821753c8
	ctx.lr = 0x8217CE2C;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ce48
	if (!ctx.cr6.eq) goto loc_8217CE48;
	// addi r4,r24,9185
	ctx.r4.s64 = ctx.r24.s64 + 9185;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CE44;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CE48;
	sub_8207B288(ctx, base);
loc_8217CE48:
	// addi r4,r24,9193
	ctx.r4.s64 = ctx.r24.s64 + 9193;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821753c8
	ctx.lr = 0x8217CE60;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ce7c
	if (!ctx.cr6.eq) goto loc_8217CE7C;
	// addi r4,r24,9193
	ctx.r4.s64 = ctx.r24.s64 + 9193;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CE78;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CE7C;
	sub_8207B288(ctx, base);
loc_8217CE7C:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821749c8
	ctx.lr = 0x8217CE84;
	sub_821749C8(ctx, base);
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r31,24(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217CEA0;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217CEDC;
	sub_82174818(ctx, base);
	// lwz r6,28(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lbz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8217cefc
	if (ctx.cr6.eq) goto loc_8217CEFC;
	// addi r4,r24,2264
	ctx.r4.s64 = ctx.r24.s64 + 2264;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217CEFC;
	sub_82178AB0(ctx, base);
loc_8217CEFC:
	// lwz r11,316(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 316);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217CF08;
	sub_82174AF8(ctx, base);
	// lwz r11,320(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 320);
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8217ccf4
	if (ctx.cr6.lt) goto loc_8217CCF4;
loc_8217CF18:
	// lwz r11,296(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 296);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217CF24;
	sub_82174AF8(ctx, base);
	// lwz r11,272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8217d064
	if (!ctx.cr6.lt) goto loc_8217D064;
loc_8217CF34:
	// lwz r11,280(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 280);
	// lfs f0,184(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bgt cr6,0x8217d064
	if (ctx.cr6.gt) goto loc_8217D064;
	// lwz r11,272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// addi r31,r29,292
	ctx.r31.s64 = ctx.r29.s64 + 292;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r5,272(r29)
	PPC_STORE_U32(ctx.r29.u32 + 272, ctx.r5.u32);
	// bl 0x82175648
	ctx.lr = 0x8217CF74;
	sub_82175648(ctx, base);
	// addi r4,r24,9201
	ctx.r4.s64 = ctx.r24.s64 + 9201;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r25.u32);
	// stw r25,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CF88;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217cfa4
	if (!ctx.cr6.eq) goto loc_8217CFA4;
	// addi r4,r24,9201
	ctx.r4.s64 = ctx.r24.s64 + 9201;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CFA0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CFA4;
	sub_8207B288(ctx, base);
loc_8217CFA4:
	// ld r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lwz r5,272(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// std r11,284(r29)
	PPC_STORE_U64(ctx.r29.u32 + 284, ctx.r11.u64);
	// bl 0x82175648
	ctx.lr = 0x8217CFBC;
	sub_82175648(ctx, base);
	// addi r4,r24,9209
	ctx.r4.s64 = ctx.r24.s64 + 9209;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r25.u32);
	// stw r25,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217CFD0;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217cfec
	if (!ctx.cr6.eq) goto loc_8217CFEC;
	// addi r4,r24,9209
	ctx.r4.s64 = ctx.r24.s64 + 9209;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217CFE8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217CFEC;
	sub_8207B288(ctx, base);
loc_8217CFEC:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175d08
	ctx.lr = 0x8217CFF4;
	sub_82175D08(ctx, base);
	// stw r3,276(r29)
	PPC_STORE_U32(ctx.r29.u32 + 276, ctx.r3.u32);
	// lwz r11,272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x82175648
	ctx.lr = 0x8217D00C;
	sub_82175648(ctx, base);
	// addi r4,r24,9217
	ctx.r4.s64 = ctx.r24.s64 + 9217;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r25.u32);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D020;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d03c
	if (!ctx.cr6.eq) goto loc_8217D03C;
	// addi r4,r24,9217
	ctx.r4.s64 = ctx.r24.s64 + 9217;
	// addi r3,r24,6509
	ctx.r3.s64 = ctx.r24.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D038;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D03C;
	sub_8207B288(ctx, base);
loc_8217D03C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175d08
	ctx.lr = 0x8217D044;
	sub_82175D08(ctx, base);
	// stw r3,280(r29)
	PPC_STORE_U32(ctx.r29.u32 + 280, ctx.r3.u32);
	// lwz r11,296(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 296);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D054;
	sub_82174AF8(ctx, base);
	// lwz r11,272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 272);
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8217cf34
	if (ctx.cr6.lt) goto loc_8217CF34;
loc_8217D064:
	// lwz r11,256(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 256);
	// li r21,524
	ctx.r21.s64 = 524;
	// lwz r10,252(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 252);
	// li r22,1
	ctx.r22.s64 = 1;
	// addi r23,r29,240
	ctx.r23.s64 = ctx.r29.s64 + 240;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r26,r22
	ctx.r26.u64 = ctx.r22.u64;
	// divw r8,r9,r21
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r21.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8217d1cc
	if (!ctx.cr6.gt) goto loc_8217D1CC;
loc_8217D08C:
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// lwz r11,16(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r21
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r21.s32);
	// cmplw cr6,r26,r8
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217d0a8
	if (ctx.cr6.lt) goto loc_8217D0A8;
	// twi 31,r0,22
loc_8217D0A8:
	// mulli r11,r26,524
	ctx.r11.s64 = ctx.r26.s64 * 524;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r25,428(r31)
	PPC_STORE_U8(ctx.r31.u32 + 428, ctx.r25.u8);
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// mulli r11,r11,148
	ctx.r11.s64 = ctx.r11.s64 * 148;
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mulli r10,r8,148
	ctx.r10.s64 = ctx.r8.s64 * 148;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// addi r30,r11,132
	ctx.r30.s64 = ctx.r11.s64 + 132;
	// addi r28,r10,132
	ctx.r28.s64 = ctx.r10.s64 + 132;
	// bl 0x82174af8
	ctx.lr = 0x8217D0E4;
	sub_82174AF8(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r3,-2
	ctx.r6.s64 = ctx.r3.s64 + -2;
	// cmplw cr6,r7,r6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x8217d1b0
	if (!ctx.cr6.lt) goto loc_8217D1B0;
loc_8217D0F4:
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,184(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x8217d1b0
	if (ctx.cr6.gt) goto loc_8217D1B0;
	// lwz r11,432(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 432);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stb r22,428(r31)
	PPC_STORE_U8(ctx.r31.u32 + 428, ctx.r22.u8);
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// ld r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r10,432(r31)
	PPC_STORE_U32(ctx.r31.u32 + 432, ctx.r10.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// bl 0x82177590
	ctx.lr = 0x8217D138;
	sub_82177590(ctx, base);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217d154
	if (!ctx.cr6.eq) goto loc_8217D154;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r31,92
	ctx.r4.s64 = ctx.r31.s64 + 92;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82178980
	ctx.lr = 0x8217D154;
	sub_82178980(ctx, base);
loc_8217D154:
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217d194
	if (ctx.cr6.eq) goto loc_8217D194;
	// lwz r27,140(r30)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// bne cr6,0x8217d178
	if (!ctx.cr6.eq) goto loc_8217D178;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// b 0x8217d188
	goto loc_8217D188;
loc_8217D178:
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8217b150
	ctx.lr = 0x8217D184;
	sub_8217B150(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8217D188:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217D194;
	sub_82178AB0(ctx, base);
loc_8217D194:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D1A0;
	sub_82174AF8(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8217d0f4
	if (ctx.cr6.lt) goto loc_8217D0F4;
loc_8217D1B0:
	// lwz r11,16(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r21
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r21.s32);
	// cmplw cr6,r26,r8
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217d08c
	if (ctx.cr6.lt) goto loc_8217D08C;
loc_8217D1CC:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217D1D4"))) PPC_WEAK_FUNC(sub_8217D1D4);
PPC_FUNC_IMPL(__imp__sub_8217D1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D1D8"))) PPC_WEAK_FUNC(sub_8217D1D8);
PPC_FUNC_IMPL(__imp__sub_8217D1D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c960
	ctx.lr = 0x8217D1E0;
	__savegprlr_18(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,316(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82174af8
	ctx.lr = 0x8217D1F8;
	sub_82174AF8(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r26,r11,-27289
	ctx.r26.s64 = ctx.r11.s64 + -27289;
	// beq cr6,0x8217d4cc
	if (ctx.cr6.eq) goto loc_8217D4CC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// bl 0x82174af8
	ctx.lr = 0x8217D218;
	sub_82174AF8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217d2c0
	if (ctx.cr6.eq) goto loc_8217D2C0;
	// addi r30,r22,312
	ctx.r30.s64 = ctx.r22.s64 + 312;
loc_8217D224:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8217D234;
	sub_82175648(ctx, base);
	// addi r4,r26,9073
	ctx.r4.s64 = ctx.r26.s64 + 9073;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D248;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d264
	if (!ctx.cr6.eq) goto loc_8217D264;
	// addi r4,r26,9073
	ctx.r4.s64 = ctx.r26.s64 + 9073;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D260;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D264;
	sub_8207B288(ctx, base);
loc_8217D264:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D26C;
	sub_82175D08(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,184(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x8217d2b0
	if (ctx.cr6.eq) goto loc_8217D2B0;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8217d2b8
	if (ctx.cr6.gt) goto loc_8217D2B8;
	// lwz r11,316(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 316);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D2A4;
	sub_82174AF8(ctx, base);
	// cmplw cr6,r31,r3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8217d224
	if (ctx.cr6.lt) goto loc_8217D224;
	// b 0x8217d2c0
	goto loc_8217D2C0;
loc_8217D2B0:
	// stw r31,320(r22)
	PPC_STORE_U32(ctx.r22.u32 + 320, ctx.r31.u32);
	// b 0x8217d2c0
	goto loc_8217D2C0;
loc_8217D2B8:
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// stw r11,320(r22)
	PPC_STORE_U32(ctx.r22.u32 + 320, ctx.r11.u32);
loc_8217D2C0:
	// lwz r11,316(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 316);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D2CC;
	sub_82174AF8(ctx, base);
	// lwz r10,320(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 320);
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// addi r31,r22,320
	ctx.r31.s64 = ctx.r22.s64 + 320;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x8217d2ec
	if (ctx.cr6.lt) goto loc_8217D2EC;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8217D2EC:
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r30,r22,312
	ctx.r30.s64 = ctx.r22.s64 + 312;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// bl 0x82175648
	ctx.lr = 0x8217D304;
	sub_82175648(ctx, base);
	// addi r4,r26,9081
	ctx.r4.s64 = ctx.r26.s64 + 9081;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D318;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d334
	if (!ctx.cr6.eq) goto loc_8217D334;
	// addi r4,r26,9081
	ctx.r4.s64 = ctx.r26.s64 + 9081;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D330;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D334;
	sub_8207B288(ctx, base);
loc_8217D334:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D33C;
	sub_82175D08(ctx, base);
	// stw r3,324(r22)
	PPC_STORE_U32(ctx.r22.u32 + 324, ctx.r3.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// bl 0x82175648
	ctx.lr = 0x8217D354;
	sub_82175648(ctx, base);
	// addi r4,r26,9089
	ctx.r4.s64 = ctx.r26.s64 + 9089;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D368;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d384
	if (!ctx.cr6.eq) goto loc_8217D384;
	// addi r4,r26,9089
	ctx.r4.s64 = ctx.r26.s64 + 9089;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D380;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D384;
	sub_8207B288(ctx, base);
loc_8217D384:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D38C;
	sub_82175D08(ctx, base);
	// stw r3,328(r22)
	PPC_STORE_U32(ctx.r22.u32 + 328, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175648
	ctx.lr = 0x8217D3A0;
	sub_82175648(ctx, base);
	// addi r4,r26,9097
	ctx.r4.s64 = ctx.r26.s64 + 9097;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D3B8;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d3d4
	if (!ctx.cr6.eq) goto loc_8217D3D4;
	// addi r4,r26,9097
	ctx.r4.s64 = ctx.r26.s64 + 9097;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D3D0;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D3D4;
	sub_8207B288(ctx, base);
loc_8217D3D4:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D3DC;
	sub_82175D08(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8217d4cc
	if (!ctx.cr6.eq) goto loc_8217D4CC;
	// addi r4,r26,9105
	ctx.r4.s64 = ctx.r26.s64 + 9105;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821753c8
	ctx.lr = 0x8217D3FC;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d418
	if (!ctx.cr6.eq) goto loc_8217D418;
	// addi r4,r26,9105
	ctx.r4.s64 = ctx.r26.s64 + 9105;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D414;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D418;
	sub_8207B288(ctx, base);
loc_8217D418:
	// addi r4,r26,9113
	ctx.r4.s64 = ctx.r26.s64 + 9113;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821753c8
	ctx.lr = 0x8217D430;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217d44c
	if (!ctx.cr6.eq) goto loc_8217D44C;
	// addi r4,r26,9113
	ctx.r4.s64 = ctx.r26.s64 + 9113;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D448;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D44C;
	sub_8207B288(ctx, base);
loc_8217D44C:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x821749c8
	ctx.lr = 0x8217D454;
	sub_821749C8(ctx, base);
	// lwz r28,88(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r31,24(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217D470;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217D4AC;
	sub_82174818(ctx, base);
	// lwz r6,28(r28)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// add r5,r3,r6
	ctx.r5.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lbz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8217d4cc
	if (ctx.cr6.eq) goto loc_8217D4CC;
	// addi r4,r26,2248
	ctx.r4.s64 = ctx.r26.s64 + 2248;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217D4CC;
	sub_82178AB0(ctx, base);
loc_8217D4CC:
	// lwz r11,296(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 296);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D4DC;
	sub_82174AF8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217d5ec
	if (ctx.cr6.eq) goto loc_8217D5EC;
	// addi r28,r22,292
	ctx.r28.s64 = ctx.r22.s64 + 292;
loc_8217D4E8:
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217D500;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217D53C;
	sub_82174818(ctx, base);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// addi r4,r26,9121
	ctx.r4.s64 = ctx.r26.s64 + 9121;
	// add r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D574;
	sub_821753C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217d590
	if (!ctx.cr6.eq) goto loc_8217D590;
	// addi r4,r26,9121
	ctx.r4.s64 = ctx.r26.s64 + 9121;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D58C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D590;
	sub_8207B288(ctx, base);
loc_8217D590:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D598;
	sub_82175D08(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,184(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x8217d5dc
	if (ctx.cr6.eq) goto loc_8217D5DC;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8217d5e4
	if (ctx.cr6.gt) goto loc_8217D5E4;
	// lwz r11,296(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 296);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D5D0;
	sub_82174AF8(ctx, base);
	// cmplw cr6,r27,r3
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8217d4e8
	if (ctx.cr6.lt) goto loc_8217D4E8;
	// b 0x8217d5ec
	goto loc_8217D5EC;
loc_8217D5DC:
	// stw r27,272(r22)
	PPC_STORE_U32(ctx.r22.u32 + 272, ctx.r27.u32);
	// b 0x8217d5ec
	goto loc_8217D5EC;
loc_8217D5E4:
	// addi r11,r27,-1
	ctx.r11.s64 = ctx.r27.s64 + -1;
	// stw r11,272(r22)
	PPC_STORE_U32(ctx.r22.u32 + 272, ctx.r11.u32);
loc_8217D5EC:
	// lwz r11,296(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 296);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217D5F8;
	sub_82174AF8(ctx, base);
	// lwz r10,272(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 272);
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// addi r27,r22,272
	ctx.r27.s64 = ctx.r22.s64 + 272;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x8217d618
	if (ctx.cr6.lt) goto loc_8217D618;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8217D618:
	// lwz r25,0(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r31,r22,292
	ctx.r31.s64 = ctx.r22.s64 + 292;
	// stw r25,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r25.u32);
	// lwz r11,296(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 296);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r28,r11,-11
	ctx.r28.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217D63C;
	sub_82174AF8(ctx, base);
	// add r10,r28,r30
	ctx.r10.u64 = ctx.r28.u64 + ctx.r30.u64;
	// lbzx r9,r28,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217D678;
	sub_82174818(ctx, base);
	// lwz r6,296(r22)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r22.u32 + 296);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r4,r26,9129
	ctx.r4.s64 = ctx.r26.s64 + 9129;
	// add r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r9,292(r22)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r22.u32 + 292);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D6B0;
	sub_821753C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217d6cc
	if (!ctx.cr6.eq) goto loc_8217D6CC;
	// addi r4,r26,9129
	ctx.r4.s64 = ctx.r26.s64 + 9129;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D6C8;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D6CC;
	sub_8207B288(ctx, base);
loc_8217D6CC:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r25,0(r27)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// std r11,284(r22)
	PPC_STORE_U64(ctx.r22.u32 + 284, ctx.r11.u64);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r28,r11,-11
	ctx.r28.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217D6F0;
	sub_82174AF8(ctx, base);
	// add r10,r28,r30
	ctx.r10.u64 = ctx.r28.u64 + ctx.r30.u64;
	// lbzx r9,r28,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217D72C;
	sub_82174818(ctx, base);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r26,9137
	ctx.r4.s64 = ctx.r26.s64 + 9137;
	// add r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D764;
	sub_821753C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217d780
	if (!ctx.cr6.eq) goto loc_8217D780;
	// addi r4,r26,9137
	ctx.r4.s64 = ctx.r26.s64 + 9137;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D77C;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D780;
	sub_8207B288(ctx, base);
loc_8217D780:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D788;
	sub_82175D08(ctx, base);
	// stw r3,276(r22)
	PPC_STORE_U32(ctx.r22.u32 + 276, ctx.r3.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lbz r11,1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// addi r27,r10,1
	ctx.r27.s64 = ctx.r10.s64 + 1;
	// addi r28,r11,-11
	ctx.r28.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217D7AC;
	sub_82174AF8(ctx, base);
	// add r10,r28,r30
	ctx.r10.u64 = ctx.r28.u64 + ctx.r30.u64;
	// lbzx r9,r28,r30
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r30.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// bl 0x82174818
	ctx.lr = 0x8217D7E8;
	sub_82174818(ctx, base);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r26,9145
	ctx.r4.s64 = ctx.r26.s64 + 9145;
	// add r11,r3,r6
	ctx.r11.u64 = ctx.r3.u64 + ctx.r6.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217D820;
	sub_821753C8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217d83c
	if (!ctx.cr6.eq) goto loc_8217D83C;
	// addi r4,r26,9145
	ctx.r4.s64 = ctx.r26.s64 + 9145;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217D838;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217D83C;
	sub_8207B288(ctx, base);
loc_8217D83C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82175d08
	ctx.lr = 0x8217D844;
	sub_82175D08(ctx, base);
	// stw r3,280(r22)
	PPC_STORE_U32(ctx.r22.u32 + 280, ctx.r3.u32);
	// lwz r10,252(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 252);
	// li r19,524
	ctx.r19.s64 = 524;
	// li r18,1
	ctx.r18.s64 = 1;
	// addi r20,r22,240
	ctx.r20.s64 = ctx.r22.s64 + 240;
	// mr r21,r18
	ctx.r21.u64 = ctx.r18.u64;
	// lwz r11,256(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 256);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r19
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r19.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8217dbfc
	if (!ctx.cr6.gt) goto loc_8217DBFC;
loc_8217D870:
	// lwz r10,12(r20)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r20.u32 + 12);
	// lwz r11,16(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r19
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r19.s32);
	// cmplw cr6,r21,r8
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217d88c
	if (ctx.cr6.lt) goto loc_8217D88C;
	// twi 31,r0,22
loc_8217D88C:
	// mulli r11,r21,524
	ctx.r11.s64 = ctx.r21.s64 * 524;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// add r25,r11,r10
	ctx.r25.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// ld r23,24(r25)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r25.u32 + 24);
	// std r23,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r23.u64);
	// lwz r28,92(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r31,r28,1
	ctx.r31.s64 = ctx.r28.s64 + 1;
	// lwz r27,88(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_8217D8B4:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r11,r11,-13
	ctx.r11.s64 = ctx.r11.s64 + -13;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x8217daa4
	if (ctx.cr6.gt) goto loc_8217DAA4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217d8e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217D8E0;
	// bdzf 4*cr6+eq,0x8217d8f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217D8F4;
	// bne cr6,0x8217d914
	if (!ctx.cr6.eq) goto loc_8217D914;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// b 0x8217d93c
	goto loc_8217D93C;
loc_8217D8E0:
	// lbz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 | ctx.r10.u64;
	// b 0x8217d93c
	goto loc_8217D93C;
loc_8217D8F4:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lbz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r6,r8
	ctx.r11.u64 = ctx.r6.u64 | ctx.r8.u64;
	// b 0x8217d93c
	goto loc_8217D93C;
loc_8217D914:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r10,3(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lbz r7,1(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 | ctx.r7.u64;
loc_8217D93C:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8217daa4
	if (!ctx.cr6.lt) goto loc_8217DAA4;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r9,r11,-13
	ctx.r9.s64 = ctx.r11.s64 + -13;
	// addi r10,r11,-11
	ctx.r10.s64 = ctx.r11.s64 + -11;
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bgt cr6,0x8217d9d4
	if (ctx.cr6.gt) goto loc_8217D9D4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217d974
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217D974;
	// bdzf 4*cr6+eq,0x8217d988
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217D988;
	// bne cr6,0x8217d9a8
	if (!ctx.cr6.eq) goto loc_8217D9A8;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// b 0x8217d9d8
	goto loc_8217D9D8;
loc_8217D974:
	// lbz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 | ctx.r9.u64;
	// b 0x8217d9d8
	goto loc_8217D9D8;
loc_8217D988:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lbz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r7,1(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r5,r7
	ctx.r11.u64 = ctx.r5.u64 | ctx.r7.u64;
	// b 0x8217d9d8
	goto loc_8217D9D8;
loc_8217D9A8:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r9,3(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r8,r11,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r7,2(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lbz r6,1(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r11,r3,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 | ctx.r6.u64;
	// b 0x8217d9d8
	goto loc_8217D9D8;
loc_8217D9D4:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8217D9D8:
	// add r9,r10,r31
	ctx.r9.u64 = ctx.r10.u64 + ctx.r31.u64;
	// lbzx r8,r10,r31
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r31.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// addi r9,r8,-12
	ctx.r9.s64 = ctx.r8.s64 + -12;
	// stw r7,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r7.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mullw r11,r9,r11
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r9,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// bl 0x82174818
	ctx.lr = 0x8217DA14;
	sub_82174818(ctx, base);
	// lwz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// add r11,r3,r28
	ctx.r11.u64 = ctx.r3.u64 + ctx.r28.u64;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r29.u32);
	// addi r4,r26,9153
	ctx.r4.s64 = ctx.r26.s64 + 9153;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// bl 0x821753c8
	ctx.lr = 0x8217DA40;
	sub_821753C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217da5c
	if (!ctx.cr6.eq) goto loc_8217DA5C;
	// addi r4,r26,9153
	ctx.r4.s64 = ctx.r26.s64 + 9153;
	// addi r3,r26,6509
	ctx.r3.s64 = ctx.r26.s64 + 6509;
	// bl 0x8207bc98
	ctx.lr = 0x8217DA58;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8217DA5C;
	sub_8207B288(ctx, base);
loc_8217DA5C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175d08
	ctx.lr = 0x8217DA64;
	sub_82175D08(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,184(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// beq cr6,0x8217da94
	if (ctx.cr6.eq) goto loc_8217DA94;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8217da9c
	if (ctx.cr6.gt) goto loc_8217DA9C;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// b 0x8217d8b4
	goto loc_8217D8B4;
loc_8217DA94:
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// b 0x8217daa0
	goto loc_8217DAA0;
loc_8217DA9C:
	// addi r24,r30,-1
	ctx.r24.s64 = ctx.r30.s64 + -1;
loc_8217DAA0:
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r24.u32);
loc_8217DAA4:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r11,r11,-13
	ctx.r11.s64 = ctx.r11.s64 + -13;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x8217db30
	if (ctx.cr6.gt) goto loc_8217DB30;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217dad0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217DAD0;
	// bdzf 4*cr6+eq,0x8217dae4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217DAE4;
	// bne cr6,0x8217db04
	if (!ctx.cr6.eq) goto loc_8217DB04;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// b 0x8217db34
	goto loc_8217DB34;
loc_8217DAD0:
	// lbz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// or r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 | ctx.r10.u64;
	// b 0x8217db34
	goto loc_8217DB34;
loc_8217DAE4:
	// lbz r11,3(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lbz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,1(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r6,r8
	ctx.r11.u64 = ctx.r6.u64 | ctx.r8.u64;
	// b 0x8217db34
	goto loc_8217DB34;
loc_8217DB04:
	// lbz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r10,3(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// rotlwi r9,r11,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lbz r7,1(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// or r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 | ctx.r7.u64;
	// b 0x8217db34
	goto loc_8217DB34;
loc_8217DB30:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8217DB34:
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// blt cr6,0x8217db4c
	if (ctx.cr6.lt) goto loc_8217DB4C;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8217DB4C:
	// lwz r31,0(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r30,r25,132
	ctx.r30.s64 = ctx.r25.s64 + 132;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// bl 0x82177590
	ctx.lr = 0x8217DB68;
	sub_82177590(ctx, base);
	// addi r6,r31,1
	ctx.r6.s64 = ctx.r31.s64 + 1;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r25,280
	ctx.r4.s64 = ctx.r25.s64 + 280;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82177590
	ctx.lr = 0x8217DB7C;
	sub_82177590(ctx, base);
	// lwz r11,8(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8);
	// stw r29,432(r25)
	PPC_STORE_U32(ctx.r25.u32 + 432, ctx.r29.u32);
	// stb r18,428(r25)
	PPC_STORE_U8(ctx.r25.u32 + 428, ctx.r18.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217dba0
	if (!ctx.cr6.eq) goto loc_8217DBA0;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r25,92
	ctx.r4.s64 = ctx.r25.s64 + 92;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82178980
	ctx.lr = 0x8217DBA0;
	sub_82178980(ctx, base);
loc_8217DBA0:
	// lwz r11,140(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + 140);
	// rlwinm r10,r11,0,13,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217dbe0
	if (ctx.cr6.eq) goto loc_8217DBE0;
	// lwz r31,272(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + 272);
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne cr6,0x8217dbc4
	if (!ctx.cr6.eq) goto loc_8217DBC4;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// b 0x8217dbd4
	goto loc_8217DBD4;
loc_8217DBC4:
	// mr r4,r21
	ctx.r4.u64 = ctx.r21.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8217b150
	ctx.lr = 0x8217DBD0;
	sub_8217B150(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8217DBD4:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82178ab0
	ctx.lr = 0x8217DBE0;
	sub_82178AB0(ctx, base);
loc_8217DBE0:
	// lwz r11,16(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 16);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// lwz r10,12(r20)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r20.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r19
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r19.s32);
	// cmplw cr6,r21,r8
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217d870
	if (ctx.cr6.lt) goto loc_8217D870;
loc_8217DBFC:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82179e70
	ctx.lr = 0x8217DC04;
	sub_82179E70(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x8207c9b0
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217DC0C"))) PPC_WEAK_FUNC(sub_8217DC0C);
PPC_FUNC_IMPL(__imp__sub_8217DC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217DC10"))) PPC_WEAK_FUNC(sub_8217DC10);
PPC_FUNC_IMPL(__imp__sub_8217DC10) {
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
	// lfs f0,188(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,148(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 148);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// stfs f13,192(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217dc44
	if (ctx.cr6.eq) goto loc_8217DC44;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8217c238
	ctx.lr = 0x8217DC44;
	sub_8217C238(ctx, base);
loc_8217DC44:
	// lbz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 176);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217deb8
	if (ctx.cr6.eq) goto loc_8217DEB8;
	// lbz r11,177(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 177);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217dca4
	if (!ctx.cr6.eq) goto loc_8217DCA4;
	// lwz r10,268(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,192(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,180
	ctx.r11.s64 = ctx.r31.s64 + 180;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,180(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 180, temp.u32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f0,f10
	ctx.f0.f64 = double(float(ctx.f10.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// blt cr6,0x8217dc9c
	if (ctx.cr6.lt) goto loc_8217DC9C;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
loc_8217DC9C:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 184, temp.u32);
loc_8217DCA4:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,192(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f12,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// lfs f0,180(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// blt cr6,0x8217dd94
	if (ctx.cr6.lt) goto loc_8217DD94;
	// lwz r11,268(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8217dd4c
	if (ctx.cr6.lt) goto loc_8217DD4C;
	// lwz r11,264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 264);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8217dcf8
	if (!ctx.cr6.lt) goto loc_8217DCF8;
	// stfs f13,184(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 184, temp.u32);
	// stb r10,176(r31)
	PPC_STORE_U8(ctx.r31.u32 + 176, ctx.r10.u8);
	// b 0x8217dd4c
	goto loc_8217DD4C;
loc_8217DCF8:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
loc_8217DD0C:
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fadds f0,f11,f12
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f0,180(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 180, temp.u32);
	// lwz r11,268(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// fcmpu cr6,f0,f7
	ctx.cr6.compare(ctx.f0.f64, ctx.f7.f64);
	// bge cr6,0x8217dd0c
	if (!ctx.cr6.lt) goto loc_8217DD0C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f0,184(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 184, temp.u32);
	// stb r11,179(r31)
	PPC_STORE_U8(ctx.r31.u32 + 179, ctx.r11.u8);
loc_8217DD4C:
	// lbz r11,179(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 179);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217dd78
	if (ctx.cr6.eq) goto loc_8217DD78;
	// stb r10,179(r31)
	PPC_STORE_U8(ctx.r31.u32 + 179, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217d1d8
	ctx.lr = 0x8217DD64;
	sub_8217D1D8(ctx, base);
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
loc_8217DD78:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217cca8
	ctx.lr = 0x8217DD80;
	sub_8217CCA8(ctx, base);
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
loc_8217DD94:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// blt cr6,0x8217ddc0
	if (ctx.cr6.lt) goto loc_8217DDC0;
	// lwz r11,264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,180(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x8217de58
	if (!ctx.cr6.lt) goto loc_8217DE58;
loc_8217DDC0:
	// lwz r11,264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 264);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8217dddc
	if (!ctx.cr6.lt) goto loc_8217DDDC;
	// stfs f12,184(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 184, temp.u32);
	// stb r10,176(r31)
	PPC_STORE_U8(ctx.r31.u32 + 176, ctx.r10.u8);
	// stfs f12,180(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 180, temp.u32);
	// b 0x8217de58
	goto loc_8217DE58;
loc_8217DDDC:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8217de48
	if (!ctx.cr6.lt) goto loc_8217DE48;
	// lwz r11,268(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// frsp f0,f11
	ctx.f0.f64 = double(float(ctx.f11.f64));
loc_8217DE14:
	// lfs f11,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f0.f64));
	// stfs f9,180(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 180, temp.u32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// lwz r11,264(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 264);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fcmpu cr6,f9,f5
	ctx.cr6.compare(ctx.f9.f64, ctx.f5.f64);
	// blt cr6,0x8217de14
	if (ctx.cr6.lt) goto loc_8217DE14;
loc_8217DE48:
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,184(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 184, temp.u32);
	// stb r11,179(r31)
	PPC_STORE_U8(ctx.r31.u32 + 179, ctx.r11.u8);
loc_8217DE58:
	// lbz r11,179(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 179);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217deb0
	if (ctx.cr6.eq) goto loc_8217DEB0;
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,179(r31)
	PPC_STORE_U8(ctx.r31.u32 + 179, ctx.r10.u8);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bne cr6,0x8217de94
	if (!ctx.cr6.eq) goto loc_8217DE94;
	// lwz r11,268(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
	// extsw r10,r11
	ctx.r10.s64 = ctx.r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,184(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 184, temp.u32);
	// stfs f12,180(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 180, temp.u32);
loc_8217DE94:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217d1d8
	ctx.lr = 0x8217DE9C;
	sub_8217D1D8(ctx, base);
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
loc_8217DEB0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217c7c8
	ctx.lr = 0x8217DEB8;
	sub_8217C7C8(ctx, base);
loc_8217DEB8:
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

__attribute__((alias("__imp__sub_8217DECC"))) PPC_WEAK_FUNC(sub_8217DECC);
PPC_FUNC_IMPL(__imp__sub_8217DECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217DED0"))) PPC_WEAK_FUNC(sub_8217DED0);
PPC_FUNC_IMPL(__imp__sub_8217DED0) {
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
	// lwz r11,-31328(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31328);
	// lbz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217df08
	if (ctx.cr6.eq) goto loc_8217DF08;
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217dc10
	ctx.lr = 0x8217DEF8;
	sub_8217DC10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8217DF08:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// bl 0x8217dc10
	ctx.lr = 0x8217DF20;
	sub_8217DC10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217DF30"))) PPC_WEAK_FUNC(sub_8217DF30);
PPC_FUNC_IMPL(__imp__sub_8217DF30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c950
	ctx.lr = 0x8217DF38;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080348
	ctx.lr = 0x8217DF40;
	__savefpr_20(ctx, base);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,480(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 480);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r10,476(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 476);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r16,r3,464
	ctx.r16.s64 = ctx.r3.s64 + 464;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r17,r22
	ctx.r17.u64 = ctx.r22.u64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8217e98c
	if (ctx.cr0.eq) goto loc_8217E98C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r19,r11,-21836
	ctx.r19.s64 = ctx.r11.s64 + -21836;
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f22,-21836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f22.f64 = double(temp.f32);
	// addi r15,r3,240
	ctx.r15.s64 = ctx.r3.s64 + 240;
	// li r25,524
	ctx.r25.s64 = 524;
	// lfs f26,2224(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 2224);
	ctx.f26.f64 = double(temp.f32);
	// li r20,1
	ctx.r20.s64 = 1;
	// lfs f23,3952(r19)
	temp.u32 = PPC_LOAD_U32(ctx.r19.u32 + 3952);
	ctx.f23.f64 = double(temp.f32);
	// li r18,15
	ctx.r18.s64 = 15;
	// lfs f27,21768(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f27.f64 = double(temp.f32);
	// lis r21,-32224
	ctx.r21.s64 = -2111832064;
	// lfs f24,432(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 432);
	ctx.f24.f64 = double(temp.f32);
	// lfs f21,392(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 392);
	ctx.f21.f64 = double(temp.f32);
	// lfs f20,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f20.f64 = double(temp.f32);
	// lfs f25,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f25.f64 = double(temp.f32);
loc_8217DFB0:
	// lwz r10,12(r16)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r16.u32 + 12);
	// lwz r11,16(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r17,r8
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217dfcc
	if (ctx.cr6.lt) goto loc_8217DFCC;
	// twi 31,r0,22
loc_8217DFCC:
	// lwz r11,12(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 12);
	// rlwinm r9,r17,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,16(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 16);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// divw r6,r7,r25
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r25.s32);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217dff0
	if (ctx.cr6.lt) goto loc_8217DFF0;
	// twi 31,r0,22
loc_8217DFF0:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,432(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 432);
	// lbz r9,436(r27)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + 436);
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// mulli r10,r10,148
	ctx.r10.s64 = ctx.r10.s64 * 148;
	// add r23,r10,r27
	ctx.r23.u64 = ctx.r10.u64 + ctx.r27.u64;
	// addi r26,r11,48
	ctx.r26.s64 = ctx.r11.s64 + 48;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217e7ac
	if (ctx.cr6.eq) goto loc_8217E7AC;
	// lbz r10,437(r27)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r27.u32 + 437);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217e7ac
	if (ctx.cr6.eq) goto loc_8217E7AC;
	// lbz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// bne cr6,0x8217e07c
	if (!ctx.cr6.eq) goto loc_8217E07C;
	// stb r20,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r20.u8);
	// lwz r10,520(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f2,32(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206c658
	ctx.lr = 0x8217E048;
	sub_8206C658(ctx, base);
	// lwz r9,520(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f0,72(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f27,84(r1)
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// bgt cr6,0x8217e06c
	if (ctx.cr6.gt) goto loc_8217E06C;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
loc_8217E06C:
	// lwz r10,520(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 72, temp.u32);
	// b 0x8217e7b0
	goto loc_8217E7B0;
loc_8217E07C:
	// lfs f13,72(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,192(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f12,72(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 72, temp.u32);
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f11,72(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f27
	ctx.cr6.compare(ctx.f11.f64, ctx.f27.f64);
	// bgt cr6,0x8217e7b0
	if (ctx.cr6.gt) goto loc_8217E7B0;
loc_8217E09C:
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f2,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206c658
	ctx.lr = 0x8217E0AC;
	sub_8206C658(ctx, base);
	// lwz r10,520(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lfs f0,72(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f13,72(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 72, temp.u32);
	// lwz r8,520(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lwz r11,24(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x82174af8
	ctx.lr = 0x8217E0D0;
	sub_82174AF8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217e790
	if (ctx.cr6.eq) goto loc_8217E790;
	// lwz r3,-31016(r21)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r21.u32 + -31016);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8217e108
	if (!ctx.cr6.eq) goto loc_8217E108;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82079fd8
	ctx.lr = 0x8217E0F0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217e100
	if (ctx.cr6.eq) goto loc_8217E100;
	// bl 0x82167b28
	ctx.lr = 0x8217E0FC;
	sub_82167B28(ctx, base);
	// b 0x8217e104
	goto loc_8217E104;
loc_8217E100:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_8217E104:
	// stw r3,-31016(r21)
	PPC_STORE_U32(ctx.r21.u32 + -31016, ctx.r3.u32);
loc_8217E108:
	// bl 0x82167910
	ctx.lr = 0x8217E10C;
	sub_82167910(ctx, base);
	// clrlwi r10,r3,1
	ctx.r10.u64 = ctx.r3.u32 & 0x7FFFFFFF;
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// divwu r9,r10,r31
	ctx.r9.u32 = ppc_divwu(ctx.r10.u32, ctx.r31.u32);
	// addi r4,r11,20
	ctx.r4.s64 = ctx.r11.s64 + 20;
	// mullw r8,r9,r31
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r31.s32);
	// subf r5,r8,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r8.s64;
	// bl 0x82175648
	ctx.lr = 0x8217E12C;
	sub_82175648(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x82175648
	ctx.lr = 0x8217E13C;
	sub_82175648(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217E148;
	sub_821749C8(ctx, base);
	// lwz r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,24(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217E164;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// bl 0x82174818
	ctx.lr = 0x8217E1A0;
	sub_82174818(ctx, base);
	// lwz r4,28(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// li r5,1
	ctx.r5.s64 = 1;
	// add r29,r3,r4
	ctx.r29.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82175648
	ctx.lr = 0x8217E1B8;
	sub_82175648(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821749c8
	ctx.lr = 0x8217E1C4;
	sub_821749C8(ctx, base);
	// lwz r28,0(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r14,r3
	ctx.r14.u64 = ctx.r3.u64;
	// lwz r31,24(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// addi r30,r11,-11
	ctx.r30.s64 = ctx.r11.s64 + -11;
	// bl 0x82174af8
	ctx.lr = 0x8217E1E0;
	sub_82174AF8(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// lbzx r9,r30,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + ctx.r31.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r11.u32);
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// bl 0x82174818
	ctx.lr = 0x8217E21C;
	sub_82174818(ctx, base);
	// lwz r10,28(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// add r30,r3,r10
	ctx.r30.u64 = ctx.r3.u64 + ctx.r10.u64;
	// li r3,540
	ctx.r3.s64 = 540;
	// bl 0x82079fd8
	ctx.lr = 0x8217E22C;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217e25c
	if (ctx.cr6.eq) goto loc_8217E25C;
	// addi r4,r19,-3157
	ctx.r4.s64 = ctx.r19.s64 + -3157;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82060190
	ctx.lr = 0x8217E244;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,4(r24)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x8217a2f8
	ctx.lr = 0x8217E254;
	sub_8217A2F8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x8217e260
	goto loc_8217E260;
loc_8217E25C:
	// mr r28,r22
	ctx.r28.u64 = ctx.r22.u64;
loc_8217E260:
	// lfs f0,308(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stfs f0,308(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 308, temp.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8217E274;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217e288
	if (ctx.cr6.eq) goto loc_8217E288;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x8217e28c
	goto loc_8217E28C;
loc_8217E288:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
loc_8217E28C:
	// stw r3,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// stw r22,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r22.u32);
	// stw r22,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r22.u32);
	// stw r22,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r22.u32);
	// bl 0x8207a630
	ctx.lr = 0x8217E2A0;
	sub_8207A630(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,232(r24)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r24.u32 + 232);
	// lwz r4,228(r24)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + 228);
	// bl 0x82179788
	ctx.lr = 0x8217E2B0;
	sub_82179788(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,236(r24)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r24.u32 + 236);
	// bl 0x821796b0
	ctx.lr = 0x8217E2BC;
	sub_821796B0(ctx, base);
	// lwz r10,140(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 140);
	// stw r18,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r18.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r22,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r22.u32);
	// stb r22,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, ctx.r22.u8);
	// stw r10,140(r28)
	PPC_STORE_U32(ctx.r28.u32 + 140, ctx.r10.u32);
	// lwz r9,144(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 144);
	// stw r9,144(r28)
	PPC_STORE_U32(ctx.r28.u32 + 144, ctx.r9.u32);
loc_8217E2DC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217e2dc
	if (!ctx.cr6.eq) goto loc_8217E2DC;
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x8217E304;
	sub_82060368(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82178378
	ctx.lr = 0x8217E310;
	sub_82178378(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8217c468
	ctx.lr = 0x8217E320;
	sub_8217C468(ctx, base);
	// lwz r11,252(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 252);
	// lwz r10,256(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 256);
	// addi r31,r28,240
	ctx.r31.s64 = ctx.r28.s64 + 240;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e33c
	if (!ctx.cr0.eq) goto loc_8217E33C;
	// twi 31,r0,22
loc_8217E33C:
	// stb r20,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r20.u8);
	// lwz r10,472(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 472);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r25
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217e35c
	if (!ctx.cr0.eq) goto loc_8217E35C;
	// twi 31,r0,22
loc_8217E35C:
	// stw r10,512(r11)
	PPC_STORE_U32(ctx.r11.u32 + 512, ctx.r10.u32);
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8217e3ec
	if (ctx.cr6.lt) goto loc_8217E3EC;
	// beq cr6,0x8217e3a4
	if (ctx.cr6.eq) goto loc_8217E3A4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x8217e3f4
	if (!ctx.cr6.lt) goto loc_8217E3F4;
	// fmr f2,f26
	ctx.f2.f64 = ctx.f26.f64;
	// fmr f1,f21
	ctx.f1.f64 = ctx.f21.f64;
	// bl 0x8206c658
	ctx.lr = 0x8217E390;
	sub_8206C658(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f2,f26
	ctx.f2.f64 = ctx.f26.f64;
	// fmr f1,f21
	ctx.f1.f64 = ctx.f21.f64;
	// bl 0x8206c658
	ctx.lr = 0x8217E3A0;
	sub_8206C658(ctx, base);
	// b 0x8217e3f4
	goto loc_8217E3F4;
loc_8217E3A4:
	// fmr f2,f23
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f23.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x8206c658
	ctx.lr = 0x8217E3B0;
	sub_8206C658(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f2,f22
	ctx.f2.f64 = ctx.f22.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x8206c658
	ctx.lr = 0x8217E3C0;
	sub_8206C658(ctx, base);
	// fsqrts f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(sqrt(ctx.f1.f64)));
	// fmuls f30,f0,f26
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f26.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207ae60
	ctx.lr = 0x8217E3D0;
	sub_8207AE60(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207af40
	ctx.lr = 0x8217E3DC;
	sub_8207AF40(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f29,f30
	ctx.f1.f64 = double(float(ctx.f29.f64 * ctx.f30.f64));
	// fmuls f31,f13,f30
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// b 0x8217e3f4
	goto loc_8217E3F4;
loc_8217E3EC:
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
loc_8217E3F4:
	// fadds f0,f31,f26
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f26.f64));
	// lfs f13,160(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f1,f26
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f26.f64));
	// lfs f11,164(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 164);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,64(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f9,72(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// addi r30,r27,64
	ctx.r30.s64 = ctx.r27.s64 + 64;
	// lfs f8,68(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 68);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,76(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 76);
	ctx.f7.f64 = double(temp.f32);
	// lfs f2,40(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,36(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f6,f0,f13
	ctx.f6.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// fsubs f5,f12,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmuls f4,f10,f6
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f6.f64));
	// fmuls f3,f9,f6
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f6.f64));
	// fmadds f31,f8,f5,f4
	ctx.f31.f64 = double(float(ctx.f8.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fmadds f30,f7,f5,f3
	ctx.f30.f64 = double(float(ctx.f7.f64 * ctx.f5.f64 + ctx.f3.f64));
	// bl 0x8206c658
	ctx.lr = 0x8217E440;
	sub_8206C658(ctx, base);
	// lwz r10,520(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// lbz r9,18(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 18);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217e460
	if (ctx.cr6.eq) goto loc_8217E460;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// b 0x8217e468
	goto loc_8217E468;
loc_8217E460:
	// lfs f2,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,72(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
loc_8217E468:
	// bl 0x8207b440
	ctx.lr = 0x8217E46C;
	sub_8207B440(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// fmuls f29,f0,f24
	ctx.f29.f64 = double(float(ctx.f0.f64 * ctx.f24.f64));
	// lfs f0,44(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// bl 0x8206c658
	ctx.lr = 0x8217E488;
	sub_8206C658(ctx, base);
	// fadds f13,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f29.f64));
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// fmuls f29,f13,f20
	ctx.f29.f64 = double(float(ctx.f13.f64 * ctx.f20.f64));
	// blt cr6,0x8217e538
	if (ctx.cr6.lt) goto loc_8217E538;
	// bne cr6,0x8217e5cc
	if (!ctx.cr6.eq) goto loc_8217E5CC;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lfs f0,448(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lfs f13,440(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,444(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e4cc
	if (!ctx.cr0.eq) goto loc_8217E4CC;
	// twi 31,r0,22
loc_8217E4CC:
	// stfs f13,480(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 480, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e4e8
	if (!ctx.cr0.eq) goto loc_8217E4E8;
	// twi 31,r0,22
loc_8217E4E8:
	// stfs f12,484(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 484, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e504
	if (!ctx.cr0.eq) goto loc_8217E504;
	// twi 31,r0,22
loc_8217E504:
	// stfs f0,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 488, temp.u32);
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8207af40
	ctx.lr = 0x8217E514;
	sub_8207AF40(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// stfs f13,196(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r28.u32 + 196, temp.u32);
	// bl 0x8207ae60
	ctx.lr = 0x8217E528;
	sub_8207AE60(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fmuls f11,f12,f28
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f28.f64));
	// stfs f11,204(r28)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r28.u32 + 204, temp.u32);
	// b 0x8217e5cc
	goto loc_8217E5CC;
loc_8217E538:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lfs f13,444(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 444);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lfs f11,440(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 440);
	ctx.f11.f64 = double(temp.f32);
	// fadds f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// lfs f0,448(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// fadds f13,f11,f31
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f31.f64));
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e564
	if (!ctx.cr0.eq) goto loc_8217E564;
	// twi 31,r0,22
loc_8217E564:
	// stfs f13,480(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 480, temp.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e580
	if (!ctx.cr0.eq) goto loc_8217E580;
	// twi 31,r0,22
loc_8217E580:
	// stfs f12,484(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 484, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e59c
	if (!ctx.cr0.eq) goto loc_8217E59C;
	// twi 31,r0,22
loc_8217E59C:
	// stfs f0,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 488, temp.u32);
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8207af40
	ctx.lr = 0x8217E5AC;
	sub_8207AF40(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f28.f64));
	// stfs f13,196(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r28.u32 + 196, temp.u32);
	// bl 0x8207ae60
	ctx.lr = 0x8217E5C0;
	sub_8207AE60(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fmuls f11,f12,f28
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f28.f64));
	// stfs f11,200(r28)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r28.u32 + 200, temp.u32);
loc_8217E5CC:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lbz r9,439(r27)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r27.u32 + 439);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// lbz r10,438(r27)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r27.u32 + 438);
	// divw. r7,r8,r25
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217e5ec
	if (!ctx.cr0.eq) goto loc_8217E5EC;
	// twi 31,r0,22
loc_8217E5EC:
	// stb r10,478(r11)
	PPC_STORE_U8(ctx.r11.u32 + 478, ctx.r10.u8);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r7,r8,r25
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217e608
	if (!ctx.cr0.eq) goto loc_8217E608;
	// twi 31,r0,22
loc_8217E608:
	// stb r9,479(r11)
	PPC_STORE_U8(ctx.r11.u32 + 479, ctx.r9.u8);
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217e690
	if (ctx.cr6.eq) goto loc_8217E690;
	// lbz r11,18(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 18);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217e658
	if (ctx.cr6.eq) goto loc_8217E658;
	// fmuls f1,f29,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f29.f64 * ctx.f24.f64));
	// fcmpu cr6,f1,f27
	ctx.cr6.compare(ctx.f1.f64, ctx.f27.f64);
	// bge cr6,0x8217e640
	if (!ctx.cr6.lt) goto loc_8217E640;
loc_8217E634:
	// fadds f1,f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f25.f64));
	// fcmpu cr6,f1,f27
	ctx.cr6.compare(ctx.f1.f64, ctx.f27.f64);
	// blt cr6,0x8217e634
	if (ctx.cr6.lt) goto loc_8217E634;
loc_8217E640:
	// fcmpu cr6,f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f25.f64);
	// blt cr6,0x8217e65c
	if (ctx.cr6.lt) goto loc_8217E65C;
loc_8217E648:
	// fsubs f1,f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f25.f64));
	// fcmpu cr6,f1,f25
	ctx.cr6.compare(ctx.f1.f64, ctx.f25.f64);
	// bge cr6,0x8217e648
	if (!ctx.cr6.lt) goto loc_8217E648;
	// b 0x8217e65c
	goto loc_8217E65C;
loc_8217E658:
	// lfs f1,452(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 452);
	ctx.f1.f64 = double(temp.f32);
loc_8217E65C:
	// lbz r11,148(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217e674
	if (ctx.cr6.eq) goto loc_8217E674;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8217c6d8
	ctx.lr = 0x8217E670;
	sub_8217C6D8(ctx, base);
	// b 0x8217e690
	goto loc_8217E690;
loc_8217E674:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e68c
	if (!ctx.cr0.eq) goto loc_8217E68C;
	// twi 31,r0,22
loc_8217E68C:
	// stfs f1,492(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r11.u32 + 492, temp.u32);
loc_8217E690:
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lbz r10,17(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 17);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217e6d8
	if (ctx.cr6.eq) goto loc_8217E6D8;
	// lfs f0,192(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 192);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// beq cr6,0x8217e6d8
	if (ctx.cr6.eq) goto loc_8217E6D8;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r11,r28,192
	ctx.r11.s64 = ctx.r28.s64 + 192;
	// addi r10,r27,76
	ctx.r10.s64 = ctx.r27.s64 + 76;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8217E6BC:
	// lfsu f0,4(r10)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r10.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// lfs f13,192(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// stfsu f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8217e6bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217E6BC;
loc_8217E6D8:
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,208(r28)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r28.u32 + 208, temp.u32);
	// bl 0x8206e258
	ctx.lr = 0x8217E6F0;
	sub_8206E258(ctx, base);
	// lwz r11,16(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// lwz r10,12(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r7,520(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// ble cr6,0x8217e790
	if (!ctx.cr6.gt) goto loc_8217E790;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8217e71c
	if (!ctx.cr6.gt) goto loc_8217E71C;
	// twi 31,r0,22
loc_8217E71C:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217e7a4
	if (!ctx.cr6.eq) goto loc_8217E7A4;
	// twi 31,r0,22
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_8217E730:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8217e740
	if (ctx.cr6.lt) goto loc_8217E740;
	// twi 31,r0,22
loc_8217E740:
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217e760
	if (ctx.cr6.eq) goto loc_8217E760;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217E760;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8217E760:
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217e774
	if (!ctx.cr6.gt) goto loc_8217E774;
	// twi 31,r0,22
loc_8217E774:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82076a10
	ctx.lr = 0x8217E790;
	sub_82076A10(ctx, base);
loc_8217E790:
	// lwz r11,520(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// lfs f0,72(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// ble cr6,0x8217e09c
	if (!ctx.cr6.gt) goto loc_8217E09C;
	// b 0x8217e7b0
	goto loc_8217E7B0;
loc_8217E7A4:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217e730
	goto loc_8217E730;
loc_8217E7AC:
	// stb r22,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r22.u8);
loc_8217E7B0:
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8217e8d8
	if (ctx.cr0.eq) goto loc_8217E8D8;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
loc_8217E7CC:
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217e7e4
	if (ctx.cr6.lt) goto loc_8217E7E4;
	// twi 31,r0,22
loc_8217E7E4:
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// lbz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8217e8b8
	if (!ctx.cr6.eq) goto loc_8217E8B8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8217E808;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,12(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r8,16(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x8217e81c
	if (!ctx.cr6.gt) goto loc_8217E81C;
	// twi 31,r0,22
loc_8217E81C:
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8217e850
	if (!ctx.cr6.eq) goto loc_8217E850;
	// twi 31,r0,22
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_8217E830:
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// add r31,r30,r10
	ctx.r31.u64 = ctx.r30.u64 + ctx.r10.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8217e868
	if (ctx.cr6.gt) goto loc_8217E868;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217e858
	if (ctx.cr6.eq) goto loc_8217E858;
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8217e85c
	goto loc_8217E85C;
loc_8217E850:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8217e830
	goto loc_8217E830;
loc_8217E858:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_8217E85C:
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8217e86c
	if (!ctx.cr6.lt) goto loc_8217E86C;
loc_8217E868:
	// twi 31,r0,22
loc_8217E86C:
	// addi r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 4;
	// subf r11,r5,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8217e88c
	if (!ctx.cr0.gt) goto loc_8217E88C;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x8207a520
	ctx.lr = 0x8217E88C;
	sub_8207A520(ctx, base);
loc_8217E88C:
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// stw r10,16(r26)
	PPC_STORE_U32(ctx.r26.u32 + 16, ctx.r10.u32);
	// bgt cr6,0x8217e8ac
	if (ctx.cr6.gt) goto loc_8217E8AC;
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217e8b0
	if (!ctx.cr6.gt) goto loc_8217E8B0;
loc_8217E8AC:
	// twi 31,r0,22
loc_8217E8B0:
	// addi r29,r29,-1
	ctx.r29.s64 = ctx.r29.s64 + -1;
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
loc_8217E8B8:
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lwz r9,12(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r29,r7
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x8217e7cc
	if (ctx.cr6.lt) goto loc_8217E7CC;
loc_8217E8D8:
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8217e970
	if (ctx.cr0.eq) goto loc_8217E970;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
loc_8217E8F0:
	// lwz r11,12(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r10,16(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r30,r8
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217e90c
	if (ctx.cr6.lt) goto loc_8217E90C;
	// twi 31,r0,22
loc_8217E90C:
	// lwzx r31,r29,r11
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 256);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217e928
	if (!ctx.cr0.eq) goto loc_8217E928;
	// twi 31,r0,22
loc_8217E928:
	// lwz r10,516(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 516);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,516(r11)
	PPC_STORE_U32(ctx.r11.u32 + 516, ctx.r10.u32);
	// lfs f1,192(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217dc10
	ctx.lr = 0x8217E93C;
	sub_8217DC10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217f318
	ctx.lr = 0x8217E944;
	sub_8217F318(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x821795c8
	ctx.lr = 0x8217E950;
	sub_821795C8(ctx, base);
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// lwz r8,12(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 12);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi r6,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// cmplw cr6,r30,r6
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217e8f0
	if (ctx.cr6.lt) goto loc_8217E8F0;
loc_8217E970:
	// lwz r11,16(r16)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r16.u32 + 16);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r10,12(r16)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r16.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r17,r8
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217dfb0
	if (ctx.cr6.lt) goto loc_8217DFB0;
loc_8217E98C:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x82080394
	ctx.lr = 0x8217E998;
	__restfpr_20(ctx, base);
	// b 0x8207c9a0
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217E99C"))) PPC_WEAK_FUNC(sub_8217E99C);
PPC_FUNC_IMPL(__imp__sub_8217E99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217E9A0"))) PPC_WEAK_FUNC(sub_8217E9A0);
PPC_FUNC_IMPL(__imp__sub_8217E9A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c964
	ctx.lr = 0x8217E9A8;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x82080354
	ctx.lr = 0x8217E9B0;
	__savefpr_23(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,456(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 456);
	// li r19,0
	ctx.r19.s64 = 0;
	// lwz r10,452(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 452);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addi r22,r3,440
	ctx.r22.s64 = ctx.r3.s64 + 440;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r23,r19
	ctx.r23.u64 = ctx.r19.u64;
	// srawi. r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8217f308
	if (ctx.cr0.eq) goto loc_8217F308;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r21,r3,240
	ctx.r21.s64 = ctx.r3.s64 + 240;
	// li r25,524
	ctx.r25.s64 = 524;
	// lfs f28,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f28.f64 = double(temp.f32);
	// li r20,1
	ctx.r20.s64 = 1;
	// lfs f24,440(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 440);
	ctx.f24.f64 = double(temp.f32);
	// lfs f25,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f25.f64 = double(temp.f32);
	// lfs f23,436(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 436);
	ctx.f23.f64 = double(temp.f32);
	// lfs f26,432(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 432);
	ctx.f26.f64 = double(temp.f32);
	// lfs f29,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
loc_8217EA0C:
	// lwz r11,12(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// lwz r10,16(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r23,r8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217ea28
	if (ctx.cr6.lt) goto loc_8217EA28;
	// twi 31,r0,22
loc_8217EA28:
	// lwz r10,12(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 12);
	// rlwinm r9,r23,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,16(r21)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r21.u32 + 16);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// lwzx r11,r9,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// divw r6,r7,r25
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r25.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217ea4c
	if (ctx.cr6.lt) goto loc_8217EA4C;
	// twi 31,r0,22
loc_8217EA4C:
	// mulli r11,r11,524
	ctx.r11.s64 = ctx.r11.s64 * 524;
	// add r27,r11,r10
	ctx.r27.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r28,r27,436
	ctx.r28.s64 = ctx.r27.s64 + 436;
	// lwz r11,432(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 432);
	// lwz r9,520(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 520);
	// mulli r10,r11,148
	ctx.r10.s64 = ctx.r11.s64 * 148;
	// lwz r26,0(r9)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// add r10,r10,r27
	ctx.r10.u64 = ctx.r10.u64 + ctx.r27.u64;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// addi r31,r10,132
	ctx.r31.s64 = ctx.r10.s64 + 132;
	// mulli r11,r7,148
	ctx.r11.s64 = ctx.r7.s64 * 148;
	// lbz r6,144(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 144);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// addi r30,r11,132
	ctx.r30.s64 = ctx.r11.s64 + 132;
	// bne cr6,0x8217f120
	if (!ctx.cr6.eq) goto loc_8217F120;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f120
	if (ctx.cr6.eq) goto loc_8217F120;
	// lbz r11,428(r27)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r27.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217eb98
	if (ctx.cr6.eq) goto loc_8217EB98;
	// lwz r11,140(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 140);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r11,140(r26)
	PPC_STORE_U32(ctx.r26.u32 + 140, ctx.r11.u32);
	// lwz r10,144(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 144);
	// stw r10,144(r26)
	PPC_STORE_U32(ctx.r26.u32 + 144, ctx.r10.u32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82060190
	ctx.lr = 0x8217EAC8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82178378
	ctx.lr = 0x8217EAD4;
	sub_82178378(ctx, base);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x8217c468
	ctx.lr = 0x8217EAE8;
	sub_8217C468(ctx, base);
	// lbz r8,179(r26)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r26.u32 + 179);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8217eb98
	if (ctx.cr6.eq) goto loc_8217EB98;
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lfs f0,180(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,192(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 192);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f28
	ctx.cr6.compare(ctx.f11.f64, ctx.f28.f64);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// std r9,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r9.u64);
	// lfd f10,160(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fadds f1,f12,f8
	ctx.f1.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// bge cr6,0x8217eb90
	if (!ctx.cr6.lt) goto loc_8217EB90;
	// lwz r11,264(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 264);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8217eb90
	if (ctx.cr6.lt) goto loc_8217EB90;
	// lwz r10,268(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 268);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r9.u64);
	// lfd f0,168(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f1,f12
	ctx.cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// blt cr6,0x8217eb90
	if (ctx.cr6.lt) goto loc_8217EB90;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r9,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// std r8,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r8.u64);
	// lfd f0,144(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// lfd f11,152(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// frsp f13,f10
	ctx.f13.f64 = double(float(ctx.f10.f64));
loc_8217EB80:
	// fsubs f11,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fadds f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// fcmpu cr6,f1,f13
	ctx.cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x8217eb80
	if (!ctx.cr6.lt) goto loc_8217EB80;
loc_8217EB90:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82176770
	ctx.lr = 0x8217EB98;
	sub_82176770(ctx, base);
loc_8217EB98:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// fmr f27,f28
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f28.f64;
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217ef00
	if (ctx.cr6.eq) goto loc_8217EF00;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lbz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 12);
	// lfs f31,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217ec18
	if (ctx.cr6.eq) goto loc_8217EC18;
	// lbz r11,13(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 13);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217ec18
	if (ctx.cr6.eq) goto loc_8217EC18;
	// lbz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ec18
	if (!ctx.cr6.eq) goto loc_8217EC18;
	// lwz r11,144(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217ec18
	if (ctx.cr6.eq) goto loc_8217EC18;
	// lfs f0,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r31,108
	ctx.r6.s64 = ctx.r31.s64 + 108;
	// lfs f13,184(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f12,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lfs f2,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fdivs f3,f11,f10
	ctx.f3.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// bl 0x8206cea0
	ctx.lr = 0x8217EC14;
	sub_8206CEA0(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_8217EC18:
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bgt cr6,0x8217ef00
	if (ctx.cr6.gt) goto loc_8217EF00;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8217ec4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217EC4C;
	// bdzf 4*cr6+eq,0x8217ece8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8217ECE8;
	// bne cr6,0x8217ee38
	if (!ctx.cr6.eq) goto loc_8217EE38;
	// lfs f0,16(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fadds f27,f0,f31
	ctx.f27.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// b 0x8217eefc
	goto loc_8217EEFC;
loc_8217EC4C:
	// lbz r11,178(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 178);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ece8
	if (!ctx.cr6.eq) goto loc_8217ECE8;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8217eca8
	if (ctx.cr6.lt) goto loc_8217ECA8;
	// bne cr6,0x8217eefc
	if (!ctx.cr6.eq) goto loc_8217EEFC;
	// lfs f2,80(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,88(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8207b440
	ctx.lr = 0x8217EC74;
	sub_8207B440(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmadds f0,f0,f26,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f26.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8217ec90
	if (!ctx.cr6.lt) goto loc_8217EC90;
loc_8217EC84:
	// fadds f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// blt cr6,0x8217ec84
	if (ctx.cr6.lt) goto loc_8217EC84;
loc_8217EC90:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// blt cr6,0x8217eef8
	if (ctx.cr6.lt) goto loc_8217EEF8;
loc_8217EC98:
	// fsubs f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8217ec98
	if (!ctx.cr6.lt) goto loc_8217EC98;
	// b 0x8217eef8
	goto loc_8217EEF8;
loc_8217ECA8:
	// lfs f2,80(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,84(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8207b440
	ctx.lr = 0x8217ECB4;
	sub_8207B440(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmadds f0,f0,f26,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f26.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8217ecd0
	if (!ctx.cr6.lt) goto loc_8217ECD0;
loc_8217ECC4:
	// fadds f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// blt cr6,0x8217ecc4
	if (ctx.cr6.lt) goto loc_8217ECC4;
loc_8217ECD0:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// blt cr6,0x8217eef8
	if (ctx.cr6.lt) goto loc_8217EEF8;
loc_8217ECD8:
	// fsubs f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8217ecd8
	if (!ctx.cr6.lt) goto loc_8217ECD8;
	// b 0x8217eef8
	goto loc_8217EEF8;
loc_8217ECE8:
	// lbz r11,13(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 13);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217ef00
	if (ctx.cr6.eq) goto loc_8217EF00;
	// lbz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8217ef00
	if (!ctx.cr6.eq) goto loc_8217EF00;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,184(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fdivs f1,f11,f10
	ctx.f1.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fadds f30,f1,f23
	ctx.f30.f64 = double(float(ctx.f1.f64 + ctx.f23.f64));
	// fcmpu cr6,f30,f25
	ctx.cr6.compare(ctx.f30.f64, ctx.f25.f64);
	// blt cr6,0x8217ed2c
	if (ctx.cr6.lt) goto loc_8217ED2C;
	// fmr f30,f25
	ctx.f30.f64 = ctx.f25.f64;
	// fmr f1,f24
	ctx.f1.f64 = ctx.f24.f64;
loc_8217ED2C:
	// addi r30,r30,56
	ctx.r30.s64 = ctx.r30.s64 + 56;
	// ld r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 92);
	// addi r29,r31,56
	ctx.r29.s64 = ctx.r31.s64 + 56;
	// ld r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 132);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// lwz r4,4(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f28,84(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f28,88(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f28,96(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f28,100(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f28,104(r1)
	temp.f32 = float(ctx.f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8206d0f0
	ctx.lr = 0x8217ED68;
	sub_8206D0F0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// ld r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// ld r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 132);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,4(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8206d0f0
	ctx.lr = 0x8217ED88;
	sub_8206D0F0(ctx, base);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8217ede8
	if (ctx.cr6.lt) goto loc_8217EDE8;
	// bne cr6,0x8217eefc
	if (!ctx.cr6.eq) goto loc_8217EEFC;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f1,f11,f12
	ctx.f1.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// bl 0x8207b440
	ctx.lr = 0x8217EDB4;
	sub_8207B440(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fmadds f0,f10,f26,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f26.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8217edd0
	if (!ctx.cr6.lt) goto loc_8217EDD0;
loc_8217EDC4:
	// fadds f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// blt cr6,0x8217edc4
	if (ctx.cr6.lt) goto loc_8217EDC4;
loc_8217EDD0:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// blt cr6,0x8217eef8
	if (ctx.cr6.lt) goto loc_8217EEF8;
loc_8217EDD8:
	// fsubs f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8217edd8
	if (!ctx.cr6.lt) goto loc_8217EDD8;
	// b 0x8217eef8
	goto loc_8217EEF8;
loc_8217EDE8:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f1,f11,f12
	ctx.f1.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// bl 0x8207b440
	ctx.lr = 0x8217EE04;
	sub_8207B440(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fmadds f0,f10,f26,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f26.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8217ee20
	if (!ctx.cr6.lt) goto loc_8217EE20;
loc_8217EE14:
	// fadds f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// blt cr6,0x8217ee14
	if (ctx.cr6.lt) goto loc_8217EE14;
loc_8217EE20:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// blt cr6,0x8217eef8
	if (ctx.cr6.lt) goto loc_8217EEF8;
loc_8217EE28:
	// fsubs f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8217ee28
	if (!ctx.cr6.lt) goto loc_8217EE28;
	// b 0x8217eef8
	goto loc_8217EEF8;
loc_8217EE38:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x82178290
	ctx.lr = 0x8217EE44;
	sub_82178290(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8217ef00
	if (ctx.cr6.eq) goto loc_8217EF00;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8217eeac
	if (ctx.cr6.lt) goto loc_8217EEAC;
	// bne cr6,0x8217eefc
	if (!ctx.cr6.eq) goto loc_8217EEFC;
	// lfs f0,440(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,448(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 448);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,12(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f1,f12,f11
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// bl 0x8207b440
	ctx.lr = 0x8217EE78;
	sub_8207B440(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fmadds f0,f10,f26,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f26.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8217ee94
	if (!ctx.cr6.lt) goto loc_8217EE94;
loc_8217EE88:
	// fadds f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// blt cr6,0x8217ee88
	if (ctx.cr6.lt) goto loc_8217EE88;
loc_8217EE94:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// blt cr6,0x8217eef8
	if (ctx.cr6.lt) goto loc_8217EEF8;
loc_8217EE9C:
	// fsubs f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8217ee9c
	if (!ctx.cr6.lt) goto loc_8217EE9C;
	// b 0x8217eef8
	goto loc_8217EEF8;
loc_8217EEAC:
	// lfs f0,440(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f11,8(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f1,f12,f11
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// bl 0x8207b440
	ctx.lr = 0x8217EEC8;
	sub_8207B440(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// fmadds f0,f10,f26,f31
	ctx.f0.f64 = double(float(ctx.f10.f64 * ctx.f26.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// bge cr6,0x8217eee4
	if (!ctx.cr6.lt) goto loc_8217EEE4;
loc_8217EED8:
	// fadds f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// blt cr6,0x8217eed8
	if (ctx.cr6.lt) goto loc_8217EED8;
loc_8217EEE4:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// blt cr6,0x8217eef8
	if (ctx.cr6.lt) goto loc_8217EEF8;
loc_8217EEEC:
	// fsubs f0,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f29.f64));
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8217eeec
	if (!ctx.cr6.lt) goto loc_8217EEEC;
loc_8217EEF8:
	// fmr f27,f0
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f0.f64;
loc_8217EEFC:
	// mr r29,r20
	ctx.r29.u64 = ctx.r20.u64;
loc_8217EF00:
	// lwz r11,252(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 252);
	// lfs f12,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,256(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 256);
	// lfs f13,8(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,4(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r31,r26,240
	ctx.r31.s64 = ctx.r26.s64 + 240;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217ef28
	if (!ctx.cr0.eq) goto loc_8217EF28;
	// twi 31,r0,22
loc_8217EF28:
	// stfs f0,480(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 480, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217ef44
	if (!ctx.cr0.eq) goto loc_8217EF44;
	// twi 31,r0,22
loc_8217EF44:
	// stfs f13,484(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 484, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217ef60
	if (!ctx.cr0.eq) goto loc_8217EF60;
	// twi 31,r0,22
loc_8217EF60:
	// stfs f12,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 488, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lbz r10,2(r28)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r28.u32 + 2);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// lbz r9,3(r28)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r28.u32 + 3);
	// divw. r6,r7,r25
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x8217ef84
	if (!ctx.cr0.eq) goto loc_8217EF84;
	// twi 31,r0,22
loc_8217EF84:
	// stb r10,478(r11)
	PPC_STORE_U8(ctx.r11.u32 + 478, ctx.r10.u8);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r7,r8,r25
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217efa0
	if (!ctx.cr0.eq) goto loc_8217EFA0;
	// twi 31,r0,22
loc_8217EFA0:
	// stb r9,479(r11)
	PPC_STORE_U8(ctx.r11.u32 + 479, ctx.r9.u8);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lfs f13,24(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lfs f0,20(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217efc4
	if (!ctx.cr0.eq) goto loc_8217EFC4;
	// twi 31,r0,22
loc_8217EFC4:
	// stfs f0,496(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 496, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217efe0
	if (!ctx.cr0.eq) goto loc_8217EFE0;
	// twi 31,r0,22
loc_8217EFE0:
	// clrlwi r10,r29,24
	ctx.r10.u64 = ctx.r29.u32 & 0xFF;
	// stfs f13,500(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 500, temp.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f028
	if (ctx.cr6.eq) goto loc_8217F028;
	// lbz r11,148(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217f00c
	if (ctx.cr6.eq) goto loc_8217F00C;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x8217c6d8
	ctx.lr = 0x8217F008;
	sub_8217C6D8(ctx, base);
	// b 0x8217f028
	goto loc_8217F028;
loc_8217F00C:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217f024
	if (!ctx.cr0.eq) goto loc_8217F024;
	// twi 31,r0,22
loc_8217F024:
	// stfs f27,492(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f27.f64);
	PPC_STORE_U32(ctx.r11.u32 + 492, temp.u32);
loc_8217F028:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lfs f13,32(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lfs f0,28(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217f048
	if (!ctx.cr0.eq) goto loc_8217F048;
	// twi 31,r0,22
loc_8217F048:
	// stfs f0,504(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 504, temp.u32);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217f064
	if (!ctx.cr0.eq) goto loc_8217F064;
	// twi 31,r0,22
loc_8217F064:
	// stfs f13,508(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 508, temp.u32);
	// lwz r10,36(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r25
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x8217f084
	if (!ctx.cr0.eq) goto loc_8217F084;
	// twi 31,r0,22
loc_8217F084:
	// stw r10,512(r11)
	PPC_STORE_U32(ctx.r11.u32 + 512, ctx.r10.u32);
	// lbz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217f0c0
	if (ctx.cr6.eq) goto loc_8217F0C0;
	// lbz r11,1(r28)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r28.u32 + 1);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217f0c0
	if (ctx.cr6.eq) goto loc_8217F0C0;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217f0b8
	if (!ctx.cr0.eq) goto loc_8217F0B8;
	// twi 31,r0,22
loc_8217F0B8:
	// stb r20,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r20.u8);
	// b 0x8217f0dc
	goto loc_8217F0DC;
loc_8217F0C0:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217f0d8
	if (!ctx.cr0.eq) goto loc_8217F0D8;
	// twi 31,r0,22
loc_8217F0D8:
	// stb r19,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r19.u8);
loc_8217F0DC:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r25
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r25.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x8217f0f4
	if (!ctx.cr0.eq) goto loc_8217F0F4;
	// twi 31,r0,22
loc_8217F0F4:
	// lwz r10,516(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 516);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r10,516(r11)
	PPC_STORE_U32(ctx.r11.u32 + 516, ctx.r10.u32);
	// lfs f1,192(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217dc10
	ctx.lr = 0x8217F108;
	sub_8217DC10(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8217f318
	ctx.lr = 0x8217F110;
	sub_8217F318(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x821795c8
	ctx.lr = 0x8217F11C;
	sub_821795C8(ctx, base);
	// b 0x8217f2ec
	goto loc_8217F2EC;
loc_8217F120:
	// stb r19,176(r26)
	PPC_STORE_U8(ctx.r26.u32 + 176, ctx.r19.u8);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82176ed0
	ctx.lr = 0x8217F12C;
	sub_82176ED0(ctx, base);
	// lwz r7,60(r26)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r26.u32 + 60);
	// addi r4,r26,36
	ctx.r4.s64 = ctx.r26.s64 + 36;
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// blt cr6,0x8217f148
	if (ctx.cr6.lt) goto loc_8217F148;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x8217f14c
	goto loc_8217F14C;
loc_8217F148:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F14C:
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// add. r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 + ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8217f194
	if (ctx.cr0.eq) goto loc_8217F194;
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x8217f168
	if (ctx.cr6.lt) goto loc_8217F168;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f16c
	goto loc_8217F16C;
loc_8217F168:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F16C:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8217f194
	if (ctx.cr6.gt) goto loc_8217F194;
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x8217f184
	if (ctx.cr6.lt) goto loc_8217F184;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f188
	goto loc_8217F188;
loc_8217F184:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F188:
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217f198
	if (!ctx.cr6.gt) goto loc_8217F198;
loc_8217F194:
	// twi 31,r0,22
loc_8217F198:
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// blt cr6,0x8217f1b0
	if (ctx.cr6.lt) goto loc_8217F1B0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f1b4
	goto loc_8217F1B4;
loc_8217F1B0:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8217F1B4:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217f1f0
	if (ctx.cr6.eq) goto loc_8217F1F0;
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x8217f1cc
	if (ctx.cr6.lt) goto loc_8217F1CC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f1d0
	goto loc_8217F1D0;
loc_8217F1CC:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F1D0:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8217f1f0
	if (ctx.cr6.gt) goto loc_8217F1F0;
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x8217f1e4
	if (ctx.cr6.lt) goto loc_8217F1E4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8217F1E4:
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8217f1f4
	if (!ctx.cr6.gt) goto loc_8217F1F4;
loc_8217F1F0:
	// twi 31,r0,22
loc_8217F1F4:
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// ld r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// ld r5,136(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// bl 0x82060968
	ctx.lr = 0x8217F20C;
	sub_82060968(ctx, base);
	// lwz r8,88(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 88);
	// addi r4,r26,64
	ctx.r4.s64 = ctx.r26.s64 + 64;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// blt cr6,0x8217f228
	if (ctx.cr6.lt) goto loc_8217F228;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// b 0x8217f22c
	goto loc_8217F22C;
loc_8217F228:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F22C:
	// lwz r7,20(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// add. r9,r7,r10
	ctx.r9.u64 = ctx.r7.u64 + ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8217f274
	if (ctx.cr0.eq) goto loc_8217F274;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8217f248
	if (ctx.cr6.lt) goto loc_8217F248;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f24c
	goto loc_8217F24C;
loc_8217F248:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F24C:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8217f274
	if (ctx.cr6.gt) goto loc_8217F274;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8217f264
	if (ctx.cr6.lt) goto loc_8217F264;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f268
	goto loc_8217F268;
loc_8217F264:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F268:
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8217f278
	if (!ctx.cr6.gt) goto loc_8217F278;
loc_8217F274:
	// twi 31,r0,22
loc_8217F278:
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// blt cr6,0x8217f290
	if (ctx.cr6.lt) goto loc_8217F290;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f294
	goto loc_8217F294;
loc_8217F290:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8217F294:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217f2d0
	if (ctx.cr6.eq) goto loc_8217F2D0;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8217f2ac
	if (ctx.cr6.lt) goto loc_8217F2AC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x8217f2b0
	goto loc_8217F2B0;
loc_8217F2AC:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8217F2B0:
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8217f2d0
	if (ctx.cr6.gt) goto loc_8217F2D0;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8217f2c4
	if (ctx.cr6.lt) goto loc_8217F2C4;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8217F2C4:
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8217f2d4
	if (!ctx.cr6.gt) goto loc_8217F2D4;
loc_8217F2D0:
	// twi 31,r0,22
loc_8217F2D4:
	// stw r4,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// ld r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// ld r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x82060968
	ctx.lr = 0x8217F2EC;
	sub_82060968(ctx, base);
loc_8217F2EC:
	// lwz r11,16(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 16);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// lwz r10,12(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r23,r8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217ea0c
	if (ctx.cr6.lt) goto loc_8217EA0C;
loc_8217F308:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x820803a0
	ctx.lr = 0x8217F314;
	__restfpr_23(ctx, base);
	// b 0x8207c9b4
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217F318"))) PPC_WEAK_FUNC(sub_8217F318);
PPC_FUNC_IMPL(__imp__sub_8217F318) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8217F320;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,3
	ctx.r11.s64 = 3;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// addi r28,r3,240
	ctx.r28.s64 = ctx.r3.s64 + 240;
	// addi r9,r3,-284
	ctx.r9.s64 = ctx.r3.s64 + -284;
	// li r27,524
	ctx.r27.s64 = 524;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r11,480
	ctx.r11.s64 = 480;
loc_8217F340:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r8,16(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r27
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x8217f358
	if (!ctx.cr0.eq) goto loc_8217F358;
	// twi 31,r0,22
loc_8217F358:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,192(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f0,f12,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f12.f64 + ctx.f13.f64));
	// stfsx f11,r10,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r11.u32, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8217f340
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217F340;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f1,208(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 208);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// beq cr6,0x8217f3c8
	if (ctx.cr6.eq) goto loc_8217F3C8;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f13,192(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// lfs f0,136(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x8207b7a8
	ctx.lr = 0x8217F3A0;
	sub_8207B7A8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,196(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 196);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,200(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 200);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,204(r22)
	temp.u32 = PPC_LOAD_U32(ctx.r22.u32 + 204);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f11,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f8,196(r22)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r22.u32 + 196, temp.u32);
	// fmuls f7,f10,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f7,200(r22)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r22.u32 + 200, temp.u32);
	// fmuls f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfs f6,204(r22)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r22.u32 + 204, temp.u32);
loc_8217F3C8:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// subf r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r7,r8,r27
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x8217f440
	if (ctx.cr0.eq) goto loc_8217F440;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
loc_8217F3E8:
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r8,16(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// divw r6,r7,r27
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r27.s32);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217f404
	if (ctx.cr6.lt) goto loc_8217F404;
	// twi 31,r0,22
loc_8217F404:
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,524
	ctx.r9.s64 = ctx.r9.s64 + 524;
	// lfs f0,440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 440);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// lfs f13,444(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// lfs f12,448(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 448);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 88, temp.u32);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r8,12(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// subf r7,r8,r11
	ctx.r7.s64 = ctx.r11.s64 - ctx.r8.s64;
	// divw r6,r7,r27
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r27.s32);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8217f3e8
	if (ctx.cr6.lt) goto loc_8217F3E8;
loc_8217F440:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82179168
	ctx.lr = 0x8217F448;
	sub_82179168(ctx, base);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// divw. r9,r10,r27
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8217f460
	if (!ctx.cr0.eq) goto loc_8217F460;
	// twi 31,r0,22
loc_8217F460:
	// bl 0x821762c0
	ctx.lr = 0x8217F464;
	sub_821762C0(ctx, base);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// li r25,1
	ctx.r25.s64 = 1;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// ble cr6,0x8217f918
	if (!ctx.cr6.gt) goto loc_8217F918;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// li r24,255
	ctx.r24.s64 = 255;
loc_8217F488:
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// cmplw cr6,r25,r8
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217f4a4
	if (ctx.cr6.lt) goto loc_8217F4A4;
	// twi 31,r0,22
loc_8217F4A4:
	// add r30,r10,r26
	ctx.r30.u64 = ctx.r10.u64 + ctx.r26.u64;
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217f4c8
	if (ctx.cr6.lt) goto loc_8217F4C8;
	// twi 31,r0,22
loc_8217F4C8:
	// mulli r10,r10,524
	ctx.r10.s64 = ctx.r10.s64 * 524;
	// add r29,r10,r11
	ctx.r29.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,0,9,9
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f518
	if (ctx.cr6.eq) goto loc_8217F518;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r9,r9,r27
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
loc_8217F4F0:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8217f500
	if (ctx.cr6.lt) goto loc_8217F500;
	// twi 31,r0,22
loc_8217F500:
	// mulli r11,r11,524
	ctx.r11.s64 = ctx.r11.s64 * 524;
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r8,r11,0,9,9
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400000;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8217f4f0
	if (!ctx.cr6.eq) goto loc_8217F4F0;
loc_8217F518:
	// lwz r11,432(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 432);
	// addi r31,r30,436
	ctx.r31.s64 = ctx.r30.s64 + 436;
	// mulli r11,r11,148
	ctx.r11.s64 = ctx.r11.s64 * 148;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lbz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 144);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8217f5a4
	if (ctx.cr6.eq) goto loc_8217F5A4;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r11,r29,432
	ctx.r11.s64 = ctx.r29.s64 + 432;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8217F544:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8217f544
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8217F544;
	// stb r23,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r23.u8);
	// lbz r11,477(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 477);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217f570
	if (ctx.cr6.eq) goto loc_8217F570;
	// lbz r11,437(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 437);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8217f574
	if (!ctx.cr6.eq) goto loc_8217F574;
loc_8217F570:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8217F574:
	// stb r11,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r11.u8);
	// addi r10,r29,64
	ctx.r10.s64 = ctx.r29.s64 + 64;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// addi r11,r30,64
	ctx.r11.s64 = ctx.r30.s64 + 64;
	// stw r9,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r9.u32);
	// lwz r8,68(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// stw r8,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r8.u32);
	// lwz r7,72(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// stw r7,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r7.u32);
	// lwz r6,76(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// stw r6,76(r30)
	PPC_STORE_U32(ctx.r30.u32 + 76, ctx.r6.u32);
	// b 0x8217f8f8
	goto loc_8217F8F8;
loc_8217F5A4:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217f5c0
	if (ctx.cr6.eq) goto loc_8217F5C0;
	// lbz r11,476(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 476);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8217f5c4
	if (!ctx.cr6.eq) goto loc_8217F5C4;
loc_8217F5C0:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8217F5C4:
	// stb r11,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
	// lbz r10,477(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 477);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f5e4
	if (ctx.cr6.eq) goto loc_8217F5E4;
	// lbz r11,437(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 437);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne cr6,0x8217f5e8
	if (!ctx.cr6.eq) goto loc_8217F5E8;
loc_8217F5E4:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_8217F5E8:
	// lbz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r11.u8);
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lbz r7,478(r30)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + 478);
	// xor r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// lbz r9,3(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// lfs f12,24(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stb r6,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r6.u8);
	// lfs f11,28(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lbz r4,479(r30)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r30.u32 + 479);
	// xor r3,r4,r9
	ctx.r3.u64 = ctx.r4.u64 ^ ctx.r9.u64;
	// stb r3,3(r31)
	PPC_STORE_U8(ctx.r31.u32 + 3, ctx.r3.u8);
	// lfs f10,32(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lfs f9,492(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 492);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// stfs f8,16(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// lfs f7,496(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 496);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f6,20(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// lfs f5,500(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 500);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f12
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// stfs f4,24(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// lfs f3,504(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 504);
	ctx.f3.f64 = double(temp.f32);
	// fadds f2,f3,f11
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f11.f64));
	// stfs f2,28(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// lfs f1,508(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 508);
	ctx.f1.f64 = double(temp.f32);
	// fadds f0,f1,f10
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f10.f64));
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lwz r10,512(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 512);
	// mullw r9,r10,r8
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// divwu r8,r9,r24
	ctx.r8.u32 = ppc_divwu(ctx.r9.u32, ctx.r24.u32);
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,480(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 480);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// stfs f9,4(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f8,484(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 484);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// stfs f7,8(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fmr f0,f7
	ctx.f0.f64 = ctx.f7.f64;
	// lfs f6,488(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 488);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f12.f64));
	// stfs f5,12(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// lwz r7,4(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x8217f6d8
	if (!ctx.cr6.eq) goto loc_8217F6D8;
	// lfs f13,68(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,76(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f7
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f7.f64));
	// fmuls f10,f7,f12
	ctx.f10.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// lfs f8,64(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,72(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	ctx.f7.f64 = double(temp.f32);
	// fmr f12,f5
	ctx.f12.f64 = ctx.f5.f64;
	// fmadds f13,f9,f8,f11
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f11.f64));
	// fmadds f0,f9,f7,f10
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f7.f64 + ctx.f10.f64));
	// b 0x8217f700
	goto loc_8217F700;
loc_8217F6D8:
	// lfs f12,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,68(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,72(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f12
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmuls f7,f11,f9
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// lfs f6,64(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,76(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f13,f11,f6,f8
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f6.f64 + ctx.f8.f64));
	// fmadds f12,f12,f5,f7
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f5.f64 + ctx.f7.f64));
loc_8217F700:
	// lfs f11,440(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 440);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f10,4(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lfs f9,444(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 444);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// stfs f8,8(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// lfs f7,448(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 448);
	ctx.f7.f64 = double(temp.f32);
	// fadds f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f12.f64));
	// stfs f6,12(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// lbz r11,177(r22)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r22.u32 + 177);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8217f744
	if (ctx.cr6.eq) goto loc_8217F744;
	// stw r23,80(r30)
	PPC_STORE_U32(ctx.r30.u32 + 80, ctx.r23.u32);
	// addi r11,r30,80
	ctx.r11.s64 = ctx.r30.s64 + 80;
	// stw r23,84(r30)
	PPC_STORE_U32(ctx.r30.u32 + 84, ctx.r23.u32);
	// stw r23,88(r30)
	PPC_STORE_U32(ctx.r30.u32 + 88, ctx.r23.u32);
	// b 0x8217f774
	goto loc_8217F774;
loc_8217F744:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f12,80(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r30.u32 + 80, temp.u32);
	// lfs f11,84(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,88(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// stfs f8,84(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r30.u32 + 84, temp.u32);
	// lfs f7,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// stfs f6,88(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r30.u32 + 88, temp.u32);
loc_8217F774:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,23,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1FC;
	// cmplwi cr6,r10,508
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 508, ctx.xer);
	// bne cr6,0x8217f7dc
	if (!ctx.cr6.eq) goto loc_8217F7DC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821762c0
	ctx.lr = 0x8217F78C;
	sub_821762C0(ctx, base);
	// lfs f0,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,76(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,72(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,76(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfs f8,64(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f12
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f6,72(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f13,f11
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f4,64(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,68(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f4,f8,f10
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f8.f64 + ctx.f10.f64));
	// stfs f2,64(r30)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r30.u32 + 64, temp.u32);
	// fmadds f1,f3,f8,f9
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f8.f64 + ctx.f9.f64));
	// stfs f1,68(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + 68, temp.u32);
	// fmadds f0,f6,f4,f7
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f4.f64 + ctx.f7.f64));
	// stfs f0,72(r30)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r30.u32 + 72, temp.u32);
	// fmadds f13,f6,f3,f5
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f3.f64 + ctx.f5.f64));
	// stfs f13,76(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r30.u32 + 76, temp.u32);
loc_8217F7DC:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f800
	if (ctx.cr6.eq) goto loc_8217F800;
	// lwz r11,472(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 472);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// divwu r8,r9,r24
	ctx.r8.u32 = ppc_divwu(ctx.r9.u32, ctx.r24.u32);
	// stw r8,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
loc_8217F800:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f820
	if (ctx.cr6.eq) goto loc_8217F820;
	// lbz r11,438(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 438);
	// lbz r10,2(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 2);
	// xor r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// stb r9,2(r31)
	PPC_STORE_U8(ctx.r31.u32 + 2, ctx.r9.u8);
loc_8217F820:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f840
	if (ctx.cr6.eq) goto loc_8217F840;
	// lbz r11,439(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 439);
	// lbz r10,3(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 3);
	// xor r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r10.u64;
	// stb r9,3(r31)
	PPC_STORE_U8(ctx.r31.u32 + 3, ctx.r9.u8);
loc_8217F840:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f860
	if (ctx.cr6.eq) goto loc_8217F860;
	// lfs f0,452(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 452);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 16, temp.u32);
loc_8217F860:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f880
	if (ctx.cr6.eq) goto loc_8217F880;
	// lfs f0,456(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
loc_8217F880:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f8a0
	if (ctx.cr6.eq) goto loc_8217F8A0;
	// lfs f0,460(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
loc_8217F8A0:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f8c0
	if (ctx.cr6.eq) goto loc_8217F8C0;
	// lfs f0,464(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
loc_8217F8C0:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x100;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f8e0
	if (ctx.cr6.eq) goto loc_8217F8E0;
	// lfs f0,468(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,32(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 32, temp.u32);
loc_8217F8E0:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// rlwinm r10,r11,0,23,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1FC;
	// cmplwi cr6,r10,508
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 508, ctx.xer);
	// beq cr6,0x8217f8f8
	if (ctx.cr6.eq) goto loc_8217F8F8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821762c0
	ctx.lr = 0x8217F8F8;
	sub_821762C0(ctx, base);
loc_8217F8F8:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// addi r26,r26,524
	ctx.r26.s64 = ctx.r26.s64 + 524;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
	// cmplw cr6,r25,r8
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8217f488
	if (ctx.cr6.lt) goto loc_8217F488;
loc_8217F918:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82176c98
	ctx.lr = 0x8217F920;
	sub_82176C98(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x82176a48
	ctx.lr = 0x8217F928;
	sub_82176A48(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8217e9a0
	ctx.lr = 0x8217F930;
	sub_8217E9A0(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x8217df30
	ctx.lr = 0x8217F938;
	sub_8217DF30(ctx, base);
	// stb r23,177(r22)
	PPC_STORE_U8(ctx.r22.u32 + 177, ctx.r23.u8);
	// stb r23,178(r22)
	PPC_STORE_U8(ctx.r22.u32 + 178, ctx.r23.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217F948"))) PPC_WEAK_FUNC(sub_8217F948);
PPC_FUNC_IMPL(__imp__sub_8217F948) {
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
	// addi r3,r3,516
	ctx.r3.s64 = ctx.r3.s64 + 516;
	// bl 0x82066558
	ctx.lr = 0x8217F964;
	sub_82066558(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31328(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31328);
	// lbz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8217f980
	if (ctx.cr6.eq) goto loc_8217F980;
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8217f994
	goto loc_8217F994;
loc_8217F980:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
loc_8217F994:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217dc10
	ctx.lr = 0x8217F99C;
	sub_8217DC10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8217f318
	ctx.lr = 0x8217F9A4;
	sub_8217F318(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82177318
	ctx.lr = 0x8217F9AC;
	sub_82177318(ctx, base);
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

__attribute__((alias("__imp__sub_8217F9C0"))) PPC_WEAK_FUNC(sub_8217F9C0);
PPC_FUNC_IMPL(__imp__sub_8217F9C0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x8217f948
	sub_8217F948(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217F9C8"))) PPC_WEAK_FUNC(sub_8217F9C8);
PPC_FUNC_IMPL(__imp__sub_8217F9C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217F9D0"))) PPC_WEAK_FUNC(sub_8217F9D0);
PPC_FUNC_IMPL(__imp__sub_8217F9D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217F9D8"))) PPC_WEAK_FUNC(sub_8217F9D8);
PPC_FUNC_IMPL(__imp__sub_8217F9D8) {
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

__attribute__((alias("__imp__sub_8217F9EC"))) PPC_WEAK_FUNC(sub_8217F9EC);
PPC_FUNC_IMPL(__imp__sub_8217F9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217F9F0"))) PPC_WEAK_FUNC(sub_8217F9F0);
PPC_FUNC_IMPL(__imp__sub_8217F9F0) {
	PPC_FUNC_PROLOGUE();
	// fctid f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA00"))) PPC_WEAK_FUNC(sub_8217FA00);
PPC_FUNC_IMPL(__imp__sub_8217FA00) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-32208(r10)
	PPC_STORE_U32(ctx.r10.u32 + -32208, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA10"))) PPC_WEAK_FUNC(sub_8217FA10);
PPC_FUNC_IMPL(__imp__sub_8217FA10) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,32
	ctx.r11.s64 = ctx.r4.s64 + 32;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r8,r10,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r6,r8,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// b 0x8209d660
	sub_8209D660(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217FA28"))) PPC_WEAK_FUNC(sub_8217FA28);
PPC_FUNC_IMPL(__imp__sub_8217FA28) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// ldx r10,r11,r3
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r11.u32 + ctx.r3.u32);
	// or r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 | ctx.r5.u64;
	// stdx r9,r11,r3
	PPC_STORE_U64(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA3C"))) PPC_WEAK_FUNC(sub_8217FA3C);
PPC_FUNC_IMPL(__imp__sub_8217FA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217FA40"))) PPC_WEAK_FUNC(sub_8217FA40);
PPC_FUNC_IMPL(__imp__sub_8217FA40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// subf r10,r4,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r4.s64;
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r7,r9,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// add r6,r11,r4
	ctx.r6.u64 = ctx.r11.u64 + ctx.r4.u64;
	// srad r5,r7,r8
	temp.u64 = ctx.r8.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r7.s64 < 0) & (((ctx.r7.s64 >> temp.u64) << temp.u64) != ctx.r7.s64);
	ctx.r5.s64 = ctx.r7.s64 >> temp.u64;
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// srd r3,r5,r4
	ctx.r3.u64 = ctx.r4.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r4.u8 & 0x7F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA68"))) PPC_WEAK_FUNC(sub_8217FA68);
PPC_FUNC_IMPL(__imp__sub_8217FA68) {
	PPC_FUNC_PROLOGUE();
	// srawi r3,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA70"))) PPC_WEAK_FUNC(sub_8217FA70);
PPC_FUNC_IMPL(__imp__sub_8217FA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA78"))) PPC_WEAK_FUNC(sub_8217FA78);
PPC_FUNC_IMPL(__imp__sub_8217FA78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA80"))) PPC_WEAK_FUNC(sub_8217FA80);
PPC_FUNC_IMPL(__imp__sub_8217FA80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA88"))) PPC_WEAK_FUNC(sub_8217FA88);
PPC_FUNC_IMPL(__imp__sub_8217FA88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FA90"))) PPC_WEAK_FUNC(sub_8217FA90);
PPC_FUNC_IMPL(__imp__sub_8217FA90) {
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

__attribute__((alias("__imp__sub_8217FAA8"))) PPC_WEAK_FUNC(sub_8217FAA8);
PPC_FUNC_IMPL(__imp__sub_8217FAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8217FAB0;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r31,r11,20456
	ctx.r31.s64 = ctx.r11.s64 + 20456;
	// addi r3,r31,-28336
	ctx.r3.s64 = ctx.r31.s64 + -28336;
	// bl 0x8209b498
	ctx.lr = 0x8217FAC8;
	sub_8209B498(ctx, base);
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-29712
	ctx.r3.s64 = ctx.r31.s64 + -29712;
	// addi r29,r30,-31488
	ctx.r29.s64 = ctx.r30.s64 + -31488;
	// stw r11,-31488(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31488, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FAE0;
	sub_8209B2B0(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,-31488(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31488);
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,-31952(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31952, ctx.r11.u32);
	// addi r27,r10,-31952
	ctx.r27.s64 = ctx.r10.s64 + -31952;
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FB10;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-4088
	ctx.r3.s64 = ctx.r31.s64 + -4088;
	// bl 0x8209b498
	ctx.lr = 0x8217FB18;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-5552
	ctx.r3.s64 = ctx.r31.s64 + -5552;
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FB28;
	sub_8209B2B0(ctx, base);
	// stw r3,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FB48;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-25328
	ctx.r3.s64 = ctx.r31.s64 + -25328;
	// bl 0x8209b498
	ctx.lr = 0x8217FB50;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-25960
	ctx.r3.s64 = ctx.r31.s64 + -25960;
	// stw r11,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FB60;
	sub_8209B2B0(ctx, base);
	// stw r3,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FB80;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-23536
	ctx.r3.s64 = ctx.r31.s64 + -23536;
	// bl 0x8209b498
	ctx.lr = 0x8217FB88;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-24928
	ctx.r3.s64 = ctx.r31.s64 + -24928;
	// stw r11,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FB98;
	sub_8209B2B0(ctx, base);
	// stw r3,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FBB8;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-21712
	ctx.r3.s64 = ctx.r31.s64 + -21712;
	// bl 0x8209b498
	ctx.lr = 0x8217FBC0;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-23136
	ctx.r3.s64 = ctx.r31.s64 + -23136;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FBD0;
	sub_8209B2B0(ctx, base);
	// stw r3,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FBF0;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-26296
	ctx.r3.s64 = ctx.r31.s64 + -26296;
	// bl 0x8209b498
	ctx.lr = 0x8217FBF8;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r11,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// addi r3,r31,-27936
	ctx.r3.s64 = ctx.r31.s64 + -27936;
	// bl 0x8209b2b0
	ctx.lr = 0x8217FC08;
	sub_8209B2B0(ctx, base);
	// stw r3,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FC28;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-14424
	ctx.r3.s64 = ctx.r31.s64 + -14424;
	// bl 0x8209b498
	ctx.lr = 0x8217FC30;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-14784
	ctx.r3.s64 = ctx.r31.s64 + -14784;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FC40;
	sub_8209B2B0(ctx, base);
	// stw r3,24(r27)
	PPC_STORE_U32(ctx.r27.u32 + 24, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FC60;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-6112
	ctx.r3.s64 = ctx.r31.s64 + -6112;
	// bl 0x8209b498
	ctx.lr = 0x8217FC68;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-9784
	ctx.r3.s64 = ctx.r31.s64 + -9784;
	// stw r11,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FC78;
	sub_8209B2B0(ctx, base);
	// stw r3,28(r27)
	PPC_STORE_U32(ctx.r27.u32 + 28, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FC98;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-15344
	ctx.r3.s64 = ctx.r31.s64 + -15344;
	// bl 0x8209b498
	ctx.lr = 0x8217FCA0;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-18032
	ctx.r3.s64 = ctx.r31.s64 + -18032;
	// stw r11,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FCB0;
	sub_8209B2B0(ctx, base);
	// stw r3,32(r27)
	PPC_STORE_U32(ctx.r27.u32 + 32, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FCD0;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-10344
	ctx.r3.s64 = ctx.r31.s64 + -10344;
	// bl 0x8209b498
	ctx.lr = 0x8217FCD8;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-14016
	ctx.r3.s64 = ctx.r31.s64 + -14016;
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FCE8;
	sub_8209B2B0(ctx, base);
	// stw r3,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FD08;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-18592
	ctx.r3.s64 = ctx.r31.s64 + -18592;
	// bl 0x8209b498
	ctx.lr = 0x8217FD10;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-21296
	ctx.r3.s64 = ctx.r31.s64 + -21296;
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FD20;
	sub_8209B2B0(ctx, base);
	// stw r3,40(r27)
	PPC_STORE_U32(ctx.r27.u32 + 40, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,40(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 40);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FD40;
	sub_820A05A0(ctx, base);
	// lis r25,-32252
	ctx.r25.s64 = -2113667072;
	// addi r30,r25,-21836
	ctx.r30.s64 = ctx.r25.s64 + -21836;
	// addi r3,r30,8092
	ctx.r3.s64 = ctx.r30.s64 + 8092;
	// bl 0x8209b498
	ctx.lr = 0x8217FD50;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r30,7140
	ctx.r3.s64 = ctx.r30.s64 + 7140;
	// stw r11,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FD60;
	sub_8209B2B0(ctx, base);
	// stw r3,44(r27)
	PPC_STORE_U32(ctx.r27.u32 + 44, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 44);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FD80;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-32640
	ctx.r3.s64 = ctx.r31.s64 + -32640;
	// bl 0x8209b498
	ctx.lr = 0x8217FD88;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r30,8892
	ctx.r3.s64 = ctx.r30.s64 + 8892;
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FD98;
	sub_8209B2B0(ctx, base);
	// stw r3,48(r27)
	PPC_STORE_U32(ctx.r27.u32 + 48, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,48(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 48);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FDB8;
	sub_820A05A0(ctx, base);
	// addi r3,r30,5124
	ctx.r3.s64 = ctx.r30.s64 + 5124;
	// bl 0x8209b498
	ctx.lr = 0x8217FDC0;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r30,4828
	ctx.r3.s64 = ctx.r30.s64 + 4828;
	// stw r11,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FDD0;
	sub_8209B2B0(ctx, base);
	// stw r3,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,52(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 52);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FDF0;
	sub_820A05A0(ctx, base);
	// addi r3,r30,6340
	ctx.r3.s64 = ctx.r30.s64 + 6340;
	// bl 0x8209b498
	ctx.lr = 0x8217FDF8;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r30,5524
	ctx.r3.s64 = ctx.r30.s64 + 5524;
	// stw r11,56(r29)
	PPC_STORE_U32(ctx.r29.u32 + 56, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FE08;
	sub_8209B2B0(ctx, base);
	// stw r3,56(r27)
	PPC_STORE_U32(ctx.r27.u32 + 56, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 56);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FE28;
	sub_820A05A0(ctx, base);
	// addi r3,r30,4428
	ctx.r3.s64 = ctx.r30.s64 + 4428;
	// bl 0x8209b498
	ctx.lr = 0x8217FE30;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r30,3956
	ctx.r3.s64 = ctx.r30.s64 + 3956;
	// stw r11,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FE40;
	sub_8209B2B0(ctx, base);
	// stw r3,60(r27)
	PPC_STORE_U32(ctx.r27.u32 + 60, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,60(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 60);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FE60;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-3384
	ctx.r3.s64 = ctx.r31.s64 + -3384;
	// bl 0x8209b498
	ctx.lr = 0x8217FE68;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-3680
	ctx.r3.s64 = ctx.r31.s64 + -3680;
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FE78;
	sub_8209B2B0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r3,64(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stw r11,64(r27)
	PPC_STORE_U32(ctx.r27.u32 + 64, ctx.r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-32152(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32152);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FEA0;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-30872
	ctx.r3.s64 = ctx.r31.s64 + -30872;
	// bl 0x8209b498
	ctx.lr = 0x8217FEA8;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-31232
	ctx.r3.s64 = ctx.r31.s64 + -31232;
	// stw r11,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FEB8;
	sub_8209B2B0(ctx, base);
	// stw r3,68(r27)
	PPC_STORE_U32(ctx.r27.u32 + 68, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 68);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FED8;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-31632
	ctx.r3.s64 = ctx.r31.s64 + -31632;
	// bl 0x8209b498
	ctx.lr = 0x8217FEE0;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-31920
	ctx.r3.s64 = ctx.r31.s64 + -31920;
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FEF0;
	sub_8209B2B0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r3,72(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 72);
	// stw r11,72(r27)
	PPC_STORE_U32(ctx.r27.u32 + 72, ctx.r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-32160(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32160);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FF18;
	sub_820A05A0(ctx, base);
	// addi r3,r31,-30112
	ctx.r3.s64 = ctx.r31.s64 + -30112;
	// bl 0x8209b498
	ctx.lr = 0x8217FF20;
	sub_8209B498(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r31,-30472
	ctx.r3.s64 = ctx.r31.s64 + -30472;
	// stw r11,76(r29)
	PPC_STORE_U32(ctx.r29.u32 + 76, ctx.r11.u32);
	// bl 0x8209b2b0
	ctx.lr = 0x8217FF30;
	sub_8209B2B0(ctx, base);
	// stw r3,76(r27)
	PPC_STORE_U32(ctx.r27.u32 + 76, ctx.r3.u32);
	// lwz r11,-31956(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31956);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,76(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 76);
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a05a0
	ctx.lr = 0x8217FF50;
	sub_820A05A0(ctx, base);
	// lis r24,-32224
	ctx.r24.s64 = -2111832064;
	// lis r7,6184
	ctx.r7.s64 = 405274624;
	// lis r23,-32224
	ctx.r23.s64 = -2111832064;
	// ori r26,r7,390
	ctx.r26.u64 = ctx.r7.u64 | 390;
	// li r27,-2
	ctx.r27.s64 = -2;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,-1
	ctx.r30.s64 = -1;
	// addi r28,r23,-32196
	ctx.r28.s64 = ctx.r23.s64 + -32196;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r4,r31,-3024
	ctx.r4.s64 = ctx.r31.s64 + -3024;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// li r5,192
	ctx.r5.s64 = 192;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x8217FFB8;
	sub_820B6770(ctx, base);
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// lwz r3,-32196(r23)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r23.u32 + -32196);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209d220
	ctx.lr = 0x8217FFC8;
	sub_8209D220(ctx, base);
	// lwz r23,408(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	// lis r3,-32224
	ctx.r3.s64 = -2111832064;
	// lwz r22,412(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// lfs f31,-21836(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r25.u32 + -21836);
	ctx.f31.f64 = double(temp.f32);
	// addi r25,r3,-31208
	ctx.r25.s64 = ctx.r3.s64 + -31208;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// addi r10,r28,4
	ctx.r10.s64 = ctx.r28.s64 + 4;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// std r23,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r23.u64);
	// lfd f0,152(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// std r22,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r22.u64);
	// lfd f13,152(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// addi r4,r31,-2512
	ctx.r4.s64 = ctx.r31.s64 + -2512;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// li r5,272
	ctx.r5.s64 = 272;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f0,f31,f10
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f10.f64));
	// stfs f0,4(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 4, temp.u32);
	// fdivs f0,f31,f9
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f9.f64));
	// stfs f0,-31208(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + -31208, temp.u32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x82180058;
	sub_820B6770(ctx, base);
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8209d220
	ctx.lr = 0x82180068;
	sub_8209D220(ctx, base);
	// lwz r6,344(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	// lwz r5,348(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// addi r9,r28,8
	ctx.r9.s64 = ctx.r28.s64 + 8;
	// std r6,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r6.u64);
	// lfd f8,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// std r5,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r5.u64);
	// lfd f7,152(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// addi r4,r31,-464
	ctx.r4.s64 = ctx.r31.s64 + -464;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,272
	ctx.r5.s64 = 272;
	// fdivs f0,f31,f4
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f4.f64));
	// stfs f0,12(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 12, temp.u32);
	// fdivs f0,f31,f3
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f3.f64));
	// stfs f0,8(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 8, temp.u32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x821800EC;
	sub_820B6770(ctx, base);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// bl 0x8209d220
	ctx.lr = 0x821800FC;
	sub_8209D220(ctx, base);
	// addi r10,r28,12
	ctx.r10.s64 = ctx.r28.s64 + 12;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// lwz r3,284(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r23,280(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// addi r4,r31,-2240
	ctx.r4.s64 = ctx.r31.s64 + -2240;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// std r3,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r3.u64);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r5,224
	ctx.r5.s64 = 224;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lfd f2,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// std r23,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r23.u64);
	// lfd f1,152(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f0,f1
	ctx.f0.f64 = double(ctx.f1.s64);
	// fcfid f13,f2
	ctx.f13.f64 = double(ctx.f2.s64);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f31,f12
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f12.f64));
	// stfs f0,16(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 16, temp.u32);
	// fdivs f0,f31,f11
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f11.f64));
	// stfs f0,20(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 20, temp.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x82180180;
	sub_820B6770(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// bl 0x8209d220
	ctx.lr = 0x82180190;
	sub_8209D220(ctx, base);
	// lwz r4,184(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// lfd f10,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// lwz r5,188(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// addi r9,r28,16
	ctx.r9.s64 = ctx.r28.s64 + 16;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// addi r4,r31,-2832
	ctx.r4.s64 = ctx.r31.s64 + -2832;
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// lfd f8,144(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// li r9,0
	ctx.r9.s64 = 0;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// li r8,0
	ctx.r8.s64 = 0;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// li r5,320
	ctx.r5.s64 = 320;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f0,f31,f5
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f5.f64));
	// stfs f0,28(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 28, temp.u32);
	// fdivs f0,f31,f7
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f7.f64));
	// stfs f0,24(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 24, temp.u32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x82180214;
	sub_820B6770(ctx, base);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// bl 0x8209d220
	ctx.lr = 0x82180224;
	sub_8209D220(ctx, base);
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// addi r5,r28,20
	ctx.r5.s64 = ctx.r28.s64 + 20;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r4,r31,-2016
	ctx.r4.s64 = ctx.r31.s64 + -2016;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lwz r3,220(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r23,216(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r5,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// li r5,1280
	ctx.r5.s64 = 1280;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// std r3,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r3.u64);
	// lfd f4,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r23,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r23.u64);
	// lfd f3,144(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// fcfid f1,f4
	ctx.f1.f64 = double(ctx.f4.s64);
	// frsp f0,f2
	ctx.f0.f64 = double(float(ctx.f2.f64));
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fdivs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// stfs f0,32(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 32, temp.u32);
	// fdivs f0,f31,f13
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f13.f64));
	// stfs f0,36(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 36, temp.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x821802A8;
	sub_820B6770(ctx, base);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// bl 0x8209d220
	ctx.lr = 0x821802B8;
	sub_8209D220(ctx, base);
	// lwz r5,248(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// addi r9,r28,24
	ctx.r9.s64 = ctx.r28.s64 + 24;
	// lwz r4,252(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// li r5,272
	ctx.r5.s64 = 272;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// lfd f12,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r4,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r4.u64);
	// fcfid f8,f12
	ctx.f8.f64 = double(ctx.f12.s64);
	// addi r4,r31,-736
	ctx.r4.s64 = ctx.r31.s64 + -736;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lfd f11,144(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fdivs f0,f31,f9
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f9.f64));
	// stfs f0,44(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 44, temp.u32);
	// fdivs f0,f31,f7
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f7.f64));
	// stfs f0,40(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 40, temp.u32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x8218033C;
	sub_820B6770(ctx, base);
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// bl 0x8209d220
	ctx.lr = 0x8218034C;
	sub_8209D220(ctx, base);
	// addi r10,r28,28
	ctx.r10.s64 = ctx.r28.s64 + 28;
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// addi r4,r31,-192
	ctx.r4.s64 = ctx.r31.s64 + -192;
	// lwz r3,316(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// lwz r23,312(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// li r5,192
	ctx.r5.s64 = 192;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// std r23,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r23.u64);
	// lfd f6,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r3,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r3.u64);
	// lfd f4,152(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f2,f4
	ctx.f2.f64 = double(ctx.f4.s64);
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// fdivs f0,f31,f1
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f1.f64));
	// stfs f0,52(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 52, temp.u32);
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// fdivs f0,f31,f3
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f3.f64));
	// stfs f0,48(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 48, temp.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x821803D0;
	sub_820B6770(ctx, base);
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,28(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// bl 0x8209d220
	ctx.lr = 0x821803E0;
	sub_8209D220(ctx, base);
	// lwz r6,376(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	// lwz r5,380(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// addi r10,r28,32
	ctx.r10.s64 = ctx.r28.s64 + 32;
	// lwz r11,-31312(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + -31312);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r29.u32);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// fcfid f10,f0
	ctx.f10.f64 = double(ctx.f0.s64);
	// li r5,192
	ctx.r5.s64 = 192;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfd f13,144(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f0,f31,f11
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f11.f64));
	// stfs f0,60(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 60, temp.u32);
	// fdivs f0,f31,f9
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f9.f64));
	// stfs f0,56(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 56, temp.u32);
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x820b6770
	ctx.lr = 0x82180464;
	sub_820B6770(ctx, base);
	// addi r5,r1,416
	ctx.r5.s64 = ctx.r1.s64 + 416;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 32);
	// bl 0x8209d220
	ctx.lr = 0x82180474;
	sub_8209D220(ctx, base);
	// lwz r9,440(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 440);
	// lwz r8,444(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	// std r9,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// lfd f8,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// std r8,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r8.u64);
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// lfd f7,144(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// fdivs f0,f31,f4
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f4.f64));
	// stfs f0,68(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 68, temp.u32);
	// fdivs f0,f31,f3
	ctx.f0.f64 = double(float(ctx.f31.f64 / ctx.f3.f64));
	// stfs f0,64(r25)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r25.u32 + 64, temp.u32);
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// lfd f31,-96(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821804B8"))) PPC_WEAK_FUNC(sub_821804B8);
PPC_FUNC_IMPL(__imp__sub_821804B8) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821804e4
	if (ctx.cr6.eq) goto loc_821804E4;
	// bl 0x820a4400
	ctx.lr = 0x821804DC;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_821804E4:
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

__attribute__((alias("__imp__sub_821804F8"))) PPC_WEAK_FUNC(sub_821804F8);
PPC_FUNC_IMPL(__imp__sub_821804F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// clrlwi r8,r4,31
	ctx.r8.u64 = ctx.r4.u32 & 0x1;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,20824
	ctx.r10.s64 = ctx.r10.s64 + 20824;
	// beq cr6,0x82180544
	if (ctx.cr6.eq) goto loc_82180544;
	// lwz r8,-15724(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -15724);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r6,-15720(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -15720);
	// lwz r5,-15716(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -15716);
	// b 0x82180580
	goto loc_82180580;
loc_82180544:
	// rlwinm r8,r4,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82180564
	if (ctx.cr6.eq) goto loc_82180564;
	// lwz r8,-14396(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14396);
	// li r7,12
	ctx.r7.s64 = 12;
	// lwz r6,-14392(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14392);
	// lwz r5,-14388(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -14388);
	// b 0x82180580
	goto loc_82180580;
loc_82180564:
	// rlwinm r8,r4,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82180598
	if (ctx.cr6.eq) goto loc_82180598;
	// lwz r8,-4060(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4060);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r6,-4056(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4056);
	// lwz r5,-4052(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4052);
loc_82180580:
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r11,r1,92
	ctx.r11.s64 = ctx.r1.s64 + 92;
	// stw r7,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// sth r9,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r9.u16);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
loc_82180598:
	// rlwinm r9,r4,0,22,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821805d0
	if (ctx.cr6.eq) goto loc_821805D0;
	// lwz r8,-3764(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3764);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r7,-3760(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3760);
	// lwz r6,-3756(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3756);
	// addi r3,r9,4
	ctx.r3.s64 = ctx.r9.s64 + 4;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// sth r9,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r9.u16);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
loc_821805D0:
	// rlwinm r9,r4,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82180608
	if (ctx.cr6.eq) goto loc_82180608;
	// lwz r8,-12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r7,-8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// lwz r6,-4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r4,r9,8
	ctx.r4.s64 = ctx.r9.s64 + 8;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// sth r9,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r9.u16);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
loc_82180608:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// bl 0x8209b018
	ctx.lr = 0x82180628;
	sub_8209B018(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180640"))) PPC_WEAK_FUNC(sub_82180640);
PPC_FUNC_IMPL(__imp__sub_82180640) {
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
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82089f78
	ctx.lr = 0x82180664;
	sub_82089F78(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x820990e0
	ctx.lr = 0x8218067C;
	sub_820990E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218068C"))) PPC_WEAK_FUNC(sub_8218068C);
PPC_FUNC_IMPL(__imp__sub_8218068C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180690"))) PPC_WEAK_FUNC(sub_82180690);
PPC_FUNC_IMPL(__imp__sub_82180690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lfs f13,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,-31312(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31312);
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x820999a8
	ctx.lr = 0x821806E0;
	sub_820999A8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821806F0"))) PPC_WEAK_FUNC(sub_821806F0);
PPC_FUNC_IMPL(__imp__sub_821806F0) {
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
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82180748
	if (ctx.cr6.eq) goto loc_82180748;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// bl 0x820a4400
	ctx.lr = 0x82180720;
	sub_820A4400(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
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
loc_82180748:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82180764"))) PPC_WEAK_FUNC(sub_82180764);
PPC_FUNC_IMPL(__imp__sub_82180764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180768"))) PPC_WEAK_FUNC(sub_82180768);
PPC_FUNC_IMPL(__imp__sub_82180768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82180770;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lis r8,10280
	ctx.r8.s64 = 673710080;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r8,438
	ctx.r8.u64 = ctx.r8.u64 | 438;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8209d2e0
	ctx.lr = 0x821807A8;
	sub_8209D2E0(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// li r6,24
	ctx.r6.s64 = 24;
	// lfs f0,21768(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// li r5,3
	ctx.r5.s64 = 3;
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r6.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r5,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r5.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180808"))) PPC_WEAK_FUNC(sub_82180808);
PPC_FUNC_IMPL(__imp__sub_82180808) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// li r10,1
	ctx.r10.s64 = 1;
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r8,r10,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r3,r8,r9
	ctx.r3.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r9.u8 & 0x7F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180820"))) PPC_WEAK_FUNC(sub_82180820);
PPC_FUNC_IMPL(__imp__sub_82180820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// rlwinm r10,r3,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r11,-1
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r8,r9,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// rldicr r5,r7,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// subf r6,r10,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r10.s64;
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// srad r3,r5,r4
	temp.u64 = ctx.r4.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r5.s64 < 0) & (((ctx.r5.s64 >> temp.u64) << temp.u64) != ctx.r5.s64);
	ctx.r3.s64 = ctx.r5.s64 >> temp.u64;
	// srd r3,r3,r10
	ctx.r3.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r3.u64 >> (ctx.r10.u8 & 0x7F));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218084C"))) PPC_WEAK_FUNC(sub_8218084C);
PPC_FUNC_IMPL(__imp__sub_8218084C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180850"))) PPC_WEAK_FUNC(sub_82180850);
PPC_FUNC_IMPL(__imp__sub_82180850) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82180858;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	ctx.r27.s64 = 0;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r28,3
	ctx.r28.s64 = 3;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// addi r30,r10,-31672
	ctx.r30.s64 = ctx.r10.s64 + -31672;
	// addi r29,r11,-32136
	ctx.r29.s64 = ctx.r11.s64 + -32136;
loc_82180878:
	// lwzx r11,r31,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821808a8
	if (ctx.cr6.eq) goto loc_821808A8;
	// addi r11,r29,56
	ctx.r11.s64 = ctx.r29.s64 + 56;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwz r10,-36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -36);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x820a4400
	ctx.lr = 0x8218089C;
	sub_820A4400(ctx, base);
	// lwzx r11,r31,r29
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stwx r10,r31,r29
	PPC_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r10.u32);
loc_821808A8:
	// lwzx r11,r31,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// addi r10,r29,56
	ctx.r10.s64 = ctx.r29.s64 + 56;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stwx r27,r31,r10
	PPC_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r27.u32);
	// beq cr6,0x821808e0
	if (ctx.cr6.eq) goto loc_821808E0;
	// addi r11,r30,20
	ctx.r11.s64 = ctx.r30.s64 + 20;
	// lwzx r11,r31,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// addi r11,r30,56
	ctx.r11.s64 = ctx.r30.s64 + 56;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x820a4400
	ctx.lr = 0x821808D4;
	sub_820A4400(ctx, base);
	// lwzx r11,r31,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stwx r10,r31,r30
	PPC_STORE_U32(ctx.r31.u32 + ctx.r30.u32, ctx.r10.u32);
loc_821808E0:
	// addi r11,r30,56
	ctx.r11.s64 = ctx.r30.s64 + 56;
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// stwx r27,r31,r11
	PPC_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r27.u32);
	// addi r31,r31,60
	ctx.r31.s64 = ctx.r31.s64 + 60;
	// bne 0x82180878
	if (!ctx.cr0.eq) goto loc_82180878;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821808FC"))) PPC_WEAK_FUNC(sub_821808FC);
PPC_FUNC_IMPL(__imp__sub_821808FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180900"))) PPC_WEAK_FUNC(sub_82180900);
PPC_FUNC_IMPL(__imp__sub_82180900) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82180908;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r27,r8,-31672
	ctx.r27.s64 = ctx.r8.s64 + -31672;
	// addi r29,r9,-12380
	ctx.r29.s64 = ctx.r9.s64 + -12380;
	// addi r28,r10,-12368
	ctx.r28.s64 = ctx.r10.s64 + -12368;
	// addi r26,r11,-32136
	ctx.r26.s64 = ctx.r11.s64 + -32136;
loc_82180934:
	// add r3,r30,r26
	ctx.r3.u64 = ctx.r30.u64 + ctx.r26.u64;
	// lwzx r5,r31,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// add r11,r31,r28
	ctx.r11.u64 = ctx.r31.u64 + ctx.r28.u64;
	// lwzx r4,r31,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// bl 0x82180768
	ctx.lr = 0x8218094C;
	sub_82180768(ctx, base);
	// add r3,r30,r27
	ctx.r3.u64 = ctx.r30.u64 + ctx.r27.u64;
	// lwzx r5,r31,r28
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r28.u32);
	// lwzx r4,r31,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// bl 0x82180768
	ctx.lr = 0x8218095C;
	sub_82180768(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
	// cmplwi cr6,r31,12
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 12, ctx.xer);
	// blt cr6,0x82180934
	if (ctx.cr6.lt) goto loc_82180934;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180974"))) PPC_WEAK_FUNC(sub_82180974);
PPC_FUNC_IMPL(__imp__sub_82180974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180978"))) PPC_WEAK_FUNC(sub_82180978);
PPC_FUNC_IMPL(__imp__sub_82180978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82180980;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r10,r5,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,-19612(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19612);
	ctx.f0.f64 = double(temp.f32);
	// lwz r31,4(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r9,-31312(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f0,21768(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r7,r6,21768
	ctx.r7.s64 = ctx.r6.s64 + 21768;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// lwz r31,-32160(r8)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32160);
	// lwz r8,152(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// addi r9,r31,4
	ctx.r9.s64 = ctx.r31.s64 + 4;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f13,-4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f11,f9
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f9.f64));
	// lfs f6,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f8,f10
	ctx.f5.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// lfs f4,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f4.f64 = double(temp.f32);
	// fadds f3,f6,f11
	ctx.f3.f64 = double(float(ctx.f6.f64 + ctx.f11.f64));
	// fadds f2,f4,f10
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f10.f64));
	// stfs f7,80(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f5,84(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// stfs f3,92(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x8209d800
	ctx.lr = 0x82180A88;
	sub_8209D800(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8207dac0
	ctx.lr = 0x82180A98;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x82180AA8;
	sub_8209D7F0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180AB0"))) PPC_WEAK_FUNC(sub_82180AB0);
PPC_FUNC_IMPL(__imp__sub_82180AB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82180AB8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82180850
	ctx.lr = 0x82180AC4;
	sub_82180850(ctx, base);
	// addi r31,r31,1484
	ctx.r31.s64 = ctx.r31.s64 + 1484;
	// li r30,91
	ctx.r30.s64 = 91;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82180AD0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82180af8
	if (ctx.cr6.eq) goto loc_82180AF8;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// bl 0x820a4400
	ctx.lr = 0x82180AEC;
	sub_820A4400(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_82180AF8:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stwu r29,60(r31)
	ea = 60 + ctx.r31.u32;
	PPC_STORE_U32(ea, ctx.r29.u32);
	ctx.r31.u32 = ea;
	// bne 0x82180ad0
	if (!ctx.cr0.eq) goto loc_82180AD0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180B0C"))) PPC_WEAK_FUNC(sub_82180B0C);
PPC_FUNC_IMPL(__imp__sub_82180B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180B10"))) PPC_WEAK_FUNC(sub_82180B10);
PPC_FUNC_IMPL(__imp__sub_82180B10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82180B18;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// addi r7,r3,7180
	ctx.r7.s64 = ctx.r3.s64 + 7180;
	// lfs f31,21768(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// addi r8,r3,6944
	ctx.r8.s64 = ctx.r3.s64 + 6944;
	// stfs f31,0(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// addi r10,r3,7100
	ctx.r10.s64 = ctx.r3.s64 + 7100;
	// stfs f31,8(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f0,-21836(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r11,r11,1408
	ctx.r11.s64 = ctx.r11.s64 + 1408;
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stfs f0,20(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stw r11,-32156(r5)
	PPC_STORE_U32(ctx.r5.u32 + -32156, ctx.r11.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// addi r9,r11,88
	ctx.r9.s64 = ctx.r11.s64 + 88;
	// stfs f31,28(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// ld r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// stw r29,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r29.u32);
	// std r4,6960(r3)
	PPC_STORE_U64(ctx.r3.u32 + 6960, ctx.r4.u64);
	// ld r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// std r3,6968(r31)
	PPC_STORE_U64(ctx.r31.u32 + 6968, ctx.r3.u64);
	// lfs f0,28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 32, temp.u32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r6,r11,-2064
	ctx.r6.s64 = ctx.r11.s64 + -2064;
	// lfs f0,104(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,100(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
loc_82180BB0:
	// stfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f0,8(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stfs f31,12(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// stfsu f31,16(r10)
	temp.f32 = float(ctx.f31.f64);
	ea = 16 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// lfs f12,40(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,40(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 40, temp.u32);
	// ldu r11,32(r9)
	ea = 32 + ctx.r9.u32;
	ctx.r11.u64 = PPC_LOAD_U64(ea);
	ctx.r9.u32 = ea;
	// stdu r11,32(r8)
	ea = 32 + ctx.r8.u32;
	PPC_STORE_U64(ea, ctx.r11.u64);
	ctx.r8.u32 = ea;
	// stfs f31,-12(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + -12, temp.u32);
	// stwu r29,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r29.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x82180bb0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82180BB0;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82099388
	ctx.lr = 0x82180BF4;
	sub_82099388(ctx, base);
	// lis r26,-32224
	ctx.r26.s64 = -2111832064;
	// stw r3,-31340(r26)
	PPC_STORE_U32(ctx.r26.u32 + -31340, ctx.r3.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82180c14
	if (ctx.cr6.eq) goto loc_82180C14;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r5,-31872(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31872);
	// b 0x82180c1c
	goto loc_82180C1C;
loc_82180C14:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r5,-32204(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + -32204);
loc_82180C1C:
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x82180C30;
	sub_8209A100(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x820a19f0
	ctx.lr = 0x82180C5C;
	sub_820A19F0(ctx, base);
	// stw r29,6948(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6948, ctx.r29.u32);
	// addi r30,r31,1488
	ctx.r30.s64 = ctx.r31.s64 + 1488;
	// stw r29,6952(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6952, ctx.r29.u32);
	// li r27,91
	ctx.r27.s64 = 91;
loc_82180C6C:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82180c88
	if (ctx.cr6.eq) goto loc_82180C88;
	// li r5,240
	ctx.r5.s64 = 240;
	// li r4,320
	ctx.r4.s64 = 320;
	// b 0x82180c90
	goto loc_82180C90;
loc_82180C88:
	// li r5,480
	ctx.r5.s64 = 480;
	// li r4,640
	ctx.r4.s64 = 640;
loc_82180C90:
	// bl 0x82180768
	ctx.lr = 0x82180C94;
	sub_82180768(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r6,56(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r29.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x820a2280
	ctx.lr = 0x82180CCC;
	sub_820A2280(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,60
	ctx.r30.s64 = ctx.r30.s64 + 60;
	// bne 0x82180c6c
	if (!ctx.cr0.eq) goto loc_82180C6C;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,-31340(r26)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31340);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209a100
	ctx.lr = 0x82180CF0;
	sub_8209A100(ctx, base);
	// lwz r3,-31340(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31340);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82180d04
	if (ctx.cr6.eq) goto loc_82180D04;
	// bl 0x820a4400
	ctx.lr = 0x82180D00;
	sub_820A4400(ctx, base);
	// stw r29,-31340(r26)
	PPC_STORE_U32(ctx.r26.u32 + -31340, ctx.r29.u32);
loc_82180D04:
	// bl 0x82180900
	ctx.lr = 0x82180D08;
	sub_82180900(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180D18"))) PPC_WEAK_FUNC(sub_82180D18);
PPC_FUNC_IMPL(__imp__sub_82180D18) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82180D20;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82180d44
	if (ctx.cr6.eq) goto loc_82180D44;
	// lwz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x82180d48
	if (!ctx.cr6.eq) goto loc_82180D48;
loc_82180D44:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82180D48:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82180df0
	if (ctx.cr6.eq) goto loc_82180DF0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82180da0
	if (ctx.cr6.eq) goto loc_82180DA0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8209ad40
	ctx.lr = 0x82180D6C;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x82180D80;
	sub_8209AB80(ctx, base);
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
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209d660
	ctx.lr = 0x82180DA0;
	sub_8209D660(ctx, base);
loc_82180DA0:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r30,r10,-31952
	ctx.r30.s64 = ctx.r10.s64 + -31952;
	// addi r29,r11,-31488
	ctx.r29.s64 = ctx.r11.s64 + -31488;
loc_82180DB4:
	// lwzx r3,r31,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// bl 0x820a4400
	ctx.lr = 0x82180DBC;
	sub_820A4400(ctx, base);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// bl 0x820a4400
	ctx.lr = 0x82180DC4;
	sub_820A4400(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r31,80
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 80, ctx.xer);
	// blt cr6,0x82180db4
	if (ctx.cr6.lt) goto loc_82180DB4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r31,9
	ctx.r31.s64 = 9;
	// addi r11,r11,-32196
	ctx.r11.s64 = ctx.r11.s64 + -32196;
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
loc_82180DE0:
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = PPC_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x820a4400
	ctx.lr = 0x82180DE8;
	sub_820A4400(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82180de0
	if (!ctx.cr0.eq) goto loc_82180DE0;
loc_82180DF0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180DF8"))) PPC_WEAK_FUNC(sub_82180DF8);
PPC_FUNC_IMPL(__imp__sub_82180DF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82180E00;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// lwz r11,-32208(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -32208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82180e50
	if (ctx.cr6.eq) goto loc_82180E50;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r10,r10,-31864
	ctx.r10.s64 = ctx.r10.s64 + -31864;
	// addi r31,r10,8
	ctx.r31.s64 = ctx.r10.s64 + 8;
loc_82180E28:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82180e40
	if (ctx.cr6.eq) goto loc_82180E40;
	// bl 0x820a4400
	ctx.lr = 0x82180E38;
	sub_820A4400(ctx, base);
	// lwz r11,-32208(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -32208);
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
loc_82180E40:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82180e28
	if (ctx.cr6.lt) goto loc_82180E28;
loc_82180E50:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stw r28,-32208(r30)
	PPC_STORE_U32(ctx.r30.u32 + -32208, ctx.r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82180E60"))) PPC_WEAK_FUNC(sub_82180E60);
PPC_FUNC_IMPL(__imp__sub_82180E60) {
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
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r8,r10,-31864
	ctx.r8.s64 = ctx.r10.s64 + -31864;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,-32208(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -32208);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82180eb0
	if (ctx.cr6.eq) goto loc_82180EB0;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_82180E94:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r6,r4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82180ee8
	if (ctx.cr6.eq) goto loc_82180EE8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,12
	ctx.r9.s64 = ctx.r9.s64 + 12;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82180e94
	if (ctx.cr6.lt) goto loc_82180E94;
loc_82180EB0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,-32208(r7)
	PPC_STORE_U32(ctx.r7.u32 + -32208, ctx.r10.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r8
	ctx.r31.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821804f8
	ctx.lr = 0x82180ED0;
	sub_821804F8(ctx, base);
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
loc_82180EE8:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
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

__attribute__((alias("__imp__sub_82180F0C"))) PPC_WEAK_FUNC(sub_82180F0C);
PPC_FUNC_IMPL(__imp__sub_82180F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180F10"))) PPC_WEAK_FUNC(sub_82180F10);
PPC_FUNC_IMPL(__imp__sub_82180F10) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82180f5c
	if (ctx.cr6.eq) goto loc_82180F5C;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82180690
	ctx.lr = 0x82180F3C;
	sub_82180690(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82089f78
	ctx.lr = 0x82180F54;
	sub_82089F78(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// b 0x82180fbc
	goto loc_82180FBC;
loc_82180F5C:
	// lis r31,-32225
	ctx.r31.s64 = -2111897600;
	// lis r30,-32225
	ctx.r30.s64 = -2111897600;
	// lfs f0,-14012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + -14012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-14016(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -14016);
	ctx.f13.f64 = double(temp.f32);
	// fctidz f0,f0
	ctx.f0.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fctidz f13,f13
	ctx.f13.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82180690
	ctx.lr = 0x82180F88;
	sub_82180690(ctx, base);
	// lfs f0,-14012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + -14012);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f13,-14016(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -14016);
	ctx.f13.f64 = double(temp.f32);
	// fctidz f12,f0
	ctx.f12.s64 = (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fctidz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfd f12,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f12.u64);
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82089f78
	ctx.lr = 0x82180FB8;
	sub_82089F78(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
loc_82180FBC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x820990e0
	ctx.lr = 0x82180FD0;
	sub_820990E0(ctx, base);
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

__attribute__((alias("__imp__sub_82180FE8"))) PPC_WEAK_FUNC(sub_82180FE8);
PPC_FUNC_IMPL(__imp__sub_82180FE8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,-31312(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31312);
	// clrldi r8,r10,32
	ctx.r8.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldicr r7,r9,63,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r6,r7,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r7.u64 >> (ctx.r8.u8 & 0x7F));
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x8209d660
	sub_8209D660(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82181018"))) PPC_WEAK_FUNC(sub_82181018);
PPC_FUNC_IMPL(__imp__sub_82181018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addi r10,r4,376
	ctx.r10.s64 = ctx.r4.s64 + 376;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r8,r4,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// subf r6,r8,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r8.s64;
	// stfsx f0,r9,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, temp.u32);
	// rldicr r5,r7,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stfs f13,6020(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6020, temp.u32);
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// stfs f12,6024(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6024, temp.u32);
	// stfs f11,6028(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 6028, temp.u32);
	// srad r11,r5,r4
	temp.u64 = ctx.r4.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r5.s64 < 0) & (((ctx.r5.s64 >> temp.u64) << temp.u64) != ctx.r5.s64);
	ctx.r11.s64 = ctx.r5.s64 >> temp.u64;
	// srd r10,r11,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r8.u8 & 0x7F));
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// std r8,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181074"))) PPC_WEAK_FUNC(sub_82181074);
PPC_FUNC_IMPL(__imp__sub_82181074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181078"))) PPC_WEAK_FUNC(sub_82181078);
PPC_FUNC_IMPL(__imp__sub_82181078) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addi r10,r4,120
	ctx.r10.s64 = ctx.r4.s64 + 120;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r8,r4,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// subf r6,r8,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r8.s64;
	// stfsx f0,r9,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, temp.u32);
	// rldicr r5,r7,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// stfs f13,1924(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1924, temp.u32);
	// clrldi r4,r6,32
	ctx.r4.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// stfs f12,1928(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1928, temp.u32);
	// stfs f11,1932(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1932, temp.u32);
	// srad r11,r5,r4
	temp.u64 = ctx.r4.u64 & 0x7F;
	if (temp.u64 > 0x3F) temp.u64 = 0x3F;
	ctx.xer.ca = (ctx.r5.s64 < 0) & (((ctx.r5.s64 >> temp.u64) << temp.u64) != ctx.r5.s64);
	ctx.r11.s64 = ctx.r5.s64 >> temp.u64;
	// srd r10,r11,r8
	ctx.r10.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r8.u8 & 0x7F));
	// ld r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821810D4"))) PPC_WEAK_FUNC(sub_821810D4);
PPC_FUNC_IMPL(__imp__sub_821810D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821810D8"))) PPC_WEAK_FUNC(sub_821810D8);
PPC_FUNC_IMPL(__imp__sub_821810D8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// cntlzw r10,r5
	ctx.r10.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r10,r11,1156
	ctx.r10.s64 = ctx.r11.s64 + 1156;
	// clrldi r5,r8,32
	ctx.r5.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// rldicr r4,r7,63,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// lwz r10,1156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1156);
	// srd r9,r4,r5
	ctx.r9.u64 = ctx.r5.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (ctx.r5.u8 & 0x7F));
	// rlwimi r10,r6,11,20,20
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r6.u32, 11) & 0x800) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r10,1156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1156, ctx.r10.u32);
	// ld r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// std r7,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r7.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181124"))) PPC_WEAK_FUNC(sub_82181124);
PPC_FUNC_IMPL(__imp__sub_82181124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181128"))) PPC_WEAK_FUNC(sub_82181128);
PPC_FUNC_IMPL(__imp__sub_82181128) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rldicr r6,r8,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r10,r11,1172
	ctx.r10.s64 = ctx.r11.s64 + 1172;
	// srd r4,r6,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// lwz r10,1172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1172);
	// rlwimi r10,r5,2,29,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 2) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r10,1172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1172, ctx.r10.u32);
	// ld r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 | ctx.r9.u64;
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218116C"))) PPC_WEAK_FUNC(sub_8218116C);
PPC_FUNC_IMPL(__imp__sub_8218116C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181170"))) PPC_WEAK_FUNC(sub_82181170);
PPC_FUNC_IMPL(__imp__sub_82181170) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rldicr r6,r8,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r10,r11,1168
	ctx.r10.s64 = ctx.r11.s64 + 1168;
	// srd r4,r6,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// lwz r10,1168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1168);
	// rlwimi r10,r5,27,0,4
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 27) & 0xF8000000) | (ctx.r10.u64 & 0xFFFFFFFF07FFFFFF);
	// stw r10,1168(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1168, ctx.r10.u32);
	// ld r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 | ctx.r9.u64;
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821811B4"))) PPC_WEAK_FUNC(sub_821811B4);
PPC_FUNC_IMPL(__imp__sub_821811B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821811B8"))) PPC_WEAK_FUNC(sub_821811B8);
PPC_FUNC_IMPL(__imp__sub_821811B8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rldicr r6,r8,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r10,r11,1168
	ctx.r10.s64 = ctx.r11.s64 + 1168;
	// srd r4,r6,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// lwz r10,1168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1168);
	// rlwimi r10,r5,22,5,9
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 22) & 0x7C00000) | (ctx.r10.u64 & 0xFFFFFFFFF83FFFFF);
	// stw r10,1168(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1168, ctx.r10.u32);
	// ld r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 | ctx.r9.u64;
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821811FC"))) PPC_WEAK_FUNC(sub_821811FC);
PPC_FUNC_IMPL(__imp__sub_821811FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181200"))) PPC_WEAK_FUNC(sub_82181200);
PPC_FUNC_IMPL(__imp__sub_82181200) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rldicr r6,r8,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r10,r11,1172
	ctx.r10.s64 = ctx.r11.s64 + 1172;
	// srd r4,r6,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// lwz r10,1172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1172);
	// rlwimi r10,r5,3,27,28
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 3) & 0x18) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r10,1172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1172, ctx.r10.u32);
	// ld r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 | ctx.r9.u64;
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181244"))) PPC_WEAK_FUNC(sub_82181244);
PPC_FUNC_IMPL(__imp__sub_82181244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181248"))) PPC_WEAK_FUNC(sub_82181248);
PPC_FUNC_IMPL(__imp__sub_82181248) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addic r10,r5,-1
	ctx.xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// subfe r7,r10,r5
	temp.u8 = (~ctx.r10.u32 + ctx.r5.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r10.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// rldicr r5,r8,63,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r10,r11,1172
	ctx.r10.s64 = ctx.r11.s64 + 1172;
	// lwz r4,1172(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1172);
	// srd r10,r5,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r6.u8 & 0x7F));
	// rlwimi r7,r4,0,0,29
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFC) | (ctx.r7.u64 & 0xFFFFFFFF00000003);
	// stw r7,1172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1172, ctx.r7.u32);
	// ld r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181294"))) PPC_WEAK_FUNC(sub_82181294);
PPC_FUNC_IMPL(__imp__sub_82181294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181298"))) PPC_WEAK_FUNC(sub_82181298);
PPC_FUNC_IMPL(__imp__sub_82181298) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// clrldi r7,r10,32
	ctx.r7.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rldicr r6,r8,63,63
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// addi r10,r11,1164
	ctx.r10.s64 = ctx.r11.s64 + 1164;
	// srd r4,r6,r7
	ctx.r4.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r6.u64 >> (ctx.r7.u8 & 0x7F));
	// lwz r10,1164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1164);
	// rlwimi r10,r5,23,7,8
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 23) & 0x1800000) | (ctx.r10.u64 & 0xFFFFFFFFFE7FFFFF);
	// stw r10,1164(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1164, ctx.r10.u32);
	// ld r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r8,r4,r9
	ctx.r8.u64 = ctx.r4.u64 | ctx.r9.u64;
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821812DC"))) PPC_WEAK_FUNC(sub_821812DC);
PPC_FUNC_IMPL(__imp__sub_821812DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821812E0"))) PPC_WEAK_FUNC(sub_821812E0);
PPC_FUNC_IMPL(__imp__sub_821812E0) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rldicr r4,r7,63,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r10,r4,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (ctx.r6.u8 & 0x7F));
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,16,13,15
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 16) & 0x70000) | (ctx.r9.u64 & 0xFFFFFFFFFFF8FFFF);
	// stwx r9,r11,r3
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// ld r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// std r7,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r7.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181320"))) PPC_WEAK_FUNC(sub_82181320);
PPC_FUNC_IMPL(__imp__sub_82181320) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rldicr r4,r7,63,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r10,r4,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (ctx.r6.u8 & 0x7F));
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,13,16,18
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 13) & 0xE000) | (ctx.r9.u64 & 0xFFFFFFFFFFFF1FFF);
	// stwx r9,r11,r3
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// ld r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// std r7,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r7.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181360"))) PPC_WEAK_FUNC(sub_82181360);
PPC_FUNC_IMPL(__imp__sub_82181360) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rldicr r4,r7,63,63
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// srd r10,r4,r6
	ctx.r10.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (ctx.r6.u8 & 0x7F));
	// lwzx r9,r11,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// rlwimi r9,r5,10,19,21
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r5.u32, 10) & 0x1C00) | (ctx.r9.u64 & 0xFFFFFFFFFFFFE3FF);
	// stwx r9,r11,r3
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, ctx.r9.u32);
	// ld r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// std r7,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r7.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821813A0"))) PPC_WEAK_FUNC(sub_821813A0);
PPC_FUNC_IMPL(__imp__sub_821813A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821813A8;
	__savegprlr_26(ctx, base);
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// add r30,r11,r3
	ctx.r30.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r27,r11,21768
	ctx.r27.s64 = ctx.r11.s64 + 21768;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r31,r1,108
	ctx.r31.s64 = ctx.r1.s64 + 108;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lis r26,-32252
	ctx.r26.s64 = -2113667072;
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lfs f0,-4(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// lfs f31,132(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	ctx.f31.f64 = double(temp.f32);
loc_82181404:
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// fmuls f30,f12,f31
	ctx.f30.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8207af40
	ctx.lr = 0x8218143C;
	sub_8207AF40(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8207ae60
	ctx.lr = 0x82181448;
	sub_8207AE60(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,0(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// lfs f0,-19612(r26)
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + -19612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f8,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// cmplwi cr6,r29,6
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 6, ctx.xer);
	// lfs f7,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f13,0(r27)
	temp.u32 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmuls f5,f10,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmsubs f4,f10,f29,f6
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f29.f64 - ctx.f6.f64));
	// fmadds f3,f9,f29,f5
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f29.f64 + ctx.f5.f64));
	// fmuls f2,f4,f0
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// fmuls f1,f3,f0
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fadds f0,f8,f2
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f2.f64));
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fadds f12,f7,f1
	ctx.f12.f64 = double(float(ctx.f7.f64 + ctx.f1.f64));
	// stfs f12,4(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// addi r31,r31,12
	ctx.r31.s64 = ctx.r31.s64 + 12;
	// blt cr6,0x82181404
	if (ctx.cr6.lt) goto loc_82181404;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r31,-32160(r10)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32160);
	// addi r10,r31,4
	ctx.r10.s64 = ctx.r31.s64 + 4;
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x821814CC;
	sub_8209D800(ctx, base);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// rlwinm r7,r8,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r8,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r8.s64;
	// bl 0x8207dac0
	ctx.lr = 0x821814E0;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x821814F0;
	sub_8209D7F0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_82181504"))) PPC_WEAK_FUNC(sub_82181504);
PPC_FUNC_IMPL(__imp__sub_82181504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181508"))) PPC_WEAK_FUNC(sub_82181508);
PPC_FUNC_IMPL(__imp__sub_82181508) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82181510;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x82080360
	ctx.lr = 0x82181518;
	__savefpr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r30,r11,-2064
	ctx.r30.s64 = ctx.r11.s64 + -2064;
	// addi r29,r10,-21836
	ctx.r29.s64 = ctx.r10.s64 + -21836;
	// lwz r31,-31336(r9)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31336);
	// lfs f0,-21836(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,136(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f11,0(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// ble cr6,0x8218156c
	if (!ctx.cr6.gt) goto loc_8218156C;
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,140(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f11,8(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// ble cr6,0x8218156c
	if (!ctx.cr6.gt) goto loc_8218156C;
	// stfs f0,8(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
loc_8218156C:
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// lwz r9,-32156(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// lfs f10,6960(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6960);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,6964(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6964);
	ctx.f12.f64 = double(temp.f32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// lfs f7,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// lfs f8,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f5,f8,f12
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fsubs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// lfs f28,144(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 144);
	ctx.f28.f64 = double(temp.f32);
	// fmuls f3,f5,f28
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f28.f64));
	// lfs f0,3952(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 3952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,148(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f4,f6,f28
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f28.f64));
	// fadds f1,f11,f3
	ctx.f1.f64 = double(float(ctx.f11.f64 + ctx.f3.f64));
	// stfs f1,6964(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6964, temp.u32);
	// fadds f2,f4,f10
	ctx.f2.f64 = double(float(ctx.f4.f64 + ctx.f10.f64));
	// stfs f2,6960(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6960, temp.u32);
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x82181600
	if (!ctx.cr6.gt) goto loc_82181600;
loc_821815E0:
	// lfs f11,32(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// stfs f10,32(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 32, temp.u32);
	// lfs f8,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// fcmpu cr6,f7,f0
	ctx.cr6.compare(ctx.f7.f64, ctx.f0.f64);
	// bgt cr6,0x821815e0
	if (ctx.cr6.gt) goto loc_821815E0;
loc_82181600:
	// lfs f0,32(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f0,152(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x82181634
	if (!ctx.cr6.lt) goto loc_82181634;
loc_82181614:
	// lfs f11,32(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,32(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 32, temp.u32);
	// lfs f8,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// fcmpu cr6,f7,f0
	ctx.cr6.compare(ctx.f7.f64, ctx.f0.f64);
	// blt cr6,0x82181614
	if (ctx.cr6.lt) goto loc_82181614;
loc_82181634:
	// lfs f12,32(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// ld r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwz r11,60(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// lfs f0,156(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// fnmsubs f10,f11,f0,f12
	ctx.f10.f64 = double(float(-(ctx.f11.f64 * ctx.f0.f64 - ctx.f12.f64)));
	// stfs f10,32(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 32, temp.u32);
	// blt cr6,0x82181754
	if (ctx.cr6.lt) goto loc_82181754;
	// beq cr6,0x82181674
	if (ctx.cr6.eq) goto loc_82181674;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82181768
	if (!ctx.cr6.lt) goto loc_82181768;
	// lfs f10,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// b 0x82181770
	goto loc_82181770;
loc_82181674:
	// lfs f0,164(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f31,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// lfs f12,160(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3880(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 3880);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f29,f31,f12
	ctx.f29.f64 = double(float(ctx.f31.f64 * ctx.f12.f64));
	// lfs f30,108(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 108);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x821816b4
	if (!ctx.cr6.gt) goto loc_821816B4;
	// lfd f2,64(r30)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r30.u32 + 64);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x8207b020
	ctx.lr = 0x821816A4;
	sub_8207B020(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f0,3880(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 3880);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// b 0x821816d4
	goto loc_821816D4;
loc_821816B4:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x821816d4
	if (!ctx.cr6.lt) goto loc_821816D4;
	// lfd f2,64(r30)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r30.u32 + 64);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// bl 0x8207b020
	ctx.lr = 0x821816C8;
	sub_8207B020(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f0,3880(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 3880);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
loc_821816D4:
	// fnabs f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f0.u64 | 0x8000000000000000;
	// lfs f13,168(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x821816ec
	if (!ctx.cr6.gt) goto loc_821816EC;
	// fsubs f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f0.f64));
loc_821816EC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-32200(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -32200);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82181704
	if (ctx.cr6.eq) goto loc_82181704;
	// lfs f13,172(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82181708
	goto loc_82181708;
loc_82181704:
	// lfs f13,176(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
loc_82181708:
	// fmr f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f0.f64;
	// lfs f0,4824(r29)
	temp.u32 = PPC_LOAD_U32(ctx.r29.u32 + 4824);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f27,f13,f0
	ctx.f27.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8207af40
	ctx.lr = 0x8218171C;
	sub_8207AF40(ctx, base);
	// frsp f26,f1
	ctx.fpscr.disableFlushMode();
	ctx.f26.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8207ae60
	ctx.lr = 0x82181728;
	sub_8207AE60(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lwz r9,-32156(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + -32156);
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f27,f13
	ctx.f12.f64 = double(float(ctx.f27.f64 * ctx.f13.f64));
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmsubs f10,f26,f0,f12
	ctx.f10.f64 = double(float(ctx.f26.f64 * ctx.f0.f64 - ctx.f12.f64));
	// fmadds f9,f27,f26,f11
	ctx.f9.f64 = double(float(ctx.f27.f64 * ctx.f26.f64 + ctx.f11.f64));
	// fadds f10,f10,f31
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f31.f64));
	// fadds f9,f9,f29
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f29.f64));
	// b 0x82181770
	goto loc_82181770;
loc_82181754:
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,160(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// b 0x82181770
	goto loc_82181770;
loc_82181768:
	// lfs f9,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
loc_82181770:
	// lfs f13,6972(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6972);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,6976
	ctx.r11.s64 = ctx.r31.s64 + 6976;
	// fsubs f11,f9,f13
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f0,6968(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6968);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f10,f0
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f0.f64));
	// addi r10,r9,120
	ctx.r10.s64 = ctx.r9.s64 + 120;
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// lfs f0,180(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 180);
	ctx.f0.f64 = double(temp.f32);
	// fmr f7,f13
	ctx.f7.f64 = ctx.f13.f64;
	// li r8,1
	ctx.r8.s64 = 1;
	// fmuls f5,f11,f28
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f28.f64));
	// fmuls f6,f12,f28
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f28.f64));
	// fadds f3,f13,f5
	ctx.f3.f64 = double(float(ctx.f13.f64 + ctx.f5.f64));
	// stfs f3,6972(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6972, temp.u32);
	// fadds f4,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 + ctx.f6.f64));
	// stfs f4,6968(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6968, temp.u32);
	// lfs f12,128(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,6984(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6984);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f8,f11,f28,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f28.f64 + ctx.f13.f64));
	// stfs f8,6984(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6984, temp.u32);
	// lfs f1,6976(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6976);
	ctx.f1.f64 = double(temp.f32);
	// lfs f5,120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// lfs f2,6980(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6980);
	ctx.f2.f64 = double(temp.f32);
	// lfs f7,124(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f3,f7,f2
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f2.f64));
	// fsubs f4,f5,f1
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f1.f64));
	// fmuls f12,f3,f28
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f28.f64));
	// fmr f6,f8
	ctx.f6.f64 = ctx.f8.f64;
	// fmuls f13,f4,f28
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f28.f64));
	// fadds f12,f2,f12
	ctx.f12.f64 = double(float(ctx.f2.f64 + ctx.f12.f64));
	// stfs f12,6980(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6980, temp.u32);
	// fadds f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// stfs f13,6976(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6976, temp.u32);
	// lfs f11,128(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f8,f11
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f11.f64));
	// fabs f7,f8
	ctx.f7.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fcmpu cr6,f7,f0
	ctx.cr6.compare(ctx.f7.f64, ctx.f0.f64);
	// bge cr6,0x82181818
	if (!ctx.cr6.lt) goto loc_82181818;
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,8(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// b 0x8218181c
	goto loc_8218181C;
loc_82181818:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8218181C:
	// lfs f11,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fabs f8,f13
	ctx.f8.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x82181838
	if (!ctx.cr6.lt) goto loc_82181838;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8218183c
	goto loc_8218183C;
loc_82181838:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8218183C:
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x82181858
	if (!ctx.cr6.lt) goto loc_82181858;
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// b 0x8218185c
	goto loc_8218185C;
loc_82181858:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8218185C:
	// lfs f13,7016(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7016);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,7008
	ctx.r11.s64 = ctx.r31.s64 + 7008;
	// lfs f12,160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r9,152
	ctx.r10.s64 = ctx.r9.s64 + 152;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f8,f11,f28,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f28.f64 + ctx.f13.f64));
	// stfs f8,7016(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7016, temp.u32);
	// lfs f3,156(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,7012(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7012);
	ctx.f2.f64 = double(temp.f32);
	// lfs f6,152(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,7008(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7008);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fmuls f13,f4,f28
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f28.f64));
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// fmuls f12,f1,f28
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// fadds f11,f13,f7
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f7.f64));
	// stfs f11,7008(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7008, temp.u32);
	// lfs f8,7012(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7012);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// stfs f7,7012(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7012, temp.u32);
	// lfs f13,160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,7016(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7016);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// bge cr6,0x821818d0
	if (!ctx.cr6.lt) goto loc_821818D0;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// b 0x821818d4
	goto loc_821818D4;
loc_821818D0:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821818D4:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x821818f4
	if (!ctx.cr6.lt) goto loc_821818F4;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x821818f8
	goto loc_821818F8;
loc_821818F4:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821818F8:
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x82181918
	if (!ctx.cr6.lt) goto loc_82181918;
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// b 0x8218191c
	goto loc_8218191C;
loc_82181918:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8218191C:
	// lfs f13,7048(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7048);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,7040
	ctx.r11.s64 = ctx.r31.s64 + 7040;
	// lfs f12,192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r9,184
	ctx.r10.s64 = ctx.r9.s64 + 184;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f8,f11,f28,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f28.f64 + ctx.f13.f64));
	// stfs f8,7048(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7048, temp.u32);
	// lfs f6,7040(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7040);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,184(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	ctx.f7.f64 = double(temp.f32);
	// fmr f4,f6
	ctx.f4.f64 = ctx.f6.f64;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// lfs f3,188(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,7044(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7044);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fmuls f13,f5,f28
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f28.f64));
	// fmuls f12,f1,f28
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// fadds f11,f13,f6
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
	// stfs f11,7040(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7040, temp.u32);
	// lfs f8,7044(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7044);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// stfs f7,7044(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7044, temp.u32);
	// lfs f6,7048(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7048);
	ctx.f6.f64 = double(temp.f32);
	// lfs f13,192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// bge cr6,0x82181990
	if (!ctx.cr6.lt) goto loc_82181990;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// b 0x82181994
	goto loc_82181994;
loc_82181990:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181994:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x821819b4
	if (!ctx.cr6.lt) goto loc_821819B4;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x821819b8
	goto loc_821819B8;
loc_821819B4:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821819B8:
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x821819d8
	if (!ctx.cr6.lt) goto loc_821819D8;
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// b 0x821819dc
	goto loc_821819DC;
loc_821819D8:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821819DC:
	// lfs f13,7080(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7080);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,7072
	ctx.r11.s64 = ctx.r31.s64 + 7072;
	// lfs f12,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r9,216
	ctx.r10.s64 = ctx.r9.s64 + 216;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f8,f11,f28,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f28.f64 + ctx.f13.f64));
	// stfs f8,7080(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7080, temp.u32);
	// lfs f6,7072(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7072);
	ctx.f6.f64 = double(temp.f32);
	// lfs f7,216(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 216);
	ctx.f7.f64 = double(temp.f32);
	// fmr f4,f6
	ctx.f4.f64 = ctx.f6.f64;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// lfs f3,220(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 220);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,7076(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7076);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fmuls f13,f5,f28
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f28.f64));
	// fmuls f12,f1,f28
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f28.f64));
	// fadds f11,f13,f6
	ctx.f11.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
	// stfs f11,7072(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7072, temp.u32);
	// lfs f8,7076(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7076);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// stfs f7,7076(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r31.u32 + 7076, temp.u32);
	// lfs f6,7080(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 7080);
	ctx.f6.f64 = double(temp.f32);
	// lfs f13,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// bge cr6,0x82181a50
	if (!ctx.cr6.lt) goto loc_82181A50;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// b 0x82181a54
	goto loc_82181A54;
loc_82181A50:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181A54:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x82181a74
	if (!ctx.cr6.lt) goto loc_82181A74;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x82181a78
	goto loc_82181A78;
loc_82181A74:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181A78:
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x82181a98
	if (!ctx.cr6.lt) goto loc_82181A98;
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// b 0x82181a9c
	goto loc_82181A9C;
loc_82181A98:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181A9C:
	// lfs f13,28(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f0
	ctx.cr6.compare(ctx.f8.f64, ctx.f0.f64);
	// bge cr6,0x82181abc
	if (!ctx.cr6.lt) goto loc_82181ABC;
	// stfs f13,32(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 32, temp.u32);
	// b 0x82181ac0
	goto loc_82181AC0;
loc_82181ABC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181AC0:
	// lfs f13,6968(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6968);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f10
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x82181adc
	if (!ctx.cr6.lt) goto loc_82181ADC;
	// stfs f10,6968(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6968, temp.u32);
	// b 0x82181ae0
	goto loc_82181AE0;
loc_82181ADC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181AE0:
	// lfs f13,6972(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6972);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f9
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fabs f11,f12
	ctx.f11.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x82181afc
	if (!ctx.cr6.lt) goto loc_82181AFC;
	// stfs f9,6972(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6972, temp.u32);
	// b 0x82181b00
	goto loc_82181B00;
loc_82181AFC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181B00:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6960(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6960);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// bge cr6,0x82181b20
	if (!ctx.cr6.lt) goto loc_82181B20;
	// stfs f13,6960(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6960, temp.u32);
	// b 0x82181b24
	goto loc_82181B24;
loc_82181B20:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181B24:
	// lfs f13,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6964(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 6964);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// bge cr6,0x82181b44
	if (!ctx.cr6.lt) goto loc_82181B44;
	// stfs f13,6964(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 6964, temp.u32);
	// b 0x82181b48
	goto loc_82181B48;
loc_82181B44:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82181B48:
	// subfic r11,r8,0
	ctx.xer.ca = ctx.r8.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r8.s64;
	// subfe r10,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r10,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stw r9,7200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 7200, ctx.r9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x820803ac
	ctx.lr = 0x82181B68;
	__restfpr_26(ctx, base);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82181B6C"))) PPC_WEAK_FUNC(sub_82181B6C);
PPC_FUNC_IMPL(__imp__sub_82181B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181B70"))) PPC_WEAK_FUNC(sub_82181B70);
PPC_FUNC_IMPL(__imp__sub_82181B70) {
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
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r11,-31344(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31344);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82181c4c
	if (ctx.cr6.eq) goto loc_82181C4C;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31344(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31344, ctx.r11.u32);
	// lwz r3,-32204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32204);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181bb4
	if (ctx.cr6.eq) goto loc_82181BB4;
	// bl 0x820a4400
	ctx.lr = 0x82181BAC;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-32204(r31)
	PPC_STORE_U32(ctx.r31.u32 + -32204, ctx.r11.u32);
loc_82181BB4:
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r3,-31872(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31872);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181bd0
	if (ctx.cr6.eq) goto loc_82181BD0;
	// bl 0x820a4400
	ctx.lr = 0x82181BC8;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31872(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31872, ctx.r11.u32);
loc_82181BD0:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r31,r11,-32148
	ctx.r31.s64 = ctx.r11.s64 + -32148;
	// lwz r3,-32148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -32148);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181bf0
	if (ctx.cr6.eq) goto loc_82181BF0;
	// bl 0x820a4400
	ctx.lr = 0x82181BE8;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82181BF0:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181c08
	if (ctx.cr6.eq) goto loc_82181C08;
	// bl 0x820a4400
	ctx.lr = 0x82181C00;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_82181C08:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82181c20
	if (ctx.cr6.eq) goto loc_82181C20;
	// bl 0x820a4400
	ctx.lr = 0x82181C18;
	sub_820A4400(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_82181C20:
	// bl 0x82180d18
	ctx.lr = 0x82181C24;
	sub_82180D18(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-32152(r8)
	PPC_STORE_U32(ctx.r8.u32 + -32152, ctx.r11.u32);
	// stw r10,-32160(r7)
	PPC_STORE_U32(ctx.r7.u32 + -32160, ctx.r10.u32);
	// stw r9,-31956(r6)
	PPC_STORE_U32(ctx.r6.u32 + -31956, ctx.r9.u32);
	// bl 0x82180df8
	ctx.lr = 0x82181C4C;
	sub_82180DF8(ctx, base);
loc_82181C4C:
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

__attribute__((alias("__imp__sub_82181C60"))) PPC_WEAK_FUNC(sub_82181C60);
PPC_FUNC_IMPL(__imp__sub_82181C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x82181C68;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r11,-31344(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31344);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82181e08
	if (!ctx.cr6.eq) goto loc_82181E08;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stw r11,-31344(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31344, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// lwz r8,156(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// lwz r3,480(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 480);
	// bl 0x8209d538
	ctx.lr = 0x82181C9C;
	sub_8209D538(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d5184
	ctx.lr = 0x82181CA4;
	__imp__XGetVideoMode(ctx, base);
	// lwz r6,140(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// addi r5,r6,-1
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r4,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stw r11,-32200(r7)
	PPC_STORE_U32(ctx.r7.u32 + -32200, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82181cd4
	if (!ctx.cr6.eq) goto loc_82181CD4;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r9,r11,-10780
	ctx.r9.s64 = ctx.r11.s64 + -10780;
	// lfs f13,-4720(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4720);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82181cec
	goto loc_82181CEC;
loc_82181CD4:
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r11,1280
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1280, ctx.xer);
	// ble cr6,0x82181d00
	if (!ctx.cr6.gt) goto loc_82181D00;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r9,r11,-10780
	ctx.r9.s64 = ctx.r11.s64 + -10780;
	// lfs f13,-10780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -10780);
	ctx.f13.f64 = double(temp.f32);
loc_82181CEC:
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lfs f0,-5536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5536);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f13,-14012(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + -14012, temp.u32);
	// stfs f0,-14016(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -14016, temp.u32);
loc_82181D00:
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1808
	ctx.r11.s64 = 1808;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r30.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// lis r9,6690
	ctx.r9.s64 = 438435840;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ori r31,r9,447
	ctx.r31.u64 = ctx.r9.u64 | 447;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,480
	ctx.r4.s64 = 480;
	// li r3,640
	ctx.r3.s64 = 640;
	// bl 0x8209d400
	ctx.lr = 0x82181D3C;
	sub_8209D400(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,240
	ctx.r4.s64 = 240;
	// stw r3,-32204(r8)
	PPC_STORE_U32(ctx.r8.u32 + -32204, ctx.r3.u32);
	// li r3,320
	ctx.r3.s64 = 320;
	// bl 0x8209d400
	ctx.lr = 0x82181D5C;
	sub_8209D400(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,-31872(r4)
	PPC_STORE_U32(ctx.r4.u32 + -31872, ctx.r3.u32);
	// li r4,60
	ctx.r4.s64 = 60;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x8209d400
	ctx.lr = 0x82181D7C;
	sub_8209D400(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,30
	ctx.r4.s64 = 30;
	// stw r3,-32148(r11)
	PPC_STORE_U32(ctx.r11.u32 + -32148, ctx.r3.u32);
	// li r3,40
	ctx.r3.s64 = 40;
	// addi r29,r11,-32148
	ctx.r29.s64 = ctx.r11.s64 + -32148;
	// bl 0x8209d400
	ctx.lr = 0x82181DA0;
	sub_8209D400(ctx, base);
	// stw r3,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r3.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8209d400
	ctx.lr = 0x82181DBC;
	sub_8209D400(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stw r3,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,-32208(r10)
	PPC_STORE_U32(ctx.r10.u32 + -32208, ctx.r30.u32);
	// bl 0x82180e60
	ctx.lr = 0x82181DD4;
	sub_82180E60(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,516
	ctx.r3.s64 = 516;
	// stw r11,-32152(r9)
	PPC_STORE_U32(ctx.r9.u32 + -32152, ctx.r11.u32);
	// bl 0x82180e60
	ctx.lr = 0x82181DE8;
	sub_82180E60(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,4100
	ctx.r3.s64 = 4100;
	// stw r11,-32160(r8)
	PPC_STORE_U32(ctx.r8.u32 + -32160, ctx.r11.u32);
	// bl 0x82180e60
	ctx.lr = 0x82181DFC;
	sub_82180E60(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// stw r3,-31956(r7)
	PPC_STORE_U32(ctx.r7.u32 + -31956, ctx.r3.u32);
	// bl 0x8217faa8
	ctx.lr = 0x82181E08;
	sub_8217FAA8(ctx, base);
loc_82181E08:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

