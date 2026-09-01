#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_88131898"))) PPC_WEAK_FUNC(sub_88131898);
PPC_FUNC_IMPL(__imp__sub_88131898) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,8
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 8, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-15272
	ctx.r9.s64 = ctx.r11.s64 + -15272;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r8,32248
	ctx.r7.s64 = ctx.r8.s64 + 32248;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r3,32248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32248, ctx.r3.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
	// stw r10,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881318CC"))) PPC_WEAK_FUNC(sub_881318CC);
PPC_FUNC_IMPL(__imp__sub_881318CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881318D0"))) PPC_WEAK_FUNC(sub_881318D0);
PPC_FUNC_IMPL(__imp__sub_881318D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r11,r11,32248
	ctx.r11.s64 = ctx.r11.s64 + 32248;
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subfic r6,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r9.s64;
	// stw r10,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r4,r8
	ctx.r10.u64 = ctx.r4.u64 & ctx.r8.u64;
	// stw r10,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131920"))) PPC_WEAK_FUNC(sub_88131920);
PPC_FUNC_IMPL(__imp__sub_88131920) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r3,r11,32248
	ctx.r3.s64 = ctx.r11.s64 + 32248;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x88073bd0
	sub_88073BD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88131934"))) PPC_WEAK_FUNC(sub_88131934);
PPC_FUNC_IMPL(__imp__sub_88131934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88131938"))) PPC_WEAK_FUNC(sub_88131938);
PPC_FUNC_IMPL(__imp__sub_88131938) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,30408
	ctx.r10.s64 = ctx.r11.s64 + 30408;
	// stw r3,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131948"))) PPC_WEAK_FUNC(sub_88131948);
PPC_FUNC_IMPL(__imp__sub_88131948) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// bne cr6,0x8813196c
	if (!ctx.cr6.eq) goto loc_8813196C;
	// addi r10,r11,30408
	ctx.r10.s64 = ctx.r11.s64 + 30408;
	// stw r3,256(r10)
	PPC_STORE_U32(ctx.r10.u32 + 256, ctx.r3.u32);
	// stw r3,468(r10)
	PPC_STORE_U32(ctx.r10.u32 + 468, ctx.r3.u32);
	// stw r3,680(r10)
	PPC_STORE_U32(ctx.r10.u32 + 680, ctx.r3.u32);
	// stw r3,892(r10)
	PPC_STORE_U32(ctx.r10.u32 + 892, ctx.r3.u32);
	// blr 
	return;
loc_8813196C:
	// addi r11,r11,30408
	ctx.r11.s64 = ctx.r11.s64 + 30408;
	// mulli r10,r4,212
	ctx.r10.s64 = ctx.r4.s64 * 212;
	// addi r9,r11,256
	ctx.r9.s64 = ctx.r11.s64 + 256;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131980"))) PPC_WEAK_FUNC(sub_88131980);
PPC_FUNC_IMPL(__imp__sub_88131980) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// stw r3,32244(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32244, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813198C"))) PPC_WEAK_FUNC(sub_8813198C);
PPC_FUNC_IMPL(__imp__sub_8813198C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88131990"))) PPC_WEAK_FUNC(sub_88131990);
PPC_FUNC_IMPL(__imp__sub_88131990) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,8
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 8, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-15272
	ctx.r9.s64 = ctx.r11.s64 + -15272;
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r8,32248
	ctx.r7.s64 = ctx.r8.s64 + 32248;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r3,32248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32248, ctx.r3.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r11.u32);
	// stw r10,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881319C4"))) PPC_WEAK_FUNC(sub_881319C4);
PPC_FUNC_IMPL(__imp__sub_881319C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881319C8"))) PPC_WEAK_FUNC(sub_881319C8);
PPC_FUNC_IMPL(__imp__sub_881319C8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mulli r10,r3,212
	ctx.r10.s64 = ctx.r3.s64 * 212;
	// addi r11,r11,30408
	ctx.r11.s64 = ctx.r11.s64 + 30408;
	// addi r11,r11,64
	ctx.r11.s64 = ctx.r11.s64 + 64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 96);
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 100);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881319F0"))) PPC_WEAK_FUNC(sub_881319F0);
PPC_FUNC_IMPL(__imp__sub_881319F0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r7,r10,30408
	ctx.r7.s64 = ctx.r10.s64 + 30408;
	// lis r10,2560
	ctx.r10.s64 = 167772160;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,184(r7)
	PPC_STORE_U32(ctx.r7.u32 + 184, ctx.r11.u32);
	// stw r10,188(r7)
	PPC_STORE_U32(ctx.r7.u32 + 188, ctx.r10.u32);
	// stw r9,176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 176, ctx.r9.u32);
	// stw r8,180(r7)
	PPC_STORE_U32(ctx.r7.u32 + 180, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131A1C"))) PPC_WEAK_FUNC(sub_88131A1C);
PPC_FUNC_IMPL(__imp__sub_88131A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88131A20"))) PPC_WEAK_FUNC(sub_88131A20);
PPC_FUNC_IMPL(__imp__sub_88131A20) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r5,176(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// clrlwi r3,r11,16
	ctx.r3.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x88090818
	sub_88090818(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88131A34"))) PPC_WEAK_FUNC(sub_88131A34);
PPC_FUNC_IMPL(__imp__sub_88131A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88131A38"))) PPC_WEAK_FUNC(sub_88131A38);
PPC_FUNC_IMPL(__imp__sub_88131A38) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,30408
	ctx.r11.s64 = ctx.r11.s64 + 30408;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// lwz r10,272(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// stw r9,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
	// stw r9,168(r11)
	PPC_STORE_U32(ctx.r11.u32 + 168, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 172, ctx.r9.u32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,68(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,30
	ctx.r11.s64 = ctx.r11.s64 + 30;
	// add r8,r6,r10
	ctx.r8.u64 = ctx.r6.u64 + ctx.r10.u64;
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,236(r8)
	PPC_STORE_U32(ctx.r8.u32 + 236, ctx.r9.u32);
	// stwx r9,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131A88"))) PPC_WEAK_FUNC(sub_88131A88);
PPC_FUNC_IMPL(__imp__sub_88131A88) {
	PPC_FUNC_PROLOGUE();
	// clrlwi r10,r4,23
	ctx.r10.u64 = ctx.r4.u32 & 0x1FF;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r8,r10,128
	ctx.r8.s64 = ctx.r10.s64 + 128;
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// addi r9,r11,30408
	ctx.r9.s64 = ctx.r11.s64 + 30408;
	// addi r6,r7,9552
	ctx.r6.s64 = ctx.r7.s64 + 9552;
	// rlwinm r11,r8,2,21,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x7FC;
	// rlwinm r7,r4,2,21,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// mulli r8,r3,212
	ctx.r8.s64 = ctx.r3.s64 * 212;
	// lwzx r4,r11,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// lwzx r7,r7,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// addi r11,r9,64
	ctx.r11.s64 = ctx.r9.s64 + 64;
	// mullw r6,r4,r5
	ctx.r6.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mullw r4,r7,r5
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// stw r10,96(r11)
	PPC_STORE_U32(ctx.r11.u32 + 96, ctx.r10.u32);
	// stw r5,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r5.u32);
	// stw r4,104(r11)
	PPC_STORE_U32(ctx.r11.u32 + 104, ctx.r4.u32);
	// stw r6,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r6.u32);
	// lwz r11,32(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r3,30
	ctx.r3.s64 = ctx.r3.s64 + 30;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r9,r3,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r4,236(r10)
	PPC_STORE_U32(ctx.r10.u32 + 236, ctx.r4.u32);
	// neg r8,r6
	ctx.r8.s64 = -ctx.r6.s64;
	// stwx r8,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131AF8"))) PPC_WEAK_FUNC(sub_88131AF8);
PPC_FUNC_IMPL(__imp__sub_88131AF8) {
	PPC_FUNC_PROLOGUE();
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r9,36(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// lwz r11,64(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// lwz r8,68(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88131ba4
	if (ctx.cr6.eq) goto loc_88131BA4;
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88131ba4
	if (!ctx.cr6.eq) goto loc_88131BA4;
	// lwz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88131ba4
	if (!ctx.cr6.eq) goto loc_88131BA4;
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88131b90
	if (!ctx.cr6.eq) goto loc_88131B90;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lis r9,232
	ctx.r9.s64 = 15204352;
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x88131b6c
	if (ctx.cr6.lt) goto loc_88131B6C;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r11,232
	ctx.r11.s64 = 15204352;
	// sth r10,16(r4)
	PPC_STORE_U16(ctx.r4.u32 + 16, ctx.r10.u16);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r8,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r8.u32);
	// blr 
	return;
loc_88131B6C:
	// lis r10,8
	ctx.r10.s64 = 524288;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x88131bb4
	if (ctx.cr6.gt) goto loc_88131BB4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r11,8
	ctx.r11.s64 = 524288;
	// sth r10,16(r4)
	PPC_STORE_U16(ctx.r4.u32 + 16, ctx.r10.u16);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r8,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r8.u32);
	// blr 
	return;
loc_88131B90:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwx r10,r9,r4
	PPC_STORE_U32(ctx.r9.u32 + ctx.r4.u32, ctx.r10.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r8,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r8.u32);
	// blr 
	return;
loc_88131BA4:
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r9.u32);
loc_88131BB4:
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// stw r8,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131BC0"))) PPC_WEAK_FUNC(sub_88131BC0);
PPC_FUNC_IMPL(__imp__sub_88131BC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,36(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88131c28
	if (ctx.cr6.eq) goto loc_88131C28;
	// bge cr6,0x88131c0c
	if (!ctx.cr6.lt) goto loc_88131C0C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x88131bfc
	if (!ctx.cr6.gt) goto loc_88131BFC;
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// blr 
	return;
loc_88131BFC:
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// blr 
	return;
loc_88131C0C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x88131c1c
	if (!ctx.cr6.gt) goto loc_88131C1C;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// b 0x88131c24
	goto loc_88131C24;
loc_88131C1C:
	// neg r9,r11
	ctx.r9.s64 = -ctx.r11.s64;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
loc_88131C24:
	// bgelr cr6
	if (!ctx.cr6.lt) return;
loc_88131C28:
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88131C30"))) PPC_WEAK_FUNC(sub_88131C30);
PPC_FUNC_IMPL(__imp__sub_88131C30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x88131C38;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r29,r11,32248
	ctx.r29.s64 = ctx.r11.s64 + 32248;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r29.u32);
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x88131c90
	if (ctx.cr6.eq) goto loc_88131C90;
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r10,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subfic r7,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r10.s64;
	// stw r11,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// stw r8,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r8.u32);
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r5,r9
	ctx.r11.u64 = ctx.r5.u64 & ctx.r9.u64;
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
loc_88131C90:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r21,0
	ctx.r21.s64 = 0;
	// addi r27,r11,30408
	ctx.r27.s64 = ctx.r11.s64 + 30408;
	// lis r31,40
	ctx.r31.s64 = 2621440;
	// lwz r11,26272(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88131e10
	if (!ctx.cr6.eq) goto loc_88131E10;
	// lhz r11,18(r27)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r27.u32 + 18);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88131cfc
	if (ctx.cr6.eq) goto loc_88131CFC;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// stw r21,36(r27)
	PPC_STORE_U32(ctx.r27.u32 + 36, ctx.r21.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x88131ce0
	if (!ctx.cr6.gt) goto loc_88131CE0;
	// addic. r11,r11,-16384
	ctx.xer.ca = ctx.r11.u32 > 16383;
	ctx.r11.s64 = ctx.r11.s64 + -16384;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// bgt 0x88131cfc
	if (ctx.cr0.gt) goto loc_88131CFC;
	// b 0x88131cec
	goto loc_88131CEC;
loc_88131CE0:
	// addic. r11,r11,16384
	ctx.xer.ca = ctx.r11.u32 > 4294950911;
	ctx.r11.s64 = ctx.r11.s64 + 16384;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// blt 0x88131cfc
	if (ctx.cr0.lt) goto loc_88131CFC;
loc_88131CEC:
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// sth r21,18(r27)
	PPC_STORE_U16(ctx.r27.u32 + 18, ctx.r21.u16);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// stw r21,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r21.u32);
loc_88131CFC:
	// stw r21,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r21.u32);
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r21,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r21.u32);
	// lis r11,-30701
	ctx.r11.s64 = -2012020736;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r11,7104
	ctx.r4.s64 = ctx.r11.s64 + 7104;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// bl 0x88135ba8
	ctx.lr = 0x88131D20;
	sub_88135BA8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88131dcc
	if (ctx.cr6.eq) goto loc_88131DCC;
	// lwz r8,12(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x88131dcc
	if (ctx.cr6.eq) goto loc_88131DCC;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// ble cr6,0x88131d80
	if (!ctx.cr6.gt) goto loc_88131D80;
	// cmpw cr6,r9,r31
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r31.s32, ctx.xer);
	// beq cr6,0x88131dcc
	if (ctx.cr6.eq) goto loc_88131DCC;
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// lis r11,2
	ctx.r11.s64 = 131072;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// ori r11,r11,49152
	ctx.r11.u64 = ctx.r11.u64 | 49152;
	// stw r10,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r10.u32);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88131dcc
	if (ctx.cr6.lt) goto loc_88131DCC;
	// subf r11,r11,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r11.s64;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r11,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// cmpw cr6,r9,r31
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r31.s32, ctx.xer);
	// stw r10,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r10.u32);
	// blt cr6,0x88131dcc
	if (ctx.cr6.lt) goto loc_88131DCC;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// b 0x88131dc8
	goto loc_88131DC8;
loc_88131D80:
	// lis r7,-40
	ctx.r7.s64 = -2621440;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// beq cr6,0x88131dcc
	if (ctx.cr6.eq) goto loc_88131DCC;
	// lwz r11,8(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 8);
	// lis r10,-3
	ctx.r10.s64 = -196608;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// ori r8,r10,16384
	ctx.r8.u64 = ctx.r10.u64 | 16384;
	// stw r11,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bgt cr6,0x88131dcc
	if (ctx.cr6.gt) goto loc_88131DCC;
	// addis r11,r11,3
	ctx.r11.s64 = ctx.r11.s64 + 196608;
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// addi r11,r11,-16384
	ctx.r11.s64 = ctx.r11.s64 + -16384;
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// stw r10,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r10.u32);
	// stw r11,8(r27)
	PPC_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// bgt cr6,0x88131dcc
	if (ctx.cr6.gt) goto loc_88131DCC;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_88131DC8:
	// stw r11,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_88131DCC:
	// sth r21,16(r27)
	PPC_STORE_U16(ctx.r27.u32 + 16, ctx.r21.u16);
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r10,6904
	ctx.r4.s64 = ctx.r10.s64 + 6904;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// bl 0x88135ba8
	ctx.lr = 0x88131DE8;
	sub_88135BA8(ctx, base);
	// lhz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r27.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88131e08
	if (!ctx.cr6.eq) goto loc_88131E08;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// b 0x88131e10
	goto loc_88131E10;
loc_88131E08:
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r21,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r21.u32);
loc_88131E10:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x88131830
	ctx.lr = 0x88131E1C;
	sub_88131830(ctx, base);
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r18,r21
	ctx.r18.u64 = ctx.r21.u64;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
	// stw r9,160(r11)
	PPC_STORE_U32(ctx.r11.u32 + 160, ctx.r9.u32);
	// lwz r11,28(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x881323e0
	if (ctx.cr6.eq) goto loc_881323E0;
	// lis r11,-30679
	ctx.r11.s64 = -2010578944;
	// srawi r9,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 16;
	// addi r14,r11,-15208
	ctx.r14.s64 = ctx.r11.s64 + -15208;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addze r20,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r20.s64 = temp.s64;
	// addi r22,r11,-11980
	ctx.r22.s64 = ctx.r11.s64 + -11980;
	// srawi r8,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 16;
	// lis r10,-30633
	ctx.r10.s64 = -2007564288;
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addze r19,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r19.s64 = temp.s64;
	// lwz r17,980(r22)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r22.u32 + 980);
	// addi r31,r27,172
	ctx.r31.s64 = ctx.r27.s64 + 172;
	// lwz r26,976(r22)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r22.u32 + 976);
	// li r24,272
	ctx.r24.s64 = 272;
	// lwz r25,0(r22)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// addi r23,r30,220
	ctx.r23.s64 = ctx.r30.s64 + 220;
	// addi r15,r10,-29728
	ctx.r15.s64 = ctx.r10.s64 + -29728;
	// addi r16,r11,2592
	ctx.r16.s64 = ctx.r11.s64 + 2592;
loc_88131E88:
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// addi r4,r24,-272
	ctx.r4.s64 = ctx.r24.s64 + -272;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r8,236(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 236);
	// stw r8,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r8.u32);
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// add r7,r11,r24
	ctx.r7.u64 = ctx.r11.u64 + ctx.r24.u64;
	// lwz r6,-32(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + -32);
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// beq cr6,0x88131ec4
	if (ctx.cr6.eq) goto loc_88131EC4;
	// stw r21,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r21.u32);
	// stw r21,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r21.u32);
loc_88131EC4:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88131f60
	if (!ctx.cr6.eq) goto loc_88131F60;
	// lwz r10,-4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 + ctx.r5.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// rlwinm r7,r11,0,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF0000;
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// rlwinm r10,r8,0,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF0000;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x88131f24
	if (ctx.cr6.eq) goto loc_88131F24;
	// subf r11,r7,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r7.s64;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_88131F24:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88131f34
	if (ctx.cr6.eq) goto loc_88131F34;
	// subf r11,r10,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r10.s64;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_88131F34:
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// stwx r10,r24,r11
	PPC_STORE_U32(ctx.r24.u32 + ctx.r11.u32, ctx.r10.u32);
	// stw r7,268(r9)
	PPC_STORE_U32(ctx.r9.u32 + 268, ctx.r7.u32);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x88131f60
	if (!ctx.cr6.eq) goto loc_88131F60;
	// lwz r10,-16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// lwz r11,-8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,-16(r31)
	PPC_STORE_U32(ctx.r31.u32 + -16, ctx.r11.u32);
loc_88131F60:
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r9,r11,-40
	ctx.r9.s64 = ctx.r11.s64 + -40;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r10,r9,19,0,12
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 19) & 0xFFF80000;
	// bge cr6,0x88131f94
	if (!ctx.cr6.lt) goto loc_88131F94;
	// stw r21,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r21.u32);
	// stw r21,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r21.u32);
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + ctx.r11.u64;
	// lwzx r8,r11,r24
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// stwx r8,r24,r11
	PPC_STORE_U32(ctx.r24.u32 + ctx.r11.u32, ctx.r8.u32);
	// stw r21,268(r9)
	PPC_STORE_U32(ctx.r9.u32 + 268, ctx.r21.u32);
loc_88131F94:
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x88131fbc
	if (!ctx.cr6.gt) goto loc_88131FBC;
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// stw r21,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r21.u32);
	// lwz r11,32(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// lwzx r9,r11,r24
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// stw r21,268(r10)
	PPC_STORE_U32(ctx.r10.u32 + 268, ctx.r21.u32);
	// stwx r9,r24,r11
	PPC_STORE_U32(ctx.r24.u32 + ctx.r11.u32, ctx.r9.u32);
loc_88131FBC:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -40;
	// rlwinm r11,r11,19,0,12
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0xFFF80000;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x88131fe4
	if (!ctx.cr6.gt) goto loc_88131FE4;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// blt cr6,0x88131fe4
	if (ctx.cr6.lt) goto loc_88131FE4;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
loc_88131FE4:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x88132000
	if (!ctx.cr6.lt) goto loc_88132000;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// blt cr6,0x88132000
	if (ctx.cr6.lt) goto loc_88132000;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_88132000:
	// lwz r11,-64(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132028
	if (ctx.cr6.eq) goto loc_88132028;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,-48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -48);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x88132028
	if (!ctx.cr6.gt) goto loc_88132028;
	// lwz r10,-32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
loc_88132028:
	// lwz r11,-60(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132050
	if (ctx.cr6.eq) goto loc_88132050;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,-44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x88132050
	if (!ctx.cr6.gt) goto loc_88132050;
	// lwz r10,-28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -28);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
loc_88132050:
	// lwz r11,-56(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -56);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132078
	if (ctx.cr6.eq) goto loc_88132078;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,-40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -40);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88132078
	if (!ctx.cr6.lt) goto loc_88132078;
	// lwz r10,-24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -24);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_88132078:
	// lwz r11,-52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881320a0
	if (ctx.cr6.eq) goto loc_881320A0;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,-36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -36);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x881320a0
	if (!ctx.cr6.lt) goto loc_881320A0;
	// lwz r10,-20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_881320A0:
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881320c0
	if (ctx.cr6.eq) goto loc_881320C0;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// divw r11,r11,r9
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r9.s32);
loc_881320C0:
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// rlwinm r9,r11,16,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r8,r10,16,0,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// addi r5,r31,-108
	ctx.r5.s64 = ctx.r31.s64 + -108;
	// stw r8,-16(r23)
	PPC_STORE_U32(ctx.r23.u32 + -16, ctx.r8.u32);
	// stw r9,0(r23)
	PPC_STORE_U32(ctx.r23.u32 + 0, ctx.r9.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addis r10,r3,40
	ctx.r10.s64 = ctx.r3.s64 + 2621440;
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// srawi r4,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 16;
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addze r9,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r4,-16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// srawi r10,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 16;
	// addze r8,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r8.s64 = temp.s64;
	// lwz r30,-100(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -100);
	// srawi r7,r7,16
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 16;
	// stw r30,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r30.u32);
	// addze r10,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r6,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 16;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// addze r8,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r8.s64 = temp.s64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r7,r20,r9
	ctx.r7.u64 = ctx.r20.u64 + ctx.r9.u64;
	// add r8,r19,r11
	ctx.r8.u64 = ctx.r19.u64 + ctx.r11.u64;
	// rlwinm r10,r4,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 25) & 0x1FFFFFF;
	// srawi r6,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 5;
	// stw r10,-100(r31)
	PPC_STORE_U32(ctx.r31.u32 + -100, ctx.r10.u32);
	// addze r6,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r6.s64 = temp.s64;
	// srawi r4,r7,5
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 5;
	// stw r6,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r6.u32);
	// addze r4,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r4.s64 = temp.s64;
	// srawi r3,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// stw r4,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// addze r8,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r3,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r3.s64 = temp.s64;
	// srawi r8,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 3;
	// stw r3,-88(r31)
	PPC_STORE_U32(ctx.r31.u32 + -88, ctx.r3.u32);
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// stw r7,-92(r31)
	PPC_STORE_U32(ctx.r31.u32 + -92, ctx.r7.u32);
	// stw r10,-52(r23)
	PPC_STORE_U32(ctx.r23.u32 + -52, ctx.r10.u32);
	// lwz r3,-108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -108);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88132390
	if (ctx.cr6.eq) goto loc_88132390;
	// lwz r10,912(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 912);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88132390
	if (!ctx.cr6.eq) goto loc_88132390;
	// lwz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// clrlwi r10,r18,16
	ctx.r10.u64 = ctx.r18.u32 & 0xFFFF;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r17
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r17.u32, ctx.xer);
	// bge cr6,0x881321c8
	if (!ctx.cr6.lt) goto loc_881321C8;
	// add r7,r20,r11
	ctx.r7.u64 = ctx.r20.u64 + ctx.r11.u64;
	// add r3,r19,r9
	ctx.r3.u64 = ctx.r19.u64 + ctx.r9.u64;
	// rlwinm r11,r10,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// clrlwi r9,r7,21
	ctx.r9.u64 = ctx.r7.u32 & 0x7FF;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// clrlwi r7,r3,21
	ctx.r7.u64 = ctx.r3.u32 & 0x7FF;
	// subfic r3,r9,2048
	ctx.xer.ca = ctx.r9.u32 <= 2048;
	ctx.r3.s64 = 2048 - ctx.r9.s64;
	// subfic r9,r7,2048
	ctx.xer.ca = ctx.r7.u32 <= 2048;
	ctx.r9.s64 = 2048 - ctx.r7.s64;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
loc_881321C8:
	// mullw r11,r8,r6
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r28,r8,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_881321E8:
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_881321F0:
	// cmplw cr6,r3,r17
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r17.u32, ctx.xer);
	// blt cr6,0x88132200
	if (ctx.cr6.lt) goto loc_88132200;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// b 0x88132228
	goto loc_88132228;
loc_88132200:
	// add r11,r8,r4
	ctx.r11.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r10,r6,r7
	ctx.r10.u64 = ctx.r6.u64 + ctx.r7.u64;
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r11,r11,6,20,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 6) & 0xFC0;
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// add r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,12(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_88132228:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 10, ctx.xer);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// lbz r9,1(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// stb r9,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r9.u8);
	// lbz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 2);
	// stb r10,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r10.u8);
	// lbz r9,3(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 3);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// stb r9,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r9.u8);
	// blt cr6,0x881321f0
	if (ctx.cr6.lt) goto loc_881321F0;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r29,r28,r29
	ctx.r29.u64 = ctx.r28.u64 + ctx.r29.u64;
	// cmpwi cr6,r7,12
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 12, ctx.xer);
	// blt cr6,0x881321e8
	if (ctx.cr6.lt) goto loc_881321E8;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r11,26272(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 26272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88132324
	if (!ctx.cr6.eq) goto loc_88132324;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x88132324
	if (ctx.cr6.eq) goto loc_88132324;
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// lbz r11,73(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 73);
	// lbz r10,69(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 69);
	// clrlwi r3,r9,24
	ctx.r3.u64 = ctx.r9.u32 & 0xFF;
	// lbz r8,74(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 74);
	// lbz r7,70(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 70);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// ble cr6,0x881322b8
	if (!ctx.cr6.gt) goto loc_881322B8;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// b 0x881322c0
	goto loc_881322C0;
loc_881322B8:
	// subf r6,r9,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
loc_881322C0:
	// blt cr6,0x881322c8
	if (ctx.cr6.lt) goto loc_881322C8;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
loc_881322C8:
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x881322dc
	if (!ctx.cr6.gt) goto loc_881322DC;
	// add r10,r7,r9
	ctx.r10.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// b 0x881322e4
	goto loc_881322E4;
loc_881322DC:
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// cmpw cr6,r8,r10
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, ctx.xer);
loc_881322E4:
	// blt cr6,0x881322ec
	if (ctx.cr6.lt) goto loc_881322EC;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_881322EC:
	// cmpw cr6,r4,r3
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, ctx.xer);
	// ble cr6,0x88132300
	if (!ctx.cr6.gt) goto loc_88132300;
	// add r11,r3,r9
	ctx.r11.u64 = ctx.r3.u64 + ctx.r9.u64;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// b 0x88132308
	goto loc_88132308;
loc_88132300:
	// subf r11,r9,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r9.s64;
	// cmpw cr6,r4,r11
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r11.s32, ctx.xer);
loc_88132308:
	// blt cr6,0x88132310
	if (ctx.cr6.lt) goto loc_88132310;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_88132310:
	// rlwinm r9,r6,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | ctx.r11.u64;
	// stw r6,68(r31)
	PPC_STORE_U32(ctx.r31.u32 + 68, ctx.r6.u32);
