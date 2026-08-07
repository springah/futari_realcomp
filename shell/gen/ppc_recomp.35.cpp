#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821C7CA4"))) PPC_WEAK_FUNC(sub_821C7CA4);
PPC_FUNC_IMPL(__imp__sub_821C7CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7CA8"))) PPC_WEAK_FUNC(sub_821C7CA8);
PPC_FUNC_IMPL(__imp__sub_821C7CA8) {
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
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c7ce8
	if (ctx.cr6.eq) goto loc_821C7CE8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c7ce8
	if (!ctx.cr6.eq) goto loc_821C7CE8;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-31368(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31368, ctx.r10.u32);
	// bl 0x82184cc8
	ctx.lr = 0x821C7CE8;
	sub_82184CC8(ctx, base);
loc_821C7CE8:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-31304(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31304);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x821C7D08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x821c54f8
	ctx.lr = 0x821C7D0C;
	sub_821C54F8(ctx, base);
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

__attribute__((alias("__imp__sub_821C7D20"))) PPC_WEAK_FUNC(sub_821C7D20);
PPC_FUNC_IMPL(__imp__sub_821C7D20) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821c7d3c
	if (ctx.cr6.lt) goto loc_821C7D3C;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// ble cr6,0x821c7d40
	if (!ctx.cr6.gt) goto loc_821C7D40;
loc_821C7D3C:
	// li r4,4
	ctx.r4.s64 = 4;
loc_821C7D40:
	// stw r4,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x821c7d58
	if (!ctx.cr6.lt) goto loc_821C7D58;
	// subfic r11,r4,4
	ctx.xer.ca = ctx.r4.u32 <= 4;
	ctx.r11.s64 = 4 - ctx.r4.s64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// b 0x821c7d60
	goto loc_821C7D60;
loc_821C7D58:
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_821C7D60:
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,11
	ctx.r3.s64 = 11;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C7D7C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7D8C"))) PPC_WEAK_FUNC(sub_821C7D8C);
PPC_FUNC_IMPL(__imp__sub_821C7D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7D90"))) PPC_WEAK_FUNC(sub_821C7D90);
PPC_FUNC_IMPL(__imp__sub_821C7D90) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,14
	ctx.r3.s64 = 14;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C7DA4"))) PPC_WEAK_FUNC(sub_821C7DA4);
PPC_FUNC_IMPL(__imp__sub_821C7DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7DA8"))) PPC_WEAK_FUNC(sub_821C7DA8);
PPC_FUNC_IMPL(__imp__sub_821C7DA8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c7dd4
	if (!ctx.cr6.eq) goto loc_821C7DD4;
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bne cr6,0x821c7dd4
	if (!ctx.cr6.eq) goto loc_821C7DD4;
	// lbz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C7DD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7DDC"))) PPC_WEAK_FUNC(sub_821C7DDC);
PPC_FUNC_IMPL(__imp__sub_821C7DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7DE0"))) PPC_WEAK_FUNC(sub_821C7DE0);
PPC_FUNC_IMPL(__imp__sub_821C7DE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C7DF4"))) PPC_WEAK_FUNC(sub_821C7DF4);
PPC_FUNC_IMPL(__imp__sub_821C7DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7DF8"))) PPC_WEAK_FUNC(sub_821C7DF8);
PPC_FUNC_IMPL(__imp__sub_821C7DF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C7E0C"))) PPC_WEAK_FUNC(sub_821C7E0C);
PPC_FUNC_IMPL(__imp__sub_821C7E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7E10"))) PPC_WEAK_FUNC(sub_821C7E10);
PPC_FUNC_IMPL(__imp__sub_821C7E10) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c7e30
	if (!ctx.cr6.eq) goto loc_821C7E30;
	// lbz r11,6(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C7E30:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7E38"))) PPC_WEAK_FUNC(sub_821C7E38);
PPC_FUNC_IMPL(__imp__sub_821C7E38) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,19
	ctx.r3.s64 = 19;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C7E5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7E6C"))) PPC_WEAK_FUNC(sub_821C7E6C);
PPC_FUNC_IMPL(__imp__sub_821C7E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7E70"))) PPC_WEAK_FUNC(sub_821C7E70);
PPC_FUNC_IMPL(__imp__sub_821C7E70) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,18
	ctx.r3.s64 = 18;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C7E80"))) PPC_WEAK_FUNC(sub_821C7E80);
PPC_FUNC_IMPL(__imp__sub_821C7E80) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// li r3,17
	ctx.r3.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C7EB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7EC8"))) PPC_WEAK_FUNC(sub_821C7EC8);
PPC_FUNC_IMPL(__imp__sub_821C7EC8) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,16
	ctx.r3.s64 = 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C7EEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7EFC"))) PPC_WEAK_FUNC(sub_821C7EFC);
PPC_FUNC_IMPL(__imp__sub_821C7EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C7F00"))) PPC_WEAK_FUNC(sub_821C7F00);
PPC_FUNC_IMPL(__imp__sub_821C7F00) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x821C7F28;
	sub_8207DAC0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C7F40;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C7F58"))) PPC_WEAK_FUNC(sub_821C7F58);
PPC_FUNC_IMPL(__imp__sub_821C7F58) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c7f80
	if (ctx.cr6.eq) goto loc_821C7F80;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
loc_821C7F80:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C7F98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C7FA8"))) PPC_WEAK_FUNC(sub_821C7FA8);
PPC_FUNC_IMPL(__imp__sub_821C7FA8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c7fdc
	if (ctx.cr6.eq) goto loc_821C7FDC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r5,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r5.u32);
	// stw r6,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r6.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// b 0x821c7fe4
	goto loc_821C7FE4;
loc_821C7FDC:
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_821C7FE4:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C7FFC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C800C"))) PPC_WEAK_FUNC(sub_821C800C);
PPC_FUNC_IMPL(__imp__sub_821C800C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8010"))) PPC_WEAK_FUNC(sub_821C8010);
PPC_FUNC_IMPL(__imp__sub_821C8010) {
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
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r9,192(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mulli r10,r10,720
	ctx.r10.s64 = ctx.r10.s64 * 720;
	// lwz r8,252(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r3,20
	ctx.r3.s64 = 20;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bctrl 
	ctx.lr = 0x821C8058;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8068"))) PPC_WEAK_FUNC(sub_821C8068);
PPC_FUNC_IMPL(__imp__sub_821C8068) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x821C8094;
	sub_8207DAC0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C80B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C80C4"))) PPC_WEAK_FUNC(sub_821C80C4);
PPC_FUNC_IMPL(__imp__sub_821C80C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C80C8"))) PPC_WEAK_FUNC(sub_821C80C8);
PPC_FUNC_IMPL(__imp__sub_821C80C8) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r10.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x821c8178
	if (ctx.cr6.eq) goto loc_821C8178;
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c8114
	if (ctx.cr6.eq) goto loc_821C8114;
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// bne cr6,0x821c8120
	if (!ctx.cr6.eq) goto loc_821C8120;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x821c8118
	goto loc_821C8118;
loc_821C8114:
	// li r11,3
	ctx.r11.s64 = 3;
loc_821C8118:
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
loc_821C8120:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r11,32
	ctx.r7.s64 = ctx.r11.s64 + 32;
	// li r4,4
	ctx.r4.s64 = 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31352(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,76(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,80(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stwx r9,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// addi r6,r11,32
	ctx.r6.s64 = ctx.r11.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r8.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C8178;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821C8178:
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_821C8194"))) PPC_WEAK_FUNC(sub_821C8194);
PPC_FUNC_IMPL(__imp__sub_821C8194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8198"))) PPC_WEAK_FUNC(sub_821C8198);
PPC_FUNC_IMPL(__imp__sub_821C8198) {
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
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,-840
	ctx.r9.s64 = ctx.r11.s64 + -840;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C81CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821c81e4
	if (ctx.cr6.eq) goto loc_821C81E4;
	// bl 0x82088d98
	ctx.lr = 0x821C81DC;
	sub_82088D98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_821C81E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821c5738
	ctx.lr = 0x821C81EC;
	sub_821C5738(ctx, base);
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

__attribute__((alias("__imp__sub_821C8200"))) PPC_WEAK_FUNC(sub_821C8200);
PPC_FUNC_IMPL(__imp__sub_821C8200) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821C8208;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x821c57b8
	ctx.lr = 0x821C8214;
	sub_821C57B8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,-840
	ctx.r10.s64 = ctx.r11.s64 + -840;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// li r5,13
	ctx.r5.s64 = 13;
	// stw r31,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r31.u32);
	// addi r30,r9,-4548
	ctx.r30.s64 = ctx.r9.s64 + -4548;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,-24
	ctx.r4.s64 = ctx.r30.s64 + -24;
	// bl 0x82060368
	ctx.lr = 0x821C8250;
	sub_82060368(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82061510
	ctx.lr = 0x821C8260;
	sub_82061510(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r30,-8
	ctx.r5.s64 = ctx.r30.s64 + -8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820615b8
	ctx.lr = 0x821C8270;
	sub_820615B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821C8284;
	sub_820601F8(ctx, base);
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x821c8298
	if (ctx.cr6.lt) goto loc_821C8298;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x821C8298;
	sub_8207A630(ctx, base);
loc_821C8298:
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r28.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// blt cr6,0x821c82b8
	if (ctx.cr6.lt) goto loc_821C82B8;
	// lwz r3,148(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x8207a630
	ctx.lr = 0x821C82B8;
	sub_8207A630(ctx, base);
loc_821C82B8:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r28.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// bge cr6,0x821c82d8
	if (!ctx.cr6.lt) goto loc_821C82D8;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C82D8:
	// bl 0x82088e10
	ctx.lr = 0x821C82DC;
	sub_82088E10(ctx, base);
	// stw r3,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c8320
	if (!ctx.cr6.eq) goto loc_821C8320;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c82fc
	if (!ctx.cr6.lt) goto loc_821C82FC;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C82FC:
	// bl 0x8210e878
	ctx.lr = 0x821C8300;
	sub_8210E878(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821c8354
	if (ctx.cr6.lt) goto loc_821C8354;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821C8314;
	sub_8207A630(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821C8320:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82088dd0
	ctx.lr = 0x821C8328;
	sub_82088DD0(ctx, base);
	// stw r3,252(r29)
	PPC_STORE_U32(ctx.r29.u32 + 252, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c834c
	if (!ctx.cr6.eq) goto loc_821C834C;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c8348
	if (!ctx.cr6.lt) goto loc_821C8348;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C8348:
	// bl 0x8210e878
	ctx.lr = 0x821C834C;
	sub_8210E878(ctx, base);
loc_821C834C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82065fe8
	ctx.lr = 0x821C8354;
	sub_82065FE8(ctx, base);
loc_821C8354:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C8360"))) PPC_WEAK_FUNC(sub_821C8360);
PPC_FUNC_IMPL(__imp__sub_821C8360) {
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
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821c64e8
	ctx.lr = 0x821C837C;
	sub_821C64E8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C839C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// li r3,7
	ctx.r3.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C83B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,304
	ctx.r5.s64 = 304;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// addi r4,r11,152
	ctx.r4.s64 = ctx.r11.s64 + 152;
	// bl 0x8207dac0
	ctx.lr = 0x821C83FC;
	sub_8207DAC0(ctx, base);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// lwz r11,-31364(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c8420
	if (ctx.cr6.eq) goto loc_821C8420;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c8424
	if (!ctx.cr6.eq) goto loc_821C8424;
loc_821C8420:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C8424:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r8,r9,-32240
	ctx.r8.s64 = ctx.r9.s64 + -32240;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// beq cr6,0x821c844c
	if (ctx.cr6.eq) goto loc_821C844C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// bne cr6,0x821c8450
	if (!ctx.cr6.eq) goto loc_821C8450;
loc_821C844C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C8450:
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r8,r9,-23112
	ctx.r8.s64 = ctx.r9.s64 + -23112;
	// lwz r7,252(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821C8478;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,252(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821C848C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r31,180
	ctx.r4.s64 = ctx.r31.s64 + 180;
	// li r3,8
	ctx.r3.s64 = 8;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C84A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r4,-32228
	ctx.r4.s64 = -2112094208;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// lis r3,-32228
	ctx.r3.s64 = -2112094208;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r9,r4,21224
	ctx.r9.s64 = ctx.r4.s64 + 21224;
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r8,r3,25096
	ctx.r8.s64 = ctx.r3.s64 + 25096;
	// addi r7,r11,22040
	ctx.r7.s64 = ctx.r11.s64 + 22040;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// addi r6,r10,21040
	ctx.r6.s64 = ctx.r10.s64 + 21040;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// li r3,9
	ctx.r3.s64 = 9;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C84F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,52(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8508;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
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

__attribute__((alias("__imp__sub_821C8520"))) PPC_WEAK_FUNC(sub_821C8520);
PPC_FUNC_IMPL(__imp__sub_821C8520) {
	PPC_FUNC_PROLOGUE();
	// b 0x821c69f0
	sub_821C69F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C8524"))) PPC_WEAK_FUNC(sub_821C8524);
PPC_FUNC_IMPL(__imp__sub_821C8524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8528"))) PPC_WEAK_FUNC(sub_821C8528);
PPC_FUNC_IMPL(__imp__sub_821C8528) {
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
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c8568
	if (ctx.cr6.eq) goto loc_821C8568;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c8568
	if (!ctx.cr6.eq) goto loc_821C8568;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-31368(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31368, ctx.r10.u32);
	// bl 0x82184cc8
	ctx.lr = 0x821C8568;
	sub_82184CC8(ctx, base);
loc_821C8568:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-31304(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31304);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x821C8588;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x821c54f8
	ctx.lr = 0x821C858C;
	sub_821C54F8(ctx, base);
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

__attribute__((alias("__imp__sub_821C85A0"))) PPC_WEAK_FUNC(sub_821C85A0);
PPC_FUNC_IMPL(__imp__sub_821C85A0) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821c85bc
	if (ctx.cr6.lt) goto loc_821C85BC;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// ble cr6,0x821c85c0
	if (!ctx.cr6.gt) goto loc_821C85C0;
loc_821C85BC:
	// li r4,4
	ctx.r4.s64 = 4;
loc_821C85C0:
	// stw r4,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x821c85d8
	if (!ctx.cr6.lt) goto loc_821C85D8;
	// subfic r11,r4,4
	ctx.xer.ca = ctx.r4.u32 <= 4;
	ctx.r11.s64 = 4 - ctx.r4.s64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// b 0x821c85e0
	goto loc_821C85E0;
loc_821C85D8:
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_821C85E0:
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,11
	ctx.r3.s64 = 11;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C85FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C860C"))) PPC_WEAK_FUNC(sub_821C860C);
PPC_FUNC_IMPL(__imp__sub_821C860C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8610"))) PPC_WEAK_FUNC(sub_821C8610);
PPC_FUNC_IMPL(__imp__sub_821C8610) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,14
	ctx.r3.s64 = 14;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8624"))) PPC_WEAK_FUNC(sub_821C8624);
PPC_FUNC_IMPL(__imp__sub_821C8624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8628"))) PPC_WEAK_FUNC(sub_821C8628);
PPC_FUNC_IMPL(__imp__sub_821C8628) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c8654
	if (!ctx.cr6.eq) goto loc_821C8654;
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bne cr6,0x821c8654
	if (!ctx.cr6.eq) goto loc_821C8654;
	// lbz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C8654:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C865C"))) PPC_WEAK_FUNC(sub_821C865C);
PPC_FUNC_IMPL(__imp__sub_821C865C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8660"))) PPC_WEAK_FUNC(sub_821C8660);
PPC_FUNC_IMPL(__imp__sub_821C8660) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8674"))) PPC_WEAK_FUNC(sub_821C8674);
PPC_FUNC_IMPL(__imp__sub_821C8674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8678"))) PPC_WEAK_FUNC(sub_821C8678);
PPC_FUNC_IMPL(__imp__sub_821C8678) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C868C"))) PPC_WEAK_FUNC(sub_821C868C);
PPC_FUNC_IMPL(__imp__sub_821C868C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8690"))) PPC_WEAK_FUNC(sub_821C8690);
PPC_FUNC_IMPL(__imp__sub_821C8690) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c86b0
	if (!ctx.cr6.eq) goto loc_821C86B0;
	// lbz r11,6(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C86B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C86B8"))) PPC_WEAK_FUNC(sub_821C86B8);
PPC_FUNC_IMPL(__imp__sub_821C86B8) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,19
	ctx.r3.s64 = 19;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C86DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C86EC"))) PPC_WEAK_FUNC(sub_821C86EC);
PPC_FUNC_IMPL(__imp__sub_821C86EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C86F0"))) PPC_WEAK_FUNC(sub_821C86F0);
PPC_FUNC_IMPL(__imp__sub_821C86F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,18
	ctx.r3.s64 = 18;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8700"))) PPC_WEAK_FUNC(sub_821C8700);
PPC_FUNC_IMPL(__imp__sub_821C8700) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// li r3,17
	ctx.r3.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C8734;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8748"))) PPC_WEAK_FUNC(sub_821C8748);
PPC_FUNC_IMPL(__imp__sub_821C8748) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,16
	ctx.r3.s64 = 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C876C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C877C"))) PPC_WEAK_FUNC(sub_821C877C);
PPC_FUNC_IMPL(__imp__sub_821C877C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8780"))) PPC_WEAK_FUNC(sub_821C8780);
PPC_FUNC_IMPL(__imp__sub_821C8780) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x821C87A8;
	sub_8207DAC0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C87C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C87D8"))) PPC_WEAK_FUNC(sub_821C87D8);
PPC_FUNC_IMPL(__imp__sub_821C87D8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c8800
	if (ctx.cr6.eq) goto loc_821C8800;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
loc_821C8800:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8818;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8828"))) PPC_WEAK_FUNC(sub_821C8828);
PPC_FUNC_IMPL(__imp__sub_821C8828) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c885c
	if (ctx.cr6.eq) goto loc_821C885C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r5,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r5.u32);
	// stw r6,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r6.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// b 0x821c8864
	goto loc_821C8864;
loc_821C885C:
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_821C8864:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C887C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C888C"))) PPC_WEAK_FUNC(sub_821C888C);
PPC_FUNC_IMPL(__imp__sub_821C888C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8890"))) PPC_WEAK_FUNC(sub_821C8890);
PPC_FUNC_IMPL(__imp__sub_821C8890) {
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
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r9,192(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mulli r10,r10,720
	ctx.r10.s64 = ctx.r10.s64 * 720;
	// lwz r8,252(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r3,20
	ctx.r3.s64 = 20;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bctrl 
	ctx.lr = 0x821C88D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C88E8"))) PPC_WEAK_FUNC(sub_821C88E8);
PPC_FUNC_IMPL(__imp__sub_821C88E8) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x821C8914;
	sub_8207DAC0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C8930;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C8944"))) PPC_WEAK_FUNC(sub_821C8944);
PPC_FUNC_IMPL(__imp__sub_821C8944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8948"))) PPC_WEAK_FUNC(sub_821C8948);
PPC_FUNC_IMPL(__imp__sub_821C8948) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r10.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x821c89f8
	if (ctx.cr6.eq) goto loc_821C89F8;
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c8994
	if (ctx.cr6.eq) goto loc_821C8994;
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// bne cr6,0x821c89a0
	if (!ctx.cr6.eq) goto loc_821C89A0;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x821c8998
	goto loc_821C8998;
loc_821C8994:
	// li r11,3
	ctx.r11.s64 = 3;
loc_821C8998:
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
loc_821C89A0:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r11,32
	ctx.r7.s64 = ctx.r11.s64 + 32;
	// li r4,4
	ctx.r4.s64 = 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31352(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,76(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,80(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stwx r9,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// addi r6,r11,32
	ctx.r6.s64 = ctx.r11.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r8.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C89F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821C89F8:
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_821C8A14"))) PPC_WEAK_FUNC(sub_821C8A14);
PPC_FUNC_IMPL(__imp__sub_821C8A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8A18"))) PPC_WEAK_FUNC(sub_821C8A18);
PPC_FUNC_IMPL(__imp__sub_821C8A18) {
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
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,-968
	ctx.r9.s64 = ctx.r11.s64 + -968;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C8A4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821c8a64
	if (ctx.cr6.eq) goto loc_821C8A64;
	// bl 0x82088d98
	ctx.lr = 0x821C8A5C;
	sub_82088D98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_821C8A64:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821c5738
	ctx.lr = 0x821C8A6C;
	sub_821C5738(ctx, base);
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

__attribute__((alias("__imp__sub_821C8A80"))) PPC_WEAK_FUNC(sub_821C8A80);
PPC_FUNC_IMPL(__imp__sub_821C8A80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821C8A88;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x821c57b8
	ctx.lr = 0x821C8A94;
	sub_821C57B8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,-968
	ctx.r10.s64 = ctx.r11.s64 + -968;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// li r5,11
	ctx.r5.s64 = 11;
	// stw r31,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r31.u32);
	// addi r30,r9,-4308
	ctx.r30.s64 = ctx.r9.s64 + -4308;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,-104
	ctx.r4.s64 = ctx.r30.s64 + -104;
	// bl 0x82060368
	ctx.lr = 0x821C8AD0;
	sub_82060368(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82061510
	ctx.lr = 0x821C8AE0;
	sub_82061510(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r30,-8
	ctx.r5.s64 = ctx.r30.s64 + -8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820615b8
	ctx.lr = 0x821C8AF0;
	sub_820615B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821C8B04;
	sub_820601F8(ctx, base);
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x821c8b18
	if (ctx.cr6.lt) goto loc_821C8B18;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x821C8B18;
	sub_8207A630(ctx, base);
loc_821C8B18:
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r28.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// blt cr6,0x821c8b38
	if (ctx.cr6.lt) goto loc_821C8B38;
	// lwz r3,148(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x8207a630
	ctx.lr = 0x821C8B38;
	sub_8207A630(ctx, base);
loc_821C8B38:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r28.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// bge cr6,0x821c8b58
	if (!ctx.cr6.lt) goto loc_821C8B58;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C8B58:
	// bl 0x82088e10
	ctx.lr = 0x821C8B5C;
	sub_82088E10(ctx, base);
	// stw r3,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c8ba0
	if (!ctx.cr6.eq) goto loc_821C8BA0;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c8b7c
	if (!ctx.cr6.lt) goto loc_821C8B7C;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C8B7C:
	// bl 0x8210e878
	ctx.lr = 0x821C8B80;
	sub_8210E878(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821c8bd4
	if (ctx.cr6.lt) goto loc_821C8BD4;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821C8B94;
	sub_8207A630(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821C8BA0:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82088dd0
	ctx.lr = 0x821C8BA8;
	sub_82088DD0(ctx, base);
	// stw r3,252(r29)
	PPC_STORE_U32(ctx.r29.u32 + 252, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c8bcc
	if (!ctx.cr6.eq) goto loc_821C8BCC;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c8bc8
	if (!ctx.cr6.lt) goto loc_821C8BC8;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C8BC8:
	// bl 0x8210e878
	ctx.lr = 0x821C8BCC;
	sub_8210E878(ctx, base);
loc_821C8BCC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82065fe8
	ctx.lr = 0x821C8BD4;
	sub_82065FE8(ctx, base);
loc_821C8BD4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C8BE0"))) PPC_WEAK_FUNC(sub_821C8BE0);
PPC_FUNC_IMPL(__imp__sub_821C8BE0) {
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
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821c64e8
	ctx.lr = 0x821C8BFC;
	sub_821C64E8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8C1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// li r3,7
	ctx.r3.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C8C30;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,304
	ctx.r5.s64 = 304;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// addi r4,r11,152
	ctx.r4.s64 = ctx.r11.s64 + 152;
	// bl 0x8207dac0
	ctx.lr = 0x821C8C7C;
	sub_8207DAC0(ctx, base);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// lwz r11,-31364(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c8ca0
	if (ctx.cr6.eq) goto loc_821C8CA0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c8ca4
	if (!ctx.cr6.eq) goto loc_821C8CA4;
loc_821C8CA0:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C8CA4:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r8,r9,-32240
	ctx.r8.s64 = ctx.r9.s64 + -32240;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// beq cr6,0x821c8ccc
	if (ctx.cr6.eq) goto loc_821C8CCC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// bne cr6,0x821c8cd0
	if (!ctx.cr6.eq) goto loc_821C8CD0;
loc_821C8CCC:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C8CD0:
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r8,r9,-23112
	ctx.r8.s64 = ctx.r9.s64 + -23112;
	// lwz r7,252(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821C8CF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,252(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821C8D0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r31,180
	ctx.r4.s64 = ctx.r31.s64 + 180;
	// li r3,8
	ctx.r3.s64 = 8;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C8D20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r4,-32228
	ctx.r4.s64 = -2112094208;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// lis r3,-32228
	ctx.r3.s64 = -2112094208;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r9,r4,21224
	ctx.r9.s64 = ctx.r4.s64 + 21224;
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r8,r3,25096
	ctx.r8.s64 = ctx.r3.s64 + 25096;
	// addi r7,r11,22040
	ctx.r7.s64 = ctx.r11.s64 + 22040;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// addi r6,r10,21040
	ctx.r6.s64 = ctx.r10.s64 + 21040;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// li r3,9
	ctx.r3.s64 = 9;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C8D74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,52(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8D88;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
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

__attribute__((alias("__imp__sub_821C8DA0"))) PPC_WEAK_FUNC(sub_821C8DA0);
PPC_FUNC_IMPL(__imp__sub_821C8DA0) {
	PPC_FUNC_PROLOGUE();
	// b 0x821c69f0
	sub_821C69F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C8DA4"))) PPC_WEAK_FUNC(sub_821C8DA4);
PPC_FUNC_IMPL(__imp__sub_821C8DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8DA8"))) PPC_WEAK_FUNC(sub_821C8DA8);
PPC_FUNC_IMPL(__imp__sub_821C8DA8) {
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
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c8de8
	if (ctx.cr6.eq) goto loc_821C8DE8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c8de8
	if (!ctx.cr6.eq) goto loc_821C8DE8;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-31368(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31368, ctx.r10.u32);
	// bl 0x82184cc8
	ctx.lr = 0x821C8DE8;
	sub_82184CC8(ctx, base);
loc_821C8DE8:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-31304(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31304);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x821C8E08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x821c54f8
	ctx.lr = 0x821C8E0C;
	sub_821C54F8(ctx, base);
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

__attribute__((alias("__imp__sub_821C8E20"))) PPC_WEAK_FUNC(sub_821C8E20);
PPC_FUNC_IMPL(__imp__sub_821C8E20) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821c8e3c
	if (ctx.cr6.lt) goto loc_821C8E3C;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// ble cr6,0x821c8e40
	if (!ctx.cr6.gt) goto loc_821C8E40;
loc_821C8E3C:
	// li r4,4
	ctx.r4.s64 = 4;
loc_821C8E40:
	// stw r4,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x821c8e58
	if (!ctx.cr6.lt) goto loc_821C8E58;
	// subfic r11,r4,4
	ctx.xer.ca = ctx.r4.u32 <= 4;
	ctx.r11.s64 = 4 - ctx.r4.s64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// b 0x821c8e60
	goto loc_821C8E60;
loc_821C8E58:
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_821C8E60:
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,11
	ctx.r3.s64 = 11;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8E7C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8E8C"))) PPC_WEAK_FUNC(sub_821C8E8C);
PPC_FUNC_IMPL(__imp__sub_821C8E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8E90"))) PPC_WEAK_FUNC(sub_821C8E90);
PPC_FUNC_IMPL(__imp__sub_821C8E90) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,14
	ctx.r3.s64 = 14;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8EA4"))) PPC_WEAK_FUNC(sub_821C8EA4);
PPC_FUNC_IMPL(__imp__sub_821C8EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8EA8"))) PPC_WEAK_FUNC(sub_821C8EA8);
PPC_FUNC_IMPL(__imp__sub_821C8EA8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c8ed4
	if (!ctx.cr6.eq) goto loc_821C8ED4;
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bne cr6,0x821c8ed4
	if (!ctx.cr6.eq) goto loc_821C8ED4;
	// lbz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C8ED4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8EDC"))) PPC_WEAK_FUNC(sub_821C8EDC);
PPC_FUNC_IMPL(__imp__sub_821C8EDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8EE0"))) PPC_WEAK_FUNC(sub_821C8EE0);
PPC_FUNC_IMPL(__imp__sub_821C8EE0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8EF4"))) PPC_WEAK_FUNC(sub_821C8EF4);
PPC_FUNC_IMPL(__imp__sub_821C8EF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8EF8"))) PPC_WEAK_FUNC(sub_821C8EF8);
PPC_FUNC_IMPL(__imp__sub_821C8EF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8F0C"))) PPC_WEAK_FUNC(sub_821C8F0C);
PPC_FUNC_IMPL(__imp__sub_821C8F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8F10"))) PPC_WEAK_FUNC(sub_821C8F10);
PPC_FUNC_IMPL(__imp__sub_821C8F10) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c8f30
	if (!ctx.cr6.eq) goto loc_821C8F30;
	// lbz r11,6(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C8F30:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8F38"))) PPC_WEAK_FUNC(sub_821C8F38);
PPC_FUNC_IMPL(__imp__sub_821C8F38) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,19
	ctx.r3.s64 = 19;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8F5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8F6C"))) PPC_WEAK_FUNC(sub_821C8F6C);
PPC_FUNC_IMPL(__imp__sub_821C8F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C8F70"))) PPC_WEAK_FUNC(sub_821C8F70);
PPC_FUNC_IMPL(__imp__sub_821C8F70) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,18
	ctx.r3.s64 = 18;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C8F80"))) PPC_WEAK_FUNC(sub_821C8F80);
PPC_FUNC_IMPL(__imp__sub_821C8F80) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// li r3,17
	ctx.r3.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C8FB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8FC8"))) PPC_WEAK_FUNC(sub_821C8FC8);
PPC_FUNC_IMPL(__imp__sub_821C8FC8) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,16
	ctx.r3.s64 = 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C8FEC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C8FFC"))) PPC_WEAK_FUNC(sub_821C8FFC);
PPC_FUNC_IMPL(__imp__sub_821C8FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9000"))) PPC_WEAK_FUNC(sub_821C9000);
PPC_FUNC_IMPL(__imp__sub_821C9000) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x821C9028;
	sub_8207DAC0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C9040;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C9058"))) PPC_WEAK_FUNC(sub_821C9058);
PPC_FUNC_IMPL(__imp__sub_821C9058) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c9080
	if (ctx.cr6.eq) goto loc_821C9080;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
loc_821C9080:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C9098;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C90A8"))) PPC_WEAK_FUNC(sub_821C90A8);
PPC_FUNC_IMPL(__imp__sub_821C90A8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c90dc
	if (ctx.cr6.eq) goto loc_821C90DC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r5,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r5.u32);
	// stw r6,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r6.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// b 0x821c90e4
	goto loc_821C90E4;
loc_821C90DC:
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_821C90E4:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C90FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C910C"))) PPC_WEAK_FUNC(sub_821C910C);
PPC_FUNC_IMPL(__imp__sub_821C910C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9110"))) PPC_WEAK_FUNC(sub_821C9110);
PPC_FUNC_IMPL(__imp__sub_821C9110) {
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
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r9,192(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mulli r10,r10,720
	ctx.r10.s64 = ctx.r10.s64 * 720;
	// lwz r8,252(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r3,20
	ctx.r3.s64 = 20;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bctrl 
	ctx.lr = 0x821C9158;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C9168"))) PPC_WEAK_FUNC(sub_821C9168);
PPC_FUNC_IMPL(__imp__sub_821C9168) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x821C9194;
	sub_8207DAC0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C91B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C91C4"))) PPC_WEAK_FUNC(sub_821C91C4);
PPC_FUNC_IMPL(__imp__sub_821C91C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C91C8"))) PPC_WEAK_FUNC(sub_821C91C8);
PPC_FUNC_IMPL(__imp__sub_821C91C8) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r10.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x821c9278
	if (ctx.cr6.eq) goto loc_821C9278;
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c9214
	if (ctx.cr6.eq) goto loc_821C9214;
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// bne cr6,0x821c9220
	if (!ctx.cr6.eq) goto loc_821C9220;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x821c9218
	goto loc_821C9218;
loc_821C9214:
	// li r11,3
	ctx.r11.s64 = 3;
loc_821C9218:
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
loc_821C9220:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r11,32
	ctx.r7.s64 = ctx.r11.s64 + 32;
	// li r4,4
	ctx.r4.s64 = 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31352(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,76(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,80(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stwx r9,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// addi r6,r11,32
	ctx.r6.s64 = ctx.r11.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r8.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C9278;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821C9278:
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_821C9294"))) PPC_WEAK_FUNC(sub_821C9294);
PPC_FUNC_IMPL(__imp__sub_821C9294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9298"))) PPC_WEAK_FUNC(sub_821C9298);
PPC_FUNC_IMPL(__imp__sub_821C9298) {
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
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,-1096
	ctx.r9.s64 = ctx.r11.s64 + -1096;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C92CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821c92e4
	if (ctx.cr6.eq) goto loc_821C92E4;
	// bl 0x82088d98
	ctx.lr = 0x821C92DC;
	sub_82088D98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_821C92E4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821c5738
	ctx.lr = 0x821C92EC;
	sub_821C5738(ctx, base);
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

__attribute__((alias("__imp__sub_821C9300"))) PPC_WEAK_FUNC(sub_821C9300);
PPC_FUNC_IMPL(__imp__sub_821C9300) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821C9308;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x821c57b8
	ctx.lr = 0x821C9314;
	sub_821C57B8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,-1096
	ctx.r10.s64 = ctx.r11.s64 + -1096;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// li r5,14
	ctx.r5.s64 = 14;
	// stw r31,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r31.u32);
	// addi r30,r9,-4172
	ctx.r30.s64 = ctx.r9.s64 + -4172;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,104
	ctx.r4.s64 = ctx.r30.s64 + 104;
	// bl 0x82060368
	ctx.lr = 0x821C9350;
	sub_82060368(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82061510
	ctx.lr = 0x821C9360;
	sub_82061510(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r30,120
	ctx.r5.s64 = ctx.r30.s64 + 120;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820615b8
	ctx.lr = 0x821C9370;
	sub_820615B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821C9384;
	sub_820601F8(ctx, base);
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x821c9398
	if (ctx.cr6.lt) goto loc_821C9398;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x821C9398;
	sub_8207A630(ctx, base);
loc_821C9398:
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r28.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// blt cr6,0x821c93b8
	if (ctx.cr6.lt) goto loc_821C93B8;
	// lwz r3,148(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x8207a630
	ctx.lr = 0x821C93B8;
	sub_8207A630(ctx, base);
loc_821C93B8:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r28.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// bge cr6,0x821c93d8
	if (!ctx.cr6.lt) goto loc_821C93D8;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C93D8:
	// bl 0x82088e10
	ctx.lr = 0x821C93DC;
	sub_82088E10(ctx, base);
	// stw r3,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c9420
	if (!ctx.cr6.eq) goto loc_821C9420;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c93fc
	if (!ctx.cr6.lt) goto loc_821C93FC;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C93FC:
	// bl 0x8210e878
	ctx.lr = 0x821C9400;
	sub_8210E878(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821c9454
	if (ctx.cr6.lt) goto loc_821C9454;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821C9414;
	sub_8207A630(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821C9420:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82088dd0
	ctx.lr = 0x821C9428;
	sub_82088DD0(ctx, base);
	// stw r3,252(r29)
	PPC_STORE_U32(ctx.r29.u32 + 252, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c944c
	if (!ctx.cr6.eq) goto loc_821C944C;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c9448
	if (!ctx.cr6.lt) goto loc_821C9448;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C9448:
	// bl 0x8210e878
	ctx.lr = 0x821C944C;
	sub_8210E878(ctx, base);
loc_821C944C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82065fe8
	ctx.lr = 0x821C9454;
	sub_82065FE8(ctx, base);
loc_821C9454:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C9460"))) PPC_WEAK_FUNC(sub_821C9460);
PPC_FUNC_IMPL(__imp__sub_821C9460) {
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
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821c64e8
	ctx.lr = 0x821C947C;
	sub_821C64E8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C949C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// li r3,7
	ctx.r3.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C94B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,304
	ctx.r5.s64 = 304;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// addi r4,r11,152
	ctx.r4.s64 = ctx.r11.s64 + 152;
	// bl 0x8207dac0
	ctx.lr = 0x821C94FC;
	sub_8207DAC0(ctx, base);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// lwz r11,-31364(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c9520
	if (ctx.cr6.eq) goto loc_821C9520;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c9524
	if (!ctx.cr6.eq) goto loc_821C9524;
loc_821C9520:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C9524:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r8,r9,-32240
	ctx.r8.s64 = ctx.r9.s64 + -32240;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// beq cr6,0x821c954c
	if (ctx.cr6.eq) goto loc_821C954C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// bne cr6,0x821c9550
	if (!ctx.cr6.eq) goto loc_821C9550;
loc_821C954C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C9550:
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r8,r9,-23112
	ctx.r8.s64 = ctx.r9.s64 + -23112;
	// lwz r7,252(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821C9578;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,252(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821C958C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r31,180
	ctx.r4.s64 = ctx.r31.s64 + 180;
	// li r3,8
	ctx.r3.s64 = 8;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C95A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r4,-32228
	ctx.r4.s64 = -2112094208;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// lis r3,-32228
	ctx.r3.s64 = -2112094208;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r9,r4,21224
	ctx.r9.s64 = ctx.r4.s64 + 21224;
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r8,r3,25096
	ctx.r8.s64 = ctx.r3.s64 + 25096;
	// addi r7,r11,22040
	ctx.r7.s64 = ctx.r11.s64 + 22040;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// addi r6,r10,21040
	ctx.r6.s64 = ctx.r10.s64 + 21040;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// li r3,9
	ctx.r3.s64 = 9;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C95F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,52(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C9608;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
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

__attribute__((alias("__imp__sub_821C9620"))) PPC_WEAK_FUNC(sub_821C9620);
PPC_FUNC_IMPL(__imp__sub_821C9620) {
	PPC_FUNC_PROLOGUE();
	// b 0x821c69f0
	sub_821C69F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C9624"))) PPC_WEAK_FUNC(sub_821C9624);
PPC_FUNC_IMPL(__imp__sub_821C9624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9628"))) PPC_WEAK_FUNC(sub_821C9628);
PPC_FUNC_IMPL(__imp__sub_821C9628) {
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
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c9668
	if (ctx.cr6.eq) goto loc_821C9668;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c9668
	if (!ctx.cr6.eq) goto loc_821C9668;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-31368(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31368, ctx.r10.u32);
	// bl 0x82184cc8
	ctx.lr = 0x821C9668;
	sub_82184CC8(ctx, base);
loc_821C9668:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-31304(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31304);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x821C9688;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x821c54f8
	ctx.lr = 0x821C968C;
	sub_821C54F8(ctx, base);
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

__attribute__((alias("__imp__sub_821C96A0"))) PPC_WEAK_FUNC(sub_821C96A0);
PPC_FUNC_IMPL(__imp__sub_821C96A0) {
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
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x821c96bc
	if (ctx.cr6.lt) goto loc_821C96BC;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// ble cr6,0x821c96c0
	if (!ctx.cr6.gt) goto loc_821C96C0;
loc_821C96BC:
	// li r4,4
	ctx.r4.s64 = 4;
loc_821C96C0:
	// stw r4,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bge cr6,0x821c96d8
	if (!ctx.cr6.lt) goto loc_821C96D8;
	// subfic r11,r4,4
	ctx.xer.ca = ctx.r4.u32 <= 4;
	ctx.r11.s64 = 4 - ctx.r4.s64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// b 0x821c96e0
	goto loc_821C96E0;
loc_821C96D8:
	// addi r11,r4,-4
	ctx.r11.s64 = ctx.r4.s64 + -4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_821C96E0:
	// slw r9,r10,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,11
	ctx.r3.s64 = 11;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C96FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C970C"))) PPC_WEAK_FUNC(sub_821C970C);
PPC_FUNC_IMPL(__imp__sub_821C970C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9710"))) PPC_WEAK_FUNC(sub_821C9710);
PPC_FUNC_IMPL(__imp__sub_821C9710) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,14
	ctx.r3.s64 = 14;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C9724"))) PPC_WEAK_FUNC(sub_821C9724);
PPC_FUNC_IMPL(__imp__sub_821C9724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9728"))) PPC_WEAK_FUNC(sub_821C9728);
PPC_FUNC_IMPL(__imp__sub_821C9728) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c9754
	if (!ctx.cr6.eq) goto loc_821C9754;
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// bne cr6,0x821c9754
	if (!ctx.cr6.eq) goto loc_821C9754;
	// lbz r11,3(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C9754:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C975C"))) PPC_WEAK_FUNC(sub_821C975C);
PPC_FUNC_IMPL(__imp__sub_821C975C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9760"))) PPC_WEAK_FUNC(sub_821C9760);
PPC_FUNC_IMPL(__imp__sub_821C9760) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,13
	ctx.r3.s64 = 13;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C9774"))) PPC_WEAK_FUNC(sub_821C9774);
PPC_FUNC_IMPL(__imp__sub_821C9774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9778"))) PPC_WEAK_FUNC(sub_821C9778);
PPC_FUNC_IMPL(__imp__sub_821C9778) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C978C"))) PPC_WEAK_FUNC(sub_821C978C);
PPC_FUNC_IMPL(__imp__sub_821C978C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9790"))) PPC_WEAK_FUNC(sub_821C9790);
PPC_FUNC_IMPL(__imp__sub_821C9790) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,180(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// bne cr6,0x821c97b0
	if (!ctx.cr6.eq) goto loc_821C97B0;
	// lbz r11,6(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_821C97B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C97B8"))) PPC_WEAK_FUNC(sub_821C97B8);
PPC_FUNC_IMPL(__imp__sub_821C97B8) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,19
	ctx.r3.s64 = 19;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C97DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C97EC"))) PPC_WEAK_FUNC(sub_821C97EC);
PPC_FUNC_IMPL(__imp__sub_821C97EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C97F0"))) PPC_WEAK_FUNC(sub_821C97F0);
PPC_FUNC_IMPL(__imp__sub_821C97F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,18
	ctx.r3.s64 = 18;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821C9800"))) PPC_WEAK_FUNC(sub_821C9800);
PPC_FUNC_IMPL(__imp__sub_821C9800) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// li r3,17
	ctx.r3.s64 = 17;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C9834;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C9848"))) PPC_WEAK_FUNC(sub_821C9848);
PPC_FUNC_IMPL(__imp__sub_821C9848) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,16
	ctx.r3.s64 = 16;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C986C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C987C"))) PPC_WEAK_FUNC(sub_821C987C);
PPC_FUNC_IMPL(__imp__sub_821C987C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9880"))) PPC_WEAK_FUNC(sub_821C9880);
PPC_FUNC_IMPL(__imp__sub_821C9880) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x8207dac0
	ctx.lr = 0x821C98A8;
	sub_8207DAC0(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r30.u32);
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C98C0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C98D8"))) PPC_WEAK_FUNC(sub_821C98D8);
PPC_FUNC_IMPL(__imp__sub_821C98D8) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c9900
	if (ctx.cr6.eq) goto loc_821C9900;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
loc_821C9900:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C9918;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C9928"))) PPC_WEAK_FUNC(sub_821C9928);
PPC_FUNC_IMPL(__imp__sub_821C9928) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c995c
	if (ctx.cr6.eq) goto loc_821C995C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r5,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r5.u32);
	// stw r6,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r6.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// b 0x821c9964
	goto loc_821C9964;
loc_821C995C:
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r11.u32);
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r11.u32);
loc_821C9964:
	// stw r4,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r11,252(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// li r3,10
	ctx.r3.s64 = 10;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C997C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C998C"))) PPC_WEAK_FUNC(sub_821C998C);
PPC_FUNC_IMPL(__imp__sub_821C998C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9990"))) PPC_WEAK_FUNC(sub_821C9990);
PPC_FUNC_IMPL(__imp__sub_821C9990) {
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
	// lwz r10,168(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r9,192(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mulli r10,r10,720
	ctx.r10.s64 = ctx.r10.s64 * 720;
	// lwz r8,252(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r3,20
	ctx.r3.s64 = 20;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r7,r11,16
	ctx.r7.s64 = ctx.r11.s64 + 16;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bctrl 
	ctx.lr = 0x821C99D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821C99E8"))) PPC_WEAK_FUNC(sub_821C99E8);
PPC_FUNC_IMPL(__imp__sub_821C99E8) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,-31348(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31348);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8207dac0
	ctx.lr = 0x821C9A14;
	sub_8207DAC0(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r9,252(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r3,15
	ctx.r3.s64 = 15;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C9A30;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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

__attribute__((alias("__imp__sub_821C9A44"))) PPC_WEAK_FUNC(sub_821C9A44);
PPC_FUNC_IMPL(__imp__sub_821C9A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9A48"))) PPC_WEAK_FUNC(sub_821C9A48);
PPC_FUNC_IMPL(__imp__sub_821C9A48) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r10,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r10.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x821c9af8
	if (ctx.cr6.eq) goto loc_821C9AF8;
	// li r11,2
	ctx.r11.s64 = 2;
	// cmplwi cr6,r5,3
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 3, ctx.xer);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r11.u32);
	// beq cr6,0x821c9a94
	if (ctx.cr6.eq) goto loc_821C9A94;
	// cmplwi cr6,r5,4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 4, ctx.xer);
	// bne cr6,0x821c9aa0
	if (!ctx.cr6.eq) goto loc_821C9AA0;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x821c9a98
	goto loc_821C9A98;
loc_821C9A94:
	// li r11,3
	ctx.r11.s64 = 3;
loc_821C9A98:
	// stw r11,120(r31)
	PPC_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r10,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
loc_821C9AA0:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r11,116(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r11,32
	ctx.r7.s64 = ctx.r11.s64 + 32;
	// li r4,4
	ctx.r4.s64 = 4;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-31352(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,76(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,80(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// stwx r9,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r7,116(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 116);
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// addi r6,r11,32
	ctx.r6.s64 = ctx.r11.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + ctx.r31.u32, ctx.r8.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stw r10,136(r31)
	PPC_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C9AF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821C9AF8:
	// stw r30,152(r31)
	PPC_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
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

__attribute__((alias("__imp__sub_821C9B14"))) PPC_WEAK_FUNC(sub_821C9B14);
PPC_FUNC_IMPL(__imp__sub_821C9B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9B18"))) PPC_WEAK_FUNC(sub_821C9B18);
PPC_FUNC_IMPL(__imp__sub_821C9B18) {
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
	// lwz r10,252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 252);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,-1224
	ctx.r9.s64 = ctx.r11.s64 + -1224;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r9,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C9B4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 248);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821c9b64
	if (ctx.cr6.eq) goto loc_821C9B64;
	// bl 0x82088d98
	ctx.lr = 0x821C9B5C;
	sub_82088D98(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,248(r31)
	PPC_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
loc_821C9B64:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821c5738
	ctx.lr = 0x821C9B6C;
	sub_821C5738(ctx, base);
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

__attribute__((alias("__imp__sub_821C9B80"))) PPC_WEAK_FUNC(sub_821C9B80);
PPC_FUNC_IMPL(__imp__sub_821C9B80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821C9B88;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x821c57b8
	ctx.lr = 0x821C9B94;
	sub_821C57B8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r10,r11,-1224
	ctx.r10.s64 = ctx.r11.s64 + -1224;
	// li r28,15
	ctx.r28.s64 = 15;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r31.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stw r31,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r31.u32);
	// addi r30,r9,-3820
	ctx.r30.s64 = ctx.r9.s64 + -3820;
	// stb r31,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r31.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,-24
	ctx.r4.s64 = ctx.r30.s64 + -24;
	// bl 0x82060368
	ctx.lr = 0x821C9BD0;
	sub_82060368(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82061510
	ctx.lr = 0x821C9BE0;
	sub_82061510(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r30,-8
	ctx.r5.s64 = ctx.r30.s64 + -8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x820615b8
	ctx.lr = 0x821C9BF0;
	sub_820615B8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821C9C04;
	sub_820601F8(ctx, base);
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x821c9c18
	if (ctx.cr6.lt) goto loc_821C9C18;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8207a630
	ctx.lr = 0x821C9C18;
	sub_8207A630(ctx, base);
loc_821C9C18:
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r28.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stb r31,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r31.u8);
	// blt cr6,0x821c9c38
	if (ctx.cr6.lt) goto loc_821C9C38;
	// lwz r3,148(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x8207a630
	ctx.lr = 0x821C9C38;
	sub_8207A630(ctx, base);
loc_821C9C38:
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r28.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// stw r31,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// stb r31,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r31.u8);
	// bge cr6,0x821c9c58
	if (!ctx.cr6.lt) goto loc_821C9C58;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C9C58:
	// bl 0x82088e10
	ctx.lr = 0x821C9C5C;
	sub_82088E10(ctx, base);
	// stw r3,248(r29)
	PPC_STORE_U32(ctx.r29.u32 + 248, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c9ca0
	if (!ctx.cr6.eq) goto loc_821C9CA0;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c9c7c
	if (!ctx.cr6.lt) goto loc_821C9C7C;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C9C7C:
	// bl 0x8210e878
	ctx.lr = 0x821C9C80;
	sub_8210E878(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821c9cd4
	if (ctx.cr6.lt) goto loc_821C9CD4;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821C9C94;
	sub_8207A630(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821C9CA0:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82088dd0
	ctx.lr = 0x821C9CA8;
	sub_82088DD0(ctx, base);
	// stw r3,252(r29)
	PPC_STORE_U32(ctx.r29.u32 + 252, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821c9ccc
	if (!ctx.cr6.eq) goto loc_821C9CCC;
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821c9cc8
	if (!ctx.cr6.lt) goto loc_821C9CC8;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_821C9CC8:
	// bl 0x8210e878
	ctx.lr = 0x821C9CCC;
	sub_8210E878(ctx, base);
loc_821C9CCC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82065fe8
	ctx.lr = 0x821C9CD4;
	sub_82065FE8(ctx, base);
loc_821C9CD4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C9CE0"))) PPC_WEAK_FUNC(sub_821C9CE0);
PPC_FUNC_IMPL(__imp__sub_821C9CE0) {
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
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821c64e8
	ctx.lr = 0x821C9CFC;
	sub_821C64E8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,252(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C9D1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// li r3,7
	ctx.r3.s64 = 7;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C9D30;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r5,304
	ctx.r5.s64 = 304;
	// lwz r11,-31312(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31312);
	// stw r8,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r8.u32);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// addi r4,r11,152
	ctx.r4.s64 = ctx.r11.s64 + 152;
	// bl 0x8207dac0
	ctx.lr = 0x821C9D7C;
	sub_8207DAC0(ctx, base);
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// lwz r11,-31364(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c9da0
	if (ctx.cr6.eq) goto loc_821C9DA0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c9da4
	if (!ctx.cr6.eq) goto loc_821C9DA4;
loc_821C9DA0:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C9DA4:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r8,r9,-32240
	ctx.r8.s64 = ctx.r9.s64 + -32240;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// beq cr6,0x821c9dcc
	if (ctx.cr6.eq) goto loc_821C9DCC;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// bne cr6,0x821c9dd0
	if (!ctx.cr6.eq) goto loc_821C9DD0;
loc_821C9DCC:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_821C9DD0:
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r8,r9,-23112
	ctx.r8.s64 = ctx.r9.s64 + -23112;
	// lwz r7,252(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821C9DF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,252(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 164);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821C9E0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r4,r31,180
	ctx.r4.s64 = ctx.r31.s64 + 180;
	// li r3,8
	ctx.r3.s64 = 8;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C9E20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r4,-32228
	ctx.r4.s64 = -2112094208;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r31.u32);
	// lis r3,-32228
	ctx.r3.s64 = -2112094208;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r31.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r31.u32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r31.u32);
	// addi r9,r4,21224
	ctx.r9.s64 = ctx.r4.s64 + 21224;
	// lwz r5,252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// addi r8,r3,25096
	ctx.r8.s64 = ctx.r3.s64 + 25096;
	// addi r7,r11,22040
	ctx.r7.s64 = ctx.r11.s64 + 22040;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// addi r6,r10,21040
	ctx.r6.s64 = ctx.r10.s64 + 21040;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// li r3,9
	ctx.r3.s64 = 9;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821C9E74;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,52(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x821C9E88;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
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

__attribute__((alias("__imp__sub_821C9EA0"))) PPC_WEAK_FUNC(sub_821C9EA0);
PPC_FUNC_IMPL(__imp__sub_821C9EA0) {
	PPC_FUNC_PROLOGUE();
	// b 0x821c69f0
	sub_821C69F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821C9EA4"))) PPC_WEAK_FUNC(sub_821C9EA4);
PPC_FUNC_IMPL(__imp__sub_821C9EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9EA8"))) PPC_WEAK_FUNC(sub_821C9EA8);
PPC_FUNC_IMPL(__imp__sub_821C9EA8) {
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
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821c9ee8
	if (ctx.cr6.eq) goto loc_821C9EE8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821c9ee8
	if (!ctx.cr6.eq) goto loc_821C9EE8;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-31368(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31368, ctx.r10.u32);
	// bl 0x82184cc8
	ctx.lr = 0x821C9EE8;
	sub_82184CC8(ctx, base);
loc_821C9EE8:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,252(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 252);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,-31304(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31304);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x821C9F08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x821c54f8
	ctx.lr = 0x821C9F0C;
	sub_821C54F8(ctx, base);
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

__attribute__((alias("__imp__sub_821C9F20"))) PPC_WEAK_FUNC(sub_821C9F20);
PPC_FUNC_IMPL(__imp__sub_821C9F20) {
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
	// lwz r31,-31364(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C9F50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r8,r3,16
	ctx.r8.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,65535
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 65535, ctx.xer);
	// beq cr6,0x821c9f78
	if (ctx.cr6.eq) goto loc_821C9F78;
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
	ctx.lr = 0x821C9F78;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821C9F78:
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

__attribute__((alias("__imp__sub_821C9F8C"))) PPC_WEAK_FUNC(sub_821C9F8C);
PPC_FUNC_IMPL(__imp__sub_821C9F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821C9F90"))) PPC_WEAK_FUNC(sub_821C9F90);
PPC_FUNC_IMPL(__imp__sub_821C9F90) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r31,-31364(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821C9FC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r8,r3,16
	ctx.r8.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,65535
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 65535, ctx.xer);
	// beq cr6,0x821c9ff0
	if (ctx.cr6.eq) goto loc_821C9FF0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821C9FF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821C9FF0:
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

__attribute__((alias("__imp__sub_821CA008"))) PPC_WEAK_FUNC(sub_821CA008);
PPC_FUNC_IMPL(__imp__sub_821CA008) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA010;
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
	ctx.lr = 0x821CA03C;
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
	ctx.lr = 0x821CA058;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA060"))) PPC_WEAK_FUNC(sub_821CA060);
PPC_FUNC_IMPL(__imp__sub_821CA060) {
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

__attribute__((alias("__imp__sub_821CA078"))) PPC_WEAK_FUNC(sub_821CA078);
PPC_FUNC_IMPL(__imp__sub_821CA078) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA080;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mulli r11,r4,28
	ctx.r11.s64 = ctx.r4.s64 * 28;
	// addi r29,r10,-32240
	ctx.r29.s64 = ctx.r10.s64 + -32240;
	// add r30,r11,r3
	ctx.r30.u64 = ctx.r11.u64 + ctx.r3.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r11,r30,268
	ctx.r11.s64 = ctx.r30.s64 + 268;
	// bl 0x821d5384
	ctx.lr = 0x821CA0AC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// stfs f31,280(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r30.u32 + 280, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r30,268(r30)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r30.u32 + 268);
	// bl 0x821d5394
	ctx.lr = 0x821CA0BC;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821ca0fc
	if (ctx.cr6.eq) goto loc_821CA0FC;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// stfs f31,508(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 508, temp.u32);
	// stfs f31,496(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 496, temp.u32);
	// addi r6,r31,496
	ctx.r6.s64 = ctx.r31.s64 + 496;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r5,492(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 492);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,504(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 504, temp.u32);
	// stfs f0,500(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 500, temp.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821CA0FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CA0FC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA108"))) PPC_WEAK_FUNC(sub_821CA108);
PPC_FUNC_IMPL(__imp__sub_821CA108) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821CA110;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mulli r10,r3,28
	ctx.r10.s64 = ctx.r3.s64 * 28;
	// lwz r28,-31364(r9)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31364);
	// addi r29,r11,-32240
	ctx.r29.s64 = ctx.r11.s64 + -32240;
	// add r31,r10,r28
	ctx.r31.u64 = ctx.r10.u64 + ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r30,r31,268
	ctx.r30.s64 = ctx.r31.s64 + 268;
	// bl 0x821d5384
	ctx.lr = 0x821CA138;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,7
	ctx.r11.s64 = 7;
	// addi r10,r30,-4
	ctx.r10.s64 = ctx.r30.s64 + -4;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r31,268(r31)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r31.u32 + 268);
loc_821CA14C:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x821ca14c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821CA14C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5394
	ctx.lr = 0x821CA15C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821ca1ac
	if (ctx.cr6.eq) goto loc_821CA1AC;
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x8207da20
	ctx.lr = 0x821CA174;
	sub_8207DA20(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r31,90(r1)
	PPC_STORE_U32(ctx.r1.u32 + 90, ctx.r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821CA198;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821CA1AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CA1AC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA1B4"))) PPC_WEAK_FUNC(sub_821CA1B4);
PPC_FUNC_IMPL(__imp__sub_821CA1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA1B8"))) PPC_WEAK_FUNC(sub_821CA1B8);
PPC_FUNC_IMPL(__imp__sub_821CA1B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821CA1C0;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// blt cr6,0x821ca2d4
	if (ctx.cr6.lt) goto loc_821CA2D4;
	// cmpwi cr6,r5,8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 8, ctx.xer);
	// bge cr6,0x821ca2d4
	if (!ctx.cr6.lt) goto loc_821CA2D4;
	// rlwinm r11,r5,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821ca2d4
	if (ctx.cr6.eq) goto loc_821CA2D4;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA220;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821ca2d4
	if (!ctx.cr6.eq) goto loc_821CA2D4;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mulli r11,r28,28
	ctx.r11.s64 = ctx.r28.s64 * 28;
	// addi r27,r10,-32240
	ctx.r27.s64 = ctx.r10.s64 + -32240;
	// add r31,r11,r30
	ctx.r31.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// addi r29,r31,268
	ctx.r29.s64 = ctx.r31.s64 + 268;
	// bl 0x821d5384
	ctx.lr = 0x821CA244;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f31,280(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 280, temp.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,276(r31)
	PPC_STORE_U32(ctx.r31.u32 + 276, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stw r10,272(r31)
	PPC_STORE_U32(ctx.r31.u32 + 272, ctx.r10.u32);
	// stw r11,288(r31)
	PPC_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// stw r11,292(r31)
	PPC_STORE_U32(ctx.r31.u32 + 292, ctx.r11.u32);
	// stw r9,268(r31)
	PPC_STORE_U32(ctx.r31.u32 + 268, ctx.r9.u32);
	// bl 0x821d5394
	ctx.lr = 0x821CA270;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,97
	ctx.r3.s64 = ctx.r1.s64 + 97;
	// bl 0x8207da20
	ctx.lr = 0x821CA280;
	sub_8207DA20(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r29,118(r1)
	PPC_STORE_U32(ctx.r1.u32 + 118, ctx.r29.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
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
	ctx.lr = 0x821CA2B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x821ca078
	ctx.lr = 0x821CA2C4;
	sub_821CA078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
loc_821CA2D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA2E4"))) PPC_WEAK_FUNC(sub_821CA2E4);
PPC_FUNC_IMPL(__imp__sub_821CA2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA2E8"))) PPC_WEAK_FUNC(sub_821CA2E8);
PPC_FUNC_IMPL(__imp__sub_821CA2E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA2F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// lwz r30,-31364(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// beq cr6,0x821ca38c
	if (ctx.cr6.eq) goto loc_821CA38C;
	// lwz r5,20(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x821ca38c
	if (ctx.cr6.eq) goto loc_821CA38C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r8,r31,4
	ctx.r8.s64 = ctx.r31.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA33C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821ca38c
	if (ctx.cr6.lt) goto loc_821CA38C;
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x821ca398
	if (ctx.cr6.eq) goto loc_821CA398;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,64
	ctx.r9.s64 = 64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// std r29,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r29.u64);
	// std r29,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r29.u64);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// sth r9,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, ctx.r9.u16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,40(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821CA384;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x821ca3cc
	if (!ctx.cr6.lt) goto loc_821CA3CC;
loc_821CA38C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_821CA398:
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA3BC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x821ca38c
	if (ctx.cr6.lt) goto loc_821CA38C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_821CA3CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA3D8"))) PPC_WEAK_FUNC(sub_821CA3D8);
PPC_FUNC_IMPL(__imp__sub_821CA3D8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA3E0;
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
	// beq cr6,0x821ca420
	if (ctx.cr6.eq) goto loc_821CA420;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA404;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821CA418;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r7,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r7.u32);
loc_821CA420:
	// addi r31,r29,20
	ctx.r31.s64 = ctx.r29.s64 + 20;
	// li r30,8
	ctx.r30.s64 = 8;
loc_821CA428:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x821ca438
	if (ctx.cr6.eq) goto loc_821CA438;
	// bl 0x82088d00
	ctx.lr = 0x821CA438;
	sub_82088D00(ctx, base);
loc_821CA438:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ca448
	if (ctx.cr6.eq) goto loc_821CA448;
	// bl 0x8207a8a0
	ctx.lr = 0x821CA448;
	sub_8207A8A0(ctx, base);
loc_821CA448:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ca458
	if (ctx.cr6.eq) goto loc_821CA458;
	// bl 0x8207a8a0
	ctx.lr = 0x821CA458;
	sub_8207A8A0(ctx, base);
loc_821CA458:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,32
	ctx.r31.s64 = ctx.r31.s64 + 32;
	// bne 0x821ca428
	if (!ctx.cr0.eq) goto loc_821CA428;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,12
	ctx.r3.s64 = ctx.r29.s64 + 12;
	// bl 0x8207da20
	ctx.lr = 0x821CA474;
	sub_8207DA20(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA47C"))) PPC_WEAK_FUNC(sub_821CA47C);
PPC_FUNC_IMPL(__imp__sub_821CA47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA480"))) PPC_WEAK_FUNC(sub_821CA480);
PPC_FUNC_IMPL(__imp__sub_821CA480) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ca4a0
	if (ctx.cr6.eq) goto loc_821CA4A0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r11,12
	ctx.r3.s64 = ctx.r11.s64 + 12;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_821CA4A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CA4A8"))) PPC_WEAK_FUNC(sub_821CA4A8);
PPC_FUNC_IMPL(__imp__sub_821CA4A8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ca4c4
	if (ctx.cr6.eq) goto loc_821CA4C4;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_821CA4C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CA4CC"))) PPC_WEAK_FUNC(sub_821CA4CC);
PPC_FUNC_IMPL(__imp__sub_821CA4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA4D0"))) PPC_WEAK_FUNC(sub_821CA4D0);
PPC_FUNC_IMPL(__imp__sub_821CA4D0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA4D8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x821ca538
	if (ctx.cr6.eq) goto loc_821CA538;
	// cmplwi cr6,r11,17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 17, ctx.xer);
	// bne cr6,0x821ca56c
	if (!ctx.cr6.eq) goto loc_821CA56C;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r11,8
	ctx.r11.s64 = 8;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,-31364(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31364);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,40
	ctx.r11.s64 = ctx.r10.s64 + 40;
loc_821CA50C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821ca528
	if (ctx.cr6.eq) goto loc_821CA528;
	// lwz r8,-28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + -28);
	// lwz r7,9(r29)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r29.u32 + 9);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x821ca528
	if (!ctx.cr6.eq) goto loc_821CA528;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_821CA528:
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// bdnz 0x821ca50c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821CA50C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
loc_821CA538:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r31,5(r29)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r29.u32 + 5);
	// addi r30,r11,-32240
	ctx.r30.s64 = ctx.r11.s64 + -32240;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5384
	ctx.lr = 0x821CA54C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,15(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 15);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x821ca564
	if (!ctx.cr6.eq) goto loc_821CA564;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_821CA564:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x821d5394
	ctx.lr = 0x821CA56C;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_821CA56C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA574"))) PPC_WEAK_FUNC(sub_821CA574);
PPC_FUNC_IMPL(__imp__sub_821CA574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA578"))) PPC_WEAK_FUNC(sub_821CA578);
PPC_FUNC_IMPL(__imp__sub_821CA578) {
	PPC_FUNC_PROLOGUE();
	// li r4,-1
	ctx.r4.s64 = -1;
	// b 0x82088438
	sub_82088438(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA580"))) PPC_WEAK_FUNC(sub_821CA580);
PPC_FUNC_IMPL(__imp__sub_821CA580) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA588;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,-32240
	ctx.r29.s64 = ctx.r11.s64 + -32240;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x821CA5A4;
	__imp__RtlEnterCriticalSection(ctx, base);
	// stw r30,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5394
	ctx.lr = 0x821CA5B0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA5B8"))) PPC_WEAK_FUNC(sub_821CA5B8);
PPC_FUNC_IMPL(__imp__sub_821CA5B8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA5C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r11,-32240
	ctx.r29.s64 = ctx.r11.s64 + -32240;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x821CA5DC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// stw r30,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r30.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5394
	ctx.lr = 0x821CA5E8;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA5F0"))) PPC_WEAK_FUNC(sub_821CA5F0);
PPC_FUNC_IMPL(__imp__sub_821CA5F0) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x821CA618;
	sub_8207DA20(ctx, base);
	// addi r3,r31,268
	ctx.r3.s64 = ctx.r31.s64 + 268;
	// li r5,224
	ctx.r5.s64 = 224;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8207da20
	ctx.lr = 0x821CA628;
	sub_8207DA20(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820e5fa8
	ctx.lr = 0x821CA634;
	sub_820E5FA8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821ca74c
	if (!ctx.cr6.eq) goto loc_821CA74C;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821CA64C:
	// stwu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x821ca64c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821CA64C;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// li r9,250
	ctx.r9.s64 = 250;
	// addi r8,r11,-23344
	ctx.r8.s64 = ctx.r11.s64 + -23344;
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r8,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r8.u32);
	// beq cr6,0x821ca690
	if (ctx.cr6.eq) goto loc_821CA690;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ca690
	if (ctx.cr6.eq) goto loc_821CA690;
	// stw r10,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// stw r30,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r30.u32);
loc_821CA690:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA6A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821ca74c
	if (!ctx.cr6.eq) goto loc_821CA74C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA6C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x821ca74c
	if (!ctx.cr6.eq) goto loc_821CA74C;
	// lhz r11,114(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,492(r31)
	PPC_STORE_U32(ctx.r31.u32 + 492, ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821ca710
	if (ctx.cr6.eq) goto loc_821CA710;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r10,r31,492
	ctx.r10.s64 = ctx.r31.s64 + 492;
	// lfs f0,21768(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
loc_821CA6F8:
	// stfsu f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	ea = 4 + ctx.r10.u32;
	PPC_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// lwz r9,492(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 492);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821ca6f8
	if (ctx.cr6.lt) goto loc_821CA6F8;
loc_821CA710:
	// li r5,25
	ctx.r5.s64 = 25;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x8207da20
	ctx.lr = 0x821CA720;
	sub_8207DA20(ctx, base);
	// li r11,17
	ctx.r11.s64 = 17;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r30,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r10,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, ctx.r10.u16);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821CA74C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CA74C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

__attribute__((alias("__imp__sub_821CA764"))) PPC_WEAK_FUNC(sub_821CA764);
PPC_FUNC_IMPL(__imp__sub_821CA764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA768"))) PPC_WEAK_FUNC(sub_821CA768);
PPC_FUNC_IMPL(__imp__sub_821CA768) {
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
	// lwz r31,-31364(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// lwz r10,560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821ca7c8
	if (ctx.cr6.eq) goto loc_821CA7C8;
	// lwz r3,568(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 568);
	// bl 0x82088440
	ctx.lr = 0x821CA794;
	sub_82088440(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// bl 0x82088438
	ctx.lr = 0x821CA7A0;
	sub_82088438(ctx, base);
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// bl 0x82088d00
	ctx.lr = 0x821CA7A8;
	sub_82088D00(ctx, base);
	// lwz r3,564(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 564);
	// bl 0x82088d00
	ctx.lr = 0x821CA7B0;
	sub_82088D00(ctx, base);
	// lwz r3,568(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 568);
	// bl 0x82088d00
	ctx.lr = 0x821CA7B8;
	sub_82088D00(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// stw r11,564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 564, ctx.r11.u32);
	// stw r11,568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 568, ctx.r11.u32);
loc_821CA7C8:
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

__attribute__((alias("__imp__sub_821CA7DC"))) PPC_WEAK_FUNC(sub_821CA7DC);
PPC_FUNC_IMPL(__imp__sub_821CA7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA7E0"))) PPC_WEAK_FUNC(sub_821CA7E0);
PPC_FUNC_IMPL(__imp__sub_821CA7E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821CA7E8;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwz r27,-31364(r11)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// blt cr6,0x821ca92c
	if (ctx.cr6.lt) goto loc_821CA92C;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// bge cr6,0x821ca92c
	if (!ctx.cr6.lt) goto loc_821CA92C;
	// rlwinm r11,r4,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// addi r29,r11,12
	ctx.r29.s64 = ctx.r11.s64 + 12;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x821ca848
	if (!ctx.cr6.eq) goto loc_821CA848;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82065fe8
	ctx.lr = 0x821CA838;
	sub_82065FE8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_821CA848:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA860;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821ca8e0
	if (ctx.cr6.eq) goto loc_821CA8E0;
loc_821CA874:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CA890;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82060d90
	ctx.lr = 0x821CA898;
	sub_82060D90(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
loc_821CA89C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// beq cr6,0x821ca8c0
	if (ctx.cr6.eq) goto loc_821CA8C0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821ca89c
	if (ctx.cr6.eq) goto loc_821CA89C;
loc_821CA8C0:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821ca8f8
	if (ctx.cr6.eq) goto loc_821CA8F8;
	// clrlwi r11,r31,16
	ctx.r11.u64 = ctx.r31.u32 & 0xFFFF;
	// lhz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// clrlwi r31,r9,16
	ctx.r31.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x821ca874
	if (ctx.cr6.lt) goto loc_821CA874;
loc_821CA8E0:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821ca944
	if (ctx.cr6.lt) goto loc_821CA944;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821CA8F4;
	sub_8207A630(ctx, base);
	// b 0x821ca944
	goto loc_821CA944;
loc_821CA8F8:
	// clrlwi r6,r31,16
	ctx.r6.u64 = ctx.r31.u32 & 0xFFFF;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x821ca1b8
	ctx.lr = 0x821CA910;
	sub_821CA1B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82065fe8
	ctx.lr = 0x821CA91C;
	sub_82065FE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
loc_821CA92C:
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821ca940
	if (ctx.cr6.lt) goto loc_821CA940;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821CA940;
	sub_8207A630(ctx, base);
loc_821CA940:
	// li r26,0
	ctx.r26.s64 = 0;
loc_821CA944:
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r26,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r26.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// stb r26,4(r30)
	PPC_STORE_U8(ctx.r30.u32 + 4, ctx.r26.u8);
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x8207c9cc
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA964"))) PPC_WEAK_FUNC(sub_821CA964);
PPC_FUNC_IMPL(__imp__sub_821CA964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CA968"))) PPC_WEAK_FUNC(sub_821CA968);
PPC_FUNC_IMPL(__imp__sub_821CA968) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA970;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ca98c
	if (ctx.cr6.eq) goto loc_821CA98C;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_821CA98C:
	// lwz r3,616(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 616);
	// addi r31,r29,604
	ctx.r31.s64 = ctx.r29.s64 + 604;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ca9a0
	if (ctx.cr6.eq) goto loc_821CA9A0;
	// bl 0x8207a630
	ctx.lr = 0x821CA9A0;
	sub_8207A630(ctx, base);
loc_821CA9A0:
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821CA9B4;
	sub_8207A630(ctx, base);
	// lwz r3,592(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 592);
	// addi r31,r29,580
	ctx.r31.s64 = ctx.r29.s64 + 580;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ca9d4
	if (ctx.cr6.eq) goto loc_821CA9D4;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82061380
	ctx.lr = 0x821CA9CC;
	sub_82061380(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x8207a630
	ctx.lr = 0x821CA9D4;
	sub_8207A630(ctx, base);
loc_821CA9D4:
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821CA9E8;
	sub_8207A630(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CA9F0"))) PPC_WEAK_FUNC(sub_821CA9F0);
PPC_FUNC_IMPL(__imp__sub_821CA9F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CA9F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lwz r31,-31364(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31364);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821caa54
	if (ctx.cr6.eq) goto loc_821CAA54;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r29,r11,-32240
	ctx.r29.s64 = ctx.r11.s64 + -32240;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x821CAA1C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r10,572(r31)
	PPC_STORE_U32(ctx.r31.u32 + 572, ctx.r10.u32);
	// bl 0x821d5394
	ctx.lr = 0x821CAA2C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// bl 0x821ca768
	ctx.lr = 0x821CAA30;
	sub_821CA768(ctx, base);
	// lwz r31,-31364(r30)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31364);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821caa4c
	if (ctx.cr6.eq) goto loc_821CAA4C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821ca968
	ctx.lr = 0x821CAA44;
	sub_821CA968(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8207a630
	ctx.lr = 0x821CAA4C;
	sub_8207A630(ctx, base);
loc_821CAA4C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31364(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31364, ctx.r11.u32);
loc_821CAA54:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CAA5C"))) PPC_WEAK_FUNC(sub_821CAA5C);
PPC_FUNC_IMPL(__imp__sub_821CAA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CAA60"))) PPC_WEAK_FUNC(sub_821CAA60);
PPC_FUNC_IMPL(__imp__sub_821CAA60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821CAA68;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r24,-31364(r11)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// beq cr6,0x821cabf8
	if (ctx.cr6.eq) goto loc_821CABF8;
	// lwz r11,596(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 596);
	// li r26,28
	ctx.r26.s64 = 28;
	// lwz r10,592(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 592);
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r31,r24,580
	ctx.r31.s64 = ctx.r24.s64 + 580;
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// divw. r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x821cabb8
	if (!ctx.cr0.gt) goto loc_821CABB8;
	// li r28,15
	ctx.r28.s64 = 15;
	// li r27,-1
	ctx.r27.s64 = -1;
loc_821CAAB4:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82061000
	ctx.lr = 0x821CAAC0;
	sub_82061000(ctx, base);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821CAAE0;
	sub_820601F8(ctx, base);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// bge cr6,0x821caaf8
	if (!ctx.cr6.lt) goto loc_821CAAF8;
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
loc_821CAAF8:
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
loc_821CAAFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x821cab20
	if (ctx.cr6.eq) goto loc_821CAB20;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821caafc
	if (ctx.cr6.eq) goto loc_821CAAFC;
loc_821CAB20:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x821cab60
	if (ctx.cr6.eq) goto loc_821CAB60;
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// blt cr6,0x821cab34
	if (ctx.cr6.lt) goto loc_821CAB34;
	// bl 0x8207a630
	ctx.lr = 0x821CAB34;
	sub_8207A630(ctx, base);
loc_821CAB34:
	// lwz r11,16(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
	// divw r8,r9,r26
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r26.s32);
	// cmpw cr6,r30,r8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x821caab4
	if (ctx.cr6.lt) goto loc_821CAAB4;
	// b 0x821cabb8
	goto loc_821CABB8;
loc_821CAB60:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r24,604
	ctx.r3.s64 = ctx.r24.s64 + 604;
	// bl 0x82066420
	ctx.lr = 0x821CAB6C;
	sub_82066420(ctx, base);
	// stfs f31,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lwz r11,628(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 628);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,104(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// beq cr6,0x821cab9c
	if (ctx.cr6.eq) goto loc_821CAB9C;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cabf8
	if (ctx.cr6.lt) goto loc_821CABF8;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821CAB90;
	sub_8207A630(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
loc_821CAB9C:
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cabac
	if (ctx.cr6.lt) goto loc_821CABAC;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8207a630
	ctx.lr = 0x821CABAC;
	sub_8207A630(ctx, base);
loc_821CABAC:
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r28.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// stb r29,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r29.u8);
loc_821CABB8:
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CABD0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x821cabf8
	if (ctx.cr6.eq) goto loc_821CABF8;
	// lwz r3,0(r24)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CABF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CABF8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CAC04"))) PPC_WEAK_FUNC(sub_821CAC04);
PPC_FUNC_IMPL(__imp__sub_821CAC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CAC08"))) PPC_WEAK_FUNC(sub_821CAC08);
PPC_FUNC_IMPL(__imp__sub_821CAC08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c97c
	ctx.lr = 0x821CAC10;
	__savegprlr_25(ctx, base);
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32224
	ctx.r27.s64 = -2111832064;
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821caf80
	if (ctx.cr6.eq) goto loc_821CAF80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821caf80
	if (ctx.cr6.eq) goto loc_821CAF80;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,-2064
	ctx.r8.s64 = ctx.r10.s64 + -2064;
	// li r28,0
	ctx.r28.s64 = 0;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r25,r28
	ctx.r25.u64 = ctx.r28.u64;
	// lfs f30,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f30.f64 = double(temp.f32);
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// lfs f29,56(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	ctx.f29.f64 = double(temp.f32);
	// addi r26,r10,-32240
	ctx.r26.s64 = ctx.r10.s64 + -32240;
loc_821CAC64:
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f30.f64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r31,r11,268
	ctx.r31.s64 = ctx.r11.s64 + 268;
	// bl 0x821d5384
	ctx.lr = 0x821CAC78;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r30,0(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// beq cr6,0x821cacd8
	if (ctx.cr6.eq) goto loc_821CACD8;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// bne 0x821caca4
	if (!ctx.cr0.eq) goto loc_821CACA4;
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// stw r28,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r28.u32);
	// b 0x821cacd8
	goto loc_821CACD8;
loc_821CACA4:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// fmuls f8,f0,f10
	ctx.f8.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f31,f8,f7
	ctx.f31.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
loc_821CACD8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x821d5394
	ctx.lr = 0x821CACE0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821cad14
	if (ctx.cr6.eq) goto loc_821CAD14;
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x821cad14
	if (ctx.cr6.eq) goto loc_821CAD14;
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// bge cr6,0x821cad04
	if (!ctx.cr6.lt) goto loc_821CAD04;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x821ca108
	ctx.lr = 0x821CAD00;
	sub_821CA108(ctx, base);
	// b 0x821cad14
	goto loc_821CAD14;
loc_821CAD04:
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r3,-31364(r27)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x821ca078
	ctx.lr = 0x821CAD14;
	sub_821CA078(ctx, base);
loc_821CAD14:
	// addi r29,r29,28
	ctx.r29.s64 = ctx.r29.s64 + 28;
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// cmpwi cr6,r29,224
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 224, ctx.xer);
	// blt cr6,0x821cac64
	if (ctx.cr6.lt) goto loc_821CAC64;
	// lwz r10,596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 596);
	// li r26,28
	ctx.r26.s64 = 28;
	// lwz r9,592(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 592);
	// addi r3,r11,580
	ctx.r3.s64 = ctx.r11.s64 + 580;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// divw. r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x821caf6c
	if (ctx.cr0.eq) goto loc_821CAF6C;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r10,-31352(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// lwz r10,44(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x821cae64
	if (!ctx.cr6.eq) goto loc_821CAE64;
	// lwz r9,628(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 628);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x821cae5c
	if (!ctx.cr6.eq) goto loc_821CAE5C;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// divw. r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble 0x821cae50
	if (!ctx.cr0.gt) goto loc_821CAE50;
	// li r29,15
	ctx.r29.s64 = 15;
	// li r25,-1
	ctx.r25.s64 = -1;
loc_821CAD8C:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82061000
	ctx.lr = 0x821CAD94;
	sub_82061000(ctx, base);
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r28,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x820601f8
	ctx.lr = 0x821CADB4;
	sub_820601F8(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821cadc8
	if (!ctx.cr6.lt) goto loc_821CADC8;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
loc_821CADC8:
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CADE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x821cae0c
	if (ctx.cr6.eq) goto loc_821CAE0C;
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CAE0C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CAE0C:
	// lwz r11,120(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cae20
	if (ctx.cr6.lt) goto loc_821CAE20;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x8207a630
	ctx.lr = 0x821CAE20;
	sub_8207A630(ctx, base);
loc_821CAE20:
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stw r28,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r28.u32);
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// addi r3,r11,580
	ctx.r3.s64 = ctx.r11.s64 + 580;
	// stb r28,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
	// lwz r10,596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 596);
	// lwz r9,592(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 592);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// divw r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// cmpw cr6,r31,r7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x821cad8c
	if (ctx.cr6.lt) goto loc_821CAD8C;
loc_821CAE50:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,628(r11)
	PPC_STORE_U32(ctx.r11.u32 + 628, ctx.r10.u32);
	// b 0x821caf6c
	goto loc_821CAF6C;
loc_821CAE5C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821caf6c
	if (ctx.cr6.eq) goto loc_821CAF6C;
loc_821CAE64:
	// lwz r10,628(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 628);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821caf6c
	if (ctx.cr6.eq) goto loc_821CAF6C;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// divw. r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble 0x821caf68
	if (!ctx.cr0.gt) goto loc_821CAF68;
	// li r29,15
	ctx.r29.s64 = 15;
	// li r25,-1
	ctx.r25.s64 = -1;
loc_821CAE90:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82061000
	ctx.lr = 0x821CAE98;
	sub_82061000(ctx, base);
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// stw r28,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r28.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stb r28,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r28.u8);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x820601f8
	ctx.lr = 0x821CAEB8;
	sub_820601F8(ctx, base);
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x821caecc
	if (!ctx.cr6.lt) goto loc_821CAECC;
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
loc_821CAECC:
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CAEE4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,65535
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 65535, ctx.xer);
	// beq cr6,0x821caf24
	if (ctx.cr6.eq) goto loc_821CAF24;
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,604
	ctx.r3.s64 = ctx.r11.s64 + 604;
	// bl 0x82066420
	ctx.lr = 0x821CAF04;
	sub_82066420(ctx, base);
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// lfs f1,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CAF24;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CAF24:
	// lwz r11,152(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821caf38
	if (ctx.cr6.lt) goto loc_821CAF38;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x8207a630
	ctx.lr = 0x821CAF38;
	sub_8207A630(ctx, base);
loc_821CAF38:
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r29.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// stb r28,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, ctx.r28.u8);
	// stw r28,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r28.u32);
	// lwz r11,-31364(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -31364);
	// addi r3,r11,580
	ctx.r3.s64 = ctx.r11.s64 + 580;
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 592);
	// lwz r9,596(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 596);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw r7,r8,r26
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r26.s32);
	// cmpw cr6,r31,r7
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x821cae90
	if (ctx.cr6.lt) goto loc_821CAE90;
loc_821CAF68:
	// stw r28,628(r11)
	PPC_STORE_U32(ctx.r11.u32 + 628, ctx.r28.u32);
loc_821CAF6C:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CAF80;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CAF80:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_821CAF94"))) PPC_WEAK_FUNC(sub_821CAF94);
PPC_FUNC_IMPL(__imp__sub_821CAF94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CAF98"))) PPC_WEAK_FUNC(sub_821CAF98);
PPC_FUNC_IMPL(__imp__sub_821CAF98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821CAFA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r30,r3,580
	ctx.r30.s64 = ctx.r3.s64 + 580;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82079fd8
	ctx.lr = 0x821CAFB4;
	sub_82079FD8(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cafc8
	if (ctx.cr6.eq) goto loc_821CAFC8;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// b 0x821cafcc
	goto loc_821CAFCC;
loc_821CAFC8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821CAFCC:
	// stw r3,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r3.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r31,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// addi r28,r29,604
	ctx.r28.s64 = ctx.r29.s64 + 604;
	// stw r31,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r31.u32);
	// stw r31,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CAFE8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821caff8
	if (ctx.cr6.eq) goto loc_821CAFF8;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r28.u32);
	// b 0x821caffc
	goto loc_821CAFFC;
loc_821CAFF8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821CAFFC:
	// addi r11,r29,12
	ctx.r11.s64 = ctx.r29.s64 + 12;
	// stw r3,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r3.u32);
	// li r5,256
	ctx.r5.s64 = 256;
	// stw r31,12(r28)
	PPC_STORE_U32(ctx.r28.u32 + 12, ctx.r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r31.u32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// stw r31,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r31.u32);
	// stw r31,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r31.u32);
	// stw r31,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r31.u32);
	// stw r31,8(r29)
	PPC_STORE_U32(ctx.r29.u32 + 8, ctx.r31.u32);
	// bl 0x8207da20
	ctx.lr = 0x821CB02C;
	sub_8207DA20(ctx, base);
	// stw r31,572(r29)
	PPC_STORE_U32(ctx.r29.u32 + 572, ctx.r31.u32);
	// stw r31,560(r29)
	PPC_STORE_U32(ctx.r29.u32 + 560, ctx.r31.u32);
	// stw r31,564(r29)
	PPC_STORE_U32(ctx.r29.u32 + 564, ctx.r31.u32);
	// stw r31,568(r29)
	PPC_STORE_U32(ctx.r29.u32 + 568, ctx.r31.u32);
	// stw r31,576(r29)
	PPC_STORE_U32(ctx.r29.u32 + 576, ctx.r31.u32);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x821cb054
	if (!ctx.cr6.gt) goto loc_821CB054;
	// twi 31,r0,22
loc_821CB054:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// ble cr6,0x821cb06c
	if (!ctx.cr6.gt) goto loc_821CB06C;
	// twi 31,r0,22
loc_821CB06C:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82061140
	ctx.lr = 0x821CB088;
	sub_82061140(ctx, base);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 12);
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 16);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x821cb0a4
	if (!ctx.cr6.gt) goto loc_821CB0A4;
	// twi 31,r0,22
	// twi 31,r0,22
	// twi 31,r0,22
loc_821CB0A4:
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// bgt cr6,0x821cb0b8
	if (ctx.cr6.gt) goto loc_821CB0B8;
	// cmplw cr6,r5,r5
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r5.u32, ctx.xer);
	// ble cr6,0x821cb0bc
	if (!ctx.cr6.gt) goto loc_821CB0BC;
loc_821CB0B8:
	// twi 31,r0,22
loc_821CB0BC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cb0cc
	if (ctx.cr6.eq) goto loc_821CB0CC;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x821cb0d0
	if (ctx.cr6.eq) goto loc_821CB0D0;
loc_821CB0CC:
	// twi 31,r0,22
loc_821CB0D0:
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x821cb0f8
	if (ctx.cr6.eq) goto loc_821CB0F8;
	// subf r11,r5,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r5.s64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r6,r3
	ctx.r30.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x821cb0f4
	if (!ctx.cr0.gt) goto loc_821CB0F4;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8207a520
	ctx.lr = 0x821CB0F4;
	sub_8207A520(ctx, base);
loc_821CB0F4:
	// stw r30,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r30.u32);
loc_821CB0F8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r31,628(r29)
	PPC_STORE_U32(ctx.r29.u32 + 628, ctx.r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB108"))) PPC_WEAK_FUNC(sub_821CB108);
PPC_FUNC_IMPL(__imp__sub_821CB108) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CB110;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x821ca5f0
	ctx.lr = 0x821CB11C;
	sub_821CA5F0(ctx, base);
	// lwz r3,564(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 564);
	// bl 0x82088440
	ctx.lr = 0x821CB124;
	sub_82088440(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r29,r11,-32240
	ctx.r29.s64 = ctx.r11.s64 + -32240;
loc_821CB12C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x821d5384
	ctx.lr = 0x821CB134;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r30,572(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 572);
	// bl 0x821d5394
	ctx.lr = 0x821CB140;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821cb150
	if (ctx.cr6.eq) goto loc_821CB150;
	// mtctr r30
	ctx.ctr.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x821CB150;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CB150:
	// lwz r11,576(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 576);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// stw r10,576(r31)
	PPC_STORE_U32(ctx.r31.u32 + 576, ctx.r10.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821cb16c
	if (!ctx.cr6.eq) goto loc_821CB16C;
	// bl 0x821cac08
	ctx.lr = 0x821CB16C;
	sub_821CAC08(ctx, base);
loc_821CB16C:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,568(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 568);
	// bl 0x82088438
	ctx.lr = 0x821CB178;
	sub_82088438(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821cb12c
	if (!ctx.cr6.eq) goto loc_821CB12C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821ca3d8
	ctx.lr = 0x821CB188;
	sub_821CA3D8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x820889c8
	ctx.lr = 0x821CB190;
	sub_820889C8(ctx, base);
}

__attribute__((alias("__imp__sub_821CB190"))) PPC_WEAK_FUNC(sub_821CB190);
PPC_FUNC_IMPL(__imp__sub_821CB190) {
	PPC_FUNC_PROLOGUE();
	// b 0x821cb108
	sub_821CB108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB194"))) PPC_WEAK_FUNC(sub_821CB194);
PPC_FUNC_IMPL(__imp__sub_821CB194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CB198"))) PPC_WEAK_FUNC(sub_821CB198);
PPC_FUNC_IMPL(__imp__sub_821CB198) {
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
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,-31364(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// bl 0x82088928
	ctx.lr = 0x821CB1C4;
	sub_82088928(ctx, base);
	// stw r3,564(r31)
	PPC_STORE_U32(ctx.r31.u32 + 564, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088928
	ctx.lr = 0x821CB1DC;
	sub_82088928(ctx, base);
	// stw r3,568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 568, ctx.r3.u32);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r10,-20080
	ctx.r5.s64 = ctx.r10.s64 + -20080;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82088d88
	ctx.lr = 0x821CB200;
	sub_82088D88(ctx, base);
	// stw r3,560(r31)
	PPC_STORE_U32(ctx.r31.u32 + 560, ctx.r3.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82088b08
	ctx.lr = 0x821CB20C;
	sub_82088B08(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// bl 0x820889f0
	ctx.lr = 0x821CB218;
	sub_820889F0(ctx, base);
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// bl 0x82088d48
	ctx.lr = 0x821CB220;
	sub_82088D48(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,564(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 564);
	// bl 0x82088438
	ctx.lr = 0x821CB22C;
	sub_82088438(ctx, base);
	// bl 0x8210e878
	ctx.lr = 0x821CB230;
	sub_8210E878(ctx, base);
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

__attribute__((alias("__imp__sub_821CB244"))) PPC_WEAK_FUNC(sub_821CB244);
PPC_FUNC_IMPL(__imp__sub_821CB244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CB248"))) PPC_WEAK_FUNC(sub_821CB248);
PPC_FUNC_IMPL(__imp__sub_821CB248) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CB250;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r11,-31364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821cb2d8
	if (!ctx.cr6.eq) goto loc_821CB2D8;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r3,r11,-32240
	ctx.r3.s64 = ctx.r11.s64 + -32240;
	// bl 0x821d53a4
	ctx.lr = 0x821CB278;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// li r3,632
	ctx.r3.s64 = 632;
	// bl 0x82079fd8
	ctx.lr = 0x821CB280;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb294
	if (ctx.cr6.eq) goto loc_821CB294;
	// bl 0x821caf98
	ctx.lr = 0x821CB28C;
	sub_821CAF98(ctx, base);
	// stw r3,-31364(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31364, ctx.r3.u32);
	// b 0x821cb29c
	goto loc_821CB29C;
loc_821CB294:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,-31364(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31364, ctx.r11.u32);
loc_821CB29C:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x821cb2d4
	if (ctx.cr6.eq) goto loc_821CB2D4;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x821cb2d4
	if (ctx.cr6.eq) goto loc_821CB2D4;
	// lis r4,-24576
	ctx.r4.s64 = -1610612736;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82088c48
	ctx.lr = 0x821CB2B8;
	sub_82088C48(ctx, base);
	// lwz r11,-31364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31364);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// bl 0x82088630
	ctx.lr = 0x821CB2CC;
	sub_82088630(ctx, base);
	// lwz r11,-31364(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31364);
	// stw r30,8(r11)
	PPC_STORE_U32(ctx.r11.u32 + 8, ctx.r30.u32);
loc_821CB2D4:
	// bl 0x821cb198
	ctx.lr = 0x821CB2D8;
	sub_821CB198(ctx, base);
loc_821CB2D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB2E0"))) PPC_WEAK_FUNC(sub_821CB2E0);
PPC_FUNC_IMPL(__imp__sub_821CB2E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_821CB2FC:
	// stdu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r11.u32 = ea;
	// bdnz 0x821cb2fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821CB2FC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d5184
	ctx.lr = 0x821CB30C;
	__imp__XGetVideoMode(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r11,r11,-12560
	ctx.r11.s64 = ctx.r11.s64 + -12560;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r9,r10,-2064
	ctx.r9.s64 = ctx.r10.s64 + -2064;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r7,80(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// lwz r11,84(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// lfs f13,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
	// fmsubs f1,f0,f13,f5
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64 - ctx.f5.f64));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CB380"))) PPC_WEAK_FUNC(sub_821CB380);
PPC_FUNC_IMPL(__imp__sub_821CB380) {
	PPC_FUNC_PROLOGUE();
	// add r11,r3,r4
	ctx.r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821CB394"))) PPC_WEAK_FUNC(sub_821CB394);
PPC_FUNC_IMPL(__imp__sub_821CB394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CB398"))) PPC_WEAK_FUNC(sub_821CB398);
PPC_FUNC_IMPL(__imp__sub_821CB398) {
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
	// bl 0x821cb2e0
	ctx.lr = 0x821CB3B0;
	sub_821CB2E0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-2064
	ctx.r9.s64 = ctx.r11.s64 + -2064;
	// addi r11,r31,120
	ctx.r11.s64 = ctx.r31.s64 + 120;
	// lfs f13,21768(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r31.u32 + 124, temp.u32);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821cb434
	if (ctx.cr6.eq) goto loc_821CB434;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// li r9,524
	ctx.r9.s64 = 524;
	// addi r11,r10,240
	ctx.r11.s64 = ctx.r10.s64 + 240;
	// lwz r10,252(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 252);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r10,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r10.s64;
	// divw. r5,r6,r9
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cb40c
	if (!ctx.cr0.eq) goto loc_821CB40C;
	// twi 31,r0,22
loc_821CB40C:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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
	// bne 0x821cb42c
	if (!ctx.cr0.eq) goto loc_821CB42C;
	// twi 31,r0,22
loc_821CB42C:
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,484(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
loc_821CB434:
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

__attribute__((alias("__imp__sub_821CB448"))) PPC_WEAK_FUNC(sub_821CB448);
PPC_FUNC_IMPL(__imp__sub_821CB448) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821CB450;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32224
	ctx.r26.s64 = -2111832064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r11,-1280
	ctx.r10.s64 = ctx.r11.s64 + -1280;
	// lwz r28,-31372(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + -31372);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x821cb4b4
	if (ctx.cr6.eq) goto loc_821CB4B4;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// li r29,2
	ctx.r29.s64 = 2;
	// li r27,0
	ctx.r27.s64 = 0;
loc_821CB480:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb494
	if (ctx.cr6.eq) goto loc_821CB494;
	// bl 0x820a4400
	ctx.lr = 0x821CB490;
	sub_820A4400(ctx, base);
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
loc_821CB494:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x821cb480
	if (!ctx.cr0.eq) goto loc_821CB480;
	// bl 0x82181b70
	ctx.lr = 0x821CB4A4;
	sub_82181B70(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8207a630
	ctx.lr = 0x821CB4AC;
	sub_8207A630(ctx, base);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stw r27,-31372(r26)
	PPC_STORE_U32(ctx.r26.u32 + -31372, ctx.r27.u32);
loc_821CB4B4:
	// addi r3,r30,96
	ctx.r3.s64 = ctx.r30.s64 + 96;
	// bl 0x82060db0
	ctx.lr = 0x821CB4BC;
	sub_82060DB0(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r30,44
	ctx.r3.s64 = ctx.r30.s64 + 44;
	// addi r31,r11,-1408
	ctx.r31.s64 = ctx.r11.s64 + -1408;
	// stw r31,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r31.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CB4D0;
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
	ctx.lr = 0x821CB4E8;
	sub_82173A18(ctx, base);
	// stw r29,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
	// stw r29,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB4F8"))) PPC_WEAK_FUNC(sub_821CB4F8);
PPC_FUNC_IMPL(__imp__sub_821CB4F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CB500;
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// addi r6,r9,-1396
	ctx.r6.s64 = ctx.r9.s64 + -1396;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r5,r8,840
	ctx.r5.s64 = ctx.r8.s64 + 840;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// addi r4,r7,-1280
	ctx.r4.s64 = ctx.r7.s64 + -1280;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// addi r29,r31,96
	ctx.r29.s64 = ctx.r31.s64 + 96;
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
	// stw r4,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// stb r9,29(r31)
	PPC_STORE_U8(ctx.r31.u32 + 29, ctx.r9.u8);
	// stb r9,57(r31)
	PPC_STORE_U8(ctx.r31.u32 + 57, ctx.r9.u8);
	// bl 0x82079fd8
	ctx.lr = 0x821CB598;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb5a8
	if (ctx.cr6.eq) goto loc_821CB5A8;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// b 0x821cb5ac
	goto loc_821CB5AC;
loc_821CB5A8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821CB5AC:
	// stw r3,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,60
	ctx.r3.s64 = 60;
	// stw r30,12(r29)
	PPC_STORE_U32(ctx.r29.u32 + 12, ctx.r30.u32);
	// stw r30,16(r29)
	PPC_STORE_U32(ctx.r29.u32 + 16, ctx.r30.u32);
	// stw r30,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CB5C4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb5d8
	if (ctx.cr6.eq) goto loc_821CB5D8;
	// bl 0x82181ec8
	ctx.lr = 0x821CB5D0;
	sub_82181EC8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cb5dc
	goto loc_821CB5DC;
loc_821CB5D8:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821CB5DC:
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r30,-31368(r9)
	PPC_STORE_U32(ctx.r9.u32 + -31368, ctx.r30.u32);
	// stw r11,-31372(r10)
	PPC_STORE_U32(ctx.r10.u32 + -31372, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB5F8"))) PPC_WEAK_FUNC(sub_821CB5F8);
PPC_FUNC_IMPL(__imp__sub_821CB5F8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// b 0x82182a68
	sub_82182A68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB600"))) PPC_WEAK_FUNC(sub_821CB600);
PPC_FUNC_IMPL(__imp__sub_821CB600) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,-31368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31368);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-31368(r11)
	PPC_STORE_U32(ctx.r11.u32 + -31368, ctx.r10.u32);
	// b 0x82184cc8
	sub_82184CC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB62C"))) PPC_WEAK_FUNC(sub_821CB62C);
PPC_FUNC_IMPL(__imp__sub_821CB62C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CB630"))) PPC_WEAK_FUNC(sub_821CB630);
PPC_FUNC_IMPL(__imp__sub_821CB630) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CB638;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82079fd8
	ctx.lr = 0x821CB648;
	sub_82079FD8(ctx, base);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb65c
	if (ctx.cr6.eq) goto loc_821CB65C;
	// bl 0x8217a960
	ctx.lr = 0x821CB658;
	sub_8217A960(ctx, base);
	// b 0x821cb660
	goto loc_821CB660;
loc_821CB65C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821CB660:
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x8217b6a8
	ctx.lr = 0x821CB66C;
	sub_8217B6A8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r3,556
	ctx.r3.s64 = 556;
	// stb r30,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r30.u8);
	// bl 0x82079fd8
	ctx.lr = 0x821CB67C;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb6f0
	if (ctx.cr6.eq) goto loc_821CB6F0;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r9,56
	ctx.r9.s64 = 56;
	// lwz r8,112(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x821cb6ac
	if (ctx.cr6.lt) goto loc_821CB6AC;
	// twi 31,r0,22
loc_821CB6AC:
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mulli r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 * 56;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r4,r11,28
	ctx.r4.s64 = ctx.r11.s64 + 28;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821CB6D8;
	sub_820601F8(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821CB6E8;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cb6f4
	goto loc_821CB6F4;
loc_821CB6F0:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821CB6F4:
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-3164
	ctx.r4.s64 = ctx.r10.s64 + -3164;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821CB70C;
	sub_8217C468(ctx, base);
	// lwz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r9,524
	ctx.r9.s64 = 524;
	// stb r30,12(r8)
	PPC_STORE_U8(ctx.r8.u32 + 12, ctx.r30.u8);
	// lwz r11,268(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 268);
	// lwz r7,272(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r9
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cb730
	if (!ctx.cr0.eq) goto loc_821CB730;
	// twi 31,r0,22
loc_821CB730:
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r7,r9,-12560
	ctx.r7.s64 = ctx.r9.s64 + -12560;
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r6,20(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r5,20(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lbz r4,73(r7)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + 73);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x821cb788
	if (!ctx.cr6.eq) goto loc_821CB788;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x821cb398
	ctx.lr = 0x821CB788;
	sub_821CB398(ctx, base);
loc_821CB788:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-17896
	ctx.r10.s64 = ctx.r11.s64 + -17896;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB79C"))) PPC_WEAK_FUNC(sub_821CB79C);
PPC_FUNC_IMPL(__imp__sub_821CB79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CB7A0"))) PPC_WEAK_FUNC(sub_821CB7A0);
PPC_FUNC_IMPL(__imp__sub_821CB7A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CB7A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,92(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x821cb7ec
	if (ctx.cr6.eq) goto loc_821CB7EC;
	// lwz r3,84(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// bl 0x82173a70
	ctx.lr = 0x821CB7C8;
	sub_82173A70(ctx, base);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb7e8
	if (ctx.cr6.eq) goto loc_821CB7E8;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CB7E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CB7E8:
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
loc_821CB7EC:
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x821cb824
	if (ctx.cr6.eq) goto loc_821CB824;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x82173a70
	ctx.lr = 0x821CB800;
	sub_82173A70(ctx, base);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb820
	if (ctx.cr6.eq) goto loc_821CB820;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CB820;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CB820:
	// stw r30,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r30.u32);
loc_821CB824:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r29,r31,76
	ctx.r29.s64 = ctx.r31.s64 + 76;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cb83c
	if (ctx.cr6.eq) goto loc_821CB83C;
	// bl 0x82060120
	ctx.lr = 0x821CB838;
	sub_82060120(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
loc_821CB83C:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 108);
	// li r9,56
	ctx.r9.s64 = 56;
	// lwz r8,112(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r11,128(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 128);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x821cb860
	if (ctx.cr6.lt) goto loc_821CB860;
	// twi 31,r0,22
loc_821CB860:
	// li r9,15
	ctx.r9.s64 = 15;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// mulli r11,r11,56
	ctx.r11.s64 = ctx.r11.s64 * 56;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x820601f8
	ctx.lr = 0x821CB888;
	sub_820601F8(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31352(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31352);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x82194df8
	ctx.lr = 0x821CB8B0;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821CB8B4;
	sub_82193870(ctx, base);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,-18896
	ctx.r9.s64 = ctx.r10.s64 + -18896;
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
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CB8E0"))) PPC_WEAK_FUNC(sub_821CB8E0);
PPC_FUNC_IMPL(__imp__sub_821CB8E0) {
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
	// lis r31,-32224
	ctx.r31.s64 = -2111832064;
	// lwz r11,-31372(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31372);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cb920
	if (ctx.cr6.eq) goto loc_821CB920;
	// lwz r11,-31368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -31368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821cb920
	if (!ctx.cr6.eq) goto loc_821CB920;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,-31368(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31368, ctx.r11.u32);
	// bl 0x82184cc8
	ctx.lr = 0x821CB920;
	sub_82184CC8(ctx, base);
loc_821CB920:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// stw r11,-31368(r31)
	PPC_STORE_U32(ctx.r31.u32 + -31368, ctx.r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x8209af10
	ctx.lr = 0x821CB940;
	sub_8209AF10(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,500(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 500);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8209ad40
	ctx.lr = 0x821CB954;
	sub_8209AD40(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r9,152(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r4,504(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 504);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8209ab80
	ctx.lr = 0x821CB968;
	sub_8209AB80(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,152(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x82097540
	ctx.lr = 0x821CB97C;
	sub_82097540(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,152(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// bl 0x820972d8
	ctx.lr = 0x821CB990;
	sub_820972D8(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,152(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x82096e78
	ctx.lr = 0x821CB9A4;
	sub_82096E78(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r5,152(r11)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// bl 0x82097338
	ctx.lr = 0x821CB9B8;
	sub_82097338(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82096fd0
	ctx.lr = 0x821CB9CC;
	sub_82096FD0(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r11,152(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// bl 0x82097060
	ctx.lr = 0x821CB9E0;
	sub_82097060(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 152);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82096eb0
	ctx.lr = 0x821CB9F4;
	sub_82096EB0(ctx, base);
	// lwz r11,-31312(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31312);
	// lwz r3,156(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 156);
	// bl 0x8216d628
	ctx.lr = 0x821CBA00;
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

__attribute__((alias("__imp__sub_821CBA18"))) PPC_WEAK_FUNC(sub_821CBA18);
PPC_FUNC_IMPL(__imp__sub_821CBA18) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,132(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r11.u32);
	// addi r9,r10,-18528
	ctx.r9.s64 = ctx.r10.s64 + -18528;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CBA3C"))) PPC_WEAK_FUNC(sub_821CBA3C);
PPC_FUNC_IMPL(__imp__sub_821CBA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CBA40"))) PPC_WEAK_FUNC(sub_821CBA40);
PPC_FUNC_IMPL(__imp__sub_821CBA40) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821CBA4C"))) PPC_WEAK_FUNC(sub_821CBA4C);
PPC_FUNC_IMPL(__imp__sub_821CBA4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CBA50"))) PPC_WEAK_FUNC(sub_821CBA50);
PPC_FUNC_IMPL(__imp__sub_821CBA50) {
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
	ctx.lr = 0x821CBA70;
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

__attribute__((alias("__imp__sub_821CBAA0"))) PPC_WEAK_FUNC(sub_821CBAA0);
PPC_FUNC_IMPL(__imp__sub_821CBAA0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-17840
	ctx.r10.s64 = ctx.r11.s64 + -17840;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CBAB0"))) PPC_WEAK_FUNC(sub_821CBAB0);
PPC_FUNC_IMPL(__imp__sub_821CBAB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CBAB8;
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,-1336
	ctx.r10.s64 = ctx.r11.s64 + -1336;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x821cbae4
	if (ctx.cr6.eq) goto loc_821CBAE4;
	// bl 0x82060120
	ctx.lr = 0x821CBADC;
	sub_82060120(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
loc_821CBAE4:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CBAF8;
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
	ctx.lr = 0x821CBB10;
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

__attribute__((alias("__imp__sub_821CBB20"))) PPC_WEAK_FUNC(sub_821CBB20);
PPC_FUNC_IMPL(__imp__sub_821CBB20) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CBB28;
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
	ctx.lr = 0x821CBB38;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cbb98
	if (ctx.cr6.eq) goto loc_821CBB98;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-20287
	ctx.r4.s64 = ctx.r11.s64 + -20287;
	// bl 0x82060190
	ctx.lr = 0x821CBB54;
	sub_82060190(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,-2860
	ctx.r4.s64 = ctx.r10.s64 + -2860;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821CBB68;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CBB78;
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
	ctx.lr = 0x821CBB94;
	sub_821BD670(ctx, base);
	// b 0x821cbb9c
	goto loc_821CBB9C;
loc_821CBB98:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821CBB9C:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-17760
	ctx.r6.s64 = ctx.r8.s64 + -17760;
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

__attribute__((alias("__imp__sub_821CBBCC"))) PPC_WEAK_FUNC(sub_821CBBCC);
PPC_FUNC_IMPL(__imp__sub_821CBBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CBBD0"))) PPC_WEAK_FUNC(sub_821CBBD0);
PPC_FUNC_IMPL(__imp__sub_821CBBD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CBBD8;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r10,r11,-17760
	ctx.r10.s64 = ctx.r11.s64 + -17760;
	// lwz r11,-31352(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r31,84(r9)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r8,1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 1, ctx.xer);
	// bne cr6,0x821cbc34
	if (!ctx.cr6.eq) goto loc_821CBC34;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cbc34
	if (ctx.cr6.eq) goto loc_821CBC34;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82088370
	ctx.lr = 0x821CBC1C;
	sub_82088370(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x821cbc2c
	if (!ctx.cr6.eq) goto loc_821CBC2C;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x821cbc38
	goto loc_821CBC38;
loc_821CBC2C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_821CBC34:
	// li r11,0
	ctx.r11.s64 = 0;
loc_821CBC38:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cbc7c
	if (ctx.cr6.eq) goto loc_821CBC7C;
	// lis r3,13
	ctx.r3.s64 = 851968;
	// li r4,1
	ctx.r4.s64 = 1;
	// ori r3,r3,12480
	ctx.r3.u64 = ctx.r3.u64 | 12480;
	// bl 0x82088378
	ctx.lr = 0x821CBC54;
	sub_82088378(ctx, base);
	// lwz r11,-31352(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 84);
	// bl 0x82190318
	ctx.lr = 0x821CBC68;
	sub_82190318(ctx, base);
	// cmpld cr6,r31,r3
	ctx.cr6.compare<uint64_t>(ctx.r31.u64, ctx.r3.u64, ctx.xer);
	// ble cr6,0x821cbc7c
	if (!ctx.cr6.gt) goto loc_821CBC7C;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-17632
	ctx.r10.s64 = ctx.r11.s64 + -17632;
	// stw r10,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r10.u32);
loc_821CBC7C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CBC84"))) PPC_WEAK_FUNC(sub_821CBC84);
PPC_FUNC_IMPL(__imp__sub_821CBC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CBC88"))) PPC_WEAK_FUNC(sub_821CBC88);
PPC_FUNC_IMPL(__imp__sub_821CBC88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CBC90;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,264
	ctx.r3.s64 = 264;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// stw r9,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r9.u32);
	// stw r9,14572(r10)
	PPC_STORE_U32(ctx.r10.u32 + 14572, ctx.r9.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CBCBC;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cbd1c
	if (ctx.cr6.eq) goto loc_821CBD1C;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-20301
	ctx.r4.s64 = ctx.r11.s64 + -20301;
	// bl 0x82060190
	ctx.lr = 0x821CBCD8;
	sub_82060190(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,-2888
	ctx.r4.s64 = ctx.r10.s64 + -2888;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821CBCEC;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CBCFC;
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
	ctx.lr = 0x821CBD18;
	sub_821BD670(ctx, base);
	// b 0x821cbd20
	goto loc_821CBD20;
loc_821CBD1C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821CBD20:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-17840
	ctx.r6.s64 = ctx.r8.s64 + -17840;
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

__attribute__((alias("__imp__sub_821CBD50"))) PPC_WEAK_FUNC(sub_821CBD50);
PPC_FUNC_IMPL(__imp__sub_821CBD50) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,132(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821cbd6c
	if (ctx.cr6.eq) goto loc_821CBD6C;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-17272
	ctx.r10.s64 = ctx.r11.s64 + -17272;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_821CBD6C:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-16648
	ctx.r10.s64 = ctx.r11.s64 + -16648;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CBD7C"))) PPC_WEAK_FUNC(sub_821CBD7C);
PPC_FUNC_IMPL(__imp__sub_821CBD7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CBD80"))) PPC_WEAK_FUNC(sub_821CBD80);
PPC_FUNC_IMPL(__imp__sub_821CBD80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CBD88;
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
	ctx.lr = 0x821CBD98;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cbdf8
	if (ctx.cr6.eq) goto loc_821CBDF8;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-20357
	ctx.r4.s64 = ctx.r11.s64 + -20357;
	// bl 0x82060190
	ctx.lr = 0x821CBDB4;
	sub_82060190(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r4,r10,-2912
	ctx.r4.s64 = ctx.r10.s64 + -2912;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821CBDC8;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CBDD8;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r31,132
	ctx.r6.s64 = ctx.r31.s64 + 132;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x821CBDF4;
	sub_821BD670(ctx, base);
	// b 0x821cbdfc
	goto loc_821CBDFC;
loc_821CBDF8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821CBDFC:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-17072
	ctx.r6.s64 = ctx.r8.s64 + -17072;
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

__attribute__((alias("__imp__sub_821CBE2C"))) PPC_WEAK_FUNC(sub_821CBE2C);
PPC_FUNC_IMPL(__imp__sub_821CBE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CBE30"))) PPC_WEAK_FUNC(sub_821CBE30);
PPC_FUNC_IMPL(__imp__sub_821CBE30) {
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
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,8288
	ctx.r3.s64 = 8288;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CBE5C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cbe70
	if (ctx.cr6.eq) goto loc_821CBE70;
	// addi r4,r31,112
	ctx.r4.s64 = ctx.r31.s64 + 112;
	// bl 0x82188c18
	ctx.lr = 0x821CBE6C;
	sub_82188C18(ctx, base);
	// b 0x821cbe74
	goto loc_821CBE74;
loc_821CBE70:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821CBE74:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-17456
	ctx.r6.s64 = ctx.r8.s64 + -17456;
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

__attribute__((alias("__imp__sub_821CBEB0"))) PPC_WEAK_FUNC(sub_821CBEB0);
PPC_FUNC_IMPL(__imp__sub_821CBEB0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,76(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,40(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x821cbee8
	if (!ctx.cr6.lt) goto loc_821CBEE8;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-16848
	ctx.r10.s64 = ctx.r11.s64 + -16848;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
loc_821CBEE8:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-17024
	ctx.r10.s64 = ctx.r11.s64 + -17024;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CBEF8"))) PPC_WEAK_FUNC(sub_821CBEF8);
PPC_FUNC_IMPL(__imp__sub_821CBEF8) {
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
	// lwz r4,108(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,76(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// bl 0x82190f80
	ctx.lr = 0x821CBF24;
	sub_82190F80(ctx, base);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// blt cr6,0x821cbf38
	if (ctx.cr6.lt) goto loc_821CBF38;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-16720
	ctx.r10.s64 = ctx.r11.s64 + -16720;
	// b 0x821cbf40
	goto loc_821CBF40;
loc_821CBF38:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-16848
	ctx.r10.s64 = ctx.r11.s64 + -16848;
loc_821CBF40:
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

__attribute__((alias("__imp__sub_821CBF58"))) PPC_WEAK_FUNC(sub_821CBF58);
PPC_FUNC_IMPL(__imp__sub_821CBF58) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// divwu r7,r11,r10
	ctx.r7.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r11.u32);
	// mullw r6,r7,r10
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// subf. r5,r6,r11
	ctx.r5.s64 = ctx.r11.s64 - ctx.r6.s64;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq 0x821cbfa0
	if (ctx.cr0.eq) goto loc_821CBFA0;
	// divwu r11,r11,r10
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821cbf9c
	if (ctx.cr6.eq) goto loc_821CBF9C;
	// stb r8,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r8.u8);
	// b 0x821cbfa0
	goto loc_821CBFA0;
loc_821CBF9C:
	// stb r9,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r9.u8);
loc_821CBFA0:
	// lwz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r11,84(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r9,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r9.u32);
	// stw r9,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r9.u32);
	// stw r9,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r9.u32);
	// stw r9,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r9.u32);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// beq cr6,0x821cbfe0
	if (ctx.cr6.eq) goto loc_821CBFE0;
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
loc_821CBFE0:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-16648
	ctx.r10.s64 = ctx.r11.s64 + -16648;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CBFF0"))) PPC_WEAK_FUNC(sub_821CBFF0);
PPC_FUNC_IMPL(__imp__sub_821CBFF0) {
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
	// lwz r11,124(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// divwu r9,r11,r10
	ctx.r9.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r11.u32);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf. r6,r8,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r8.s64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x821cc04c
	if (ctx.cr0.eq) goto loc_821CC04C;
	// divwu r11,r11,r10
	ctx.r11.u32 = ppc_divwu(ctx.r11.u32, ctx.r10.u32);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r11,88(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821cc048
	if (ctx.cr6.eq) goto loc_821CC048;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r10.u8);
	// b 0x821cc04c
	goto loc_821CC04C;
loc_821CC048:
	// stb r7,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r7.u8);
loc_821CC04C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r3,80(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// bl 0x82190a90
	ctx.lr = 0x821CC060;
	sub_82190A90(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(ctx.r31.u32 + 108, ctx.r3.u32);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x821cc0bc
	if (!ctx.cr6.lt) goto loc_821CC0BC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r7,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r7.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,300
	ctx.r11.s64 = ctx.r11.s64 + 300;
loc_821CC088:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821cc0a8
	if (ctx.cr6.eq) goto loc_821CC0A8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// ble cr6,0x821cc088
	if (!ctx.cr6.gt) goto loc_821CC088;
	// li r3,1
	ctx.r3.s64 = 1;
loc_821CC0A8:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82188f90
	ctx.lr = 0x821CC0B0;
	sub_82188F90(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-16552
	ctx.r10.s64 = ctx.r11.s64 + -16552;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821CC0BC:
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

__attribute__((alias("__imp__sub_821CC0D0"))) PPC_WEAK_FUNC(sub_821CC0D0);
PPC_FUNC_IMPL(__imp__sub_821CC0D0) {
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
	// lwz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821cc124
	if (!ctx.cr6.eq) goto loc_821CC124;
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r9,524
	ctx.r9.s64 = 524;
	// stb r30,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r30.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r8,272(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821cc11c
	if (!ctx.cr0.eq) goto loc_821CC11C;
	// twi 31,r0,22
loc_821CC11C:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
loc_821CC124:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31352(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 76);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// lwz r8,596(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 596);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// rlwinm r7,r7,0,31,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x821cc150
	if (ctx.cr6.eq) goto loc_821CC150;
	// li r11,60
	ctx.r11.s64 = 60;
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
loc_821CC150:
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r7,r9,-2064
	ctx.r7.s64 = ctx.r9.s64 + -2064;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,136(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,292(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// rotlwi r11,r6,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// or r10,r11,r6
	ctx.r10.u64 = ctx.r11.u64 | ctx.r6.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwimi r4,r8,8,0,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r4.u64 & 0xFFFFFFFF000000FF);
	// bl 0x821796b0
	ctx.lr = 0x821CC1B0;
	sub_821796B0(ctx, base);
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,60
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 60, ctx.xer);
	// stw r7,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r7.u32);
	// blt cr6,0x821cc1e4
	if (ctx.cr6.lt) goto loc_821CC1E4;
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// stb r30,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r30.u8);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// stb r30,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r30.u8);
	// bl 0x82188908
	ctx.lr = 0x821CC1D8;
	sub_82188908(ctx, base);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// addi r8,r9,-16400
	ctx.r8.s64 = ctx.r9.s64 + -16400;
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
loc_821CC1E4:
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

__attribute__((alias("__imp__sub_821CC1FC"))) PPC_WEAK_FUNC(sub_821CC1FC);
PPC_FUNC_IMPL(__imp__sub_821CC1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC200"))) PPC_WEAK_FUNC(sub_821CC200);
PPC_FUNC_IMPL(__imp__sub_821CC200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c974
	ctx.lr = 0x821CC208;
	__savegprlr_23(ctx, base);
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r23,r11,-2064
	ctx.r23.s64 = ctx.r11.s64 + -2064;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r11,-31348(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r6,-32225
	ctx.r6.s64 = -2111897600;
	// lfs f31,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,164(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// li r3,28
	ctx.r3.s64 = 28;
	// lfs f30,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f30.f64 = double(temp.f32);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// stfs f31,-31332(r7)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + -31332, temp.u32);
	// stfs f30,-14024(r6)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r6.u32 + -14024, temp.u32);
	// stfs f0,1452(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1452, temp.u32);
	// stfs f30,1460(r11)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1460, temp.u32);
	// stfs f0,1456(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1456, temp.u32);
	// stfs f30,1464(r11)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r11.u32 + 1464, temp.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CC26C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r30,0
	ctx.r30.s64 = 0;
	// beq cr6,0x821cc2ac
	if (ctx.cr6.eq) goto loc_821CC2AC;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r9,r10,5300
	ctx.r9.s64 = ctx.r10.s64 + 5300;
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// b 0x821cc2b0
	goto loc_821CC2B0;
loc_821CC2AC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821CC2B0:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82079fd8
	ctx.lr = 0x821CC2BC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cc328
	if (ctx.cr6.eq) goto loc_821CC328;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r30.u32);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r30,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r30.u8);
	// addi r9,r10,5312
	ctx.r9.s64 = ctx.r10.s64 + 5312;
	// stb r30,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r30.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lfs f0,56(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stb r30,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r30.u8);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r30.u32);
	// stb r30,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r30.u8);
	// stfs f31,28(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f31,32(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f31,36(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f31,40(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f30,44(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f30,48(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f31,52(r3)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f30,56(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f30,60(r3)
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// b 0x821cc32c
	goto loc_821CC32C;
loc_821CC328:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821CC32C:
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82079fd8
	ctx.lr = 0x821CC338;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cc348
	if (ctx.cr6.eq) goto loc_821CC348;
	// bl 0x8217a960
	ctx.lr = 0x821CC344;
	sub_8217A960(ctx, base);
	// b 0x821cc34c
	goto loc_821CC34C;
loc_821CC348:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821CC34C:
	// stw r3,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r3.u32);
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// bl 0x8217b6a8
	ctx.lr = 0x821CC358;
	sub_8217B6A8(ctx, base);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// li r3,556
	ctx.r3.s64 = 556;
	// stb r30,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r30.u8);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CC384;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r26,r11,-2940
	ctx.r26.s64 = ctx.r11.s64 + -2940;
	// beq cr6,0x821cc3bc
	if (ctx.cr6.eq) goto loc_821CC3BC;
	// addi r4,r26,-84
	ctx.r4.s64 = ctx.r26.s64 + -84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821CC3A4;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// bl 0x8217aa80
	ctx.lr = 0x821CC3B4;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cc3c0
	goto loc_821CC3C0;
loc_821CC3BC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821CC3C0:
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// addi r4,r26,-76
	ctx.r4.s64 = ctx.r26.s64 + -76;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821CC3D4;
	sub_8217C468(ctx, base);
	// lwz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// li r24,1
	ctx.r24.s64 = 1;
	// li r10,524
	ctx.r10.s64 = 524;
	// stb r24,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r24.u8);
	// lwz r11,268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// lwz r8,272(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// divw. r6,r7,r10
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821cc3fc
	if (!ctx.cr0.eq) goto loc_821CC3FC;
	// twi 31,r0,22
loc_821CC3FC:
	// stb r30,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r30.u8);
	// lis r25,-32224
	ctx.r25.s64 = -2111832064;
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// lwz r8,-31380(r25)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r25.u32 + -31380);
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r9,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r9.u32);
	// addi r9,r8,104
	ctx.r9.s64 = ctx.r8.s64 + 104;
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
loc_821CC42C:
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x821cc484
	if (ctx.cr6.eq) goto loc_821CC484;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,52
	ctx.r9.s64 = ctx.r9.s64 + 52;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// blt cr6,0x821cc42c
	if (ctx.cr6.lt) goto loc_821CC42C;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_821CC44C:
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82079fd8
	ctx.lr = 0x821CC454;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cc4b8
	if (ctx.cr6.eq) goto loc_821CC4B8;
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x821CC468;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cc494
	if (ctx.cr6.eq) goto loc_821CC494;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8216fcf0
	ctx.lr = 0x821CC47C;
	sub_8216FCF0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x821cc498
	goto loc_821CC498;
loc_821CC484:
	// mulli r11,r10,52
	ctx.r11.s64 = ctx.r10.s64 * 52;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r29,116(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// b 0x821cc44c
	goto loc_821CC44C;
loc_821CC494:
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_821CC498:
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216e790
	ctx.lr = 0x821CC4B0;
	sub_8216E790(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cc4c0
	goto loc_821CC4C0;
loc_821CC4B8:
	// lwz r27,80(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_821CC4C0:
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82079fd8
	ctx.lr = 0x821CC4CC;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cc560
	if (ctx.cr6.eq) goto loc_821CC560;
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x821CC4E0;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cc540
	if (ctx.cr6.eq) goto loc_821CC540;
	// lwz r9,-31380(r25)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r25.u32 + -31380);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r9,104
	ctx.r10.s64 = ctx.r9.s64 + 104;
loc_821CC4F4:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,3
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 3, ctx.xer);
	// beq cr6,0x821cc524
	if (ctx.cr6.eq) goto loc_821CC524;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,52
	ctx.r10.s64 = ctx.r10.s64 + 52;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x821cc4f4
	if (ctx.cr6.lt) goto loc_821CC4F4;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8216fcf0
	ctx.lr = 0x821CC51C;
	sub_8216FCF0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x821cc544
	goto loc_821CC544;
loc_821CC524:
	// mulli r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 * 52;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r4,116(r11)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// bl 0x8216fcf0
	ctx.lr = 0x821CC538;
	sub_8216FCF0(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// b 0x821cc544
	goto loc_821CC544;
loc_821CC540:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
loc_821CC544:
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8216e790
	ctx.lr = 0x821CC55C;
	sub_8216E790(ctx, base);
	// b 0x821cc568
	goto loc_821CC568;
loc_821CC560:
	// lwz r28,80(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821CC568:
	// stw r3,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CC584;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r29,15
	ctx.r29.s64 = 15;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// addi r4,r26,-68
	ctx.r4.s64 = ctx.r26.s64 + -68;
	// li r5,18
	ctx.r5.s64 = 18;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f29,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f29.f64 = double(temp.f32);
	// bl 0x82060368
	ctx.lr = 0x821CC5B4;
	sub_82060368(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8216f7a8
	ctx.lr = 0x821CC5C8;
	sub_8216F7A8(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lwz r7,88(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f30,32(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 32);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// lfs f10,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f30.f64));
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lfs f0,5388(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 5388);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f11,f29,f0
	ctx.f11.f64 = double(float(ctx.f29.f64 * ctx.f0.f64));
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// fadds f8,f11,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f8,84(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x821CC610;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// addi r4,r26,-48
	ctx.r4.s64 = ctx.r26.s64 + -48;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// li r5,18
	ctx.r5.s64 = 18;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060368
	ctx.lr = 0x821CC62C;
	sub_82060368(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8216e718
	ctx.lr = 0x821CC638;
	sub_8216E718(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r24,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r24.u8);
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x821CC674;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// addi r4,r26,-28
	ctx.r4.s64 = ctx.r26.s64 + -28;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// li r5,24
	ctx.r5.s64 = 24;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f31,4(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x82060368
	ctx.lr = 0x821CC6A0;
	sub_82060368(ctx, base);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8216f7a8
	ctx.lr = 0x821CC6B4;
	sub_8216F7A8(ctx, base);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lfs f6,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f0,96(r23)
	temp.u32 = PPC_LOAD_U32(ctx.r23.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f30.f64));
	// fmuls f7,f31,f0
	ctx.f7.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f4,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f4,f30
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f30.f64));
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// fadds f2,f7,f5
	ctx.f2.f64 = double(float(ctx.f7.f64 + ctx.f5.f64));
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x821CC6F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r30,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// li r5,24
	ctx.r5.s64 = 24;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r30.u8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060368
	ctx.lr = 0x821CC710;
	sub_82060368(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// bl 0x8216e718
	ctx.lr = 0x821CC71C;
	sub_8216E718(ctx, base);
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// lis r7,-32227
	ctx.r7.s64 = -2112028672;
	// li r6,20
	ctx.r6.s64 = 20;
	// addi r5,r7,-16176
	ctx.r5.s64 = ctx.r7.s64 + -16176;
	// stb r24,12(r4)
	PPC_STORE_U8(ctx.r4.u32 + 12, ctx.r24.u8);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// stw r8,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r8.u32);
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r9,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r9.u32);
	// stw r30,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// stw r6,128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 128, ctx.r6.u32);
	// stw r5,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r5.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x8207c9c4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CC7A4"))) PPC_WEAK_FUNC(sub_821CC7A4);
PPC_FUNC_IMPL(__imp__sub_821CC7A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC7A8"))) PPC_WEAK_FUNC(sub_821CC7A8);
PPC_FUNC_IMPL(__imp__sub_821CC7A8) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r10,-3044
	ctx.r4.s64 = ctx.r10.s64 + -3044;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821CC7E8;
	sub_82060368(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r9,128
	ctx.r9.s64 = 8388608;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31352(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31352);
	// addi r5,r31,76
	ctx.r5.s64 = ctx.r31.s64 + 76;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x82194df8
	ctx.lr = 0x821CC810;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821CC814;
	sub_82193870(ctx, base);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,-15872
	ctx.r9.s64 = ctx.r10.s64 + -15872;
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

__attribute__((alias("__imp__sub_821CC850"))) PPC_WEAK_FUNC(sub_821CC850);
PPC_FUNC_IMPL(__imp__sub_821CC850) {
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
	// lis r5,-32227
	ctx.r5.s64 = -2112028672;
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
	// addi r6,r6,-1336
	ctx.r6.s64 = ctx.r6.s64 + -1336;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r5,r5,-14424
	ctx.r5.s64 = ctx.r5.s64 + -14424;
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
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// stw r5,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CC8F0"))) PPC_WEAK_FUNC(sub_821CC8F0);
PPC_FUNC_IMPL(__imp__sub_821CC8F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CC8F4"))) PPC_WEAK_FUNC(sub_821CC8F4);
PPC_FUNC_IMPL(__imp__sub_821CC8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC8F8"))) PPC_WEAK_FUNC(sub_821CC8F8);
PPC_FUNC_IMPL(__imp__sub_821CC8F8) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821CC904"))) PPC_WEAK_FUNC(sub_821CC904);
PPC_FUNC_IMPL(__imp__sub_821CC904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC908"))) PPC_WEAK_FUNC(sub_821CC908);
PPC_FUNC_IMPL(__imp__sub_821CC908) {
	PPC_FUNC_PROLOGUE();
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,104
	ctx.r11.s64 = ctx.r3.s64 + 104;
loc_821CC910:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r9,r4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, ctx.xer);
	// beq cr6,0x821cc934
	if (ctx.cr6.eq) goto loc_821CC934;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 + 52;
	// cmpwi cr6,r10,8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 8, ctx.xer);
	// blt cr6,0x821cc910
	if (ctx.cr6.lt) goto loc_821CC910;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_821CC934:
	// mulli r11,r10,52
	ctx.r11.s64 = ctx.r10.s64 * 52;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r3,116(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CC944"))) PPC_WEAK_FUNC(sub_821CC944);
PPC_FUNC_IMPL(__imp__sub_821CC944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC948"))) PPC_WEAK_FUNC(sub_821CC948);
PPC_FUNC_IMPL(__imp__sub_821CC948) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821CC954"))) PPC_WEAK_FUNC(sub_821CC954);
PPC_FUNC_IMPL(__imp__sub_821CC954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC958"))) PPC_WEAK_FUNC(sub_821CC958);
PPC_FUNC_IMPL(__imp__sub_821CC958) {
	PPC_FUNC_PROLOGUE();
	// lbz r11,116(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,104(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r9,116(r3)
	PPC_STORE_U8(ctx.r3.u32 + 116, ctx.r9.u8);
	// li r8,524
	ctx.r8.s64 = 524;
	// stb r10,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r10.u8);
	// lwz r10,268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 268);
	// lwz r7,272(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// subf r6,r10,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r10.s64;
	// divw. r5,r6,r8
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cc99c
	if (!ctx.cr0.eq) goto loc_821CC99C;
	// twi 31,r0,22
loc_821CC99C:
	// stb r9,477(r10)
	PPC_STORE_U8(ctx.r10.u32 + 477, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CC9A4"))) PPC_WEAK_FUNC(sub_821CC9A4);
PPC_FUNC_IMPL(__imp__sub_821CC9A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CC9A8"))) PPC_WEAK_FUNC(sub_821CC9A8);
PPC_FUNC_IMPL(__imp__sub_821CC9A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,115(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 115);
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,100(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r4,115(r3)
	PPC_STORE_U8(ctx.r3.u32 + 115, ctx.r4.u8);
	// addi r9,r10,-12560
	ctx.r9.s64 = ctx.r10.s64 + -12560;
	// lbz r8,73(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 73);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821cca40
	if (ctx.cr6.eq) goto loc_821CCA40;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,1448(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1448);
	// clrlwi r6,r8,31
	ctx.r6.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x821cca40
	if (!ctx.cr6.eq) goto loc_821CCA40;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// li r10,524
	ctx.r10.s64 = 524;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cca1c
	if (!ctx.cr0.eq) goto loc_821CCA1C;
	// twi 31,r0,22
loc_821CCA1C:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r8,r8,-2064
	ctx.r8.s64 = ctx.r8.s64 + -2064;
	// lfs f0,116(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// b 0x821cca84
	goto loc_821CCA84;
loc_821CCA40:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// li r10,524
	ctx.r10.s64 = 524;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cca64
	if (!ctx.cr0.eq) goto loc_821CCA64;
	// twi 31,r0,22
loc_821CCA64:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r8,r8,-2064
	ctx.r8.s64 = ctx.r8.s64 + -2064;
	// lfs f0,124(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r5,r9,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r9.s64;
	// divw. r4,r5,r10
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
loc_821CCA84:
	// bne 0x821cca8c
	if (!ctx.cr0.eq) goto loc_821CCA8C;
	// twi 31,r0,22
loc_821CCA8C:
	// lfs f0,120(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stfs f0,484(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 484, temp.u32);
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// beq cr6,0x821ccacc
	if (ctx.cr6.eq) goto loc_821CCACC;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r8.u8);
	// lwz r11,268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// lwz r7,272(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccac0
	if (!ctx.cr0.eq) goto loc_821CCAC0;
	// twi 31,r0,22
loc_821CCAC0:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
loc_821CCACC:
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r8.u8);
	// lwz r11,268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// lwz r7,272(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccaec
	if (!ctx.cr0.eq) goto loc_821CCAEC;
	// twi 31,r0,22
loc_821CCAEC:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CCAF8"))) PPC_WEAK_FUNC(sub_821CCAF8);
PPC_FUNC_IMPL(__imp__sub_821CCAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,114(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 114);
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,96(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r4,114(r3)
	PPC_STORE_U8(ctx.r3.u32 + 114, ctx.r4.u8);
	// addi r9,r10,-12560
	ctx.r9.s64 = ctx.r10.s64 + -12560;
	// lbz r8,73(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 73);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821ccb90
	if (ctx.cr6.eq) goto loc_821CCB90;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,1448(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1448);
	// clrlwi r6,r8,31
	ctx.r6.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x821ccb90
	if (!ctx.cr6.eq) goto loc_821CCB90;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// li r10,524
	ctx.r10.s64 = 524;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccb6c
	if (!ctx.cr0.eq) goto loc_821CCB6C;
	// twi 31,r0,22
loc_821CCB6C:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r8,r8,-2064
	ctx.r8.s64 = ctx.r8.s64 + -2064;
	// lfs f0,116(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// b 0x821ccbd4
	goto loc_821CCBD4;
loc_821CCB90:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// li r10,524
	ctx.r10.s64 = 524;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccbb4
	if (!ctx.cr0.eq) goto loc_821CCBB4;
	// twi 31,r0,22
loc_821CCBB4:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r8,r8,-2064
	ctx.r8.s64 = ctx.r8.s64 + -2064;
	// lfs f0,124(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r5,r9,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r9.s64;
	// divw. r4,r5,r10
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
loc_821CCBD4:
	// bne 0x821ccbdc
	if (!ctx.cr0.eq) goto loc_821CCBDC;
	// twi 31,r0,22
loc_821CCBDC:
	// lfs f0,120(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stfs f0,484(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 484, temp.u32);
	// lwz r9,96(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// beq cr6,0x821ccc1c
	if (ctx.cr6.eq) goto loc_821CCC1C;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r8.u8);
	// lwz r11,268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// lwz r7,272(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccc10
	if (!ctx.cr0.eq) goto loc_821CCC10;
	// twi 31,r0,22
loc_821CCC10:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
loc_821CCC1C:
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r8.u8);
	// lwz r11,268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// lwz r7,272(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccc3c
	if (!ctx.cr0.eq) goto loc_821CCC3C;
	// twi 31,r0,22
loc_821CCC3C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CCC48"))) PPC_WEAK_FUNC(sub_821CCC48);
PPC_FUNC_IMPL(__imp__sub_821CCC48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,113(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 113);
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,92(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r4,113(r3)
	PPC_STORE_U8(ctx.r3.u32 + 113, ctx.r4.u8);
	// addi r9,r10,-12560
	ctx.r9.s64 = ctx.r10.s64 + -12560;
	// lbz r8,73(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 73);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x821ccce0
	if (ctx.cr6.eq) goto loc_821CCCE0;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r10,-31348(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31348);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r8,1448(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1448);
	// clrlwi r6,r8,31
	ctx.r6.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x821ccce0
	if (!ctx.cr6.eq) goto loc_821CCCE0;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// li r10,524
	ctx.r10.s64 = 524;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cccbc
	if (!ctx.cr0.eq) goto loc_821CCCBC;
	// twi 31,r0,22
loc_821CCCBC:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r8,r8,-2064
	ctx.r8.s64 = ctx.r8.s64 + -2064;
	// lfs f0,116(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r11
	ctx.r6.s64 = ctx.r11.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// b 0x821ccd24
	goto loc_821CCD24;
loc_821CCCE0:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// li r10,524
	ctx.r10.s64 = 524;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r6,r9,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r9.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccd04
	if (!ctx.cr0.eq) goto loc_821CCD04;
	// twi 31,r0,22
loc_821CCD04:
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r8,r8,-2064
	ctx.r8.s64 = ctx.r8.s64 + -2064;
	// lfs f0,124(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 480, temp.u32);
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r5,r9,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r9.s64;
	// divw. r4,r5,r10
	ctx.r4.s32 = ppc_divw(ctx.r5.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
loc_821CCD24:
	// bne 0x821ccd2c
	if (!ctx.cr0.eq) goto loc_821CCD2C;
	// twi 31,r0,22
loc_821CCD2C:
	// lfs f0,120(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stfs f0,484(r9)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 484, temp.u32);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r8,12(r9)
	PPC_STORE_U8(ctx.r9.u32 + 12, ctx.r8.u8);
	// lwz r11,268(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// lwz r7,272(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r10
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r10.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821ccd60
	if (!ctx.cr0.eq) goto loc_821CCD60;
	// twi 31,r0,22
loc_821CCD60:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CCD6C"))) PPC_WEAK_FUNC(sub_821CCD6C);
PPC_FUNC_IMPL(__imp__sub_821CCD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CCD70"))) PPC_WEAK_FUNC(sub_821CCD70);
PPC_FUNC_IMPL(__imp__sub_821CCD70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821CCD78;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r10,r11,-1352
	ctx.r10.s64 = ctx.r11.s64 + -1352;
	// addi r31,r3,124
	ctx.r31.s64 = ctx.r3.s64 + 124;
	// li r30,8
	ctx.r30.s64 = 8;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_821CCD94:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ccdb4
	if (ctx.cr6.eq) goto loc_821CCDB4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CCDB4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CCDB4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ccdd4
	if (ctx.cr6.eq) goto loc_821CCDD4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CCDD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CCDD4:
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ccde4
	if (ctx.cr6.eq) goto loc_821CCDE4;
	// bl 0x82060120
	ctx.lr = 0x821CCDE4;
	sub_82060120(ctx, base);
loc_821CCDE4:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,52
	ctx.r31.s64 = ctx.r31.s64 + 52;
	// bne 0x821ccd94
	if (!ctx.cr0.eq) goto loc_821CCD94;
	// lwz r31,496(r28)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r28.u32 + 496);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821cce58
	if (ctx.cr6.eq) goto loc_821CCE58;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x821CCE08;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cce3c
	if (ctx.cr6.eq) goto loc_821CCE3C;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r31.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// addi r9,r11,5288
	ctx.r9.s64 = ctx.r11.s64 + 5288;
	// stb r29,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r29.u8);
	// addi r8,r10,6640
	ctx.r8.s64 = ctx.r10.s64 + 6640;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r8,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r8.u32);
	// b 0x821cce40
	goto loc_821CCE40;
loc_821CCE3C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CCE40:
	// lwz r8,36(r28)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r28.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// addi r9,r28,16
	ctx.r9.s64 = ctx.r28.s64 + 16;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r28)
	PPC_STORE_U32(ctx.r28.u32 + 36, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
loc_821CCE58:
	// addi r11,r28,492
	ctx.r11.s64 = ctx.r28.s64 + 492;
	// li r30,7
	ctx.r30.s64 = 7;
	// addi r31,r11,4
	ctx.r31.s64 = ctx.r11.s64 + 4;
	// li r27,15
	ctx.r27.s64 = 15;
loc_821CCE68:
	// addi r31,r31,-52
	ctx.r31.s64 = ctx.r31.s64 + -52;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cce80
	if (ctx.cr6.lt) goto loc_821CCE80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x8207a630
	ctx.lr = 0x821CCE80;
	sub_8207A630(ctx, base);
loc_821CCE80:
	// stw r27,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r27.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r29,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stb r29,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r29.u8);
	// bge 0x821cce68
	if (!ctx.cr0.lt) goto loc_821CCE68;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r28,44
	ctx.r3.s64 = ctx.r28.s64 + 44;
	// addi r31,r11,-1408
	ctx.r31.s64 = ctx.r11.s64 + -1408;
	// stw r31,44(r28)
	PPC_STORE_U32(ctx.r28.u32 + 44, ctx.r31.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CCEA8;
	sub_82173A18(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r28,16
	ctx.r3.s64 = ctx.r28.s64 + 16;
	// addi r30,r10,-1456
	ctx.r30.s64 = ctx.r10.s64 + -1456;
	// stw r30,44(r28)
	PPC_STORE_U32(ctx.r28.u32 + 44, ctx.r30.u32);
	// stw r31,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r31.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CCEC0;
	sub_82173A18(ctx, base);
	// stw r30,16(r28)
	PPC_STORE_U32(ctx.r28.u32 + 16, ctx.r30.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CCED0"))) PPC_WEAK_FUNC(sub_821CCED0);
PPC_FUNC_IMPL(__imp__sub_821CCED0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CCED8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,84(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,-1368
	ctx.r10.s64 = ctx.r11.s64 + -1368;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x821ccf04
	if (ctx.cr6.eq) goto loc_821CCF04;
	// bl 0x82060120
	ctx.lr = 0x821CCEFC;
	sub_82060120(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_821CCF04:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// addi r30,r11,-1408
	ctx.r30.s64 = ctx.r11.s64 + -1408;
	// stw r30,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CCF18;
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
	ctx.lr = 0x821CCF30;
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

__attribute__((alias("__imp__sub_821CCF40"))) PPC_WEAK_FUNC(sub_821CCF40);
PPC_FUNC_IMPL(__imp__sub_821CCF40) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c980
	ctx.lr = 0x821CCF48;
	__savegprlr_26(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// li r27,0
	ctx.r27.s64 = 0;
	// li r26,15
	ctx.r26.s64 = 15;
	// stw r27,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r27.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r26,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r26.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r9,-31380(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31380);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stb r27,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r27.u8);
	// addi r10,r9,104
	ctx.r10.s64 = ctx.r9.s64 + 104;
loc_821CCF7C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x821ccfe0
	if (ctx.cr6.eq) goto loc_821CCFE0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,52
	ctx.r10.s64 = ctx.r10.s64 + 52;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// blt cr6,0x821ccf7c
	if (ctx.cr6.lt) goto loc_821CCF7C;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_821CCF9C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82060900
	ctx.lr = 0x821CCFA4;
	sub_82060900(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x821cd0d0
	if (ctx.cr6.eq) goto loc_821CD0D0;
	// lwz r11,20(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 20);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,44(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r27.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// beq cr6,0x821cd060
	if (ctx.cr6.eq) goto loc_821CD060;
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x821ccff0
	if (ctx.cr6.lt) goto loc_821CCFF0;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// b 0x821ccff4
	goto loc_821CCFF4;
loc_821CCFE0:
	// mulli r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 * 52;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r31,116(r11)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r11.u32 + 116);
	// b 0x821ccf9c
	goto loc_821CCF9C;
loc_821CCFF0:
	// addi r5,r28,4
	ctx.r5.s64 = ctx.r28.s64 + 4;
loc_821CCFF4:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82175ae8
	ctx.lr = 0x821CD000;
	sub_82175AE8(ctx, base);
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cd014
	if (ctx.cr6.lt) goto loc_821CD014;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x821cd018
	goto loc_821CD018;
loc_821CD014:
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
loc_821CD018:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821753c8
	ctx.lr = 0x821CD024;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cd0d0
	if (ctx.cr6.eq) goto loc_821CD0D0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821749c8
	ctx.lr = 0x821CD038;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82175150
	ctx.lr = 0x821CD044;
	sub_82175150(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_821CD04C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821cd04c
	if (!ctx.cr6.eq) goto loc_821CD04C;
	// b 0x821cd0bc
	goto loc_821CD0BC;
loc_821CD060:
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x821cd074
	if (ctx.cr6.lt) goto loc_821CD074;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// b 0x821cd078
	goto loc_821CD078;
loc_821CD074:
	// addi r4,r29,4
	ctx.r4.s64 = ctx.r29.s64 + 4;
loc_821CD078:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821753c8
	ctx.lr = 0x821CD084;
	sub_821753C8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cd0d0
	if (ctx.cr6.eq) goto loc_821CD0D0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x821749c8
	ctx.lr = 0x821CD098;
	sub_821749C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82175150
	ctx.lr = 0x821CD0A4;
	sub_82175150(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_821CD0AC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821cd0ac
	if (!ctx.cr6.eq) goto loc_821CD0AC;
loc_821CD0BC:
	// subf r11,r4,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r4.s64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x82060368
	ctx.lr = 0x821CD0D0;
	sub_82060368(ctx, base);
loc_821CD0D0:
	// lwz r11,24(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cd0e4
	if (ctx.cr6.lt) goto loc_821CD0E4;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821CD0E4;
	sub_8207A630(ctx, base);
loc_821CD0E4:
	// stw r26,24(r29)
	PPC_STORE_U32(ctx.r29.u32 + 24, ctx.r26.u32);
	// stw r27,20(r29)
	PPC_STORE_U32(ctx.r29.u32 + 20, ctx.r27.u32);
	// stb r27,4(r29)
	PPC_STORE_U8(ctx.r29.u32 + 4, ctx.r27.u8);
	// lwz r11,24(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x821cd104
	if (ctx.cr6.lt) goto loc_821CD104;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x8207a630
	ctx.lr = 0x821CD104;
	sub_8207A630(ctx, base);
loc_821CD104:
	// stw r26,24(r28)
	PPC_STORE_U32(ctx.r28.u32 + 24, ctx.r26.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r27,20(r28)
	PPC_STORE_U32(ctx.r28.u32 + 20, ctx.r27.u32);
	// stb r27,4(r28)
	PPC_STORE_U8(ctx.r28.u32 + 4, ctx.r27.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8207c9d0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CD11C"))) PPC_WEAK_FUNC(sub_821CD11C);
PPC_FUNC_IMPL(__imp__sub_821CD11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CD120"))) PPC_WEAK_FUNC(sub_821CD120);
PPC_FUNC_IMPL(__imp__sub_821CD120) {
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
	// lwz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821cd258
	if (ctx.cr6.eq) goto loc_821CD258;
	// lbz r11,113(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 113);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cd1bc
	if (ctx.cr6.eq) goto loc_821CD1BC;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21836);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x821cd1b4
	if (!ctx.cr6.lt) goto loc_821CD1B4;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// lfs f12,136(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,120(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x821cd184
	if (!ctx.cr6.gt) goto loc_821CD184;
	// stfs f0,120(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
loc_821CD184:
	// lfs f13,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,252(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 252);
	// lfs f0,184(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r10,16
	ctx.r3.s64 = ctx.r10.s64 + 16;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// rlwinm r8,r9,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF00;
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// or r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 | ctx.r8.u64;
	// bl 0x821796b0
	ctx.lr = 0x821CD1B0;
	sub_821796B0(ctx, base);
	// b 0x821cd258
	goto loc_821CD258;
loc_821CD1B4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821cd258
	if (!ctx.cr6.eq) goto loc_821CD258;
loc_821CD1BC:
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f31,21768(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 21768);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x821cd258
	if (!ctx.cr6.gt) goto loc_821CD258;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// addi r11,r11,-2064
	ctx.r11.s64 = ctx.r11.s64 + -2064;
	// lfs f13,136(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,120(r31)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r31.u32 + 120, temp.u32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x821cd1f0
	if (!ctx.cr6.lt) goto loc_821CD1F0;
	// stfs f31,120(r31)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r31.u32 + 120, temp.u32);
loc_821CD1F0:
	// lfs f13,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,252(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 252);
	// lfs f0,184(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r10,16
	ctx.r3.s64 = ctx.r10.s64 + 16;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// rlwinm r8,r9,0,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF00;
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// or r4,r7,r8
	ctx.r4.u64 = ctx.r7.u64 | ctx.r8.u64;
	// bl 0x821796b0
	ctx.lr = 0x821CD21C;
	sub_821796B0(ctx, base);
	// lfs f10,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r31.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f31
	ctx.cr6.compare(ctx.f10.f64, ctx.f31.f64);
	// bne cr6,0x821cd258
	if (!ctx.cr6.eq) goto loc_821CD258;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,524
	ctx.r8.s64 = 524;
	// stb r9,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r9.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r7,272(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r8
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cd250
	if (!ctx.cr0.eq) goto loc_821CD250;
	// twi 31,r0,22
loc_821CD250:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r10.u8);
loc_821CD258:
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

__attribute__((alias("__imp__sub_821CD270"))) PPC_WEAK_FUNC(sub_821CD270);
PPC_FUNC_IMPL(__imp__sub_821CD270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821CD278;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// li r29,0
	ctx.r29.s64 = 0;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// addi r31,r3,120
	ctx.r31.s64 = ctx.r3.s64 + 120;
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// lfs f31,-21836(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + -21836);
	ctx.f31.f64 = double(temp.f32);
loc_821CD298:
	// lbz r11,-8(r31)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r31.u32 + -8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cd36c
	if (ctx.cr6.eq) goto loc_821CD36C;
	// lwz r11,-12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + -12);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x821cd300
	if (ctx.cr6.eq) goto loc_821CD300;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x821cd2c4
	if (ctx.cr6.eq) goto loc_821CD2C4;
	// stw r29,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// b 0x821cd348
	goto loc_821CD348;
loc_821CD2C4:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x82174590
	ctx.lr = 0x821CD2CC;
	sub_82174590(ctx, base);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82079fd8
	ctx.lr = 0x821CD2D4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd2e4
	if (ctx.cr6.eq) goto loc_821CD2E4;
	// bl 0x8217a960
	ctx.lr = 0x821CD2E0;
	sub_8217A960(ctx, base);
	// b 0x821cd2e8
	goto loc_821CD2E8;
loc_821CD2E4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CD2E8:
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// lwz r4,-4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x8217b6a8
	ctx.lr = 0x821CD2F4;
	sub_8217B6A8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// stb r29,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r29.u8);
	// b 0x821cd330
	goto loc_821CD330;
loc_821CD300:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// bl 0x82174590
	ctx.lr = 0x821CD308;
	sub_82174590(ctx, base);
	// li r3,92
	ctx.r3.s64 = 92;
	// bl 0x82079fd8
	ctx.lr = 0x821CD310;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd328
	if (ctx.cr6.eq) goto loc_821CD328;
	// lwz r4,-4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8216fcf0
	ctx.lr = 0x821CD324;
	sub_8216FCF0(ctx, base);
	// b 0x821cd32c
	goto loc_821CD32C;
loc_821CD328:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CD32C:
	// stw r3,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r3.u32);
loc_821CD330:
	// lwz r30,-4(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + -4);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd348
	if (ctx.cr6.eq) goto loc_821CD348;
	// bl 0x8207a8a0
	ctx.lr = 0x821CD344;
	sub_8207A8A0(ctx, base);
	// stw r29,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r29.u32);
loc_821CD348:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,52
	ctx.r31.s64 = ctx.r31.s64 + 52;
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// blt cr6,0x821cd298
	if (ctx.cr6.lt) goto loc_821CD298;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-14096
	ctx.r9.s64 = ctx.r11.s64 + -14096;
	// stb r10,492(r27)
	PPC_STORE_U8(ctx.r27.u32 + 492, ctx.r10.u8);
	// stw r9,72(r27)
	PPC_STORE_U32(ctx.r27.u32 + 72, ctx.r9.u32);
loc_821CD36C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CD378"))) PPC_WEAK_FUNC(sub_821CD378);
PPC_FUNC_IMPL(__imp__sub_821CD378) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c96c
	ctx.lr = 0x821CD380;
	__savegprlr_21(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// addi r24,r11,-13448
	ctx.r24.s64 = ctx.r11.s64 + -13448;
	// addi r27,r3,16
	ctx.r27.s64 = ctx.r3.s64 + 16;
	// addi r31,r3,108
	ctx.r31.s64 = ctx.r3.s64 + 108;
	// addi r30,r24,32
	ctx.r30.s64 = ctx.r24.s64 + 32;
	// li r25,-1
	ctx.r25.s64 = -1;
	// li r22,15
	ctx.r22.s64 = 15;
	// lis r23,-32224
	ctx.r23.s64 = -2111832064;
	// li r28,0
	ctx.r28.s64 = 0;
loc_821CD3AC:
	// addi r29,r31,-32
	ctx.r29.s64 = ctx.r31.s64 + -32;
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,-32
	ctx.r4.s64 = ctx.r30.s64 + -32;
	// bl 0x820601f8
	ctx.lr = 0x821CD3C4;
	sub_820601F8(ctx, base);
	// lwz r11,-4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -4);
	// stw r22,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r22.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r28.u32);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// stb r28,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r28.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,-4(r31)
	PPC_STORE_U32(ctx.r31.u32 + -4, ctx.r11.u32);
	// addi r29,r31,4
	ctx.r29.s64 = ctx.r31.s64 + 4;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// addi r26,r31,8
	ctx.r26.s64 = ctx.r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lbz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r30.u32 + 4);
	// stb r9,4(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4, ctx.r9.u8);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// stw r8,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// stw r7,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r7.u32);
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// stw r11,16(r31)
	PPC_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bl 0x820601f8
	ctx.lr = 0x821CD41C;
	sub_820601F8(ctx, base);
	// lwz r11,-31352(r23)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + -31352);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82194df8
	ctx.lr = 0x821CD440;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821CD444;
	sub_82193870(ctx, base);
	// lwz r10,20(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 20);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r30,r30,52
	ctx.r30.s64 = ctx.r30.s64 + 52;
	// addi r9,r24,448
	ctx.r9.s64 = ctx.r24.s64 + 448;
	// addi r31,r31,52
	ctx.r31.s64 = ctx.r31.s64 + 52;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// cmpw cr6,r30,r9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r9.s32, ctx.xer);
	// stw r11,20(r27)
	PPC_STORE_U32(ctx.r27.u32 + 20, ctx.r11.u32);
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r28.u32);
	// blt cr6,0x821cd3ac
	if (ctx.cr6.lt) goto loc_821CD3AC;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,496(r21)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r21.u32 + 496);
	// bl 0x821ccc48
	ctx.lr = 0x821CD478;
	sub_821CCC48(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-11664
	ctx.r10.s64 = ctx.r11.s64 + -11664;
	// stw r10,72(r21)
	PPC_STORE_U32(ctx.r21.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8207c9bc
	__restgprlr_21(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CD48C"))) PPC_WEAK_FUNC(sub_821CD48C);
PPC_FUNC_IMPL(__imp__sub_821CD48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CD490"))) PPC_WEAK_FUNC(sub_821CD490);
PPC_FUNC_IMPL(__imp__sub_821CD490) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,496(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// lbz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 112);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-11400
	ctx.r10.s64 = ctx.r11.s64 + -11400;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CD4B0"))) PPC_WEAK_FUNC(sub_821CD4B0);
PPC_FUNC_IMPL(__imp__sub_821CD4B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c978
	ctx.lr = 0x821CD4B8;
	__savegprlr_24(ctx, base);
	// stfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f29.u64);
	// stfd f30,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x821CD4D4;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// beq cr6,0x821cd514
	if (ctx.cr6.eq) goto loc_821CD514;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r29,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r29.u8);
	// addi r9,r10,5300
	ctx.r9.s64 = ctx.r10.s64 + 5300;
	// stb r29,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r29.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r29,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r29.u8);
	// stw r29,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r29.u32);
	// stb r29,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r29.u8);
	// b 0x821cd518
	goto loc_821CD518;
loc_821CD514:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CD518:
	// stw r11,76(r31)
	PPC_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82079fd8
	ctx.lr = 0x821CD524;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r24,r11,-2064
	ctx.r24.s64 = ctx.r11.s64 + -2064;
	// beq cr6,0x821cd5a8
	if (ctx.cr6.eq) goto loc_821CD5A8;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stb r29,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r29.u8);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stb r29,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r29.u8);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r29,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r29.u8);
	// addi r7,r10,5312
	ctx.r7.s64 = ctx.r10.s64 + 5312;
	// stw r29,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r29.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lfs f12,56(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lfs f0,21768(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
	// stb r29,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r29.u8);
	// stfs f0,28(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f13,-21836(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21836);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f12,64(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f12,68(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// b 0x821cd5ac
	goto loc_821CD5AC;
loc_821CD5A8:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CD5AC:
	// stw r11,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82079fd8
	ctx.lr = 0x821CD5B8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd5c8
	if (ctx.cr6.eq) goto loc_821CD5C8;
	// bl 0x8217a960
	ctx.lr = 0x821CD5C4;
	sub_8217A960(ctx, base);
	// b 0x821cd5cc
	goto loc_821CD5CC;
loc_821CD5C8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CD5CC:
	// stw r3,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r3.u32);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x8217b6a8
	ctx.lr = 0x821CD5D8;
	sub_8217B6A8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// li r3,556
	ctx.r3.s64 = 556;
	// stb r29,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r29.u8);
	// bl 0x82079fd8
	ctx.lr = 0x821CD5E8;
	sub_82079FD8(ctx, base);
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r27,r11,-2612
	ctx.r27.s64 = ctx.r11.s64 + -2612;
	// beq cr6,0x821cd620
	if (ctx.cr6.eq) goto loc_821CD620;
	// addi r4,r27,-68
	ctx.r4.s64 = ctx.r27.s64 + -68;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821CD608;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821CD618;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cd624
	goto loc_821CD624;
loc_821CD620:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CD624:
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// addi r4,r27,-60
	ctx.r4.s64 = ctx.r27.s64 + -60;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821CD638;
	sub_8217C468(ctx, base);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// li r25,1
	ctx.r25.s64 = 1;
	// li r30,524
	ctx.r30.s64 = 524;
	// stb r25,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r25.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r9,272(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821cd660
	if (!ctx.cr0.eq) goto loc_821CD660;
	// twi 31,r0,22
loc_821CD660:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r29,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r29.u8);
	// lfs f30,124(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 124);
	ctx.f30.f64 = double(temp.f32);
	// addi r26,r10,-12560
	ctx.r26.s64 = ctx.r10.s64 + -12560;
	// lfs f29,116(r24)
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 116);
	ctx.f29.f64 = double(temp.f32);
	// lbz r11,73(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 73);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x821cd6bc
	if (ctx.cr6.eq) goto loc_821CD6BC;
	// bne 0x821cd6a4
	if (!ctx.cr0.eq) goto loc_821CD6A4;
	// twi 31,r0,22
loc_821CD6A4:
	// stfs f29,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// b 0x821cd6d8
	goto loc_821CD6D8;
loc_821CD6BC:
	// bne 0x821cd6c4
	if (!ctx.cr0.eq) goto loc_821CD6C4;
	// twi 31,r0,22
loc_821CD6C4:
	// stfs f30,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
loc_821CD6D8:
	// bne 0x821cd6e0
	if (!ctx.cr0.eq) goto loc_821CD6E0;
	// twi 31,r0,22
loc_821CD6E0:
	// lfs f31,120(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 120);
	ctx.f31.f64 = double(temp.f32);
	// li r3,556
	ctx.r3.s64 = 556;
	// stfs f31,484(r10)
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CD70C;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd73c
	if (ctx.cr6.eq) goto loc_821CD73C;
	// addi r4,r27,-48
	ctx.r4.s64 = ctx.r27.s64 + -48;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821CD724;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821CD734;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cd740
	goto loc_821CD740;
loc_821CD73C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CD740:
	// stw r11,96(r31)
	PPC_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// addi r4,r27,-36
	ctx.r4.s64 = ctx.r27.s64 + -36;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821CD754;
	sub_8217C468(ctx, base);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// stb r25,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r25.u8);
	// lwz r9,272(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821cd774
	if (!ctx.cr0.eq) goto loc_821CD774;
	// twi 31,r0,22
loc_821CD774:
	// stb r29,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r29.u8);
	// lbz r11,73(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 73);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x821cd7c0
	if (ctx.cr6.eq) goto loc_821CD7C0;
	// bne 0x821cd7a8
	if (!ctx.cr0.eq) goto loc_821CD7A8;
	// twi 31,r0,22
loc_821CD7A8:
	// stfs f29,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// b 0x821cd7dc
	goto loc_821CD7DC;
loc_821CD7C0:
	// bne 0x821cd7c8
	if (!ctx.cr0.eq) goto loc_821CD7C8;
	// twi 31,r0,22
loc_821CD7C8:
	// stfs f30,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
loc_821CD7DC:
	// bne 0x821cd7e4
	if (!ctx.cr0.eq) goto loc_821CD7E4;
	// twi 31,r0,22
loc_821CD7E4:
	// stfs f31,484(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// li r3,556
	ctx.r3.s64 = 556;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,96(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 96);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CD80C;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd83c
	if (ctx.cr6.eq) goto loc_821CD83C;
	// addi r4,r27,-28
	ctx.r4.s64 = ctx.r27.s64 + -28;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821CD824;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821CD834;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cd840
	goto loc_821CD840;
loc_821CD83C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CD840:
	// stw r11,100(r31)
	PPC_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// addi r4,r27,-16
	ctx.r4.s64 = ctx.r27.s64 + -16;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821CD854;
	sub_8217C468(ctx, base);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// stb r25,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r25.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r9,272(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821cd874
	if (!ctx.cr0.eq) goto loc_821CD874;
	// twi 31,r0,22
loc_821CD874:
	// stb r29,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r29.u8);
	// lbz r11,73(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 73);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x821cd8c0
	if (ctx.cr6.eq) goto loc_821CD8C0;
	// bne 0x821cd8a8
	if (!ctx.cr0.eq) goto loc_821CD8A8;
	// twi 31,r0,22
loc_821CD8A8:
	// stfs f29,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// b 0x821cd8dc
	goto loc_821CD8DC;
loc_821CD8C0:
	// bne 0x821cd8c8
	if (!ctx.cr0.eq) goto loc_821CD8C8;
	// twi 31,r0,22
loc_821CD8C8:
	// stfs f30,480(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r9,r10,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r10.s64;
	// divw. r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
loc_821CD8DC:
	// bne 0x821cd8e4
	if (!ctx.cr0.eq) goto loc_821CD8E4;
	// twi 31,r0,22
loc_821CD8E4:
	// stfs f31,484(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 484, temp.u32);
	// li r3,556
	ctx.r3.s64 = 556;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,100(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 100);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CD90C;
	sub_82079FD8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cd93c
	if (ctx.cr6.eq) goto loc_821CD93C;
	// addi r4,r27,-8
	ctx.r4.s64 = ctx.r27.s64 + -8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060190
	ctx.lr = 0x821CD924;
	sub_82060190(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x8217aa80
	ctx.lr = 0x821CD934;
	sub_8217AA80(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821cd940
	goto loc_821CD940;
loc_821CD93C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_821CD940:
	// stw r11,104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// bl 0x8217c468
	ctx.lr = 0x821CD954;
	sub_8217C468(ctx, base);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// stb r25,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r25.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r9,272(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821cd974
	if (!ctx.cr0.eq) goto loc_821CD974;
	// twi 31,r0,22
loc_821CD974:
	// stb r29,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r29.u8);
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// addi r11,r11,240
	ctx.r11.s64 = ctx.r11.s64 + 240;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// divw. r7,r8,r30
	ctx.r7.s32 = ppc_divw(ctx.r8.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne 0x821cd99c
	if (!ctx.cr0.eq) goto loc_821CD99C;
	// twi 31,r0,22
loc_821CD99C:
	// lfs f0,396(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 396);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,480(r10)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 480, temp.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,12(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// divw. r8,r9,r30
	ctx.r8.s32 = ppc_divw(ctx.r9.s32, ctx.r30.s32);
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne 0x821cd9bc
	if (!ctx.cr0.eq) goto loc_821CD9BC;
	// twi 31,r0,22
loc_821CD9BC:
	// lfs f0,400(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r24.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,484(r11)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r11.u32 + 484, temp.u32);
	// addi r11,r31,44
	ctx.r11.s64 = ctx.r31.s64 + 44;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r11,104(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 104);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// lwz r11,88(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 88);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// stw r10,20(r7)
	PPC_STORE_U32(ctx.r7.u32 + 20, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// lwz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r4,20(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// stw r10,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// lwz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r29,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// stb r25,112(r31)
	PPC_STORE_U8(ctx.r31.u32 + 112, ctx.r25.u8);
	// bl 0x8210e878
	ctx.lr = 0x821CDA3C;
	sub_8210E878(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-12000
	ctx.r10.s64 = ctx.r11.s64 + -12000;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f30,-88(r1)
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x8207c9c8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CDA5C"))) PPC_WEAK_FUNC(sub_821CDA5C);
PPC_FUNC_IMPL(__imp__sub_821CDA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CDA60"))) PPC_WEAK_FUNC(sub_821CDA60);
PPC_FUNC_IMPL(__imp__sub_821CDA60) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r30,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// li r5,25
	ctx.r5.s64 = 25;
	// addi r4,r10,-2708
	ctx.r4.s64 = ctx.r10.s64 + -2708;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82060368
	ctx.lr = 0x821CDAA0;
	sub_82060368(ctx, base);
	// lis r5,-32224
	ctx.r5.s64 = -2111832064;
	// lis r9,64
	ctx.r9.s64 = 4194304;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,-31352(r5)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -31352);
	// addi r5,r31,84
	ctx.r5.s64 = ctx.r31.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x82194df8
	ctx.lr = 0x821CDAC8;
	sub_82194DF8(ctx, base);
	// bl 0x82193870
	ctx.lr = 0x821CDACC;
	sub_82193870(ctx, base);
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,-11088
	ctx.r9.s64 = ctx.r10.s64 + -11088;
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

__attribute__((alias("__imp__sub_821CDB08"))) PPC_WEAK_FUNC(sub_821CDB08);
PPC_FUNC_IMPL(__imp__sub_821CDB08) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-9632
	ctx.r10.s64 = ctx.r11.s64 + -9632;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CDB18"))) PPC_WEAK_FUNC(sub_821CDB18);
PPC_FUNC_IMPL(__imp__sub_821CDB18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r8,r8,-1396
	ctx.r8.s64 = ctx.r8.s64 + -1396;
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
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// lis r4,-32227
	ctx.r4.s64 = -2112028672;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r11.u8);
	// addi r7,r7,840
	ctx.r7.s64 = ctx.r7.s64 + 840;
	// stb r11,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r11.u8);
	// addi r10,r9,16
	ctx.r10.s64 = ctx.r9.s64 + 16;
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r11.u32);
	// addi r5,r5,-1368
	ctx.r5.s64 = ctx.r5.s64 + -1368;
	// stb r11,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r11.u8);
	// addi r4,r4,-9464
	ctx.r4.s64 = ctx.r4.s64 + -9464;
	// stw r7,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r7.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// lfs f0,21768(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 21768);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f0,120(r3)
	temp.f32 = float(ctx.f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stb r11,112(r3)
	PPC_STORE_U8(ctx.r3.u32 + 112, ctx.r11.u8);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r11.u32);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r11.u32);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r11.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r11.u32);
	// stb r11,113(r3)
	PPC_STORE_U8(ctx.r3.u32 + 113, ctx.r11.u8);
	// stb r11,114(r3)
	PPC_STORE_U8(ctx.r3.u32 + 114, ctx.r11.u8);
	// stb r11,115(r3)
	PPC_STORE_U8(ctx.r3.u32 + 115, ctx.r11.u8);
	// stb r11,116(r3)
	PPC_STORE_U8(ctx.r3.u32 + 116, ctx.r11.u8);
	// stb r11,117(r3)
	PPC_STORE_U8(ctx.r3.u32 + 117, ctx.r11.u8);
	// stw r4,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CDBE8"))) PPC_WEAK_FUNC(sub_821CDBE8);
PPC_FUNC_IMPL(__imp__sub_821CDBE8) {
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
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r11.u32);
	// addi r8,r9,-1396
	ctx.r8.s64 = ctx.r9.s64 + -1396;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r30.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stb r30,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r30.u8);
	// li r9,8
	ctx.r9.s64 = 8;
	// stb r30,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r30.u8);
	// stb r30,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r30.u8);
	// addi r5,r7,840
	ctx.r5.s64 = ctx.r7.s64 + 840;
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r30,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r30.u8);
	// addi r4,r6,-1352
	ctx.r4.s64 = ctx.r6.s64 + -1352;
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r11.u32);
	// addi r11,r3,76
	ctx.r11.s64 = ctx.r3.s64 + 76;
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r30.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stb r30,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, ctx.r30.u8);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stb r30,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r30.u8);
	// li r10,15
	ctx.r10.s64 = 15;
	// stb r30,59(r3)
	PPC_STORE_U8(ctx.r3.u32 + 59, ctx.r30.u8);
	// stw r30,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r30.u32);
	// stb r30,58(r3)
	PPC_STORE_U8(ctx.r3.u32 + 58, ctx.r30.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// stb r8,57(r3)
	PPC_STORE_U8(ctx.r3.u32 + 57, ctx.r8.u8);
loc_821CDC98:
	// stw r10,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// stw r30,16(r11)
	PPC_STORE_U32(ctx.r11.u32 + 16, ctx.r30.u32);
	// stb r30,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// addi r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 + 52;
	// bdnz 0x821cdc98
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_821CDC98;
	// stb r30,492(r31)
	PPC_STORE_U8(ctx.r31.u32 + 492, ctx.r30.u8);
	// li r3,124
	ctx.r3.s64 = 124;
	// bl 0x82079fd8
	ctx.lr = 0x821CDCB8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cdcc8
	if (ctx.cr6.eq) goto loc_821CDCC8;
	// bl 0x821cdb18
	ctx.lr = 0x821CDCC4;
	sub_821CDB18(ctx, base);
	// b 0x821cdccc
	goto loc_821CDCCC;
loc_821CDCC8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_821CDCCC:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r3,496(r31)
	PPC_STORE_U32(ctx.r31.u32 + 496, ctx.r3.u32);
	// lwz r11,-31324(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cdd04
	if (ctx.cr6.eq) goto loc_821CDD04;
	// lwz r11,16(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821cdd04
	if (ctx.cr6.eq) goto loc_821CDD04;
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 64);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// addi r9,r11,44
	ctx.r9.s64 = ctx.r11.s64 + 44;
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// stw r10,64(r11)
	PPC_STORE_U32(ctx.r11.u32 + 64, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
loc_821CDD04:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r10,r11,-11120
	ctx.r10.s64 = ctx.r11.s64 + -11120;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_821CDD2C"))) PPC_WEAK_FUNC(sub_821CDD2C);
PPC_FUNC_IMPL(__imp__sub_821CDD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CDD30"))) PPC_WEAK_FUNC(sub_821CDD30);
PPC_FUNC_IMPL(__imp__sub_821CDD30) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r11,-7168
	ctx.r8.s64 = ctx.r11.s64 + -7168;
	// stw r10,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r10.u32);
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// stw r8,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821CDD50"))) PPC_WEAK_FUNC(sub_821CDD50);
PPC_FUNC_IMPL(__imp__sub_821CDD50) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,72(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_821CDD5C"))) PPC_WEAK_FUNC(sub_821CDD5C);
PPC_FUNC_IMPL(__imp__sub_821CDD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CDD60"))) PPC_WEAK_FUNC(sub_821CDD60);
PPC_FUNC_IMPL(__imp__sub_821CDD60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c984
	ctx.lr = 0x821CDD68;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lis r28,-32224
	ctx.r28.s64 = -2111832064;
	// addi r10,r11,-1384
	ctx.r10.s64 = ctx.r11.s64 + -1384;
	// addi r31,r3,44
	ctx.r31.s64 = ctx.r3.s64 + 44;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,-31380(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31380);
	// bl 0x82173a70
	ctx.lr = 0x821CDD90;
	sub_82173A70(ctx, base);
	// addi r29,r30,16
	ctx.r29.s64 = ctx.r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82173a18
	ctx.lr = 0x821CDD9C;
	sub_82173A18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82173a18
	ctx.lr = 0x821CDDA4;
	sub_82173A18(ctx, base);
	// lwz r3,-31380(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + -31380);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cddc4
	if (ctx.cr6.eq) goto loc_821CDDC4;
	// lwz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821CDDC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_821CDDC4:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r28,r11,-1408
	ctx.r28.s64 = ctx.r11.s64 + -1408;
	// stw r28,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CDDD8;
	sub_82173A18(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r27,r10,-1456
	ctx.r27.s64 = ctx.r10.s64 + -1456;
	// stw r27,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r27.u32);
	// stw r28,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
	// bl 0x82173a18
	ctx.lr = 0x821CDDF0;
	sub_82173A18(ctx, base);
	// stw r27,0(r29)
	PPC_STORE_U32(ctx.r29.u32 + 0, ctx.r27.u32);
	// stw r27,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CDE00"))) PPC_WEAK_FUNC(sub_821CDE00);
PPC_FUNC_IMPL(__imp__sub_821CDE00) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821CDE08;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// bl 0x82173d88
	ctx.lr = 0x821CDE18;
	sub_82173D88(ctx, base);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r10,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// lwz r3,-31352(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31352);
	// bl 0x82189a70
	ctx.lr = 0x821CDE40;
	sub_82189A70(ctx, base);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,-31380(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + -31380);
	// lwz r3,496(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 496);
	// bl 0x821ccc48
	ctx.lr = 0x821CDE54;
	sub_821CCC48(ctx, base);
	// lwz r11,496(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 496);
	// lbz r6,116(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 116);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x821cde9c
	if (ctx.cr6.eq) goto loc_821CDE9C;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821cde9c
	if (ctx.cr6.eq) goto loc_821CDE9C;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r29,116(r11)
	PPC_STORE_U8(ctx.r11.u32 + 116, ctx.r29.u8);
	// li r8,524
	ctx.r8.s64 = 524;
	// stb r9,12(r10)
	PPC_STORE_U8(ctx.r10.u32 + 12, ctx.r9.u8);
	// lwz r11,268(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 268);
	// lwz r7,272(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// divw. r5,r6,r8
	ctx.r5.s32 = ppc_divw(ctx.r6.s32, ctx.r8.s32);
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne 0x821cde98
	if (!ctx.cr0.eq) goto loc_821CDE98;
	// twi 31,r0,22
loc_821CDE98:
	// stb r29,477(r11)
	PPC_STORE_U8(ctx.r11.u32 + 477, ctx.r29.u8);
loc_821CDE9C:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x821CDEA4;
	sub_82079FD8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821cdf04
	if (ctx.cr6.eq) goto loc_821CDF04;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-20285
	ctx.r4.s64 = ctx.r11.s64 + -20285;
	// bl 0x82060190
	ctx.lr = 0x821CDEC0;
	sub_82060190(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,-2276
	ctx.r4.s64 = ctx.r10.s64 + -2276;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821CDED4;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CDEE4;
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
	ctx.lr = 0x821CDF00;
	sub_821BD670(ctx, base);
	// b 0x821cdf08
	goto loc_821CDF08;
loc_821CDF04:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CDF08:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r9,-8912
	ctx.r8.s64 = ctx.r9.s64 + -8912;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r8,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CDF30"))) PPC_WEAK_FUNC(sub_821CDF30);
PPC_FUNC_IMPL(__imp__sub_821CDF30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821CDF38;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,92(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// bl 0x82173d88
	ctx.lr = 0x821CDF48;
	sub_82173D88(ctx, base);
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lwz r8,36(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// lwz r3,-31352(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -31352);
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r10.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// lwz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r31,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r31.u32);
	// stw r31,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r31.u32);
	// lwz r11,84(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r31,68(r11)
	PPC_STORE_U32(ctx.r11.u32 + 68, ctx.r31.u32);
	// stw r31,72(r11)
	PPC_STORE_U32(ctx.r11.u32 + 72, ctx.r31.u32);
	// stw r31,76(r11)
	PPC_STORE_U32(ctx.r11.u32 + 76, ctx.r31.u32);
	// stw r31,52(r11)
	PPC_STORE_U32(ctx.r11.u32 + 52, ctx.r31.u32);
	// lwz r6,20(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r6,1
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 1, ctx.xer);
	// beq cr6,0x821cdfa4
	if (ctx.cr6.eq) goto loc_821CDFA4;
	// stw r28,20(r11)
	PPC_STORE_U32(ctx.r11.u32 + 20, ctx.r28.u32);
loc_821CDFA4:
	// bl 0x82189a70
	ctx.lr = 0x821CDFA8;
	sub_82189A70(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,-31380(r11)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31380);
	// lwz r3,496(r29)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r29.u32 + 496);
	// bl 0x821ccc48
	ctx.lr = 0x821CDFBC;
	sub_821CCC48(ctx, base);
	// lwz r10,496(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 496);
	// lbz r9,116(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 116);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x821ce000
	if (ctx.cr6.eq) goto loc_821CE000;
	// lwz r11,104(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ce000
	if (ctx.cr6.eq) goto loc_821CE000;
	// stb r31,116(r10)
	PPC_STORE_U8(ctx.r10.u32 + 116, ctx.r31.u8);
	// li r9,524
	ctx.r9.s64 = 524;
	// stb r28,12(r11)
	PPC_STORE_U8(ctx.r11.u32 + 12, ctx.r28.u8);
	// lwz r10,268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 268);
	// lwz r8,272(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
	// divw. r6,r7,r9
	ctx.r6.s32 = ppc_divw(ctx.r7.s32, ctx.r9.s32);
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne 0x821cdffc
	if (!ctx.cr0.eq) goto loc_821CDFFC;
	// twi 31,r0,22
loc_821CDFFC:
	// stb r31,477(r10)
	PPC_STORE_U8(ctx.r10.u32 + 477, ctx.r31.u8);
loc_821CE000:
	// li r3,264
	ctx.r3.s64 = 264;
	// bl 0x82079fd8
	ctx.lr = 0x821CE008;
	sub_82079FD8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce068
	if (ctx.cr6.eq) goto loc_821CE068;
	// lis r11,-32252
	ctx.r11.s64 = -2113667072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-20286
	ctx.r4.s64 = ctx.r11.s64 + -20286;
	// bl 0x82060190
	ctx.lr = 0x821CE024;
	sub_82060190(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r10,-2292
	ctx.r4.s64 = ctx.r10.s64 + -2292;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82060190
	ctx.lr = 0x821CE038;
	sub_82060190(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x821ccf40
	ctx.lr = 0x821CE048;
	sub_821CCF40(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x821bd670
	ctx.lr = 0x821CE064;
	sub_821BD670(ctx, base);
	// b 0x821ce06c
	goto loc_821CE06C;
loc_821CE068:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821CE06C:
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r8,r9,-8912
	ctx.r8.s64 = ctx.r9.s64 + -8912;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r8,72(r30)
	PPC_STORE_U32(ctx.r30.u32 + 72, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CE094"))) PPC_WEAK_FUNC(sub_821CE094);
PPC_FUNC_IMPL(__imp__sub_821CE094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE098"))) PPC_WEAK_FUNC(sub_821CE098);
PPC_FUNC_IMPL(__imp__sub_821CE098) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c988
	ctx.lr = 0x821CE0A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,80(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r28,r3,80
	ctx.r28.s64 = ctx.r3.s64 + 80;
	// addi r10,r11,-1
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r10,5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 5, ctx.xer);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r11.u32);
	// bgt cr6,0x821ce3e8
	if (ctx.cr6.gt) goto loc_821CE3E8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x821ce144
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821CE144;
	// bdzf 4*cr6+eq,0x821ce198
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821CE198;
	// bdzf 4*cr6+eq,0x821ce1f4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821CE1F4;
	// bdzf 4*cr6+eq,0x821ce308
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_821CE308;
	// bne cr6,0x821ce39c
	if (!ctx.cr6.eq) goto loc_821CE39C;
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lwz r11,-31376(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821ce128
	if (!ctx.cr6.eq) goto loc_821CE128;
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82079fd8
	ctx.lr = 0x821CE0F4;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce108
	if (ctx.cr6.eq) goto loc_821CE108;
	// bl 0x821cb4f8
	ctx.lr = 0x821CE104;
	sub_821CB4F8(ctx, base);
	// b 0x821ce10c
	goto loc_821CE10C;
loc_821CE108:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE10C:
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,-31376(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31376, ctx.r3.u32);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
loc_821CE128:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-7168
	ctx.r10.s64 = ctx.r11.s64 + -7168;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821CE144:
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82079fd8
	ctx.lr = 0x821CE14C;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce160
	if (ctx.cr6.eq) goto loc_821CE160;
	// bl 0x821d1bf8
	ctx.lr = 0x821CE15C;
	sub_821D1BF8(ctx, base);
	// b 0x821ce164
	goto loc_821CE164;
loc_821CE160:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE164:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// addi r10,r11,-7168
	ctx.r10.s64 = ctx.r11.s64 + -7168;
	// stw r8,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r8.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821CE198:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r11,-31376(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ce1b4
	if (ctx.cr6.eq) goto loc_821CE1B4;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82182a68
	ctx.lr = 0x821CE1B4;
	sub_82182A68(ctx, base);
loc_821CE1B4:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,-31352(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// bl 0x82189a70
	ctx.lr = 0x821CE1C0;
	sub_82189A70(ctx, base);
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x82188eb8
	ctx.lr = 0x821CE1C8;
	sub_82188EB8(ctx, base);
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82079fd8
	ctx.lr = 0x821CE1D0;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce1e8
	if (ctx.cr6.eq) goto loc_821CE1E8;
	// bl 0x821cc850
	ctx.lr = 0x821CE1E0;
	sub_821CC850(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// b 0x821ce3cc
	goto loc_821CE3CC;
loc_821CE1E8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// b 0x821ce3cc
	goto loc_821CE3CC;
loc_821CE1F4:
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// lwz r11,-31376(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ce210
	if (ctx.cr6.eq) goto loc_821CE210;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82182a68
	ctx.lr = 0x821CE210;
	sub_82182A68(ctx, base);
loc_821CE210:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r3,-31352(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31352);
	// bl 0x8218a028
	ctx.lr = 0x821CE21C;
	sub_8218A028(ctx, base);
	// lwz r11,-31376(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31376);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x821ce264
	if (!ctx.cr6.eq) goto loc_821CE264;
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82079fd8
	ctx.lr = 0x821CE234;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce244
	if (ctx.cr6.eq) goto loc_821CE244;
	// bl 0x821cb4f8
	ctx.lr = 0x821CE240;
	sub_821CB4F8(ctx, base);
	// b 0x821ce248
	goto loc_821CE248;
loc_821CE244:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE248:
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r3,-31376(r30)
	PPC_STORE_U32(ctx.r30.u32 + -31376, ctx.r3.u32);
	// addi r10,r31,44
	ctx.r10.s64 = ctx.r31.s64 + 44;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
loc_821CE264:
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82079fd8
	ctx.lr = 0x821CE26C;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce27c
	if (ctx.cr6.eq) goto loc_821CE27C;
	// bl 0x82189ec0
	ctx.lr = 0x821CE278;
	sub_82189EC0(ctx, base);
	// b 0x821ce280
	goto loc_821CE280;
loc_821CE27C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE280:
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// lis r30,-32224
	ctx.r30.s64 = -2111832064;
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwz r11,-31364(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31364);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// lwz r8,272(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 272);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x821ce2b8
	if (ctx.cr6.eq) goto loc_821CE2B8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821ca108
	ctx.lr = 0x821CE2B4;
	sub_821CA108(ctx, base);
	// lwz r11,-31364(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31364);
loc_821CE2B8:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r11,r11,272
	ctx.r11.s64 = ctx.r11.s64 + 272;
loc_821CE2C0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821ce2dc
	if (ctx.cr6.eq) goto loc_821CE2DC;
	// addic. r3,r3,1
	ctx.xer.ca = ctx.r3.u32 > 4294967294;
	ctx.r3.s64 = ctx.r3.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// ble 0x821ce2c0
	if (!ctx.cr0.gt) goto loc_821CE2C0;
	// li r3,0
	ctx.r3.s64 = 0;
loc_821CE2DC:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82188f90
	ctx.lr = 0x821CE2E4;
	sub_82188F90(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x821ce3f4
	if (ctx.cr6.eq) goto loc_821CE3F4;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-7168
	ctx.r10.s64 = ctx.r11.s64 + -7168;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821CE308:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r11,-31364(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31364);
	// addi r11,r11,272
	ctx.r11.s64 = ctx.r11.s64 + 272;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x821ce34c
	if (!ctx.cr6.eq) goto loc_821CE34C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE328:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x821ce344
	if (ctx.cr6.eq) goto loc_821CE344;
	// addic. r3,r3,1
	ctx.xer.ca = ctx.r3.u32 > 4294967294;
	ctx.r3.s64 = ctx.r3.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// addi r11,r11,28
	ctx.r11.s64 = ctx.r11.s64 + 28;
	// ble 0x821ce328
	if (!ctx.cr0.gt) goto loc_821CE328;
	// li r3,0
	ctx.r3.s64 = 0;
loc_821CE344:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82188f90
	ctx.lr = 0x821CE34C;
	sub_82188F90(ctx, base);
loc_821CE34C:
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82079fd8
	ctx.lr = 0x821CE354;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce36c
	if (ctx.cr6.eq) goto loc_821CE36C;
	// addi r5,r31,84
	ctx.r5.s64 = ctx.r31.s64 + 84;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x821b80d0
	ctx.lr = 0x821CE368;
	sub_821B80D0(ctx, base);
	// b 0x821ce370
	goto loc_821CE370;
loc_821CE36C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE370:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// addi r10,r11,-7168
	ctx.r10.s64 = ctx.r11.s64 + -7168;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
loc_821CE39C:
	// li r3,120
	ctx.r3.s64 = 120;
	// bl 0x82188eb8
	ctx.lr = 0x821CE3A4;
	sub_82188EB8(ctx, base);
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82079fd8
	ctx.lr = 0x821CE3AC;
	sub_82079FD8(ctx, base);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce3c4
	if (ctx.cr6.eq) goto loc_821CE3C4;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x821c3f38
	ctx.lr = 0x821CE3C0;
	sub_821C3F38(ctx, base);
	// b 0x821ce3c8
	goto loc_821CE3C8;
loc_821CE3C4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_821CE3C8:
	// li r9,5
	ctx.r9.s64 = 5;
loc_821CE3CC:
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// stw r9,0(r28)
	PPC_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
loc_821CE3E8:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-7168
	ctx.r10.s64 = ctx.r11.s64 + -7168;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821CE3F4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8207c9d8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CE3FC"))) PPC_WEAK_FUNC(sub_821CE3FC);
PPC_FUNC_IMPL(__imp__sub_821CE3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE400"))) PPC_WEAK_FUNC(sub_821CE400);
PPC_FUNC_IMPL(__imp__sub_821CE400) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-31352(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// lwz r11,104(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x821ce438
	if (ctx.cr6.eq) goto loc_821CE438;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-8400
	ctx.r10.s64 = ctx.r11.s64 + -8400;
	// b 0x821ce49c
	goto loc_821CE49C;
loc_821CE438:
	// bl 0x82189740
	ctx.lr = 0x821CE43C;
	sub_82189740(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x821ce454
	if (ctx.cr6.eq) goto loc_821CE454;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-8704
	ctx.r10.s64 = ctx.r11.s64 + -8704;
	// b 0x821ce49c
	goto loc_821CE49C;
loc_821CE454:
	// lwz r11,92(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x821ce4a0
	if (!ctx.cr6.eq) goto loc_821CE4A0;
	// lwz r11,80(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 76);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x821ce4a0
	if (ctx.cr6.eq) goto loc_821CE4A0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x821ce488
	if (ctx.cr6.lt) goto loc_821CE488;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// ble cr6,0x821ce48c
	if (!ctx.cr6.gt) goto loc_821CE48C;
loc_821CE488:
	// li r10,0
	ctx.r10.s64 = 0;
loc_821CE48C:
	// lwz r11,-31352(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -31352);
	// stw r10,100(r11)
	PPC_STORE_U32(ctx.r11.u32 + 100, ctx.r10.u32);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-8040
	ctx.r10.s64 = ctx.r11.s64 + -8040;
loc_821CE49C:
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821CE4A0:
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

__attribute__((alias("__imp__sub_821CE4B8"))) PPC_WEAK_FUNC(sub_821CE4B8);
PPC_FUNC_IMPL(__imp__sub_821CE4B8) {
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
	// lwz r11,-31380(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -31380);
	// lbz r10,492(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 492);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x821ce510
	if (ctx.cr6.eq) goto loc_821CE510;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r10,-31352(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -31352);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x821ce510
	if (ctx.cr6.eq) goto loc_821CE510;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,496(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 496);
	// bl 0x821ccc48
	ctx.lr = 0x821CE504;
	sub_821CCC48(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-7168
	ctx.r10.s64 = ctx.r11.s64 + -7168;
	// stw r10,72(r31)
	PPC_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
loc_821CE510:
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

__attribute__((alias("__imp__sub_821CE524"))) PPC_WEAK_FUNC(sub_821CE524);
PPC_FUNC_IMPL(__imp__sub_821CE524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE528"))) PPC_WEAK_FUNC(sub_821CE528);
PPC_FUNC_IMPL(__imp__sub_821CE528) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8207c98c
	ctx.lr = 0x821CE530;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82079fd8
	ctx.lr = 0x821CE540;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// li r31,0
	ctx.r31.s64 = 0;
	// beq cr6,0x821ce580
	if (ctx.cr6.eq) goto loc_821CE580;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r31.u32);
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// stb r31,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, ctx.r31.u8);
	// addi r9,r10,-1396
	ctx.r9.s64 = ctx.r10.s64 + -1396;
	// stb r31,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, ctx.r31.u8);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r31,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, ctx.r31.u8);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r31.u32);
	// stb r31,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, ctx.r31.u8);
	// b 0x821ce584
	goto loc_821CE584;
loc_821CE580:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_821CE584:
	// stw r11,92(r29)
	PPC_STORE_U32(ctx.r29.u32 + 92, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r29.u32 + 64);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// addi r30,r29,44
	ctx.r30.s64 = ctx.r29.s64 + 44;
	// stw r10,64(r29)
	PPC_STORE_U32(ctx.r29.u32 + 64, ctx.r10.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CE5A8;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce5c0
	if (ctx.cr6.eq) goto loc_821CE5C0;
	// lwz r4,92(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 92);
	// bl 0x8218a358
	ctx.lr = 0x821CE5B8;
	sub_8218A358(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x821ce5c4
	goto loc_821CE5C4;
loc_821CE5C0:
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_821CE5C4:
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// li r3,500
	ctx.r3.s64 = 500;
	// addi r10,r10,-31352
	ctx.r10.s64 = ctx.r10.s64 + -31352;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r10,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r10.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// bl 0x82079fd8
	ctx.lr = 0x821CE5EC;
	sub_82079FD8(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x821ce5fc
	if (ctx.cr6.eq) goto loc_821CE5FC;
	// bl 0x821cdbe8
	ctx.lr = 0x821CE5F8;
	sub_821CDBE8(ctx, base);
	// b 0x821ce600
	goto loc_821CE600;
loc_821CE5FC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_821CE600:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// addi r11,r11,-31380
	ctx.r11.s64 = ctx.r11.s64 + -31380;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r9,-6984
	ctx.r7.s64 = ctx.r9.s64 + -6984;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r31.u32);
	// stw r8,80(r29)
	PPC_STORE_U32(ctx.r29.u32 + 80, ctx.r8.u32);
	// stw r7,72(r29)
	PPC_STORE_U32(ctx.r29.u32 + 72, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8207c9dc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821CE63C"))) PPC_WEAK_FUNC(sub_821CE63C);
PPC_FUNC_IMPL(__imp__sub_821CE63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821CE640"))) PPC_WEAK_FUNC(sub_821CE640);
PPC_FUNC_IMPL(__imp__sub_821CE640) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addi r10,r11,-6872
	ctx.r10.s64 = ctx.r11.s64 + -6872;
	// stw r10,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r10.u32);
	// blr 
	return;
}

