#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_880F0EA4"))) PPC_WEAK_FUNC(sub_880F0EA4);
PPC_FUNC_IMPL(__imp__sub_880F0EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0EA8"))) PPC_WEAK_FUNC(sub_880F0EA8);
PPC_FUNC_IMPL(__imp__sub_880F0EA8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r8,r10,31024
	ctx.r8.s64 = ctx.r10.s64 + 31024;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stwx r5,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0EC8"))) PPC_WEAK_FUNC(sub_880F0EC8);
PPC_FUNC_IMPL(__imp__sub_880F0EC8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-30642
	ctx.r9.s64 = -2008154112;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r9,31504
	ctx.r11.s64 = ctx.r9.s64 + 31504;
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r10,r11,10
	ctx.r10.s64 = ctx.r11.s64 + 10;
	// rlwinm r11,r8,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0EEC"))) PPC_WEAK_FUNC(sub_880F0EEC);
PPC_FUNC_IMPL(__imp__sub_880F0EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0EF0"))) PPC_WEAK_FUNC(sub_880F0EF0);
PPC_FUNC_IMPL(__imp__sub_880F0EF0) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-30642
	ctx.r9.s64 = -2008154112;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r11,r9,31024
	ctx.r11.s64 = ctx.r9.s64 + 31024;
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r10,r11,10
	ctx.r10.s64 = ctx.r11.s64 + 10;
	// rlwinm r11,r8,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0F14"))) PPC_WEAK_FUNC(sub_880F0F14);
PPC_FUNC_IMPL(__imp__sub_880F0F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0F18"))) PPC_WEAK_FUNC(sub_880F0F18);
PPC_FUNC_IMPL(__imp__sub_880F0F18) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31504
	ctx.r11.s64 = ctx.r11.s64 + 31504;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,9
	ctx.r8.s64 = ctx.r11.s64 + 9;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0F3C"))) PPC_WEAK_FUNC(sub_880F0F3C);
PPC_FUNC_IMPL(__imp__sub_880F0F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0F40"))) PPC_WEAK_FUNC(sub_880F0F40);
PPC_FUNC_IMPL(__imp__sub_880F0F40) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,9
	ctx.r8.s64 = ctx.r11.s64 + 9;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0F64"))) PPC_WEAK_FUNC(sub_880F0F64);
PPC_FUNC_IMPL(__imp__sub_880F0F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0F68"))) PPC_WEAK_FUNC(sub_880F0F68);
PPC_FUNC_IMPL(__imp__sub_880F0F68) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31504
	ctx.r11.s64 = ctx.r11.s64 + 31504;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0F8C"))) PPC_WEAK_FUNC(sub_880F0F8C);
PPC_FUNC_IMPL(__imp__sub_880F0F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0F90"))) PPC_WEAK_FUNC(sub_880F0F90);
PPC_FUNC_IMPL(__imp__sub_880F0F90) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0FB4"))) PPC_WEAK_FUNC(sub_880F0FB4);
PPC_FUNC_IMPL(__imp__sub_880F0FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0FB8"))) PPC_WEAK_FUNC(sub_880F0FB8);
PPC_FUNC_IMPL(__imp__sub_880F0FB8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31504
	ctx.r11.s64 = ctx.r11.s64 + 31504;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,7
	ctx.r8.s64 = ctx.r11.s64 + 7;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F0FDC"))) PPC_WEAK_FUNC(sub_880F0FDC);
PPC_FUNC_IMPL(__imp__sub_880F0FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F0FE0"))) PPC_WEAK_FUNC(sub_880F0FE0);
PPC_FUNC_IMPL(__imp__sub_880F0FE0) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,7
	ctx.r8.s64 = ctx.r11.s64 + 7;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1004"))) PPC_WEAK_FUNC(sub_880F1004);
PPC_FUNC_IMPL(__imp__sub_880F1004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1008"))) PPC_WEAK_FUNC(sub_880F1008);
PPC_FUNC_IMPL(__imp__sub_880F1008) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,6
	ctx.r8.s64 = ctx.r11.s64 + 6;
	// lbzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// rlwinm r3,r7,28,4,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1030"))) PPC_WEAK_FUNC(sub_880F1030);
PPC_FUNC_IMPL(__imp__sub_880F1030) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31504
	ctx.r11.s64 = ctx.r11.s64 + 31504;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,6
	ctx.r8.s64 = ctx.r11.s64 + 6;
	// lbzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// clrlwi r3,r7,28
	ctx.r3.u64 = ctx.r7.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1058"))) PPC_WEAK_FUNC(sub_880F1058);
PPC_FUNC_IMPL(__imp__sub_880F1058) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,6
	ctx.r8.s64 = ctx.r11.s64 + 6;
	// lbzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// clrlwi r3,r7,28
	ctx.r3.u64 = ctx.r7.u32 & 0xF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1080"))) PPC_WEAK_FUNC(sub_880F1080);
PPC_FUNC_IMPL(__imp__sub_880F1080) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31504
	ctx.r11.s64 = ctx.r11.s64 + 31504;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F10A4"))) PPC_WEAK_FUNC(sub_880F10A4);
PPC_FUNC_IMPL(__imp__sub_880F10A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F10A8"))) PPC_WEAK_FUNC(sub_880F10A8);
PPC_FUNC_IMPL(__imp__sub_880F10A8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F10CC"))) PPC_WEAK_FUNC(sub_880F10CC);
PPC_FUNC_IMPL(__imp__sub_880F10CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F10D0"))) PPC_WEAK_FUNC(sub_880F10D0);
PPC_FUNC_IMPL(__imp__sub_880F10D0) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31504
	ctx.r11.s64 = ctx.r11.s64 + 31504;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F10F4"))) PPC_WEAK_FUNC(sub_880F10F4);
PPC_FUNC_IMPL(__imp__sub_880F10F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F10F8"))) PPC_WEAK_FUNC(sub_880F10F8);
PPC_FUNC_IMPL(__imp__sub_880F10F8) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r11,r11,31024
	ctx.r11.s64 = ctx.r11.s64 + 31024;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lbzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F111C"))) PPC_WEAK_FUNC(sub_880F111C);
PPC_FUNC_IMPL(__imp__sub_880F111C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1120"))) PPC_WEAK_FUNC(sub_880F1120);
PPC_FUNC_IMPL(__imp__sub_880F1120) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r8,r10,31504
	ctx.r8.s64 = ctx.r10.s64 + 31504;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1140"))) PPC_WEAK_FUNC(sub_880F1140);
PPC_FUNC_IMPL(__imp__sub_880F1140) {
	PPC_FUNC_PROLOGUE();
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r8,r10,31024
	ctx.r8.s64 = ctx.r10.s64 + 31024;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1160"))) PPC_WEAK_FUNC(sub_880F1160);
PPC_FUNC_IMPL(__imp__sub_880F1160) {
	PPC_FUNC_PROLOGUE();
	// li r11,480
	ctx.r11.s64 = 480;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// addi r3,r10,31504
	ctx.r3.s64 = ctx.r10.s64 + 31504;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1174"))) PPC_WEAK_FUNC(sub_880F1174);
PPC_FUNC_IMPL(__imp__sub_880F1174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1178"))) PPC_WEAK_FUNC(sub_880F1178);
PPC_FUNC_IMPL(__imp__sub_880F1178) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880F1180;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// addi r29,r11,-5064
	ctx.r29.s64 = ctx.r11.s64 + -5064;
	// addi r30,r10,31024
	ctx.r30.s64 = ctx.r10.s64 + 31024;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_880F1198:
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88072260
	ctx.lr = 0x880F11A8;
	sub_88072260(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880f1198
	if (ctx.cr6.lt) goto loc_880F1198;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F11C4"))) PPC_WEAK_FUNC(sub_880F11C4);
PPC_FUNC_IMPL(__imp__sub_880F11C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F11C8"))) PPC_WEAK_FUNC(sub_880F11C8);
PPC_FUNC_IMPL(__imp__sub_880F11C8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// addi r8,r11,31504
	ctx.r8.s64 = ctx.r11.s64 + 31504;
	// addi r11,r8,8
	ctx.r11.s64 = ctx.r8.s64 + 8;
loc_880F11D8:
	// li r9,5
	ctx.r9.s64 = 5;
loc_880F11DC:
	// ld r7,-16(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + -16);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r7,-8(r11)
	PPC_STORE_U32(ctx.r11.u32 + -8, ctx.r7.u32);
	// lbz r5,-3(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + -3);
	// stb r5,-3(r11)
	PPC_STORE_U8(ctx.r11.u32 + -3, ctx.r5.u8);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stb r4,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r4.u8);
	// lbz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + -4);
	// stb r3,-4(r11)
	PPC_STORE_U8(ctx.r11.u32 + -4, ctx.r3.u8);
	// lbz r7,-2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + -2);
	// stb r7,-2(r11)
	PPC_STORE_U8(ctx.r11.u32 + -2, ctx.r7.u8);
	// lbz r6,-1(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// stb r6,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r6.u8);
	// lbz r5,1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// stb r5,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r5.u8);
	// lbz r4,-8(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + -8);
	// stb r4,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r4.u8);
	// lbz r3,-7(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + -7);
	// stb r3,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r3.u8);
	// lbz r7,-6(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6);
	// stb r7,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r7.u8);
	// lbz r6,-5(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -5);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// stb r6,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r6.u8);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bne 0x880f11dc
	if (!ctx.cr0.eq) goto loc_880F11DC;
	// addi r9,r8,488
	ctx.r9.s64 = ctx.r8.s64 + 488;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f11d8
	if (ctx.cr6.lt) goto loc_880F11D8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1254"))) PPC_WEAK_FUNC(sub_880F1254);
PPC_FUNC_IMPL(__imp__sub_880F1254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1258"))) PPC_WEAK_FUNC(sub_880F1258);
PPC_FUNC_IMPL(__imp__sub_880F1258) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// addi r8,r10,31504
	ctx.r8.s64 = ctx.r10.s64 + 31504;
	// addi r10,r8,8
	ctx.r10.s64 = ctx.r8.s64 + 8;
loc_880F1268:
	// li r9,5
	ctx.r9.s64 = 5;
loc_880F126C:
	// lwz r7,-8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r7,-16(r11)
	PPC_STORE_U64(ctx.r11.u32 + -16, ctx.r7.u64);
	// lbz r6,-3(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -3);
	// stb r6,-3(r11)
	PPC_STORE_U8(ctx.r11.u32 + -3, ctx.r6.u8);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stb r5,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r5.u8);
	// lbz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + -4);
	// stb r4,-4(r11)
	PPC_STORE_U8(ctx.r11.u32 + -4, ctx.r4.u8);
	// lbz r3,-2(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + -2);
	// stb r3,-2(r11)
	PPC_STORE_U8(ctx.r11.u32 + -2, ctx.r3.u8);
	// lbz r7,-1(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// stb r7,-1(r11)
	PPC_STORE_U8(ctx.r11.u32 + -1, ctx.r7.u8);
	// lbz r6,1(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// stb r6,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r6.u8);
	// lbz r5,2(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// stb r5,-8(r11)
	PPC_STORE_U8(ctx.r11.u32 + -8, ctx.r5.u8);
	// lbz r4,3(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// stb r4,-7(r11)
	PPC_STORE_U8(ctx.r11.u32 + -7, ctx.r4.u8);
	// lbz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// stb r3,-6(r11)
	PPC_STORE_U8(ctx.r11.u32 + -6, ctx.r3.u8);
	// lbz r7,5(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 5);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stb r7,-5(r11)
	PPC_STORE_U8(ctx.r11.u32 + -5, ctx.r7.u8);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// bne 0x880f126c
	if (!ctx.cr0.eq) goto loc_880F126C;
	// addi r9,r8,488
	ctx.r9.s64 = ctx.r8.s64 + 488;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f1268
	if (ctx.cr6.lt) goto loc_880F1268;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F12E4"))) PPC_WEAK_FUNC(sub_880F12E4);
PPC_FUNC_IMPL(__imp__sub_880F12E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F12E8"))) PPC_WEAK_FUNC(sub_880F12E8);
PPC_FUNC_IMPL(__imp__sub_880F12E8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F12EC"))) PPC_WEAK_FUNC(sub_880F12EC);
PPC_FUNC_IMPL(__imp__sub_880F12EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F12F0"))) PPC_WEAK_FUNC(sub_880F12F0);
PPC_FUNC_IMPL(__imp__sub_880F12F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880F12F8;
	__savegprlr_25(ctx, base);
	// stwu r1,-864(r1)
	ea = -864 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r3,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
	// addi r26,r10,31504
	ctx.r26.s64 = ctx.r10.s64 + 31504;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_880F1328:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x880f134c
	if (ctx.cr6.lt) goto loc_880F134C;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// cmpwi cr6,r30,5
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 5, ctx.xer);
	// blt cr6,0x880f1328
	if (ctx.cr6.lt) goto loc_880F1328;
	// addi r1,r1,864
	ctx.r1.s64 = ctx.r1.s64 + 864;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_880F134C:
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// bne cr6,0x880f1368
	if (!ctx.cr6.eq) goto loc_880F1368;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r31,5
	ctx.r31.s64 = 5;
	// bl 0x88072260
	ctx.lr = 0x880F1364;
	sub_88072260(ctx, base);
	// b 0x880f13b8
	goto loc_880F13B8;
loc_880F1368:
	// subfic r27,r30,4
	ctx.xer.ca = ctx.r30.u32 <= 4;
	ctx.r27.s64 = 4 - ctx.r30.s64;
	// addi r28,r11,80
	ctx.r28.s64 = ctx.r11.s64 + 80;
	// addi r31,r11,64
	ctx.r31.s64 = ctx.r11.s64 + 64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x880f139c
	if (!ctx.cr6.gt) goto loc_880F139C;
loc_880F137C:
	// addi r31,r31,-16
	ctx.r31.s64 = ctx.r31.s64 + -16;
	// addi r28,r28,-16
	ctx.r28.s64 = ctx.r28.s64 + -16;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x88072260
	ctx.lr = 0x880F1394;
	sub_88072260(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne 0x880f137c
	if (!ctx.cr0.eq) goto loc_880F137C;
loc_880F139C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 1;
	// bl 0x88072260
	ctx.lr = 0x880F13B0;
	sub_88072260(ctx, base);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x880f1440
	if (ctx.cr6.eq) goto loc_880F1440;
loc_880F13B8:
	// rlwinm r11,r29,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// subfic r10,r31,6
	ctx.xer.ca = ctx.r31.u32 <= 6;
	ctx.r10.s64 = 6 - ctx.r31.s64;
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// rlwinm r10,r10,3,17,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x7FF8;
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r9,3,1,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0x7FFFFFF8;
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r7,r7,14
	ctx.r7.s64 = ctx.r7.s64 + 14;
	// add r4,r8,r26
	ctx.r4.u64 = ctx.r8.u64 + ctx.r26.u64;
	// clrlwi r8,r7,24
	ctx.r8.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r31,r9,-10864
	ctx.r31.s64 = ctx.r9.s64 + -10864;
	// beq cr6,0x880f141c
	if (ctx.cr6.eq) goto loc_880F141C;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r31,-3640
	ctx.r9.s64 = ctx.r31.s64 + -3640;
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r11.s64;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r26,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r26.s64;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// bl 0x880726e8
	ctx.lr = 0x880F141C;
	sub_880726E8(ctx, base);
loc_880F141C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x880f1258
	ctx.lr = 0x880F1424;
	sub_880F1258(ctx, base);
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,25928
	ctx.r3.s64 = ctx.r11.s64 + 25928;
	// li r5,720
	ctx.r5.s64 = 720;
	// bl 0x88072260
	ctx.lr = 0x880F1438;
	sub_88072260(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_880F1440:
	// addi r1,r1,864
	ctx.r1.s64 = ctx.r1.s64 + 864;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F1448"))) PPC_WEAK_FUNC(sub_880F1448);
PPC_FUNC_IMPL(__imp__sub_880F1448) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071154
	ctx.lr = 0x880F1450;
	__savegprlr_27(ctx, base);
	// stwu r1,-848(r1)
	ea = -848 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8808e9c8
	ctx.lr = 0x880F1458;
	sub_8808E9C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f1470
	if (ctx.cr6.eq) goto loc_880F1470;
	// bl 0x880f11c8
	ctx.lr = 0x880F1464;
	sub_880F11C8(ctx, base);
	// bl 0x880f1178
	ctx.lr = 0x880F1468;
	sub_880F1178(ctx, base);
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
loc_880F1470:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r28,r11,-5064
	ctx.r28.s64 = ctx.r11.s64 + -5064;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// addi r29,r11,31504
	ctx.r29.s64 = ctx.r11.s64 + 31504;
loc_880F1488:
	// lwz r27,0(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r29,-480
	ctx.r11.s64 = ctx.r29.s64 + -480;
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r3,r30,r11
	ctx.r3.u64 = ctx.r30.u64 + ctx.r11.u64;
	// bl 0x88072260
	ctx.lr = 0x880F14A0;
	sub_88072260(ctx, base);
	// li r5,80
	ctx.r5.s64 = 80;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r3,r30,r29
	ctx.r3.u64 = ctx.r30.u64 + ctx.r29.u64;
	// bl 0x88072260
	ctx.lr = 0x880F14B0;
	sub_88072260(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r28,24
	ctx.r11.s64 = ctx.r28.s64 + 24;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880f1488
	if (ctx.cr6.lt) goto loc_880F1488;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x880f1258
	ctx.lr = 0x880F14CC;
	sub_880F1258(ctx, base);
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,25928
	ctx.r3.s64 = ctx.r11.s64 + 25928;
	// li r5,720
	ctx.r5.s64 = 720;
	// bl 0x88072260
	ctx.lr = 0x880F14E0;
	sub_88072260(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-10864(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10864, ctx.r11.u32);
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// b 0x880711a4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F14F4"))) PPC_WEAK_FUNC(sub_880F14F4);
PPC_FUNC_IMPL(__imp__sub_880F14F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F14F8"))) PPC_WEAK_FUNC(sub_880F14F8);
PPC_FUNC_IMPL(__imp__sub_880F14F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880F1500;
	__savegprlr_29(ctx, base);
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8808e9c8
	ctx.lr = 0x880F1508;
	sub_8808E9C8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f151c
	if (ctx.cr6.eq) goto loc_880F151C;
	// bl 0x880f11c8
	ctx.lr = 0x880F1514;
	sub_880F11C8(ctx, base);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880F151C:
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r29,r10,-5064
	ctx.r29.s64 = ctx.r10.s64 + -5064;
	// addi r30,r11,31504
	ctx.r30.s64 = ctx.r11.s64 + 31504;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_880F1530:
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x88072260
	ctx.lr = 0x880F1540;
	sub_88072260(ctx, base);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r29,24
	ctx.r11.s64 = ctx.r29.s64 + 24;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x880f1530
	if (ctx.cr6.lt) goto loc_880F1530;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x880f1258
	ctx.lr = 0x880F155C;
	sub_880F1258(ctx, base);
	// lis r11,-30628
	ctx.r11.s64 = -2007236608;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,25928
	ctx.r3.s64 = ctx.r11.s64 + 25928;
	// li r5,720
	ctx.r5.s64 = 720;
	// bl 0x88072260
	ctx.lr = 0x880F1570;
	sub_88072260(ctx, base);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-10864(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10864, ctx.r11.u32);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F1584"))) PPC_WEAK_FUNC(sub_880F1584);
PPC_FUNC_IMPL(__imp__sub_880F1584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1588"))) PPC_WEAK_FUNC(sub_880F1588);
PPC_FUNC_IMPL(__imp__sub_880F1588) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-5040
	ctx.r11.s64 = ctx.r11.s64 + -5040;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F15A0"))) PPC_WEAK_FUNC(sub_880F15A0);
PPC_FUNC_IMPL(__imp__sub_880F15A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,-5040
	ctx.r9.s64 = ctx.r11.s64 + -5040;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F15B4"))) PPC_WEAK_FUNC(sub_880F15B4);
PPC_FUNC_IMPL(__imp__sub_880F15B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F15B8"))) PPC_WEAK_FUNC(sub_880F15B8);
PPC_FUNC_IMPL(__imp__sub_880F15B8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r6,32
	ctx.r6.s64 = 2097152;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,47
	ctx.r8.s64 = 47;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r7,372
	ctx.r7.s64 = 372;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// ori r6,r6,32880
	ctx.r6.u64 = ctx.r6.u64 | 32880;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F15F0"))) PPC_WEAK_FUNC(sub_880F15F0);
PPC_FUNC_IMPL(__imp__sub_880F15F0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r6,32
	ctx.r6.s64 = 2097152;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,35
	ctx.r8.s64 = 35;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r7,372
	ctx.r7.s64 = 372;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// ori r6,r6,32880
	ctx.r6.u64 = ctx.r6.u64 | 32880;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1628"))) PPC_WEAK_FUNC(sub_880F1628);
PPC_FUNC_IMPL(__imp__sub_880F1628) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r6,32
	ctx.r6.s64 = 2097152;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,25
	ctx.r8.s64 = 25;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r7,372
	ctx.r7.s64 = 372;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// ori r6,r6,32880
	ctx.r6.u64 = ctx.r6.u64 | 32880;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1660"))) PPC_WEAK_FUNC(sub_880F1660);
PPC_FUNC_IMPL(__imp__sub_880F1660) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r6,128
	ctx.r6.s64 = 8388608;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,47
	ctx.r8.s64 = 47;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r7,372
	ctx.r7.s64 = 372;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// ori r6,r6,8224
	ctx.r6.u64 = ctx.r6.u64 | 8224;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1698"))) PPC_WEAK_FUNC(sub_880F1698);
PPC_FUNC_IMPL(__imp__sub_880F1698) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r6,128
	ctx.r6.s64 = 8388608;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,35
	ctx.r8.s64 = 35;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r7,372
	ctx.r7.s64 = 372;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// ori r6,r6,8224
	ctx.r6.u64 = ctx.r6.u64 | 8224;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F16D0"))) PPC_WEAK_FUNC(sub_880F16D0);
PPC_FUNC_IMPL(__imp__sub_880F16D0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lis r6,128
	ctx.r6.s64 = 8388608;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,160
	ctx.r9.s64 = 160;
	// li r8,25
	ctx.r8.s64 = 25;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r7,372
	ctx.r7.s64 = 372;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// ori r6,r6,8224
	ctx.r6.u64 = ctx.r6.u64 | 8224;
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r7,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,80(r11)
	PPC_STORE_U32(ctx.r11.u32 + 80, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1708"))) PPC_WEAK_FUNC(sub_880F1708);
PPC_FUNC_IMPL(__imp__sub_880F1708) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// bge 0x880f172c
	if (!ctx.cr0.lt) goto loc_880F172C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_880F172C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1734"))) PPC_WEAK_FUNC(sub_880F1734);
PPC_FUNC_IMPL(__imp__sub_880F1734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1738"))) PPC_WEAK_FUNC(sub_880F1738);
PPC_FUNC_IMPL(__imp__sub_880F1738) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1754"))) PPC_WEAK_FUNC(sub_880F1754);
PPC_FUNC_IMPL(__imp__sub_880F1754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1758"))) PPC_WEAK_FUNC(sub_880F1758);
PPC_FUNC_IMPL(__imp__sub_880F1758) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1774"))) PPC_WEAK_FUNC(sub_880F1774);
PPC_FUNC_IMPL(__imp__sub_880F1774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1778"))) PPC_WEAK_FUNC(sub_880F1778);
PPC_FUNC_IMPL(__imp__sub_880F1778) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1794"))) PPC_WEAK_FUNC(sub_880F1794);
PPC_FUNC_IMPL(__imp__sub_880F1794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1798"))) PPC_WEAK_FUNC(sub_880F1798);
PPC_FUNC_IMPL(__imp__sub_880F1798) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,112
	ctx.r9.s64 = 112;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F17B4"))) PPC_WEAK_FUNC(sub_880F17B4);
PPC_FUNC_IMPL(__imp__sub_880F17B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F17B8"))) PPC_WEAK_FUNC(sub_880F17B8);
PPC_FUNC_IMPL(__imp__sub_880F17B8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F17D4"))) PPC_WEAK_FUNC(sub_880F17D4);
PPC_FUNC_IMPL(__imp__sub_880F17D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F17D8"))) PPC_WEAK_FUNC(sub_880F17D8);
PPC_FUNC_IMPL(__imp__sub_880F17D8) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,5044
	ctx.r8.s64 = 5044;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F17FC"))) PPC_WEAK_FUNC(sub_880F17FC);
PPC_FUNC_IMPL(__imp__sub_880F17FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1800"))) PPC_WEAK_FUNC(sub_880F1800);
PPC_FUNC_IMPL(__imp__sub_880F1800) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,5028
	ctx.r8.s64 = 5028;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1824"))) PPC_WEAK_FUNC(sub_880F1824);
PPC_FUNC_IMPL(__imp__sub_880F1824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1828"))) PPC_WEAK_FUNC(sub_880F1828);
PPC_FUNC_IMPL(__imp__sub_880F1828) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,5012
	ctx.r8.s64 = 5012;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F184C"))) PPC_WEAK_FUNC(sub_880F184C);
PPC_FUNC_IMPL(__imp__sub_880F184C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1850"))) PPC_WEAK_FUNC(sub_880F1850);
PPC_FUNC_IMPL(__imp__sub_880F1850) {
	PPC_FUNC_PROLOGUE();
	// lis r6,16838
	ctx.r6.s64 = 1103495168;
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lis r5,-30671
	ctx.r5.s64 = -2010054656;
	// ori r11,r6,20077
	ctx.r11.u64 = ctx.r6.u64 | 20077;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4200);
	// lis r4,-13108
	ctx.r4.s64 = -859045888;
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// ori r6,r4,52429
	ctx.r6.u64 = ctx.r4.u64 | 52429;
	// mullw r9,r11,r3
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r3.s32);
	// stw r11,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r4,255
	ctx.r4.s64 = 255;
	// stw r9,4200(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4200, ctx.r9.u32);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// lhz r5,4200(r5)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r5.u32 + 4200);
	// stw r4,72(r7)
	PPC_STORE_U32(ctx.r7.u32 + 72, ctx.r4.u32);
	// clrlwi r4,r11,27
	ctx.r4.u64 = ctx.r11.u32 & 0x1F;
	// stw r4,48(r7)
	PPC_STORE_U32(ctx.r7.u32 + 48, ctx.r4.u32);
	// addi r10,r10,-6396
	ctx.r10.s64 = ctx.r10.s64 + -6396;
	// mulhwu r3,r5,r6
	ctx.r3.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r11,r3,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r10,8
	ctx.r6.s64 = ctx.r10.s64 + 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,1
	ctx.r3.s64 = 1;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r11,r4,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r4.s64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r10
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r11,76(r7)
	PPC_STORE_U32(ctx.r7.u32 + 76, ctx.r11.u32);
	// lwzx r11,r4,r6
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// add r10,r11,r8
	ctx.r10.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r10,32(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F18F4"))) PPC_WEAK_FUNC(sub_880F18F4);
PPC_FUNC_IMPL(__imp__sub_880F18F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F18F8"))) PPC_WEAK_FUNC(sub_880F18F8);
PPC_FUNC_IMPL(__imp__sub_880F18F8) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,255
	ctx.r7.s64 = 255;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,5292
	ctx.r5.s64 = 5292;
	// stw r7,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r4,r11,26
	ctx.r4.u64 = ctx.r11.u32 & 0x3F;
	// stw r4,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F193C"))) PPC_WEAK_FUNC(sub_880F193C);
PPC_FUNC_IMPL(__imp__sub_880F193C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1940"))) PPC_WEAK_FUNC(sub_880F1940);
PPC_FUNC_IMPL(__imp__sub_880F1940) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,255
	ctx.r7.s64 = 255;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,5260
	ctx.r5.s64 = 5260;
	// stw r7,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r4,r11,27
	ctx.r4.u64 = ctx.r11.u32 & 0x1F;
	// stw r4,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1984"))) PPC_WEAK_FUNC(sub_880F1984);
PPC_FUNC_IMPL(__imp__sub_880F1984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1988"))) PPC_WEAK_FUNC(sub_880F1988);
PPC_FUNC_IMPL(__imp__sub_880F1988) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,255
	ctx.r7.s64 = 255;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,5212
	ctx.r5.s64 = 5212;
	// stw r7,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r4,r11,27
	ctx.r4.u64 = ctx.r11.u32 & 0x1F;
	// stw r4,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F19CC"))) PPC_WEAK_FUNC(sub_880F19CC);
PPC_FUNC_IMPL(__imp__sub_880F19CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F19D0"))) PPC_WEAK_FUNC(sub_880F19D0);
PPC_FUNC_IMPL(__imp__sub_880F19D0) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,255
	ctx.r7.s64 = 255;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,5244
	ctx.r5.s64 = 5244;
	// stw r7,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r5.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r4,r11,28
	ctx.r4.u64 = ctx.r11.u32 & 0xF;
	// stw r4,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1A14"))) PPC_WEAK_FUNC(sub_880F1A14);
PPC_FUNC_IMPL(__imp__sub_880F1A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1A18"))) PPC_WEAK_FUNC(sub_880F1A18);
PPC_FUNC_IMPL(__imp__sub_880F1A18) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,4964
	ctx.r4.s64 = 4964;
	// stw r7,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r7.u32);
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, ctx.r5.u32);
	// stw r4,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r4.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1A64"))) PPC_WEAK_FUNC(sub_880F1A64);
PPC_FUNC_IMPL(__imp__sub_880F1A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1A68"))) PPC_WEAK_FUNC(sub_880F1A68);
PPC_FUNC_IMPL(__imp__sub_880F1A68) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,4948
	ctx.r4.s64 = 4948;
	// stw r7,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r7.u32);
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, ctx.r5.u32);
	// stw r4,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r4.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1AB4"))) PPC_WEAK_FUNC(sub_880F1AB4);
PPC_FUNC_IMPL(__imp__sub_880F1AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1AB8"))) PPC_WEAK_FUNC(sub_880F1AB8);
PPC_FUNC_IMPL(__imp__sub_880F1AB8) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30671
	ctx.r9.s64 = -2010054656;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// ori r6,r8,20077
	ctx.r6.u64 = ctx.r8.u64 | 20077;
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4200);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,4932
	ctx.r4.s64 = 4932;
	// stw r7,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r7.u32);
	// mullw r11,r11,r6
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r6.s32);
	// stw r5,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, ctx.r5.u32);
	// stw r4,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r4.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4200(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4200, ctx.r11.u32);
	// lhz r11,4200(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4200);
	// clrlwi r11,r11,28
	ctx.r11.u64 = ctx.r11.u32 & 0xF;
	// stw r11,48(r10)
	PPC_STORE_U32(ctx.r10.u32 + 48, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F1B04"))) PPC_WEAK_FUNC(sub_880F1B04);
PPC_FUNC_IMPL(__imp__sub_880F1B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1B08"))) PPC_WEAK_FUNC(sub_880F1B08);
PPC_FUNC_IMPL(__imp__sub_880F1B08) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-4
	ctx.xer.ca = ctx.r11.u32 > 3;
	ctx.r11.s64 = ctx.r11.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f1b4c
	if (!ctx.cr0.lt) goto loc_880F1B4C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F1B4C:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r4,r10,16
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r10.s32 >> 16;
	// clrlwi r6,r8,16
	ctx.r6.u64 = ctx.r8.u32 & 0xFFFF;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// clrlwi r3,r7,16
	ctx.r3.u64 = ctx.r7.u32 & 0xFFFF;
	// bl 0x88091ef8
	ctx.lr = 0x880F1B80;
	sub_88091EF8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f1bb8
	if (ctx.cr6.eq) goto loc_880F1BB8;
	// lwz r11,40(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r6,r8,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// rlwinm r4,r5,26,0,5
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0xFC000000;
	// or r11,r4,r7
	ctx.r11.u64 = ctx.r4.u64 | ctx.r7.u64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
loc_880F1BB8:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f1bec
	if (ctx.cr6.eq) goto loc_880F1BEC;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F1BEC:
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

__attribute__((alias("__imp__sub_880F1C04"))) PPC_WEAK_FUNC(sub_880F1C04);
PPC_FUNC_IMPL(__imp__sub_880F1C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1C08"))) PPC_WEAK_FUNC(sub_880F1C08);
PPC_FUNC_IMPL(__imp__sub_880F1C08) {
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
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x881538c0
	ctx.lr = 0x880F1C30;
	sub_881538C0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f1c6c
	if (ctx.cr6.eq) goto loc_880F1C6C;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
loc_880F1C6C:
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

__attribute__((alias("__imp__sub_880F1C80"))) PPC_WEAK_FUNC(sub_880F1C80);
PPC_FUNC_IMPL(__imp__sub_880F1C80) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-3
	ctx.xer.ca = ctx.r11.u32 > 2;
	ctx.r11.s64 = ctx.r11.s64 + -3;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f1cc4
	if (!ctx.cr0.lt) goto loc_880F1CC4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F1CC4:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r3,-21832
	ctx.r3.s64 = ctx.r3.s64 + -21832;
	// bl 0x881538c0
	ctx.lr = 0x880F1CE0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f1cfc
	if (ctx.cr6.eq) goto loc_880F1CFC;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F1CFC:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f1d38
	if (ctx.cr6.eq) goto loc_880F1D38;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
loc_880F1D38:
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

__attribute__((alias("__imp__sub_880F1D50"))) PPC_WEAK_FUNC(sub_880F1D50);
PPC_FUNC_IMPL(__imp__sub_880F1D50) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f1d94
	if (!ctx.cr0.lt) goto loc_880F1D94;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F1D94:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addis r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 65536;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r3,-21848
	ctx.r3.s64 = ctx.r3.s64 + -21848;
	// bl 0x881538c0
	ctx.lr = 0x880F1DB0;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f1dcc
	if (ctx.cr6.eq) goto loc_880F1DCC;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F1DCC:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f1e08
	if (ctx.cr6.eq) goto loc_880F1E08;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
loc_880F1E08:
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

__attribute__((alias("__imp__sub_880F1E20"))) PPC_WEAK_FUNC(sub_880F1E20);
PPC_FUNC_IMPL(__imp__sub_880F1E20) {
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
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x881538c0
	ctx.lr = 0x880F1E48;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f1e64
	if (ctx.cr6.eq) goto loc_880F1E64;
	// lwz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F1E64:
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f1e98
	if (ctx.cr6.eq) goto loc_880F1E98;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F1E98:
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

__attribute__((alias("__imp__sub_880F1EAC"))) PPC_WEAK_FUNC(sub_880F1EAC);
PPC_FUNC_IMPL(__imp__sub_880F1EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1EB0"))) PPC_WEAK_FUNC(sub_880F1EB0);
PPC_FUNC_IMPL(__imp__sub_880F1EB0) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-8
	ctx.xer.ca = ctx.r11.u32 > 7;
	ctx.r11.s64 = ctx.r11.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f1ef4
	if (!ctx.cr0.lt) goto loc_880F1EF4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F1EF4:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// blt cr6,0x880f1f10
	if (ctx.cr6.lt) goto loc_880F1F10;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_880F1F10:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F1F24;
	sub_880F1E20(ctx, base);
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// addi r11,r11,-6396
	ctx.r11.s64 = ctx.r11.s64 + -6396;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r11,r11,-1815
	ctx.r11.s64 = ctx.r11.s64 + -1815;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// addi r3,r11,372
	ctx.r3.s64 = ctx.r11.s64 + 372;
	// bl 0x881538c0
	ctx.lr = 0x880F1F5C;
	sub_881538C0(ctx, base);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// clrlwi r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	// beq cr6,0x880f1fa4
	if (ctx.cr6.eq) goto loc_880F1FA4;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,32784
	ctx.r6.u64 = ctx.r7.u64 | 32784;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F1FA4:
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

__attribute__((alias("__imp__sub_880F1FBC"))) PPC_WEAK_FUNC(sub_880F1FBC);
PPC_FUNC_IMPL(__imp__sub_880F1FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F1FC0"))) PPC_WEAK_FUNC(sub_880F1FC0);
PPC_FUNC_IMPL(__imp__sub_880F1FC0) {
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
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-3
	ctx.xer.ca = ctx.r10.u32 > 2;
	ctx.r10.s64 = ctx.r10.s64 + -3;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// bge 0x880f1ffc
	if (!ctx.cr0.lt) goto loc_880F1FFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_880F1FFC:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// bge 0x880f2040
	if (!ctx.cr0.lt) goto loc_880F2040;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r9,60(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// stw r9,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r9.u32);
	// bge 0x880f2040
	if (!ctx.cr0.lt) goto loc_880F2040;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_880F2040:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880f1c08
	ctx.lr = 0x880F2054;
	sub_880F1C08(ctx, base);
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

__attribute__((alias("__imp__sub_880F2068"))) PPC_WEAK_FUNC(sub_880F2068);
PPC_FUNC_IMPL(__imp__sub_880F2068) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-6
	ctx.xer.ca = ctx.r11.u32 > 5;
	ctx.r11.s64 = ctx.r11.s64 + -6;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f20ac
	if (!ctx.cr0.lt) goto loc_880F20AC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F20AC:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// blt cr6,0x880f20c8
	if (ctx.cr6.lt) goto loc_880F20C8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_880F20C8:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F20DC;
	sub_880F1E20(ctx, base);
	// li r3,397
	ctx.r3.s64 = 397;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x881538c0
	ctx.lr = 0x880F20F0;
	sub_881538C0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f2130
	if (ctx.cr6.eq) goto loc_880F2130;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,4112
	ctx.r6.u64 = ctx.r7.u64 | 4112;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F2130:
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

__attribute__((alias("__imp__sub_880F2148"))) PPC_WEAK_FUNC(sub_880F2148);
PPC_FUNC_IMPL(__imp__sub_880F2148) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-6
	ctx.xer.ca = ctx.r11.u32 > 5;
	ctx.r11.s64 = ctx.r11.s64 + -6;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f218c
	if (!ctx.cr0.lt) goto loc_880F218C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F218C:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// blt cr6,0x880f21a8
	if (ctx.cr6.lt) goto loc_880F21A8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_880F21A8:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F21BC;
	sub_880F1E20(ctx, base);
	// li r3,382
	ctx.r3.s64 = 382;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x881538c0
	ctx.lr = 0x880F21D0;
	sub_881538C0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f2210
	if (ctx.cr6.eq) goto loc_880F2210;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r7,128
	ctx.r7.s64 = 8388608;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,4112
	ctx.r6.u64 = ctx.r7.u64 | 4112;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F2210:
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

__attribute__((alias("__imp__sub_880F2228"))) PPC_WEAK_FUNC(sub_880F2228);
PPC_FUNC_IMPL(__imp__sub_880F2228) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-8
	ctx.xer.ca = ctx.r11.u32 > 7;
	ctx.r11.s64 = ctx.r11.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f226c
	if (!ctx.cr0.lt) goto loc_880F226C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F226C:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// blt cr6,0x880f2288
	if (ctx.cr6.lt) goto loc_880F2288;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_880F2288:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F229C;
	sub_880F1E20(ctx, base);
	// li r3,397
	ctx.r3.s64 = 397;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x881538c0
	ctx.lr = 0x880F22B0;
	sub_881538C0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// beq cr6,0x880f22f8
	if (ctx.cr6.eq) goto loc_880F22F8;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,32784
	ctx.r6.u64 = ctx.r7.u64 | 32784;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F22F8:
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

__attribute__((alias("__imp__sub_880F2310"))) PPC_WEAK_FUNC(sub_880F2310);
PPC_FUNC_IMPL(__imp__sub_880F2310) {
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
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-7
	ctx.xer.ca = ctx.r11.u32 > 6;
	ctx.r11.s64 = ctx.r11.s64 + -7;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r11.u32);
	// bge 0x880f2354
	if (!ctx.cr0.lt) goto loc_880F2354;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
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
loc_880F2354:
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// blt cr6,0x880f2370
	if (ctx.cr6.lt) goto loc_880F2370;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
loc_880F2370:
	// li r3,387
	ctx.r3.s64 = 387;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x881538c0
	ctx.lr = 0x880F2384;
	sub_881538C0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// beq cr6,0x880f23cc
	if (ctx.cr6.eq) goto loc_880F23CC;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// ori r6,r7,32784
	ctx.r6.u64 = ctx.r7.u64 | 32784;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F23CC:
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F23E0;
	sub_880F1E20(ctx, base);
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

__attribute__((alias("__imp__sub_880F23F8"))) PPC_WEAK_FUNC(sub_880F23F8);
PPC_FUNC_IMPL(__imp__sub_880F23F8) {
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
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r10.u32);
	// bge 0x880f244c
	if (!ctx.cr0.lt) goto loc_880F244C;
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// stw r9,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r9.u32);
	// bge 0x880f244c
	if (!ctx.cr0.lt) goto loc_880F244C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_880F244C:
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r4,r10,4932
	ctx.r4.s64 = ctx.r10.s64 + 4932;
	// bl 0x880f1e20
	ctx.lr = 0x880F245C;
	sub_880F1E20(ctx, base);
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

__attribute__((alias("__imp__sub_880F2470"))) PPC_WEAK_FUNC(sub_880F2470);
PPC_FUNC_IMPL(__imp__sub_880F2470) {
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
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-4
	ctx.xer.ca = ctx.r10.u32 > 3;
	ctx.r10.s64 = ctx.r10.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// bge 0x880f24ac
	if (!ctx.cr0.lt) goto loc_880F24AC;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_880F24AC:
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 56);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r10.u32);
	// bge 0x880f24e0
	if (!ctx.cr0.lt) goto loc_880F24E0;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// lwz r9,60(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 60);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
	// cmpwi cr6,r10,16
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16, ctx.xer);
	// stw r9,56(r11)
	PPC_STORE_U32(ctx.r11.u32 + 56, ctx.r9.u32);
	// blt cr6,0x880f24e0
	if (ctx.cr6.lt) goto loc_880F24E0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,48(r11)
	PPC_STORE_U32(ctx.r11.u32 + 48, ctx.r10.u32);
loc_880F24E0:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F24F4;
	sub_880F1E20(ctx, base);
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

__attribute__((alias("__imp__sub_880F2508"))) PPC_WEAK_FUNC(sub_880F2508);
PPC_FUNC_IMPL(__imp__sub_880F2508) {
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
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-2
	ctx.xer.ca = ctx.r10.u32 > 1;
	ctx.r10.s64 = ctx.r10.s64 + -2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// bge 0x880f2544
	if (!ctx.cr0.lt) goto loc_880F2544;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_880F2544:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r11,48(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x880f1e20
	ctx.lr = 0x880F2558;
	sub_880F1E20(ctx, base);
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

__attribute__((alias("__imp__sub_880F256C"))) PPC_WEAK_FUNC(sub_880F256C);
PPC_FUNC_IMPL(__imp__sub_880F256C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F2570"))) PPC_WEAK_FUNC(sub_880F2570);
PPC_FUNC_IMPL(__imp__sub_880F2570) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f257c
	if (!ctx.cr6.eq) goto loc_880F257C;
	// blr 
	return;
loc_880F257C:
	// stw r4,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2588"))) PPC_WEAK_FUNC(sub_880F2588);
PPC_FUNC_IMPL(__imp__sub_880F2588) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f2594
	if (!ctx.cr6.eq) goto loc_880F2594;
	// blr 
	return;
loc_880F2594:
	// stw r4,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F25A0"))) PPC_WEAK_FUNC(sub_880F25A0);
PPC_FUNC_IMPL(__imp__sub_880F25A0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f25ac
	if (!ctx.cr6.eq) goto loc_880F25AC;
	// blr 
	return;
loc_880F25AC:
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F25B8"))) PPC_WEAK_FUNC(sub_880F25B8);
PPC_FUNC_IMPL(__imp__sub_880F25B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807114c
	ctx.lr = 0x880F25C0;
	__savegprlr_25(ctx, base);
	// lis r6,-30642
	ctx.r6.s64 = -2008154112;
	// lwz r7,31016(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	// cmplwi cr6,r7,128
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 128, ctx.xer);
	// blt cr6,0x880f25d8
	if (ctx.cr6.lt) goto loc_880F25D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
loc_880F25D8:
	// lis r31,-30642
	ctx.r31.s64 = -2008154112;
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// addi r10,r31,31008
	ctx.r10.s64 = ctx.r31.s64 + 31008;
	// lis r11,-30667
	ctx.r11.s64 = -2009792512;
	// addi r29,r10,-11264
	ctx.r29.s64 = ctx.r10.s64 + -11264;
	// lwz r10,31008(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 31008);
	// lis r28,128
	ctx.r28.s64 = 8388608;
	// li r26,1
	ctx.r26.s64 = 1;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r27,r10,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,12372(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12372);
	// srawi r30,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r30.s64 = ctx.r9.s32 >> 7;
	// lwz r8,12364(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12364);
	// li r11,0
	ctx.r11.s64 = 0;
	// addze r30,r30
	temp.s64 = ctx.r30.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r30.u32;
	ctx.r30.s64 = temp.s64;
	// li r25,-1
	ctx.r25.s64 = -1;
	// lwzx r29,r27,r29
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r29.u32);
	// rlwinm r30,r30,7,0,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 7) & 0xFFFFFF80;
	// ori r28,r28,32896
	ctx.r28.u64 = ctx.r28.u64 | 32896;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r30.s64;
	// stw r7,31016(r6)
	PPC_STORE_U32(ctx.r6.u32 + 31016, ctx.r7.u32);
	// stw r3,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r26,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r26.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// stw r8,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r8.u32);
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
	// stw r4,32(r29)
	PPC_STORE_U32(ctx.r29.u32 + 32, ctx.r4.u32);
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// stw r11,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r11.u32);
	// stw r25,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r25.u32);
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// stw r11,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r11.u32);
	// stw r28,80(r29)
	PPC_STORE_U32(ctx.r29.u32 + 80, ctx.r28.u32);
	// stw r5,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r5.u32);
	// stw r11,56(r29)
	PPC_STORE_U32(ctx.r29.u32 + 56, ctx.r11.u32);
	// stw r11,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r11.u32);
	// stw r9,31008(r31)
	PPC_STORE_U32(ctx.r31.u32 + 31008, ctx.r9.u32);
	// b 0x8807119c
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F2678"))) PPC_WEAK_FUNC(sub_880F2678);
PPC_FUNC_IMPL(__imp__sub_880F2678) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// li r9,128
	ctx.r9.s64 = 128;
	// addi r11,r11,31008
	ctx.r11.s64 = ctx.r11.s64 + 31008;
	// addi r10,r10,20256
	ctx.r10.s64 = ctx.r10.s64 + 20256;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r10,-84
	ctx.r7.s64 = ctx.r10.s64 + -84;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r3,-11268(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11268, ctx.r3.u32);
loc_880F269C:
	// stwu r8,84(r7)
	ea = 84 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x880f269c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880F269C;
	// li r9,128
	ctx.r9.s64 = 128;
	// lis r6,-30642
	ctx.r6.s64 = -2008154112;
	// addi r7,r11,-11264
	ctx.r7.s64 = ctx.r11.s64 + -11264;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r8,31016(r6)
	PPC_STORE_U32(ctx.r6.u32 + 31016, ctx.r8.u32);
loc_880F26BC:
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
	// addi r10,r10,84
	ctx.r10.s64 = ctx.r10.s64 + 84;
	// bdnz 0x880f26bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880F26BC;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F26DC"))) PPC_WEAK_FUNC(sub_880F26DC);
PPC_FUNC_IMPL(__imp__sub_880F26DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F26E0"))) PPC_WEAK_FUNC(sub_880F26E0);
PPC_FUNC_IMPL(__imp__sub_880F26E0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f26ec
	if (!ctx.cr6.eq) goto loc_880F26EC;
	// blr 
	return;
loc_880F26EC:
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// stw r4,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r4.u32);
	// addic. r11,r3,28
	ctx.xer.ca = ctx.r3.u32 > 4294967267;
	ctx.r11.s64 = ctx.r3.s64 + 28;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// addi r8,r3,24
	ctx.r8.s64 = ctx.r3.s64 + 24;
	// clrlwi r9,r5,23
	ctx.r9.u64 = ctx.r5.u32 & 0x1FF;
	// addi r10,r10,9552
	ctx.r10.s64 = ctx.r10.s64 + 9552;
	// beq 0x880f2720
	if (ctx.cr0.eq) goto loc_880F2720;
	// addi r7,r9,128
	ctx.r7.s64 = ctx.r9.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// mullw r3,r5,r4
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_880F2720:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880f2738
	if (ctx.cr6.eq) goto loc_880F2738;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mullw r9,r10,r4
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_880F2738:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2740"))) PPC_WEAK_FUNC(sub_880F2740);
PPC_FUNC_IMPL(__imp__sub_880F2740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880F2748;
	__savegprlr_23(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-30642
	ctx.r28.s64 = -2008154112;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r11,31016(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 31016);
	// mr r23,r11
	ctx.r23.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,-11940(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11940, ctx.r11.u32);
	// beq cr6,0x880f290c
	if (ctx.cr6.eq) goto loc_880F290C;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r29,r11,31012
	ctx.r29.s64 = ctx.r11.s64 + 31012;
	// lwz r11,-11272(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + -11272);
	// lwz r10,236(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 236);
	// lwz r9,240(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 240);
	// lwz r8,244(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 244);
	// lwz r7,248(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 248);
	// lwz r6,252(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 252);
	// lwz r5,256(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 256);
	// lwz r4,260(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 260);
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 264);
	// lwz r31,88(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// stw r5,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r5.u32);
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// bne cr6,0x880f27c8
	if (!ctx.cr6.eq) goto loc_880F27C8;
	// lwz r25,212(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 212);
	// b 0x880f27cc
	goto loc_880F27CC;
loc_880F27C8:
	// lwz r25,208(r11)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r11.u32 + 208);
loc_880F27CC:
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// li r24,1
	ctx.r24.s64 = 1;
	// addi r11,r11,20256
	ctx.r11.s64 = ctx.r11.s64 + 20256;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// addi r26,r11,-5040
	ctx.r26.s64 = ctx.r11.s64 + -5040;
loc_880F27E8:
	// lwz r11,-4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// addi r30,r31,-4
	ctx.r30.s64 = ctx.r31.s64 + -4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f2900
	if (ctx.cr6.eq) goto loc_880F2900;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880f2820
	if (!ctx.cr6.eq) goto loc_880F2820;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r10,r26
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r26.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x880F281C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r24,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
loc_880F2820:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r6,r9,r25
	ctx.r6.u64 = ctx.r9.u64 + ctx.r25.u64;
	// stw r8,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r6,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r6.u32);
	// blt cr6,0x880f28a0
	if (ctx.cr6.lt) goto loc_880F28A0;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f287c
	if (ctx.cr6.eq) goto loc_880F287C;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x880f2874
	if (!ctx.cr6.gt) goto loc_880F2874;
	// addi r11,r11,4681
	ctx.r11.s64 = ctx.r11.s64 + 4681;
	// b 0x880f2878
	goto loc_880F2878;
loc_880F2874:
	// addi r11,r11,-4681
	ctx.r11.s64 = ctx.r11.s64 + -4681;
loc_880F2878:
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_880F287C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880f28a0
	if (ctx.cr6.eq) goto loc_880F28A0;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// addi r11,r7,4681
	ctx.r11.s64 = ctx.r7.s64 + 4681;
	// bgt cr6,0x880f289c
	if (ctx.cr6.gt) goto loc_880F289C;
	// addi r11,r7,-4681
	ctx.r11.s64 = ctx.r7.s64 + -4681;
loc_880F289C:
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_880F28A0:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r26,4
	ctx.r10.s64 = ctx.r26.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x880F28BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880f28fc
	if (!ctx.cr6.eq) goto loc_880F28FC;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r8,r29,-11268
	ctx.r8.s64 = ctx.r29.s64 + -11268;
	// lwz r9,31016(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 31016);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r27,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r6,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 7;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// stw r11,31016(r28)
	PPC_STORE_U32(ctx.r28.u32 + 31016, ctx.r11.u32);
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// stwx r30,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r30.u32);
	// subf r11,r4,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r4.s64;
	// stw r11,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_880F28FC:
	// addi r23,r23,-1
	ctx.r23.s64 = ctx.r23.s64 + -1;
loc_880F2900:
	// addi r31,r31,84
	ctx.r31.s64 = ctx.r31.s64 + 84;
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// bne cr6,0x880f27e8
	if (!ctx.cr6.eq) goto loc_880F27E8;
loc_880F290C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F2914"))) PPC_WEAK_FUNC(sub_880F2914);
PPC_FUNC_IMPL(__imp__sub_880F2914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F2918"))) PPC_WEAK_FUNC(sub_880F2918);
PPC_FUNC_IMPL(__imp__sub_880F2918) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-4448
	ctx.r11.s64 = ctx.r11.s64 + -4448;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2930"))) PPC_WEAK_FUNC(sub_880F2930);
PPC_FUNC_IMPL(__imp__sub_880F2930) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,-4448
	ctx.r9.s64 = ctx.r11.s64 + -4448;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2944"))) PPC_WEAK_FUNC(sub_880F2944);
PPC_FUNC_IMPL(__imp__sub_880F2944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F2948"))) PPC_WEAK_FUNC(sub_880F2948);
PPC_FUNC_IMPL(__imp__sub_880F2948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r3,r10,43691
	ctx.r3.u64 = ctx.r10.u64 | 43691;
	// lis r4,-30680
	ctx.r4.s64 = -2010644480;
	// mulhw r10,r5,r3
	ctx.r10.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32)) >> 32;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addi r6,r4,-4544
	ctx.r6.s64 = ctx.r4.s64 + -4544;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// rlwinm r8,r5,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lhzx r4,r8,r6
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r6.u32);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// lhz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// addi r8,r3,-1
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880f29bc
	if (!ctx.cr6.eq) goto loc_880F29BC;
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x880f29e4
	goto loc_880F29E4;
loc_880F29BC:
	// lwz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// mullw r8,r6,r9
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r6,r3,r5
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r6,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r6.s64;
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F29E4:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// sth r6,32(r11)
	PPC_STORE_U16(ctx.r11.u32 + 32, ctx.r6.u16);
	// lhz r6,26(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 26);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// lis r3,-30584
	ctx.r3.s64 = -2004353024;
	// mullw r7,r9,r5
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// stw r4,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r4.u32);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// ori r4,r3,34953
	ctx.r4.u64 = ctx.r3.u64 | 34953;
	// addi r8,r7,12345
	ctx.r8.s64 = ctx.r7.s64 + 12345;
	// mulhwu r3,r5,r4
	ctx.r3.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r4,r3,29,3,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lhz r9,4200(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// rlwinm r3,r4,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// subf r8,r4,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r4.s64;
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// subf r5,r8,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r8.s64;
	// addi r6,r9,52
	ctx.r6.s64 = ctx.r9.s64 + 52;
	// extsh r8,r5
	ctx.r8.s64 = ctx.r5.s16;
	// extsh r9,r6
	ctx.r9.s64 = ctx.r6.s16;
	// sth r6,24(r11)
	PPC_STORE_U16(ctx.r11.u32 + 24, ctx.r6.u16);
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// addi r5,r8,-7
	ctx.r5.s64 = ctx.r8.s64 + -7;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r3,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 2;
	// addi r6,r10,-16
	ctx.r6.s64 = ctx.r10.s64 + -16;
	// addze r8,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r8.s64 = temp.s64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// srawi r9,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 1;
	// sth r4,24(r11)
	PPC_STORE_U16(ctx.r11.u32 + 24, ctx.r4.u16);
	// clrlwi r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r8,26(r11)
	PPC_STORE_U16(ctx.r11.u32 + 26, ctx.r8.u16);
	// addze r10,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r10.s64 = temp.s64;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r6,r10,32
	ctx.r6.s64 = ctx.r10.s64 + 32;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r5,42(r11)
	PPC_STORE_U16(ctx.r11.u32 + 42, ctx.r5.u16);
	// sth r6,46(r11)
	PPC_STORE_U16(ctx.r11.u32 + 46, ctx.r6.u16);
	// cmpwi cr6,r3,256
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 256, ctx.xer);
	// blt cr6,0x880f2ab4
	if (ctx.cr6.lt) goto loc_880F2AB4;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r10,48(r11)
	PPC_STORE_U16(ctx.r11.u32 + 48, ctx.r10.u16);
loc_880F2AB4:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,40(r11)
	PPC_STORE_U16(ctx.r11.u32 + 40, ctx.r10.u16);
	// sth r10,38(r11)
	PPC_STORE_U16(ctx.r11.u32 + 38, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2AC8"))) PPC_WEAK_FUNC(sub_880F2AC8);
PPC_FUNC_IMPL(__imp__sub_880F2AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r3,r10,43691
	ctx.r3.u64 = ctx.r10.u64 | 43691;
	// lis r4,-30680
	ctx.r4.s64 = -2010644480;
	// mulhw r10,r5,r3
	ctx.r10.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32)) >> 32;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addi r6,r4,-4544
	ctx.r6.s64 = ctx.r4.s64 + -4544;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// rlwinm r8,r5,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lhzx r4,r8,r6
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r6.u32);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// lhz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// addi r8,r3,-1
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880f2b3c
	if (!ctx.cr6.eq) goto loc_880F2B3C;
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x880f2b64
	goto loc_880F2B64;
loc_880F2B3C:
	// lwz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// mullw r8,r6,r9
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r6,r3,r5
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r6,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r6.s64;
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F2B64:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// sth r6,32(r11)
	PPC_STORE_U16(ctx.r11.u32 + 32, ctx.r6.u16);
	// lhz r6,26(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 26);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// lis r3,-30584
	ctx.r3.s64 = -2004353024;
	// mullw r7,r9,r5
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// stw r4,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r4.u32);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// ori r4,r3,34953
	ctx.r4.u64 = ctx.r3.u64 | 34953;
	// addi r8,r7,12345
	ctx.r8.s64 = ctx.r7.s64 + 12345;
	// mulhwu r3,r5,r4
	ctx.r3.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r4,r3,29,3,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1FFFFFFF;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// rlwinm r3,r4,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lhz r9,4200(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// subf r8,r4,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r4.s64;
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r9,r9,28
	ctx.r9.u64 = ctx.r9.u32 & 0xF;
	// subf r5,r8,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r8.s64;
	// addi r6,r9,52
	ctx.r6.s64 = ctx.r9.s64 + 52;
	// extsh r8,r5
	ctx.r8.s64 = ctx.r5.s16;
	// clrlwi r9,r6,16
	ctx.r9.u64 = ctx.r6.u32 & 0xFFFF;
	// sth r6,24(r11)
	PPC_STORE_U16(ctx.r11.u32 + 24, ctx.r6.u16);
	// addi r5,r8,-7
	ctx.r5.s64 = ctx.r8.s64 + -7;
	// rlwinm r10,r10,1,27,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1E;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r3,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 2;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// addze r8,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r8.s64 = temp.s64;
	// srawi r9,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 1;
	// sth r4,24(r11)
	PPC_STORE_U16(ctx.r11.u32 + 24, ctx.r4.u16);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addze r10,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r10.s64 = temp.s64;
	// clrlwi r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r8,26(r11)
	PPC_STORE_U16(ctx.r11.u32 + 26, ctx.r8.u16);
	// addi r6,r10,32
	ctx.r6.s64 = ctx.r10.s64 + 32;
	// li r5,255
	ctx.r5.s64 = 255;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r6,46(r11)
	PPC_STORE_U16(ctx.r11.u32 + 46, ctx.r6.u16);
	// sth r5,42(r11)
	PPC_STORE_U16(ctx.r11.u32 + 42, ctx.r5.u16);
	// cmpwi cr6,r3,256
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 256, ctx.xer);
	// blt cr6,0x880f2c30
	if (ctx.cr6.lt) goto loc_880F2C30;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r10,48(r11)
	PPC_STORE_U16(ctx.r11.u32 + 48, ctx.r10.u16);
loc_880F2C30:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,40(r11)
	PPC_STORE_U16(ctx.r11.u32 + 40, ctx.r10.u16);
	// sth r10,38(r11)
	PPC_STORE_U16(ctx.r11.u32 + 38, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2C44"))) PPC_WEAK_FUNC(sub_880F2C44);
PPC_FUNC_IMPL(__imp__sub_880F2C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F2C48"))) PPC_WEAK_FUNC(sub_880F2C48);
PPC_FUNC_IMPL(__imp__sub_880F2C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r3,r10,43691
	ctx.r3.u64 = ctx.r10.u64 | 43691;
	// lis r4,-30680
	ctx.r4.s64 = -2010644480;
	// mulhw r10,r5,r3
	ctx.r10.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32)) >> 32;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addi r6,r4,-4544
	ctx.r6.s64 = ctx.r4.s64 + -4544;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// rlwinm r8,r5,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lhzx r4,r8,r6
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r6.u32);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// lhz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// addi r8,r3,-1
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880f2cbc
	if (!ctx.cr6.eq) goto loc_880F2CBC;
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x880f2ce4
	goto loc_880F2CE4;
loc_880F2CBC:
	// lwz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// mullw r8,r6,r9
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r6,r3,r5
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r6,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r6.s64;
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F2CE4:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// sth r6,32(r11)
	PPC_STORE_U16(ctx.r11.u32 + 32, ctx.r6.u16);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// lis r6,12192
	ctx.r6.s64 = 799014912;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// ori r4,r6,48771
	ctx.r4.u64 = ctx.r6.u64 | 48771;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r5,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r5.u32);
	// lhz r3,4200(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// mulhwu r9,r3,r4
	ctx.r9.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// addi r8,r7,12345
	ctx.r8.s64 = ctx.r7.s64 + 12345;
	// rlwinm r7,r9,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// mulli r5,r7,43
	ctx.r5.s64 = ctx.r7.s64 * 43;
	// lhz r9,4200(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// sth r6,40(r11)
	PPC_STORE_U16(ctx.r11.u32 + 40, ctx.r6.u16);
	// sth r6,38(r11)
	PPC_STORE_U16(ctx.r11.u32 + 38, ctx.r6.u16);
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// subf r4,r5,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r5.s64;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// addi r8,r8,26
	ctx.r8.s64 = ctx.r8.s64 + 26;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r6,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// sth r7,24(r11)
	PPC_STORE_U16(ctx.r11.u32 + 24, ctx.r7.u16);
	// srawi r9,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 1;
	// li r5,255
	ctx.r5.s64 = 255;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// addi r6,r10,5
	ctx.r6.s64 = ctx.r10.s64 + 5;
	// sth r5,42(r11)
	PPC_STORE_U16(ctx.r11.u32 + 42, ctx.r5.u16);
	// addi r8,r9,168
	ctx.r8.s64 = ctx.r9.s64 + 168;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r4,r8,16
	ctx.r4.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r8,26(r11)
	PPC_STORE_U16(ctx.r11.u32 + 26, ctx.r8.u16);
	// sth r5,46(r11)
	PPC_STORE_U16(ctx.r11.u32 + 46, ctx.r5.u16);
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// cmpwi cr6,r3,256
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 256, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r10,48(r11)
	PPC_STORE_U16(ctx.r11.u32 + 48, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2DA8"))) PPC_WEAK_FUNC(sub_880F2DA8);
PPC_FUNC_IMPL(__imp__sub_880F2DA8) {
	PPC_FUNC_PROLOGUE();
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// lbz r5,1(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r3,r10,43691
	ctx.r3.u64 = ctx.r10.u64 | 43691;
	// lis r4,-30680
	ctx.r4.s64 = -2010644480;
	// mulhw r10,r5,r3
	ctx.r10.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r3.s32)) >> 32;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addi r6,r4,-4544
	ctx.r6.s64 = ctx.r4.s64 + -4544;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r7.s64;
	// rlwinm r8,r5,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r8,r6
	ctx.r7.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lhzx r4,r8,r6
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r6.u32);
	// stw r4,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r4.u32);
	// lhz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// addi r8,r3,-1
	ctx.r8.s64 = ctx.r3.s64 + -1;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x880f2e1c
	if (!ctx.cr6.eq) goto loc_880F2E1C;
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x880f2e44
	goto loc_880F2E44;
loc_880F2E1C:
	// lwz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// mullw r8,r6,r9
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r6,r3,r5
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r6,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r6.s64;
	// clrlwi r6,r5,16
	ctx.r6.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F2E44:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// sth r6,32(r11)
	PPC_STORE_U16(ctx.r11.u32 + 32, ctx.r6.u16);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// lis r4,12192
	ctx.r4.s64 = 799014912;
	// mullw r7,r9,r6
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// stw r5,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r5.u32);
	// lhz r3,4200(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// ori r9,r4,48771
	ctx.r9.u64 = ctx.r4.u64 | 48771;
	// addi r8,r7,12345
	ctx.r8.s64 = ctx.r7.s64 + 12345;
	// mulhwu r7,r3,r9
	ctx.r7.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r9.u32)) >> 32;
	// rlwinm r5,r7,29,3,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r9,4200(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// mulli r4,r5,43
	ctx.r4.s64 = ctx.r5.s64 * 43;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// sth r6,40(r11)
	PPC_STORE_U16(ctx.r11.u32 + 40, ctx.r6.u16);
	// sth r6,38(r11)
	PPC_STORE_U16(ctx.r11.u32 + 38, ctx.r6.u16);
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// subf r9,r4,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r4.s64;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// addi r3,r9,-21
	ctx.r3.s64 = ctx.r9.s64 + -21;
	// addi r9,r8,26
	ctx.r9.s64 = ctx.r8.s64 + 26;
	// rlwinm r8,r3,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r7,r10,5
	ctx.r7.s64 = ctx.r10.s64 + 5;
	// clrlwi r3,r8,16
	ctx.r3.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r8,26(r11)
	PPC_STORE_U16(ctx.r11.u32 + 26, ctx.r8.u16);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r5,24(r11)
	PPC_STORE_U16(ctx.r11.u32 + 24, ctx.r5.u16);
	// li r10,255
	ctx.r10.s64 = 255;
	// cmpwi cr6,r9,256
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 256, ctx.xer);
	// sth r4,46(r11)
	PPC_STORE_U16(ctx.r11.u32 + 46, ctx.r4.u16);
	// sth r10,42(r11)
	PPC_STORE_U16(ctx.r11.u32 + 42, ctx.r10.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// li r10,2
	ctx.r10.s64 = 2;
	// sth r10,48(r11)
	PPC_STORE_U16(ctx.r11.u32 + 48, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F2EFC"))) PPC_WEAK_FUNC(sub_880F2EFC);
PPC_FUNC_IMPL(__imp__sub_880F2EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F2F00"))) PPC_WEAK_FUNC(sub_880F2F00);
PPC_FUNC_IMPL(__imp__sub_880F2F00) {
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
	// lhz r11,38(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x880f2f80
	if (!ctx.cr6.lt) goto loc_880F2F80;
	// lhz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f2f80
	if (ctx.cr6.eq) goto loc_880F2F80;
	// li r10,3
	ctx.r10.s64 = 3;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// sth r10,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r10.u16);
	// ble cr6,0x880f2f58
	if (!ctx.cr6.gt) goto loc_880F2F58;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r9,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// bgt cr6,0x880f2f64
	if (ctx.cr6.gt) goto loc_880F2F64;
loc_880F2F58:
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// blt cr6,0x880f2f64
	if (ctx.cr6.lt) goto loc_880F2F64;
	// sth r10,38(r31)
	PPC_STORE_U16(ctx.r31.u32 + 38, ctx.r10.u16);
loc_880F2F64:
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// sth r10,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x880f2f80
	if (!ctx.cr6.lt) goto loc_880F2F80;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r11.u16);
loc_880F2F80:
	// lhz r11,46(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 46);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880f2fc0
	if (!ctx.cr6.eq) goto loc_880F2FC0;
	// lhz r11,42(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 42);
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,42(r31)
	PPC_STORE_U16(ctx.r31.u32 + 42, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x880f2fc8
	if (!ctx.cr6.lt) goto loc_880F2FC8;
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
loc_880F2FC0:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sth r11,46(r31)
	PPC_STORE_U16(ctx.r31.u32 + 46, ctx.r11.u16);
loc_880F2FC8:
	// lhz r11,26(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 26);
	// lis r9,-30714
	ctx.r9.s64 = -2012872704;
	// lhz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r7,r9,9552
	ctx.r7.s64 = ctx.r9.s64 + 9552;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r6,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// extsh r11,r8
	ctx.r11.s64 = ctx.r8.s16;
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// lwzx r6,r4,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// lwzx r5,r3,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// cmpwi cr6,r8,28
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 28, ctx.xer);
	// mullw r8,r6,r11
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r5,r11
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r8,r4,-32768
	ctx.r8.s64 = ctx.r4.s64 + -32768;
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// blt cr6,0x880f303c
	if (ctx.cr6.lt) goto loc_880F303C;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// sth r9,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r9.u16);
loc_880F303C:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x880f3070
	if (ctx.cr6.lt) goto loc_880F3070;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,26
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 26, ctx.xer);
	// bgt cr6,0x880f3070
	if (ctx.cr6.gt) goto loc_880F3070;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// sth r9,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r9.u16);
loc_880F3070:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,18
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 18, ctx.xer);
	// bgt cr6,0x880f3094
	if (ctx.cr6.gt) goto loc_880F3094;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// sth r9,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r9.u16);
loc_880F3094:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f30d0
	if (ctx.cr6.eq) goto loc_880F30D0;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r6,r9
	ctx.r6.s64 = ctx.r9.s8;
	// extsb r5,r7
	ctx.r5.s64 = ctx.r7.s8;
	// rlwinm r11,r6,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r5,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFFFF0000;
loc_880F30D0:
	// lhz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lhz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// add r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F30F8;
	sub_881538C0(ctx, base);
	// lhz r6,42(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 42);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r6,24
	ctx.r11.u64 = ctx.r6.u32 & 0xFF;
	// beq cr6,0x880f3164
	if (ctx.cr6.eq) goto loc_880F3164;
	// lis r10,547
	ctx.r10.s64 = 35848192;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r6,40(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r4,r7,15,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0xFFFF0000;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r6,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// subf r6,r4,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r4.s64;
	// lhz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 48);
	// rlwinm r4,r5,26,0,21
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0xFFFFFC00;
	// lwz r11,-11932(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11932);
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// stw r11,-11932(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11932, ctx.r11.u32);
loc_880F3164:
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

__attribute__((alias("__imp__sub_880F317C"))) PPC_WEAK_FUNC(sub_880F317C);
PPC_FUNC_IMPL(__imp__sub_880F317C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3180"))) PPC_WEAK_FUNC(sub_880F3180);
PPC_FUNC_IMPL(__imp__sub_880F3180) {
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
	// lhz r11,38(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x880f31fc
	if (!ctx.cr6.lt) goto loc_880F31FC;
	// lhz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x880f31fc
	if (!ctx.cr6.gt) goto loc_880F31FC;
	// li r10,3
	ctx.r10.s64 = 3;
	// cmpwi cr6,r11,16
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16, ctx.xer);
	// sth r10,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r10.u16);
	// ble cr6,0x880f31dc
	if (!ctx.cr6.gt) goto loc_880F31DC;
	// li r9,1
	ctx.r9.s64 = 1;
	// sth r9,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, ctx.r9.u16);
	// bgt cr6,0x880f31e8
	if (ctx.cr6.gt) goto loc_880F31E8;
loc_880F31DC:
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// blt cr6,0x880f31e8
	if (ctx.cr6.lt) goto loc_880F31E8;
	// sth r10,38(r31)
	PPC_STORE_U16(ctx.r31.u32 + 38, ctx.r10.u16);
loc_880F31E8:
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// sth r10,24(r31)
	PPC_STORE_U16(ctx.r31.u32 + 24, ctx.r10.u16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x880f3224
	if (ctx.cr6.lt) goto loc_880F3224;
loc_880F31FC:
	// lhz r11,46(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 46);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880f322c
	if (!ctx.cr6.eq) goto loc_880F322C;
	// lhz r11,42(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 42);
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,42(r31)
	PPC_STORE_U16(ctx.r31.u32 + 42, ctx.r9.u16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bge cr6,0x880f3234
	if (!ctx.cr6.lt) goto loc_880F3234;
loc_880F3224:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880f3404
	goto loc_880F3404;
loc_880F322C:
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sth r11,46(r31)
	PPC_STORE_U16(ctx.r31.u32 + 46, ctx.r11.u16);
loc_880F3234:
	// lhz r11,26(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 26);
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// lhz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// clrlwi r11,r11,23
	ctx.r11.u64 = ctx.r11.u32 & 0x1FF;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r7,r10,9552
	ctx.r7.s64 = ctx.r10.s64 + 9552;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// extsh r30,r9
	ctx.r30.s64 = ctx.r9.s16;
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// lwzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// rlwinm r9,r4,2,21,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// extsh r4,r3
	ctx.r4.s64 = ctx.r3.s16;
	// mullw r3,r8,r30
	ctx.r3.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r30.s32);
	// lwzx r8,r9,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// addi r5,r11,-88
	ctx.r5.s64 = ctx.r11.s64 + -88;
	// srawi r7,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 2;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r3,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 1;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addze r7,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r7.s64 = temp.s64;
	// mullw r8,r8,r30
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r30.s32);
	// rlwinm r7,r7,10,0,21
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 10) & 0xFFFFFC00;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r6,r9,r6
	ctx.r6.u64 = ctx.r9.u64 + ctx.r6.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// cmpwi cr6,r4,28
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 28, ctx.xer);
	// stw r5,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r5.u32);
	// blt cr6,0x880f32d4
	if (ctx.cr6.lt) goto loc_880F32D4;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// sth r9,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r9.u16);
loc_880F32D4:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// blt cr6,0x880f3308
	if (ctx.cr6.lt) goto loc_880F3308;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,26
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 26, ctx.xer);
	// bgt cr6,0x880f3308
	if (ctx.cr6.gt) goto loc_880F3308;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// sth r9,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r9.u16);
loc_880F3308:
	// lhz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 24);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,18
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 18, ctx.xer);
	// bgt cr6,0x880f332c
	if (ctx.cr6.gt) goto loc_880F332C;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r9,r10,27
	ctx.r9.u64 = ctx.r10.u32 & 0x1F;
	// sth r9,32(r31)
	PPC_STORE_U16(ctx.r31.u32 + 32, ctx.r9.u16);
loc_880F332C:
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f3368
	if (ctx.cr6.eq) goto loc_880F3368;
	// lhz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,1(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// extsb r6,r8
	ctx.r6.s64 = ctx.r8.s8;
	// rlwinm r11,r7,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r6,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
loc_880F3368:
	// lhz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 12);
	// lhz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 32);
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F3394;
	sub_881538C0(ctx, base);
	// lhz r7,42(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 42);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r7,24
	ctx.r11.u64 = ctx.r7.u32 & 0xFF;
	// beq cr6,0x880f3400
	if (ctx.cr6.eq) goto loc_880F3400;
	// lis r10,547
	ctx.r10.s64 = 35848192;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r6,40(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r4,r7,15,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0xFFFF0000;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r6,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// subf r6,r4,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r4.s64;
	// lhz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 48);
	// rlwinm r4,r5,26,0,21
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 26) & 0xFFFFFC00;
	// lwz r11,-11932(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11932);
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// stw r11,-11932(r8)
	PPC_STORE_U32(ctx.r8.u32 + -11932, ctx.r11.u32);
loc_880F3400:
	// li r3,1
	ctx.r3.s64 = 1;
loc_880F3404:
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

__attribute__((alias("__imp__sub_880F341C"))) PPC_WEAK_FUNC(sub_880F341C);
PPC_FUNC_IMPL(__imp__sub_880F341C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3420"))) PPC_WEAK_FUNC(sub_880F3420);
PPC_FUNC_IMPL(__imp__sub_880F3420) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// sth r4,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3430"))) PPC_WEAK_FUNC(sub_880F3430);
PPC_FUNC_IMPL(__imp__sub_880F3430) {
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
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r31,r10,19728
	ctx.r31.s64 = ctx.r10.s64 + 19728;
	// li r5,7168
	ctx.r5.s64 = 7168;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,-7168
	ctx.r3.s64 = ctx.r31.s64 + -7168;
	// stw r11,-7684(r31)
	PPC_STORE_U32(ctx.r31.u32 + -7684, ctx.r11.u32);
	// bl 0x88073bd0
	ctx.lr = 0x880F3460;
	sub_88073BD0(ctx, base);
	// li r10,128
	ctx.r10.s64 = 128;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r31,-7680
	ctx.r8.s64 = ctx.r31.s64 + -7680;
	// stw r9,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// addi r11,r31,-7168
	ctx.r11.s64 = ctx.r31.s64 + -7168;
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_880F347C:
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// addi r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 + 56;
	// bdnz 0x880f347c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880F347C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_880F34AC"))) PPC_WEAK_FUNC(sub_880F34AC);
PPC_FUNC_IMPL(__imp__sub_880F34AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F34B0"))) PPC_WEAK_FUNC(sub_880F34B0);
PPC_FUNC_IMPL(__imp__sub_880F34B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8807115c
	ctx.lr = 0x880F34B8;
	__savegprlr_29(ctx, base);
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// addi r11,r11,19728
	ctx.r11.s64 = ctx.r11.s64 + 19728;
	// lis r9,-30667
	ctx.r9.s64 = -2009792512;
	// lwz r6,12372(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12372);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r5,12364(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12364);
	// cmplwi cr6,r7,128
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 128, ctx.xer);
	// blt cr6,0x880f34e4
	if (ctx.cr6.lt) goto loc_880F34E4;
loc_880F34DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
loc_880F34E4:
	// lis r10,-30643
	ctx.r10.s64 = -2008219648;
	// addi r9,r10,26432
	ctx.r9.s64 = ctx.r10.s64 + 26432;
	// lwz r10,312(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x880f3508
	if (!ctx.cr6.eq) goto loc_880F3508;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r10,-13976(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13976);
	// cmpwi cr6,r10,15
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 15, ctx.xer);
	// bge cr6,0x880f34dc
	if (!ctx.cr6.lt) goto loc_880F34DC;
loc_880F3508:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r31,r11,-7680
	ctx.r31.s64 = ctx.r11.s64 + -7680;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r30,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r30.s64 = ctx.r9.s32 >> 7;
	// li r29,1
	ctx.r29.s64 = 1;
	// addze r30,r30
	temp.s64 = ctx.r30.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r30.u32;
	ctx.r30.s64 = temp.s64;
	// lwzx r31,r10,r31
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// rlwinm r30,r30,7,0,24
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 7) & 0xFFFFFF80;
	// addi r10,r7,1
	ctx.r10.s64 = ctx.r7.s64 + 1;
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r30.s64;
	// stw r10,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stb r3,1(r31)
	PPC_STORE_U8(ctx.r31.u32 + 1, ctx.r3.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// stw r5,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sth r4,12(r31)
	PPC_STORE_U16(ctx.r31.u32 + 12, ctx.r4.u16);
	// sth r8,26(r31)
	PPC_STORE_U16(ctx.r31.u32 + 26, ctx.r8.u16);
	// sth r8,44(r31)
	PPC_STORE_U16(ctx.r31.u32 + 44, ctx.r8.u16);
	// sth r8,48(r31)
	PPC_STORE_U16(ctx.r31.u32 + 48, ctx.r8.u16);
	// b 0x880711ac
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F3568"))) PPC_WEAK_FUNC(sub_880F3568);
PPC_FUNC_IMPL(__imp__sub_880F3568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880F3570;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// addi r30,r11,19732
	ctx.r30.s64 = ctx.r11.s64 + 19732;
	// addi r31,r30,-7172
	ctx.r31.s64 = ctx.r30.s64 + -7172;
	// lwz r25,4(r30)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x880f3688
	if (ctx.cr6.eq) goto loc_880F3688;
	// lwz r11,-7688(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -7688);
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 208);
	// lwz r11,212(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 212);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// beq cr6,0x880f35ac
	if (ctx.cr6.eq) goto loc_880F35AC;
	// mr r27,r10
	ctx.r27.u64 = ctx.r10.u64;
loc_880F35AC:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// li r26,2
	ctx.r26.s64 = 2;
	// li r24,128
	ctx.r24.s64 = 128;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r11,-4448
	ctx.r29.s64 = ctx.r11.s64 + -4448;
loc_880F35C0:
	// lbz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f367c
	if (ctx.cr6.eq) goto loc_880F367C;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x880f35f4
	if (!ctx.cr6.eq) goto loc_880F35F4;
	// lbz r11,1(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 3);
	// lwzx r9,r10,r29
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x880F35F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r26,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r26.u8);
loc_880F35F4:
	// lhz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 44);
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,44(r31)
	PPC_STORE_U16(ctx.r31.u32 + 44, ctx.r9.u16);
	// cmpwi cr6,r9,128
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 128, ctx.xer);
	// blt cr6,0x880f3610
	if (ctx.cr6.lt) goto loc_880F3610;
	// sth r24,44(r31)
	PPC_STORE_U16(ctx.r31.u32 + 44, ctx.r24.u16);
loc_880F3610:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r29,4
	ctx.r10.s64 = ctx.r29.s64 + 4;
	// lbz r9,1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 1);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r8,r11,r27
	ctx.r8.u64 = ctx.r11.u64 + ctx.r27.u64;
	// rotlwi r7,r9,3
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 3);
	// stw r8,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x880F3638;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880f3678
	if (!ctx.cr6.eq) goto loc_880F3678;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r8,r30,-7684
	ctx.r8.s64 = ctx.r30.s64 + -7684;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r6,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 7;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// stwx r31,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r31.u32);
	// subf r11,r4,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r4.s64;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_880F3678:
	// addi r25,r25,-1
	ctx.r25.s64 = ctx.r25.s64 + -1;
loc_880F367C:
	// addi r31,r31,56
	ctx.r31.s64 = ctx.r31.s64 + 56;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// bne cr6,0x880f35c0
	if (!ctx.cr6.eq) goto loc_880F35C0;
loc_880F3688:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F3690"))) PPC_WEAK_FUNC(sub_880F3690);
PPC_FUNC_IMPL(__imp__sub_880F3690) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,25
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 25, ctx.xer);
	// blt cr6,0x880f369c
	if (ctx.cr6.lt) goto loc_880F369C;
	// li r3,24
	ctx.r3.s64 = 24;
loc_880F369C:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,4120
	ctx.r11.s64 = ctx.r11.s64 + 4120;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F36B4"))) PPC_WEAK_FUNC(sub_880F36B4);
PPC_FUNC_IMPL(__imp__sub_880F36B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F36B8"))) PPC_WEAK_FUNC(sub_880F36B8);
PPC_FUNC_IMPL(__imp__sub_880F36B8) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,25
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 25, ctx.xer);
	// blt cr6,0x880f36c4
	if (ctx.cr6.lt) goto loc_880F36C4;
	// li r3,24
	ctx.r3.s64 = 24;
loc_880F36C4:
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,4120
	ctx.r9.s64 = ctx.r11.s64 + 4120;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F36D8"))) PPC_WEAK_FUNC(sub_880F36D8);
PPC_FUNC_IMPL(__imp__sub_880F36D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3734
	if (!ctx.cr0.lt) goto loc_880F3734;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3704
	if (!ctx.cr0.lt) goto loc_880F3704;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3704:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3724
	if (ctx.cr6.lt) goto loc_880F3724;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3724:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,3852
	ctx.r8.s64 = ctx.r9.s64 + 3852;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3734:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,3928
	ctx.r9.s64 = ctx.r6.s64 + 3928;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,3876
	ctx.r10.s64 = ctx.r5.s64 + 3876;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3784"))) PPC_WEAK_FUNC(sub_880F3784);
PPC_FUNC_IMPL(__imp__sub_880F3784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3788"))) PPC_WEAK_FUNC(sub_880F3788);
PPC_FUNC_IMPL(__imp__sub_880F3788) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,24
	ctx.r6.s64 = 24;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,3852(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3852);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f37cc
	if (ctx.cr6.eq) goto loc_880F37CC;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F37CC:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f37e0
	if (ctx.cr6.eq) goto loc_880F37E0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F37E0:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F37F8"))) PPC_WEAK_FUNC(sub_880F37F8);
PPC_FUNC_IMPL(__imp__sub_880F37F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3854
	if (!ctx.cr0.lt) goto loc_880F3854;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3824
	if (!ctx.cr0.lt) goto loc_880F3824;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3824:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3844
	if (ctx.cr6.lt) goto loc_880F3844;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3844:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,3460
	ctx.r8.s64 = ctx.r9.s64 + 3460;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3854:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,3568
	ctx.r9.s64 = ctx.r6.s64 + 3568;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,3496
	ctx.r10.s64 = ctx.r5.s64 + 3496;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F38A4"))) PPC_WEAK_FUNC(sub_880F38A4);
PPC_FUNC_IMPL(__imp__sub_880F38A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F38A8"))) PPC_WEAK_FUNC(sub_880F38A8);
PPC_FUNC_IMPL(__imp__sub_880F38A8) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,35
	ctx.r6.s64 = 35;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,3460(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3460);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f38ec
	if (ctx.cr6.eq) goto loc_880F38EC;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F38EC:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3900
	if (ctx.cr6.eq) goto loc_880F3900;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3900:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3918"))) PPC_WEAK_FUNC(sub_880F3918);
PPC_FUNC_IMPL(__imp__sub_880F3918) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3974
	if (!ctx.cr0.lt) goto loc_880F3974;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3944
	if (!ctx.cr0.lt) goto loc_880F3944;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3944:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3964
	if (ctx.cr6.lt) goto loc_880F3964;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3964:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,3108
	ctx.r8.s64 = ctx.r9.s64 + 3108;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3974:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,3208
	ctx.r9.s64 = ctx.r6.s64 + 3208;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,3140
	ctx.r10.s64 = ctx.r5.s64 + 3140;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F39C4"))) PPC_WEAK_FUNC(sub_880F39C4);
PPC_FUNC_IMPL(__imp__sub_880F39C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F39C8"))) PPC_WEAK_FUNC(sub_880F39C8);
PPC_FUNC_IMPL(__imp__sub_880F39C8) {
	PPC_FUNC_PROLOGUE();
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r7,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r7.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,31
	ctx.r6.s64 = 31;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,3108(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3108);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f3a0c
	if (ctx.cr6.eq) goto loc_880F3A0C;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F3A0C:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3a20
	if (ctx.cr6.eq) goto loc_880F3A20;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3A20:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3A38"))) PPC_WEAK_FUNC(sub_880F3A38);
PPC_FUNC_IMPL(__imp__sub_880F3A38) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3a94
	if (!ctx.cr0.lt) goto loc_880F3A94;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3a64
	if (!ctx.cr0.lt) goto loc_880F3A64;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3A64:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3a84
	if (ctx.cr6.lt) goto loc_880F3A84;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3A84:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,2780
	ctx.r8.s64 = ctx.r9.s64 + 2780;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3A94:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,2872
	ctx.r9.s64 = ctx.r6.s64 + 2872;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,2812
	ctx.r10.s64 = ctx.r5.s64 + 2812;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3AE4"))) PPC_WEAK_FUNC(sub_880F3AE4);
PPC_FUNC_IMPL(__imp__sub_880F3AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3AE8"))) PPC_WEAK_FUNC(sub_880F3AE8);
PPC_FUNC_IMPL(__imp__sub_880F3AE8) {
	PPC_FUNC_PROLOGUE();
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r7,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r7.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,29
	ctx.r6.s64 = 29;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,2780(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2780);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f3b2c
	if (ctx.cr6.eq) goto loc_880F3B2C;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F3B2C:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3b40
	if (ctx.cr6.eq) goto loc_880F3B40;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3B40:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3B58"))) PPC_WEAK_FUNC(sub_880F3B58);
PPC_FUNC_IMPL(__imp__sub_880F3B58) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3bb4
	if (!ctx.cr0.lt) goto loc_880F3BB4;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3b84
	if (!ctx.cr0.lt) goto loc_880F3B84;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3B84:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3ba4
	if (ctx.cr6.lt) goto loc_880F3BA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3BA4:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,2404
	ctx.r8.s64 = ctx.r9.s64 + 2404;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3BB4:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,2512
	ctx.r9.s64 = ctx.r6.s64 + 2512;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,2440
	ctx.r10.s64 = ctx.r5.s64 + 2440;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3C04"))) PPC_WEAK_FUNC(sub_880F3C04);
PPC_FUNC_IMPL(__imp__sub_880F3C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3C08"))) PPC_WEAK_FUNC(sub_880F3C08);
PPC_FUNC_IMPL(__imp__sub_880F3C08) {
	PPC_FUNC_PROLOGUE();
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r7,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r7.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,33
	ctx.r6.s64 = 33;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,2404(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2404);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f3c4c
	if (ctx.cr6.eq) goto loc_880F3C4C;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F3C4C:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3c60
	if (ctx.cr6.eq) goto loc_880F3C60;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3C60:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3C78"))) PPC_WEAK_FUNC(sub_880F3C78);
PPC_FUNC_IMPL(__imp__sub_880F3C78) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3cd4
	if (!ctx.cr0.lt) goto loc_880F3CD4;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3ca4
	if (!ctx.cr0.lt) goto loc_880F3CA4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3CA4:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3cc4
	if (ctx.cr6.lt) goto loc_880F3CC4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3CC4:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,2004
	ctx.r8.s64 = ctx.r9.s64 + 2004;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3CD4:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,2112
	ctx.r9.s64 = ctx.r6.s64 + 2112;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,2040
	ctx.r10.s64 = ctx.r5.s64 + 2040;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3D24"))) PPC_WEAK_FUNC(sub_880F3D24);
PPC_FUNC_IMPL(__imp__sub_880F3D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3D28"))) PPC_WEAK_FUNC(sub_880F3D28);
PPC_FUNC_IMPL(__imp__sub_880F3D28) {
	PPC_FUNC_PROLOGUE();
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r7,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r7.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,36
	ctx.r6.s64 = 36;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,2004(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2004);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f3d6c
	if (ctx.cr6.eq) goto loc_880F3D6C;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F3D6C:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3d80
	if (ctx.cr6.eq) goto loc_880F3D80;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3D80:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3D98"))) PPC_WEAK_FUNC(sub_880F3D98);
PPC_FUNC_IMPL(__imp__sub_880F3D98) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3df4
	if (!ctx.cr0.lt) goto loc_880F3DF4;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3dc4
	if (!ctx.cr0.lt) goto loc_880F3DC4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3DC4:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3de4
	if (ctx.cr6.lt) goto loc_880F3DE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3DE4:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,1644
	ctx.r8.s64 = ctx.r9.s64 + 1644;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3DF4:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,1744
	ctx.r9.s64 = ctx.r6.s64 + 1744;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,1680
	ctx.r10.s64 = ctx.r5.s64 + 1680;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3E44"))) PPC_WEAK_FUNC(sub_880F3E44);
PPC_FUNC_IMPL(__imp__sub_880F3E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3E48"))) PPC_WEAK_FUNC(sub_880F3E48);
PPC_FUNC_IMPL(__imp__sub_880F3E48) {
	PPC_FUNC_PROLOGUE();
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r7,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r7.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,32
	ctx.r6.s64 = 32;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,1644(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1644);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f3e8c
	if (ctx.cr6.eq) goto loc_880F3E8C;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F3E8C:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3ea0
	if (ctx.cr6.eq) goto loc_880F3EA0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3EA0:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3EB8"))) PPC_WEAK_FUNC(sub_880F3EB8);
PPC_FUNC_IMPL(__imp__sub_880F3EB8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f3f14
	if (!ctx.cr0.lt) goto loc_880F3F14;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f3ee4
	if (!ctx.cr0.lt) goto loc_880F3EE4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F3EE4:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f3f04
	if (ctx.cr6.lt) goto loc_880F3F04;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F3F04:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,1252
	ctx.r8.s64 = ctx.r9.s64 + 1252;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F3F14:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,1360
	ctx.r9.s64 = ctx.r6.s64 + 1360;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,1288
	ctx.r10.s64 = ctx.r5.s64 + 1288;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3F64"))) PPC_WEAK_FUNC(sub_880F3F64);
PPC_FUNC_IMPL(__imp__sub_880F3F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F3F68"))) PPC_WEAK_FUNC(sub_880F3F68);
PPC_FUNC_IMPL(__imp__sub_880F3F68) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,35
	ctx.r6.s64 = 35;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,1252(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1252);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f3fac
	if (ctx.cr6.eq) goto loc_880F3FAC;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F3FAC:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f3fc0
	if (ctx.cr6.eq) goto loc_880F3FC0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F3FC0:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F3FD8"))) PPC_WEAK_FUNC(sub_880F3FD8);
PPC_FUNC_IMPL(__imp__sub_880F3FD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4034
	if (!ctx.cr0.lt) goto loc_880F4034;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f4004
	if (!ctx.cr0.lt) goto loc_880F4004;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F4004:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4024
	if (ctx.cr6.lt) goto loc_880F4024;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4024:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,940
	ctx.r8.s64 = ctx.r9.s64 + 940;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4034:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,1024
	ctx.r9.s64 = ctx.r6.s64 + 1024;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,968
	ctx.r10.s64 = ctx.r5.s64 + 968;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4084"))) PPC_WEAK_FUNC(sub_880F4084);
PPC_FUNC_IMPL(__imp__sub_880F4084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4088"))) PPC_WEAK_FUNC(sub_880F4088);
PPC_FUNC_IMPL(__imp__sub_880F4088) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,28
	ctx.r6.s64 = 28;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,940(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 940);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f40cc
	if (ctx.cr6.eq) goto loc_880F40CC;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F40CC:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f40e0
	if (ctx.cr6.eq) goto loc_880F40E0;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F40E0:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F40F8"))) PPC_WEAK_FUNC(sub_880F40F8);
PPC_FUNC_IMPL(__imp__sub_880F40F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f413c
	if (!ctx.cr0.lt) goto loc_880F413C;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f412c
	if (ctx.cr6.lt) goto loc_880F412C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F412C:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,636
	ctx.r8.s64 = ctx.r9.s64 + 636;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F413C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,720
	ctx.r9.s64 = ctx.r6.s64 + 720;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,664
	ctx.r10.s64 = ctx.r5.s64 + 664;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F418C"))) PPC_WEAK_FUNC(sub_880F418C);
PPC_FUNC_IMPL(__imp__sub_880F418C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4190"))) PPC_WEAK_FUNC(sub_880F4190);
PPC_FUNC_IMPL(__imp__sub_880F4190) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,27
	ctx.r6.s64 = 27;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,636(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 636);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f41d4
	if (ctx.cr6.eq) goto loc_880F41D4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F41D4:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f41e8
	if (ctx.cr6.eq) goto loc_880F41E8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F41E8:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4200"))) PPC_WEAK_FUNC(sub_880F4200);
PPC_FUNC_IMPL(__imp__sub_880F4200) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4244
	if (!ctx.cr0.lt) goto loc_880F4244;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4234
	if (ctx.cr6.lt) goto loc_880F4234;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4234:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,332
	ctx.r8.s64 = ctx.r9.s64 + 332;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4244:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,416
	ctx.r9.s64 = ctx.r6.s64 + 416;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,360
	ctx.r10.s64 = ctx.r5.s64 + 360;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4294"))) PPC_WEAK_FUNC(sub_880F4294);
PPC_FUNC_IMPL(__imp__sub_880F4294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4298"))) PPC_WEAK_FUNC(sub_880F4298);
PPC_FUNC_IMPL(__imp__sub_880F4298) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,27
	ctx.r6.s64 = 27;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,332(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + 332);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f42dc
	if (ctx.cr6.eq) goto loc_880F42DC;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F42DC:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f42f0
	if (ctx.cr6.eq) goto loc_880F42F0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F42F0:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4308"))) PPC_WEAK_FUNC(sub_880F4308);
PPC_FUNC_IMPL(__imp__sub_880F4308) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f434c
	if (!ctx.cr0.lt) goto loc_880F434C;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f433c
	if (ctx.cr6.lt) goto loc_880F433C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F433C:
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r9,-12152
	ctx.r8.s64 = ctx.r9.s64 + -12152;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F434C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,80
	ctx.r9.s64 = ctx.r6.s64 + 80;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,12
	ctx.r10.s64 = ctx.r5.s64 + 12;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F439C"))) PPC_WEAK_FUNC(sub_880F439C);
PPC_FUNC_IMPL(__imp__sub_880F439C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F43A0"))) PPC_WEAK_FUNC(sub_880F43A0);
PPC_FUNC_IMPL(__imp__sub_880F43A0) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,31
	ctx.r6.s64 = 31;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-12152(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -12152);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f43e4
	if (ctx.cr6.eq) goto loc_880F43E4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F43E4:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f43f8
	if (ctx.cr6.eq) goto loc_880F43F8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F43F8:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4410"))) PPC_WEAK_FUNC(sub_880F4410);
PPC_FUNC_IMPL(__imp__sub_880F4410) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f446c
	if (!ctx.cr0.lt) goto loc_880F446C;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f443c
	if (!ctx.cr0.lt) goto loc_880F443C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F443C:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f445c
	if (ctx.cr6.lt) goto loc_880F445C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F445C:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,1252
	ctx.r8.s64 = ctx.r9.s64 + 1252;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F446C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,1360
	ctx.r9.s64 = ctx.r6.s64 + 1360;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,1288
	ctx.r10.s64 = ctx.r5.s64 + 1288;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F44BC"))) PPC_WEAK_FUNC(sub_880F44BC);
PPC_FUNC_IMPL(__imp__sub_880F44BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F44C0"))) PPC_WEAK_FUNC(sub_880F44C0);
PPC_FUNC_IMPL(__imp__sub_880F44C0) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,35
	ctx.r6.s64 = 35;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,1252(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1252);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4504
	if (ctx.cr6.eq) goto loc_880F4504;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F4504:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f4518
	if (ctx.cr6.eq) goto loc_880F4518;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F4518:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f4528
	if (ctx.cr6.eq) goto loc_880F4528;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
loc_880F4528:
	// lis r10,185
	ctx.r10.s64 = 12124160;
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r9,r10,39547
	ctx.r9.u64 = ctx.r10.u64 | 39547;
	// stw r9,160(r11)
	PPC_STORE_U32(ctx.r11.u32 + 160, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F453C"))) PPC_WEAK_FUNC(sub_880F453C);
PPC_FUNC_IMPL(__imp__sub_880F453C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4540"))) PPC_WEAK_FUNC(sub_880F4540);
PPC_FUNC_IMPL(__imp__sub_880F4540) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f459c
	if (!ctx.cr0.lt) goto loc_880F459C;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f456c
	if (!ctx.cr0.lt) goto loc_880F456C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F456C:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f458c
	if (ctx.cr6.lt) goto loc_880F458C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F458C:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-340
	ctx.r8.s64 = ctx.r9.s64 + -340;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F459C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-240
	ctx.r9.s64 = ctx.r6.s64 + -240;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-308
	ctx.r10.s64 = ctx.r5.s64 + -308;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F45EC"))) PPC_WEAK_FUNC(sub_880F45EC);
PPC_FUNC_IMPL(__imp__sub_880F45EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F45F0"))) PPC_WEAK_FUNC(sub_880F45F0);
PPC_FUNC_IMPL(__imp__sub_880F45F0) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,31
	ctx.r6.s64 = 31;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,-340(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + -340);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4634
	if (ctx.cr6.eq) goto loc_880F4634;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F4634:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f4648
	if (ctx.cr6.eq) goto loc_880F4648;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F4648:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4660"))) PPC_WEAK_FUNC(sub_880F4660);
PPC_FUNC_IMPL(__imp__sub_880F4660) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f46bc
	if (!ctx.cr0.lt) goto loc_880F46BC;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f468c
	if (!ctx.cr0.lt) goto loc_880F468C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F468C:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f46ac
	if (ctx.cr6.lt) goto loc_880F46AC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F46AC:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,940
	ctx.r8.s64 = ctx.r9.s64 + 940;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F46BC:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,1024
	ctx.r9.s64 = ctx.r6.s64 + 1024;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,968
	ctx.r10.s64 = ctx.r5.s64 + 968;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F470C"))) PPC_WEAK_FUNC(sub_880F470C);
PPC_FUNC_IMPL(__imp__sub_880F470C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4710"))) PPC_WEAK_FUNC(sub_880F4710);
PPC_FUNC_IMPL(__imp__sub_880F4710) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,28
	ctx.r6.s64 = 28;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,940(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 940);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4754
	if (ctx.cr6.eq) goto loc_880F4754;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F4754:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f4768
	if (ctx.cr6.eq) goto loc_880F4768;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F4768:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f4778
	if (ctx.cr6.eq) goto loc_880F4778;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
loc_880F4778:
	// lis r10,185
	ctx.r10.s64 = 12124160;
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r9,r10,39547
	ctx.r9.u64 = ctx.r10.u64 | 39547;
	// stw r9,160(r11)
	PPC_STORE_U32(ctx.r11.u32 + 160, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F478C"))) PPC_WEAK_FUNC(sub_880F478C);
PPC_FUNC_IMPL(__imp__sub_880F478C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4790"))) PPC_WEAK_FUNC(sub_880F4790);
PPC_FUNC_IMPL(__imp__sub_880F4790) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f47ec
	if (!ctx.cr0.lt) goto loc_880F47EC;
	// lwz r10,140(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// addic. r10,r10,-8
	ctx.xer.ca = ctx.r10.u32 > 7;
	ctx.r10.s64 = ctx.r10.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
	// bge 0x880f47bc
	if (!ctx.cr0.lt) goto loc_880F47BC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r10.u32);
loc_880F47BC:
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r11)
	PPC_STORE_U32(ctx.r11.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f47dc
	if (ctx.cr6.lt) goto loc_880F47DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F47DC:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-644
	ctx.r8.s64 = ctx.r9.s64 + -644;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F47EC:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-560
	ctx.r9.s64 = ctx.r6.s64 + -560;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-616
	ctx.r10.s64 = ctx.r5.s64 + -616;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F483C"))) PPC_WEAK_FUNC(sub_880F483C);
PPC_FUNC_IMPL(__imp__sub_880F483C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4840"))) PPC_WEAK_FUNC(sub_880F4840);
PPC_FUNC_IMPL(__imp__sub_880F4840) {
	PPC_FUNC_PROLOGUE();
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// lis r10,-30680
	ctx.r10.s64 = -2010644480;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,27
	ctx.r6.s64 = 27;
	// rlwinm r5,r9,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x8;
	// lbz r4,-644(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + -644);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4884
	if (ctx.cr6.eq) goto loc_880F4884;
	// stw r8,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r8.u32);
loc_880F4884:
	// rlwinm r10,r9,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f4898
	if (ctx.cr6.eq) goto loc_880F4898;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r10.u32);
loc_880F4898:
	// rlwinm r10,r9,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F48B0"))) PPC_WEAK_FUNC(sub_880F48B0);
PPC_FUNC_IMPL(__imp__sub_880F48B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f48f4
	if (!ctx.cr0.lt) goto loc_880F48F4;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f48e4
	if (ctx.cr6.lt) goto loc_880F48E4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F48E4:
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// addi r8,r9,-12188
	ctx.r8.s64 = ctx.r9.s64 + -12188;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F48F4:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-928
	ctx.r9.s64 = ctx.r6.s64 + -928;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-1000
	ctx.r10.s64 = ctx.r5.s64 + -1000;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4944"))) PPC_WEAK_FUNC(sub_880F4944);
PPC_FUNC_IMPL(__imp__sub_880F4944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4948"))) PPC_WEAK_FUNC(sub_880F4948);
PPC_FUNC_IMPL(__imp__sub_880F4948) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30597
	ctx.r9.s64 = -2005204992;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,35
	ctx.r6.s64 = 35;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-12188(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -12188);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f498c
	if (ctx.cr6.eq) goto loc_880F498C;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F498C:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f49a0
	if (ctx.cr6.eq) goto loc_880F49A0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F49A0:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F49B8"))) PPC_WEAK_FUNC(sub_880F49B8);
PPC_FUNC_IMPL(__imp__sub_880F49B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f49fc
	if (!ctx.cr0.lt) goto loc_880F49FC;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f49ec
	if (ctx.cr6.lt) goto loc_880F49EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F49EC:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-1404
	ctx.r8.s64 = ctx.r9.s64 + -1404;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F49FC:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-1296
	ctx.r9.s64 = ctx.r6.s64 + -1296;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-1368
	ctx.r10.s64 = ctx.r5.s64 + -1368;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4A4C"))) PPC_WEAK_FUNC(sub_880F4A4C);
PPC_FUNC_IMPL(__imp__sub_880F4A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4A50"))) PPC_WEAK_FUNC(sub_880F4A50);
PPC_FUNC_IMPL(__imp__sub_880F4A50) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,36
	ctx.r6.s64 = 36;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-1404(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1404);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4a94
	if (ctx.cr6.eq) goto loc_880F4A94;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F4A94:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f4aa8
	if (ctx.cr6.eq) goto loc_880F4AA8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F4AA8:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4AC0"))) PPC_WEAK_FUNC(sub_880F4AC0);
PPC_FUNC_IMPL(__imp__sub_880F4AC0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4b04
	if (!ctx.cr0.lt) goto loc_880F4B04;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4af4
	if (ctx.cr6.lt) goto loc_880F4AF4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4AF4:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-2924
	ctx.r8.s64 = ctx.r9.s64 + -2924;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4B04:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-2800
	ctx.r9.s64 = ctx.r6.s64 + -2800;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-2880
	ctx.r10.s64 = ctx.r5.s64 + -2880;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4B54"))) PPC_WEAK_FUNC(sub_880F4B54);
PPC_FUNC_IMPL(__imp__sub_880F4B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4B58"))) PPC_WEAK_FUNC(sub_880F4B58);
PPC_FUNC_IMPL(__imp__sub_880F4B58) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,39
	ctx.r6.s64 = 39;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-2924(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -2924);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4b9c
	if (ctx.cr6.eq) goto loc_880F4B9C;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F4B9C:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f4bb0
	if (ctx.cr6.eq) goto loc_880F4BB0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F4BB0:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4BC8"))) PPC_WEAK_FUNC(sub_880F4BC8);
PPC_FUNC_IMPL(__imp__sub_880F4BC8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4c0c
	if (!ctx.cr0.lt) goto loc_880F4C0C;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4bfc
	if (ctx.cr6.lt) goto loc_880F4BFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4BFC:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-3404
	ctx.r8.s64 = ctx.r9.s64 + -3404;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4C0C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-3272
	ctx.r9.s64 = ctx.r6.s64 + -3272;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-3360
	ctx.r10.s64 = ctx.r5.s64 + -3360;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4C5C"))) PPC_WEAK_FUNC(sub_880F4C5C);
PPC_FUNC_IMPL(__imp__sub_880F4C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4C60"))) PPC_WEAK_FUNC(sub_880F4C60);
PPC_FUNC_IMPL(__imp__sub_880F4C60) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,43
	ctx.r6.s64 = 43;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-3404(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -3404);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4ca4
	if (ctx.cr6.eq) goto loc_880F4CA4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F4CA4:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f4cb8
	if (ctx.cr6.eq) goto loc_880F4CB8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F4CB8:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4CD0"))) PPC_WEAK_FUNC(sub_880F4CD0);
PPC_FUNC_IMPL(__imp__sub_880F4CD0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4d14
	if (!ctx.cr0.lt) goto loc_880F4D14;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4d04
	if (ctx.cr6.lt) goto loc_880F4D04;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4D04:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-3796
	ctx.r8.s64 = ctx.r9.s64 + -3796;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4D14:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-3688
	ctx.r9.s64 = ctx.r6.s64 + -3688;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-3760
	ctx.r10.s64 = ctx.r5.s64 + -3760;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4D64"))) PPC_WEAK_FUNC(sub_880F4D64);
PPC_FUNC_IMPL(__imp__sub_880F4D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4D68"))) PPC_WEAK_FUNC(sub_880F4D68);
PPC_FUNC_IMPL(__imp__sub_880F4D68) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,35
	ctx.r6.s64 = 35;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-3796(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -3796);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4dac
	if (ctx.cr6.eq) goto loc_880F4DAC;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F4DAC:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f4dc0
	if (ctx.cr6.eq) goto loc_880F4DC0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F4DC0:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4DD8"))) PPC_WEAK_FUNC(sub_880F4DD8);
PPC_FUNC_IMPL(__imp__sub_880F4DD8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4e1c
	if (!ctx.cr0.lt) goto loc_880F4E1C;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4e0c
	if (ctx.cr6.lt) goto loc_880F4E0C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4E0C:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-4064
	ctx.r8.s64 = ctx.r9.s64 + -4064;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4E1C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-4032
	ctx.r9.s64 = ctx.r6.s64 + -4032;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-5588
	ctx.r10.s64 = ctx.r5.s64 + -5588;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4E6C"))) PPC_WEAK_FUNC(sub_880F4E6C);
PPC_FUNC_IMPL(__imp__sub_880F4E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4E70"))) PPC_WEAK_FUNC(sub_880F4E70);
PPC_FUNC_IMPL(__imp__sub_880F4E70) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,29
	ctx.r6.s64 = 29;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-4064(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -4064);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4eb4
	if (ctx.cr6.eq) goto loc_880F4EB4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F4EB4:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f4ec8
	if (ctx.cr6.eq) goto loc_880F4EC8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F4EC8:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4EE0"))) PPC_WEAK_FUNC(sub_880F4EE0);
PPC_FUNC_IMPL(__imp__sub_880F4EE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f4f24
	if (!ctx.cr0.lt) goto loc_880F4F24;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f4f14
	if (ctx.cr6.lt) goto loc_880F4F14;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F4F14:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-1804
	ctx.r8.s64 = ctx.r9.s64 + -1804;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F4F24:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-1696
	ctx.r9.s64 = ctx.r6.s64 + -1696;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-1768
	ctx.r10.s64 = ctx.r5.s64 + -1768;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4F74"))) PPC_WEAK_FUNC(sub_880F4F74);
PPC_FUNC_IMPL(__imp__sub_880F4F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F4F78"))) PPC_WEAK_FUNC(sub_880F4F78);
PPC_FUNC_IMPL(__imp__sub_880F4F78) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,36
	ctx.r6.s64 = 36;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-1804(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1804);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f4fbc
	if (ctx.cr6.eq) goto loc_880F4FBC;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F4FBC:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f4fd0
	if (ctx.cr6.eq) goto loc_880F4FD0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F4FD0:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F4FE8"))) PPC_WEAK_FUNC(sub_880F4FE8);
PPC_FUNC_IMPL(__imp__sub_880F4FE8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f5030
	if (!ctx.cr0.lt) goto loc_880F5030;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f501c
	if (ctx.cr6.lt) goto loc_880F501C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F501C:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-2180
	ctx.r8.s64 = ctx.r9.s64 + -2180;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// extsb r6,r7
	ctx.r6.s64 = ctx.r7.s8;
	// stw r6,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r6.u32);
loc_880F5030:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-2072
	ctx.r9.s64 = ctx.r6.s64 + -2072;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-2144
	ctx.r10.s64 = ctx.r5.s64 + -2144;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5080"))) PPC_WEAK_FUNC(sub_880F5080);
PPC_FUNC_IMPL(__imp__sub_880F5080) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// li r6,33
	ctx.r6.s64 = 33;
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r9,-2180(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + -2180);
	// extsb r4,r9
	ctx.r4.s64 = ctx.r9.s8;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f50c8
	if (ctx.cr6.eq) goto loc_880F50C8;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F50C8:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f50dc
	if (ctx.cr6.eq) goto loc_880F50DC;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F50DC:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F50F4"))) PPC_WEAK_FUNC(sub_880F50F4);
PPC_FUNC_IMPL(__imp__sub_880F50F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F50F8"))) PPC_WEAK_FUNC(sub_880F50F8);
PPC_FUNC_IMPL(__imp__sub_880F50F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r10.u32);
	// bge 0x880f513c
	if (!ctx.cr0.lt) goto loc_880F513C;
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x880f512c
	if (ctx.cr6.lt) goto loc_880F512C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F512C:
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// addi r8,r9,-2484
	ctx.r8.s64 = ctx.r9.s64 + -2484;
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,124(r11)
	PPC_STORE_U32(ctx.r11.u32 + 124, ctx.r7.u32);
loc_880F513C:
	// lwz r7,116(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// lis r5,-30680
	ctx.r5.s64 = -2010644480;
	// addi r9,r6,-2400
	ctx.r9.s64 = ctx.r6.s64 + -2400;
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r5,-2456
	ctx.r10.s64 = ctx.r5.s64 + -2456;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r8,r9
	ctx.r3.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r3,152(r11)
	PPC_STORE_U32(ctx.r11.u32 + 152, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbzx r8,r4,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r10.u32);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// rlwinm r6,r7,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// stw r6,28(r11)
	PPC_STORE_U32(ctx.r11.u32 + 28, ctx.r6.u32);
	// lbzx r5,r4,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + ctx.r9.u32);
	// extsb r4,r5
	ctx.r4.s64 = ctx.r5.s8;
	// rlwinm r10,r4,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFFFF0000;
	// stw r10,32(r11)
	PPC_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F518C"))) PPC_WEAK_FUNC(sub_880F518C);
PPC_FUNC_IMPL(__imp__sub_880F518C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F5190"))) PPC_WEAK_FUNC(sub_880F5190);
PPC_FUNC_IMPL(__imp__sub_880F5190) {
	PPC_FUNC_PROLOGUE();
	// lis r9,-30680
	ctx.r9.s64 = -2010644480;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,27
	ctx.r6.s64 = 27;
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// rlwinm r5,r10,0,28,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// lbz r4,-2484(r9)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r9.u32 + -2484);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r6,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r6.u32);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// stw r7,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r7.u32);
	// stw r8,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r8.u32);
	// stw r4,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// beq cr6,0x880f51d4
	if (ctx.cr6.eq) goto loc_880F51D4;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
loc_880F51D4:
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x880f51e8
	if (ctx.cr6.eq) goto loc_880F51E8;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r9.u32);
loc_880F51E8:
	// rlwinm r10,r10,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stw r7,156(r11)
	PPC_STORE_U32(ctx.r11.u32 + 156, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5200"))) PPC_WEAK_FUNC(sub_880F5200);
PPC_FUNC_IMPL(__imp__sub_880F5200) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f5210
	if (!ctx.cr6.eq) goto loc_880F5210;
	// blr 
	return;
loc_880F5210:
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5220"))) PPC_WEAK_FUNC(sub_880F5220);
PPC_FUNC_IMPL(__imp__sub_880F5220) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f5230
	if (!ctx.cr6.eq) goto loc_880F5230;
	// blr 
	return;
loc_880F5230:
	// extsb r10,r5
	ctx.r10.s64 = ctx.r5.s8;
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// stw r10,168(r11)
	PPC_STORE_U32(ctx.r11.u32 + 168, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,164(r11)
	PPC_STORE_U32(ctx.r11.u32 + 164, ctx.r9.u32);
	// stw r10,172(r11)
	PPC_STORE_U32(ctx.r11.u32 + 172, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F524C"))) PPC_WEAK_FUNC(sub_880F524C);
PPC_FUNC_IMPL(__imp__sub_880F524C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F5250"))) PPC_WEAK_FUNC(sub_880F5250);
PPC_FUNC_IMPL(__imp__sub_880F5250) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f525c
	if (!ctx.cr6.eq) goto loc_880F525C;
	// blr 
	return;
loc_880F525C:
	// stw r4,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5268"))) PPC_WEAK_FUNC(sub_880F5268);
PPC_FUNC_IMPL(__imp__sub_880F5268) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f5274
	if (!ctx.cr6.eq) goto loc_880F5274;
	// blr 
	return;
loc_880F5274:
	// stw r4,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5280"))) PPC_WEAK_FUNC(sub_880F5280);
PPC_FUNC_IMPL(__imp__sub_880F5280) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f528c
	if (!ctx.cr6.eq) goto loc_880F528C;
	// blr 
	return;
loc_880F528C:
	// stw r4,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5298"))) PPC_WEAK_FUNC(sub_880F5298);
PPC_FUNC_IMPL(__imp__sub_880F5298) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f52a4
	if (!ctx.cr6.eq) goto loc_880F52A4;
	// blr 
	return;
loc_880F52A4:
	// stw r4,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F52B0"))) PPC_WEAK_FUNC(sub_880F52B0);
PPC_FUNC_IMPL(__imp__sub_880F52B0) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f52bc
	if (!ctx.cr6.eq) goto loc_880F52BC;
	// blr 
	return;
loc_880F52BC:
	// stw r4,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r4.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F52C8"))) PPC_WEAK_FUNC(sub_880F52C8);
PPC_FUNC_IMPL(__imp__sub_880F52C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880F52D0;
	__savegprlr_26(ctx, base);
	// lis r5,-30642
	ctx.r5.s64 = -2008154112;
	// lwz r6,12032(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12032);
	// cmplwi cr6,r6,128
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 128, ctx.xer);
	// blt cr6,0x880f52e8
	if (ctx.cr6.lt) goto loc_880F52E8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880F52E8:
	// lis r31,-30642
	ctx.r31.s64 = -2008154112;
	// lis r8,-30667
	ctx.r8.s64 = -2009792512;
	// addi r10,r31,12036
	ctx.r10.s64 = ctx.r31.s64 + 12036;
	// lis r30,-30667
	ctx.r30.s64 = -2009792512;
	// addi r29,r10,-516
	ctx.r29.s64 = ctx.r10.s64 + -516;
	// lwz r10,12036(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12036);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r28,r10,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lwz r10,12372(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12372);
	// lwz r8,12364(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12364);
	// li r30,-1
	ctx.r30.s64 = -1;
	// srawi r27,r9,7
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r27.s64 = ctx.r9.s32 >> 7;
	// li r26,255
	ctx.r26.s64 = 255;
	// lwzx r29,r28,r29
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r29.u32);
	// addze r28,r27
	temp.s64 = ctx.r27.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r27.u32;
	ctx.r28.s64 = temp.s64;
	// rlwinm r28,r28,7,0,24
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 7) & 0xFFFFFF80;
	// subf r9,r28,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r28.s64;
	// stw r10,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r10.u32);
	// addi r10,r6,1
	ctx.r10.s64 = ctx.r6.s64 + 1;
	// stw r3,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r7,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r7.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// stw r8,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r8.u32);
	// stw r4,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r4.u32);
	// stw r11,36(r29)
	PPC_STORE_U32(ctx.r29.u32 + 36, ctx.r11.u32);
	// stw r11,40(r29)
	PPC_STORE_U32(ctx.r29.u32 + 40, ctx.r11.u32);
	// stw r11,44(r29)
	PPC_STORE_U32(ctx.r29.u32 + 44, ctx.r11.u32);
	// stw r11,48(r29)
	PPC_STORE_U32(ctx.r29.u32 + 48, ctx.r11.u32);
	// stw r11,52(r29)
	PPC_STORE_U32(ctx.r29.u32 + 52, ctx.r11.u32);
	// stw r11,56(r29)
	PPC_STORE_U32(ctx.r29.u32 + 56, ctx.r11.u32);
	// stw r11,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r11.u32);
	// stw r11,60(r29)
	PPC_STORE_U32(ctx.r29.u32 + 60, ctx.r11.u32);
	// stw r11,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r11.u32);
	// stw r11,68(r29)
	PPC_STORE_U32(ctx.r29.u32 + 68, ctx.r11.u32);
	// stw r11,96(r29)
	PPC_STORE_U32(ctx.r29.u32 + 96, ctx.r11.u32);
	// stw r11,92(r29)
	PPC_STORE_U32(ctx.r29.u32 + 92, ctx.r11.u32);
	// stw r30,144(r29)
	PPC_STORE_U32(ctx.r29.u32 + 144, ctx.r30.u32);
	// stw r11,104(r29)
	PPC_STORE_U32(ctx.r29.u32 + 104, ctx.r11.u32);
	// stw r11,148(r29)
	PPC_STORE_U32(ctx.r29.u32 + 148, ctx.r11.u32);
	// stw r11,112(r29)
	PPC_STORE_U32(ctx.r29.u32 + 112, ctx.r11.u32);
	// stw r7,100(r29)
	PPC_STORE_U32(ctx.r29.u32 + 100, ctx.r7.u32);
	// stw r11,116(r29)
	PPC_STORE_U32(ctx.r29.u32 + 116, ctx.r11.u32);
	// stw r11,124(r29)
	PPC_STORE_U32(ctx.r29.u32 + 124, ctx.r11.u32);
	// stw r11,128(r29)
	PPC_STORE_U32(ctx.r29.u32 + 128, ctx.r11.u32);
	// stw r26,140(r29)
	PPC_STORE_U32(ctx.r29.u32 + 140, ctx.r26.u32);
	// stw r11,160(r29)
	PPC_STORE_U32(ctx.r29.u32 + 160, ctx.r11.u32);
	// stw r11,164(r29)
	PPC_STORE_U32(ctx.r29.u32 + 164, ctx.r11.u32);
	// stw r11,168(r29)
	PPC_STORE_U32(ctx.r29.u32 + 168, ctx.r11.u32);
	// stw r11,172(r29)
	PPC_STORE_U32(ctx.r29.u32 + 172, ctx.r11.u32);
	// stw r11,180(r29)
	PPC_STORE_U32(ctx.r29.u32 + 180, ctx.r11.u32);
	// stw r11,184(r29)
	PPC_STORE_U32(ctx.r29.u32 + 184, ctx.r11.u32);
	// stw r11,156(r29)
	PPC_STORE_U32(ctx.r29.u32 + 156, ctx.r11.u32);
	// stw r10,12032(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12032, ctx.r10.u32);
	// stw r9,12036(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12036, ctx.r9.u32);
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F53D0"))) PPC_WEAK_FUNC(sub_880F53D0);
PPC_FUNC_IMPL(__imp__sub_880F53D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// lis r10,-30642
	ctx.r10.s64 = -2008154112;
	// li r9,128
	ctx.r9.s64 = 128;
	// addi r11,r11,12036
	ctx.r11.s64 = ctx.r11.s64 + 12036;
	// addi r10,r10,-12544
	ctx.r10.s64 = ctx.r10.s64 + -12544;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r10,-188
	ctx.r7.s64 = ctx.r10.s64 + -188;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r3,-24584(r11)
	PPC_STORE_U32(ctx.r11.u32 + -24584, ctx.r3.u32);
loc_880F53F4:
	// stwu r8,188(r7)
	ea = 188 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x880f53f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880F53F4;
	// li r9,128
	ctx.r9.s64 = 128;
	// lis r6,-30642
	ctx.r6.s64 = -2008154112;
	// addi r7,r11,-516
	ctx.r7.s64 = ctx.r11.s64 + -516;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r8,12032(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12032, ctx.r8.u32);
loc_880F5414:
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
	// addi r10,r10,188
	ctx.r10.s64 = ctx.r10.s64 + 188;
	// bdnz 0x880f5414
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880F5414;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5434"))) PPC_WEAK_FUNC(sub_880F5434);
PPC_FUNC_IMPL(__imp__sub_880F5434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F5438"))) PPC_WEAK_FUNC(sub_880F5438);
PPC_FUNC_IMPL(__imp__sub_880F5438) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f544c
	if (!ctx.cr6.eq) goto loc_880F544C;
loc_880F5444:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_880F544C:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x880f5444
	if (ctx.cr6.eq) goto loc_880F5444;
	// lwz r10,128(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// lwz r10,84(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f54fc
	if (ctx.cr6.eq) goto loc_880F54FC;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x880f54fc
	if (ctx.cr6.eq) goto loc_880F54FC;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x880f5444
	if (!ctx.cr6.eq) goto loc_880F5444;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x880f54ac
	if (!ctx.cr6.eq) goto loc_880F54AC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x880f5444
	if (ctx.cr6.eq) goto loc_880F5444;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r10.u32);
	// cmpwi cr6,r8,40
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 40, ctx.xer);
	// stw r9,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r9.u32);
	// blt cr6,0x880f5564
	if (ctx.cr6.lt) goto loc_880F5564;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r10.u32);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// blr 
	return;
loc_880F54AC:
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r10,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r10.u32);
	// stw r9,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r9.u32);
	// beq cr6,0x880f54e4
	if (ctx.cr6.eq) goto loc_880F54E4;
	// cmpwi cr6,r8,40
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 40, ctx.xer);
	// blt cr6,0x880f5564
	if (ctx.cr6.lt) goto loc_880F5564;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r8.u32);
	// blr 
	return;
loc_880F54E4:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x880f54f0
	if (ctx.cr6.eq) goto loc_880F54F0;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
loc_880F54F0:
	// stw r6,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r6.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_880F54FC:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x880f5538
	if (!ctx.cr6.eq) goto loc_880F5538;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r10,-12780(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12780);
	// divwu r9,r7,r10
	ctx.r9.u32 = ppc_divwu(ctx.r7.u32, ctx.r10.u32);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x880f5444
	if (!ctx.cr6.eq) goto loc_880F5444;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r10.u32);
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// blr 
	return;
loc_880F5538:
	// lis r8,-30597
	ctx.r8.s64 = -2005204992;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r9,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r9.u32);
	// lwz r8,-12780(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12780);
	// divwu r7,r7,r8
	ctx.r7.u32 = ppc_divwu(ctx.r7.u32, ctx.r8.u32);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x880f5560
	if (ctx.cr6.eq) goto loc_880F5560;
	// stw r10,176(r11)
	PPC_STORE_U32(ctx.r11.u32 + 176, ctx.r10.u32);
loc_880F5560:
	// stw r10,180(r11)
	PPC_STORE_U32(ctx.r11.u32 + 180, ctx.r10.u32);
loc_880F5564:
	// stw r9,184(r11)
	PPC_STORE_U32(ctx.r11.u32 + 184, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F5570"))) PPC_WEAK_FUNC(sub_880F5570);
PPC_FUNC_IMPL(__imp__sub_880F5570) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x880f557c
	if (!ctx.cr6.eq) goto loc_880F557C;
	// blr 
	return;
loc_880F557C:
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// stw r4,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r4.u32);
	// addic. r11,r3,40
	ctx.xer.ca = ctx.r3.u32 > 4294967255;
	ctx.r11.s64 = ctx.r3.s64 + 40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r5,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r5.u32);
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// clrlwi r9,r5,23
	ctx.r9.u64 = ctx.r5.u32 & 0x1FF;
	// addi r10,r10,9552
	ctx.r10.s64 = ctx.r10.s64 + 9552;
	// beq 0x880f55b0
	if (ctx.cr0.eq) goto loc_880F55B0;
	// addi r7,r9,128
	ctx.r7.s64 = ctx.r9.s64 + 128;
	// rlwinm r6,r7,2,21,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x7FC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// mullw r3,r5,r4
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
loc_880F55B0:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x880f55c8
	if (ctx.cr6.eq) goto loc_880F55C8;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mullw r9,r10,r4
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
loc_880F55C8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F55D0"))) PPC_WEAK_FUNC(sub_880F55D0);
PPC_FUNC_IMPL(__imp__sub_880F55D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071120
	ctx.lr = 0x880F55D8;
	__savegprlr_14(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r17,-30642
	ctx.r17.s64 = -2008154112;
	// lis r11,-30597
	ctx.r11.s64 = -2005204992;
	// lwz r9,12032(r17)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r17.u32 + 12032);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r9,-11960(r11)
	PPC_STORE_U32(ctx.r11.u32 + -11960, ctx.r9.u32);
	// beq cr6,0x880f5ad8
	if (ctx.cr6.eq) goto loc_880F5AD8;
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r19,r11,12040
	ctx.r19.s64 = ctx.r11.s64 + 12040;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r11,-24588(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + -24588);
	// addi r10,r11,204
	ctx.r10.s64 = ctx.r11.s64 + 204;
	// addi r10,r11,264
	ctx.r10.s64 = ctx.r11.s64 + 264;
	// lwz r6,204(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 204);
	// lwz r5,208(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 208);
	// lwz r4,212(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 212);
	// lwz r3,216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 216);
	// stw r6,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r5,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r5.u32);
	// stw r4,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r4.u32);
	// stw r3,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r3.u32);
loc_880F5640:
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwzu r7,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// stwu r7,8(r8)
	ea = 8 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x880f5640
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_880F5640;
	// lwz r11,88(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 88);
	// lwz r14,104(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880f5668
	if (ctx.cr6.eq) goto loc_880F5668;
	// lwz r14,100(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_880F5668:
	// lis r11,-30642
	ctx.r11.s64 = -2008154112;
	// lis r8,16838
	ctx.r8.s64 = 1103495168;
	// addi r11,r11,-12544
	ctx.r11.s64 = ctx.r11.s64 + -12544;
	// lis r7,-3856
	ctx.r7.s64 = -252706816;
	// addi r31,r11,112
	ctx.r31.s64 = ctx.r11.s64 + 112;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lis r10,-30714
	ctx.r10.s64 = -2012872704;
	// li r16,0
	ctx.r16.s64 = 0;
	// ori r26,r8,20077
	ctx.r26.u64 = ctx.r8.u64 | 20077;
	// ori r27,r7,61681
	ctx.r27.u64 = ctx.r7.u64 | 61681;
	// lis r28,-30671
	ctx.r28.s64 = -2010054656;
	// lis r23,-30667
	ctx.r23.s64 = -2009792512;
	// lis r22,-30667
	ctx.r22.s64 = -2009792512;
	// lis r21,-30667
	ctx.r21.s64 = -2009792512;
	// addi r15,r11,4120
	ctx.r15.s64 = ctx.r11.s64 + 4120;
	// addi r18,r10,9552
	ctx.r18.s64 = ctx.r10.s64 + 9552;
loc_880F56A8:
	// lwz r11,-112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -112);
	// addi r20,r31,-112
	ctx.r20.s64 = ctx.r31.s64 + -112;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5ac8
	if (ctx.cr6.eq) goto loc_880F5AC8;
	// lwz r11,-108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x880f5858
	if (!ctx.cr6.eq) goto loc_880F5858;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bge 0x880f5810
	if (!ctx.cr0.lt) goto loc_880F5810;
	// lwz r11,-100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -100);
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// blt cr6,0x880f56e4
	if (ctx.cr6.lt) goto loc_880F56E4;
	// li r11,24
	ctx.r11.s64 = 24;
loc_880F56E4:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r11,r11,r15
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r15.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x880f57d4
	if (ctx.cr6.eq) goto loc_880F57D4;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x880F5700;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,68(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// mr r29,r16
	ctx.r29.u64 = ctx.r16.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r25,-96(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + -96);
	// lwz r24,-92(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + -92);
	// ble cr6,0x880f57c4
	if (!ctx.cr6.gt) goto loc_880F57C4;
	// lis r10,-30667
	ctx.r10.s64 = -2009792512;
	// lwz r30,4200(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4200);
	// li r11,140
	ctx.r11.s64 = 140;
	// stw r11,12376(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12376, ctx.r11.u32);
loc_880F5728:
	// mullw r11,r30,r26
	ctx.r11.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r26.s32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r5,72(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// stw r3,12380(r21)
	PPC_STORE_U32(ctx.r21.u32 + 12380, ctx.r3.u32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r4,140
	ctx.r4.s64 = 140;
	// stw r11,4200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4200, ctx.r11.u32);
	// mullw r10,r11,r26
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r26.s32);
	// lhz r7,4200(r28)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r28.u32 + 4200);
	// addi r30,r10,12345
	ctx.r30.s64 = ctx.r10.s64 + 12345;
	// stw r30,4200(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4200, ctx.r30.u32);
	// lhz r11,4200(r28)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r28.u32 + 4200);
	// mulhwu r10,r11,r27
	ctx.r10.u64 = (uint64_t(ctx.r11.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mulhwu r6,r7,r27
	ctx.r6.u64 = (uint64_t(ctx.r7.u32) * uint64_t(ctx.r27.u32)) >> 32;
	// rlwinm r11,r6,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r8,r11,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r11,r8,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r8.s64;
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r6,r6,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r6.s64;
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// extsh r11,r6
	ctx.r11.s64 = ctx.r6.s16;
	// addi r8,r10,-8
	ctx.r8.s64 = ctx.r10.s64 + -8;
	// addi r7,r11,-8
	ctx.r7.s64 = ctx.r11.s64 + -8;
	// rlwinm r11,r8,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r10,r7,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFFFF0000;
	// add r11,r11,r25
	ctx.r11.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// stw r11,12364(r22)
	PPC_STORE_U32(ctx.r22.u32 + 12364, ctx.r11.u32);
	// stw r10,12372(r23)
	PPC_STORE_U32(ctx.r23.u32 + 12372, ctx.r10.u32);
	// bl 0x881607f8
	ctx.lr = 0x880F57B4;
	sub_881607F8(ctx, base);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r6
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r6.s32, ctx.xer);
	// blt cr6,0x880f5728
	if (ctx.cr6.lt) goto loc_880F5728;
loc_880F57C4:
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r9,12032(r17)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r17.u32 + 12032);
	// stw r11,-108(r31)
	PPC_STORE_U32(ctx.r31.u32 + -108, ctx.r11.u32);
	// b 0x880f5858
	goto loc_880F5858;
loc_880F57D4:
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// addi r10,r19,-520
	ctx.r10.s64 = ctx.r19.s64 + -520;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r16,0(r20)
	PPC_STORE_U32(ctx.r20.u32 + 0, ctx.r16.u32);
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,12032(r17)
	PPC_STORE_U32(ctx.r17.u32 + 12032, ctx.r9.u32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r6,r11,7
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 7;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// stwx r20,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r20.u32);
	// subf r3,r4,r11
	ctx.r3.s64 = ctx.r11.s64 - ctx.r4.s64;
	// stw r3,0(r19)
	PPC_STORE_U32(ctx.r19.u32 + 0, ctx.r3.u32);
	// b 0x880f5858
	goto loc_880F5858;
loc_880F5810:
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x880f5848
	if (ctx.cr6.lt) goto loc_880F5848;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,-96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -96);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r7,-92(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -92);
	// addi r6,r1,116
	ctx.r6.s64 = ctx.r1.s64 + 116;
	// lwzx r5,r11,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// lwzx r4,r11,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r6.u32);
	// subf r3,r5,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r5.s64;
	// subf r11,r4,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r4.s64;
	// stw r3,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r3.u32);
	// stw r11,-92(r31)
	PPC_STORE_U32(ctx.r31.u32 + -92, ctx.r11.u32);
loc_880F5848:
	// lwz r11,-96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -96);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r8,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r8.u32);
loc_880F5858:
	// lwz r11,-108(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -108);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5abc
	if (ctx.cr6.eq) goto loc_880F5ABC;
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x880f58d8
	if (ctx.cr6.eq) goto loc_880F58D8;
	// lwz r11,-8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x880f58d8
	if (!ctx.cr6.gt) goto loc_880F58D8;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r10.u32);
	// bge 0x880f58d8
	if (!ctx.cr0.lt) goto loc_880F58D8;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// lwz r7,-4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// addic. r6,r31,-72
	ctx.xer.ca = ctx.r31.u32 > 71;
	ctx.r6.s64 = ctx.r31.s64 + -72;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r11,-8(r31)
	PPC_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
	// clrlwi r10,r7,23
	ctx.r10.u64 = ctx.r7.u32 & 0x1FF;
	// stw r8,56(r31)
	PPC_STORE_U32(ctx.r31.u32 + 56, ctx.r8.u32);
	// beq 0x880f58c0
	if (ctx.cr0.eq) goto loc_880F58C0;
	// addi r9,r10,128
	ctx.r9.s64 = ctx.r10.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r8,r18
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r18.u32);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// stw r6,-72(r31)
	PPC_STORE_U32(ctx.r31.u32 + -72, ctx.r6.u32);
loc_880F58C0:
	// addic. r9,r31,-76
	ctx.xer.ca = ctx.r31.u32 > 75;
	ctx.r9.s64 = ctx.r31.s64 + -76;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x880f58d8
	if (ctx.cr0.eq) goto loc_880F58D8;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r18.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r8,-76(r31)
	PPC_STORE_U32(ctx.r31.u32 + -76, ctx.r8.u32);
loc_880F58D8:
	// lwz r10,-20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f5944
	if (ctx.cr6.eq) goto loc_880F5944;
	// lwz r11,-36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -36);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,-36(r31)
	PPC_STORE_U32(ctx.r31.u32 + -36, ctx.r11.u32);
	// bge 0x880f5944
	if (!ctx.cr0.lt) goto loc_880F5944;
	// lwz r11,-52(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -52);
	// addic. r9,r31,-64
	ctx.xer.ca = ctx.r31.u32 > 63;
	ctx.r9.s64 = ctx.r31.s64 + -64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r8,-32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// lwz r7,-44(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -44);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,-52(r31)
	PPC_STORE_U32(ctx.r31.u32 + -52, ctx.r11.u32);
	// clrlwi r10,r7,23
	ctx.r10.u64 = ctx.r7.u32 & 0x1FF;
	// stw r8,-36(r31)
	PPC_STORE_U32(ctx.r31.u32 + -36, ctx.r8.u32);
	// beq 0x880f592c
	if (ctx.cr0.eq) goto loc_880F592C;
	// addi r9,r10,128
	ctx.r9.s64 = ctx.r10.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r8,r18
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r18.u32);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// stw r6,-64(r31)
	PPC_STORE_U32(ctx.r31.u32 + -64, ctx.r6.u32);
loc_880F592C:
	// addic. r9,r31,-68
	ctx.xer.ca = ctx.r31.u32 > 67;
	ctx.r9.s64 = ctx.r31.s64 + -68;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x880f5944
	if (ctx.cr0.eq) goto loc_880F5944;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r18.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r8,-68(r31)
	PPC_STORE_U32(ctx.r31.u32 + -68, ctx.r8.u32);
loc_880F5944:
	// lwz r10,-16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f59b0
	if (ctx.cr6.eq) goto loc_880F59B0;
	// lwz r11,-28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -28);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,-28(r31)
	PPC_STORE_U32(ctx.r31.u32 + -28, ctx.r11.u32);
	// bge 0x880f59b0
	if (!ctx.cr0.lt) goto loc_880F59B0;
	// lwz r11,-48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -48);
	// addic. r9,r31,-56
	ctx.xer.ca = ctx.r31.u32 > 55;
	ctx.r9.s64 = ctx.r31.s64 + -56;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r8,-24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -24);
	// lwz r7,-40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -40);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,-48(r31)
	PPC_STORE_U32(ctx.r31.u32 + -48, ctx.r11.u32);
	// clrlwi r10,r7,23
	ctx.r10.u64 = ctx.r7.u32 & 0x1FF;
	// stw r8,-28(r31)
	PPC_STORE_U32(ctx.r31.u32 + -28, ctx.r8.u32);
	// beq 0x880f5998
	if (ctx.cr0.eq) goto loc_880F5998;
	// addi r9,r10,128
	ctx.r9.s64 = ctx.r10.s64 + 128;
	// rlwinm r8,r9,2,21,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x7FC;
	// lwzx r7,r8,r18
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r18.u32);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// stw r6,-56(r31)
	PPC_STORE_U32(ctx.r31.u32 + -56, ctx.r6.u32);
loc_880F5998:
	// addic. r9,r31,-60
	ctx.xer.ca = ctx.r31.u32 > 59;
	ctx.r9.s64 = ctx.r31.s64 + -60;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x880f59b0
	if (ctx.cr0.eq) goto loc_880F59B0;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r18.u32);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r8,-60(r31)
	PPC_STORE_U32(ctx.r31.u32 + -60, ctx.r8.u32);
loc_880F59B0:
	// lwz r8,-68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -68);
	// lwz r9,-76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -76);
	// lwz r10,-64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// lwz r11,-72(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -72);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r8,-60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -60);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r7,-96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -96);
	// lwz r10,-56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -56);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r8,-92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -92);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r9,r9,r14
	ctx.r9.u64 = ctx.r9.u64 + ctx.r14.u64;
	// stw r10,-92(r31)
	PPC_STORE_U32(ctx.r31.u32 + -92, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r9.u32);
	// blt cr6,0x880f5a24
	if (ctx.cr6.lt) goto loc_880F5A24;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// lwzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// lwzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// subf r4,r6,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r6.s64;
	// subf r3,r5,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r5.s64;
	// stw r4,-96(r31)
	PPC_STORE_U32(ctx.r31.u32 + -96, ctx.r4.u32);
	// stw r3,-92(r31)
	PPC_STORE_U32(ctx.r31.u32 + -92, ctx.r3.u32);
loc_880F5A24:
	// lwz r11,-100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -100);
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// blt cr6,0x880f5a34
	if (ctx.cr6.lt) goto loc_880F5A34;
	// li r11,24
	ctx.r11.s64 = 24;
loc_880F5A34:
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r15,4
	ctx.r10.s64 = ctx.r15.s64 + 4;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x880F5A4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x880f5a90
	if (!ctx.cr6.eq) goto loc_880F5A90;
	// lwz r11,0(r19)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r19.u32 + 0);
	// addi r8,r19,-520
	ctx.r8.s64 = ctx.r19.s64 + -520;
	// lwz r9,12032(r17)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r17.u32 + 12032);
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// stw r16,0(r20)
	PPC_STORE_U32(ctx.r20.u32 + 0, ctx.r16.u32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r6,r10,7
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 7;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// stw r9,12032(r17)
	PPC_STORE_U32(ctx.r17.u32 + 12032, ctx.r9.u32);
	// rlwinm r4,r5,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// stwx r20,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r20.u32);
	// subf r3,r4,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r4.s64;
	// stw r3,0(r19)
	PPC_STORE_U32(ctx.r19.u32 + 0, ctx.r3.u32);
	// b 0x880f5abc
	goto loc_880F5ABC;
loc_880F5A90:
	// lwz r11,0(r20)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r20.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5ab8
	if (ctx.cr6.eq) goto loc_880F5AB8;
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// addi r10,r15,200
	ctx.r10.s64 = ctx.r15.s64 + 200;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x880F5AB8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_880F5AB8:
	// lwz r9,12032(r17)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r17.u32 + 12032);
loc_880F5ABC:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_880F5AC8:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r31,188
	ctx.r31.s64 = ctx.r31.s64 + 188;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x880f56a8
	if (!ctx.cr6.eq) goto loc_880F56A8;
loc_880F5AD8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x88071170
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F5AE0"))) PPC_WEAK_FUNC(sub_880F5AE0);
PPC_FUNC_IMPL(__imp__sub_880F5AE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880F5AE8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x880f5b08
	if (!ctx.cr6.eq) goto loc_880F5B08;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880F5B08:
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x880f5b14
	if (!ctx.cr6.eq) goto loc_880F5B14;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F5B14:
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bne cr6,0x880f5b24
	if (!ctx.cr6.eq) goto loc_880F5B24;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F5B24:
	// lwz r8,152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lhz r9,2(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// lhz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880f5be8
	if (!ctx.cr6.eq) goto loc_880F5BE8;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F5B50;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5b6c
	if (ctx.cr6.eq) goto loc_880F5B6C;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F5B6C:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f5ba0
	if (ctx.cr6.eq) goto loc_880F5BA0;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,545
	ctx.r8.s64 = 35717120;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F5BA0:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5bc0
	if (ctx.cr6.eq) goto loc_880F5BC0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5cf0
	if (ctx.cr6.eq) goto loc_880F5CF0;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880F5BC0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5cf0
	if (ctx.cr6.eq) goto loc_880F5CF0;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880F5BE8:
	// lwz r6,152(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r27,r7,r10
	ctx.r27.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r30,4(r6)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// ble cr6,0x880f5cf0
	if (!ctx.cr6.gt) goto loc_880F5CF0;
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// lwz r26,-11932(r24)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
loc_880F5C14:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lhz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// beq cr6,0x880f5c48
	if (ctx.cr6.eq) goto loc_880F5C48;
	// rotlwi r9,r11,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r11,r10,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// subf r4,r9,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r9.s64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// b 0x880f5c58
	goto loc_880F5C58;
loc_880F5C48:
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
loc_880F5C58:
	// bl 0x881538c0
	ctx.lr = 0x880F5C5C;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5c78
	if (ctx.cr6.eq) goto loc_880F5C78;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F5C78:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f5ca0
	if (ctx.cr6.eq) goto loc_880F5CA0;
	// lis r10,545
	ctx.r10.s64 = 35717120;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F5CA0:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5cbc
	if (ctx.cr6.eq) goto loc_880F5CBC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5cdc
	if (ctx.cr6.eq) goto loc_880F5CDC;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// b 0x880f5cdc
	goto loc_880F5CDC;
loc_880F5CBC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5cdc
	if (ctx.cr6.eq) goto loc_880F5CDC;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
loc_880F5CDC:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x880f5c14
	if (!ctx.cr0.eq) goto loc_880F5C14;
	// stw r26,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r26.u32);
loc_880F5CF0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F5CF8"))) PPC_WEAK_FUNC(sub_880F5CF8);
PPC_FUNC_IMPL(__imp__sub_880F5CF8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071148
	ctx.lr = 0x880F5D00;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x880f5d20
	if (!ctx.cr6.eq) goto loc_880F5D20;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880F5D20:
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x880f5d2c
	if (!ctx.cr6.eq) goto loc_880F5D2C;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F5D2C:
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bne cr6,0x880f5d3c
	if (!ctx.cr6.eq) goto loc_880F5D3C;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F5D3C:
	// lwz r8,152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lhz r9,2(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// lhz r3,0(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x880f5e00
	if (!ctx.cr6.eq) goto loc_880F5E00;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F5D68;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5d84
	if (ctx.cr6.eq) goto loc_880F5D84;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F5D84:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f5db8
	if (ctx.cr6.eq) goto loc_880F5DB8;
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,531
	ctx.r8.s64 = 34799616;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F5DB8:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5dd8
	if (ctx.cr6.eq) goto loc_880F5DD8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5f08
	if (ctx.cr6.eq) goto loc_880F5F08;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880F5DD8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5f08
	if (ctx.cr6.eq) goto loc_880F5F08;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
loc_880F5E00:
	// lwz r6,152(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r8,r11
	ctx.r28.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r27,r7,r10
	ctx.r27.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r30,4(r6)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// ble cr6,0x880f5f08
	if (!ctx.cr6.gt) goto loc_880F5F08;
	// lis r24,-30597
	ctx.r24.s64 = -2005204992;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// lwz r26,-11932(r24)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r24.u32 + -11932);
loc_880F5E2C:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lhz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// beq cr6,0x880f5e60
	if (ctx.cr6.eq) goto loc_880F5E60;
	// rotlwi r9,r11,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r11,r10,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// subf r4,r9,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r9.s64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// b 0x880f5e70
	goto loc_880F5E70;
loc_880F5E60:
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
loc_880F5E70:
	// bl 0x881538c0
	ctx.lr = 0x880F5E74;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5e90
	if (ctx.cr6.eq) goto loc_880F5E90;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F5E90:
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// beq cr6,0x880f5eb8
	if (ctx.cr6.eq) goto loc_880F5EB8;
	// lis r10,531
	ctx.r10.s64 = 34799616;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// rlwimi r10,r11,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r11.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F5EB8:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f5ed4
	if (ctx.cr6.eq) goto loc_880F5ED4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5ef4
	if (ctx.cr6.eq) goto loc_880F5EF4;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// b 0x880f5ef4
	goto loc_880F5EF4;
loc_880F5ED4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5ef4
	if (ctx.cr6.eq) goto loc_880F5EF4;
	// lwz r11,140(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 140);
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | ctx.r11.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
loc_880F5EF4:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x880f5e2c
	if (!ctx.cr0.eq) goto loc_880F5E2C;
	// stw r26,-11932(r24)
	PPC_STORE_U32(ctx.r24.u32 + -11932, ctx.r26.u32);
loc_880F5F08:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071198
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F5F10"))) PPC_WEAK_FUNC(sub_880F5F10);
PPC_FUNC_IMPL(__imp__sub_880F5F10) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071144
	ctx.lr = 0x880F5F18;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x880f5f38
	if (!ctx.cr6.eq) goto loc_880F5F38;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880F5F38:
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x880f5f44
	if (!ctx.cr6.eq) goto loc_880F5F44;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F5F44:
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bne cr6,0x880f5f54
	if (!ctx.cr6.eq) goto loc_880F5F54;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F5F54:
	// lwz r9,152(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lhz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,2(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x880f60b4
	if (!ctx.cr6.gt) goto loc_880F60B4;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880f5fe0
	if (!ctx.cr6.eq) goto loc_880F5FE0;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F5F88;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f5fc0
	if (ctx.cr6.eq) goto loc_880F5FC0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30597
	ctx.r10.s64 = -2005204992;
	// oris r9,r11,531
	ctx.r9.u64 = ctx.r11.u64 | 34799616;
	// ori r9,r9,40960
	ctx.r9.u64 = ctx.r9.u64 | 40960;
	// lwz r11,-11932(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -11932);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,148(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// rlwinm r7,r8,26,0,5
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0xFC000000;
	// or r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 | ctx.r9.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r11,-11932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -11932, ctx.r11.u32);
loc_880F5FC0:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f60b4
	if (ctx.cr6.eq) goto loc_880F60B4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f60b4
	if (ctx.cr6.eq) goto loc_880F60B4;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
loc_880F5FE0:
	// lwz r6,152(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r9,r11
	ctx.r28.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r30,4(r6)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// ble cr6,0x880f60b4
	if (!ctx.cr6.gt) goto loc_880F60B4;
	// lis r23,-30597
	ctx.r23.s64 = -2005204992;
	// lis r11,531
	ctx.r11.s64 = 34799616;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// ori r24,r11,40960
	ctx.r24.u64 = ctx.r11.u64 | 40960;
	// lwz r26,-11932(r23)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r23.u32 + -11932);
loc_880F6018:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lhz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// beq cr6,0x880f604c
	if (ctx.cr6.eq) goto loc_880F604C;
	// rotlwi r9,r11,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r11,r10,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// subf r4,r9,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r9.s64;
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// b 0x880f605c
	goto loc_880F605C;
loc_880F604C:
	// rotlwi r11,r11,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r10,r10,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r5,r10,r27
	ctx.r5.u64 = ctx.r10.u64 + ctx.r27.u64;
loc_880F605C:
	// bl 0x881538c0
	ctx.lr = 0x880F6060;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6088
	if (ctx.cr6.eq) goto loc_880F6088;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// or r10,r11,r24
	ctx.r10.u64 = ctx.r11.u64 | ctx.r24.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lwz r9,148(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// rlwinm r8,r9,26,0,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// or r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 | ctx.r10.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_880F6088:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f60a0
	if (ctx.cr6.eq) goto loc_880F60A0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f60a0
	if (ctx.cr6.eq) goto loc_880F60A0;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880F60A0:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x880f6018
	if (!ctx.cr0.eq) goto loc_880F6018;
	// stw r26,-11932(r23)
	PPC_STORE_U32(ctx.r23.u32 + -11932, ctx.r26.u32);
loc_880F60B4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x88071194
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F60BC"))) PPC_WEAK_FUNC(sub_880F60BC);
PPC_FUNC_IMPL(__imp__sub_880F60BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F60C0"))) PPC_WEAK_FUNC(sub_880F60C0);
PPC_FUNC_IMPL(__imp__sub_880F60C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88071150
	ctx.lr = 0x880F60C8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,28(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x880f60e8
	if (!ctx.cr6.eq) goto loc_880F60E8;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
loc_880F60E8:
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// bne cr6,0x880f60f4
	if (!ctx.cr6.eq) goto loc_880F60F4;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F60F4:
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// bne cr6,0x880f6104
	if (!ctx.cr6.eq) goto loc_880F6104;
	// neg r11,r11
	ctx.r11.s64 = -ctx.r11.s64;
	// neg r10,r10
	ctx.r10.s64 = -ctx.r10.s64;
loc_880F6104:
	// lwz r9,152(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// lhz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lhz r7,2(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x880f6228
	if (!ctx.cr6.gt) goto loc_880F6228;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880f6174
	if (!ctx.cr6.eq) goto loc_880F6174;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// add r4,r8,r11
	ctx.r4.u64 = ctx.r8.u64 + ctx.r11.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F6138;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6154
	if (ctx.cr6.eq) goto loc_880F6154;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F6154:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f6228
	if (ctx.cr6.eq) goto loc_880F6228;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6228
	if (ctx.cr6.eq) goto loc_880F6228;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
loc_880F6174:
	// lwz r6,152(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 152);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r28,r9,r11
	ctx.r28.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r30,4(r6)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// ble cr6,0x880f6228
	if (!ctx.cr6.gt) goto loc_880F6228;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
loc_880F619C:
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lhz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r30.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x880f61cc
	if (ctx.cr6.eq) goto loc_880F61CC;
	// lhz r10,2(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// rotlwi r9,r11,16
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r11,r10,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 16);
	// subf r4,r9,r28
	ctx.r4.s64 = ctx.r28.s64 - ctx.r9.s64;
	// b 0x880f61dc
	goto loc_880F61DC;
loc_880F61CC:
	// lhz r9,2(r30)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r30.u32 + 2);
	// rotlwi r10,r11,16
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 16);
	// rotlwi r11,r9,16
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 16);
	// add r4,r10,r28
	ctx.r4.u64 = ctx.r10.u64 + ctx.r28.u64;
loc_880F61DC:
	// add r5,r11,r27
	ctx.r5.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x881538c0
	ctx.lr = 0x880F61E4;
	sub_881538C0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6200
	if (ctx.cr6.eq) goto loc_880F6200;
	// lwz r11,148(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 148);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0xFC000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
loc_880F6200:
	// lwz r11,160(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 160);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f6218
	if (ctx.cr6.eq) goto loc_880F6218;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6218
	if (ctx.cr6.eq) goto loc_880F6218;
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r11.u32);
loc_880F6218:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x880f619c
	if (!ctx.cr0.eq) goto loc_880F619C;
loc_880F6228:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x880711a0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_880F6230"))) PPC_WEAK_FUNC(sub_880F6230);
PPC_FUNC_IMPL(__imp__sub_880F6230) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,5064
	ctx.r11.s64 = ctx.r11.s64 + 5064;
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6248"))) PPC_WEAK_FUNC(sub_880F6248);
PPC_FUNC_IMPL(__imp__sub_880F6248) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,5064
	ctx.r9.s64 = ctx.r11.s64 + 5064;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F625C"))) PPC_WEAK_FUNC(sub_880F625C);
PPC_FUNC_IMPL(__imp__sub_880F625C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F6260"))) PPC_WEAK_FUNC(sub_880F6260);
PPC_FUNC_IMPL(__imp__sub_880F6260) {
	PPC_FUNC_PROLOGUE();
	// lis r4,-30671
	ctx.r4.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// ori r7,r10,20077
	ctx.r7.u64 = ctx.r10.u64 | 20077;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4200);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// addic. r10,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r10.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// stb r5,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r5.u8);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// addi r6,r11,20
	ctx.r6.s64 = ctx.r11.s64 + 20;
	// stw r9,4200(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4200, ctx.r9.u32);
	// clrlwi r7,r3,23
	ctx.r7.u64 = ctx.r3.u32 & 0x1FF;
	// lhz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4200);
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// beq 0x880f62c4
	if (ctx.cr0.eq) goto loc_880F62C4;
	// addi r4,r7,128
	ctx.r4.s64 = ctx.r7.s64 + 128;
	// rlwinm r3,r4,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r3,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// mullw r3,r4,r9
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
loc_880F62C4:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x880f62dc
	if (ctx.cr6.eq) goto loc_880F62DC;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
loc_880F62DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r5,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F62E8"))) PPC_WEAK_FUNC(sub_880F62E8);
PPC_FUNC_IMPL(__imp__sub_880F62E8) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// lis r31,-30671
	ctx.r31.s64 = -2010054656;
	// ori r10,r10,20077
	ctx.r10.u64 = ctx.r10.u64 | 20077;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// lwz r10,4200(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4200);
	// li r8,3
	ctx.r8.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// stb r8,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r8.u8);
	// stb r8,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r8.u8);
	// stb r4,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r4.u8);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// lis r7,-30714
	ctx.r7.s64 = -2012872704;
	// mullw r8,r10,r5
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// stw r10,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r10.u32);
	// lhz r10,4200(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// clrlwi r6,r10,27
	ctx.r6.u64 = ctx.r10.u32 & 0x1F;
	// stw r8,4200(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4200, ctx.r8.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lhz r10,4200(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4200);
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// addic. r9,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r9.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// sth r6,30(r11)
	PPC_STORE_U16(ctx.r11.u32 + 30, ctx.r6.u16);
	// addi r5,r11,20
	ctx.r5.s64 = ctx.r11.s64 + 20;
	// clrlwi r8,r3,23
	ctx.r8.u64 = ctx.r3.u32 & 0x1FF;
	// addi r7,r7,9552
	ctx.r7.s64 = ctx.r7.s64 + 9552;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// beq 0x880f6380
	if (ctx.cr0.eq) goto loc_880F6380;
	// addi r6,r8,128
	ctx.r6.s64 = ctx.r8.s64 + 128;
	// rlwinm r3,r6,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x7FC;
	// lwzx r6,r3,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// mullw r3,r6,r10
	ctx.r3.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
loc_880F6380:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x880f6398
	if (ctx.cr6.eq) goto loc_880F6398;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// mullw r7,r8,r10
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// stw r7,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
loc_880F6398:
	// sth r4,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r4.u16);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r4.u8);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F63AC"))) PPC_WEAK_FUNC(sub_880F63AC);
PPC_FUNC_IMPL(__imp__sub_880F63AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F63B0"))) PPC_WEAK_FUNC(sub_880F63B0);
PPC_FUNC_IMPL(__imp__sub_880F63B0) {
	PPC_FUNC_PROLOGUE();
	// lis r4,-30671
	ctx.r4.s64 = -2010054656;
	// lis r10,16838
	ctx.r10.s64 = 1103495168;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lhz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// ori r7,r10,20077
	ctx.r7.u64 = ctx.r10.u64 | 20077;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4200);
	// lis r8,-30714
	ctx.r8.s64 = -2012872704;
	// addic. r10,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r10.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// stb r5,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r5.u8);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// addi r6,r11,20
	ctx.r6.s64 = ctx.r11.s64 + 20;
	// stw r9,4200(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4200, ctx.r9.u32);
	// clrlwi r7,r3,23
	ctx.r7.u64 = ctx.r3.u32 & 0x1FF;
	// lhz r9,4200(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4200);
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// addi r8,r8,9552
	ctx.r8.s64 = ctx.r8.s64 + 9552;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// beq 0x880f6414
	if (ctx.cr0.eq) goto loc_880F6414;
	// addi r4,r7,128
	ctx.r4.s64 = ctx.r7.s64 + 128;
	// rlwinm r3,r4,2,21,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r3,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// mullw r3,r4,r9
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r9.s32);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
loc_880F6414:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x880f642c
	if (ctx.cr6.eq) goto loc_880F642C;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r10,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
loc_880F642C:
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r5,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r5.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6438"))) PPC_WEAK_FUNC(sub_880F6438);
PPC_FUNC_IMPL(__imp__sub_880F6438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// rlwinm r7,r10,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// stb r8,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r8.u8);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// stb r8,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r8.u8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// bne cr6,0x880f652c
	if (!ctx.cr6.eq) goto loc_880F652C;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lhz r6,38(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r5,r5,27
	ctx.r5.u64 = ctx.r5.u32 & 0x1F;
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r4.u16);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bne cr6,0x880f64a8
	if (!ctx.cr6.eq) goto loc_880F64A8;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f64cc
	goto loc_880F64CC;
loc_880F64A8:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F64CC:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// addic. r7,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r7.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r4,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// extsh r6,r5
	ctx.r6.s64 = ctx.r5.s16;
	// addze r5,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r5.s64 = temp.s64;
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// subf r5,r5,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// addi r5,r4,9552
	ctx.r5.s64 = ctx.r4.s64 + 9552;
	// clrlwi r6,r6,23
	ctx.r6.u64 = ctx.r6.u32 & 0x1FF;
	// beq 0x880f6514
	if (ctx.cr0.eq) goto loc_880F6514;
	// addi r4,r6,128
	ctx.r4.s64 = ctx.r6.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6514:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f652c
	if (ctx.cr6.eq) goto loc_880F652C;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F652C:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// lis r3,-21846
	ctx.r3.s64 = -1431699456;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// addi r5,r7,12345
	ctx.r5.s64 = ctx.r7.s64 + 12345;
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// rlwinm r4,r8,2,26,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3C;
	// stw r5,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r5.u32);
	// ori r8,r3,43691
	ctx.r8.u64 = ctx.r3.u64 | 43691;
	// lhz r31,4200(r10)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// addi r7,r6,4504
	ctx.r7.s64 = ctx.r6.s64 + 4504;
	// mulhwu r6,r31,r8
	ctx.r6.u64 = (uint64_t(ctx.r31.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// addi r8,r7,400
	ctx.r8.s64 = ctx.r7.s64 + 400;
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 + ctx.r8.u64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r7,-96
	ctx.r3.s64 = ctx.r7.s64 + -96;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lhz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// subf r6,r6,r31
	ctx.r6.s64 = ctx.r31.s64 - ctx.r6.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// stb r4,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r4.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r4.u8);
	// lbz r8,3(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r8,41(r11)
	PPC_STORE_U8(ctx.r11.u32 + 41, ctx.r8.u8);
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// bne cr6,0x880f65b4
	if (!ctx.cr6.eq) goto loc_880F65B4;
	// addi r8,r7,-48
	ctx.r8.s64 = ctx.r7.s64 + -48;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// b 0x880f65c0
	goto loc_880F65C0;
loc_880F65B4:
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x880f65c0
	if (!ctx.cr6.eq) goto loc_880F65C0;
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
loc_880F65C0:
	// mullw r9,r5,r9
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f65e4
	if (ctx.cr6.eq) goto loc_880F65E4;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,36(r11)
	PPC_STORE_U16(ctx.r11.u32 + 36, ctx.r10.u16);
loc_880F65E4:
	// li r10,192
	ctx.r10.s64 = 192;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r10.u16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F65F8"))) PPC_WEAK_FUNC(sub_880F65F8);
PPC_FUNC_IMPL(__imp__sub_880F65F8) {
	PPC_FUNC_PROLOGUE();
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// lis r6,-3856
	ctx.r6.s64 = -252706816;
	// ori r5,r7,20077
	ctx.r5.u64 = ctx.r7.u64 | 20077;
	// ori r4,r6,61681
	ctx.r4.u64 = ctx.r6.u64 | 61681;
	// lwz r11,4200(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// stb r10,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
	// stb r10,5(r9)
	PPC_STORE_U8(ctx.r9.u32 + 5, ctx.r10.u8);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r11.u32);
	// lhz r8,4200(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// mulhwu r7,r8,r4
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// stb r3,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// subfic r4,r5,47
	ctx.xer.ca = ctx.r5.u32 <= 47;
	ctx.r4.s64 = 47 - ctx.r5.s64;
	// sth r4,34(r9)
	PPC_STORE_U16(ctx.r9.u32 + 34, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F665C"))) PPC_WEAK_FUNC(sub_880F665C);
PPC_FUNC_IMPL(__imp__sub_880F665C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F6660"))) PPC_WEAK_FUNC(sub_880F6660);
PPC_FUNC_IMPL(__imp__sub_880F6660) {
	PPC_FUNC_PROLOGUE();
	// lis r8,-30671
	ctx.r8.s64 = -2010054656;
	// lis r7,16838
	ctx.r7.s64 = 1103495168;
	// lis r6,-3856
	ctx.r6.s64 = -252706816;
	// ori r5,r7,20077
	ctx.r5.u64 = ctx.r7.u64 | 20077;
	// ori r4,r6,61681
	ctx.r4.u64 = ctx.r6.u64 | 61681;
	// lwz r11,4200(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4200);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r10,2
	ctx.r10.s64 = 2;
	// mullw r11,r11,r5
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r5.s32);
	// stb r10,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, ctx.r10.u8);
	// stb r10,5(r9)
	PPC_STORE_U8(ctx.r9.u32 + 5, ctx.r10.u8);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,4200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4200, ctx.r11.u32);
	// lhz r8,4200(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4200);
	// mulhwu r7,r8,r4
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(ctx.r4.u32)) >> 32;
	// rlwinm r11,r7,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0xFFFFFFF;
	// stb r3,3(r9)
	PPC_STORE_U8(ctx.r9.u32 + 3, ctx.r3.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// subfic r4,r5,79
	ctx.xer.ca = ctx.r5.u32 <= 79;
	ctx.r4.s64 = 79 - ctx.r5.s64;
	// sth r4,34(r9)
	PPC_STORE_U16(ctx.r9.u32 + 34, ctx.r4.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F66C4"))) PPC_WEAK_FUNC(sub_880F66C4);
PPC_FUNC_IMPL(__imp__sub_880F66C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F66C8"))) PPC_WEAK_FUNC(sub_880F66C8);
PPC_FUNC_IMPL(__imp__sub_880F66C8) {
	PPC_FUNC_PROLOGUE();
	// li r9,127
	ctx.r9.s64 = 127;
	// lhz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// addic. r11,r3,24
	ctx.xer.ca = ctx.r3.u32 > 4294967271;
	ctx.r11.s64 = ctx.r3.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// sth r9,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, ctx.r9.u16);
	// addi r9,r3,20
	ctx.r9.s64 = ctx.r3.s64 + 20;
	// beq 0x880f66e8
	if (ctx.cr0.eq) goto loc_880F66E8;
	// rlwinm r10,r10,12,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_880F66E8:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6700"))) PPC_WEAK_FUNC(sub_880F6700);
PPC_FUNC_IMPL(__imp__sub_880F6700) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// li r7,20
	ctx.r7.s64 = 20;
	// ori r8,r5,20077
	ctx.r8.u64 = ctx.r5.u64 | 20077;
	// lis r4,-3856
	ctx.r4.s64 = -252706816;
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// lwz r9,4200(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r3,r6,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// stb r7,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r7.u8);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// ori r6,r4,61681
	ctx.r6.u64 = ctx.r4.u64 | 61681;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// mulhwu r4,r5,r6
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r7,r4,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// subf r7,r3,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r3.s64;
	// subfic r6,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r6.s64 = 255 - ctx.r7.s64;
	// sth r6,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r6.u16);
	// bne cr6,0x880f681c
	if (!ctx.cr6.eq) goto loc_880F681C;
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lhz r6,38(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 38);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r5,r5,26
	ctx.r5.u64 = ctx.r5.u32 & 0x3F;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r31,r5,4
	ctx.r31.s64 = ctx.r5.s64 + 4;
	// bne cr6,0x880f6798
	if (!ctx.cr6.eq) goto loc_880F6798;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f67bc
	goto loc_880F67BC;
loc_880F6798:
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F67BC:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// addic. r7,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r7.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r6,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 1;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// subf r5,r5,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// add r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 + ctx.r4.u64;
	// addi r6,r6,9552
	ctx.r6.s64 = ctx.r6.s64 + 9552;
	// clrlwi r5,r4,23
	ctx.r5.u64 = ctx.r4.u32 & 0x1FF;
	// beq 0x880f6804
	if (ctx.cr0.eq) goto loc_880F6804;
	// addi r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6804:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f681c
	if (ctx.cr6.eq) goto loc_880F681C;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F681C:
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// ori r7,r8,43691
	ctx.r7.u64 = ctx.r8.u64 | 43691;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// mulhwu r5,r6,r7
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r10,r5,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r4,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r4.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// stb r8,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r8.u8);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6860"))) PPC_WEAK_FUNC(sub_880F6860);
PPC_FUNC_IMPL(__imp__sub_880F6860) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// li r7,20
	ctx.r7.s64 = 20;
	// ori r8,r5,20077
	ctx.r8.u64 = ctx.r5.u64 | 20077;
	// lis r4,-3856
	ctx.r4.s64 = -252706816;
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// lwz r9,4200(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// rlwinm r3,r6,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// stb r7,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r7.u8);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// ori r6,r4,61681
	ctx.r6.u64 = ctx.r4.u64 | 61681;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// mulhwu r4,r5,r6
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r7,r4,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// subf r7,r3,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r3.s64;
	// subfic r6,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r6.s64 = 255 - ctx.r7.s64;
	// sth r6,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r6.u16);
	// bne cr6,0x880f697c
	if (!ctx.cr6.eq) goto loc_880F697C;
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lhz r6,38(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 38);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r5,r5,26
	ctx.r5.u64 = ctx.r5.u32 & 0x3F;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r31,r5,4
	ctx.r31.s64 = ctx.r5.s64 + 4;
	// bne cr6,0x880f68f8
	if (!ctx.cr6.eq) goto loc_880F68F8;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f691c
	goto loc_880F691C;
loc_880F68F8:
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F691C:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// addic. r7,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r7.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r6,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 1;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// subf r5,r5,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// add r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 + ctx.r4.u64;
	// addi r6,r6,9552
	ctx.r6.s64 = ctx.r6.s64 + 9552;
	// clrlwi r5,r4,23
	ctx.r5.u64 = ctx.r4.u32 & 0x1FF;
	// beq 0x880f6964
	if (ctx.cr0.eq) goto loc_880F6964;
	// addi r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6964:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f697c
	if (ctx.cr6.eq) goto loc_880F697C;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F697C:
	// mullw r9,r9,r8
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// ori r7,r8,43691
	ctx.r7.u64 = ctx.r8.u64 | 43691;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lhz r6,4200(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// mulhwu r5,r6,r7
	ctx.r5.u64 = (uint64_t(ctx.r6.u32) * uint64_t(ctx.r7.u32)) >> 32;
	// rlwinm r10,r5,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r4,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r4.s64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// addi r8,r10,24
	ctx.r8.s64 = ctx.r10.s64 + 24;
	// stb r8,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r8.u8);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F69C0"))) PPC_WEAK_FUNC(sub_880F69C0);
PPC_FUNC_IMPL(__imp__sub_880F69C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// li r8,2
	ctx.r8.s64 = 2;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// rlwinm r7,r10,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// stb r8,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r8.u8);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// stb r8,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r8.u8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// bne cr6,0x880f6ab4
	if (!ctx.cr6.eq) goto loc_880F6AB4;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lhz r6,38(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r5,4200(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r5,r5,27
	ctx.r5.u64 = ctx.r5.u32 & 0x1F;
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r4.u16);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bne cr6,0x880f6a30
	if (!ctx.cr6.eq) goto loc_880F6A30;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f6a54
	goto loc_880F6A54;
loc_880F6A30:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F6A54:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// addic. r7,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r7.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r4,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// extsh r6,r5
	ctx.r6.s64 = ctx.r5.s16;
	// addze r5,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r5.s64 = temp.s64;
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// subf r5,r5,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// addi r5,r4,9552
	ctx.r5.s64 = ctx.r4.s64 + 9552;
	// clrlwi r6,r6,23
	ctx.r6.u64 = ctx.r6.u32 & 0x1FF;
	// beq 0x880f6a9c
	if (ctx.cr0.eq) goto loc_880F6A9C;
	// addi r4,r6,128
	ctx.r4.s64 = ctx.r6.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6A9C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6ab4
	if (ctx.cr6.eq) goto loc_880F6AB4;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F6AB4:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// lis r3,-21846
	ctx.r3.s64 = -1431699456;
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// addi r5,r7,12345
	ctx.r5.s64 = ctx.r7.s64 + 12345;
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// rlwinm r4,r8,2,26,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3C;
	// stw r5,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r5.u32);
	// ori r8,r3,43691
	ctx.r8.u64 = ctx.r3.u64 | 43691;
	// lhz r31,4200(r10)
	ctx.r31.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// addi r7,r6,4504
	ctx.r7.s64 = ctx.r6.s64 + 4504;
	// mulhwu r6,r31,r8
	ctx.r6.u64 = (uint64_t(ctx.r31.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// addi r8,r7,400
	ctx.r8.s64 = ctx.r7.s64 + 400;
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 + ctx.r8.u64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r7,-96
	ctx.r3.s64 = ctx.r7.s64 + -96;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lhz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// subf r6,r6,r31
	ctx.r6.s64 = ctx.r31.s64 - ctx.r6.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// stb r4,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r4.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r4.u8);
	// lbz r8,3(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r8,41(r11)
	PPC_STORE_U8(ctx.r11.u32 + 41, ctx.r8.u8);
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// bne cr6,0x880f6b3c
	if (!ctx.cr6.eq) goto loc_880F6B3C;
	// addi r8,r7,-48
	ctx.r8.s64 = ctx.r7.s64 + -48;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// b 0x880f6b48
	goto loc_880F6B48;
loc_880F6B3C:
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x880f6b48
	if (!ctx.cr6.eq) goto loc_880F6B48;
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
loc_880F6B48:
	// mullw r9,r5,r9
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f6b6c
	if (ctx.cr6.eq) goto loc_880F6B6C;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,36(r11)
	PPC_STORE_U16(ctx.r11.u32 + 36, ctx.r10.u16);
loc_880F6B6C:
	// li r10,192
	ctx.r10.s64 = 192;
	// li r3,1
	ctx.r3.s64 = 1;
	// sth r10,34(r11)
	PPC_STORE_U16(ctx.r11.u32 + 34, ctx.r10.u16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6B80"))) PPC_WEAK_FUNC(sub_880F6B80);
PPC_FUNC_IMPL(__imp__sub_880F6B80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lhz r6,38(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// li r5,3
	ctx.r5.s64 = 3;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// stb r5,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r5.u8);
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// lwz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stb r5,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r5.u8);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// mullw r4,r8,r9
	ctx.r4.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r5,r5,28
	ctx.r5.u64 = ctx.r5.u32 & 0xF;
	// addi r8,r4,12345
	ctx.r8.s64 = ctx.r4.s64 + 12345;
	// subfic r4,r5,255
	ctx.xer.ca = ctx.r5.u32 <= 255;
	ctx.r4.s64 = 255 - ctx.r5.s64;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r5,r5,26
	ctx.r5.u64 = ctx.r5.u32 & 0x3F;
	// addi r31,r5,8
	ctx.r31.s64 = ctx.r5.s64 + 8;
	// sth r4,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, ctx.r4.u16);
	// bne cr6,0x880f6bf0
	if (!ctx.cr6.eq) goto loc_880F6BF0;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f6c14
	goto loc_880F6C14;
loc_880F6BF0:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F6C14:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r4,32(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 32);
	// addic. r7,r10,24
	ctx.xer.ca = ctx.r10.u32 > 4294967271;
	ctx.r7.s64 = ctx.r10.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r3,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 1;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// addi r3,r10,20
	ctx.r3.s64 = ctx.r10.s64 + 20;
	// add r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r6,r6,9552
	ctx.r6.s64 = ctx.r6.s64 + 9552;
	// clrlwi r5,r5,23
	ctx.r5.u64 = ctx.r5.u32 & 0x1FF;
	// beq 0x880f6c5c
	if (ctx.cr0.eq) goto loc_880F6C5C;
	// addi r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6C5C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6c74
	if (ctx.cr6.eq) goto loc_880F6C74;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F6C74:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r6,r8,12345
	ctx.r6.s64 = ctx.r8.s64 + 12345;
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// stw r6,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r6.u32);
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// ori r5,r8,43691
	ctx.r5.u64 = ctx.r8.u64 | 43691;
	// lhz r3,4200(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r7,r7,4384
	ctx.r7.s64 = ctx.r7.s64 + 4384;
	// mulhwu r8,r3,r5
	ctx.r8.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r4,r7,-48
	ctx.r4.s64 = ctx.r7.s64 + -48;
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// add r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 + ctx.r5.u64;
	// subf r4,r5,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r5.s64;
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880f6cc8
	if (!ctx.cr6.eq) goto loc_880F6CC8;
	// addi r8,r7,-24
	ctx.r8.s64 = ctx.r7.s64 + -24;
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// b 0x880f6cd4
	goto loc_880F6CD4;
loc_880F6CC8:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x880f6cd4
	if (!ctx.cr6.eq) goto loc_880F6CD4;
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
loc_880F6CD4:
	// mullw r9,r6,r9
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// lhz r11,4200(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f6cfc
	if (ctx.cr6.eq) goto loc_880F6CFC;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,36(r10)
	PPC_STORE_U16(ctx.r10.u32 + 36, ctx.r11.u16);
loc_880F6CFC:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6D04"))) PPC_WEAK_FUNC(sub_880F6D04);
PPC_FUNC_IMPL(__imp__sub_880F6D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F6D08"))) PPC_WEAK_FUNC(sub_880F6D08);
PPC_FUNC_IMPL(__imp__sub_880F6D08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// li r30,1
	ctx.r30.s64 = 1;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stb r30,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r30.u8);
	// lwz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r8,r6,12345
	ctx.r8.s64 = ctx.r6.s64 + 12345;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lhz r7,4200(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r7,r7,25
	ctx.r7.u64 = ctx.r7.u32 & 0x7F;
	// addi r5,r7,16
	ctx.r5.s64 = ctx.r7.s64 + 16;
	// stb r6,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, ctx.r6.u8);
	// extsh r3,r5
	ctx.r3.s64 = ctx.r5.s16;
	// sth r3,30(r10)
	PPC_STORE_U16(ctx.r10.u32 + 30, ctx.r3.u16);
	// cmpwi cr6,r3,72
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 72, ctx.xer);
	// ble cr6,0x880f6d78
	if (!ctx.cr6.gt) goto loc_880F6D78;
	// li r7,72
	ctx.r7.s64 = 72;
	// sth r7,30(r10)
	PPC_STORE_U16(ctx.r10.u32 + 30, ctx.r7.u16);
loc_880F6D78:
	// lhz r5,38(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 38);
	// lhz r6,30(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 30);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// extsh r31,r6
	ctx.r31.s64 = ctx.r6.s16;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880f6d98
	if (!ctx.cr6.eq) goto loc_880F6D98;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x880f6dbc
	goto loc_880F6DBC;
loc_880F6D98:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// divwu r3,r4,r6
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r6.u32);
	// mullw r7,r3,r6
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// subf r6,r7,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r6,r6,16
	ctx.r6.u64 = ctx.r6.u32 & 0xFFFF;
loc_880F6DBC:
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lhz r3,32(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 32);
	// addic. r7,r10,24
	ctx.xer.ca = ctx.r10.u32 > 4294967271;
	ctx.r7.s64 = ctx.r10.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r5,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 1;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// addze r5,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r5.s64 = temp.s64;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// subf r5,r5,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r10,20
	ctx.r3.s64 = ctx.r10.s64 + 20;
	// add r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 + ctx.r4.u64;
	// addi r6,r6,9552
	ctx.r6.s64 = ctx.r6.s64 + 9552;
	// clrlwi r5,r4,23
	ctx.r5.u64 = ctx.r4.u32 & 0x1FF;
	// beq 0x880f6e04
	if (ctx.cr0.eq) goto loc_880F6E04;
	// addi r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6E04:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6e1c
	if (ctx.cr6.eq) goto loc_880F6E1C;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F6E1C:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// lis r6,-30680
	ctx.r6.s64 = -2010644480;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r5,r6,4552
	ctx.r5.s64 = ctx.r6.s64 + 4552;
	// clrlwi r4,r7,31
	ctx.r4.u64 = ctx.r7.u32 & 0x1;
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x880f6e48
	if (ctx.cr6.eq) goto loc_880F6E48;
	// sth r30,36(r10)
	PPC_STORE_U16(ctx.r10.u32 + 36, ctx.r30.u16);
loc_880F6E48:
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// lhz r11,4200(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// stb r11,42(r10)
	PPC_STORE_U8(ctx.r10.u32 + 42, ctx.r11.u8);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F6E70"))) PPC_WEAK_FUNC(sub_880F6E70);
PPC_FUNC_IMPL(__imp__sub_880F6E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r10,-30671
	ctx.r10.s64 = -2010054656;
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// li r7,2
	ctx.r7.s64 = 2;
	// ori r9,r9,20077
	ctx.r9.u64 = ctx.r9.u64 | 20077;
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4200);
	// stb r7,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r7.u8);
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r7,r7,26
	ctx.r7.u64 = ctx.r7.u32 & 0x3F;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r6.u16);
	// cmpwi cr6,r6,52
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 52, ctx.xer);
	// ble cr6,0x880f6ec8
	if (!ctx.cr6.gt) goto loc_880F6EC8;
	// li r7,52
	ctx.r7.s64 = 52;
	// sth r7,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r7.u16);
loc_880F6EC8:
	// lhz r5,38(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 38);
	// lhz r6,30(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 30);
	// extsh r7,r5
	ctx.r7.s64 = ctx.r5.s16;
	// extsh r31,r6
	ctx.r31.s64 = ctx.r6.s16;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x880f6ee8
	if (!ctx.cr6.eq) goto loc_880F6EE8;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x880f6f0c
	goto loc_880F6F0C;
loc_880F6EE8:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// divwu r3,r4,r6
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r6.u32);
	// mullw r7,r3,r6
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// subf r6,r7,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r6,r6,16
	ctx.r6.u64 = ctx.r6.u32 & 0xFFFF;
loc_880F6F0C:
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lhz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// addic. r7,r11,24
	ctx.xer.ca = ctx.r11.u32 > 4294967271;
	ctx.r7.s64 = ctx.r11.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r5,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 1;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// addze r5,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r5.s64 = temp.s64;
	// lis r4,-30714
	ctx.r4.s64 = -2012872704;
	// subf r5,r5,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r5.s64;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// add r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 + ctx.r6.u64;
	// addi r5,r4,9552
	ctx.r5.s64 = ctx.r4.s64 + 9552;
	// clrlwi r6,r6,23
	ctx.r6.u64 = ctx.r6.u32 & 0x1FF;
	// beq 0x880f6f54
	if (ctx.cr0.eq) goto loc_880F6F54;
	// addi r4,r6,128
	ctx.r4.s64 = ctx.r6.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r5.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F6F54:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f6f6c
	if (ctx.cr6.eq) goto loc_880F6F6C;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r5
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F6F6C:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// lis r3,-21846
	ctx.r3.s64 = -1431699456;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// lhz r7,4200(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// addi r8,r6,12345
	ctx.r8.s64 = ctx.r6.s64 + 12345;
	// rlwinm r4,r7,2,26,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3C;
	// stw r8,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r8.u32);
	// mullw r7,r8,r9
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r5,r7,12345
	ctx.r5.s64 = ctx.r7.s64 + 12345;
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// addi r7,r7,4504
	ctx.r7.s64 = ctx.r7.s64 + 4504;
	// lhz r8,4200(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r31,r8,30
	ctx.r31.u64 = ctx.r8.u32 & 0x3;
	// ori r8,r3,43691
	ctx.r8.u64 = ctx.r3.u64 | 43691;
	// stw r5,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r5.u32);
	// lhz r30,4200(r10)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// addi r3,r7,-96
	ctx.r3.s64 = ctx.r7.s64 + -96;
	// mulhwu r6,r30,r8
	ctx.r6.u64 = (uint64_t(ctx.r30.u32) * uint64_t(ctx.r8.u32)) >> 32;
	// addi r8,r7,336
	ctx.r8.s64 = ctx.r7.s64 + 336;
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 + ctx.r8.u64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 + ctx.r4.u64;
	// lhz r4,0(r8)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r8.u32 + 0);
	// subf r6,r6,r30
	ctx.r6.s64 = ctx.r30.s64 - ctx.r6.s64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// stb r4,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r4.u8);
	// lbz r4,2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + 2);
	// stb r4,40(r11)
	PPC_STORE_U8(ctx.r11.u32 + 40, ctx.r4.u8);
	// lbz r8,3(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + 3);
	// stb r8,41(r11)
	PPC_STORE_U8(ctx.r11.u32 + 41, ctx.r8.u8);
	// stw r3,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r3.u32);
	// stb r31,42(r11)
	PPC_STORE_U8(ctx.r11.u32 + 42, ctx.r31.u8);
	// bne cr6,0x880f700c
	if (!ctx.cr6.eq) goto loc_880F700C;
	// addi r8,r7,-48
	ctx.r8.s64 = ctx.r7.s64 + -48;
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// b 0x880f7018
	goto loc_880F7018;
loc_880F700C:
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x880f7018
	if (!ctx.cr6.eq) goto loc_880F7018;
	// stw r7,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
loc_880F7018:
	// mullw r9,r5,r9
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4200(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4200, ctx.r9.u32);
	// lhz r10,4200(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4200);
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x880f7040
	if (ctx.cr6.eq) goto loc_880F7040;
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r10,36(r11)
	PPC_STORE_U16(ctx.r11.u32 + 36, ctx.r10.u16);
loc_880F7040:
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F704C"))) PPC_WEAK_FUNC(sub_880F704C);
PPC_FUNC_IMPL(__imp__sub_880F704C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_880F7050"))) PPC_WEAK_FUNC(sub_880F7050);
PPC_FUNC_IMPL(__imp__sub_880F7050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// li r7,20
	ctx.r7.s64 = 20;
	// ori r9,r5,20077
	ctx.r9.u64 = ctx.r5.u64 | 20077;
	// lis r4,-3856
	ctx.r4.s64 = -252706816;
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// lwz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// rlwinm r3,r6,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stb r7,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, ctx.r7.u8);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// ori r6,r4,61681
	ctx.r6.u64 = ctx.r4.u64 | 61681;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// mulhwu r4,r5,r6
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r7,r4,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// subf r7,r3,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r3.s64;
	// subfic r6,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r6.s64 = 255 - ctx.r7.s64;
	// sth r6,34(r10)
	PPC_STORE_U16(ctx.r10.u32 + 34, ctx.r6.u16);
	// bne cr6,0x880f7170
	if (!ctx.cr6.eq) goto loc_880F7170;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lhz r6,38(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 38);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r5,r5,26
	ctx.r5.u64 = ctx.r5.u32 & 0x3F;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// rlwinm r31,r5,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x880f70ec
	if (!ctx.cr6.eq) goto loc_880F70EC;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f7110
	goto loc_880F7110;
loc_880F70EC:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F7110:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r4,32(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 32);
	// addic. r7,r10,24
	ctx.xer.ca = ctx.r10.u32 > 4294967271;
	ctx.r7.s64 = ctx.r10.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r3,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 1;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// addi r3,r10,20
	ctx.r3.s64 = ctx.r10.s64 + 20;
	// add r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r6,r6,9552
	ctx.r6.s64 = ctx.r6.s64 + 9552;
	// clrlwi r5,r5,23
	ctx.r5.u64 = ctx.r5.u32 & 0x1FF;
	// beq 0x880f7158
	if (ctx.cr0.eq) goto loc_880F7158;
	// addi r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F7158:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f7170
	if (ctx.cr6.eq) goto loc_880F7170;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F7170:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r6,r8,12345
	ctx.r6.s64 = ctx.r8.s64 + 12345;
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// stw r6,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r6.u32);
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// ori r5,r8,43691
	ctx.r5.u64 = ctx.r8.u64 | 43691;
	// lhz r3,4200(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r7,r7,4384
	ctx.r7.s64 = ctx.r7.s64 + 4384;
	// mulhwu r8,r3,r5
	ctx.r8.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r4,r7,-48
	ctx.r4.s64 = ctx.r7.s64 + -48;
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// add r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 + ctx.r5.u64;
	// subf r4,r5,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r5.s64;
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880f71c4
	if (!ctx.cr6.eq) goto loc_880F71C4;
	// addi r8,r7,-24
	ctx.r8.s64 = ctx.r7.s64 + -24;
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// b 0x880f71d0
	goto loc_880F71D0;
loc_880F71C4:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x880f71d0
	if (!ctx.cr6.eq) goto loc_880F71D0;
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
loc_880F71D0:
	// mullw r9,r6,r9
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// lhz r11,4200(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f71f4
	if (ctx.cr6.eq) goto loc_880F71F4;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,36(r10)
	PPC_STORE_U16(ctx.r10.u32 + 36, ctx.r11.u16);
loc_880F71F4:
	// li r11,6
	ctx.r11.s64 = 6;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r11.u8);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_880F7208"))) PPC_WEAK_FUNC(sub_880F7208);
PPC_FUNC_IMPL(__imp__sub_880F7208) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-30671
	ctx.r11.s64 = -2010054656;
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// li r7,3
	ctx.r7.s64 = 3;
	// ori r9,r5,20077
	ctx.r9.u64 = ctx.r5.u64 | 20077;
	// lis r4,-3856
	ctx.r4.s64 = -252706816;
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// lwz r8,4200(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4200);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// rlwinm r3,r6,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// stb r7,5(r10)
	PPC_STORE_U8(ctx.r10.u32 + 5, ctx.r7.u8);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// ori r6,r4,61681
	ctx.r6.u64 = ctx.r4.u64 | 61681;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// mulhwu r4,r5,r6
	ctx.r4.u64 = (uint64_t(ctx.r5.u32) * uint64_t(ctx.r6.u32)) >> 32;
	// rlwinm r7,r4,28,4,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r6,r7,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r6,r7
	ctx.r3.u64 = ctx.r6.u64 + ctx.r7.u64;
	// subf r7,r3,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r3.s64;
	// subfic r6,r7,255
	ctx.xer.ca = ctx.r7.u32 <= 255;
	ctx.r6.s64 = 255 - ctx.r7.s64;
	// sth r6,34(r10)
	PPC_STORE_U16(ctx.r10.u32 + 34, ctx.r6.u16);
	// bne cr6,0x880f7328
	if (!ctx.cr6.eq) goto loc_880F7328;
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lhz r6,38(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 38);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r5,4200(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r5,r5,26
	ctx.r5.u64 = ctx.r5.u32 & 0x3F;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// rlwinm r31,r5,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x880f72a4
	if (!ctx.cr6.eq) goto loc_880F72A4;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x880f72c8
	goto loc_880F72C8;
loc_880F72A4:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r8,r8,12345
	ctx.r8.s64 = ctx.r8.s64 + 12345;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// stw r8,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r8.u32);
	// lhz r4,4200(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// divwu r3,r4,r5
	ctx.r3.u32 = ppc_divwu(ctx.r4.u32, ctx.r5.u32);
	// mullw r7,r3,r5
	ctx.r7.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r5.s32);
	// subf r5,r7,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r7.s64;
	// clrlwi r5,r5,16
	ctx.r5.u64 = ctx.r5.u32 & 0xFFFF;
loc_880F72C8:
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhz r4,32(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 32);
	// addic. r7,r10,24
	ctx.xer.ca = ctx.r10.u32 > 4294967271;
	ctx.r7.s64 = ctx.r10.s64 + 24;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// srawi r3,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 1;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// lis r6,-30714
	ctx.r6.s64 = -2012872704;
	// subf r4,r3,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r3.s64;
	// addi r3,r10,20
	ctx.r3.s64 = ctx.r10.s64 + 20;
	// add r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64;
	// addi r6,r6,9552
	ctx.r6.s64 = ctx.r6.s64 + 9552;
	// clrlwi r5,r5,23
	ctx.r5.u64 = ctx.r5.u32 & 0x1FF;
	// beq 0x880f7310
	if (ctx.cr0.eq) goto loc_880F7310;
	// addi r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 128;
	// rlwinm r4,r4,2,21,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x7FC;
	// lwzx r4,r4,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// mullw r4,r4,r31
	ctx.r4.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r31.s32);
	// stw r4,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r4.u32);
loc_880F7310:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x880f7328
	if (ctx.cr6.eq) goto loc_880F7328;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// mullw r5,r6,r31
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r31.s32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
loc_880F7328:
	// mullw r8,r8,r9
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// addi r6,r8,12345
	ctx.r6.s64 = ctx.r8.s64 + 12345;
	// lis r8,-21846
	ctx.r8.s64 = -1431699456;
	// stw r6,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r6.u32);
	// lis r7,-30680
	ctx.r7.s64 = -2010644480;
	// ori r5,r8,43691
	ctx.r5.u64 = ctx.r8.u64 | 43691;
	// lhz r3,4200(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// addi r7,r7,4384
	ctx.r7.s64 = ctx.r7.s64 + 4384;
	// mulhwu r8,r3,r5
	ctx.r8.u64 = (uint64_t(ctx.r3.u32) * uint64_t(ctx.r5.u32)) >> 32;
	// rlwinm r8,r8,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r4,r7,-48
	ctx.r4.s64 = ctx.r7.s64 + -48;
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// add r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 + ctx.r5.u64;
	// subf r4,r5,r3
	ctx.r4.s64 = ctx.r3.s64 - ctx.r5.s64;
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x880f737c
	if (!ctx.cr6.eq) goto loc_880F737C;
	// addi r8,r7,-24
	ctx.r8.s64 = ctx.r7.s64 + -24;
	// stw r8,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r8.u32);
	// b 0x880f7388
	goto loc_880F7388;
loc_880F737C:
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// bne cr6,0x880f7388
	if (!ctx.cr6.eq) goto loc_880F7388;
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
loc_880F7388:
	// mullw r9,r6,r9
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// addi r9,r9,12345
	ctx.r9.s64 = ctx.r9.s64 + 12345;
	// stw r9,4200(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4200, ctx.r9.u32);
	// lhz r11,4200(r11)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4200);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x880f73ac
	if (ctx.cr6.eq) goto loc_880F73AC;
	// li r11,1
	ctx.r11.s64 = 1;
	// sth r11,36(r10)
	PPC_STORE_U16(ctx.r10.u32 + 36, ctx.r11.u16);
loc_880F73AC:
	// li r11,6
	ctx.r11.s64 = 6;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, ctx.r11.u8);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