loc_88132324:
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88132390
	if (!ctx.cr6.eq) goto loc_88132390;
	// lwz r10,0(r14)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// cmplwi cr6,r25,30000
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 30000, ctx.xer);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// bge cr6,0x88132390
	if (!ctx.cr6.lt) goto loc_88132390;
	// rlwinm r11,r25,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,3,20,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFF8;
	// add r11,r25,r11
	ctx.r11.u64 = ctx.r25.u64 + ctx.r11.u64;
	// addi r9,r16,4
	ctx.r9.s64 = ctx.r16.s64 + 4;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-30701
	ctx.r8.s64 = -2012020736;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// addi r7,r8,6688
	ctx.r7.s64 = ctx.r8.s64 + 6688;
	// lwzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r11.u32);
	// stw r25,0(r22)
	PPC_STORE_U32(ctx.r22.u32 + 0, ctx.r25.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r21,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r21.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r5,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r5.u32);
	// beq cr6,0x8813238c
	if (ctx.cr6.eq) goto loc_8813238C;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// b 0x88132390
	goto loc_88132390;
loc_8813238C:
	// stwx r11,r10,r16
	PPC_STORE_U32(ctx.r10.u32 + ctx.r16.u32, ctx.r11.u32);
loc_88132390:
	// lwz r4,-100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + -100);
	// lwz r11,-84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -84);
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// beq cr6,0x881323bc
	if (ctx.cr6.eq) goto loc_881323BC;
	// stw r4,-84(r31)
	PPC_STORE_U32(ctx.r31.u32 + -84, ctx.r4.u32);
	// addi r6,r31,88
	ctx.r6.s64 = ctx.r31.s64 + 88;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x8822b520
	ctx.lr = 0x881323B0;
	sub_8822B520(ctx, base);
	// lwz r17,980(r22)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r22.u32 + 980);
	// lwz r26,976(r22)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r22.u32 + 976);
	// lwz r25,0(r22)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
loc_881323BC:
	// lwz r11,28(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 28);
	// addi r18,r18,1
	ctx.r18.s64 = ctx.r18.s64 + 1;
	// addi r31,r31,212
	ctx.r31.s64 = ctx.r31.s64 + 212;
	// addi r24,r24,8
	ctx.r24.s64 = ctx.r24.s64 + 8;
	// addi r23,r23,4
	ctx.r23.s64 = ctx.r23.s64 + 4;
	// addi r14,r14,4
	ctx.r14.s64 = ctx.r14.s64 + 4;
	// cmplw cr6,r18,r11
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x88131e88
	if (ctx.cr6.lt) goto loc_88131E88;
	// lwz r29,88(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_881323E0:
	// lwz r11,-4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132570
	if (ctx.cr6.eq) goto loc_88132570;
	// lwz r11,48(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 48);
	// addi r10,r27,64
	ctx.r10.s64 = ctx.r27.s64 + 64;
	// lwz r7,56(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 56);
	// mulli r11,r11,212
	ctx.r11.s64 = ctx.r11.s64 * 212;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r31,8(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// ble cr6,0x88132470
	if (!ctx.cr6.gt) goto loc_88132470;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// stw r21,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r21.u32);
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x88132474
	if (!ctx.cr6.gt) goto loc_88132474;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_88132428:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88132460
	if (ctx.cr6.eq) goto loc_88132460;
loc_88132430:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x88132460
	if (ctx.cr6.eq) goto loc_88132460;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88132460
	if (!ctx.cr6.eq) goto loc_88132460;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add. r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x88132430
	if (!ctx.cr0.eq) goto loc_88132430;
loc_88132460:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r8,r31
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r31.s32, ctx.xer);
	// blt cr6,0x88132428
	if (ctx.cr6.lt) goto loc_88132428;
	// b 0x88132474
	goto loc_88132474;
loc_88132470:
	// lwz r11,52(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 52);
loc_88132474:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add. r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x88132570
	if (ctx.cr0.eq) goto loc_88132570;
	// lwz r8,32(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
loc_8813248C:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x88132570
	if (ctx.cr6.eq) goto loc_88132570;
	// cmpw cr6,r31,r9
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88132570
	if (!ctx.cr6.eq) goto loc_88132570;
	// lwz r9,1860(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1860);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bne cr6,0x881324cc
	if (!ctx.cr6.eq) goto loc_881324CC;
	// lwz r9,1888(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1888);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x881324cc
	if (ctx.cr6.eq) goto loc_881324CC;
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// cmplwi cr6,r9,48
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 48, ctx.xer);
	// beq cr6,0x88132554
	if (ctx.cr6.eq) goto loc_88132554;
	// cmplwi cr6,r9,229
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 229, ctx.xer);
	// beq cr6,0x88132554
	if (ctx.cr6.eq) goto loc_88132554;
loc_881324CC:
	// lwz r9,912(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 912);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8813250c
	if (ctx.cr6.eq) goto loc_8813250C;
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// cmplwi cr6,r9,237
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 237, ctx.xer);
	// beq cr6,0x8813250c
	if (ctx.cr6.eq) goto loc_8813250C;
	// cmpwi cr6,r31,565
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 565, ctx.xer);
	// bne cr6,0x881324f4
	if (!ctx.cr6.eq) goto loc_881324F4;
	// cmplwi cr6,r9,75
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 75, ctx.xer);
	// beq cr6,0x8813250c
	if (ctx.cr6.eq) goto loc_8813250C;
loc_881324F4:
	// cmplwi cr6,r9,99
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 99, ctx.xer);
	// beq cr6,0x8813250c
	if (ctx.cr6.eq) goto loc_8813250C;
	// cmplwi cr6,r9,56
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 56, ctx.xer);
	// beq cr6,0x8813250c
	if (ctx.cr6.eq) goto loc_8813250C;
	// cmplwi cr6,r9,119
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 119, ctx.xer);
	// bne cr6,0x88132554
	if (!ctx.cr6.eq) goto loc_88132554;
