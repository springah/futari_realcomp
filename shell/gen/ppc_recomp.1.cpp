#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_820661D4"))) PPC_WEAK_FUNC(sub_820661D4);
PPC_FUNC_IMPL(__imp__sub_820661D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820661D8"))) PPC_WEAK_FUNC(sub_820661D8);
PPC_FUNC_IMPL(__imp__sub_820661D8) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,1232
	ctx.r10.s64 = ctx.r11.s64 + 1232;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821ba410
	ctx.lr = 0x82066204;
	sub_821BA410(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206621c
	if (ctx.cr6.eq) goto loc_8206621C;
	// bl 0x8207a630
	ctx.lr = 0x82066218;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206621C:
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

__attribute__((alias("__imp__sub_82066234"))) PPC_WEAK_FUNC(sub_82066234);
PPC_FUNC_IMPL(__imp__sub_82066234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82066238"))) PPC_WEAK_FUNC(sub_82066238);
PPC_FUNC_IMPL(__imp__sub_82066238) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,1304
	ctx.r8.s64 = ctx.r10.s64 + 1304;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r9,108(r11)
	PPC_STORE_U32(ctx.r11.u32 + 108, ctx.r9.u32);
	// bl 0x821ba410
	ctx.lr = 0x82066274;
	sub_821BA410(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206628c
	if (ctx.cr6.eq) goto loc_8206628C;
	// bl 0x8207a630
	ctx.lr = 0x82066288;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206628C:
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

__attribute__((alias("__imp__sub_820662A4"))) PPC_WEAK_FUNC(sub_820662A4);
PPC_FUNC_IMPL(__imp__sub_820662A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820662A8"))) PPC_WEAK_FUNC(sub_820662A8);
PPC_FUNC_IMPL(__imp__sub_820662A8) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820662B8"))) PPC_WEAK_FUNC(sub_820662B8);
PPC_FUNC_IMPL(__imp__sub_820662B8) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820662C8"))) PPC_WEAK_FUNC(sub_820662C8);
PPC_FUNC_IMPL(__imp__sub_820662C8) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,76(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820662D8"))) PPC_WEAK_FUNC(sub_820662D8);
PPC_FUNC_IMPL(__imp__sub_820662D8) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_820662E8"))) PPC_WEAK_FUNC(sub_820662E8);
PPC_FUNC_IMPL(__imp__sub_820662E8) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,1396
	ctx.r10.s64 = ctx.r11.s64 + 1396;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b89a0
	ctx.lr = 0x82066314;
	sub_821B89A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206632c
	if (ctx.cr6.eq) goto loc_8206632C;
	// bl 0x8207a630
	ctx.lr = 0x82066328;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206632C:
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

__attribute__((alias("__imp__sub_82066344"))) PPC_WEAK_FUNC(sub_82066344);
PPC_FUNC_IMPL(__imp__sub_82066344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82066348"))) PPC_WEAK_FUNC(sub_82066348);
PPC_FUNC_IMPL(__imp__sub_82066348) {
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
	// bl 0x821b5c28
	ctx.lr = 0x82066368;
	sub_821B5C28(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82066380
	if (ctx.cr6.eq) goto loc_82066380;
	// bl 0x8207a630
	ctx.lr = 0x8206637C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82066380:
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

__attribute__((alias("__imp__sub_82066398"))) PPC_WEAK_FUNC(sub_82066398);
PPC_FUNC_IMPL(__imp__sub_82066398) {
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
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x820601f8
	ctx.lr = 0x820663C0;
	sub_820601F8(ctx, base);
	// lwz r11,28(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// addi r4,r30,56
	ctx.r4.s64 = ctx.r30.s64 + 56;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r9,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// lwz r8,40(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// stw r8,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
	// lwz r7,44(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// stw r7,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r7.u32);
	// lwz r6,48(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// stw r6,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r6.u32);
	// lwz r5,52(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// stw r5,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r5.u32);
	// bl 0x820666c0
	ctx.lr = 0x82066404;
	sub_820666C0(ctx, base);
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

__attribute__((alias("__imp__sub_82066420"))) PPC_WEAK_FUNC(sub_82066420);
PPC_FUNC_IMPL(__imp__sub_82066420) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82066428;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x820664f0
	if (ctx.cr6.gt) goto loc_820664F0;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r11,-1264
	ctx.r4.s64 = ctx.r11.s64 + -1264;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82060368
	ctx.lr = 0x82066474;
	sub_82060368(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060e58
	ctx.lr = 0x82066480;
	sub_82060E58(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,-12320(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12320);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820664a0
	if (ctx.cr6.eq) goto loc_820664A0;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x820664A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_820664A0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x820664B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a0c0
	ctx.lr = 0x820664BC;
	sub_8207A0C0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r8,r9,-1236
	ctx.r8.s64 = ctx.r9.s64 + -1236;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// bl 0x82060c50
	ctx.lr = 0x820664D0;
	sub_82060C50(ctx, base);
	// lwz r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x820664e4
	if (ctx.cr6.lt) goto loc_820664E4;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x820664E4;
	sub_8207A630(ctx, base);
loc_820664E4:
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
loc_820664F0:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82066504
	if (!ctx.cr6.gt) goto loc_82066504;
	// twi 31,r0,22
loc_82066504:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82061310
	ctx.lr = 0x82066520;
	sub_82061310(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82066550
	if (!ctx.cr6.eq) goto loc_82066550;
	// twi 31,r0,22
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82066534:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82066548
	if (ctx.cr6.lt) goto loc_82066548;
	// twi 31,r0,22
loc_82066548:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82066550:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82066534
	goto loc_82066534;
}

__attribute__((alias("__imp__sub_82066558"))) PPC_WEAK_FUNC(sub_82066558);
PPC_FUNC_IMPL(__imp__sub_82066558) {
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
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r5,16(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x8206658c
	if (!ctx.cr6.gt) goto loc_8206658C;
	// twi 31,r0,22
	// twi 31,r0,22
	// twi 31,r0,22
loc_8206658C:
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x820665a0
	if (ctx.cr6.gt) goto loc_820665A0;
	// cmplw cr6,r5,r5
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x820665a4
	if (!ctx.cr6.gt) goto loc_820665A4;
loc_820665A0:
	// twi 31,r0,22
loc_820665A4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820665b4
	if (ctx.cr6.eq) goto loc_820665B4;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x820665b8
	if (ctx.cr6.eq) goto loc_820665B8;
loc_820665B4:
	// twi 31,r0,22
loc_820665B8:
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x820665e0
	if (ctx.cr6.eq) goto loc_820665E0;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r3
	ctx.r31.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x820665dc
	if (!ctx.cr0.gt) goto loc_820665DC;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x820665DC;
	sub_8207A520(ctx, base);
loc_820665DC:
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
loc_820665E0:
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

__attribute__((alias("__imp__sub_820665F8"))) PPC_WEAK_FUNC(sub_820665F8);
PPC_FUNC_IMPL(__imp__sub_820665F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82066600;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,4
	ctx.r3.s64 = 4;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82079fd8
	ctx.lr = 0x82066614;
	sub_82079FD8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82066628
	if (ctx.cr6.eq) goto loc_82066628;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8206662c
	goto loc_8206662C;
loc_82066628:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_8206662C:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r10,80
	ctx.r10.s64 = 80;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// divw. r4,r7,r10
	ctx.r4.s32 = ppc_divw(ctx.r7.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r11.u32);
	// stw r11,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r11.u32);
	// stw r11,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
	// beq 0x82066660
	if (ctx.cr0.eq) goto loc_82066660;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82066a38
	ctx.lr = 0x8206665C;
	sub_82066A38(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82066660:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820666b0
	if (ctx.cr6.eq) goto loc_820666B0;
	// lwz r28,16(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r31,12(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// ble cr6,0x82066684
	if (!ctx.cr6.gt) goto loc_82066684;
	// twi 31,r0,22
	// twi 31,r0,22
loc_82066684:
	// lwz r30,12(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820666ac
	if (ctx.cr6.eq) goto loc_820666AC;
loc_82066690:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82067168
	ctx.lr = 0x8206669C;
	sub_82067168(ctx, base);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82066690
	if (!ctx.cr6.eq) goto loc_82066690;
loc_820666AC:
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
loc_820666B0:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820666BC"))) PPC_WEAK_FUNC(sub_820666BC);
PPC_FUNC_IMPL(__imp__sub_820666BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820666C0"))) PPC_WEAK_FUNC(sub_820666C0);
PPC_FUNC_IMPL(__imp__sub_820666C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820666C8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8206687c
	if (ctx.cr6.eq) goto loc_8206687C;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// li r29,80
	ctx.r29.s64 = 80;
	// lwz r3,12(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// subf r11,r3,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r3.s64;
	// divw. r9,r11,r29
	ctx.r9.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82066708
	if (!ctx.cr0.eq) goto loc_82066708;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820669a0
	ctx.lr = 0x820666FC;
	sub_820669A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82066708:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r11,r5,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r5.s64;
	// divw r11,r11,r29
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r29.s32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82066764
	if (ctx.cr6.gt) goto loc_82066764;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// bl 0x82067068
	ctx.lr = 0x82066728;
	sub_82067068(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82066ab0
	ctx.lr = 0x82066730;
	sub_82066AB0(ctx, base);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r11,r8,r29
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_82066764:
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82066778
	if (!ctx.cr6.eq) goto loc_82066778;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// b 0x82066784
	goto loc_82066784;
loc_82066778:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r8,r5,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r5.s64;
	// divw r10,r8,r29
	ctx.r10.s32 = ppc_divw(ctx.r8.s32, ctx.r29.s32);
loc_82066784:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x820667ec
	if (ctx.cr6.gt) goto loc_820667EC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r29,r11,r3
	ctx.r29.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82067068
	ctx.lr = 0x820667A8;
	sub_82067068(ctx, base);
	// lwz r28,16(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r30,16(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x820667dc
	if (ctx.cr6.eq) goto loc_820667DC;
loc_820667B8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x820667cc
	if (ctx.cr6.eq) goto loc_820667CC;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066f68
	ctx.lr = 0x820667CC;
	sub_82066F68(ctx, base);
loc_820667CC:
	// addi r29,r29,80
	ctx.r29.s64 = ctx.r29.s64 + 80;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x820667b8
	if (!ctx.cr6.eq) goto loc_820667B8;
loc_820667DC:
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_820667EC:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82066804
	if (ctx.cr6.eq) goto loc_82066804;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82066ab0
	ctx.lr = 0x820667FC;
	sub_82066AB0(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x82066804;
	sub_8207A630(ctx, base);
loc_82066804:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r28,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// divw. r4,r9,r29
	ctx.r4.s32 = ppc_divw(ctx.r9.s32, ctx.r29.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x8206682c
	if (!ctx.cr0.eq) goto loc_8206682C;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x82066834
	goto loc_82066834;
loc_8206682C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066a38
	ctx.lr = 0x82066834;
	sub_82066A38(ctx, base);
loc_82066834:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206687c
	if (ctx.cr6.eq) goto loc_8206687C;
	// lwz r28,16(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r30,12(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r29,12(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82066878
	if (ctx.cr6.eq) goto loc_82066878;
loc_82066854:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82066868
	if (ctx.cr6.eq) goto loc_82066868;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82066f68
	ctx.lr = 0x82066868;
	sub_82066F68(ctx, base);
loc_82066868:
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// addi r29,r29,80
	ctx.r29.s64 = ctx.r29.s64 + 80;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82066854
	if (!ctx.cr6.eq) goto loc_82066854;
loc_82066878:
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
loc_8206687C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82066888"))) PPC_WEAK_FUNC(sub_82066888);
PPC_FUNC_IMPL(__imp__sub_82066888) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r8,80
	ctx.r8.s64 = 80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820668b8
	if (!ctx.cr6.eq) goto loc_820668B8;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x820668c4
	goto loc_820668C4;
loc_820668B8:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r8
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r8.s32);
loc_820668C4:
	// lwz r31,16(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r10,r11,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r10,r10,r8
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r8.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820668f4
	if (!ctx.cr6.lt) goto loc_820668F4;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x820668e8
	if (ctx.cr6.eq) goto loc_820668E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066f68
	ctx.lr = 0x820668E8;
	sub_82066F68(ctx, base);
loc_820668E8:
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// b 0x82066988
	goto loc_82066988;
loc_820668F4:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82066900
	if (!ctx.cr6.gt) goto loc_82066900;
	// twi 31,r0,22
loc_82066900:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne cr6,0x82066920
	if (!ctx.cr6.eq) goto loc_82066920;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82066948
	goto loc_82066948;
loc_82066920:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8206692c
	if (!ctx.cr6.gt) goto loc_8206692C;
	// twi 31,r0,22
loc_8206692C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206693c
	if (ctx.cr6.eq) goto loc_8206693C;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82066940
	if (ctx.cr6.eq) goto loc_82066940;
loc_8206693C:
	// twi 31,r0,22
loc_82066940:
	// subf r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r31,r11,r8
	ctx.r31.s32 = ppc_divw(ctx.r11.s32, ctx.r8.s32);
loc_82066948:
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066bd8
	ctx.lr = 0x82066958;
	sub_82066BD8(ctx, base);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206696c
	if (!ctx.cr6.gt) goto loc_8206696C;
	// twi 31,r0,22
loc_8206696C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x820626c0
	ctx.lr = 0x82066988;
	sub_820626C0(ctx, base);
loc_82066988:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_820669A0"))) PPC_WEAK_FUNC(sub_820669A0);
PPC_FUNC_IMPL(__imp__sub_820669A0) {
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
	// lwz r5,12(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// ble cr6,0x820669d4
	if (!ctx.cr6.gt) goto loc_820669D4;
	// twi 31,r0,22
	// twi 31,r0,22
	// twi 31,r0,22
loc_820669D4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x820669e8
	if (ctx.cr6.gt) goto loc_820669E8;
	// cmplw cr6,r4,r4
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r4.u32, ctx.xer);
	// ble cr6,0x820669ec
	if (!ctx.cr6.gt) goto loc_820669EC;
loc_820669E8:
	// twi 31,r0,22
loc_820669EC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820669fc
	if (ctx.cr6.eq) goto loc_820669FC;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82066a00
	if (ctx.cr6.eq) goto loc_82066A00;
loc_820669FC:
	// twi 31,r0,22
loc_82066A00:
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82066a20
	if (ctx.cr6.eq) goto loc_82066A20;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82067068
	ctx.lr = 0x82066A10;
	sub_82067068(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// bl 0x82066ab0
	ctx.lr = 0x82066A1C;
	sub_82066AB0(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_82066A20:
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

__attribute__((alias("__imp__sub_82066A38"))) PPC_WEAK_FUNC(sub_82066A38);
PPC_FUNC_IMPL(__imp__sub_82066A38) {
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
	// lis r11,819
	ctx.r11.s64 = 53673984;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ori r10,r11,13107
	ctx.r10.u64 = ctx.r11.u64 | 13107;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82066a6c
	if (!ctx.cr6.gt) goto loc_82066A6C;
	// bl 0x820686c0
	ctx.lr = 0x82066A68;
	sub_820686C0(ctx, base);
	// b 0x82066a94
	goto loc_82066A94;
loc_82066A6C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066ef0
	ctx.lr = 0x82066A74;
	sub_82066EF0(ctx, base);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r3.u32);
	// add r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 + ctx.r10.u64;
	// stw r3,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r3.u32);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
loc_82066A94:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_82066AB0"))) PPC_WEAK_FUNC(sub_82066AB0);
PPC_FUNC_IMPL(__imp__sub_82066AB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82066AB8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82066b14
	if (ctx.cr6.eq) goto loc_82066B14;
	// addi r31,r3,56
	ctx.r31.s64 = ctx.r3.s64 + 56;
	// li r28,15
	ctx.r28.s64 = 15;
	// li r30,0
	ctx.r30.s64 = 0;
loc_82066AD4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066b20
	ctx.lr = 0x82066ADC;
	sub_82066B20(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82066AE4;
	sub_8207A630(ctx, base);
	// lwz r11,-32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82066af8
	if (ctx.cr6.lt) goto loc_82066AF8;
	// lwz r3,-52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -52);
	// bl 0x8207a630
	ctx.lr = 0x82066AF8;
	sub_8207A630(ctx, base);
loc_82066AF8:
	// stw r28,-32(r31)
	PPC_STORE_U32(ctx.r31.u32 + -32, ctx.r28.u32);
	// stw r30,-36(r31)
	PPC_STORE_U32(ctx.r31.u32 + -36, ctx.r30.u32);
	// stb r30,-52(r31)
	PPC_STORE_U8(ctx.r31.u32 + -52, ctx.r30.u8);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// addi r11,r31,-56
	ctx.r11.s64 = ctx.r31.s64 + -56;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82066ad4
	if (!ctx.cr6.eq) goto loc_82066AD4;
loc_82066B14:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82066B1C"))) PPC_WEAK_FUNC(sub_82066B1C);
PPC_FUNC_IMPL(__imp__sub_82066B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82066B20"))) PPC_WEAK_FUNC(sub_82066B20);
PPC_FUNC_IMPL(__imp__sub_82066B20) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82066b50
	if (ctx.cr6.eq) goto loc_82066B50;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82066ab0
	ctx.lr = 0x82066B48;
	sub_82066AB0(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x82066B50;
	sub_8207A630(ctx, base);
loc_82066B50:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
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

__attribute__((alias("__imp__sub_82066B74"))) PPC_WEAK_FUNC(sub_82066B74);
PPC_FUNC_IMPL(__imp__sub_82066B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82066B78"))) PPC_WEAK_FUNC(sub_82066B78);
PPC_FUNC_IMPL(__imp__sub_82066B78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82066B80;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82066bc0
	if (ctx.cr6.eq) goto loc_82066BC0;
loc_82066BA0:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82066bb4
	if (ctx.cr6.eq) goto loc_82066BB4;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82066f68
	ctx.lr = 0x82066BB4;
	sub_82066F68(ctx, base);
loc_82066BB4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// bne 0x82066ba0
	if (!ctx.cr0.eq) goto loc_82066BA0;
loc_82066BC0:
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82066BD8"))) PPC_WEAK_FUNC(sub_82066BD8);
PPC_FUNC_IMPL(__imp__sub_82066BD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82066BE0;
	__savegprlr_23(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r4,264(r1)
	PPC_STORE_U64(ctx.r1.u32 + 264, ctx.r4.u64);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r23,80
	ctx.r23.s64 = 80;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82066c08
	if (!ctx.cr6.eq) goto loc_82066C08;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82066c14
	goto loc_82066C14;
loc_82066C08:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r23
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
loc_82066C14:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,819
	ctx.r10.s64 = 53673984;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// ori r10,r10,13107
	ctx.r10.u64 = ctx.r10.u64 | 13107;
	// divw r11,r7,r23
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r23.s32);
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x82066c40
	if (!ctx.cr6.lt) goto loc_82066C40;
	// bl 0x820686c0
	ctx.lr = 0x82066C38;
	sub_820686C0(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82066C40:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82066d8c
	if (!ctx.cr6.lt) goto loc_82066D8C;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// li r24,0
	ctx.r24.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82066c64
	if (ctx.cr6.lt) goto loc_82066C64;
	// add r24,r11,r8
	ctx.r24.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_82066C64:
	// cmplw cr6,r24,r7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82066c70
	if (!ctx.cr6.lt) goto loc_82066C70;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
loc_82066C70:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82066ef0
	ctx.lr = 0x82066C78;
	sub_82066EF0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r28,268(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// subf r10,r11,r28
	ctx.r10.s64 = ctx.r28.s64 - ctx.r11.s64;
	// li r4,1
	ctx.r4.s64 = 1;
	// divw r27,r10,r23
	ctx.r27.s32 = ppc_divw(ctx.r10.s32, ctx.r23.s32);
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r27,r11
	ctx.r9.u64 = ctx.r27.u64 + ctx.r11.u64;
	// rlwinm r25,r9,4,0,27
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	// bl 0x82066b78
	ctx.lr = 0x82066CA8;
	sub_82066B78(ctx, base);
	// mr r26,r29
	ctx.r26.u64 = ctx.r29.u64;
	// lwz r30,12(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82066cdc
	if (ctx.cr6.eq) goto loc_82066CDC;
loc_82066CB8:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x82066ccc
	if (ctx.cr6.eq) goto loc_82066CCC;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82066f68
	ctx.lr = 0x82066CCC;
	sub_82066F68(ctx, base);
loc_82066CCC:
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// addi r26,r26,80
	ctx.r26.s64 = ctx.r26.s64 + 80;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82066cb8
	if (!ctx.cr6.eq) goto loc_82066CB8;
loc_82066CDC:
	// addi r11,r27,1
	ctx.r11.s64 = ctx.r27.s64 + 1;
	// lwz r27,16(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// beq cr6,0x82066d30
	if (ctx.cr6.eq) goto loc_82066D30;
	// subf r11,r25,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r25.s64;
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r28,r11,-80
	ctx.r28.s64 = ctx.r11.s64 + -80;
loc_82066D0C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82066d20
	if (ctx.cr6.eq) goto loc_82066D20;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066f68
	ctx.lr = 0x82066D20;
	sub_82066F68(ctx, base);
loc_82066D20:
	// addi r28,r28,80
	ctx.r28.s64 = ctx.r28.s64 + 80;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82066d0c
	if (!ctx.cr6.eq) goto loc_82066D0C;
loc_82066D30:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// divw r11,r11,r23
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x82066d58
	if (ctx.cr6.eq) goto loc_82066D58;
	// bl 0x82066ab0
	ctx.lr = 0x82066D50;
	sub_82066AB0(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x82066D58;
	sub_8207A630(ctx, base);
loc_82066D58:
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r10,r24,r10
	ctx.r10.u64 = ctx.r24.u64 + ctx.r10.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r29
	ctx.r7.u64 = ctx.r11.u64 + ctx.r29.u64;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// stw r7,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// stw r8,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r8.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82066D8C:
	// lwz r26,268(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// subf r11,r26,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r26.s64;
	// divw r10,r11,r23
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bge cr6,0x82066e10
	if (!ctx.cr6.lt) goto loc_82066E10;
	// bl 0x82066f68
	ctx.lr = 0x82066DAC;
	sub_82066F68(ctx, base);
	// addi r30,r26,80
	ctx.r30.s64 = ctx.r26.s64 + 80;
	// lwz r28,16(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r26,r28
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82066de4
	if (ctx.cr6.eq) goto loc_82066DE4;
	// addi r29,r30,-80
	ctx.r29.s64 = ctx.r30.s64 + -80;
loc_82066DC0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82066dd4
	if (ctx.cr6.eq) goto loc_82066DD4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82066f68
	ctx.lr = 0x82066DD4;
	sub_82066F68(ctx, base);
loc_82066DD4:
	// addi r29,r29,80
	ctx.r29.s64 = ctx.r29.s64 + 80;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82066dc0
	if (!ctx.cr6.eq) goto loc_82066DC0;
loc_82066DE4:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// subf r11,r26,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r26.s64;
	// divw r10,r11,r23
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// subfic r4,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r4.s64 = 1 - ctx.r10.s64;
	// bl 0x82066b78
	ctx.lr = 0x82066DFC;
	sub_82066B78(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,80
	ctx.r11.s64 = ctx.r11.s64 + 80;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// addi r4,r11,-80
	ctx.r4.s64 = ctx.r11.s64 + -80;
	// b 0x82066ed0
	goto loc_82066ED0;
loc_82066E10:
	// bl 0x82066f68
	ctx.lr = 0x82066E14;
	sub_82066F68(ctx, base);
	// lwz r27,16(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r27,-80
	ctx.r30.s64 = ctx.r27.s64 + -80;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x82066e50
	if (ctx.cr6.eq) goto loc_82066E50;
loc_82066E2C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82066e40
	if (ctx.cr6.eq) goto loc_82066E40;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82066f68
	ctx.lr = 0x82066E40;
	sub_82066F68(ctx, base);
loc_82066E40:
	// addi r28,r28,80
	ctx.r28.s64 = ctx.r28.s64 + 80;
	// addi r29,r29,80
	ctx.r29.s64 = ctx.r29.s64 + 80;
	// cmplw cr6,r28,r27
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82066e2c
	if (!ctx.cr6.eq) goto loc_82066E2C;
loc_82066E50:
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82066ecc
	if (ctx.cr6.eq) goto loc_82066ECC;
	// addi r31,r30,112
	ctx.r31.s64 = ctx.r30.s64 + 112;
	// li r29,-1
	ctx.r29.s64 = -1;
loc_82066E64:
	// addi r30,r30,-80
	ctx.r30.s64 = ctx.r30.s64 + -80;
	// addi r31,r31,-80
	ctx.r31.s64 = ctx.r31.s64 + -80;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,-32
	ctx.r3.s64 = ctx.r31.s64 + -32;
	// bl 0x820601f8
	ctx.lr = 0x82066E80;
	sub_820601F8(ctx, base);
	// lwz r11,-84(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -84);
	// addi r4,r31,-56
	ctx.r4.s64 = ctx.r31.s64 + -56;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// stw r11,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r11.u32);
	// lwz r10,-80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + -80);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r9,-76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + -76);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// lwz r8,-72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + -72);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// lwz r7,-68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + -68);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// lwz r6,-64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + -64);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// lwz r5,-60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + -60);
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// bl 0x820666c0
	ctx.lr = 0x82066EC4;
	sub_820666C0(ctx, base);
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82066e64
	if (!ctx.cr6.eq) goto loc_82066E64;
loc_82066ECC:
	// addi r4,r26,80
	ctx.r4.s64 = ctx.r26.s64 + 80;
loc_82066ED0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820670c8
	ctx.lr = 0x82066EDC;
	sub_820670C8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82067008
	ctx.lr = 0x82066EE4;
	sub_82067008(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82066EEC"))) PPC_WEAK_FUNC(sub_82066EEC);
PPC_FUNC_IMPL(__imp__sub_82066EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82066EF0"))) PPC_WEAK_FUNC(sub_82066EF0);
PPC_FUNC_IMPL(__imp__sub_82066EF0) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82066f44
	if (ctx.cr6.eq) goto loc_82066F44;
	// li r11,-1
	ctx.r11.s64 = -1;
	// divwu r10,r11,r31
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r31.u32);
	// cmplwi cr6,r10,80
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 80, ctx.xer);
	// bge cr6,0x82066f44
	if (!ctx.cr6.lt) goto loc_82066F44;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1468
	ctx.r9.s64 = ctx.r11.s64 + -1468;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x82060018
	ctx.lr = 0x82066F38;
	sub_82060018(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r7,r8,-1480
	ctx.r7.s64 = ctx.r8.s64 + -1480;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
loc_82066F44:
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82079fd8
	ctx.lr = 0x82066F54;
	sub_82079FD8(ctx, base);
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

__attribute__((alias("__imp__sub_82066F68"))) PPC_WEAK_FUNC(sub_82066F68);
PPC_FUNC_IMPL(__imp__sub_82066F68) {
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
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r11.u8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x820601f8
	ctx.lr = 0x82066FA4;
	sub_820601F8(ctx, base);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 28);
	// addi r3,r31,56
	ctx.r3.s64 = ctx.r31.s64 + 56;
	// addi r4,r30,56
	ctx.r4.s64 = ctx.r30.s64 + 56;
	// stw r9,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 32);
	// stw r8,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// stw r7,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// stw r6,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r6.u32);
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 44);
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// lwz r11,48(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 48);
	// stw r11,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// lwz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 52);
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// bl 0x820665f8
	ctx.lr = 0x82066FE8;
	sub_820665F8(ctx, base);
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

__attribute__((alias("__imp__sub_82067004"))) PPC_WEAK_FUNC(sub_82067004);
PPC_FUNC_IMPL(__imp__sub_82067004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067008"))) PPC_WEAK_FUNC(sub_82067008);
PPC_FUNC_IMPL(__imp__sub_82067008) {
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
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// bl 0x82066b20
	ctx.lr = 0x82067024;
	sub_82066B20(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 56);
	// bl 0x8207a630
	ctx.lr = 0x8206702C;
	sub_8207A630(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82067040
	if (ctx.cr6.lt) goto loc_82067040;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82067040;
	sub_8207A630(ctx, base);
loc_82067040:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
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

__attribute__((alias("__imp__sub_82067068"))) PPC_WEAK_FUNC(sub_82067068);
PPC_FUNC_IMPL(__imp__sub_82067068) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82067070;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,80
	ctx.r10.s64 = 80;
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// divw r11,r11,r10
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r10.s32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r28,r11,r5
	ctx.r28.u64 = ctx.r11.u64 + ctx.r5.u64;
	// beq cr6,0x820670bc
	if (ctx.cr6.eq) goto loc_820670BC;
	// subf r29,r3,r5
	ctx.r29.s64 = ctx.r5.s64 - ctx.r3.s64;
loc_820670A4:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// bl 0x82066398
	ctx.lr = 0x820670B0;
	sub_82066398(ctx, base);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820670a4
	if (!ctx.cr6.eq) goto loc_820670A4;
loc_820670BC:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820670C8"))) PPC_WEAK_FUNC(sub_820670C8);
PPC_FUNC_IMPL(__imp__sub_820670C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820670D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8206715c
	if (ctx.cr6.eq) goto loc_8206715C;
	// addi r30,r5,40
	ctx.r30.s64 = ctx.r5.s64 + 40;
	// addi r28,r5,56
	ctx.r28.s64 = ctx.r5.s64 + 56;
	// addi r31,r3,32
	ctx.r31.s64 = ctx.r3.s64 + 32;
	// li r26,-1
	ctx.r26.s64 = -1;
loc_820670F4:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,-32
	ctx.r3.s64 = ctx.r31.s64 + -32;
	// bl 0x820601f8
	ctx.lr = 0x82067108;
	sub_820601F8(ctx, base);
	// lwz r11,28(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 28);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r31,24
	ctx.r3.s64 = ctx.r31.s64 + 24;
	// stw r11,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r11.u32);
	// lwz r10,32(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 32);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 36);
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r5,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// bl 0x820666c0
	ctx.lr = 0x8206714C;
	sub_820666C0(ctx, base);
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// addi r4,r31,-32
	ctx.r4.s64 = ctx.r31.s64 + -32;
	// cmplw cr6,r4,r27
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x820670f4
	if (!ctx.cr6.eq) goto loc_820670F4;
loc_8206715C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82067164"))) PPC_WEAK_FUNC(sub_82067164);
PPC_FUNC_IMPL(__imp__sub_82067164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067168"))) PPC_WEAK_FUNC(sub_82067168);
PPC_FUNC_IMPL(__imp__sub_82067168) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// b 0x82066f68
	sub_82066F68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82067174"))) PPC_WEAK_FUNC(sub_82067174);
PPC_FUNC_IMPL(__imp__sub_82067174) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82067178"))) PPC_WEAK_FUNC(sub_82067178);
PPC_FUNC_IMPL(__imp__sub_82067178) {
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
	// bl 0x821b4b30
	ctx.lr = 0x82067198;
	sub_821B4B30(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820671b0
	if (ctx.cr6.eq) goto loc_820671B0;
	// bl 0x8207a630
	ctx.lr = 0x820671AC;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820671B0:
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

__attribute__((alias("__imp__sub_820671C8"))) PPC_WEAK_FUNC(sub_820671C8);
PPC_FUNC_IMPL(__imp__sub_820671C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x820671D0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// std r5,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// std r6,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r6.u64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82067210
	if (ctx.cr6.eq) goto loc_82067210;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82067210
	if (ctx.cr6.gt) goto loc_82067210;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82067214
	if (!ctx.cr6.gt) goto loc_82067214;
loc_82067210:
	// twi 31,r0,22
loc_82067214:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r31,188(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// cmplw cr6,r9,r31
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r31.u32, ctx.xer);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// bgt cr6,0x8206723c
	if (ctx.cr6.gt) goto loc_8206723C;
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x82067240
	if (!ctx.cr6.gt) goto loc_82067240;
loc_8206723C:
	// twi 31,r0,22
loc_82067240:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206724c
	if (!ctx.cr6.eq) goto loc_8206724C;
	// twi 31,r0,22
loc_8206724C:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x820672a0
	if (ctx.cr6.eq) goto loc_820672A0;
	// lwz r30,16(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// li r10,644
	ctx.r10.s64 = 644;
	// subf r9,r31,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r31.s64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// divw r8,r9,r10
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r10.s32);
	// mulli r10,r8,644
	ctx.r10.s64 = ctx.r8.s64 * 644;
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// beq cr6,0x82067290
	if (ctx.cr6.eq) goto loc_82067290;
	// subf r28,r31,r11
	ctx.r28.s64 = ctx.r11.s64 - ctx.r31.s64;
loc_82067278:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r28,r31
	ctx.r3.u64 = ctx.r28.u64 + ctx.r31.u64;
	// bl 0x82067370
	ctx.lr = 0x82067284;
	sub_82067370(ctx, base);
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82067278
	if (!ctx.cr6.eq) goto loc_82067278;
loc_82067290:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// bl 0x820672b0
	ctx.lr = 0x8206729C;
	sub_820672B0(ctx, base);
	// stw r27,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r27.u32);
loc_820672A0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820672AC"))) PPC_WEAK_FUNC(sub_820672AC);
PPC_FUNC_IMPL(__imp__sub_820672AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820672B0"))) PPC_WEAK_FUNC(sub_820672B0);
PPC_FUNC_IMPL(__imp__sub_820672B0) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x820672e8
	if (ctx.cr6.eq) goto loc_820672E8;
loc_820672D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820673f8
	ctx.lr = 0x820672DC;
	sub_820673F8(ctx, base);
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820672d4
	if (!ctx.cr6.eq) goto loc_820672D4;
loc_820672E8:
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

__attribute__((alias("__imp__sub_82067300"))) PPC_WEAK_FUNC(sub_82067300);
PPC_FUNC_IMPL(__imp__sub_82067300) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82067354
	if (ctx.cr6.eq) goto loc_82067354;
	// li r11,-1
	ctx.r11.s64 = -1;
	// divwu r10,r11,r31
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r31.u32);
	// cmplwi cr6,r10,644
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 644, ctx.xer);
	// bge cr6,0x82067354
	if (!ctx.cr6.lt) goto loc_82067354;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1468
	ctx.r9.s64 = ctx.r11.s64 + -1468;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x82060018
	ctx.lr = 0x82067348;
	sub_82060018(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r7,r8,-1480
	ctx.r7.s64 = ctx.r8.s64 + -1480;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
loc_82067354:
	// mulli r3,r31,644
	ctx.r3.s64 = ctx.r31.s64 * 644;
	// bl 0x82079fd8
	ctx.lr = 0x8206735C;
	sub_82079FD8(ctx, base);
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

__attribute__((alias("__imp__sub_82067370"))) PPC_WEAK_FUNC(sub_82067370);
PPC_FUNC_IMPL(__imp__sub_82067370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x82067378;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r30,r4,40
	ctx.r30.s64 = ctx.r4.s64 + 40;
	// addi r31,r3,36
	ctx.r31.s64 = ctx.r3.s64 + 36;
	// subf r28,r3,r4
	ctx.r28.s64 = ctx.r4.s64 - ctx.r3.s64;
	// li r29,16
	ctx.r29.s64 = 16;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r26,-1
	ctx.r26.s64 = -1;
loc_8206739C:
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-36
	ctx.r4.s64 = ctx.r30.s64 + -36;
	// addi r3,r31,-32
	ctx.r3.s64 = ctx.r31.s64 + -32;
	// bl 0x820601f8
	ctx.lr = 0x820673B0;
	sub_820601F8(ctx, base);
	// lfs f0,-8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + -8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + -4, temp.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lfsx f13,r28,r31
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// lbz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// lbz r10,1(r30)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// stb r10,5(r31)
	PPC_STORE_U8(ctx.r31.u32 + 5, ctx.r10.u8);
	// lbz r9,2(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 2);
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// stb r9,6(r31)
	PPC_STORE_U8(ctx.r31.u32 + 6, ctx.r9.u8);
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// bne 0x8206739c
	if (!ctx.cr0.eq) goto loc_8206739C;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820673F4"))) PPC_WEAK_FUNC(sub_820673F4);
PPC_FUNC_IMPL(__imp__sub_820673F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820673F8"))) PPC_WEAK_FUNC(sub_820673F8);
PPC_FUNC_IMPL(__imp__sub_820673F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82067400;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,644
	ctx.r11.s64 = ctx.r3.s64 + 644;
	// li r28,15
	ctx.r28.s64 = 15;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82067418:
	// addi r31,r31,-40
	ctx.r31.s64 = ctx.r31.s64 + -40;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82067430
	if (ctx.cr6.lt) goto loc_82067430;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82067430;
	sub_8207A630(ctx, base);
loc_82067430:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x82067418
	if (!ctx.cr0.lt) goto loc_82067418;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206744C"))) PPC_WEAK_FUNC(sub_8206744C);
PPC_FUNC_IMPL(__imp__sub_8206744C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067450"))) PPC_WEAK_FUNC(sub_82067450);
PPC_FUNC_IMPL(__imp__sub_82067450) {
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
	// bl 0x821b1c30
	ctx.lr = 0x82067470;
	sub_821B1C30(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82067488
	if (ctx.cr6.eq) goto loc_82067488;
	// bl 0x8207a630
	ctx.lr = 0x82067484;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067488:
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

__attribute__((alias("__imp__sub_820674A0"))) PPC_WEAK_FUNC(sub_820674A0);
PPC_FUNC_IMPL(__imp__sub_820674A0) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,1744
	ctx.r10.s64 = ctx.r11.s64 + 1744;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x820674CC;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820674e4
	if (ctx.cr6.eq) goto loc_820674E4;
	// bl 0x8207a630
	ctx.lr = 0x820674E0;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820674E4:
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

__attribute__((alias("__imp__sub_820674FC"))) PPC_WEAK_FUNC(sub_820674FC);
PPC_FUNC_IMPL(__imp__sub_820674FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067500"))) PPC_WEAK_FUNC(sub_82067500);
PPC_FUNC_IMPL(__imp__sub_82067500) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,1840
	ctx.r10.s64 = ctx.r11.s64 + 1840;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x8206752C;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82067544
	if (ctx.cr6.eq) goto loc_82067544;
	// bl 0x8207a630
	ctx.lr = 0x82067540;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067544:
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

__attribute__((alias("__imp__sub_8206755C"))) PPC_WEAK_FUNC(sub_8206755C);
PPC_FUNC_IMPL(__imp__sub_8206755C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067560"))) PPC_WEAK_FUNC(sub_82067560);
PPC_FUNC_IMPL(__imp__sub_82067560) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82067568;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,1936
	ctx.r9.s64 = ctx.r11.s64 + 1936;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x82067594;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x820675AC;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820675cc
	if (ctx.cr6.eq) goto loc_820675CC;
	// bl 0x8207a630
	ctx.lr = 0x820675C8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820675CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820675D4"))) PPC_WEAK_FUNC(sub_820675D4);
PPC_FUNC_IMPL(__imp__sub_820675D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820675D8"))) PPC_WEAK_FUNC(sub_820675D8);
PPC_FUNC_IMPL(__imp__sub_820675D8) {
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
	// bl 0x821afae0
	ctx.lr = 0x820675F8;
	sub_821AFAE0(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82067610
	if (ctx.cr6.eq) goto loc_82067610;
	// bl 0x8207a630
	ctx.lr = 0x8206760C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067610:
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

__attribute__((alias("__imp__sub_82067628"))) PPC_WEAK_FUNC(sub_82067628);
PPC_FUNC_IMPL(__imp__sub_82067628) {
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
	// bl 0x821af960
	ctx.lr = 0x82067648;
	sub_821AF960(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82067660
	if (ctx.cr6.eq) goto loc_82067660;
	// bl 0x8207a630
	ctx.lr = 0x8206765C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067660:
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

__attribute__((alias("__imp__sub_82067678"))) PPC_WEAK_FUNC(sub_82067678);
PPC_FUNC_IMPL(__imp__sub_82067678) {
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
	// bl 0x821acc98
	ctx.lr = 0x82067698;
	sub_821ACC98(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820676b0
	if (ctx.cr6.eq) goto loc_820676B0;
	// bl 0x8207a630
	ctx.lr = 0x820676AC;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820676B0:
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

__attribute__((alias("__imp__sub_820676C8"))) PPC_WEAK_FUNC(sub_820676C8);
PPC_FUNC_IMPL(__imp__sub_820676C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x820676D0;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,4
	ctx.r31.s64 = ctx.r3.s64 + 4;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r24,15
	ctx.r24.s64 = 15;
	// subf r11,r3,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r3.s64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// subf r26,r4,r3
	ctx.r26.s64 = ctx.r3.s64 - ctx.r4.s64;
	// addi r30,r11,36
	ctx.r30.s64 = ctx.r11.s64 + 36;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r25,-1
	ctx.r25.s64 = -1;
loc_82067704:
	// stw r24,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r24.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r27,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r27.u8);
	// addi r4,r30,-36
	ctx.r4.s64 = ctx.r30.s64 + -36;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x82067724;
	sub_820601F8(ctx, base);
	// lwz r11,-8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -8);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// stw r10,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r10.u32);
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 0);
	// stbx r9,r26,r30
	PPC_STORE_U8(ctx.r26.u32 + ctx.r30.u32, ctx.r9.u8);
	// lbz r8,1(r30)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r30.u32 + 1);
	// stb r8,37(r31)
	PPC_STORE_U8(ctx.r31.u32 + 37, ctx.r8.u8);
	// lbz r7,2(r30)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r30.u32 + 2);
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// stb r7,38(r31)
	PPC_STORE_U8(ctx.r31.u32 + 38, ctx.r7.u8);
	// addi r31,r31,40
	ctx.r31.s64 = ctx.r31.s64 + 40;
	// bge 0x82067704
	if (!ctx.cr0.lt) goto loc_82067704;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82067768"))) PPC_WEAK_FUNC(sub_82067768);
PPC_FUNC_IMPL(__imp__sub_82067768) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,2152
	ctx.r10.s64 = ctx.r11.s64 + 2152;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82067794;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820677ac
	if (ctx.cr6.eq) goto loc_820677AC;
	// bl 0x8207a630
	ctx.lr = 0x820677A8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820677AC:
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

__attribute__((alias("__imp__sub_820677C4"))) PPC_WEAK_FUNC(sub_820677C4);
PPC_FUNC_IMPL(__imp__sub_820677C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820677C8"))) PPC_WEAK_FUNC(sub_820677C8);
PPC_FUNC_IMPL(__imp__sub_820677C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820677D0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,2132
	ctx.r9.s64 = ctx.r11.s64 + 2132;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x820677FC;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82067814;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82067834
	if (ctx.cr6.eq) goto loc_82067834;
	// bl 0x8207a630
	ctx.lr = 0x82067830;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067834:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206783C"))) PPC_WEAK_FUNC(sub_8206783C);
PPC_FUNC_IMPL(__imp__sub_8206783C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067840"))) PPC_WEAK_FUNC(sub_82067840);
PPC_FUNC_IMPL(__imp__sub_82067840) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,2248
	ctx.r10.s64 = ctx.r11.s64 + 2248;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x8206786C;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82067884
	if (ctx.cr6.eq) goto loc_82067884;
	// bl 0x8207a630
	ctx.lr = 0x82067880;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067884:
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

__attribute__((alias("__imp__sub_8206789C"))) PPC_WEAK_FUNC(sub_8206789C);
PPC_FUNC_IMPL(__imp__sub_8206789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820678A0"))) PPC_WEAK_FUNC(sub_820678A0);
PPC_FUNC_IMPL(__imp__sub_820678A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x820678A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r10,644
	ctx.r10.s64 = 644;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// subf r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	// li r29,0
	ctx.r29.s64 = 0;
	// divw r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x82067974
	if (ctx.cr6.gt) goto loc_82067974;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r11,-1264
	ctx.r4.s64 = ctx.r11.s64 + -1264;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82060368
	ctx.lr = 0x820678F8;
	sub_82060368(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060e58
	ctx.lr = 0x82067904;
	sub_82060E58(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,-12320(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12320);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82067924
	if (ctx.cr6.eq) goto loc_82067924;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82067924;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82067924:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82067938;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a0c0
	ctx.lr = 0x82067940;
	sub_8207A0C0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r8,r9,-1236
	ctx.r8.s64 = ctx.r9.s64 + -1236;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// bl 0x82060c50
	ctx.lr = 0x82067954;
	sub_82060C50(ctx, base);
	// lwz r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x82067968
	if (ctx.cr6.lt) goto loc_82067968;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82067968;
	sub_8207A630(ctx, base);
loc_82067968:
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
loc_82067974:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82067988
	if (!ctx.cr6.gt) goto loc_82067988;
	// twi 31,r0,22
loc_82067988:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82067af8
	ctx.lr = 0x820679A4;
	sub_82067AF8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820679d4
	if (!ctx.cr6.eq) goto loc_820679D4;
	// twi 31,r0,22
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_820679B8:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820679cc
	if (ctx.cr6.lt) goto loc_820679CC;
	// twi 31,r0,22
loc_820679CC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820679D4:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x820679b8
	goto loc_820679B8;
}

__attribute__((alias("__imp__sub_820679DC"))) PPC_WEAK_FUNC(sub_820679DC);
PPC_FUNC_IMPL(__imp__sub_820679DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820679E0"))) PPC_WEAK_FUNC(sub_820679E0);
PPC_FUNC_IMPL(__imp__sub_820679E0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r8,644
	ctx.r8.s64 = 644;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82067a10
	if (!ctx.cr6.eq) goto loc_82067A10;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82067a1c
	goto loc_82067A1C;
loc_82067A10:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r8
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r8.s32);
loc_82067A1C:
	// lwz r31,16(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r10,r11,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r10,r10,r8
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r8.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82067a4c
	if (!ctx.cr6.lt) goto loc_82067A4C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82067a40
	if (ctx.cr6.eq) goto loc_82067A40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067A40;
	sub_820676C8(ctx, base);
loc_82067A40:
	// addi r11,r31,644
	ctx.r11.s64 = ctx.r31.s64 + 644;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// b 0x82067ae0
	goto loc_82067AE0;
loc_82067A4C:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82067a58
	if (!ctx.cr6.gt) goto loc_82067A58;
	// twi 31,r0,22
loc_82067A58:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne cr6,0x82067a78
	if (!ctx.cr6.eq) goto loc_82067A78;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x82067aa0
	goto loc_82067AA0;
loc_82067A78:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82067a84
	if (!ctx.cr6.gt) goto loc_82067A84;
	// twi 31,r0,22
loc_82067A84:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82067a94
	if (ctx.cr6.eq) goto loc_82067A94;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82067a98
	if (ctx.cr6.eq) goto loc_82067A98;
loc_82067A94:
	// twi 31,r0,22
loc_82067A98:
	// subf r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r31,r11,r8
	ctx.r31.s32 = ppc_divw(ctx.r11.s32, ctx.r8.s32);
loc_82067AA0:
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82067b68
	ctx.lr = 0x82067AB0;
	sub_82067B68(ctx, base);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82067ac4
	if (!ctx.cr6.gt) goto loc_82067AC4;
	// twi 31,r0,22
loc_82067AC4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82067af8
	ctx.lr = 0x82067AE0;
	sub_82067AF8(ctx, base);
loc_82067AE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82067AF8"))) PPC_WEAK_FUNC(sub_82067AF8);
PPC_FUNC_IMPL(__imp__sub_82067AF8) {
	PPC_FUNC_PROLOGUE();
	// ld r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lwz r8,-16(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82067b3c
	if (!ctx.cr6.eq) goto loc_82067B3C;
	// twi 31,r0,22
	// li r9,0
	ctx.r9.s64 = 0;
loc_82067B14:
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// mulli r11,r5,644
	ctx.r11.s64 = ctx.r5.s64 * 644;
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x82067b54
	if (ctx.cr6.gt) goto loc_82067B54;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82067b44
	if (ctx.cr6.eq) goto loc_82067B44;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82067b48
	goto loc_82067B48;
loc_82067B3C:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82067b14
	goto loc_82067B14;
loc_82067B44:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82067B48:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82067b58
	if (!ctx.cr6.lt) goto loc_82067B58;
loc_82067B54:
	// twi 31,r0,22
loc_82067B58:
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// ld r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82067B68"))) PPC_WEAK_FUNC(sub_82067B68);
PPC_FUNC_IMPL(__imp__sub_82067B68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x82067B70;
	__savegprlr_23(ctx, base);
	// stwu r1,-1472(r1)
	ea = -1472 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// std r4,1496(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1496, ctx.r4.u64);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r23,644
	ctx.r23.s64 = 644;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82067b98
	if (!ctx.cr6.eq) goto loc_82067B98;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82067ba4
	goto loc_82067BA4;
loc_82067B98:
	// lwz r10,20(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r23
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r23.s32);
loc_82067BA4:
	// lwz r9,16(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// lis r10,101
	ctx.r10.s64 = 6619136;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// ori r10,r10,50067
	ctx.r10.u64 = ctx.r10.u64 | 50067;
	// divw r11,r7,r23
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r23.s32);
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x82067bd0
	if (!ctx.cr6.lt) goto loc_82067BD0;
	// bl 0x820686c0
	ctx.lr = 0x82067BC8;
	sub_820686C0(ctx, base);
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82067BD0:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82067cfc
	if (!ctx.cr6.lt) goto loc_82067CFC;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// li r24,0
	ctx.r24.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82067bf4
	if (ctx.cr6.lt) goto loc_82067BF4;
	// add r24,r11,r8
	ctx.r24.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_82067BF4:
	// cmplw cr6,r24,r7
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82067c00
	if (!ctx.cr6.lt) goto loc_82067C00;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
loc_82067C00:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82067300
	ctx.lr = 0x82067C08;
	sub_82067300(ctx, base);
	// lwz r11,12(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r30,1500(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1500);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// subf r10,r11,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r11.s64;
	// divw r26,r10,r23
	ctx.r26.s32 = ppc_divw(ctx.r10.s32, ctx.r23.s32);
	// mulli r25,r26,644
	ctx.r25.s64 = ctx.r26.s64 * 644;
	// add. r3,r25,r3
	ctx.r3.u64 = ctx.r25.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82067c30
	if (ctx.cr0.eq) goto loc_82067C30;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067C30;
	sub_820676C8(ctx, base);
loc_82067C30:
	// lwz r31,12(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82067c64
	if (ctx.cr6.eq) goto loc_82067C64;
loc_82067C40:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82067c54
	if (ctx.cr6.eq) goto loc_82067C54;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067C54;
	sub_820676C8(ctx, base);
loc_82067C54:
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// addi r29,r29,644
	ctx.r29.s64 = ctx.r29.s64 + 644;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82067c40
	if (!ctx.cr6.eq) goto loc_82067C40;
loc_82067C64:
	// addi r11,r26,1
	ctx.r11.s64 = ctx.r26.s64 + 1;
	// lwz r29,16(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// mulli r11,r11,644
	ctx.r11.s64 = ctx.r11.s64 * 644;
	// add r31,r11,r28
	ctx.r31.u64 = ctx.r11.u64 + ctx.r28.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82067cb0
	if (ctx.cr6.eq) goto loc_82067CB0;
	// subf r11,r25,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r25.s64;
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,-644
	ctx.r30.s64 = ctx.r11.s64 + -644;
loc_82067C8C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82067ca0
	if (ctx.cr6.eq) goto loc_82067CA0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067CA0;
	sub_820676C8(ctx, base);
loc_82067CA0:
	// addi r30,r30,644
	ctx.r30.s64 = ctx.r30.s64 + 644;
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82067c8c
	if (!ctx.cr6.eq) goto loc_82067C8C;
loc_82067CB0:
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// lwz r4,16(r27)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// divw r11,r11,r23
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x82067cd8
	if (ctx.cr6.eq) goto loc_82067CD8;
	// bl 0x820672b0
	ctx.lr = 0x82067CD0;
	sub_820672B0(ctx, base);
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x82067CD8;
	sub_8207A630(ctx, base);
loc_82067CD8:
	// mulli r10,r24,644
	ctx.r10.s64 = ctx.r24.s64 * 644;
	// stw r28,12(r27)
	PPC_STORE_U32(ctx.r27.u32 + 12, ctx.r28.u32);
	// mulli r11,r31,644
	ctx.r11.s64 = ctx.r31.s64 * 644;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r9,r11,r28
	ctx.r9.u64 = ctx.r11.u64 + ctx.r28.u64;
	// stw r10,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r10.u32);
	// stw r9,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r9.u32);
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82067CFC:
	// lwz r26,1500(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1500);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// subf r11,r26,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r26.s64;
	// divw r10,r11,r23
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bge cr6,0x82067dd0
	if (!ctx.cr6.lt) goto loc_82067DD0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820676c8
	ctx.lr = 0x82067D1C;
	sub_820676C8(ctx, base);
	// addi r31,r26,644
	ctx.r31.s64 = ctx.r26.s64 + 644;
	// lwz r29,16(r27)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// cmplw cr6,r26,r29
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82067d54
	if (ctx.cr6.eq) goto loc_82067D54;
	// addi r30,r31,-644
	ctx.r30.s64 = ctx.r31.s64 + -644;
loc_82067D30:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82067d44
	if (ctx.cr6.eq) goto loc_82067D44;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067D44;
	sub_820676C8(ctx, base);
loc_82067D44:
	// addi r30,r30,644
	ctx.r30.s64 = ctx.r30.s64 + 644;
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82067d30
	if (!ctx.cr6.eq) goto loc_82067D30;
loc_82067D54:
	// lwz r30,16(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// subf r11,r26,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r26.s64;
	// divw r10,r11,r23
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r23.s32);
	// subfic r31,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r31.s64 = 1 - ctx.r10.s64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82067d8c
	if (ctx.cr6.eq) goto loc_82067D8C;
loc_82067D6C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82067d80
	if (ctx.cr6.eq) goto loc_82067D80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067D80;
	sub_820676C8(ctx, base);
loc_82067D80:
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r30,r30,644
	ctx.r30.s64 = ctx.r30.s64 + 644;
	// bne 0x82067d6c
	if (!ctx.cr0.eq) goto loc_82067D6C;
loc_82067D8C:
	// lwz r11,16(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// addi r11,r11,644
	ctx.r11.s64 = ctx.r11.s64 + 644;
	// addi r30,r11,-644
	ctx.r30.s64 = ctx.r11.s64 + -644;
	// stw r11,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r11.u32);
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82067dc0
	if (ctx.cr6.eq) goto loc_82067DC0;
loc_82067DA8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067370
	ctx.lr = 0x82067DB4;
	sub_82067370(ctx, base);
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82067da8
	if (!ctx.cr6.eq) goto loc_82067DA8;
loc_82067DC0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820673f8
	ctx.lr = 0x82067DC8;
	sub_820673F8(ctx, base);
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
loc_82067DD0:
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x820676c8
	ctx.lr = 0x82067DD8;
	sub_820676C8(ctx, base);
	// lwz r28,16(r27)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + 16);
	// addi r31,r28,-644
	ctx.r31.s64 = ctx.r28.s64 + -644;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x82067e14
	if (ctx.cr6.eq) goto loc_82067E14;
loc_82067DF0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82067e04
	if (ctx.cr6.eq) goto loc_82067E04;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820676c8
	ctx.lr = 0x82067E04;
	sub_820676C8(ctx, base);
loc_82067E04:
	// addi r29,r29,644
	ctx.r29.s64 = ctx.r29.s64 + 644;
	// addi r30,r30,644
	ctx.r30.s64 = ctx.r30.s64 + 644;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82067df0
	if (!ctx.cr6.eq) goto loc_82067DF0;
loc_82067E14:
	// stw r30,16(r27)
	PPC_STORE_U32(ctx.r27.u32 + 16, ctx.r30.u32);
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82067e3c
	if (ctx.cr6.eq) goto loc_82067E3C;
	// subf r30,r31,r28
	ctx.r30.s64 = ctx.r28.s64 - ctx.r31.s64;
loc_82067E24:
	// addi r31,r31,-644
	ctx.r31.s64 = ctx.r31.s64 + -644;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r31,r30
	ctx.r3.u64 = ctx.r31.u64 + ctx.r30.u64;
	// bl 0x82067370
	ctx.lr = 0x82067E34;
	sub_82067370(ctx, base);
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x82067e24
	if (!ctx.cr6.eq) goto loc_82067E24;
loc_82067E3C:
	// addi r30,r26,644
	ctx.r30.s64 = ctx.r26.s64 + 644;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82067e64
	if (ctx.cr6.eq) goto loc_82067E64;
loc_82067E4C:
	// addi r4,r1,736
	ctx.r4.s64 = ctx.r1.s64 + 736;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82067370
	ctx.lr = 0x82067E58;
	sub_82067370(ctx, base);
	// addi r31,r31,644
	ctx.r31.s64 = ctx.r31.s64 + 644;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82067e4c
	if (!ctx.cr6.eq) goto loc_82067E4C;
loc_82067E64:
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x820673f8
	ctx.lr = 0x82067E6C;
	sub_820673F8(ctx, base);
	// addi r1,r1,1472
	ctx.r1.s64 = ctx.r1.s64 + 1472;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82067E74"))) PPC_WEAK_FUNC(sub_82067E74);
PPC_FUNC_IMPL(__imp__sub_82067E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067E78"))) PPC_WEAK_FUNC(sub_82067E78);
PPC_FUNC_IMPL(__imp__sub_82067E78) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,2344
	ctx.r10.s64 = ctx.r11.s64 + 2344;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b4b30
	ctx.lr = 0x82067EA4;
	sub_821B4B30(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82067ebc
	if (ctx.cr6.eq) goto loc_82067EBC;
	// bl 0x8207a630
	ctx.lr = 0x82067EB8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067EBC:
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

__attribute__((alias("__imp__sub_82067ED4"))) PPC_WEAK_FUNC(sub_82067ED4);
PPC_FUNC_IMPL(__imp__sub_82067ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067ED8"))) PPC_WEAK_FUNC(sub_82067ED8);
PPC_FUNC_IMPL(__imp__sub_82067ED8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82067EE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,2476
	ctx.r9.s64 = ctx.r11.s64 + 2476;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x82067F0C;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82067F24;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82067f44
	if (ctx.cr6.eq) goto loc_82067F44;
	// bl 0x8207a630
	ctx.lr = 0x82067F40;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067F44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82067F4C"))) PPC_WEAK_FUNC(sub_82067F4C);
PPC_FUNC_IMPL(__imp__sub_82067F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82067F50"))) PPC_WEAK_FUNC(sub_82067F50);
PPC_FUNC_IMPL(__imp__sub_82067F50) {
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
	// bl 0x821a9cc8
	ctx.lr = 0x82067F70;
	sub_821A9CC8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82067f88
	if (ctx.cr6.eq) goto loc_82067F88;
	// bl 0x8207a630
	ctx.lr = 0x82067F84;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82067F88:
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

__attribute__((alias("__imp__sub_82067FA0"))) PPC_WEAK_FUNC(sub_82067FA0);
PPC_FUNC_IMPL(__imp__sub_82067FA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82067FA8;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r10,24
	ctx.r10.s64 = 24;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// subf r8,r9,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r9.s64;
	// li r29,0
	ctx.r29.s64 = 0;
	// divw r7,r8,r10
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r10.s32);
	// cmplw cr6,r7,r4
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x82068074
	if (ctx.cr6.gt) goto loc_82068074;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r11,-1264
	ctx.r4.s64 = ctx.r11.s64 + -1264;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82060368
	ctx.lr = 0x82067FF8;
	sub_82060368(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060e58
	ctx.lr = 0x82068004;
	sub_82060E58(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,-12320(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12320);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82068024
	if (ctx.cr6.eq) goto loc_82068024;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82068024;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82068024:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82068038;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a0c0
	ctx.lr = 0x82068040;
	sub_8207A0C0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r8,r9,-1236
	ctx.r8.s64 = ctx.r9.s64 + -1236;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// bl 0x82060c50
	ctx.lr = 0x82068054;
	sub_82060C50(ctx, base);
	// lwz r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x82068068
	if (ctx.cr6.lt) goto loc_82068068;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82068068;
	sub_8207A630(ctx, base);
loc_82068068:
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
loc_82068074:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82068088
	if (!ctx.cr6.gt) goto loc_82068088;
	// twi 31,r0,22
loc_82068088:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x820682e0
	ctx.lr = 0x820680A4;
	sub_820682E0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x820680d4
	if (!ctx.cr6.eq) goto loc_820680D4;
	// twi 31,r0,22
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_820680B8:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x820680cc
	if (ctx.cr6.lt) goto loc_820680CC;
	// twi 31,r0,22
loc_820680CC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820680D4:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x820680b8
	goto loc_820680B8;
}

__attribute__((alias("__imp__sub_820680DC"))) PPC_WEAK_FUNC(sub_820680DC);
PPC_FUNC_IMPL(__imp__sub_820680DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820680E0"))) PPC_WEAK_FUNC(sub_820680E0);
PPC_FUNC_IMPL(__imp__sub_820680E0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r7,24
	ctx.r7.s64 = 24;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82068114
	if (!ctx.cr6.eq) goto loc_82068114;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x82068120
	goto loc_82068120;
loc_82068114:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r8,r9,r7
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r7.s32);
loc_82068120:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r9,r9,r7
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r7.s32);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82068160
	if (!ctx.cr6.lt) goto loc_82068160;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82068154
	if (ctx.cr6.eq) goto loc_82068154;
	// ld r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r5.u32 + 0);
	// ld r9,8(r5)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r5.u32 + 8);
	// ld r8,16(r5)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r5.u32 + 16);
	// std r10,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// std r9,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r9.u64);
	// std r8,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r8.u64);
loc_82068154:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// b 0x820681f0
	goto loc_820681F0;
loc_82068160:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206816c
	if (!ctx.cr6.gt) goto loc_8206816C;
	// twi 31,r0,22
loc_8206816C:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bne cr6,0x8206818c
	if (!ctx.cr6.eq) goto loc_8206818C;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x820681b4
	goto loc_820681B4;
loc_8206818C:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82068198
	if (!ctx.cr6.gt) goto loc_82068198;
	// twi 31,r0,22
loc_82068198:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820681a8
	if (ctx.cr6.eq) goto loc_820681A8;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x820681ac
	if (ctx.cr6.eq) goto loc_820681AC;
loc_820681A8:
	// twi 31,r0,22
loc_820681AC:
	// subf r11,r10,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r30,r11,r7
	ctx.r30.s32 = ppc_divw(ctx.r11.s32, ctx.r7.s32);
loc_820681B4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82068358
	ctx.lr = 0x820681C0;
	sub_82068358(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820681d4
	if (!ctx.cr6.gt) goto loc_820681D4;
	// twi 31,r0,22
loc_820681D4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x820682e0
	ctx.lr = 0x820681F0;
	sub_820682E0(ctx, base);
loc_820681F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82068208"))) PPC_WEAK_FUNC(sub_82068208);
PPC_FUNC_IMPL(__imp__sub_82068208) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// lwz r8,36(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 36);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8206823c
	if (ctx.cr6.eq) goto loc_8206823C;
	// lwz r11,12(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8206823c
	if (ctx.cr6.gt) goto loc_8206823C;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82068240
	if (!ctx.cr6.gt) goto loc_82068240;
loc_8206823C:
	// twi 31,r0,22
loc_82068240:
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,44(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 44);
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bgt cr6,0x82068268
	if (ctx.cr6.gt) goto loc_82068268;
	// lwz r9,16(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8206826c
	if (!ctx.cr6.gt) goto loc_8206826C;
loc_82068268:
	// twi 31,r0,22
loc_8206826C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82068278
	if (!ctx.cr6.eq) goto loc_82068278;
	// twi 31,r0,22
loc_82068278:
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// li r9,24
	ctx.r9.s64 = 24;
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// divw r9,r7,r9
	ctx.r9.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r9,r7
	ctx.r6.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r9,r6,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// beq cr6,0x820682d4
	if (ctx.cr6.eq) goto loc_820682D4;
	// subf r9,r11,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r11.s64;
loc_820682AC:
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stdx r8,r9,r11
	PPC_STORE_U64(ctx.r9.u32 + ctx.r11.u32, ctx.r8.u64);
	// ld r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// std r5,8(r6)
	PPC_STORE_U64(ctx.r6.u32 + 8, ctx.r5.u64);
	// ld r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// std r8,16(r6)
	PPC_STORE_U64(ctx.r6.u32 + 16, ctx.r8.u64);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x820682ac
	if (!ctx.cr6.eq) goto loc_820682AC;
loc_820682D4:
	// stw r7,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820682DC"))) PPC_WEAK_FUNC(sub_820682DC);
PPC_FUNC_IMPL(__imp__sub_820682DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820682E0"))) PPC_WEAK_FUNC(sub_820682E0);
PPC_FUNC_IMPL(__imp__sub_820682E0) {
	PPC_FUNC_PROLOGUE();
	// ld r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lwz r8,-16(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8206832c
	if (!ctx.cr6.eq) goto loc_8206832C;
	// twi 31,r0,22
	// li r9,0
	ctx.r9.s64 = 0;
loc_820682FC:
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r7,r5,r11
	ctx.r7.u64 = ctx.r5.u64 + ctx.r11.u64;
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x82068344
	if (ctx.cr6.gt) goto loc_82068344;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82068334
	if (ctx.cr6.eq) goto loc_82068334;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82068338
	goto loc_82068338;
loc_8206832C:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x820682fc
	goto loc_820682FC;
loc_82068334:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82068338:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82068348
	if (!ctx.cr6.lt) goto loc_82068348;
loc_82068344:
	// twi 31,r0,22
loc_82068348:
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// ld r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82068358"))) PPC_WEAK_FUNC(sub_82068358);
PPC_FUNC_IMPL(__imp__sub_82068358) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82068360;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// std r4,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r4.u64);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r30,24
	ctx.r30.s64 = 24;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068388
	if (!ctx.cr6.eq) goto loc_82068388;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82068394
	goto loc_82068394;
loc_82068388:
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r30
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
loc_82068394:
	// lwz r7,16(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lis r10,2730
	ctx.r10.s64 = 178913280;
	// subf r8,r11,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r11.s64;
	// ori r10,r10,43690
	ctx.r10.u64 = ctx.r10.u64 | 43690;
	// divw r11,r8,r30
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x820683c0
	if (!ctx.cr6.lt) goto loc_820683C0;
	// bl 0x820686c0
	ctx.lr = 0x820683B8;
	sub_820686C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_820683C0:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206852c
	if (!ctx.cr6.lt) goto loc_8206852C;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// li r28,0
	ctx.r28.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x820683e4
	if (ctx.cr6.lt) goto loc_820683E4;
	// add r28,r11,r9
	ctx.r28.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_820683E4:
	// cmplw cr6,r28,r8
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x820683f0
	if (!ctx.cr6.lt) goto loc_820683F0;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
loc_820683F0:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82068780
	ctx.lr = 0x820683F8;
	sub_82068780(ctx, base);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r9,156(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw r8,r10,r30
	ctx.r8.s32 = ppc_divw(ctx.r10.s32, ctx.r30.s32);
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add. r11,r7,r3
	ctx.r11.u64 = ctx.r7.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82068438
	if (ctx.cr0.eq) goto loc_82068438;
	// ld r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r27.u32 + 0);
	// ld r6,8(r27)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r27.u32 + 8);
	// ld r5,16(r27)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r27.u32 + 16);
	// std r10,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// std r6,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r6.u64);
	// std r5,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r5.u64);
loc_82068438:
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82068478
	if (ctx.cr6.eq) goto loc_82068478;
loc_82068448:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82068468
	if (ctx.cr6.eq) goto loc_82068468;
	// ld r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// std r6,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r6.u64);
	// ld r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// std r5,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r5.u64);
	// ld r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// std r4,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r4.u64);
loc_82068468:
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82068448
	if (!ctx.cr6.eq) goto loc_82068448;
loc_82068478:
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// lwz r8,16(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// beq cr6,0x820684d8
	if (ctx.cr6.eq) goto loc_820684D8;
	// subf r10,r7,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r7.s64;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,-24
	ctx.r10.s64 = ctx.r10.s64 + -24;
loc_820684A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x820684c8
	if (ctx.cr6.eq) goto loc_820684C8;
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r9,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// std r7,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r7.u64);
	// ld r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 16);
	// std r6,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r6.u64);
loc_820684C8:
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x820684a8
	if (!ctx.cr6.eq) goto loc_820684A8;
loc_820684D8:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// divw r11,r10,r30
	ctx.r11.s32 = ppc_divw(ctx.r10.s32, ctx.r30.s32);
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x820684f8
	if (ctx.cr6.eq) goto loc_820684F8;
	// bl 0x8207a630
	ctx.lr = 0x820684F8;
	sub_8207A630(ctx, base);
loc_820684F8:
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r31,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r31.u32);
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r30,r11
	ctx.r9.u64 = ctx.r30.u64 + ctx.r11.u64;
	// add r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 + ctx.r10.u64;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + ctx.r31.u64;
	// stw r7,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r7.u32);
	// stw r8,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r8.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206852C:
	// lwz r11,156(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// subf r10,r11,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw r9,r10,r30
	ctx.r9.s32 = ppc_divw(ctx.r10.s32, ctx.r30.s32);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bge cr6,0x82068608
	if (!ctx.cr6.lt) goto loc_82068608;
	// addi r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 24;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x82068580
	if (ctx.cr6.eq) goto loc_82068580;
	// addi r9,r10,-24
	ctx.r9.s64 = ctx.r10.s64 + -24;
loc_82068550:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82068570
	if (ctx.cr6.eq) goto loc_82068570;
	// ld r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// std r6,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r6.u64);
	// ld r5,16(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 16);
	// std r5,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r5.u64);
loc_82068570:
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x82068550
	if (!ctx.cr6.eq) goto loc_82068550;
loc_82068580:
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	// subfic r9,r8,1
	ctx.xer.ca = ctx.r8.u32 <= 1;
	ctx.r9.s64 = 1 - ctx.r8.s64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820685c4
	if (ctx.cr6.eq) goto loc_820685C4;
loc_82068598:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x820685b8
	if (ctx.cr6.eq) goto loc_820685B8;
	// ld r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r27.u32 + 0);
	// ld r7,8(r27)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r27.u32 + 8);
	// ld r6,16(r27)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r27.u32 + 16);
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// std r7,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r7.u64);
	// std r6,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r6.u64);
loc_820685B8:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// bne 0x82068598
	if (!ctx.cr0.eq) goto loc_82068598;
loc_820685C4:
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// addi r9,r10,-24
	ctx.r9.s64 = ctx.r10.s64 + -24;
	// stw r10,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r10.u32);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x820686b4
	if (ctx.cr6.eq) goto loc_820686B4;
loc_820685DC:
	// ld r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r27.u32 + 0);
	// ld r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r27.u32 + 8);
	// ld r7,16(r27)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r27.u32 + 16);
	// std r10,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// std r8,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r8.u64);
	// std r7,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r7.u64);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x820685dc
	if (!ctx.cr6.eq) goto loc_820685DC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82068608:
	// addi r10,r7,-24
	ctx.r10.s64 = ctx.r7.s64 + -24;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8206864c
	if (ctx.cr6.eq) goto loc_8206864C;
loc_8206861C:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206863c
	if (ctx.cr6.eq) goto loc_8206863C;
	// ld r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// std r6,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r6.u64);
	// ld r5,8(r8)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// std r5,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r5.u64);
	// ld r4,16(r8)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r8.u32 + 16);
	// std r4,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r4.u64);
loc_8206863C:
	// addi r8,r8,24
	ctx.r8.s64 = ctx.r8.s64 + 24;
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8206861c
	if (!ctx.cr6.eq) goto loc_8206861C;
loc_8206864C:
	// stw r9,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r9.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82068684
	if (ctx.cr6.eq) goto loc_82068684;
	// addi r9,r10,24
	ctx.r9.s64 = ctx.r10.s64 + 24;
loc_8206865C:
	// addi r10,r10,-24
	ctx.r10.s64 = ctx.r10.s64 + -24;
	// addi r9,r9,-24
	ctx.r9.s64 = ctx.r9.s64 + -24;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r8,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r8.u64);
	// ld r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// std r7,8(r9)
	PPC_STORE_U64(ctx.r9.u32 + 8, ctx.r7.u64);
	// ld r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r10.u32 + 16);
	// std r6,16(r9)
	PPC_STORE_U64(ctx.r9.u32 + 16, ctx.r6.u64);
	// bne cr6,0x8206865c
	if (!ctx.cr6.eq) goto loc_8206865C;
loc_82068684:
	// addi r10,r11,24
	ctx.r10.s64 = ctx.r11.s64 + 24;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x820686b4
	if (ctx.cr6.eq) goto loc_820686B4;
loc_82068690:
	// ld r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r27.u32 + 0);
	// ld r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r27.u32 + 8);
	// ld r7,16(r27)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r27.u32 + 16);
	// std r9,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r9.u64);
	// std r8,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r8.u64);
	// std r7,16(r11)
	PPC_STORE_U64(ctx.r11.u32 + 16, ctx.r7.u64);
	// addi r11,r11,24
	ctx.r11.s64 = ctx.r11.s64 + 24;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82068690
	if (!ctx.cr6.eq) goto loc_82068690;
loc_820686B4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820686BC"))) PPC_WEAK_FUNC(sub_820686BC);
PPC_FUNC_IMPL(__imp__sub_820686BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820686C0"))) PPC_WEAK_FUNC(sub_820686C0);
PPC_FUNC_IMPL(__imp__sub_820686C0) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// li r5,18
	ctx.r5.s64 = 18;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r11.u8);
	// addi r4,r9,-1312
	ctx.r4.s64 = ctx.r9.s64 + -1312;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x820686F8;
	sub_82060368(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060e58
	ctx.lr = 0x82068704;
	sub_82060E58(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,-12320(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12320);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82068724
	if (ctx.cr6.eq) goto loc_82068724;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82068724;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82068724:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82068738;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a0c0
	ctx.lr = 0x82068740;
	sub_8207A0C0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r8,r9,-1236
	ctx.r8.s64 = ctx.r9.s64 + -1236;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// bl 0x82060c50
	ctx.lr = 0x82068754;
	sub_82060C50(ctx, base);
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x82068768
	if (ctx.cr6.lt) goto loc_82068768;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x82068768;
	sub_8207A630(ctx, base);
loc_82068768:
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

__attribute__((alias("__imp__sub_8206877C"))) PPC_WEAK_FUNC(sub_8206877C);
PPC_FUNC_IMPL(__imp__sub_8206877C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82068780"))) PPC_WEAK_FUNC(sub_82068780);
PPC_FUNC_IMPL(__imp__sub_82068780) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x820687d4
	if (ctx.cr6.eq) goto loc_820687D4;
	// li r11,-1
	ctx.r11.s64 = -1;
	// divwu r10,r11,r31
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r31.u32);
	// cmplwi cr6,r10,24
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 24, ctx.xer);
	// bge cr6,0x820687d4
	if (!ctx.cr6.lt) goto loc_820687D4;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1468
	ctx.r9.s64 = ctx.r11.s64 + -1468;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x82060018
	ctx.lr = 0x820687C8;
	sub_82060018(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r7,r8,-1480
	ctx.r7.s64 = ctx.r8.s64 + -1480;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
loc_820687D4:
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82079fd8
	ctx.lr = 0x820687E4;
	sub_82079FD8(ctx, base);
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

__attribute__((alias("__imp__sub_820687F8"))) PPC_WEAK_FUNC(sub_820687F8);
PPC_FUNC_IMPL(__imp__sub_820687F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82068808"))) PPC_WEAK_FUNC(sub_82068808);
PPC_FUNC_IMPL(__imp__sub_82068808) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82068818"))) PPC_WEAK_FUNC(sub_82068818);
PPC_FUNC_IMPL(__imp__sub_82068818) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82068828"))) PPC_WEAK_FUNC(sub_82068828);
PPC_FUNC_IMPL(__imp__sub_82068828) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82068838"))) PPC_WEAK_FUNC(sub_82068838);
PPC_FUNC_IMPL(__imp__sub_82068838) {
	PPC_FUNC_PROLOGUE();
	// lwz r12,0(r3)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,128(r12)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r12.u32 + 128);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82068848"))) PPC_WEAK_FUNC(sub_82068848);
PPC_FUNC_IMPL(__imp__sub_82068848) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,1424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1424, ctx.r9.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82068888;
	sub_821B5C28(ctx, base);
	// clrlwi r6,r30,31
	ctx.r6.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x820688a0
	if (ctx.cr6.eq) goto loc_820688A0;
	// bl 0x8207a630
	ctx.lr = 0x8206889C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820688A0:
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

__attribute__((alias("__imp__sub_820688B8"))) PPC_WEAK_FUNC(sub_820688B8);
PPC_FUNC_IMPL(__imp__sub_820688B8) {
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
	// addi r31,r3,4
	ctx.r31.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x820688e0
	if (ctx.cr6.lt) goto loc_820688E0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x820688E0;
	sub_8207A630(ctx, base);
loc_820688E0:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
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

__attribute__((alias("__imp__sub_82068908"))) PPC_WEAK_FUNC(sub_82068908);
PPC_FUNC_IMPL(__imp__sub_82068908) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,2624
	ctx.r8.s64 = ctx.r10.s64 + 2624;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,1424(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1424, ctx.r9.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82068948;
	sub_821B5C28(ctx, base);
	// clrlwi r6,r30,31
	ctx.r6.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82068960
	if (ctx.cr6.eq) goto loc_82068960;
	// bl 0x8207a630
	ctx.lr = 0x8206895C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82068960:
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

__attribute__((alias("__imp__sub_82068978"))) PPC_WEAK_FUNC(sub_82068978);
PPC_FUNC_IMPL(__imp__sub_82068978) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,3008
	ctx.r10.s64 = ctx.r11.s64 + 3008;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x820689A4;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820689bc
	if (ctx.cr6.eq) goto loc_820689BC;
	// bl 0x8207a630
	ctx.lr = 0x820689B8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820689BC:
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

__attribute__((alias("__imp__sub_820689D4"))) PPC_WEAK_FUNC(sub_820689D4);
PPC_FUNC_IMPL(__imp__sub_820689D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820689D8"))) PPC_WEAK_FUNC(sub_820689D8);
PPC_FUNC_IMPL(__imp__sub_820689D8) {
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
	// lwz r10,364(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// rlwinm r9,r10,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r7,r8,3104
	ctx.r7.s64 = ctx.r8.s64 + 3104;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r6,1548(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1548, ctx.r6.u32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stw r5,1424(r11)
	PPC_STORE_U32(ctx.r11.u32 + 1424, ctx.r5.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82068A30;
	sub_821B5C28(ctx, base);
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82068a48
	if (ctx.cr6.eq) goto loc_82068A48;
	// bl 0x8207a630
	ctx.lr = 0x82068A44;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82068A48:
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

__attribute__((alias("__imp__sub_82068A60"))) PPC_WEAK_FUNC(sub_82068A60);
PPC_FUNC_IMPL(__imp__sub_82068A60) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,2720
	ctx.r10.s64 = ctx.r11.s64 + 2720;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82068A8C;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82068aa4
	if (ctx.cr6.eq) goto loc_82068AA4;
	// bl 0x8207a630
	ctx.lr = 0x82068AA0;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82068AA4:
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

__attribute__((alias("__imp__sub_82068ABC"))) PPC_WEAK_FUNC(sub_82068ABC);
PPC_FUNC_IMPL(__imp__sub_82068ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82068AC0"))) PPC_WEAK_FUNC(sub_82068AC0);
PPC_FUNC_IMPL(__imp__sub_82068AC0) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,2816
	ctx.r10.s64 = ctx.r11.s64 + 2816;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82068AEC;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82068b04
	if (ctx.cr6.eq) goto loc_82068B04;
	// bl 0x8207a630
	ctx.lr = 0x82068B00;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82068B04:
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

__attribute__((alias("__imp__sub_82068B1C"))) PPC_WEAK_FUNC(sub_82068B1C);
PPC_FUNC_IMPL(__imp__sub_82068B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82068B20"))) PPC_WEAK_FUNC(sub_82068B20);
PPC_FUNC_IMPL(__imp__sub_82068B20) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,2912
	ctx.r10.s64 = ctx.r11.s64 + 2912;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82068B4C;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82068b64
	if (ctx.cr6.eq) goto loc_82068B64;
	// bl 0x8207a630
	ctx.lr = 0x82068B60;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82068B64:
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

__attribute__((alias("__imp__sub_82068B7C"))) PPC_WEAK_FUNC(sub_82068B7C);
PPC_FUNC_IMPL(__imp__sub_82068B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82068B80"))) PPC_WEAK_FUNC(sub_82068B80);
PPC_FUNC_IMPL(__imp__sub_82068B80) {
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
	// bl 0x8219e3d0
	ctx.lr = 0x82068BA0;
	sub_8219E3D0(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82068bb8
	if (ctx.cr6.eq) goto loc_82068BB8;
	// bl 0x8207a630
	ctx.lr = 0x82068BB4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82068BB8:
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

__attribute__((alias("__imp__sub_82068BD0"))) PPC_WEAK_FUNC(sub_82068BD0);
PPC_FUNC_IMPL(__imp__sub_82068BD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82068BD8;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r8,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 5;
	// cmplw cr6,r8,r4
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x82068ca0
	if (ctx.cr6.gt) goto loc_82068CA0;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// li r5,27
	ctx.r5.s64 = 27;
	// addi r4,r11,-1264
	ctx.r4.s64 = ctx.r11.s64 + -1264;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82060368
	ctx.lr = 0x82068C24;
	sub_82060368(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060e58
	ctx.lr = 0x82068C30;
	sub_82060E58(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,-12320(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -12320);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82068c50
	if (ctx.cr6.eq) goto loc_82068C50;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82068C50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82068C50:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82068C64;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a0c0
	ctx.lr = 0x82068C6C;
	sub_8207A0C0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r8,r9,-1236
	ctx.r8.s64 = ctx.r9.s64 + -1236;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// bl 0x82060c50
	ctx.lr = 0x82068C80;
	sub_82060C50(ctx, base);
	// lwz r7,120(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r7,16
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 16, ctx.xer);
	// blt cr6,0x82068c94
	if (ctx.cr6.lt) goto loc_82068C94;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x82068C94;
	sub_8207A630(ctx, base);
loc_82068C94:
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// stb r29,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r29.u8);
loc_82068CA0:
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82068cb4
	if (!ctx.cr6.gt) goto loc_82068CB4;
	// twi 31,r0,22
loc_82068CB4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82068e48
	ctx.lr = 0x82068CD0;
	sub_82068E48(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068d00
	if (!ctx.cr6.eq) goto loc_82068D00;
	// twi 31,r0,22
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82068CE4:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82068cf8
	if (ctx.cr6.lt) goto loc_82068CF8;
	// twi 31,r0,22
loc_82068CF8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82068D00:
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82068ce4
	goto loc_82068CE4;
}

__attribute__((alias("__imp__sub_82068D08"))) PPC_WEAK_FUNC(sub_82068D08);
PPC_FUNC_IMPL(__imp__sub_82068D08) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82068d3c
	if (!ctx.cr6.eq) goto loc_82068D3C;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// b 0x82068d48
	goto loc_82068D48;
loc_82068D3C:
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r9,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 5;
loc_82068D48:
	// lwz r31,16(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r11,r10,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r10.s64;
	// srawi r11,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 5;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82068d9c
	if (!ctx.cr6.lt) goto loc_82068D9C;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82068d90
	if (ctx.cr6.eq) goto loc_82068D90;
	// lwz r11,0(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r4,r5,4
	ctx.r4.s64 = ctx.r5.s64 + 4;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r8.u32);
	// stb r8,8(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8, ctx.r8.u8);
	// bl 0x820601f8
	ctx.lr = 0x82068D90;
	sub_820601F8(ctx, base);
loc_82068D90:
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// b 0x82068e2c
	goto loc_82068E2C;
loc_82068D9C:
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82068da8
	if (!ctx.cr6.gt) goto loc_82068DA8;
	// twi 31,r0,22
loc_82068DA8:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne cr6,0x82068dc8
	if (!ctx.cr6.eq) goto loc_82068DC8;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
	// b 0x82068df0
	goto loc_82068DF0;
loc_82068DC8:
	// cmplw cr6,r10,r31
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x82068dd4
	if (!ctx.cr6.gt) goto loc_82068DD4;
	// twi 31,r0,22
loc_82068DD4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82068de4
	if (ctx.cr6.eq) goto loc_82068DE4;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82068de8
	if (ctx.cr6.eq) goto loc_82068DE8;
loc_82068DE4:
	// twi 31,r0,22
loc_82068DE8:
	// subf r11,r10,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r10.s64;
	// srawi r31,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r31.s64 = ctx.r11.s32 >> 5;
loc_82068DF0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x82068eb8
	ctx.lr = 0x82068DFC;
	sub_82068EB8(ctx, base);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82068e10
	if (!ctx.cr6.gt) goto loc_82068E10;
	// twi 31,r0,22
loc_82068E10:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82068e48
	ctx.lr = 0x82068E2C;
	sub_82068E48(ctx, base);
loc_82068E2C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82068E44"))) PPC_WEAK_FUNC(sub_82068E44);
PPC_FUNC_IMPL(__imp__sub_82068E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82068E48"))) PPC_WEAK_FUNC(sub_82068E48);
PPC_FUNC_IMPL(__imp__sub_82068E48) {
	PPC_FUNC_PROLOGUE();
	// ld r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lwz r8,-16(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x82068e8c
	if (!ctx.cr6.eq) goto loc_82068E8C;
	// twi 31,r0,22
	// li r9,0
	ctx.r9.s64 = 0;
loc_82068E64:
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// rlwinm r11,r5,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x82068ea4
	if (ctx.cr6.gt) goto loc_82068EA4;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82068e94
	if (ctx.cr6.eq) goto loc_82068E94;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82068e98
	goto loc_82068E98;
loc_82068E8C:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82068e64
	goto loc_82068E64;
loc_82068E94:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82068E98:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82068ea8
	if (!ctx.cr6.lt) goto loc_82068EA8;
loc_82068EA4:
	// twi 31,r0,22
loc_82068EA8:
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// ld r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82068EB8"))) PPC_WEAK_FUNC(sub_82068EB8);
PPC_FUNC_IMPL(__imp__sub_82068EB8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x82068EC0;
	__savegprlr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r4,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r4.u64);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82068ee4
	if (!ctx.cr6.eq) goto loc_82068EE4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82068ef0
	goto loc_82068EF0;
loc_82068EE4:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r9,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 5;
loc_82068EF0:
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,2047
	ctx.r10.s64 = 134152192;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// srawi r11,r7,5
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 5;
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x82068f1c
	if (!ctx.cr6.lt) goto loc_82068F1C;
	// bl 0x820686c0
	ctx.lr = 0x82068F14;
	sub_820686C0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82068F1C:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82068ff0
	if (!ctx.cr6.lt) goto loc_82068FF0;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// li r27,0
	ctx.r27.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82068f40
	if (ctx.cr6.lt) goto loc_82068F40;
	// add r27,r11,r9
	ctx.r27.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_82068F40:
	// cmplw cr6,r27,r7
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x82068f4c
	if (!ctx.cr6.lt) goto loc_82068F4C;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
loc_82068F4C:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82069128
	ctx.lr = 0x82068F54;
	sub_82069128(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,220(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// subf r10,r11,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r11.s64;
	// li r4,1
	ctx.r4.s64 = 1;
	// srawi r28,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r28.s64 = ctx.r10.s32 >> 5;
	// rlwinm r11,r28,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bl 0x82069478
	ctx.lr = 0x82068F7C;
	sub_82069478(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x820691e8
	ctx.lr = 0x82068F8C;
	sub_820691E8(ctx, base);
	// addi r9,r28,1
	ctx.r9.s64 = ctx.r28.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// rlwinm r11,r9,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x820691e8
	ctx.lr = 0x82068FA4;
	sub_820691E8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r8,r3,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r3.s64;
	// srawi r11,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 5;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x82068fcc
	if (ctx.cr6.eq) goto loc_82068FCC;
	// bl 0x820694f8
	ctx.lr = 0x82068FC4;
	sub_820694F8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x82068FCC;
	sub_8207A630(ctx, base);
loc_82068FCC:
	// rlwinm r10,r27,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// rlwinm r11,r29,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_82068FF0:
	// lwz r30,220(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// subf r11,r30,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r30.s64;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bge cr6,0x8206908c
	if (!ctx.cr6.lt) goto loc_8206908C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82069558
	ctx.lr = 0x82069010;
	sub_82069558(ctx, base);
	// addi r5,r30,32
	ctx.r5.s64 = ctx.r30.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x820691e8
	ctx.lr = 0x82069020;
	sub_820691E8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// subf r11,r30,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r30.s64;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// subfic r4,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r4.s64 = 1 - ctx.r10.s64;
	// bl 0x82069478
	ctx.lr = 0x82069038;
	sub_82069478(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r29,r11,-32
	ctx.r29.s64 = ctx.r11.s64 + -32;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8206907c
	if (ctx.cr6.eq) goto loc_8206907C;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_82069054:
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r30,4
	ctx.r3.s64 = ctx.r30.s64 + 4;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x820601f8
	ctx.lr = 0x82069070;
	sub_820601F8(ctx, base);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82069054
	if (!ctx.cr6.eq) goto loc_82069054;
loc_8206907C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820688b8
	ctx.lr = 0x82069084;
	sub_820688B8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206908C:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82069558
	ctx.lr = 0x82069094;
	sub_82069558(ctx, base);
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r29,r5,-32
	ctx.r29.s64 = ctx.r5.s64 + -32;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x820691e8
	ctx.lr = 0x820690A8;
	sub_820691E8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// li r28,-1
	ctx.r28.s64 = -1;
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x820690e0
	if (ctx.cr6.eq) goto loc_820690E0;
loc_820690BC:
	// lwzu r11,-32(r31)
	ea = -32 + ctx.r31.u32;
	ctx.r11.u64 = PPC_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
	// addi r3,r31,36
	ctx.r3.s64 = ctx.r31.s64 + 36;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// bl 0x820601f8
	ctx.lr = 0x820690D8;
	sub_820601F8(ctx, base);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x820690bc
	if (!ctx.cr6.eq) goto loc_820690BC;
loc_820690E0:
	// addi r29,r30,32
	ctx.r29.s64 = ctx.r30.s64 + 32;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x82069118
	if (ctx.cr6.eq) goto loc_82069118;
loc_820690F0:
	// lwz r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// stw r11,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x820601f8
	ctx.lr = 0x8206910C;
	sub_820601F8(ctx, base);
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x820690f0
	if (!ctx.cr6.eq) goto loc_820690F0;
loc_82069118:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820688b8
	ctx.lr = 0x82069120;
	sub_820688B8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82069128"))) PPC_WEAK_FUNC(sub_82069128);
PPC_FUNC_IMPL(__imp__sub_82069128) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206917c
	if (ctx.cr6.eq) goto loc_8206917C;
	// li r11,-1
	ctx.r11.s64 = -1;
	// divwu r10,r11,r31
	ctx.r10.u32 = ppc_divwu(ctx.r11.u32, ctx.r31.u32);
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bge cr6,0x8206917c
	if (!ctx.cr6.lt) goto loc_8206917C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-1468
	ctx.r9.s64 = ctx.r11.s64 + -1468;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x82060018
	ctx.lr = 0x82069170;
	sub_82060018(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r7,r8,-1480
	ctx.r7.s64 = ctx.r8.s64 + -1480;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
loc_8206917C:
	// rlwinm r3,r31,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82079fd8
	ctx.lr = 0x82069184;
	sub_82079FD8(ctx, base);
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

__attribute__((alias("__imp__sub_82069198"))) PPC_WEAK_FUNC(sub_82069198);
PPC_FUNC_IMPL(__imp__sub_82069198) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207aba0
	ctx.lr = 0x820691D8;
	sub_8207ABA0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_820691E8"))) PPC_WEAK_FUNC(sub_820691E8);
PPC_FUNC_IMPL(__imp__sub_820691E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x820691F0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8206925c
	if (ctx.cr6.eq) goto loc_8206925C;
	// addi r31,r5,8
	ctx.r31.s64 = ctx.r5.s64 + 8;
	// subf r29,r5,r3
	ctx.r29.s64 = ctx.r3.s64 - ctx.r5.s64;
	// li r26,15
	ctx.r26.s64 = 15;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r27,-1
	ctx.r27.s64 = -1;
loc_82069218:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82069248
	if (ctx.cr6.eq) goto loc_82069248;
	// lwzx r11,r29,r30
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r30.u32);
	// addi r3,r31,-4
	ctx.r3.s64 = ctx.r31.s64 + -4;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r4,r3,r29
	ctx.r4.u64 = ctx.r3.u64 + ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// bl 0x820601f8
	ctx.lr = 0x82069248;
	sub_820601F8(ctx, base);
loc_82069248:
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// add r11,r29,r30
	ctx.r11.u64 = ctx.r29.u64 + ctx.r30.u64;
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x82069218
	if (!ctx.cr6.eq) goto loc_82069218;
loc_8206925C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82069268"))) PPC_WEAK_FUNC(sub_82069268);
PPC_FUNC_IMPL(__imp__sub_82069268) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,3304
	ctx.r10.s64 = ctx.r11.s64 + 3304;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x82069294;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820692ac
	if (ctx.cr6.eq) goto loc_820692AC;
	// bl 0x8207a630
	ctx.lr = 0x820692A8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820692AC:
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

__attribute__((alias("__imp__sub_820692C4"))) PPC_WEAK_FUNC(sub_820692C4);
PPC_FUNC_IMPL(__imp__sub_820692C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820692C8"))) PPC_WEAK_FUNC(sub_820692C8);
PPC_FUNC_IMPL(__imp__sub_820692C8) {
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
	// bl 0x8219ae10
	ctx.lr = 0x820692E8;
	sub_8219AE10(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069300
	if (ctx.cr6.eq) goto loc_82069300;
	// bl 0x8207a630
	ctx.lr = 0x820692FC;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069300:
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

__attribute__((alias("__imp__sub_82069318"))) PPC_WEAK_FUNC(sub_82069318);
PPC_FUNC_IMPL(__imp__sub_82069318) {
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
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206933c
	if (!ctx.cr6.gt) goto loc_8206933C;
	// twi 31,r0,22
loc_8206933C:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x82069354
	if (!ctx.cr6.gt) goto loc_82069354;
	// twi 31,r0,22
loc_82069354:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82069380
	ctx.lr = 0x8206936C;
	sub_82069380(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206937C"))) PPC_WEAK_FUNC(sub_8206937C);
PPC_FUNC_IMPL(__imp__sub_8206937C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069380"))) PPC_WEAK_FUNC(sub_82069380);
PPC_FUNC_IMPL(__imp__sub_82069380) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82069388;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// std r5,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// std r6,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r6.u64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x820693c8
	if (ctx.cr6.eq) goto loc_820693C8;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x820693c8
	if (ctx.cr6.gt) goto loc_820693C8;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x820693cc
	if (!ctx.cr6.gt) goto loc_820693CC;
loc_820693C8:
	// twi 31,r0,22
loc_820693CC:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r31,188(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// stw r11,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r11.u32);
	// cmplw cr6,r9,r31
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r31.u32, ctx.xer);
	// stw r10,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r10.u32);
	// bgt cr6,0x820693f4
	if (ctx.cr6.gt) goto loc_820693F4;
	// lwz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x820693f8
	if (!ctx.cr6.gt) goto loc_820693F8;
loc_820693F4:
	// twi 31,r0,22
loc_820693F8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82069404
	if (!ctx.cr6.eq) goto loc_82069404;
	// twi 31,r0,22
loc_82069404:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82069468
	if (ctx.cr6.eq) goto loc_82069468;
	// lwz r30,16(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r10,r31,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r31.s64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// srawi r9,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 5;
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r26,r10,r11
	ctx.r26.u64 = ctx.r10.u64 + ctx.r11.u64;
	// beq cr6,0x82069458
	if (ctx.cr6.eq) goto loc_82069458;
	// subf r29,r31,r11
	ctx.r29.s64 = ctx.r11.s64 - ctx.r31.s64;
	// li r27,-1
	ctx.r27.s64 = -1;
loc_82069430:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r3,r29,r4
	ctx.r3.u64 = ctx.r29.u64 + ctx.r4.u64;
	// stwx r11,r29,r31
	PPC_STORE_U32(ctx.r29.u32 + ctx.r31.u32, ctx.r11.u32);
	// bl 0x820601f8
	ctx.lr = 0x8206944C;
	sub_820601F8(ctx, base);
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82069430
	if (!ctx.cr6.eq) goto loc_82069430;
loc_82069458:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// bl 0x820694f8
	ctx.lr = 0x82069464;
	sub_820694F8(ctx, base);
	// stw r26,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r26.u32);
loc_82069468:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82069474"))) PPC_WEAK_FUNC(sub_82069474);
PPC_FUNC_IMPL(__imp__sub_82069474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069478"))) PPC_WEAK_FUNC(sub_82069478);
PPC_FUNC_IMPL(__imp__sub_82069478) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x82069480;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x820694e8
	if (ctx.cr6.eq) goto loc_820694E8;
	// addi r31,r3,8
	ctx.r31.s64 = ctx.r3.s64 + 8;
	// li r27,15
	ctx.r27.s64 = 15;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_820694AC:
	// addic. r11,r31,-8
	ctx.xer.ca = ctx.r31.u32 > 7;
	ctx.r11.s64 = ctx.r31.s64 + -8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x820694dc
	if (ctx.cr0.eq) goto loc_820694DC;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,-4
	ctx.r3.s64 = ctx.r31.s64 + -4;
	// stw r11,-8(r31)
	PPC_STORE_U32(ctx.r31.u32 + -8, ctx.r11.u32);
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stb r30,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r30.u8);
	// bl 0x820601f8
	ctx.lr = 0x820694DC;
	sub_820601F8(ctx, base);
loc_820694DC:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// bne 0x820694ac
	if (!ctx.cr0.eq) goto loc_820694AC;
loc_820694E8:
	// rlwinm r11,r25,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r24
	ctx.r3.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820694F8"))) PPC_WEAK_FUNC(sub_820694F8);
PPC_FUNC_IMPL(__imp__sub_820694F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82069500;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8206954c
	if (ctx.cr6.eq) goto loc_8206954C;
	// addi r31,r3,8
	ctx.r31.s64 = ctx.r3.s64 + 8;
	// li r28,15
	ctx.r28.s64 = 15;
	// li r30,0
	ctx.r30.s64 = 0;
loc_8206951C:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82069530
	if (ctx.cr6.lt) goto loc_82069530;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82069530;
	sub_8207A630(ctx, base);
loc_82069530:
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stb r30,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r30.u8);
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// addi r11,r31,-8
	ctx.r11.s64 = ctx.r31.s64 + -8;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8206951c
	if (!ctx.cr6.eq) goto loc_8206951C;
loc_8206954C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82069554"))) PPC_WEAK_FUNC(sub_82069554);
PPC_FUNC_IMPL(__imp__sub_82069554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069558"))) PPC_WEAK_FUNC(sub_82069558);
PPC_FUNC_IMPL(__imp__sub_82069558) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r9,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stb r11,8(r31)
	PPC_STORE_U8(ctx.r31.u32 + 8, ctx.r11.u8);
	// bl 0x820601f8
	ctx.lr = 0x8206959C;
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

__attribute__((alias("__imp__sub_820695B4"))) PPC_WEAK_FUNC(sub_820695B4);
PPC_FUNC_IMPL(__imp__sub_820695B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820695B8"))) PPC_WEAK_FUNC(sub_820695B8);
PPC_FUNC_IMPL(__imp__sub_820695B8) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,3504
	ctx.r10.s64 = ctx.r11.s64 + 3504;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x820695E4;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820695fc
	if (ctx.cr6.eq) goto loc_820695FC;
	// bl 0x8207a630
	ctx.lr = 0x820695F8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820695FC:
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

__attribute__((alias("__imp__sub_82069614"))) PPC_WEAK_FUNC(sub_82069614);
PPC_FUNC_IMPL(__imp__sub_82069614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069618"))) PPC_WEAK_FUNC(sub_82069618);
PPC_FUNC_IMPL(__imp__sub_82069618) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82069620;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,3600
	ctx.r9.s64 = ctx.r11.s64 + 3600;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x8206964C;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82069664;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82069684
	if (ctx.cr6.eq) goto loc_82069684;
	// bl 0x8207a630
	ctx.lr = 0x82069680;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069684:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206968C"))) PPC_WEAK_FUNC(sub_8206968C);
PPC_FUNC_IMPL(__imp__sub_8206968C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069690"))) PPC_WEAK_FUNC(sub_82069690);
PPC_FUNC_IMPL(__imp__sub_82069690) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r11,3840
	ctx.r10.s64 = ctx.r11.s64 + 3840;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x821b5c28
	ctx.lr = 0x820696BC;
	sub_821B5C28(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x820696d4
	if (ctx.cr6.eq) goto loc_820696D4;
	// bl 0x8207a630
	ctx.lr = 0x820696D0;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820696D4:
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

__attribute__((alias("__imp__sub_820696EC"))) PPC_WEAK_FUNC(sub_820696EC);
PPC_FUNC_IMPL(__imp__sub_820696EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820696F0"))) PPC_WEAK_FUNC(sub_820696F0);
PPC_FUNC_IMPL(__imp__sub_820696F0) {
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
	// bl 0x82195070
	ctx.lr = 0x82069710;
	sub_82195070(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069728
	if (ctx.cr6.eq) goto loc_82069728;
	// bl 0x8207a630
	ctx.lr = 0x82069724;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069728:
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

__attribute__((alias("__imp__sub_82069740"))) PPC_WEAK_FUNC(sub_82069740);
PPC_FUNC_IMPL(__imp__sub_82069740) {
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
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82069764
	if (!ctx.cr6.eq) goto loc_82069764;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82069770
	goto loc_82069770;
loc_82069764:
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_82069770:
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x820697a4
	if (!ctx.cr6.lt) goto loc_820697A4;
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_820697A4:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x820697b0
	if (!ctx.cr6.gt) goto loc_820697B0;
	// twi 31,r0,22
loc_820697B0:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x820697e0
	ctx.lr = 0x820697CC;
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

__attribute__((alias("__imp__sub_820697DC"))) PPC_WEAK_FUNC(sub_820697DC);
PPC_FUNC_IMPL(__imp__sub_820697DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820697E0"))) PPC_WEAK_FUNC(sub_820697E0);
PPC_FUNC_IMPL(__imp__sub_820697E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x820697E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// std r5,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r5.u64);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r9,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8206981c
	if (!ctx.cr6.eq) goto loc_8206981C;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82069850
	goto loc_82069850;
loc_8206981C:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82069828
	if (!ctx.cr6.gt) goto loc_82069828;
	// twi 31,r0,22
loc_82069828:
	// lwz r9,160(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82069840
	if (ctx.cr6.eq) goto loc_82069840;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82069844
	if (ctx.cr6.eq) goto loc_82069844;
loc_82069840:
	// twi 31,r0,22
loc_82069844:
	// lwz r11,164(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// subf r10,r10,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r30,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r10.s32 >> 2;
loc_82069850:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820717a0
	ctx.lr = 0x8206985C;
	sub_820717A0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82069870
	if (!ctx.cr6.gt) goto loc_82069870;
	// twi 31,r0,22
loc_82069870:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// bne cr6,0x820698b8
	if (!ctx.cr6.eq) goto loc_820698B8;
	// twi 31,r0,22
	// li r9,0
	ctx.r9.s64 = 0;
loc_82069894:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x820698d0
	if (ctx.cr6.gt) goto loc_820698D0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x820698c0
	if (ctx.cr6.eq) goto loc_820698C0;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x820698c4
	goto loc_820698C4;
loc_820698B8:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x82069894
	goto loc_82069894;
loc_820698C0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_820698C4:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x820698d4
	if (!ctx.cr6.lt) goto loc_820698D4;
loc_820698D0:
	// twi 31,r0,22
loc_820698D4:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r29)
	PPC_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820698EC"))) PPC_WEAK_FUNC(sub_820698EC);
PPC_FUNC_IMPL(__imp__sub_820698EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820698F0"))) PPC_WEAK_FUNC(sub_820698F0);
PPC_FUNC_IMPL(__imp__sub_820698F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x820698F8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,3972
	ctx.r9.s64 = ctx.r11.s64 + 3972;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x82069924;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8206993C;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206995c
	if (ctx.cr6.eq) goto loc_8206995C;
	// bl 0x8207a630
	ctx.lr = 0x82069958;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206995C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82069964"))) PPC_WEAK_FUNC(sub_82069964);
PPC_FUNC_IMPL(__imp__sub_82069964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069968"))) PPC_WEAK_FUNC(sub_82069968);
PPC_FUNC_IMPL(__imp__sub_82069968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82069970;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,3988
	ctx.r9.s64 = ctx.r11.s64 + 3988;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x8206999C;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x820699B4;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x820699d4
	if (ctx.cr6.eq) goto loc_820699D4;
	// bl 0x8207a630
	ctx.lr = 0x820699D0;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_820699D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_820699DC"))) PPC_WEAK_FUNC(sub_820699DC);
PPC_FUNC_IMPL(__imp__sub_820699DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_820699E0"))) PPC_WEAK_FUNC(sub_820699E0);
PPC_FUNC_IMPL(__imp__sub_820699E0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82069A04"))) PPC_WEAK_FUNC(sub_82069A04);
PPC_FUNC_IMPL(__imp__sub_82069A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069A08"))) PPC_WEAK_FUNC(sub_82069A08);
PPC_FUNC_IMPL(__imp__sub_82069A08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x82069A10;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r11,4084
	ctx.r9.s64 = ctx.r11.s64 + 4084;
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x82069A3C;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x82069A54;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82069a74
	if (ctx.cr6.eq) goto loc_82069A74;
	// bl 0x8207a630
	ctx.lr = 0x82069A70;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069A74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82069A7C"))) PPC_WEAK_FUNC(sub_82069A7C);
PPC_FUNC_IMPL(__imp__sub_82069A7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069A80"))) PPC_WEAK_FUNC(sub_82069A80);
PPC_FUNC_IMPL(__imp__sub_82069A80) {
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
	// bl 0x82193120
	ctx.lr = 0x82069AA0;
	sub_82193120(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069ab8
	if (ctx.cr6.eq) goto loc_82069AB8;
	// bl 0x8207a630
	ctx.lr = 0x82069AB4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069AB8:
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

__attribute__((alias("__imp__sub_82069AD0"))) PPC_WEAK_FUNC(sub_82069AD0);
PPC_FUNC_IMPL(__imp__sub_82069AD0) {
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
	// lwz r11,56(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r3,32
	ctx.r31.s64 = ctx.r3.s64 + 32;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82069b00
	if (ctx.cr6.lt) goto loc_82069B00;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82069B00;
	sub_8207A630(ctx, base);
loc_82069B00:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// bl 0x8207a630
	ctx.lr = 0x82069B1C;
	sub_8207A630(ctx, base);
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

__attribute__((alias("__imp__sub_82069B38"))) PPC_WEAK_FUNC(sub_82069B38);
PPC_FUNC_IMPL(__imp__sub_82069B38) {
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
	// bl 0x82192d80
	ctx.lr = 0x82069B58;
	sub_82192D80(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069b70
	if (ctx.cr6.eq) goto loc_82069B70;
	// bl 0x8207a630
	ctx.lr = 0x82069B6C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069B70:
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

__attribute__((alias("__imp__sub_82069B88"))) PPC_WEAK_FUNC(sub_82069B88);
PPC_FUNC_IMPL(__imp__sub_82069B88) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,4036
	ctx.r10.s64 = ctx.r11.s64 + 4036;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82069bc0
	if (ctx.cr6.eq) goto loc_82069BC0;
	// bl 0x82069c00
	ctx.lr = 0x82069BC0;
	sub_82069C00(ctx, base);
loc_82069BC0:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,-1456
	ctx.r9.s64 = ctx.r11.s64 + -1456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82069be4
	if (ctx.cr6.eq) goto loc_82069BE4;
	// bl 0x8207a630
	ctx.lr = 0x82069BE0;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069BE4:
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

__attribute__((alias("__imp__sub_82069BFC"))) PPC_WEAK_FUNC(sub_82069BFC);
PPC_FUNC_IMPL(__imp__sub_82069BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069C00"))) PPC_WEAK_FUNC(sub_82069C00);
PPC_FUNC_IMPL(__imp__sub_82069C00) {
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
	// bl 0x82191b38
	ctx.lr = 0x82069C1C;
	sub_82191B38(ctx, base);
	// lwz r11,392(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 392);
	// addi r31,r30,368
	ctx.r31.s64 = ctx.r30.s64 + 368;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82069c34
	if (ctx.cr6.lt) goto loc_82069C34;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x82069C34;
	sub_8207A630(ctx, base);
loc_82069C34:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// bl 0x8207a630
	ctx.lr = 0x82069C50;
	sub_8207A630(ctx, base);
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

__attribute__((alias("__imp__sub_82069C6C"))) PPC_WEAK_FUNC(sub_82069C6C);
PPC_FUNC_IMPL(__imp__sub_82069C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069C70"))) PPC_WEAK_FUNC(sub_82069C70);
PPC_FUNC_IMPL(__imp__sub_82069C70) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,4048
	ctx.r10.s64 = ctx.r11.s64 + 4048;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82069ca8
	if (ctx.cr6.eq) goto loc_82069CA8;
	// bl 0x82069c00
	ctx.lr = 0x82069CA8;
	sub_82069C00(ctx, base);
loc_82069CA8:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,-1456
	ctx.r9.s64 = ctx.r11.s64 + -1456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82069ccc
	if (ctx.cr6.eq) goto loc_82069CCC;
	// bl 0x8207a630
	ctx.lr = 0x82069CC8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069CCC:
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

__attribute__((alias("__imp__sub_82069CE4"))) PPC_WEAK_FUNC(sub_82069CE4);
PPC_FUNC_IMPL(__imp__sub_82069CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069CE8"))) PPC_WEAK_FUNC(sub_82069CE8);
PPC_FUNC_IMPL(__imp__sub_82069CE8) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,4060
	ctx.r10.s64 = ctx.r11.s64 + 4060;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82069d20
	if (ctx.cr6.eq) goto loc_82069D20;
	// bl 0x82069c00
	ctx.lr = 0x82069D20;
	sub_82069C00(ctx, base);
loc_82069D20:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,-1456
	ctx.r9.s64 = ctx.r11.s64 + -1456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82069d44
	if (ctx.cr6.eq) goto loc_82069D44;
	// bl 0x8207a630
	ctx.lr = 0x82069D40;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069D44:
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

__attribute__((alias("__imp__sub_82069D5C"))) PPC_WEAK_FUNC(sub_82069D5C);
PPC_FUNC_IMPL(__imp__sub_82069D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069D60"))) PPC_WEAK_FUNC(sub_82069D60);
PPC_FUNC_IMPL(__imp__sub_82069D60) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r10,r11,4072
	ctx.r10.s64 = ctx.r11.s64 + 4072;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82069d98
	if (ctx.cr6.eq) goto loc_82069D98;
	// bl 0x82069c00
	ctx.lr = 0x82069D98;
	sub_82069C00(ctx, base);
loc_82069D98:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,-1456
	ctx.r9.s64 = ctx.r11.s64 + -1456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82069dbc
	if (ctx.cr6.eq) goto loc_82069DBC;
	// bl 0x8207a630
	ctx.lr = 0x82069DB8;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82069DBC:
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

__attribute__((alias("__imp__sub_82069DD4"))) PPC_WEAK_FUNC(sub_82069DD4);
PPC_FUNC_IMPL(__imp__sub_82069DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82069DD8"))) PPC_WEAK_FUNC(sub_82069DD8);
PPC_FUNC_IMPL(__imp__sub_82069DD8) {
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
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bne cr6,0x82069e60
	if (!ctx.cr6.eq) goto loc_82069E60;
	// twi 31,r0,22
	// li r10,0
	ctx.r10.s64 = 0;
loc_82069E08:
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82069e18
	if (!ctx.cr6.eq) goto loc_82069E18;
	// twi 31,r0,22
loc_82069E18:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x82069e4c
	if (ctx.cr6.eq) goto loc_82069E4C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// bl 0x8207a630
	ctx.lr = 0x82069E40;
	sub_8207A630(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r6,r11,-1
	ctx.r6.s64 = ctx.r11.s64 + -1;
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
loc_82069E4C:
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
loc_82069E60:
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x82069e08
	goto loc_82069E08;
}

__attribute__((alias("__imp__sub_82069E68"))) PPC_WEAK_FUNC(sub_82069E68);
PPC_FUNC_IMPL(__imp__sub_82069E68) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r11.u32);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r9,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r9.u32);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// cmplw cr6,r3,r8
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r8.u32, ctx.xer);
	// stw r10,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// beq cr6,0x82069ec0
	if (ctx.cr6.eq) goto loc_82069EC0;
loc_82069EA8:
	// lwz r31,0(r3)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x82069EB0;
	sub_8207A630(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82069ea8
	if (!ctx.cr6.eq) goto loc_82069EA8;
loc_82069EC0:
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

__attribute__((alias("__imp__sub_82069ED8"))) PPC_WEAK_FUNC(sub_82069ED8);
PPC_FUNC_IMPL(__imp__sub_82069ED8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x82069EE0;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82069f44
	if (ctx.cr6.eq) goto loc_82069F44;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x82069f18
	if (ctx.cr6.lt) goto loc_82069F18;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82069f1c
	goto loc_82069F1C;
loc_82069F18:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_82069F1C:
	// cmplw cr6,r25,r10
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82069f44
	if (ctx.cr6.lt) goto loc_82069F44;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x82069f30
	if (ctx.cr6.lt) goto loc_82069F30;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_82069F30:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r25
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r25.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bgt cr6,0x82069f48
	if (ctx.cr6.gt) goto loc_82069F48;
loc_82069F44:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82069F48:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82069f8c
	if (ctx.cr6.eq) goto loc_82069F8C;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x82069f68
	if (ctx.cr6.lt) goto loc_82069F68;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x82069f6c
	goto loc_82069F6C;
loc_82069F68:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_82069F6C:
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// subf r6,r11,r25
	ctx.r6.s64 = ctx.r25.s64 - ctx.r11.s64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206a430
	ctx.lr = 0x82069F84;
	sub_8206A430(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_82069F8C:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82069f9c
	if (!ctx.cr6.lt) goto loc_82069F9C;
	// bl 0x8207a2d0
	ctx.lr = 0x82069F9C;
	sub_8207A2D0(ctx, base);
loc_82069F9C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r11,r30,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r30.s64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82069fb0
	if (!ctx.cr6.lt) goto loc_82069FB0;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_82069FB0:
	// subf r11,r29,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r29.s64;
	// subfic r10,r28,-1
	ctx.xer.ca = ctx.r28.u32 <= 4294967295;
	ctx.r10.s64 = -1 - ctx.r28.s64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82069fc4
	if (ctx.cr6.gt) goto loc_82069FC4;
	// bl 0x8207a250
	ctx.lr = 0x82069FC4;
	sub_8207A250(ctx, base);
loc_82069FC4:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// subf r10,r30,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r30.s64;
	// subf r27,r29,r10
	ctx.r27.s64 = ctx.r10.s64 - ctx.r29.s64;
	// bge cr6,0x8206a020
	if (!ctx.cr6.lt) goto loc_8206A020;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x82069ff0
	if (ctx.cr6.lt) goto loc_82069FF0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x82069ff4
	goto loc_82069FF4;
loc_82069FF0:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_82069FF4:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a000
	if (ctx.cr6.lt) goto loc_8206A000;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8206A000:
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r30.s64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r5,r10,r29
	ctx.r5.u64 = ctx.r10.u64 + ctx.r29.u64;
	// subf r4,r28,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r28.s64;
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A020;
	sub_8207A520(ctx, base);
loc_8206A020:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8206a030
	if (!ctx.cr6.eq) goto loc_8206A030;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8206a0f4
	if (ctx.cr6.eq) goto loc_8206A0F4;
loc_8206A030:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subf r11,r29,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r29.s64;
	// add r26,r11,r28
	ctx.r26.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82060540
	ctx.lr = 0x8206A04C;
	sub_82060540(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206a0f4
	if (ctx.cr6.eq) goto loc_8206A0F4;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8206a0a8
	if (!ctx.cr6.lt) goto loc_8206A0A8;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a078
	if (ctx.cr6.lt) goto loc_8206A078;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8206a07c
	goto loc_8206A07C;
loc_8206A078:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8206A07C:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a088
	if (ctx.cr6.lt) goto loc_8206A088;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8206A088:
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// subf r9,r30,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r30.s64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// add r5,r10,r29
	ctx.r5.u64 = ctx.r10.u64 + ctx.r29.u64;
	// subf r4,r28,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r28.s64;
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A0A8;
	sub_8207A520(ctx, base);
loc_8206A0A8:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8206a0c0
	if (ctx.cr6.lt) goto loc_8206A0C0;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8206a0c4
	goto loc_8206A0C4;
loc_8206A0C0:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A0C4:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// subf r4,r30,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r30.s64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8207a638
	ctx.lr = 0x8206A0D8;
	sub_8207A638(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r26,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r26.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a0ec
	if (ctx.cr6.lt) goto loc_8206A0EC;
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_8206A0EC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stbx r11,r29,r26
	PPC_STORE_U8(ctx.r29.u32 + ctx.r26.u32, ctx.r11.u8);
loc_8206A0F4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A100"))) PPC_WEAK_FUNC(sub_8206A100);
PPC_FUNC_IMPL(__imp__sub_8206A100) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206A108;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8206a138
	if (!ctx.cr6.eq) goto loc_8206A138;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8206a138
	if (ctx.cr6.gt) goto loc_8206A138;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8206A138:
	// lwz r11,20(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8206a200
	if (!ctx.cr6.lt) goto loc_8206A200;
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8206a200
	if (ctx.cr6.gt) goto loc_8206A200;
	// lwz r10,24(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// subf r11,r28,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r28.s64;
	// addi r26,r27,4
	ctx.r26.s64 = ctx.r27.s64 + 4;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8206a170
	if (ctx.cr6.lt) goto loc_8206A170;
	// lwz r11,4(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// b 0x8206a174
	goto loc_8206A174;
loc_8206A170:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8206A174:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// add r31,r11,r5
	ctx.r31.u64 = ctx.r11.u64 + ctx.r5.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207adb0
	ctx.lr = 0x8206A18C;
	sub_8207ADB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206a200
	if (ctx.cr6.eq) goto loc_8206A200;
loc_8206A194:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8206a1cc
	if (ctx.cr6.eq) goto loc_8206A1CC;
	// add r8,r3,r28
	ctx.r8.u64 = ctx.r3.u64 + ctx.r28.u64;
loc_8206A1AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8206a1cc
	if (!ctx.cr0.eq) goto loc_8206A1CC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8206a1ac
	if (!ctx.cr6.eq) goto loc_8206A1AC;
loc_8206A1CC:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8206a20c
	if (ctx.cr6.eq) goto loc_8206A20C;
	// subf r11,r3,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r3.s64;
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r29.u32 + 0);
	// addi r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 1;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x8207adb0
	ctx.lr = 0x8206A1F8;
	sub_8207ADB0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206a194
	if (!ctx.cr6.eq) goto loc_8206A194;
loc_8206A200:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8206A20C:
	// lwz r11,24(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a228
	if (ctx.cr6.lt) goto loc_8206A228;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// subf r3,r11,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r11.s64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8206A228:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// subf r3,r26,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r26.s64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A238"))) PPC_WEAK_FUNC(sub_8206A238);
PPC_FUNC_IMPL(__imp__sub_8206A238) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206A240;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r4.u64);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r27,236(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// li r3,12
	ctx.r3.s64 = 12;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// lwz r28,4(r27)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x82079fd8
	ctx.lr = 0x8206A260;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206a270
	if (ctx.cr6.eq) goto loc_8206A270;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r27.u32);
loc_8206A270:
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8206a280
	if (ctx.cr6.eq) goto loc_8206A280;
	// stw r28,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
loc_8206A280:
	// addic. r11,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r11.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8206a290
	if (ctx.cr0.eq) goto loc_8206A290;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_8206A290:
	// lis r11,16383
	ctx.r11.s64 = 1073676288;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// ori r9,r11,65535
	ctx.r9.u64 = ctx.r11.u64 | 65535;
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x8206a304
	if (!ctx.cr6.lt) goto loc_8206A304;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,3952
	ctx.r4.s64 = ctx.r11.s64 + 3952;
	// bl 0x82060190
	ctx.lr = 0x8206A2B8;
	sub_82060190(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060e58
	ctx.lr = 0x8206A2C4;
	sub_82060E58(ctx, base);
	// bl 0x82060018
	ctx.lr = 0x8206A2C8;
	sub_82060018(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r9,r10,-1236
	ctx.r9.s64 = ctx.r10.s64 + -1236;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// bl 0x82060c50
	ctx.lr = 0x8206A2DC;
	sub_82060C50(ctx, base);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8206a2f0
	if (ctx.cr6.lt) goto loc_8206A2F0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8206A2F0;
	sub_8207A630(ctx, base);
loc_8206A2F0:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r11.u8);
loc_8206A304:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// stw r31,4(r27)
	PPC_STORE_U32(ctx.r27.u32 + 4, ctx.r31.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A324"))) PPC_WEAK_FUNC(sub_8206A324);
PPC_FUNC_IMPL(__imp__sub_8206A324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206A328"))) PPC_WEAK_FUNC(sub_8206A328);
PPC_FUNC_IMPL(__imp__sub_8206A328) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206A330;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r4.u64);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r26,236(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// li r3,24
	ctx.r3.s64 = 24;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lwz r27,4(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bl 0x82079fd8
	ctx.lr = 0x8206A350;
	sub_82079FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206a360
	if (ctx.cr6.eq) goto loc_8206A360;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r26.u32);
loc_8206A360:
	// addi r30,r31,4
	ctx.r30.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8206a370
	if (ctx.cr6.eq) goto loc_8206A370;
	// stw r27,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
loc_8206A370:
	// addic. r11,r31,8
	ctx.xer.ca = ctx.r31.u32 > 4294967287;
	ctx.r11.s64 = ctx.r31.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8206a398
	if (ctx.cr0.eq) goto loc_8206A398;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// lwz r8,8(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 8);
	// lwz r7,12(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// stw r7,12(r11)
	PPC_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
loc_8206A398:
	// lis r11,4095
	ctx.r11.s64 = 268369920;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// ori r9,r11,65535
	ctx.r9.u64 = ctx.r11.u64 | 65535;
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bge cr6,0x8206a40c
	if (!ctx.cr6.lt) goto loc_8206A40C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,3952
	ctx.r4.s64 = ctx.r11.s64 + 3952;
	// bl 0x82060190
	ctx.lr = 0x8206A3C0;
	sub_82060190(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060e58
	ctx.lr = 0x8206A3CC;
	sub_82060E58(ctx, base);
	// bl 0x82060018
	ctx.lr = 0x8206A3D0;
	sub_82060018(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r9,r10,-1236
	ctx.r9.s64 = ctx.r10.s64 + -1236;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// bl 0x82060c50
	ctx.lr = 0x8206A3E4;
	sub_82060C50(ctx, base);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8206a3f8
	if (ctx.cr6.lt) goto loc_8206A3F8;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8206A3F8;
	sub_8207A630(ctx, base);
loc_8206A3F8:
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r11.u8);
loc_8206A40C:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r11.u32);
	// stw r31,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r31.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r31,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r31.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A42C"))) PPC_WEAK_FUNC(sub_8206A42C);
PPC_FUNC_IMPL(__imp__sub_8206A42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206A430"))) PPC_WEAK_FUNC(sub_8206A430);
PPC_FUNC_IMPL(__imp__sub_8206A430) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8206A438;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r24,r6
	ctx.r24.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// li r28,1
	ctx.r28.s64 = 1;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x8206a46c
	if (ctx.cr6.lt) goto loc_8206A46C;
	// lwz r11,20(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x8206a470
	if (!ctx.cr6.lt) goto loc_8206A470;
loc_8206A46C:
	// bl 0x8207a2d0
	ctx.lr = 0x8206A470;
	sub_8207A2D0(ctx, base);
loc_8206A470:
	// lwz r10,20(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 20);
	// subf r11,r31,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r31.s64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8206a484
	if (!ctx.cr6.lt) goto loc_8206A484;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
loc_8206A484:
	// lwz r11,20(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// subf r11,r24,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r24.s64;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8206a498
	if (!ctx.cr6.lt) goto loc_8206A498;
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
loc_8206A498:
	// subf r11,r28,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r28.s64;
	// subfic r10,r30,-1
	ctx.xer.ca = ctx.r30.u32 <= 4294967295;
	ctx.r10.s64 = -1 - ctx.r30.s64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8206a4ac
	if (ctx.cr6.gt) goto loc_8206A4AC;
	// bl 0x8207a250
	ctx.lr = 0x8206A4AC;
	sub_8207A250(ctx, base);
loc_8206A4AC:
	// lwz r10,20(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 20);
	// subf r11,r28,r10
	ctx.r11.s64 = ctx.r10.s64 - ctx.r28.s64;
	// subf r9,r31,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r31.s64;
	// add r23,r11,r30
	ctx.r23.u64 = ctx.r11.u64 + ctx.r30.u64;
	// subf r25,r28,r9
	ctx.r25.s64 = ctx.r9.s64 - ctx.r28.s64;
	// cmplw cr6,r10,r23
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x8206a4d8
	if (!ctx.cr6.lt) goto loc_8206A4D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82060540
	ctx.lr = 0x8206A4D8;
	sub_82060540(ctx, base);
loc_8206A4D8:
	// lwz r9,24(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplw cr6,r26,r27
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r27.u32, ctx.xer);
	// addi r29,r26,4
	ctx.r29.s64 = ctx.r26.s64 + 4;
	// beq cr6,0x8206a578
	if (ctx.cr6.eq) goto loc_8206A578;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a4f8
	if (ctx.cr6.lt) goto loc_8206A4F8;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// b 0x8206a4fc
	goto loc_8206A4FC;
loc_8206A4F8:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A4FC:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a50c
	if (ctx.cr6.lt) goto loc_8206A50C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a510
	goto loc_8206A510;
loc_8206A50C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A510:
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r31.s64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r4,r30,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r30.s64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A530;
	sub_8207A520(ctx, base);
	// lwz r8,24(r27)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8206a544
	if (ctx.cr6.lt) goto loc_8206A544;
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + 4);
	// b 0x8206a548
	goto loc_8206A548;
loc_8206A544:
	// addi r9,r27,4
	ctx.r9.s64 = ctx.r27.s64 + 4;
loc_8206A548:
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8206a55c
	if (ctx.cr6.lt) goto loc_8206A55C;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a560
	goto loc_8206A560;
loc_8206A55C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A560:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// add r5,r9,r24
	ctx.r5.u64 = ctx.r9.u64 + ctx.r24.u64;
	// subf r4,r31,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r31.s64;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x8207a638
	ctx.lr = 0x8206A574;
	sub_8207A638(ctx, base);
	// b 0x8206a820
	goto loc_8206A820;
loc_8206A578:
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x8206a608
	if (ctx.cr6.gt) goto loc_8206A608;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a590
	if (ctx.cr6.lt) goto loc_8206A590;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// b 0x8206a594
	goto loc_8206A594;
loc_8206A590:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A594:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a5a4
	if (ctx.cr6.lt) goto loc_8206A5A4;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a5a8
	goto loc_8206A5A8;
loc_8206A5A4:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A5A8:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// add r5,r10,r24
	ctx.r5.u64 = ctx.r10.u64 + ctx.r24.u64;
	// subf r4,r31,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r31.s64;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A5BC;
	sub_8207A520(ctx, base);
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a5d0
	if (ctx.cr6.lt) goto loc_8206A5D0;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a5d4
	goto loc_8206A5D4;
loc_8206A5D0:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A5D4:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a5e4
	if (ctx.cr6.lt) goto loc_8206A5E4;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a5e8
	goto loc_8206A5E8;
loc_8206A5E4:
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_8206A5E8:
	// subf r8,r31,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r4,r30,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r30.s64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// b 0x8206a81c
	goto loc_8206A81C;
loc_8206A608:
	// cmplw cr6,r24,r31
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x8206a6a8
	if (ctx.cr6.gt) goto loc_8206A6A8;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a620
	if (ctx.cr6.lt) goto loc_8206A620;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// b 0x8206a624
	goto loc_8206A624;
loc_8206A620:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A624:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a634
	if (ctx.cr6.lt) goto loc_8206A634;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a638
	goto loc_8206A638;
loc_8206A634:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A638:
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r31.s64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r4,r30,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r30.s64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A658;
	sub_8207A520(ctx, base);
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a66c
	if (ctx.cr6.lt) goto loc_8206A66C;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a670
	goto loc_8206A670;
loc_8206A66C:
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_8206A670:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a690
	if (ctx.cr6.lt) goto loc_8206A690;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// add r5,r9,r24
	ctx.r5.u64 = ctx.r9.u64 + ctx.r24.u64;
	// subf r4,r31,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r3,r10,r31
	ctx.r3.u64 = ctx.r10.u64 + ctx.r31.u64;
	// b 0x8206a81c
	goto loc_8206A81C;
loc_8206A690:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// add r5,r9,r24
	ctx.r5.u64 = ctx.r9.u64 + ctx.r24.u64;
	// subf r4,r31,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// b 0x8206a81c
	goto loc_8206A81C;
loc_8206A6A8:
	// add r11,r31,r28
	ctx.r11.u64 = ctx.r31.u64 + ctx.r28.u64;
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// bgt cr6,0x8206a74c
	if (ctx.cr6.gt) goto loc_8206A74C;
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a6c4
	if (ctx.cr6.lt) goto loc_8206A6C4;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// b 0x8206a6c8
	goto loc_8206A6C8;
loc_8206A6C4:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A6C8:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a6d8
	if (ctx.cr6.lt) goto loc_8206A6D8;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a6dc
	goto loc_8206A6DC;
loc_8206A6D8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A6DC:
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// subf r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r31.s64;
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r4,r30,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r30.s64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A6FC;
	sub_8207A520(ctx, base);
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a710
	if (ctx.cr6.lt) goto loc_8206A710;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a714
	goto loc_8206A714;
loc_8206A710:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A714:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a734
	if (ctx.cr6.lt) goto loc_8206A734;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r28.s64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// subf r4,r31,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + ctx.r31.u64;
	// b 0x8206a814
	goto loc_8206A814;
loc_8206A734:
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r28.s64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// subf r4,r31,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// b 0x8206a814
	goto loc_8206A814;
loc_8206A74C:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a75c
	if (ctx.cr6.lt) goto loc_8206A75C;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// b 0x8206a760
	goto loc_8206A760;
loc_8206A75C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A760:
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// blt cr6,0x8206a770
	if (ctx.cr6.lt) goto loc_8206A770;
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a774
	goto loc_8206A774;
loc_8206A770:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_8206A774:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// add r5,r10,r24
	ctx.r5.u64 = ctx.r10.u64 + ctx.r24.u64;
	// subf r4,r31,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r31.s64;
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A788;
	sub_8207A520(ctx, base);
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a79c
	if (ctx.cr6.lt) goto loc_8206A79C;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a7a0
	goto loc_8206A7A0;
loc_8206A79C:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A7A0:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a7b0
	if (ctx.cr6.lt) goto loc_8206A7B0;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a7b4
	goto loc_8206A7B4;
loc_8206A7B0:
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_8206A7B4:
	// subf r8,r31,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + ctx.r31.u64;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// subf r4,r30,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r30.s64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206A7D4;
	sub_8207A520(ctx, base);
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a7e8
	if (ctx.cr6.lt) goto loc_8206A7E8;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a7ec
	goto loc_8206A7EC;
loc_8206A7E8:
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8206A7EC:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a7fc
	if (ctx.cr6.lt) goto loc_8206A7FC;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206a800
	goto loc_8206A800;
loc_8206A7FC:
	// mr r9,r29
	ctx.r9.u64 = ctx.r29.u64;
loc_8206A800:
	// subf r8,r31,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r31.s64;
	// add r11,r9,r31
	ctx.r11.u64 = ctx.r9.u64 + ctx.r31.u64;
	// subf r6,r28,r30
	ctx.r6.s64 = ctx.r30.s64 - ctx.r28.s64;
	// subf r4,r28,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r28.s64;
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
loc_8206A814:
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + ctx.r30.u64;
loc_8206A81C:
	// bl 0x8207a520
	ctx.lr = 0x8206A820;
	sub_8207A520(ctx, base);
loc_8206A820:
	// lwz r11,24(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// stw r23,20(r26)
	PPC_STORE_U32(ctx.r26.u32 + 20, ctx.r23.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a834
	if (ctx.cr6.lt) goto loc_8206A834;
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_8206A834:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stbx r11,r29,r23
	PPC_STORE_U8(ctx.r29.u32 + ctx.r23.u32, ctx.r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A848"))) PPC_WEAK_FUNC(sub_8206A848);
PPC_FUNC_IMPL(__imp__sub_8206A848) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8206A850;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8206a8b0
	if (ctx.cr6.eq) goto loc_8206A8B0;
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// blt cr6,0x8206a880
	if (ctx.cr6.lt) goto loc_8206A880;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x8206a884
	goto loc_8206A884;
loc_8206A880:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
loc_8206A884:
	// cmplw cr6,r28,r10
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8206a8b0
	if (ctx.cr6.lt) goto loc_8206A8B0;
	// cmplwi cr6,r9,8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 8, ctx.xer);
	// blt cr6,0x8206a898
	if (ctx.cr6.lt) goto loc_8206A898;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
loc_8206A898:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r11,1
	ctx.r11.s64 = 1;
	// cmplw cr6,r9,r28
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x8206a8b4
	if (ctx.cr6.gt) goto loc_8206A8B4;
loc_8206A8B0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8206A8B4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a8f8
	if (ctx.cr6.eq) goto loc_8206A8F8;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8206a8d4
	if (ctx.cr6.lt) goto loc_8206A8D4;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8206a8d8
	goto loc_8206A8D8;
loc_8206A8D4:
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
loc_8206A8D8:
	// subf r11,r11,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r11.s64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// srawi r5,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r11.s32 >> 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82063cc8
	ctx.lr = 0x8206A8F0;
	sub_82063CC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206A8F8:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82064328
	ctx.lr = 0x8206A904;
	sub_82064328(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206a95c
	if (ctx.cr6.eq) goto loc_8206A95C;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8206a928
	if (ctx.cr6.lt) goto loc_8206A928;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// b 0x8206a92c
	goto loc_8206A92C;
loc_8206A928:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_8206A92C:
	// rlwinm r30,r27,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8207a638
	ctx.lr = 0x8206A940;
	sub_8207A638(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8206a954
	if (ctx.cr6.lt) goto loc_8206A954;
	// lwz r29,0(r29)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
loc_8206A954:
	// li r11,0
	ctx.r11.s64 = 0;
	// sthx r11,r30,r29
	PPC_STORE_U16(ctx.r30.u32 + ctx.r29.u32, ctx.r11.u16);
loc_8206A95C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A968"))) PPC_WEAK_FUNC(sub_8206A968);
PPC_FUNC_IMPL(__imp__sub_8206A968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8206A970;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x8206A9A4;
	sub_820601F8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82061660
	ctx.lr = 0x8206A9B8;
	sub_82061660(ctx, base);
	// stw r28,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r28.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r30,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x8206A9D8;
	sub_820601F8(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206a9ec
	if (ctx.cr6.lt) goto loc_8206A9EC;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8206A9EC;
	sub_8207A630(ctx, base);
loc_8206A9EC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206A9F8"))) PPC_WEAK_FUNC(sub_8206A9F8);
PPC_FUNC_IMPL(__imp__sub_8206A9F8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stb r11,-32212(r9)
	PPC_STORE_U8(ctx.r9.u32 + -32212, ctx.r11.u8);
	// bl 0x82088d00
	ctx.lr = 0x8206AA34;
	sub_82088D00(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82088d00
	ctx.lr = 0x8206AA3C;
	sub_82088D00(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x82088d00
	ctx.lr = 0x8206AA44;
	sub_82088D00(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// clrlwi r6,r30,31
	ctx.r6.u64 = ctx.r30.u32 & 0x1;
	// addi r5,r7,-1456
	ctx.r5.s64 = ctx.r7.s64 + -1456;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8206aa68
	if (ctx.cr6.eq) goto loc_8206AA68;
	// bl 0x8207a630
	ctx.lr = 0x8206AA64;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AA68:
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

__attribute__((alias("__imp__sub_8206AA80"))) PPC_WEAK_FUNC(sub_8206AA80);
PPC_FUNC_IMPL(__imp__sub_8206AA80) {
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
	// bl 0x82191700
	ctx.lr = 0x8206AAA0;
	sub_82191700(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206aab8
	if (ctx.cr6.eq) goto loc_8206AAB8;
	// bl 0x8207a630
	ctx.lr = 0x8206AAB4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AAB8:
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

__attribute__((alias("__imp__sub_8206AAD0"))) PPC_WEAK_FUNC(sub_8206AAD0);
PPC_FUNC_IMPL(__imp__sub_8206AAD0) {
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
	// bl 0x8218e3e8
	ctx.lr = 0x8206AAF0;
	sub_8218E3E8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206ab08
	if (ctx.cr6.eq) goto loc_8206AB08;
	// bl 0x8207a630
	ctx.lr = 0x8206AB04;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AB08:
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

__attribute__((alias("__imp__sub_8206AB20"))) PPC_WEAK_FUNC(sub_8206AB20);
PPC_FUNC_IMPL(__imp__sub_8206AB20) {
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
	// bl 0x8218e328
	ctx.lr = 0x8206AB40;
	sub_8218E328(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206ab58
	if (ctx.cr6.eq) goto loc_8206AB58;
	// bl 0x8207a630
	ctx.lr = 0x8206AB54;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AB58:
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

__attribute__((alias("__imp__sub_8206AB70"))) PPC_WEAK_FUNC(sub_8206AB70);
PPC_FUNC_IMPL(__imp__sub_8206AB70) {
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
	// bl 0x8218e188
	ctx.lr = 0x8206AB90;
	sub_8218E188(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206aba8
	if (ctx.cr6.eq) goto loc_8206ABA8;
	// bl 0x8207a630
	ctx.lr = 0x8206ABA4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206ABA8:
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

__attribute__((alias("__imp__sub_8206ABC0"))) PPC_WEAK_FUNC(sub_8206ABC0);
PPC_FUNC_IMPL(__imp__sub_8206ABC0) {
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
	// bl 0x8218e0c0
	ctx.lr = 0x8206ABE0;
	sub_8218E0C0(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206abf8
	if (ctx.cr6.eq) goto loc_8206ABF8;
	// bl 0x8207a630
	ctx.lr = 0x8206ABF4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206ABF8:
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

__attribute__((alias("__imp__sub_8206AC10"))) PPC_WEAK_FUNC(sub_8206AC10);
PPC_FUNC_IMPL(__imp__sub_8206AC10) {
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
	// bl 0x8218df90
	ctx.lr = 0x8206AC30;
	sub_8218DF90(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206ac48
	if (ctx.cr6.eq) goto loc_8206AC48;
	// bl 0x8207a630
	ctx.lr = 0x8206AC44;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AC48:
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

__attribute__((alias("__imp__sub_8206AC60"))) PPC_WEAK_FUNC(sub_8206AC60);
PPC_FUNC_IMPL(__imp__sub_8206AC60) {
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
	// bl 0x8218dee0
	ctx.lr = 0x8206AC80;
	sub_8218DEE0(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206ac98
	if (ctx.cr6.eq) goto loc_8206AC98;
	// bl 0x8207a630
	ctx.lr = 0x8206AC94;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AC98:
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

__attribute__((alias("__imp__sub_8206ACB0"))) PPC_WEAK_FUNC(sub_8206ACB0);
PPC_FUNC_IMPL(__imp__sub_8206ACB0) {
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
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r9,r11,4328
	ctx.r9.s64 = ctx.r11.s64 + 4328;
	// addi r3,r3,52
	ctx.r3.s64 = ctx.r3.s64 + 52;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,997
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 997, ctx.xer);
	// bne cr6,0x8206acec
	if (!ctx.cr6.eq) goto loc_8206ACEC;
	// bl 0x82089e18
	ctx.lr = 0x8206ACEC;
	sub_82089E18(ctx, base);
loc_8206ACEC:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206acfc
	if (ctx.cr6.eq) goto loc_8206ACFC;
	// bl 0x8207a8a0
	ctx.lr = 0x8206ACFC;
	sub_8207A8A0(ctx, base);
loc_8206ACFC:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,-1456
	ctx.r9.s64 = ctx.r11.s64 + -1456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8206ad20
	if (ctx.cr6.eq) goto loc_8206AD20;
	// bl 0x8207a630
	ctx.lr = 0x8206AD1C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206AD20:
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

__attribute__((alias("__imp__sub_8206AD38"))) PPC_WEAK_FUNC(sub_8206AD38);
PPC_FUNC_IMPL(__imp__sub_8206AD38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c970
	ctx.lr = 0x8206AD40;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r4,200(r1)
	PPC_STORE_U64(ctx.r1.u32 + 200, ctx.r4.u64);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// std r5,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.r5.u64);
	// std r6,216(r1)
	PPC_STORE_U64(ctx.r1.u32 + 216, ctx.r6.u64);
	// lwz r11,216(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206ad6c
	if (ctx.cr6.eq) goto loc_8206AD6C;
	// lwz r10,208(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8206ad70
	if (ctx.cr6.eq) goto loc_8206AD70;
loc_8206AD6C:
	// twi 31,r0,22
loc_8206AD70:
	// lwz r28,212(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// li r22,80
	ctx.r22.s64 = 80;
	// lwz r24,220(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// lwz r11,12(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// subf r10,r28,r24
	ctx.r10.s64 = ctx.r24.s64 - ctx.r28.s64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// divw r23,r10,r22
	ctx.r23.s32 = ppc_divw(ctx.r10.s32, ctx.r22.s32);
	// bne cr6,0x8206ad98
	if (!ctx.cr6.eq) goto loc_8206AD98;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8206ada4
	goto loc_8206ADA4;
loc_8206AD98:
	// lwz r10,20(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r22
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r22.s32);
loc_8206ADA4:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x8206af80
	if (ctx.cr6.eq) goto loc_8206AF80;
	// lwz r30,16(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// lis r10,819
	ctx.r10.s64 = 53673984;
	// subf r8,r11,r30
	ctx.r8.s64 = ctx.r30.s64 - ctx.r11.s64;
	// ori r10,r10,13107
	ctx.r10.u64 = ctx.r10.u64 | 13107;
	// divw r11,r8,r22
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r22.s32);
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r7,r23
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x8206add8
	if (!ctx.cr6.lt) goto loc_8206ADD8;
	// bl 0x820686c0
	ctx.lr = 0x8206ADD0;
	sub_820686C0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_8206ADD8:
	// add r8,r11,r23
	ctx.r8.u64 = ctx.r11.u64 + ctx.r23.u64;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206af0c
	if (!ctx.cr6.lt) goto loc_8206AF0C;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// li r25,0
	ctx.r25.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8206adfc
	if (ctx.cr6.lt) goto loc_8206ADFC;
	// add r25,r11,r9
	ctx.r25.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8206ADFC:
	// cmplw cr6,r25,r8
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206ae08
	if (!ctx.cr6.lt) goto loc_8206AE08;
	// mr r25,r8
	ctx.r25.u64 = ctx.r8.u64;
loc_8206AE08:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82066ef0
	ctx.lr = 0x8206AE10;
	sub_82066EF0(ctx, base);
	// lwz r30,12(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r27,204(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x8206ae4c
	if (ctx.cr6.eq) goto loc_8206AE4C;
loc_8206AE28:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206ae3c
	if (ctx.cr6.eq) goto loc_8206AE3C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82061ba8
	ctx.lr = 0x8206AE3C;
	sub_82061BA8(ctx, base);
loc_8206AE3C:
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// cmplw cr6,r30,r27
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x8206ae28
	if (!ctx.cr6.eq) goto loc_8206AE28;
loc_8206AE4C:
	// cmplw cr6,r28,r24
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8206ae7c
	if (ctx.cr6.eq) goto loc_8206AE7C;
	// subf r30,r31,r28
	ctx.r30.s64 = ctx.r28.s64 - ctx.r31.s64;
loc_8206AE58:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206ae6c
	if (ctx.cr6.eq) goto loc_8206AE6C;
	// add r4,r30,r31
	ctx.r4.u64 = ctx.r30.u64 + ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82061ba8
	ctx.lr = 0x8206AE6C;
	sub_82061BA8(ctx, base);
loc_8206AE6C:
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r24
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x8206ae58
	if (!ctx.cr6.eq) goto loc_8206AE58;
loc_8206AE7C:
	// lwz r28,16(r29)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplw cr6,r27,r28
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8206aeb0
	if (ctx.cr6.eq) goto loc_8206AEB0;
	// subf r30,r31,r27
	ctx.r30.s64 = ctx.r27.s64 - ctx.r31.s64;
loc_8206AE8C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206aea0
	if (ctx.cr6.eq) goto loc_8206AEA0;
	// add r4,r30,r31
	ctx.r4.u64 = ctx.r30.u64 + ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82061ba8
	ctx.lr = 0x8206AEA0;
	sub_82061BA8(ctx, base);
loc_8206AEA0:
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// add r11,r30,r31
	ctx.r11.u64 = ctx.r30.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8206ae8c
	if (!ctx.cr6.eq) goto loc_8206AE8C;
loc_8206AEB0:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r11,r3,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// divw r11,r11,r22
	ctx.r11.s32 = ppc_divw(ctx.r11.s32, ctx.r22.s32);
	// add r31,r11,r23
	ctx.r31.u64 = ctx.r11.u64 + ctx.r23.u64;
	// beq cr6,0x8206aed8
	if (ctx.cr6.eq) goto loc_8206AED8;
	// bl 0x82062350
	ctx.lr = 0x8206AED0;
	sub_82062350(ctx, base);
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x8206AED8;
	sub_8207A630(ctx, base);
loc_8206AED8:
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r26.u32);
	// rlwinm r10,r25,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r31,r11
	ctx.r9.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r10,r25,r10
	ctx.r10.u64 = ctx.r25.u64 + ctx.r10.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r7,r11,r26
	ctx.r7.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r8,r10,r26
	ctx.r8.u64 = ctx.r10.u64 + ctx.r26.u64;
	// stw r7,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r7.u32);
	// stw r8,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r8.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
loc_8206AF0C:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r24
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r24.u32, ctx.xer);
	// beq cr6,0x8206af3c
	if (ctx.cr6.eq) goto loc_8206AF3C;
loc_8206AF18:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8206af2c
	if (ctx.cr6.eq) goto loc_8206AF2C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82061ba8
	ctx.lr = 0x8206AF2C;
	sub_82061BA8(ctx, base);
loc_8206AF2C:
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// addi r30,r30,80
	ctx.r30.s64 = ctx.r30.s64 + 80;
	// cmplw cr6,r31,r24
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r24.u32, ctx.xer);
	// bne cr6,0x8206af18
	if (!ctx.cr6.eq) goto loc_8206AF18;
loc_8206AF3C:
	// lwz r30,204(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206af88
	ctx.lr = 0x8206AF4C;
	sub_8206AF88(ctx, base);
	// rlwinm r11,r23,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// add r11,r23,r11
	ctx.r11.u64 = ctx.r23.u64 + ctx.r11.u64;
	// rlwinm r31,r11,4,0,27
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r4,r31,r3
	ctx.r4.u64 = ctx.r31.u64 + ctx.r3.u64;
	// bl 0x8206af88
	ctx.lr = 0x8206AF64;
	sub_8206AF88(ctx, base);
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// add r4,r31,r11
	ctx.r4.u64 = ctx.r31.u64 + ctx.r11.u64;
	// bl 0x8206af88
	ctx.lr = 0x8206AF74;
	sub_8206AF88(ctx, base);
	// lwz r11,16(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
	// stw r10,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r10.u32);
loc_8206AF80:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9c0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206AF88"))) PPC_WEAK_FUNC(sub_8206AF88);
PPC_FUNC_IMPL(__imp__sub_8206AF88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8206AF90;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8206b008
	if (ctx.cr6.eq) goto loc_8206B008;
	// li r28,15
	ctx.r28.s64 = 15;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8206AFAC:
	// addi r30,r30,-80
	ctx.r30.s64 = ctx.r30.s64 + -80;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8206b008
	if (ctx.cr6.eq) goto loc_8206B008;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82061ba8
	ctx.lr = 0x8206AFC4;
	sub_82061BA8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82062920
	ctx.lr = 0x8206AFD0;
	sub_82062920(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82062920
	ctx.lr = 0x8206AFDC;
	sub_82062920(ctx, base);
	// lwz r11,116(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206aff0
	if (ctx.cr6.lt) goto loc_8206AFF0;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x8207a630
	ctx.lr = 0x8206AFF0;
	sub_8207A630(ctx, base);
loc_8206AFF0:
	// addi r31,r31,80
	ctx.r31.s64 = ctx.r31.s64 + 80;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r29.u32);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// stb r29,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r29.u8);
	// bne cr6,0x8206afac
	if (!ctx.cr6.eq) goto loc_8206AFAC;
loc_8206B008:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206B010"))) PPC_WEAK_FUNC(sub_8206B010);
PPC_FUNC_IMPL(__imp__sub_8206B010) {
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
	// bl 0x8218b338
	ctx.lr = 0x8206B030;
	sub_8218B338(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b048
	if (ctx.cr6.eq) goto loc_8206B048;
	// bl 0x8207a630
	ctx.lr = 0x8206B044;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B048:
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

__attribute__((alias("__imp__sub_8206B060"))) PPC_WEAK_FUNC(sub_8206B060);
PPC_FUNC_IMPL(__imp__sub_8206B060) {
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
	// bl 0x8218b250
	ctx.lr = 0x8206B080;
	sub_8218B250(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b098
	if (ctx.cr6.eq) goto loc_8206B098;
	// bl 0x8207a630
	ctx.lr = 0x8206B094;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B098:
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

__attribute__((alias("__imp__sub_8206B0B0"))) PPC_WEAK_FUNC(sub_8206B0B0);
PPC_FUNC_IMPL(__imp__sub_8206B0B0) {
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
	// bl 0x8218b168
	ctx.lr = 0x8206B0D0;
	sub_8218B168(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b0e8
	if (ctx.cr6.eq) goto loc_8206B0E8;
	// bl 0x8207a630
	ctx.lr = 0x8206B0E4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B0E8:
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

__attribute__((alias("__imp__sub_8206B100"))) PPC_WEAK_FUNC(sub_8206B100);
PPC_FUNC_IMPL(__imp__sub_8206B100) {
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
	// bl 0x8218b070
	ctx.lr = 0x8206B120;
	sub_8218B070(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b138
	if (ctx.cr6.eq) goto loc_8206B138;
	// bl 0x8207a630
	ctx.lr = 0x8206B134;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B138:
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

__attribute__((alias("__imp__sub_8206B150"))) PPC_WEAK_FUNC(sub_8206B150);
PPC_FUNC_IMPL(__imp__sub_8206B150) {
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
	// bl 0x82189ab8
	ctx.lr = 0x8206B170;
	sub_82189AB8(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b188
	if (ctx.cr6.eq) goto loc_8206B188;
	// bl 0x8207a630
	ctx.lr = 0x8206B184;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B188:
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

__attribute__((alias("__imp__sub_8206B1A0"))) PPC_WEAK_FUNC(sub_8206B1A0);
PPC_FUNC_IMPL(__imp__sub_8206B1A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8206B1A8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// addi r29,r10,-1408
	ctx.r29.s64 = ctx.r10.s64 + -1408;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// stw r29,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r29.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82173a18
	ctx.lr = 0x8206B1D4;
	sub_82173A18(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// addi r28,r8,-1456
	ctx.r28.s64 = ctx.r8.s64 + -1456;
	// stw r28,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r28.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// bl 0x82173a18
	ctx.lr = 0x8206B1EC;
	sub_82173A18(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = ctx.r30.u32 & 0x1;
	// stw r28,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206b20c
	if (ctx.cr6.eq) goto loc_8206B20C;
	// bl 0x8207a630
	ctx.lr = 0x8206B208;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B20C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206B214"))) PPC_WEAK_FUNC(sub_8206B214);
PPC_FUNC_IMPL(__imp__sub_8206B214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206B218"))) PPC_WEAK_FUNC(sub_8206B218);
PPC_FUNC_IMPL(__imp__sub_8206B218) {
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
	// bl 0x821890d0
	ctx.lr = 0x8206B238;
	sub_821890D0(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b250
	if (ctx.cr6.eq) goto loc_8206B250;
	// bl 0x8207a630
	ctx.lr = 0x8206B24C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206B250:
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

__attribute__((alias("__imp__sub_8206B268"))) PPC_WEAK_FUNC(sub_8206B268);
PPC_FUNC_IMPL(__imp__sub_8206B268) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r8,28
	ctx.r8.s64 = 28;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b29c
	if (!ctx.cr6.eq) goto loc_8206B29C;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x8206b2a8
	goto loc_8206B2A8;
loc_8206B29C:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r8
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r8.s32);
loc_8206B2A8:
	// lwz r31,16(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r10,r11,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r10,r10,r8
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r8.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8206b2f0
	if (!ctx.cr6.lt) goto loc_8206B2F0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206b2e4
	if (ctx.cr6.eq) goto loc_8206B2E4;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r7,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r7,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r7.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x8206B2E4;
	sub_820601F8(ctx, base);
loc_8206B2E4:
	// addi r11,r31,28
	ctx.r11.s64 = ctx.r31.s64 + 28;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// b 0x8206b384
	goto loc_8206B384;
loc_8206B2F0:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8206b2fc
	if (!ctx.cr6.gt) goto loc_8206B2FC;
	// twi 31,r0,22
loc_8206B2FC:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne cr6,0x8206b31c
	if (!ctx.cr6.eq) goto loc_8206B31C;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// b 0x8206b344
	goto loc_8206B344;
loc_8206B31C:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8206b328
	if (!ctx.cr6.gt) goto loc_8206B328;
	// twi 31,r0,22
loc_8206B328:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206b338
	if (ctx.cr6.eq) goto loc_8206B338;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8206b33c
	if (ctx.cr6.eq) goto loc_8206B33C;
loc_8206B338:
	// twi 31,r0,22
loc_8206B33C:
	// subf r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r31,r11,r8
	ctx.r31.s32 = ppc_divw(ctx.r11.s32, ctx.r8.s32);
loc_8206B344:
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8206b528
	ctx.lr = 0x8206B354;
	sub_8206B528(ctx, base);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206b368
	if (!ctx.cr6.gt) goto loc_8206B368;
	// twi 31,r0,22
loc_8206B368:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x820612a0
	ctx.lr = 0x8206B384;
	sub_820612A0(ctx, base);
loc_8206B384:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8206B39C"))) PPC_WEAK_FUNC(sub_8206B39C);
PPC_FUNC_IMPL(__imp__sub_8206B39C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206B3A0"))) PPC_WEAK_FUNC(sub_8206B3A0);
PPC_FUNC_IMPL(__imp__sub_8206B3A0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8206b3d0
	if (!ctx.cr6.eq) goto loc_8206B3D0;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8206b3dc
	goto loc_8206B3DC;
loc_8206B3D0:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r10,r9,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r8,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
loc_8206B3DC:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r9,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206b404
	if (!ctx.cr6.lt) goto loc_8206B404;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// b 0x8206b494
	goto loc_8206B494;
loc_8206B404:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206b410
	if (!ctx.cr6.gt) goto loc_8206B410;
	// twi 31,r0,22
loc_8206B410:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bne cr6,0x8206b430
	if (!ctx.cr6.eq) goto loc_8206B430;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8206b458
	goto loc_8206B458;
loc_8206B430:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206b43c
	if (!ctx.cr6.gt) goto loc_8206B43C;
	// twi 31,r0,22
loc_8206B43C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206b44c
	if (ctx.cr6.eq) goto loc_8206B44C;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8206b450
	if (ctx.cr6.eq) goto loc_8206B450;
loc_8206B44C:
	// twi 31,r0,22
loc_8206B450:
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r30,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r11.s32 >> 2;
loc_8206B458:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206b788
	ctx.lr = 0x8206B464;
	sub_8206B788(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206b478
	if (!ctx.cr6.gt) goto loc_8206B478;
	// twi 31,r0,22
loc_8206B478:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82061310
	ctx.lr = 0x8206B494;
	sub_82061310(ctx, base);
loc_8206B494:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8206B4AC"))) PPC_WEAK_FUNC(sub_8206B4AC);
PPC_FUNC_IMPL(__imp__sub_8206B4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206B4B0"))) PPC_WEAK_FUNC(sub_8206B4B0);
PPC_FUNC_IMPL(__imp__sub_8206B4B0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8206B4B8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8206b518
	if (ctx.cr6.eq) goto loc_8206B518;
	// addi r31,r3,4
	ctx.r31.s64 = ctx.r3.s64 + 4;
	// li r28,15
	ctx.r28.s64 = 15;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r29,-1
	ctx.r29.s64 = -1;
loc_8206B4E4:
	// addic. r11,r31,-4
	ctx.xer.ca = ctx.r31.u32 > 3;
	ctx.r11.s64 = ctx.r31.s64 + -4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8206b50c
	if (ctx.cr0.eq) goto loc_8206B50C;
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r30.u8);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r31,-4
	ctx.r3.s64 = ctx.r31.s64 + -4;
	// bl 0x820601f8
	ctx.lr = 0x8206B50C;
	sub_820601F8(ctx, base);
loc_8206B50C:
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// bne 0x8206b4e4
	if (!ctx.cr0.eq) goto loc_8206B4E4;
loc_8206B518:
	// mulli r11,r25,28
	ctx.r11.s64 = ctx.r25.s64 * 28;
	// add r3,r11,r24
	ctx.r3.u64 = ctx.r11.u64 + ctx.r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206B528"))) PPC_WEAK_FUNC(sub_8206B528);
PPC_FUNC_IMPL(__imp__sub_8206B528) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x8206B530;
	__savegprlr_25(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r4,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r4.u64);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// li r27,28
	ctx.r27.s64 = 28;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b558
	if (!ctx.cr6.eq) goto loc_8206B558;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8206b564
	goto loc_8206B564;
loc_8206B558:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r8,r9,r27
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r27.s32);
loc_8206B564:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,2340
	ctx.r10.s64 = 153354240;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r11.s64;
	// ori r10,r10,37449
	ctx.r10.u64 = ctx.r10.u64 | 37449;
	// divw r11,r7,r27
	ctx.r11.s32 = ppc_divw(ctx.r7.s32, ctx.r27.s32);
	// subf r6,r11,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x8206b590
	if (!ctx.cr6.lt) goto loc_8206B590;
	// bl 0x820686c0
	ctx.lr = 0x8206B588;
	sub_820686C0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8206B590:
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8206b664
	if (!ctx.cr6.lt) goto loc_8206B664;
	// rlwinm r11,r8,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// li r26,0
	ctx.r26.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8206b5b4
	if (ctx.cr6.lt) goto loc_8206B5B4;
	// add r26,r11,r8
	ctx.r26.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_8206B5B4:
	// cmplw cr6,r26,r7
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r7.u32, ctx.xer);
	// bge cr6,0x8206b5c0
	if (!ctx.cr6.lt) goto loc_8206B5C0;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
loc_8206B5C0:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x820613e0
	ctx.lr = 0x8206B5C8;
	sub_820613E0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,236(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// subf r10,r11,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r11.s64;
	// li r4,1
	ctx.r4.s64 = 1;
	// divw r28,r10,r27
	ctx.r28.s32 = ppc_divw(ctx.r10.s32, ctx.r27.s32);
	// mulli r11,r28,28
	ctx.r11.s64 = ctx.r28.s64 * 28;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// bl 0x8206b4b0
	ctx.lr = 0x8206B5F0;
	sub_8206B4B0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8206b9f8
	ctx.lr = 0x8206B600;
	sub_8206B9F8(ctx, base);
	// addi r9,r28,1
	ctx.r9.s64 = ctx.r28.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mulli r11,r9,28
	ctx.r11.s64 = ctx.r9.s64 * 28;
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8206b9f8
	ctx.lr = 0x8206B618;
	sub_8206B9F8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r8,r3,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r3.s64;
	// divw r11,r8,r27
	ctx.r11.s32 = ppc_divw(ctx.r8.s32, ctx.r27.s32);
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8206b640
	if (ctx.cr6.eq) goto loc_8206B640;
	// bl 0x82061380
	ctx.lr = 0x8206B638;
	sub_82061380(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x8206B640;
	sub_8207A630(ctx, base);
loc_8206B640:
	// mulli r10,r26,28
	ctx.r10.s64 = ctx.r26.s64 * 28;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// mulli r11,r29,28
	ctx.r11.s64 = ctx.r29.s64 * 28;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8206B664:
	// lwz r30,236(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// subf r11,r30,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r30.s64;
	// divw r10,r11,r27
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bge cr6,0x8206b6f8
	if (!ctx.cr6.lt) goto loc_8206B6F8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820608b0
	ctx.lr = 0x8206B684;
	sub_820608B0(ctx, base);
	// addi r5,r30,28
	ctx.r5.s64 = ctx.r30.s64 + 28;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x8206b9f8
	ctx.lr = 0x8206B694;
	sub_8206B9F8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// subf r11,r30,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r30.s64;
	// divw r10,r11,r27
	ctx.r10.s32 = ppc_divw(ctx.r11.s32, ctx.r27.s32);
	// subfic r4,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r4.s64 = 1 - ctx.r10.s64;
	// bl 0x8206b4b0
	ctx.lr = 0x8206B6AC;
	sub_8206B4B0(ctx, base);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// addi r29,r11,-28
	ctx.r29.s64 = ctx.r11.s64 + -28;
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8206b6e8
	if (ctx.cr6.eq) goto loc_8206B6E8;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_8206B6C8:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820601f8
	ctx.lr = 0x8206B6DC;
	sub_820601F8(ctx, base);
	// addi r30,r30,28
	ctx.r30.s64 = ctx.r30.s64 + 28;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8206b6c8
	if (!ctx.cr6.eq) goto loc_8206B6C8;
loc_8206B6E8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82065fe8
	ctx.lr = 0x8206B6F0;
	sub_82065FE8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_8206B6F8:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820608b0
	ctx.lr = 0x8206B700;
	sub_820608B0(ctx, base);
	// lwz r29,16(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r28,r29,-28
	ctx.r28.s64 = ctx.r29.s64 + -28;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206b9f8
	ctx.lr = 0x8206B718;
	sub_8206B9F8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8206b744
	if (ctx.cr6.eq) goto loc_8206B744;
	// subf r29,r28,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r28.s64;
loc_8206B72C:
	// addi r31,r31,-28
	ctx.r31.s64 = ctx.r31.s64 + -28;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// bl 0x8206ba98
	ctx.lr = 0x8206B73C;
	sub_8206BA98(ctx, base);
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8206b72c
	if (!ctx.cr6.eq) goto loc_8206B72C;
loc_8206B744:
	// addi r29,r30,28
	ctx.r29.s64 = ctx.r30.s64 + 28;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8206b778
	if (ctx.cr6.eq) goto loc_8206B778;
	// li r28,-1
	ctx.r28.s64 = -1;
loc_8206B758:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x8206B76C;
	sub_820601F8(ctx, base);
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x8206b758
	if (!ctx.cr6.eq) goto loc_8206B758;
loc_8206B778:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82065fe8
	ctx.lr = 0x8206B780;
	sub_82065FE8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206B788"))) PPC_WEAK_FUNC(sub_8206B788);
PPC_FUNC_IMPL(__imp__sub_8206B788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206B790;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r4,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r4.u64);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206b7b8
	if (!ctx.cr6.eq) goto loc_8206B7B8;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8206b7c4
	goto loc_8206B7C4;
loc_8206B7B8:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
loc_8206B7C4:
	// lwz r30,16(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// subf r8,r11,r30
	ctx.r8.s64 = ctx.r30.s64 - ctx.r11.s64;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x8206b7f4
	if (!ctx.cr6.lt) goto loc_8206B7F4;
	// bl 0x820686c0
	ctx.lr = 0x8206B7E8;
	sub_820686C0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8206B7F4:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206b8dc
	if (!ctx.cr6.lt) goto loc_8206B8DC;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// li r27,0
	ctx.r27.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8206b818
	if (ctx.cr6.lt) goto loc_8206B818;
	// add r27,r11,r9
	ctx.r27.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8206B818:
	// cmplw cr6,r27,r8
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206b824
	if (!ctx.cr6.lt) goto loc_8206B824;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
loc_8206B824:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x820719f8
	ctx.lr = 0x8206B82C;
	sub_820719F8(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r29,172(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f0,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// subf r10,r11,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r11.s64;
	// srawi r28,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r28.s64 = ctx.r10.s32 >> 2;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r11,r3
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + ctx.r3.u32, temp.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r5,r29
	ctx.r9.s64 = ctx.r29.s64 - ctx.r5.s64;
	// srawi. r11,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8206b868
	if (ctx.cr0.eq) goto loc_8206B868;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206B868;
	sub_8207A520(ctx, base);
loc_8206B868:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r29,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r29.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8206b894
	if (ctx.cr0.eq) goto loc_8206B894;
	// addi r10,r28,1
	ctx.r10.s64 = ctx.r28.s64 + 1;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206B894;
	sub_8207A520(ctx, base);
loc_8206B894:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8206b8b4
	if (ctx.cr6.eq) goto loc_8206B8B4;
	// bl 0x8207a630
	ctx.lr = 0x8206B8B4;
	sub_8207A630(ctx, base);
loc_8206B8B4:
	// rlwinm r11,r27,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8206B8DC:
	// lwz r29,172(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lfs f31,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// subf r11,r29,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r29.s64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8206b978
	if (!ctx.cr6.lt) goto loc_8206B978;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b910
	if (ctx.cr6.eq) goto loc_8206B910;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r3,r29,4
	ctx.r3.s64 = ctx.r29.s64 + 4;
	// bl 0x8207a520
	ctx.lr = 0x8206B910;
	sub_8207A520(ctx, base);
loc_8206B910:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r11,r29,r4
	ctx.r11.s64 = ctx.r4.s64 - ctx.r29.s64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// subfic r11,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r11.s64 = 1 - ctx.r10.s64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206b940
	if (ctx.cr6.eq) goto loc_8206B940;
	// stfs f31,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r4,4
	ctx.r3.s64 = ctx.r4.s64 + 4;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r5,r11,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// bl 0x8207df48
	ctx.lr = 0x8206B940;
	sub_8207DF48(ctx, base);
loc_8206B940:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// stw r10,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8206b9e8
	if (ctx.cr6.eq) goto loc_8206B9E8;
loc_8206B95C:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8206b95c
	if (!ctx.cr6.eq) goto loc_8206B95C;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
loc_8206B978:
	// addi r28,r30,-4
	ctx.r28.s64 = ctx.r30.s64 + -4;
	// subf r11,r28,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r28.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r27,r6,r30
	ctx.r27.u64 = ctx.r6.u64 + ctx.r30.u64;
	// beq 0x8206b9a0
	if (ctx.cr0.eq) goto loc_8206B9A0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206B9A0;
	sub_8207A520(ctx, base);
loc_8206B9A0:
	// subf r11,r29,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r29.s64;
	// stw r27,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r27.u32);
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8206b9c8
	if (!ctx.cr0.gt) goto loc_8206B9C8;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// subf r3,r11,r30
	ctx.r3.s64 = ctx.r30.s64 - ctx.r11.s64;
	// bl 0x8207a520
	ctx.lr = 0x8206B9C8;
	sub_8207A520(ctx, base);
loc_8206B9C8:
	// addi r10,r29,4
	ctx.r10.s64 = ctx.r29.s64 + 4;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8206b9e8
	if (ctx.cr6.eq) goto loc_8206B9E8;
loc_8206B9D8:
	// stfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8206b9d8
	if (!ctx.cr6.eq) goto loc_8206B9D8;
loc_8206B9E8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206B9F4"))) PPC_WEAK_FUNC(sub_8206B9F4);
PPC_FUNC_IMPL(__imp__sub_8206B9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206B9F8"))) PPC_WEAK_FUNC(sub_8206B9F8);
PPC_FUNC_IMPL(__imp__sub_8206B9F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206BA00;
	__savegprlr_26(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r27,15
	ctx.r27.s64 = 15;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r27.u32);
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// beq cr6,0x8206ba88
	if (ctx.cr6.eq) goto loc_8206BA88;
	// subf r29,r5,r3
	ctx.r29.s64 = ctx.r3.s64 - ctx.r5.s64;
	// li r26,-1
	ctx.r26.s64 = -1;
loc_8206BA30:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206ba58
	if (ctx.cr6.eq) goto loc_8206BA58;
	// stw r27,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r27.u32);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r30,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x8206BA58;
	sub_820601F8(ctx, base);
loc_8206BA58:
	// add r4,r29,r31
	ctx.r4.u64 = ctx.r29.u64 + ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206ba98
	ctx.lr = 0x8206BA64;
	sub_8206BA98(ctx, base);
	// addi r31,r31,28
	ctx.r31.s64 = ctx.r31.s64 + 28;
	// add r11,r29,r31
	ctx.r11.u64 = ctx.r29.u64 + ctx.r31.u64;
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8206ba30
	if (!ctx.cr6.eq) goto loc_8206BA30;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206ba88
	if (ctx.cr6.lt) goto loc_8206BA88;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x8206BA88;
	sub_8207A630(ctx, base);
loc_8206BA88:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206BA94"))) PPC_WEAK_FUNC(sub_8206BA94);
PPC_FUNC_IMPL(__imp__sub_8206BA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206BA98"))) PPC_WEAK_FUNC(sub_8206BA98);
PPC_FUNC_IMPL(__imp__sub_8206BA98) {
	PPC_FUNC_PROLOGUE();
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lwz r6,12(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// lwz r11,4(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r6,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r6.u32);
	// stw r5,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r5.u32);
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r8,8(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r7,12(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// stw r7,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r7.u32);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// stw r8,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r8.u32);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// stw r10,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r10.u32);
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r7,24(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// stw r8,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206BB34"))) PPC_WEAK_FUNC(sub_8206BB34);
PPC_FUNC_IMPL(__imp__sub_8206BB34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206BB38"))) PPC_WEAK_FUNC(sub_8206BB38);
PPC_FUNC_IMPL(__imp__sub_8206BB38) {
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
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// sth r11,4(r31)
	PPC_STORE_U16(ctx.r31.u32 + 4, ctx.r11.u16);
	// bl 0x8207adf0
	ctx.lr = 0x8206BB70;
	sub_8207ADF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8206a848
	ctx.lr = 0x8206BB80;
	sub_8206A848(ctx, base);
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

__attribute__((alias("__imp__sub_8206BB9C"))) PPC_WEAK_FUNC(sub_8206BB9C);
PPC_FUNC_IMPL(__imp__sub_8206BB9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206BBA0"))) PPC_WEAK_FUNC(sub_8206BBA0);
PPC_FUNC_IMPL(__imp__sub_8206BBA0) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// clrlwi r9,r5,26
	ctx.r9.u64 = ctx.r5.u32 & 0x3F;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// blt cr6,0x8206bbbc
	if (ctx.cr6.lt) goto loc_8206BBBC;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
loc_8206BBBC:
	// cmpwi cr6,r6,2
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2, ctx.xer);
	// bne cr6,0x8206bbc8
	if (!ctx.cr6.eq) goto loc_8206BBC8;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_8206BBC8:
	// addi r11,r11,79
	ctx.r11.s64 = ctx.r11.s64 + 79;
	// li r8,80
	ctx.r8.s64 = 80;
	// addi r6,r10,15
	ctx.r6.s64 = ctx.r10.s64 + 15;
	// divwu r11,r11,r8
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r8.u32);
	// rlwinm r8,r6,0,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r9,21
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 21, ctx.xer);
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// beq cr6,0x8206bc00
	if (ctx.cr6.eq) goto loc_8206BC00;
	// cmpwi cr6,r9,32
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 32, ctx.xer);
	// beq cr6,0x8206bc00
	if (ctx.cr6.eq) goto loc_8206BC00;
	// cmpwi cr6,r9,37
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 37, ctx.xer);
	// bne cr6,0x8206bc04
	if (!ctx.cr6.eq) goto loc_8206BC04;
loc_8206BC00:
	// li r7,8
	ctx.r7.s64 = 8;
loc_8206BC04:
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// mullw r10,r11,r7
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// li r9,5120
	ctx.r9.s64 = 5120;
	// divwu r3,r10,r9
	ctx.r3.u32 = ppc_divwu(ctx.r10.u32, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206BC18"))) PPC_WEAK_FUNC(sub_8206BC18);
PPC_FUNC_IMPL(__imp__sub_8206BC18) {
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
	// bl 0x82080368
	ctx.lr = 0x8206BC2C;
	__savefpr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x8207af40
	ctx.lr = 0x8206BC3C;
	sub_8207AF40(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8207ae60
	ctx.lr = 0x8206BC48;
	sub_8207AE60(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f9,f12,f30
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f30.f64));
	// lfs f2,12(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f3,f6,f30
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f30.f64));
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f29,f2,f30
	ctx.f29.f64 = double(float(ctx.f2.f64 * ctx.f30.f64));
	// lfs f10,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// lfs f8,20(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f30
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f30.f64));
	// lfs f4,24(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f5,f8,f30
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f30.f64));
	// lfs f31,28(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f1,f4,f30
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f30.f64));
	// fmuls f30,f31,f30
	ctx.f30.f64 = double(float(ctx.f31.f64 * ctx.f30.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fneg f28,f0
	ctx.f28.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fmadds f13,f13,f0,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64 + ctx.f9.f64));
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 16, temp.u32);
	// fmadds f10,f10,f0,f5
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64 + ctx.f5.f64));
	// stfs f10,20(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// fmadds f9,f6,f0,f1
	ctx.f9.f64 = double(float(ctx.f6.f64 * ctx.f0.f64 + ctx.f1.f64));
	// stfs f9,24(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// fmadds f6,f2,f0,f30
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f0.f64 + ctx.f30.f64));
	// stfs f6,28(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// fmadds f5,f12,f28,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f28.f64 + ctx.f11.f64));
	// stfs f5,0(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// fmadds f2,f8,f28,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f28.f64 + ctx.f7.f64));
	// stfs f2,4(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// fmadds f1,f4,f28,f3
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f28.f64 + ctx.f3.f64));
	// stfs f1,8(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r31.u32 + 8, temp.u32);
	// fmadds f0,f31,f28,f29
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f28.f64 + ctx.f29.f64));
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// addi r12,r1,-16
	ctx.r12.s64 = ctx.r1.s64 + -16;
	// bl 0x820803b4
	ctx.lr = 0x8206BCE0;
	__restfpr_28(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206BCF0"))) PPC_WEAK_FUNC(sub_8206BCF0);
PPC_FUNC_IMPL(__imp__sub_8206BCF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x82080330
	ctx.lr = 0x8206BD00;
	__savefpr_14(ctx, base);
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f11,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmuls f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f12,36(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lfs f4,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f6,f11,f12
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f3,20(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f4,f0
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f0.f64));
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f31,f3,f0
	ctx.f31.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// lfs f1,24(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f29,f4,f13
	ctx.f29.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// lfs f30,44(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// lfs f7,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f22,f4,f12
	ctx.f22.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fmuls f27,f3,f13
	ctx.f27.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// lfs f5,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f20,f3,f12
	ctx.f20.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// lfs f28,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// fmadds f10,f30,f9,f10
	ctx.f10.f64 = double(float(ctx.f30.f64 * ctx.f9.f64 + ctx.f10.f64));
	// lfs f24,32(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	ctx.f24.f64 = double(temp.f32);
	// fmadds f8,f30,f7,f8
	ctx.f8.f64 = double(float(ctx.f30.f64 * ctx.f7.f64 + ctx.f8.f64));
	// lfs f23,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f23.f64 = double(temp.f32);
	// fmuls f13,f1,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// lfs f19,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	ctx.f19.f64 = double(temp.f32);
	// fmuls f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lfs f21,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f21.f64 = double(temp.f32);
	// fmadds f6,f30,f5,f6
	ctx.f6.f64 = double(float(ctx.f30.f64 * ctx.f5.f64 + ctx.f6.f64));
	// lfs f26,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f26.f64 = double(temp.f32);
	// fmadds f2,f24,f9,f2
	ctx.f2.f64 = double(float(ctx.f24.f64 * ctx.f9.f64 + ctx.f2.f64));
	// lfs f25,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f25.f64 = double(temp.f32);
	// fmadds f0,f19,f9,f0
	ctx.f0.f64 = double(float(ctx.f19.f64 * ctx.f9.f64 + ctx.f0.f64));
	// lfs f18,52(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	ctx.f18.f64 = double(temp.f32);
	// fmadds f31,f21,f9,f31
	ctx.f31.f64 = double(float(ctx.f21.f64 * ctx.f9.f64 + ctx.f31.f64));
	// lfs f17,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f17.f64 = double(temp.f32);
	// fmadds f29,f24,f7,f29
	ctx.f29.f64 = double(float(ctx.f24.f64 * ctx.f7.f64 + ctx.f29.f64));
	// lfs f15,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f15.f64 = double(temp.f32);
	// fmadds f27,f21,f7,f27
	ctx.f27.f64 = double(float(ctx.f21.f64 * ctx.f7.f64 + ctx.f27.f64));
	// lfs f9,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f10,f23,f28,f10
	ctx.f10.f64 = double(float(ctx.f23.f64 * ctx.f28.f64 + ctx.f10.f64));
	// lfs f16,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f16.f64 = double(temp.f32);
	// fmadds f8,f23,f26,f8
	ctx.f8.f64 = double(float(ctx.f23.f64 * ctx.f26.f64 + ctx.f8.f64));
	// stfs f30,-168(r1)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + -168, temp.u32);
	// fmadds f22,f24,f5,f22
	ctx.f22.f64 = double(float(ctx.f24.f64 * ctx.f5.f64 + ctx.f22.f64));
	// stfs f1,-176(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -176, temp.u32);
	// fmadds f20,f21,f5,f20
	ctx.f20.f64 = double(float(ctx.f21.f64 * ctx.f5.f64 + ctx.f20.f64));
	// lfs f14,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f14.f64 = double(temp.f32);
	// fmadds f7,f19,f7,f13
	ctx.f7.f64 = double(float(ctx.f19.f64 * ctx.f7.f64 + ctx.f13.f64));
	// lfs f13,48(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f5,f19,f5,f12
	ctx.f5.f64 = double(float(ctx.f19.f64 * ctx.f5.f64 + ctx.f12.f64));
	// stfs f13,-172(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -172, temp.u32);
	// fmadds f12,f23,f25,f6
	ctx.f12.f64 = double(float(ctx.f23.f64 * ctx.f25.f64 + ctx.f6.f64));
	// lfs f30,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f6,f4,f18
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f18.f64));
	// lfs f1,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,60(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f4,f17,f28,f2
	ctx.f4.f64 = double(float(ctx.f17.f64 * ctx.f28.f64 + ctx.f2.f64));
	// fmadds f0,f15,f28,f0
	ctx.f0.f64 = double(float(ctx.f15.f64 * ctx.f28.f64 + ctx.f0.f64));
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fadds f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f9.f64));
	// stfs f4,0(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fmadds f2,f16,f28,f31
	ctx.f2.f64 = double(float(ctx.f16.f64 * ctx.f28.f64 + ctx.f31.f64));
	// stfs f2,4(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// fmadds f9,f17,f26,f29
	ctx.f9.f64 = double(float(ctx.f17.f64 * ctx.f26.f64 + ctx.f29.f64));
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fadds f0,f8,f14
	ctx.f0.f64 = double(float(ctx.f8.f64 + ctx.f14.f64));
	// stfs f9,16(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fmadds f4,f16,f26,f27
	ctx.f4.f64 = double(float(ctx.f16.f64 * ctx.f26.f64 + ctx.f27.f64));
	// stfs f4,20(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fmadds f2,f15,f26,f7
	ctx.f2.f64 = double(float(ctx.f15.f64 * ctx.f26.f64 + ctx.f7.f64));
	// stfs f2,24(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fmadds f10,f17,f25,f22
	ctx.f10.f64 = double(float(ctx.f17.f64 * ctx.f25.f64 + ctx.f22.f64));
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// fmadds f9,f16,f25,f20
	ctx.f9.f64 = double(float(ctx.f16.f64 * ctx.f25.f64 + ctx.f20.f64));
	// stfs f10,32(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fmadds f8,f15,f25,f5
	ctx.f8.f64 = double(float(ctx.f15.f64 * ctx.f25.f64 + ctx.f5.f64));
	// stfs f9,36(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f8,40(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fmuls f5,f11,f18
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f18.f64));
	// lfs f11,-168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -168);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f4,f3,f18
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f18.f64));
	// lfs f3,-176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -176);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f2,f3,f18
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f18.f64));
	// lfs f0,-172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -172);
	ctx.f0.f64 = double(temp.f32);
	// fadds f7,f12,f30
	ctx.f7.f64 = double(float(ctx.f12.f64 + ctx.f30.f64));
	// stfs f7,44(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fmadds f6,f24,f1,f6
	ctx.f6.f64 = double(float(ctx.f24.f64 * ctx.f1.f64 + ctx.f6.f64));
	// fmadds f10,f11,f1,f5
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 + ctx.f5.f64));
	// fmadds f9,f21,f1,f4
	ctx.f9.f64 = double(float(ctx.f21.f64 * ctx.f1.f64 + ctx.f4.f64));
	// fmadds f8,f19,f1,f2
	ctx.f8.f64 = double(float(ctx.f19.f64 * ctx.f1.f64 + ctx.f2.f64));
	// fmadds f12,f17,f0,f6
	ctx.f12.f64 = double(float(ctx.f17.f64 * ctx.f0.f64 + ctx.f6.f64));
	// stfs f12,48(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// fmadds f7,f23,f0,f10
	ctx.f7.f64 = double(float(ctx.f23.f64 * ctx.f0.f64 + ctx.f10.f64));
	// fmadds f6,f16,f0,f9
	ctx.f6.f64 = double(float(ctx.f16.f64 * ctx.f0.f64 + ctx.f9.f64));
	// stfs f6,52(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fmadds f5,f15,f0,f8
	ctx.f5.f64 = double(float(ctx.f15.f64 * ctx.f0.f64 + ctx.f8.f64));
	// stfs f5,56(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fadds f4,f7,f13
	ctx.f4.f64 = double(float(ctx.f7.f64 + ctx.f13.f64));
	// stfs f4,60(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// addi r12,r1,-8
	ctx.r12.s64 = ctx.r1.s64 + -8;
	// bl 0x8208037c
	ctx.lr = 0x8206BEA0;
	__restfpr_14(ctx, base);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206BEAC"))) PPC_WEAK_FUNC(sub_8206BEAC);
PPC_FUNC_IMPL(__imp__sub_8206BEAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206BEB0"))) PPC_WEAK_FUNC(sub_8206BEB0);
PPC_FUNC_IMPL(__imp__sub_8206BEB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fadds f9,f1,f13
	ctx.f9.f64 = double(float(ctx.f1.f64 + ctx.f13.f64));
	// lfs f12,44(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fadds f8,f2,f13
	ctx.f8.f64 = double(float(ctx.f2.f64 + ctx.f13.f64));
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// fsubs f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// stfs f0,56(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// fsubs f4,f13,f8
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// lfs f11,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// fadds f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// lfs f10,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fadds f3,f8,f13
	ctx.f3.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// stfs f10,60(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// fsubs f2,f8,f13
	ctx.f2.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fdivs f1,f12,f7
	ctx.f1.f64 = double(float(ctx.f12.f64 / ctx.f7.f64));
	// stfs f1,0(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fdivs f13,f12,f4
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f4.f64));
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fdivs f0,f6,f5
	ctx.f0.f64 = double(float(ctx.f6.f64 / ctx.f5.f64));
	// stfs f0,12(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fdivs f12,f3,f2
	ctx.f12.f64 = double(float(ctx.f3.f64 / ctx.f2.f64));
	// stfs f12,28(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206BF48"))) PPC_WEAK_FUNC(sub_8206BF48);
PPC_FUNC_IMPL(__imp__sub_8206BF48) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8206BF50;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// bne cr6,0x8206bf6c
	if (!ctx.cr6.eq) goto loc_8206BF6C;
	// addi r31,r31,-1
	ctx.r31.s64 = ctx.r31.s64 + -1;
loc_8206BF6C:
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,1836
	ctx.r9.s64 = ctx.r11.s64 + 1836;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8209d800
	ctx.lr = 0x8206BF98;
	sub_8209D800(ctx, base);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mullw r5,r7,r31
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r31.s32);
	// bl 0x8207dac0
	ctx.lr = 0x8206BFA8;
	sub_8207DAC0(ctx, base);
	// lwz r11,-31312(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31312);
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8209d7f0
	ctx.lr = 0x8206BFB8;
	sub_8209D7F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206BFC0"))) PPC_WEAK_FUNC(sub_8206BFC0);
PPC_FUNC_IMPL(__imp__sub_8206BFC0) {
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
	// bl 0x82181f60
	ctx.lr = 0x8206BFE0;
	sub_82181F60(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206bff8
	if (ctx.cr6.eq) goto loc_8206BFF8;
	// bl 0x8207a630
	ctx.lr = 0x8206BFF4;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206BFF8:
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

__attribute__((alias("__imp__sub_8206C010"))) PPC_WEAK_FUNC(sub_8206C010);
PPC_FUNC_IMPL(__imp__sub_8206C010) {
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
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206c034
	if (!ctx.cr6.eq) goto loc_8206C034;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8206c040
	goto loc_8206C040;
loc_8206C034:
	// lwz r11,20(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r9,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 5;
loc_8206C040:
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r7,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 5;
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8206c090
	if (!ctx.cr6.lt) goto loc_8206C090;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c078
	if (ctx.cr6.eq) goto loc_8206C078;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r10,r6,-4
	ctx.r10.s64 = ctx.r6.s64 + -4;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8206C06C:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8206c06c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C06C;
loc_8206C078:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8206C090:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206c09c
	if (!ctx.cr6.gt) goto loc_8206C09C;
	// twi 31,r0,22
loc_8206C09C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206c0c8
	ctx.lr = 0x8206C0B8;
	sub_8206C0C8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206C0C8"))) PPC_WEAK_FUNC(sub_8206C0C8);
PPC_FUNC_IMPL(__imp__sub_8206C0C8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8206C0D0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// std r5,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r5.u64);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// rlwinm r8,r9,0,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFE0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8206c104
	if (!ctx.cr6.eq) goto loc_8206C104;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8206c138
	goto loc_8206C138;
loc_8206C104:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206c110
	if (!ctx.cr6.gt) goto loc_8206C110;
	// twi 31,r0,22
loc_8206C110:
	// lwz r9,160(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206c128
	if (ctx.cr6.eq) goto loc_8206C128;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206c12c
	if (ctx.cr6.eq) goto loc_8206C12C;
loc_8206C128:
	// twi 31,r0,22
loc_8206C12C:
	// lwz r11,164(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// subf r10,r10,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r10.s64;
	// srawi r30,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r30.s64 = ctx.r10.s32 >> 5;
loc_8206C138:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206c1d8
	ctx.lr = 0x8206C144;
	sub_8206C1D8(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206c158
	if (!ctx.cr6.gt) goto loc_8206C158;
	// twi 31,r0,22
loc_8206C158:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// bne cr6,0x8206c1a0
	if (!ctx.cr6.eq) goto loc_8206C1A0;
	// twi 31,r0,22
	// li r9,0
	ctx.r9.s64 = 0;
loc_8206C17C:
	// rlwinm r10,r30,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8206c1b8
	if (ctx.cr6.gt) goto loc_8206C1B8;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206c1a8
	if (ctx.cr6.eq) goto loc_8206C1A8;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x8206c1ac
	goto loc_8206C1AC;
loc_8206C1A0:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x8206c17c
	goto loc_8206C17C;
loc_8206C1A8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8206C1AC:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8206c1bc
	if (!ctx.cr6.lt) goto loc_8206C1BC;
loc_8206C1B8:
	// twi 31,r0,22
loc_8206C1BC:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r29)
	PPC_STORE_U64(ctx.r29.u32 + 0, ctx.r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206C1D4"))) PPC_WEAK_FUNC(sub_8206C1D4);
PPC_FUNC_IMPL(__imp__sub_8206C1D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206C1D8"))) PPC_WEAK_FUNC(sub_8206C1D8);
PPC_FUNC_IMPL(__imp__sub_8206C1D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8206C1E0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// std r4,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r4.u64);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206c204
	if (!ctx.cr6.eq) goto loc_8206C204;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8206c210
	goto loc_8206C210;
loc_8206C204:
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// srawi r9,r9,5
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 5;
loc_8206C210:
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// lis r10,2047
	ctx.r10.s64 = 134152192;
	// subf r8,r11,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r11.s64;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// srawi r11,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 5;
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplwi cr6,r7,1
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 1, ctx.xer);
	// bge cr6,0x8206c23c
	if (!ctx.cr6.lt) goto loc_8206C23C;
	// bl 0x820686c0
	ctx.lr = 0x8206C234;
	sub_820686C0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8206C23C:
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206c394
	if (!ctx.cr6.lt) goto loc_8206C394;
	// rlwinm r11,r9,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// li r29,0
	ctx.r29.s64 = 0;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r11.s64;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8206c260
	if (ctx.cr6.lt) goto loc_8206C260;
	// add r29,r11,r9
	ctx.r29.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8206C260:
	// cmplw cr6,r29,r8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206c26c
	if (!ctx.cr6.lt) goto loc_8206C26C;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
loc_8206C26C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82069128
	ctx.lr = 0x8206C274;
	sub_82069128(ctx, base);
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r6,188(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r11.s64;
	// srawi r5,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 5;
	// rlwinm r4,r5,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add. r11,r4,r3
	ctx.r11.u64 = ctx.r4.u64 + ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8206c2b0
	if (ctx.cr0.eq) goto loc_8206C2B0;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r10,r31,-4
	ctx.r10.s64 = ctx.r31.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8206C2A4:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8206c2a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C2A4;
loc_8206C2B0:
	// lwz r11,12(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8206c2f4
	if (ctx.cr6.eq) goto loc_8206C2F4;
loc_8206C2C0:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x8206c2e4
	if (ctx.cr6.eq) goto loc_8206C2E4;
	// li r8,8
	ctx.r8.s64 = 8;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// addi r9,r7,-4
	ctx.r9.s64 = ctx.r7.s64 + -4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_8206C2D8:
	// lwzu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8206c2d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C2D8;
loc_8206C2E4:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8206c2c0
	if (!ctx.cr6.eq) goto loc_8206C2C0;
loc_8206C2F4:
	// addi r11,r5,1
	ctx.r11.s64 = ctx.r5.s64 + 1;
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// rlwinm r11,r11,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xFFFFFFE0;
	// cmplw cr6,r6,r5
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, ctx.xer);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// beq cr6,0x8206c350
	if (ctx.cr6.eq) goto loc_8206C350;
	// subf r10,r4,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r4.s64;
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r30.s64;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// addi r8,r10,-32
	ctx.r8.s64 = ctx.r10.s64 + -32;
loc_8206C31C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c340
	if (ctx.cr6.eq) goto loc_8206C340;
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8206C334:
	// lwzu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8206c334
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C334;
loc_8206C340:
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x8206c31c
	if (!ctx.cr6.eq) goto loc_8206C31C;
loc_8206C350:
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// subf r10,r3,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi r11,r10,5
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 5;
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// beq cr6,0x8206c370
	if (ctx.cr6.eq) goto loc_8206C370;
	// bl 0x8207a630
	ctx.lr = 0x8206C370;
	sub_8207A630(ctx, base);
loc_8206C370:
	// rlwinm r11,r29,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r30,12(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12, ctx.r30.u32);
	// rlwinm r10,r31,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// stw r11,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r11.u32);
	// stw r10,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8206C394:
	// lwz r3,188(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// li r9,8
	ctx.r9.s64 = 8;
	// subf r11,r3,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// addi r11,r31,-4
	ctx.r11.s64 = ctx.r31.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// addi r10,r1,76
	ctx.r10.s64 = ctx.r1.s64 + 76;
	// bge cr6,0x8206c474
	if (!ctx.cr6.lt) goto loc_8206C474;
loc_8206C3B8:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8206c3b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C3B8;
	// addi r8,r3,32
	ctx.r8.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8206c408
	if (ctx.cr6.eq) goto loc_8206C408;
	// addi r7,r8,-32
	ctx.r7.s64 = ctx.r8.s64 + -32;
loc_8206C3D4:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206c3f8
	if (ctx.cr6.eq) goto loc_8206C3F8;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8206C3EC:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8206c3ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C3EC;
loc_8206C3F8:
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// cmplw cr6,r7,r5
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x8206c3d4
	if (!ctx.cr6.eq) goto loc_8206C3D4;
loc_8206C408:
	// lwz r8,16(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// subf r11,r3,r8
	ctx.r11.s64 = ctx.r8.s64 - ctx.r3.s64;
	// srawi r10,r11,5
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 5;
	// subfic r11,r10,1
	ctx.xer.ca = ctx.r10.u32 <= 1;
	ctx.r11.s64 = 1 - ctx.r10.s64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206c454
	if (ctx.cr6.eq) goto loc_8206C454;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
loc_8206C424:
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206c448
	if (ctx.cr6.eq) goto loc_8206C448;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r11,r1,76
	ctx.r11.s64 = ctx.r1.s64 + 76;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8206C43C:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8206c43c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C43C;
loc_8206C448:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// bne 0x8206c424
	if (!ctx.cr0.eq) goto loc_8206C424;
loc_8206C454:
	// lwz r11,16(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// stw r11,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// addi r4,r11,-32
	ctx.r4.s64 = ctx.r11.s64 + -32;
	// bl 0x8206c590
	ctx.lr = 0x8206C46C;
	sub_8206C590(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8206C474:
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8206c474
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C474;
	// addi r6,r5,-32
	ctx.r6.s64 = ctx.r5.s64 + -32;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// cmplw cr6,r6,r5
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x8206c4c8
	if (ctx.cr6.eq) goto loc_8206C4C8;
loc_8206C494:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206c4b8
	if (ctx.cr6.eq) goto loc_8206C4B8;
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r11,r8,-4
	ctx.r11.s64 = ctx.r8.s64 + -4;
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8206C4AC:
	// lwzu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stwu r7,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8206c4ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8206C4AC;
loc_8206C4B8:
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// cmplw cr6,r8,r5
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r5.u32, ctx.xer);
	// bne cr6,0x8206c494
	if (!ctx.cr6.eq) goto loc_8206C494;
loc_8206C4C8:
	// stw r9,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r9.u32);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// cmplw cr6,r3,r6
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x8206c528
	if (ctx.cr6.eq) goto loc_8206C528;
	// addi r11,r6,56
	ctx.r11.s64 = ctx.r6.s64 + 56;
loc_8206C4DC:
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
	// lfsu f0,-32(r10)
	ctx.fpscr.disableFlushMode();
	ea = -32 + ctx.r10.u32;
	temp.u32 = PPC_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// stfs f0,-24(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + -24, temp.u32);
	// lfs f13,-52(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-20(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + -20, temp.u32);
	// lfs f12,-48(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -48);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,-16(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + -16, temp.u32);
	// lfs f11,-44(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -44);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,-12(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + -12, temp.u32);
	// lfs f10,-40(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -40);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,-8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// lfs f9,-36(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -36);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lfs f8,-32(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f7,-28(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -28);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,4(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// bne cr6,0x8206c4dc
	if (!ctx.cr6.eq) goto loc_8206C4DC;
loc_8206C528:
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8206c590
	ctx.lr = 0x8206C534;
	sub_8206C590(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206C53C"))) PPC_WEAK_FUNC(sub_8206C53C);
PPC_FUNC_IMPL(__imp__sub_8206C53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206C540"))) PPC_WEAK_FUNC(sub_8206C540);
PPC_FUNC_IMPL(__imp__sub_8206C540) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8207aba0
	ctx.lr = 0x8206C580;
	sub_8207ABA0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206C590"))) PPC_WEAK_FUNC(sub_8206C590);
PPC_FUNC_IMPL(__imp__sub_8206C590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// addi r10,r5,16
	ctx.r10.s64 = ctx.r5.s64 + 16;
	// addi r11,r3,24
	ctx.r11.s64 = ctx.r3.s64 + 24;
loc_8206C5A0:
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-24(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + -24, temp.u32);
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-20(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r11.u32 + -20, temp.u32);
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,-16(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r11.u32 + -16, temp.u32);
	// lfs f11,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,-12(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r11.u32 + -12, temp.u32);
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,-8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r11.u32 + -8, temp.u32);
	// lfs f9,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lfs f8,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f7,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,4(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r9,r11,-24
	ctx.r9.s64 = ctx.r11.s64 + -24;
	// cmplw cr6,r9,r4
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x8206c5a0
	if (!ctx.cr6.eq) goto loc_8206C5A0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206C5F4"))) PPC_WEAK_FUNC(sub_8206C5F4);
PPC_FUNC_IMPL(__imp__sub_8206C5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206C5F8"))) PPC_WEAK_FUNC(sub_8206C5F8);
PPC_FUNC_IMPL(__imp__sub_8206C5F8) {
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
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// lfs f0,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// blt cr6,0x8206c63c
	if (ctx.cr6.lt) goto loc_8206C63C;
	// fadds f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// bl 0x8207abb0
	ctx.lr = 0x8206C628;
	sub_8207ABB0(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8206C63C:
	// fsubs f1,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// bl 0x8207b570
	ctx.lr = 0x8206C644;
	sub_8207B570(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206C658"))) PPC_WEAK_FUNC(sub_8206C658);
PPC_FUNC_IMPL(__imp__sub_8206C658) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// fcmpu cr6,f1,f2
	ctx.cr6.compare(ctx.f1.f64, ctx.f2.f64);
	// bne cr6,0x8206c684
	if (!ctx.cr6.eq) goto loc_8206C684;
	// b 0x8206c6f0
	goto loc_8206C6F0;
loc_8206C684:
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r3,-31016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31016);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206c6b4
	if (!ctx.cr6.eq) goto loc_8206C6B4;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82079fd8
	ctx.lr = 0x8206C69C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206c6ac
	if (ctx.cr6.eq) goto loc_8206C6AC;
	// bl 0x82167b28
	ctx.lr = 0x8206C6A8;
	sub_82167B28(ctx, base);
	// b 0x8206c6b0
	goto loc_8206C6B0;
loc_8206C6AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8206C6B0:
	// stw r3,-31016(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31016, ctx.r3.u32);
loc_8206C6B4:
	// bl 0x82167910
	ctx.lr = 0x8206C6B8;
	sub_82167910(ctx, base);
	// clrldi r11,r3,32
	ctx.r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,72(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	ctx.f0.f64 = double(temp.f32);
	// lfd f2,48(r9)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r9.u32 + 48);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// bl 0x8207b020
	ctx.lr = 0x8206C6E4;
	sub_8207B020(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// fsubs f10,f30,f31
	ctx.f10.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// fmadds f1,f11,f10,f31
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f31.f64));
loc_8206C6F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8206C70C"))) PPC_WEAK_FUNC(sub_8206C70C);
PPC_FUNC_IMPL(__imp__sub_8206C70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206C710"))) PPC_WEAK_FUNC(sub_8206C710);
PPC_FUNC_IMPL(__imp__sub_8206C710) {
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
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x82080368
	ctx.lr = 0x8206C728;
	__savefpr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// std r3,208(r1)
	PPC_STORE_U64(ctx.r1.u32 + 208, ctx.r3.u64);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// addi r5,r11,5164
	ctx.r5.s64 = ctx.r11.s64 + 5164;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8206C748;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r5,r9,5168
	ctx.r5.s64 = ctx.r9.s64 + 5168;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// bl 0x82175ae8
	ctx.lr = 0x8206C768;
	sub_82175AE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r5,r6,5172
	ctx.r5.s64 = ctx.r6.s64 + 5172;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// ld r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bl 0x82175ae8
	ctx.lr = 0x8206C788;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// bl 0x82175648
	ctx.lr = 0x8206C7A4;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C7A8;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x8206c7c8
	if (ctx.cr6.gt) goto loc_8206C7C8;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206C7C0;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C7C4;
	sub_82175BB0(ctx, base);
	// b 0x8206c938
	goto loc_8206C938;
loc_8206C7C8:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r31,r11,1
	ctx.r31.s64 = ctx.r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82174af8
	ctx.lr = 0x8206C7D8;
	sub_82174AF8(ctx, base);
	// addi r5,r3,-1
	ctx.r5.s64 = ctx.r3.s64 + -1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206C7E8;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C7EC;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// blt cr6,0x8206c814
	if (ctx.cr6.lt) goto loc_8206C814;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82174af8
	ctx.lr = 0x8206C7FC;
	sub_82174AF8(ctx, base);
	// addi r5,r3,-1
	ctx.r5.s64 = ctx.r3.s64 + -1;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206C80C;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C810;
	sub_82175BB0(ctx, base);
	// b 0x8206c938
	goto loc_8206C938;
loc_8206C814:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// li r31,0
	ctx.r31.s64 = 0;
	// bl 0x82175648
	ctx.lr = 0x8206C828;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C82C;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// ble cr6,0x8206c854
	if (!ctx.cr6.gt) goto loc_8206C854;
loc_8206C834:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175648
	ctx.lr = 0x8206C848;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C84C;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x8206c834
	if (ctx.cr6.gt) goto loc_8206C834;
loc_8206C854:
	// addi r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206C868;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C86C;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175648
	ctx.lr = 0x8206C880;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C884;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fsubs f30,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f30.f64 - ctx.f1.f64));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206C898;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C89C;
	sub_82175BB0(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f1.f64));
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f31,f13,f30
	ctx.f31.f64 = double(float(ctx.f13.f64 / ctx.f30.f64));
	// fsubs f29,f0,f31
	ctx.f29.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// bl 0x82175648
	ctx.lr = 0x8206C8C0;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C8C4;
	sub_82175BB0(ctx, base);
	// fmuls f12,f31,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f31.f64));
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// fmsubs f11,f12,f31,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f31.f64 - ctx.f31.f64));
	// fmuls f28,f1,f11
	ctx.f28.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// bl 0x82175648
	ctx.lr = 0x8206C8E0;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C8E4;
	sub_82175BB0(ctx, base);
	// fmuls f10,f29,f29
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f29.f64 * ctx.f29.f64));
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,200(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 200);
	ctx.f0.f64 = double(temp.f32);
	// fmsubs f9,f10,f29,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f29.f64 - ctx.f29.f64));
	// fmadds f8,f1,f9,f28
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f9.f64 + ctx.f28.f64));
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f30.f64));
	// fmuls f6,f7,f30
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f30.f64));
	// fmuls f30,f6,f0
	ctx.f30.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// bl 0x82175648
	ctx.lr = 0x8206C918;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C91C;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// fmadds f31,f1,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 * ctx.f31.f64 + ctx.f30.f64));
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82175648
	ctx.lr = 0x8206C930;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206C934;
	sub_82175BB0(ctx, base);
	// fmadds f1,f1,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f29.f64 + ctx.f31.f64));
loc_8206C938:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x820803b4
	ctx.lr = 0x8206C944;
	__restfpr_28(ctx, base);
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

__attribute__((alias("__imp__sub_8206C958"))) PPC_WEAK_FUNC(sub_8206C958);
PPC_FUNC_IMPL(__imp__sub_8206C958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8206C960;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// std r4,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r4.u64);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r4,r1,232
	ctx.r4.s64 = ctx.r1.s64 + 232;
	// addi r5,r11,5164
	ctx.r5.s64 = ctx.r11.s64 + 5164;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x82175ae8
	ctx.lr = 0x8206C98C;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r4,r1,232
	ctx.r4.s64 = ctx.r1.s64 + 232;
	// addi r5,r9,5168
	ctx.r5.s64 = ctx.r9.s64 + 5168;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// bl 0x82175ae8
	ctx.lr = 0x8206C9AC;
	sub_82175AE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r1,232
	ctx.r4.s64 = ctx.r1.s64 + 232;
	// addi r5,r6,5176
	ctx.r5.s64 = ctx.r6.s64 + 5176;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r11,0(r7)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// std r11,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// bl 0x82175ae8
	ctx.lr = 0x8206C9CC;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r4,r1,232
	ctx.r4.s64 = ctx.r1.s64 + 232;
	// addi r5,r9,5180
	ctx.r5.s64 = ctx.r9.s64 + 5180;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ld r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// bl 0x82175ae8
	ctx.lr = 0x8206C9EC;
	sub_82175AE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r31,0
	ctx.r31.s64 = 0;
	// ld r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// bl 0x82175648
	ctx.lr = 0x8206CA0C;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CA10;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// ble cr6,0x8206ca38
	if (!ctx.cr6.gt) goto loc_8206CA38;
loc_8206CA18:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175648
	ctx.lr = 0x8206CA2C;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CA30;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x8206ca18
	if (ctx.cr6.gt) goto loc_8206CA18;
loc_8206CA38:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175648
	ctx.lr = 0x8206CA48;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CA4C;
	sub_82175BB0(ctx, base);
	// addi r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fsubs f31,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f1.f64));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82175648
	ctx.lr = 0x8206CA60;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CA64;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x82175648
	ctx.lr = 0x8206CA78;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CA7C;
	sub_82175BB0(ctx, base);
	// fsubs f0,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f1.f64));
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// fdivs f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 / ctx.f0.f64));
	// bl 0x82175648
	ctx.lr = 0x8206CA94;
	sub_82175648(ctx, base);
	// ld r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8206c710
	ctx.lr = 0x8206CAA0;
	sub_8206C710(ctx, base);
	// rlwinm r11,r31,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r30,0
	ctx.r30.s64 = 0;
	// add r31,r31,r11
	ctx.r31.u64 = ctx.r31.u64 + ctx.r11.u64;
loc_8206CAB0:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// bl 0x82175648
	ctx.lr = 0x8206CAC0;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CAC4;
	sub_82175BB0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfsx f1,r30,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, temp.u32);
	// bl 0x82175648
	ctx.lr = 0x8206CADC;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CAE0;
	sub_82175BB0(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stfsx f1,r30,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, temp.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r30,16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16, ctx.xer);
	// blt cr6,0x8206cab0
	if (ctx.cr6.lt) goto loc_8206CAB0;
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f10,f13,f31
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f11,f31
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f31.f64));
	// fmuls f7,f9,f31
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f31.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// lfs f6,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f6,f31
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f31.f64));
	// fmuls f3,f5,f31
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f31.f64));
	// lfs f2,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,-21836(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,208(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f31.f64));
	// fmuls f11,f10,f31
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f31.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f10,f8,f0
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f9,f7,f31
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f31.f64));
	// fmuls f8,f4,f31
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f31.f64));
	// fmuls f7,f3,f31
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f31.f64));
	// fmuls f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f6,f2,f13,f12
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fmadds f4,f1,f13,f10
	ctx.f4.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmuls f3,f9,f0
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fmuls f2,f8,f31
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fmuls f1,f7,f31
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f31.f64));
	// fmadds f0,f6,f13,f5
	ctx.f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// fmadds f12,f4,f13,f3
	ctx.f12.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 + ctx.f3.f64));
	// fmadds f11,f0,f13,f2
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 + ctx.f2.f64));
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// fmadds f10,f12,f13,f1
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f1.f64));
	// stfs f10,4(r29)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-48(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206CBA0"))) PPC_WEAK_FUNC(sub_8206CBA0);
PPC_FUNC_IMPL(__imp__sub_8206CBA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8206CBA8;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x82080368
	ctx.lr = 0x8206CBB0;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x821746a0
	ctx.lr = 0x8206CBC4;
	sub_821746A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8206cbe0
	if (!ctx.cr6.eq) goto loc_8206CBE0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x820803b4
	ctx.lr = 0x8206CBDC;
	__restfpr_28(ctx, base);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8206CBE0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 44);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// bl 0x82175d08
	ctx.lr = 0x8206CBF8;
	sub_82175D08(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r5,r9,5184
	ctx.r5.s64 = ctx.r9.s64 + 5184;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8206CC10;
	sub_82175AE8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x82175648
	ctx.lr = 0x8206CC20;
	sub_82175648(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// addi r28,r11,-21836
	ctx.r28.s64 = ctx.r11.s64 + -21836;
	// addi r29,r10,5164
	ctx.r29.s64 = ctx.r10.s64 + 5164;
loc_8206CC38:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175648
	ctx.lr = 0x8206CC48;
	sub_82175648(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// bl 0x821753c8
	ctx.lr = 0x8206CC60;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206cc7c
	if (!ctx.cr6.eq) goto loc_8206CC7C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r28,1056
	ctx.r3.s64 = ctx.r28.s64 + 1056;
	// bl 0x8207bc98
	ctx.lr = 0x8206CC78;
	sub_8207BC98(ctx, base);
	// bl 0x8207b288
	ctx.lr = 0x8206CC7C;
	sub_8207B288(ctx, base);
loc_8206CC7C:
	// ld r11,88(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82174af8
	ctx.lr = 0x8206CC90;
	sub_82174AF8(ctx, base);
	// addi r5,r3,-1
	ctx.r5.s64 = ctx.r3.s64 + -1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206CCA0;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CCA4;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x8206cc38
	if (ctx.cr6.gt) goto loc_8206CC38;
	// addi r30,r30,-1
	ctx.r30.s64 = ctx.r30.s64 + -1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206CCC0;
	sub_82175648(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r11,5168
	ctx.r5.s64 = ctx.r11.s64 + 5168;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175ae8
	ctx.lr = 0x8206CCD4;
	sub_82175AE8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// bl 0x82175648
	ctx.lr = 0x8206CCF0;
	sub_82175648(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r8,5172
	ctx.r5.s64 = ctx.r8.s64 + 5172;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175ae8
	ctx.lr = 0x8206CD04;
	sub_82175AE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// ld r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// bl 0x82175648
	ctx.lr = 0x8206CD20;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CD24;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// ble cr6,0x8206cd4c
	if (!ctx.cr6.gt) goto loc_8206CD4C;
loc_8206CD2C:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82175648
	ctx.lr = 0x8206CD40;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CD44;
	sub_82175BB0(ctx, base);
	// fcmpu cr6,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f1.f64);
	// bgt cr6,0x8206cd2c
	if (ctx.cr6.gt) goto loc_8206CD2C;
loc_8206CD4C:
	// addi r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82175648
	ctx.lr = 0x8206CD60;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CD64;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82175648
	ctx.lr = 0x8206CD78;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CD7C;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fsubs f30,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f30.f64 - ctx.f1.f64));
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x82175648
	ctx.lr = 0x8206CD90;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CD94;
	sub_82175BB0(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f1.f64));
	// lfs f0,0(r28)
	temp.u32 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// fdivs f31,f13,f30
	ctx.f31.f64 = double(float(ctx.f13.f64 / ctx.f30.f64));
	// fsubs f29,f0,f31
	ctx.f29.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// bl 0x82175648
	ctx.lr = 0x8206CDB4;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CDB8;
	sub_82175BB0(ctx, base);
	// fmuls f12,f31,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f31.f64));
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fmsubs f11,f12,f31,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f31.f64 - ctx.f31.f64));
	// fmuls f28,f1,f11
	ctx.f28.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// bl 0x82175648
	ctx.lr = 0x8206CDD4;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CDD8;
	sub_82175BB0(ctx, base);
	// fmuls f10,f29,f29
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f29.f64 * ctx.f29.f64));
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r10,r11,-2064
	ctx.r10.s64 = ctx.r11.s64 + -2064;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lfs f0,200(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	ctx.f0.f64 = double(temp.f32);
	// fmsubs f9,f10,f29,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f29.f64 - ctx.f29.f64));
	// fmadds f8,f1,f9,f28
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f9.f64 + ctx.f28.f64));
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f30.f64));
	// fmuls f6,f7,f30
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f30.f64));
	// fmuls f30,f6,f0
	ctx.f30.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// bl 0x82175648
	ctx.lr = 0x8206CE0C;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CE10;
	sub_82175BB0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// fmadds f31,f1,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 * ctx.f31.f64 + ctx.f30.f64));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82175648
	ctx.lr = 0x8206CE24;
	sub_82175648(ctx, base);
	// bl 0x82175bb0
	ctx.lr = 0x8206CE28;
	sub_82175BB0(ctx, base);
	// fmadds f1,f1,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f29.f64 + ctx.f31.f64));
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x820803b4
	ctx.lr = 0x8206CE38;
	__restfpr_28(ctx, base);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206CE3C"))) PPC_WEAK_FUNC(sub_8206CE3C);
PPC_FUNC_IMPL(__imp__sub_8206CE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206CE40"))) PPC_WEAK_FUNC(sub_8206CE40);
PPC_FUNC_IMPL(__imp__sub_8206CE40) {
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
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// fcmpu cr6,f1,f2
	ctx.cr6.compare(ctx.f1.f64, ctx.f2.f64);
	// bne cr6,0x8206ce68
	if (!ctx.cr6.eq) goto loc_8206CE68;
	// b 0x8206ce88
	goto loc_8206CE88;
loc_8206CE68:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// fmr f1,f3
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x8206cba0
	ctx.lr = 0x8206CE74;
	sub_8206CBA0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmuls f13,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f1.f64));
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// fmadds f1,f0,f31,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_8206CE88:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206CEA0"))) PPC_WEAK_FUNC(sub_8206CEA0);
PPC_FUNC_IMPL(__imp__sub_8206CEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f29.u64);
	// stfd f30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// fcmpu cr6,f1,f2
	ctx.cr6.compare(ctx.f1.f64, ctx.f2.f64);
	// bne cr6,0x8206cecc
	if (!ctx.cr6.eq) goto loc_8206CECC;
	// b 0x8206cf5c
	goto loc_8206CF5C;
loc_8206CECC:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// lfs f29,8(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f29.f64 = double(temp.f32);
	// lfs f0,248(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// bge cr6,0x8206cef8
	if (!ctx.cr6.lt) goto loc_8206CEF8;
	// fsubs f13,f31,f30
	ctx.f13.f64 = double(float(ctx.f31.f64 - ctx.f30.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8206cf08
	if (!ctx.cr6.gt) goto loc_8206CF08;
	// fsubs f31,f31,f29
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f29.f64));
	// b 0x8206cf08
	goto loc_8206CF08;
loc_8206CEF8:
	// fsubs f13,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8206cf08
	if (!ctx.cr6.gt) goto loc_8206CF08;
	// fadds f31,f31,f29
	ctx.f31.f64 = double(float(ctx.f31.f64 + ctx.f29.f64));
loc_8206CF08:
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// bne cr6,0x8206cf18
	if (!ctx.cr6.eq) goto loc_8206CF18;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// b 0x8206cf38
	goto loc_8206CF38;
loc_8206CF18:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// fmr f1,f3
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x8206cba0
	ctx.lr = 0x8206CF24;
	sub_8206CBA0(ctx, base);
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// fmuls f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// lfs f0,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// fmadds f1,f0,f30,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f30.f64 + ctx.f13.f64));
loc_8206CF38:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,21768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x8206cf50
	if (!ctx.cr6.lt) goto loc_8206CF50;
	// fadds f1,f1,f29
	ctx.f1.f64 = double(float(ctx.f1.f64 + ctx.f29.f64));
	// b 0x8206cf5c
	goto loc_8206CF5C;
loc_8206CF50:
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f29.f64);
	// blt cr6,0x8206cf5c
	if (ctx.cr6.lt) goto loc_8206CF5C;
	// fsubs f1,f1,f29
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f29.f64));
loc_8206CF5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f30,-24(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206CF78"))) PPC_WEAK_FUNC(sub_8206CF78);
PPC_FUNC_IMPL(__imp__sub_8206CF78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x8206CF80;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// bne cr6,0x8206cfac
	if (!ctx.cr6.eq) goto loc_8206CFAC;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_8206CFAC:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8206cba0
	ctx.lr = 0x8206CFB4;
	sub_8206CBA0(ctx, base);
	// clrlwi r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(ctx.f0.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f30,f0,f1
	ctx.f30.f64 = double(float(ctx.f0.f64 - ctx.f1.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f8,f10,f1
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmadds f1,f9,f30,f8
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f30.f64 + ctx.f8.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8206CFF8;
	sub_8206C5F8(ctx, base);
	// rlwinm r8,r31,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 8) & 0xFF;
	// fctidz f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// rlwinm r7,r30,8,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 8) & 0xFF;
	// stfd f7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f7.u64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f6
	ctx.f3.f64 = double(ctx.f6.s64);
	// lwz r29,92(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmuls f0,f2,f31
	ctx.f0.f64 = double(float(ctx.f2.f64 * ctx.f31.f64));
	// fmadds f1,f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f30.f64 + ctx.f0.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8206D038;
	sub_8206C5F8(ctx, base);
	// rlwinm r6,r31,16,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 16) & 0xFF;
	// fctidz f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// rlwinm r5,r30,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 16) & 0xFF;
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// lwz r28,84(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f31.f64));
	// fmadds f1,f7,f30,f6
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f30.f64 + ctx.f6.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8206D078;
	sub_8206C5F8(ctx, base);
	// rlwinm r4,r31,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 24) & 0xFF;
	// fctidz f5,f1
	ctx.fpscr.disableFlushMode();
	ctx.f5.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// rlwinm r3,r30,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 24) & 0xFF;
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f4,88(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f3,88(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f1,f4
	ctx.f1.f64 = double(ctx.f4.s64);
	// lwz r31,84(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// frsp f0,f2
	ctx.f0.f64 = double(float(ctx.f2.f64));
	// fmuls f12,f0,f31
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fmadds f1,f13,f30,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f30.f64 + ctx.f12.f64));
	// bl 0x8206c5f8
	ctx.lr = 0x8206D0B8;
	sub_8206C5F8(ctx, base);
	// rlwinm r11,r28,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 8) & 0xFFFFFF00;
	// fctidz f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// or r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 | ctx.r31.u64;
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r6,r29
	ctx.r3.u64 = ctx.r6.u64 | ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206D0EC"))) PPC_WEAK_FUNC(sub_8206D0EC);
PPC_FUNC_IMPL(__imp__sub_8206D0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206D0F0"))) PPC_WEAK_FUNC(sub_8206D0F0);
PPC_FUNC_IMPL(__imp__sub_8206D0F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8206D0F8;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x82080368
	ctx.lr = 0x8206D100;
	__savefpr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// std r8,232(r1)
	PPC_STORE_U64(ctx.r1.u32 + 232, ctx.r8.u64);
	// lfs f13,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// std r9,240(r1)
	PPC_STORE_U64(ctx.r1.u32 + 240, ctx.r9.u64);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// bne cr6,0x8206d174
	if (!ctx.cr6.eq) goto loc_8206D174;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x8206d174
	if (!ctx.cr6.eq) goto loc_8206D174;
	// lfs f13,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x8206d174
	if (!ctx.cr6.eq) goto loc_8206D174;
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f0,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803b4
	ctx.lr = 0x8206D170;
	__restfpr_28(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206D174:
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// bl 0x8206cba0
	ctx.lr = 0x8206D17C;
	sub_8206CBA0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r3,r1,232
	ctx.r3.s64 = ctx.r1.s64 + 232;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x821746a0
	ctx.lr = 0x8206D194;
	sub_821746A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8206d238
	if (!ctx.cr6.eq) goto loc_8206D238;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,0(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// lfs f28,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f28.f64 = double(temp.f32);
	// beq cr6,0x8206d1cc
	if (ctx.cr6.eq) goto loc_8206D1CC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8206cba0
	ctx.lr = 0x8206D1C0;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f30,f1
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_8206D1CC:
	// stfs f31,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// lfs f31,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x8206d1f8
	if (ctx.cr6.eq) goto loc_8206D1F8;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8206cba0
	ctx.lr = 0x8206D1EC;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f30,f1
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_8206D1F8:
	// stfs f31,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4, temp.u32);
	// lfs f31,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,8(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x8206d224
	if (ctx.cr6.eq) goto loc_8206D224;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x8206cba0
	ctx.lr = 0x8206D218;
	sub_8206CBA0(ctx, base);
	// fsubs f0,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f28.f64 - ctx.f1.f64));
	// fmuls f13,f30,f1
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f1.f64));
	// fmadds f31,f0,f31,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64 + ctx.f13.f64));
loc_8206D224:
	// stfs f31,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r29.u32 + 8, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803b4
	ctx.lr = 0x8206D234;
	__restfpr_28(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206D238:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f29.f64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8206c958
	ctx.lr = 0x8206D248;
	sub_8206C958(ctx, base);
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// blt cr6,0x8206d2bc
	if (ctx.cr6.lt) goto loc_8206D2BC;
	// bne cr6,0x8206d314
	if (!ctx.cr6.eq) goto loc_8206D314;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = ctx.f29.f64;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fsubs f29,f13,f0
	ctx.f29.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f12,8(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f31,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
	// fsubs f28,f12,f11
	ctx.f28.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f30,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f30.f64 = double(temp.f32);
	// fmadds f10,f29,f31,f0
	ctx.f10.f64 = double(float(ctx.f29.f64 * ctx.f31.f64 + ctx.f0.f64));
	// fnmsubs f9,f28,f30,f10
	ctx.f9.f64 = double(float(-(ctx.f28.f64 * ctx.f30.f64 - ctx.f10.f64)));
	// stfs f9,0(r29)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// lfs f2,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206ce40
	ctx.lr = 0x8206D294;
	sub_8206CE40(ctx, base);
	// fmuls f8,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f28.f64 * ctx.f31.f64));
	// fmadds f7,f29,f30,f8
	ctx.f7.f64 = double(float(ctx.f29.f64 * ctx.f30.f64 + ctx.f8.f64));
	// stfs f1,4(r29)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4, temp.u32);
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fadds f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// stfs f5,8(r29)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r29.u32 + 8, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803b4
	ctx.lr = 0x8206D2B8;
	__restfpr_28(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206D2BC:
	// lfs f12,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f11,0(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = ctx.f29.f64;
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f9,4(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f6,f13,f10
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmadds f5,f0,f10,f12
	ctx.f5.f64 = double(float(ctx.f0.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f4,f0,f7,f6
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fnmsubs f2,f13,f7,f5
	ctx.f2.f64 = double(float(-(ctx.f13.f64 * ctx.f7.f64 - ctx.f5.f64)));
	// stfs f2,0(r29)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// lfs f1,4(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fadds f0,f4,f1
	ctx.f0.f64 = double(float(ctx.f4.f64 + ctx.f1.f64));
	// stfs f0,4(r29)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r29.u32 + 4, temp.u32);
	// lfs f2,8(r30)
	temp.u32 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r31)
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8206ce40
	ctx.lr = 0x8206D310;
	sub_8206CE40(ctx, base);
	// stfs f1,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r29.u32 + 8, temp.u32);
loc_8206D314:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x820803b4
	ctx.lr = 0x8206D320;
	__restfpr_28(ctx, base);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206D324"))) PPC_WEAK_FUNC(sub_8206D324);
PPC_FUNC_IMPL(__imp__sub_8206D324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206D328"))) PPC_WEAK_FUNC(sub_8206D328);
PPC_FUNC_IMPL(__imp__sub_8206D328) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32640
	ctx.r11.s64 = -2139095040;
	// ori r10,r11,32896
	ctx.r10.u64 = ctx.r11.u64 | 32896;
	// cmplw cr6,r4,r10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,255
	ctx.r11.s64 = 255;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r11.u32);
	// rlwinm r10,r8,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// rlwinm r8,r4,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF;
	// rlwinm r6,r4,16,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFF;
	// stw r10,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r10.u32);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// rlwinm r9,r3,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFF;
	// rlwinm r7,r3,16,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFF;
	// rlwinm r5,r3,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFF;
	// rlwinm r4,r4,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// bgt cr6,0x8206d37c
	if (ctx.cr6.gt) goto loc_8206D37C;
	// addi r10,r1,-12
	ctx.r10.s64 = ctx.r1.s64 + -12;
loc_8206D37C:
	// mullw r9,r8,r9
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// rlwinm r10,r9,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// addi r10,r1,-12
	ctx.r10.s64 = ctx.r1.s64 + -12;
	// bgt cr6,0x8206d3a0
	if (ctx.cr6.gt) goto loc_8206D3A0;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
loc_8206D3A0:
	// mullw r9,r6,r7
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// rlwinm r10,r9,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// addi r10,r1,-12
	ctx.r10.s64 = ctx.r1.s64 + -12;
	// bgt cr6,0x8206d3c4
	if (ctx.cr6.gt) goto loc_8206D3C4;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
loc_8206D3C4:
	// mullw r7,r4,r5
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r5.s32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// rlwinm r10,r7,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// addi r11,r1,-12
	ctx.r11.s64 = ctx.r1.s64 + -12;
	// stw r10,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r10.u32);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// bgt cr6,0x8206d3e8
	if (ctx.cr6.gt) goto loc_8206D3E8;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
loc_8206D3E8:
	// rlwinm r10,r8,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 | ctx.r8.u64;
	// rlwinm r4,r5,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 | ctx.r3.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206D408"))) PPC_WEAK_FUNC(sub_8206D408);
PPC_FUNC_IMPL(__imp__sub_8206D408) {
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
	// bl 0x8217a740
	ctx.lr = 0x8206D428;
	sub_8217A740(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206d440
	if (ctx.cr6.eq) goto loc_8206D440;
	// bl 0x8207a630
	ctx.lr = 0x8206D43C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206D440:
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

__attribute__((alias("__imp__sub_8206D458"))) PPC_WEAK_FUNC(sub_8206D458);
PPC_FUNC_IMPL(__imp__sub_8206D458) {
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
	// bl 0x82179930
	ctx.lr = 0x8206D478;
	sub_82179930(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206d490
	if (ctx.cr6.eq) goto loc_8206D490;
	// bl 0x8207a630
	ctx.lr = 0x8206D48C;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206D490:
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

__attribute__((alias("__imp__sub_8206D4A8"))) PPC_WEAK_FUNC(sub_8206D4A8);
PPC_FUNC_IMPL(__imp__sub_8206D4A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8206D4B0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// addi r29,r31,160
	ctx.r29.s64 = ctx.r31.s64 + 160;
	// stw r30,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r30.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(ctx.r31.u32 + 112, ctx.r30.u32);
	// stw r30,116(r31)
	PPC_STORE_U32(ctx.r31.u32 + 116, ctx.r30.u32);
	// stw r30,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// stw r30,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r30.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// stw r30,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(ctx.r31.u32 + 140, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x8206D4FC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206d50c
	if (ctx.cr6.eq) goto loc_8206D50C;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x8206d510
	goto loc_8206D510;
loc_8206D50C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8206D510:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206D52C"))) PPC_WEAK_FUNC(sub_8206D52C);
PPC_FUNC_IMPL(__imp__sub_8206D52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206D530"))) PPC_WEAK_FUNC(sub_8206D530);
PPC_FUNC_IMPL(__imp__sub_8206D530) {
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
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82179930
	ctx.lr = 0x8206D554;
	sub_82179930(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r9,r11,-1456
	ctx.r9.s64 = ctx.r11.s64 + -1456;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x8206d578
	if (ctx.cr6.eq) goto loc_8206D578;
	// bl 0x8207a630
	ctx.lr = 0x8206D574;
	sub_8207A630(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_8206D578:
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

__attribute__((alias("__imp__sub_8206D590"))) PPC_WEAK_FUNC(sub_8206D590);
PPC_FUNC_IMPL(__imp__sub_8206D590) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206D598;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x820704e8
	ctx.lr = 0x8206D5A8;
	sub_820704E8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x8206d5bc
	if (!ctx.cr6.eq) goto loc_8206D5BC;
	// twi 31,r0,22
loc_8206D5BC:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x8206d5dc
	if (ctx.cr6.eq) goto loc_8206D5DC;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206d5e0
	if (ctx.cr6.eq) goto loc_8206D5E0;
loc_8206D5DC:
	// twi 31,r0,22
loc_8206D5E0:
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8206d620
	if (ctx.cr6.eq) goto loc_8206D620;
	// lwz r10,36(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 36);
	// addi r11,r26,12
	ctx.r11.s64 = ctx.r26.s64 + 12;
	// lwz r6,32(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 32);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8206d608
	if (ctx.cr6.lt) goto loc_8206D608;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8206d60c
	goto loc_8206D60C;
loc_8206D608:
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
loc_8206D60C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// bl 0x820654f8
	ctx.lr = 0x8206D618;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8206d69c
	if (!ctx.cr6.lt) goto loc_8206D69C;
loc_8206D620:
	// li r29,15
	ctx.r29.s64 = 15;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// bl 0x820601f8
	ctx.lr = 0x8206D648;
	sub_820601F8(ctx, base);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r31.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// bl 0x8206e880
	ctx.lr = 0x8206D66C;
	sub_8206E880(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r9,16
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16, ctx.xer);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// blt cr6,0x8206d688
	if (ctx.cr6.lt) goto loc_8206D688;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x8206D688;
	sub_8207A630(ctx, base);
loc_8206D688:
	// lwz r26,84(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
loc_8206D69C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x8206d6ac
	if (!ctx.cr6.eq) goto loc_8206D6AC;
	// twi 31,r0,22
	// b 0x8206d6b0
	goto loc_8206D6B0;
loc_8206D6AC:
	// lwz r31,0(r27)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
loc_8206D6B0:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8206d6c0
	if (!ctx.cr6.eq) goto loc_8206D6C0;
	// twi 31,r0,22
loc_8206D6C0:
	// addi r3,r26,40
	ctx.r3.s64 = ctx.r26.s64 + 40;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206D6CC"))) PPC_WEAK_FUNC(sub_8206D6CC);
PPC_FUNC_IMPL(__imp__sub_8206D6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206D6D0"))) PPC_WEAK_FUNC(sub_8206D6D0);
PPC_FUNC_IMPL(__imp__sub_8206D6D0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r8,44
	ctx.r8.s64 = 44;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206d704
	if (!ctx.cr6.eq) goto loc_8206D704;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8206d710
	goto loc_8206D710;
loc_8206D704:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r8
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r8.s32);
loc_8206D710:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r11.s64;
	// divw r10,r10,r8
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r8.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8206d734
	if (!ctx.cr6.lt) goto loc_8206D734;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8206ec90
	ctx.lr = 0x8206D72C;
	sub_8206EC90(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// b 0x8206d7c4
	goto loc_8206D7C4;
loc_8206D734:
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x8206d740
	if (!ctx.cr6.gt) goto loc_8206D740;
	// twi 31,r0,22
loc_8206D740:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne cr6,0x8206d760
	if (!ctx.cr6.eq) goto loc_8206D760;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8206d788
	goto loc_8206D788;
loc_8206D760:
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x8206d76c
	if (!ctx.cr6.gt) goto loc_8206D76C;
	// twi 31,r0,22
loc_8206D76C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206d77c
	if (ctx.cr6.eq) goto loc_8206D77C;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8206d780
	if (ctx.cr6.eq) goto loc_8206D780;
loc_8206D77C:
	// twi 31,r0,22
loc_8206D780:
	// subf r11,r11,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r11.s64;
	// divw r30,r11,r8
	ctx.r30.s32 = ppc_divw(ctx.r11.s32, ctx.r8.s32);
loc_8206D788:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x820705e0
	ctx.lr = 0x8206D794;
	sub_820705E0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206d7a8
	if (!ctx.cr6.gt) goto loc_8206D7A8;
	// twi 31,r0,22
loc_8206D7A8:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8206e490
	ctx.lr = 0x8206D7C4;
	sub_8206E490(ctx, base);
loc_8206D7C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8206D7DC"))) PPC_WEAK_FUNC(sub_8206D7DC);
PPC_FUNC_IMPL(__imp__sub_8206D7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206D7E0"))) PPC_WEAK_FUNC(sub_8206D7E0);
PPC_FUNC_IMPL(__imp__sub_8206D7E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x8206D7E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8206d960
	if (ctx.cr6.eq) goto loc_8206D960;
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r5,12(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// subf r10,r5,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r5.s64;
	// srawi. r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8206d820
	if (!ctx.cr0.eq) goto loc_8206D820;
	// bl 0x82066558
	ctx.lr = 0x8206D814;
	sub_82066558(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8206D820:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r8,r3,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r3.s64;
	// srawi r9,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 2;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8206d87c
	if (ctx.cr6.gt) goto loc_8206D87C;
	// subf r11,r5,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8206d850
	if (!ctx.cr0.gt) goto loc_8206D850;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206D850;
	sub_8207A520(ctx, base);
loc_8206D850:
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// srawi r7,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r6,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_8206D87C:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8206d890
	if (!ctx.cr6.eq) goto loc_8206D890;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x8206d89c
	goto loc_8206D89C;
loc_8206D890:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r8,r3,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r3.s64;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
loc_8206D89C:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8206d8ec
	if (ctx.cr6.gt) goto loc_8206D8EC;
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r29,r11,r5
	ctx.r29.u64 = ctx.r11.u64 + ctx.r5.u64;
	// subf r11,r5,r29
	ctx.r11.s64 = ctx.r29.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x8206d8c8
	if (!ctx.cr0.gt) goto loc_8206D8C8;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206D8C8;
	sub_8207A520(ctx, base);
loc_8206D8C8:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r29,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r29.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r6,r3
	ctx.r30.u64 = ctx.r6.u64 + ctx.r3.u64;
	// beq 0x8206d95c
	if (ctx.cr0.eq) goto loc_8206D95C;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// b 0x8206d954
	goto loc_8206D954;
loc_8206D8EC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206d8f8
	if (ctx.cr6.eq) goto loc_8206D8F8;
	// bl 0x8207a630
	ctx.lr = 0x8206D8F8;
	sub_8207A630(ctx, base);
loc_8206D8F8:
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r29,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// srawi. r4,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r4.s64 = ctx.r9.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x8206d920
	if (!ctx.cr0.eq) goto loc_8206D920;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// b 0x8206d928
	goto loc_8206D928;
loc_8206D920:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8206edf8
	ctx.lr = 0x8206D928;
	sub_8206EDF8(ctx, base);
loc_8206D928:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206d960
	if (ctx.cr6.eq) goto loc_8206D960;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// subf r10,r5,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r5.s64;
	// srawi. r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r6,r3
	ctx.r30.u64 = ctx.r6.u64 + ctx.r3.u64;
	// beq 0x8206d95c
	if (ctx.cr0.eq) goto loc_8206D95C;
loc_8206D954:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x8206D95C;
	sub_8207A520(ctx, base);
loc_8206D95C:
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
loc_8206D960:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206D96C"))) PPC_WEAK_FUNC(sub_8206D96C);
PPC_FUNC_IMPL(__imp__sub_8206D96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206D970"))) PPC_WEAK_FUNC(sub_8206D970);
PPC_FUNC_IMPL(__imp__sub_8206D970) {
	PPC_FUNC_PROLOGUE();
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206d9a4
	if (ctx.cr6.eq) goto loc_8206D9A4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_8206D9A4:
	// addi r11,r4,12
	ctx.r11.s64 = ctx.r4.s64 + 12;
	// addi r10,r3,12
	ctx.r10.s64 = ctx.r3.s64 + 12;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206d9c4
	if (ctx.cr6.eq) goto loc_8206D9C4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_8206D9C4:
	// addi r11,r4,16
	ctx.r11.s64 = ctx.r4.s64 + 16;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206d9e4
	if (ctx.cr6.eq) goto loc_8206D9E4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_8206D9E4:
	// addi r11,r4,20
	ctx.r11.s64 = ctx.r4.s64 + 20;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206DA08"))) PPC_WEAK_FUNC(sub_8206DA08);
PPC_FUNC_IMPL(__imp__sub_8206DA08) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r8,524
	ctx.r8.s64 = 524;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206da38
	if (!ctx.cr6.eq) goto loc_8206DA38;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8206da44
	goto loc_8206DA44;
loc_8206DA38:
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw r9,r9,r8
	ctx.r9.s32 = ppc_divw(ctx.r9.s32, ctx.r8.s32);
loc_8206DA44:
	// lwz r31,16(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r10,r11,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r10,r10,r8
	ctx.r10.s32 = ppc_divw(ctx.r10.s32, ctx.r8.s32);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x8206da78
	if (!ctx.cr6.lt) goto loc_8206DA78;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206da6c
	if (ctx.cr6.eq) goto loc_8206DA6C;
	// li r5,524
	ctx.r5.s64 = 524;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8206DA6C;
	sub_8207DAC0(ctx, base);
loc_8206DA6C:
	// addi r11,r31,524
	ctx.r11.s64 = ctx.r31.s64 + 524;
	// stw r11,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// b 0x8206db0c
	goto loc_8206DB0C;
loc_8206DA78:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8206da84
	if (!ctx.cr6.gt) goto loc_8206DA84;
	// twi 31,r0,22
loc_8206DA84:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bne cr6,0x8206daa4
	if (!ctx.cr6.eq) goto loc_8206DAA4;
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8206dacc
	goto loc_8206DACC;
loc_8206DAA4:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8206dab0
	if (!ctx.cr6.gt) goto loc_8206DAB0;
	// twi 31,r0,22
loc_8206DAB0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206dac0
	if (ctx.cr6.eq) goto loc_8206DAC0;
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8206dac4
	if (ctx.cr6.eq) goto loc_8206DAC4;
loc_8206DAC0:
	// twi 31,r0,22
loc_8206DAC4:
	// subf r11,r11,r31
	ctx.r11.s64 = ctx.r31.s64 - ctx.r11.s64;
	// divw r31,r11,r8
	ctx.r31.s32 = ppc_divw(ctx.r11.s32, ctx.r8.s32);
loc_8206DACC:
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x820708c8
	ctx.lr = 0x8206DADC;
	sub_820708C8(ctx, base);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206daf0
	if (!ctx.cr6.gt) goto loc_8206DAF0;
	// twi 31,r0,22
loc_8206DAF0:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8206e720
	ctx.lr = 0x8206DB0C;
	sub_8206E720(ctx, base);
loc_8206DB0C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8206DB24"))) PPC_WEAK_FUNC(sub_8206DB24);
PPC_FUNC_IMPL(__imp__sub_8206DB24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206DB28"))) PPC_WEAK_FUNC(sub_8206DB28);
PPC_FUNC_IMPL(__imp__sub_8206DB28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x8206DB30;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,0
	ctx.r10.s64 = 0;
	// std r5,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r5.u64);
	// lwz r11,180(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// std r6,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r6.u64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8206db70
	if (ctx.cr6.eq) goto loc_8206DB70;
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8206db70
	if (ctx.cr6.gt) goto loc_8206DB70;
	// lwz r10,16(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206db74
	if (!ctx.cr6.gt) goto loc_8206DB74;
loc_8206DB70:
	// twi 31,r0,22
loc_8206DB74:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r31,188(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 12);
	// stw r11,4(r26)
	PPC_STORE_U32(ctx.r26.u32 + 4, ctx.r11.u32);
	// cmplw cr6,r9,r31
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r31.u32, ctx.xer);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// bgt cr6,0x8206db9c
	if (ctx.cr6.gt) goto loc_8206DB9C;
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// cmplw cr6,r31,r9
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8206dba0
	if (!ctx.cr6.gt) goto loc_8206DBA0;
loc_8206DB9C:
	// twi 31,r0,22
loc_8206DBA0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206dbac
	if (!ctx.cr6.eq) goto loc_8206DBAC;
	// twi 31,r0,22
loc_8206DBAC:
	// cmplw cr6,r11,r31
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8206dbf8
	if (ctx.cr6.eq) goto loc_8206DBF8;
	// lwz r30,16(r29)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r29.u32 + 16);
	// li r10,524
	ctx.r10.s64 = 524;
	// subf r9,r31,r30
	ctx.r9.s64 = ctx.r30.s64 - ctx.r31.s64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// divw r8,r9,r10
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r10.s32);
	// mulli r10,r8,524
	ctx.r10.s64 = ctx.r8.s64 * 524;
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// beq cr6,0x8206dbf4
	if (ctx.cr6.eq) goto loc_8206DBF4;
	// subf r28,r31,r11
	ctx.r28.s64 = ctx.r11.s64 - ctx.r31.s64;
loc_8206DBD8:
	// add r3,r28,r31
	ctx.r3.u64 = ctx.r28.u64 + ctx.r31.u64;
	// li r5,524
	ctx.r5.s64 = 524;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8207dac0
	ctx.lr = 0x8206DBE8;
	sub_8207DAC0(ctx, base);
	// addi r31,r31,524
	ctx.r31.s64 = ctx.r31.s64 + 524;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8206dbd8
	if (!ctx.cr6.eq) goto loc_8206DBD8;
loc_8206DBF4:
	// stw r27,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r27.u32);
loc_8206DBF8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206DC04"))) PPC_WEAK_FUNC(sub_8206DC04);
PPC_FUNC_IMPL(__imp__sub_8206DC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206DC08"))) PPC_WEAK_FUNC(sub_8206DC08);
PPC_FUNC_IMPL(__imp__sub_8206DC08) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x8206DC10;
	__savegprlr_27(ctx, base);
	// stwu r1,-560(r1)
	ea = -560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x820712d0
	ctx.lr = 0x8206DC20;
	sub_820712D0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8206dc34
	if (!ctx.cr6.eq) goto loc_8206DC34;
	// twi 31,r0,22
loc_8206DC34:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x8206dc54
	if (ctx.cr6.eq) goto loc_8206DC54;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206dc58
	if (ctx.cr6.eq) goto loc_8206DC58;
loc_8206DC54:
	// twi 31,r0,22
loc_8206DC58:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplw cr6,r27,r10
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8206dc98
	if (ctx.cr6.eq) goto loc_8206DC98;
	// lwz r10,36(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 36);
	// addi r11,r27,12
	ctx.r11.s64 = ctx.r27.s64 + 12;
	// lwz r6,32(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8206dc80
	if (ctx.cr6.lt) goto loc_8206DC80;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8206dc84
	goto loc_8206DC84;
loc_8206DC80:
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
loc_8206DC84:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,20(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// bl 0x820654f8
	ctx.lr = 0x8206DC90;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8206dd28
	if (!ctx.cr6.lt) goto loc_8206DD28;
loc_8206DC98:
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x8206d4a8
	ctx.lr = 0x8206DCA0;
	sub_8206D4A8(ctx, base);
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r30,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r30.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820601f8
	ctx.lr = 0x8206DCC8;
	sub_820601F8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// bl 0x8206fd88
	ctx.lr = 0x8206DCD4;
	sub_8206FD88(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8206eec8
	ctx.lr = 0x8206DCE8;
	sub_8206EEC8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// bl 0x8206e790
	ctx.lr = 0x8206DCFC;
	sub_8206E790(ctx, base);
	// lwz r3,492(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 492);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206dd0c
	if (ctx.cr6.eq) goto loc_8206DD0C;
	// bl 0x8207a630
	ctx.lr = 0x8206DD0C;
	sub_8207A630(ctx, base);
loc_8206DD0C:
	// stw r30,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r30.u32);
	// stw r30,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r30.u32);
	// stw r30,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r30.u32);
	// lwz r3,480(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 480);
	// bl 0x8207a630
	ctx.lr = 0x8206DD20;
	sub_8207A630(ctx, base);
	// lwz r27,84(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,80(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8206DD28:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8206dd54
	if (!ctx.cr6.eq) goto loc_8206DD54;
	// twi 31,r0,22
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8206DD38:
	// lwz r11,24(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// cmplw cr6,r27,r11
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8206dd48
	if (!ctx.cr6.eq) goto loc_8206DD48;
	// twi 31,r0,22
loc_8206DD48:
	// addi r3,r27,40
	ctx.r3.s64 = ctx.r27.s64 + 40;
	// addi r1,r1,560
	ctx.r1.s64 = ctx.r1.s64 + 560;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_8206DD54:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// b 0x8206dd38
	goto loc_8206DD38;
}

__attribute__((alias("__imp__sub_8206DD5C"))) PPC_WEAK_FUNC(sub_8206DD5C);
PPC_FUNC_IMPL(__imp__sub_8206DD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206DD60"))) PPC_WEAK_FUNC(sub_8206DD60);
PPC_FUNC_IMPL(__imp__sub_8206DD60) {
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
	// lwz r11,24(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82070e48
	ctx.lr = 0x8206DDA4;
	sub_82070E48(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x8207a630
	ctx.lr = 0x8206DDAC;
	sub_8207A630(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bl 0x8207a630
	ctx.lr = 0x8206DDC0;
	sub_8207A630(ctx, base);
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

__attribute__((alias("__imp__sub_8206DDD4"))) PPC_WEAK_FUNC(sub_8206DDD4);
PPC_FUNC_IMPL(__imp__sub_8206DDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206DDD8"))) PPC_WEAK_FUNC(sub_8206DDD8);
PPC_FUNC_IMPL(__imp__sub_8206DDD8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x8206DDE0;
	__savegprlr_23(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// std r5,288(r1)
	PPC_STORE_U64(ctx.r1.u32 + 288, ctx.r5.u64);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r31,292(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// li r24,15
	ctx.r24.s64 = 15;
	// li r27,0
	ctx.r27.s64 = 0;
	// lbz r11,225(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + 225);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206de5c
	if (ctx.cr6.eq) goto loc_8206DE5C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,5192
	ctx.r4.s64 = ctx.r11.s64 + 5192;
	// bl 0x82060190
	ctx.lr = 0x8206DE18;
	sub_82060190(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82060e58
	ctx.lr = 0x8206DE24;
	sub_82060E58(ctx, base);
	// bl 0x82060018
	ctx.lr = 0x8206DE28;
	sub_82060018(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r9,r10,-1236
	ctx.r9.s64 = ctx.r10.s64 + -1236;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// bl 0x82060c50
	ctx.lr = 0x8206DE3C;
	sub_82060C50(ctx, base);
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x8206de50
	if (ctx.cr6.lt) goto loc_8206DE50;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x8206DE50;
	sub_8207A630(ctx, base);
loc_8206DE50:
	// stw r24,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r24.u32);
	// stw r27,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r27.u32);
	// stb r27,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r27.u8);
loc_8206DE5C:
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// bl 0x8206fce0
	ctx.lr = 0x8206DE68;
	sub_8206FCE0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r10,225(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r25,292(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// beq cr6,0x8206de84
	if (ctx.cr6.eq) goto loc_8206DE84;
	// lwz r29,8(r31)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// b 0x8206dea8
	goto loc_8206DEA8;
loc_8206DE84:
	// lwz r10,8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// lbz r9,225(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 225);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206de9c
	if (ctx.cr6.eq) goto loc_8206DE9C;
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// b 0x8206dea8
	goto loc_8206DEA8;
loc_8206DE9C:
	// lwz r29,8(r25)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r25.u32 + 8);
	// cmplw cr6,r25,r26
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206df94
	if (!ctx.cr6.eq) goto loc_8206DF94;
loc_8206DEA8:
	// lbz r11,225(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 225);
	// lwz r31,4(r26)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206debc
	if (!ctx.cr6.eq) goto loc_8206DEBC;
	// stw r31,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
loc_8206DEBC:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206ded4
	if (!ctx.cr6.eq) goto loc_8206DED4;
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// b 0x8206deec
	goto loc_8206DEEC;
loc_8206DED4:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206dee8
	if (!ctx.cr6.eq) goto loc_8206DEE8;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// b 0x8206deec
	goto loc_8206DEEC;
loc_8206DEE8:
	// stw r29,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
loc_8206DEEC:
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206df3c
	if (!ctx.cr6.eq) goto loc_8206DF3C;
	// lbz r11,225(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 225);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206df10
	if (ctx.cr6.eq) goto loc_8206DF10;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// b 0x8206df38
	goto loc_8206DF38;
loc_8206DF10:
	// lwz r11,0(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lbz r8,225(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8206df38
	if (!ctx.cr6.eq) goto loc_8206DF38;
loc_8206DF24:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r8,225(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206df24
	if (ctx.cr6.eq) goto loc_8206DF24;
loc_8206DF38:
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
loc_8206DF3C:
	// lwz r9,24(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// lwz r11,8(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplw cr6,r11,r26
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206e038
	if (!ctx.cr6.eq) goto loc_8206E038;
	// lbz r11,225(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 225);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206df64
	if (ctx.cr6.eq) goto loc_8206DF64;
	// mr r10,r31
	ctx.r10.u64 = ctx.r31.u64;
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r31.u32);
	// b 0x8206e038
	goto loc_8206E038;
loc_8206DF64:
	// lwz r11,8(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 8);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lbz r8,225(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8206df8c
	if (!ctx.cr6.eq) goto loc_8206DF8C;
loc_8206DF78:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r8,225(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206df78
	if (ctx.cr6.eq) goto loc_8206DF78;
loc_8206DF8C:
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// b 0x8206e038
	goto loc_8206E038;
loc_8206DF94:
	// stw r25,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// stw r11,0(r25)
	PPC_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// lwz r10,8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// cmplw cr6,r25,r10
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8206dfb4
	if (!ctx.cr6.eq) goto loc_8206DFB4;
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
	// b 0x8206dfdc
	goto loc_8206DFDC;
loc_8206DFB4:
	// lbz r11,225(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 225);
	// lwz r31,4(r25)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r25.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206dfc8
	if (!ctx.cr6.eq) goto loc_8206DFC8;
	// stw r31,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
loc_8206DFC8:
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// lwz r11,8(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// stw r11,8(r25)
	PPC_STORE_U32(ctx.r25.u32 + 8, ctx.r11.u32);
	// lwz r10,8(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 8);
	// stw r25,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r25.u32);
loc_8206DFDC:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206dff4
	if (!ctx.cr6.eq) goto loc_8206DFF4;
	// stw r25,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r25.u32);
	// b 0x8206e010
	goto loc_8206E010;
loc_8206DFF4:
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r26
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x8206e00c
	if (!ctx.cr6.eq) goto loc_8206E00C;
	// stw r25,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// b 0x8206e010
	goto loc_8206E010;
loc_8206E00C:
	// stw r25,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r25.u32);
loc_8206E010:
	// lwz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// addi r11,r26,224
	ctx.r11.s64 = ctx.r26.s64 + 224;
	// addi r10,r25,224
	ctx.r10.s64 = ctx.r25.s64 + 224;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r9,4(r25)
	PPC_STORE_U32(ctx.r25.u32 + 4, ctx.r9.u32);
	// beq cr6,0x8206e038
	if (ctx.cr6.eq) goto loc_8206E038;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
loc_8206E038:
	// lbz r11,224(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 224);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8206e1cc
	if (!ctx.cr6.eq) goto loc_8206E1CC;
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// li r30,1
	ctx.r30.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8206e1c8
	if (ctx.cr6.eq) goto loc_8206E1C8;
loc_8206E058:
	// lbz r11,224(r29)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r29.u32 + 224);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x8206e1c8
	if (!ctx.cr6.eq) goto loc_8206E1C8;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8206e110
	if (!ctx.cr6.eq) goto loc_8206E110;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lbz r10,224(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 224);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206e098
	if (!ctx.cr6.eq) goto loc_8206E098;
	// stb r30,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stb r27,224(r31)
	PPC_STORE_U8(ctx.r31.u32 + 224, ctx.r27.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f290
	ctx.lr = 0x8206E094;
	sub_8206F290(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
loc_8206E098:
	// lbz r10,225(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206e164
	if (!ctx.cr6.eq) goto loc_8206E164;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r9,224(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 224);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x8206e0c4
	if (!ctx.cr6.eq) goto loc_8206E0C4;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r8,224(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 224);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// beq cr6,0x8206e160
	if (ctx.cr6.eq) goto loc_8206E160;
loc_8206E0C4:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r8,224(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 224);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x8206e0ec
	if (!ctx.cr6.eq) goto loc_8206E0EC;
	// stb r30,224(r10)
	PPC_STORE_U8(ctx.r10.u32 + 224, ctx.r30.u8);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stb r27,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r27.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f308
	ctx.lr = 0x8206E0E8;
	sub_8206F308(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
loc_8206E0EC:
	// lbz r10,224(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 224);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stb r10,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r10.u8);
	// stb r30,224(r31)
	PPC_STORE_U8(ctx.r31.u32 + 224, ctx.r30.u8);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// stb r30,224(r9)
	PPC_STORE_U8(ctx.r9.u32 + 224, ctx.r30.u8);
	// bl 0x8206f290
	ctx.lr = 0x8206E10C;
	sub_8206F290(ctx, base);
	// b 0x8206e1c8
	goto loc_8206E1C8;
loc_8206E110:
	// lbz r10,224(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 224);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206e134
	if (!ctx.cr6.eq) goto loc_8206E134;
	// stb r30,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r30.u8);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stb r27,224(r31)
	PPC_STORE_U8(ctx.r31.u32 + 224, ctx.r27.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f308
	ctx.lr = 0x8206E130;
	sub_8206F308(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
loc_8206E134:
	// lbz r10,225(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 225);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8206e164
	if (!ctx.cr6.eq) goto loc_8206E164;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// lbz r9,224(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 224);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x8206e180
	if (!ctx.cr6.eq) goto loc_8206E180;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r8,224(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 224);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x8206e180
	if (!ctx.cr6.eq) goto loc_8206E180;
loc_8206E160:
	// stb r27,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r27.u8);
loc_8206E164:
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// lwz r31,4(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8206e058
	if (!ctx.cr6.eq) goto loc_8206E058;
	// b 0x8206e1c8
	goto loc_8206E1C8;
loc_8206E180:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r8,224(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 224);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x8206e1a8
	if (!ctx.cr6.eq) goto loc_8206E1A8;
	// stb r30,224(r10)
	PPC_STORE_U8(ctx.r10.u32 + 224, ctx.r30.u8);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// stb r27,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r27.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8206f290
	ctx.lr = 0x8206E1A4;
	sub_8206F290(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
loc_8206E1A8:
	// lbz r10,224(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 224);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stb r10,224(r11)
	PPC_STORE_U8(ctx.r11.u32 + 224, ctx.r10.u8);
	// stb r30,224(r31)
	PPC_STORE_U8(ctx.r31.u32 + 224, ctx.r30.u8);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stb r30,224(r9)
	PPC_STORE_U8(ctx.r9.u32 + 224, ctx.r30.u8);
	// bl 0x8206f308
	ctx.lr = 0x8206E1C8;
	sub_8206F308(ctx, base);
loc_8206E1C8:
	// stb r30,224(r29)
	PPC_STORE_U8(ctx.r29.u32 + 224, ctx.r30.u8);
loc_8206E1CC:
	// lwz r3,212(r26)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r26.u32 + 212);
	// addi r31,r26,12
	ctx.r31.s64 = ctx.r26.s64 + 12;
	// addi r30,r31,188
	ctx.r30.s64 = ctx.r31.s64 + 188;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8206e1e4
	if (ctx.cr6.eq) goto loc_8206E1E4;
	// bl 0x8207a630
	ctx.lr = 0x8206E1E4;
	sub_8207A630(ctx, base);
loc_8206E1E4:
	// stw r27,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r27.u32);
	// stw r27,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r27.u32);
	// stw r27,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r27.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x8206E1F8;
	sub_8207A630(ctx, base);
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8206e20c
	if (ctx.cr6.lt) goto loc_8206E20C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x8206E20C;
	sub_8207A630(ctx, base);
loc_8206E20C:
	// stw r24,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r24.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// stb r27,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r27.u8);
	// bl 0x8207a630
	ctx.lr = 0x8206E220;
	sub_8207A630(ctx, base);
	// lwz r11,28(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e234
	if (ctx.cr6.eq) goto loc_8206E234;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,28(r28)
	PPC_STORE_U32(ctx.r28.u32 + 28, ctx.r11.u32);
loc_8206E234:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r25.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,0(r23)
	PPC_STORE_U64(ctx.r23.u32 + 0, ctx.r10.u64);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206E254"))) PPC_WEAK_FUNC(sub_8206E254);
PPC_FUNC_IMPL(__imp__sub_8206E254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206E258"))) PPC_WEAK_FUNC(sub_8206E258);
PPC_FUNC_IMPL(__imp__sub_8206E258) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8206e288
	if (!ctx.cr6.eq) goto loc_8206E288;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8206e294
	goto loc_8206E294;
loc_8206E288:
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// subf r10,r9,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r8,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
loc_8206E294:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// subf r10,r9,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x8206e2bc
	if (!ctx.cr6.lt) goto loc_8206E2BC;
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// b 0x8206e34c
	goto loc_8206E34C;
loc_8206E2BC:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206e2c8
	if (!ctx.cr6.gt) goto loc_8206E2C8;
	// twi 31,r0,22
loc_8206E2C8:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bne cr6,0x8206e2e8
	if (!ctx.cr6.eq) goto loc_8206E2E8;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8206e310
	goto loc_8206E310;
loc_8206E2E8:
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206e2f4
	if (!ctx.cr6.gt) goto loc_8206E2F4;
	// twi 31,r0,22
loc_8206E2F4:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8206e304
	if (ctx.cr6.eq) goto loc_8206E304;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8206e308
	if (ctx.cr6.eq) goto loc_8206E308;
loc_8206E304:
	// twi 31,r0,22
loc_8206E308:
	// subf r11,r9,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r9.s64;
	// srawi r30,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r30.s64 = ctx.r11.s32 >> 2;
loc_8206E310:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x820717a0
	ctx.lr = 0x8206E31C;
	sub_820717A0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8206e330
	if (!ctx.cr6.gt) goto loc_8206E330;
	// twi 31,r0,22
loc_8206E330:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82061310
	ctx.lr = 0x8206E34C;
	sub_82061310(ctx, base);
loc_8206E34C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8206E364"))) PPC_WEAK_FUNC(sub_8206E364);
PPC_FUNC_IMPL(__imp__sub_8206E364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8206E368"))) PPC_WEAK_FUNC(sub_8206E368);
PPC_FUNC_IMPL(__imp__sub_8206E368) {
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
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// std r6,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r6.u64);
	// std r7,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r7.u64);
	// std r8,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r8.u64);
	// std r9,176(r1)
	PPC_STORE_U64(ctx.r1.u32 + 176, ctx.r9.u64);
	// li r9,100
	ctx.r9.s64 = 100;
	// std r10,184(r1)
	PPC_STORE_U64(ctx.r1.u32 + 184, ctx.r10.u64);
	// lwz r11,16(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r8,r10,r11
	ctx.r8.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw r9,r8,r9
	ctx.r9.s32 = ppc_divw(ctx.r8.s32, ctx.r9.s32);
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x8206e3e0
	if (!ctx.cr6.gt) goto loc_8206E3E0;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206e3b4
	if (!ctx.cr6.gt) goto loc_8206E3B4;
	// twi 31,r0,22
loc_8206E3B4:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r5,r9,r4
	ctx.r5.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206f638
	ctx.lr = 0x8206E3D0;
	sub_8206F638(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_8206E3E0:
	// bge cr6,0x8206e480
	if (!ctx.cr6.lt) goto loc_8206E480;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8206e3f0
	if (!ctx.cr6.gt) goto loc_8206E3F0;
	// twi 31,r0,22
loc_8206E3F0:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// ble cr6,0x8206e408
	if (!ctx.cr6.gt) goto loc_8206E408;
	// twi 31,r0,22
loc_8206E408:
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bne cr6,0x8206e44c
	if (!ctx.cr6.eq) goto loc_8206E44C;
	// twi 31,r0,22
	// li r8,0
	ctx.r8.s64 = 0;
loc_8206E428:
	// mulli r11,r4,100
	ctx.r11.s64 = ctx.r4.s64 * 100;
	// lwz r8,16(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bgt cr6,0x8206e464
	if (ctx.cr6.gt) goto loc_8206E464;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8206e454
	if (ctx.cr6.eq) goto loc_8206E454;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8206e458
	goto loc_8206E458;
loc_8206E44C:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x8206e428
	goto loc_8206E428;
loc_8206E454:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8206E458:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8206e468
	if (!ctx.cr6.lt) goto loc_8206E468;
loc_8206E464:
	// twi 31,r0,22
loc_8206E468:
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8206f558
	ctx.lr = 0x8206E480;
	sub_8206F558(ctx, base);
loc_8206E480:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206E490"))) PPC_WEAK_FUNC(sub_8206E490);
PPC_FUNC_IMPL(__imp__sub_8206E490) {
	PPC_FUNC_PROLOGUE();
	// ld r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r4.u32 + 0);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r11.u64);
	// lwz r8,-16(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8206e4d4
	if (!ctx.cr6.eq) goto loc_8206E4D4;
	// twi 31,r0,22
	// li r9,0
	ctx.r9.s64 = 0;
loc_8206E4AC:
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// mulli r11,r5,44
	ctx.r11.s64 = ctx.r5.s64 * 44;
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8206e4ec
	if (ctx.cr6.gt) goto loc_8206E4EC;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206e4dc
	if (ctx.cr6.eq) goto loc_8206E4DC;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x8206e4e0
	goto loc_8206E4E0;
loc_8206E4D4:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x8206e4ac
	goto loc_8206E4AC;
loc_8206E4DC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8206E4E0:
	// lwz r10,12(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8206e4f0
	if (!ctx.cr6.lt) goto loc_8206E4F0;
loc_8206E4EC:
	// twi 31,r0,22
loc_8206E4F0:
	// stw r11,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r11.u32);
	// ld r11,-16(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8206E500"))) PPC_WEAK_FUNC(sub_8206E500);
PPC_FUNC_IMPL(__imp__sub_8206E500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x8206E508;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,24(r4)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r24,1
	ctx.r24.s64 = 1;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lbz r11,41(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 41);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8206e614
	if (!ctx.cr6.eq) goto loc_8206E614;
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// addi r27,r29,4
	ctx.r27.s64 = ctx.r29.s64 + 4;
	// lwz r25,24(r29)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8206E544:
	// lwz r10,36(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// addi r11,r5,12
	ctx.r11.s64 = ctx.r5.s64 + 12;
	// lwz r6,32(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8206e564
	if (ctx.cr6.lt) goto loc_8206E564;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x8206e568
	goto loc_8206E568;
loc_8206E564:
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
loc_8206E568:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplw cr6,r4,r3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x8206e578
	if (!ctx.cr6.lt) goto loc_8206E578;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
loc_8206E578:
	// cmplw cr6,r7,r6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, ctx.xer);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// blt cr6,0x8206e588
	if (ctx.cr6.lt) goto loc_8206E588;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_8206E588:
	// cmplwi cr6,r25,16
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 16, ctx.xer);
	// blt cr6,0x8206e598
	if (ctx.cr6.lt) goto loc_8206E598;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// b 0x8206e59c
	goto loc_8206E59C;
loc_8206E598:
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8206E59C:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x8206e5cc
	if (ctx.cr6.eq) goto loc_8206E5CC;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
loc_8206E5AC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r31,0(r10)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r31,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r31.s64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8206e5cc
	if (!ctx.cr0.eq) goto loc_8206E5CC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8206e5ac
	if (!ctx.cr6.eq) goto loc_8206E5AC;
loc_8206E5CC:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8206e5f0
	if (!ctx.cr6.eq) goto loc_8206E5F0;
	// cmplw cr6,r7,r6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, ctx.xer);
	// bge cr6,0x8206e5e4
	if (!ctx.cr6.lt) goto loc_8206E5E4;
	// li r9,-1
	ctx.r9.s64 = -1;
	// b 0x8206e5f0
	goto loc_8206E5F0;
loc_8206E5E4:
	// subf r11,r7,r6
	ctx.r11.s64 = ctx.r6.s64 - ctx.r7.s64;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r9,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8206E5F0:
	// rlwinm r31,r9,1,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8206e604
	if (ctx.cr6.eq) goto loc_8206E604;
	// lwz r5,0(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// b 0x8206e608
	goto loc_8206E608;
loc_8206E604:
	// lwz r5,8(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
loc_8206E608:
	// lbz r11,41(r5)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 41);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8206e544
	if (ctx.cr6.eq) goto loc_8206E544;
loc_8206E614:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// beq cr6,0x8206e690
	if (ctx.cr6.eq) goto loc_8206E690;
	// lwz r10,24(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x8206e644
	if (ctx.cr6.eq) goto loc_8206E644;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8206e648
	if (ctx.cr6.eq) goto loc_8206E648;
loc_8206E644:
	// twi 31,r0,22
loc_8206E648:
	// cmplw cr6,r30,r10
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r10.u32, ctx.xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x8206e68c
	if (!ctx.cr6.eq) goto loc_8206E68C;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x8206f988
	ctx.lr = 0x8206E668;
	sub_8206F988(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r24,8(r28)
	PPC_STORE_U8(ctx.r28.u32 + 8, ctx.r24.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r9,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8206E68C:
	// bl 0x82072900
	ctx.lr = 0x8206E690;
	sub_82072900(ctx, base);
loc_8206E690:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r6,20(r29)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// addi r3,r10,12
	ctx.r3.s64 = ctx.r10.s64 + 12;
	// blt cr6,0x8206e6b0
	if (ctx.cr6.lt) goto loc_8206E6B0;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x8206e6b4
	goto loc_8206E6B4;
loc_8206E6B0:
	// addi r5,r29,4
	ctx.r5.s64 = ctx.r29.s64 + 4;
loc_8206E6B4:
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x820654f8
	ctx.lr = 0x8206E6BC;
	sub_820654F8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8206e700
	if (!ctx.cr6.lt) goto loc_8206E700;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8206f988
	ctx.lr = 0x8206E6DC;
	sub_8206F988(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r24,8(r28)
	PPC_STORE_U8(ctx.r28.u32 + 8, ctx.r24.u8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r9,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_8206E700:
	// ld r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stb r10,8(r28)
	PPC_STORE_U8(ctx.r28.u32 + 8, ctx.r10.u8);
	// std r11,0(r28)
	PPC_STORE_U64(ctx.r28.u32 + 0, ctx.r11.u64);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8206E71C"))) PPC_WEAK_FUNC(sub_8206E71C);
PPC_FUNC_IMPL(__imp__sub_8206E71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