loc_8813250C:
	// lhz r3,2(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// cmplwi cr6,r3,256
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 256, ctx.xer);
	// bge cr6,0x88132554
	if (!ctx.cr6.lt) goto loc_88132554;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,60(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 60);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lhz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r7,10(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lbz r8,7(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// lbz r7,6(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// bl 0x880957a8
	ctx.lr = 0x88132548;
	sub_880957A8(ctx, base);
	// lwz r7,56(r27)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r27.u32 + 56);
	// lwz r11,52(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 52);
	// lwz r8,32(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
loc_88132554:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,52(r27)
	PPC_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add. r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8813248c
	if (!ctx.cr0.eq) goto loc_8813248C;
loc_88132570:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88132578"))) PPC_WEAK_FUNC(sub_88132578);
PPC_FUNC_IMPL(__imp__sub_88132578) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88132580;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r30,r10,30408
	ctx.r30.s64 = ctx.r10.s64 + 30408;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r11,912(r30)
	PPC_STORE_U32(ctx.r30.u32 + 912, ctx.r11.u32);
	// beq cr6,0x881325b8
	if (ctx.cr6.eq) goto loc_881325B8;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
loc_881325A4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x88131c30
	ctx.lr = 0x881325B0;
	sub_88131C30(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x881325a4
	if (!ctx.cr0.eq) goto loc_881325A4;
loc_881325B8:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,912(r30)
	PPC_STORE_U32(ctx.r30.u32 + 912, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881325C8"))) PPC_WEAK_FUNC(sub_881325C8);
PPC_FUNC_IMPL(__imp__sub_881325C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071128
	ctx.lr = 0x881325D0;
	__savegprlr_16(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r20,r10,32248
	ctx.r20.s64 = ctx.r10.s64 + 32248;
	// addi r30,r11,30408
	ctx.r30.s64 = ctx.r11.s64 + 30408;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	// li r5,916
	ctx.r5.s64 = 916;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r31,-924(r20)
	PPC_STORE_U32(ctx.r20.u32 + -924, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88132600;
	sub_88073BD0(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r31,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r31.u32);
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r29,912(r30)
	PPC_STORE_U32(ctx.r30.u32 + 912, ctx.r29.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r29,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r29.u32);
	// lis r7,-30679
	ctx.r7.s64 = -2010578944;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r24,r7,-18492
	ctx.r24.s64 = ctx.r7.s64 + -18492;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r3,r30,48
	ctx.r3.s64 = ctx.r30.s64 + 48;
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r29,172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 172, ctx.r29.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r29,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r29.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r29,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r29.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r8,200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 200, ctx.r8.u32);
	// stw r31,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r31.u32);
	// lwz r6,88(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// rlwinm r23,r6,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r23,r24
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r24.u32);
	// addi r4,r11,8
	ctx.r4.s64 = ctx.r11.s64 + 8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// stw r11,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r11.u32);
	// bl 0x88072260
	ctx.lr = 0x88132678;
	sub_88072260(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// stw r11,-4(r20)
	PPC_STORE_U32(ctx.r20.u32 + -4, ctx.r11.u32);
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88132800
	if (ctx.cr6.eq) goto loc_88132800;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// lis r10,-30628
	ctx.r10.s64 = -2007236608;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// mr r22,r29
	ctx.r22.u64 = ctx.r29.u64;
	// addi r31,r30,256
	ctx.r31.s64 = ctx.r30.s64 + 256;
	// ori r26,r9,32896
	ctx.r26.u64 = ctx.r9.u64 | 32896;
	// li r18,-1
	ctx.r18.s64 = -1;
	// li r19,2048
	ctx.r19.s64 = 2048;
	// addi r17,r10,23440
	ctx.r17.s64 = ctx.r10.s64 + 23440;
	// addi r21,r11,-11004
	ctx.r21.s64 = ctx.r11.s64 + -11004;
loc_881326BC:
	// lwzx r11,r23,r24
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r24.u32);
	// clrlwi r28,r27,16
	ctx.r28.u64 = ctx.r27.u32 & 0xFFFF;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// cmplwi cr6,r28,4
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 4, ctx.xer);
	// lwz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r27,-188(r31)
	PPC_STORE_U32(ctx.r31.u32 + -188, ctx.r27.u32);
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// stw r7,-24(r31)
	PPC_STORE_U32(ctx.r31.u32 + -24, ctx.r7.u32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// add r25,r25,r10
	ctx.r25.u64 = ctx.r25.u64 + ctx.r10.u64;
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// stw r6,-40(r31)
	PPC_STORE_U32(ctx.r31.u32 + -40, ctx.r6.u32);
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// stw r5,-36(r31)
	PPC_STORE_U32(ctx.r31.u32 + -36, ctx.r5.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r26,-16(r31)
	PPC_STORE_U32(ctx.r31.u32 + -16, ctx.r26.u32);
	// stw r26,-12(r31)
	PPC_STORE_U32(ctx.r31.u32 + -12, ctx.r26.u32);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// bge cr6,0x88132740
	if (!ctx.cr6.lt) goto loc_88132740;
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// rlwinm r7,r28,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r17,4
	ctx.r6.s64 = ctx.r17.s64 + 4;
	// clrlwi r5,r8,19
	ctx.r5.u64 = ctx.r8.u32 & 0x1FFF;
	// clrlwi r4,r10,20
	ctx.r4.u64 = ctx.r10.u32 & 0xFFF;
	// stwx r5,r7,r17
	PPC_STORE_U32(ctx.r7.u32 + ctx.r17.u32, ctx.r5.u32);
	// stwx r4,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r4.u32);
loc_88132740:
	// stw r18,-168(r31)
	PPC_STORE_U32(ctx.r31.u32 + -168, ctx.r18.u32);
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// addi r5,r31,-192
	ctx.r5.s64 = ctx.r31.s64 + -192;
	// stw r10,-64(r31)
	PPC_STORE_U32(ctx.r31.u32 + -64, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r9,-60(r31)
	PPC_STORE_U32(ctx.r31.u32 + -60, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r8,-72(r31)
	PPC_STORE_U32(ctx.r31.u32 + -72, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// stw r7,-68(r31)
	PPC_STORE_U32(ctx.r31.u32 + -68, ctx.r7.u32);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stw r29,-100(r31)
	PPC_STORE_U32(ctx.r31.u32 + -100, ctx.r29.u32);
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// stw r29,-184(r31)
	PPC_STORE_U32(ctx.r31.u32 + -184, ctx.r29.u32);
	// stw r29,-168(r31)
	PPC_STORE_U32(ctx.r31.u32 + -168, ctx.r29.u32);
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 16;
	// stw r11,-172(r31)
	PPC_STORE_U32(ctx.r31.u32 + -172, ctx.r11.u32);
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r8,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 3;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// stw r7,-176(r31)
	PPC_STORE_U32(ctx.r31.u32 + -176, ctx.r7.u32);
	// bl 0x8822b520
	ctx.lr = 0x881327B4;
	sub_8822B520(ctx, base);
	// lwz r10,4(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 4);
	// clrlwi r11,r28,16
	ctx.r11.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x881327d8
	if (!ctx.cr6.lt) goto loc_881327D8;
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r19,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r19.u32);
	// stw r19,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r19.u32);
loc_881327D8:
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r31,r31,212
	ctx.r31.s64 = ctx.r31.s64 + 212;
	// addi r22,r22,36
	ctx.r22.s64 = ctx.r22.s64 + 36;
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x881326bc
	if (ctx.cr6.lt) goto loc_881326BC;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x88132800
	if (ctx.cr6.eq) goto loc_88132800;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
loc_88132800:
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88073bd0
	ctx.lr = 0x88132810;
	sub_88073BD0(ctx, base);
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lwz r11,-25268(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -25268);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8813284c
	if (ctx.cr6.eq) goto loc_8813284C;
loc_88132820:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r16.u32, ctx.xer);
	// beq cr6,0x88132840
	if (ctx.cr6.eq) goto loc_88132840;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88132820
	if (!ctx.cr6.eq) goto loc_88132820;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
loc_88132840:
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// addi r9,r10,7216
	ctx.r9.s64 = ctx.r10.s64 + 7216;
	// stw r9,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r9.u32);
loc_8813284C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x88071178
	__restgprlr_16(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88132854"))) PPC_WEAK_FUNC(sub_88132854);
PPC_FUNC_IMPL(__imp__sub_88132854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132858"))) PPC_WEAK_FUNC(sub_88132858);
PPC_FUNC_IMPL(__imp__sub_88132858) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88132860;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,84(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lis r8,-30679
	ctx.r8.s64 = -2010578944;
	// lwz r7,92(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-13840
	ctx.r6.s64 = ctx.r8.s64 + -13840;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r10,30324
	ctx.r31.s64 = ctx.r10.s64 + 30324;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r5,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// stw r29,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r29.u32);
	// stw r29,344(r3)
	PPC_STORE_U32(ctx.r3.u32 + 344, ctx.r29.u32);
	// add r30,r10,r9
	ctx.r30.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r29,348(r3)
	PPC_STORE_U32(ctx.r3.u32 + 348, ctx.r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// lwzx r11,r10,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881328c4
	if (!ctx.cr6.eq) goto loc_881328C4;
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881328ec
	if (ctx.cr6.eq) goto loc_881328EC;
loc_881328C4:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r5,20
	ctx.r5.s64 = 20;
	// stw r11,344(r3)
	PPC_STORE_U32(ctx.r3.u32 + 344, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88072260
	ctx.lr = 0x881328E0;
	sub_88072260(ctx, base);
	// stw r29,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_881328EC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881328F4"))) PPC_WEAK_FUNC(sub_881328F4);
PPC_FUNC_IMPL(__imp__sub_881328F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881328F8"))) PPC_WEAK_FUNC(sub_881328F8);
PPC_FUNC_IMPL(__imp__sub_881328F8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r11,r11,26432
	ctx.r11.s64 = ctx.r11.s64 + 26432;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 344);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88132928
	if (!ctx.cr6.eq) goto loc_88132928;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,348(r11)
	PPC_STORE_U32(ctx.r11.u32 + 348, ctx.r8.u32);
loc_88132914:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r9.u32);
	// stw r10,3924(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3924, ctx.r10.u32);
loc_88132924:
	// blr 
	return;
loc_88132928:
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 348);
	// lis r5,-30597
	ctx.r5.s64 = -2005204992;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,3916(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3916);
	// lwz r4,-13976(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -13976);
	// beq cr6,0x88132970
	if (ctx.cr6.eq) goto loc_88132970;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r10.u32);
	// bge 0x88132970
	if (!ctx.cr0.lt) goto loc_88132970;
	// lwz r10,356(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 356);
	// li r9,2
	ctx.r9.s64 = 2;
	// cmpwi cr6,r4,15
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 15, ctx.xer);
	// stw r9,-13988(r5)
	PPC_STORE_U32(ctx.r5.u32 + -13988, ctx.r9.u32);
	// stw r10,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r10.u32);
	// blt cr6,0x88132970
	if (ctx.cr6.lt) goto loc_88132970;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,-13988(r5)
	PPC_STORE_U32(ctx.r5.u32 + -13988, ctx.r9.u32);
loc_88132970:
	// lwz r9,300(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 300);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88132914
	if (ctx.cr6.eq) goto loc_88132914;
	// lwz r9,3912(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3912);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88132914
	if (ctx.cr6.eq) goto loc_88132914;
	// lis r9,-30643
	ctx.r9.s64 = -2008219648;
	// lwz r9,26272(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26272);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88132a68
	if (!ctx.cr6.eq) goto loc_88132A68;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r9,-13960
	ctx.r8.s64 = ctx.r9.s64 + -13960;
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x881329b4
	if (!ctx.cr6.eq) goto loc_881329B4;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x881329c0
	goto loc_881329C0;
loc_881329B4:
	// lis r7,4
	ctx.r7.s64 = 262144;
	// ori r6,r7,33864
	ctx.r6.u64 = ctx.r7.u64 | 33864;
	// lwzx r7,r9,r6
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
loc_881329C0:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x881329d4
	if (!ctx.cr6.eq) goto loc_881329D4;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x881329e0
	goto loc_881329E0;
loc_881329D4:
	// lis r8,2
	ctx.r8.s64 = 131072;
	// ori r6,r8,53260
	ctx.r6.u64 = ctx.r8.u64 | 53260;
	// lwzx r8,r9,r6
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
loc_881329E0:
	// lwz r9,3892(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3892);
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x88132a28
	if (!ctx.cr6.lt) goto loc_88132A28;
	// lwz r9,3896(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3896);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x88132a28
	if (!ctx.cr6.lt) goto loc_88132A28;
	// lwz r9,3924(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3924);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x88132a68
	if (ctx.cr6.eq) goto loc_88132A68;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r10,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r10.u32);
	// stw r9,3924(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3924, ctx.r9.u32);
	// bge 0x88132a70
	if (!ctx.cr0.lt) goto loc_88132A70;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r10,3920(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3920);
	// stw r9,-13988(r5)
	PPC_STORE_U32(ctx.r5.u32 + -13988, ctx.r9.u32);
	// b 0x88132a6c
	goto loc_88132A6C;
loc_88132A28:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r10.u32);
	// bge 0x88132a70
	if (!ctx.cr0.lt) goto loc_88132A70;
	// lwz r8,3924(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3924);
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r10,3904(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3904);
	// lwz r7,3920(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3920);
	// lwz r9,3908(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3908);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r6,-13988(r5)
	PPC_STORE_U32(ctx.r5.u32 + -13988, ctx.r6.u32);
	// stw r10,3924(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3924, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r7.u32);
	// blt cr6,0x88132a70
	if (ctx.cr6.lt) goto loc_88132A70;
	// stw r9,3924(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3924, ctx.r9.u32);
	// b 0x88132a70
	goto loc_88132A70;
loc_88132A68:
	// li r10,0
	ctx.r10.s64 = 0;
loc_88132A6C:
	// stw r10,3916(r11)
	PPC_STORE_U32(ctx.r11.u32 + 3916, ctx.r10.u32);
loc_88132A70:
	// cmpwi cr6,r4,15
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 15, ctx.xer);
	// blt cr6,0x88132924
	if (ctx.cr6.lt) goto loc_88132924;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-13988(r5)
	PPC_STORE_U32(ctx.r5.u32 + -13988, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132A84"))) PPC_WEAK_FUNC(sub_88132A84);
PPC_FUNC_IMPL(__imp__sub_88132A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132A88"))) PPC_WEAK_FUNC(sub_88132A88);
PPC_FUNC_IMPL(__imp__sub_88132A88) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,90
	ctx.r11.s64 = 90;
	// stw r11,-10908(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10908, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132A98"))) PPC_WEAK_FUNC(sub_88132A98);
PPC_FUNC_IMPL(__imp__sub_88132A98) {
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
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r31,r11,26280
	ctx.r31.s64 = ctx.r11.s64 + 26280;
	// lwz r11,4028(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4028);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bgt cr6,0x88132b08
	if (ctx.cr6.gt) goto loc_88132B08;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x88132b08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132B08;
	// bdzf 4*cr6+eq,0x88132b3c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132B3C;
	// bdzf 4*cr6+eq,0x88132b60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132B60;
	// bdzf 4*cr6+eq,0x88132c34
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132C34;
	// bne cr6,0x88132cb8
	if (!ctx.cr6.eq) goto loc_88132CB8;
	// bl 0x88136548
	ctx.lr = 0x88132AE0;
	sub_88136548(ctx, base);
	// lwz r30,4024(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4024);
	// addi r11,r30,16
	ctx.r11.s64 = ctx.r30.s64 + 16;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x88152c60
	ctx.lr = 0x88132AF0;
	sub_88152C60(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r9,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
loc_88132B00:
	// stw r10,4028(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4028, ctx.r10.u32);
loc_88132B04:
	// stw r11,4036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4036, ctx.r11.u32);
loc_88132B08:
	// lwz r11,4032(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4032);
	// lis r10,255
	ctx.r10.s64 = 16711680;
	// li r9,248
	ctx.r9.s64 = 248;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stw r9,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r10.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
loc_88132B24:
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
loc_88132B3C:
	// lwz r11,4036(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4036);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132b50
	if (ctx.cr6.eq) goto loc_88132B50;
loc_88132B48:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x88132b04
	goto loc_88132B04;
loc_88132B50:
	// bl 0x88136c58
	ctx.lr = 0x88132B54;
	sub_88136C58(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x88132b00
	goto loc_88132B00;
loc_88132B60:
	// lwz r11,4036(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4036);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88132b48
	if (!ctx.cr6.eq) goto loc_88132B48;
	// bl 0x88136cd0
	ctx.lr = 0x88132B70;
	sub_88136CD0(ctx, base);
	// lwz r11,4040(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4040);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bgt cr6,0x88132be0
	if (ctx.cr6.gt) goto loc_88132BE0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x88132ba4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132BA4;
	// bdzf 4*cr6+eq,0x88132bb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132BB4;
	// bdzf 4*cr6+eq,0x88132bc4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_88132BC4;
	// bne cr6,0x88132bd4
	if (!ctx.cr6.eq) goto loc_88132BD4;
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// addi r11,r11,-4428
	ctx.r11.s64 = ctx.r11.s64 + -4428;
	// addi r3,r11,-96
	ctx.r3.s64 = ctx.r11.s64 + -96;
	// b 0x88132bdc
	goto loc_88132BDC;
loc_88132BA4:
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// addi r11,r11,-4428
	ctx.r11.s64 = ctx.r11.s64 + -4428;
	// addi r3,r11,-72
	ctx.r3.s64 = ctx.r11.s64 + -72;
	// b 0x88132bdc
	goto loc_88132BDC;
loc_88132BB4:
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// addi r11,r11,-4428
	ctx.r11.s64 = ctx.r11.s64 + -4428;
	// addi r3,r11,-48
	ctx.r3.s64 = ctx.r11.s64 + -48;
	// b 0x88132bdc
	goto loc_88132BDC;
loc_88132BC4:
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// addi r11,r11,-4428
	ctx.r11.s64 = ctx.r11.s64 + -4428;
	// addi r3,r11,-24
	ctx.r3.s64 = ctx.r11.s64 + -24;
	// b 0x88132bdc
	goto loc_88132BDC;
loc_88132BD4:
	// lis r11,-30719
	ctx.r11.s64 = -2013200384;
	// addi r3,r11,-4428
	ctx.r3.s64 = ctx.r11.s64 + -4428;
loc_88132BDC:
	// bl 0x880e3888
	ctx.lr = 0x88132BE0;
	sub_880E3888(ctx, base);
loc_88132BE0:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r3,4024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4024);
	// stw r11,6132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 6132, ctx.r11.u32);
	// bl 0x88094f38
	ctx.lr = 0x88132BF0;
	sub_88094F38(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r11,1992(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1992, ctx.r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,4024(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4024);
	// stw r10,120(r11)
	PPC_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lwz r11,4024(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4024);
	// stw r9,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r9.u32);
	// lwz r3,4024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4024);
	// bl 0x88136a58
	ctx.lr = 0x88132C18;
	sub_88136A58(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,284(r31)
	PPC_STORE_U32(ctx.r31.u32 + 284, ctx.r11.u32);
	// stw r10,4036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4036, ctx.r10.u32);
	// stw r9,4028(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4028, ctx.r9.u32);
	// b 0x88132b08
	goto loc_88132B08;
loc_88132C34:
	// lwz r11,4036(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4036);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132c8c
	if (ctx.cr6.eq) goto loc_88132C8C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4036, ctx.r11.u32);
	// bne 0x88132b08
	if (!ctx.cr0.eq) goto loc_88132B08;
	// lwz r3,4024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4024);
	// lwz r11,1860(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1860);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88132c80
	if (!ctx.cr6.eq) goto loc_88132C80;
	// lwz r11,1888(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1888);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88132c80
	if (ctx.cr6.eq) goto loc_88132C80;
	// lwz r11,4040(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4040);
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,4340
	ctx.r8.s64 = ctx.r10.s64 + 4340;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x88132578
	ctx.lr = 0x88132C80;
	sub_88132578(ctx, base);
loc_88132C80:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,280(r31)
	PPC_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// b 0x88132b08
	goto loc_88132B08;
loc_88132C8C:
	// lwz r11,4032(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4032);
	// addic r11,r11,-6
	ctx.xer.ca = ctx.r11.u32 > 5;
	ctx.r11.s64 = ctx.r11.s64 + -6;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r11,4032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4032, ctx.r11.u32);
	// cmpwi r10,0
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt 0x88132b08
	if (ctx.cr0.gt) goto loc_88132B08;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r10,4032(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4032, ctx.r10.u32);
	// stw r11,4028(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4028, ctx.r11.u32);
	// b 0x88132b08
	goto loc_88132B08;
loc_88132CB8:
	// bl 0x88152c60
	ctx.lr = 0x88132CBC;
	sub_88152C60(ctx, base);
	// b 0x88132b24
	goto loc_88132B24;
}

__attribute__((alias("__imp__sub_88132CC0"))) PPC_WEAK_FUNC(sub_88132CC0);
PPC_FUNC_IMPL(__imp__sub_88132CC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88132CC8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r31,r11,30304
	ctx.r31.s64 = ctx.r11.s64 + 30304;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88073bd0
	ctx.lr = 0x88132CEC;
	sub_88073BD0(ctx, base);
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r30,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// li r8,255
	ctx.r8.s64 = 255;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lwz r9,88(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 88);
	// lwz r11,-25268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25268);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88132d7c
	if (ctx.cr6.eq) goto loc_88132D7C;
loc_88132D1C:
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r29
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x88132d38
	if (ctx.cr6.eq) goto loc_88132D38;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88132d1c
	if (!ctx.cr6.eq) goto loc_88132D1C;
	// b 0x88132d44
	goto loc_88132D44;
loc_88132D38:
	// lis r9,-30701
	ctx.r9.s64 = -2012020736;
	// addi r8,r9,10904
	ctx.r8.s64 = ctx.r9.s64 + 10904;
	// stw r8,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r8.u32);
loc_88132D44:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88132d7c
	if (ctx.cr6.eq) goto loc_88132D7C;
loc_88132D4C:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r29
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x88132d6c
	if (ctx.cr6.eq) goto loc_88132D6C;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88132d4c
	if (!ctx.cr6.eq) goto loc_88132D4C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88132D6C:
	// lis r10,-30701
	ctx.r10.s64 = -2012020736;
	// stw r31,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r31.u32);
	// addi r9,r10,10888
	ctx.r9.s64 = ctx.r10.s64 + 10888;
	// stw r9,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
loc_88132D7C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88132D84"))) PPC_WEAK_FUNC(sub_88132D84);
PPC_FUNC_IMPL(__imp__sub_88132D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132D88"))) PPC_WEAK_FUNC(sub_88132D88);
PPC_FUNC_IMPL(__imp__sub_88132D88) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132D94"))) PPC_WEAK_FUNC(sub_88132D94);
PPC_FUNC_IMPL(__imp__sub_88132D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132D98"))) PPC_WEAK_FUNC(sub_88132D98);
PPC_FUNC_IMPL(__imp__sub_88132D98) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DA0"))) PPC_WEAK_FUNC(sub_88132DA0);
PPC_FUNC_IMPL(__imp__sub_88132DA0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DA8"))) PPC_WEAK_FUNC(sub_88132DA8);
PPC_FUNC_IMPL(__imp__sub_88132DA8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DB0"))) PPC_WEAK_FUNC(sub_88132DB0);
PPC_FUNC_IMPL(__imp__sub_88132DB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DB8"))) PPC_WEAK_FUNC(sub_88132DB8);
PPC_FUNC_IMPL(__imp__sub_88132DB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,28(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DC0"))) PPC_WEAK_FUNC(sub_88132DC0);
PPC_FUNC_IMPL(__imp__sub_88132DC0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88132dd0
	if (!ctx.cr6.eq) goto loc_88132DD0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_88132DD0:
	// lwz r3,136(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DD8"))) PPC_WEAK_FUNC(sub_88132DD8);
PPC_FUNC_IMPL(__imp__sub_88132DD8) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,6(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DE4"))) PPC_WEAK_FUNC(sub_88132DE4);
PPC_FUNC_IMPL(__imp__sub_88132DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132DE8"))) PPC_WEAK_FUNC(sub_88132DE8);
PPC_FUNC_IMPL(__imp__sub_88132DE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,180(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132DF0"))) PPC_WEAK_FUNC(sub_88132DF0);
PPC_FUNC_IMPL(__imp__sub_88132DF0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88132dfc
	if (!ctx.cr6.eq) goto loc_88132DFC;
	// blr 
	return;
loc_88132DFC:
	// lwz r3,176(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132E04"))) PPC_WEAK_FUNC(sub_88132E04);
PPC_FUNC_IMPL(__imp__sub_88132E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132E08"))) PPC_WEAK_FUNC(sub_88132E08);
PPC_FUNC_IMPL(__imp__sub_88132E08) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r9,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r9.u32);
	// stw r10,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r10.u32);
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132E40"))) PPC_WEAK_FUNC(sub_88132E40);
PPC_FUNC_IMPL(__imp__sub_88132E40) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132E50"))) PPC_WEAK_FUNC(sub_88132E50);
PPC_FUNC_IMPL(__imp__sub_88132E50) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x88132e5c
	if (!ctx.cr6.eq) goto loc_88132E5C;
	// blr 
	return;
loc_88132E5C:
	// lwz r3,164(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132E64"))) PPC_WEAK_FUNC(sub_88132E64);
PPC_FUNC_IMPL(__imp__sub_88132E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88132E68"))) PPC_WEAK_FUNC(sub_88132E68);
PPC_FUNC_IMPL(__imp__sub_88132E68) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r4,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132E78"))) PPC_WEAK_FUNC(sub_88132E78);
PPC_FUNC_IMPL(__imp__sub_88132E78) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,160(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132E80"))) PPC_WEAK_FUNC(sub_88132E80);
PPC_FUNC_IMPL(__imp__sub_88132E80) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x88132e90
	if (!ctx.cr6.eq) goto loc_88132E90;
	// lwz r3,148(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// blr 
	return;
loc_88132E90:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x88132ea0
	if (!ctx.cr6.eq) goto loc_88132EA0;
	// lwz r3,152(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// blr 
	return;
loc_88132EA0:
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bne cr6,0x88132eb0
	if (!ctx.cr6.eq) goto loc_88132EB0;
	// lwz r3,156(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// blr 
	return;
loc_88132EB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88132EB8"))) PPC_WEAK_FUNC(sub_88132EB8);
PPC_FUNC_IMPL(__imp__sub_88132EB8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// blt cr6,0x88132ec8
	if (ctx.cr6.lt) goto loc_88132EC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88132EC8:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x88132f0c
	if (!ctx.cr6.eq) goto loc_88132F0C;
	// lwz r9,144(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// beq cr6,0x88132ef8
	if (ctx.cr6.eq) goto loc_88132EF8;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// stw r9,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r9.u32);
	// b 0x88132fd0
	goto loc_88132FD0;
loc_88132EF8:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r9,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r9.u32);
	// b 0x88132fd0
	goto loc_88132FD0;
loc_88132F0C:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x88132f50
	if (!ctx.cr6.eq) goto loc_88132F50;
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// beq cr6,0x88132f3c
	if (ctx.cr6.eq) goto loc_88132F3C;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// stw r9,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r9.u32);
	// b 0x88132fd0
	goto loc_88132FD0;
loc_88132F3C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// stw r9,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r9.u32);
	// b 0x88132fd0
	goto loc_88132FD0;
loc_88132F50:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x88132f94
	if (!ctx.cr6.eq) goto loc_88132F94;
	// lwz r9,152(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// beq cr6,0x88132f80
	if (ctx.cr6.eq) goto loc_88132F80;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// addi r8,r10,14
	ctx.r8.s64 = ctx.r10.s64 + 14;
	// addi r7,r11,14
	ctx.r7.s64 = ctx.r11.s64 + 14;
	// stw r9,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r9.u32);
	// b 0x88132fd0
	goto loc_88132FD0;
loc_88132F80:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r10,7
	ctx.r8.s64 = ctx.r10.s64 + 7;
	// addi r7,r11,7
	ctx.r7.s64 = ctx.r11.s64 + 7;
	// stw r9,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r9.u32);
	// b 0x88132fd0
	goto loc_88132FD0;
loc_88132F94:
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bne cr6,0x88132fd8
	if (!ctx.cr6.eq) goto loc_88132FD8;
	// lwz r9,156(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// beq cr6,0x88132fc0
	if (ctx.cr6.eq) goto loc_88132FC0;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// addi r8,r10,26
	ctx.r8.s64 = ctx.r10.s64 + 26;
	// addi r7,r11,26
	ctx.r7.s64 = ctx.r11.s64 + 26;
	// b 0x88132fcc
	goto loc_88132FCC;
loc_88132FC0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r10,13
	ctx.r8.s64 = ctx.r10.s64 + 13;
	// addi r7,r11,13
	ctx.r7.s64 = ctx.r11.s64 + 13;
loc_88132FCC:
	// stw r9,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r9.u32);
loc_88132FD0:
	// stw r7,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r7.u32);
	// stw r8,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r8.u32);
loc_88132FD8:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// ori r11,r11,34463
	ctx.r11.u64 = ctx.r11.u64 | 34463;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88132ff0
	if (ctx.cr6.lt) goto loc_88132FF0;
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r11.u32);
loc_88132FF0:
	// lis r11,15
	ctx.r11.s64 = 983040;
	// lwz r10,164(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// ori r11,r11,16959
	ctx.r11.u64 = ctx.r11.u64 | 16959;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x88133008
	if (ctx.cr6.lt) goto loc_88133008;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r11.u32);
loc_88133008:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133010"))) PPC_WEAK_FUNC(sub_88133010);
PPC_FUNC_IMPL(__imp__sub_88133010) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,7(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 7);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// blt cr6,0x88133034
	if (ctx.cr6.lt) goto loc_88133034;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8813302c
	if (ctx.cr6.eq) goto loc_8813302C;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_8813302C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88133034:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133048"))) PPC_WEAK_FUNC(sub_88133048);
PPC_FUNC_IMPL(__imp__sub_88133048) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,7(r11)
	PPC_STORE_U8(ctx.r11.u32 + 7, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133058"))) PPC_WEAK_FUNC(sub_88133058);
PPC_FUNC_IMPL(__imp__sub_88133058) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,10(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133060"))) PPC_WEAK_FUNC(sub_88133060);
PPC_FUNC_IMPL(__imp__sub_88133060) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,10(r11)
	PPC_STORE_U8(ctx.r11.u32 + 10, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133070"))) PPC_WEAK_FUNC(sub_88133070);
PPC_FUNC_IMPL(__imp__sub_88133070) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,9(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 9);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133078"))) PPC_WEAK_FUNC(sub_88133078);
PPC_FUNC_IMPL(__imp__sub_88133078) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,9(r11)
	PPC_STORE_U8(ctx.r11.u32 + 9, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133088"))) PPC_WEAK_FUNC(sub_88133088);
PPC_FUNC_IMPL(__imp__sub_88133088) {
	PPC_FUNC_PROLOGUE();
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133090"))) PPC_WEAK_FUNC(sub_88133090);
PPC_FUNC_IMPL(__imp__sub_88133090) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8813309c
	if (!ctx.cr6.eq) goto loc_8813309C;
	// blr 
	return;
loc_8813309C:
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330A4"))) PPC_WEAK_FUNC(sub_881330A4);
PPC_FUNC_IMPL(__imp__sub_881330A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881330A8"))) PPC_WEAK_FUNC(sub_881330A8);
PPC_FUNC_IMPL(__imp__sub_881330A8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330B0"))) PPC_WEAK_FUNC(sub_881330B0);
PPC_FUNC_IMPL(__imp__sub_881330B0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330B8"))) PPC_WEAK_FUNC(sub_881330B8);
PPC_FUNC_IMPL(__imp__sub_881330B8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,8(r11)
	PPC_STORE_U8(ctx.r11.u32 + 8, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330C8"))) PPC_WEAK_FUNC(sub_881330C8);
PPC_FUNC_IMPL(__imp__sub_881330C8) {
	PPC_FUNC_PROLOGUE();
	// lhz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330D4"))) PPC_WEAK_FUNC(sub_881330D4);
PPC_FUNC_IMPL(__imp__sub_881330D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881330D8"))) PPC_WEAK_FUNC(sub_881330D8);
PPC_FUNC_IMPL(__imp__sub_881330D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330E0"))) PPC_WEAK_FUNC(sub_881330E0);
PPC_FUNC_IMPL(__imp__sub_881330E0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881330E8"))) PPC_WEAK_FUNC(sub_881330E8);
PPC_FUNC_IMPL(__imp__sub_881330E8) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x881330f8
	if (ctx.cr6.eq) goto loc_881330F8;
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_881330F8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x88133108
	if (ctx.cr6.eq) goto loc_88133108;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
loc_88133108:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133110"))) PPC_WEAK_FUNC(sub_88133110);
PPC_FUNC_IMPL(__imp__sub_88133110) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r5,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133124"))) PPC_WEAK_FUNC(sub_88133124);
PPC_FUNC_IMPL(__imp__sub_88133124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133128"))) PPC_WEAK_FUNC(sub_88133128);
PPC_FUNC_IMPL(__imp__sub_88133128) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r9,68(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 68);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133144"))) PPC_WEAK_FUNC(sub_88133144);
PPC_FUNC_IMPL(__imp__sub_88133144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133148"))) PPC_WEAK_FUNC(sub_88133148);
PPC_FUNC_IMPL(__imp__sub_88133148) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r4,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r5,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813315C"))) PPC_WEAK_FUNC(sub_8813315C);
PPC_FUNC_IMPL(__imp__sub_8813315C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133160"))) PPC_WEAK_FUNC(sub_88133160);
PPC_FUNC_IMPL(__imp__sub_88133160) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813316C"))) PPC_WEAK_FUNC(sub_8813316C);
PPC_FUNC_IMPL(__imp__sub_8813316C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133170"))) PPC_WEAK_FUNC(sub_88133170);
PPC_FUNC_IMPL(__imp__sub_88133170) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// clrlwi r3,r11,31
	ctx.r3.u64 = ctx.r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813317C"))) PPC_WEAK_FUNC(sub_8813317C);
PPC_FUNC_IMPL(__imp__sub_8813317C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133180"))) PPC_WEAK_FUNC(sub_88133180);
PPC_FUNC_IMPL(__imp__sub_88133180) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813318C"))) PPC_WEAK_FUNC(sub_8813318C);
PPC_FUNC_IMPL(__imp__sub_8813318C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133190"))) PPC_WEAK_FUNC(sub_88133190);
PPC_FUNC_IMPL(__imp__sub_88133190) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813319C"))) PPC_WEAK_FUNC(sub_8813319C);
PPC_FUNC_IMPL(__imp__sub_8813319C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881331A0"))) PPC_WEAK_FUNC(sub_881331A0);
PPC_FUNC_IMPL(__imp__sub_881331A0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r4.u32);
	// stw r5,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881331AC"))) PPC_WEAK_FUNC(sub_881331AC);
PPC_FUNC_IMPL(__imp__sub_881331AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881331B0"))) PPC_WEAK_FUNC(sub_881331B0);
PPC_FUNC_IMPL(__imp__sub_881331B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881331B8"))) PPC_WEAK_FUNC(sub_881331B8);
PPC_FUNC_IMPL(__imp__sub_881331B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881331C0"))) PPC_WEAK_FUNC(sub_881331C0);
PPC_FUNC_IMPL(__imp__sub_881331C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881331C8"))) PPC_WEAK_FUNC(sub_881331C8);
PPC_FUNC_IMPL(__imp__sub_881331C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88133200
	if (!ctx.cr6.eq) goto loc_88133200;
	// lwz r11,76(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88133200
	if (!ctx.cr6.eq) goto loc_88133200;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r9,r11,26432
	ctx.r9.s64 = ctx.r11.s64 + 26432;
	// lwz r11,200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 200);
	// addi r8,r11,51
	ctx.r8.s64 = ctx.r11.s64 + 51;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// blr 
	return;
loc_88133200:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133208"))) PPC_WEAK_FUNC(sub_88133208);
PPC_FUNC_IMPL(__imp__sub_88133208) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// lwz r9,128(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,84(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133224"))) PPC_WEAK_FUNC(sub_88133224);
PPC_FUNC_IMPL(__imp__sub_88133224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133228"))) PPC_WEAK_FUNC(sub_88133228);
PPC_FUNC_IMPL(__imp__sub_88133228) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,24(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lwz r8,128(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lwz r7,92(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// lwz r6,128(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lwz r5,100(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// lwz r11,128(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lbz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lbz r8,9(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// lwz r7,28(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r7,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r7.u32);
	// lbz r6,1(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// subfic r5,r6,255
	ctx.xer.ca = ctx.r6.u32 <= 255;
	ctx.r5.s64 = 255 - ctx.r6.s64;
	// stb r5,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, ctx.r5.u8);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// subfic r9,r10,255
	ctx.xer.ca = ctx.r10.u32 <= 255;
	ctx.r9.s64 = 255 - ctx.r10.s64;
	// stb r9,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r9.u8);
	// lbz r7,1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// subfic r6,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r6.s64 = 255 - ctx.r7.s64;
	// stb r6,34(r3)
	PPC_STORE_U8(ctx.r3.u32 + 34, ctx.r6.u8);
	// lbz r4,1(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// subfic r11,r4,255
	ctx.xer.ca = ctx.r4.u32 <= 255;
	ctx.r11.s64 = 255 - ctx.r4.s64;
	// stb r11,35(r3)
	PPC_STORE_U8(ctx.r3.u32 + 35, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881332AC"))) PPC_WEAK_FUNC(sub_881332AC);
PPC_FUNC_IMPL(__imp__sub_881332AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881332B0"))) PPC_WEAK_FUNC(sub_881332B0);
PPC_FUNC_IMPL(__imp__sub_881332B0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x881332c8
	if (ctx.cr6.eq) goto loc_881332C8;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lbz r10,364(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 364);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
loc_881332C8:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x881332e0
	if (ctx.cr6.eq) goto loc_881332E0;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lbz r10,365(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 365);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
loc_881332E0:
	// lwz r3,140(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881332E8"))) PPC_WEAK_FUNC(sub_881332E8);
PPC_FUNC_IMPL(__imp__sub_881332E8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// li r8,9
	ctx.r8.s64 = 9;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// blt cr6,0x88133304
	if (ctx.cr6.lt) goto loc_88133304;
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
loc_88133304:
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r10,1852
	ctx.r9.s64 = ctx.r10.s64 + 1852;
	// lbz r9,1852(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1852);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stb r9,1852(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1852, ctx.r9.u8);
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lbz r5,1852(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 1852);
	// cmplwi cr6,r5,9
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 9, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stb r8,1852(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1852, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133344"))) PPC_WEAK_FUNC(sub_88133344);
PPC_FUNC_IMPL(__imp__sub_88133344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133348"))) PPC_WEAK_FUNC(sub_88133348);
PPC_FUNC_IMPL(__imp__sub_88133348) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r11,90
	ctx.r11.s64 = 90;
	// li r9,9
	ctx.r9.s64 = 9;
	// stb r11,365(r10)
	PPC_STORE_U8(ctx.r10.u32 + 365, ctx.r11.u8);
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stb r11,366(r8)
	PPC_STORE_U8(ctx.r8.u32 + 366, ctx.r11.u8);
	// lwz r7,128(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stb r9,364(r7)
	PPC_STORE_U8(ctx.r7.u32 + 364, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813336C"))) PPC_WEAK_FUNC(sub_8813336C);
PPC_FUNC_IMPL(__imp__sub_8813336C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133370"))) PPC_WEAK_FUNC(sub_88133370);
PPC_FUNC_IMPL(__imp__sub_88133370) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lis r8,-30643
	ctx.r8.s64 = -2008219648;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r9,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, ctx.r9.u32);
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// li r10,224
	ctx.r10.s64 = 224;
	// stw r7,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,112(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 112);
	// rlwinm r5,r6,28,4,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r4,r5,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r10,26276(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26276, ctx.r10.u32);
	// subf r10,r5,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r5.s64;
	// stw r10,112(r11)
	PPC_STORE_U32(ctx.r11.u32 + 112, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881333B4"))) PPC_WEAK_FUNC(sub_881333B4);
PPC_FUNC_IMPL(__imp__sub_881333B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881333B8"))) PPC_WEAK_FUNC(sub_881333B8);
PPC_FUNC_IMPL(__imp__sub_881333B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,1884(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1884);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x881333d8
	if (!ctx.cr6.eq) goto loc_881333D8;
	// lbz r10,6(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stb r9,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r9.u8);
loc_881333D8:
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,6
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 6, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r10,6
	ctx.r10.s64 = 6;
	// stb r10,6(r11)
	PPC_STORE_U8(ctx.r11.u32 + 6, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881333F8"))) PPC_WEAK_FUNC(sub_881333F8);
PPC_FUNC_IMPL(__imp__sub_881333F8) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x88133408
	if (!ctx.cr6.eq) goto loc_88133408;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_88133408:
	// lwz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// li r8,48
	ctx.r8.s64 = 48;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881334b4
	if (ctx.cr6.eq) goto loc_881334B4;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x88133488
	if (!ctx.cr6.eq) goto loc_88133488;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r9,3
	ctx.r9.s64 = 3;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// bne cr6,0x88133454
	if (!ctx.cr6.eq) goto loc_88133454;
	// lwz r6,88(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// li r7,1
	ctx.r7.s64 = 1;
	// subfic r5,r6,4
	ctx.xer.ca = ctx.r6.u32 <= 4;
	ctx.r5.s64 = 4 - ctx.r6.s64;
	// stw r7,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r7.u32);
	// rlwinm r11,r5,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r4,r11,3
	ctx.r4.s64 = ctx.r11.s64 + 3;
	// stw r4,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r4.u32);
	// b 0x88133470
	goto loc_88133470;
loc_88133454:
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r9,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r9.u32);
	// subfic r6,r7,4
	ctx.xer.ca = ctx.r7.u32 <= 4;
	ctx.r6.s64 = 4 - ctx.r7.s64;
	// rlwinm r11,r6,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,10
	ctx.r5.s64 = ctx.r11.s64 + 10;
	// stw r5,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r5.u32);
loc_88133470:
	// lwz r11,176(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x8813351c
	if (ctx.cr6.lt) goto loc_8813351C;
	// stw r8,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r8.u32);
	// stw r9,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r9.u32);
	// b 0x8813351c
	goto loc_8813351C;
loc_88133488:
	// li r11,6
	ctx.r11.s64 = 6;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// bne cr6,0x881334a0
	if (!ctx.cr6.eq) goto loc_881334A0;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r9.u32);
	// b 0x881334a4
	goto loc_881334A4;
loc_881334A0:
	// stw r11,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r11.u32);
loc_881334A4:
	// cmpwi cr6,r10,48
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 48, ctx.xer);
	// blt cr6,0x8813351c
	if (ctx.cr6.lt) goto loc_8813351C;
	// stw r8,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r8.u32);
	// b 0x88133518
	goto loc_88133518;
loc_881334B4:
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x88133508
	if (!ctx.cr6.eq) goto loc_88133508;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// subfic r7,r9,4
	ctx.xer.ca = ctx.r9.u32 <= 4;
	ctx.r7.s64 = 4 - ctx.r9.s64;
	// rlwinm r11,r7,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// bne cr6,0x881334e0
	if (!ctx.cr6.eq) goto loc_881334E0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r6,r11,4
	ctx.r6.s64 = ctx.r11.s64 + 4;
	// b 0x881334e8
	goto loc_881334E8;
loc_881334E0:
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r6,r11,12
	ctx.r6.s64 = ctx.r11.s64 + 12;
loc_881334E8:
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stw r6,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r6.u32);
	// stw r10,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r10.u32);
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x8813351c
	if (ctx.cr6.lt) goto loc_8813351C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r8,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r8.u32);
	// b 0x88133518
	goto loc_88133518;
loc_88133508:
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// li r11,3
	ctx.r11.s64 = 3;
	// beq cr6,0x88133518
	if (ctx.cr6.eq) goto loc_88133518;
	// li r11,6
	ctx.r11.s64 = 6;
loc_88133518:
	// stw r11,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r11.u32);
loc_8813351C:
	// lwz r11,176(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// cmpwi cr6,r11,48
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 48, ctx.xer);
	// blt cr6,0x8813352c
	if (ctx.cr6.lt) goto loc_8813352C;
	// stw r8,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r8.u32);
loc_8813352C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133534"))) PPC_WEAK_FUNC(sub_88133534);
PPC_FUNC_IMPL(__imp__sub_88133534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133538"))) PPC_WEAK_FUNC(sub_88133538);
PPC_FUNC_IMPL(__imp__sub_88133538) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r11,r11,-7
	ctx.r11.s64 = ctx.r11.s64 + -7;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r11.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133568"))) PPC_WEAK_FUNC(sub_88133568);
PPC_FUNC_IMPL(__imp__sub_88133568) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,160(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r11.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// beq cr6,0x88133598
	if (ctx.cr6.eq) goto loc_88133598;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r11.u32);
	// blr 
	return;
loc_88133598:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881335AC"))) PPC_WEAK_FUNC(sub_881335AC);
PPC_FUNC_IMPL(__imp__sub_881335AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881335B0"))) PPC_WEAK_FUNC(sub_881335B0);
PPC_FUNC_IMPL(__imp__sub_881335B0) {
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
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// blt cr6,0x881335dc
	if (ctx.cr6.lt) goto loc_881335DC;
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
loc_881335DC:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8813361c
	if (!ctx.cr6.eq) goto loc_8813361C;
	// lwz r9,144(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// beq cr6,0x88133608
	if (ctx.cr6.eq) goto loc_88133608;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// stw r7,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r7.u32);
	// b 0x881336d0
	goto loc_881336D0;
loc_88133608:
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r7,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r7.u32);
	// b 0x881336d0
	goto loc_881336D0;
loc_8813361C:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x8813365c
	if (!ctx.cr6.eq) goto loc_8813365C;
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// beq cr6,0x88133648
	if (ctx.cr6.eq) goto loc_88133648;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// stw r7,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r7.u32);
	// b 0x881336d0
	goto loc_881336D0;
loc_88133648:
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// stw r7,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r7.u32);
	// b 0x881336d0
	goto loc_881336D0;
loc_8813365C:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x88133694
	if (!ctx.cr6.eq) goto loc_88133694;
	// lwz r9,152(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// beq cr6,0x88133680
	if (ctx.cr6.eq) goto loc_88133680;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// stw r7,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r7.u32);
	// b 0x881336c8
	goto loc_881336C8;
loc_88133680:
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// addi r6,r10,5
	ctx.r6.s64 = ctx.r10.s64 + 5;
	// stw r7,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r7.u32);
	// b 0x881336d0
	goto loc_881336D0;
loc_88133694:
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bne cr6,0x881336d8
	if (!ctx.cr6.eq) goto loc_881336D8;
	// lwz r9,156(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// beq cr6,0x881336c0
	if (ctx.cr6.eq) goto loc_881336C0;
	// addi r7,r9,2
	ctx.r7.s64 = ctx.r9.s64 + 2;
	// addi r8,r11,20
	ctx.r8.s64 = ctx.r11.s64 + 20;
	// addi r6,r10,20
	ctx.r6.s64 = ctx.r10.s64 + 20;
	// stw r7,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r7.u32);
	// b 0x881336d0
	goto loc_881336D0;
loc_881336C0:
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// stw r7,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r7.u32);
loc_881336C8:
	// addi r6,r10,10
	ctx.r6.s64 = ctx.r10.s64 + 10;
	// addi r8,r11,10
	ctx.r8.s64 = ctx.r11.s64 + 10;
loc_881336D0:
	// stw r6,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r6.u32);
	// stw r8,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r8.u32);
loc_881336D8:
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r10,9999
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 9999, ctx.xer);
	// blt cr6,0x881336ec
	if (ctx.cr6.lt) goto loc_881336EC;
	// li r10,9999
	ctx.r10.s64 = 9999;
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
loc_881336EC:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,164(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// ori r10,r10,34463
	ctx.r10.u64 = ctx.r10.u64 | 34463;
	// cmpw cr6,r9,r10
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88133704
	if (ctx.cr6.lt) goto loc_88133704;
	// stw r10,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r10.u32);
loc_88133704:
	// cmpwi cr6,r11,30000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30000, ctx.xer);
	// bge cr6,0x88133768
	if (!ctx.cr6.lt) goto loc_88133768;
	// lwz r11,164(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmpwi cr6,r11,30000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30000, ctx.xer);
	// blt cr6,0x88133768
	if (ctx.cr6.lt) goto loc_88133768;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-16616
	ctx.r11.s64 = ctx.r11.s64 + -16616;
	// lwz r10,5876(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5876);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88133768
	if (ctx.cr6.eq) goto loc_88133768;
	// lwz r10,5868(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5868);
	// cmplwi cr6,r10,22
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 22, ctx.xer);
	// ble cr6,0x88133768
	if (!ctx.cr6.gt) goto loc_88133768;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88133760
	if (!ctx.cr6.eq) goto loc_88133760;
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x8808d1b8
	ctx.lr = 0x8813374C;
	sub_8808D1B8(ctx, base);
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
loc_88133760:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r10.u32);
loc_88133768:
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

__attribute__((alias("__imp__sub_8813377C"))) PPC_WEAK_FUNC(sub_8813377C);
PPC_FUNC_IMPL(__imp__sub_8813377C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133780"))) PPC_WEAK_FUNC(sub_88133780);
PPC_FUNC_IMPL(__imp__sub_88133780) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88133788;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,160(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 4, ctx.xer);
	// blt cr6,0x881337a8
	if (ctx.cr6.lt) goto loc_881337A8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881337A8:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x88133800
	if (!ctx.cr6.eq) goto loc_88133800;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x881337dc
	if (ctx.cr6.eq) goto loc_881337DC;
	// lwz r11,144(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// addi r9,r29,4
	ctx.r9.s64 = ctx.r29.s64 + 4;
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r8,r11,2
	ctx.r8.s64 = ctx.r11.s64 + 2;
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// addi r7,r10,4
	ctx.r7.s64 = ctx.r10.s64 + 4;
	// stw r8,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r8.u32);
	// stw r7,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r7.u32);
	// b 0x8813389c
	goto loc_8813389C;
loc_881337DC:
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 144);
	// addi r9,r29,2
	ctx.r9.s64 = ctx.r29.s64 + 2;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// stw r8,144(r31)
	PPC_STORE_U32(ctx.r31.u32 + 144, ctx.r8.u32);
	// stw r7,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r7.u32);
	// b 0x8813389c
	goto loc_8813389C;
loc_88133800:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x88133850
	if (!ctx.cr6.eq) goto loc_88133850;
	// lwz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// beq cr6,0x88133834
	if (ctx.cr6.eq) goto loc_88133834;
	// addi r9,r29,10
	ctx.r9.s64 = ctx.r29.s64 + 10;
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r7,r11,10
	ctx.r7.s64 = ctx.r11.s64 + 10;
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// stw r8,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r8.u32);
	// stw r7,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r7.u32);
	// b 0x8813389c
	goto loc_8813389C;
loc_88133834:
	// addi r9,r29,5
	ctx.r9.s64 = ctx.r29.s64 + 5;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r7,r11,5
	ctx.r7.s64 = ctx.r11.s64 + 5;
	// stw r9,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r9.u32);
	// stw r8,148(r31)
	PPC_STORE_U32(ctx.r31.u32 + 148, ctx.r8.u32);
	// stw r7,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r7.u32);
	// b 0x8813389c
	goto loc_8813389C;
loc_88133850:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x88133874
	if (!ctx.cr6.eq) goto loc_88133874;
	// lwz r11,152(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// addi r10,r29,10
	ctx.r10.s64 = ctx.r29.s64 + 10;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r8,r11,10
	ctx.r8.s64 = ctx.r11.s64 + 10;
	// stw r9,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r9.u32);
	// b 0x88133894
	goto loc_88133894;
loc_88133874:
	// cmplwi cr6,r4,3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 3, ctx.xer);
	// bne cr6,0x8813389c
	if (!ctx.cr6.eq) goto loc_8813389C;
	// lwz r11,156(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 156);
	// addi r10,r29,20
	ctx.r10.s64 = ctx.r29.s64 + 20;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r8,r11,20
	ctx.r8.s64 = ctx.r11.s64 + 20;
	// stw r9,156(r31)
	PPC_STORE_U32(ctx.r31.u32 + 156, ctx.r9.u32);
loc_88133894:
	// stw r8,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r8.u32);
	// stw r10,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r10.u32);
loc_8813389C:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,9999
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9999, ctx.xer);
	// blt cr6,0x881338b0
	if (ctx.cr6.lt) goto loc_881338B0;
	// li r11,9999
	ctx.r11.s64 = 9999;
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
loc_881338B0:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// lwz r10,164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// ori r11,r11,34463
	ctx.r11.u64 = ctx.r11.u64 | 34463;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x881338c8
	if (ctx.cr6.lt) goto loc_881338C8;
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
loc_881338C8:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// cmpwi cr6,r29,1000
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1000, ctx.xer);
	// addi r30,r11,-16616
	ctx.r30.s64 = ctx.r11.s64 + -16616;
	// bge cr6,0x8813391c
	if (!ctx.cr6.lt) goto loc_8813391C;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,1000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1000, ctx.xer);
	// blt cr6,0x8813391c
	if (ctx.cr6.lt) goto loc_8813391C;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813391c
	if (ctx.cr6.eq) goto loc_8813391C;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 26, ctx.xer);
	// ble cr6,0x8813391c
	if (!ctx.cr6.gt) goto loc_8813391C;
	// lwz r11,208(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 208);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88133914
	if (!ctx.cr6.eq) goto loc_88133914;
	// li r3,26
	ctx.r3.s64 = 26;
	// bl 0x8808d1b8
	ctx.lr = 0x88133910;
	sub_8808D1B8(ctx, base);
	// b 0x8813391c
	goto loc_8813391C;
loc_88133914:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,212(r30)
	PPC_STORE_U32(ctx.r30.u32 + 212, ctx.r11.u32);
loc_8813391C:
	// cmpwi cr6,r29,5000
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 5000, ctx.xer);
	// bge cr6,0x88133968
	if (!ctx.cr6.lt) goto loc_88133968;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,5000
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5000, ctx.xer);
	// blt cr6,0x88133968
	if (ctx.cr6.lt) goto loc_88133968;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88133968
	if (ctx.cr6.eq) goto loc_88133968;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 27, ctx.xer);
	// ble cr6,0x88133968
	if (!ctx.cr6.gt) goto loc_88133968;
	// lwz r11,216(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 216);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88133960
	if (!ctx.cr6.eq) goto loc_88133960;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x8808d1b8
	ctx.lr = 0x8813395C;
	sub_8808D1B8(ctx, base);
	// b 0x88133968
	goto loc_88133968;
loc_88133960:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,220(r30)
	PPC_STORE_U32(ctx.r30.u32 + 220, ctx.r11.u32);
loc_88133968:
	// cmpwi cr6,r29,9999
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 9999, ctx.xer);
	// bge cr6,0x881339bc
	if (!ctx.cr6.lt) goto loc_881339BC;
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,9999
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9999, ctx.xer);
	// blt cr6,0x881339bc
	if (ctx.cr6.lt) goto loc_881339BC;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881339bc
	if (ctx.cr6.eq) goto loc_881339BC;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 28, ctx.xer);
	// ble cr6,0x881339bc
	if (!ctx.cr6.gt) goto loc_881339BC;
	// lwz r11,224(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 224);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881339b4
	if (!ctx.cr6.eq) goto loc_881339B4;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x8808d1b8
	ctx.lr = 0x881339A8;
	sub_8808D1B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_881339B4:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,228(r30)
	PPC_STORE_U32(ctx.r30.u32 + 228, ctx.r11.u32);
loc_881339BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881339C8"))) PPC_WEAK_FUNC(sub_881339C8);
PPC_FUNC_IMPL(__imp__sub_881339C8) {
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
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,1880(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1880);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x881339f0
	if (!ctx.cr6.eq) goto loc_881339F0;
	// lhz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// sth r10,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r10.u16);
loc_881339F0:
	// lhz r11,2(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x88133a48
	if (ctx.cr6.gt) goto loc_88133A48;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-11048
	ctx.r11.s64 = ctx.r11.s64 + -11048;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x88133a34
	if (ctx.cr6.eq) goto loc_88133A34;
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// subfe r4,r8,r10
	temp.u8 = (~ctx.r8.u32 + ctx.r10.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r4.u64 = ~ctx.r8.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x88133A34;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_88133A34:
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
loc_88133A48:
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

__attribute__((alias("__imp__sub_88133A5C"))) PPC_WEAK_FUNC(sub_88133A5C);
PPC_FUNC_IMPL(__imp__sub_88133A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133A60"))) PPC_WEAK_FUNC(sub_88133A60);
PPC_FUNC_IMPL(__imp__sub_88133A60) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r9,1880(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1880);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x88133a80
	if (!ctx.cr6.eq) goto loc_88133A80;
	// lhz r10,2(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 2);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// sth r9,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r9.u16);
loc_88133A80:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x88133a9c
	if (ctx.cr6.lt) goto loc_88133A9C;
	// sth r10,4(r11)
	PPC_STORE_U16(ctx.r11.u32 + 4, ctx.r10.u16);
loc_88133A9C:
	RT_WITNESS3_GATE(ctx.r11.u32, (uint32_t)ctx.r9.s32);  // r23-w76 DRIVER, HARNESS-ONLY, NEVER SHIP
	// cmpwi cr6,r9,9
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 9, ctx.xer);
	// ble cr6,0x88133ab8
	if (!ctx.cr6.gt) goto loc_88133AB8;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r10,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r10.u16);
	// sth r10,4(r11)
	PPC_STORE_U16(ctx.r11.u32 + 4, ctx.r10.u16);
	// blr 
	return;
loc_88133AB8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133AC0"))) PPC_WEAK_FUNC(sub_88133AC0);
PPC_FUNC_IMPL(__imp__sub_88133AC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// lwz r11,120(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133AD4"))) PPC_WEAK_FUNC(sub_88133AD4);
PPC_FUNC_IMPL(__imp__sub_88133AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133AD8"))) PPC_WEAK_FUNC(sub_88133AD8);
PPC_FUNC_IMPL(__imp__sub_88133AD8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,-26112
	ctx.r9.s64 = ctx.r10.s64 + -26112;
	// li r8,256
	ctx.r8.s64 = 256;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// lbz r10,27(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 27);
	// stw r8,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r8.u32);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// stb r10,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r10.u8);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r11.u32);
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133B14"))) PPC_WEAK_FUNC(sub_88133B14);
PPC_FUNC_IMPL(__imp__sub_88133B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133B18"))) PPC_WEAK_FUNC(sub_88133B18);
PPC_FUNC_IMPL(__imp__sub_88133B18) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r11.u32);
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r11.u32);
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r11.u32);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r11.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x88133b58
	if (!ctx.cr6.eq) goto loc_88133B58;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r10.u32);
loc_88133B58:
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r11.u32);
	// stw r11,168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 168, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133B64"))) PPC_WEAK_FUNC(sub_88133B64);
PPC_FUNC_IMPL(__imp__sub_88133B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133B68"))) PPC_WEAK_FUNC(sub_88133B68);
PPC_FUNC_IMPL(__imp__sub_88133B68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88133B70;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r29,r11,26432
	ctx.r29.s64 = ctx.r11.s64 + 26432;
	// addi r31,r29,1576
	ctx.r31.s64 = ctx.r29.s64 + 1576;
loc_88133B84:
	// li r5,196
	ctx.r5.s64 = 196;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-128
	ctx.r3.s64 = ctx.r31.s64 + -128;
	// bl 0x88073bd0
	ctx.lr = 0x88133B94;
	sub_88073BD0(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stb r11,-127(r31)
	PPC_STORE_U8(ctx.r31.u32 + -127, ctx.r11.u8);
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// cmpwi cr6,r30,2
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 2, ctx.xer);
	// blt cr6,0x88133b84
	if (ctx.cr6.lt) goto loc_88133B84;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88133BB8"))) PPC_WEAK_FUNC(sub_88133BB8);
PPC_FUNC_IMPL(__imp__sub_88133BB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r8,128(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// lis r9,-30679
	ctx.r9.s64 = -2010578944;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// addi r11,r9,-13616
	ctx.r11.s64 = ctx.r9.s64 + -13616;
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// addi r8,r11,-160
	ctx.r8.s64 = ctx.r11.s64 + -160;
	// lbz r9,21(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 21);
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// bne cr6,0x88133be8
	if (!ctx.cr6.eq) goto loc_88133BE8;
	// lbz r9,22(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 22);
	// addi r8,r11,-80
	ctx.r8.s64 = ctx.r11.s64 + -80;
loc_88133BE8:
	// cmpwi cr6,r7,2
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 2, ctx.xer);
	// bne cr6,0x88133bf8
	if (!ctx.cr6.eq) goto loc_88133BF8;
	// lbz r9,23(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 23);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_88133BF8:
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r10,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stw r7,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r7.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r6,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133C2C"))) PPC_WEAK_FUNC(sub_88133C2C);
PPC_FUNC_IMPL(__imp__sub_88133C2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88133C30"))) PPC_WEAK_FUNC(sub_88133C30);
PPC_FUNC_IMPL(__imp__sub_88133C30) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r9,255
	ctx.r9.s64 = 255;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88133c48
	if (ctx.cr6.eq) goto loc_88133C48;
	// li r9,254
	ctx.r9.s64 = 254;
loc_88133C48:
	// addi r8,r11,475
	ctx.r8.s64 = ctx.r11.s64 + 475;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stbx r7,r6,r10
	PPC_STORE_U8(ctx.r6.u32 + ctx.r10.u32, ctx.r7.u8);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r10,1901(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1901, ctx.r10.u8);
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r8,1902(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1902, ctx.r8.u8);
	// stb r5,1903(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1903, ctx.r5.u8);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lbz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r8,84(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// mulli r11,r11,180
	ctx.r11.s64 = ctx.r11.s64 * 180;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// lbz r7,32(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88133ccc
	if (!ctx.cr6.eq) goto loc_88133CCC;
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r8,32(r10)
	PPC_STORE_U8(ctx.r10.u32 + 32, ctx.r8.u8);
	// lbz r7,1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r7,33(r10)
	PPC_STORE_U8(ctx.r10.u32 + 33, ctx.r7.u8);
	// lbz r6,2(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r6,34(r10)
	PPC_STORE_U8(ctx.r10.u32 + 34, ctx.r6.u8);
	// lbz r5,3(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r5,35(r10)
	PPC_STORE_U8(ctx.r10.u32 + 35, ctx.r5.u8);
loc_88133CCC:
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r10,404
	ctx.r10.s64 = ctx.r10.s64 + 404;
	// lbz r8,32(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88133d04
	if (!ctx.cr6.eq) goto loc_88133D04;
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r8,32(r10)
	PPC_STORE_U8(ctx.r10.u32 + 32, ctx.r8.u8);
	// lbz r7,1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r7,33(r10)
	PPC_STORE_U8(ctx.r10.u32 + 33, ctx.r7.u8);
	// lbz r6,2(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r6,34(r10)
	PPC_STORE_U8(ctx.r10.u32 + 34, ctx.r6.u8);
	// lbz r5,3(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r5,35(r10)
	PPC_STORE_U8(ctx.r10.u32 + 35, ctx.r5.u8);
loc_88133D04:
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r10,440
	ctx.r10.s64 = ctx.r10.s64 + 440;
	// lbz r8,32(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88133d3c
	if (!ctx.cr6.eq) goto loc_88133D3C;
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r8,32(r10)
	PPC_STORE_U8(ctx.r10.u32 + 32, ctx.r8.u8);
	// lbz r7,1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r7,33(r10)
	PPC_STORE_U8(ctx.r10.u32 + 33, ctx.r7.u8);
	// lbz r6,2(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r6,34(r10)
	PPC_STORE_U8(ctx.r10.u32 + 34, ctx.r6.u8);
	// lbz r5,3(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r5,35(r10)
	PPC_STORE_U8(ctx.r10.u32 + 35, ctx.r5.u8);
loc_88133D3C:
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r10,476
	ctx.r10.s64 = ctx.r10.s64 + 476;
	// lbz r8,32(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88133d74
	if (!ctx.cr6.eq) goto loc_88133D74;
	// lbz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r8,32(r10)
	PPC_STORE_U8(ctx.r10.u32 + 32, ctx.r8.u8);
	// lbz r7,1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r7,33(r10)
	PPC_STORE_U8(ctx.r10.u32 + 33, ctx.r7.u8);
	// lbz r6,2(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r6,34(r10)
	PPC_STORE_U8(ctx.r10.u32 + 34, ctx.r6.u8);
	// lbz r5,3(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r5,35(r10)
	PPC_STORE_U8(ctx.r10.u32 + 35, ctx.r5.u8);
loc_88133D74:
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// lbz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// stb r10,32(r11)
	PPC_STORE_U8(ctx.r11.u32 + 32, ctx.r10.u8);
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r9,33(r11)
	PPC_STORE_U8(ctx.r11.u32 + 33, ctx.r9.u8);
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r8,34(r11)
	PPC_STORE_U8(ctx.r11.u32 + 34, ctx.r8.u8);
	// lbz r7,3(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r7,35(r11)
	PPC_STORE_U8(ctx.r11.u32 + 35, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133DB0"))) PPC_WEAK_FUNC(sub_88133DB0);
PPC_FUNC_IMPL(__imp__sub_88133DB0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lbz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// lbz r6,1(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// rotlwi r7,r9,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// extsb r5,r6
	ctx.r5.s64 = ctx.r6.s8;
	// lwz r6,84(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// mulli r9,r9,180
	ctx.r9.s64 = ctx.r9.s64 * 180;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,400
	ctx.r10.s64 = ctx.r10.s64 + 400;
loc_88133DE4:
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x88133df8
	if (!ctx.cr6.eq) goto loc_88133DF8;
	// cmplwi cr6,r7,255
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 255, ctx.xer);
	// b 0x88133dfc
	goto loc_88133DFC;
loc_88133DF8:
	// cmplwi cr6,r7,254
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 254, ctx.xer);
loc_88133DFC:
	// beq cr6,0x88133e18
	if (ctx.cr6.eq) goto loc_88133E18;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// cmpwi cr6,r8,5
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 5, ctx.xer);
	// blt cr6,0x88133de4
	if (ctx.cr6.lt) goto loc_88133DE4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_88133E14:
	// blr 
	return;
loc_88133E18:
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// addi r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 1;
	// cmpw cr6,r10,r3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, ctx.xer);
	// beq cr6,0x88133e14
	if (ctx.cr6.eq) goto loc_88133E14;
	// stw r3,172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 172, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88133E30"))) PPC_WEAK_FUNC(sub_88133E30);
PPC_FUNC_IMPL(__imp__sub_88133E30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88133E38;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r11,312(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88134010
	if (!ctx.cr6.eq) goto loc_88134010;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// ld r9,1864(r11)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r11.u32 + 1864);
	// cmpld cr6,r10,r9
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r9.u64, ctx.xer);
	// ble cr6,0x88133e78
	if (!ctx.cr6.gt) goto loc_88133E78;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// std r10,1864(r11)
	PPC_STORE_U64(ctx.r11.u32 + 1864, ctx.r10.u64);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// stw r8,1872(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1872, ctx.r8.u32);
loc_88133E78:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// rotlwi r8,r10,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// lwz r7,84(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// mulli r10,r10,180
	ctx.r10.s64 = ctx.r10.s64 * 180;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,368
	ctx.r11.s64 = ctx.r11.s64 + 368;
loc_88133EA4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r6,r8
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x88133ec8
	if (ctx.cr6.gt) goto loc_88133EC8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// cmpwi cr6,r9,5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 5, ctx.xer);
	// blt cr6,0x88133ea4
	if (ctx.cr6.lt) goto loc_88133EA4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88133EC8:
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// bne cr6,0x88133f54
	if (!ctx.cr6.eq) goto loc_88133F54;
	// stw r6,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r7,92(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r5,100(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	// stw r5,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r5.u32);
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r3,104(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// stw r3,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r3.u32);
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lbz r9,9(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 9);
	// stw r9,24(r11)
	PPC_STORE_U32(ctx.r11.u32 + 24, ctx.r9.u32);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r8,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r8.u32);
	// lbz r7,1(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r6,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r6.s64 = 255 - ctx.r7.s64;
	// stb r6,32(r11)
	PPC_STORE_U8(ctx.r11.u32 + 32, ctx.r6.u8);
	// lbz r4,1(r31)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r3,r4,255
	ctx.xer.ca = ctx.r4.u32 <= 255;
	ctx.r3.s64 = 255 - ctx.r4.s64;
	// stb r3,33(r11)
	PPC_STORE_U8(ctx.r11.u32 + 33, ctx.r3.u8);
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r8,r9,255
	ctx.xer.ca = ctx.r9.u32 <= 255;
	ctx.r8.s64 = 255 - ctx.r9.s64;
	// stb r8,34(r11)
	PPC_STORE_U8(ctx.r11.u32 + 34, ctx.r8.u8);
	// lbz r6,1(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r5,r6,255
	ctx.xer.ca = ctx.r6.u32 <= 255;
	ctx.r5.s64 = 255 - ctx.r6.s64;
	// stb r5,35(r11)
	PPC_STORE_U8(ctx.r11.u32 + 35, ctx.r5.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88133F54:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// subfic r28,r9,4
	ctx.xer.ca = ctx.r9.u32 <= 4;
	ctx.r28.s64 = 4 - ctx.r9.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r11,512
	ctx.r30.s64 = ctx.r11.s64 + 512;
	// addi r29,r11,548
	ctx.r29.s64 = ctx.r11.s64 + 548;
	// ble cr6,0x88133f90
	if (!ctx.cr6.gt) goto loc_88133F90;
loc_88133F70:
	// addi r30,r30,-36
	ctx.r30.s64 = ctx.r30.s64 + -36;
	// addi r29,r29,-36
	ctx.r29.s64 = ctx.r29.s64 + -36;
	// li r5,36
	ctx.r5.s64 = 36;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x88072260
	ctx.lr = 0x88133F88;
	sub_88072260(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne 0x88133f70
	if (!ctx.cr0.eq) goto loc_88133F70;
loc_88133F90:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stw r9,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r7,92(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	// stw r7,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r7.u32);
	// lwz r6,128(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r5,100(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	// stw r5,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r5.u32);
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r3,104(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// stw r3,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r3.u32);
	// lbz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// stw r11,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lbz r10,9(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 9);
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// stw r9,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r9.u32);
	// lbz r8,1(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r7,r8,255
	ctx.xer.ca = ctx.r8.u32 <= 255;
	ctx.r7.s64 = 255 - ctx.r8.s64;
	// stb r7,32(r30)
	PPC_STORE_U8(ctx.r30.u32 + 32, ctx.r7.u8);
	// lbz r5,1(r31)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r4,r5,255
	ctx.xer.ca = ctx.r5.u32 <= 255;
	ctx.r4.s64 = 255 - ctx.r5.s64;
	// stb r4,33(r30)
	PPC_STORE_U8(ctx.r30.u32 + 33, ctx.r4.u8);
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r10,r11,255
	ctx.xer.ca = ctx.r11.u32 <= 255;
	ctx.r10.s64 = 255 - ctx.r11.s64;
	// stb r10,34(r30)
	PPC_STORE_U8(ctx.r30.u32 + 34, ctx.r10.u8);
	// lbz r8,1(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// subfic r7,r8,255
	ctx.xer.ca = ctx.r8.u32 <= 255;
	ctx.r7.s64 = 255 - ctx.r8.s64;
	// stb r7,35(r30)
	PPC_STORE_U8(ctx.r30.u32 + 35, ctx.r7.u8);
loc_88134010:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88134018"))) PPC_WEAK_FUNC(sub_88134018);
PPC_FUNC_IMPL(__imp__sub_88134018) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,90
	ctx.r11.s64 = 90;
	// stw r9,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r9.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// stb r11,365(r10)
	PPC_STORE_U8(ctx.r10.u32 + 365, ctx.r11.u8);
	// lwz r7,128(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stb r11,366(r7)
	PPC_STORE_U8(ctx.r7.u32 + 366, ctx.r11.u8);
	// lwz r6,128(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stb r8,364(r6)
	PPC_STORE_U8(ctx.r6.u32 + 364, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88134044"))) PPC_WEAK_FUNC(sub_88134044);
PPC_FUNC_IMPL(__imp__sub_88134044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134048"))) PPC_WEAK_FUNC(sub_88134048);
PPC_FUNC_IMPL(__imp__sub_88134048) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88134050;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x88139848
	ctx.lr = 0x88134064;
	sub_88139848(ctx, base);
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// lbz r9,25(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x88134090
	if (!ctx.cr6.eq) goto loc_88134090;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r9,r11,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// rlwinm r8,r10,0,26,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r9,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
loc_88134090:
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r11,r11,26432
	ctx.r11.s64 = ctx.r11.s64 + 26432;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 128);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x881340c4
	if (!ctx.cr6.eq) goto loc_881340C4;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r8,r10,0,28,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// rlwinm r7,r9,0,28,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFF0F;
	// rlwinm r8,r8,0,20,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// rlwinm r7,r7,0,20,17
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
loc_881340C4:
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x881340f0
	if (ctx.cr6.eq) goto loc_881340F0;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r8,r10,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF00;
	// rlwinm r7,r9,0,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF00;
	// rlwinm r8,r8,0,20,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// rlwinm r7,r7,0,20,17
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFCFFF;
	// stw r8,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r8.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
loc_881340F0:
	// lwz r11,132(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813423c
	if (ctx.cr6.eq) goto loc_8813423C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 56);
	// rlwinm r28,r11,0,0,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r5,64(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 64);
	// rlwinm r9,r10,0,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r4,60(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 60);
	// lwz r6,68(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 68);
	// subf. r11,r5,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r5.s64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r28,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// bge 0x88134130
	if (!ctx.cr0.lt) goto loc_88134130;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_88134130:
	// subf. r10,r6,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge 0x8813413c
	if (!ctx.cr0.lt) goto loc_8813413C;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_8813413C:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x88134154
	if (!ctx.cr6.lt) goto loc_88134154;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x88134160
	goto loc_88134160;
loc_88134154:
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_88134160:
	// lis r10,2
	ctx.r10.s64 = 131072;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8813417c
	if (ctx.cr6.gt) goto loc_8813417C;
	// stw r3,64(r30)
	PPC_STORE_U32(ctx.r30.u32 + 64, ctx.r3.u32);
	// stw r4,68(r30)
	PPC_STORE_U32(ctx.r30.u32 + 68, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8813417C:
	// bl 0x88153070
	ctx.lr = 0x88134180;
	sub_88153070(ctx, base);
	// rlwinm r11,r3,26,22,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 26) & 0x3FF;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813419c
	if (!ctx.cr6.eq) goto loc_8813419C;
	// ori r11,r28,1
	ctx.r11.u64 = ctx.r28.u64 | 1;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8813419C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881341b4
	if (!ctx.cr6.eq) goto loc_881341B4;
	// ori r11,r28,9
	ctx.r11.u64 = ctx.r28.u64 | 9;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_881341B4:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x881341cc
	if (!ctx.cr6.eq) goto loc_881341CC;
	// ori r11,r28,8
	ctx.r11.u64 = ctx.r28.u64 | 8;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_881341CC:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x881341e4
	if (!ctx.cr6.eq) goto loc_881341E4;
	// ori r11,r28,10
	ctx.r11.u64 = ctx.r28.u64 | 10;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_881341E4:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x881341fc
	if (!ctx.cr6.eq) goto loc_881341FC;
	// ori r11,r28,2
	ctx.r11.u64 = ctx.r28.u64 | 2;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_881341FC:
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x88134214
	if (!ctx.cr6.eq) goto loc_88134214;
	// ori r11,r28,6
	ctx.r11.u64 = ctx.r28.u64 | 6;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_88134214:
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8813422c
	if (!ctx.cr6.eq) goto loc_8813422C;
	// ori r11,r28,4
	ctx.r11.u64 = ctx.r28.u64 | 4;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
loc_8813422C:
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x8813423c
	if (!ctx.cr6.eq) goto loc_8813423C;
	// ori r11,r28,5
	ctx.r11.u64 = ctx.r28.u64 | 5;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_8813423C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88134244"))) PPC_WEAK_FUNC(sub_88134244);
PPC_FUNC_IMPL(__imp__sub_88134244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134248"))) PPC_WEAK_FUNC(sub_88134248);
PPC_FUNC_IMPL(__imp__sub_88134248) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88134250;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// lwz r29,24(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r9,r11,13
	ctx.r9.s64 = ctx.r11.s64 + 13;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x88152b00
	ctx.lr = 0x88134278;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8813428c
	if (!ctx.cr6.eq) goto loc_8813428C;
loc_88134280:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8813428C:
	// lwz r11,136(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 136);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88134280
	if (!ctx.cr6.eq) goto loc_88134280;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-4501
	ctx.r10.s64 = -294977536;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// ori r10,r10,10239
	ctx.r10.u64 = ctx.r10.u64 | 10239;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x881342b8
	if (ctx.cr6.lt) goto loc_881342B8;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
loc_881342B8:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813438c
	if (!ctx.cr6.eq) goto loc_8813438C;
	// lis r11,3051
	ctx.r11.s64 = 199950336;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// ori r11,r11,49664
	ctx.r11.u64 = ctx.r11.u64 | 49664;
	// addi r30,r10,-16616
	ctx.r30.s64 = ctx.r10.s64 + -16616;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x88134324
	if (ctx.cr6.lt) goto loc_88134324;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x88134324
	if (!ctx.cr6.lt) goto loc_88134324;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88134324
	if (ctx.cr6.eq) goto loc_88134324;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// ble cr6,0x88134324
	if (!ctx.cr6.gt) goto loc_88134324;
	// lwz r11,240(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 240);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8813431c
	if (!ctx.cr6.eq) goto loc_8813431C;
	// li r3,30
	ctx.r3.s64 = 30;
	// bl 0x8808d1b8
	ctx.lr = 0x88134318;
	sub_8808D1B8(ctx, base);
	// b 0x88134324
	goto loc_88134324;
loc_8813431C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,244(r30)
	PPC_STORE_U32(ctx.r30.u32 + 244, ctx.r11.u32);
loc_88134324:
	// lis r11,1525
	ctx.r11.s64 = 99942400;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// ori r11,r11,57600
	ctx.r11.u64 = ctx.r11.u64 | 57600;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8813444c
	if (ctx.cr6.lt) goto loc_8813444C;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8813444c
	if (!ctx.cr6.lt) goto loc_8813444C;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813444c
	if (ctx.cr6.eq) goto loc_8813444C;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 29, ctx.xer);
	// ble cr6,0x8813444c
	if (!ctx.cr6.gt) goto loc_8813444C;
	// lwz r11,232(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 232);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88134378
	if (!ctx.cr6.eq) goto loc_88134378;
	// li r3,29
	ctx.r3.s64 = 29;
	// bl 0x8808d1b8
	ctx.lr = 0x8813436C;
	sub_8808D1B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88134378:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,236(r30)
	PPC_STORE_U32(ctx.r30.u32 + 236, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_8813438C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8813444c
	if (!ctx.cr6.eq) goto loc_8813444C;
	// lis r11,4577
	ctx.r11.s64 = 299958272;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// ori r11,r11,41728
	ctx.r11.u64 = ctx.r11.u64 | 41728;
	// addi r30,r10,-16616
	ctx.r30.s64 = ctx.r10.s64 + -16616;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x881343f0
	if (ctx.cr6.lt) goto loc_881343F0;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x881343f0
	if (!ctx.cr6.lt) goto loc_881343F0;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881343f0
	if (ctx.cr6.eq) goto loc_881343F0;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// ble cr6,0x881343f0
	if (!ctx.cr6.gt) goto loc_881343F0;
	// lwz r11,256(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 256);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x881343e8
	if (!ctx.cr6.eq) goto loc_881343E8;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8808d1b8
	ctx.lr = 0x881343E4;
	sub_8808D1B8(ctx, base);
	// b 0x881343f0
	goto loc_881343F0;
loc_881343E8:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,260(r30)
	PPC_STORE_U32(ctx.r30.u32 + 260, ctx.r11.u32);
loc_881343F0:
	// lis r11,1525
	ctx.r11.s64 = 99942400;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// ori r11,r11,57600
	ctx.r11.u64 = ctx.r11.u64 | 57600;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8813444c
	if (ctx.cr6.lt) goto loc_8813444C;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8813444c
	if (!ctx.cr6.lt) goto loc_8813444C;
	// lwz r11,5876(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5876);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8813444c
	if (ctx.cr6.eq) goto loc_8813444C;
	// lwz r11,5868(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 5868);
	// cmplwi cr6,r11,31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 31, ctx.xer);
	// ble cr6,0x8813444c
	if (!ctx.cr6.gt) goto loc_8813444C;
	// lwz r11,248(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 248);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x88134444
	if (!ctx.cr6.eq) goto loc_88134444;
	// li r3,31
	ctx.r3.s64 = 31;
	// bl 0x8808d1b8
	ctx.lr = 0x88134438;
	sub_8808D1B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88134444:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,252(r30)
	PPC_STORE_U32(ctx.r30.u32 + 252, ctx.r11.u32);
loc_8813444C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88134458"))) PPC_WEAK_FUNC(sub_88134458);
PPC_FUNC_IMPL(__imp__sub_88134458) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x881344a4
	if (ctx.cr6.eq) goto loc_881344A4;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,13
	ctx.r9.s64 = ctx.r11.s64 + 13;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x88152b00
	ctx.lr = 0x8813448C;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x881344a4
	if (ctx.cr6.eq) goto loc_881344A4;
	// lwz r11,136(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 136);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x881344a8
	if (ctx.cr6.eq) goto loc_881344A8;
loc_881344A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_881344A8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881344B8"))) PPC_WEAK_FUNC(sub_881344B8);
PPC_FUNC_IMPL(__imp__sub_881344B8) {
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
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8813450c
	if (ctx.cr6.eq) goto loc_8813450C;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r9,r11,13
	ctx.r9.s64 = ctx.r11.s64 + 13;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x88152b00
	ctx.lr = 0x881344F4;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8813450c
	if (ctx.cr6.eq) goto loc_8813450C;
	// lwz r11,136(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 136);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88134510
	if (ctx.cr6.eq) goto loc_88134510;
loc_8813450C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_88134510:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88134520"))) PPC_WEAK_FUNC(sub_88134520);
PPC_FUNC_IMPL(__imp__sub_88134520) {
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
	// lis r10,-30651
	ctx.r10.s64 = -2008743936;
	// lwz r9,160(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// li r11,0
	ctx.r11.s64 = 0;
	// lbz r7,10(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// addi r6,r10,-26112
	ctx.r6.s64 = ctx.r10.s64 + -26112;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r31,256
	ctx.r31.s64 = 256;
	// lis r30,50
	ctx.r30.s64 = 3276800;
	// lbz r9,27(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 27);
	// stb r9,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r9.u8);
	// divw r9,r5,r8
	ctx.r9.s32 = ppc_divw(ctx.r5.s32, ctx.r8.s32);
	// stw r31,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r31.u32);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r11.u32);
	// stw r11,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r11.u32);
	// stw r4,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r4.u32);
	// stw r30,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r30.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// stb r7,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
	// lwz r4,84(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x881345bc
	if (!ctx.cr6.eq) goto loc_881345BC;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x881345bc
	if (!ctx.cr6.eq) goto loc_881345BC;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
loc_881345BC:
	// lwz r9,164(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r11.u32);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r11.u32);
	// lbz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// divw r6,r7,r8
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r8.s32);
	// stw r6,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r6.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lwz r5,88(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// blt cr6,0x88134610
	if (ctx.cr6.lt) goto loc_88134610;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bne cr6,0x88134608
	if (!ctx.cr6.eq) goto loc_88134608;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,243
	ctx.r4.s64 = 243;
	// b 0x88134638
	goto loc_88134638;
loc_88134608:
	// li r4,203
	ctx.r4.s64 = 203;
	// b 0x88134634
	goto loc_88134634;
loc_88134610:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bne cr6,0x88134630
	if (!ctx.cr6.eq) goto loc_88134630;
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,242
	ctx.r4.s64 = 242;
	// b 0x88134638
	goto loc_88134638;
loc_88134630:
	// li r4,202
	ctx.r4.s64 = 202;
loc_88134634:
	// li r5,105
	ctx.r5.s64 = 105;
loc_88134638:
	// bl 0x880e31b0
	ctx.lr = 0x8813463C;
	sub_880E31B0(ctx, base);
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

__attribute__((alias("__imp__sub_88134654"))) PPC_WEAK_FUNC(sub_88134654);
PPC_FUNC_IMPL(__imp__sub_88134654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134658"))) PPC_WEAK_FUNC(sub_88134658);
PPC_FUNC_IMPL(__imp__sub_88134658) {
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
	// lis r11,-30651
	ctx.r11.s64 = -2008743936;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,-26112
	ctx.r10.s64 = ctx.r11.s64 + -26112;
	// li r9,256
	ctx.r9.s64 = 256;
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// lis r7,50
	ctx.r7.s64 = 3276800;
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r11,27(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 27);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r11.u8);
	// stw r9,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r9.u32);
	// stw r5,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r5.u32);
	// stw r5,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, ctx.r5.u32);
	// stw r5,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r5.u32);
	// stw r5,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r5.u32);
	// stw r5,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r5.u32);
	// stw r5,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r5.u32);
	// lbz r11,26(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 26);
	// stb r4,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r4.u8);
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// stw r7,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r7.u32);
	// stw r5,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r5.u32);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r11.u8);
	// stw r5,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r5.u32);
	// lbz r11,24(r10)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 24);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stw r5,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r5.u32);
	// stw r5,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r5.u32);
	// sth r11,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r11.u16);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r11.u16);
	// stw r6,172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 172, ctx.r6.u32);
	// bl 0x88133bb8
	ctx.lr = 0x881346E8;
	sub_88133BB8(ctx, base);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// stw r5,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r5.u32);
	// stw r5,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r5.u32);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x88134704
	if (!ctx.cr6.eq) goto loc_88134704;
	// stw r4,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r4.u32);
loc_88134704:
	// lbz r11,10(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// stw r5,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r5.u32);
	// stw r5,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r5.u32);
	// stw r5,168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 168, ctx.r5.u32);
	// stw r4,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r4.u32);
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813472C"))) PPC_WEAK_FUNC(sub_8813472C);
PPC_FUNC_IMPL(__imp__sub_8813472C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134730"))) PPC_WEAK_FUNC(sub_88134730);
PPC_FUNC_IMPL(__imp__sub_88134730) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x88133db0
	ctx.lr = 0x88134744;
	sub_88133DB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8813475c
	if (!ctx.cr6.eq) goto loc_8813475C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8813475C:
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lbz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,352(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 352);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881347A4"))) PPC_WEAK_FUNC(sub_881347A4);
PPC_FUNC_IMPL(__imp__sub_881347A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881347A8"))) PPC_WEAK_FUNC(sub_881347A8);
PPC_FUNC_IMPL(__imp__sub_881347A8) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x88133db0
	ctx.lr = 0x881347BC;
	sub_88133DB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x881347d4
	if (!ctx.cr6.eq) goto loc_881347D4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_881347D4:
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lbz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,348(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 348);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813481C"))) PPC_WEAK_FUNC(sub_8813481C);
PPC_FUNC_IMPL(__imp__sub_8813481C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134820"))) PPC_WEAK_FUNC(sub_88134820);
PPC_FUNC_IMPL(__imp__sub_88134820) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x88133db0
	ctx.lr = 0x88134834;
	sub_88133DB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8813484c
	if (!ctx.cr6.eq) goto loc_8813484C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8813484C:
	// lwz r8,128(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lbz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lwz r10,84(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88134894"))) PPC_WEAK_FUNC(sub_88134894);
PPC_FUNC_IMPL(__imp__sub_88134894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134898"))) PPC_WEAK_FUNC(sub_88134898);
PPC_FUNC_IMPL(__imp__sub_88134898) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x88133db0
	ctx.lr = 0x881348AC;
	sub_88133DB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x881348c4
	if (!ctx.cr6.eq) goto loc_881348C4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_881348C4:
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lbz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,344(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 344);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813490C"))) PPC_WEAK_FUNC(sub_8813490C);
PPC_FUNC_IMPL(__imp__sub_8813490C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134910"))) PPC_WEAK_FUNC(sub_88134910);
PPC_FUNC_IMPL(__imp__sub_88134910) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x88133db0
	ctx.lr = 0x88134924;
	sub_88133DB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8813493c
	if (!ctx.cr6.eq) goto loc_8813493C;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8813493C:
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lbz r11,8(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r3,332(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 332);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88134984"))) PPC_WEAK_FUNC(sub_88134984);
PPC_FUNC_IMPL(__imp__sub_88134984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134988"))) PPC_WEAK_FUNC(sub_88134988);
PPC_FUNC_IMPL(__imp__sub_88134988) {
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
	// lbz r11,6(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88134a24
	if (ctx.cr6.eq) goto loc_88134A24;
	// lwz r11,128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 164);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88134a24
	if (!ctx.cr6.eq) goto loc_88134A24;
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r7,68(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// extsb r4,r11
	ctx.r4.s64 = ctx.r11.s8;
	// lwz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// bl 0x88161068
	ctx.lr = 0x881349D0;
	sub_88161068(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x88134a24
	if (ctx.cr6.eq) goto loc_88134A24;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,1884(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1884);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x881349f4
	if (!ctx.cr6.eq) goto loc_881349F4;
	// lbz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 6);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stb r9,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r9.u8);
loc_881349F4:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// li r9,64
	ctx.r9.s64 = 64;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r9,164(r11)
	PPC_STORE_U32(ctx.r11.u32 + 164, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r8,120(r7)
	PPC_STORE_U32(ctx.r7.u32 + 120, ctx.r8.u32);
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
loc_88134A24:
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

__attribute__((alias("__imp__sub_88134A3C"))) PPC_WEAK_FUNC(sub_88134A3C);
PPC_FUNC_IMPL(__imp__sub_88134A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134A40"))) PPC_WEAK_FUNC(sub_88134A40);
PPC_FUNC_IMPL(__imp__sub_88134A40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x88134A48;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,24(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x88134248
	ctx.lr = 0x88134A58;
	sub_88134248(ctx, base);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88134b18
	if (!ctx.cr6.eq) goto loc_88134B18;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,22
	ctx.r11.s64 = ctx.r11.s64 + 22;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x88134b18
	if (ctx.cr6.eq) goto loc_88134B18;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// blt cr6,0x88134abc
	if (ctx.cr6.lt) goto loc_88134ABC;
	// bne cr6,0x88134b18
	if (!ctx.cr6.eq) goto loc_88134B18;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x88134b18
	if (ctx.cr6.lt) goto loc_88134B18;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x88134b18
	if (!ctx.cr6.lt) goto loc_88134B18;
	// lhz r11,2(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 2);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 9, ctx.xer);
	// b 0x88134acc
	goto loc_88134ACC;
loc_88134ABC:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x88134b18
	if (ctx.cr6.lt) goto loc_88134B18;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
loc_88134ACC:
	// bge cr6,0x88134b18
	if (!ctx.cr6.lt) goto loc_88134B18;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-16616
	ctx.r11.s64 = ctx.r11.s64 + -16616;
	// lwz r10,5876(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5876);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88134b18
	if (ctx.cr6.eq) goto loc_88134B18;
	// lwz r10,5868(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5868);
	// cmplwi cr6,r10,48
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 48, ctx.xer);
	// ble cr6,0x88134b18
	if (!ctx.cr6.gt) goto loc_88134B18;
	// lwz r10,384(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 384);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88134b10
	if (!ctx.cr6.eq) goto loc_88134B10;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x8808d1b8
	ctx.lr = 0x88134B04;
	sub_8808D1B8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_88134B10:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,388(r11)
	PPC_STORE_U32(ctx.r11.u32 + 388, ctx.r10.u32);
loc_88134B18:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88134B24"))) PPC_WEAK_FUNC(sub_88134B24);
PPC_FUNC_IMPL(__imp__sub_88134B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88134B28"))) PPC_WEAK_FUNC(sub_88134B28);
PPC_FUNC_IMPL(__imp__sub_88134B28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x88134B30;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,112(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88134b4c
	if (ctx.cr6.eq) goto loc_88134B4C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r11.u32);
loc_88134B4C:
	// lwz r11,192(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// blt cr6,0x88134b68
	if (ctx.cr6.lt) goto loc_88134B68;
	// li r11,20
	ctx.r11.s64 = 20;
	// stw r11,192(r31)
	PPC_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
loc_88134B68:
	// lwz r11,176(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 176);
	// li r27,0
	ctx.r27.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88134c0c
	if (ctx.cr6.eq) goto loc_88134C0C;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x88134b90
	if (ctx.cr6.lt) goto loc_88134B90;
	// addic. r11,r11,-4
	ctx.xer.ca = ctx.r11.u32 > 3;
	ctx.r11.s64 = ctx.r11.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x88134c00
	goto loc_88134C00;
loc_88134B90:
	// lwz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 180);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88134c0c
	if (!ctx.cr6.eq) goto loc_88134C0C;
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 184);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r10.u32);
	// bge 0x88134c0c
	if (!ctx.cr0.lt) goto loc_88134C0C;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88134bd4
	if (!ctx.cr6.eq) goto loc_88134BD4;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// subfic r8,r9,4
	ctx.xer.ca = ctx.r9.u32 <= 4;
	ctx.r8.s64 = 4 - ctx.r9.s64;
	// rlwinm r7,r8,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r6,r7,4
	ctx.xer.ca = ctx.r7.u32 <= 4;
	ctx.r6.s64 = 4 - ctx.r7.s64;
	// stw r6,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r6.u32);
	// b 0x88134bfc
	goto loc_88134BFC;
loc_88134BD4:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// blt cr6,0x88134bf8
	if (ctx.cr6.lt) goto loc_88134BF8;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// subfic r8,r9,4
	ctx.xer.ca = ctx.r9.u32 <= 4;
	ctx.r8.s64 = 4 - ctx.r9.s64;
	// rlwinm r7,r8,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// subfic r6,r7,8
	ctx.xer.ca = ctx.r7.u32 <= 8;
	ctx.r6.s64 = 8 - ctx.r7.s64;
	// stw r6,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r6.u32);
	// b 0x88134bfc
	goto loc_88134BFC;
loc_88134BF8:
	// stw r26,184(r31)
	PPC_STORE_U32(ctx.r31.u32 + 184, ctx.r26.u32);
loc_88134BFC:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_88134C00:
	// stw r11,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// bgt 0x88134c0c
	if (ctx.cr0.gt) goto loc_88134C0C;
	// stw r27,176(r31)
	PPC_STORE_U32(ctx.r31.u32 + 176, ctx.r27.u32);
loc_88134C0C:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// li r25,2
	ctx.r25.s64 = 2;
	// lis r29,-30633
	ctx.r29.s64 = -2007564288;
	// lwz r10,360(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 360);
	// lwz r28,84(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88134d58
	if (ctx.cr6.eq) goto loc_88134D58;
	// lwz r11,-29776(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -29776);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88134d58
	if (!ctx.cr6.eq) goto loc_88134D58;
	// lwz r30,164(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x88134df4
	if (!ctx.cr6.eq) goto loc_88134DF4;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,4464
	ctx.r10.u64 = ctx.r11.u64 | 4464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134c5c
	if (ctx.cr6.lt) goto loc_88134C5C;
	// li r4,1111
	ctx.r4.s64 = 1111;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134C5C;
	sub_88134248(ctx, base);
loc_88134C5C:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,9464
	ctx.r10.u64 = ctx.r11.u64 | 9464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134c78
	if (ctx.cr6.lt) goto loc_88134C78;
	// li r4,2222
	ctx.r4.s64 = 2222;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134C78;
	sub_88134248(ctx, base);
loc_88134C78:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,14464
	ctx.r10.u64 = ctx.r11.u64 | 14464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134c94
	if (ctx.cr6.lt) goto loc_88134C94;
	// li r4,3333
	ctx.r4.s64 = 3333;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134C94;
	sub_88134248(ctx, base);
loc_88134C94:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,19464
	ctx.r10.u64 = ctx.r11.u64 | 19464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134cb0
	if (ctx.cr6.lt) goto loc_88134CB0;
	// li r4,4444
	ctx.r4.s64 = 4444;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134CB0;
	sub_88134248(ctx, base);
loc_88134CB0:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,24464
	ctx.r10.u64 = ctx.r11.u64 | 24464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134ccc
	if (ctx.cr6.lt) goto loc_88134CCC;
	// li r4,5555
	ctx.r4.s64 = 5555;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134CCC;
	sub_88134248(ctx, base);
loc_88134CCC:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,29464
	ctx.r10.u64 = ctx.r11.u64 | 29464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134ce8
	if (ctx.cr6.lt) goto loc_88134CE8;
	// li r4,6666
	ctx.r4.s64 = 6666;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134CE8;
	sub_88134248(ctx, base);
loc_88134CE8:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,34464
	ctx.r10.u64 = ctx.r11.u64 | 34464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134d04
	if (ctx.cr6.lt) goto loc_88134D04;
	// li r4,7777
	ctx.r4.s64 = 7777;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134D04;
	sub_88134248(ctx, base);
loc_88134D04:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,39464
	ctx.r10.u64 = ctx.r11.u64 | 39464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134d20
	if (ctx.cr6.lt) goto loc_88134D20;
	// li r4,8888
	ctx.r4.s64 = 8888;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134D20;
	sub_88134248(ctx, base);
loc_88134D20:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,44464
	ctx.r10.u64 = ctx.r11.u64 | 44464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134d3c
	if (ctx.cr6.lt) goto loc_88134D3C;
	// li r4,9999
	ctx.r4.s64 = 9999;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134D3C;
	sub_88134248(ctx, base);
loc_88134D3C:
	// lis r11,1
	ctx.r11.s64 = 65536;
	// ori r10,r11,49464
	ctx.r10.u64 = ctx.r11.u64 | 49464;
	// cmpw cr6,r30,r10
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x88134d58
	if (ctx.cr6.lt) goto loc_88134D58;
	// li r4,11111
	ctx.r4.s64 = 11111;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88134248
	ctx.lr = 0x88134D58;
	sub_88134248(ctx, base);
loc_88134D58:
	// lwz r11,-29776(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -29776);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x88134df4
	if (!ctx.cr6.eq) goto loc_88134DF4;
	// lwz r11,168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 168);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
	// bgt 0x88134df4
	if (ctx.cr0.gt) goto loc_88134DF4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 192);
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// subfic r8,r9,7
	ctx.xer.ca = ctx.r9.u32 <= 7;
	ctx.r8.s64 = 7 - ctx.r9.s64;
	// stw r8,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r8.u32);
	// blt cr6,0x88134d94
	if (ctx.cr6.lt) goto loc_88134D94;
	// stw r25,168(r31)
	PPC_STORE_U32(ctx.r31.u32 + 168, ctx.r25.u32);
loc_88134D94:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// beq cr6,0x88134dc8
	if (ctx.cr6.eq) goto loc_88134DC8;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// bgt 0x88134db0
	if (ctx.cr0.gt) goto loc_88134DB0;
	// stw r27,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r27.u32);
loc_88134DB0:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// bgt 0x88134df4
	if (ctx.cr0.gt) goto loc_88134DF4;
	// stw r27,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r27.u32);
	// b 0x88134df4
	goto loc_88134DF4;
loc_88134DC8:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r11.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x88134ddc
	if (ctx.cr6.gt) goto loc_88134DDC;
	// stw r26,160(r31)
	PPC_STORE_U32(ctx.r31.u32 + 160, ctx.r26.u32);
loc_88134DDC:
	// lwz r11,164(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r11.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bgt cr6,0x88134df4
	if (ctx.cr6.gt) goto loc_88134DF4;
	// stw r26,164(r31)
	PPC_STORE_U32(ctx.r31.u32 + 164, ctx.r26.u32);
loc_88134DF4:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// lwz r10,144(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 144);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88134ee8
	if (!ctx.cr6.eq) goto loc_88134EE8;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r10,r11,22
	ctx.r10.s64 = ctx.r11.s64 + 22;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x88134ee8
	if (ctx.cr6.eq) goto loc_88134EE8;
	// lwz r9,104(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// blt cr6,0x88134e78
	if (ctx.cr6.lt) goto loc_88134E78;
	// bne cr6,0x88134ee8
	if (!ctx.cr6.eq) goto loc_88134EE8;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x88134ee8
	if (ctx.cr6.lt) goto loc_88134EE8;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// bl 0x88133a60
	ctx.lr = 0x88134E58;
	sub_88133A60(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x88134ee8
	if (ctx.cr6.eq) goto loc_88134EE8;
	// li r6,254
	ctx.r6.s64 = 254;
	// li r5,100
	ctx.r5.s64 = 100;
	// li r4,113
	ctx.r4.s64 = 113;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x880e32d0
	ctx.lr = 0x88134E74;
	sub_880E32D0(ctx, base);
	// b 0x88134ea8
	goto loc_88134EA8;
loc_88134E78:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x88134ee8
	if (ctx.cr6.lt) goto loc_88134EE8;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// li r6,254
	ctx.r6.s64 = 254;
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// li r5,100
	ctx.r5.s64 = 100;
	// li r4,113
	ctx.r4.s64 = 113;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x880e32d0
	ctx.lr = 0x88134EA0;
	sub_880E32D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x88133a60
	ctx.lr = 0x88134EA8;
	sub_88133A60(ctx, base);
loc_88134EA8:
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// addi r11,r11,-16616
	ctx.r11.s64 = ctx.r11.s64 + -16616;
	// lwz r10,5876(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5876);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88134ee8
	if (ctx.cr6.eq) goto loc_88134EE8;
	// lwz r10,5868(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 5868);
	// cmplwi cr6,r10,42
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 42, ctx.xer);
	// ble cr6,0x88134ee8
	if (!ctx.cr6.gt) goto loc_88134EE8;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 336);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x88134ee0
	if (!ctx.cr6.eq) goto loc_88134EE0;
	// li r3,42
	ctx.r3.s64 = 42;
	// bl 0x8808d1b8
	ctx.lr = 0x88134EDC;
	sub_8808D1B8(ctx, base);
	// b 0x88134ee8
	goto loc_88134EE8;
loc_88134EE0:
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r26,340(r11)
	PPC_STORE_U32(ctx.r11.u32 + 340, ctx.r26.u32);
loc_88134EE8:
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r6,r11,26432
	ctx.r6.s64 = ctx.r11.s64 + 26432;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88134f64
	if (ctx.cr6.eq) goto loc_88134F64;
	// lwz r3,12(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// bl 0x88152b00
	ctx.lr = 0x88134F04;
	sub_88152B00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88134f64
	if (!ctx.cr6.eq) goto loc_88134F64;
	// lwz r11,304(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 304);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88134f64
	if (!ctx.cr6.eq) goto loc_88134F64;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// lis r9,-30628
	ctx.r9.s64 = -2007236608;
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r11,r9,13264
	ctx.r11.s64 = ctx.r9.s64 + 13264;
	// subfe r7,r8,r10
	temp.u8 = (~ctx.r8.u32 + ctx.r10.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// mulli r4,r7,88
	ctx.r4.s64 = ctx.r7.s64 * 88;
	// lwzx r3,r4,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// rlwinm r11,r3,0,24,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xF0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x88134f4c
	if (ctx.cr6.eq) goto loc_88134F4C;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// stb r27,365(r11)
	PPC_STORE_U8(ctx.r11.u32 + 365, ctx.r27.u8);
loc_88134F4C:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lbz r10,364(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 364);
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// blt cr6,0x88134f64
	if (ctx.cr6.lt) goto loc_88134F64;
	// stw r27,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r27.u32);
	// stb r27,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r27.u8);
loc_88134F64:
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r30,324(r6)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 324);
	// lwz r5,88(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// bl 0x881344b8
	ctx.lr = 0x88134F78;
	sub_881344B8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x881355c4
	if (ctx.cr6.eq) goto loc_881355C4;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// bgt cr6,0x881355c4
	if (ctx.cr6.gt) goto loc_881355C4;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x881350f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_881350F4;
	// bdzf 4*cr6+eq,0x8813524c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8813524C;
	// bne cr6,0x881353a4
	if (!ctx.cr6.eq) goto loc_881353A4;
	// lbz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// bne cr6,0x88135048
	if (!ctx.cr6.eq) goto loc_88135048;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88135004
	if (!ctx.cr6.eq) goto loc_88135004;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88134ffc
	if (!ctx.cr6.eq) goto loc_88134FFC;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// li r5,95
	ctx.r5.s64 = 95;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bne cr6,0x88134ff0
	if (!ctx.cr6.eq) goto loc_88134FF0;
	// li r4,224
	ctx.r4.s64 = 224;
	// bl 0x880e31b0
	ctx.lr = 0x88134FEC;
	sub_880E31B0(ctx, base);
	// b 0x88135000
	goto loc_88135000;
loc_88134FF0:
	// li r4,223
	ctx.r4.s64 = 223;
	// bl 0x880e31b0
	ctx.lr = 0x88134FF8;
	sub_880E31B0(ctx, base);
	// b 0x88135000
	goto loc_88135000;
loc_88134FFC:
	// blt cr6,0x88135004
	if (ctx.cr6.lt) goto loc_88135004;
loc_88135000:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_88135004:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// cmpwi cr6,r10,217
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 217, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r5,95
	ctx.r5.s64 = 95;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,225
	ctx.r4.s64 = 225;
	// li r6,254
	ctx.r6.s64 = 254;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135040;
	sub_880E31B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_88135048:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881350c4
	if (!ctx.cr6.eq) goto loc_881350C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8813508c
	if (!ctx.cr6.eq) goto loc_8813508C;
	// cmpwi cr6,r11,69
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 69, ctx.xer);
	// bne cr6,0x881350bc
	if (!ctx.cr6.eq) goto loc_881350BC;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,184
	ctx.r4.s64 = 184;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135088;
	sub_880E31B0(ctx, base);
	// b 0x881350c0
	goto loc_881350C0;
loc_8813508C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881350b8
	if (!ctx.cr6.eq) goto loc_881350B8;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,183
	ctx.r4.s64 = 183;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881350B4;
	sub_880E31B0(ctx, base);
	// b 0x881350c0
	goto loc_881350C0;
loc_881350B8:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
loc_881350BC:
	// blt cr6,0x881350c4
	if (ctx.cr6.lt) goto loc_881350C4;
loc_881350C0:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_881350C4:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	// cmpwi cr6,r10,220
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 220, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,185
	ctx.r4.s64 = 185;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// b 0x881355b4
	goto loc_881355B4;
loc_881350F4:
	// lbz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// bne cr6,0x881351a0
	if (!ctx.cr6.eq) goto loc_881351A0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813515c
	if (!ctx.cr6.eq) goto loc_8813515C;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88135154
	if (!ctx.cr6.eq) goto loc_88135154;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// li r5,95
	ctx.r5.s64 = 95;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bne cr6,0x88135148
	if (!ctx.cr6.eq) goto loc_88135148;
	// li r4,227
	ctx.r4.s64 = 227;
	// bl 0x880e31b0
	ctx.lr = 0x88135144;
	sub_880E31B0(ctx, base);
	// b 0x88135158
	goto loc_88135158;
loc_88135148:
	// li r4,226
	ctx.r4.s64 = 226;
	// bl 0x880e31b0
	ctx.lr = 0x88135150;
	sub_880E31B0(ctx, base);
	// b 0x88135158
	goto loc_88135158;
loc_88135154:
	// blt cr6,0x8813515c
	if (ctx.cr6.lt) goto loc_8813515C;
loc_88135158:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_8813515C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,584
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 584, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r5,95
	ctx.r5.s64 = 95;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,228
	ctx.r4.s64 = 228;
	// li r6,254
	ctx.r6.s64 = 254;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135198;
	sub_880E31B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_881351A0:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813521c
	if (!ctx.cr6.eq) goto loc_8813521C;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x881351e4
	if (!ctx.cr6.eq) goto loc_881351E4;
	// cmpwi cr6,r11,21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 21, ctx.xer);
	// bne cr6,0x88135214
	if (!ctx.cr6.eq) goto loc_88135214;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,187
	ctx.r4.s64 = 187;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881351E0;
	sub_880E31B0(ctx, base);
	// b 0x88135218
	goto loc_88135218;
loc_881351E4:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88135210
	if (!ctx.cr6.eq) goto loc_88135210;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,186
	ctx.r4.s64 = 186;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x8813520C;
	sub_880E31B0(ctx, base);
	// b 0x88135218
	goto loc_88135218;
loc_88135210:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
loc_88135214:
	// blt cr6,0x8813521c
	if (ctx.cr6.lt) goto loc_8813521C;
loc_88135218:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_8813521C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,584
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 584, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,188
	ctx.r4.s64 = 188;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// b 0x881355b4
	goto loc_881355B4;
loc_8813524C:
	// lbz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// bne cr6,0x881352f8
	if (!ctx.cr6.eq) goto loc_881352F8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881352b4
	if (!ctx.cr6.eq) goto loc_881352B4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881352ac
	if (!ctx.cr6.eq) goto loc_881352AC;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// li r5,95
	ctx.r5.s64 = 95;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bne cr6,0x881352a0
	if (!ctx.cr6.eq) goto loc_881352A0;
	// li r4,230
	ctx.r4.s64 = 230;
	// bl 0x880e31b0
	ctx.lr = 0x8813529C;
	sub_880E31B0(ctx, base);
	// b 0x881352b0
	goto loc_881352B0;
loc_881352A0:
	// li r4,229
	ctx.r4.s64 = 229;
	// bl 0x880e31b0
	ctx.lr = 0x881352A8;
	sub_880E31B0(ctx, base);
	// b 0x881352b0
	goto loc_881352B0;
loc_881352AC:
	// blt cr6,0x881352b4
	if (ctx.cr6.lt) goto loc_881352B4;
loc_881352B0:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_881352B4:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,644
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 644, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r5,95
	ctx.r5.s64 = 95;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,231
	ctx.r4.s64 = 231;
	// li r6,254
	ctx.r6.s64 = 254;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881352F0;
	sub_880E31B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_881352F8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88135374
	if (!ctx.cr6.eq) goto loc_88135374;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x8813533c
	if (!ctx.cr6.eq) goto loc_8813533C;
	// cmpwi cr6,r11,11
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 11, ctx.xer);
	// bne cr6,0x8813536c
	if (!ctx.cr6.eq) goto loc_8813536C;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,190
	ctx.r4.s64 = 190;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135338;
	sub_880E31B0(ctx, base);
	// b 0x88135370
	goto loc_88135370;
loc_8813533C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88135368
	if (!ctx.cr6.eq) goto loc_88135368;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,189
	ctx.r4.s64 = 189;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135364;
	sub_880E31B0(ctx, base);
	// b 0x88135370
	goto loc_88135370;
loc_88135368:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
loc_8813536C:
	// blt cr6,0x88135374
	if (ctx.cr6.lt) goto loc_88135374;
loc_88135370:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_88135374:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,644
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 644, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,191
	ctx.r4.s64 = 191;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// b 0x881355b4
	goto loc_881355B4;
loc_881353A4:
	// lbz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// bne cr6,0x881354f8
	if (!ctx.cr6.eq) goto loc_881354F8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88135430
	if (!ctx.cr6.eq) goto loc_88135430;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x881353f8
	if (!ctx.cr6.eq) goto loc_881353F8;
	// cmpwi cr6,r11,15
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 15, ctx.xer);
	// bne cr6,0x88135428
	if (!ctx.cr6.eq) goto loc_88135428;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,232
	ctx.r4.s64 = 232;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881353F4;
	sub_880E31B0(ctx, base);
	// b 0x8813542c
	goto loc_8813542C;
loc_881353F8:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88135424
	if (!ctx.cr6.eq) goto loc_88135424;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,232
	ctx.r4.s64 = 232;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135420;
	sub_880E31B0(ctx, base);
	// b 0x8813542c
	goto loc_8813542C;
loc_88135424:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
loc_88135428:
	// blt cr6,0x88135430
	if (ctx.cr6.lt) goto loc_88135430;
loc_8813542C:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_88135430:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x881354b0
	if (!ctx.cr6.eq) goto loc_881354B0;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r30,2
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 2, ctx.xer);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// bne cr6,0x88135478
	if (!ctx.cr6.eq) goto loc_88135478;
	// cmpwi cr6,r11,809
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 809, ctx.xer);
	// bne cr6,0x881354a8
	if (!ctx.cr6.eq) goto loc_881354A8;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,233
	ctx.r4.s64 = 233;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135474;
	sub_880E31B0(ctx, base);
	// b 0x881354ac
	goto loc_881354AC;
loc_88135478:
	// cmpwi cr6,r11,794
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 794, ctx.xer);
	// bne cr6,0x881354a4
	if (!ctx.cr6.eq) goto loc_881354A4;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,95
	ctx.r5.s64 = 95;
	// li r4,233
	ctx.r4.s64 = 233;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881354A0;
	sub_880E31B0(ctx, base);
	// b 0x881354ac
	goto loc_881354AC;
loc_881354A4:
	// cmpwi cr6,r11,794
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 794, ctx.xer);
loc_881354A8:
	// blt cr6,0x881354b0
	if (ctx.cr6.lt) goto loc_881354B0;
loc_881354AC:
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
loc_881354B0:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,832
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 832, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// li r11,3
	ctx.r11.s64 = 3;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,95
	ctx.r5.s64 = 95;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// li r4,234
	ctx.r4.s64 = 234;
	// li r6,254
	ctx.r6.s64 = 254;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881354F0;
	sub_880E31B0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_881354F8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8813553c
	if (!ctx.cr6.eq) goto loc_8813553C;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88135534
	if (!ctx.cr6.eq) goto loc_88135534;
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,192
	ctx.r4.s64 = 192;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135530;
	sub_880E31B0(ctx, base);
	// b 0x88135538
	goto loc_88135538;
loc_88135534:
	// blt cr6,0x8813553c
	if (ctx.cr6.lt) goto loc_8813553C;
loc_88135538:
	// stw r26,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
loc_8813553C:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x88135584
	if (!ctx.cr6.eq) goto loc_88135584;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r11,176(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r11,794
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 794, ctx.xer);
	// bne cr6,0x8813557c
	if (!ctx.cr6.eq) goto loc_8813557C;
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
	// li r6,254
	ctx.r6.s64 = 254;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r5,105
	ctx.r5.s64 = 105;
	// li r4,193
	ctx.r4.s64 = 193;
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x88135578;
	sub_880E31B0(ctx, base);
	// b 0x88135580
	goto loc_88135580;
loc_8813557C:
	// blt cr6,0x88135584
	if (ctx.cr6.lt) goto loc_88135584;
loc_88135580:
	// stw r25,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r25.u32);
loc_88135584:
	// lwz r11,108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	// cmpwi cr6,r10,832
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 832, ctx.xer);
	// bne cr6,0x881355c4
	if (!ctx.cr6.eq) goto loc_881355C4;
	// li r11,3
	ctx.r11.s64 = 3;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// li r4,194
	ctx.r4.s64 = 194;
	// stw r11,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r11.u32);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
loc_881355B4:
	// li r5,105
	ctx.r5.s64 = 105;
	// li r6,254
	ctx.r6.s64 = 254;
	// addi r3,r11,5
	ctx.r3.s64 = ctx.r11.s64 + 5;
	// bl 0x880e31b0
	ctx.lr = 0x881355C4;
	sub_880E31B0(ctx, base);
loc_881355C4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_881355CC"))) PPC_WEAK_FUNC(sub_881355CC);
PPC_FUNC_IMPL(__imp__sub_881355CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881355D0"))) PPC_WEAK_FUNC(sub_881355D0);
PPC_FUNC_IMPL(__imp__sub_881355D0) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r4,475
	ctx.r10.s64 = ctx.r4.s64 + 475;
	// lbz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stbx r9,r8,r3
	PPC_STORE_U8(ctx.r8.u32 + ctx.r3.u32, ctx.r9.u8);
	// lbz r6,1(r5)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// stb r6,1901(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1901, ctx.r6.u8);
	// lbz r5,2(r5)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r5.u32 + 2);
	// stb r5,1902(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1902, ctx.r5.u8);
	// stb r7,1903(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1903, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135604"))) PPC_WEAK_FUNC(sub_88135604);
PPC_FUNC_IMPL(__imp__sub_88135604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135608"))) PPC_WEAK_FUNC(sub_88135608);
PPC_FUNC_IMPL(__imp__sub_88135608) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,1888(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1888);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135610"))) PPC_WEAK_FUNC(sub_88135610);
PPC_FUNC_IMPL(__imp__sub_88135610) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,1884(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1884);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135618"))) PPC_WEAK_FUNC(sub_88135618);
PPC_FUNC_IMPL(__imp__sub_88135618) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,1880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1880);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135620"))) PPC_WEAK_FUNC(sub_88135620);
PPC_FUNC_IMPL(__imp__sub_88135620) {
	PPC_FUNC_PROLOGUE();
	// std r5,1864(r3)
	PPC_STORE_U64(ctx.r3.u32 + 1864, ctx.r5.u64);
	// stw r4,1872(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1872, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813562C"))) PPC_WEAK_FUNC(sub_8813562C);
PPC_FUNC_IMPL(__imp__sub_8813562C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135630"))) PPC_WEAK_FUNC(sub_88135630);
PPC_FUNC_IMPL(__imp__sub_88135630) {
	PPC_FUNC_PROLOGUE();
	// ld r3,1864(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 1864);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135638"))) PPC_WEAK_FUNC(sub_88135638);
PPC_FUNC_IMPL(__imp__sub_88135638) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,1860(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1860);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135640"))) PPC_WEAK_FUNC(sub_88135640);
PPC_FUNC_IMPL(__imp__sub_88135640) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,1844(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1844);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,1848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1848, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135658"))) PPC_WEAK_FUNC(sub_88135658);
PPC_FUNC_IMPL(__imp__sub_88135658) {
	PPC_FUNC_PROLOGUE();
	// stw r4,1844(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1844, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135660"))) PPC_WEAK_FUNC(sub_88135660);
PPC_FUNC_IMPL(__imp__sub_88135660) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// lbz r3,1852(r11)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1852);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813566C"))) PPC_WEAK_FUNC(sub_8813566C);
PPC_FUNC_IMPL(__imp__sub_8813566C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135670"))) PPC_WEAK_FUNC(sub_88135670);
PPC_FUNC_IMPL(__imp__sub_88135670) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r10,r11,1852
	ctx.r10.s64 = ctx.r11.s64 + 1852;
	// lbz r10,1852(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1852);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r10,1852(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1852, ctx.r10.u8);
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// add r8,r3,r11
	ctx.r8.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lbz r7,1852(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 1852);
	// cmplwi cr6,r7,9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 9, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// li r10,9
	ctx.r10.s64 = 9;
	// add r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stb r10,1852(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1852, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881356B0"))) PPC_WEAK_FUNC(sub_881356B0);
PPC_FUNC_IMPL(__imp__sub_881356B0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881356B8"))) PPC_WEAK_FUNC(sub_881356B8);
PPC_FUNC_IMPL(__imp__sub_881356B8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,200(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881356C8"))) PPC_WEAK_FUNC(sub_881356C8);
PPC_FUNC_IMPL(__imp__sub_881356C8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// mulli r11,r3,196
	ctx.r11.s64 = ctx.r3.s64 * 196;
	// addi r10,r10,26432
	ctx.r10.s64 = ctx.r10.s64 + 26432;
	// addi r10,r10,1448
	ctx.r10.s64 = ctx.r10.s64 + 1448;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881356E0"))) PPC_WEAK_FUNC(sub_881356E0);
PPC_FUNC_IMPL(__imp__sub_881356E0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,360(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 360);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881356E8"))) PPC_WEAK_FUNC(sub_881356E8);
PPC_FUNC_IMPL(__imp__sub_881356E8) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,13
	ctx.r11.s64 = ctx.r4.s64 + 13;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881356F8"))) PPC_WEAK_FUNC(sub_881356F8);
PPC_FUNC_IMPL(__imp__sub_881356F8) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,365(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 365);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135700"))) PPC_WEAK_FUNC(sub_88135700);
PPC_FUNC_IMPL(__imp__sub_88135700) {
	PPC_FUNC_PROLOGUE();
	// li r11,90
	ctx.r11.s64 = 90;
	// stb r11,366(r3)
	PPC_STORE_U8(ctx.r3.u32 + 366, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813570C"))) PPC_WEAK_FUNC(sub_8813570C);
PPC_FUNC_IMPL(__imp__sub_8813570C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135710"))) PPC_WEAK_FUNC(sub_88135710);
PPC_FUNC_IMPL(__imp__sub_88135710) {
	PPC_FUNC_PROLOGUE();
	// stb r4,365(r3)
	PPC_STORE_U8(ctx.r3.u32 + 365, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135718"))) PPC_WEAK_FUNC(sub_88135718);
PPC_FUNC_IMPL(__imp__sub_88135718) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,364(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 364);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135720"))) PPC_WEAK_FUNC(sub_88135720);
PPC_FUNC_IMPL(__imp__sub_88135720) {
	PPC_FUNC_PROLOGUE();
	// li r11,9
	ctx.r11.s64 = 9;
	// stb r11,364(r3)
	PPC_STORE_U8(ctx.r3.u32 + 364, ctx.r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813572C"))) PPC_WEAK_FUNC(sub_8813572C);
PPC_FUNC_IMPL(__imp__sub_8813572C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135730"))) PPC_WEAK_FUNC(sub_88135730);
PPC_FUNC_IMPL(__imp__sub_88135730) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r3,r11,368
	ctx.r3.s64 = ctx.r11.s64 + 368;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135754"))) PPC_WEAK_FUNC(sub_88135754);
PPC_FUNC_IMPL(__imp__sub_88135754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135758"))) PPC_WEAK_FUNC(sub_88135758);
PPC_FUNC_IMPL(__imp__sub_88135758) {
	PPC_FUNC_PROLOGUE();
	// stw r4,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135760"))) PPC_WEAK_FUNC(sub_88135760);
PPC_FUNC_IMPL(__imp__sub_88135760) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,112(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135768"))) PPC_WEAK_FUNC(sub_88135768);
PPC_FUNC_IMPL(__imp__sub_88135768) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,1840(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1840);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135778"))) PPC_WEAK_FUNC(sub_88135778);
PPC_FUNC_IMPL(__imp__sub_88135778) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// stw r11,1840(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1840, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813578C"))) PPC_WEAK_FUNC(sub_8813578C);
PPC_FUNC_IMPL(__imp__sub_8813578C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135790"))) PPC_WEAK_FUNC(sub_88135790);
PPC_FUNC_IMPL(__imp__sub_88135790) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// stw r11,1840(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1840, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881357A4"))) PPC_WEAK_FUNC(sub_881357A4);
PPC_FUNC_IMPL(__imp__sub_881357A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881357A8"))) PPC_WEAK_FUNC(sub_881357A8);
PPC_FUNC_IMPL(__imp__sub_881357A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,164(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881357B0"))) PPC_WEAK_FUNC(sub_881357B0);
PPC_FUNC_IMPL(__imp__sub_881357B0) {
	PPC_FUNC_PROLOGUE();
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881357BC"))) PPC_WEAK_FUNC(sub_881357BC);
PPC_FUNC_IMPL(__imp__sub_881357BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881357C0"))) PPC_WEAK_FUNC(sub_881357C0);
PPC_FUNC_IMPL(__imp__sub_881357C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,1460(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1460);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x881357dc
	if (!ctx.cr6.eq) goto loc_881357DC;
	// lwz r11,1656(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1656);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_881357DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881357E4"))) PPC_WEAK_FUNC(sub_881357E4);
PPC_FUNC_IMPL(__imp__sub_881357E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881357E8"))) PPC_WEAK_FUNC(sub_881357E8);
PPC_FUNC_IMPL(__imp__sub_881357E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8813580c
	if (ctx.cr6.eq) goto loc_8813580C;
	// lwz r11,156(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
loc_8813580C:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,160(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135834"))) PPC_WEAK_FUNC(sub_88135834);
PPC_FUNC_IMPL(__imp__sub_88135834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135838"))) PPC_WEAK_FUNC(sub_88135838);
PPC_FUNC_IMPL(__imp__sub_88135838) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,160(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// neg r3,r11
	ctx.r3.s64 = -ctx.r11.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135844"))) PPC_WEAK_FUNC(sub_88135844);
PPC_FUNC_IMPL(__imp__sub_88135844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135848"))) PPC_WEAK_FUNC(sub_88135848);
PPC_FUNC_IMPL(__imp__sub_88135848) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,156(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// neg r3,r11
	ctx.r3.s64 = -ctx.r11.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135854"))) PPC_WEAK_FUNC(sub_88135854);
PPC_FUNC_IMPL(__imp__sub_88135854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135858"))) PPC_WEAK_FUNC(sub_88135858);
PPC_FUNC_IMPL(__imp__sub_88135858) {
	PPC_FUNC_PROLOGUE();
	// stw r4,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r4.u32);
	// stw r5,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135864"))) PPC_WEAK_FUNC(sub_88135864);
PPC_FUNC_IMPL(__imp__sub_88135864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135868"))) PPC_WEAK_FUNC(sub_88135868);
PPC_FUNC_IMPL(__imp__sub_88135868) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135870"))) PPC_WEAK_FUNC(sub_88135870);
PPC_FUNC_IMPL(__imp__sub_88135870) {
	PPC_FUNC_PROLOGUE();
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135878"))) PPC_WEAK_FUNC(sub_88135878);
PPC_FUNC_IMPL(__imp__sub_88135878) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135880"))) PPC_WEAK_FUNC(sub_88135880);
PPC_FUNC_IMPL(__imp__sub_88135880) {
	PPC_FUNC_PROLOGUE();
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8813588C"))) PPC_WEAK_FUNC(sub_8813588C);
PPC_FUNC_IMPL(__imp__sub_8813588C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135890"))) PPC_WEAK_FUNC(sub_88135890);
PPC_FUNC_IMPL(__imp__sub_88135890) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,308(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135898"))) PPC_WEAK_FUNC(sub_88135898);
PPC_FUNC_IMPL(__imp__sub_88135898) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881358A0"))) PPC_WEAK_FUNC(sub_881358A0);
PPC_FUNC_IMPL(__imp__sub_881358A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,324(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 324);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881358B0"))) PPC_WEAK_FUNC(sub_881358B0);
PPC_FUNC_IMPL(__imp__sub_881358B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,328(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 328);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881358C0"))) PPC_WEAK_FUNC(sub_881358C0);
PPC_FUNC_IMPL(__imp__sub_881358C0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// stw r11,312(r9)
	PPC_STORE_U32(ctx.r9.u32 + 312, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881358D4"))) PPC_WEAK_FUNC(sub_881358D4);
PPC_FUNC_IMPL(__imp__sub_881358D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_881358D8"))) PPC_WEAK_FUNC(sub_881358D8);
PPC_FUNC_IMPL(__imp__sub_881358D8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,312(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881358E8"))) PPC_WEAK_FUNC(sub_881358E8);
PPC_FUNC_IMPL(__imp__sub_881358E8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// stw r11,348(r9)
	PPC_STORE_U32(ctx.r9.u32 + 348, ctx.r11.u32);
	// stw r3,356(r9)
	PPC_STORE_U32(ctx.r9.u32 + 356, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135900"))) PPC_WEAK_FUNC(sub_88135900);
PPC_FUNC_IMPL(__imp__sub_88135900) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// stw r3,344(r10)
	PPC_STORE_U32(ctx.r10.u32 + 344, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135910"))) PPC_WEAK_FUNC(sub_88135910);
PPC_FUNC_IMPL(__imp__sub_88135910) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135920"))) PPC_WEAK_FUNC(sub_88135920);
PPC_FUNC_IMPL(__imp__sub_88135920) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,1(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// lwz r9,324(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 324);
	// extsb r10,r11
	ctx.r10.s64 = ctx.r11.s8;
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// mulli r11,r10,196
	ctx.r11.s64 = ctx.r10.s64 * 196;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lis r9,50
	ctx.r9.s64 = 3276800;
	// stw r9,1508(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1508, ctx.r9.u32);
	// bne cr6,0x88135964
	if (!ctx.cr6.eq) goto loc_88135964;
	// lis r8,60
	ctx.r8.s64 = 3932160;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r8,1504(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1504, ctx.r8.u32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,180
	ctx.r10.s64 = 11796480;
	// stw r9,1508(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1508, ctx.r9.u32);
	// stw r10,1504(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1504, ctx.r10.u32);
	// blr 
	return;
loc_88135964:
	// lis r10,120
	ctx.r10.s64 = 7864320;
	// stw r10,1504(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1504, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135970"))) PPC_WEAK_FUNC(sub_88135970);
PPC_FUNC_IMPL(__imp__sub_88135970) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,136(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135980"))) PPC_WEAK_FUNC(sub_88135980);
PPC_FUNC_IMPL(__imp__sub_88135980) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// stw r3,136(r10)
	PPC_STORE_U32(ctx.r10.u32 + 136, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135990"))) PPC_WEAK_FUNC(sub_88135990);
PPC_FUNC_IMPL(__imp__sub_88135990) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881359A0"))) PPC_WEAK_FUNC(sub_881359A0);
PPC_FUNC_IMPL(__imp__sub_881359A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// stw r3,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881359B0"))) PPC_WEAK_FUNC(sub_881359B0);
PPC_FUNC_IMPL(__imp__sub_881359B0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// stw r3,304(r10)
	PPC_STORE_U32(ctx.r10.u32 + 304, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881359C0"))) PPC_WEAK_FUNC(sub_881359C0);
PPC_FUNC_IMPL(__imp__sub_881359C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,300(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 300);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881359D0"))) PPC_WEAK_FUNC(sub_881359D0);
PPC_FUNC_IMPL(__imp__sub_881359D0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,140(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_881359E0"))) PPC_WEAK_FUNC(sub_881359E0);
PPC_FUNC_IMPL(__imp__sub_881359E0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r5,42
	ctx.r10.s64 = ctx.r5.s64 + 42;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A04"))) PPC_WEAK_FUNC(sub_88135A04);
PPC_FUNC_IMPL(__imp__sub_88135A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135A08"))) PPC_WEAK_FUNC(sub_88135A08);
PPC_FUNC_IMPL(__imp__sub_88135A08) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r5,42
	ctx.r10.s64 = ctx.r5.s64 + 42;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A20"))) PPC_WEAK_FUNC(sub_88135A20);
PPC_FUNC_IMPL(__imp__sub_88135A20) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// stw r3,340(r10)
	PPC_STORE_U32(ctx.r10.u32 + 340, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A30"))) PPC_WEAK_FUNC(sub_88135A30);
PPC_FUNC_IMPL(__imp__sub_88135A30) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30643
	ctx.r11.s64 = -2008219648;
	// addi r10,r11,26432
	ctx.r10.s64 = ctx.r11.s64 + 26432;
	// lwz r3,340(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A40"))) PPC_WEAK_FUNC(sub_88135A40);
PPC_FUNC_IMPL(__imp__sub_88135A40) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,120(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A48"))) PPC_WEAK_FUNC(sub_88135A48);
PPC_FUNC_IMPL(__imp__sub_88135A48) {
	PPC_FUNC_PROLOGUE();
	// stw r4,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A50"))) PPC_WEAK_FUNC(sub_88135A50);
PPC_FUNC_IMPL(__imp__sub_88135A50) {
	PPC_FUNC_PROLOGUE();
	// stw r4,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A58"))) PPC_WEAK_FUNC(sub_88135A58);
PPC_FUNC_IMPL(__imp__sub_88135A58) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,30
	ctx.r11.s64 = ctx.r4.s64 + 30;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A68"))) PPC_WEAK_FUNC(sub_88135A68);
PPC_FUNC_IMPL(__imp__sub_88135A68) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r4,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r3,236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 236);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135A78"))) PPC_WEAK_FUNC(sub_88135A78);
PPC_FUNC_IMPL(__imp__sub_88135A78) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r10,r5,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r5,34
	ctx.r9.s64 = ctx.r5.s64 + 34;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r6,r9,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r7,268(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 268);
	// stw r7,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r7.u32);
	// lwzx r5,r6,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r11.u32);
	// stw r5,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135AA4"))) PPC_WEAK_FUNC(sub_88135AA4);
PPC_FUNC_IMPL(__imp__sub_88135AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135AA8"))) PPC_WEAK_FUNC(sub_88135AA8);
PPC_FUNC_IMPL(__imp__sub_88135AA8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r6,34
	ctx.r9.s64 = ctx.r6.s64 + 34;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,268(r8)
	PPC_STORE_U32(ctx.r8.u32 + 268, ctx.r4.u32);
	// stwx r5,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135ACC"))) PPC_WEAK_FUNC(sub_88135ACC);
PPC_FUNC_IMPL(__imp__sub_88135ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135AD0"))) PPC_WEAK_FUNC(sub_88135AD0);
PPC_FUNC_IMPL(__imp__sub_88135AD0) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r6,30
	ctx.r9.s64 = ctx.r6.s64 + 30;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,236(r8)
	PPC_STORE_U32(ctx.r8.u32 + 236, ctx.r4.u32);
	// stwx r5,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + ctx.r11.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135AF4"))) PPC_WEAK_FUNC(sub_88135AF4);
PPC_FUNC_IMPL(__imp__sub_88135AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135AF8"))) PPC_WEAK_FUNC(sub_88135AF8);
PPC_FUNC_IMPL(__imp__sub_88135AF8) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r5,55
	ctx.r10.s64 = ctx.r5.s64 + 55;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135B10"))) PPC_WEAK_FUNC(sub_88135B10);
PPC_FUNC_IMPL(__imp__sub_88135B10) {
	PPC_FUNC_PROLOGUE();
	// addi r10,r5,51
	ctx.r10.s64 = ctx.r5.s64 + 51;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r4,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135B28"))) PPC_WEAK_FUNC(sub_88135B28);
PPC_FUNC_IMPL(__imp__sub_88135B28) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,55
	ctx.r11.s64 = ctx.r4.s64 + 55;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135B38"))) PPC_WEAK_FUNC(sub_88135B38);
PPC_FUNC_IMPL(__imp__sub_88135B38) {
	PPC_FUNC_PROLOGUE();
	// addi r11,r4,51
	ctx.r11.s64 = ctx.r4.s64 + 51;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135B48"))) PPC_WEAK_FUNC(sub_88135B48);
PPC_FUNC_IMPL(__imp__sub_88135B48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88135B50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r31,r11,1448
	ctx.r31.s64 = ctx.r11.s64 + 1448;
	// li r28,2
	ctx.r28.s64 = 2;
loc_88135B6C:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88135b90
	if (!ctx.cr6.eq) goto loc_88135B90;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x88135B8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
loc_88135B90:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// bne 0x88135b6c
	if (!ctx.cr0.eq) goto loc_88135B6C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88135BA4"))) PPC_WEAK_FUNC(sub_88135BA4);
PPC_FUNC_IMPL(__imp__sub_88135BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135BA8"))) PPC_WEAK_FUNC(sub_88135BA8);
PPC_FUNC_IMPL(__imp__sub_88135BA8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071158
	ctx.lr = 0x88135BB0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r31,r11,1448
	ctx.r31.s64 = ctx.r11.s64 + 1448;
	// li r28,2
	ctx.r28.s64 = 2;
loc_88135BCC:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88135bf0
	if (ctx.cr6.eq) goto loc_88135BF0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x88135BEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
loc_88135BF0:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r31,r31,196
	ctx.r31.s64 = ctx.r31.s64 + 196;
	// bne 0x88135bcc
	if (!ctx.cr0.eq) goto loc_88135BCC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880711a8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_88135C04"))) PPC_WEAK_FUNC(sub_88135C04);
PPC_FUNC_IMPL(__imp__sub_88135C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135C08"))) PPC_WEAK_FUNC(sub_88135C08);
PPC_FUNC_IMPL(__imp__sub_88135C08) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// stw r4,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r4.u32);
	// addi r9,r10,-10940
	ctx.r9.s64 = ctx.r10.s64 + -10940;
	// stb r4,8(r9)
	PPC_STORE_U8(ctx.r9.u32 + 8, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C1C"))) PPC_WEAK_FUNC(sub_88135C1C);
PPC_FUNC_IMPL(__imp__sub_88135C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_88135C20"))) PPC_WEAK_FUNC(sub_88135C20);
PPC_FUNC_IMPL(__imp__sub_88135C20) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,104(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C28"))) PPC_WEAK_FUNC(sub_88135C28);
PPC_FUNC_IMPL(__imp__sub_88135C28) {
	PPC_FUNC_PROLOGUE();
	// stw r4,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C30"))) PPC_WEAK_FUNC(sub_88135C30);
PPC_FUNC_IMPL(__imp__sub_88135C30) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C38"))) PPC_WEAK_FUNC(sub_88135C38);
PPC_FUNC_IMPL(__imp__sub_88135C38) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,100(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C40"))) PPC_WEAK_FUNC(sub_88135C40);
PPC_FUNC_IMPL(__imp__sub_88135C40) {
	PPC_FUNC_PROLOGUE();
	// stw r4,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C48"))) PPC_WEAK_FUNC(sub_88135C48);
PPC_FUNC_IMPL(__imp__sub_88135C48) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_88135C50"))) PPC_WEAK_FUNC(sub_88135C50);
PPC_FUNC_IMPL(__imp__sub_88135C50) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,88(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// blr 
	return;
}

